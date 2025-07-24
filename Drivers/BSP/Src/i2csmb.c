#include "i2csmb.h"
#include "stdio.h"

uint8_t I2C_Send_Bit(I2CSMB_Type *I2CSMBx, uint8_t BIT_def)
{
    switch(BIT_def)
    {
        case STARTBIT:
            SET_BIT(I2CSMBx->CR2, 0x1U);//发送START时序

            while((uint32_t)(READ_BIT(I2CSMBx->CR2, 0x1U) == 0x1U))
            {
            }

            break;

        case RESTARTBIT:
            SET_BIT(I2CSMBx->CR2, 0x1U << 1U);

            while((uint32_t)(READ_BIT(I2CSMBx->CR2, 0x1U << 1U) == (0x1U << 1U)))
            {
            }

            break;

        case STOPBIT:
            SET_BIT(I2CSMBx->CR2, 0x1U << 2U);

            while((uint32_t)(READ_BIT(I2CSMBx->CR2, 0x1U << 2U) == (0x1U << 2U)))
            {
            }

            break;

        default:
            break;
    }
    return 0; //ok

}

uint8_t I2C_Send_Byte(I2CSMB_Type *I2CSMBx, uint8_t x_byte)
{

    MODIFY_REG(I2CSMBx->TXBUF, (0xffU << 0U), (x_byte << 0U));

    while(!((uint32_t)(READ_BIT(I2CSMBx->ISR, 0x1U << 1U) == (0x1U << 1U))));

    WRITE_REG(I2CSMBx->ISR, 0x1U << 1U);

    if(!((uint32_t)(READ_BIT(I2CSMBx->ISR, 0x1U << 3U) == (0x1U << 3U))))
    {
        return 0;
    }

    else
    {
        WRITE_REG(I2CSMBx->ISR, 0x1U << 3U);
        return 1;
    }

}

uint8_t I2C_Receive_Byte(I2CSMB_Type *I2CSMBx, uint8_t *x_byte)
{

    MODIFY_REG(I2CSMBx->CR2, 0x1U << 3U, 0x1U << 3U);

    while(!((uint32_t)(READ_BIT(I2CSMBx->ISR, 0x1U << 0U) == (0x1U << 0U))));

    WRITE_REG(I2CSMBx->ISR, 0x1U << 0U);
    *x_byte = (uint32_t)(READ_BIT(I2CSMBx->RXBUF, (0xffU << 0U)) >> 0U);;
    return 0;
}

uint8_t Sendaddr(I2CSMB_Type *I2CSMBx, uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t Opt)
{
    uint8_t result, Devi_Addr;

    Devi_Addr = Device;

    /*-------------- start bit ---------------*/
    result = I2C_Send_Bit(I2CSMBx, STARTBIT); //发送起始位

    if(result != 0) { return 1; }   //failure.

    /*-------------- disable read -------------*/
    MODIFY_REG(I2CSMBx->CR2, 0x1U << 3U, 0x0U << 3U);
    /*-------------- device addr -------------*/
    result = I2C_Send_Byte(I2CSMBx, Devi_Addr);  //发送器件地址

    if(result != 0) { return 2; }   //failure.

    /*--------------- data addr --------------*/
    if(AddrLen == 2)
    {
        result = I2C_Send_Byte(I2CSMBx, Addr >> 8); //发送数据地址高8位

        if(result != 0) { return 3; }   //failure.
    }

    result = I2C_Send_Byte(I2CSMBx, Addr >> 0); //发送数据地址低8位

    if(result != 0) { return 3; }   //failure.

    if(Opt == I2CREAD)   //读操作
    {
        result = I2C_Send_Bit(I2CSMBx, RESTARTBIT);  //发送重起始位

        if(result != 0) { return 5; }   //failure.

        result = I2C_Send_Byte(I2CSMBx, Devi_Addr | 1); //发送器件地址

        if(result != 0) { return 5; }   //failure.
    }

    return 0; //ok
}

uint8_t Wait_for_end(I2CSMB_Type *I2CSMBx, uint8_t Device)
{
    uint8_t result, Devi_Addr;
    Devi_Addr = Device;

    SysTick->LOAD = 0x1000000 - 1;
    SysTick->VAL = 0;
    FL_DelayMsStart(3000); //需要5ms的内部写周期, 循环一次所需时间: 42个Delay()。

    while(!FL_DelayEnd())
    {
        I2C_Send_Bit(I2CSMBx, STARTBIT);     //发送起始位

        result = I2C_Send_Byte(I2CSMBx, Devi_Addr);  //发送器件地址

        I2C_Send_Bit(I2CSMBx, STOPBIT);  //发送停止位

        if(result == 0) { return 0; }   //设置地址成功, 写周期结束
    }

    return 1; //设置地址失败
}

uint8_t I2C_Write_Bottom(I2CSMB_Type *I2CSMBx, uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t *Buf, uint8_t Len)
{
    uint8_t k, n, status;

    if(Len > 128) { return 0xFF; }//一次最多操作128字节

    for(k = 0; k < 3; k++) //每遍最多写3次
    {
        status = 0;

        if(Sendaddr(I2CSMBx, Device, Addr, AddrLen, I2CWRITE))
        {
            status = 1; //写入失败
        }

        else
        {
            for(n = 0; n < Len; n++)
            {
                //发送一个字节
                if(I2C_Send_Byte(I2CSMBx, Buf[n]))
                {
                    status = 1;
                    break;
                } //写入失败
            }
        }

        //发送停止位
        if(I2C_Send_Bit(I2CSMBx, STOPBIT))
        { status = 1; }

        if(status == 0)
        {
            status = Wait_for_end(I2CSMBx, Device);
            break;
        } //写正确
    }

    return(status);
}

uint8_t I2C_Read_Bottom(I2CSMB_Type *I2CSMBx, uint8_t Device, uint16_t Addr, uint8_t AddrLen, uint8_t *Buf, uint8_t Len)
{
    uint8_t k, n, status;

    if(Len > 128) { return 0xFF; }//一次最多操作128字节

    for(k = 0; k < 3; k++) //每遍最多读3次
    {
        status = 0;

        if(Sendaddr(I2CSMBx, Device, Addr, AddrLen, I2CREAD))
        { status = 1; } //写入失败

        else
        {
            for(n = 0; n < Len; n++)
            {
                if(n < (Len - 1))
                {  
//										MODIFY_REG(I2CSMBx->CR2, 0x1U << 3U, 0x0U << 3U); 
											MODIFY_REG(I2CSMBx->CR2, 0x1U << 4U, 0x0U << 4U); 
								}
                else
                {
//                    MODIFY_REG(I2CSMBx->CR2, 0x1U << 3U, 0x1U << 3U);
											MODIFY_REG(I2CSMBx->CR2, 0x1U << 4U, 0x1U << 4U);
                }

                //接收一个字节
                if(I2C_Receive_Byte(I2CSMBx, Buf + n))
                {
                    status = 1;
                    break;
                }

            }
        }

        //发送停止位
        if(I2C_Send_Bit(I2CSMBx, STOPBIT))
        { status = 1; }   //失败

        if(status == 0) { break; }  //读正确
    }

    return(status);
}

void I2C_Init(void)
{
    uint32_t BRG = 0;

    FL_I2C_SMBUS_MasterMode_InitTypeDef   IICSMBInitStructer;
    FL_GPIO_InitTypeDef    GPIO_InitStruct ;

	// I2C引脚配置为上拉+开漏输出
    GPIO_InitStruct.pin        = FL_GPIO_PIN_8 | FL_GPIO_PIN_9;
    GPIO_InitStruct.mode       = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_OPENDRAIN;
		GPIO_InitStruct.pull          = FL_GPIO_PULLUP_ENABLE;
    GPIO_InitStruct.remapPin   = FL_GPIO_PINREMAP_FUNCTON1;
		GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X4;
	
    FL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    IICSMBInitStructer.clockSource = FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK;
    IICSMBInitStructer.baudRate = 100000;
    FL_I2C_SMBUS_MasterMode_Init(I2CSMB1, &IICSMBInitStructer);

}


uint8_t GT911_I2C_Write(uint16_t reg, uint8_t *buf, uint8_t len) {
		return I2C_Write_Bottom(I2CSMB1, DEVICE_CTP, reg, ADDRLEN_CTP, buf, len);
}

uint8_t GT911_I2C_Read(uint16_t reg, uint8_t *buf, uint8_t len) {
		return I2C_Read_Bottom(I2CSMB1, DEVICE_CTP, reg, ADDRLEN_CTP, buf, len);
}