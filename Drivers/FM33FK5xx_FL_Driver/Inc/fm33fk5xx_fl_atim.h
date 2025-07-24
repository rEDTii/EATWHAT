/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_atim.h
  * @author  FMSH Application Team
  * @brief   Head file of ATIM FL Module
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

/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FK5XX_FL_ATIM_H
#define __FM33FK5XX_FL_ATIM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup ATIM_FL_ES_INIT ATIM Exported Init structures
  * @{
  */

/**
  * @brief FL ATIM Init Sturcture definition
  */

typedef struct
{
    /*! 时钟源选择 */
    uint32_t clockSource;
    /*! 预分频系数 */
    uint32_t prescaler;
    /*! 计数模式 */
    uint32_t counterMode;
    /*! 自动重装载值 */
    uint32_t autoReload;
    /*! 预装载使能 */
    uint32_t autoReloadState;
    /*! 定时器分频系数与数字滤波器所使用的采样时钟分频比 */
    uint32_t clockDivision;
    /*! 重复计数次数 */
    uint32_t repetitionCounter;

} FL_ATIM_InitTypeDef;

typedef struct
{
    /*! 外部时钟源模式 */
    uint32_t slaveMode;
    /*! 输入触发信号选择 */
    uint32_t triggerSrc;
    /*! Trigger 延迟*/
    uint32_t triggerDelay;

} FL_ATIM_SlaveInitTypeDef;

/**
  * @brief  TIM ETR  configuration structure definition.
  */

typedef struct
{
    /*! 外部触发使能 */
    uint32_t useExternalTrigger;
    /*! 外部时钟滤波 */
    uint32_t ETRFilter;
    /*! 外部时钟分频 */
    uint32_t ETRClockDivision;
    /*! 外部时钟触发极性 */
    uint32_t ETRPolarity;
    /** ETR输入选择信号 */
    uint32_t ETRInput;

} FL_ATIM_ETR_InitTypeDef;

/**
  * @brief  TIM Output Compare configuration structure definition.
  */
typedef struct
{
    /*! 比较输出模式 */
    uint32_t OCMode;
    /*! 正向比较通道输出使能 */
    uint32_t OCState;
    /*! 比较互补通道输出使能 */
    uint32_t OCNState;
    /*! 比较输出极性 */
    uint32_t OCPolarity;
    /*! 比较互补输出极性 */
    uint32_t OCNPolarity;
    /*! 比较输出通道快速模式使能 */
    uint32_t OCFastMode;
    /*! 输出比较预装载 */
    uint32_t OCPreload;
    /*! 通道比较值 */
    uint32_t compareValue;
    /*! 输出空闲状态电平 */
    uint32_t OCIdleState;
    /*! ETR清0使能 */
    uint32_t OCETRFStatus;
    /*! 互补输出空闲状态电平 */
    uint32_t OCNIdleState;

} FL_ATIM_OC_InitTypeDef;
/**
  * @brief  TIM Input Capture configuration structure definition.
  */

typedef struct
{
    /** 通道输入选择 */
    uint32_t ITSelect;
    /*! 输入捕获极性 */
    uint32_t ICPolarity;
    /*! 通道映射激活的输入选择 */
    uint32_t ICActiveInput;
    /*! 输入分频 */
    uint32_t ICPrescaler;
    /*! 输入滤波 */
    uint32_t ICFilter;
    /*! 输入捕获使能 */
    uint32_t captureState;

} FL_ATIM_IC_InitTypeDef;

/**
  * @brief  BDTR (Break and Dead Time) structure definition
  */
typedef struct
{
    /*! 运行状态下的输出关闭状态 */
    uint32_t OSSRState;
    /*! 空闲状态下的输出关闭状态 */
    uint32_t OSSIState;
    /*! 寄存器写保护等级 */
    uint32_t lockLevel;
    /*! 死区时间 */
    uint32_t deadTime;
    /*! 刹车使能 */
    uint32_t breakState;
    /*! 刹车信号滤波 */
    uint32_t breakFilter;
    /*! 刹车信号极性 */
    uint32_t breakPolarity;
    /*! 刹车后计数器重装后自动输出使能*/
    uint32_t automaticOutput;
    /*! 刹车信号极性 */
    uint32_t breakSource;
} FL_ATIM_BDTR_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup ATIM_FL_Exported_Constants ATIM Exported Constants
  * @{
  */

#define    ATIM_CR1_UIFREMAP_Pos                                  (11U)
#define    ATIM_CR1_UIFREMAP_Msk                                  (0x1U << ATIM_CR1_UIFREMAP_Pos)
#define    ATIM_CR1_UIFREMAP                                      ATIM_CR1_UIFREMAP_Msk

#define    ATIM_CR1_CKD_Pos                                       (8U)
#define    ATIM_CR1_CKD_Msk                                       (0x3U << ATIM_CR1_CKD_Pos)
#define    ATIM_CR1_CKD                                           ATIM_CR1_CKD_Msk

#define    ATIM_CR1_ARPE_Pos                                      (7U)
#define    ATIM_CR1_ARPE_Msk                                      (0x1U << ATIM_CR1_ARPE_Pos)
#define    ATIM_CR1_ARPE                                          ATIM_CR1_ARPE_Msk

#define    ATIM_CR1_CMS_Pos                                       (5U)
#define    ATIM_CR1_CMS_Msk                                       (0x3U << ATIM_CR1_CMS_Pos)
#define    ATIM_CR1_CMS                                           ATIM_CR1_CMS_Msk

#define    ATIM_CR1_DIR_Pos                                       (4U)
#define    ATIM_CR1_DIR_Msk                                       (0x1U << ATIM_CR1_DIR_Pos)
#define    ATIM_CR1_DIR                                           ATIM_CR1_DIR_Msk

#define    ATIM_CR1_OPM_Pos                                       (3U)
#define    ATIM_CR1_OPM_Msk                                       (0x1U << ATIM_CR1_OPM_Pos)
#define    ATIM_CR1_OPM                                           ATIM_CR1_OPM_Msk

#define    ATIM_CR1_URS_Pos                                       (2U)
#define    ATIM_CR1_URS_Msk                                       (0x1U << ATIM_CR1_URS_Pos)
#define    ATIM_CR1_URS                                           ATIM_CR1_URS_Msk

#define    ATIM_CR1_UDIS_Pos                                      (1U)
#define    ATIM_CR1_UDIS_Msk                                      (0x1U << ATIM_CR1_UDIS_Pos)
#define    ATIM_CR1_UDIS                                          ATIM_CR1_UDIS_Msk

#define    ATIM_CR1_CEN_Pos                                       (0U)
#define    ATIM_CR1_CEN_Msk                                       (0x1U << ATIM_CR1_CEN_Pos)
#define    ATIM_CR1_CEN                                           ATIM_CR1_CEN_Msk

#define    ATIM_CR2_MMS2_Pos                                      (20U)
#define    ATIM_CR2_MMS2_Msk                                      (0xfU << ATIM_CR2_MMS2_Pos)
#define    ATIM_CR2_MMS2                                          ATIM_CR2_MMS2_Msk

#define    ATIM_CR2_OISN_Pos                                      (9U)
#define    ATIM_CR2_OISN_Msk                                      (0x1U << ATIM_CR2_OISN_Pos)
#define    ATIM_CR2_OISN                                          ATIM_CR2_OISN_Msk

#define    ATIM_CR2_OIS_Pos                                       (8U)
#define    ATIM_CR2_OIS_Msk                                       (0x1U << ATIM_CR2_OIS_Pos)
#define    ATIM_CR2_OIS                                           ATIM_CR2_OIS_Msk

#define    ATIM_CR2_TI1S_Pos                                      (7U)
#define    ATIM_CR2_TI1S_Msk                                      (0x1U << ATIM_CR2_TI1S_Pos)
#define    ATIM_CR2_TI1S                                          ATIM_CR2_TI1S_Msk

#define    ATIM_CR2_MMS_Pos                                       (4U)
#define    ATIM_CR2_MMS_Msk                                       (0x200007U << ATIM_CR2_MMS_Pos)
#define    ATIM_CR2_MMS                                           ATIM_CR2_MMS_Msk

#define    ATIM_CR2_CCDS_Pos                                      (3U)
#define    ATIM_CR2_CCDS_Msk                                      (0x1U << ATIM_CR2_CCDS_Pos)
#define    ATIM_CR2_CCDS                                          ATIM_CR2_CCDS_Msk

#define    ATIM_CR2_CCUS_Pos                                      (2U)
#define    ATIM_CR2_CCUS_Msk                                      (0x1U << ATIM_CR2_CCUS_Pos)
#define    ATIM_CR2_CCUS                                          ATIM_CR2_CCUS_Msk

#define    ATIM_CR2_CCPC_Pos                                      (0U)
#define    ATIM_CR2_CCPC_Msk                                      (0x1U << ATIM_CR2_CCPC_Pos)
#define    ATIM_CR2_CCPC                                          ATIM_CR2_CCPC_Msk

#define    ATIM_SMCR_SMSPS_Pos                                    (25U)
#define    ATIM_SMCR_SMSPS_Msk                                    (0x1U << ATIM_SMCR_SMSPS_Pos)
#define    ATIM_SMCR_SMSPS                                        ATIM_SMCR_SMSPS_Msk

#define    ATIM_SMCR_SMSPE_Pos                                    (24U)
#define    ATIM_SMCR_SMSPE_Msk                                    (0x1U << ATIM_SMCR_SMSPE_Pos)
#define    ATIM_SMCR_SMSPE                                        ATIM_SMCR_SMSPE_Msk

#define    ATIM_SMCR_OCCS_Pos                                     (16U)
#define    ATIM_SMCR_OCCS_Msk                                     (0x1U << ATIM_SMCR_OCCS_Pos)
#define    ATIM_SMCR_OCCS                                         ATIM_SMCR_OCCS_Msk

#define    ATIM_SMCR_ETP_Pos                                      (15U)
#define    ATIM_SMCR_ETP_Msk                                      (0x1U << ATIM_SMCR_ETP_Pos)
#define    ATIM_SMCR_ETP                                          ATIM_SMCR_ETP_Msk

#define    ATIM_SMCR_ECE_Pos                                      (14U)
#define    ATIM_SMCR_ECE_Msk                                      (0x1U << ATIM_SMCR_ECE_Pos)
#define    ATIM_SMCR_ECE                                          ATIM_SMCR_ECE_Msk

#define    ATIM_SMCR_ETPS_Pos                                     (12U)
#define    ATIM_SMCR_ETPS_Msk                                     (0x3U << ATIM_SMCR_ETPS_Pos)
#define    ATIM_SMCR_ETPS                                         ATIM_SMCR_ETPS_Msk

#define    ATIM_SMCR_ETF_Pos                                      (8U)
#define    ATIM_SMCR_ETF_Msk                                      (0xfU << ATIM_SMCR_ETF_Pos)
#define    ATIM_SMCR_ETF                                          ATIM_SMCR_ETF_Msk

#define    ATIM_SMCR_MSM_Pos                                      (7U)
#define    ATIM_SMCR_MSM_Msk                                      (0x1U << ATIM_SMCR_MSM_Pos)
#define    ATIM_SMCR_MSM                                          ATIM_SMCR_MSM_Msk

#define    ATIM_SMCR_TS_Pos                                       (4U)
#define    ATIM_SMCR_TS_Msk                                       (0x30007U << ATIM_SMCR_TS_Pos)
#define    ATIM_SMCR_TS                                           ATIM_SMCR_TS_Msk

#define    ATIM_SMCR_SMS_Pos                                      (0U)
#define    ATIM_SMCR_SMS_Msk                                      (0xfU << ATIM_SMCR_SMS_Pos)
#define    ATIM_SMCR_SMS                                          ATIM_SMCR_SMS_Msk

#define    ATIM_DIER_TERRIE_Pos                                   (23U)
#define    ATIM_DIER_TERRIE_Msk                                   (0x1U << ATIM_DIER_TERRIE_Pos)
#define    ATIM_DIER_TERRIE                                       ATIM_DIER_TERRIE_Msk

#define    ATIM_DIER_IERRIE_Pos                                   (22U)
#define    ATIM_DIER_IERRIE_Msk                                   (0x1U << ATIM_DIER_IERRIE_Pos)
#define    ATIM_DIER_IERRIE                                       ATIM_DIER_IERRIE_Msk

#define    ATIM_DIER_DIRIE_Pos                                    (21U)
#define    ATIM_DIER_DIRIE_Msk                                    (0x1U << ATIM_DIER_DIRIE_Pos)
#define    ATIM_DIER_DIRIE                                        ATIM_DIER_DIRIE_Msk

#define    ATIM_DIER_IDXIE_Pos                                    (20U)
#define    ATIM_DIER_IDXIE_Msk                                    (0x1U << ATIM_DIER_IDXIE_Pos)
#define    ATIM_DIER_IDXIE                                        ATIM_DIER_IDXIE_Msk

#define    ATIM_DIER_CC4BURSTEN_Pos                               (19U)
#define    ATIM_DIER_CC4BURSTEN_Msk                               (0x1U << ATIM_DIER_CC4BURSTEN_Pos)
#define    ATIM_DIER_CC4BURSTEN                                   ATIM_DIER_CC4BURSTEN_Msk

#define    ATIM_DIER_CC3BURSTEN_Pos                               (18U)
#define    ATIM_DIER_CC3BURSTEN_Msk                               (0x1U << ATIM_DIER_CC3BURSTEN_Pos)
#define    ATIM_DIER_CC3BURSTEN                                   ATIM_DIER_CC3BURSTEN_Msk

#define    ATIM_DIER_CC2BURSTEN_Pos                               (17U)
#define    ATIM_DIER_CC2BURSTEN_Msk                               (0x1U << ATIM_DIER_CC2BURSTEN_Pos)
#define    ATIM_DIER_CC2BURSTEN                                   ATIM_DIER_CC2BURSTEN_Msk

#define    ATIM_DIER_CC1BURSTEN_Pos                               (16U)
#define    ATIM_DIER_CC1BURSTEN_Msk                               (0x1U << ATIM_DIER_CC1BURSTEN_Pos)
#define    ATIM_DIER_CC1BURSTEN                                   ATIM_DIER_CC1BURSTEN_Msk

#define    ATIM_DIER_TDE_Pos                                      (14U)
#define    ATIM_DIER_TDE_Msk                                      (0x1U << ATIM_DIER_TDE_Pos)
#define    ATIM_DIER_TDE                                          ATIM_DIER_TDE_Msk

#define    ATIM_DIER_COMDE_Pos                                    (13U)
#define    ATIM_DIER_COMDE_Msk                                    (0x1U << ATIM_DIER_COMDE_Pos)
#define    ATIM_DIER_COMDE                                        ATIM_DIER_COMDE_Msk

#define    ATIM_DIER_CCDE_Pos                                     (9U)
#define    ATIM_DIER_CCDE_Msk                                     (0xFU << ATIM_DIER_CCDE_Pos)
#define    ATIM_DIER_CCDE                                         ATIM_DIER_CCDE_Msk

#define    ATIM_DIER_UDE_Pos                                      (8U)
#define    ATIM_DIER_UDE_Msk                                      (0x1U << ATIM_DIER_UDE_Pos)
#define    ATIM_DIER_UDE                                          ATIM_DIER_UDE_Msk

#define    ATIM_DIER_BIE_Pos                                      (7U)
#define    ATIM_DIER_BIE_Msk                                      (0x1U << ATIM_DIER_BIE_Pos)
#define    ATIM_DIER_BIE                                          ATIM_DIER_BIE_Msk

#define    ATIM_DIER_TIE_Pos                                      (6U)
#define    ATIM_DIER_TIE_Msk                                      (0x1U << ATIM_DIER_TIE_Pos)
#define    ATIM_DIER_TIE                                          ATIM_DIER_TIE_Msk

#define    ATIM_DIER_COMIE_Pos                                    (5U)
#define    ATIM_DIER_COMIE_Msk                                    (0x1U << ATIM_DIER_COMIE_Pos)
#define    ATIM_DIER_COMIE                                        ATIM_DIER_COMIE_Msk

#define    ATIM_DIER_CCIE_Pos                                     (1U)
#define    ATIM_DIER_CCIE_Msk                                     (0xFU << ATIM_DIER_CCIE_Pos)
#define    ATIM_DIER_CCIE                                         ATIM_DIER_CCIE_Msk

#define    ATIM_DIER_UIE_Pos                                      (0U)
#define    ATIM_DIER_UIE_Msk                                      (0x1U << ATIM_DIER_UIE_Pos)
#define    ATIM_DIER_UIE                                          ATIM_DIER_UIE_Msk

#define    ATIM_ISR_TERRIF_Pos                                    (23U)
#define    ATIM_ISR_TERRIF_Msk                                    (0x1U << ATIM_ISR_TERRIF_Pos)
#define    ATIM_ISR_TERRIF                                        ATIM_ISR_TERRIF_Msk

#define    ATIM_ISR_IERRIF_Pos                                    (22U)
#define    ATIM_ISR_IERRIF_Msk                                    (0x1U << ATIM_ISR_IERRIF_Pos)
#define    ATIM_ISR_IERRIF                                        ATIM_ISR_IERRIF_Msk

#define    ATIM_ISR_DIRIF_Pos                                     (21U)
#define    ATIM_ISR_DIRIF_Msk                                     (0x1U << ATIM_ISR_DIRIF_Pos)
#define    ATIM_ISR_DIRIF                                         ATIM_ISR_DIRIF_Msk

#define    ATIM_ISR_IDXIF_Pos                                     (20U)
#define    ATIM_ISR_IDXIF_Msk                                     (0x1U << ATIM_ISR_IDXIF_Pos)
#define    ATIM_ISR_IDXIF                                         ATIM_ISR_IDXIF_Msk

#define    ATIM_ISR_CCOF_Pos                                      (9U)
#define    ATIM_ISR_CCOF_Msk                                      (0x1U << ATIM_ISR_CCOF_Pos)
#define    ATIM_ISR_CCOF                                          ATIM_ISR_CCOF_Msk

#define    ATIM_ISR_B2IF_Pos                                      (8U)
#define    ATIM_ISR_B2IF_Msk                                      (0x1U << ATIM_ISR_B2IF_Pos)
#define    ATIM_ISR_B2IF                                          ATIM_ISR_B2IF_Msk

#define    ATIM_ISR_BIF_Pos                                       (7U)
#define    ATIM_ISR_BIF_Msk                                       (0x1U << ATIM_ISR_BIF_Pos)
#define    ATIM_ISR_BIF                                           ATIM_ISR_BIF_Msk

#define    ATIM_ISR_TIF_Pos                                       (6U)
#define    ATIM_ISR_TIF_Msk                                       (0x1U << ATIM_ISR_TIF_Pos)
#define    ATIM_ISR_TIF                                           ATIM_ISR_TIF_Msk

#define    ATIM_ISR_COMIF_Pos                                     (5U)
#define    ATIM_ISR_COMIF_Msk                                     (0x1U << ATIM_ISR_COMIF_Pos)
#define    ATIM_ISR_COMIF                                         ATIM_ISR_COMIF_Msk

#define    ATIM_ISR_CCIF_Pos                                      (1U)
#define    ATIM_ISR_CCIF_Msk                                      (0x1U << ATIM_ISR_CCIF_Pos)
#define    ATIM_ISR_CCIF                                          ATIM_ISR_CCIF_Msk

#define    ATIM_ISR_UIF_Pos                                       (0U)
#define    ATIM_ISR_UIF_Msk                                       (0x1U << ATIM_ISR_UIF_Pos)
#define    ATIM_ISR_UIF                                           ATIM_ISR_UIF_Msk

#define    ATIM_EGR_B2G_Pos                                       (8U)
#define    ATIM_EGR_B2G_Msk                                       (0x1U << ATIM_EGR_B2G_Pos)
#define    ATIM_EGR_B2G                                           ATIM_EGR_B2G_Msk

#define    ATIM_EGR_BG_Pos                                        (7U)
#define    ATIM_EGR_BG_Msk                                        (0x1U << ATIM_EGR_BG_Pos)
#define    ATIM_EGR_BG                                            ATIM_EGR_BG_Msk

#define    ATIM_EGR_TG_Pos                                        (6U)
#define    ATIM_EGR_TG_Msk                                        (0x1U << ATIM_EGR_TG_Pos)
#define    ATIM_EGR_TG                                            ATIM_EGR_TG_Msk

#define    ATIM_EGR_COMG_Pos                                      (5U)
#define    ATIM_EGR_COMG_Msk                                      (0x1U << ATIM_EGR_COMG_Pos)
#define    ATIM_EGR_COMG                                          ATIM_EGR_COMG_Msk

#define    ATIM_EGR_CCG_Pos                                       (1U)
#define    ATIM_EGR_CCG_Msk                                       (0xFU << ATIM_EGR_CCG_Pos)
#define    ATIM_EGR_CCG                                           ATIM_EGR_CCG_Msk

#define    ATIM_EGR_UG_Pos                                        (0U)
#define    ATIM_EGR_UG_Msk                                        (0x1U << ATIM_EGR_UG_Pos)
#define    ATIM_EGR_UG                                            ATIM_EGR_UG_Msk

#define    ATIM_CCMR_OCCE_Pos                                     (7U)
#define    ATIM_CCMR_OCCE_Msk                                     (0x1U << ATIM_CCMR_OCCE_Pos)
#define    ATIM_CCMR_OCCE                                         ATIM_CCMR_OCCE_Msk

#define    ATIM_CCMR_OCM_Pos                                      (4U)
#define    ATIM_CCMR_OCM_Msk                                      (0x1007U << ATIM_CCMR_OCM_Pos)
#define    ATIM_CCMR_OCM                                          ATIM_CCMR_OCM_Msk

#define    ATIM_CCMR_OCPE_Pos                                     (3U)
#define    ATIM_CCMR_OCPE_Msk                                     (0x1U << ATIM_CCMR_OCPE_Pos)
#define    ATIM_CCMR_OCPE                                         ATIM_CCMR_OCPE_Msk

#define    ATIM_CCMR_OCFE_Pos                                     (2U)
#define    ATIM_CCMR_OCFE_Msk                                     (0x1U << ATIM_CCMR_OCFE_Pos)
#define    ATIM_CCMR_OCFE                                         ATIM_CCMR_OCFE_Msk

#define    ATIM_CCMR_ICF_Pos                                      (4U)
#define    ATIM_CCMR_ICF_Msk                                      (0xfU << ATIM_CCMR_ICF_Pos)
#define    ATIM_CCMR_ICF                                          ATIM_CCMR_ICF_Msk

#define    ATIM_CCMR_ICPSC_Pos                                    (2U)
#define    ATIM_CCMR_ICPSC_Msk                                    (0x3U << ATIM_CCMR_ICPSC_Pos)
#define    ATIM_CCMR_ICPSC                                        ATIM_CCMR_ICPSC_Msk

#define    ATIM_CCMR_CCS_Pos                                      (0U)
#define    ATIM_CCMR_CCS_Msk                                      (0x3U << ATIM_CCMR_CCS_Pos)
#define    ATIM_CCMR_CCS                                          ATIM_CCMR_CCS_Msk

#define    ATIM_CCER_CCNP_Pos                                     (3U)
#define    ATIM_CCER_CCNP_Msk                                     (0x1U << ATIM_CCER_CCNP_Pos)
#define    ATIM_CCER_CCNP                                         ATIM_CCER_CCNP_Msk

#define    ATIM_CCER_CCNE_Pos                                     (2U)
#define    ATIM_CCER_CCNE_Msk                                     (0x1U << ATIM_CCER_CCNE_Pos)
#define    ATIM_CCER_CCNE                                         ATIM_CCER_CCNE_Msk

#define    ATIM_CCER_CCOP_Pos                                     (1U)
#define    ATIM_CCER_CCOP_Msk                                     (0x1U << ATIM_CCER_CCOP_Pos)
#define    ATIM_CCER_CCOP                                         ATIM_CCER_CCOP_Msk

#define    ATIM_CCER_CCIP_Pos                                     (1U)
#define    ATIM_CCER_CCIP_Msk                                     (0x1U << ATIM_CCER_CCIP_Pos)
#define    ATIM_CCER_CCIP                                         ATIM_CCER_CCIP_Msk

#define    ATIM_CCER_CCOE_Pos                                     (0U)
#define    ATIM_CCER_CCOE_Msk                                     (0x1U << ATIM_CCER_CCOE_Pos)
#define    ATIM_CCER_CCOE                                         ATIM_CCER_CCOE_Msk

#define    ATIM_CCER_CCIE_Pos                                     (0U)
#define    ATIM_CCER_CCIE_Msk                                     (0x1U << ATIM_CCER_CCIE_Pos)
#define    ATIM_CCER_CCIE                                         ATIM_CCER_CCIE_Msk

#define    ATIM_CNT_UIFCPY_Pos                                    (31U)
#define    ATIM_CNT_UIFCPY_Msk                                    (0x1U << ATIM_CNT_UIFCPY_Pos)
#define    ATIM_CNT_UIFCPY                                        ATIM_CNT_UIFCPY_Msk

#define    ATIM_BDTR_BK2P_Pos                                      (25U)
#define    ATIM_BDTR_BK2P_Msk                                      (0x1U << ATIM_BDTR_BK2P_Pos)
#define    ATIM_BDTR_BK2P                                          ATIM_BDTR_BK2P_Msk

#define    ATIM_BDTR_BK2E_Pos                                      (24U)
#define    ATIM_BDTR_BK2E_Msk                                      (0x1U << ATIM_BDTR_BK2E_Pos)
#define    ATIM_BDTR_BK2E                                          ATIM_BDTR_BK2E_Msk

#define    ATIM_BDTR_BK2F_Pos                                      (20U)
#define    ATIM_BDTR_BK2F_Msk                                      (0xfU << ATIM_BDTR_BK2F_Pos)
#define    ATIM_BDTR_BK2F                                          ATIM_BDTR_BK2F_Msk

#define    ATIM_BDTR_BKF_Pos                                      (16U)
#define    ATIM_BDTR_BKF_Msk                                      (0xfU << ATIM_BDTR_BKF_Pos)
#define    ATIM_BDTR_BKF                                          ATIM_BDTR_BKF_Msk

#define    ATIM_BDTR_MOE_Pos                                      (15U)
#define    ATIM_BDTR_MOE_Msk                                      (0x1U << ATIM_BDTR_MOE_Pos)
#define    ATIM_BDTR_MOE                                          ATIM_BDTR_MOE_Msk

#define    ATIM_BDTR_AOE_Pos                                      (14U)
#define    ATIM_BDTR_AOE_Msk                                      (0x1U << ATIM_BDTR_AOE_Pos)
#define    ATIM_BDTR_AOE                                          ATIM_BDTR_AOE_Msk

#define    ATIM_BDTR_BKP_Pos                                      (13U)
#define    ATIM_BDTR_BKP_Msk                                      (0x1U << ATIM_BDTR_BKP_Pos)
#define    ATIM_BDTR_BKP                                          ATIM_BDTR_BKP_Msk

#define    ATIM_BDTR_BKE_Pos                                      (12U)
#define    ATIM_BDTR_BKE_Msk                                      (0x1U << ATIM_BDTR_BKE_Pos)
#define    ATIM_BDTR_BKE                                          ATIM_BDTR_BKE_Msk

#define    ATIM_BDTR_OSSR_Pos                                     (11U)
#define    ATIM_BDTR_OSSR_Msk                                     (0x1U << ATIM_BDTR_OSSR_Pos)
#define    ATIM_BDTR_OSSR                                         ATIM_BDTR_OSSR_Msk

#define    ATIM_BDTR_OSSI_Pos                                     (10U)
#define    ATIM_BDTR_OSSI_Msk                                     (0x1U << ATIM_BDTR_OSSI_Pos)
#define    ATIM_BDTR_OSSI                                         ATIM_BDTR_OSSI_Msk

#define    ATIM_BDTR_LOCK_Pos                                     (8U)
#define    ATIM_BDTR_LOCK_Msk                                     (0x3U << ATIM_BDTR_LOCK_Pos)
#define    ATIM_BDTR_LOCK                                         ATIM_BDTR_LOCK_Msk

#define    ATIM_BDTR_DTG_Pos                                      (0U)
#define    ATIM_BDTR_DTG_Msk                                      (0xffU << ATIM_BDTR_DTG_Pos)
#define    ATIM_BDTR_DTG                                          ATIM_BDTR_DTG_Msk

#define    ATIM_CCR5_GC5C3_Pos                                     (31U)
#define    ATIM_CCR5_GC5C3_Msk                                     (0x1UL << ATIM_CCR5_GC5C3_Pos)
#define    ATIM_CCR5_GC5C3                                          ATIM_CCR5_GC5C3_Msk

#define    ATIM_CCR5_GC5C2_Pos                                     (30U)
#define    ATIM_CCR5_GC5C2_Msk                                     (0x1UL << ATIM_CCR5_GC5C2_Pos)
#define    ATIM_CCR5_GC5C2                                         ATIM_CCR5_GC5C2_Msk

#define    ATIM_CCR5_GC5C1_Pos                                     (29U)
#define    ATIM_CCR5_GC5C1_Msk                                     (0x1UL << ATIM_CCR5_GC5C1_Pos)
#define    ATIM_CCR5_GC5C1                                         ATIM_CCR5_GC5C1_Msk

#define    ATIM_ECR_IPOS_Pos                                      (6U)
#define    ATIM_ECR_IPOS_Msk                                      (0x3U << ATIM_ECR_IPOS_Pos)
#define    ATIM_ECR_IPOS                                          ATIM_ECR_IPOS_Msk

#define    ATIM_ECR_FIDX_Pos                                      (5U)
#define    ATIM_ECR_FIDX_Msk                                      (0x1U << ATIM_ECR_FIDX_Pos)
#define    ATIM_ECR_FIDX                                          ATIM_ECR_FIDX_Msk

#define    ATIM_ECR_IDIR_Pos                                      (1U)
#define    ATIM_ECR_IDIR_Msk                                      (0x3U << ATIM_ECR_IDIR_Pos)
#define    ATIM_ECR_IDIR                                          ATIM_ECR_IDIR_Msk

#define    ATIM_ECR_IE_Pos                                        (0U)
#define    ATIM_ECR_IE_Msk                                        (0x1U << ATIM_ECR_IE_Pos)
#define    ATIM_ECR_IE                                            ATIM_ECR_IE_Msk

#define    ATIM_TISEL_TISEL_Pos                                  (0U)
#define    ATIM_TISEL_TISEL_Msk                                  (0xfU << ATIM_TISEL_TISEL_Pos)
#define    ATIM_TISEL_TISEL                                      ATIM_TISEL_TISEL_Msk

#define    ATIM_AFR_ETRSEL_Pos                                    (20U)
#define    ATIM_AFR_ETRSEL_Msk                                    (0xfU << ATIM_AFR_ETRSEL_Pos)
#define    ATIM_AFR_ETRSEL                                        ATIM_AFR_ETRSEL_Msk

#define    ATIM_AFR_OCCLR_SEL_Pos                                 (16U)
#define    ATIM_AFR_OCCLR_SEL_Msk                                 (0x7U << ATIM_AFR_OCCLR_SEL_Pos)
#define    ATIM_AFR_OCCLR_SEL                                     ATIM_AFR_OCCLR_SEL_Msk

#define    ATIM_AFR_BKSYS_E_Pos                                   (8U)
#define    ATIM_AFR_BKSYS_E_Msk                                   (0xfU << ATIM_AFR_BKSYS_E_Pos)
#define    ATIM_AFR_BKSYS_E                                       ATIM_AFR_BKSYS_E_Msk

#define    ATIM_AFR_BKCMP_E_Pos                                   (2U)
#define    ATIM_AFR_BKCMP_E_Msk                                   (0xfU << ATIM_AFR_BKCMP_E_Pos)
#define    ATIM_AFR_BKCMP_E                                       ATIM_AFR_BKCMP_E_Msk

#define    ATIM_AFR_BKIN_E_Pos                                    (0U)
#define    ATIM_AFR_BKIN_E_Msk                                    (0x3U << ATIM_AFR_BKIN_E_Pos)
#define    ATIM_AFR_BKIN_E                                        ATIM_AFR_BKIN_E_Msk

#define    ATIM_BRKFLAG_BKSYS_F_Pos                               (8U)
#define    ATIM_BRKFLAG_BKSYS_F_Msk                               (0xfU << ATIM_BRKFLAG_BKSYS_F_Pos)
#define    ATIM_BRKFLAG_BKSYS_F                                   ATIM_BRKFLAG_BKSYS_F_Msk

#define    ATIM_BRKFLAG_BKCMP_F_Pos                               (2U)
#define    ATIM_BRKFLAG_BKCMP_F_Msk                               (0xfU << ATIM_BRKFLAG_BKCMP_F_Pos)
#define    ATIM_BRKFLAG_BKCMP_F                                    ATIM_BRKFLAG_BKCMP_F_Msk

#define    ATIM_BRKFLAG_BKIN_F_Pos                                (0U)
#define    ATIM_BRKFLAG_BKIN_F_Msk                                (0x3U << ATIM_BRKFLAG_BKIN_F_Pos)
#define    ATIM_BRKFLAG_BKIN_F                                    ATIM_BRKFLAG_BKIN_F_Msk

#define    ATIM_DCR_DBL_Pos                                       (8U)
#define    ATIM_DCR_DBL_Msk                                       (0x1fU << ATIM_DCR_DBL_Pos)
#define    ATIM_DCR_DBL                                           ATIM_DCR_DBL_Msk

#define    ATIM_DCR_DBA_Pos                                       (0U)
#define    ATIM_DCR_DBA_Msk                                       (0x1fU << ATIM_DCR_DBA_Pos)
#define    ATIM_DCR_DBA                                           ATIM_DCR_DBA_Msk

#define    FL_ATIM_CHANNEL_1                                      0x0U
#define    FL_ATIM_CHANNEL_2                                      0x1U
#define    FL_ATIM_CHANNEL_3                                      0x2U
#define    FL_ATIM_CHANNEL_4                                      0x3U
#define    FL_ATIM_CHANNEL_5                                      0x4U
#define    FL_ATIM_CHANNEL_6                                      0x5U

#define    FL_ATIM_TI0                                          0x0U
#define    FL_ATIM_TI1                                          0x1U
#define    FL_ATIM_TI2                                          0x2U
#define    FL_ATIM_TI3                                          0x3U

#define    FL_ATIM_BREAKCHANNEL_0                                 0x0U
#define    FL_ATIM_BREAKCHANNEL_1                                 0x1U

#define    FL_ATIM_CLK_DIVISION_DIV1                              (0x0U << ATIM_CR1_CKD_Pos)
#define    FL_ATIM_CLK_DIVISION_DIV2                              (0x1U << ATIM_CR1_CKD_Pos)
#define    FL_ATIM_CLK_DIVISION_DIV4                              (0x2U << ATIM_CR1_CKD_Pos)

#define    FL_ATIM_COUNTER_ALIGNED_EDGE                           (0x0U << ATIM_CR1_CMS_Pos)
#define    FL_ATIM_COUNTER_ALIGNED_CENTER_DOWN                    (0x1U << ATIM_CR1_CMS_Pos)
#define    FL_ATIM_COUNTER_ALIGNED_CENTER_UP                      (0x2U << ATIM_CR1_CMS_Pos)
#define    FL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN                 (0x3U << ATIM_CR1_CMS_Pos)

#define    FL_ATIM_COUNTER_DIR_UP                                 (0x0U << ATIM_CR1_DIR_Pos)
#define    FL_ATIM_COUNTER_DIR_DOWN                               (0x1U << ATIM_CR1_DIR_Pos)

#define    FL_ATIM_ONE_PULSE_MODE_CONTINUOUS                      (0x0U << ATIM_CR1_OPM_Pos)
#define    FL_ATIM_ONE_PULSE_MODE_SINGLE                          (0x1U << ATIM_CR1_OPM_Pos)

#define    FL_ATIM_UPDATE_SOURCE_REGULAR                          (0x0U << ATIM_CR1_URS_Pos)
#define    FL_ATIM_UPDATE_SOURCE_COUNTER                          (0x1U << ATIM_CR1_URS_Pos)

#define    FL_ATIM_TRGO2_UG                                        (0x0U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_ENABLE                                    (0x1U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_UPDATE                                    (0x2U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_CC1IF                                     (0x3U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC1REF                                    (0x4U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC2REF                                    (0x5U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC3REF                                    (0x6U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC4REF                                    (0x7U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC5REF                                    (0x8U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC6REF                                    (0x9U << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC4REF_RISINGFALLING                      (0xaU << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC6REF_RISINGFALLING                      (0xbU << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC4REF_RISING_OC6REF_RISING               (0xcU << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC4REF_RISING_OC6REF_FALLING              (0xdU << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC5REF_RISING_OC6REF_RISING               (0xeU << ATIM_CR2_MMS2_Pos)
#define    FL_ATIM_TRGO2_OC5REF_RISING_OC6REF_FALLING              (0xfU << ATIM_CR2_MMS2_Pos)

#define    FL_ATIM_OCN_IDLE_STATE_LOW                             (0x0U << ATIM_CR2_OISN_Pos)
#define    FL_ATIM_OCN_IDLE_STATE_HIGH                            (0x1U << ATIM_CR2_OISN_Pos)

#define    FL_ATIM_OC_IDLE_STATE_LOW                              (0x0U << ATIM_CR2_OIS_Pos)
#define    FL_ATIM_OC_IDLE_STATE_HIGH                             (0x1U << ATIM_CR2_OIS_Pos)

#define    FL_ATIM_TRGO_RESET                                     (0x0U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_ENABLE                                    (0x1U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_UPDATE                                    (0x2U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_CC1IF                                     (0x3U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OC1REF                                    (0x4U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OC2REF                                    (0x5U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OC3REF                                    (0x6U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OC4REF                                    (0x7U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_ENCODER                                   (0x200000U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OCREF1_FALLING                            (0x200001U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OCREF2_FALLING                            (0x200002U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OCREF3_FALLING                            (0x200003U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OCREF4_FALLING                            (0x200004U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OCREF5_FALLING                            (0x200005U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OCREF6_FALLING                            (0x200006U << ATIM_CR2_MMS_Pos)
#define    FL_ATIM_TRGO_OC4REF_FALLING_OCREF6_FALLING             (0x200007U << ATIM_CR2_MMS_Pos)

#define    FL_ATIM_CCDMAREQUEST_CC                                (0x0U << ATIM_CR2_CCDS_Pos)
#define    FL_ATIM_CCDMAREQUEST_UPDATE                            (0x1U << ATIM_CR2_CCDS_Pos)

#define    FL_ATIM_CCUPDATESOURCE_COMG_ONLY                       (0x0U << ATIM_CR2_CCUS_Pos)
#define    FL_ATIM_CCUPDATESOURCE_COMG_AND_TRGI                   (0x1U << ATIM_CR2_CCUS_Pos)

#define    FL_ATIM_SMSPS_TIMUPDATE                                (0x0U << ATIM_SMCR_SMSPS_Pos)
#define    FL_ATIM_SMSPS_INDEX                                    (0x1U << ATIM_SMCR_SMSPS_Pos)

#define    FL_ATIM_OCREF_CLR                                      (0x0U << ATIM_SMCR_OCCS_Pos)
#define    FL_ATIM_OCREF_ETRF                                     (0x1U << ATIM_SMCR_OCCS_Pos)

#define    FL_ATIM_ETR_POLARITY_NORMAL                            (0x0U << ATIM_SMCR_ETP_Pos)
#define    FL_ATIM_ETR_POLARITY_INVERT                            (0x1U << ATIM_SMCR_ETP_Pos)

#define    FL_ATIM_ETR_PSC_DIV1                                   (0x0U << ATIM_SMCR_ETPS_Pos)
#define    FL_ATIM_ETR_PSC_DIV2                                   (0x1U << ATIM_SMCR_ETPS_Pos)
#define    FL_ATIM_ETR_PSC_DIV4                                   (0x2U << ATIM_SMCR_ETPS_Pos)
#define    FL_ATIM_ETR_PSC_DIV8                                   (0x3U << ATIM_SMCR_ETPS_Pos)

#define    FL_ATIM_ETR_FILTER_DIV1                                (0x0U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV1_N2                             (0x1U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV1_N4                             (0x2U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV1_N8                             (0x3U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV2_N6                             (0x4U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV2_N8                             (0x5U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV4_N6                             (0x6U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV4_N8                             (0x7U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV8_N6                             (0x8U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV8_N8                             (0x9U << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV16_N5                            (0xaU << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV16_N6                            (0xbU << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV16_N8                            (0xcU << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV32_N5                            (0xdU << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV32_N6                            (0xeU << ATIM_SMCR_ETF_Pos)
#define    FL_ATIM_ETR_FILTER_DIV32_N8                            (0xfU << ATIM_SMCR_ETF_Pos)

#define    FL_ATIM_TRGI_ITR0                                      (0x0U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR1                                      (0x1U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR2                                      (0x2U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR3                                      (0x3U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_TI1F_EDGE                                 (0x4U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_TI1FP1                                    (0x5U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_TI2FP2                                    (0x6U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ETRF                                      (0x7U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR4                                      (0x10000U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR5                                      (0x10001U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR6                                      (0x10002U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR7                                      (0x10003U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR8                                      (0x10004U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR9                                      (0x10005U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR10                                     (0x10006U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR11                                     (0x10007U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR12                                     (0x20000U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR13                                     (0x20001U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR14                                     (0x20002U << ATIM_SMCR_TS_Pos)
#define    FL_ATIM_TRGI_ITR15                                     (0x20003U << ATIM_SMCR_TS_Pos)

#define    FL_ATIM_SLAVE_MODE_PROHIBITED                         (0x0U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_ENCODER_X1_TI1                     (0x1U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_ENCODER_X2_TI2                     (0x2U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_ENCODER_X4_TI1TI2                  (0x3U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_RISE_RST                      (0x4U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN                      (0x5U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_RISE_RUN                      (0x6U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_CLK                           (0x7U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_RISE_RST_RUN                  (0x8U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_HIGH_RISE_RUN                 (0x9U << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_ENCODER_CLK_DIR_X2            (0xaU << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_ENCODER_CLK_DIR_X1            (0xbU << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_ENCODER_CLKWithDIR_X2         (0xcU << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_TRGI_ENCODER_CLKWithDIR_X1         (0xdU << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_QUADRATURE_ENCODER_X1_TI1FP1       (0xeU << ATIM_SMCR_SMS_Pos)
#define    FL_ATIM_SLAVE_MODE_QUADRATURE_ENCODER_X1_TI2FP2       (0xfU << ATIM_SMCR_SMS_Pos)

#define    FL_ATIM_OC_MODE_FROZEN                                 (0x0U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_ACTIVE                                 (0x1U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_INACTIVE                               (0x2U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_TOGGLE                                 (0x3U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_FORCED_INACTIVE                        (0x4U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_FORCED_ACTIVE                          (0x5U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_PWM1                                   (0x6U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_PWM2                                   (0x7U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_RETRIG_OPM1                            (0x1000U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_RETRIG_OPM2                            (0x1001U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_COMBINED_PWM1                          (0x1004U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_COMBINED_PWM2                          (0x1005U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_ASSYMETRIC_PWM1                        (0x1006U << ATIM_CCMR_OCM_Pos)
#define    FL_ATIM_OC_MODE_ASSYMETRIC_PWM2                        (0x1007U << ATIM_CCMR_OCM_Pos)

#define    FL_ATIM_IC_FILTER_DIV1                                 (0x0U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV1_N2                              (0x1U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV1_N4                              (0x2U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV1_N8                              (0x3U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV2_N6                              (0x4U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV2_N8                              (0x5U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV4_N6                              (0x6U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV4_N8                              (0x7U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV8_N6                              (0x8U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV8_N8                              (0x9U << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV16_N5                             (0xaU << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV16_N6                             (0xbU << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV16_N8                             (0xcU << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV32_N5                             (0xdU << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV32_N6                             (0xeU << ATIM_CCMR_ICF_Pos)
#define    FL_ATIM_IC_FILTER_DIV32_N8                             (0xfU << ATIM_CCMR_ICF_Pos)

#define    FL_ATIM_IC_PSC_DIV1                                    (0x0U << ATIM_CCMR_ICPSC_Pos)
#define    FL_ATIM_IC_PSC_DIV2                                    (0x1U << ATIM_CCMR_ICPSC_Pos)
#define    FL_ATIM_IC_PSC_DIV4                                    (0x2U << ATIM_CCMR_ICPSC_Pos)
#define    FL_ATIM_IC_PSC_DIV8                                    (0x3U << ATIM_CCMR_ICPSC_Pos)

#define    FL_ATIM_CHANNEL_MODE_OUTPUT                            (0x0U << ATIM_CCMR_CCS_Pos)
#define    FL_ATIM_CHANNEL_MODE_INPUT_NORMAL                      (0x1U << ATIM_CCMR_CCS_Pos)
#define    FL_ATIM_CHANNEL_MODE_INPUT_CROSSOVER                   (0x2U << ATIM_CCMR_CCS_Pos)
#define    FL_ATIM_CHANNEL_MODE_INPUT_TRC                         (0x3U << ATIM_CCMR_CCS_Pos)

#define    FL_ATIM_OCN_POLARITY_NORMAL                            (0x0U << ATIM_CCER_CCNP_Pos)
#define    FL_ATIM_OCN_POLARITY_INVERT                            (0x1U << ATIM_CCER_CCNP_Pos)

#define    FL_ATIM_OC_POLARITY_NORMAL                             (0x0U << ATIM_CCER_CCOP_Pos)
#define    FL_ATIM_OC_POLARITY_INVERT                             (0x1U << ATIM_CCER_CCOP_Pos)

#define    FL_ATIM_IC_POLARITY_NORMAL                             (0x0U << ATIM_CCER_CCIP_Pos)
#define    FL_ATIM_IC_POLARITY_INVERT                             (0x1U << ATIM_CCER_CCIP_Pos)

#define    FL_ATIM_BREAK2_POLARITY_LOW                             (0x0U << ATIM_BDTR_BK2P_Pos)
#define    FL_ATIM_BREAK2_POLARITY_HIGH                            (0x1U << ATIM_BDTR_BK2P_Pos)

#define    FL_ATIM_BREAK_POLARITY_LOW                             (0x0U << ATIM_BDTR_BKP_Pos)
#define    FL_ATIM_BREAK_POLARITY_HIGH                            (0x1U << ATIM_BDTR_BKP_Pos)

#define    FL_ATIM_OSSR_DISABLE                                   (0x0U << ATIM_BDTR_OSSR_Pos)
#define    FL_ATIM_OSSR_ENABLE                                    (0x1U << ATIM_BDTR_OSSR_Pos)

#define    FL_ATIM_OSSI_DISABLE                                   (0x0U << ATIM_BDTR_OSSI_Pos)
#define    FL_ATIM_OSSI_ENABLE                                    (0x1U << ATIM_BDTR_OSSI_Pos)

#define    FL_ATIM_LOCK_LEVEL_OFF                                 (0x0U << ATIM_BDTR_LOCK_Pos)
#define    FL_ATIM_LOCK_LEVEL_1                                   (0x1U << ATIM_BDTR_LOCK_Pos)
#define    FL_ATIM_LOCK_LEVEL_2                                   (0x2U << ATIM_BDTR_LOCK_Pos)
#define    FL_ATIM_LOCK_LEVEL_3                                   (0x3U << ATIM_BDTR_LOCK_Pos)

#define    FL_ATIM_BREAK_FILTER_DIV1                              (0x0U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N2                           (0x1U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N4                           (0x2U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N8                           (0x3U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N12                           (0x4U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N16                           (0x5U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N24                           (0x6U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N32                           (0x7U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N48                           (0x8U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N64                           (0x9U << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N80                          (0xaU << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N96                          (0xbU << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N128                          (0xcU << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N160                          (0xdU << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N192                          (0xeU << ATIM_BDTR_BKF_Pos)
#define    FL_ATIM_BREAK_FILTER_DIV1_N256                          (0xfU << ATIM_BDTR_BKF_Pos)

#define    FL_ATIM_INDEX_POSITION_DOWN_DOWN                       (0x0U << ATIM_ECR_IPOS_Pos)
#define    FL_ATIM_INDEX_POSITION_DOWN_UP                         (0x1U << ATIM_ECR_IPOS_Pos)
#define    FL_ATIM_INDEX_POSITION_UP_DOWN                         (0x2U << ATIM_ECR_IPOS_Pos)
#define    FL_ATIM_INDEX_POSITION_UP_UP                           (0x3U << ATIM_ECR_IPOS_Pos)

#define    FL_ATIM_INDEX_FIRST_ONLY                               (0x1U << ATIM_ECR_FIDX_Pos)
#define    FL_ATIM_INDEX_ALL                                      (0x0U << ATIM_ECR_FIDX_Pos)

#define    FL_ATIM_INDEX_UP_DOWN                                  (0x0U << ATIM_ECR_IDIR_Pos)
#define    FL_ATIM_INDEX_UP                                       (0x1U << ATIM_ECR_IDIR_Pos)
#define    FL_ATIM_INDEX_DOWN                                     (0x2U << ATIM_ECR_IDIR_Pos)

#define    FL_ATIM_TIM_CH                                        (0x0U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN1                                    (0x1U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN2                                    (0x2U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN3                                    (0x3U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN4                                    (0x4U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN5                                    (0x5U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN6                                    (0x6U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN7                                    (0x7U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN8                                    (0x8U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN9                                    (0x9U << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN10                                   (0xaU << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN11                                   (0xbU << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN12                                   (0xcU << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN13                                   (0xdU << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN14                                   (0xeU << ATIM_TISEL_TISEL_Pos)
#define    FL_ATIM_TIM_TI_IN15                                   (0xfU << ATIM_TISEL_TISEL_Pos)

#define    FL_ATIM_TIM_ETR_IN0                                   (0x0U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN1                                   (0x1U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN2                                   (0x2U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN3                                   (0x3U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN4                                   (0x4U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN5                                   (0x5U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN6                                   (0x6U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN7                                   (0x7U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN8                                   (0x8U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN9                                   (0x9U << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN10                                  (0xaU << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN11                                  (0xbU << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN12                                  (0xcU << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN13                                  (0xdU << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN14                                  (0xeU << ATIM_AFR_ETRSEL_Pos)
#define    FL_ATIM_TIM_ETR_IN15                                  (0xfU << ATIM_AFR_ETRSEL_Pos)

#define    FL_ATIM_OCREF_CLRSOURCE_COMP1                          (0x0U << ATIM_AFR_OCCLR_SEL_Pos)
#define    FL_ATIM_OCREF_CLRSOURCE_COMP2                          (0x1U << ATIM_AFR_OCCLR_SEL_Pos)
#define    FL_ATIM_OCREF_CLRSOURCE_COMP3                          (0x2U << ATIM_AFR_OCCLR_SEL_Pos)

#define    FL_ATIM_GROUPCH5_NONE                                  (0x0U)
#define    FL_ATIM_GROUPCH5_OC1REFC                               (0x1U << ATIM_CCR5_GC5C1_Pos)
#define    FL_ATIM_GROUPCH5_OC2REFC                               (0x1U << ATIM_CCR5_GC5C2_Pos)
#define    FL_ATIM_GROUPCH5_OC3REFC                               (0x1U << ATIM_CCR5_GC5C3_Pos)

#define    FL_ATIM_BKIN_SOURCE_GPIO1                              (0x1U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_GPIO2                              (0x2U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_COMP1                              (0x4U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_COMP2                              (0x8U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_COMP3                              (0x10U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_HFDET                              (0x100U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_SVD                                (0x200U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_LOCKUP                             (0x400U << ATIM_AFR_BKIN_E_Pos)
#define    FL_ATIM_BKIN_SOURCE_RAMPARITY                          (0x800U << ATIM_AFR_BKIN_E_Pos)

#define    FL_ATIM_DMA_BURST_LENGTH_1                             (0x0U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_2                             (0x1U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_3                             (0x2U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_4                             (0x3U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_5                             (0x4U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_6                             (0x5U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_7                             (0x6U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_8                             (0x7U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_9                             (0x8U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_10                            (0x9U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_11                            (0xaU << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_12                            (0xbU << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_13                            (0xcU << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_14                            (0xdU << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_15                            (0xeU << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_16                            (0xfU << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_17                            (0x10U << ATIM_DCR_DBL_Pos)
#define    FL_ATIM_DMA_BURST_LENGTH_18                            (0x11U << ATIM_DCR_DBL_Pos)

#define    FL_ATIM_DMA_BURST_ADDR_CR1                             (0x0U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CR2                             (0x1U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_SMCR                            (0x2U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_DIER                            (0x3U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_SR                              (0x4U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_EGR                             (0x5U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCMR1                           (0x6U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCMR2                           (0x7U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCER                            (0x8U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CNT                             (0x9U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_PSC                             (0xaU << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_ARR                             (0xbU << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_RCR                             (0xcU << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCR1                            (0xdU << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCR2                            (0xeU << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCR3                            (0xfU << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_CCR4                            (0x10U << ATIM_DCR_DBA_Pos)
#define    FL_ATIM_DMA_BURST_ADDR_BDTR                            (0x11U << ATIM_DCR_DBA_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup ATIM_FL_Exported_Functions ATIM Exported Functions
  * @{
  */

/**
  * @brief    UIF remap enable
  * @rmtoll   CR1    UIFREMAP    FL_ATIM_EnableUIFRemap
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableUIFRemap(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_UIFREMAP_Msk);
}

/**
  * @brief    Get UIF remap  status
  * @rmtoll   CR1    UIFREMAP    FL_ATIM_IsEnabledUIFRemap
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledUIFRemap(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_UIFREMAP_Msk) == ATIM_CR1_UIFREMAP_Msk);
}

/**
  * @brief    UIF remap  disable
  * @rmtoll   CR1    UIFREMAP    FL_ATIM_DisableUIFRemap
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableUIFRemap(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_UIFREMAP_Msk);
}

/**
  * @brief    Set clock division
  * @rmtoll   CR1    CKD    FL_ATIM_SetClockDivision
  * @param    TIMx TIM instance
  * @param    div This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CLK_DIVISION_DIV1
  *           @arg @ref FL_ATIM_CLK_DIVISION_DIV2
  *           @arg @ref FL_ATIM_CLK_DIVISION_DIV4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetClockDivision(ATIM_Type *TIMx, uint32_t div)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_CKD_Msk, div);
}

/**
  * @brief    Get clock division
  * @rmtoll   CR1    CKD    FL_ATIM_GetClockDivision
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_CLK_DIVISION_DIV1
  *           @arg @ref FL_ATIM_CLK_DIVISION_DIV2
  *           @arg @ref FL_ATIM_CLK_DIVISION_DIV4
  */
__STATIC_INLINE uint32_t FL_ATIM_GetClockDivision(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_CKD_Msk));
}

/**
  * @brief    ARRP reload enable
  * @rmtoll   CR1    ARPE    FL_ATIM_EnableARRPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableARRPreload(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_ARPE_Msk);
}

/**
  * @brief    Get ARRP reload enable status
  * @rmtoll   CR1    ARPE    FL_ATIM_IsEnabledARRPreload
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledARRPreload(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_ARPE_Msk) == ATIM_CR1_ARPE_Msk);
}

/**
  * @brief    ARRP reload disable
  * @rmtoll   CR1    ARPE    FL_ATIM_DisableARRPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableARRPreload(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_ARPE_Msk);
}

/**
  * @brief    Set counter aligned mode
  * @rmtoll   CR1    CMS    FL_ATIM_SetCounterAlignedMode
  * @param    TIMx TIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_EDGE
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_CENTER_DOWN
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_CENTER_UP
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetCounterAlignedMode(ATIM_Type *TIMx, uint32_t mode)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_CMS_Msk, mode);
}

/**
  * @brief    Get counter aligned mode
  * @rmtoll   CR1    CMS    FL_ATIM_GetCounterAlignedMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_EDGE
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_CENTER_DOWN
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_CENTER_UP
  *           @arg @ref FL_ATIM_COUNTER_ALIGNED_CENTER_UP_DOWN
  */
__STATIC_INLINE uint32_t FL_ATIM_GetCounterAlignedMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_CMS_Msk));
}

/**
  * @brief    Set counter direction
  * @rmtoll   CR1    DIR    FL_ATIM_SetCounterDirection
  * @param    TIMx TIM instance
  * @param    dir This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_COUNTER_DIR_UP
  *           @arg @ref FL_ATIM_COUNTER_DIR_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetCounterDirection(ATIM_Type *TIMx, uint32_t dir)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_DIR_Msk, dir);
}

/**
  * @brief    Get counter direction
  * @rmtoll   CR1    DIR    FL_ATIM_GetCounterDirection
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_COUNTER_DIR_UP
  *           @arg @ref FL_ATIM_COUNTER_DIR_DOWN
  */
__STATIC_INLINE uint32_t FL_ATIM_GetCounterDirection(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_DIR_Msk));
}

/**
  * @brief    Set one pulse mode
  * @rmtoll   CR1    OPM    FL_ATIM_SetOnePulseMode
  * @param    TIMx TIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_ONE_PULSE_MODE_CONTINUOUS
  *           @arg @ref FL_ATIM_ONE_PULSE_MODE_SINGLE
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetOnePulseMode(ATIM_Type *TIMx, uint32_t mode)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_OPM_Msk, mode);
}

/**
  * @brief    Get one pulse mode
  * @rmtoll   CR1    OPM    FL_ATIM_GetOnePulseMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_ONE_PULSE_MODE_CONTINUOUS
  *           @arg @ref FL_ATIM_ONE_PULSE_MODE_SINGLE
  */
__STATIC_INLINE uint32_t FL_ATIM_GetOnePulseMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_OPM_Msk));
}

/**
  * @brief    Set update source
  * @rmtoll   CR1    URS    FL_ATIM_SetUpdateSource
  * @param    TIMx TIM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_UPDATE_SOURCE_REGULAR
  *           @arg @ref FL_ATIM_UPDATE_SOURCE_COUNTER
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetUpdateSource(ATIM_Type *TIMx, uint32_t source)
{
    MODIFY_REG(TIMx->CR1, ATIM_CR1_URS_Msk, source);
}

/**
  * @brief    Get update source
  * @rmtoll   CR1    URS    FL_ATIM_GetUpdateSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_UPDATE_SOURCE_REGULAR
  *           @arg @ref FL_ATIM_UPDATE_SOURCE_COUNTER
  */
__STATIC_INLINE uint32_t FL_ATIM_GetUpdateSource(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_URS_Msk));
}

/**
  * @brief    Update event enable
  * @rmtoll   CR1    UDIS    FL_ATIM_EnableUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableUpdateEvent(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_UDIS_Msk);
}

/**
  * @brief    Get update event enable status
  * @rmtoll   CR1    UDIS    FL_ATIM_IsEnabledUpdateEvent
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledUpdateEvent(ATIM_Type *TIMx)
{
    return (uint32_t)!(READ_BIT(TIMx->CR1, ATIM_CR1_UDIS_Msk) == ATIM_CR1_UDIS_Msk);
}

/**
  * @brief    Disable update event
  * @rmtoll   CR1    UDIS    FL_ATIM_DisableUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableUpdateEvent(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_UDIS_Msk);
}

/**
  * @brief    counter enable
  * @rmtoll   CR1    CEN    FL_ATIM_Enable
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_Enable(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->CR1, ATIM_CR1_CEN_Msk);
}

/**
  * @brief    Get counter enable status
  * @rmtoll   CR1    CEN    FL_ATIM_IsEnabled
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabled(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR1, ATIM_CR1_CEN_Msk) == ATIM_CR1_CEN_Msk);
}

/**
  * @brief    counter disable
  * @rmtoll   CR1    CEN    FL_ATIM_Disable
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_Disable(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->CR1, ATIM_CR1_CEN_Msk);
}

/**
  * @brief    Set the synchronous trigger signal source
  * @rmtoll   CR2    MMS2    FL_ATIM_SetTriggerOutput2
  * @param    TIMx TIM instance
  * @param    triggerOutput This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TRGO2_UG
  *           @arg @ref FL_ATIM_TRGO2_ENABLE
  *           @arg @ref FL_ATIM_TRGO2_UPDATE
  *           @arg @ref FL_ATIM_TRGO2_CC1IF
  *           @arg @ref FL_ATIM_TRGO2_OC1REF
  *           @arg @ref FL_ATIM_TRGO2_OC2REF
  *           @arg @ref FL_ATIM_TRGO2_OC3REF
  *           @arg @ref FL_ATIM_TRGO2_OC4REF
  *           @arg @ref FL_ATIM_TRGO2_OC5REF
  *           @arg @ref FL_ATIM_TRGO2_OC6REF
  *           @arg @ref FL_ATIM_TRGO2_OC4REF_RISINGFALLING
  *           @arg @ref FL_ATIM_TRGO2_OC6REF_RISINGFALLING
  *           @arg @ref FL_ATIM_TRGO2_OC4REF_RISING_OC6REF_RISING
  *           @arg @ref FL_ATIM_TRGO2_OC4REF_RISING_OC6REF_FALLING
  *           @arg @ref FL_ATIM_TRGO2_OC5REF_RISING_OC6REF_RISING
  *           @arg @ref FL_ATIM_TRGO2_OC5REF_RISING_OC6REF_FALLING
  * @param    TIMx TIM instance
  * @param    triggerOutput This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TRGO2_UG
  *           @arg @ref FL_ATIM_TRGO2_ENABLE
  *           @arg @ref FL_ATIM_TRGO2_UPDATE
  *           @arg @ref FL_ATIM_TRGO2_CC1IF
  *           @arg @ref FL_ATIM_TRGO2_OC1REF
  *           @arg @ref FL_ATIM_TRGO2_OC2REF
  *           @arg @ref FL_ATIM_TRGO2_OC3REF
  *           @arg @ref FL_ATIM_TRGO2_OC4REF
  *           @arg @ref FL_ATIM_TRGO2_OC5REF
  *           @arg @ref FL_ATIM_TRGO2_OC6REF
  *           @arg @ref FL_ATIM_TRGO2_OC4REF_RISINGFALLING
  *           @arg @ref FL_ATIM_TRGO2_OC6REF_RISINGFALLING
  *           @arg @ref FL_ATIM_TRGO2_OC4REF_RISING_OC6REF_RISING
  *           @arg @ref FL_ATIM_TRGO2_OC4REF_RISING_OC6REF_FALLING
  *           @arg @ref FL_ATIM_TRGO2_OC5REF_RISING_OC6REF_RISING
  *           @arg @ref FL_ATIM_TRGO2_OC5REF_RISING_OC6REF_FALLING
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetTriggerOutput2(ATIM_Type *TIMx, uint32_t triggerOutput)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_MMS2_Msk, triggerOutput);
}

/**
  * @brief    Set the OCN output idle state
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OISN    FL_ATIM_OC_SetReverseChannelIdleState
  * @param    TIMx TIM instance
  * @param    OCNIdleState This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OCN_IDLE_STATE_LOW
  *           @arg @ref FL_ATIM_OCN_IDLE_STATE_HIGH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_SetReverseChannelIdleState(ATIM_Type *TIMx, uint32_t OCNIdleState, uint32_t channel)
{
    MODIFY_REG(TIMx->CR2, (ATIM_CR2_OISN_Msk << (channel * 2)), OCNIdleState << (channel * 2));
}

/**
  * @brief    Get the OCN output idle state
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OISN    FL_ATIM_OC_GetReverseChannelIdleState
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OCN_IDLE_STATE_LOW
  *           @arg @ref FL_ATIM_OCN_IDLE_STATE_HIGH
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_GetReverseChannelIdleState(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, (ATIM_CR2_OISN_Msk << (channel * 2))));
}

/**
  * @brief    Set the OC output idle state
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OIS    FL_ATIM_OC_SetChannelIdleState
  * @param    TIMx TIM instance
  * @param    OCIdleState This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OC_IDLE_STATE_LOW
  *           @arg @ref FL_ATIM_OC_IDLE_STATE_HIGH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6

  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_SetChannelIdleState(ATIM_Type *TIMx, uint32_t OCIdleState, uint32_t channel)
{
    MODIFY_REG(TIMx->CR2, (ATIM_CR2_OIS_Msk << (channel * 2)), OCIdleState << (channel * 2));
}

/**
  * @brief    Get the OC output idle state
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    OIS    FL_ATIM_OC_GetChannelIdleState
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6

  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OC_IDLE_STATE_LOW
  *           @arg @ref FL_ATIM_OC_IDLE_STATE_HIGH
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_GetChannelIdleState(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, (ATIM_CR2_OIS_Msk << (channel * 2))));
}

/**
  * @brief    Channel 1 input source selection
  * @rmtoll   CR2    TI1S    FL_ATIM_IC_EnableXORCombination
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_EnableXORCombination(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->CR2, ATIM_CR2_TI1S_Msk);
}

/**
  * @brief    Read the channel 1 input source

  * @rmtoll   CR2    TI1S    FL_ATIM_IC_IsEnabledXORCombination
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IC_IsEnabledXORCombination(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_TI1S_Msk) == ATIM_CR2_TI1S_Msk);
}

/**
  * @brief    XOR combinations are disabled for channel 1 input sources
  * @rmtoll   CR2    TI1S    FL_ATIM_IC_DisableXORCombination
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_DisableXORCombination(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->CR2, ATIM_CR2_TI1S_Msk);
}

/**
  * @brief    Set the synchronous trigger signal source
  * @rmtoll   CR2    MMS    FL_ATIM_SetTriggerOutput
  * @param    TIMx TIM instance
  * @param    triggerOutput This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TRGO_RESET
  *           @arg @ref FL_ATIM_TRGO_ENABLE
  *           @arg @ref FL_ATIM_TRGO_UPDATE
  *           @arg @ref FL_ATIM_TRGO_CC1IF
  *           @arg @ref FL_ATIM_TRGO_OC1REF
  *           @arg @ref FL_ATIM_TRGO_OC2REF
  *           @arg @ref FL_ATIM_TRGO_OC3REF
  *           @arg @ref FL_ATIM_TRGO_OC4REF
  *           @arg @ref FL_ATIM_TRGO_ENCODER
  *           @arg @ref FL_ATIM_TRGO_OCREF1_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF2_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF3_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF4_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF5_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF6_FALLING
  *           @arg @ref FL_ATIM_TRGO_OC4REF_FALLING_OCREF6_FALLING
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetTriggerOutput(ATIM_Type *TIMx, uint32_t triggerOutput)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_MMS_Msk, triggerOutput);
}

/**
  * @brief    读取同步触发源
  * @rmtoll   CR2    MMS    FL_ATIM_GetTriggerOutput
  * @param    TIMx TIM instance
  * @param    triggerOutput This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TRGO_RESET
  *           @arg @ref FL_ATIM_TRGO_ENABLE
  *           @arg @ref FL_ATIM_TRGO_UPDATE
  *           @arg @ref FL_ATIM_TRGO_CC1IF
  *           @arg @ref FL_ATIM_TRGO_OC1REF
  *           @arg @ref FL_ATIM_TRGO_OC2REF
  *           @arg @ref FL_ATIM_TRGO_OC3REF
  *           @arg @ref FL_ATIM_TRGO_OC4REF
  *           @arg @ref FL_ATIM_TRGO_ENCODER
  *           @arg @ref FL_ATIM_TRGO_OCREF1_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF2_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF3_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF4_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF5_FALLING
  *           @arg @ref FL_ATIM_TRGO_OCREF6_FALLING
  *           @arg @ref FL_ATIM_TRGO_OC4REF_FALLING_OCREF6_FALLING
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_ATIM_GetTriggerOutput(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_MMS_Msk));
}

/**
  * @brief    Set the trigger of the capture/compare DMA request
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    CCDS    FL_ATIM_SetDMAReqTrigger
  * @param    TIMx TIM instance
  * @param    DMAReqTrigger This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CCDMAREQUEST_CC
  *           @arg @ref FL_ATIM_CCDMAREQUEST_UPDATE
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetDMAReqTrigger(ATIM_Type *TIMx, uint32_t DMAReqTrigger)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_CCDS_Msk, DMAReqTrigger);
}

/**
  * @brief    Get the trigger of the capture/compare DMA request
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    CCDS    FL_ATIM_GetDMAReqTrigger
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_CCDMAREQUEST_CC
  */
__STATIC_INLINE uint32_t FL_ATIM_GetDMAReqTrigger(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_CCDS_Msk));
}

/**
  * @brief    Set the updated source of the capture/compare control bits (CCxE, CCxNE and OCxM)
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    CCUS    FL_ATIM_SetUpdate
  * @param    TIMx TIM instance
  * @param    CCUpdateSource This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CCUPDATESOURCE_COMG_ONLY
  *           @arg @ref FL_ATIM_CCUPDATESOURCE_COMG_AND_TRGI
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetUpdate(ATIM_Type *TIMx, uint32_t CCUpdateSource)
{
    MODIFY_REG(TIMx->CR2, ATIM_CR2_CCUS_Msk, CCUpdateSource);
}

/**
  * @brief    Get the updated source of the capture/compare control bits (CCxE, CCxNE and OCxM)
  * @note     仅仅高级定时器支持
  * @rmtoll   CR2    CCUS    FL_ATIM_GetUpdate
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_CCUPDATESOURCE_COMG_ONLY
  *           @arg @ref FL_ATIM_CCUPDATESOURCE_COMG_AND_TRGI
  */
__STATIC_INLINE uint32_t FL_ATIM_GetUpdate(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_CCUS_Msk));
}

/**
  * @brief    CC preload control enable
  * @rmtoll   CR2    CCPC    FL_ATIM_CC_EnablePreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_CC_EnablePreload(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->CR2, ATIM_CR2_CCPC_Msk);
}

/**
  * @brief    Get CC preload control enable status
  * @rmtoll   CR2    CCPC    FL_ATIM_CC_IsEnabledPreload
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_CC_IsEnabledPreload(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CR2, ATIM_CR2_CCPC_Msk) == ATIM_CR2_CCPC_Msk);
}

/**
  * @brief    CC preload control disable
  * @rmtoll   CR2    CCPC    FL_ATIM_CC_DisablePreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_CC_DisablePreload(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->CR2, ATIM_CR2_CCPC_Msk);
}

/**
  * @brief    Set the preload source of SMS
  * @rmtoll   SMCR    SMSPS    FL_ATIM_SetSMSPreloadSource
  * @param    TIMx TIM instance
  * @param    PreloadSource This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_SMSPS_TIMUPDATE
  *           @arg @ref FL_ATIM_OCREF_INDEX
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetSMSPreloadSource(ATIM_Type *TIMx, uint32_t PreloadSource)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_SMSPS_Msk, PreloadSource);
}

/**
  * @brief    Get the preload source of SMS
  * @rmtoll   SMCR    SMSPS    FL_ATIM_GetSMSPreloadSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_SMSPS_TIMUPDATE
  *           @arg @ref FL_ATIM_OCREF_INDEX
  */
__STATIC_INLINE uint32_t FL_ATIM_GetSMSPreloadSource(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_SMSPS_Msk));
}

/**
  * @brief    Enable SMS preload
  * @rmtoll   SMCR    SMSPE    FL_ATIM_EnableSMSPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableSMSPreload(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->SMCR, ATIM_SMCR_SMSPE_Msk);
}

/**
  * @brief    Indicate whether  SMS preload is enabled
  * @rmtoll   SMCR    SMSPE    FL_ATIM_IsEnabledSMSPreload
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledSMSPreload(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_SMSPE_Msk) == ATIM_SMCR_SMSPE_Msk);
}

/**
  * @brief    Disable SMS preload
  * @rmtoll   SMCR    SMSPE    FL_ATIM_DisableSMSPreload
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableSMSPreload(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->SMCR, ATIM_SMCR_SMSPE_Msk);
}

/**
  * @brief    Set the OCREF clear input sourc
  * @rmtoll   SMCR    OCCS    FL_ATIM_SetOCRefClearInputSource
  * @param    TIMx TIM instance
  * @param    OCRefClearInputSource This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OCREF_CLR
  *           @arg @ref FL_ATIM_OCREF_ETRF
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetOCRefClearInputSource(ATIM_Type *TIMx, uint32_t OCRefClearInputSource)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_OCCS_Msk, OCRefClearInputSource);
}

/**
  * @brief    Get the OCREF clear input sourc
  * @rmtoll   SMCR    OCCS    FL_ATIM_GetOCRefClearInputSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OCREF_CLR
  *           @arg @ref FL_ATIM_OCREF_ETRF
  */
__STATIC_INLINE uint32_t FL_ATIM_GetOCRefClearInputSource(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_OCCS_Msk));
}

/**
  * @brief    Set external trigger polarity
  * @rmtoll   SMCR    ETP    FL_ATIM_SetETRPolarity
  * @param    TIMx TIM instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_ETR_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_ETR_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetETRPolarity(ATIM_Type *TIMx, uint32_t polarity)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_ETP_Msk, polarity);
}

/**
  * @brief    Get external trigger polarity
  * @rmtoll   SMCR    ETP    FL_ATIM_GetETRPolarity
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_ETR_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_ETR_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_ATIM_GetETRPolarity(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ETP_Msk));
}

/**
  * @brief    External clock enable
  * @rmtoll   SMCR    ECE    FL_ATIM_EnableExternalClock
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableExternalClock(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->SMCR, ATIM_SMCR_ECE_Msk);
}

/**
  * @brief    Get external clock enable states
  * @rmtoll   SMCR    ECE    FL_ATIM_IsEnabledExternalClock
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledExternalClock(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ECE_Msk) == ATIM_SMCR_ECE_Msk);
}

/**
  * @brief    External clock disable
  * @rmtoll   SMCR    ECE    FL_ATIM_DisableExternalClock
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableExternalClock(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->SMCR, ATIM_SMCR_ECE_Msk);
}

/**
  * @brief    Set external trigger prescaler
  * @rmtoll   SMCR    ETPS    FL_ATIM_SetETRPrescaler
  * @param    TIMx TIM instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_ETR_PSC_DIV1
  *           @arg @ref FL_ATIM_ETR_PSC_DIV2
  *           @arg @ref FL_ATIM_ETR_PSC_DIV4
  *           @arg @ref FL_ATIM_ETR_PSC_DIV8
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetETRPrescaler(ATIM_Type *TIMx, uint32_t psc)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_ETPS_Msk, psc);
}

/**
  * @brief    Get external trigger prescaler
  * @rmtoll   SMCR    ETPS    FL_ATIM_GetETRPrescaler
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_ETR_PSC_DIV1
  *           @arg @ref FL_ATIM_ETR_PSC_DIV2
  *           @arg @ref FL_ATIM_ETR_PSC_DIV4
  *           @arg @ref FL_ATIM_ETR_PSC_DIV8
  */
__STATIC_INLINE uint32_t FL_ATIM_GetETRPrescaler(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ETPS_Msk));
}

/**
  * @brief    Set external trigger signal filter clock and length
  * @rmtoll   SMCR    ETF    FL_ATIM_SetETRFilter
  * @param    TIMx TIM instance
  * @param    filter This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1_N2
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1_N4
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV2_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV2_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV4_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV4_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV8_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV8_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV16_N5
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV16_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV16_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV32_N5
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV32_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV32_N8
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetETRFilter(ATIM_Type *TIMx, uint32_t filter)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_ETF_Msk, filter);
}

/**
  * @brief    Get external trigger signal filter clock and length
  * @rmtoll   SMCR    ETF    FL_ATIM_GetETRFilter
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1_N2
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1_N4
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV1_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV2_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV2_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV4_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV4_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV8_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV8_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV16_N5
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV16_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV16_N8
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV32_N5
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV32_N6
  *           @arg @ref FL_ATIM_ETR_FILTER_DIV32_N8
  */
__STATIC_INLINE uint32_t FL_ATIM_GetETRFilter(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_ETF_Msk));
}

/**
  * @brief    Master slave mode enable
  * @rmtoll   SMCR    MSM    FL_ATIM_EnableMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableMasterSlaveMode(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->SMCR, ATIM_SMCR_MSM_Msk);
}

/**
  * @brief    Get master slave mode enable status
  * @rmtoll   SMCR    MSM    FL_ATIM_IsEnabledMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledMasterSlaveMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_MSM_Msk) == ATIM_SMCR_MSM_Msk);
}

/**
  * @brief    Master slave mode disable
  * @rmtoll   SMCR    MSM    FL_ATIM_DisableMasterSlaveMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableMasterSlaveMode(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->SMCR, ATIM_SMCR_MSM_Msk);
}

/**
  * @brief    Set synchronizing counter trigger Source
  * @rmtoll   SMCR    TS    FL_ATIM_SetTriggerInput
  * @param    TIMx TIM instance
  * @param    triggerInput This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TRGI_ITR0
  *           @arg @ref FL_ATIM_TRGI_ITR1
  *           @arg @ref FL_ATIM_TRGI_ITR2
  *           @arg @ref FL_ATIM_TRGI_ITR3
  *           @arg @ref FL_ATIM_TRGI_TI1F_EDGE
  *           @arg @ref FL_ATIM_TRGI_TI1FP1
  *           @arg @ref FL_ATIM_TRGI_TI2FP2
  *           @arg @ref FL_ATIM_TRGI_ETRF
  *           @arg @refFL_ATIM_TRGI_ITR4
  *           @arg @refFL_ATIM_TRGI_ITR5
  *           @arg @refFL_ATIM_TRGI_ITR6
  *           @arg @refFL_ATIM_TRGI_ITR7
  *           @arg @refFL_ATIM_TRGI_ITR8
  *           @arg @refFL_ATIM_TRGI_ITR9
  *           @arg @refFL_ATIM_TRGI_ITR10
  *           @arg @refFL_ATIM_TRGI_ITR11
  *           @arg @refFL_ATIM_TRGI_ITR12
  *           @arg @refFL_ATIM_TRGI_ITR13
  *           @arg @refFL_ATIM_TRGI_ITR14
  *           @arg @refFL_ATIM_TRGI_ITR15
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetTriggerInput(ATIM_Type *TIMx, uint32_t triggerInput)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_TS_Msk, triggerInput);
}

/**
  * @brief    Get  synchronizing counter trigger Source
  * @rmtoll   SMCR    TS    FL_ATIM_GetTriggerInput
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_TRGI_ITR0
  *           @arg @ref FL_ATIM_TRGI_ITR1
  *           @arg @ref FL_ATIM_TRGI_ITR2
  *           @arg @ref FL_ATIM_TRGI_ITR3
  *           @arg @ref FL_ATIM_TRGI_TI1F_EDGE
  *           @arg @ref FL_ATIM_TRGI_TI1FP1
  *           @arg @ref FL_ATIM_TRGI_TI2FP2
  *           @arg @ref FL_ATIM_TRGI_ETRF
  *           @arg @refFL_ATIM_TRGI_ITR4
  *           @arg @refFL_ATIM_TRGI_ITR5
  *           @arg @refFL_ATIM_TRGI_ITR6
  *           @arg @refFL_ATIM_TRGI_ITR7
  *           @arg @refFL_ATIM_TRGI_ITR8
  *           @arg @refFL_ATIM_TRGI_ITR9
  *           @arg @refFL_ATIM_TRGI_ITR10
  *           @arg @refFL_ATIM_TRGI_ITR11
  *           @arg @refFL_ATIM_TRGI_ITR12
  *           @arg @refFL_ATIM_TRGI_ITR13
  *           @arg @refFL_ATIM_TRGI_ITR14
  *           @arg @refFL_ATIM_TRGI_ITR15
  */
__STATIC_INLINE uint32_t FL_ATIM_GetTriggerInput(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_TS_Msk));
}

/**
  * @brief    Set slave mode
  * @rmtoll   SMCR    SMS    FL_ATIM_SetSlaveMode
  * @param    TIMx TIM instance
  * @param    encoderMode This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_SLAVE_MODE_PROHIBITED
  *           @arg @ref FL_ATIM_SLAVE_MODE_ENCODER_X1_TI1
  *           @arg @ref FL_ATIM_SLAVE_MODE_ENCODER_X2_TI2
  *           @arg @ref FL_ATIM_SLAVE_MODE_ENCODER_X4_TI1TI2
  *           @arg @ref FL_ATIM_SLAVE_MODE_TRGI_RISE_RST
  *           @arg @ref FL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN
  *           @arg @ref FL_ATIM_SLAVE_MODE_TRGI_RISE_RUN
  *           @arg @ref FL_ATIM_SLAVE_MODE_EXT_MODE1
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetSlaveMode(ATIM_Type *TIMx, uint32_t encoderMode)
{
    MODIFY_REG(TIMx->SMCR, ATIM_SMCR_SMS_Msk, encoderMode);
}

/**
  * @brief    Get slave mode
  * @rmtoll   SMCR    SMS    FL_ATIM_GetSlaveMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_SLAVE_MODE_PROHIBITED
  *           @arg @ref FL_ATIM_SLAVE_MODE_ENCODER_X1_TI1
  *           @arg @ref FL_ATIM_SLAVE_MODE_ENCODER_X2_TI2
  *           @arg @ref FL_ATIM_SLAVE_MODE_ENCODER_X4_TI1TI2
  *           @arg @ref FL_ATIM_SLAVE_MODE_TRGI_RISE_RST
  *           @arg @ref FL_ATIM_SLAVE_MODE_TRGI_HIGH_RUN
  *           @arg @ref FL_ATIM_SLAVE_MODE_TRGI_RISE_RUN
  *           @arg @ref FL_ATIM_SLAVE_MODE_EXT_MODE1
  */
__STATIC_INLINE uint32_t FL_ATIM_GetSlaveMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->SMCR, ATIM_SMCR_SMS_Msk));
}

/**
  * @brief    Enable transition error interrupt (TERRIE)
  * @rmtoll   DIER    TERRIE    FL_ATIM_EnableIT_TERR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_TERR(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_TERRIE_Msk);
}

/**
  * @brief    ndicates whether the transition error interrupt (TERRIE) is enabled
  * @rmtoll   DIER    TERRIE    FL_ATIM_IsEnabledIT_TERR
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_TERR(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_TERRIE_Msk) == ATIM_DIER_TERRIE_Msk);
}

/**
  * @brief    Disable transition error interrupt (TERRIE)
  * @rmtoll   DIER    TERRIE    FL_ATIM_DisableIT_TERR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_TERR(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_TERRIE_Msk);
}

/**
  * @brief    Enable index error interrupt (IERRIE)
  * @rmtoll   DIER    IERRIE    FL_ATIM_EnableIT_IERR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_IERR(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_IERRIE_Msk);
}

/**
  * @brief    Indicates whether the index error interrupt (IERRIE) is enabled.
  * @rmtoll   DIER    IERRIE    FL_ATIM_IsEnabledIT_IERR
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_IERR(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_IERRIE_Msk) == ATIM_DIER_IERRIE_Msk);
}

/**
  * @brief    Disable index error interrupt (IERRIE)
  * @rmtoll   DIER    IERRIE    FL_ATIM_DisableIT_IERR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_IERR(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_IERRIE_Msk);
}

/**
  * @brief    Enable direction change interrupt (DIRIE)
  * @rmtoll   DIER    DIRIE    FL_ATIM_EnableIT_DIR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_DIR(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_DIRIE_Msk);
}

/**
  * @brief     Indicates whether the direction change interrupt (DIRIE) is enabled.
  * @rmtoll   DIER    DIRIE    FL_ATIM_IsEnabledIT_DIR
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_DIR(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_DIRIE_Msk) == ATIM_DIER_DIRIE_Msk);
}

/**
  * @brief    Disable direction change interrupt (DIRIE).
  * @rmtoll   DIER    DIRIE    FL_ATIM_DisableIT_DIR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_DIR(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_DIRIE_Msk);
}

/**
  * @brief    Enable index interrupt (IDXIE).
  * @rmtoll   DIER    IDXIE    FL_ATIM_EnableIT_IDX
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_IDX(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_IDXIE_Msk);
}

/**
  * @brief    Indicates whether the index interrupt (IDXIE) is enabled.
  * @rmtoll   DIER    IDXIE    FL_ATIM_IsEnabledIT_IDX
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_IDX(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_IDXIE_Msk) == ATIM_DIER_IDXIE_Msk);
}

/**
  * @brief    Disable index interrupt (IDXIE).
  * @rmtoll   DIER    IDXIE    FL_ATIM_DisableIT_IDX
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_IDX(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_IDXIE_Msk);
}

/**
  * @brief    CC1 Burst modle enable
  * @rmtoll   DIER    CC1BURSTEN    FL_ATIM_EnableCC1DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableCC1DMABurstMode(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    Get CC1 burst enable status
  * @rmtoll   DIER    CC1BURSTEN    FL_ATIM_IsEnabledCC1DMABurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledCC1DMABurstMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC1BURSTEN_Msk) == ATIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    CC1 Burst modle disable
  * @rmtoll   DIER    CC1BURSTEN    FL_ATIM_DisableCC1DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableCC1DMABurstMode(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC1BURSTEN_Msk);
}

/**
  * @brief    CC2 Burst modle enable
  * @rmtoll   DIER    CC2BURSTEN    FL_ATIM_EnableCC2DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableCC2DMABurstMode(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    Get CC2 burst enable status
  * @rmtoll   DIER    CC2BURSTEN    FL_ATIM_IsEnabledCC2DMABurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledCC2DMABurstMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC2BURSTEN_Msk) == ATIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    CC2 Burst modle disable
  * @rmtoll   DIER    CC2BURSTEN    FL_ATIM_DisableCC2DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableCC2DMABurstMode(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC2BURSTEN_Msk);
}

/**
  * @brief    CC3 Burst modle enable
  * @rmtoll   DIER    CC3BURSTEN    FL_ATIM_EnableCC3DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableCC3DMABurstMode(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    Get CC3 burst enable status
  * @rmtoll   DIER    CC3BURSTEN    FL_ATIM_IsEnabledCC3DMABurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledCC3DMABurstMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC3BURSTEN_Msk) == ATIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    CC3 Burst modle disable
  * @rmtoll   DIER    CC3BURSTEN    FL_ATIM_DisableCC3DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableCC3DMABurstMode(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC3BURSTEN_Msk);
}

/**
  * @brief    CC4 Burst modle enable
  * @rmtoll   DIER    CC4BURSTEN    FL_ATIM_EnableCC4DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableCC4DMABurstMode(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    Get CC4 burst enable status
  * @rmtoll   DIER    CC4BURSTEN    FL_ATIM_IsEnabledCC4DMABurstMode
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledCC4DMABurstMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_CC4BURSTEN_Msk) == ATIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    CC4 Burst modle disable
  * @rmtoll   DIER    CC4BURSTEN    FL_ATIM_DisableCC4DMABurstMode
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableCC4DMABurstMode(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CC4BURSTEN_Msk);
}

/**
  * @brief    Triggered DMA enable
  * @rmtoll   DIER    TDE    FL_ATIM_EnableDMAReq_Trigger
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableDMAReq_Trigger(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_TDE_Msk);
}

/**
  * @brief    Get triggered DMA enable status
  * @rmtoll   DIER    TDE    FL_ATIM_IsEnabledDMAReq_Trigger
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledDMAReq_Trigger(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_TDE_Msk) == ATIM_DIER_TDE_Msk);
}

/**
  * @brief    Triggered DMA disable
  * @rmtoll   DIER    TDE    FL_ATIM_DisableDMAReq_Trigger
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableDMAReq_Trigger(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_TDE_Msk);
}

/**
  * @brief    COM event DMA enable
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMDE    FL_ATIM_EnableDMAReq_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableDMAReq_COM(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_COMDE_Msk);
}

/**
  * @brief    Get COM event DMA enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMDE    FL_ATIM_IsEnabledDMAReq_COM
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledDMAReq_COM(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_COMDE_Msk) == ATIM_DIER_COMDE_Msk);
}

/**
  * @brief    COM event DMA disable
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMDE    FL_ATIM_DisableDMAReq_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableDMAReq_COM(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_COMDE_Msk);
}

/**
  * @brief    CCx DMA enable
  * @rmtoll   DIER    CCDE    FL_ATIM_EnableDMAReq_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableDMAReq_CC(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CCDE_Msk << channel);
}

/**
  * @brief    Get CCx DMA enable
  * @rmtoll   DIER    CCDE    FL_ATIM_IsEnabledDMAReq_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledDMAReq_CC(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, (ATIM_DIER_CCDE_Msk << channel)) == (ATIM_DIER_CCDE_Msk << channel));
}

/**
  * @brief    CCx DMA disable
  * @rmtoll   DIER    CCDE    FL_ATIM_DisableDMAReq_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableDMAReq_CC(ATIM_Type *TIMx, uint32_t channel)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CCDE_Msk << channel);
}

/**
  * @brief    Update event DMA enable
  * @rmtoll   DIER    UDE    FL_ATIM_EnableDMAReq_Update
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableDMAReq_Update(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_UDE_Msk);
}

/**
  * @brief    Get update event DMA enable status
  * @rmtoll   DIER    UDE    FL_ATIM_IsEnabledDMAReq_Update
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledDMAReq_Update(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_UDE_Msk) == ATIM_DIER_UDE_Msk);
}

/**
  * @brief    Update event DMA disable
  * @rmtoll   DIER    UDE    FL_ATIM_DisableDMAReq_Update
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableDMAReq_Update(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_UDE_Msk);
}

/**
  * @brief    Break event interrupt enable
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    BIE    FL_ATIM_EnableIT_Break
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_Break(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_BIE_Msk);
}

/**
  * @brief    Get break event interrupt enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    BIE    FL_ATIM_IsEnabledIT_Break
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_Break(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_BIE_Msk) == ATIM_DIER_BIE_Msk);
}

/**
  * @brief    Break event interrupt disable
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    BIE    FL_ATIM_DisableIT_Break
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_Break(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_BIE_Msk);
}

/**
  * @brief    Trigger event interrupt enable
  * @rmtoll   DIER    TIE    FL_ATIM_EnableIT_Trigger
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_Trigger(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_TIE_Msk);
}

/**
  * @brief    Get trigger event interrupt enable status
  * @rmtoll   DIER    TIE    FL_ATIM_IsEnabledIT_Trigger
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_Trigger(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_TIE_Msk) == ATIM_DIER_TIE_Msk);
}

/**
  * @brief    Trigger event interrupt disable
  * @rmtoll   DIER    TIE    FL_ATIM_DisableIT_Trigger
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_Trigger(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_TIE_Msk);
}

/**
  * @brief    COM event interrupt enable
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMIE    FL_ATIM_EnableIT_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_COM(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_COMIE_Msk);
}

/**
  * @brief    Get COM event interrupt enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMIE    FL_ATIM_IsEnabledIT_COM
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_COM(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_COMIE_Msk) == ATIM_DIER_COMIE_Msk);
}

/**
  * @brief    COM event interrupt disable
  * @note     仅仅高级定时器支持
  * @rmtoll   DIER    COMIE    FL_ATIM_DisableIT_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_COM(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_COMIE_Msk);
}

/**
  * @brief    CCx interrupt enable
  * @rmtoll   DIER    CCIE    FL_ATIM_EnableIT_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_CC(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_CCIE_Msk << channel);
}

/**
  * @brief    Get CCx interrupt enable status
  * @rmtoll   DIER    CCIE    FL_ATIM_IsEnabledIT_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_CC(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, (ATIM_DIER_CCIE_Msk << channel)) == (ATIM_DIER_CCIE_Msk << channel));
}

/**
  * @brief    CCx interrupt disable
  * @rmtoll   DIER    CCIE    FL_ATIM_DisableIT_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_CC(ATIM_Type *TIMx, uint32_t channel)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_CCIE_Msk << channel);
}

/**
  * @brief    Update event interrupt enable
  * @rmtoll   DIER    UIE    FL_ATIM_EnableIT_Update
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIT_Update(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->DIER, ATIM_DIER_UIE_Msk);
}

/**
  * @brief    Get update event interrupt enable status
  * @rmtoll   DIER    UIE    FL_ATIM_IsEnabledIT_Update
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIT_Update(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DIER, ATIM_DIER_UIE_Msk) == ATIM_DIER_UIE_Msk);
}

/**
  * @brief    Update event interrupt enable
  * @rmtoll   DIER    UIE    FL_ATIM_DisableIT_Update
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIT_Update(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->DIER, ATIM_DIER_UIE_Msk);
}

/**
  * @brief    Indicate whether transition error interrupt flag (TERRF) is set (transition error interrupt is pending)
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    TERRIF    FL_ATIM_IsActiveFlag_TERR
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_TERR(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_TERRIF_Msk) == (ATIM_ISR_TERRIF_Msk));
}

/**
  * @brief    Clear the transition error interrupt flag (TERRF).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    TERRIF    FL_ATIM_ClearFlag_TERR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_TERR(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_TERRIF_Msk);
}

/**
  * @brief     Indicate whether index error interrupt flag (IERRF) is set (index error interrupt is pending)
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    IERRIF    FL_ATIM_IsActiveFlag_IERR
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_IERR(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_IERRIF_Msk) == (ATIM_ISR_IERRIF_Msk));
}

/**
  * @brief     Clear the index error interrupt flag (IERRF).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    IERRIF    FL_ATIM_ClearFlag_IERR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_IERR(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_IERRIF_Msk);
}

/**
  * @brief    Indicate whether direction change interrupt flag (DIRF) is set (direction change interrupt is pending).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    DIRIF    FL_ATIM_IsActiveFlag_DIR
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_DIR(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_DIRIF_Msk) == (ATIM_ISR_DIRIF_Msk));
}

/**
  * @brief    Clear the direction change interrupt flag (DIRF).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    DIRIF    FL_ATIM_ClearFlag_DIR
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_DIR(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_DIRIF_Msk);
}

/**
  * @brief    Indicate whether index interrupt flag (IDXF) is set (index interrupt is pending).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    IDXIF    FL_ATIM_IsActiveFlag_IDX
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_IDX(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_IDXIF_Msk) == (ATIM_ISR_IDXIF_Msk));
}

/**
  * @brief    Clear the index interrupt flag (IDXF)
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    IDXIF    FL_ATIM_ClearFlag_IDX
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_IDX(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_IDXIF_Msk);
}

/**
  * @brief     Over-capture interrupt flag for CCx
  * @rmtoll   ISR    CCOF    FL_ATIM_IsActiveFlag_CCOverflow
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_CCOverflow(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, (ATIM_ISR_CCOF_Msk << channel)) == (ATIM_ISR_CCOF_Msk << channel));
}

/**
  * @brief    Clear Overcapture interrupt flag
  * @rmtoll   ISR    CCOF    FL_ATIM_ClearFlag_CCOverflow
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_CCOverflow(ATIM_Type *TIMx, uint32_t channel)
{
    WRITE_REG(TIMx->ISR, (ATIM_ISR_CCOF_Msk << channel));
}

/**
  * @brief     Indicate whether break 2 interrupt flag (B2IF) is set (break 2 interrupt is pending).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    B2IF    FL_ATIM_IsActiveFlag_BRK2
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_BRK2(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_B2IF_Msk) == (ATIM_ISR_B2IF_Msk));
}

/**
  * @brief    Clear the break 2 interrupt flag (B2IF).
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    B2IF    FL_ATIM_ClearFlag_BRK2
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_BRK2(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_B2IF_Msk);
}

/**
  * @brief    Get break interrupt flag
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    BIF    FL_ATIM_IsActiveFlag_Break
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_Break(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_BIF_Msk) == (ATIM_ISR_BIF_Msk));
}

/**
  * @brief    Clear Break interrupt flag
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    BIF    FL_ATIM_ClearFlag_Break
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_Break(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_BIF_Msk);
}

/**
  * @brief    Get trigger interrupt flag
  * @rmtoll   ISR    TIF    FL_ATIM_IsActiveFlag_Trigger
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_Trigger(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_TIF_Msk) == (ATIM_ISR_TIF_Msk));
}

/**
  * @brief    Clear trigger interrupt flag
  * @rmtoll   ISR    TIF    FL_ATIM_ClearFlag_Trigger
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_Trigger(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_TIF_Msk);
}

/**
  * @brief    Get COM interrupt flag
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    COMIF    FL_ATIM_IsActiveFlag_COM
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_COM(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_COMIF_Msk) == (ATIM_ISR_COMIF_Msk));
}

/**
  * @brief    Clear COM interrupt flag
  * @note     仅仅高级定时器支持
  * @rmtoll   ISR    COMIF    FL_ATIM_ClearFlag_COM
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_COM(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_COMIF_Msk);
}

/**
  * @brief    Get CCx interrupt flag
  * @rmtoll   ISR    CCIF    FL_ATIM_IsActiveFlag_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_CC(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel <= 3)
    {
        return (uint32_t)(READ_BIT(TIMx->ISR, (ATIM_ISR_CCIF_Msk << channel)) == (ATIM_ISR_CCIF_Msk << channel));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->ISR, (ATIM_ISR_CCIF_Msk << (channel + 11))) == (ATIM_ISR_CCIF_Msk << (channel + 11)));
    }
}

/**
  * @brief    Clear CCx interrupt flag
  * @rmtoll   ISR    CCIF    FL_ATIM_ClearFlag_CC
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_CC(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel <= 3)
    {
        WRITE_REG(TIMx->ISR, (ATIM_ISR_CCIF_Msk << channel));
    }
    else
    {
        WRITE_REG(TIMx->ISR, (ATIM_ISR_CCIF_Msk << (channel + 11)));
    }

}

/**
  * @brief    Get update event interrupt flag
  * @rmtoll   ISR    UIF    FL_ATIM_IsActiveFlag_Update
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_Update(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ISR, ATIM_ISR_UIF_Msk) == (ATIM_ISR_UIF_Msk));
}

/**
  * @brief    Clear update event interrupt flag
  * @rmtoll   ISR    UIF    FL_ATIM_ClearFlag_Update
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_ClearFlag_Update(ATIM_Type *TIMx)
{
    WRITE_REG(TIMx->ISR, ATIM_ISR_UIF_Msk);
}

/**
  * @brief     Generate break 2 event.
  * @note     仅仅高级定时器支持
  * @rmtoll   EGR    B2G    FL_ATIM_GenerateBreakEvent2
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_GenerateBreakEvent2(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_B2G_Msk);
}

/**
  * @brief    Software break enable
  * @note     仅仅高级定时器支持
  * @rmtoll   EGR    BG    FL_ATIM_GenerateBreakEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_GenerateBreakEvent(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_BG_Msk);
}

/**
  * @brief    Software trigger enable
  * @rmtoll   EGR    TG    FL_ATIM_GenerateTriggerEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_GenerateTriggerEvent(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_TG_Msk);
}

/**
  * @brief    Software COM event enable
  * @note     仅仅高级定时器支持
  * @rmtoll   EGR    COMG    FL_ATIM_GenerateCOMEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_GenerateCOMEvent(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_COMG_Msk);
}

/**
  * @brief    CCx software trigger enable
  * @rmtoll   EGR    CCG    FL_ATIM_GenerateCCEvent
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_GenerateCCEvent(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_CCG_Msk << channel);
}

/**
  * @brief    Software update event enable
  * @rmtoll   EGR    UG    FL_ATIM_GenerateUpdateEvent
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_GenerateUpdateEvent(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->EGR, ATIM_EGR_UG_Msk);
}

/**
  * @brief    Get update event interrupt flag
  * @rmtoll   CNT    UIFCPY    FL_ATIM_IsActiveFlag_UpdateCopy
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsActiveFlag_UpdateCopy(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CNT, ATIM_CNT_UIFCPY_Msk) == (ATIM_CNT_UIFCPY_Msk));
}

/**
  * @brief    Set counter value
  * @rmtoll   CNT        FL_ATIM_WriteCounter
  * @param    TIMx TIM instance
  * @param    counter
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCounter(ATIM_Type *TIMx, uint32_t counter)
{
    MODIFY_REG(TIMx->CNT, (0xffffU << 0U), (counter << 0U));
}

/**
  * @brief    Get counter value
  * @rmtoll   CNT        FL_ATIM_ReadCounter
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCounter(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CNT, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set CK_CNT prescaler value
  * @rmtoll   PSC        FL_ATIM_WritePrescaler
  * @param    TIMx TIM instance
  * @param    psc
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WritePrescaler(ATIM_Type *TIMx, uint32_t psc)
{
    MODIFY_REG(TIMx->PSC, (0xffffU << 0U), (psc << 0U));
}

/**
  * @brief    Get CK_CNT prescaler value
  * @rmtoll   PSC        FL_ATIM_ReadPrescaler
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadPrescaler(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->PSC, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set Auto-Reload register value
  * @rmtoll   ARR        FL_ATIM_WriteAutoReload
  * @param    TIMx TIM instance
  * @param    autoReload
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteAutoReload(ATIM_Type *TIMx, uint32_t autoReload)
{
    MODIFY_REG(TIMx->ARR, (0xffffU << 0U), (autoReload << 0U));
}

/**
  * @brief    Get Auto-Reload register value
  * @rmtoll   ARR        FL_ATIM_ReadAutoReload
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadAutoReload(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ARR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set capture/compare channel 1 register
  * @rmtoll   CCR1        FL_ATIM_WriteCompareCH1
  * @param    TIMx TIM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCompareCH1(ATIM_Type *TIMx, uint32_t compareValue)
{
    MODIFY_REG(TIMx->CCR1, (0xffffU << 0U), (compareValue << 0U));
}

/**
  * @brief    Get capture/compare channel 1 register value
  * @rmtoll   CCR1        FL_ATIM_ReadCompareCH1
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCompareCH1(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR1, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set capture/compare channel 2 register
  * @rmtoll   CCR2        FL_ATIM_WriteCompareCH2
  * @param    TIMx TIM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCompareCH2(ATIM_Type *TIMx, uint32_t compareValue)
{
    MODIFY_REG(TIMx->CCR2, (0xffffU << 0U), (compareValue << 0U));
}

/**
  * @brief    Get capture/compare channel 2 register value
  * @rmtoll   CCR2        FL_ATIM_ReadCompareCH2
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCompareCH2(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR2, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set capture/compare channel 3 register
  * @rmtoll   CCR3        FL_ATIM_WriteCompareCH3
  * @param    TIMx TIM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCompareCH3(ATIM_Type *TIMx, uint32_t compareValue)
{
    MODIFY_REG(TIMx->CCR3, (0xffffU << 0U), (compareValue << 0U));
}

/**
  * @brief    Get capture/compare channel 3 register value
  * @rmtoll   CCR3        FL_ATIM_ReadCompareCH3
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCompareCH3(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR3, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set capture/compare channel 4 register
  * @rmtoll   CCR4        FL_ATIM_WriteCompareCH4
  * @param    TIMx TIM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCompareCH4(ATIM_Type *TIMx, uint32_t compareValue)
{
    MODIFY_REG(TIMx->CCR4, (0xffffU << 0U), (compareValue << 0U));
}

/**
  * @brief    Get capture/compare channel 4 register value
  * @rmtoll   CCR4        FL_ATIM_ReadCompareCH4
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCompareCH4(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR4, (0xffffU << 0U)) >> 0U);
}
/**
  * @brief  Select on which reference signal the OC5REF is combined to.
  * @note Macro IS_TIM_COMBINED3PHASEPWM_INSTANCE(TIMx) can be used to check
  *       whether or not a timer instance supports the combined 3-phase PWM mode.
  * @rmtoll CCR5         GC5C3          FL_ATIM_SetCH5CombinedChannels\n
  *         CCR5         GC5C2          FL_ATIM_SetCH5CombinedChannels\n
  *         CCR5         GC5C1          FL_ATIM_SetCH5CombinedChannels
  * @param  TIMx Timer instance
  * @param  GroupCH5 This parameter can be a combination of the following values:
  *         @arg @ref FL_ATIM_GROUPCH5_NONE
  *         @arg @ref FL_ATIM_GROUPCH5_OC1REFC
  *         @arg @ref FL_ATIM_GROUPCH5_OC2REFC
  *         @arg @ref FL_ATIM_GROUPCH5_OC3REFC
  * @retval None
  */
__STATIC_INLINE void FL_ATIM_SetCH5CombinedChannels(ATIM_Type *TIMx, uint32_t GroupCH5)
{
    MODIFY_REG(TIMx->CCR5, (ATIM_CCR5_GC5C3_Msk | ATIM_CCR5_GC5C2_Msk | ATIM_CCR5_GC5C2_Msk), GroupCH5);
}

/**
  * @brief    Set capture/compare channel 4 register
  * @rmtoll   CCR5        FL_ATIM_WriteCompareCH5
  * @param    TIMx TIM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCompareCH5(ATIM_Type *TIMx, uint32_t compareValue)
{
    MODIFY_REG(TIMx->CCR5, (0xffffU << 0U), (compareValue << 0U));
}

/**
  * @brief    Get capture/compare channel 4 register value
  * @rmtoll   CCR5        FL_ATIM_ReadCompareCH5
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCompareCH5(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR5, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set capture/compare channel 4 register
  * @rmtoll   CCR6        FL_ATIM_WriteCompareCH6
  * @param    TIMx TIM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteCompareCH6(ATIM_Type *TIMx, uint32_t compareValue)
{
    MODIFY_REG(TIMx->CCR6, (0xffffU << 0U), (compareValue << 0U));
}

/**
  * @brief    Get capture/compare channel 4 register value
  * @rmtoll   CCR6        FL_ATIM_ReadCompareCH6
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadCompareCH6(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->CCR6, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set DMA burst length
  * @rmtoll   DCR    DBL    FL_ATIM_SetDMABurstLength
  * @param    TIMx TIM instance
  * @param    length This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_1
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_2
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_3
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_4
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_5
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_6
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_7
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_8
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_9
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_10
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_11
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_12
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_13
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_14
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_15
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_16
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_17
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_18
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetDMABurstLength(ATIM_Type *TIMx, uint32_t length)
{
    MODIFY_REG(TIMx->DCR, ATIM_DCR_DBL_Msk, length);
}

/**
  * @brief    Get DMA burst length
  * @rmtoll   DCR    DBL    FL_ATIM_GetDMABurstLength
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_1
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_2
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_3
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_4
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_5
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_6
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_7
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_8
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_9
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_10
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_11
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_12
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_13
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_14
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_15
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_16
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_17
  *           @arg @ref FL_ATIM_DMA_BURST_LENGTH_18
  */
__STATIC_INLINE uint32_t FL_ATIM_GetDMABurstLength(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DCR, ATIM_DCR_DBL_Msk));
}

/**
  * @brief    Set DMA burst address
  * @rmtoll   DCR    DBA    FL_ATIM_SetDMABurstAddress
  * @param    TIMx TIM instance
  * @param    address This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CR1
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CR2
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_SMCR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_DIER
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_SR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_EGR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCMR1
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCMR2
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCER
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CNT
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_PSC
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_ARR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_RCR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR1
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR2
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR3
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR4
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_BDTR
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetDMABurstAddress(ATIM_Type *TIMx, uint32_t address)
{
    MODIFY_REG(TIMx->DCR, ATIM_DCR_DBA_Msk, address);
}

/**
  * @brief    Get DMA burst address
  * @rmtoll   DCR    DBA    FL_ATIM_GetDMABurstAddress
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CR1
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CR2
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_SMCR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_DIER
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_SR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_EGR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCMR1
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCMR2
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCER
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CNT
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_PSC
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_ARR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_RCR
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR1
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR2
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR3
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_CCR4
  *           @arg @ref FL_ATIM_DMA_BURST_ADDR_BDTR
  */
__STATIC_INLINE uint32_t FL_ATIM_GetDMABurstAddress(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DCR, ATIM_DCR_DBA_Msk));
}

/**
  * @brief    Set DMA burst access Register
  * @rmtoll   DMAR        FL_ATIM_WriteDMAAddress
  * @param    TIMx TIM instance
  * @param    address
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteDMAAddress(ATIM_Type *TIMx, uint32_t address)
{
    MODIFY_REG(TIMx->DMAR, (0xffffffffU << 0U), (address << 0U));
}

/**
  * @brief    Get DMA burst access Register value
  * @rmtoll   DMAR        FL_ATIM_ReadDMAAddress
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadDMAAddress(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->DMAR, (0xffffffffU << 0U)) >> 0U);
}

/**
  * @brief    OCx clear enable
  * @rmtoll   CCMR    OCCE    FL_ATIM_OC_EnableClear
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_EnableClear(ATIM_Type *TIMx, uint32_t channel)
{
    if((channel == FL_ATIM_CHANNEL_1) | (channel == FL_ATIM_CHANNEL_2))
    {
        SET_BIT(TIMx->CCMR1, (ATIM_CCMR_OCCE_Msk << (channel * 8)));
    }
    else if((channel == FL_ATIM_CHANNEL_3) | (channel == FL_ATIM_CHANNEL_4))
    {
        SET_BIT(TIMx->CCMR2, (ATIM_CCMR_OCCE_Msk << ((channel - 2) * 8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR3, (ATIM_CCMR_OCCE_Msk << ((channel - 4) * 8)));
    }
}

/**
  * @brief    Get OCx Clear enable status
  * @rmtoll   CCMR    OCCE    FL_ATIM_OC_IsEnabledClear
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
      *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_IsEnabledClear(ATIM_Type *TIMx, uint32_t channel)
{
    if((channel == FL_ATIM_CHANNEL_1) | (channel == FL_ATIM_CHANNEL_2))
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_OCCE_Msk << (channel * 8))) == (ATIM_CCMR_OCCE_Msk << (channel * 8)));
    }
    else if((channel == FL_ATIM_CHANNEL_3) | (channel == FL_ATIM_CHANNEL_4))
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_OCCE_Msk << ((channel - 2) * 8))) == (ATIM_CCMR_OCCE_Msk << ((channel - 2) * 8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR3, (ATIM_CCMR_OCCE_Msk << ((channel - 4) * 8))) == (ATIM_CCMR_OCCE_Msk << ((channel - 4) * 8)));
    }
}

/**
  * @brief    OCx clear disable
  * @rmtoll   CCMR    OCCE    FL_ATIM_OC_DisableClear
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
      *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_DisableClear(ATIM_Type *TIMx, uint32_t channel)
{
    if((channel == FL_ATIM_CHANNEL_1) | (channel == FL_ATIM_CHANNEL_2))
    {
        CLEAR_BIT(TIMx->CCMR1, (ATIM_CCMR_OCCE_Msk << (channel * 8)));
    }
    else if((channel == FL_ATIM_CHANNEL_3) | (channel == FL_ATIM_CHANNEL_4))
    {
        CLEAR_BIT(TIMx->CCMR2, (ATIM_CCMR_OCCE_Msk << ((channel - 2) * 8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR3, (ATIM_CCMR_OCCE_Msk << ((channel - 4) * 8)));
    }
}

/**
  * @brief    Set OCx mode
  * @rmtoll   CCMR    OCM    FL_ATIM_OC_SetMode
  * @param    TIMx TIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OC_MODE_FROZEN
  *           @arg @ref FL_ATIM_OC_MODE_ACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_INACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_TOGGLE
  *           @arg @ref FL_ATIM_OC_MODE_FORCED_INACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_FORCED_ACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_PWM1
  *           @arg @ref FL_ATIM_OC_MODE_PWM2
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
        *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_SetMode(ATIM_Type *TIMx, uint32_t mode, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1, (ATIM_CCMR_OCM_Msk << (channel * 8)), (mode << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        MODIFY_REG(TIMx->CCMR3, (ATIM_CCMR_OCM_Msk << ((channel - 4) * 8)), (mode << ((channel - 4) * 8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2, (ATIM_CCMR_OCM_Msk << ((channel - 2) * 8)), (mode << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Get OCx mode value
  * @rmtoll   CCMR    OCM    FL_ATIM_OC_GetMode
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
        *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OC_MODE_FROZEN
  *           @arg @ref FL_ATIM_OC_MODE_ACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_INACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_TOGGLE
  *           @arg @ref FL_ATIM_OC_MODE_FORCED_INACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_FORCED_ACTIVE
  *           @arg @ref FL_ATIM_OC_MODE_PWM1
  *           @arg @ref FL_ATIM_OC_MODE_PWM2
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_GetMode(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_OCM_Msk << (channel * 8))));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR3, (ATIM_CCMR_OCM_Msk << ((channel - 4) * 8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_OCM_Msk << ((channel - 2) * 8))));
    }
}

/**
  * @brief    OCx preload enable
  * @rmtoll   CCMR    OCPE    FL_ATIM_OC_EnablePreload
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
        *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_EnablePreload(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1, (ATIM_CCMR_OCPE_Msk << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        SET_BIT(TIMx->CCMR3, (ATIM_CCMR_OCPE_Msk << ((channel - 4) * 8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2, (ATIM_CCMR_OCPE_Msk << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Get OCx preload enable status
  * @rmtoll   CCMR    OCPE    FL_ATIM_OC_IsEnabledPreload
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
          *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_IsEnabledPreload(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_OCPE_Msk << (channel * 8))) == (ATIM_CCMR_OCPE_Msk << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR3, (ATIM_CCMR_OCPE_Msk << ((channel - 4) * 8))) == (ATIM_CCMR_OCPE_Msk << ((channel - 4) * 8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_OCPE_Msk << ((channel - 2) * 8))) == (ATIM_CCMR_OCPE_Msk << ((channel - 2) * 8)));
    }
}

/**
  * @brief    OCx preload disable
  * @rmtoll   CCMR    OCPE    FL_ATIM_OC_DisablePreload
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
          *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_DisablePreload(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1, (ATIM_CCMR_OCPE_Msk << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        CLEAR_BIT(TIMx->CCMR3, (ATIM_CCMR_OCPE_Msk << ((channel - 4) * 8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2, (ATIM_CCMR_OCPE_Msk << ((channel - 2) * 8)));
    }
}

/**
  * @brief    OCx fast enable
  * @rmtoll   CCMR    OCFE    FL_ATIM_OC_EnableFastMode
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
            *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_EnableFastMode(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        SET_BIT(TIMx->CCMR1, (ATIM_CCMR_OCFE_Msk << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        SET_BIT(TIMx->CCMR3, (ATIM_CCMR_OCFE_Msk << ((channel - 4) * 8)));
    }
    else
    {
        SET_BIT(TIMx->CCMR2, (ATIM_CCMR_OCFE_Msk << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Get OCx fast enable status
  * @rmtoll   CCMR    OCFE    FL_ATIM_OC_IsEnabledFastMode
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
            *         @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_IsEnabledFastMode(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_OCFE_Msk << (channel * 8))) == (ATIM_CCMR_OCFE_Msk << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR3, (ATIM_CCMR_OCFE_Msk << ((channel - 4) * 8))) == (ATIM_CCMR_OCFE_Msk << ((channel - 4) * 8)));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_OCFE_Msk << ((channel - 2) * 8))) == (ATIM_CCMR_OCFE_Msk << ((channel - 2) * 8)));
    }
}

/**
  * @brief    OCx fast disable
  * @rmtoll   CCMR    OCFE    FL_ATIM_OC_DisableFastMode
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_DisableFastMode(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        CLEAR_BIT(TIMx->CCMR1, (ATIM_CCMR_OCFE_Msk << (channel * 8)));
    }
    else if(channel > FL_ATIM_CHANNEL_4)
    {
        CLEAR_BIT(TIMx->CCMR3, (ATIM_CCMR_OCFE_Msk << ((channel - 4) * 8)));
    }
    else
    {
        CLEAR_BIT(TIMx->CCMR2, (ATIM_CCMR_OCFE_Msk << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Set ICx filter
  * @rmtoll   CCMR    ICF    FL_ATIM_IC_SetFilter
  * @param    TIMx TIM instance
  * @param    filter This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1_N2
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1_N4
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV2_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV2_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV4_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV4_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV8_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV8_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV16_N5
  *           @arg @ref FL_ATIM_IC_FILTER_DIV16_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV16_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV32_N5
  *           @arg @ref FL_ATIM_IC_FILTER_DIV32_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV32_N8
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_SetFilter(ATIM_Type *TIMx, uint32_t filter, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1, (ATIM_CCMR_ICF_Msk << (channel * 8)), (filter << (channel * 8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2, (ATIM_CCMR_ICF_Msk << ((channel - 2) * 8)), (filter << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Get ICx filter value
  * @rmtoll   CCMR    ICF    FL_ATIM_IC_GetFilter
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1_N2
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1_N4
  *           @arg @ref FL_ATIM_IC_FILTER_DIV1_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV2_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV2_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV4_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV4_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV8_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV8_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV16_N5
  *           @arg @ref FL_ATIM_IC_FILTER_DIV16_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV16_N8
  *           @arg @ref FL_ATIM_IC_FILTER_DIV32_N5
  *           @arg @ref FL_ATIM_IC_FILTER_DIV32_N6
  *           @arg @ref FL_ATIM_IC_FILTER_DIV32_N8
  */
__STATIC_INLINE uint32_t FL_ATIM_IC_GetFilter(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_ICF_Msk << (channel * 8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_ICF_Msk << ((channel - 2) * 8))));
    }
}

/**
  * @brief    Set ICx prescaler
  * @rmtoll   CCMR    ICPSC    FL_ATIM_IC_SetPrescaler
  * @param    TIMx TIM instance
  * @param    psc This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_IC_PSC_DIV1
  *           @arg @ref FL_ATIM_IC_PSC_DIV2
  *           @arg @ref FL_ATIM_IC_PSC_DIV4
  *           @arg @ref FL_ATIM_IC_PSC_DIV8
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_SetPrescaler(ATIM_Type *TIMx, uint32_t psc, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1, (ATIM_CCMR_ICPSC_Msk << (channel * 8)), (psc << (channel * 8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2, (ATIM_CCMR_ICPSC_Msk << ((channel - 2) * 8)), (psc << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Get ICx prescaler value
  * @rmtoll   CCMR    ICPSC    FL_ATIM_IC_GetPrescaler
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_IC_PSC_DIV1
  *           @arg @ref FL_ATIM_IC_PSC_DIV2
  *           @arg @ref FL_ATIM_IC_PSC_DIV4
  *           @arg @ref FL_ATIM_IC_PSC_DIV8
  */
__STATIC_INLINE uint32_t FL_ATIM_IC_GetPrescaler(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_ICPSC_Msk << (channel * 8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_ICPSC_Msk << ((channel - 2) * 8))));
    }
}

/**
  * @brief    CCx channel selection
  * @rmtoll   CCMR    CCS    FL_ATIM_CC_SetChannelMode
  * @param    TIMx TIM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_MODE_OUTPUT
  *           @arg @ref FL_ATIM_CHANNEL_MODE_INPUT_NORMAL
  *           @arg @ref FL_ATIM_CHANNEL_MODE_INPUT_CROSSOVER
  *           @arg @ref FL_ATIM_CHANNEL_MODE_INPUT_TRC
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_CC_SetChannelMode(ATIM_Type *TIMx, uint32_t mode, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        MODIFY_REG(TIMx->CCMR1, (ATIM_CCMR_CCS_Msk << (channel * 8)), (mode << (channel * 8)));
    }
    else
    {
        MODIFY_REG(TIMx->CCMR2, (ATIM_CCMR_CCS_Msk << ((channel - 2) * 8)), (mode << ((channel - 2) * 8)));
    }
}

/**
  * @brief    Get CCx channel
  * @rmtoll   CCMR    CCS    FL_ATIM_CC_GetChannelMode
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_MODE_OUTPUT
  *           @arg @ref FL_ATIM_CHANNEL_MODE_INPUT_NORMAL
  *           @arg @ref FL_ATIM_CHANNEL_MODE_INPUT_CROSSOVER
  *           @arg @ref FL_ATIM_CHANNEL_MODE_INPUT_TRC
  */
__STATIC_INLINE uint32_t FL_ATIM_CC_GetChannelMode(ATIM_Type *TIMx, uint32_t channel)
{
    if(channel < FL_ATIM_CHANNEL_3)
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR1, (ATIM_CCMR_CCS_Msk << (channel * 8))));
    }
    else
    {
        return (uint32_t)(READ_BIT(TIMx->CCMR2, (ATIM_CCMR_CCS_Msk << ((channel - 2) * 8))));
    }
}

/**
  * @brief    Set CCxN polarity
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNP    FL_ATIM_OC_SetReverseChannelPolarity
  * @param    TIMx TIM instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OCN_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_OCN_POLARITY_INVERT
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_SetReverseChannelPolarity(ATIM_Type *TIMx, uint32_t polarity, uint32_t channel)
{
    MODIFY_REG(TIMx->CCER, (ATIM_CCER_CCNP_Msk << (channel * 4)), (polarity << (channel * 4)));
}

/**
  * @brief    Get CCxN polarity
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNP    FL_ATIM_OC_GetReverseChannelPolarity
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OCN_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_OCN_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_GetReverseChannelPolarity(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCNP_Msk << (channel * 4))));
}

/**
  * @brief    CCxN enable
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNE    FL_ATIM_OC_EnableReverseChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_EnableReverseChannel(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->CCER, (ATIM_CCER_CCNE_Msk << (channel * 4)));
}

/**
  * @brief    Get CCxN enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNE    FL_ATIM_OC_IsEnabledReverseChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_IsEnabledReverseChannel(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCNE_Msk << (channel * 4))) == (ATIM_CCER_CCNE_Msk << (channel * 4)));
}

/**
  * @brief    CCxN disable
  * @note     仅仅高级定时器支持
  * @rmtoll   CCER    CCNE    FL_ATIM_OC_DisableReverseChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_DisableReverseChannel(ATIM_Type *TIMx, uint32_t channel)
{
    CLEAR_BIT(TIMx->CCER, (ATIM_CCER_CCNE_Msk << (channel * 4)));
}

/**
  * @brief    Set CCOx Polarity
  * @rmtoll   CCER    CCOP    FL_ATIM_OC_SetChannelPolarity
  * @param    TIMx TIM instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OC_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_OC_POLARITY_INVERT
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_SetChannelPolarity(ATIM_Type *TIMx, uint32_t polarity, uint32_t channel)
{
    MODIFY_REG(TIMx->CCER, (ATIM_CCER_CCOP_Msk << (channel * 4)), (polarity << (channel * 4)));
}

/**
  * @brief    Get CCOx Polarity
  * @rmtoll   CCER    CCOP    FL_ATIM_OC_GetChannelPolarity
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OC_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_OC_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_GetChannelPolarity(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCOP_Msk << (channel * 4))));
}

/**
  * @brief    Set CCIx Polarity
  * @rmtoll   CCER    CCIP    FL_ATIM_IC_SetChannelPolarity
  * @param    TIMx TIM instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_IC_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_IC_POLARITY_INVERT
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_SetChannelPolarity(ATIM_Type *TIMx, uint32_t polarity, uint32_t channel)
{
    MODIFY_REG(TIMx->CCER, (ATIM_CCER_CCIP_Msk << (channel * 4)), (polarity << (channel * 4)));
}

/**
  * @brief    Get CCIx Polarity
  * @rmtoll   CCER    CCIP    FL_ATIM_IC_GetChannelPolarity
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_IC_POLARITY_NORMAL
  *           @arg @ref FL_ATIM_IC_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_ATIM_IC_GetChannelPolarity(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCIP_Msk << (channel * 4))));
}

/**
  * @brief    CCOx Enable
  * @rmtoll   CCER    CCOE    FL_ATIM_OC_EnableChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_EnableChannel(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->CCER, (ATIM_CCER_CCOE_Msk << (channel * 4)));
}

/**
  * @brief    Get CCOx enable status
  * @rmtoll   CCER    CCOE    FL_ATIM_OC_IsEnabledChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_OC_IsEnabledChannel(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCOE_Msk << (channel * 4))) == (ATIM_CCER_CCOE_Msk << (channel * 4)));
}

/**
  * @brief    CCOx disable
  * @rmtoll   CCER    CCOE    FL_ATIM_OC_DisableChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
    *           @arg @ref FL_ATIM_CHANNEL_5
  *           @arg @ref FL_ATIM_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_OC_DisableChannel(ATIM_Type *TIMx, uint32_t channel)
{
    CLEAR_BIT(TIMx->CCER, (ATIM_CCER_CCOE_Msk << (channel * 4)));
}

/**
  * @brief    CCIx Enable
  * @rmtoll   CCER    CCIE    FL_ATIM_IC_EnableChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_EnableChannel(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->CCER, (ATIM_CCER_CCIE_Msk << (channel * 4)));
}

/**
  * @brief    Get CCIx enable status
  * @rmtoll   CCER    CCIE    FL_ATIM_IC_IsEnabledChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IC_IsEnabledChannel(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->CCER, (ATIM_CCER_CCIE_Msk << (channel * 4))) == (ATIM_CCER_CCIE_Msk << (channel * 4)));
}

/**
  * @brief    CCIx disable
  * @rmtoll   CCER    CCIE    FL_ATIM_IC_DisableChannel
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_CHANNEL_1
  *           @arg @ref FL_ATIM_CHANNEL_2
  *           @arg @ref FL_ATIM_CHANNEL_3
  *           @arg @ref FL_ATIM_CHANNEL_4
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_IC_DisableChannel(ATIM_Type *TIMx, uint32_t channel)
{
    CLEAR_BIT(TIMx->CCER, (ATIM_CCER_CCIE_Msk << (channel * 4)));
}

/**
  * @brief    Set repeat count value
  * @note     仅仅高级定时器支持
  * @rmtoll   RCR        FL_ATIM_WriteRepetitionCounter
  * @param    TIMx TIM instance
  * @param    repeatCounter
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteRepetitionCounter(ATIM_Type *TIMx, uint32_t repeatCounter)
{
    MODIFY_REG(TIMx->RCR, (0xffU << 0U), (repeatCounter << 0U));
}

/**
  * @brief    Get repeat count value
  * @note     仅仅高级定时器支持
  * @rmtoll   RCR        FL_ATIM_ReadRepetitionCounter
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadRepetitionCounter(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->RCR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Master output enable
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    MOE    FL_ATIM_EnableALLOutput
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableALLOutput(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->BDTR, ATIM_BDTR_MOE_Msk);
}

/**
  * @brief    Get master output enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    MOE    FL_ATIM_IsEnabledALLOutput
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledALLOutput(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_MOE_Msk) == ATIM_BDTR_MOE_Msk);
}

/**
  * @brief    Master output disable
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    MOE    FL_ATIM_DisableALLOutput
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableALLOutput(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->BDTR, ATIM_BDTR_MOE_Msk);
}

/**
  * @brief    Automatic output enable
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    AOE    FL_ATIM_EnableAutomaticOutput
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableAutomaticOutput(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->BDTR, ATIM_BDTR_AOE_Msk);
}

/**
  * @brief    Get automatic output enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    AOE    FL_ATIM_IsEnabledAutomaticOutput
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledAutomaticOutput(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_AOE_Msk) == ATIM_BDTR_AOE_Msk);
}

/**
  * @brief    Automatic output disable
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    AOE    FL_ATIM_DisableAutomaticOutput
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableAutomaticOutput(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->BDTR, ATIM_BDTR_AOE_Msk);
}

/**
  * @brief    Set break polarity
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKP    FL_ATIM_SetBreakPolarity
  * @param    TIMx TIM instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAK_POLARITY_LOW
  *           @arg @ref FL_ATIM_BREAK_POLARITY_HIGH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetBreakPolarity(ATIM_Type *TIMx,  uint32_t channel, uint32_t polarity)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_BKP_Msk << (channel * 12), polarity << (channel * 12));
}

/**
  * @brief    Get break polarity
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKP    FL_ATIM_GetBreakPolarity
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_BREAK_POLARITY_LOW
  *           @arg @ref FL_ATIM_BREAK_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t FL_ATIM_GetBreakPolarity(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_BKP_Msk << (channel * 12)));
}

/**
  * @brief    Break enable
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKE    FL_ATIM_EnableBreak
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableBreak(ATIM_Type *TIMx, uint32_t channel)
{
    SET_BIT(TIMx->BDTR, ATIM_BDTR_BKE_Msk << (channel * 12));
}

/**
  * @brief    Get break enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKE    FL_ATIM_IsEnabledBreak
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledBreak(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_BKE_Msk << (channel * 12)) == ATIM_BDTR_BKE_Msk << (channel * 12));
}

/**
  * @brief    Break disable
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKE    FL_ATIM_DisableBreak
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableBreak(ATIM_Type *TIMx, uint32_t channel)
{
    CLEAR_BIT(TIMx->BDTR, ATIM_BDTR_BKE_Msk << (channel * 12));
}

/**
  * @brief    Off-State Select in Run mode
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSR    FL_ATIM_SetOffStateRun
  * @param    TIMx TIM instance
  * @param    state This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OSSR_DISABLE
  *           @arg @ref FL_ATIM_OSSR_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetOffStateRun(ATIM_Type *TIMx, uint32_t state)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_OSSR_Msk, state);
}

/**
  * @brief    Get Off-State Select in Run mode
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSR    FL_ATIM_GetOffStateRun
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OSSR_DISABLE
  *           @arg @ref FL_ATIM_OSSR_ENABLE
  */
__STATIC_INLINE uint32_t FL_ATIM_GetOffStateRun(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_OSSR_Msk));
}

/**
  * @brief    Off-State Select in IDLE mode
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSI    FL_ATIM_SetOffStateIdle
  * @param    TIMx TIM instance
  * @param    state This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OSSI_DISABLE
  *           @arg @ref FL_ATIM_OSSI_ENABLE
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetOffStateIdle(ATIM_Type *TIMx, uint32_t state)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_OSSI_Msk, state);
}

/**
  * @brief     Set Off-State Select in IDLE mode
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    OSSI    FL_ATIM_GetOffStateIdle
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OSSI_DISABLE
  *           @arg @ref FL_ATIM_OSSI_ENABLE
  */
__STATIC_INLINE uint32_t FL_ATIM_GetOffStateIdle(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_OSSI_Msk));
}

/**
  * @brief    Set register write LOCK level
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    LOCK    FL_ATIM_SetLockLevel
  * @param    TIMx TIM instance
  * @param    lockLevel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_LOCK_LEVEL_OFF
  *           @arg @ref FL_ATIM_LOCK_LEVEL_1
  *           @arg @ref FL_ATIM_LOCK_LEVEL_2
  *           @arg @ref FL_ATIM_LOCK_LEVEL_3
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetLockLevel(ATIM_Type *TIMx, uint32_t lockLevel)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_LOCK_Msk, lockLevel);
}

/**
  * @brief    Get register write LOCK status
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    LOCK    FL_ATIM_GetLockLevel
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_LOCK_LEVEL_OFF
  *           @arg @ref FL_ATIM_LOCK_LEVEL_1
  *           @arg @ref FL_ATIM_LOCK_LEVEL_2
  *           @arg @ref FL_ATIM_LOCK_LEVEL_3
  */
__STATIC_INLINE uint32_t FL_ATIM_GetLockLevel(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_LOCK_Msk));
}

/**
  * @brief    Set dead time generation length
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    DTG    FL_ATIM_WriteDeadTime
  * @param    TIMx TIM instance
  * @param    deadTime
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_WriteDeadTime(ATIM_Type *TIMx, uint32_t deadTime)
{
    MODIFY_REG(TIMx->BDTR, (0xffU << 0U), (deadTime << 0U));
}

/**
  * @brief    Get dead time generation length
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    DTG    FL_ATIM_ReadDeadTime
  * @param    TIMx TIM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_ATIM_ReadDeadTime(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set brake signal filter clock and length selection
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKF    FL_ATIM_SetBreakFilter
  * @param    TIMx TIM instance
  * @param    filter This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1_N2
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1_N4
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV2_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV2_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV4_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV4_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV8_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV8_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV16_N5
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV16_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV16_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV32_N5
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV32_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV32_N8
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetBreakFilter(ATIM_Type *TIMx, uint32_t channel, uint32_t filter)
{
    MODIFY_REG(TIMx->BDTR, ATIM_BDTR_BKF_Msk << (channel * 4), filter << (channel * 4));
}

/**
  * @brief    Get brake signal filter clock and length selection
  * @note     仅仅高级定时器支持
  * @rmtoll   BDTR    BKF    FL_ATIM_GetBreakFilter
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BREAKCHANNEL_0
  *           @arg @ref FL_ATIM_BREAKCHANNEL_1
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1_N2
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1_N4
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV1_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV2_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV2_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV4_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV4_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV8_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV8_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV16_N5
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV16_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV16_N8
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV32_N5
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV32_N6
  *           @arg @ref FL_ATIM_BREAK_FILTER_DIV32_N8
  */
__STATIC_INLINE uint32_t FL_ATIM_GetBreakFilter(ATIM_Type *TIMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(TIMx->BDTR, ATIM_BDTR_BKF_Msk << (channel * 4)));
}

/**
  * @brief    Set index positioning
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IPOS    FL_ATIM_SetIndexPositionning
  * @param    TIMx TIM instance
  * @param    IndexPositionning This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_INDEX_POSITION_DOWN_DOWN
  *           @arg @ref FL_ATIM_INDEX_POSITION_DOWN_UP
  *           @arg @ref FL_ATIM_INDEX_POSITION_UP_DOWN
  *           @arg @ref FL_ATIM_INDEX_POSITION_UP_UP
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetIndexPositionning(ATIM_Type *TIMx, uint32_t IndexPositionning)
{
    MODIFY_REG(TIMx->ECR, ATIM_ECR_IPOS_Msk, IndexPositionning);
}

/**
  * @brief    Get actual index positioning
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IPOS    FL_ATIM_GetIndexPositionning
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_INDEX_POSITION_DOWN_DOWN
  *           @arg @ref FL_ATIM_INDEX_POSITION_DOWN_UP
  *           @arg @ref FL_ATIM_INDEX_POSITION_UP_DOWN
  *           @arg @ref FL_ATIM_INDEX_POSITION_UP_UP
  */
__STATIC_INLINE uint32_t FL_ATIM_GetIndexPositionning(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ECR, ATIM_ECR_IPOS_Msk));
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    FIDX    FL_ATIM_SetIDXMode
  * @param    TIMx TIM instance
  * @param    IDXmode This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_INDEX_FIRST_ONLY
  *           @arg @ref FL_ATIM_INDEX_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetIDXMode(ATIM_Type *TIMx, uint32_t IDXmode)
{
    MODIFY_REG(TIMx->ECR, ATIM_ECR_FIDX_Msk, IDXmode);
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    FIDX    FL_ATIM_GetIDXMode
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_INDEX_FIRST_ONLY
  *           @arg @ref FL_ATIM_INDEX_ALL
  */
__STATIC_INLINE uint32_t FL_ATIM_GetIDXMode(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ECR, ATIM_ECR_FIDX_Msk));
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IDIR    FL_ATIM_SetIDXDirection
  * @param    TIMx TIM instance
  * @param    IDXdirection This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_INDEX_UP_DOWN
  *           @arg @ref FL_ATIM_INDEX_UP
  *           @arg @ref FL_ATIM_INDEX_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetIDXDirection(ATIM_Type *TIMx, uint32_t IDXdirection)
{
    MODIFY_REG(TIMx->ECR, ATIM_ECR_IDIR_Msk, IDXdirection);
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IDIR    FL_ATIM_GetIDXDirection
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_INDEX_UP_DOWN
  *           @arg @ref FL_ATIM_INDEX_UP
  *           @arg @ref FL_ATIM_INDEX_DOWN
  */
__STATIC_INLINE uint32_t FL_ATIM_GetIDXDirection(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ECR, ATIM_ECR_IDIR_Msk));
}

/**
  * @brief    Break enable
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IE    FL_ATIM_EnableIDX
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_EnableIDX(ATIM_Type *TIMx)
{
    SET_BIT(TIMx->ECR, ATIM_ECR_IE_Msk);
}

/**
  * @brief    Get break enable status
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IE    FL_ATIM_IsEnabledIDX
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_ATIM_IsEnabledIDX(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->ECR, ATIM_ECR_IE_Msk) == ATIM_ECR_IE_Msk);
}

/**
  * @brief    Break disable
  * @note     仅仅高级定时器支持
  * @rmtoll   ECR    IE    FL_ATIM_DisableIDX
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_DisableIDX(ATIM_Type *TIMx)
{
    CLEAR_BIT(TIMx->ECR, ATIM_ECR_IE_Msk);
}

/**
  * @brief
  * @rmtoll   TISEL    TISEL    FL_GPTIM_SetTISource
  * @param    TIMx TIM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TIM_TI_IN0
  *           @arg @ref FL_ATIM_TIM_TI_IN1
  *           @arg @ref FL_ATIM_TIM_TI_IN2
  *           @arg @ref FL_ATIM_TIM_TI_IN3
  *           @arg @ref FL_ATIM_TIM_TI_IN4
  *           @arg @ref FL_ATIM_TIM_TI_IN5
  *           @arg @ref FL_ATIM_TIM_TI_IN6
  *           @arg @ref FL_ATIM_TIM_TI_IN7
  *           @arg @ref FL_ATIM_TIM_TI_IN8
  *           @arg @ref FL_ATIM_TIM_TI_IN9
  *           @arg @ref FL_ATIM_TIM_TI_IN10
  *           @arg @ref FL_ATIM_TIM_TI_IN11
  *           @arg @ref FL_ATIM_TIM_TI_IN12
  *           @arg @ref FL_ATIM_TIM_TI_IN13
  *           @arg @ref FL_ATIM_TIM_TI_IN14
  *           @arg @ref FL_ATIM_TIM_TI_IN15
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TI0
  *           @arg @ref FL_ATIM_TI1
  *           @arg @ref FL_ATIM_TI2
  *           @arg @ref FL_ATIM_TI3
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetTISource(ATIM_Type *TIMx, uint32_t source, uint32_t channel)
{
    switch(channel)
    {
        case FL_ATIM_TI0:
            MODIFY_REG(TIMx->TISEL, (0xFU << 0U), (source));
            break;
        case FL_ATIM_TI1:
            MODIFY_REG(TIMx->TISEL, (0xFU << 8U), (source << 8U));
            break;
        case FL_ATIM_TI2:
            MODIFY_REG(TIMx->TISEL, (0xFU << 16U), (source << 16U));
            break;
        case FL_ATIM_TI3:
            MODIFY_REG(TIMx->TISEL, (0xFU << 24U), (source << 24U));
            break;
    }
}

/**
  * @brief
  * @rmtoll   TISEL    TISEL    FL_GPTIM_GetTISource
  * @param    TIMx TIM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TI0
  *           @arg @ref FL_ATIM_TI1
  *           @arg @ref FL_ATIM_TI2
  *           @arg @ref FL_ATIM_TI3
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_TIM_TI_IN0
  *           @arg @ref FL_ATIM_TIM_TI_IN1
  *           @arg @ref FL_ATIM_TIM_TI_IN2
  *           @arg @ref FL_ATIM_TIM_TI_IN3
  *           @arg @ref FL_ATIM_TIM_TI_IN4
  *           @arg @ref FL_ATIM_TIM_TI_IN5
  *           @arg @ref FL_ATIM_TIM_TI_IN6
  *           @arg @ref FL_ATIM_TIM_TI_IN7
  *           @arg @ref FL_ATIM_TIM_TI_IN8
  *           @arg @ref FL_ATIM_TIM_TI_IN9
  *           @arg @ref FL_ATIM_TIM_TI_IN10
  *           @arg @ref FL_ATIM_TIM_TI_IN11
  *           @arg @ref FL_ATIM_TIM_TI_IN12
  *           @arg @ref FL_ATIM_TIM_TI_IN13
  *           @arg @ref FL_ATIM_TIM_TI_IN14
  *           @arg @ref FL_ATIM_TIM_TI_IN15
  */
__STATIC_INLINE uint32_t FL_ATIM_GetTISource(ATIM_Type *TIMx, uint32_t channel)
{
    switch(channel)
    {
        case FL_ATIM_TI0:
            return (uint32_t)(READ_BIT(TIMx->TISEL, (0xFU << 0U)) >> 0U);
        case FL_ATIM_TI1:
            return (uint32_t)(READ_BIT(TIMx->TISEL, (0xFU << 8U)) >> 8U);
        case FL_ATIM_TI2:
            return (uint32_t)(READ_BIT(TIMx->TISEL, (0xFU << 16U)) >> 16U);
        case FL_ATIM_TI3:
            return (uint32_t)(READ_BIT(TIMx->TISEL, (0xFU << 24U)) >> 24U);
        default:
            return 0;
    }
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   AFR    ETRSEL    FL_ATIM_SetETRSource
  * @param    TIMx TIM instance
  * @param    ETRsource This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_TIM_ETR_IN0
  *           @arg @ref FL_ATIM_TIM_ETR_IN1
  *           @arg @ref FL_ATIM_TIM_ETR_IN2
  *           @arg @ref FL_ATIM_TIM_ETR_IN3
  *           @arg @ref FL_ATIM_TIM_ETR_IN4
  *           @arg @ref FL_ATIM_TIM_ETR_IN5
  *           @arg @ref FL_ATIM_TIM_ETR_IN6
  *           @arg @ref FL_ATIM_TIM_ETR_IN7
  *           @arg @ref FL_ATIM_TIM_ETR_IN8
  *           @arg @ref FL_ATIM_TIM_ETR_IN9
  *           @arg @ref FL_ATIM_TIM_ETR_IN10
  *           @arg @ref FL_ATIM_TIM_ETR_IN11
  *           @arg @ref FL_ATIM_TIM_ETR_IN12
  *           @arg @ref FL_ATIM_TIM_ETR_IN13
  *           @arg @ref FL_ATIM_TIM_ETR_IN14
  *           @arg @ref FL_ATIM_TIM_ETR_IN15
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetETRSource(ATIM_Type *TIMx, uint32_t ETRsource)
{
    MODIFY_REG(TIMx->AFR, ATIM_AFR_ETRSEL_Msk, ETRsource);
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   AFR    ETRSEL    FL_ATIM_GetETRSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_TIM_ETR_IN0
  *           @arg @ref FL_ATIM_TIM_ETR_IN1
  *           @arg @ref FL_ATIM_TIM_ETR_IN2
  *           @arg @ref FL_ATIM_TIM_ETR_IN3
  *           @arg @ref FL_ATIM_TIM_ETR_IN4
  *           @arg @ref FL_ATIM_TIM_ETR_IN5
  *           @arg @ref FL_ATIM_TIM_ETR_IN6
  *           @arg @ref FL_ATIM_TIM_ETR_IN7
  *           @arg @ref FL_ATIM_TIM_ETR_IN8
  *           @arg @ref FL_ATIM_TIM_ETR_IN9
  *           @arg @ref FL_ATIM_TIM_ETR_IN10
  *           @arg @ref FL_ATIM_TIM_ETR_IN11
  *           @arg @ref FL_ATIM_TIM_ETR_IN12
  *           @arg @ref FL_ATIM_TIM_ETR_IN13
  *           @arg @ref FL_ATIM_TIM_ETR_IN14
  *           @arg @ref FL_ATIM_TIM_ETR_IN15
  */
__STATIC_INLINE uint32_t FL_ATIM_GetETRSource(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->AFR, ATIM_AFR_ETRSEL_Msk));
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   AFR    OCCLR_SEL    FL_ATIM_SetOCRefClearSource
  * @param    TIMx TIM instance
  * @param    OCrefsource This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_OCREF_CLRSOURCE_COMP1
  *           @arg @ref FL_ATIM_OCREF_CLRSOURCE_COMP2
  *           @arg @ref FL_ATIM_OCREF_CLRSOURCE_COMP3
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetOCRefClearSource(ATIM_Type *TIMx, uint32_t OCrefsource)
{
    MODIFY_REG(TIMx->AFR, ATIM_AFR_OCCLR_SEL_Msk, OCrefsource);
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   AFR    OCCLR_SEL    FL_ATIM_GetOCRefClearSource
  * @param    TIMx TIM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_ATIM_OCREF_CLRSOURCE_COMP1
  *           @arg @ref FL_ATIM_OCREF_CLRSOURCE_COMP2
  *           @arg @ref FL_ATIM_OCREF_CLRSOURCE_COMP3
  */
__STATIC_INLINE uint32_t FL_ATIM_GetOCRefClearSource(ATIM_Type *TIMx)
{
    return (uint32_t)(READ_BIT(TIMx->AFR, ATIM_AFR_OCCLR_SEL_Msk));
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   AFR    BKIN1E    FL_ATIM_SetBreakInput
  * @param    TIMx TIM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BKIN_SOURCE_GPIO1
  *           @arg @ref FL_ATIM_BKIN_SOURCE_GPIO2
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP1
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP2
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP3
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP4
  *           @arg @ref FL_ATIM_BKIN_SOURCE_HFDET
  *           @arg @ref FL_ATIM_BKIN_SOURCE_SVD
  *           @arg @ref FL_ATIM_BKIN_SOURCE_LOCKUP
  *           @arg @ref FL_ATIM_BKIN_SOURCE_RAMPARITY
  * @retval   None
  */
__STATIC_INLINE void FL_ATIM_SetBreakInput(ATIM_Type *TIMx, uint32_t BRKsource)
{
    MODIFY_REG(TIMx->AFR, ATIM_AFR_BKIN_E_Msk | ATIM_AFR_BKCMP_E_Msk | ATIM_AFR_BKSYS_E_Msk, BRKsource);
}

/**
  * @brief
  * @note     仅仅高级定时器支持
  * @rmtoll   AFR    BKSYS3E    FL_ATIM_GetBreakInput
  * @param    TIMx TIM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_ATIM_BKIN_SOURCE_GPIO1
  *           @arg @ref FL_ATIM_BKIN_SOURCE_GPIO2
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP1
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP2
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP3
  *           @arg @ref FL_ATIM_BKIN_SOURCE_COMP4
  *           @arg @ref FL_ATIM_BKIN_SOURCE_HFDET
  *           @arg @ref FL_ATIM_BKIN_SOURCE_SVD
  *           @arg @ref FL_ATIM_BKIN_SOURCE_LOCKUP
  *           @arg @ref FL_ATIM_BKIN_SOURCE_RAMPARITY
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_ATIM_GetBreakInput(ATIM_Type *TIMx, uint32_t BRKsource)
{
    return (uint32_t)(READ_BIT(TIMx->AFR, 0xfff << 0));
}

/**
  * @}
  */

/** @defgroup ATIM_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_ATIM_Init(ATIM_Type *TIMx, FL_ATIM_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_ATIM_SlaveMode_Init(ATIM_Type *TIMx, FL_ATIM_SlaveInitTypeDef *TIM_InitStruct);
FL_ErrorStatus  FL_ATIM_IC_Init(ATIM_Type *TIMx, uint32_t channel, FL_ATIM_IC_InitTypeDef *IC_InitStruct);
FL_ErrorStatus  FL_ATIM_ETR_Init(ATIM_Type *TIMx, FL_ATIM_ETR_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_ATIM_OC_Init(ATIM_Type *TIMx, uint32_t channel, FL_ATIM_OC_InitTypeDef *TIM_OC_InitStruct);
FL_ErrorStatus FL_ATIM_BDTR_Init(ATIM_Type *TIMx, uint32_t channel, FL_ATIM_BDTR_InitTypeDef *TIM_BDTR_InitStruct);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_ATIM_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-18*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
