/**
  ****************************************************************************************************
  * @file    fm33fk5xx_fl_adc.c
  * @author  FMSH Application Team
  * @brief   Src file of ADC FL Module
  ****************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
  * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
  * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
  * See the Mulan PSL v2 for more details.
  *
  ****************************************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fm33fk5xx_fl.h"

/** @addtogroup fm33fk5xx_FL_Driver
  * @{
  */

/** @addtogroup ADC
  * @{
  */

#ifdef FL_ADC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup ADC_FL_Private_Macros
  * @{
  */

#define         IS_FL_ADC_INSTANCE(INSTANCE)                ((INSTANCE) == ADC)

#define         IS_FL_ADC_CLK_SOURCE(__VALUE__)             (((__VALUE__) == FL_CMU_ADC_CLK_SOURCE_APBCLK)||\
                                                            ((__VALUE__) == FL_CMU_ADC_CLK_SOURCE_RCHF)||\
                                                            ((__VALUE__) == FL_CMU_ADC_CLK_SOURCE_XTHF)||\
                                                            ((__VALUE__) == FL_CMU_ADC_CLK_SOURCE_PLL))

#define         IS_FL_ADC_REFERENCE_SOURCE(__VALUE__)       (((__VALUE__) == FL_ADC_REF_SOURCE_VDDA)||\
                                                            ((__VALUE__) == FL_ADC_REF_SOURCE_VREFP))

#define         IS_FL_ADC_TRIGERMODE(__VALUE__)             (((__VALUE__) == FL_ADC_TRIGER_MODE_NOMAL)||\
                                                            ((__VALUE__) == FL_ADC_TRIGER_MODE_ONE_SHOT)||\
                                                            ((__VALUE__) == FL_ADC_TRIGER_MODE_CONTINUOUS))

#define         IS_FL_ADC_CONVERSIONMODE(__VALUE__)             (((__VALUE__) == FL_ADC_SYNC_MODE_SYNC)||\
                                                            ((__VALUE__) == FL_ADC_SYNC_MODE_ASYNC))

#define         IS_FL_ADC_WAITCOFIG(__VALUE__)                  (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_ADC_OVERRUNCOFIG(__VALUE__)           (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_ADC_CHANNELSELECT(__VALUE__)          (((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA0)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA1)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA2)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA3)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA4)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA5)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA6)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA7)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INA8_OPA0_OUT)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_TS)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_AVREF)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_P_CALIBRATION)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB0)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB1)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB2)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB3)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB4)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB5)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB6)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB7)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_INB8_OPA1_OUT)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_VBAT_DIV3)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_DAC0)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SELECT_CHANNEL_N_CALIBRATION))

#define         IS_FL_ADC_TRIGSOURCE(__VALUE__)                     (((__VALUE__) == FL_ADC_ACQ_TRGI_SOFE_TRG)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_LUT0_TRG)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_LUT1_TRG)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_LUT2_TRG)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_LUT3_TRG)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_ATIM0_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_ATIM1_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_ATIM0_TRGO2)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_ATIM1_TRGO2)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_GPTIM0_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_GPTIM1_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_GPTIM2_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM0SOCA)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM1SOCA)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM1SOCB)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM2SOCA)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM2SOCB)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM3SOCA)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_EPWM3SOCB)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_COMP0_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_COMP1_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_COMP2_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_LPTIM0_TRGO)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_TRGI_BSTIM0_TRGO))

#define         IS_FL_ADC_CHANNEL_TIME(__VALUE__)               (((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK)||\
                                                            ((__VALUE__) == FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK))

#define         IS_FL_ADC_OVERSAMPCOFIG(__VALUE__)          (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_ADC_OVERSAMPINGRATIO(__VALUE__)       (((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_2X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_4X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_8X)||\
                                                            ((__VALUE__) == FL_ADC_OVERSAMPLING_MUL_16X))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup ADC_FL_EF_Init
  * @{
  */

/**
  * @brief  ADC时钟寄存器值为复位值
  * @param  外设入口地址
  * @retval 返回错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void)
{
    /* 关闭总线时钟 */
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);
    /* 关闭操作时钟 */
    FL_CMU_DisableGroup1OperationClock(FL_CMU_OPCLK_ADC);
    return FL_PASS;
}

/**
  * @brief  恢复对应的ADC入口地址寄存器为默认值
  *
  * @param  ADCx  外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC配置成功
  */
FL_ErrorStatus  FL_ADC_DeInit(ADC_Type *ADCx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_ADC_INSTANCE(ADCx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADC);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADC);
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADCCR);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_ADCCR);
    FL_RMU_DisablePeripheralReset(RMU);
    return status;
}

/**
  * @brief  ADC共用寄存器设置以配置外设工作时钟
  *
  * @param  ADC  外设入口地址
  * @param  ADC_CommonInitStructt指向FL_ADC_CommonInitTypeDef类的结构体，它包含指定ADC外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC配置成功
  */
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    uint32_t i = 0, Calibration_Flag;
    if(ADC_CommonInitStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FL_ADC_CLK_SOURCE(ADC_CommonInitStruct->clockSource));
        assert_param(IS_FL_ADC_REFERENCE_SOURCE(ADC_CommonInitStruct->referenceSource));
        assert_param(IS_FL_ADC_TRIGERMODE(ADC_CommonInitStruct->trigMode));
        assert_param(IS_FL_ADC_WAITCOFIG(ADC_CommonInitStruct->waitMode));
        assert_param(IS_FL_ADC_OVERRUNCOFIG(ADC_CommonInitStruct->overrunMode));
        assert_param(IS_FL_ADC_OVERSAMPCOFIG(ADC_CommonInitStruct->oversamplingMode));
        assert_param(IS_FL_ADC_OVERSAMPINGRATIO(ADC_CommonInitStruct->overSampingMultiplier));
        /* 开启总线时钟 */
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);
        /* 设置ADCCLK时钟源 */
        FL_CMU_SetADCClockSource(ADC_CommonInitStruct->clockSource);
        /* 配置ADCCLK时钟预分频 */
        FL_CMU_SetADCPrescaler(ADC_CommonInitStruct->clockPrescaler);
        /* 开启操作时钟 */
        FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_ADC);

        /* 开启PTAT*/
        FL_PMU_EnableTemperatureSensor(PMU);
        /* 开启VREFBUFFER*/
        FL_PMU_EnableAVREFBuffer(PMU);
        /* 开启PTATBUFFER*/
        FL_PMU_EnableVPTATBuffer(PMU);

        /* 配置ADC基准电压*/
        FL_ADC_SetReferenceSource(ADC, ADC_CommonInitStruct->referenceSource);
        if(ADC_CommonInitStruct->referenceSource == FL_ADC_REF_SOURCE_VDDA)
        {
            FL_ADC_SetNegativePeference(ADC, FL_ADC_Negative_Peference_VSSA);
        }
        else
        {
            FL_ADC_SetNegativePeference(ADC, FL_ADC_Negative_Peference_VREFN);
        }
        FL_ADC_Disable(ADC);
        FL_ADC_SetOverSamplingMode(ADC, FL_ADC_OVERSAMPLING_MODE_DISABLE);

        FL_ADC_Enable(ADC);
        FL_ADC_SetOverSamplingMultiplier(ADC, FL_ADC_OVERSAMPLING_MUL_16X);
        FL_ADC_SetOverSamplingMode(ADC, FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE);
        FL_ADC_EnableOverrunMode(ADC);
        FL_ADC_SetTrigerMode(ADC, FL_ADC_TRIGER_MODE_NOMAL);
        FL_ADC_SetConversionMode(ADC, FL_ADC_SYNC_MODE_ASYNC);
        FL_ADC_WritePChannelCalibration(ADC, 0);
        FL_ADC_WriteNChannelCalibration(ADC, 0);
        FL_ADC_SetDual0Mode(ADC, FL_ADC_DUAL0_MODE_ENABLE);
        FL_ADC_SetACQ0ChannelSelect(ADC, FL_ADC_ACQ0_SELECT_CHANNEL_P_CALIBRATION);
        FL_ADC_SetACQ1ChannelSelect(ADC, FL_ADC_ACQ1_SELECT_CHANNEL_N_CALIBRATION);
        FL_ADC_EnableACQ(ADC, FL_ADC_ACQ0);
        FL_ADC_EnableACQSWConversion(ADC, FL_ADC_ACQ0);
        do
        {
            Calibration_Flag = FL_ADC_IsActiveFlag_EndOfConversion(ADC, FL_ADC_ACQ0);
            IWDT->SERV = 0x12345A5AU;
            i++;
        } while((i != 0xFFFFFFFFU) && (Calibration_Flag == 0U));           //等待转换完成
        FL_ADC_WritePChannelCalibration(ADC, FL_ADC_ReadACQ0ConversionData(ADC));
        FL_ADC_WriteNChannelCalibration(ADC, FL_ADC_ReadACQ1ConversionData(ADC));
        FL_ADC_DisableACQ(ADC, FL_ADC_ACQ0);
        FL_ADC_SetDual0Mode(ADC, FL_ADC_DUAL0_MODE_DISABLE);
        FL_ADC_EnableRoundRobinReset(ADC);

        if(Calibration_Flag == 0x01)
        {
            /*转换模式 */
            FL_ADC_SetTrigerMode(ADC, ADC_CommonInitStruct->trigMode);
            /* 通道等待使能 */
            if(ADC_CommonInitStruct->waitMode == FL_ENABLE)
            {
                FL_ADC_EnableWaitMode(ADC);
            }
            else
            {
                FL_ADC_DisableWaitMode(ADC);
            }
            /*数据冲突模式设置*/
            if(ADC_CommonInitStruct->overrunMode == FL_ENABLE)
            {
                FL_ADC_EnableOverrunMode(ADC);
            }
            else
            {
                FL_ADC_DisableOverrunMode(ADC);
            }
            if(ADC_CommonInitStruct->oversamplingMode == FL_ENABLE)
            {
                FL_ADC_SetOverSamplingMultiplier(ADC, ADC_CommonInitStruct->overSampingMultiplier);
                /* 过采样使能 */
                FL_ADC_SetOverSamplingMode(ADC, FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE);
            }
            else
            {
                /* 关闭过采样 */
                FL_ADC_SetOverSamplingMode(ADC, FL_ADC_OVERSAMPLING_MODE_DISABLE);
            }
            status = FL_PASS;
        }
        else
        {
            status = FL_FAIL;
        }
    }
    return status;
}
/**
  * @brief  设置 ADC_CommonInitStruct 为默认配置
  * @param  ADC_CommonInitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ADC_CommonInitTypeDef 结构体
  *
  * @retval None
  */
void FL_ADC_CommonStructInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct)
{
    /* 默认使用RCHF作为ADC时钟模块时钟源，预分频系数1 */
    if(ADC_CommonInitStruct != NULL)
    {
        ADC_CommonInitStruct->clockSource           = FL_CMU_ADC_CLK_SOURCE_APBCLK;
        ADC_CommonInitStruct->clockPrescaler        = FL_CMU_ADC_PSC_DIV1;
        ADC_CommonInitStruct->referenceSource       = FL_ADC_REF_SOURCE_VDDA;
        ADC_CommonInitStruct->trigMode              = FL_ADC_TRIGER_MODE_NOMAL;
        ADC_CommonInitStruct->waitMode              = FL_ENABLE;
        ADC_CommonInitStruct->overrunMode           = FL_ENABLE;
        ADC_CommonInitStruct->oversamplingMode      = FL_ENABLE;
        ADC_CommonInitStruct->overSampingMultiplier = FL_ADC_OVERSAMPLING_MUL_16X;
    }
}

/**
  * @brief  初始化ADCx指定的入口地址的外设寄存器
  *
  * @note   用户必须检查此函数的返回值，以确保自校准完成，否则转换结果精度无法保证，除此之外ADC使能过采样实际不会增加ADC的
  *         转换精度只会提高转换结果的稳定性（同时配置移位寄存器的情况下），同时过采样会降低转换速度。
  * @param  ADCx  外设入口地址
  * @param  ADC_InitStruct 指向一 @ref FL_ADC_InitTypeDef 结构体，它包含指定ADC外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS ADC配置成功
  */
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct, uint32_t ACQx)
{
    FL_ErrorStatus status = FL_FAIL;

    if(ADC_InitStruct != NULL)
    {
        /* 入口合法性检查 */
        assert_param(IS_FL_ADC_INSTANCE(ADCx));
        assert_param(IS_FL_ADC_CHANNELSELECT(ADC_InitStruct->channelSelect));
        assert_param(IS_FL_ADC_TRIGSOURCE(ADC_InitStruct->trigerSource));
        assert_param(IS_FL_ADC_CHANNEL_TIME(ADC_InitStruct->channelTime));

        switch(ACQx)
        {
            case FL_ADC_ACQ0:
            {
                FL_ADC_SetACQ0ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ0TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ0SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ1:
            {
                FL_ADC_SetACQ1ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ1TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ1SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ2:
            {
                FL_ADC_SetACQ2ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ2TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ2SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ3:
            {
                FL_ADC_SetACQ3ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ3TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ3SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ4:
            {
                FL_ADC_SetACQ4ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ4TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ4SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ5:
            {
                FL_ADC_SetACQ5ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ5TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ5SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ6:
            {
                FL_ADC_SetACQ6ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ6TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ6SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ7:
            {
                FL_ADC_SetACQ7ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ7TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ7SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ8:
            {
                FL_ADC_SetACQ8ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ8TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ8SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ9:
            {
                FL_ADC_SetACQ9ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ9TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ9SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ10:
            {
                FL_ADC_SetACQ10ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ10TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ10SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ11:
            {
                FL_ADC_SetACQ11ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ11TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ11SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ12:
            {
                FL_ADC_SetACQ12ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ12TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ12SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ13:
            {
                FL_ADC_SetACQ13ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ13TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ13SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ14:
            {
                FL_ADC_SetACQ14ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ14TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ14SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            case FL_ADC_ACQ15:
            {
                FL_ADC_SetACQ15ChannelSelect(ADCx, ADC_InitStruct->channelSelect);
                FL_ADC_SetACQ15TriggerSource(ADCx, ADC_InitStruct->trigerSource);
                FL_ADC_SetACQ15SamplingTime(ADCx, ADC_InitStruct->channelTime);
                break;
            }
            default :
            {
                status = FL_FAIL;
            }
        }
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  设置 ADC_InitStruct 为默认配置
  * @param  ADC_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_ADC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_ADC_StructInit(FL_ADC_InitTypeDef *ADC_InitStruct)
{
    if(ADC_InitStruct != NULL)
    {
        ADC_InitStruct->trigerSource = FL_ADC_ACQ_TRGI_SOFE_TRG;
        ADC_InitStruct->channelTime = FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK;
        ADC_InitStruct->channelSelect = FL_ADC_ACQ_SELECT_CHANNEL_INA0;
    }
}

/**
  * @}
  */

#endif /* FL_ADC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
