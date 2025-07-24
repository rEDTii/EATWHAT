/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_adc.h
  * @author  FMSH Application Team
  * @brief   Head file of ADC FL Module
  *******************************************************************************************************
  * @attention
  *
  * Copyright (c) [2019] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under the Mulan PSL v1.
  * can use this software according to the terms and conditions of the Mulan PSL v1.
  * You may obtain a copy of Mulan PSL v1 at:
  * http://license.coscl.org.cn/MulanPSL
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR
  * PURPOSE.
  * See the Mulan PSL v1 for more details.
  *
  *******************************************************************************************************
  */

/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FK5XX_FL_ADC_H
#define __FM33FK5XX_FL_ADC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_ES_INIT ADC Exported Init structures
  * @{
  */
#define ADC_VREF                    (*((uint16_t *)(0x0010FB0C)))   //VREF1P0
#define ADC_TS_VOL                  (*((uint16_t *)(0x0010FB10)))   //PTAT
/**
  * @brief FL ADC Init Sturcture definition
  */
typedef struct
{
    /** ADC工作时钟源选择 */
    uint32_t clockSource;
    /** ADCCLK预分频配置 */
    uint32_t clockPrescaler;
    /** ADC基准源选择 */
    uint32_t referenceSource;
    /** 转换模式配置 */
    uint32_t trigMode;
    /** 等待模式配置 */
    FL_FunState waitMode;
    /** 覆盖模式配置 */
    FL_FunState overrunMode;
    /** 过采样使能配置 */
    uint32_t oversamplingMode;
    /** 过采样率配置 */
    uint32_t overSampingMultiplier;

} FL_ADC_CommonInitTypeDef;

typedef struct
{
    /** 触发源选择 */
    uint32_t trigerSource;
    /** 采样通道选择*/
    uint32_t channelSelect;
    /** 通道采样时间配置 */
    uint32_t channelTime;
} FL_ADC_InitTypeDef;
/**
  * @
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Constants ADC Exported Constants
  * @{
  */
#define    ADC_ACQ_ISR_OVR_Pos                                    (16U)
#define    ADC_ACQ_ISR_OVR_Msk                                    (0xffffU << ADC_ACQ_ISR_OVR_Pos)
#define    ADC_ACQ_ISR_OVR                                        ADC_ACQ_ISR_OVR_Msk

#define    ADC_ACQ_ISR_EOC_Pos                                    (0U)
#define    ADC_ACQ_ISR_EOC_Msk                                    (0xffffU << ADC_ACQ_ISR_EOC_Pos)
#define    ADC_ACQ_ISR_EOC                                        ADC_ACQ_ISR_EOC_Msk

#define    ADC_ACQ_IER_OVRIE_Pos                                  (16U)
#define    ADC_ACQ_IER_OVRIE_Msk                                  (0xffffU << ADC_ACQ_IER_OVRIE_Pos)
#define    ADC_ACQ_IER_OVRIE                                      ADC_ACQ_IER_OVRIE_Msk

#define    ADC_ACQ_IER_EOCIE_Pos                                  (0U)
#define    ADC_ACQ_IER_EOCIE_Msk                                  (0xffffU << ADC_ACQ_IER_EOCIE_Pos)
#define    ADC_ACQ_IER_EOCIE                                      ADC_ACQ_IER_EOCIE_Msk

#define    ADC_GISR_ACQ_ID_Pos                                    (4U)
#define    ADC_GISR_ACQ_ID_Msk                                    (0x1fU << ADC_GISR_ACQ_ID_Pos)
#define    ADC_GISR_ACQ_ID                                        ADC_GISR_ACQ_ID_Msk

#define    ADC_GISR_OSF_Pos                                       (3U)
#define    ADC_GISR_OSF_Msk                                       (0x1U << ADC_GISR_OSF_Pos)
#define    ADC_GISR_OSF                                           ADC_GISR_OSF_Msk

#define    ADC_GISR_EOCNT_Pos                                     (2U)
#define    ADC_GISR_EOCNT_Msk                                     (0x1U << ADC_GISR_EOCNT_Pos)
#define    ADC_GISR_EOCNT                                         ADC_GISR_EOCNT_Msk

#define    ADC_GISR_BUSY_Pos                                      (1U)
#define    ADC_GISR_BUSY_Msk                                      (0x1U << ADC_GISR_BUSY_Pos)
#define    ADC_GISR_BUSY                                          ADC_GISR_BUSY_Msk

#define    ADC_GIER_EOCNTIE_Pos                                   (2U)
#define    ADC_GIER_EOCNTIE_Msk                                   (0x1U << ADC_GIER_EOCNTIE_Pos)
#define    ADC_GIER_EOCNTIE                                       ADC_GIER_EOCNTIE_Msk

#define    ADC_CR1_ACQEN_Pos                                      (16U)
#define    ADC_CR1_ACQEN_Msk                                      (0xffffU << ADC_CR1_ACQEN_Pos)
#define    ADC_CR1_ACQEN                                          ADC_CR1_ACQEN_Msk

#define    ADC_CR1_RR_SWRST_Pos                                   (1U)
#define    ADC_CR1_RR_SWRST_Msk                                   (0x1U << ADC_CR1_RR_SWRST_Pos)
#define    ADC_CR1_RR_SWRST                                       ADC_CR1_RR_SWRST_Msk

#define    ADC_CR1_ADEN_Pos                                       (0U)
#define    ADC_CR1_ADEN_Msk                                       (0x1U << ADC_CR1_ADEN_Pos)
#define    ADC_CR1_ADEN                                           ADC_CR1_ADEN_Msk

#define    ADC_CR2_SWTRIG_Pos                                     (0U)
#define    ADC_CR2_SWTRIG_Msk                                     (0xffffU << ADC_CR2_SWTRIG_Pos)
#define    ADC_CR2_SWTRIG                                         ADC_CR2_SWTRIG_Msk

#define    ADC_CFGR1_RPTLEN_Pos                                   (16U)
#define    ADC_CFGR1_RPTLEN_Msk                                   (0xffffU << ADC_CFGR1_RPTLEN_Pos)
#define    ADC_CFGR1_RPTLEN                                       ADC_CFGR1_RPTLEN_Msk

#define    ADC_CFGR1_CONV_CYCLE_Pos                               (8U)
#define    ADC_CFGR1_CONV_CYCLE_Msk                               (0xffU << ADC_CFGR1_CONV_CYCLE_Pos)
#define    ADC_CFGR1_CONV_CYCLE                                   ADC_CFGR1_CONV_CYCLE_Msk

#define    ADC_CFGR1_SYNC_MODE_Pos                                (4U)
#define    ADC_CFGR1_SYNC_MODE_Msk                                (0x1U << ADC_CFGR1_SYNC_MODE_Pos)
#define    ADC_CFGR1_SYNC_MODE                                    ADC_CFGR1_SYNC_MODE_Msk

#define    ADC_CFGR1_INJ_MODE_Pos                                 (3U)
#define    ADC_CFGR1_INJ_MODE_Msk                                 (0x1U << ADC_CFGR1_INJ_MODE_Pos)
#define    ADC_CFGR1_INJ_MODE                                     ADC_CFGR1_INJ_MODE_Msk

#define    ADC_CFGR1_REFNSEL_Pos                                  (2U)
#define    ADC_CFGR1_REFNSEL_Msk                                  (0x1U << ADC_CFGR1_REFNSEL_Pos)
#define    ADC_CFGR1_REFNSEL                                      ADC_CFGR1_REFNSEL_Msk

#define    ADC_CFGR1_PEFSEL_Pos                                   (0U)
#define    ADC_CFGR1_PEFSEL_Msk                                   (0x3U << ADC_CFGR1_PEFSEL_Pos)
#define    ADC_CFGR1_PEFSEL                                       ADC_CFGR1_PEFSEL_Msk

#define    ADC_CFGR2_AVGR_Pos                                     (18U)
#define    ADC_CFGR2_AVGR_Msk                                     (0x3U << ADC_CFGR2_AVGR_Pos)
#define    ADC_CFGR2_AVGR                                         ADC_CFGR2_AVGR_Msk

#define    ADC_CFGR2_AVGEN_Pos                                    (16U)
#define    ADC_CFGR2_AVGEN_Msk                                    (0x3U << ADC_CFGR2_AVGEN_Pos)
#define    ADC_CFGR2_AVGEN                                        ADC_CFGR2_AVGEN_Msk

#define    ADC_CFGR2_WAIT_Pos                                     (11U)
#define    ADC_CFGR2_WAIT_Msk                                     (0x1U << ADC_CFGR2_WAIT_Pos)
#define    ADC_CFGR2_WAIT                                         ADC_CFGR2_WAIT_Msk

#define    ADC_CFGR2_TMOD_Pos                                     (9U)
#define    ADC_CFGR2_TMOD_Msk                                     (0x3U << ADC_CFGR2_TMOD_Pos)
#define    ADC_CFGR2_TMOD                                         ADC_CFGR2_TMOD_Msk

#define    ADC_CFGR2_OVRM_Pos                                     (8U)
#define    ADC_CFGR2_OVRM_Msk                                     (0x1U << ADC_CFGR2_OVRM_Pos)
#define    ADC_CFGR2_OVRM                                         ADC_CFGR2_OVRM_Msk

#define    ADC_CFGR2_DMAEN_Pos                                    (0U)
#define    ADC_CFGR2_DMAEN_Msk                                    (0x1U << ADC_CFGR2_DMAEN_Pos)
#define    ADC_CFGR2_DMAEN                                        ADC_CFGR2_DMAEN_Msk

#define    ADC_PRICR_INJC_Pos                                     (0U)
#define    ADC_PRICR_INJC_Msk                                     (0xfU << ADC_PRICR_INJC_Pos)
#define    ADC_PRICR_INJC                                         ADC_PRICR_INJC_Msk

#define    ADC_DMR_DM14_Pos                                       (7U)
#define    ADC_DMR_DM14_Msk                                       (0x1U << ADC_DMR_DM14_Pos)
#define    ADC_DMR_DM14                                           ADC_DMR_DM14_Msk

#define    ADC_DMR_DM12_Pos                                       (6U)
#define    ADC_DMR_DM12_Msk                                       (0x1U << ADC_DMR_DM12_Pos)
#define    ADC_DMR_DM12                                           ADC_DMR_DM12_Msk

#define    ADC_DMR_DM10_Pos                                       (5U)
#define    ADC_DMR_DM10_Msk                                       (0x1U << ADC_DMR_DM10_Pos)
#define    ADC_DMR_DM10                                           ADC_DMR_DM10_Msk

#define    ADC_DMR_DM8_Pos                                        (4U)
#define    ADC_DMR_DM8_Msk                                        (0x1U << ADC_DMR_DM8_Pos)
#define    ADC_DMR_DM8                                            ADC_DMR_DM8_Msk

#define    ADC_DMR_DM6_Pos                                        (3U)
#define    ADC_DMR_DM6_Msk                                        (0x1U << ADC_DMR_DM6_Pos)
#define    ADC_DMR_DM6                                            ADC_DMR_DM6_Msk

#define    ADC_DMR_DM4_Pos                                        (2U)
#define    ADC_DMR_DM4_Msk                                        (0x1U << ADC_DMR_DM4_Pos)
#define    ADC_DMR_DM4                                            ADC_DMR_DM4_Msk

#define    ADC_DMR_DM2_Pos                                        (1U)
#define    ADC_DMR_DM2_Msk                                        (0x1U << ADC_DMR_DM2_Pos)
#define    ADC_DMR_DM2                                            ADC_DMR_DM2_Msk

#define    ADC_DMR_DM0_Pos                                        (0U)
#define    ADC_DMR_DM0_Msk                                        (0x1U << ADC_DMR_DM0_Pos)
#define    ADC_DMR_DM0                                            ADC_DMR_DM0_Msk

#define    ADC_OSR_POS_CALI_Pos                                   (16U)
#define    ADC_OSR_POS_CALI_Msk                                   (0x1fffU << ADC_OSR_POS_CALI_Pos)
#define    ADC_OSR_POS_CALI                                       ADC_OSR_POS_CALI_Msk

#define    ADC_OSR_NOS_CALI_Pos                                   (0U)
#define    ADC_OSR_NOS_CALI_Msk                                   (0x1fffU << ADC_OSR_NOS_CALI_Pos)
#define    ADC_OSR_NOS_CALI                                       ADC_OSR_NOS_CALI_Msk

#define    ADC_ACQ_SR_REQ_Pos                                     (0U)
#define    ADC_ACQ_SR_REQ_Msk                                     (0xffffU << ADC_ACQ_SR_REQ_Pos)
#define    ADC_ACQ_SR_REQ                                         ADC_ACQ_SR_REQ_Msk

#define    ADC_ACQ0_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ0_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ0_CR_CHSEL_Pos)
#define    ADC_ACQ0_CR_CHSEL                                      ADC_ACQ0_CR_CHSEL_Msk

#define    ADC_ACQ0_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ0_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    ADC_ACQ0_CR_TRIGSEL                                    ADC_ACQ0_CR_TRIGSEL_Msk

#define    ADC_ACQ0_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ0_CR_SMTS_Msk                                   (0xfU << ADC_ACQ0_CR_SMTS_Pos)
#define    ADC_ACQ0_CR_SMTS                                       ADC_ACQ0_CR_SMTS_Msk

#define    ADC_ACQ1_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ1_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ1_CR_CHSEL_Pos)
#define    ADC_ACQ1_CR_CHSEL                                      ADC_ACQ1_CR_CHSEL_Msk

#define    ADC_ACQ1_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ1_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    ADC_ACQ1_CR_TRIGSEL                                    ADC_ACQ1_CR_TRIGSEL_Msk

#define    ADC_ACQ1_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ1_CR_SMTS_Msk                                   (0xfU << ADC_ACQ1_CR_SMTS_Pos)
#define    ADC_ACQ1_CR_SMTS                                       ADC_ACQ1_CR_SMTS_Msk

#define    ADC_ACQ2_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ2_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ2_CR_CHSEL_Pos)
#define    ADC_ACQ2_CR_CHSEL                                      ADC_ACQ2_CR_CHSEL_Msk

#define    ADC_ACQ2_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ2_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    ADC_ACQ2_CR_TRIGSEL                                    ADC_ACQ2_CR_TRIGSEL_Msk

#define    ADC_ACQ2_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ2_CR_SMTS_Msk                                   (0xfU << ADC_ACQ2_CR_SMTS_Pos)
#define    ADC_ACQ2_CR_SMTS                                       ADC_ACQ2_CR_SMTS_Msk

#define    ADC_ACQ3_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ3_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ3_CR_CHSEL_Pos)
#define    ADC_ACQ3_CR_CHSEL                                      ADC_ACQ3_CR_CHSEL_Msk

#define    ADC_ACQ3_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ3_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    ADC_ACQ3_CR_TRIGSEL                                    ADC_ACQ3_CR_TRIGSEL_Msk

#define    ADC_ACQ3_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ3_CR_SMTS_Msk                                   (0xfU << ADC_ACQ3_CR_SMTS_Pos)
#define    ADC_ACQ3_CR_SMTS                                       ADC_ACQ3_CR_SMTS_Msk

#define    ADC_ACQ4_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ4_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ4_CR_CHSEL_Pos)
#define    ADC_ACQ4_CR_CHSEL                                      ADC_ACQ4_CR_CHSEL_Msk

#define    ADC_ACQ4_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ4_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    ADC_ACQ4_CR_TRIGSEL                                    ADC_ACQ4_CR_TRIGSEL_Msk

#define    ADC_ACQ4_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ4_CR_SMTS_Msk                                   (0xfU << ADC_ACQ4_CR_SMTS_Pos)
#define    ADC_ACQ4_CR_SMTS                                       ADC_ACQ4_CR_SMTS_Msk

#define    ADC_ACQ5_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ5_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ5_CR_CHSEL_Pos)
#define    ADC_ACQ5_CR_CHSEL                                      ADC_ACQ5_CR_CHSEL_Msk

#define    ADC_ACQ5_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ5_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    ADC_ACQ5_CR_TRIGSEL                                    ADC_ACQ5_CR_TRIGSEL_Msk

#define    ADC_ACQ5_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ5_CR_SMTS_Msk                                   (0xfU << ADC_ACQ5_CR_SMTS_Pos)
#define    ADC_ACQ5_CR_SMTS                                       ADC_ACQ5_CR_SMTS_Msk

#define    ADC_ACQ6_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ6_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ6_CR_CHSEL_Pos)
#define    ADC_ACQ6_CR_CHSEL                                      ADC_ACQ6_CR_CHSEL_Msk

#define    ADC_ACQ6_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ6_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    ADC_ACQ6_CR_TRIGSEL                                    ADC_ACQ6_CR_TRIGSEL_Msk

#define    ADC_ACQ6_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ6_CR_SMTS_Msk                                   (0xfU << ADC_ACQ6_CR_SMTS_Pos)
#define    ADC_ACQ6_CR_SMTS                                       ADC_ACQ6_CR_SMTS_Msk

#define    ADC_ACQ7_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ7_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ7_CR_CHSEL_Pos)
#define    ADC_ACQ7_CR_CHSEL                                      ADC_ACQ7_CR_CHSEL_Msk

#define    ADC_ACQ7_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ7_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    ADC_ACQ7_CR_TRIGSEL                                    ADC_ACQ7_CR_TRIGSEL_Msk

#define    ADC_ACQ7_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ7_CR_SMTS_Msk                                   (0xfU << ADC_ACQ7_CR_SMTS_Pos)
#define    ADC_ACQ7_CR_SMTS                                       ADC_ACQ7_CR_SMTS_Msk

#define    ADC_ACQ8_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ8_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ8_CR_CHSEL_Pos)
#define    ADC_ACQ8_CR_CHSEL                                      ADC_ACQ8_CR_CHSEL_Msk

#define    ADC_ACQ8_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ8_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    ADC_ACQ8_CR_TRIGSEL                                    ADC_ACQ8_CR_TRIGSEL_Msk

#define    ADC_ACQ8_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ8_CR_SMTS_Msk                                   (0xfU << ADC_ACQ8_CR_SMTS_Pos)
#define    ADC_ACQ8_CR_SMTS                                       ADC_ACQ8_CR_SMTS_Msk

#define    ADC_ACQ9_CR_CHSEL_Pos                                  (9U)
#define    ADC_ACQ9_CR_CHSEL_Msk                                  (0x1fU << ADC_ACQ9_CR_CHSEL_Pos)
#define    ADC_ACQ9_CR_CHSEL                                      ADC_ACQ9_CR_CHSEL_Msk

#define    ADC_ACQ9_CR_TRIGSEL_Pos                                (4U)
#define    ADC_ACQ9_CR_TRIGSEL_Msk                                (0x1fU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    ADC_ACQ9_CR_TRIGSEL                                    ADC_ACQ9_CR_TRIGSEL_Msk

#define    ADC_ACQ9_CR_SMTS_Pos                                   (0U)
#define    ADC_ACQ9_CR_SMTS_Msk                                   (0xfU << ADC_ACQ9_CR_SMTS_Pos)
#define    ADC_ACQ9_CR_SMTS                                       ADC_ACQ9_CR_SMTS_Msk

#define    ADC_ACQ10_CR_CHSEL_Pos                                 (9U)
#define    ADC_ACQ10_CR_CHSEL_Msk                                 (0x1fU << ADC_ACQ10_CR_CHSEL_Pos)
#define    ADC_ACQ10_CR_CHSEL                                     ADC_ACQ10_CR_CHSEL_Msk

#define    ADC_ACQ10_CR_TRIGSEL_Pos                               (4U)
#define    ADC_ACQ10_CR_TRIGSEL_Msk                               (0x1fU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    ADC_ACQ10_CR_TRIGSEL                                   ADC_ACQ10_CR_TRIGSEL_Msk

#define    ADC_ACQ10_CR_SMTS_Pos                                  (0U)
#define    ADC_ACQ10_CR_SMTS_Msk                                  (0xfU << ADC_ACQ10_CR_SMTS_Pos)
#define    ADC_ACQ10_CR_SMTS                                      ADC_ACQ10_CR_SMTS_Msk

#define    ADC_ACQ11_CR_CHSEL_Pos                                 (9U)
#define    ADC_ACQ11_CR_CHSEL_Msk                                 (0x1fU << ADC_ACQ11_CR_CHSEL_Pos)
#define    ADC_ACQ11_CR_CHSEL                                     ADC_ACQ11_CR_CHSEL_Msk

#define    ADC_ACQ11_CR_TRIGSEL_Pos                               (4U)
#define    ADC_ACQ11_CR_TRIGSEL_Msk                               (0x1fU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    ADC_ACQ11_CR_TRIGSEL                                   ADC_ACQ11_CR_TRIGSEL_Msk

#define    ADC_ACQ11_CR_SMTS_Pos                                  (0U)
#define    ADC_ACQ11_CR_SMTS_Msk                                  (0xfU << ADC_ACQ11_CR_SMTS_Pos)
#define    ADC_ACQ11_CR_SMTS                                      ADC_ACQ11_CR_SMTS_Msk

#define    ADC_ACQ12_CR_CHSEL_Pos                                 (9U)
#define    ADC_ACQ12_CR_CHSEL_Msk                                 (0x1fU << ADC_ACQ12_CR_CHSEL_Pos)
#define    ADC_ACQ12_CR_CHSEL                                     ADC_ACQ12_CR_CHSEL_Msk

#define    ADC_ACQ12_CR_TRIGSEL_Pos                               (4U)
#define    ADC_ACQ12_CR_TRIGSEL_Msk                               (0x1fU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    ADC_ACQ12_CR_TRIGSEL                                   ADC_ACQ12_CR_TRIGSEL_Msk

#define    ADC_ACQ12_CR_SMTS_Pos                                  (0U)
#define    ADC_ACQ12_CR_SMTS_Msk                                  (0xfU << ADC_ACQ12_CR_SMTS_Pos)
#define    ADC_ACQ12_CR_SMTS                                      ADC_ACQ12_CR_SMTS_Msk

#define    ADC_ACQ13_CR_CHSEL_Pos                                 (9U)
#define    ADC_ACQ13_CR_CHSEL_Msk                                 (0x1fU << ADC_ACQ13_CR_CHSEL_Pos)
#define    ADC_ACQ13_CR_CHSEL                                     ADC_ACQ13_CR_CHSEL_Msk

#define    ADC_ACQ13_CR_TRIGSEL_Pos                               (4U)
#define    ADC_ACQ13_CR_TRIGSEL_Msk                               (0x1fU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    ADC_ACQ13_CR_TRIGSEL                                   ADC_ACQ13_CR_TRIGSEL_Msk

#define    ADC_ACQ13_CR_SMTS_Pos                                  (0U)
#define    ADC_ACQ13_CR_SMTS_Msk                                  (0xfU << ADC_ACQ13_CR_SMTS_Pos)
#define    ADC_ACQ13_CR_SMTS                                      ADC_ACQ13_CR_SMTS_Msk

#define    ADC_ACQ14_CR_CHSEL_Pos                                 (9U)
#define    ADC_ACQ14_CR_CHSEL_Msk                                 (0x1fU << ADC_ACQ14_CR_CHSEL_Pos)
#define    ADC_ACQ14_CR_CHSEL                                     ADC_ACQ14_CR_CHSEL_Msk

#define    ADC_ACQ14_CR_TRIGSEL_Pos                               (4U)
#define    ADC_ACQ14_CR_TRIGSEL_Msk                               (0x1fU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    ADC_ACQ14_CR_TRIGSEL                                   ADC_ACQ14_CR_TRIGSEL_Msk

#define    ADC_ACQ14_CR_SMTS_Pos                                  (0U)
#define    ADC_ACQ14_CR_SMTS_Msk                                  (0xfU << ADC_ACQ14_CR_SMTS_Pos)
#define    ADC_ACQ14_CR_SMTS                                      ADC_ACQ14_CR_SMTS_Msk

#define    ADC_ACQ15_CR_CHSEL_Pos                                 (9U)
#define    ADC_ACQ15_CR_CHSEL_Msk                                 (0x1fU << ADC_ACQ15_CR_CHSEL_Pos)
#define    ADC_ACQ15_CR_CHSEL                                     ADC_ACQ15_CR_CHSEL_Msk

#define    ADC_ACQ15_CR_TRIGSEL_Pos                               (4U)
#define    ADC_ACQ15_CR_TRIGSEL_Msk                               (0x1fU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    ADC_ACQ15_CR_TRIGSEL                                   ADC_ACQ15_CR_TRIGSEL_Msk

#define    ADC_ACQ15_CR_SMTS_Pos                                  (0U)
#define    ADC_ACQ15_CR_SMTS_Msk                                  (0xfU << ADC_ACQ15_CR_SMTS_Pos)
#define    ADC_ACQ15_CR_SMTS                                      ADC_ACQ15_CR_SMTS_Msk

#define    ADC_ACQ0_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ0_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ0_DR_RESULT_Pos)
#define    ADC_ACQ0_DR_RESULT                                     ADC_ACQ0_DR_RESULT_Msk

#define    ADC_ACQ1_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ1_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ1_DR_RESULT_Pos)
#define    ADC_ACQ1_DR_RESULT                                     ADC_ACQ1_DR_RESULT_Msk

#define    ADC_ACQ2_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ2_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ2_DR_RESULT_Pos)
#define    ADC_ACQ2_DR_RESULT                                     ADC_ACQ2_DR_RESULT_Msk

#define    ADC_ACQ3_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ3_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ3_DR_RESULT_Pos)
#define    ADC_ACQ3_DR_RESULT                                     ADC_ACQ3_DR_RESULT_Msk

#define    ADC_ACQ4_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ4_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ4_DR_RESULT_Pos)
#define    ADC_ACQ4_DR_RESULT                                     ADC_ACQ4_DR_RESULT_Msk

#define    ADC_ACQ5_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ5_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ5_DR_RESULT_Pos)
#define    ADC_ACQ5_DR_RESULT                                     ADC_ACQ5_DR_RESULT_Msk

#define    ADC_ACQ6_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ6_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ6_DR_RESULT_Pos)
#define    ADC_ACQ6_DR_RESULT                                     ADC_ACQ6_DR_RESULT_Msk

#define    ADC_ACQ7_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ7_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ7_DR_RESULT_Pos)
#define    ADC_ACQ7_DR_RESULT                                     ADC_ACQ7_DR_RESULT_Msk

#define    ADC_ACQ8_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ8_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ8_DR_RESULT_Pos)
#define    ADC_ACQ8_DR_RESULT                                     ADC_ACQ8_DR_RESULT_Msk

#define    ADC_ACQ9_DR_RESULT_Pos                                 (0U)
#define    ADC_ACQ9_DR_RESULT_Msk                                 (0xfffU << ADC_ACQ9_DR_RESULT_Pos)
#define    ADC_ACQ9_DR_RESULT                                     ADC_ACQ9_DR_RESULT_Msk

#define    ADC_ACQ10_DR_RESULT_Pos                                (0U)
#define    ADC_ACQ10_DR_RESULT_Msk                                (0xfffU << ADC_ACQ10_DR_RESULT_Pos)
#define    ADC_ACQ10_DR_RESULT                                    ADC_ACQ10_DR_RESULT_Msk

#define    ADC_ACQ11_DR_RESULT_Pos                                (0U)
#define    ADC_ACQ11_DR_RESULT_Msk                                (0xfffU << ADC_ACQ11_DR_RESULT_Pos)
#define    ADC_ACQ11_DR_RESULT                                    ADC_ACQ11_DR_RESULT_Msk

#define    ADC_ACQ12_DR_RESULT_Pos                                (0U)
#define    ADC_ACQ12_DR_RESULT_Msk                                (0xfffU << ADC_ACQ12_DR_RESULT_Pos)
#define    ADC_ACQ12_DR_RESULT                                    ADC_ACQ12_DR_RESULT_Msk

#define    ADC_ACQ13_DR_RESULT_Pos                                (0U)
#define    ADC_ACQ13_DR_RESULT_Msk                                (0xfffU << ADC_ACQ13_DR_RESULT_Pos)
#define    ADC_ACQ13_DR_RESULT                                    ADC_ACQ13_DR_RESULT_Msk

#define    ADC_ACQ14_DR_RESULT_Pos                                (0U)
#define    ADC_ACQ14_DR_RESULT_Msk                                (0xfffU << ADC_ACQ14_DR_RESULT_Pos)
#define    ADC_ACQ14_DR_RESULT                                    ADC_ACQ14_DR_RESULT_Msk

#define    ADC_ACQ15_DR_RESULT_Pos                                (0U)
#define    ADC_ACQ15_DR_RESULT_Msk                                (0xfffU << ADC_ACQ15_DR_RESULT_Pos)
#define    ADC_ACQ15_DR_RESULT                                    ADC_ACQ15_DR_RESULT_Msk

#define    ADC_DMACOMB_CR_COMB_ACQEN_Pos                          (0U)
#define    ADC_DMACOMB_CR_COMB_ACQEN_Msk                          (0xffffU << ADC_DMACOMB_CR_COMB_ACQEN_Pos)
#define    ADC_DMACOMB_CR_COMB_ACQEN                              ADC_DMACOMB_CR_COMB_ACQEN_Msk

#define    ADC_DMACOMB_DR_ACQ_ID_Pos                              (16U)
#define    ADC_DMACOMB_DR_ACQ_ID_Msk                              (0xfU << ADC_DMACOMB_DR_ACQ_ID_Pos)
#define    ADC_DMACOMB_DR_ACQ_ID                                  ADC_DMACOMB_DR_ACQ_ID_Msk

#define    ADC_DMACOMB_DR_COMB_DR_Pos                             (0U)
#define    ADC_DMACOMB_DR_COMB_DR_Msk                             (0xfffU << ADC_DMACOMB_DR_COMB_DR_Pos)
#define    ADC_DMACOMB_DR_COMB_DR                                 ADC_DMACOMB_DR_COMB_DR_Msk

#define    FL_ADC_ACQ0                                            (0x1U << 0U)
#define    FL_ADC_ACQ1                                            (0x1U << 1U)
#define    FL_ADC_ACQ2                                            (0x1U << 2U)
#define    FL_ADC_ACQ3                                            (0x1U << 3U)
#define    FL_ADC_ACQ4                                            (0x1U << 4U)
#define    FL_ADC_ACQ5                                            (0x1U << 5U)
#define    FL_ADC_ACQ6                                            (0x1U << 6U)
#define    FL_ADC_ACQ7                                            (0x1U << 7U)
#define    FL_ADC_ACQ8                                            (0x1U << 8U)
#define    FL_ADC_ACQ9                                            (0x1U << 9U)
#define    FL_ADC_ACQ10                                           (0x1U << 10U)
#define    FL_ADC_ACQ11                                           (0x1U << 11U)
#define    FL_ADC_ACQ12                                           (0x1U << 12U)
#define    FL_ADC_ACQ13                                           (0x1U << 13U)
#define    FL_ADC_ACQ14                                           (0x1U << 14U)
#define    FL_ADC_ACQ15                                           (0x1U << 15U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA0                         (0x0U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA1                         (0x1U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA2                         (0x2U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA3                         (0x3U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA4                         (0x4U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA5                         (0x5U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA6                         (0x6U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA7                         (0x7U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INA8_OPA0_OUT                (0x8U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_TS                           (0x9U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_AVREF                        (0xaU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_P_CALIBRATION                (0xcU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB0                         (0x10U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB1                         (0x11U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB2                         (0x12U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB3                         (0x13U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB4                         (0x14U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB5                         (0x15U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB6                         (0x16U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB7                         (0x17U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_INB8_OPA1_OUT                (0x18U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_VBAT_DIV3                   (0x19U << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_DAC0                         (0x1aU << 9U)
#define    FL_ADC_ACQ_SELECT_CHANNEL_N_CALIBRATION                (0x1cU << 9U)
#define    FL_ADC_ACQ_TRGI_SOFE_TRG                               (0x0U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT0_TRG                               (0x1U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT1_TRG                               (0x2U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT2_TRG                               (0x3U << 4U)
#define    FL_ADC_ACQ_TRGI_LUT3_TRG                               (0x4U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM0_TRGO                             (0x5U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM1_TRGO                             (0x6U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM0_TRGO2                            (0x7U << 4U)
#define    FL_ADC_ACQ_TRGI_ATIM1_TRGO2                            (0x8U << 4U)
#define    FL_ADC_ACQ_TRGI_GPTIM0_TRGO                            (0x9U << 4U)
#define    FL_ADC_ACQ_TRGI_GPTIM1_TRGO                            (0xaU << 4U)
#define    FL_ADC_ACQ_TRGI_GPTIM2_TRGO                            (0xbU << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM0SOCA                              (0xcU << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM0SOCB                              (0xdU << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM1SOCA                              (0xeU << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM1SOCB                              (0xfU << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM2SOCA                              (0x10U << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM2SOCB                              (0x11U << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM3SOCA                              (0x12U << 4U)
#define    FL_ADC_ACQ_TRGI_EPWM3SOCB                              (0x13U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP0_TRGO                             (0x14U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP1_TRGO                             (0x15U << 4U)
#define    FL_ADC_ACQ_TRGI_COMP2_TRGO                             (0x16U << 4U)
#define    FL_ADC_ACQ_TRGI_LPTIM0_TRGO                            (0x17U << 4U)
#define    FL_ADC_ACQ_TRGI_BSTIM0_TRGO                            (0x18U << 4U)
#define    FL_ADC_ACQ_SAMPLING_TIME_1_ADCCLK                      (0x0U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_2_ADCCLK                      (0x1U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_4_ADCCLK                      (0x2U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_8_ADCCLK                      (0x3U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_12_ADCCLK                     (0x4U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_16_ADCCLK                     (0x5U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_32_ADCCLK                     (0x6U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_64_ADCCLK                     (0x7U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_80_ADCCLK                     (0x8U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_96_ADCCLK                     (0x9U << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_128_ADCCLK                    (0xaU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_160_ADCCLK                    (0xbU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_192_ADCCLK                    (0xcU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_256_ADCCLK                    (0xdU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_320_ADCCLK                    (0xeU << 0U)
#define    FL_ADC_ACQ_SAMPLING_TIME_512_ADCCLK                    (0xfU << 0U)

#define    FL_ADC_SYNC_MODE_ASYNC                                 (0x0U << ADC_CFGR1_SYNC_MODE_Pos)
#define    FL_ADC_SYNC_MODE_SYNC                                  (0x1U << ADC_CFGR1_SYNC_MODE_Pos)

#define    FL_ADC_INJ_MODE_DELAY                                  (0x0U << ADC_CFGR1_INJ_MODE_Pos)
#define    FL_ADC_INJ_MODE_IMMEDIA                                (0x1U << ADC_CFGR1_INJ_MODE_Pos)

#define    FL_ADC_Negative_Peference_VSSA                         (0x0U << ADC_CFGR1_REFNSEL_Pos)
#define    FL_ADC_Negative_Peference_VREFN                        (0x1U << ADC_CFGR1_REFNSEL_Pos)

#define    FL_ADC_REF_SOURCE_VDDA                                 (0x0U << ADC_CFGR1_PEFSEL_Pos)
#define    FL_ADC_REF_SOURCE_VREFP                                (0x1U << ADC_CFGR1_PEFSEL_Pos)

#define    FL_ADC_OVERSAMPLING_MUL_2X                             (0x0U << ADC_CFGR2_AVGR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_4X                             (0x1U << ADC_CFGR2_AVGR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_8X                             (0x2U << ADC_CFGR2_AVGR_Pos)
#define    FL_ADC_OVERSAMPLING_MUL_16X                            (0x3U << ADC_CFGR2_AVGR_Pos)

#define    FL_ADC_OVERSAMPLING_MODE_DISABLE                       (0x0U << ADC_CFGR2_AVGEN_Pos)
#define    FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE                (0x1U << ADC_CFGR2_AVGEN_Pos)

#define    FL_ADC_TRIGER_MODE_NOMAL                               (0x0U << ADC_CFGR2_TMOD_Pos)
#define    FL_ADC_TRIGER_MODE_ONE_SHOT                            (0x1U << ADC_CFGR2_TMOD_Pos)
#define    FL_ADC_TRIGER_MODE_CONTINUOUS                          (0x2U << ADC_CFGR2_TMOD_Pos)

#define    FL_ADC_INJECTION_CONTROL_NONE                          (0x0U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0                          (0x1U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_1                     (0x2U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_2                     (0x3U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_3                     (0x4U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_4                     (0x5U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_5                     (0x6U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_6                     (0x7U << ADC_PRICR_INJC_Pos)
#define    FL_ADC_INJECTION_CONTROL_ACQ0_TO_7                     (0x8U << ADC_PRICR_INJC_Pos)

#define    FL_ADC_DUAL14_MODE_DISABLE                             (0x0U << ADC_DMR_DM14_Pos)
#define    FL_ADC_DUAL14_MODE_ENABLE                              (0x1U << ADC_DMR_DM14_Pos)

#define    FL_ADC_DUAL12_MODE_DISABLE                             (0x0U << ADC_DMR_DM12_Pos)
#define    FL_ADC_DUAL12_MODE_ENABLE                              (0x1U << ADC_DMR_DM12_Pos)

#define    FL_ADC_DUAL10_MODE_DISABLE                             (0x0U << ADC_DMR_DM10_Pos)
#define    FL_ADC_DUAL10_MODE_ENABLE                              (0x1U << ADC_DMR_DM10_Pos)

#define    FL_ADC_DUAL8_MODE_DISABLE                              (0x0U << ADC_DMR_DM8_Pos)
#define    FL_ADC_DUAL8_MODE_ENABLE                               (0x1U << ADC_DMR_DM8_Pos)

#define    FL_ADC_DUAL6_MODE_DISABLE                              (0x0U << ADC_DMR_DM6_Pos)
#define    FL_ADC_DUAL6_MODE_ENABLE                               (0x1U << ADC_DMR_DM6_Pos)

#define    FL_ADC_DUAL4_MODE_DISABLE                              (0x0U << ADC_DMR_DM4_Pos)
#define    FL_ADC_DUAL4_MODE_ENABLE                               (0x1U << ADC_DMR_DM4_Pos)

#define    FL_ADC_DUAL2_MODE_DISABLE                              (0x0U << ADC_DMR_DM2_Pos)
#define    FL_ADC_DUAL2_MODE_ENABLE                               (0x1U << ADC_DMR_DM2_Pos)

#define    FL_ADC_DUAL0_MODE_DISABLE                              (0x0U << ADC_DMR_DM0_Pos)
#define    FL_ADC_DUAL0_MODE_ENABLE                               (0x1U << ADC_DMR_DM0_Pos)

#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA8_OPA0_OUT           (0x8U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ0_CR_CHSEL_Pos)
#define    FL_ADC_ACQ0_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ0_CR_CHSEL_Pos)

#define    FL_ADC_ACQ0_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ0_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ0_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ0_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ0_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ0_CR_SMTS_Pos)
#define    FL_ADC_ACQ0_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ0_CR_SMTS_Pos)

#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ1_CR_CHSEL_Pos)
#define    FL_ADC_ACQ1_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ1_CR_CHSEL_Pos)

#define    FL_ADC_ACQ1_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ1_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ1_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ1_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ1_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ1_CR_SMTS_Pos)
#define    FL_ADC_ACQ1_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ1_CR_SMTS_Pos)

#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ2_CR_CHSEL_Pos)
#define    FL_ADC_ACQ2_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ2_CR_CHSEL_Pos)

#define    FL_ADC_ACQ2_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ2_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ2_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ2_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ2_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ2_CR_SMTS_Pos)
#define    FL_ADC_ACQ2_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ2_CR_SMTS_Pos)

#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ3_CR_CHSEL_Pos)
#define    FL_ADC_ACQ3_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ3_CR_CHSEL_Pos)

#define    FL_ADC_ACQ3_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ3_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ3_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ3_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ3_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ3_CR_SMTS_Pos)
#define    FL_ADC_ACQ3_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ3_CR_SMTS_Pos)

#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ4_CR_CHSEL_Pos)
#define    FL_ADC_ACQ4_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ4_CR_CHSEL_Pos)

#define    FL_ADC_ACQ4_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ4_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ4_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ4_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ4_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ4_CR_SMTS_Pos)
#define    FL_ADC_ACQ4_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ4_CR_SMTS_Pos)

#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ5_CR_CHSEL_Pos)
#define    FL_ADC_ACQ5_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ5_CR_CHSEL_Pos)

#define    FL_ADC_ACQ5_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ5_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ5_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ5_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ5_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ5_CR_SMTS_Pos)
#define    FL_ADC_ACQ5_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ5_CR_SMTS_Pos)

#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ6_CR_CHSEL_Pos)
#define    FL_ADC_ACQ6_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ6_CR_CHSEL_Pos)

#define    FL_ADC_ACQ6_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ6_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ6_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ6_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ6_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ6_CR_SMTS_Pos)
#define    FL_ADC_ACQ6_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ6_CR_SMTS_Pos)

#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ7_CR_CHSEL_Pos)
#define    FL_ADC_ACQ7_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ7_CR_CHSEL_Pos)

#define    FL_ADC_ACQ7_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ7_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ7_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ7_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ7_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ7_CR_SMTS_Pos)
#define    FL_ADC_ACQ7_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ7_CR_SMTS_Pos)

#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ8_CR_CHSEL_Pos)
#define    FL_ADC_ACQ8_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ8_CR_CHSEL_Pos)

#define    FL_ADC_ACQ8_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ8_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ8_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ8_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ8_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ8_CR_SMTS_Pos)
#define    FL_ADC_ACQ8_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ8_CR_SMTS_Pos)

#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA0                    (0x0U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA1                    (0x1U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA2                    (0x2U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA3                    (0x3U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA4                    (0x4U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA5                    (0x5U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA6                    (0x6U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA7                    (0x7U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB8_OPA0_OUT           (0x8U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_TS                          (0x9U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_AVREF                       (0xaU << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_P_CALIBRATION               (0xcU << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB0                    (0x10U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB1                    (0x11U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB2                    (0x12U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB3                    (0x13U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB4                    (0x14U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB5                    (0x15U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB6                    (0x16U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB7                    (0x17U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB8_OPA1_OUT           (0x18U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_VBAT_DIV3                  (0x19U << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_DAC1_OUT1                   (0x1aU << ADC_ACQ9_CR_CHSEL_Pos)
#define    FL_ADC_ACQ9_SELECT_CHANNEL_N_CALIBRATION               (0x1cU << ADC_ACQ9_CR_CHSEL_Pos)

#define    FL_ADC_ACQ9_TRGI_SOFE_TRG                              (0x0U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_LUT0_TRG                              (0x1U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_LUT1_TRG                              (0x2U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_LUT2_TRG                              (0x3U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_LUT3_TRG                              (0x4U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_ATIM0_TRGO                            (0x5U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_ATIM1_TRGO                            (0x6U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_ATIM0_TRGO2                           (0x7U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_ATIM1_TRGO2                           (0x8U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_GPTIM0_TRGO                           (0x9U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_GPTIM1_TRGO                           (0xaU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_GPTIM2_TRGO                           (0xbU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM0SOCA                             (0xcU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM0SOCB                             (0xdU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM1SOCA                             (0xeU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM1SOCB                             (0xfU << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM2SOCA                             (0x10U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM2SOCB                             (0x11U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM3SOCA                             (0x12U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_EPWM3SOCB                             (0x13U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_COMP0_TRGO                            (0x14U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_COMP1_TRGO                            (0x15U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_COMP2_TRGO                            (0x16U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_LPTIM0_TRGO                           (0x17U << ADC_ACQ9_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ9_TRGI_BSTIM0_TRGO                           (0x18U << ADC_ACQ9_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ9_SAMPLING_TIME_1_ADCCLK                     (0x0U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_2_ADCCLK                     (0x1U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_4_ADCCLK                     (0x2U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_8_ADCCLK                     (0x3U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_12_ADCCLK                    (0x4U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_16_ADCCLK                    (0x5U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_32_ADCCLK                    (0x6U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_64_ADCCLK                    (0x7U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_80_ADCCLK                    (0x8U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_96_ADCCLK                    (0x9U << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_128_ADCCLK                   (0xaU << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_160_ADCCLK                   (0xbU << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_192_ADCCLK                   (0xcU << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_256_ADCCLK                   (0xdU << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_320_ADCCLK                   (0xeU << ADC_ACQ9_CR_SMTS_Pos)
#define    FL_ADC_ACQ9_SAMPLING_TIME_512_ADCCLK                   (0xfU << ADC_ACQ9_CR_SMTS_Pos)

#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA0                   (0x0U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA1                   (0x1U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA2                   (0x2U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA3                   (0x3U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA4                   (0x4U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA5                   (0x5U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA6                   (0x6U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA7                   (0x7U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB8_OPA0_OUT          (0x8U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_TS                         (0x9U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_AVREF                      (0xaU << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_P_CALIBRATION              (0xcU << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB0                   (0x10U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB1                   (0x11U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB2                   (0x12U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB3                   (0x13U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB4                   (0x14U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB5                   (0x15U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB6                   (0x16U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB7                   (0x17U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB8_OPA1_OUT          (0x18U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_VBAT_DIV3                 (0x19U << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_DAC1_OUT1                  (0x1aU << ADC_ACQ10_CR_CHSEL_Pos)
#define    FL_ADC_ACQ10_SELECT_CHANNEL_N_CALIBRATION              (0x1cU << ADC_ACQ10_CR_CHSEL_Pos)

#define    FL_ADC_ACQ10_TRGI_SOFE_TRG                             (0x0U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_LUT0_TRG                             (0x1U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_LUT1_TRG                             (0x2U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_LUT2_TRG                             (0x3U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_LUT3_TRG                             (0x4U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_ATIM0_TRGO                           (0x5U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_ATIM1_TRGO                           (0x6U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_ATIM0_TRGO2                          (0x7U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_ATIM1_TRGO2                          (0x8U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_GPTIM0_TRGO                          (0x9U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_GPTIM1_TRGO                          (0xaU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_GPTIM2_TRGO                          (0xbU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM0SOCA                            (0xcU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM0SOCB                            (0xdU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM1SOCA                            (0xeU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM1SOCB                            (0xfU << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM2SOCA                            (0x10U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM2SOCB                            (0x11U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM3SOCA                            (0x12U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_EPWM3SOCB                            (0x13U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_COMP0_TRGO                           (0x14U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_COMP1_TRGO                           (0x15U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_COMP2_TRGO                           (0x16U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_LPTIM0_TRGO                          (0x17U << ADC_ACQ10_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ10_TRGI_BSTIM0_TRGO                          (0x18U << ADC_ACQ10_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ10_SAMPLING_TIME_1_ADCCLK                    (0x0U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_2_ADCCLK                    (0x1U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_4_ADCCLK                    (0x2U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_8_ADCCLK                    (0x3U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_12_ADCCLK                   (0x4U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_16_ADCCLK                   (0x5U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_32_ADCCLK                   (0x6U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_64_ADCCLK                   (0x7U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_80_ADCCLK                   (0x8U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_96_ADCCLK                   (0x9U << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_128_ADCCLK                  (0xaU << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_160_ADCCLK                  (0xbU << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_192_ADCCLK                  (0xcU << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_256_ADCCLK                  (0xdU << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_320_ADCCLK                  (0xeU << ADC_ACQ10_CR_SMTS_Pos)
#define    FL_ADC_ACQ10_SAMPLING_TIME_512_ADCCLK                  (0xfU << ADC_ACQ10_CR_SMTS_Pos)

#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA0                   (0x0U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA1                   (0x1U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA2                   (0x2U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA3                   (0x3U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA4                   (0x4U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA5                   (0x5U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA6                   (0x6U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA7                   (0x7U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB8_OPA0_OUT          (0x8U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_TS                         (0x9U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_AVREF                      (0xaU << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_P_CALIBRATION              (0xcU << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB0                   (0x10U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB1                   (0x11U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB2                   (0x12U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB3                   (0x13U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB4                   (0x14U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB5                   (0x15U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB6                   (0x16U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB7                   (0x17U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB8_OPA1_OUT          (0x18U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_VBAT_DIV3                 (0x19U << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_DAC1_OUT1                  (0x1aU << ADC_ACQ11_CR_CHSEL_Pos)
#define    FL_ADC_ACQ11_SELECT_CHANNEL_N_CALIBRATION              (0x1cU << ADC_ACQ11_CR_CHSEL_Pos)

#define    FL_ADC_ACQ11_TRGI_SOFE_TRG                             (0x0U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_LUT0_TRG                             (0x1U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_LUT1_TRG                             (0x2U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_LUT2_TRG                             (0x3U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_LUT3_TRG                             (0x4U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_ATIM0_TRGO                           (0x5U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_ATIM1_TRGO                           (0x6U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_ATIM0_TRGO2                          (0x7U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_ATIM1_TRGO2                          (0x8U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_GPTIM0_TRGO                          (0x9U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_GPTIM1_TRGO                          (0xaU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_GPTIM2_TRGO                          (0xbU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM0SOCA                            (0xcU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM0SOCB                            (0xdU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM1SOCA                            (0xeU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM1SOCB                            (0xfU << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM2SOCA                            (0x10U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM2SOCB                            (0x11U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM3SOCA                            (0x12U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_EPWM3SOCB                            (0x13U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_COMP0_TRGO                           (0x14U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_COMP1_TRGO                           (0x15U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_COMP2_TRGO                           (0x16U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_LPTIM0_TRGO                          (0x17U << ADC_ACQ11_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ11_TRGI_BSTIM0_TRGO                          (0x18U << ADC_ACQ11_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ11_SAMPLING_TIME_1_ADCCLK                    (0x0U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_2_ADCCLK                    (0x1U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_4_ADCCLK                    (0x2U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_8_ADCCLK                    (0x3U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_12_ADCCLK                   (0x4U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_16_ADCCLK                   (0x5U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_32_ADCCLK                   (0x6U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_64_ADCCLK                   (0x7U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_80_ADCCLK                   (0x8U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_96_ADCCLK                   (0x9U << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_128_ADCCLK                  (0xaU << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_160_ADCCLK                  (0xbU << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_192_ADCCLK                  (0xcU << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_256_ADCCLK                  (0xdU << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_320_ADCCLK                  (0xeU << ADC_ACQ11_CR_SMTS_Pos)
#define    FL_ADC_ACQ11_SAMPLING_TIME_512_ADCCLK                  (0xfU << ADC_ACQ11_CR_SMTS_Pos)

#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA0                   (0x0U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA1                   (0x1U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA2                   (0x2U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA3                   (0x3U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA4                   (0x4U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA5                   (0x5U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA6                   (0x6U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA7                   (0x7U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB8_OPA0_OUT          (0x8U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_TS                         (0x9U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_AVREF                      (0xaU << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_P_CALIBRATION              (0xcU << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB0                   (0x10U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB1                   (0x11U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB2                   (0x12U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB3                   (0x13U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB4                   (0x14U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB5                   (0x15U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB6                   (0x16U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB7                   (0x17U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB8_OPA1_OUT          (0x18U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_VBAT_DIV3                 (0x19U << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_DAC1_OUT1                  (0x1aU << ADC_ACQ12_CR_CHSEL_Pos)
#define    FL_ADC_ACQ12_SELECT_CHANNEL_N_CALIBRATION              (0x1cU << ADC_ACQ12_CR_CHSEL_Pos)

#define    FL_ADC_ACQ12_TRGI_SOFE_TRG                             (0x0U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_LUT0_TRG                             (0x1U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_LUT1_TRG                             (0x2U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_LUT2_TRG                             (0x3U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_LUT3_TRG                             (0x4U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_ATIM0_TRGO                           (0x5U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_ATIM1_TRGO                           (0x6U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_ATIM0_TRGO2                          (0x7U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_ATIM1_TRGO2                          (0x8U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_GPTIM0_TRGO                          (0x9U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_GPTIM1_TRGO                          (0xaU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_GPTIM2_TRGO                          (0xbU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM0SOCA                            (0xcU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM0SOCB                            (0xdU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM1SOCA                            (0xeU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM1SOCB                            (0xfU << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM2SOCA                            (0x10U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM2SOCB                            (0x11U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM3SOCA                            (0x12U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_EPWM3SOCB                            (0x13U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_COMP0_TRGO                           (0x14U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_COMP1_TRGO                           (0x15U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_COMP2_TRGO                           (0x16U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_LPTIM0_TRGO                          (0x17U << ADC_ACQ12_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ12_TRGI_BSTIM0_TRGO                          (0x18U << ADC_ACQ12_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ12_SAMPLING_TIME_1_ADCCLK                    (0x0U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_2_ADCCLK                    (0x1U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_4_ADCCLK                    (0x2U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_8_ADCCLK                    (0x3U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_12_ADCCLK                   (0x4U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_16_ADCCLK                   (0x5U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_32_ADCCLK                   (0x6U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_64_ADCCLK                   (0x7U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_80_ADCCLK                   (0x8U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_96_ADCCLK                   (0x9U << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_128_ADCCLK                  (0xaU << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_160_ADCCLK                  (0xbU << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_192_ADCCLK                  (0xcU << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_256_ADCCLK                  (0xdU << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_320_ADCCLK                  (0xeU << ADC_ACQ12_CR_SMTS_Pos)
#define    FL_ADC_ACQ12_SAMPLING_TIME_512_ADCCLK                  (0xfU << ADC_ACQ12_CR_SMTS_Pos)

#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA0                   (0x0U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA1                   (0x1U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA2                   (0x2U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA3                   (0x3U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA4                   (0x4U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA5                   (0x5U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA6                   (0x6U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA7                   (0x7U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB8_OPA0_OUT          (0x8U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_TS                         (0x9U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_AVREF                      (0xaU << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_P_CALIBRATION              (0xcU << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB0                   (0x10U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB1                   (0x11U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB2                   (0x12U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB3                   (0x13U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB4                   (0x14U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB5                   (0x15U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB6                   (0x16U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB7                   (0x17U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB8_OPA1_OUT          (0x18U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_VBAT_DIV3                 (0x19U << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_DAC1_OUT1                  (0x1aU << ADC_ACQ13_CR_CHSEL_Pos)
#define    FL_ADC_ACQ13_SELECT_CHANNEL_N_CALIBRATION              (0x1cU << ADC_ACQ13_CR_CHSEL_Pos)

#define    FL_ADC_ACQ13_TRGI_SOFE_TRG                             (0x0U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_LUT0_TRG                             (0x1U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_LUT1_TRG                             (0x2U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_LUT2_TRG                             (0x3U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_LUT3_TRG                             (0x4U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_ATIM0_TRGO                           (0x5U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_ATIM1_TRGO                           (0x6U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_ATIM0_TRGO2                          (0x7U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_ATIM1_TRGO2                          (0x8U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_GPTIM0_TRGO                          (0x9U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_GPTIM1_TRGO                          (0xaU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_GPTIM2_TRGO                          (0xbU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM0SOCA                            (0xcU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM0SOCB                            (0xdU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM1SOCA                            (0xeU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM1SOCB                            (0xfU << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM2SOCA                            (0x10U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM2SOCB                            (0x11U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM3SOCA                            (0x12U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_EPWM3SOCB                            (0x13U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_COMP0_TRGO                           (0x14U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_COMP1_TRGO                           (0x15U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_COMP2_TRGO                           (0x16U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_LPTIM0_TRGO                          (0x17U << ADC_ACQ13_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ13_TRGI_BSTIM0_TRGO                          (0x18U << ADC_ACQ13_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ13_SAMPLING_TIME_1_ADCCLK                    (0x0U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_2_ADCCLK                    (0x1U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_4_ADCCLK                    (0x2U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_8_ADCCLK                    (0x3U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_12_ADCCLK                   (0x4U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_16_ADCCLK                   (0x5U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_32_ADCCLK                   (0x6U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_64_ADCCLK                   (0x7U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_80_ADCCLK                   (0x8U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_96_ADCCLK                   (0x9U << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_128_ADCCLK                  (0xaU << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_160_ADCCLK                  (0xbU << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_192_ADCCLK                  (0xcU << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_256_ADCCLK                  (0xdU << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_320_ADCCLK                  (0xeU << ADC_ACQ13_CR_SMTS_Pos)
#define    FL_ADC_ACQ13_SAMPLING_TIME_512_ADCCLK                  (0xfU << ADC_ACQ13_CR_SMTS_Pos)

#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA0                   (0x0U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA1                   (0x1U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA2                   (0x2U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA3                   (0x3U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA4                   (0x4U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA5                   (0x5U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA6                   (0x6U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA7                   (0x7U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB8_OPA0_OUT          (0x8U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_TS                         (0x9U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_AVREF                      (0xaU << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_P_CALIBRATION              (0xcU << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB0                   (0x10U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB1                   (0x11U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB2                   (0x12U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB3                   (0x13U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB4                   (0x14U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB5                   (0x15U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB6                   (0x16U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB7                   (0x17U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB8_OPA1_OUT          (0x18U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_VBAT_DIV3                 (0x19U << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_DAC1_OUT1                  (0x1aU << ADC_ACQ14_CR_CHSEL_Pos)
#define    FL_ADC_ACQ14_SELECT_CHANNEL_N_CALIBRATION              (0x1cU << ADC_ACQ14_CR_CHSEL_Pos)

#define    FL_ADC_ACQ14_TRGI_SOFE_TRG                             (0x0U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_LUT0_TRG                             (0x1U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_LUT1_TRG                             (0x2U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_LUT2_TRG                             (0x3U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_LUT3_TRG                             (0x4U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_ATIM0_TRGO                           (0x5U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_ATIM1_TRGO                           (0x6U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_ATIM0_TRGO2                          (0x7U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_ATIM1_TRGO2                          (0x8U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_GPTIM0_TRGO                          (0x9U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_GPTIM1_TRGO                          (0xaU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_GPTIM2_TRGO                          (0xbU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM0SOCA                            (0xcU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM0SOCB                            (0xdU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM1SOCA                            (0xeU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM1SOCB                            (0xfU << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM2SOCA                            (0x10U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM2SOCB                            (0x11U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM3SOCA                            (0x12U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_EPWM3SOCB                            (0x13U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_COMP0_TRGO                           (0x14U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_COMP1_TRGO                           (0x15U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_COMP2_TRGO                           (0x16U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_LPTIM0_TRGO                          (0x17U << ADC_ACQ14_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ14_TRGI_BSTIM0_TRGO                          (0x18U << ADC_ACQ14_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ14_SAMPLING_TIME_1_ADCCLK                    (0x0U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_2_ADCCLK                    (0x1U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_4_ADCCLK                    (0x2U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_8_ADCCLK                    (0x3U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_12_ADCCLK                   (0x4U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_16_ADCCLK                   (0x5U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_32_ADCCLK                   (0x6U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_64_ADCCLK                   (0x7U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_80_ADCCLK                   (0x8U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_96_ADCCLK                   (0x9U << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_128_ADCCLK                  (0xaU << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_160_ADCCLK                  (0xbU << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_192_ADCCLK                  (0xcU << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_256_ADCCLK                  (0xdU << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_320_ADCCLK                  (0xeU << ADC_ACQ14_CR_SMTS_Pos)
#define    FL_ADC_ACQ14_SAMPLING_TIME_512_ADCCLK                  (0xfU << ADC_ACQ14_CR_SMTS_Pos)

#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA0                   (0x0U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA1                   (0x1U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA2                   (0x2U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA3                   (0x3U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA4                   (0x4U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA5                   (0x5U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA6                   (0x6U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA7                   (0x7U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB8_OPA0_OUT          (0x8U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_TS                         (0x9U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_AVREF                      (0xaU << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_P_CALIBRATION              (0xcU << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB0                   (0x10U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB1                   (0x11U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB2                   (0x12U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB3                   (0x13U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB4                   (0x14U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB5                   (0x15U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB6                   (0x16U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB7                   (0x17U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB8_OPA1_OUT          (0x18U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_VBAT_DIV3                 (0x19U << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_DAC1_OUT1                  (0x1aU << ADC_ACQ15_CR_CHSEL_Pos)
#define    FL_ADC_ACQ15_SELECT_CHANNEL_N_CALIBRATION              (0x1cU << ADC_ACQ15_CR_CHSEL_Pos)

#define    FL_ADC_ACQ15_TRGI_SOFE_TRG                             (0x0U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_LUT0_TRG                             (0x1U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_LUT1_TRG                             (0x2U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_LUT2_TRG                             (0x3U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_LUT3_TRG                             (0x4U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_ATIM0_TRGO                           (0x5U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_ATIM1_TRGO                           (0x6U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_ATIM0_TRGO2                          (0x7U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_ATIM1_TRGO2                          (0x8U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_GPTIM0_TRGO                          (0x9U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_GPTIM1_TRGO                          (0xaU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_GPTIM2_TRGO                          (0xbU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM0SOCA                            (0xcU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM0SOCB                            (0xdU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM1SOCA                            (0xeU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM1SOCB                            (0xfU << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM2SOCA                            (0x10U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM2SOCB                            (0x11U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM3SOCA                            (0x12U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_EPWM3SOCB                            (0x13U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_COMP0_TRGO                           (0x14U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_COMP1_TRGO                           (0x15U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_COMP2_TRGO                           (0x16U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_LPTIM0_TRGO                          (0x17U << ADC_ACQ15_CR_TRIGSEL_Pos)
#define    FL_ADC_ACQ15_TRGI_BSTIM0_TRGO                          (0x18U << ADC_ACQ15_CR_TRIGSEL_Pos)

#define    FL_ADC_ACQ15_SAMPLING_TIME_1_ADCCLK                    (0x0U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_2_ADCCLK                    (0x1U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_4_ADCCLK                    (0x2U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_8_ADCCLK                    (0x3U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_12_ADCCLK                   (0x4U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_16_ADCCLK                   (0x5U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_32_ADCCLK                   (0x6U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_64_ADCCLK                   (0x7U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_80_ADCCLK                   (0x8U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_96_ADCCLK                   (0x9U << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_128_ADCCLK                  (0xaU << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_160_ADCCLK                  (0xbU << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_192_ADCCLK                  (0xcU << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_256_ADCCLK                  (0xdU << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_320_ADCCLK                  (0xeU << ADC_ACQ15_CR_SMTS_Pos)
#define    FL_ADC_ACQ15_SAMPLING_TIME_512_ADCCLK                  (0xfU << ADC_ACQ15_CR_SMTS_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ADC_FL_Exported_Functions ADC Exported Functions
  * @{
  */

/**
  * @brief    Get ADC Data Overrun Flag
  * @rmtoll   ACQ_ISR    OVR    FL_ADC_IsActiveFlag_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_ovr & 0xffff) << 0x10U)) == ((acqx_ovr & 0xffff) << 0x10U));
}

/**
  * @brief    Clear ADC  Data Overrun Flag
  * @rmtoll   ACQ_ISR    OVR    FL_ADC_ClearFlag_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    SET_BIT(ADCx->ACQ_ISR, ((acqx_ovr & 0xffff) << 0x10U));
}

/**
  * @brief    Get ADC End Of Conversion Flag
  * @rmtoll   ACQ_ISR    EOC    FL_ADC_IsActiveFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_ISR, ((acqx_eoc & 0xffff) << 0x0U)) == ((acqx_eoc & 0xffff) << 0x0U));
}

/**
  * @brief    Clear ADC End Of Conversion Flag
  * @rmtoll   ACQ_ISR    EOC    FL_ADC_ClearFlag_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    SET_BIT(ADCx->ACQ_ISR, ((acqx_eoc & 0xffff) << 0x0U));
}

/**
  * @brief    Enable ADC Data Overrun interrupt
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_EnableIT_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_ovr & 0xffff) << 0x10U));
}

/**
  * @brief    Disable ADC Data Overrun interrupt
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_DisableIT_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_ovr & 0xffff) << 0x10U));
}

/**
  * @brief    Get ADC Data Overrun interrupt Enable Status
  * @rmtoll   ACQ_IER    OVRIE    FL_ADC_IsEnabledIT_Overrun
  * @param    ADCx ADC instance
  * @param    acqx_ovr This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_Overrun(ADC_Type *ADCx, uint32_t acqx_ovr)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_ovr & 0xffff) << 0x10U)) == ((acqx_ovr & 0xffff) << 0x10U));
}

/**
  * @brief    Enable ADC End 0f Conversion interrupt
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_EnableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    SET_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0xffff) << 0x0U));
}

/**
  * @brief    Disable ADC End 0f Conversion interrupt
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_DisableIT_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    CLEAR_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0xffff) << 0x0U));
}

/**
  * @brief    Get ADC End 0f Conversion interrupt Enable Status
  * @rmtoll   ACQ_IER    EOCIE    FL_ADC_IsEnabledIT_EndOfConversion
  * @param    ADCx ADC instance
  * @param    acqx_eoc This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_EndOfConversion(ADC_Type *ADCx, uint32_t acqx_eoc)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_IER, ((acqx_eoc & 0xffff) << 0x0U)) == ((acqx_eoc & 0xffff) << 0x0U));
}

/**
  * @brief    Get Working ACQx ID
  * @rmtoll   GISR    ACQ_ID    FL_ADC_GetWorkingACQID
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_GetWorkingACQID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, (0x1fU << 4U)) >> 4U);
}

/**
  * @brief    Get ADC Over Speed Flag
  * @rmtoll   GISR    OSF    FL_ADC_IsActiveFlag_OverSpeed
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_OverSpeed(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_OSF_Msk) == (ADC_GISR_OSF_Msk));
}

/**
  * @brief    Clear ADC Over Speed Flag
  * @rmtoll   GISR    OSF    FL_ADC_ClearFlag_OverSpeed
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_OverSpeed(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_OSF_Msk);
}

/**
  * @brief    Clear ADC Continuous Mode Complete Flag
  * @rmtoll   GISR    EOCNT    FL_ADC_ClearFlag_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_ClearFlag_ContinuousModeComplete(ADC_Type *ADCx)
{
    WRITE_REG(ADCx->GISR, ADC_GISR_EOCNT_Msk);
}

/**
  * @brief    Get ADC Continuous Mode Complete Flag
  * @rmtoll   GISR    EOCNT    FL_ADC_IsActiveFlag_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ContinuousModeComplete(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_EOCNT_Msk) == (ADC_GISR_EOCNT_Msk));
}

/**
  * @brief    Get ADC Busy Flag
  * @rmtoll   GISR    BUSY    FL_ADC_IsActiveFlag_Busy
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_Busy(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GISR, ADC_GISR_BUSY_Msk) == (ADC_GISR_BUSY_Msk));
}

/**
  * @brief    Enable ADC Continuous Mode Complete interrupt
  * @rmtoll   GIER    EOCNTIE    FL_ADC_EnableIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    SET_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    Disable ADC Continuous Mode Complete interrupt
  * @rmtoll   GIER    EOCNTIE    FL_ADC_DisableIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    Get ADC Continuous Mode Complete interrupt Enable Status
  * @rmtoll   GIER    EOCNTIE    FL_ADC_IsEnabledIT_ContinuousModeComplete
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledIT_ContinuousModeComplete(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->GIER, ADC_GIER_EOCNTIE_Msk) == ADC_GIER_EOCNTIE_Msk);
}

/**
  * @brief    Enable ACQ
  * @rmtoll   CR1    ACQEN    FL_ADC_EnableACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    SET_BIT(ADCx->CR1, ((acqx_en & 0xffff) << 0x10U));
}

/**
  * @brief    Disable ADC
  * @rmtoll   CR1    ACQEN    FL_ADC_DisableACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    CLEAR_BIT(ADCx->CR1, ((acqx_en & 0xffff) << 0x10U));
}

/**
  * @brief    Get ADC Enable Status
  * @rmtoll   CR1    ACQEN    FL_ADC_IsEnabledACQ
  * @param    ADCx ADC instance
  * @param    acqx_en This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledACQ(ADC_Type *ADCx, uint32_t acqx_en)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ((acqx_en & 0xffff) << 0x10U)) == ((acqx_en & 0xffff) << 0x10U));
}

/**
  * @brief    Enable Round Robin Reset
  * @rmtoll   CR1    RR_SWRST    FL_ADC_EnableRoundRobinReset
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableRoundRobinReset(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_RR_SWRST_Msk);
}

/**
  * @brief    Enable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Enable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Enable(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Disable ADC
  * @rmtoll   CR1    ADEN    FL_ADC_Disable
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_Disable(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Get ADC Enable Status
  * @rmtoll   CR1    ADEN    FL_ADC_IsEnabled
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabled(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CR1, ADC_CR1_ADEN_Msk) == ADC_CR1_ADEN_Msk);
}

/**
  * @brief    Enable ACQx Sofeware Triggered Conversion
  * @rmtoll   CR2    SWTRIG    FL_ADC_EnableACQSWConversion
  * @param    ADCx ADC instance
  * @param    acqx_sw This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQSWConversion(ADC_Type *ADCx, uint32_t acqx_sw)
{
    SET_BIT(ADCx->CR2, ((acqx_sw & 0xffff) << 0x0U));
}

/**
  * @brief    Set ADC Repeat Length for Continuous Mode
  * @rmtoll   CFGR1    RPTLEN    FL_ADC_SetRepeatLength
  * @param    ADCx ADC instance
  * @param    count
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetRepeatLength(ADC_Type *ADCx, uint32_t count)
{
    MODIFY_REG(ADCx->CFGR1, (0xffffU << 16U), (count << 16U));
}

/**
  * @brief    Read ADC Repeat Length for Continuous Mode
  * @rmtoll   CFGR1    RPTLEN    FL_ADC_GetRepeatLength
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_GetRepeatLength(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, (0xffffU << 16U)) >> 16U);
}

/**
  * @brief    Set ADC Conversion Cycle
  * @rmtoll   CFGR1    CONV_CYCLE    FL_ADC_SetConversionCycle
  * @param    ADCx ADC instance
  * @param    cycle
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetConversionCycle(ADC_Type *ADCx, uint32_t cycle)
{
    MODIFY_REG(ADCx->CFGR1, (0xffU << 8U), (cycle << 8U));
}

/**
  * @brief    Read ADC Conversion Cycle
  * @rmtoll   CFGR1    CONV_CYCLE    FL_ADC_GetConversionCycle
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionCycle(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Set ADC Conversion Mode
  * @rmtoll   CFGR1    SYNC_MODE    FL_ADC_SetConversionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_SYNC_MODE_ASYNC
  *           @arg @ref FL_ADC_SYNC_MODE_SYNC
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetConversionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_SYNC_MODE_Msk, mode);
}

/**
  * @brief    Get ADC Conversion Mode
  * @rmtoll   CFGR1    SYNC_MODE    FL_ADC_GetConversionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_SYNC_MODE_ASYNC
  *           @arg @ref FL_ADC_SYNC_MODE_SYNC
  */
__STATIC_INLINE uint32_t FL_ADC_GetConversionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_SYNC_MODE_Msk));
}

/**
  * @brief    Set ADC Injection Mode
  * @rmtoll   CFGR1    INJ_MODE    FL_ADC_SetInjectionMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INJ_MODE_DELAY
  *           @arg @ref FL_ADC_INJ_MODE_IMMEDIA
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_INJ_MODE_Msk, mode);
}

/**
  * @brief    Get ADC Injection Mode
  * @rmtoll   CFGR1    INJ_MODE    FL_ADC_GetInjectionMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_INJ_MODE_DELAY
  *           @arg @ref FL_ADC_INJ_MODE_IMMEDIA
  */
__STATIC_INLINE uint32_t FL_ADC_GetInjectionMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_INJ_MODE_Msk));
}

/**
  * @brief    Set ADC Negative Peference
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_SetNegativePeference
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_Negative_Peference_VSSA
  *           @arg @ref FL_ADC_Negative_Peference_VREFN
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetNegativePeference(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk, mode);
}

/**
  * @brief    Read ADC Negative Peference
  * @rmtoll   CFGR1    REFNSEL    FL_ADC_GetNegativePeference
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_Negative_Peference_VSSA
  *           @arg @ref FL_ADC_Negative_Peference_VREFN
  */
__STATIC_INLINE uint32_t FL_ADC_GetNegativePeference(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_REFNSEL_Msk));
}

/**
  * @brief    Set ADC Reference Source
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_SetReferenceSource
  * @param    ADCx ADC instance
  * @param    ref This parameter can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetReferenceSource(ADC_Type *ADCx, uint32_t ref)
{
    MODIFY_REG(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk, ref);
}

/**
  * @brief    Read ADC Reference Source
  * @rmtoll   CFGR1    PEFSEL    FL_ADC_GetReferenceSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_REF_SOURCE_VDDA
  *           @arg @ref FL_ADC_REF_SOURCE_VREFP
  */
__STATIC_INLINE uint32_t FL_ADC_GetReferenceSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR1, ADC_CFGR1_PEFSEL_Msk));
}

/**
  * @brief    Set ADC OverSampling Multiplier
  * @rmtoll   CFGR2    AVGR    FL_ADC_SetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @param    mul This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMultiplier(ADC_Type *ADCx, uint32_t mul)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGR_Msk, mul);
}

/**
  * @brief    Read ADC OverSampling Multiplier
  * @rmtoll   CFGR2    AVGR    FL_ADC_GetOverSamplingMultiplier
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_2X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_4X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_8X
  *           @arg @ref FL_ADC_OVERSAMPLING_MUL_16X
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMultiplier(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGR_Msk));
}

/**
  * @brief    Set ADC OverSampling Mode
  * @rmtoll   CFGR2    AVGEN    FL_ADC_SetOverSamplingMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_DISABLE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetOverSamplingMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_AVGEN_Msk, mode);
}

/**
  * @brief    Read ADC OverSampling Mode
  * @rmtoll   CFGR2    AVGEN    FL_ADC_GetOverSamplingMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_DISABLE
  *           @arg @ref FL_ADC_OVERSAMPLING_MODE_ENABLE_AVERAGE
  */
__STATIC_INLINE uint32_t FL_ADC_GetOverSamplingMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_AVGEN_Msk));
}

/**
  * @brief    Enable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT    FL_ADC_EnableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableWaitMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Disable ADC Wait Mode
  * @rmtoll   CFGR2    WAIT    FL_ADC_DisableWaitMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableWaitMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Get ADC Wait Mode Enable Status
  * @rmtoll   CFGR2    WAIT    FL_ADC_IsEnabledWaitMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledWaitMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_WAIT_Msk) == ADC_CFGR2_WAIT_Msk);
}

/**
  * @brief    Set ADC Triger Mode
  * @rmtoll   CFGR2    TMOD    FL_ADC_SetTrigerMode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_TRIGER_MODE_NOMAL
  *           @arg @ref FL_ADC_TRIGER_MODE_ONE_SHOT
  *           @arg @ref FL_ADC_TRIGER_MODE_CONTINUOUS
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetTrigerMode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->CFGR2, ADC_CFGR2_TMOD_Msk, mode);
}

/**
  * @brief    Read ADC Triger Mode
  * @rmtoll   CFGR2    TMOD    FL_ADC_GetTrigerMode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_TRIGER_MODE_NOMAL
  *           @arg @ref FL_ADC_TRIGER_MODE_ONE_SHOT
  *           @arg @ref FL_ADC_TRIGER_MODE_CONTINUOUS
  */
__STATIC_INLINE uint32_t FL_ADC_GetTrigerMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_TMOD_Msk));
}

/**
  * @brief    Enable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_EnableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableOverrunMode(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Disable ADC Overrun Mode
  * @rmtoll   CFGR2    OVRM    FL_ADC_DisableOverrunMode
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableOverrunMode(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Get ADC Overrun Mode Enable Status
  * @rmtoll   CFGR2    OVRM    FL_ADC_IsEnabledOverrunMode
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledOverrunMode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_OVRM_Msk) == ADC_CFGR2_OVRM_Msk);
}

/**
  * @brief    Enable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_EnableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableDMAReq(ADC_Type *ADCx)
{
    SET_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Disable ADC DMA
  * @rmtoll   CFGR2    DMAEN    FL_ADC_DisableDMAReq
  * @param    ADCx ADC instance
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableDMAReq(ADC_Type *ADCx)
{
    CLEAR_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Get ADC DMA Enable Status
  * @rmtoll   CFGR2    DMAEN    FL_ADC_IsEnabledDMAReq
  * @param    ADCx ADC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledDMAReq(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->CFGR2, ADC_CFGR2_DMAEN_Msk) == ADC_CFGR2_DMAEN_Msk);
}

/**
  * @brief    Set ADC Injection Control
  * @rmtoll   PRICR    INJC    FL_ADC_SetInjectionControl
  * @param    ADCx ADC instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_ADC_INJECTION_CONTROL_NONE
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_1
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_2
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_3
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_4
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_5
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_6
  *           @arg @ref FL_ADC_INJECTION_CONTROL_ACQ0_TO_7
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetInjectionControl(ADC_Type *ADCx, uint32_t config)
{
    MODIFY_REG(ADCx->PRICR, ADC_PRICR_INJC_Msk, config);
}

/**
  * @brief    Set ACQ14 and ACQ15 Mode
  * @rmtoll   DMR    DM14    FL_ADC_SetDual14Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL14_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL14_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual14Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM14_Msk, mode);
}

/**
  * @brief    Read ACQ14 and ACQ15 Mode
  * @rmtoll   DMR    DM14    FL_ADC_GetDual14Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL14_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL14_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual14Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM14_Msk));
}

/**
  * @brief    Set ACQ12 and ACQ13 Mode
  * @rmtoll   DMR    DM12    FL_ADC_SetDual12Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL12_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL12_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual12Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM12_Msk, mode);
}

/**
  * @brief    Read ACQ12 and ACQ13 Mode
  * @rmtoll   DMR    DM12    FL_ADC_GetDual12Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL12_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL12_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual12Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM12_Msk));
}

/**
  * @brief    Set ACQ10 and ACQ11 Mode
  * @rmtoll   DMR    DM10    FL_ADC_SetDual10Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL10_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL10_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual10Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM10_Msk, mode);
}

/**
  * @brief    Read ACQ10 and ACQ11 Mode
  * @rmtoll   DMR    DM10    FL_ADC_GetDual10Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL10_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL10_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual10Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM10_Msk));
}

/**
  * @brief    Set ACQ8 and ACQ9 Mode
  * @rmtoll   DMR    DM8    FL_ADC_SetDual8Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL8_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL8_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual8Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM8_Msk, mode);
}

/**
  * @brief    Read ACQ8 and ACQ9 Mode
  * @rmtoll   DMR    DM8    FL_ADC_GetDual8Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL8_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL8_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual8Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM8_Msk));
}

/**
  * @brief    Set ACQ6 and ACQ7 Mode
  * @rmtoll   DMR    DM6    FL_ADC_SetDual6Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL6_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL6_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual6Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM6_Msk, mode);
}

/**
  * @brief    Read ACQ6 and ACQ7 Mode
  * @rmtoll   DMR    DM6    FL_ADC_GetDual6Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL6_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL6_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual6Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM6_Msk));
}

/**
  * @brief    Set ACQ4 and ACQ5 Mode
  * @rmtoll   DMR    DM4    FL_ADC_SetDual4Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL4_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL4_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual4Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM4_Msk, mode);
}

/**
  * @brief    Read ACQ4 and ACQ5 Mode
  * @rmtoll   DMR    DM4    FL_ADC_GetDual4Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL4_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL4_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual4Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM4_Msk));
}

/**
  * @brief    Set ACQ2 and ACQ3 Mode
  * @rmtoll   DMR    DM2    FL_ADC_SetDual2Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL2_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL2_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual2Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM2_Msk, mode);
}

/**
  * @brief    Read ACQ2 and ACQ3 Mode
  * @rmtoll   DMR    DM2    FL_ADC_GetDual2Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL2_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL2_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual2Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM2_Msk));
}

/**
  * @brief    Set ACQ0 and ACQ1 Mode
  * @rmtoll   DMR    DM0    FL_ADC_SetDual0Mode
  * @param    ADCx ADC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ADC_DUAL0_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL0_MODE_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetDual0Mode(ADC_Type *ADCx, uint32_t mode)
{
    MODIFY_REG(ADCx->DMR, ADC_DMR_DM0_Msk, mode);
}

/**
  * @brief    Read ACQ0 and ACQ1 Mode
  * @rmtoll   DMR    DM0    FL_ADC_GetDual0Mode
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_DUAL0_MODE_DISABLE
  *           @arg @ref FL_ADC_DUAL0_MODE_ENABLE
  */
__STATIC_INLINE uint32_t FL_ADC_GetDual0Mode(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMR, ADC_DMR_DM0_Msk));
}

/**
  * @brief    Write P Channel Calibration Value
  * @rmtoll   OSR    POS_CALI    FL_ADC_WritePChannelCalibration
  * @param    ADCx ADC instance
  * @param    calibration
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WritePChannelCalibration(ADC_Type *ADCx, uint32_t calibration)
{
    MODIFY_REG(ADCx->OSR, (0x1fffU << 16U), (calibration << 16U));
}

/**
  * @brief    Get P Channel Calibration Value
  * @rmtoll   OSR    POS_CALI    FL_ADC_ReadPChannelCalibration
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadPChannelCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, (0x1fffU << 16U)) >> 16U);
}

/**
  * @brief    Write N Channel Calibration Value
  * @rmtoll   OSR    NOS_CALI    FL_ADC_WriteNChannelCalibration
  * @param    ADCx ADC instance
  * @param    calibration
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_WriteNChannelCalibration(ADC_Type *ADCx, uint32_t calibration)
{
    MODIFY_REG(ADCx->OSR, (0x1fffU << 0U), (calibration << 0U));
}

/**
  * @brief    Get N Channel Calibration Value
  * @rmtoll   OSR    NOS_CALI    FL_ADC_ReadNChannelCalibration
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadNChannelCalibration(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->OSR, (0x1fffU << 0U)) >> 0U);
}

/**
  * @brief    Read ACQx Pending Flag
  * @rmtoll   ACQ_SR    REQ    FL_ADC_IsActiveFlag_ACQxPending
  * @param    ADCx ADC instance
  * @param    acqx_pending This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsActiveFlag_ACQxPending(ADC_Type *ADCx, uint32_t acqx_pending)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ_SR, ((acqx_pending & 0xffff) << 0x0U)) == ((acqx_pending & 0xffff) << 0x0U));
}

/**
  * @brief    Set ACQ0 Channel
  * @rmtoll   ACQ0_CR    CHSEL    FL_ADC_SetACQ0ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ0 Channel
  * @rmtoll   ACQ0_CR    CHSEL    FL_ADC_GetACQ0ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INA8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ0_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ0ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ0 Trigger Source
  * @rmtoll   ACQ0_CR    TRIGSEL    FL_ADC_SetACQ0TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ0_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ0 Trigger Source
  * @rmtoll   ACQ0_CR    TRIGSEL    FL_ADC_GetACQ0TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ0_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ0_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ0_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ0_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ0_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ0TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ0 Sampling Time
  * @rmtoll   ACQ0_CR    SMTS    FL_ADC_SetACQ0SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ0SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ0_CR, ADC_ACQ0_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ0 Sampling Time
  * @rmtoll   ACQ0_CR    SMTS    FL_ADC_GeACQ0SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ0_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ0SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_CR, ADC_ACQ0_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ1 Channel
  * @rmtoll   ACQ1_CR    CHSEL    FL_ADC_SetACQ1ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ1 Channel
  * @rmtoll   ACQ1_CR    CHSEL    FL_ADC_GetACQ1ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ1_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ1ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ1 Trigger Source
  * @rmtoll   ACQ1_CR    TRIGSEL    FL_ADC_SetACQ1TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ1_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ1_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ1 Trigger Source
  * @rmtoll   ACQ1_CR    TRIGSEL    FL_ADC_GetACQ1TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ1_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ1_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ1_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ1_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ1_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ1_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ1TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ1 Sampling Time
  * @rmtoll   ACQ1_CR    SMTS    FL_ADC_SetACQ1SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ1SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ1_CR, ADC_ACQ1_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ1 Sampling Time
  * @rmtoll   ACQ1_CR    SMTS    FL_ADC_GeACQ1SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ1_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ1SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_CR, ADC_ACQ1_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ2 Channel
  * @rmtoll   ACQ2_CR    CHSEL    FL_ADC_SetACQ2ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ2 Channel
  * @rmtoll   ACQ2_CR    CHSEL    FL_ADC_GetACQ2ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ2_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ2ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ2 Trigger Source
  * @rmtoll   ACQ2_CR    TRIGSEL    FL_ADC_SetACQ2TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ2_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ2_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ2 Trigger Source
  * @rmtoll   ACQ2_CR    TRIGSEL    FL_ADC_GetACQ2TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ2_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ2_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ2_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ2_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ2_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ2_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ2TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ2 Sampling Time
  * @rmtoll   ACQ2_CR    SMTS    FL_ADC_SetACQ2SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ2SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ2_CR, ADC_ACQ2_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ2 Sampling Time
  * @rmtoll   ACQ2_CR    SMTS    FL_ADC_GeACQ2SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ2_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ2SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_CR, ADC_ACQ2_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ3 Channel
  * @rmtoll   ACQ3_CR    CHSEL    FL_ADC_SetACQ3ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ3 Channel
  * @rmtoll   ACQ3_CR    CHSEL    FL_ADC_GetACQ3ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ3_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ3 Trigger Source
  * @rmtoll   ACQ3_CR    TRIGSEL    FL_ADC_SetACQ3TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ3_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ3_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ3 Trigger Source
  * @rmtoll   ACQ3_CR    TRIGSEL    FL_ADC_GetACQ3TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ3_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ3_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ3_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ3_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ3_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ3_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ3TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ3 Sampling Time
  * @rmtoll   ACQ3_CR    SMTS    FL_ADC_SetACQ3SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ3SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ3_CR, ADC_ACQ3_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ3 Sampling Time
  * @rmtoll   ACQ3_CR    SMTS    FL_ADC_GeACQ3SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ3_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ3SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_CR, ADC_ACQ3_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ4 Channel
  * @rmtoll   ACQ4_CR    CHSEL    FL_ADC_SetACQ4ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ4ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ4_CR, ADC_ACQ4_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ4 Channel
  * @rmtoll   ACQ4_CR    CHSEL    FL_ADC_GetACQ4ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ4_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ4ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ4_CR, ADC_ACQ4_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ4 Trigger Source
  * @rmtoll   ACQ4_CR    TRIGSEL    FL_ADC_SetACQ4TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ4_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ4_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ4TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ4_CR, ADC_ACQ4_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ4 Trigger Source
  * @rmtoll   ACQ4_CR    TRIGSEL    FL_ADC_GetACQ4TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ4_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ4_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ4_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ4_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ4_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ4_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ4TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ4_CR, ADC_ACQ4_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ4 Sampling Time
  * @rmtoll   ACQ4_CR    SMTS    FL_ADC_SetACQ4SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ4SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ4_CR, ADC_ACQ4_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ4 Sampling Time
  * @rmtoll   ACQ4_CR    SMTS    FL_ADC_GeACQ4SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ4_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ4SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ4_CR, ADC_ACQ4_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ5 Channel
  * @rmtoll   ACQ5_CR    CHSEL    FL_ADC_SetACQ5ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ5ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ5_CR, ADC_ACQ5_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ5 Channel
  * @rmtoll   ACQ5_CR    CHSEL    FL_ADC_GetACQ5ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ5_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ5ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ5_CR, ADC_ACQ5_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ5 Trigger Source
  * @rmtoll   ACQ5_CR    TRIGSEL    FL_ADC_SetACQ5TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ5_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ5_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ5TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ5_CR, ADC_ACQ5_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ5 Trigger Source
  * @rmtoll   ACQ5_CR    TRIGSEL    FL_ADC_GetACQ5TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ5_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ5_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ5_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ5_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ5_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ5_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ5TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ5_CR, ADC_ACQ5_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ5 Sampling Time
  * @rmtoll   ACQ5_CR    SMTS    FL_ADC_SetACQ5SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ5SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ5_CR, ADC_ACQ5_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ5 Sampling Time
  * @rmtoll   ACQ5_CR    SMTS    FL_ADC_GeACQ5SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ5_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ5SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ5_CR, ADC_ACQ5_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ6 Channel
  * @rmtoll   ACQ6_CR    CHSEL    FL_ADC_SetACQ6ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ6ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ6_CR, ADC_ACQ6_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ6 Channel
  * @rmtoll   ACQ6_CR    CHSEL    FL_ADC_GetACQ6ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ6_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ6ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ6_CR, ADC_ACQ6_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ6 Trigger Source
  * @rmtoll   ACQ6_CR    TRIGSEL    FL_ADC_SetACQ6TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ6_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ6_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ6TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ6_CR, ADC_ACQ6_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ6 Trigger Source
  * @rmtoll   ACQ6_CR    TRIGSEL    FL_ADC_GetACQ6TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ6_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ6_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ6_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ6_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ6_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ6_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ6TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ6_CR, ADC_ACQ6_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ6 Sampling Time
  * @rmtoll   ACQ6_CR    SMTS    FL_ADC_SetACQ6SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ6SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ6_CR, ADC_ACQ6_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ6 Sampling Time
  * @rmtoll   ACQ6_CR    SMTS    FL_ADC_GeACQ6SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ6_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ6SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ6_CR, ADC_ACQ6_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ7 Channel
  * @rmtoll   ACQ7_CR    CHSEL    FL_ADC_SetACQ7ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ7ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ7_CR, ADC_ACQ7_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ7 Channel
  * @rmtoll   ACQ7_CR    CHSEL    FL_ADC_GetACQ7ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ7_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ7ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ7_CR, ADC_ACQ7_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ7 Trigger Source
  * @rmtoll   ACQ7_CR    TRIGSEL    FL_ADC_SetACQ7TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ7_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ7_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ7TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ7_CR, ADC_ACQ7_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ7 Trigger Source
  * @rmtoll   ACQ7_CR    TRIGSEL    FL_ADC_GetACQ7TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ7_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ7_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ7_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ7_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ7_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ7_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ7TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ7_CR, ADC_ACQ7_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ7 Sampling Time
  * @rmtoll   ACQ7_CR    SMTS    FL_ADC_SetACQ7SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ7SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ7_CR, ADC_ACQ7_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ7 Sampling Time
  * @rmtoll   ACQ7_CR    SMTS    FL_ADC_GeACQ7SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ7_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ7SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ7_CR, ADC_ACQ7_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ8 Channel
  * @rmtoll   ACQ8_CR    CHSEL    FL_ADC_SetACQ8ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ8ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ8_CR, ADC_ACQ8_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ8 Channel
  * @rmtoll   ACQ8_CR    CHSEL    FL_ADC_GetACQ8ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ8_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ8ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ8_CR, ADC_ACQ8_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ8 Trigger Source
  * @rmtoll   ACQ8_CR    TRIGSEL    FL_ADC_SetACQ8TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ8_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ8_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ8TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ8_CR, ADC_ACQ8_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ8 Trigger Source
  * @rmtoll   ACQ8_CR    TRIGSEL    FL_ADC_GetACQ8TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ8_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ8_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ8_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ8_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ8_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ8_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ8TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ8_CR, ADC_ACQ8_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ8 Sampling Time
  * @rmtoll   ACQ8_CR    SMTS    FL_ADC_SetACQ8SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ8SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ8_CR, ADC_ACQ8_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ8 Sampling Time
  * @rmtoll   ACQ8_CR    SMTS    FL_ADC_GeACQ8SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ8_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ8SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ8_CR, ADC_ACQ8_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ9 Channel
  * @rmtoll   ACQ9_CR    CHSEL    FL_ADC_SetACQ9ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ9ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ9_CR, ADC_ACQ9_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ9 Channel
  * @rmtoll   ACQ9_CR    CHSEL    FL_ADC_GetACQ9ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ9_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ9ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ9_CR, ADC_ACQ9_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ9 Trigger Source
  * @rmtoll   ACQ9_CR    TRIGSEL    FL_ADC_SetACQ9TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ9_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ9_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ9TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ9_CR, ADC_ACQ9_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ9 Trigger Source
  * @rmtoll   ACQ9_CR    TRIGSEL    FL_ADC_GetACQ9TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ9_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ9_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ9_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ9_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ9_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ9_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ9TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ9_CR, ADC_ACQ9_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ9 Sampling Time
  * @rmtoll   ACQ9_CR    SMTS    FL_ADC_SetACQ9SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ9SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ9_CR, ADC_ACQ9_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ9 Sampling Time
  * @rmtoll   ACQ9_CR    SMTS    FL_ADC_GeACQ9SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ9_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ9SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ9_CR, ADC_ACQ9_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ10 Channel
  * @rmtoll   ACQ10_CR    CHSEL    FL_ADC_SetACQ10ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ10ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ10_CR, ADC_ACQ10_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ10 Channel
  * @rmtoll   ACQ10_CR    CHSEL    FL_ADC_GetACQ10ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ10_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ10ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ10_CR, ADC_ACQ10_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ10 Trigger Source
  * @rmtoll   ACQ10_CR    TRIGSEL    FL_ADC_SetACQ10TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ10_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ10_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ10TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ10_CR, ADC_ACQ10_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ10 Trigger Source
  * @rmtoll   ACQ10_CR    TRIGSEL    FL_ADC_GetACQ10TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ10_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ10_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ10_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ10_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ10_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ10_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ10TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ10_CR, ADC_ACQ10_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ10 Sampling Time
  * @rmtoll   ACQ10_CR    SMTS    FL_ADC_SetACQ10SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ10SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ10_CR, ADC_ACQ10_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ10 Sampling Time
  * @rmtoll   ACQ10_CR    SMTS    FL_ADC_GeACQ10SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ10_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ10SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ10_CR, ADC_ACQ10_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ11 Channel
  * @rmtoll   ACQ11_CR    CHSEL    FL_ADC_SetACQ11ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ11ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ11_CR, ADC_ACQ11_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ11 Channel
  * @rmtoll   ACQ11_CR    CHSEL    FL_ADC_GetACQ11ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ11_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ11ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ11_CR, ADC_ACQ11_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ11 Trigger Source
  * @rmtoll   ACQ11_CR    TRIGSEL    FL_ADC_SetACQ11TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ11_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ11_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ11TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ11_CR, ADC_ACQ11_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ11 Trigger Source
  * @rmtoll   ACQ11_CR    TRIGSEL    FL_ADC_GetACQ11TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ11_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ11_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ11_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ11_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ11_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ11_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ11TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ11_CR, ADC_ACQ11_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ11 Sampling Time
  * @rmtoll   ACQ11_CR    SMTS    FL_ADC_SetACQ11SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ11SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ11_CR, ADC_ACQ11_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ11 Sampling Time
  * @rmtoll   ACQ11_CR    SMTS    FL_ADC_GeACQ11SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ11_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ11SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ11_CR, ADC_ACQ11_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ12 Channel
  * @rmtoll   ACQ12_CR    CHSEL    FL_ADC_SetACQ12ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ12ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ12_CR, ADC_ACQ12_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ12 Channel
  * @rmtoll   ACQ12_CR    CHSEL    FL_ADC_GetACQ12ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ12_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ12ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ12_CR, ADC_ACQ12_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ12 Trigger Source
  * @rmtoll   ACQ12_CR    TRIGSEL    FL_ADC_SetACQ12TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ12_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ12_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ12TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ12_CR, ADC_ACQ12_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ12 Trigger Source
  * @rmtoll   ACQ12_CR    TRIGSEL    FL_ADC_GetACQ12TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ12_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ12_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ12_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ12_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ12_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ12_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ12TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ12_CR, ADC_ACQ12_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ12 Sampling Time
  * @rmtoll   ACQ12_CR    SMTS    FL_ADC_SetACQ12SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ12SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ12_CR, ADC_ACQ12_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ12 Sampling Time
  * @rmtoll   ACQ12_CR    SMTS    FL_ADC_GeACQ12SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ12_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ12SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ12_CR, ADC_ACQ12_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ13 Channel
  * @rmtoll   ACQ13_CR    CHSEL    FL_ADC_SetACQ13ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ13ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ13_CR, ADC_ACQ13_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ13 Channel
  * @rmtoll   ACQ13_CR    CHSEL    FL_ADC_GetACQ13ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ13_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ13ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ13_CR, ADC_ACQ13_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ13 Trigger Source
  * @rmtoll   ACQ13_CR    TRIGSEL    FL_ADC_SetACQ13TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ13_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ13_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ13TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ13_CR, ADC_ACQ13_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ13 Trigger Source
  * @rmtoll   ACQ13_CR    TRIGSEL    FL_ADC_GetACQ13TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ13_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ13_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ13_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ13_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ13_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ13_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ13TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ13_CR, ADC_ACQ13_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ13 Sampling Time
  * @rmtoll   ACQ13_CR    SMTS    FL_ADC_SetACQ13SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ13SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ13_CR, ADC_ACQ13_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ13 Sampling Time
  * @rmtoll   ACQ13_CR    SMTS    FL_ADC_GeACQ13SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ13_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ13SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ13_CR, ADC_ACQ13_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ14 Channel
  * @rmtoll   ACQ14_CR    CHSEL    FL_ADC_SetACQ14ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ14ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ14_CR, ADC_ACQ14_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ14 Channel
  * @rmtoll   ACQ14_CR    CHSEL    FL_ADC_GetACQ14ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ14_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ14ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ14_CR, ADC_ACQ14_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ14 Trigger Source
  * @rmtoll   ACQ14_CR    TRIGSEL    FL_ADC_SetACQ14TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ14_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ14_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ14TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ14_CR, ADC_ACQ14_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ14 Trigger Source
  * @rmtoll   ACQ14_CR    TRIGSEL    FL_ADC_GetACQ14TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ14_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ14_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ14_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ14_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ14_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ14_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ14TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ14_CR, ADC_ACQ14_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ14 Sampling Time
  * @rmtoll   ACQ14_CR    SMTS    FL_ADC_SetACQ14SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ14SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ14_CR, ADC_ACQ14_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ14 Sampling Time
  * @rmtoll   ACQ14_CR    SMTS    FL_ADC_GeACQ14SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ14_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ14SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ14_CR, ADC_ACQ14_CR_SMTS_Msk));
}

/**
  * @brief    Set ACQ15 Channel
  * @rmtoll   ACQ15_CR    CHSEL    FL_ADC_SetACQ15ChannelSelect
  * @param    ADCx ADC instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_N_CALIBRATION
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ15ChannelSelect(ADC_Type *ADCx, uint32_t channel)
{
    MODIFY_REG(ADCx->ACQ15_CR, ADC_ACQ15_CR_CHSEL_Msk, channel);
}

/**
  * @brief    Read ACQ15 Channel
  * @rmtoll   ACQ15_CR    CHSEL    FL_ADC_GetACQ15ChannelSelect
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA0
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA1
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA2
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA3
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA4
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA5
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA6
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INA7
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB8_OPA0_OUT
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_TS
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_AVREF
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_P_CALIBRATION
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB0
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB1
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB2
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB3
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB4
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB5
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB6
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB7
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_ADC_INB8_OPA1_OUT
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_VBAT_DIV3
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_DAC1_OUT1
  *           @arg @ref FL_ADC_ACQ15_SELECT_CHANNEL_N_CALIBRATION
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ15ChannelSelect(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ15_CR, ADC_ACQ15_CR_CHSEL_Msk));
}

/**
  * @brief    Set ACQ15 Trigger Source
  * @rmtoll   ACQ15_CR    TRIGSEL    FL_ADC_SetACQ15TriggerSource
  * @param    ADCx ADC instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ15_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ15_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_BSTIM0_TRGO
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ15TriggerSource(ADC_Type *ADCx, uint32_t source)
{
    MODIFY_REG(ADCx->ACQ15_CR, ADC_ACQ15_CR_TRIGSEL_Msk, source);
}

/**
  * @brief    Get ACQ15 Trigger Source
  * @rmtoll   ACQ15_CR    TRIGSEL    FL_ADC_GetACQ15TriggerSource
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ15_TRGI_SOFE_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT0_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT1_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT2_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_LUT3_TRG
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM1_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM0_TRGO2
  *           @arg @ref FL_ADC_ACQ15_TRGI_ATIM1_TRGO2
  *           @arg @ref FL_ADC_ACQ15_TRGI_GPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_GPTIM1_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_GPTIM2_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM0SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM0SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM1SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM1SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM2SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM2SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM3SOCA
  *           @arg @ref FL_ADC_ACQ15_TRGI_EPWM3SOCB
  *           @arg @ref FL_ADC_ACQ15_TRGI_COMP0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_COMP1_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_COMP2_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_LPTIM0_TRGO
  *           @arg @ref FL_ADC_ACQ15_TRGI_BSTIM0_TRGO
  */
__STATIC_INLINE uint32_t FL_ADC_GetACQ15TriggerSource(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ15_CR, ADC_ACQ15_CR_TRIGSEL_Msk));
}

/**
  * @brief    Set ACQ15 Sampling Time
  * @rmtoll   ACQ15_CR    SMTS    FL_ADC_SetACQ15SamplingTime
  * @param    ADCx ADC instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_512_ADCCLK
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_SetACQ15SamplingTime(ADC_Type *ADCx, uint32_t time)
{
    MODIFY_REG(ADCx->ACQ15_CR, ADC_ACQ15_CR_SMTS_Msk, time);
}

/**
  * @brief    Read ACQ15 Sampling Time
  * @rmtoll   ACQ15_CR    SMTS    FL_ADC_GeACQ15SamplingTime
  * @param    ADCx ADC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_1_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_2_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_4_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_8_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_12_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_16_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_32_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_64_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_80_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_96_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_128_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_160_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_192_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_256_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_320_ADCCLK
  *           @arg @ref FL_ADC_ACQ15_SAMPLING_TIME_512_ADCCLK
  */
__STATIC_INLINE uint32_t FL_ADC_GeACQ15SamplingTime(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ15_CR, ADC_ACQ15_CR_SMTS_Msk));
}

/**
  * @brief    Get ACQ0 Conversion Data
  * @rmtoll   ACQ0_DR    RESULT    FL_ADC_ReadACQ0ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ0ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ0_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ1 Conversion Data
  * @rmtoll   ACQ1_DR    RESULT    FL_ADC_ReadACQ1ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ1ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ1_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ2 Conversion Data
  * @rmtoll   ACQ2_DR    RESULT    FL_ADC_ReadACQ2ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ2ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ2_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ3 Conversion Data
  * @rmtoll   ACQ3_DR    RESULT    FL_ADC_ReadACQ3ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ3ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ3_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ4 Conversion Data
  * @rmtoll   ACQ4_DR    RESULT    FL_ADC_ReadACQ4ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ4ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ4_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ5 Conversion Data
  * @rmtoll   ACQ5_DR    RESULT    FL_ADC_ReadACQ5ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ5ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ5_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ6 Conversion Data
  * @rmtoll   ACQ6_DR    RESULT    FL_ADC_ReadACQ6ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ6ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ6_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ7 Conversion Data
  * @rmtoll   ACQ7_DR    RESULT    FL_ADC_ReadACQ7ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ7ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ7_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ8 Conversion Data
  * @rmtoll   ACQ8_DR    RESULT    FL_ADC_ReadACQ8ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ8ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ8_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ9 Conversion Data
  * @rmtoll   ACQ9_DR    RESULT    FL_ADC_ReadACQ9ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ9ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ9_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ10 Conversion Data
  * @rmtoll   ACQ10_DR    RESULT    FL_ADC_ReadACQ10ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ10ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ10_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ11 Conversion Data
  * @rmtoll   ACQ11_DR    RESULT    FL_ADC_ReadACQ11ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ11ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ11_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ12 Conversion Data
  * @rmtoll   ACQ12_DR    RESULT    FL_ADC_ReadACQ12ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ12ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ12_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ13 Conversion Data
  * @rmtoll   ACQ13_DR    RESULT    FL_ADC_ReadACQ13ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ13ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ13_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ14 Conversion Data
  * @rmtoll   ACQ14_DR    RESULT    FL_ADC_ReadACQ14ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ14ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ14_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get ACQ15 Conversion Data
  * @rmtoll   ACQ15_DR    RESULT    FL_ADC_ReadACQ15ConversionData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadACQ15ConversionData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->ACQ15_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Enable ACQx DMA Combination
  * @rmtoll   DMACOMB_CR    COMB_ACQEN    FL_ADC_EnableACQ_DMACombination
  * @param    ADCx ADC instance
  * @param    acqx_comb This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_EnableACQ_DMACombination(ADC_Type *ADCx, uint32_t acqx_comb)
{
    SET_BIT(ADCx->DMACOMB_CR, ((acqx_comb & 0xffff) << 0x0U));
}

/**
  * @brief    Disable ACQx DMA Combination
  * @rmtoll   DMACOMB_CR    COMB_ACQEN    FL_ADC_DisableACQ_DMACombination
  * @param    ADCx ADC instance
  * @param    acqx_comb This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   None
  */
__STATIC_INLINE void FL_ADC_DisableACQ_DMACombination(ADC_Type *ADCx, uint32_t acqx_comb)
{
    CLEAR_BIT(ADCx->DMACOMB_CR, ((acqx_comb & 0xffff) << 0x0U));
}

/**
  * @brief    Get ACQx DMA Combination
  * @rmtoll   DMACOMB_CR    COMB_ACQEN    FL_ADC_IsEnabledACQ_DMACombination
  * @param    ADCx ADC instance
  * @param    acqx_comb This parameter can be one of the following values:
  *           @arg @ref FL_ADC_ACQ0
  *           @arg @ref FL_ADC_ACQ1
  *           @arg @ref FL_ADC_ACQ2
  *           @arg @ref FL_ADC_ACQ3
  *           @arg @ref FL_ADC_ACQ4
  *           @arg @ref FL_ADC_ACQ5
  *           @arg @ref FL_ADC_ACQ6
  *           @arg @ref FL_ADC_ACQ7
  *           @arg @ref FL_ADC_ACQ8
  *           @arg @ref FL_ADC_ACQ9
  *           @arg @ref FL_ADC_ACQ10
  *           @arg @ref FL_ADC_ACQ11
  *           @arg @ref FL_ADC_ACQ12
  *           @arg @ref FL_ADC_ACQ13
  *           @arg @ref FL_ADC_ACQ14
  *           @arg @ref FL_ADC_ACQ15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ADC_IsEnabledACQ_DMACombination(ADC_Type *ADCx, uint32_t acqx_comb)
{
    return (uint32_t)(READ_BIT(ADCx->DMACOMB_CR, ((acqx_comb & 0xffff) << 0x0U)) == ((acqx_comb & 0xffff) << 0x0U));
}

/**
  * @brief    Get DMA MODE ADCID
  * @rmtoll   DMACOMB_DR    ACQ_ID    FL_ADC_ReadDMA_ACQID
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadDMA_ACQID(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMACOMB_DR, (0xfU << 16U)) >> 16U);
}

/**
  * @brief    Get DMA ACQ DATA
  * @rmtoll   DMACOMB_DR    COMB_DR    FL_ADC_ReadDMA_ACQData
  * @param    ADCx ADC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ADC_ReadDMA_ACQData(ADC_Type *ADCx)
{
    return (uint32_t)(READ_BIT(ADCx->DMACOMB_DR, (0xfffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup ADC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_ADC_CommonDeInit(void);
FL_ErrorStatus FL_ADC_CommonInit(FL_ADC_CommonInitTypeDef *ADC_CommonInitStruct);
FL_ErrorStatus  FL_ADC_DeInit(ADC_Type *ADCx);
FL_ErrorStatus FL_ADC_Init(ADC_Type *ADCx, FL_ADC_InitTypeDef  *ADC_InitStruct, uint32_t ACQx);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_ADC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-09*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
