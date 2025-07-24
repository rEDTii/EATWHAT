/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_i2c.c
  * @author  FMSH Application Team
  * @brief   Src file of I2C FL Module
  *******************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * You may obtain a copy of Mulan PSL v2 at:
  *          http://license.coscl.org.cn/MulanPSL2
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
  * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
  * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
  * See the Mulan PSL v2 for more details.
  *
  *******************************************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fm33fk5xx_fl.h"

/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

#ifdef FL_I2C_SMBUS_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C_FL_Private_Macros
  * @{
  */

#define         IS_FL_I2C_SMBUS_INSTANCE(INSTANCE)                      (((INSTANCE) == I2CSMB0)||\
                                                                        ((INSTANCE) == I2CSMB1))

#define         IS_FL_I2C_SMBUS_BAUDRATE(__VALUE__)                     (((__VALUE__) > 0 )&&((__VALUE__) <= 1000000))

#define         IS_FL_I2C_SMBUS_CLOCKSRC(__VALUE__)                     (((__VALUE__) == FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK )||\
                                                                        ((__VALUE__) == FL_CMU_I2CSMB1_CLK_SOURCE_RCHF)||\
                                                                        ((__VALUE__) == FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK ))

#define         IS_FL_I2C_SMBUS_MSATER_TIMEOUT(__VALUE__)               (((__VALUE__) == FL_IWDT_PERIOD_125MS)||\
                                                                        ((__VALUE__) == FL_IWDT_PERIOD_16000MS))

#define         IS_FL_I2C_SMBUS_ANGLOGFILTER(__VALUE__)                 (((__VALUE__) == FL_ENABLE)||\
                                                                        ((__VALUE__) == FL_DISABLE))

#define         IS_FL_I2C_SMBUS_ADDRSIZE10BIT(__VALUE__)                (((__VALUE__) == FL_ENABLE)||\
                                                                        ((__VALUE__) == FL_DISABLE))

#define         IS_FL_I2C_SMBUS_SLAVE_SCLSEN(__VALUE__)                 (((__VALUE__) == FL_ENABLE)||\
                                                                        ((__VALUE__) == FL_DISABLE))

/**
  * @}
  */

/** @addtogroup I2CSMBUS_FL_EF_Init
  * @{
  */

/**
  * @brief  复位I2CSMBUS外设.
  * @param  I2CSMBx 外设入口地址
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_I2C_SMBUS_DeInit(I2CSMB_Type *I2CSMBx)
{
    assert_param(IS_FL_I2C_SMBUS_INSTANCE(I2CSMBx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(I2CSMBx == I2CSMB0)
    {
        /* 复位I2CSMB0外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2CSMB0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2CSMB0);

    }
    else if(I2CSMBx == I2CSMB1)
    {
        /* 复位I2CSMB1外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
    }

    else
    {
        FL_RMU_DisablePeripheralReset(RMU);
        return FL_FAIL;
    }

    return FL_PASS;
}

/**
  * @brief  配置I2CSMBUS主机模式.
  * @param  I2CSMBx 外设入口地址
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_MasterMode_InitTypeDef 结构体的指针
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_I2C_SMBUS_MasterMode_Init(I2CSMB_Type *I2CSMBx, FL_I2C_SMBUS_MasterMode_InitTypeDef *I2CSMB_InitStruct)
{
    uint32_t I2C_Clk_Freq = 0, BRG = 0;
    assert_param(IS_FL_I2C_SMBUS_INSTANCE(I2CSMBx));
    assert_param(IS_FL_I2C_SMBUS_CLOCKSRC(I2CSMB_InitStruct->clockSource));
    assert_param(IS_FL_I2C_SMBUS_BAUDRATE(I2CSMB_InitStruct->baudRate));
    /* 外设总线时钟和工作时钟开启 */
    if(I2CSMBx == I2CSMB0)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB0);
        FL_CMU_SetI2CSMB0ClockSource(I2CSMB_InitStruct->clockSource);
        FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_I2CSMB0);

    }
    else if(I2CSMBx == I2CSMB1)
    {
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB1);
        FL_CMU_SetI2CSMB1ClockSource(I2CSMB_InitStruct->clockSource);
        FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_I2CSMB1);
    }
    else if(I2CSMBx == I2CSMB2)
    {
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB2);
        FL_CMU_SetI2CSMB2ClockSource(I2CSMB_InitStruct->clockSource);
        FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_I2CSMB2);
    }
    else
    {
        return FL_FAIL;
    }
    /* 获取时钟源速度 */
    switch(I2CSMB_InitStruct->clockSource)
    {
        case FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK:
            I2C_Clk_Freq = FL_CMU_GetAPB1ClockFreq();
            break;
        case FL_CMU_I2CSMB1_CLK_SOURCE_RCHF:
            I2C_Clk_Freq = FL_CMU_GetRCHFClockFreq();
            break;
        case FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK:
            I2C_Clk_Freq = FL_CMU_GetSystemClockFreq();
            break;
        default:
            I2C_Clk_Freq = FL_CMU_GetAPB1ClockFreq();
            break;
    }
    /* 根据不同的时钟源速度计算出配置速率需要的寄存器值并配置相关寄存器 */
    BRG = (uint32_t)(I2C_Clk_Freq / (2 * I2CSMB_InitStruct->baudRate)) - 1;
    FL_I2CSMB_WriteSCLHighWidth(I2CSMBx, BRG);
    FL_I2CSMB_WriteSCLLowWidth(I2CSMBx, BRG);
    FL_I2CSMB_WriteSDAHoldTime(I2CSMBx, (uint32_t)(BRG / 2.0 + 0.5));
    /* 使能外设 */
    FL_I2CSMB_Enable(I2CSMBx);
    return FL_PASS;
}

/**
  * @brief  将 @ref FL_I2C_SMBUS_MasterMode_InitTypeDef 结构体初始化为默认配置
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_MasterMode_InitTypeDef 结构体的指针
  *
  * @retval None
  */
void FL_I2C_SMBUS_MasterMode_StructInit(FL_I2C_SMBUS_MasterMode_InitTypeDef *I2CSMB_InitStruct)
{
    I2CSMB_InitStruct->clockSource = FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK;
    I2CSMB_InitStruct->baudRate = 40000;
}

/**
  * @brief  配置I2CSMBUS从机模式.
  * @param  I2CSMBx 外设入口地址
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_SlaveMode_InitTypeDef 结构体的指针.
  * @note   作为从机时的从机地址应参考手册推荐具体设置
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_I2C_SMBUS_SlaveMode_Init(I2CSMB_Type *I2CSMBx, FL_I2C_SMBUS_SlaveMode_InitTypeDef *I2CSMB_InitStruct)
{
    assert_param(IS_FL_I2C_SMBUS_INSTANCE(I2CSMBx));
    assert_param(IS_FL_I2C_SMBUS_ADDRSIZE10BIT(I2CSMB_InitStruct->ownAddrSize10bit));
    assert_param(IS_FL_I2C_SMBUS_SLAVE_SCLSEN(I2CSMB_InitStruct->SCLSEN));
    /* 外设总线时钟开启 注：不需要工作时钟*/
    if(I2CSMBx == I2CSMB0)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB0);

    }
    else if(I2CSMBx == I2CSMB1)
    {
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB1);
    }
    else if(I2CSMBx == I2CSMB2)
    {
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2CSMB2);
    }
    else
    {
        return FL_FAIL;
    }

    /* 从机地址宽度  和地址配置 */
    if(I2CSMB_InitStruct->ownAddrSize10bit == FL_ENABLE)
    {
        FL_I2CSMB_Enable10BitAddress(I2CSMBx);
        FL_I2CSMB_WriteSlave10BitAddress(I2CSMBx, I2CSMB_InitStruct->ownAddr & 0x3FF);
    }
    else
    {
        FL_I2CSMB_Disable10BitAddress(I2CSMBx);
        FL_I2CSMB_WriteSlave10BitAddress(I2CSMBx, I2CSMB_InitStruct->ownAddr & 0x7F);
    }
    /* 从机时钟延展使能 */
    if(I2CSMB_InitStruct->SCLSEN == FL_ENABLE)
    {
        FL_I2CSMB_EnableSlaveSCLStretching(I2CSMBx);
    }
    else
    {
        FL_I2CSMB_DisableSlaveSCLStretching(I2CSMBx);
    }
    /* 使能外设 */
    FL_I2CSMB_Enable(I2CSMBx);
    return FL_PASS;
}

/**
  * @brief  将 @ref FL_I2C_SMBUS_SlaveMode_InitTypeDef 结构体初始化为默认配置
  * @param  I2CSMB_InitStruct 指向 @ref FL_I2C_SMBUS_SlaveMode_InitTypeDef 结构体的指针
  *
  * @retval None
  */

void FL_I2C_SMBUS_SlaveMode_StructInit(FL_I2C_SMBUS_SlaveMode_InitTypeDef *I2CSMB_InitStruct)
{
    I2CSMB_InitStruct->ownAddr             = 0x55;
    I2CSMB_InitStruct->ownAddrSize10bit    = FL_DISABLE;
    I2CSMB_InitStruct->SCLSEN              = FL_DISABLE;
}

/**
  * @}
  */

#endif /* FL_I2C_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
