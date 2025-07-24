/**
  ****************************************************************************************************
  * @file    fm33fk5xx_fl_cmu.c
  * @author  FMSH Application Team
  * @brief   Src file of CMU FL Module
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

/** @addtogroup EPWM
  * @{
  */

#ifdef FL_EPWM_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup EPWM_FL_Private_Macros
  * @{
  */
#define IS_EPWM_INSTANCE(TIMx)                     (((TIMx) == EPWM0) ||((TIMx) == EPWM1) ||((TIMx) == EPWM2) ||((TIMx) == EPWM3) )

#define IS_FL_EPWM_COUNTERMODE(__VALUE__)                   (((__VALUE__)==FL_EPWM_COUNTER_MODE_UP)\
                                                          ||((__VALUE__)==FL_EPWM_COUNTER_MODE_DOWN)\
                                                          ||((__VALUE__)==FL_EPWM_COUNTER_MODE_UP_DOWN)\
                                                          ||((__VALUE__)==FL_EPWM_COUNTER_MODE_STOP))

#define IS_FL_EPWM_CLKSOURCE(__VALUE__)                   (((__VALUE__)==FL_CMU_EPWM_CLK_SOURCE_APBCLK)\
                                                          ||((__VALUE__)==FL_CMU_EPWM_CLK_SOURCE_USB_BCK_PSC)\
                                                          ||((__VALUE__)==FL_CMU_EPWM_CLK_SOURCE_PLLx2)\
                                                          ||((__VALUE__)==FL_CMU_EPWM_CLK_SOURCE_PLLx1))

#define IS_FL_EPWM_DEBUGMODE(__VALUE__)                   (((__VALUE__)==FL_EPWM_DEBUG_STOP)\
                                                          ||((__VALUE__)==FL_EPWM_DEBUG_STOP_UPDATE)\
                                                          ||((__VALUE__)==FL_EPWM_DEBUG_FREE_RUN))

#define IS_FL_EPWM_STARTCOUNTDIR(__VALUE__)               (((__VALUE__)==FL_EPWM_COUNTER_SYNC_DIR_UP)\
                                                          ||((__VALUE__)==FL_EPWM_COUNTER_SYNC_DIR_DOWN))

#define IS_FL_EPWM_CHANNEL(__VALUE__)                     (((__VALUE__)==FL_EPWM_CHANNEL_A)\
                                                          ||((__VALUE__)==FL_EPWM_CHANNEL_B))

#define IS_FL_EPWM_OCLOADTRIGGER(__VALUE__)               (((__VALUE__)==FL_EPWM_OC_LOAD_CNT_0)\
                                                           ||((__VALUE__)==FL_EPWM_OC_LOAD_CNT_PRD)\
                                                           ||((__VALUE__)==FL_EPWM_OC_LOAD_SYNC_RISING))

#define IS_FL_EPWM_OCMODE_CNTEQUALCMPB_DIRDOWN(__VALUE__)                (((__VALUE__)==FL_EPWM_OC_MODE_FROZEN)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_TOGGLE))

#define IS_FL_EPWM_OCMODE_CNTEQUALCMPB_DIRUP(__VALUE__)                 (((__VALUE__)==FL_EPWM_OC_MODE_FROZEN)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_TOGGLE))

#define IS_FL_EPWM_OCMODE_CNTEQUALCMPA_DIRDOWN(__VALUE__)               (((__VALUE__)==FL_EPWM_OC_MODE_FROZEN)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_TOGGLE))

#define IS_FL_EPWM_OCMODE_CNTEQUALCMPA_DIRUP(__VALUE__)                 (((__VALUE__)==FL_EPWM_OC_MODE_FROZEN)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_TOGGLE))

#define IS_FL_EPWM_OCMODE_CNTEQUALPRD(__VALUE__)                         (((__VALUE__)==FL_EPWM_OC_MODE_FROZEN)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_TOGGLE))

#define IS_FL_EPWM_OCMODE_CNTEQUALZRO(__VALUE__)                         (((__VALUE__)==FL_EPWM_OC_MODE_FROZEN)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_OC_MODE_TOGGLE))

#define IS_FL_EPWM_CMPCHANNEL(__VALUE__)                                 (((__VALUE__)==FL_EPWM_COMPAREA)\
                                                                         ||((__VALUE__)==FL_EPWM_COMPAREB)\
                                                                         ||((__VALUE__)==FL_EPWM_COMPAREC)\
                                                                         ||((__VALUE__)==FL_EPWM_COMPARED))

#define IS_FL_EPWM_LOADCMPTRIGGER(__VALUE__)                             (((__VALUE__)==FL_EPWM_CMPD_LOAD_CNT_0)\
                                                                         ||((__VALUE__)==FL_EPWM_CMPD_LOAD_CNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_CMPD_LOAD_SYNC_RISING))

#define IS_FL_EPWM_REDSRC(__VALUE__)                                     (((__VALUE__)==FL_EPWM_DEADBAND_RISING_EPWMB)\
                                                                         ||((__VALUE__)==FL_EPWM_DEADBAND_RISING_EPWMA))

#define IS_FL_EPWM_FEDSRC(__VALUE__)                                     (((__VALUE__)==FL_EPWM_DEADBAND_FALLING_EPWMB)\
                                                                         ||((__VALUE__)==FL_EPWM_DEADBAND_FALLING_EPWMA))

#define IS_FL_EPWM_CHANNELBOUTPUTPOLAR(__VALUE__)                        (((__VALUE__)==FL_EPWM_DEADBAND_PORLARITY_NORMAL)\
                                                                         ||((__VALUE__)==FL_EPWM_DEADBAND_PORLARITY_REVERSE))

#define IS_FL_EPWM_CHANNELAOUTPUTPOLAR(__VALUE__)                        (((__VALUE__)==FL_EPWM_DEADBAND_PORLARITY_NORMAL)\
                                                                         ||((__VALUE__)==FL_EPWM_DEADBAND_PORLARITY_REVERSE))

#define IS_FL_EPWM_CHPHW_MASK(__VALUE__)                                 (__VALUE__<=63U)
#define IS_FL_EPWM_CHPLW_MASK(__VALUE__)                                 (__VALUE__<=63U)
#define IS_FL_EPWM_OSP_MASK(__VALUE__)                                   (__VALUE__<=15U)

#define IS_FL_EPWM_DCBEVTACTIVE(__VALUE__)                             (((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DISABLE)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCL_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCL_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW))

#define IS_FL_EPWM_DCAEVTACTIVE(__VALUE__)                              (((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DISABLE)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCL_LOW)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCL_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH)\
                                                                         ||((__VALUE__)==FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW))

#define IS_FL_EPWM_DCBLINPUTSRC(__VALUE__)                               (((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK1)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK2)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK3)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP1OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP2OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP3OUT))

#define IS_FL_EPWM_DCBHINPUTSRC(__VALUE__)                               (((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK1)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK2)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK3)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP1OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP2OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP3OUT))

#define IS_FL_EPWM_DCALINPUTSRC(__VALUE__)                               (((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK1)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK2)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK3)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP1OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP2OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP3OUT))

#define IS_FL_EPWM_DCAHINPUTSRC(__VALUE__)                               (((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK1)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK2)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_BK3)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP1OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP2OUT)\
                                                                         ||((__VALUE__)==FL_EPWM_INPUT_SOURCE_COMP3OUT))

#define IS_FL_EPWM_PCNTSEL(__VALUE__)                                    (((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_0)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_0ORCNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_DOWN))

#define IS_FL_EPWM_SOCBSEL(__VALUE__)                                     (((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_DCBEVT1)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_0)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_0ORCNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_DOWN))

#define IS_FL_EPWM_SOCASEL(__VALUE__)                                     (((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_DCAEVT1)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_0)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_0ORCNT_PRD)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_DOWN)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_UP)\
                                                                         ||((__VALUE__)==FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_DOWN))

#define IS_FL_EPWM_PCNTPSC(__VALUE__)                                    (((__VALUE__)==FL_EPWM_PULSE_EVENT_N0)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N1)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N2)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N3)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N4)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N5)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N6)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N7)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N8)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N9)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N10)\
                                                                         ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N11)\
                                                                          ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N12)\
                                                                           ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N13)\
                                                                            ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N14)\
                                                                             ||((__VALUE__)==FL_EPWM_PULSE_EVENT_N15))

#define IS_FL_EPWM_SOCBPSC(__VALUE__)                                    (((__VALUE__)==FL_EPWM_SOCB_EVENT_N0)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N1)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N2)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N3)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N4)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N5)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N6)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N7)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N8)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N9)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N10)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N11)\
                                                                          ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N12)\
                                                                           ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N13)\
                                                                            ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N14)\
                                                                             ||((__VALUE__)==FL_EPWM_SOCB_EVENT_N15))

#define IS_FL_EPWM_SOCAPSC(__VALUE__)                                    (((__VALUE__)==FL_EPWM_SOCA_EVENT_N0)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N1)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N2)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N3)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N4)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N5)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N6)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N7)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N8)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N9)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N10)\
                                                                         ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N11)\
                                                                          ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N12)\
                                                                           ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N13)\
                                                                            ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N14)\
                                                                             ||((__VALUE__)==FL_EPWM_SOCA_EVENT_N15))

#define IS_FL_EPWM_RED_MASK(__VALUE__)                                 (__VALUE__<=1023U)
#define IS_FL_EPWM_FED_MASK(__VALUE__)                                 (__VALUE__<=1023U)

/**
  * @brief  配置基本定时器时基单元（内部时钟源）.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_EPWM_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */

FL_ErrorStatus FL_EPWM_Init(EPWM_Type *TIMx, FL_EPWM_InitTypeDef *TIM_InitStruct)
{

    /* 参数检查 */
    assert_param(IS_EPWM_INSTANCE(TIMx));
    assert_param(IS_FL_EPWM_COUNTERMODE(TIM_InitStruct->counterMode));
    assert_param(IS_FL_EPWM_DEBUGMODE(TIM_InitStruct->DBGMode));
    assert_param(IS_FL_EPWM_STARTCOUNTDIR(TIM_InitStruct->startCounterDir));
    assert_param(IS_FL_EPWM_CLKSOURCE(TIM_InitStruct->clockSrc));
    /* 时钟总线使能配置 */
    if(TIMx == EPWM0)
    {
        FL_CMU_SetEPWMClockSource(TIM_InitStruct->clockSrc);
        FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_EPWM);
        FL_CMU_EnableGroup2OperationClock(FL_CMU_OPCLK_EPWM0);
    }
    else if(TIMx == EPWM1)
    {
        FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_EPWM);
        FL_CMU_SetEPWMClockSource(TIM_InitStruct->clockSrc);
        FL_CMU_EnableGroup2OperationClock(FL_CMU_OPCLK_EPWM1);
    }
    else if(TIMx == EPWM2)
    {
        FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_EPWM);
        FL_CMU_SetEPWMClockSource(TIM_InitStruct->clockSrc);
        FL_CMU_EnableGroup2OperationClock(FL_CMU_OPCLK_EPWM2);
    }
    else if(TIMx == EPWM3)
    {
        FL_CMU_EnableGroup4BusClock(FL_CMU_GROUP4_BUSCLK_EPWM);
        FL_CMU_SetEPWMClockSource(TIM_InitStruct->clockSrc);
        FL_CMU_EnableGroup2OperationClock(FL_CMU_OPCLK_EPWM3);
    }
    if(TIM_InitStruct->periodAutoReload == FL_ENABLE)
    { FL_EPWM_EnablePRDPreload(TIMx); }
    else if(TIM_InitStruct->periodAutoReload == FL_DISABLE)
    { FL_EPWM_DisablePRDPreload(TIMx); }

    if(TIM_InitStruct->phaseLoad == FL_ENABLE)
    { FL_EPWM_EnablePhaseReload(TIMx); }
    else if(TIM_InitStruct->phaseLoad == FL_DISABLE)
    { FL_EPWM_DisablePhaseReload(TIMx); }

    FL_EPWM_SetCounterMode(TIMx, TIM_InitStruct->counterMode);
    FL_EPWM_SetDebugMode(TIMx, TIM_InitStruct->DBGMode);
    FL_EPWM_SetInitialPhaseDirection(TIMx, TIM_InitStruct->startCounterDir);
    FL_EPWM_WriteAutoReload(TIMx, TIM_InitStruct->period);
    FL_EPWM_WritePhaseLoad(TIMx, TIM_InitStruct->phase);
    FL_EPWM_WritePrescaler(TIMx, TIM_InitStruct->prescaler);

    return FL_PASS;
}
/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_EPWM_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_StructInit(FL_EPWM_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->clockSrc = FL_CMU_EPWM1_CLK_SOURCE_APBCLK;
    TIM_InitStruct->counterMode = FL_EPWM_COUNTER_MODE_UP;
    TIM_InitStruct->DBGMode = FL_EPWM_DEBUG_FREE_RUN;
    TIM_InitStruct->period = 65535U;
    TIM_InitStruct->periodAutoReload = FL_ENABLE;
    TIM_InitStruct->phase = 0;
    TIM_InitStruct->phaseLoad = FL_ENABLE;
    TIM_InitStruct->prescaler = 8 - 1;
    TIM_InitStruct->startCounterDir = FL_EPWM_COUNTER_SYNC_DIR_UP;

}

/**
  * @brief  配置输出寄存器单元.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_EPWM_OC_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_EPWM_OC_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_OC_InitTypeDef *TIM_InitStruct)
{
    assert_param(IS_FL_EPWM_CHANNEL(channel));
    assert_param(IS_FL_EPWM_OCLOADTRIGGER(TIM_InitStruct->OCLoadtrigger));
    assert_param(IS_FL_EPWM_OCMODE_CNTEQUALCMPB_DIRDOWN(TIM_InitStruct->OCMode_CNTEqualCMPB_DirDown));
    assert_param(IS_FL_EPWM_OCMODE_CNTEQUALCMPB_DIRUP(TIM_InitStruct->OCMode_CNTEqualCMPB_DirUp));
    assert_param(IS_FL_EPWM_OCMODE_CNTEQUALCMPA_DIRDOWN(TIM_InitStruct->OCMode_CNTEqualCMPA_DirDown));
    assert_param(IS_FL_EPWM_OCMODE_CNTEQUALCMPA_DIRUP(TIM_InitStruct->OCMode_CNTEqualCMPA_DirUp));
    assert_param(IS_FL_EPWM_OCMODE_CNTEQUALPRD(TIM_InitStruct->OCMode_CNTEqualPRD));
    assert_param(IS_FL_EPWM_OCMODE_CNTEQUALZRO(TIM_InitStruct->OCMode_CNTEqualZRO));
    if(TIM_InitStruct->OCautoReload == FL_ENABLE)
    { FL_EPWM_OC_EnablePreload(TIMx, channel); }
    else if(TIM_InitStruct->OCautoReload == FL_DISABLE)
    { FL_EPWM_OC_DisablePreload(TIMx, channel); }

    FL_EPWM_OC_SetpreloadTrigger(TIMx, TIM_InitStruct->OCLoadtrigger, channel);
    FL_EPWM_SetOCMode_CNTEqualCMPB_DirDown(TIMx, TIM_InitStruct->OCMode_CNTEqualCMPB_DirDown, channel);
    FL_EPWM_SetOCMode_CNTEqualCMPB_DirUp(TIMx, TIM_InitStruct->OCMode_CNTEqualCMPB_DirUp, channel);
    FL_EPWM_SetOCMode_CNTEqualCMPA_DirDown(TIMx, TIM_InitStruct->OCMode_CNTEqualCMPA_DirDown, channel);
    FL_EPWM_SetOCMode_CNTEqualCMPA_DirUp(TIMx, TIM_InitStruct->OCMode_CNTEqualCMPA_DirUp, channel);
    FL_EPWM_SetOCMode_CNTEqualPRD(TIMx, TIM_InitStruct->OCMode_CNTEqualPRD, channel);
    FL_EPWM_SetOCMode_CNTEqualZero(TIMx, TIM_InitStruct->OCMode_CNTEqualZRO, channel);
    return FL_PASS;
}

/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_OC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_OC_StructInit(FL_EPWM_OC_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->OCautoReload = FL_ENABLE;
    TIM_InitStruct->OCLoadtrigger =  FL_EPWM_OC_LOAD_CNT_0;
    TIM_InitStruct->OCMode_CNTEqualCMPA_DirDown = FL_EPWM_OC_MODE_TOGGLE;
    TIM_InitStruct->OCMode_CNTEqualCMPA_DirUp = FL_EPWM_OC_MODE_TOGGLE;
    TIM_InitStruct->OCMode_CNTEqualCMPB_DirDown = FL_EPWM_OC_MODE_TOGGLE;
    TIM_InitStruct->OCMode_CNTEqualCMPB_DirUp =  FL_EPWM_OC_MODE_TOGGLE;
    TIM_InitStruct->OCMode_CNTEqualPRD =  FL_EPWM_OC_MODE_TOGGLE;
    TIM_InitStruct->OCMode_CNTEqualZRO =  FL_EPWM_OC_MODE_TOGGLE;

}
/**
  * @brief  配置输出寄存器单元.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_EPWM_CMP_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_EPWM_CMP_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_CMP_InitTypeDef *TIM_InitStruct)
{
    assert_param(IS_FL_EPWM_CMPCHANNEL(channel));
    assert_param(IS_FL_EPWM_OCLOADTRIGGER(TIM_InitStruct->CMPLoadTrigger));

    switch(channel)
    {
        case  FL_EPWM_COMPARED:
            if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareDPreload(TIMx); }
            else if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareDPreload(TIMx); }
            FL_EPWM_SetCompareDPreloadTrigger(TIMx, TIM_InitStruct->CMPLoadTrigger);
            break;
        case  FL_EPWM_COMPAREC:
            if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareCPreload(TIMx); }
            else if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareCPreload(TIMx); }
            FL_EPWM_SetCompareCPreloadTrigger(TIMx, TIM_InitStruct->CMPLoadTrigger);
            break;
        case  FL_EPWM_COMPAREB:
            if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareBPreload(TIMx); }
            else if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareBPreload(TIMx); }
            FL_EPWM_SetCompareBPreloadTrigger(TIMx, TIM_InitStruct->CMPLoadTrigger);
            break;
        case  FL_EPWM_COMPAREA:
            if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareAPreload(TIMx); }
            else if(TIM_InitStruct->CMPAutoReload == FL_ENABLE)
            { FL_EPWM_EnableCompareAPreload(TIMx); }
            FL_EPWM_SetCompareAPreloadTrigger(TIMx, TIM_InitStruct->CMPLoadTrigger);
            break;
        default:
            break;
    }

    return FL_PASS;
}

/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_CMP_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_CMP_StructInit(FL_EPWM_CMP_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->CMPAutoReload = FL_ENABLE;
    TIM_InitStruct->CMPLoadTrigger = FL_EPWM_OC_LOAD_CNT_PRD;

}

/**
  * @brief  配置死区寄存器单元.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_ATIM_DT_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_EPWM_DT_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_DT_InitTypeDef *TIM_InitStruct)
{

    assert_param(IS_FL_EPWM_REDSRC(TIM_InitStruct->REDSrc));
    assert_param(IS_FL_EPWM_FEDSRC(TIM_InitStruct->FEDSrc));
    assert_param(IS_FL_EPWM_CHANNELBOUTPUTPOLAR(TIM_InitStruct->ChannelOutputPolar));
    assert_param(IS_FL_EPWM_RED_MASK(TIM_InitStruct->REDDelayTime));
    assert_param(IS_FL_EPWM_FED_MASK(TIM_InitStruct->FEDDelayTime));

    FL_EPWM_WriteDeadbandRisingDelayTime(TIMx, TIM_InitStruct->REDDelayTime);
    FL_EPWM_WriteDeadbandFallingDelayTime(TIMx, TIM_InitStruct->FEDDelayTime);

    FL_EPWM_SetDeadbandRisingDelaySignalSource(TIMx, TIM_InitStruct->REDSrc);
    FL_EPWM_SetDeadbandFallingDelaySignalSource(TIMx, TIM_InitStruct->FEDSrc);

    FL_EPWM_SetDeadbandOutputPolarity(TIMx, TIM_InitStruct->ChannelOutputPolar, channel);
    if(TIM_InitStruct->ChannelBypass == FL_ENABLE)
    { FL_EPWM_EnableDeadbandBypass(TIMx, channel); }
    else if(TIM_InitStruct->ChannelBypass == FL_DISABLE)
    { FL_EPWM_DisableDeadbandBypass(TIMx, channel); }

    return FL_PASS;
}

/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_DT_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_DT_StructInit(FL_EPWM_DT_InitTypeDef *TIM_InitStruct)
{
    TIM_InitStruct->ChannelBypass = FL_ENABLE;
    TIM_InitStruct->ChannelOutputPolar = FL_EPWM_DEADBAND_PORLARITY_NORMAL;
    TIM_InitStruct->FEDDelayTime = 512U;
    TIM_InitStruct->REDDelayTime = 512U;
    TIM_InitStruct->FEDSrc = FL_EPWM_DEADBAND_FALLING_EPWMB;
    TIM_InitStruct->REDSrc =  FL_EPWM_DEADBAND_RISING_EPWMB;
}

/**
  * @brief  配置死区寄存器单元.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_ATIM_CHP_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_EPWM_CHP_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_CHP_InitTypeDef *TIM_InitStruct)
{

    assert_param(IS_FL_EPWM_CHPHW_MASK(TIM_InitStruct->chopperHighWidth));
    assert_param(IS_FL_EPWM_CHPLW_MASK(TIM_InitStruct->chopperLowWidth));
    assert_param(IS_FL_EPWM_OSP_MASK(TIM_InitStruct->oneShotPulseWidth));

    FL_EPWM_WriteChopperCarrierHighWidth(TIMx, TIM_InitStruct->chopperHighWidth);
    FL_EPWM_WriteChopperCarrierLowWidth(TIMx, TIM_InitStruct->chopperLowWidth);
    FL_EPWM_WriteOneShotPulseWidth(TIMx, TIM_InitStruct->oneShotPulseWidth);
    if(TIM_InitStruct->oneShotMode == FL_ENABLE)
    { FL_EPWM_EnableOneShotPulse(TIMx); }
    else if(TIM_InitStruct->oneShotMode == FL_DISABLE)
    { FL_EPWM_DisableOneShotPulse(TIMx); }

    if(TIM_InitStruct->channelChopper == FL_ENABLE)
    { FL_EPWM_EnableChopper(TIMx, channel); }
    else if(TIM_InitStruct->channelChopper == FL_DISABLE)
    { FL_EPWM_EnableChopper(TIMx, channel); }

    return FL_PASS;
}

/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_CHP_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_CHP_StructInit(FL_EPWM_CHP_InitTypeDef *TIM_InitStruct)
{

    TIM_InitStruct->channelChopper = FL_DISABLE;
    TIM_InitStruct->chopperHighWidth = 10U;
    TIM_InitStruct->chopperLowWidth = 10U;
    TIM_InitStruct->oneShotMode =  FL_DISABLE;
    TIM_InitStruct->oneShotPulseWidth = 5U;
}

/**
  * @brief  配置死区寄存器单元.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_ATIM_DCEvent_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_EPWM_DCEvent_Init(EPWM_Type *TIMx, uint32_t event, FL_EPWM_DCEvent_InitTypeDef *TIM_InitStruct)
{

    assert_param(IS_FL_EPWM_DCBEVTACTIVE(TIM_InitStruct->DCBEVTActive));
    assert_param(IS_FL_EPWM_DCAEVTACTIVE(TIM_InitStruct->DCAEVTActive));
    assert_param(IS_FL_EPWM_DCBLINPUTSRC(TIM_InitStruct->DCBLInputSrc));
    assert_param(IS_FL_EPWM_DCBHINPUTSRC(TIM_InitStruct->DCBHInputSrc));
    assert_param(IS_FL_EPWM_DCALINPUTSRC(TIM_InitStruct->DCALInputSrc));
    assert_param(IS_FL_EPWM_DCAHINPUTSRC(TIM_InitStruct->DCAHInputSrc));

    FL_EPWM_SetDCBBreakEvent(TIMx, TIM_InitStruct->DCBEVTActive, event);
    FL_EPWM_SetDCABreakEvent(TIMx, TIM_InitStruct->DCAEVTActive, event);
    FL_EPWM_SetDCALInputSource(TIMx, TIM_InitStruct->DCALInputSrc);
    FL_EPWM_SetDCAHInputSource(TIMx, TIM_InitStruct->DCAHInputSrc);
    FL_EPWM_SetDCBLInputSource(TIMx, TIM_InitStruct->DCBLInputSrc);
    FL_EPWM_SetDCBHInputSource(TIMx, TIM_InitStruct->DCBHInputSrc);

    return FL_PASS;
}

/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_CHP_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_DCEvent_StructInit(FL_EPWM_DCEvent_InitTypeDef *TIM_InitStruct)
{

    TIM_InitStruct->DCAEVTActive = FL_DISABLE ;
    TIM_InitStruct->DCBEVTActive = FL_DISABLE ;
    TIM_InitStruct->DCBLInputSrc = FL_EPWM_INPUT_SOURCE_BK1;
    TIM_InitStruct->DCALInputSrc = FL_EPWM_INPUT_SOURCE_BK2;
    TIM_InitStruct->DCBHInputSrc =  FL_EPWM_INPUT_SOURCE_BK1;
    TIM_InitStruct->DCBLInputSrc = FL_EPWM_INPUT_SOURCE_BK2;
}

/**
  * @brief  配置死区寄存器单元.
  * @param  TIMx Timer Instance
  * @param  TIM_InitStruct 指向一个 @ref FL_ATIM_SOC_InitTypeDef(时基配置结构体)
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 成功
  */
FL_ErrorStatus FL_EPWM_SOC_Init(EPWM_Type *TIMx, FL_EPWM_SOC_InitTypeDef *TIM_InitStruct)
{

    assert_param(IS_FL_EPWM_PCNTSEL(TIM_InitStruct->pulseCNTInterruptSrc));
    assert_param(IS_FL_EPWM_SOCBSEL(TIM_InitStruct->SOCBInputSrc));
    assert_param(IS_FL_EPWM_SOCASEL(TIM_InitStruct->SOCAInputSrc));
    assert_param(IS_FL_EPWM_PCNTPSC(TIM_InitStruct->pulseCNTEventPsc));
    assert_param(IS_FL_EPWM_SOCBPSC(TIM_InitStruct->SOCBEventPsc));
    assert_param(IS_FL_EPWM_SOCAPSC(TIM_InitStruct->SOCAEventPsc));

    FL_EPWM_SetPulseCountInterruptSignalSource(TIMx, TIM_InitStruct->pulseCNTInterruptSrc);
    FL_EPWM_SetADCSOCBSignalSource(TIMx, TIM_InitStruct->SOCBInputSrc);
    FL_EPWM_SetADCSOCASignalSource(TIMx, TIM_InitStruct->SOCAInputSrc);

    FL_EPWM_SetPulseCountInterruptTriggerCondition(TIMx, TIM_InitStruct->pulseCNTEventPsc);
    FL_EPWM_SetSOCBOutputCondition(TIMx, TIM_InitStruct->SOCBEventPsc);
    FL_EPWM_SetSOCAOutputCondition(TIMx, TIM_InitStruct->SOCAEventPsc);

    if(TIM_InitStruct->SOCBEventState == FL_ENABLE)
    { FL_EPWM_EnableADCSOCBEvent(TIMx); }
    else if(TIM_InitStruct->SOCBEventState == FL_DISABLE)
    { FL_EPWM_DisableADCSOCBEvent(TIMx); }

    if(TIM_InitStruct->SOCAEventState == FL_ENABLE)
    { FL_EPWM_EnableADCSOCAEvent(TIMx); }
    else if(TIM_InitStruct->SOCAEventState == FL_DISABLE)
    { FL_EPWM_DisableADCSOCAEvent(TIMx); }

    return FL_PASS;
}

/**
  * @brief  设置 EPWM_InitStruct 为默认配置
  * @param  EPWM_InitStruct 指向需要将值设置为默认配置的结构体 @ref FL_SOC_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPWM_SOC_StructInit(FL_EPWM_SOC_InitTypeDef *TIM_InitStruct)
{

    TIM_InitStruct->pulseCNTEventPsc = FL_EPWM_PULSE_EVENT_N1;
    TIM_InitStruct->pulseCNTInterruptSrc =  FL_EPWM_COUNT_IE_SOURCE_CNT_PRD;
    TIM_InitStruct->SOCAEventPsc = FL_EPWM_SOCA_EVENT_N1;
    TIM_InitStruct->SOCAEventState = FL_ENABLE ;
    TIM_InitStruct->SOCAInputSrc = FL_EPWM_ADC_SOCA_SOURCE_CNT_PRD;
    TIM_InitStruct->SOCBEventPsc = FL_EPWM_SOCB_EVENT_N1;
    TIM_InitStruct->SOCBEventState = FL_ENABLE ;
    TIM_InitStruct->SOCBInputSrc = FL_EPWM_ADC_SOCB_SOURCE_CNT_PRD;

}

#endif /* FL_EPWM_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
