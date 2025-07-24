/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_rng.c
  * @author  FMSH Application Team
  * @brief   Src file of RNG FL Module
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

/** @addtogroup RNG
  * @{
  */

#ifdef FL_RNG_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup RNG_FL_Private_Macros
* @{
*/
#define         IS_FL_RNG_INSTANCE(INTANCE)                         ((INTANCE) == RNG)

#define         IS_FL_RNG_CLOCK_PRESCALER(__VALUE__)               (((__VALUE__) == FL_RCC_RNG_PSC_DIV1)||\
                                                                     ((__VALUE__) == FL_RCC_RNG_PSC_DIV2)||\
                                                                     ((__VALUE__) == FL_RCC_RNG_PSC_DIV4)||\
                                                                     ((__VALUE__) == FL_RCC_RNG_PSC_DIV8)||\
                                                                     ((__VALUE__) == FL_RCC_RNG_PSC_DIV16)||\
                                                                     ((__VALUE__) == FL_RCC_RNG_PSC_DIV32))
/**
  *@}
  */

/** @addtogroup RNG_FL_EF_Init
  * @{
  */

/**
  * @brief  复位RNG
  *
  * @param  RNGx 外设入口地址
  *
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_RNG_DeInit(RNG_Type *RNGx)
{
    assert_param(IS_FL_RNG_INSTANCE(RNGx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    /* 复位外设寄存器 */
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_RNG);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_RNG);
    /* 关闭外设总线始时钟和工作时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_RNG);
    /* 锁定外设复位 */
    FL_RMU_DisablePeripheralReset(RMU);
    return FL_PASS;
}

/**
  * @brief  配置RNG
  *
  * @param  RNGx 外设入口地址
  * @param  initStruct 指向 @ref FL_RNG_InitTypeDef 结构体的指针
  *
  * @note   RNG使用RCHF默认的8M作为时钟输入，经2分频后4M提供给RNG
  *
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_RNG_Init(RNG_Type *RNGx)
{
    assert_param(IS_FL_RNG_INSTANCE(RNGx));
    /* RNG 使用RCHF作为工作时钟因此必须确认RCHF使能*/
    if(FL_CMU_RCHF_IsEnabled() != FL_SET)
    {
        FL_CMU_RCHF_Enable();
    }
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_RNG);
    /* RNG 工作时钟预分频*/
    switch(FL_CMU_RCHF_GetFrequency())
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV2);
            break;
        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV4);
            break;
        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV8);
            break;
        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV8);
            break;
        default:
            FL_CMU_SetRNGPrescaler(FL_CMU_RNG_PSC_DIV2);
            break;
    }
    /* RNG 工作时钟使能*/
    FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_RNG);
    return FL_PASS;
}

/**
  * @brief  获取一次随机数
  * @param  rng：输出参数，随机数的值
  * @retval FL_ErrorStatus枚举值
  *         -FL_PASS 成功
  *         -FL_FAIL 失败
  */
FL_ErrorStatus GetRandomNumber(uint32_t *rng)
{
    FL_RNG_ClearFlag_RandomFail(RNG);
    FL_RNG_Enable(RNG);
    /* 由于LFSR循环移位周期是32cycle，为保证随机数质量，应用应保证两次读取RNGOUT之间的间隔大于32个TRNG_CLK周期 */
    FL_DelayUs(12);
    FL_RNG_Disable(RNG);
    if(FL_RNG_IsActiveFlag_RandomFail(RNG) == 0x01)
    {
        FL_RNG_ClearFlag_RandomFail(RNG);
        *rng = 0xFFFFFFFFU;
        return FL_FAIL;
    }
    *rng = FL_RNG_ReadData(RNG);
    return FL_PASS;
}
/**
  * @brief  获取CRC32
  * @param  dataIn：输入参数 待计算的数据
  * @param  crcResult：输出参数 crc计算结果
  * @retval FL_ErrorStatus枚举值
  *         -FL_PASS 成功
  *         -FL_FAIL 失败
  *
  */
FL_ErrorStatus GetCrc32(uint32_t dataIn, uint32_t *crcResult)
{
    uint32_t timeout = 0, completeStatus;
    FL_RNG_CRC_WriteData(RNG, dataIn);
    FL_RNG_ClearFlag_CRCComplete(RNG);
    FL_RNG_CRC_Enable(RNG);
    do
    {
        completeStatus = FL_RNG_IsActiveFlag_CRCComplete(RNG);
        timeout++;
    } while((timeout != RNG_TIMEOUT) && (completeStatus != 0x1U));
    if(completeStatus != 0x1U)
    {
        FL_RNG_ClearFlag_CRCComplete(RNG);
        FL_RNG_Disable(RNG);
        *crcResult = 0xFFFFFFFFU;
        return FL_FAIL;
    }
    FL_RNG_ClearFlag_CRCComplete(RNG);
    *crcResult = FL_RNG_ReadData(RNG);
    FL_RNG_Disable(RNG);
    return FL_PASS;
}

/**
  * @}
  */

#endif /* FL_RNG_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
