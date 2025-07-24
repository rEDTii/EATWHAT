/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_spi.c
  * @author  FMSH Application Team
  * @brief   Src file of SPI FL Module
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

/** @addtogroup SPI
  * @{
  */

#ifdef FL_SPI_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup SPI_FL_Private_Macros
  * @{
  */
#define         IS_FL_SPI_INSTANCE(INTANCE)                     (((INTANCE) == SPI0)||\
                                                                 ((INTANCE) == SPI1)||\
                                                                                                                                 ((INTANCE) == SPI2)||\
                                                                                                                                 ((INTANCE) == SPI3)||\
                                                                                                                                 ((INTANCE) == SPI4))

#define         IS_FL_SPI_MODE(__VALUE__)                       (((__VALUE__) == FL_SPI_WORK_MODE_SLAVE)||\
                                                                 ((__VALUE__) == FL_SPI_WORK_MODE_MASTER))

#define         IS_FL_SPI_DATAWIDTH_L(__VALUE__)                (((__VALUE__) == FL_SPI_DATAL_LENGTH0)||\
                                                                 ((__VALUE__) == FL_SPI_DATAL_LENGTH1)||\
                                                                 ((__VALUE__) == FL_SPI_DATAL_LENGTH2)||\
                                                                 ((__VALUE__) == FL_SPI_DATAL_LENGTH3))

#define         IS_FL_SPI_DATAWIDTH_H(__VALUE__)                (((__VALUE__) == FL_SPI_DATAH_LENGTH0)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH1)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH2)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH3)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH4)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH5)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH6)||\
                                                                 ((__VALUE__) == FL_SPI_DATAH_LENGTH7))

#define         IS_FL_SPI_BITORDER(__VALUE__)                   (((__VALUE__) == FL_SPI_BIT_ORDER_MSB_FIRST)||\
                                                                 ((__VALUE__) == FL_SPI_BIT_ORDER_LSB_FIRST))

#define         IS_FL_SPI_CLOCK_PHASE(__VALUE__)                (((__VALUE__) == FL_SPI_PHASE_EDGE1)||\
                                                                 ((__VALUE__) == FL_SPI_PHASE_EDGE2))

#define         IS_FL_SPI_CLOCK_POLARITY(__VALUE__)             (((__VALUE__) == FL_SPI_POLARITY_NORMAL)||\
                                                                 ((__VALUE__) == FL_SPI_POLARITY_INVERT))

#define         IS_FL_SPI_BAUDRATE(__VALUE__)                   (((__VALUE__) == FL_SPI_PCLK_DIV2)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV4)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV8)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV16)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV32)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV64)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV128)||\
                                                                 ((__VALUE__) == FL_SPI_PCLK_DIV256))

#define         IS_FL_SPI_TANSFERMODE(__VALUE__)                (((__VALUE__) == FL_SPI_TRANSFER_MODE_FULL_DUPLEX)||\
                                                                 ((__VALUE__) == FL_SPI_TRANSFER_MODE_HALF_DUPLEX))

#define         IS_FL_I2S_MODE(__VALUE__)                       (((__VALUE__) == FL_I2S_MODE_SLAVE_RX)||\
                                                                 ((__VALUE__) == FL_I2S_MODE_SLAVE_TX)||\
                                                                 ((__VALUE__) == FL_I2S_MODE_MASTER_RX)||\
                                                                 ((__VALUE__) == FL_I2S_MODE_MASTER_TX))

#define         IS_FL_I2S_DATAFORMAT(__VALUE__)                 (((__VALUE__) == FL_I2S_DATAFORMAT_16B)||\
                                                                 ((__VALUE__) == FL_I2S_DATAFORMAT_16B_EXTENDED)||\
                                                                 ((__VALUE__) == FL_I2S_DATAFORMAT_24B)||\
                                                                 ((__VALUE__) == FL_I2S_DATAFORMAT_32B))

#define         IS_FL_I2S_IDLE_POLARITY(__VALUE__)              (((__VALUE__) == FL_I2S_IDLE_POLARITY_LOW)||\
                                                                 ((__VALUE__) == FL_I2S_IDLE_POLARITY_HIGHT))

#define         IS_FL_I2S_STANDARD(__VALUE__)                   (((__VALUE__) == FL_I2S_STANDARD_PHILIPS)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_MSB)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_LSB)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_PCM_SHORT)||\
                                                                 ((__VALUE__) == FL_I2S_STANDARD_PCM_LONG))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup SPI_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应SPI寄存器.
  * @param  SPIx
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_SPI_DeInit(SPI_Type *SPIx)
{
    assert_param(IS_FL_SPI_INSTANCE(SPIx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(SPIx == SPI0)
    {
        /* 复位SPI外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI0);
        /* 关闭外设总线始时钟和工作时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI0);
    }
    else if(SPIx == SPI1)
    {
        /* 复位SPI外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI1);
        /* 关闭外设总线始时钟和工作时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI1);
    }
    else if(SPIx == SPI2)
    {
        /* 复位SPI外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI2);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI2);
        /* 关闭外设总线始时钟和工作时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI2);
    }

    else if(SPIx == SPI3)
    {
        /* 复位SPI外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI3);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI3);
        /* 关闭外设总线始时钟和工作时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI3);
    }
    else if(SPIx == SPI4)
    {
        /* 复位SPI外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI4);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_SPI4);
        /* 关闭外设总线始时钟和工作时钟 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI4);
    }
    else
    {
        FL_RMU_DisablePeripheralReset(RMU);
        return FL_FAIL;
    }
    /* 锁定外设复位 */
    RMU->PERHRSTEN = ~(0x13579BDFUL);
    return FL_PASS;
}
/**
  * @brief  根据 SPI_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  SPIx SPIx
  * @param  SPI_InitStruct 指向一个 @ref FL_SPI_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS SPI配置成功
  */
FL_ErrorStatus FL_SPI_Init(SPI_Type *SPIx, FL_SPI_InitTypeDef *initStruct)
{
    assert_param(IS_FL_SPI_INSTANCE(SPIx));
    assert_param(IS_FL_SPI_MODE(initStruct->mode));
    assert_param(IS_FL_SPI_BITORDER(initStruct->bitOrder));
    assert_param(IS_FL_SPI_DATAWIDTH_L(initStruct->dataWidth_l));
    assert_param(IS_FL_SPI_DATAWIDTH_H(initStruct->dataWidth_h));
    assert_param(IS_FL_SPI_BAUDRATE(initStruct->baudRate));
    assert_param(IS_FL_SPI_CLOCK_PHASE(initStruct->clockPhase));
    assert_param(IS_FL_SPI_CLOCK_POLARITY(initStruct->clockPolarity));
    if(SPIx == SPI0)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI0);
    }
    else if(SPIx == SPI1)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI1);
    }
    else if(SPIx == SPI2)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI2);
    }
    else if(SPIx == SPI3)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI3);
    }
    else if(SPIx == SPI4)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI4);
    }
    else
    {
        return FL_FAIL;
    }
    /* 外设工作主从模式 */
    FL_SPI_SetWorkMode(SPIx, initStruct->mode);
    if(initStruct->mode == FL_SPI_WORK_MODE_MASTER)
    {
        /*MASTER模式SSN mode下，送完一帧后拉高 SSN*/
        FL_SPI_SetHardwareSSNMode(SPIx, FL_SPI_HARDWARE_SSN_AUTO_HIGH);
        /*默认帧间隔 1 WAIT*/
        FL_SPI_SetSendWait(SPIx, FL_SPI_SEND_WAIT_1);
    }
    /* 选择NSS脚控制模式 */
    if(initStruct->softControl == FL_ENABLE)
    {
        FL_SPI_EnableSSNSoftControl(SPIx);
        FL_SPI_SetHardwareSSNMode(SPIx, FL_SPI_HARDWARE_SSN_KEEP_LOW);
    }
    else
    {
        FL_SPI_DisableSSNSoftControl(SPIx);
    }
    /* 总线通讯速率 */
    FL_SPI_SetBaudRate(SPIx, initStruct->baudRate);
    /* 数据bit方向 */
    FL_SPI_SetBitOrder(SPIx, initStruct->bitOrder);
    /* 总线数据位宽
     * CR2寄存器中DLEN与DLEN2组合 {DLEN2, DLEN} 决定总线数据位宽
     * 实际总线数据宽度可查询产品说明书
     * 或者由总线数据位宽函数获取 __STATIC_INLINE uint32_t FL_SPI_GetDataWidth(SPI_Type* SPIx)
     */
    FL_SPI_SetDataWidth(SPIx, initStruct->dataWidth_l, initStruct->dataWidth_h);
    /* 时钟相位 */
    FL_SPI_SetClockPhase(SPIx, initStruct->clockPhase);
    /* 传输模式 双工半双工  */
    FL_SPI_SetTransferMode(SPIx, initStruct->transferMode);
    /* 时钟极性 */
    FL_SPI_SetClockPolarity(SPIx, initStruct->clockPolarity);
    /* 使能 外设*/
    FL_SPI_Enable(SPIx);

    return FL_PASS;
}
/**
  * @brief  设置 SPI_InitStruct 为默认配置
  * @param  SPI_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_SPI_InitTypeDef 结构体
  *
  * @retval None
  */

void FL_SPI_StructInit(FL_SPI_InitTypeDef *initStruct)
{
    initStruct->softControl         =   FL_DISABLE;
    initStruct->mode                =   FL_SPI_WORK_MODE_MASTER;
    initStruct->baudRate            =   FL_SPI_PCLK_DIV4;
    initStruct->bitOrder            =   FL_SPI_BIT_ORDER_MSB_FIRST;
    initStruct->dataWidth_l         =   FL_SPI_DATAL_LENGTH0;
    initStruct->dataWidth_h         =   FL_SPI_DATAH_LENGTH0;
    initStruct->clockPolarity       =   FL_SPI_POLARITY_NORMAL;
    initStruct->clockPhase          =   FL_SPI_PHASE_EDGE1;
    initStruct->transferMode        =   FL_SPI_TRANSFER_MODE_FULL_DUPLEX;
}

/**
  * @brief  复位对应I2S寄存器.
  * @param  SPIx
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_I2S_DeInit(SPI_Type *SPIx)
{
    return FL_SPI_DeInit(SPIx);
}

/**
  * @brief  根据 I2S_InitStruct 的配置信息初始化对应外设入口地址的寄存器值.
  * @param  SPIx
  * @param  I2S_InitStruct 指向一个 @ref FL_I2S_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS SPI配置成功
  */
FL_ErrorStatus FL_I2S_Init(SPI_Type *SPIx, FL_I2S_InitTypeDef *initStruct)
{
    uint32_t packetlength = 1U;
    uint32_t sourceclock;
    uint32_t tmp;
    uint32_t i2sdiv = 2U;
    uint32_t i2sodd = 0U;
    assert_param(IS_FL_SPI_INSTANCE(SPIx));
    assert_param(IS_FL_I2S_MODE(initStruct->mode));
    assert_param(IS_FL_I2S_DATAFORMAT(initStruct->dataFormat));
    assert_param(IS_FL_I2S_IDLE_POLARITY(initStruct->clockPolarity));
    assert_param(IS_FL_I2S_STANDARD(initStruct->standard));

    if(SPIx == SPI0)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI0);
    }
    else if(SPIx == SPI1)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI1);
    }
    else if(SPIx == SPI2)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI2);
    }
    else if(SPIx == SPI3)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI3);
    }
    else if(SPIx == SPI4)
    {
        /* 外设总线始时钟 */
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_SPI4);
    }
    else
    {
        return FL_FAIL;
    }

    FL_I2S_Disable(SPIx);
    /*! I2S主从机模式 */
    FL_I2S_SetTransferMode(SPIx, initStruct->mode);

    /*! I2S标准选择*/
    if((initStruct->standard == FL_I2S_STANDARD_PCM_SHORT) || (initStruct->standard == FL_I2S_STANDARD_PCM_LONG))
    {
        FL_I2S_SetStandardMode(SPIx, initStruct->standard);
        FL_I2S_SetPCMFrameSynchronization(SPIx, initStruct->standard);
    }
    else
    { FL_I2S_SetStandardMode(SPIx, initStruct->standard); }

    /*! I2S通信长度*/
    if(initStruct->dataFormat != FL_I2S_DATAFORMAT_16B)
    {
        FL_I2S_SetVocalTractLength(SPIx, initStruct->dataFormat);
        FL_I2S_SetDataLength(SPIx, initStruct->dataFormat);
        packetlength = 2U;
    }

    sourceclock = FL_CMU_GetAPB1ClockFreq();

    /*! I2S_MCLK输出使能*/
    if(initStruct->mclkOutput)
    {
        FL_I2S_EnableMasterClockOutput(SPIx);
        tmp = (((((sourceclock / 256U) * 10U) / initStruct->audioFreq)) + 5U);
    }
    else
    {
        FL_I2S_DisableMasterClockOutput(SPIx);
        tmp = (((((sourceclock / (32U * packetlength)) * 10U) / initStruct->audioFreq)) + 5U);
    }

    tmp = tmp / 10U;
    i2sodd = (tmp & (uint16_t)0x0001U);
    i2sdiv = ((tmp - i2sodd) / 2U);
    if(i2sodd)
    { FL_I2S_SetPrescalerParity(SPIx, FL_I2S_PRESCALER_PARITY_ODD); }
    else
    { FL_I2S_SetPrescalerParity(SPIx, FL_I2S_PRESCALER_PARITY_EVEN); }

    FL_I2S_WritePrescalerLinear(SPIx, i2sdiv);

    /*! I2S空闲时钟极性*/
    FL_I2S_SetIdleClockPolarity(SPIx, initStruct->clockPolarity);

    /*! 选择I2S*/
    FL_I2S_SetPeriphralMode(SPIx, FL_I2S_PERIPHRAL_MODE_I2S);
    /* 使能 外设*/
    FL_I2S_Enable(SPIx);
    return FL_PASS;
}

/**
  * @brief  设置 I2S_InitStruct 为默认配置
  * @param  I2S_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_I2S_InitTypeDef 结构体
  *
  * @retval None
  */

void FL_I2S_StructInit(FL_I2S_InitTypeDef *initStruct)
{
    initStruct->mode                =   FL_I2S_MODE_MASTER_TX;
    initStruct->standard            =   FL_I2S_STANDARD_PHILIPS;
    initStruct->dataFormat          =   FL_I2S_DATAFORMAT_16B;
    initStruct->clockPolarity       =   FL_I2S_IDLE_POLARITY_LOW;
    initStruct->audioFreq           =   FL_I2S_AUDIOFREQ_8K;
    initStruct->mclkOutput          =   FL_ENABLE;
}

/**
  * @}
  */

#endif /* FL_SPI_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
