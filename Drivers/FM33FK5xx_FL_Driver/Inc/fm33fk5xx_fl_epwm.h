/**
  *******************************************************************************************************
  * @file    fm33Fk5xx_fl_epwm.h
  * @author  FMSH Application Team
  * @brief   Head file of EPWM FL Module
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
#ifndef __FM33FK5XX_FL_EPWM_H
#define __FM33FK5XX_FL_EPWM_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup EPWM_FL_ES_INIT EPWM Exported Init structures
  * @{
  */

/**
  * @brief FL EPWM Init Sturcture definition
  */
typedef struct
{
    /*! 时钟源 */
    uint32_t clockSrc;
    /*! 预分频系数 */
    uint32_t prescaler;
    /*! 计数模式 */
    uint32_t counterMode;
    /*! 自动重装载值 */
    uint32_t period;
    /*! 相位值 */
    uint32_t phase;
    /*! PRD预装载使能 */
    uint32_t periodAutoReload;
    /*! 相位装载使能 */
    uint32_t phaseLoad;
    /*! DBG模式 */
    uint32_t DBGMode;
    /*! 初始计数方向 */
    uint32_t startCounterDir;
} FL_EPWM_InitTypeDef;

/**
  * @brief  TIM Output Compare configuration structure definition.
  */
typedef struct
{
    /*! 通道预装载使能 */
    uint32_t OCautoReload;
    /*! 通道A影子寄存器生效时刻 */
    uint32_t OCLoadtrigger;
    /*! 向下计数CNT=CMPB时的输出动作 */
    uint32_t OCMode_CNTEqualCMPB_DirDown;
    /*! 向上计数CNT=CMPB时的输出动作 */
    uint32_t OCMode_CNTEqualCMPB_DirUp;
    /*! 向下计数CNT=CMPA时的输出动作 */
    uint32_t OCMode_CNTEqualCMPA_DirDown;
    /*! 向上计数CNT=CMPA时的输出动作 */
    uint32_t OCMode_CNTEqualCMPA_DirUp;
    /*! CNT=PRD时的输出动作 */
    uint32_t OCMode_CNTEqualPRD;
    /*! CNT=ZRO时的输出动作 */
    uint32_t OCMode_CNTEqualZRO;

} FL_EPWM_OC_InitTypeDef;
/**
  * @brief  TIM Compare configuration structure definition.
  */
typedef struct
{
    /*! CMPA预装载使能 */
    uint32_t CMPAutoReload;
    /*! CMPA影子寄存器生效时刻 */
    uint32_t CMPLoadTrigger;

} FL_EPWM_CMP_InitTypeDef;

/**
  * @brief  DT (Dead Time) structure definition
  */
typedef struct
{
    /*! 下降沿延迟信号输入源 */
    uint32_t FEDSrc;
    /*! 上升沿延迟信号输入源 */
    uint32_t REDSrc;
    /*! EPWM输出极性选择 */
    uint32_t ChannelOutputPolar;
    /*! EPWMB bypass使能 */
    uint32_t ChannelBypass;
    /*! 上升沿延迟时间 */
    uint32_t REDDelayTime;
    /*! 下降沿延迟时间 */
    uint32_t FEDDelayTime;
} FL_EPWM_DT_InitTypeDef;

/**
  * @brief  CHP (Chopper) structure definition
  */
typedef struct
{
    /*! Chopper高电平宽度 */
    uint32_t chopperHighWidth;
    /*! Chopper低电平宽度 */
    uint32_t chopperLowWidth;
    /*! One-Shot 脉冲宽度 */
    uint32_t oneShotPulseWidth;
    /*! One-Shot 脉冲使能 */
    uint32_t oneShotMode;
    /*! channelChopper使能 */
    uint32_t channelChopper;
} FL_EPWM_CHP_InitTypeDef;

/**
  * @brief  BRK (Break) structure definition
  */
typedef struct
{
    /*! DCBEVT事件有效配置 */
    uint32_t DCBEVTActive;
    /*! DCAEVT事件有效配置 */
    uint32_t DCAEVTActive;
    /*! DCBL输入源 */
    uint32_t DCBLInputSrc;
    /*! DCBH输入源 */
    uint32_t DCBHInputSrc;
    /*! DCAL输入源 */
    uint32_t DCALInputSrc;
    /*! DCAH输入源 */
    uint32_t DCAHInputSrc;
} FL_EPWM_DCEvent_InitTypeDef;

/**
  * @brief  SOC (Break) structure definition
  */
typedef struct
{
    /*! Pulse CNT中断信号源选择 */
    uint32_t pulseCNTInterruptSrc;
    /*! SOCB信号源选择 */
    uint32_t SOCBInputSrc;
    /*! SOCA信号源选择 */
    uint32_t SOCAInputSrc;
    /*! SOCB事件使能 */
    uint32_t SOCBEventState;
    /*! SOCA事件使能 */
    uint32_t SOCAEventState;
    /*! Pulse CNT事件预分频 */
    uint32_t pulseCNTEventPsc;
    /*! SOCB事件预分频 */
    uint32_t SOCBEventPsc;
    /*! SOCA事件预分频 */
    uint32_t SOCAEventPsc;
} FL_EPWM_SOC_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup EPWM_FL_Exported_Constants EPWM Exported Constants
  * @{
  */

#define    EPWM_PRD_PRD_Pos                                       (0U)
#define    EPWM_PRD_PRD_Msk                                       (0xffffU << EPWM_PRD_PRD_Pos)
#define    EPWM_PRD_PRD                                           EPWM_PRD_PRD_Msk

#define    EPWM_PHSR_PHS_Pos                                      (0U)
#define    EPWM_PHSR_PHS_Msk                                      (0xffffU << EPWM_PHSR_PHS_Pos)
#define    EPWM_PHSR_PHS                                          EPWM_PHSR_PHS_Msk

#define    EPWM_PSC_PSC_Pos                                       (0U)
#define    EPWM_PSC_PSC_Msk                                       (0xffffU << EPWM_PSC_PSC_Pos)
#define    EPWM_PSC_PSC                                           EPWM_PSC_PSC_Msk

#define    EPWM_CNTR_CNT_Pos                                      (0U)
#define    EPWM_CNTR_CNT_Msk                                      (0xffffU << EPWM_CNTR_CNT_Pos)
#define    EPWM_CNTR_CNT                                          EPWM_CNTR_CNT_Msk

#define    EPWM_TBCR_DBGMODE_Pos                                  (8U)
#define    EPWM_TBCR_DBGMODE_Msk                                  (0x3U << EPWM_TBCR_DBGMODE_Pos)
#define    EPWM_TBCR_DBGMODE                                      EPWM_TBCR_DBGMODE_Msk

#define    EPWM_TBCR_PHSDIR_Pos                                   (7U)
#define    EPWM_TBCR_PHSDIR_Msk                                   (0x1U << EPWM_TBCR_PHSDIR_Pos)
#define    EPWM_TBCR_PHSDIR                                       EPWM_TBCR_PHSDIR_Msk

#define    EPWM_TBCR_OSTSYNCO_Pos                                 (5U)
#define    EPWM_TBCR_OSTSYNCO_Msk                                 (0x1U << EPWM_TBCR_OSTSYNCO_Pos)
#define    EPWM_TBCR_OSTSYNCO                                     EPWM_TBCR_OSTSYNCO_Msk

#define    EPWM_TBCR_OSTSYNCOEN_Pos                               (4U)
#define    EPWM_TBCR_OSTSYNCOEN_Msk                               (0x1U << EPWM_TBCR_OSTSYNCOEN_Pos)
#define    EPWM_TBCR_OSTSYNCOEN                                   EPWM_TBCR_OSTSYNCOEN_Msk

#define    EPWM_TBCR_PRDSHEN_Pos                                  (3U)
#define    EPWM_TBCR_PRDSHEN_Msk                                  (0x1U << EPWM_TBCR_PRDSHEN_Pos)
#define    EPWM_TBCR_PRDSHEN                                      EPWM_TBCR_PRDSHEN_Msk

#define    EPWM_TBCR_PHSEN_Pos                                    (2U)
#define    EPWM_TBCR_PHSEN_Msk                                    (0x1U << EPWM_TBCR_PHSEN_Pos)
#define    EPWM_TBCR_PHSEN                                        EPWM_TBCR_PHSEN_Msk

#define    EPWM_TBCR_CNTMODE_Pos                                  (0U)
#define    EPWM_TBCR_CNTMODE_Msk                                  (0x3U << EPWM_TBCR_CNTMODE_Pos)
#define    EPWM_TBCR_CNTMODE                                      EPWM_TBCR_CNTMODE_Msk

#define    EPWM_TBSR_CNTMAX_Pos                                   (2U)
#define    EPWM_TBSR_CNTMAX_Msk                                   (0x1U << EPWM_TBSR_CNTMAX_Pos)
#define    EPWM_TBSR_CNTMAX                                       EPWM_TBSR_CNTMAX_Msk

#define    EPWM_TBSR_SYNCIF_Pos                                   (1U)
#define    EPWM_TBSR_SYNCIF_Msk                                   (0x1U << EPWM_TBSR_SYNCIF_Pos)
#define    EPWM_TBSR_SYNCIF                                       EPWM_TBSR_SYNCIF_Msk

#define    EPWM_TBSR_CNTDIR_Pos                                   (0U)
#define    EPWM_TBSR_CNTDIR_Msk                                   (0x1U << EPWM_TBSR_CNTDIR_Pos)
#define    EPWM_TBSR_CNTDIR                                       EPWM_TBSR_CNTDIR_Msk

#define    EPWM_SYNC_SWSYNCOEN_Pos                                (7U)
#define    EPWM_SYNC_SWSYNCOEN_Msk                                (0x1ffU << EPWM_SYNC_SWSYNCOEN_Pos)
#define    EPWM_SYNC_SWSYNCOEN                                    EPWM_SYNC_SWSYNCOEN_Msk

#define    EPWM_SYNC_SYNCINSEL_Pos                                (0U)
#define    EPWM_SYNC_SYNCINSEL_Msk                                (0xfU << EPWM_SYNC_SYNCINSEL_Pos)
#define    EPWM_SYNC_SYNCINSEL                                    EPWM_SYNC_SYNCINSEL_Msk

#define    EPWM_SWACT_SWSYNC_Pos                                  (0U)
#define    EPWM_SWACT_SWSYNC_Msk                                  (0x1U << EPWM_SWACT_SWSYNC_Pos)
#define    EPWM_SWACT_SWSYNC                                      EPWM_SWACT_SWSYNC_Msk

#define    EPWM_CMPA_CMPA_Pos                                     (0U)
#define    EPWM_CMPA_CMPA_Msk                                     (0xffffU << EPWM_CMPA_CMPA_Pos)
#define    EPWM_CMPA_CMPA                                         EPWM_CMPA_CMPA_Msk

#define    EPWM_CMPB_CMPB_Pos                                     (0U)
#define    EPWM_CMPB_CMPB_Msk                                     (0xffffU << EPWM_CMPB_CMPB_Pos)
#define    EPWM_CMPB_CMPB                                         EPWM_CMPB_CMPB_Msk

#define    EPWM_CMPC_CMPC_Pos                                     (0U)
#define    EPWM_CMPC_CMPC_Msk                                     (0xffffU << EPWM_CMPC_CMPC_Pos)
#define    EPWM_CMPC_CMPC                                         EPWM_CMPC_CMPC_Msk

#define    EPWM_CMPD_CMPD_Pos                                     (0U)
#define    EPWM_CMPD_CMPD_Msk                                     (0xffffU << EPWM_CMPD_CMPD_Pos)
#define    EPWM_CMPD_CMPD                                         EPWM_CMPD_CMPD_Msk

#define    EPWM_CCR_CMPDSHEN_Pos                                  (26U)
#define    EPWM_CCR_CMPDSHEN_Msk                                  (0x1U << EPWM_CCR_CMPDSHEN_Pos)
#define    EPWM_CCR_CMPDSHEN                                      EPWM_CCR_CMPDSHEN_Msk

#define    EPWM_CCR_CMPCSHEN_Pos                                  (24U)
#define    EPWM_CCR_CMPCSHEN_Msk                                  (0x1U << EPWM_CCR_CMPCSHEN_Pos)
#define    EPWM_CCR_CMPCSHEN                                      EPWM_CCR_CMPCSHEN_Msk

#define    EPWM_CCR_LDCMPD_Pos                                    (20U)
#define    EPWM_CCR_LDCMPD_Msk                                    (0x7U << EPWM_CCR_LDCMPD_Pos)
#define    EPWM_CCR_LDCMPD                                        EPWM_CCR_LDCMPD_Msk

#define    EPWM_CCR_LDCMPC_Pos                                    (16U)
#define    EPWM_CCR_LDCMPC_Msk                                    (0x7U << EPWM_CCR_LDCMPC_Pos)
#define    EPWM_CCR_LDCMPC                                        EPWM_CCR_LDCMPC_Msk

#define    EPWM_CCR_CMPBSHEN_Pos                                  (10U)
#define    EPWM_CCR_CMPBSHEN_Msk                                  (0x1U << EPWM_CCR_CMPBSHEN_Pos)
#define    EPWM_CCR_CMPBSHEN                                      EPWM_CCR_CMPBSHEN_Msk

#define    EPWM_CCR_CMPASHEN_Pos                                  (8U)
#define    EPWM_CCR_CMPASHEN_Msk                                  (0x1U << EPWM_CCR_CMPASHEN_Pos)
#define    EPWM_CCR_CMPASHEN                                      EPWM_CCR_CMPASHEN_Msk

#define    EPWM_CCR_LDCMPB_Pos                                    (4U)
#define    EPWM_CCR_LDCMPB_Msk                                    (0x7U << EPWM_CCR_LDCMPB_Pos)
#define    EPWM_CCR_LDCMPB                                        EPWM_CCR_LDCMPB_Msk

#define    EPWM_CCR_LDCMPA_Pos                                    (0U)
#define    EPWM_CCR_LDCMPA_Msk                                    (0x7U << EPWM_CCR_LDCMPA_Pos)
#define    EPWM_CCR_LDCMPA                                        EPWM_CCR_LDCMPA_Msk

#define    EPWM_OACR_OACRSHEN_Pos                                 (15U)
#define    EPWM_OACR_OACRSHEN_Msk                                 (0x1U << EPWM_OACR_OACRSHEN_Pos)
#define    EPWM_OACR_OACRSHEN                                     EPWM_OACR_OACRSHEN_Msk

#define    EPWM_OACR_LDOA_Pos                                     (12U)
#define    EPWM_OACR_LDOA_Msk                                     (0x7U << EPWM_OACR_LDOA_Pos)
#define    EPWM_OACR_LDOA                                         EPWM_OACR_LDOA_Msk

#define    EPWM_OACR_CBD_Pos                                      (10U)
#define    EPWM_OACR_CBD_Msk                                      (0x3U << EPWM_OACR_CBD_Pos)
#define    EPWM_OACR_CBD                                          EPWM_OACR_CBD_Msk

#define    EPWM_OACR_CBU_Pos                                      (8U)
#define    EPWM_OACR_CBU_Msk                                      (0x3U << EPWM_OACR_CBU_Pos)
#define    EPWM_OACR_CBU                                          EPWM_OACR_CBU_Msk

#define    EPWM_OACR_CAD_Pos                                      (6U)
#define    EPWM_OACR_CAD_Msk                                      (0x3U << EPWM_OACR_CAD_Pos)
#define    EPWM_OACR_CAD                                          EPWM_OACR_CAD_Msk

#define    EPWM_OACR_CAU_Pos                                      (4U)
#define    EPWM_OACR_CAU_Msk                                      (0x3U << EPWM_OACR_CAU_Pos)
#define    EPWM_OACR_CAU                                          EPWM_OACR_CAU_Msk

#define    EPWM_OACR_PRD_Pos                                      (2U)
#define    EPWM_OACR_PRD_Msk                                      (0x3U << EPWM_OACR_PRD_Pos)
#define    EPWM_OACR_PRD                                          EPWM_OACR_PRD_Msk

#define    EPWM_OACR_ZRO_Pos                                      (0U)
#define    EPWM_OACR_ZRO_Msk                                      (0x3U << EPWM_OACR_ZRO_Pos)
#define    EPWM_OACR_ZRO                                          EPWM_OACR_ZRO_Msk

#define    EPWM_SFCR_LDSFR_Pos                                    (8U)
#define    EPWM_SFCR_LDSFR_Msk                                    (0x3U << EPWM_SFCR_LDSFR_Pos)
#define    EPWM_SFCR_LDSFR                                        EPWM_SFCR_LDSFR_Msk

#define    EPWM_SFCR_ACTOTSFB_Pos                                 (4U)
#define    EPWM_SFCR_ACTOTSFB_Msk                                 (0x3U << EPWM_SFCR_ACTOTSFB_Pos)
#define    EPWM_SFCR_ACTOTSFB                                     EPWM_SFCR_ACTOTSFB_Msk

#define    EPWM_SFCR_ACTOTSFA_Pos                                 (0U)
#define    EPWM_SFCR_ACTOTSFA_Msk                                 (0x3U << EPWM_SFCR_ACTOTSFA_Pos)
#define    EPWM_SFCR_ACTOTSFA                                     EPWM_SFCR_ACTOTSFA_Msk

#define    EPWM_SFR_OTSFB_Pos                                     (6U)
#define    EPWM_SFR_OTSFB_Msk                                     (0x1U << EPWM_SFR_OTSFB_Pos)
#define    EPWM_SFR_OTSFB                                         EPWM_SFR_OTSFB_Msk

#define    EPWM_SFR_OTSFA_Pos                                     (4U)
#define    EPWM_SFR_OTSFA_Msk                                     (0x1U << EPWM_SFR_OTSFA_Pos)
#define    EPWM_SFR_OTSFA                                         EPWM_SFR_OTSFA_Msk

#define    EPWM_SFR_CSFA_Pos                                      (0U)
#define    EPWM_SFR_CSFA_Msk                                      (0x3U << EPWM_SFR_CSFA_Pos)
#define    EPWM_SFR_CSFA                                          EPWM_SFR_CSFA_Msk

#define    EPWM_DTCR_FEDSEL_Pos                                   (5U)
#define    EPWM_DTCR_FEDSEL_Msk                                   (0x1U << EPWM_DTCR_FEDSEL_Pos)
#define    EPWM_DTCR_FEDSEL                                       EPWM_DTCR_FEDSEL_Msk

#define    EPWM_DTCR_REDSEL_Pos                                   (4U)
#define    EPWM_DTCR_REDSEL_Msk                                   (0x1U << EPWM_DTCR_REDSEL_Pos)
#define    EPWM_DTCR_REDSEL                                       EPWM_DTCR_REDSEL_Msk

#define    EPWM_DTCR_POLSELA_Pos                                  (2U)
#define    EPWM_DTCR_POLSELA_Msk                                  (0x1U << EPWM_DTCR_POLSELA_Pos)
#define    EPWM_DTCR_POLSELA                                      EPWM_DTCR_POLSELA_Msk

#define    EPWM_DTCR_BYPASSA_Pos                                  (0U)
#define    EPWM_DTCR_BYPASSA_Msk                                  (0x1U << EPWM_DTCR_BYPASSA_Pos)
#define    EPWM_DTCR_BYPASSA                                      EPWM_DTCR_BYPASSA_Msk

#define    EPWM_DTDLY_RED_Pos                                     (16U)
#define    EPWM_DTDLY_RED_Msk                                     (0x3ffU << EPWM_DTDLY_RED_Pos)
#define    EPWM_DTDLY_RED                                         EPWM_DTDLY_RED_Msk

#define    EPWM_DTDLY_FED_Pos                                     (0U)
#define    EPWM_DTDLY_FED_Msk                                     (0x3ffU << EPWM_DTDLY_FED_Pos)
#define    EPWM_DTDLY_FED                                         EPWM_DTDLY_FED_Msk

#define    EPWM_CPCR_CHPHW_Pos                                    (16U)
#define    EPWM_CPCR_CHPHW_Msk                                    (0x3fU << EPWM_CPCR_CHPHW_Pos)
#define    EPWM_CPCR_CHPHW                                        EPWM_CPCR_CHPHW_Msk

#define    EPWM_CPCR_CHPLW_Pos                                    (8U)
#define    EPWM_CPCR_CHPLW_Msk                                    (0x3fU << EPWM_CPCR_CHPLW_Pos)
#define    EPWM_CPCR_CHPLW                                        EPWM_CPCR_CHPLW_Msk

#define    EPWM_CPCR_OSPW_Pos                                     (4U)
#define    EPWM_CPCR_OSPW_Msk                                     (0xfU << EPWM_CPCR_OSPW_Pos)
#define    EPWM_CPCR_OSPW                                         EPWM_CPCR_OSPW_Msk

#define    EPWM_CPCR_OSPEN_Pos                                    (2U)
#define    EPWM_CPCR_OSPEN_Msk                                    (0x1U << EPWM_CPCR_OSPEN_Pos)
#define    EPWM_CPCR_OSPEN                                        EPWM_CPCR_OSPEN_Msk

#define    EPWM_CPCR_CHPENA_Pos                                   (0U)
#define    EPWM_CPCR_CHPENA_Msk                                   (0x1U << EPWM_CPCR_CHPENA_Pos)
#define    EPWM_CPCR_CHPENA                                       EPWM_CPCR_CHPENA_Msk

#define    EPWM_BKCFR_DCBEVT2_TZEN_Pos                            (19U)
#define    EPWM_BKCFR_DCBEVT2_TZEN_Msk                            (0x1U << EPWM_BKCFR_DCBEVT2_TZEN_Pos)
#define    EPWM_BKCFR_DCBEVT2_TZEN                                EPWM_BKCFR_DCBEVT2_TZEN_Msk

#define    EPWM_BKCFR_DCBEVT1_TZEN_Pos                            (18U)
#define    EPWM_BKCFR_DCBEVT1_TZEN_Msk                            (0x1U << EPWM_BKCFR_DCBEVT1_TZEN_Pos)
#define    EPWM_BKCFR_DCBEVT1_TZEN                                EPWM_BKCFR_DCBEVT1_TZEN_Msk

#define    EPWM_BKCFR_DCAEVT2_TZEN_Pos                            (17U)
#define    EPWM_BKCFR_DCAEVT2_TZEN_Msk                            (0x1U << EPWM_BKCFR_DCAEVT2_TZEN_Pos)
#define    EPWM_BKCFR_DCAEVT2_TZEN                                EPWM_BKCFR_DCAEVT2_TZEN_Msk

#define    EPWM_BKCFR_DCAEVT1_TZEN_Pos                            (16U)
#define    EPWM_BKCFR_DCAEVT1_TZEN_Msk                            (0x1U << EPWM_BKCFR_DCAEVT1_TZEN_Pos)
#define    EPWM_BKCFR_DCAEVT1_TZEN                                EPWM_BKCFR_DCAEVT1_TZEN_Msk

#define    EPWM_BKCFR_DCBEVT1_OSTEN_Pos                           (15U)
#define    EPWM_BKCFR_DCBEVT1_OSTEN_Msk                           (0x1U << EPWM_BKCFR_DCBEVT1_OSTEN_Pos)
#define    EPWM_BKCFR_DCBEVT1_OSTEN                               EPWM_BKCFR_DCBEVT1_OSTEN_Msk

#define    EPWM_BKCFR_DCAEVT1_OSTEN_Pos                           (14U)
#define    EPWM_BKCFR_DCAEVT1_OSTEN_Msk                           (0x1U << EPWM_BKCFR_DCAEVT1_OSTEN_Pos)
#define    EPWM_BKCFR_DCAEVT1_OSTEN                               EPWM_BKCFR_DCAEVT1_OSTEN_Msk

#define    EPWM_BKCFR_OSTEN_Pos                                   (8U)
#define    EPWM_BKCFR_OSTEN_Msk                                   (0x1U << EPWM_BKCFR_OSTEN_Pos)
#define    EPWM_BKCFR_OSTEN                                       EPWM_BKCFR_OSTEN_Msk

#define    EPWM_BKCFR_DCBEVT2_CBCEN_Pos                           (7U)
#define    EPWM_BKCFR_DCBEVT2_CBCEN_Msk                           (0x1U << EPWM_BKCFR_DCBEVT2_CBCEN_Pos)
#define    EPWM_BKCFR_DCBEVT2_CBCEN                               EPWM_BKCFR_DCBEVT2_CBCEN_Msk

#define    EPWM_BKCFR_DCAEVT2_CBCEN_Pos                           (6U)
#define    EPWM_BKCFR_DCAEVT2_CBCEN_Msk                           (0x1U << EPWM_BKCFR_DCAEVT2_CBCEN_Pos)
#define    EPWM_BKCFR_DCAEVT2_CBCEN                               EPWM_BKCFR_DCAEVT2_CBCEN_Msk

#define    EPWM_BKCFR_CBCEN_Pos                                   (0U)
#define    EPWM_BKCFR_CBCEN_Msk                                   (0x1U << EPWM_BKCFR_CBCEN_Pos)
#define    EPWM_BKCFR_CBCEN                                       EPWM_BKCFR_CBCEN_Msk

#define    EPWM_BKCR_DCBEVT2_Pos                                  (10U)
#define    EPWM_BKCR_DCBEVT2_Msk                                  (0x3U << EPWM_BKCR_DCBEVT2_Pos)
#define    EPWM_BKCR_DCBEVT2                                      EPWM_BKCR_DCBEVT2_Msk

#define    EPWM_BKCR_DCBEVT1_Pos                                  (8U)
#define    EPWM_BKCR_DCBEVT1_Msk                                  (0x3U << EPWM_BKCR_DCBEVT1_Pos)
#define    EPWM_BKCR_DCBEVT1                                      EPWM_BKCR_DCBEVT1_Msk

#define    EPWM_BKCR_DCAEVT2_Pos                                  (6U)
#define    EPWM_BKCR_DCAEVT2_Msk                                  (0x3U << EPWM_BKCR_DCAEVT2_Pos)
#define    EPWM_BKCR_DCAEVT2                                      EPWM_BKCR_DCAEVT2_Msk

#define    EPWM_BKCR_DCAEVT1_Pos                                  (4U)
#define    EPWM_BKCR_DCAEVT1_Msk                                  (0x3U << EPWM_BKCR_DCAEVT1_Pos)
#define    EPWM_BKCR_DCAEVT1                                      EPWM_BKCR_DCAEVT1_Msk

#define    EPWM_BKCR_TZA_Pos                                      (0U)
#define    EPWM_BKCR_TZA_Msk                                      (0x3U << EPWM_BKCR_TZA_Pos)
#define    EPWM_BKCR_TZA                                          EPWM_BKCR_TZA_Msk

#define    EPWM_BKIER_DCBEVT2IE_Pos                               (6U)
#define    EPWM_BKIER_DCBEVT2IE_Msk                               (0x1U << EPWM_BKIER_DCBEVT2IE_Pos)
#define    EPWM_BKIER_DCBEVT2IE                                   EPWM_BKIER_DCBEVT2IE_Msk

#define    EPWM_BKIER_DCBEVT1IE_Pos                               (5U)
#define    EPWM_BKIER_DCBEVT1IE_Msk                               (0x1U << EPWM_BKIER_DCBEVT1IE_Pos)
#define    EPWM_BKIER_DCBEVT1IE                                   EPWM_BKIER_DCBEVT1IE_Msk

#define    EPWM_BKIER_DCAEVT2IE_Pos                               (4U)
#define    EPWM_BKIER_DCAEVT2IE_Msk                               (0x1U << EPWM_BKIER_DCAEVT2IE_Pos)
#define    EPWM_BKIER_DCAEVT2IE                                   EPWM_BKIER_DCAEVT2IE_Msk

#define    EPWM_BKIER_DCAEVT1IE_Pos                               (3U)
#define    EPWM_BKIER_DCAEVT1IE_Msk                               (0x1U << EPWM_BKIER_DCAEVT1IE_Pos)
#define    EPWM_BKIER_DCAEVT1IE                                   EPWM_BKIER_DCAEVT1IE_Msk

#define    EPWM_BKIER_OSTIE_Pos                                   (2U)
#define    EPWM_BKIER_OSTIE_Msk                                   (0x1U << EPWM_BKIER_OSTIE_Pos)
#define    EPWM_BKIER_OSTIE                                       EPWM_BKIER_OSTIE_Msk

#define    EPWM_BKIER_CBCIE_Pos                                   (1U)
#define    EPWM_BKIER_CBCIE_Msk                                   (0x1U << EPWM_BKIER_CBCIE_Pos)
#define    EPWM_BKIER_CBCIE                                       EPWM_BKIER_CBCIE_Msk

#define    EPWM_BKISR_OST_DCBEVT1_Pos                             (31U)
#define    EPWM_BKISR_OST_DCBEVT1_Msk                             (0x1U << EPWM_BKISR_OST_DCBEVT1_Pos)
#define    EPWM_BKISR_OST_DCBEVT1                                 EPWM_BKISR_OST_DCBEVT1_Msk

#define    EPWM_BKISR_OST_DCAEVT1_Pos                             (30U)
#define    EPWM_BKISR_OST_DCAEVT1_Msk                             (0x1U << EPWM_BKISR_OST_DCAEVT1_Pos)
#define    EPWM_BKISR_OST_DCAEVT1                                 EPWM_BKISR_OST_DCAEVT1_Msk

#define    EPWM_BKISR_OST6_Pos                                    (29U)
#define    EPWM_BKISR_OST6_Msk                                    (0x1U << EPWM_BKISR_OST6_Pos)
#define    EPWM_BKISR_OST6                                        EPWM_BKISR_OST6_Msk

#define    EPWM_BKISR_OST5_Pos                                    (28U)
#define    EPWM_BKISR_OST5_Msk                                    (0x1U << EPWM_BKISR_OST5_Pos)
#define    EPWM_BKISR_OST5                                        EPWM_BKISR_OST5_Msk

#define    EPWM_BKISR_OST4_Pos                                    (27U)
#define    EPWM_BKISR_OST4_Msk                                    (0x1U << EPWM_BKISR_OST4_Pos)
#define    EPWM_BKISR_OST4                                        EPWM_BKISR_OST4_Msk

#define    EPWM_BKISR_OST3_Pos                                    (26U)
#define    EPWM_BKISR_OST3_Msk                                    (0x1U << EPWM_BKISR_OST3_Pos)
#define    EPWM_BKISR_OST3                                        EPWM_BKISR_OST3_Msk

#define    EPWM_BKISR_OST2_Pos                                    (25U)
#define    EPWM_BKISR_OST2_Msk                                    (0x1U << EPWM_BKISR_OST2_Pos)
#define    EPWM_BKISR_OST2                                        EPWM_BKISR_OST2_Msk

#define    EPWM_BKISR_OST1_Pos                                    (24U)
#define    EPWM_BKISR_OST1_Msk                                    (0x1U << EPWM_BKISR_OST1_Pos)
#define    EPWM_BKISR_OST1                                        EPWM_BKISR_OST1_Msk

#define    EPWM_BKISR_CBC_DCBEVT2_Pos                             (23U)
#define    EPWM_BKISR_CBC_DCBEVT2_Msk                             (0x1U << EPWM_BKISR_CBC_DCBEVT2_Pos)
#define    EPWM_BKISR_CBC_DCBEVT2                                 EPWM_BKISR_CBC_DCBEVT2_Msk

#define    EPWM_BKISR_CBC_DCAEVT2_Pos                             (22U)
#define    EPWM_BKISR_CBC_DCAEVT2_Msk                             (0x1U << EPWM_BKISR_CBC_DCAEVT2_Pos)
#define    EPWM_BKISR_CBC_DCAEVT2                                 EPWM_BKISR_CBC_DCAEVT2_Msk

#define    EPWM_BKISR_CBC6_Pos                                    (21U)
#define    EPWM_BKISR_CBC6_Msk                                    (0x1U << EPWM_BKISR_CBC6_Pos)
#define    EPWM_BKISR_CBC6                                        EPWM_BKISR_CBC6_Msk

#define    EPWM_BKISR_CBC5_Pos                                    (20U)
#define    EPWM_BKISR_CBC5_Msk                                    (0x1U << EPWM_BKISR_CBC5_Pos)
#define    EPWM_BKISR_CBC5                                        EPWM_BKISR_CBC5_Msk

#define    EPWM_BKISR_CBC4_Pos                                    (19U)
#define    EPWM_BKISR_CBC4_Msk                                    (0x1U << EPWM_BKISR_CBC4_Pos)
#define    EPWM_BKISR_CBC4                                        EPWM_BKISR_CBC4_Msk

#define    EPWM_BKISR_CBC3_Pos                                    (18U)
#define    EPWM_BKISR_CBC3_Msk                                    (0x1U << EPWM_BKISR_CBC3_Pos)
#define    EPWM_BKISR_CBC3                                        EPWM_BKISR_CBC3_Msk

#define    EPWM_BKISR_CBC2_Pos                                    (17U)
#define    EPWM_BKISR_CBC2_Msk                                    (0x1U << EPWM_BKISR_CBC2_Pos)
#define    EPWM_BKISR_CBC2                                        EPWM_BKISR_CBC2_Msk

#define    EPWM_BKISR_CBC1_Pos                                    (16U)
#define    EPWM_BKISR_CBC1_Msk                                    (0x1U << EPWM_BKISR_CBC1_Pos)
#define    EPWM_BKISR_CBC1                                        EPWM_BKISR_CBC1_Msk

#define    EPWM_BKISR_DCBEVT2IF_Pos                               (6U)
#define    EPWM_BKISR_DCBEVT2IF_Msk                               (0x1U << EPWM_BKISR_DCBEVT2IF_Pos)
#define    EPWM_BKISR_DCBEVT2IF                                   EPWM_BKISR_DCBEVT2IF_Msk

#define    EPWM_BKISR_DCBEVT1IF_Pos                               (5U)
#define    EPWM_BKISR_DCBEVT1IF_Msk                               (0x1U << EPWM_BKISR_DCBEVT1IF_Pos)
#define    EPWM_BKISR_DCBEVT1IF                                   EPWM_BKISR_DCBEVT1IF_Msk

#define    EPWM_BKISR_DCAEVT2IF_Pos                               (4U)
#define    EPWM_BKISR_DCAEVT2IF_Msk                               (0x1U << EPWM_BKISR_DCAEVT2IF_Pos)
#define    EPWM_BKISR_DCAEVT2IF                                   EPWM_BKISR_DCAEVT2IF_Msk

#define    EPWM_BKISR_DCAEVT1IF_Pos                               (3U)
#define    EPWM_BKISR_DCAEVT1IF_Msk                               (0x1U << EPWM_BKISR_DCAEVT1IF_Pos)
#define    EPWM_BKISR_DCAEVT1IF                                   EPWM_BKISR_DCAEVT1IF_Msk

#define    EPWM_BKISR_OSTIF_Pos                                   (2U)
#define    EPWM_BKISR_OSTIF_Msk                                   (0x1U << EPWM_BKISR_OSTIF_Pos)
#define    EPWM_BKISR_OSTIF                                       EPWM_BKISR_OSTIF_Msk

#define    EPWM_BKISR_CBCIF_Pos                                   (1U)
#define    EPWM_BKISR_CBCIF_Msk                                   (0x1U << EPWM_BKISR_CBCIF_Pos)
#define    EPWM_BKISR_CBCIF                                       EPWM_BKISR_CBCIF_Msk

#define    EPWM_BKCLR_DCBEVT2C_Pos                                (6U)
#define    EPWM_BKCLR_DCBEVT2C_Msk                                (0x1U << EPWM_BKCLR_DCBEVT2C_Pos)
#define    EPWM_BKCLR_DCBEVT2C                                    EPWM_BKCLR_DCBEVT2C_Msk

#define    EPWM_BKCLR_DCBEVT1C_Pos                                (5U)
#define    EPWM_BKCLR_DCBEVT1C_Msk                                (0x1U << EPWM_BKCLR_DCBEVT1C_Pos)
#define    EPWM_BKCLR_DCBEVT1C                                    EPWM_BKCLR_DCBEVT1C_Msk

#define    EPWM_BKCLR_DCAEVT2C_Pos                                (4U)
#define    EPWM_BKCLR_DCAEVT2C_Msk                                (0x1U << EPWM_BKCLR_DCAEVT2C_Pos)
#define    EPWM_BKCLR_DCAEVT2C                                    EPWM_BKCLR_DCAEVT2C_Msk

#define    EPWM_BKCLR_DCAEVT1C_Pos                                (3U)
#define    EPWM_BKCLR_DCAEVT1C_Msk                                (0x1U << EPWM_BKCLR_DCAEVT1C_Pos)
#define    EPWM_BKCLR_DCAEVT1C                                    EPWM_BKCLR_DCAEVT1C_Msk

#define    EPWM_BKCLR_OSTC_Pos                                    (2U)
#define    EPWM_BKCLR_OSTC_Msk                                    (0x1U << EPWM_BKCLR_OSTC_Pos)
#define    EPWM_BKCLR_OSTC                                        EPWM_BKCLR_OSTC_Msk

#define    EPWM_BKCLR_CBCC_Pos                                    (1U)
#define    EPWM_BKCLR_CBCC_Msk                                    (0x1U << EPWM_BKCLR_CBCC_Pos)
#define    EPWM_BKCLR_CBCC                                        EPWM_BKCLR_CBCC_Msk

#define    EPWM_BKSFR_DCBEVT2SF_Pos                               (6U)
#define    EPWM_BKSFR_DCBEVT2SF_Msk                               (0x1U << EPWM_BKSFR_DCBEVT2SF_Pos)
#define    EPWM_BKSFR_DCBEVT2SF                                   EPWM_BKSFR_DCBEVT2SF_Msk

#define    EPWM_BKSFR_DCBEVT1SF_Pos                               (5U)
#define    EPWM_BKSFR_DCBEVT1SF_Msk                               (0x1U << EPWM_BKSFR_DCBEVT1SF_Pos)
#define    EPWM_BKSFR_DCBEVT1SF                                   EPWM_BKSFR_DCBEVT1SF_Msk

#define    EPWM_BKSFR_DCAEVT2SF_Pos                               (4U)
#define    EPWM_BKSFR_DCAEVT2SF_Msk                               (0x1U << EPWM_BKSFR_DCAEVT2SF_Pos)
#define    EPWM_BKSFR_DCAEVT2SF                                   EPWM_BKSFR_DCAEVT2SF_Msk

#define    EPWM_BKSFR_DCAEVT1SF_Pos                               (3U)
#define    EPWM_BKSFR_DCAEVT1SF_Msk                               (0x1U << EPWM_BKSFR_DCAEVT1SF_Pos)
#define    EPWM_BKSFR_DCAEVT1SF                                   EPWM_BKSFR_DCAEVT1SF_Msk

#define    EPWM_BKSFR_OSTSF_Pos                                   (2U)
#define    EPWM_BKSFR_OSTSF_Msk                                   (0x1U << EPWM_BKSFR_OSTSF_Pos)
#define    EPWM_BKSFR_OSTSF                                       EPWM_BKSFR_OSTSF_Msk

#define    EPWM_BKSFR_CBCSF_Pos                                   (1U)
#define    EPWM_BKSFR_CBCSF_Msk                                   (0x1U << EPWM_BKSFR_CBCSF_Pos)
#define    EPWM_BKSFR_CBCSF                                       EPWM_BKSFR_CBCSF_Msk

#define    EPWM_DCINSR_DCBEVT1CFG_Pos                             (22U)
#define    EPWM_DCINSR_DCBEVT1CFG_Msk                             (0x7U << EPWM_DCINSR_DCBEVT1CFG_Pos)
#define    EPWM_DCINSR_DCBEVT1CFG                                 EPWM_DCINSR_DCBEVT1CFG_Msk

#define    EPWM_DCINSR_DCAEVT1CFG_Pos                             (16U)
#define    EPWM_DCINSR_DCAEVT1CFG_Msk                             (0x7U << EPWM_DCINSR_DCAEVT1CFG_Pos)
#define    EPWM_DCINSR_DCAEVT1CFG                                 EPWM_DCINSR_DCAEVT1CFG_Msk

#define    EPWM_DCINSR_DCBLSEL_Pos                                (12U)
#define    EPWM_DCINSR_DCBLSEL_Msk                                (0xfU << EPWM_DCINSR_DCBLSEL_Pos)
#define    EPWM_DCINSR_DCBLSEL                                    EPWM_DCINSR_DCBLSEL_Msk

#define    EPWM_DCINSR_DCBHSEL_Pos                                (8U)
#define    EPWM_DCINSR_DCBHSEL_Msk                                (0xfU << EPWM_DCINSR_DCBHSEL_Pos)
#define    EPWM_DCINSR_DCBHSEL                                    EPWM_DCINSR_DCBHSEL_Msk

#define    EPWM_DCINSR_DCALSEL_Pos                                (4U)
#define    EPWM_DCINSR_DCALSEL_Msk                                (0xfU << EPWM_DCINSR_DCALSEL_Pos)
#define    EPWM_DCINSR_DCALSEL                                    EPWM_DCINSR_DCALSEL_Msk

#define    EPWM_DCINSR_DCAHSEL_Pos                                (0U)
#define    EPWM_DCINSR_DCAHSEL_Msk                                (0xfU << EPWM_DCINSR_DCAHSEL_Pos)
#define    EPWM_DCINSR_DCAHSEL                                    EPWM_DCINSR_DCAHSEL_Msk

#define    EPWM_DCCR_DCAEVT2FRCS_Pos                              (9U)
#define    EPWM_DCCR_DCAEVT2FRCS_Msk                              (0x1U << EPWM_DCCR_DCAEVT2FRCS_Pos)
#define    EPWM_DCCR_DCAEVT2FRCS                                  EPWM_DCCR_DCAEVT2FRCS_Msk

#define    EPWM_DCCR_DCAEVT2SRC_Pos                               (8U)
#define    EPWM_DCCR_DCAEVT2SRC_Msk                               (0x1U << EPWM_DCCR_DCAEVT2SRC_Pos)
#define    EPWM_DCCR_DCAEVT2SRC                                   EPWM_DCCR_DCAEVT2SRC_Msk

#define    EPWM_DCCR_DCAEVT1SYNC_Pos                              (3U)
#define    EPWM_DCCR_DCAEVT1SYNC_Msk                              (0x1U << EPWM_DCCR_DCAEVT1SYNC_Pos)
#define    EPWM_DCCR_DCAEVT1SYNC                                  EPWM_DCCR_DCAEVT1SYNC_Msk

#define    EPWM_DCCR_DCAEVT1SOC_Pos                               (2U)
#define    EPWM_DCCR_DCAEVT1SOC_Msk                               (0x1U << EPWM_DCCR_DCAEVT1SOC_Pos)
#define    EPWM_DCCR_DCAEVT1SOC                                   EPWM_DCCR_DCAEVT1SOC_Msk

#define    EPWM_DCCR_DCAEVT1FRCS_Pos                              (1U)
#define    EPWM_DCCR_DCAEVT1FRCS_Msk                              (0x1U << EPWM_DCCR_DCAEVT1FRCS_Pos)
#define    EPWM_DCCR_DCAEVT1FRCS                                  EPWM_DCCR_DCAEVT1FRCS_Msk

#define    EPWM_DCCR_DCAEVT1SRC_Pos                               (0U)
#define    EPWM_DCCR_DCAEVT1SRC_Msk                               (0x1U << EPWM_DCCR_DCAEVT1SRC_Pos)
#define    EPWM_DCCR_DCAEVT1SRC                                   EPWM_DCCR_DCAEVT1SRC_Msk

#define    EPWM_DCFCR_ALIGN_Pos                                   (4U)
#define    EPWM_DCFCR_ALIGN_Msk                                   (0x3U << EPWM_DCFCR_ALIGN_Pos)
#define    EPWM_DCFCR_ALIGN                                       EPWM_DCFCR_ALIGN_Msk

#define    EPWM_DCFCR_BLKINV_Pos                                  (3U)
#define    EPWM_DCFCR_BLKINV_Msk                                  (0x1U << EPWM_DCFCR_BLKINV_Pos)
#define    EPWM_DCFCR_BLKINV                                      EPWM_DCFCR_BLKINV_Msk

#define    EPWM_DCFCR_BLKE_Pos                                    (2U)
#define    EPWM_DCFCR_BLKE_Msk                                    (0x1U << EPWM_DCFCR_BLKE_Pos)
#define    EPWM_DCFCR_BLKE                                        EPWM_DCFCR_BLKE_Msk

#define    EPWM_DCFCR_SRCSEL_Pos                                    (0U)
#define    EPWM_DCFCR_SRCSEL_Msk                                    (0x3U << EPWM_DCFCR_SRCSEL_Pos)
#define    EPWM_DCFCR_SRCSEL                                        EPWM_DCFCR_SRCSEL_Msk

#define    EPWM_DCFWR_WINDOW_Pos                                  (16U)
#define    EPWM_DCFWR_WINDOW_Msk                                  (0xffU << EPWM_DCFWR_WINDOW_Pos)
#define    EPWM_DCFWR_WINDOW                                      EPWM_DCFWR_WINDOW_Msk

#define    EPWM_DCFWR_WINOFFSET_Pos                               (0U)
#define    EPWM_DCFWR_WINOFFSET_Msk                               (0xffffU << EPWM_DCFWR_WINOFFSET_Pos)
#define    EPWM_DCFWR_WINOFFSET                                   EPWM_DCFWR_WINOFFSET_Msk

#define    EPWM_DCFDR_WINDOW_CNT_Pos                              (16U)
#define    EPWM_DCFDR_WINDOW_CNT_Msk                              (0xffU << EPWM_DCFDR_WINDOW_CNT_Pos)
#define    EPWM_DCFDR_WINDOW_CNT                                  EPWM_DCFDR_WINDOW_CNT_Msk

#define    EPWM_DCFDR_WINOFFSET_CNT_Pos                           (0U)
#define    EPWM_DCFDR_WINOFFSET_CNT_Msk                           (0xffffU << EPWM_DCFDR_WINOFFSET_CNT_Pos)
#define    EPWM_DCFDR_WINOFFSET_CNT                               EPWM_DCFDR_WINOFFSET_CNT_Msk

#define    EPWM_EIER_PCNTSEL_Pos                                  (24U)
#define    EPWM_EIER_PCNTSEL_Msk                                  (0xfU << EPWM_EIER_PCNTSEL_Pos)
#define    EPWM_EIER_PCNTSEL                                      EPWM_EIER_PCNTSEL_Msk

#define    EPWM_EIER_SOCBSEL_Pos                                  (20U)
#define    EPWM_EIER_SOCBSEL_Msk                                  (0xfU << EPWM_EIER_SOCBSEL_Pos)
#define    EPWM_EIER_SOCBSEL                                      EPWM_EIER_SOCBSEL_Msk

#define    EPWM_EIER_SOCASEL_Pos                                  (16U)
#define    EPWM_EIER_SOCASEL_Msk                                  (0xfU << EPWM_EIER_SOCASEL_Pos)
#define    EPWM_EIER_SOCASEL                                      EPWM_EIER_SOCASEL_Msk

#define    EPWM_EIER_SOCBEN_Pos                                   (14U)
#define    EPWM_EIER_SOCBEN_Msk                                   (0x1U << EPWM_EIER_SOCBEN_Pos)
#define    EPWM_EIER_SOCBEN                                       EPWM_EIER_SOCBEN_Msk

#define    EPWM_EIER_SOCAEN_Pos                                   (13U)
#define    EPWM_EIER_SOCAEN_Msk                                   (0x1U << EPWM_EIER_SOCAEN_Pos)
#define    EPWM_EIER_SOCAEN                                       EPWM_EIER_SOCAEN_Msk

#define    EPWM_EIER_PCNTIE_Pos                                   (12U)
#define    EPWM_EIER_PCNTIE_Msk                                   (0x1U << EPWM_EIER_PCNTIE_Pos)
#define    EPWM_EIER_PCNTIE                                       EPWM_EIER_PCNTIE_Msk

#define    EPWM_EIER_SOCBIE_Pos                                   (11U)
#define    EPWM_EIER_SOCBIE_Msk                                   (0x1U << EPWM_EIER_SOCBIE_Pos)
#define    EPWM_EIER_SOCBIE                                       EPWM_EIER_SOCBIE_Msk

#define    EPWM_EIER_SOCAIE_Pos                                   (10U)
#define    EPWM_EIER_SOCAIE_Msk                                   (0x1U << EPWM_EIER_SOCAIE_Pos)
#define    EPWM_EIER_SOCAIE                                       EPWM_EIER_SOCAIE_Msk

#define    EPWM_EIER_CAUIE_Pos                                    (2U)
#define    EPWM_EIER_CAUIE_Msk                                    (0x1U << EPWM_EIER_CAUIE_Pos)
#define    EPWM_EIER_CAUIE                                        EPWM_EIER_CAUIE_Msk

#define    EPWM_EIER_CPIE_Pos                                     (1U)
#define    EPWM_EIER_CPIE_Msk                                     (0x1U << EPWM_EIER_CPIE_Pos)
#define    EPWM_EIER_CPIE                                         EPWM_EIER_CPIE_Msk

#define    EPWM_EIER_CZIE_Pos                                     (0U)
#define    EPWM_EIER_CZIE_Msk                                     (0x1U << EPWM_EIER_CZIE_Pos)
#define    EPWM_EIER_CZIE                                         EPWM_EIER_CZIE_Msk

#define    EPWM_EISR_PCNTIF_Pos                                   (12U)
#define    EPWM_EISR_PCNTIF_Msk                                   (0x1U << EPWM_EISR_PCNTIF_Pos)
#define    EPWM_EISR_PCNTIF                                       EPWM_EISR_PCNTIF_Msk

#define    EPWM_EISR_SOCBIF_Pos                                   (11U)
#define    EPWM_EISR_SOCBIF_Msk                                   (0x1U << EPWM_EISR_SOCBIF_Pos)
#define    EPWM_EISR_SOCBIF                                       EPWM_EISR_SOCBIF_Msk

#define    EPWM_EISR_SOCAIF_Pos                                   (10U)
#define    EPWM_EISR_SOCAIF_Msk                                   (0x1U << EPWM_EISR_SOCAIF_Pos)
#define    EPWM_EISR_SOCAIF                                       EPWM_EISR_SOCAIF_Msk

#define    EPWM_EISR_CAUIF_Pos                                    (2U)
#define    EPWM_EISR_CAUIF_Msk                                    (0x1U << EPWM_EISR_CAUIF_Pos)
#define    EPWM_EISR_CAUIF                                        EPWM_EISR_CAUIF_Msk

#define    EPWM_EISR_CPIF_Pos                                     (1U)
#define    EPWM_EISR_CPIF_Msk                                     (0x1U << EPWM_EISR_CPIF_Pos)
#define    EPWM_EISR_CPIF                                         EPWM_EISR_CPIF_Msk

#define    EPWM_EISR_CZIF_Pos                                     (0U)
#define    EPWM_EISR_CZIF_Msk                                     (0x1U << EPWM_EISR_CZIF_Pos)
#define    EPWM_EISR_CZIF                                         EPWM_EISR_CZIF_Msk

#define    EPWM_EPSR_PCINTCNT_Pos                                 (20U)
#define    EPWM_EPSR_PCINTCNT_Msk                                 (0xfU << EPWM_EPSR_PCINTCNT_Pos)
#define    EPWM_EPSR_PCINTCNT                                     EPWM_EPSR_PCINTCNT_Msk

#define    EPWM_EPSR_PCINTPRD_Pos                                 (16U)
#define    EPWM_EPSR_PCINTPRD_Msk                                 (0xfU << EPWM_EPSR_PCINTPRD_Pos)
#define    EPWM_EPSR_PCINTPRD                                     EPWM_EPSR_PCINTPRD_Msk

#define    EPWM_EPSR_SOCBCNT_Pos                                  (12U)
#define    EPWM_EPSR_SOCBCNT_Msk                                  (0xfU << EPWM_EPSR_SOCBCNT_Pos)
#define    EPWM_EPSR_SOCBCNT                                      EPWM_EPSR_SOCBCNT_Msk

#define    EPWM_EPSR_SOCBPRD_Pos                                  (8U)
#define    EPWM_EPSR_SOCBPRD_Msk                                  (0xfU << EPWM_EPSR_SOCBPRD_Pos)
#define    EPWM_EPSR_SOCBPRD                                      EPWM_EPSR_SOCBPRD_Msk

#define    EPWM_EPSR_SOCACNT_Pos                                  (4U)
#define    EPWM_EPSR_SOCACNT_Msk                                  (0xfU << EPWM_EPSR_SOCACNT_Pos)
#define    EPWM_EPSR_SOCACNT                                      EPWM_EPSR_SOCACNT_Msk

#define    EPWM_EPSR_SOCAPRD_Pos                                  (0U)
#define    EPWM_EPSR_SOCAPRD_Msk                                  (0xfU << EPWM_EPSR_SOCAPRD_Pos)
#define    EPWM_EPSR_SOCAPRD                                      EPWM_EPSR_SOCAPRD_Msk

#define    EPWM_SWTR_SOCB_Pos                                     (1U)
#define    EPWM_SWTR_SOCB_Msk                                     (0x1U << EPWM_SWTR_SOCB_Pos)
#define    EPWM_SWTR_SOCB                                         EPWM_SWTR_SOCB_Msk

#define    EPWM_SWTR_SOCA_Pos                                     (0U)
#define    EPWM_SWTR_SOCA_Msk                                     (0x1U << EPWM_SWTR_SOCA_Pos)
#define    EPWM_SWTR_SOCA                                         EPWM_SWTR_SOCA_Msk

#define    EPWM_HRCR_HRLDPRD_Pos                                  (10U)
#define    EPWM_HRCR_HRLDPRD_Msk                                  (0x1U << EPWM_HRCR_HRLDPRD_Pos)
#define    EPWM_HRCR_HRLDPRD                                      EPWM_HRCR_HRLDPRD_Msk

#define    EPWM_HRCR_HRLDZRO_Pos                                  (9U)
#define    EPWM_HRCR_HRLDZRO_Msk                                  (0x1U << EPWM_HRCR_HRLDZRO_Pos)
#define    EPWM_HRCR_HRLDZRO                                      EPWM_HRCR_HRLDZRO_Msk

#define    EPWM_HRCR_HRSHEN_Pos                                   (8U)
#define    EPWM_HRCR_HRSHEN_Msk                                   (0x1U << EPWM_HRCR_HRSHEN_Pos)
#define    EPWM_HRCR_HRSHEN                                       EPWM_HRCR_HRSHEN_Msk

#define    EPWM_HRCR_HRPWMEN_Pos                                  (0U)
#define    EPWM_HRCR_HRPWMEN_Msk                                  (0x1U << EPWM_HRCR_HRPWMEN_Pos)
#define    EPWM_HRCR_HRPWMEN                                      EPWM_HRCR_HRPWMEN_Msk

#define    EPWM_HRPRD_HRPRD_Pos                                   (0U)
#define    EPWM_HRPRD_HRPRD_Msk                                   (0x1fU << EPWM_HRPRD_HRPRD_Pos)
#define    EPWM_HRPRD_HRPRD                                       EPWM_HRPRD_HRPRD_Msk

#define    EPWM_HRCMPA_HRCMPA_Pos                                 (0U)
#define    EPWM_HRCMPA_HRCMPA_Msk                                 (0x1fU << EPWM_HRCMPA_HRCMPA_Pos)
#define    EPWM_HRCMPA_HRCMPA                                     EPWM_HRCMPA_HRCMPA_Msk

#define    EPWM_HRCMPB_HRCMPB_Pos                                 (0U)
#define    EPWM_HRCMPB_HRCMPB_Msk                                 (0x1fU << EPWM_HRCMPB_HRCMPB_Pos)
#define    EPWM_HRCMPB_HRCMPB                                     EPWM_HRCMPB_HRCMPB_Msk

#define    EPWM_HRACR_LOCK_Pos                                    (16U)
#define    EPWM_HRACR_LOCK_Msk                                    (0x1U << EPWM_HRACR_LOCK_Pos)
#define    EPWM_HRACR_LOCK                                        EPWM_HRACR_LOCK_Msk

#define    EPWM_HRACR_PWRESHAPER_EN_Pos                           (8U)
#define    EPWM_HRACR_PWRESHAPER_EN_Msk                           (0x1U << EPWM_HRACR_PWRESHAPER_EN_Pos)
#define    EPWM_HRACR_PWRESHAPER_EN                               EPWM_HRACR_PWRESHAPER_EN_Msk

#define    EPWM_HRACR_ITRIM_Pos                                   (4U)
#define    EPWM_HRACR_ITRIM_Msk                                   (0x7U << EPWM_HRACR_ITRIM_Pos)
#define    EPWM_HRACR_ITRIM                                       EPWM_HRACR_ITRIM_Msk

#define    EPWM_HRACR_RTRIM_Pos                                   (0U)
#define    EPWM_HRACR_RTRIM_Msk                                   (0xfU << EPWM_HRACR_RTRIM_Pos)
#define    EPWM_HRACR_RTRIM                                       EPWM_HRACR_RTRIM_Msk

#define    EPWM_LINK_LINK_Pos                                     (0U)
#define    EPWM_LINK_LINK_Msk                                     (0x7U << EPWM_LINK_LINK_Pos)
#define    EPWM_LINK_LINK                                         EPWM_LINK_LINK_Msk

#define    EPWM_CR_CEN_Pos                                       (0U)
#define    EPWM_CR_CEN_Msk                                       (0x1U << EPWM_CR_CEN_Pos)
#define    EPWM_CR_CEN                                            EPWM_CR_CEN_Msk

#define    FL_EPWM_CHANNEL_A                                      0x0U
#define    FL_EPWM_CHANNEL_B                                      0x1U

#define    FL_EPWM_BKCHANNEL_1                                     0x0U
#define    FL_EPWM_BKCHANNEL_2                                     0x1U
#define    FL_EPWM_BKCHANNEL_3                                     0x2U
#define    FL_EPWM_BKCHANNEL_4                                     0x3U
#define    FL_EPWM_BKCHANNEL_5                                     0x4U
#define    FL_EPWM_BKCHANNEL_6                                     0x5U

#define    FL_EPWM_COMPAREA                                        0x1U
#define    FL_EPWM_COMPAREB                                        0x2U
#define    FL_EPWM_COMPAREC                                        0x3U
#define    FL_EPWM_COMPARED                                        0x4U

#define    FL_EPWM_DEBUG_STOP                                     (0x0U << EPWM_TBCR_DBGMODE_Pos)
#define    FL_EPWM_DEBUG_STOP_UPDATE                              (0x1U << EPWM_TBCR_DBGMODE_Pos)
#define    FL_EPWM_DEBUG_FREE_RUN                                 (0x2U << EPWM_TBCR_DBGMODE_Pos)

#define    FL_EPWM_COUNTER_SYNC_DIR_UP                            (0x1U << EPWM_TBCR_PHSDIR_Pos)
#define    FL_EPWM_COUNTER_SYNC_DIR_DOWN                          (0x0U << EPWM_TBCR_PHSDIR_Pos)

#define    FL_EPWM_SYNCOUT_ONCE                                   (0x0U << EPWM_TBCR_OSTSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_CONTINUE                               (0x1U << EPWM_TBCR_OSTSYNCOEN_Pos)

#define    FL_EPWM_COUNTER_MODE_UP                                (0x0U << EPWM_TBCR_CNTMODE_Pos)
#define    FL_EPWM_COUNTER_MODE_DOWN                              (0x1U << EPWM_TBCR_CNTMODE_Pos)
#define    FL_EPWM_COUNTER_MODE_UP_DOWN                           (0x2U << EPWM_TBCR_CNTMODE_Pos)
#define    FL_EPWM_COUNTER_MODE_STOP                              (0x3U << EPWM_TBCR_CNTMODE_Pos)

#define    FL_EPWM_COUNTER_DIR_DOWN                               (0x0U << EPWM_TBSR_CNTDIR_Pos)
#define    FL_EPWM_COUNTER_DIR_UP                                 (0x1U << EPWM_TBSR_CNTDIR_Pos)

#define    FL_EPWM_SYNCOUT_SRC_SWSYNC                             (0x1U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_CNT_0                              (0x2U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_CNT_PRD                            (0x4U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_CNT_CMPA                           (0x8U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_CNT_CMPB                           (0x10U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_CNT_CMPC                           (0x20U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_CNT_CMPD                           (0x40U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_DCAEVT1                            (0x80U << EPWM_SYNC_SWSYNCOEN_Pos)
#define    FL_EPWM_SYNCOUT_SRC_DCBEVT1                            (0x100U << EPWM_SYNC_SWSYNCOEN_Pos)

#define    FL_EPWM_SYNC_IN_SEL_NONE                               (0x0U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_EPWM0_SYNCOUT                      (0x1U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_EPWM1_SYNCOUT                      (0x2U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_EPWM2_SYNCOUT                      (0x3U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_EPWM3_SYNCOUT                      (0x4U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_ATIM0                              (0x7U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_ATIM1                              (0x8U << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_GPTIM0                             (0xbU << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_GPTIM1                             (0xcU << EPWM_SYNC_SYNCINSEL_Pos)
#define    FL_EPWM_SYNC_IN_SEL_GPTIM2                             (0xdU << EPWM_SYNC_SYNCINSEL_Pos)

#define    FL_EPWM_COUNT_MODE_UP_CNT_CMPA                         (0x0U )
#define    FL_EPWM_COUNT_MODE_DOWN_CNT_CMPA                       (0x1U)
#define    FL_EPWM_COUNT_MODE_UP_CNT_CMPB                         (0x2U )
#define    FL_EPWM_COUNT_MODE_DOWN_CNT_CMPB                       (0x3U)
#define    FL_EPWM_COUNT_MODE_UP_CNT_CMPC                         (0x4U )
#define    FL_EPWM_COUNT_MODE_DOWN_CNT_CMPC                       (0x5U )
#define    FL_EPWM_COUNT_MODE_UP_CNT_CMPD                         (0x6U )
#define    FL_EPWM_COUNT_MODE_DOWN_CNT_CMPD                       (0x7U )

#define    FL_EPWM_CMPD_LOAD_CNT_0                                (0x1U << EPWM_CCR_LDCMPD_Pos)
#define    FL_EPWM_CMPD_LOAD_CNT_PRD                              (0x2U << EPWM_CCR_LDCMPD_Pos)
#define    FL_EPWM_CMPD_LOAD_SYNC_RISING                          (0x4U << EPWM_CCR_LDCMPD_Pos)

#define    FL_EPWM_CMPC_LOAD_CNT_0                                (0x1U << EPWM_CCR_LDCMPC_Pos)
#define    FL_EPWM_CMPC_LOAD_CNT_PRD                              (0x2U << EPWM_CCR_LDCMPC_Pos)
#define    FL_EPWM_CMPC_LOAD_SYNC_RISING                          (0x4U << EPWM_CCR_LDCMPC_Pos)

#define    FL_EPWM_CMPB_LOAD_CNT_0                                (0x1U << EPWM_CCR_LDCMPB_Pos)
#define    FL_EPWM_CMPB_LOAD_CNT_PRD                              (0x2U << EPWM_CCR_LDCMPB_Pos)
#define    FL_EPWM_CMPB_LOAD_SYNC_RISING                          (0x4U << EPWM_CCR_LDCMPB_Pos)

#define    FL_EPWM_CMPA_LOAD_CNT_0                                (0x1U << EPWM_CCR_LDCMPA_Pos)
#define    FL_EPWM_CMPA_LOAD_CNT_PRD                              (0x2U << EPWM_CCR_LDCMPA_Pos)
#define    FL_EPWM_CMPA_LOAD_SYNC_RISING                          (0x4U << EPWM_CCR_LDCMPA_Pos)

#define    FL_EPWM_OC_LOAD_CNT_0                                  (0x1U<<0)
#define    FL_EPWM_OC_LOAD_CNT_PRD                                (0x1U<<1)
#define    FL_EPWM_OC_LOAD_SYNC_RISING                            (0x1U<<2)

#define    FL_EPWM_OC_MODE_FROZEN                                 (0x0U)
#define    FL_EPWM_OC_MODE_LOW                                    (0x1U)
#define    FL_EPWM_OC_MODE_HIGH                                   (0x2U)
#define    FL_EPWM_OC_MODE_TOGGLE                                 (0x3U)

#define    FL_EPWM_CSF_LOAD_CNT_0                                 (0x0U << EPWM_SFCR_LDSFR_Pos)
#define    FL_EPWM_CSF_LOAD_CNT_ARR                               (0x1U << EPWM_SFCR_LDSFR_Pos)
#define    FL_EPWM_CSF_LOAD_CNT_0_ARR                             (0x2U << EPWM_SFCR_LDSFR_Pos)
#define    FL_EPWM_CSF_LOAD_SOFTWARE                              (0x3U << EPWM_SFCR_LDSFR_Pos)

#define    FL_EPWM_OTSFA_MODE_FROZEN                                 (0x0U << EPWM_SFCR_ACTOTSFA_Pos)
#define    FL_EPWM_OTSFA_MODE_LOW                                    (0x1U << EPWM_SFCR_ACTOTSFA_Pos)
#define    FL_EPWM_OTSFA_MODE_HIGH                                   (0x2U << EPWM_SFCR_ACTOTSFA_Pos)
#define    FL_EPWM_OTSFA_MODE_TOGGLE                                 (0x3U << EPWM_SFCR_ACTOTSFA_Pos)

#define    FL_EPWM_OTSFB_MODE_FROZEN                                 (0x0U << EPWM_SFCR_ACTOTSFB_Pos)
#define    FL_EPWM_OTSFB_MODE_LOW                                    (0x1U << EPWM_SFCR_ACTOTSFB_Pos)
#define    FL_EPWM_OTSFB_MODE_HIGH                                   (0x2U << EPWM_SFCR_ACTOTSFB_Pos)
#define    FL_EPWM_OTSFB_MODE_TOGGLE                                 (0x3U << EPWM_SFCR_ACTOTSFB_Pos)

#define    FL_EPWM_CSF_MODE_FROZEN                                (0x0U << EPWM_SFR_CSFA_Pos)
#define    FL_EPWM_CSF_MODE_CONTINUE_LOW                          (0x1U << EPWM_SFR_CSFA_Pos)
#define    FL_EPWM_CSF_MODE_CONTINUE_HIGH                         (0x2U << EPWM_SFR_CSFA_Pos)
//#define    FL_EPWM_CSF_MODE_FROZEN                                (0x3U << EPWM_SFR_CSFA_Pos)

#define    FL_EPWM_DEADBAND_FALLING_EPWMB                  (0x0U << EPWM_DTCR_FEDSEL_Pos)
#define    FL_EPWM_DEADBAND_FALLING_EPWMA                  (0x1U << EPWM_DTCR_FEDSEL_Pos)

#define    FL_EPWM_DEADBAND_RISING_EPWMB                   (0x0U << EPWM_DTCR_REDSEL_Pos)
#define    FL_EPWM_DEADBAND_RISING_EPWMA                   (0x1U << EPWM_DTCR_REDSEL_Pos)

#define    FL_EPWM_DEADBAND_PORLARITY_NORMAL                      (0x0U << EPWM_DTCR_POLSELA_Pos)
#define    FL_EPWM_DEADBAND_PORLARITY_REVERSE                     (0x1U << EPWM_DTCR_POLSELA_Pos)

#define    FL_EPWM_OUTPUT_HIGH_IMPEDANCE                          (0x0U)
#define    FL_EPWM_OUTPUT_HIGH                                    (0x1U)
#define    FL_EPWM_OUTPUT_LOW                                     (0x2U)
#define    FL_EPWM_OUTPUT_FROZEN                                  (0x3U)

#define    FL_EPWM_DIGITAL_COMPARE_DISABLE                        (0x0U )
#define    FL_EPWM_DIGITAL_COMPARE_DCH_LOW                        (0x1U )
#define    FL_EPWM_DIGITAL_COMPARE_DCH_HIGH                       (0x2U )
#define    FL_EPWM_DIGITAL_COMPARE_DCL_LOW                        (0x3U )
#define    FL_EPWM_DIGITAL_COMPARE_DCL_HIGH                       (0x4U )
#define    FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH             (0x5U )
#define    FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW             (0x6U )

#define    FL_EPWM_DC_EVENT_1                                      (0x0U )
#define    FL_EPWM_DC_EVENT_2                                       (0x3U )

#define    FL_EPWM_INPUT_SOURCE_BK1                               (0x0U)
#define    FL_EPWM_INPUT_SOURCE_BK2                               (0x1U)
#define    FL_EPWM_INPUT_SOURCE_BK3                               (0x2U)
#define    FL_EPWM_INPUT_SOURCE_COMP1OUT                          (0x8U)
#define    FL_EPWM_INPUT_SOURCE_COMP2OUT                          (0x9U)
#define    FL_EPWM_INPUT_SOURCE_COMP3OUT                          (0xaU)

#define    FL_EPWM_DCEVT2_SOFTWARE_SOUECE_SYNC                    (0x0U << EPWM_DCCR_DCAEVT2FRCS_Pos)
#define    FL_EPWM_DCEVT2_SOFTWARE_SOUECE_ASYNC                   (0x1U << EPWM_DCCR_DCAEVT2FRCS_Pos)

#define    FL_EPWM_DCEVT2_SOUECE_DEEVT2                           (0x0U << EPWM_DCCR_DCAEVT2SRC_Pos)
#define    FL_EPWM_DCEVT2_SOUECE_DCEVTFLT                         (0x1U << EPWM_DCCR_DCAEVT2SRC_Pos)

#define    FL_EPWM_DCEVT1_SOFTWARE_SOUECE_SYNC                    (0x0U << EPWM_DCCR_DCAEVT1FRCS_Pos)
#define    FL_EPWM_DCEVT1_SOFTWARE_SOUECE_ASYNC                   (0x1U << EPWM_DCCR_DCAEVT1FRCS_Pos)

#define    FL_EPWM_DCEVT1_SOUECE_DEEVT1                           (0x0U << EPWM_DCCR_DCAEVT1SRC_Pos)
#define    FL_EPWM_DCEVT1_SOUECE_DCEVTFLT                         (0x1U << EPWM_DCCR_DCAEVT1SRC_Pos)

#define    FL_EPWM_ALIGNMENT_MODE_CNT_0                           (0x0U << EPWM_DCFCR_ALIGN_Pos)
#define    FL_EPWM_ALIGNMENT_MODE_CNT_PRD                         (0x1U << EPWM_DCFCR_ALIGN_Pos)
#define    FL_EPWM_ALIGNMENT_MODE_CNT_0ANDCNT_PRD                 (0x2U << EPWM_DCFCR_ALIGN_Pos)
//#define    FL_EPWM_ALIGNMENT_MODE_CNT_0ANDCNT_PRD                 (0x3U << EPWM_DCFCR_ALIGN_Pos)

#define    FL_EPWM_FILTER_INPUT_SOURCE_DCAEVT1                    (0x0U << EPWM_DCFCR_SRCSEL_Pos)
#define    FL_EPWM_FILTER_INPUT_SOURCE_DCAEVT2                    (0x1U << EPWM_DCFCR_SRCSEL_Pos)
#define    FL_EPWM_FILTER_INPUT_SOURCE_DCBEVT1                    (0x2U << EPWM_DCFCR_SRCSEL_Pos)
#define    FL_EPWM_FILTER_INPUT_SOURCE_DCBEVT2                    (0x3U << EPWM_DCFCR_SRCSEL_Pos)

#define    FL_EPWM_COUNT_IE_SOURCE_CNT_0                          (0x1U <<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_PRD                        (0x2U<<EPWM_EIER_PCNTSEL_Pos)
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_0ORCNT_PRD                 (0x3U<<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_UP                    (0x4U<<EPWM_EIER_PCNTSEL_Pos)
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_DOWN                  (0x5U<<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_UP                    (0x6U<<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_DOWN                  (0x7U<<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_UP                    (0xcU<<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_DOWN                  (0xdU<<EPWM_EIER_PCNTSEL_Pos )
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_UP                    (0xeU <<EPWM_EIER_PCNTSEL_Pos)
#define    FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_DOWN                  (0xfU <<EPWM_EIER_PCNTSEL_Pos)

#define    FL_EPWM_PULSE_EVENT_N0                                 (0x0U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N1                                 (0x1U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N2                                 (0x2U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N3                                 (0x3U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N4                                 (0x4U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N5                                 (0x5U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N6                                 (0x6U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N7                                 (0x7U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N8                                 (0x8U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N9                                 (0x9U <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N10                                (0xaU <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N11                                (0xbU <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N12                                (0xcU<<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N13                                (0xdU<<EPWM_EPSR_PCINTPRD_Pos )
#define    FL_EPWM_PULSE_EVENT_N14                                (0xeU <<EPWM_EPSR_PCINTPRD_Pos)
#define    FL_EPWM_PULSE_EVENT_N15                                (0xfU<<EPWM_EPSR_PCINTPRD_Pos)

#define    FL_EPWM_SOCB_EVENT_N0                                  (0x0U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N1                                  (0x1U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N2                                  (0x2U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N3                                  (0x3U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N4                                  (0x4U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N5                                  (0x5U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N6                                  (0x6U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N7                                  (0x7U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N8                                  (0x8U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N9                                  (0x9U <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N10                                 (0xaU <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N11                                 (0xbU <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N12                                 (0xcU <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N13                                 (0xdU <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N14                                 (0xeU <<EPWM_EPSR_SOCBPRD_Pos)
#define    FL_EPWM_SOCB_EVENT_N15                                 (0xfU <<EPWM_EPSR_SOCBPRD_Pos)

#define    FL_EPWM_SOCA_EVENT_N0                                  (0x0U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N1                                  (0x1U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N2                                  (0x2U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N3                                  (0x3U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N4                                  (0x4U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N5                                  (0x5U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N6                                  (0x6U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N7                                  (0x7U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N8                                  (0x8U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N9                                  (0x9U <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N10                                 (0xaU <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N11                                 (0xbU <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N12                                 (0xcU <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N13                                 (0xdU <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N14                                 (0xeU <<EPWM_EPSR_SOCAPRD_Pos)
#define    FL_EPWM_SOCA_EVENT_N15                                 (0xfU <<EPWM_EPSR_SOCAPRD_Pos)

#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_DCBEVT1                    (0x0U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_0                          (0x1U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_PRD                        (0x2U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_0ORCNT_PRD                 (0x3U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_UP                    (0x4U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_DOWN                  (0x5U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_UP                    (0x6U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_DOWN                  (0x7U << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_UP                    (0xcU << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_DOWN                  (0xdU << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_UP                    (0xeU << EPWM_EIER_SOCBSEL_Pos)
#define    FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_DOWN                  (0xfU << EPWM_EIER_SOCBSEL_Pos)

#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_DCAEVT1                    (0x0U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_0                          (0x1U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_PRD                        (0x2U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_0ORCNT_PRD                 (0x3U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_UP                    (0x4U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_DOWN                  (0x5U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_UP                    (0x6U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_DOWN                  (0x7U << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_UP                    (0xcU << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_DOWN                  (0xdU << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_UP                    (0xeU << EPWM_EIER_SOCASEL_Pos)
#define    FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_DOWN                  (0xfU << EPWM_EIER_SOCASEL_Pos)

#define    FL_EPWM_LINK_NONE                                      (0x0U << EPWM_LINK_LINK_Pos)
#define    FL_EPWM_LINK_EPWM0                                     (0x1U << EPWM_LINK_LINK_Pos)
#define    FL_EPWM_LINK_EPWM1                                     (0x2U << EPWM_LINK_LINK_Pos)
#define    FL_EPWM_LINK_EPWM2                                     (0x3U << EPWM_LINK_LINK_Pos)
#define    FL_EPWM_LINK_EPWM3                                     (0x4U << EPWM_LINK_LINK_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup EPWM_FL_Exported_Functions EPWM Exported Functions
  * @{
  */

/**
  * @brief    设置PWM周期值
  * @rmtoll   PRD    PRD    FL_EPWM_WriteAutoReload
  * @param    EPWMx EPWM instance
  * @param    autoReload
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteAutoReload(EPWM_Type *EPWMx, uint32_t autoReload)
{
    MODIFY_REG(EPWMx->PRD, (0xffffU << 0U), (autoReload << 0U));
}

/**
  * @brief    获取PWM周期值
  * @rmtoll   PRD    PRD    FL_EPWM_ReadAutoReload
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadAutoReload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->PRD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置相位load值
  * @rmtoll   PHSR    PHS    FL_EPWM_WritePhaseLoad
  * @param    EPWMx EPWM instance
  * @param    phaseload
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WritePhaseLoad(EPWM_Type *EPWMx, uint32_t phaseload)
{
    MODIFY_REG(EPWMx->PHSR, (0xffffU << 0U), (phaseload << 0U));
}

/**
  * @brief    获取相位load值
  * @rmtoll   PHSR    PHS    FL_EPWM_ReadPhaseLoad
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadPhaseLoad(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->PHSR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置计数器时钟预分频值
  * @rmtoll   PSC    PSC    FL_EPWM_WritePrescaler
  * @param    EPWMx EPWM instance
  * @param    psc
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WritePrescaler(EPWM_Type *EPWMx, uint32_t psc)
{
    MODIFY_REG(EPWMx->PSC, (0xffffU << 0U), (psc << 0U));
}

/**
  * @brief    读取计数器时钟预分频值
  * @rmtoll   PSC    PSC    FL_EPWM_ReadPrescaler
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadPrescaler(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->PSC, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置计数器值
  * @rmtoll   CNTR    CNT    FL_EPWM_WriteCounter
  * @param    EPWMx EPWM instance
  * @param    counter
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteCounter(EPWM_Type *EPWMx, uint32_t counter)
{
    MODIFY_REG(EPWMx->CNTR, (0xffffU << 0U), (counter << 0U));
}

/**
  * @brief    读取计数器值
  * @rmtoll   CNTR    CNT    FL_EPWM_ReadCounter
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadCounter(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CNTR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置debug模式
  * @rmtoll   TBCR    DBGMODE    FL_EPWM_SetDebugMode
  * @param    EPWMx EPWM instance
  * @param    debugmode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DEBUG_STOP
  *           @arg @ref FL_EPWM_DEBUG_STOP_UPDATE
  *           @arg @ref FL_EPWM_DEBUG_FREE_RUN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDebugMode(EPWM_Type *EPWMx, uint32_t debugmode)
{
    MODIFY_REG(EPWMx->TBCR, EPWM_TBCR_DBGMODE_Msk, debugmode);
}

/**
  * @brief    获取debug模式
  * @rmtoll   TBCR    DBGMODE    FL_EPWM_GetDebugMode
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DEBUG_STOP
  *           @arg @ref FL_EPWM_DEBUG_STOP_UPDATE
  *           @arg @ref FL_EPWM_DEBUG_FREE_RUN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDebugMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBCR, EPWM_TBCR_DBGMODE_Msk));
}

/**
  * @brief    设置初始相位方向
  * @rmtoll   TBCR    PHSDIR    FL_EPWM_SetCounterDirection
  * @param    EPWMx EPWM instance
  * @param    counterdir This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_COUNTER_SYNC_DIR_UP
  *           @arg @ref FL_EPWM_COUNTER_SYNC_DIR_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetInitialPhaseDirection(EPWM_Type *EPWMx, uint32_t counterdir)
{
    MODIFY_REG(EPWMx->TBCR, EPWM_TBCR_PHSDIR_Msk, counterdir);
}

/**
  * @brief    获取计数方向
  * @rmtoll   TBCR    PHSDIR    FL_EPWM_GetCounterDirection
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_COUNTER_SYNC_DIR_UP
  *           @arg @ref FL_EPWM_COUNTER_SYNC_DIR_DOWN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetInitialPhaseDirection(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBCR, EPWM_TBCR_PHSDIR_Msk));
}

/**
  * @brief    使能SYNCOUT
  * @rmtoll   TBCR    OSTSYNCO    FL_EPWM_EnableSYNCOUT
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableSYNCOUT(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->TBCR, EPWM_TBCR_OSTSYNCO_Msk);
}

/**
  * @brief    设置SYNCOUT模式
  * @rmtoll   TBCR    OSTSYNCOEN    FL_EPWM_SetSYNCOUTMode
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_SYNCOUT_ONCE
  *           @arg @ref FL_EPWM_SYNCOUT_CONTINUE
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetSYNCOUTMode(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->TBCR, EPWM_TBCR_OSTSYNCOEN_Msk, mode);
}

/**
  * @brief    获取SYNCOUT模式
  * @rmtoll   TBCR    OSTSYNCOEN    FL_EPWM_GetSYNCOUTMode
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SYNCOUT_ONCE
  *           @arg @ref FL_EPWM_SYNCOUT_CONTINUE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSYNCOUTMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBCR, EPWM_TBCR_OSTSYNCOEN_Msk));
}

/**
  * @brief    使能ARR预装载功能
  * @rmtoll   TBCR    PRDSHEN    FL_EPWM_EnableARRPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnablePRDPreload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->TBCR, EPWM_TBCR_PRDSHEN_Msk);
}

/**
  * @brief    获取ARR预装载使能状态
  * @rmtoll   TBCR    PRDSHEN    FL_EPWM_IsEnabledARRPreload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledPRDPreload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBCR, EPWM_TBCR_PRDSHEN_Msk) == EPWM_TBCR_PRDSHEN_Msk);
}

/**
  * @brief    失能ARR预装载功能
  * @rmtoll   TBCR    PRDSHEN    FL_EPWM_DisableARRPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisablePRDPreload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->TBCR, EPWM_TBCR_PRDSHEN_Msk);
}

/**
  * @brief    使能ARR预装载功能
  * @rmtoll   TBCR    PHSEN    FL_EPWM_EnablePhaseReload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnablePhaseReload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->TBCR, EPWM_TBCR_PHSEN_Msk);
}

/**
  * @brief    获取ARR预装载使能状态
  * @rmtoll   TBCR    PHSEN    FL_EPWM_IsEnabledPhaseReload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledPhaseReload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBCR, EPWM_TBCR_PHSEN_Msk) == EPWM_TBCR_PHSEN_Msk);
}

/**
  * @brief    失能ARR预装载功能
  * @rmtoll   TBCR    PHSEN    FL_EPWM_DisablePhaseReload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisablePhaseReload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->TBCR, EPWM_TBCR_PHSEN_Msk);
}

/**
  * @brief    设置定时器模式
  * @rmtoll   TBCR    CNTMODE    FL_EPWM_SetCounterMode
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_COUNTER_MODE_UP
  *           @arg @ref FL_EPWM_COUNTER_MODE_DOWN
  *           @arg @ref FL_EPWM_COUNTER_MODE_UP_DOWN
  *           @arg @ref FL_EPWM_COUNTER_MODE_STOP
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetCounterMode(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->TBCR, EPWM_TBCR_CNTMODE_Msk, mode);
}

/**
  * @brief    获取定时器模式
  * @rmtoll   TBCR    CNTMODE    FL_EPWM_GetCounterMode
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_COUNTER_MODE_UP
  *           @arg @ref FL_EPWM_COUNTER_MODE_DOWN
  *           @arg @ref FL_EPWM_COUNTER_MODE_UP_DOWN
  *           @arg @ref FL_EPWM_COUNTER_MODE_STOP
  */
__STATIC_INLINE uint32_t FL_EPWM_GetCounterMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBCR, EPWM_TBCR_CNTMODE_Msk));
}

/**
  * @brief    计数值达到最大标志
  * @rmtoll   TBSR    CNTMAX    FL_EPWM_IsActiveFlag_CNTMAX
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_CNTMAX(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBSR, EPWM_TBSR_CNTMAX_Msk) == (EPWM_TBSR_CNTMAX_Msk));
}

/**
  * @brief    清除计数值达到最大标志
  * @rmtoll   TBSR    CNTMAX    FL_EPWM_ClearFlag_CNTMAX
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_CNTMAX(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->TBSR, EPWM_TBSR_CNTMAX_Msk);
}

/**
  * @brief    获取输入同步标志
  * @rmtoll   TBSR    SYNCIF    FL_EPWM_IsActiveFlag_InputSYNC
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_InputSYNC(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBSR, EPWM_TBSR_SYNCIF_Msk) == (EPWM_TBSR_SYNCIF_Msk));
}

/**
  * @brief    清除输入同步标志
  * @rmtoll   TBSR    SYNCIF    FL_EPWM_ClearFlag_InputSYNC
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_InputSYNC(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->TBSR, EPWM_TBSR_SYNCIF_Msk);
}

/**
  * @brief    获取定时器计数方向
  * @rmtoll   TBSR    CNTDIR    FL_EPWM_GetCounterDirection
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_COUNTER_DIR_UP
  *           @arg @ref FL_EPWM_COUNTER_DIR_DOWN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetCounterDirection(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->TBSR, EPWM_TBSR_CNTDIR_Msk));
}

/**
  * @brief    设置SYNCOUT源
  * @rmtoll   SYNC    SWSYNCOEN    FL_EPWM_SetSYNCOUTSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_SWSYNC
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_0
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_PRD
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPA
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPB
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPC
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPD
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_DCAEVT1
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_DCBEVT1
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetSYNCOUTSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->SYNC, EPWM_SYNC_SWSYNCOEN_Msk, source);
}

/**
  * @brief    设置SYNCOUT源
  * @rmtoll   SYNC    SWSYNCOEN    FL_EPWM_GetSYNCOUTSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_SWSYNC
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_0
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_PRD
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPA
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPB
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPC
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_CNT_CMPD
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_DCAEVT1
  *           @arg @ref FL_EPWM_SYNCOUT_SRC_DCBEVT1
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSYNCOUTSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->SYNC, EPWM_SYNC_SWSYNCOEN_Msk));
}

/**
  * @brief    设置EPWM同步信号输入
  * @rmtoll   SYNC    SYNCINSEL    FL_EPWM_SetSYNCInputSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_NONE
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM0_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM1_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM2_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM3_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_ATIM0
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_ATIM1
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_GPTIM0
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_GPTIM1
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_GPTIM2
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetSYNCInputSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->SYNC, EPWM_SYNC_SYNCINSEL_Msk, source);
}

/**
  * @brief    读取EPWM同步信号输入
  * @rmtoll   SYNC    SYNCINSEL    FL_EPWM_GetSYNCInputSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_NONE
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM0_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM1_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM2_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_EPWM3_SYNCOUT
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_ATIM0
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_ATIM1
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_GPTIM0
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_GPTIM1
  *           @arg @ref FL_EPWM_SYNC_IN_SEL_GPTIM2
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSYNCInputSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->SYNC, EPWM_SYNC_SYNCINSEL_Msk));
}

/**
  * @brief    使能软件SYNC事件
  * @rmtoll   SWACT    SWSYNC    FL_EPWM_EnableSoftwareSYNC
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableSoftwareSYNC(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->SWACT, EPWM_SWACT_SWSYNC_Msk);
}

/**
  * @brief    设置EPWMA的比较值
  * @rmtoll   CMPA    CMPA    FL_EPWM_WriteCompareA
  * @param    EPWMx EPWM instance
  * @param    compare
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteCompareA(EPWM_Type *EPWMx, uint32_t compare)
{
    MODIFY_REG(EPWMx->CMPA, (0xffffU << 0U), (compare << 0U));
}

/**
  * @brief    读取EPWMA的比较值
  * @rmtoll   CMPA    CMPA    FL_EPWM_ReadCompareA
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadCompareA(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CMPA, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置EPWMB的比较值
  * @rmtoll   CMPB    CMPB    FL_EPWM_WriteCompareB
  * @param    EPWMx EPWM instance
  * @param    compare
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteCompareB(EPWM_Type *EPWMx, uint32_t compare)
{
    MODIFY_REG(EPWMx->CMPB, (0xffffU << 0U), (compare << 0U));
}

/**
  * @brief    读取EPWMB的比较值
  * @rmtoll   CMPB    CMPB    FL_EPWM_ReadCompareB
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadCompareB(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CMPB, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置EPWMC的比较值
  * @rmtoll   CMPC    CMPC    FL_EPWM_WriteCompareC
  * @param    EPWMx EPWM instance
  * @param    compare
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteCompareC(EPWM_Type *EPWMx, uint32_t compare)
{
    MODIFY_REG(EPWMx->CMPC, (0xffffU << 0U), (compare << 0U));
}

/**
  * @brief    读取EPWMC的比较值
  * @rmtoll   CMPC    CMPC    FL_EPWM_ReadCompareC
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadCompareC(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CMPC, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    设置EPWMD的比较值
  * @rmtoll   CMPD    CMPD    FL_EPWM_WriteCompareD
  * @param    EPWMx EPWM instance
  * @param    compare
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteCompareD(EPWM_Type *EPWMx, uint32_t compare)
{
    MODIFY_REG(EPWMx->CMPD, (0xffffU << 0U), (compare << 0U));
}

/**
  * @brief    读取EPWMD的比较值
  * @rmtoll   CMPD    CMPD    FL_EPWM_ReadCompareD
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadCompareD(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CMPD, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    使能比较通道D的预装载功能
  * @rmtoll   CCR    CMPDSHEN    FL_EPWM_EnableCompareDPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableCompareDPreload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->CCR, EPWM_CCR_CMPDSHEN_Msk);
}

/**
  * @brief    读取比较通道D的预装载使能状态
  * @rmtoll   CCR    CMPDSHEN    FL_EPWM_IsEnabledCompareDPreload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledCompareDPreload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_CMPDSHEN_Msk) == EPWM_CCR_CMPDSHEN_Msk);
}

/**
  * @brief    失能比较通道D的预装载功能
  * @rmtoll   CCR    CMPDSHEN    FL_EPWM_DisableCompareDPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableCompareDPreload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->CCR, EPWM_CCR_CMPDSHEN_Msk);
}

/**
  * @brief    使能比较通道C的预装载功能
  * @rmtoll   CCR    CMPCSHEN    FL_EPWM_EnableCompareCPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableCompareCPreload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->CCR, EPWM_CCR_CMPCSHEN_Msk);
}

/**
  * @brief    读取比较通道C的预装载使能状态
  * @rmtoll   CCR    CMPCSHEN    FL_EPWM_IsEnabledCompareCPreload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledCompareCPreload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_CMPCSHEN_Msk) == EPWM_CCR_CMPCSHEN_Msk);
}

/**
  * @brief    失能比较通道C的预装载功能
  * @rmtoll   CCR    CMPCSHEN    FL_EPWM_DisableCompareCPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableCompareCPreload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->CCR, EPWM_CCR_CMPCSHEN_Msk);
}

/**
  * @brief    设置比较通道D的预装载触发
  * @rmtoll   CCR    LDCMPD    FL_EPWM_SetCompareDPreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    trigger This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CMPD_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPD_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPD_LOAD_SYNC_RISING
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetCompareDPreloadTrigger(EPWM_Type *EPWMx, uint32_t trigger)
{
    MODIFY_REG(EPWMx->CCR, EPWM_CCR_LDCMPD_Msk, trigger);
}

/**
  * @brief    获取比较通道D的预装载触发源
  * @rmtoll   CCR    LDCMPD    FL_EPWM_GetCompareDPreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    trigger This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CMPD_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPD_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPD_LOAD_SYNC_RISING
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_CMPD_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPD_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPD_LOAD_SYNC_RISING
  */
__STATIC_INLINE uint32_t FL_EPWM_GetCompareDPreloadTrigger(EPWM_Type *EPWMx, uint32_t trigger)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_LDCMPD_Msk));
}

/**
  * @brief    设置比较通道C的预装载触发
  * @rmtoll   CCR    LDCMPC    FL_EPWM_SetCompareCPreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    trigger This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CMPC_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPC_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPC_LOAD_SYNC_RISING
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetCompareCPreloadTrigger(EPWM_Type *EPWMx, uint32_t trigger)
{
    MODIFY_REG(EPWMx->CCR, EPWM_CCR_LDCMPC_Msk, trigger);
}

/**
  * @brief    获取比较通道C的预装载触发源
  * @rmtoll   CCR    LDCMPC    FL_EPWM_GetCompareCPreloadTrigger
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_CMPC_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPC_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPC_LOAD_SYNC_RISING
  */
__STATIC_INLINE uint32_t FL_EPWM_GetCompareCPreloadTrigger(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_LDCMPC_Msk));
}

/**
  * @brief    使能比较通道B的预装载功能
  * @rmtoll   CCR    CMPBSHEN    FL_EPWM_EnableCompareBPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableCompareBPreload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->CCR, EPWM_CCR_CMPBSHEN_Msk);
}

/**
  * @brief    读取比较通道B的预装载使能状态
  * @rmtoll   CCR    CMPBSHEN    FL_EPWM_IsEnabledCompareBPreload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledCompareBPreload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_CMPBSHEN_Msk) == EPWM_CCR_CMPBSHEN_Msk);
}

/**
  * @brief    失能比较通道B的预装载功能
  * @rmtoll   CCR    CMPBSHEN    FL_EPWM_DisableCompareBPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableCompareBPreload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->CCR, EPWM_CCR_CMPBSHEN_Msk);
}

/**
  * @brief    使能比较通道A的预装载功能
  * @rmtoll   CCR    CMPASHEN    FL_EPWM_EnableCompareAPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableCompareAPreload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->CCR, EPWM_CCR_CMPASHEN_Msk);
}

/**
  * @brief    读取比较通道A的预装载使能状态
  * @rmtoll   CCR    CMPASHEN    FL_EPWM_IsEnabledCompareAPreload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledCompareAPreload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_CMPASHEN_Msk) == EPWM_CCR_CMPASHEN_Msk);
}

/**
  * @brief    失能比较通道A的预装载功能
  * @rmtoll   CCR    CMPASHEN    FL_EPWM_DisableCompareAPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableCompareAPreload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->CCR, EPWM_CCR_CMPASHEN_Msk);
}

/**
  * @brief    设置比较通道B的预装载触发
  * @rmtoll   CCR    LDCMPB    FL_EPWM_SetCompareBPreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    trigger This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CMPB_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPB_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPB_LOAD_SYNC_RISING
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetCompareBPreloadTrigger(EPWM_Type *EPWMx, uint32_t trigger)
{
    MODIFY_REG(EPWMx->CCR, EPWM_CCR_LDCMPB_Msk, trigger);
}

/**
  * @brief    获取比较通道B的预装载触发源
  * @rmtoll   CCR    LDCMPB    FL_EPWM_GetCompareBPreloadTrigger
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_CMPB_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPB_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPB_LOAD_SYNC_RISING
  */
__STATIC_INLINE uint32_t FL_EPWM_GetCompareBPreloadTrigger(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_LDCMPB_Msk));
}

/**
  * @brief    设置比较通道A的预装载触发
  * @rmtoll   CCR    LDCMPA    FL_EPWM_SetCompareAPreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    trigger This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CMPA_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPA_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPA_LOAD_SYNC_RISING
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetCompareAPreloadTrigger(EPWM_Type *EPWMx, uint32_t trigger)
{
    MODIFY_REG(EPWMx->CCR, EPWM_CCR_LDCMPA_Msk, trigger);
}

/**
  * @brief    获取比较通道A的预装载触发源
  * @rmtoll   CCR    LDCMPA    FL_EPWM_GetCompareAPreloadTrigger
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_CMPA_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CMPA_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_CMPA_LOAD_SYNC_RISING
  */
__STATIC_INLINE uint32_t FL_EPWM_GetCompareAPreloadTrigger(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CCR, EPWM_CCR_LDCMPA_Msk));
}

/**
  * @brief    使能输出通道的预装载功能
  * @rmtoll   OACR    OACRSHEN    FL_EPWM_OC_EnablePreload
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_OC_EnablePreload(EPWM_Type *EPWMx, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    {
        SET_BIT(EPWMx->OACR, EPWM_OACR_OACRSHEN_Msk);
    }
    else if(channel == FL_EPWM_CHANNEL_B)
    {
        SET_BIT(EPWMx->OBCR, EPWM_OACR_OACRSHEN_Msk);
    }

}

/**
  * @brief    读取输出的预装载使能状态
  * @rmtoll   OACR    OACRSHEN    FL_EPWM_OC_IsEnabledPreload
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_OC_IsEnabledPreload(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t status;
    if(channel == FL_EPWM_CHANNEL_A)
    { status = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_OACRSHEN_Msk) == EPWM_OACR_OACRSHEN_Msk); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { status = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_OACRSHEN_Msk) == EPWM_OACR_OACRSHEN_Msk); }
    return status;
}

/**
  * @brief    失能输出的预装载功能
  * @rmtoll   OACR    OACRSHEN    FL_EPWM_OC_DisablePreload
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_OC_DisablePreload(EPWM_Type *EPWMx, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { CLEAR_BIT(EPWMx->OACR, EPWM_OACR_OACRSHEN_Msk); }
    if(channel == FL_EPWM_CHANNEL_B)
    { CLEAR_BIT(EPWMx->OBCR, EPWM_OACR_OACRSHEN_Msk); }
}

/**
  * @brief    设置比较通道的预装载触发
  * @rmtoll   OACR    LDOA    FL_EPWM_OC_SetpreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    trigger This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OC_LOAD_CNT_0
  *           @arg @ref FL_EPWM_OC_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_OC_LOAD_SYNC_RISING
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_OC_SetpreloadTrigger(EPWM_Type *EPWMx, uint32_t trigger, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_LDOA_Msk, trigger << EPWM_OACR_LDOA_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_LDOA_Msk, trigger << EPWM_OACR_LDOA_Pos); }
}

/**
  * @brief    获取比较通道的预装载触发源
  * @rmtoll   OACR    LDOA    FL_EPWM_OC_GetpreloadTrigger
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OC_LOAD_CNT_0
  *           @arg @ref FL_EPWM_OC_LOAD_CNT_PRD
  *           @arg @ref FL_EPWM_OC_LOAD_SYNC_RISING
  */
__STATIC_INLINE uint32_t FL_EPWM_OC_GetpreloadTrigger(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t trigger;
    if(channel == FL_EPWM_CHANNEL_A)
    { trigger = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_LDOA_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { trigger = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_LDOA_Msk)); }
    return trigger;
}

/**
  * @brief    设置向下计数时CNT=CMPB时的EPWM输出动作
  * @rmtoll   OACR    CBD    FL_EPWM_SetOCMode_CNTEqualCMPB_DirDown
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OC_MODE_FROZEN
  *           @arg @ref FL_EPWM_OC_MODE_LOW
  *           @arg @ref FL_EPWM_OC_MODE_HIGH
  *           @arg @ref FL_EPWM_OC_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_CNTEqualCMPB_DirDown(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_CBD_Msk, mode << EPWM_OACR_CBD_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_CBD_Msk, mode << EPWM_OACR_CBD_Pos); }
}

/**
  * @brief    获取向下计数时CNT=CMPB时的EPWM输出动作
  * @rmtoll   OACR    CBD    FL_EPWM_GetOCMode_CNTEqualsCMPB_DirDown
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_CNTEqualCMPB_DirDown(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t mode;
    if(channel == FL_EPWM_CHANNEL_A)
    { mode = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_CBD_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { mode = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_CBD_Msk)); }
    return mode;

}

/**
  * @brief    设置向上计数时CNT=CMPB时的EPWM输出动作
  * @rmtoll   OACR    CBU    FL_EPWM_SetOCMode_CNTEqualsCMPB_DirUp
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_CNTEqualCMPB_DirUp(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_CBU_Msk, mode << EPWM_OACR_CBU_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_CBU_Msk, mode << EPWM_OACR_CBU_Pos); }
}

/**
  * @brief    获取向上计数时CNT=CMPB时的EPWM输出动作
  * @rmtoll   OACR    CBU    FL_EPWM_GetOCMode_CNTEqualsCMPB_DirUp
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_CNTEqualCMPB_DirUp(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t mode;
    if(channel == FL_EPWM_CHANNEL_A)
    { mode = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_CBU_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { mode = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_CBU_Msk)); }
    return mode;
}

/**
  * @brief    设置向下计数时CNT=CMPA时的EPWM输出动作
  * @rmtoll   OACR    CAD    FL_EPWM_SetOCMode_CNTEqualsCMPA_DirDown
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_CNTEqualCMPA_DirDown(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_CAD_Msk, mode << EPWM_OACR_CAD_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_CAD_Msk, mode << EPWM_OACR_CAD_Pos); }
}

/**
  * @brief    获取向下计数时CNT=CMPA时的EPWM输出动作
  * @rmtoll   OACR    CAD    FL_EPWM_GetOCMode_CNTEqualsCMPA_DirDown
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_CNTEqualCMPA_DirDown(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t mode;
    if(channel == FL_EPWM_CHANNEL_A)
    { mode = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_CAD_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { mode = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_CAD_Msk)); }
    return mode;
}

/**
  * @brief    设置向上计数时CNT=CMPA时的EPWM输出动作
  * @rmtoll   OACR    CAU    FL_EPWM_SetOCMode_CNTEqualsCMPA_DirUp
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_CNTEqualCMPA_DirUp(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_CAU_Msk, mode << EPWM_OACR_CAU_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_CAU_Msk, mode << EPWM_OACR_CAU_Pos); }
}

/**
  * @brief    获取向上计数时CNT=CMPA时的EPWM输出动作
  * @rmtoll   OACR    CAU    FL_EPWM_GetOCMode_CNTEqualsCMPA_DirUp
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_CNTEqualCMPA_DirUp(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t mode;
    if(channel == FL_EPWM_CHANNEL_A)
    { mode = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_CAU_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { mode = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_CAU_Msk)); }
    return mode;
}

/**
  * @brief    设置CNT=PRD时的EPWM输出动作
  * @rmtoll   OACR    PRD    FL_EPWM_SetOCMode_CNTEqualsPRD
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_CNTEqualPRD(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_PRD_Msk, mode << EPWM_OACR_PRD_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_PRD_Msk, mode << EPWM_OACR_PRD_Pos); }
}

/**
  * @brief    获取CNT=PRD时的EPWM输出动作
  * @rmtoll   OACR    PRD    FL_EPWM_GetOCMode_CNTEqualsPRD
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_CNTEqualPRD(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t mode;
    if(channel == FL_EPWM_CHANNEL_A)
    { mode = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_PRD_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { mode = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_PRD_Msk)); }
    return mode;
}

/**
  * @brief    设置CNT=0时的EPWM输出动作
  * @rmtoll   OACR    ZRO    FL_EPWM_SetOCMode_CNTEqualsZero
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_CNTEqualZero(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    if(channel == FL_EPWM_CHANNEL_A)
    { MODIFY_REG(EPWMx->OACR, EPWM_OACR_ZRO_Msk, mode << EPWM_OACR_ZRO_Pos); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { MODIFY_REG(EPWMx->OBCR, EPWM_OACR_ZRO_Msk, mode << EPWM_OACR_ZRO_Pos); }
}

/**
  * @brief    获取CNT=0时的EPWM输出动作
  * @rmtoll   OACR    ZRO    FL_EPWM_GetOCMode_CNTEqualsZero
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_CNTEqualZero(EPWM_Type *EPWMx, uint32_t channel)
{
    uint32_t mode;
    if(channel == FL_EPWM_CHANNEL_A)
    { mode = (uint32_t)(READ_BIT(EPWMx->OACR, EPWM_OACR_ZRO_Msk)); }
    else if(channel == FL_EPWM_CHANNEL_B)
    { mode = (uint32_t)(READ_BIT(EPWMx->OBCR, EPWM_OACR_ZRO_Msk)); }
    return mode;
}

/**
  * @brief    设置CSF装载模式
  * @rmtoll   SFCR    LDSFR    FL_EPWM_SetContinuousSoftwareForceLoadMode
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CSF_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CSF_LOAD_CNT_ARR
  *           @arg @ref FL_EPWM_CSF_LOAD_CNT_0_ARR
  *           @arg @ref FL_EPWM_CSF_LOAD_SOFTWARE
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetContinuousSoftwareForceLoadMode(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->SFCR, EPWM_SFCR_LDSFR_Msk, mode);
}

/**
  * @brief    读取CSF装载模式
  * @rmtoll   SFCR    LDSFR    FL_EPWM_GetContinuousSoftwareForceLoadMode
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_CSF_LOAD_CNT_0
  *           @arg @ref FL_EPWM_CSF_LOAD_CNT_ARR
  *           @arg @ref FL_EPWM_CSF_LOAD_CNT_0_ARR
  *           @arg @ref FL_EPWM_CSF_LOAD_SOFTWARE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetContinuousSoftwareForceLoadMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->SFCR, EPWM_SFCR_LDSFR_Msk));
}

/**
  * @brief    设置软件触发EPWM输出动作
  * @rmtoll   SFCR    ACTOTSFA    FL_EPWM_SetOCMode_SoftwareSingleForce
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetOCMode_SoftwareSingleForce(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    MODIFY_REG(EPWMx->SFCR, mode, EPWM_SFCR_ACTOTSFA_Msk << channel);
}

/**
  * @brief    获取软件触发EPWM输出动作
  * @rmtoll   SFCR    ACTOTSFA    FL_EPWM_GetOCMode_SoftwareSingleForce
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OA_MODE_FROZEN
  *           @arg @ref FL_EPWM_OA_MODE_LOW
  *           @arg @ref FL_EPWM_OA_MODE_HIGH
  *           @arg @ref FL_EPWM_OA_MODE_TOGGLE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetOCMode_SoftwareSingleForce(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->SFCR, EPWM_SFCR_ACTOTSFA_Msk << channel));
}

/**
  * @brief    设置软件触发EPWMB输出
  * @rmtoll   SFR    OTSFB    FL_EPWM_EnableOutputBSoftwareSingleForce
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableOutputBSoftwareSingleForce(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->SFR, EPWM_SFR_OTSFB_Msk);
}

/**
  * @brief    设置软件触发EPWMA输出
  * @rmtoll   SFR    OTSFA    FL_EPWM_EnableOutputASoftwareSingleForce
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableOutputASoftwareSingleForce(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->SFR, EPWM_SFR_OTSFA_Msk);
}

/**
  * @brief    设置软件触发模式
  * @rmtoll   SFR    CSFA    FL_EPWM_SetSoftwareSingleForceMode
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CSF_MODE_FROZEN
  *           @arg @ref FL_EPWM_CSF_MODE_CONTINUE_LOW
  *           @arg @ref FL_EPWM_CSF_MODE_CONTINUE_HIGH
  *           @arg @ref FL_EPWM_CSF_MODE_FROZEN
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetSoftwareSingleForceMode(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    MODIFY_REG(EPWMx->SFR, mode, EPWM_SFR_CSFA_Msk << channel);
}

/**
  * @brief    获取软件触发模式
  * @rmtoll   SFR    CSFA    FL_EPWM_GetSoftwareSingleForceMode
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_CSF_MODE_FROZEN
  *           @arg @ref FL_EPWM_CSF_MODE_CONTINUE_LOW
  *           @arg @ref FL_EPWM_CSF_MODE_CONTINUE_HIGH
  *           @arg @ref FL_EPWM_CSF_MODE_FROZEN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSoftwareSingleForceMode(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->SFR, EPWM_SFR_CSFA_Msk << channel));
}

/**
  * @brief    设置死区下降沿延迟信号输入源
  * @rmtoll   DTCR    FEDSEL    FL_EPWM _SetDeadbandFallingDelaySignalSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DEADBAND_FALLING_EPWMB
  *           @arg @ref FL_EPWM_DEADBAND_FALLING_EPWMA
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDeadbandFallingDelaySignalSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DTCR, EPWM_DTCR_FEDSEL_Msk, source);
}

/**
  * @brief    获取死区下降沿延迟信号输入源
  * @rmtoll   DTCR    FEDSEL    FL_EPWM _GetDeadbandFallingDelaySignalSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DEADBAND_FALLING_EPWMB
  *           @arg @ref FL_EPWM_DEADBAND_FALLING_EPWMA
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDeadbandFallingDelaySignalSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DTCR, EPWM_DTCR_FEDSEL_Msk));
}

/**
  * @brief    设置死区上升沿延迟信号输入源
  * @rmtoll   DTCR    REDSEL    FL_EPWM _SetDeadbandRisingDelaySignalSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DEADBAND_RISING_EPWMB
  *           @arg @ref FL_EPWM_DEADBAND_RISING_EPWMA
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDeadbandRisingDelaySignalSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DTCR, EPWM_DTCR_REDSEL_Msk, source);
}

/**
  * @brief    获取死区上升沿延迟信号输入源
  * @rmtoll   DTCR    REDSEL    FL_EPWM _GetDeadbandRisingDelaySignalSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DEADBAND_RISING_EPWMB
  *           @arg @ref FL_EPWM_DEADBAND_RISING_EPWMA
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDeadbandRisingDelaySignalSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DTCR, EPWM_DTCR_REDSEL_Msk));
}

/**
  * @brief    设置死区输出极性
  * @rmtoll   DTCR    POLSELA    FL_EPWM _SetDeadbandOutputPolarity
  * @param    EPWMx EPWM instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DEADBAND_PORLARITY_NORMAL
  *           @arg @ref FL_EPWM_DEADBAND_PORLARITY_REVERSE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDeadbandOutputPolarity(EPWM_Type *EPWMx, uint32_t polarity, uint32_t channel)
{
    MODIFY_REG(EPWMx->DTCR, polarity, EPWM_DTCR_POLSELA_Msk << channel);
}

/**
  * @brief    读取死区输出极性
  * @rmtoll   DTCR    POLSELA    FL_EPWM _GetDeadbandOutputPolarity
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DEADBAND_PORLARITY_NORMAL
  *           @arg @ref FL_EPWM_DEADBAND_PORLARITY_REVERSE
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDeadbandOutputPolarity(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DTCR, EPWM_DTCR_POLSELA_Msk << channel));
}

/**
  * @brief    使能死区Bypass
  * @rmtoll   DTCR    BYPASSA    FL_EPWM_EnableDeadbandBypass
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableDeadbandBypass(EPWM_Type *EPWMx, uint32_t channel)
{
    SET_BIT(EPWMx->DTCR, EPWM_DTCR_BYPASSA_Msk << channel);
}

/**
  * @brief    读取死区Bypass使能状态
  * @rmtoll   DTCR    BYPASSA    FL_EPWM_IsEnabledDeadbandBypass
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledDeadbandBypass(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DTCR, EPWM_DTCR_BYPASSA_Msk << channel) == EPWM_DTCR_BYPASSA_Msk << channel);
}

/**
  * @brief    失能死区Bypass
  * @rmtoll   DTCR    BYPASSA    FL_EPWM_DisableDeadbandBypass
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableDeadbandBypass(EPWM_Type *EPWMx, uint32_t channel)
{
    CLEAR_BIT(EPWMx->DTCR, EPWM_DTCR_BYPASSA_Msk << channel);
}

/**
  * @brief    设置死区上升沿延迟时间
  * @rmtoll   DTDLY    RED    FL_EPWM_WriteDeadbandRisingDelayTime
  * @param    EPWMx EPWM instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteDeadbandRisingDelayTime(EPWM_Type *EPWMx, uint32_t time)
{
    MODIFY_REG(EPWMx->DTDLY, (0x3ffU << 16U), (time << 16U));
}

/**
  * @brief    读取死区上升沿延迟时间
  * @rmtoll   DTDLY    RED    FL_EPWM_ReadDeadbandRisingDelayTime
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadDeadbandRisingDelayTime(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DTDLY, (0x3ffU << 16U)) >> 16U);
}

/**
  * @brief    设置死区下降沿延迟时间
  * @rmtoll   DTDLY    FED    FL_EPWM_WriteDeadbandFallingDelayTime
  * @param    EPWMx EPWM instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteDeadbandFallingDelayTime(EPWM_Type *EPWMx, uint32_t time)
{
    MODIFY_REG(EPWMx->DTDLY, (0x3ffU << 0U), (time << 0U));
}

/**
  * @brief    读取死区下降沿延迟时间
  * @rmtoll   DTDLY    FED    FL_EPWM_ReadDeadbandFallingDelayTime
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadDeadbandFallingDelayTime(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DTDLY, (0x3ffU << 0U)) >> 0U);
}

/**
  * @brief    设置Chopper载波高电平宽度
  * @rmtoll   CPCR    CHPHW    FL_EPWM_WriteChopperCarrierHighWidth
  * @param    EPWMx EPWM instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteChopperCarrierHighWidth(EPWM_Type *EPWMx, uint32_t width)
{
    MODIFY_REG(EPWMx->CPCR, (0x3fU << 16U), (width << 16U));
}

/**
  * @brief    读取Chopper载波高电平宽度
  * @rmtoll   CPCR    CHPHW    FL_EPWM_ReadChopperCarrierHighWidth
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadChopperCarrierHighWidth(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CPCR, (0x3fU << 16U)) >> 16U);
}

/**
  * @brief    设置Chopper载波低电平宽度
  * @rmtoll   CPCR    CHPLW    FL_EPWM_WriteChopperCarrierLowWidth
  * @param    EPWMx EPWM instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteChopperCarrierLowWidth(EPWM_Type *EPWMx, uint32_t width)
{
    MODIFY_REG(EPWMx->CPCR, (0x3fU << 8U), (width << 8U));
}

/**
  * @brief    读取Chopper载波低电平宽度
  * @rmtoll   CPCR    CHPLW    FL_EPWM_ReadChopperCarrierLowWidth
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadChopperCarrierLowWidth(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CPCR, (0x3fU << 8U)) >> 8U);
}

/**
  * @brief    设置单脉冲宽度
  * @rmtoll   CPCR    OSPW    FL_EPWM_WriteOneShotPulseWidth
  * @param    EPWMx EPWM instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteOneShotPulseWidth(EPWM_Type *EPWMx, uint32_t width)
{
    MODIFY_REG(EPWMx->CPCR, (0xfU << 4U), ((width & 0xfU) << 4U));
}

/**
  * @brief    读取单脉冲宽度
  * @rmtoll   CPCR    OSPW    FL_EPWM_ReadOneShotPulseWidth
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadOneShotPulseWidth(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CPCR, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    使能单脉冲
  * @rmtoll   CPCR    OSPEN    FL_EPWM_EnableOneShotPulse
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableOneShotPulse(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->CPCR, EPWM_CPCR_OSPEN_Msk);
}

/**
  * @brief    读取单脉冲使能状态
  * @rmtoll   CPCR    OSPEN    FL_EPWM_IsEnabledOneShotPulse
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledOneShotPulse(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CPCR, EPWM_CPCR_OSPEN_Msk) == EPWM_CPCR_OSPEN_Msk);
}

/**
  * @brief    失能单脉冲
  * @rmtoll   CPCR    OSPEN    FL_EPWM_DisableOneShotPulse
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableOneShotPulse(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->CPCR, EPWM_CPCR_OSPEN_Msk);
}

/**
  * @brief    使能Chopper
  * @rmtoll   CPCR    CHPENA    FL_EPWM_EnableChopper
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableChopper(EPWM_Type *EPWMx, uint32_t channel)
{
    SET_BIT(EPWMx->CPCR, EPWM_CPCR_CHPENA_Msk << channel);
}

/**
  * @brief    读取Chopper使能状态
  * @rmtoll   CPCR    CHPENA    FL_EPWM_IsEnabledChopper
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledChopper(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->CPCR, EPWM_CPCR_CHPENA_Msk << channel) == EPWM_CPCR_CHPENA_Msk << channel);
}

/**
  * @brief    失能Chopper
  * @rmtoll   CPCR    CHPENA    FL_EPWM_DisableChopper
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableChopper(EPWM_Type *EPWMx, uint32_t channel)
{
    CLEAR_BIT(EPWMx->CPCR, EPWM_CPCR_CHPENA_Msk << channel);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT2_TZEN    FL_EPWM_BK_EnableDigitalCompareOutputBEvent2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputBEvent2(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT2_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT2_TZEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT2_TZEN_Msk) == EPWM_BKCFR_DCBEVT2_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT2_TZEN    FL_EPWM_BK_DisableDigitalCompareOutputBEvent2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputBEvent2(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT2_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT1_TZEN    FL_EPWM_BK_EnableDigitalCompareOutputBEvent1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputBEvent1(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT1_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT1_TZEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT1_TZEN_Msk) == EPWM_BKCFR_DCBEVT1_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT1_TZEN    FL_EPWM_BK_DisableDigitalCompareOutputBEvent1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputBEvent1(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT1_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT2_TZEN    FL_EPWM_BK_EnableDigitalCompareOutputAEvent2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputAEvent2(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT2_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT2_TZEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT2_TZEN_Msk) == EPWM_BKCFR_DCAEVT2_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT2_TZEN    FL_EPWM_BK_DisableDigitalCompareOutputAEvent2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputAEvent2(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT2_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT1_TZEN    FL_EPWM_BK_EnableDigitalCompareOutputAEvent1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputAEvent1(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT1_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT1_TZEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT1_TZEN_Msk) == EPWM_BKCFR_DCAEVT1_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT1_TZEN    FL_EPWM_BK_DisableDigitalCompareOutputAEvent1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputAEvent1(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT1_TZEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT1_OSTEN    FL_EPWM_BK_EnableDigitalCompareOutputBEvent1_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputBEvent1_OneShot(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT1_OSTEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT1_OSTEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent1_OneShot
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent1_OneShot(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT1_OSTEN_Msk) == EPWM_BKCFR_DCBEVT1_OSTEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT1_OSTEN    FL_EPWM_BK_DisableDigitalCompareOutputBEvent1_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputBEvent1_OneShot(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT1_OSTEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT1_OSTEN    FL_EPWM_BK_EnableDigitalCompareOutputAEvent1_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputAEvent1_OneShot(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT1_OSTEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT1_OSTEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent1_OneShot
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent1_OneShot(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT1_OSTEN_Msk) == EPWM_BKCFR_DCAEVT1_OSTEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT1_OSTEN    FL_EPWM_BK_DisableDigitalCompareOutputAEvent1_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputAEvent1_OneShot(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT1_OSTEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    OSTEN    FL_EPWM_BK_EnableOneShotMode
  * @param    EPWMx EPWM instance
  * @param    breakchannel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_BKCHANNEL_1
  *           @arg @ref FL_EPWM_BKCHANNEL_2
  *           @arg @ref FL_EPWM_BKCHANNEL_3
  *           @arg @ref FL_EPWM_BKCHANNEL_4
  *           @arg @ref FL_EPWM_BKCHANNEL_5
  *           @arg @ref FL_EPWM_BKCHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableOneShotMode(EPWM_Type *EPWMx, uint32_t breakchannel)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_OSTEN_Msk << breakchannel);
}

/**
  * @brief
  * @rmtoll   BKCFR    OSTEN    FL_EPWM_BK_IsEnabledOneShotMode
  * @param    EPWMx EPWM instance
  * @param    breakchannel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_BKCHANNEL_1
  *           @arg @ref FL_EPWM_BKCHANNEL_2
  *           @arg @ref FL_EPWM_BKCHANNEL_3
  *           @arg @ref FL_EPWM_BKCHANNEL_4
  *           @arg @ref FL_EPWM_BKCHANNEL_5
  *           @arg @ref FL_EPWM_BKCHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledOneShotMode(EPWM_Type *EPWMx, uint32_t breakchannel)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_OSTEN_Msk << breakchannel) == EPWM_BKCFR_OSTEN_Msk << breakchannel);
}

/**
  * @brief
  * @rmtoll   BKCFR    OSTEN    FL_EPWM_BK_DisableOneShotMode
  * @param    EPWMx EPWM instance
  * @param    breakchannel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_BKCHANNEL_1
  *           @arg @ref FL_EPWM_BKCHANNEL_2
  *           @arg @ref FL_EPWM_BKCHANNEL_3
  *           @arg @ref FL_EPWM_BKCHANNEL_4
  *           @arg @ref FL_EPWM_BKCHANNEL_5
  *           @arg @ref FL_EPWM_BKCHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableOneShotMode(EPWM_Type *EPWMx, uint32_t breakchannel)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_OSTEN_Msk << breakchannel);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT2_CBCEN    FL_EPWM_BK_EnableDigitalCompareOutputBEvent2_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputBEvent2_CycleByCycle(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT2_CBCEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT2_CBCEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent2_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputBEvent2_CycleByCycle(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT2_CBCEN_Msk) == EPWM_BKCFR_DCBEVT2_CBCEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCBEVT2_CBCEN    FL_EPWM_BK_DisableDigitalCompareOutputBEvent2_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputBEvent2_CycleByCycle(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCBEVT2_CBCEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT2_CBCEN    FL_EPWM_BK_EnableDigitalCompareOutputAEvent1_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableDigitalCompareOutputAEvent1_CycleByCycle(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT2_CBCEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT2_CBCEN    FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent2_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledDigitalCompareOutputAEvent2_CycleByCycle(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT2_CBCEN_Msk) == EPWM_BKCFR_DCAEVT2_CBCEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    DCAEVT2_CBCEN    FL_EPWM_BK_DisableDigitalCompareOutputAEvent2_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableDigitalCompareOutputAEvent2_CycleByCycle(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_DCAEVT2_CBCEN_Msk);
}

/**
  * @brief
  * @rmtoll   BKCFR    CBCEN    FL_EPWM_BK_EnableCycleByCycleMode
  * @param    EPWMx EPWM instance
  * @param    breakchannel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_EnableCycleByCycleMode(EPWM_Type *EPWMx, uint32_t breakchannel)
{
    SET_BIT(EPWMx->BKCFR, EPWM_BKCFR_CBCEN_Msk << breakchannel);
}

/**
  * @brief
  * @rmtoll   BKCFR    CBCEN    FL_EPWM_BK_IsEnabledCycleByCycleMode
  * @param    EPWMx EPWM instance
  * @param    breakchannel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_IsEnabledCycleByCycleMode(EPWM_Type *EPWMx, uint32_t breakchannel)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCFR, EPWM_BKCFR_CBCEN_Msk << breakchannel) == EPWM_BKCFR_CBCEN_Msk << breakchannel);
}

/**
  * @brief
  * @rmtoll   BKCFR    CBCEN    FL_EPWM_BK_DisableCycleByCycleMode
  * @param    EPWMx EPWM instance
  * @param    breakchannel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_DisableCycleByCycleMode(EPWM_Type *EPWMx, uint32_t breakchannel)
{
    CLEAR_BIT(EPWMx->BKCFR, EPWM_BKCFR_CBCEN_Msk << breakchannel);
}

/**
  * @brief
  * @rmtoll   BKCR    DCBEVT2    FL_EPWM_BK_SetOutputBmode_DCBEVT2
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_SetOutputBmode_DCBEVT2(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->BKCR, EPWM_BKCR_DCBEVT2_Msk, mode << EPWM_BKCR_DCBEVT2_Pos);
}

/**
  * @brief
  * @rmtoll   BKCR    DCBEVT2    FL_EPWM_BK_GetOutputBmode_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_GetOutputBmode_DCBEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCR, EPWM_BKCR_DCBEVT2_Msk));
}

/**
  * @brief
  * @rmtoll   BKCR    DCBEVT1    FL_EPWM_BK_SetOutputBmode_DCBEVT1
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_SetOutputBmode_DCBEVT1(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->BKCR, EPWM_BKCR_DCBEVT1_Msk, mode << EPWM_BKCR_DCBEVT1_Pos);
}

/**
  * @brief
  * @rmtoll   BKCR    DCBEVT1    FL_EPWM_BK_GetOutputBmode_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_GetOutputBmode_DCBEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCR, EPWM_BKCR_DCBEVT1_Msk));
}

/**
  * @brief
  * @rmtoll   BKCR    DCAEVT2    FL_EPWM_BK_SetOutputBmode_DCBEVT2
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_SetOutputBmode_DCAEVT2(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->BKCR, EPWM_BKCR_DCAEVT2_Msk, mode << EPWM_BKCR_DCAEVT2_Pos);
}

/**
  * @brief
  * @rmtoll   BKCR    DCAEVT2    FL_EPWM_BK_GetOutputBmode_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_GetOutputBmode_DCAEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCR, EPWM_BKCR_DCAEVT2_Msk));
}

/**
  * @brief
  * @rmtoll   BKCR    DCAEVT1    FL_EPWM_BK_SetOutputBmode_DCBEVT1
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_SetOutputBmode_DCAEVT1(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->BKCR, EPWM_BKCR_DCAEVT1_Msk, mode << EPWM_BKCR_DCAEVT1_Pos);
}

/**
  * @brief
  * @rmtoll   BKCR    DCAEVT1    FL_EPWM_BK_GetOutputBmode_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_GetOutputBmode_DCAEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCR, EPWM_BKCR_DCAEVT1_Msk));
}

/**
  * @brief
  * @rmtoll   BKCR    TZA    FL_EPWM_BK_SetOutputBmode_CBCOST
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_BK_SetOutputBmode_CBCOST(EPWM_Type *EPWMx, uint32_t mode, uint32_t channel)
{
    MODIFY_REG(EPWMx->BKCR, EPWM_BKCR_TZA_Msk << channel, mode << channel);
}

/**
  * @brief
  * @rmtoll   BKCR    TZA    FL_EPWM_BK_GetOutputBmode_CBCOST
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_OUTPUT_HIGH_IMPEDANCE
  *           @arg @ref FL_EPWM_OUTPUT_HIGH
  *           @arg @ref FL_EPWM_OUTPUT_LOW
  *           @arg @ref FL_EPWM_OUTPUT_FROZEN
  */
__STATIC_INLINE uint32_t FL_EPWM_BK_GetOutputBmode_CBCOST(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->BKCR, EPWM_BKCR_TZA_Msk << channel));
}

/**
  * @brief
  * @rmtoll   BKIER    DCBEVT2IE    FL_EPWM_EnableIT_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_DCBEVT2(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKIER, EPWM_BKIER_DCBEVT2IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCBEVT2IE    FL_EPWM_IsEnabledIT_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_DCBEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKIER, EPWM_BKIER_DCBEVT2IE_Msk) == EPWM_BKIER_DCBEVT2IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCBEVT2IE    FL_EPWM_DisableIT_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_DCBEVT2(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKIER, EPWM_BKIER_DCBEVT2IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCBEVT1IE    FL_EPWM_EnableIT_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_DCBEVT1(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKIER, EPWM_BKIER_DCBEVT1IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCBEVT1IE    FL_EPWM_IsEnabledIT_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_DCBEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKIER, EPWM_BKIER_DCBEVT1IE_Msk) == EPWM_BKIER_DCBEVT1IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCBEVT1IE    FL_EPWM_DisableIT_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_DCBEVT1(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKIER, EPWM_BKIER_DCBEVT1IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCAEVT2IE    FL_EPWM_EnableIT_DCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_DCAEVT2(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKIER, EPWM_BKIER_DCAEVT2IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCAEVT2IE    FL_EPWM_IsEnabledIT_DCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_DCAEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKIER, EPWM_BKIER_DCAEVT2IE_Msk) == EPWM_BKIER_DCAEVT2IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCAEVT2IE    FL_EPWM_DisableIT_DCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_DCAEVT2(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKIER, EPWM_BKIER_DCAEVT2IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCAEVT1IE    FL_EPWM_EnableIT_DCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_DCAEVT1(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKIER, EPWM_BKIER_DCAEVT1IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCAEVT1IE    FL_EPWM_IsEnabledIT_DCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_DCAEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKIER, EPWM_BKIER_DCAEVT1IE_Msk) == EPWM_BKIER_DCAEVT1IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    DCAEVT1IE    FL_EPWM_DisableIT_DCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_DCAEVT1(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKIER, EPWM_BKIER_DCAEVT1IE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    OSTIE    FL_EPWM_EnableIT_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_OneShot(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKIER, EPWM_BKIER_OSTIE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    OSTIE    FL_EPWM_IsEnabledIT_OneShot
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_OneShot(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKIER, EPWM_BKIER_OSTIE_Msk) == EPWM_BKIER_OSTIE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    OSTIE    FL_EPWM_DisableIT_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_OneShot(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKIER, EPWM_BKIER_OSTIE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    CBCIE    FL_EPWM_EnableIT_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_CycleByCycle(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKIER, EPWM_BKIER_CBCIE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    CBCIE    FL_EPWM_IsEnabledIT_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_CycleByCycle(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKIER, EPWM_BKIER_CBCIE_Msk) == EPWM_BKIER_CBCIE_Msk);
}

/**
  * @brief
  * @rmtoll   BKIER    CBCIE    FL_EPWM_DisableIT_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_CycleByCycle(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->BKIER, EPWM_BKIER_CBCIE_Msk);
}

/**
  * @brief
  * @rmtoll   BKISR    OST_DCBEVT1    FL_EPWM_IsActiveFlag_BreakLockByDCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByDCBEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST_DCBEVT1_Msk) == (EPWM_BKISR_OST_DCBEVT1_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST_DCAEVT1    FL_EPWM_IsActiveFlag_BreakLockByDCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByDCAEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST_DCAEVT1_Msk) == (EPWM_BKISR_OST_DCAEVT1_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST6    FL_EPWM_IsActiveFlag_BreakLockByOST6
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByOST6(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST6_Msk) == (EPWM_BKISR_OST6_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST5    FL_EPWM_IsActiveFlag_BreakLockByOST5
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByOST5(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST5_Msk) == (EPWM_BKISR_OST5_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST4    FL_EPWM_IsActiveFlag_BreakLockByOST4
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByOST4(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST4_Msk) == (EPWM_BKISR_OST4_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST3    FL_EPWM_IsActiveFlag_BreakLockByOST3
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByOST3(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST3_Msk) == (EPWM_BKISR_OST3_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST2    FL_EPWM_IsActiveFlag_BreakLockByOST2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByOST2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST2_Msk) == (EPWM_BKISR_OST2_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OST1    FL_EPWM_IsActiveFlag_BreakLockByOST1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByOST1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OST1_Msk) == (EPWM_BKISR_OST1_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC_DCBEVT2    FL_EPWM_IsActiveFlag_BreakLockByDCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByDCBEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC_DCBEVT2_Msk) == (EPWM_BKISR_CBC_DCBEVT2_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC_DCAEVT2    FL_EPWM_IsActiveFlag_BreakLockByDCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByDCAEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC_DCAEVT2_Msk) == (EPWM_BKISR_CBC_DCAEVT2_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC6    FL_EPWM_IsActiveFlag_BreakLockByCBC6
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByCBC6(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC6_Msk) == (EPWM_BKISR_CBC6_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC5    FL_EPWM_IsActiveFlag_BreakLockByCBC5
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByCBC5(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC5_Msk) == (EPWM_BKISR_CBC5_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC4    FL_EPWM_IsActiveFlag_BreakLockByCBC4
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByCBC4(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC4_Msk) == (EPWM_BKISR_CBC4_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC3    FL_EPWM_IsActiveFlag_BreakLockByCBC3
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByCBC3(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC3_Msk) == (EPWM_BKISR_CBC3_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC2    FL_EPWM_IsActiveFlag_BreakLockByCBC2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByCBC2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC2_Msk) == (EPWM_BKISR_CBC2_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBC1    FL_EPWM_IsActiveFlag_BreakLockByCBC1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_BreakLockByCBC1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBC1_Msk) == (EPWM_BKISR_CBC1_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    DCBEVT2IF    FL_EPWM_IsActiveFlag_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_DCBEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_DCBEVT2IF_Msk) == (EPWM_BKISR_DCBEVT2IF_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    DCBEVT2IF    FL_EPWM_ClearFlag_DCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_DCBEVT2(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKISR, EPWM_BKISR_DCBEVT2IF_Msk);
}

/**
  * @brief
  * @rmtoll   BKISR    DCBEVT1IF    FL_EPWM_IsActiveFlag_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_DCBEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_DCBEVT1IF_Msk) == (EPWM_BKISR_DCBEVT1IF_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    DCBEVT1IF    FL_EPWM_ClearFlag_DCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_DCBEVT1(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKISR, EPWM_BKISR_DCBEVT1IF_Msk);
}

/**
  * @brief
  * @rmtoll   BKISR    DCAEVT2IF    FL_EPWM_IsActiveFlag_DCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_DCAEVT2(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_DCAEVT2IF_Msk) == (EPWM_BKISR_DCAEVT2IF_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    DCAEVT2IF    FL_EPWM_ClearFlag_DCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_DCAEVT2(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKISR, EPWM_BKISR_DCAEVT2IF_Msk);
}

/**
  * @brief
  * @rmtoll   BKISR    DCAEVT1IF    FL_EPWM_IsActiveFlag_DCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_DCAEVT1(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_DCAEVT1IF_Msk) == (EPWM_BKISR_DCAEVT1IF_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    DCAEVT1IF    FL_EPWM_ClearFlag_DCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_DCAEVT1(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKISR, EPWM_BKISR_DCAEVT1IF_Msk);
}

/**
  * @brief
  * @rmtoll   BKISR    OSTIF    FL_EPWM_IsActiveFlag_OneShot
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_OneShot(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_OSTIF_Msk) == (EPWM_BKISR_OSTIF_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    OSTIF    FL_EPWM_ClearFlag_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_OneShot(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKISR, EPWM_BKISR_OSTIF_Msk);
}

/**
  * @brief
  * @rmtoll   BKISR    CBCIF    FL_EPWM_IsActiveFlag_CycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_CycleByCycle(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->BKISR, EPWM_BKISR_CBCIF_Msk) == (EPWM_BKISR_CBCIF_Msk));
}

/**
  * @brief
  * @rmtoll   BKISR    CBCIF    FL_EPWM_ClearFlag_OneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_CycleByCycle(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKISR, EPWM_BKISR_CBCIF_Msk);
}

/**
  * @brief
  * @rmtoll   BKCLR    DCBEVT2C    FL_EPWM_ClearFlag_BreakLockByDCBEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_BreakLockByDCBEVT2(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKCLR, EPWM_BKCLR_DCBEVT2C_Msk);
}

/**
  * @brief
  * @rmtoll   BKCLR    DCBEVT1C    FL_EPWM_ClearFlag_BreakLockByDCBEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_BreakLockByDCBEVT1(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKCLR, EPWM_BKCLR_DCBEVT1C_Msk);
}

/**
  * @brief
  * @rmtoll   BKCLR    DCAEVT2C    FL_EPWM_ClearFlag_BreakLockByDCAEVT2
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_BreakLockByDCAEVT2(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKCLR, EPWM_BKCLR_DCAEVT2C_Msk);
}

/**
  * @brief
  * @rmtoll   BKCLR    DCAEVT1C    FL_EPWM_ClearFlag_BreakLockByDCAEVT1
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_BreakLockByDCAEVT1(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKCLR, EPWM_BKCLR_DCAEVT1C_Msk);
}

/**
  * @brief
  * @rmtoll   BKCLR    OSTC    FL_EPWM_ClearFlag_BreakLockByOneShot
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_BreakLockByOneShot(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKCLR, EPWM_BKCLR_OSTC_Msk);
}

/**
  * @brief
  * @rmtoll   BKCLR    CBCC    FL_EPWM_ClearFlag_BreakLockByCycleByCycle
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_BreakLockByCycleByCycle(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->BKCLR, EPWM_BKCLR_CBCC_Msk);
}

/**
  * @brief
  * @rmtoll   BKSFR    DCBEVT2SF    FL_EPWM_GenerateDCBEVT2BreakEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateDCBEVT2BreakEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKSFR, EPWM_BKSFR_DCBEVT2SF_Msk);
}

/**
  * @brief
  * @rmtoll   BKSFR    DCBEVT1SF    FL_EPWM_GenerateDCBEVT1BreakEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateDCBEVT1BreakEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKSFR, EPWM_BKSFR_DCBEVT1SF_Msk);
}

/**
  * @brief
  * @rmtoll   BKSFR    DCAEVT2SF    FL_EPWM_GenerateDCAEVT2BreakEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateDCAEVT2BreakEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKSFR, EPWM_BKSFR_DCAEVT2SF_Msk);
}

/**
  * @brief
  * @rmtoll   BKSFR    DCAEVT1SF    FL_EPWM_GenerateDCAEVT1BreakEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateDCAEVT1BreakEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKSFR, EPWM_BKSFR_DCAEVT1SF_Msk);
}

/**
  * @brief
  * @rmtoll   BKSFR    OSTSF    FL_EPWM_GenerateOneShotBreakEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateOneShotBreakEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKSFR, EPWM_BKSFR_OSTSF_Msk);
}

/**
  * @brief
  * @rmtoll   BKSFR    CBCSF    FL_EPWM_GenerateCycleByCycleBreakEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateCycleByCycleBreakEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->BKSFR, EPWM_BKSFR_CBCSF_Msk);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCBEVT1CFG    FL_EPWM_SetBreakEventActive
  * @param    EPWMx EPWM instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DISABLE
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW
  * @param    event This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DC_EVENT_1
  *           @arg @ref FL_EPWM_DC_EVENT_2
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCBBreakEvent(EPWM_Type *EPWMx, uint32_t config, uint32_t event)
{
    MODIFY_REG(EPWMx->DCINSR, EPWM_DCINSR_DCAEVT1CFG_Msk << event, (config << EPWM_DCINSR_DCBEVT1CFG_Pos) << event);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCBEVT1CFG    FL_EPWM_GetBreakEventActive
  * @param    EPWMx EPWM instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DISABLE
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DC_EVENT_1
  *           @arg @ref FL_EPWM_DC_EVENT_2

  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCBBreakEvent(EPWM_Type *EPWMx, uint32_t event)
{
    return (uint32_t)(READ_BIT(EPWMx->DCINSR, EPWM_DCINSR_DCAEVT1CFG_Msk << event));
}

/**
  * @brief
  * @rmtoll   DCINSR    DCAEVT1CFG    FL_EPWM_SetBreakEventActive
  * @param    EPWMx EPWM instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DISABLE
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW
  * @param    event This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DC_EVENT_1
  *           @arg @ref FL_EPWM_DC_EVENT_2
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCABreakEvent(EPWM_Type *EPWMx, uint32_t config, uint32_t event)
{
    MODIFY_REG(EPWMx->DCINSR, EPWM_DCINSR_DCAEVT1CFG_Msk << event, config << EPWM_DCINSR_DCAEVT1CFG_Pos << event);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCAEVT1CFG    FL_EPWM_GetBreakEventActive
  * @param    EPWMx EPWM instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DISABLE
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_LOW
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_LOWANDDCL_HIGH
  *           @arg @ref FL_EPWM_DIGITAL_COMPARE_DCH_HIGHANDDCL_LOW
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DC_EVENT_1
  *           @arg @ref FL_EPWM_DC_EVENT_2
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCABreakEvent(EPWM_Type *EPWMx, uint32_t event)
{
    return (uint32_t)(READ_BIT(EPWMx->DCINSR, EPWM_DCINSR_DCAEVT1CFG_Msk));
}

/**
  * @brief
  * @rmtoll   DCINSR    DCALSEL    FL_EPWM_SetDCLInputSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT

  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCALInputSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DCINSR, EPWM_DCINSR_DCALSEL_Msk, source << EPWM_DCINSR_DCALSEL_Pos);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCALSEL    FL_EPWM_GetDCLInputSource
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCALInputSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCINSR, EPWM_DCINSR_DCALSEL_Msk));
}

/**
  * @brief
  * @rmtoll   DCINSR    DCAHSEL    FL_EPWM_SetDCHInputSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCAHInputSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DCINSR, EPWM_DCINSR_DCAHSEL_Msk, source << EPWM_DCINSR_DCAHSEL_Pos);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCAHSEL    FL_EPWM_GetDCHInputSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCAHInputSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCINSR, EPWM_DCINSR_DCAHSEL_Msk));
}

/**
  * @brief
  * @rmtoll   DCINSR    DCALSEL    FL_EPWM_SetDCLInputSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT

  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCBLInputSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DCINSR, EPWM_DCINSR_DCBLSEL_Msk, source << EPWM_DCINSR_DCBLSEL_Pos);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCALSEL    FL_EPWM_GetDCLInputSource
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCBLInputSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCINSR, EPWM_DCINSR_DCBLSEL_Msk));
}

/**
  * @brief
  * @rmtoll   DCINSR    DCAHSEL    FL_EPWM_SetDCHInputSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT
  * @param    channel This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCBHInputSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DCINSR, EPWM_DCINSR_DCBHSEL_Msk, source << EPWM_DCINSR_DCBHSEL_Pos);
}

/**
  * @brief
  * @rmtoll   DCINSR    DCAHSEL    FL_EPWM_GetDCHInputSource
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK1
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK2
  *           @arg @ref FL_EPWM_INPUT_SOURCE_BK3
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP1OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP2OUT
  *           @arg @ref FL_EPWM_INPUT_SOURCE_COMP3OUT
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCBHInputSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCINSR, EPWM_DCINSR_DCBHSEL_Msk));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT2FRCS    FL_EPWM_SetDCEVT2SoftwareSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT2_SOFTWARE_SOUECE_SYNC
  *           @arg @ref FL_EPWM_DCEVT2_SOFTWARE_SOUECE_ASYNC
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCEVT2ForceSource(EPWM_Type *EPWMx, uint32_t source, uint32_t channel)
{
    MODIFY_REG(EPWMx->DCCR, EPWM_DCCR_DCAEVT2FRCS_Msk << (channel * 16), source << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT2FRCS    FL_EPWM_GetDCEVT2SoftwareSource
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT2_SOFTWARE_SOUECE_SYNC
  *           @arg @ref FL_EPWM_DCEVT2_SOFTWARE_SOUECE_ASYNC
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCEVT2ForceSource(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT2FRCS_Msk << (channel * 16)));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT2SRC    FL_EPWM_SetDCEVT2Source
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT2_SOUECE_DEEVT2
  *           @arg @ref FL_EPWM_DCEVT2_SOUECE_DCEVTFLT
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCEVT2Source(EPWM_Type *EPWMx, uint32_t source, uint32_t channel)
{
    MODIFY_REG(EPWMx->DCCR, EPWM_DCCR_DCAEVT2SRC_Msk << (channel * 16), source << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT2SRC    FL_EPWM_GetDCEVT2Source
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT2_SOUECE_DEEVT2
  *           @arg @ref FL_EPWM_DCEVT2_SOUECE_DCEVTFLT
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCEVT2Source(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT2SRC_Msk << (channel * 16)));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SYNC    FL_EPWM_EnableDCEVT1SYNCSignalOutput
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableDCEVT1SYNCSignalOutput(EPWM_Type *EPWMx, uint32_t channel)
{
    SET_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SYNC_Msk << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SYNC    FL_EPWM_IsEnabledDCEVT1SYNCSignalOutput
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledDCEVT1SYNCSignalOutput(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SYNC_Msk << (channel * 16)) == EPWM_DCCR_DCAEVT1SYNC_Msk << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SYNC    FL_EPWM_DisableDCEVT1SYNCSignalOutput
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableDCEVT1SYNCSignalOutput(EPWM_Type *EPWMx, uint32_t channel)
{
    CLEAR_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SYNC_Msk << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SOC    FL_EPWM_EnableDCEVT1SOCSignalOutput
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableDCEVT1SOCSignalOutput(EPWM_Type *EPWMx, uint32_t channel)
{
    SET_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SOC_Msk << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SOC    FL_EPWM_IsEnabledDCEVT1SOCSignalOutput
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledDCEVT1SOCSignalOutput(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SOC_Msk << (channel * 16)) == EPWM_DCCR_DCAEVT1SOC_Msk << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SOC    FL_EPWM_DisableDCEVT1SOCSignalOutput
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableDCEVT1SOCSignalOutput(EPWM_Type *EPWMx, uint32_t channel)
{
    CLEAR_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SOC_Msk << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1FRCS    FL_EPWM_SetDCEVT1SoftwareSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT1_SOFTWARE_SOUECE_SYNC
  *           @arg @ref FL_EPWM_DCEVT1_SOFTWARE_SOUECE_ASYNC
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCEVT1ForceSource(EPWM_Type *EPWMx, uint32_t source, uint32_t channel)
{
    MODIFY_REG(EPWMx->DCCR, EPWM_DCCR_DCAEVT1FRCS_Msk << (channel * 16), source << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1FRCS    FL_EPWM_GetDCEVT1SoftwareSource
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT1_SOFTWARE_SOUECE_SYNC
  *           @arg @ref FL_EPWM_DCEVT1_SOFTWARE_SOUECE_ASYNC
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCEVT1ForceSource(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1FRCS_Msk << (channel * 16)));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SRC    FL_EPWM_SetDCEVT1Source
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT1_SOUECE_DEEVT1
  *           @arg @ref FL_EPWM_DCEVT1_SOUECE_DCEVTFLT
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetDCEVT1Source(EPWM_Type *EPWMx, uint32_t source, uint32_t channel)
{
    MODIFY_REG(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SRC_Msk << (channel * 16), source << (channel * 16));
}

/**
  * @brief
  * @rmtoll   DCCR    DCAEVT1SRC    FL_EPWM_GetDCEVT1Source
  * @param    EPWMx EPWM instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_CHANNEL_A
  *           @arg @ref FL_EPWM_CHANNEL_B
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_DCEVT1_SOUECE_DEEVT1
  *           @arg @ref FL_EPWM_DCEVT1_SOUECE_DCEVTFLT
  */
__STATIC_INLINE uint32_t FL_EPWM_GetDCEVT1Source(EPWM_Type *EPWMx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(EPWMx->DCCR, EPWM_DCCR_DCAEVT1SRC_Msk << (channel * 16)));
}

/**
  * @brief
  * @rmtoll   DCFCR    ALIGN    FL_EPWM_SetWindowAlignmentMode
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_0
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_PRD
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_0ANDCNT_PRD
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_0ANDCNT_PRD
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetWindowAlignmentMode(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->DCFCR, EPWM_DCFCR_ALIGN_Msk, mode);
}

/**
  * @brief
  * @rmtoll   DCFCR    ALIGN    FL_EPWM_GetWindowAlignmentMode
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_0
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_PRD
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_0ANDCNT_PRD
  *           @arg @ref FL_EPWM_ALIGNMENT_MODE_CNT_0ANDCNT_PRD
  */
__STATIC_INLINE uint32_t FL_EPWM_GetWindowAlignmentMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFCR, EPWM_DCFCR_ALIGN_Msk));
}

/**
  * @brief
  * @rmtoll   DCFCR    BLKINV    FL_EPWM_EnableShieldWindowInvert
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableShieldWindowInvert(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->DCFCR, EPWM_DCFCR_BLKINV_Msk);
}

/**
  * @brief
  * @rmtoll   DCFCR    BLKINV    FL_EPWM_IsEnabledShieldWindowInvert
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledShieldWindowInvert(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFCR, EPWM_DCFCR_BLKINV_Msk) == EPWM_DCFCR_BLKINV_Msk);
}

/**
  * @brief
  * @rmtoll   DCFCR    BLKINV    FL_EPWM_DisableShieldWindowInvert
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableShieldWindowInvert(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->DCFCR, EPWM_DCFCR_BLKINV_Msk);
}

/**
  * @brief
  * @rmtoll   DCFCR    BLKE    FL_EPWM_EnableShieldWindow
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableShieldWindow(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->DCFCR, EPWM_DCFCR_BLKE_Msk);
}

/**
  * @brief
  * @rmtoll   DCFCR    BLKE    FL_EPWM_IsEnabledShieldWindow
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledShieldWindow(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFCR, EPWM_DCFCR_BLKE_Msk) == EPWM_DCFCR_BLKE_Msk);
}

/**
  * @brief
  * @rmtoll   DCFCR    BLKE    FL_EPWM_DisableShieldWindow
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableShieldWindow(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->DCFCR, EPWM_DCFCR_BLKE_Msk);
}

/**
  * @brief
  * @rmtoll   DCFCR    ALIGN    FL_EPWM_SetFilterModuleInputSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCAEVT1
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCAEVT2
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCBEVT1
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCBEVT2
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetFilterModuleInputSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->DCFCR, EPWM_DCFCR_SRCSEL_Msk, source);
}

/**
  * @brief
  * @rmtoll   DCFCR    ALIGN    FL_EPWM_GetFilterModuleInputSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCAEVT1
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCAEVT2
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCBEVT1
  *           @arg @ref FL_EPWM_FILTER_INPUT_SOURCE_DCBEVT2
  */
__STATIC_INLINE uint32_t FL_EPWM_GetFilterModuleInputSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFCR, EPWM_DCFCR_SRCSEL_Msk));
}

/**
  * @brief
  * @rmtoll   DCFWR    WINDOW    FL_EPWM_WriteShieldWindowWidth
  * @param    EPWMx EPWM instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteShieldWindowWidth(EPWM_Type *EPWMx, uint32_t width)
{
    MODIFY_REG(EPWMx->DCFWR, (0xffU << 16U), (width << 16U));
}

/**
  * @brief
  * @rmtoll   DCFWR    WINDOW    FL_EPWM_ReadShieldWindowWidth
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadShieldWindowWidth(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFWR, (0xffU << 16U)) >> 16U);
}

/**
  * @brief
  * @rmtoll   DCFWR    WINOFFSET    FL_EPWM_WriteShieldWindowOffsetWidth
  * @param    EPWMx EPWM instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteShieldWindowOffsetWidth(EPWM_Type *EPWMx, uint32_t width)
{
    MODIFY_REG(EPWMx->DCFWR, (0xffffU << 0U), (width << 0U));
}

/**
  * @brief
  * @rmtoll   DCFWR    WINOFFSET    FL_EPWM_ReadShieldWindowOffsetWidth
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadShieldWindowOffsetWidth(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFWR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief
  * @rmtoll   DCFDR    WINDOW_CNT    FL_EPWM_ReadShieldWindowCounter
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadShieldWindowCounter(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFDR, (0xffU << 16U)) >> 16U);
}

/**
  * @brief
  * @rmtoll   DCFDR    WINOFFSET_CNT    FL_EPWM_ReadShieldWindowOffsetCounter
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadShieldWindowOffsetCounter(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->DCFDR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief
  * @rmtoll   EIER    PCNTSEL    FL_EPWM_SetPulseCountInterruptSignalSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_0
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_PRD
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_0ORCNT_PRD
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_DOWN
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_DOWN
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_DOWN
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetPulseCountInterruptSignalSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->EIER, EPWM_EIER_PCNTSEL_Msk, source);
}

/**
  * @brief
  * @rmtoll   EIER    PCNTSEL    FL_EPWM_GetPulseCountInterruptSignalSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_0
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_PRD
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_0ORCNT_PRD
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPA_DOWN
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPB_DOWN
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPC_DOWN
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_UP
  *           @arg @ref FL_EPWM_COUNT_IE_SOURCE_CNT_CMPD_DOWN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetPulseCountInterruptSignalSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_PCNTSEL_Msk));
}

/**
  * @brief
  * @rmtoll   EIER    SOCBSEL    FL_EPWM_SetADCSOCBSignalSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_DCBEVT1_SOC
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_0
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_0ORCNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetADCSOCBSignalSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->EIER, EPWM_EIER_SOCBSEL_Msk, source);
}

/**
  * @brief
  * @rmtoll   EIER    SOCBSEL    FL_EPWM_GetADCSOCBSignalSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_DCBEVT1_SOC
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_0
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_0ORCNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPA_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPB_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPC_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_UP
  *           @arg @ref FL_EPWM_ADC_SOCB_SOURCE_CNT_CMPD_DOWN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetADCSOCBSignalSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_SOCBSEL_Msk));
}

/**
  * @brief
  * @rmtoll   EIER    SOCASEL    FL_EPWM_SetADCSOCASignalSource
  * @param    EPWMx EPWM instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_DCBEVT1_SOC
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_0
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_0ORCNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_DOWN
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetADCSOCASignalSource(EPWM_Type *EPWMx, uint32_t source)
{
    MODIFY_REG(EPWMx->EIER, EPWM_EIER_SOCASEL_Msk, source);
}

/**
  * @brief
  * @rmtoll   EIER    SOCASEL    FL_EPWM_GetADCSOCASignalSource
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_DCBEVT1_SOC
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_0
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_0ORCNT_PRD
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPA_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPB_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPC_DOWN
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_UP
  *           @arg @ref FL_EPWM_ADC_SOCA_SOURCE_CNT_CMPD_DOWN
  */
__STATIC_INLINE uint32_t FL_EPWM_GetADCSOCASignalSource(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_SOCASEL_Msk));
}

/**
  * @brief
  * @rmtoll   EIER    SOCBEN    FL_EPWM_EnableADCSOCBEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableADCSOCBEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_SOCBEN_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCBEN    FL_EPWM_IsEnabledADCSOCBEvent
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledADCSOCBEvent(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_SOCBEN_Msk) == EPWM_EIER_SOCBEN_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCBEN    FL_EPWM_DisableADCSOCBEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableADCSOCBEvent(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_SOCBEN_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCAEN    FL_EPWM_EnableADCSOCAEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableADCSOCAEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_SOCAEN_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCAEN    FL_EPWM_IsEnabledADCSOCAEvent
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledADCSOCAEvent(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_SOCAEN_Msk) == EPWM_EIER_SOCAEN_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCAEN    FL_EPWM_DisableADCSOCAEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableADCSOCAEvent(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_SOCAEN_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    PCNTIE    FL_EPWM_EnableIT_PulseCountEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_PulseCountEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_PCNTIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    PCNTIE    FL_EPWM_IsEnabledIT_PulseCountEvent
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_PulseCountEvent(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_PCNTIE_Msk) == EPWM_EIER_PCNTIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    PCNTIE    FL_EPWM_DisableIT_PulseCountEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_PulseCountEvent(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_PCNTIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCBIE    FL_EPWM_EnableIT_ADCSOCB
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_ADCSOCB(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_SOCBIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCBIE    FL_EPWM_IsEnabledIT_ADCSOCB
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_ADCSOCB(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_SOCBIE_Msk) == EPWM_EIER_SOCBIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCBIE    FL_EPWM_DisableIT_ADCSOCB
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_ADCSOCB(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_SOCBIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCAIE    FL_EPWM_EnableIT_ADCSOCA
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_ADCSOCA(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_SOCAIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCAIE    FL_EPWM_IsEnabledIT_ADCSOCA
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_ADCSOCA(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_SOCAIE_Msk) == EPWM_EIER_SOCAIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    SOCAIE    FL_EPWM_DisableIT_ADCSOCA
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_ADCSOCA(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_SOCAIE_Msk);
}
/**
  * @brief
  * @rmtoll   EIER    CAUIE    FL_EPWM_EnableIT_CompareEvent
  * @param    EPWMx EPWM instance
  * @param    dir This parameter can be one of the following values:
  * @param    event This parameter can be one of the following values:
              FL_EPWM_COUNT_MODE_UP_CNT_CMPA
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPA
              FL_EPWM_COUNT_MODE_UP_CNT_CMPB
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPB
              FL_EPWM_COUNT_MODE_UP_CNT_CMPC
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPC
              FL_EPWM_COUNT_MODE_UP_CNT_CMPD
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPD
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_CompareEvent(EPWM_Type *EPWMx, uint32_t event)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_CAUIE_Msk << event);
}

/**
  * @brief
  * @rmtoll   EIER    CAUIE    FL_EPWM_IsEnabledIT_CompareEvent
  * @param    EPWMx EPWM instance
  * @param    dir This parameter can be one of the following values:
  * @param    event This parameter can be one of the following values:
              FL_EPWM_COUNT_MODE_UP_CNT_CMPA
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPA
              FL_EPWM_COUNT_MODE_UP_CNT_CMPB
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPB
              FL_EPWM_COUNT_MODE_UP_CNT_CMPC
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPC
              FL_EPWM_COUNT_MODE_UP_CNT_CMPD
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPD
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_CompareEvent(EPWM_Type *EPWMx, uint32_t event)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_CAUIE_Msk << event) == EPWM_EIER_CAUIE_Msk << event);
}

/**
  * @brief
  * @rmtoll   EIER    CAUIE    FL_EPWM_DisableIT_CompareEvent
  * @param    EPWMx EPWM instance
  * @param    dir This parameter can be one of the following values:
  * @param    event This parameter can be one of the following values:
              FL_EPWM_COUNT_MODE_UP_CNT_CMPA
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPA
              FL_EPWM_COUNT_MODE_UP_CNT_CMPB
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPB
              FL_EPWM_COUNT_MODE_UP_CNT_CMPC
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPC
              FL_EPWM_COUNT_MODE_UP_CNT_CMPD
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPD
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_CompareEvent(EPWM_Type *EPWMx,  uint32_t event)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_CAUIE_Msk << event);
}

/**
  * @brief
  * @rmtoll   EIER    CPIE    FL_EPWM_EnableIT_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_CNTEqualPRD(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_CPIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    CPIE    FL_EPWM_IsEnabledIT_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_CNTEqualPRD(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_CPIE_Msk) == EPWM_EIER_CPIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    CPIE    FL_EPWM_DisableIT_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_CNTEqualPRD(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_CPIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    CZIE    FL_EPWM_EnableIT_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableIT_CNTEqualZero(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->EIER, EPWM_EIER_CZIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    CZIE    FL_EPWM_IsEnabledIT_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledIT_CNTEqualZero(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EIER, EPWM_EIER_CZIE_Msk) == EPWM_EIER_CZIE_Msk);
}

/**
  * @brief
  * @rmtoll   EIER    CZIE    FL_EPWM_DisableIT_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableIT_CNTEqualZero(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->EIER, EPWM_EIER_CZIE_Msk);
}

/**
  * @brief
  * @rmtoll   EISR    PCNTIF    FL_EPWM_IsActiveFlag_PulseCountEvent
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_PulseCountEvent(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EISR, EPWM_EISR_PCNTIF_Msk) == (EPWM_EISR_PCNTIF_Msk));
}

/**
  * @brief
  * @rmtoll   EISR    PCNTIF    FL_EPWM_ClearFlag_PulseCountEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_PulseCountEvent(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->EISR, EPWM_EISR_PCNTIF_Msk);
}

/**
  * @brief
  * @rmtoll   EISR    SOCBIF    FL_EPWM_IsActiveFlag_ADCSOCB
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_ADCSOCB(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EISR, EPWM_EISR_SOCBIF_Msk) == (EPWM_EISR_SOCBIF_Msk));
}

/**
  * @brief
  * @rmtoll   EISR    SOCBIF    FL_EPWM_ClearFlag_ADCSOCB
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_ADCSOCB(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->EISR, EPWM_EISR_SOCBIF_Msk);
}

/**
  * @brief
  * @rmtoll   EISR    SOCAIF    FL_EPWM_IsActiveFlag_ADCSOCA
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_ADCSOCA(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EISR, EPWM_EISR_SOCAIF_Msk) == (EPWM_EISR_SOCAIF_Msk));
}

/**
  * @brief
  * @rmtoll   EISR    SOCAIF    FL_EPWM_ClearFlag_ADCSOCA
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_ADCSOCA(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->EISR, EPWM_EISR_SOCAIF_Msk);
}

/**
  * @brief
  * @rmtoll   EISR    CAUIF    FL_EPWM_IsActiveFlag_CompareEvent
  * @param    EPWMx EPWM instance
  * @param    dir This parameter can be one of the following values:
  * @param    event This parameter can be one of the following values:
              FL_EPWM_COUNT_MODE_UP_CNT_CMPA
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPA
              FL_EPWM_COUNT_MODE_UP_CNT_CMPB
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPB
              FL_EPWM_COUNT_MODE_UP_CNT_CMPC
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPC
              FL_EPWM_COUNT_MODE_UP_CNT_CMPD
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPD
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_CompareEvent(EPWM_Type *EPWMx, uint32_t event)
{
    return (uint32_t)(READ_BIT(EPWMx->EISR, EPWM_EISR_CAUIF_Msk << event) == (EPWM_EISR_CAUIF_Msk << event));
}

/**
  * @brief
  * @rmtoll   EISR    CAUIF    FL_EPWM_ClearFlag_CompareEvent
  * @param    EPWMx EPWM instance
  * @param    dir This parameter can be one of the following values:
  * @param    event This parameter can be one of the following values:
              FL_EPWM_COUNT_MODE_UP_CNT_CMPA
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPA
              FL_EPWM_COUNT_MODE_UP_CNT_CMPB
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPB
              FL_EPWM_COUNT_MODE_UP_CNT_CMPC
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPC
              FL_EPWM_COUNT_MODE_UP_CNT_CMPD
              FL_EPWM_COUNT_MODE_DOWN_CNT_CMPD
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_CompareEvent(EPWM_Type *EPWMx, uint32_t event)
{
    WRITE_REG(EPWMx->EISR, EPWM_EISR_CAUIF_Msk << event);
}

/**
  * @brief
  * @rmtoll   EISR    CPIF    FL_EPWM_IsActiveFlag_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_CNTEqualPRD(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EISR, EPWM_EISR_CPIF_Msk) == (EPWM_EISR_CPIF_Msk));
}

/**
  * @brief
  * @rmtoll   EISR    CPIF    FL_EPWM_ClearFlag_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_CNTEqualPRD(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->EISR, EPWM_EISR_CPIF_Msk);
}

/**
  * @brief
  * @rmtoll   EISR    CZIF    FL_EPWM_IsActiveFlag_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_CNTEqualZero(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EISR, EPWM_EISR_CZIF_Msk) == (EPWM_EISR_CZIF_Msk));
}

/**
  * @brief
  * @rmtoll   EISR    CZIF    FL_EPWM_ClearFlag_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_ClearFlag_CNTEqualZero(EPWM_Type *EPWMx)
{
    WRITE_REG(EPWMx->EISR, EPWM_EISR_CZIF_Msk);
}

/**
  * @brief
  * @rmtoll   EPSR    PCINTCNT    FL_EPWM_GetSelectPulseEventCounter
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_PULSE_EVENT_N0
  *           @arg @ref FL_EPWM_PULSE_EVENT_N1
  *           @arg @ref FL_EPWM_PULSE_EVENT_N2
  *           @arg @ref FL_EPWM_PULSE_EVENT_N3
  *           @arg @ref FL_EPWM_PULSE_EVENT_N4
  *           @arg @ref FL_EPWM_PULSE_EVENT_N5
  *           @arg @ref FL_EPWM_PULSE_EVENT_N6
  *           @arg @ref FL_EPWM_PULSE_EVENT_N7
  *           @arg @ref FL_EPWM_PULSE_EVENT_N8
  *           @arg @ref FL_EPWM_PULSE_EVENT_N9
  *           @arg @ref FL_EPWM_PULSE_EVENT_N10
  *           @arg @ref FL_EPWM_PULSE_EVENT_N11
  *           @arg @ref FL_EPWM_PULSE_EVENT_N12
  *           @arg @ref FL_EPWM_PULSE_EVENT_N13
  *           @arg @ref FL_EPWM_PULSE_EVENT_N14
  *           @arg @ref FL_EPWM_PULSE_EVENT_N15
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSelectPulseEventCounter(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EPSR, EPWM_EPSR_PCINTCNT_Msk));
}

/**
  * @brief
  * @rmtoll   EPSR    PCINTPRD    FL_EPWM_SetPulseCountInterruptTriggerCondition
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_PULSE_EVENT_N0
  *           @arg @ref FL_EPWM_PULSE_EVENT_N1
  *           @arg @ref FL_EPWM_PULSE_EVENT_N2
  *           @arg @ref FL_EPWM_PULSE_EVENT_N3
  *           @arg @ref FL_EPWM_PULSE_EVENT_N4
  *           @arg @ref FL_EPWM_PULSE_EVENT_N5
  *           @arg @ref FL_EPWM_PULSE_EVENT_N6
  *           @arg @ref FL_EPWM_PULSE_EVENT_N7
  *           @arg @ref FL_EPWM_PULSE_EVENT_N8
  *           @arg @ref FL_EPWM_PULSE_EVENT_N9
  *           @arg @ref FL_EPWM_PULSE_EVENT_N10
  *           @arg @ref FL_EPWM_PULSE_EVENT_N11
  *           @arg @ref FL_EPWM_PULSE_EVENT_N12
  *           @arg @ref FL_EPWM_PULSE_EVENT_N13
  *           @arg @ref FL_EPWM_PULSE_EVENT_N14
  *           @arg @ref FL_EPWM_PULSE_EVENT_N15
  */
__STATIC_INLINE void FL_EPWM_SetPulseCountInterruptTriggerCondition(EPWM_Type *EPWMx, uint32_t count)
{
    MODIFY_REG(EPWMx->EPSR, EPWM_EPSR_PCINTPRD_Msk, count);
}

/**
  * @brief
  * @rmtoll   EPSR    PCINTPRD    FL_EPWM_GetPulseCountInterruptTriggerCondition
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_PULSE_EVENT_N0
  *           @arg @ref FL_EPWM_PULSE_EVENT_N1
  *           @arg @ref FL_EPWM_PULSE_EVENT_N2
  *           @arg @ref FL_EPWM_PULSE_EVENT_N3
  *           @arg @ref FL_EPWM_PULSE_EVENT_N4
  *           @arg @ref FL_EPWM_PULSE_EVENT_N5
  *           @arg @ref FL_EPWM_PULSE_EVENT_N6
  *           @arg @ref FL_EPWM_PULSE_EVENT_N7
  *           @arg @ref FL_EPWM_PULSE_EVENT_N8
  *           @arg @ref FL_EPWM_PULSE_EVENT_N9
  *           @arg @ref FL_EPWM_PULSE_EVENT_N10
  *           @arg @ref FL_EPWM_PULSE_EVENT_N11
  *           @arg @ref FL_EPWM_PULSE_EVENT_N12
  *           @arg @ref FL_EPWM_PULSE_EVENT_N13
  *           @arg @ref FL_EPWM_PULSE_EVENT_N14
  *           @arg @ref FL_EPWM_PULSE_EVENT_N15
  */
__STATIC_INLINE uint32_t FL_EPWM_GetPulseCountInterruptTriggerCondition(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EPSR, EPWM_EPSR_PCINTPRD_Msk));
}

/**
  * @brief
  * @rmtoll   EPSR    SOCBCNT    FL_EPWM_GetSOCBEventCounter
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SOCB_EVENT_N0
  *           @arg @ref FL_EPWM_SOCB_EVENT_N1
  *           @arg @ref FL_EPWM_SOCB_EVENT_N2
  *           @arg @ref FL_EPWM_SOCB_EVENT_N3
  *           @arg @ref FL_EPWM_SOCB_EVENT_N4
  *           @arg @ref FL_EPWM_SOCB_EVENT_N5
  *           @arg @ref FL_EPWM_SOCB_EVENT_N6
  *           @arg @ref FL_EPWM_SOCB_EVENT_N7
  *           @arg @ref FL_EPWM_SOCB_EVENT_N8
  *           @arg @ref FL_EPWM_SOCB_EVENT_N9
  *           @arg @ref FL_EPWM_SOCB_EVENT_N10
  *           @arg @ref FL_EPWM_SOCB_EVENT_N11
  *           @arg @ref FL_EPWM_SOCB_EVENT_N12
  *           @arg @ref FL_EPWM_SOCB_EVENT_N13
  *           @arg @ref FL_EPWM_SOCB_EVENT_N14
  *           @arg @ref FL_EPWM_SOCB_EVENT_N15
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSOCBEventCounter(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EPSR, EPWM_EPSR_SOCBCNT_Msk));
}

/**
  * @brief
  * @rmtoll   EPSR    SOCBPRD    FL_EPWM_SetSOCBOutputCondition
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SOCB_EVENT_N0
  *           @arg @ref FL_EPWM_SOCB_EVENT_N1
  *           @arg @ref FL_EPWM_SOCB_EVENT_N2
  *           @arg @ref FL_EPWM_SOCB_EVENT_N3
  *           @arg @ref FL_EPWM_SOCB_EVENT_N4
  *           @arg @ref FL_EPWM_SOCB_EVENT_N5
  *           @arg @ref FL_EPWM_SOCB_EVENT_N6
  *           @arg @ref FL_EPWM_SOCB_EVENT_N7
  *           @arg @ref FL_EPWM_SOCB_EVENT_N8
  *           @arg @ref FL_EPWM_SOCB_EVENT_N9
  *           @arg @ref FL_EPWM_SOCB_EVENT_N10
  *           @arg @ref FL_EPWM_SOCB_EVENT_N11
  *           @arg @ref FL_EPWM_SOCB_EVENT_N12
  *           @arg @ref FL_EPWM_SOCB_EVENT_N13
  *           @arg @ref FL_EPWM_SOCB_EVENT_N14
  *           @arg @ref FL_EPWM_SOCB_EVENT_N15
  */
__STATIC_INLINE void FL_EPWM_SetSOCBOutputCondition(EPWM_Type *EPWMx, uint32_t count)
{
    MODIFY_REG(EPWMx->EPSR, EPWM_EPSR_SOCBPRD_Msk, count);
}

/**
  * @brief
  * @rmtoll   EPSR    SOCBPRD    FL_EPWM_GetSOCBOutputCondition
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SOCB_EVENT_N0
  *           @arg @ref FL_EPWM_SOCB_EVENT_N1
  *           @arg @ref FL_EPWM_SOCB_EVENT_N2
  *           @arg @ref FL_EPWM_SOCB_EVENT_N3
  *           @arg @ref FL_EPWM_SOCB_EVENT_N4
  *           @arg @ref FL_EPWM_SOCB_EVENT_N5
  *           @arg @ref FL_EPWM_SOCB_EVENT_N6
  *           @arg @ref FL_EPWM_SOCB_EVENT_N7
  *           @arg @ref FL_EPWM_SOCB_EVENT_N8
  *           @arg @ref FL_EPWM_SOCB_EVENT_N9
  *           @arg @ref FL_EPWM_SOCB_EVENT_N10
  *           @arg @ref FL_EPWM_SOCB_EVENT_N11
  *           @arg @ref FL_EPWM_SOCB_EVENT_N12
  *           @arg @ref FL_EPWM_SOCB_EVENT_N13
  *           @arg @ref FL_EPWM_SOCB_EVENT_N14
  *           @arg @ref FL_EPWM_SOCB_EVENT_N15
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSOCBOutputCondition(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EPSR, EPWM_EPSR_SOCBPRD_Msk));
}

/**
  * @brief
  * @rmtoll   EPSR    SOCACNT    FL_EPWM_GetSOCAEventCounter
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SOCA_EVENT_N0
  *           @arg @ref FL_EPWM_SOCA_EVENT_N1
  *           @arg @ref FL_EPWM_SOCA_EVENT_N2
  *           @arg @ref FL_EPWM_SOCA_EVENT_N3
  *           @arg @ref FL_EPWM_SOCA_EVENT_N4
  *           @arg @ref FL_EPWM_SOCA_EVENT_N5
  *           @arg @ref FL_EPWM_SOCA_EVENT_N6
  *           @arg @ref FL_EPWM_SOCA_EVENT_N7
  *           @arg @ref FL_EPWM_SOCA_EVENT_N8
  *           @arg @ref FL_EPWM_SOCA_EVENT_N9
  *           @arg @ref FL_EPWM_SOCA_EVENT_N10
  *           @arg @ref FL_EPWM_SOCA_EVENT_N11
  *           @arg @ref FL_EPWM_SOCA_EVENT_N12
  *           @arg @ref FL_EPWM_SOCA_EVENT_N13
  *           @arg @ref FL_EPWM_SOCA_EVENT_N14
  *           @arg @ref FL_EPWM_SOCA_EVENT_N15
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSOCAEventCounter(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EPSR, EPWM_EPSR_SOCACNT_Msk));
}

/**
  * @brief
  * @rmtoll   EPSR    SOCACNT    FL_EPWM_SetSOCAOutputCondition
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SOCA_EVENT_N0
  *           @arg @ref FL_EPWM_SOCA_EVENT_N1
  *           @arg @ref FL_EPWM_SOCA_EVENT_N2
  *           @arg @ref FL_EPWM_SOCA_EVENT_N3
  *           @arg @ref FL_EPWM_SOCA_EVENT_N4
  *           @arg @ref FL_EPWM_SOCA_EVENT_N5
  *           @arg @ref FL_EPWM_SOCA_EVENT_N6
  *           @arg @ref FL_EPWM_SOCA_EVENT_N7
  *           @arg @ref FL_EPWM_SOCA_EVENT_N8
  *           @arg @ref FL_EPWM_SOCA_EVENT_N9
  *           @arg @ref FL_EPWM_SOCA_EVENT_N10
  *           @arg @ref FL_EPWM_SOCA_EVENT_N11
  *           @arg @ref FL_EPWM_SOCA_EVENT_N12
  *           @arg @ref FL_EPWM_SOCA_EVENT_N13
  *           @arg @ref FL_EPWM_SOCA_EVENT_N14
  *           @arg @ref FL_EPWM_SOCA_EVENT_N15
  */
__STATIC_INLINE void FL_EPWM_SetSOCAOutputCondition(EPWM_Type *EPWMx, uint32_t count)
{
    MODIFY_REG(EPWMx->EPSR, EPWM_EPSR_SOCAPRD_Msk, count);
}

/**
  * @brief
  * @rmtoll   EPSR    SOCACNT    FL_EPWM_GetSOCAOutputCondition
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_SOCA_EVENT_N0
  *           @arg @ref FL_EPWM_SOCA_EVENT_N1
  *           @arg @ref FL_EPWM_SOCA_EVENT_N2
  *           @arg @ref FL_EPWM_SOCA_EVENT_N3
  *           @arg @ref FL_EPWM_SOCA_EVENT_N4
  *           @arg @ref FL_EPWM_SOCA_EVENT_N5
  *           @arg @ref FL_EPWM_SOCA_EVENT_N6
  *           @arg @ref FL_EPWM_SOCA_EVENT_N7
  *           @arg @ref FL_EPWM_SOCA_EVENT_N8
  *           @arg @ref FL_EPWM_SOCA_EVENT_N9
  *           @arg @ref FL_EPWM_SOCA_EVENT_N10
  *           @arg @ref FL_EPWM_SOCA_EVENT_N11
  *           @arg @ref FL_EPWM_SOCA_EVENT_N12
  *           @arg @ref FL_EPWM_SOCA_EVENT_N13
  *           @arg @ref FL_EPWM_SOCA_EVENT_N14
  *           @arg @ref FL_EPWM_SOCA_EVENT_N15
  */
__STATIC_INLINE uint32_t FL_EPWM_GetSOCAOutputCondition(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->EPSR, EPWM_EPSR_SOCAPRD_Msk));
}

/**
  * @brief
  * @rmtoll   SWTR    SOCB    FL_EPWM_GenerateSOCBEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateSOCBEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->SWTR, EPWM_SWTR_SOCB_Msk);
}

/**
  * @brief
  * @rmtoll   SWTR    SOCA    FL_EPWM_GenerateSOCAEvent
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_GenerateSOCAEvent(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->SWTR, EPWM_SWTR_SOCA_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRLDPRD    FL_EPWM_EnableHPWMCompareRegisterLoad_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableHPWMCompareRegisterLoad_CNTEqualPRD(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->HRCR, EPWM_HRCR_HRLDPRD_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRLDPRD    FL_EPWM_IsEnabledHPWMCompareRegisterLoad_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledHPWMCompareRegisterLoad_CNTEqualPRD(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRCR, EPWM_HRCR_HRLDPRD_Msk) == EPWM_HRCR_HRLDPRD_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRLDPRD    FL_EPWM_DisableHPWMCompareRegisterLoad_CNTEqualPRD
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableHPWMCompareRegisterLoad_CNTEqualPRD(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->HRCR, EPWM_HRCR_HRLDPRD_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRLDZRO    FL_EPWM_EnableHPWMCompareRegisterLoad_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableHPWMCompareRegisterLoad_CNTEqualZero(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->HRCR, EPWM_HRCR_HRLDZRO_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRLDZRO    FL_EPWM_IsEnabledHPWMCompareRegisterLoad_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledHPWMCompareRegisterLoad_CNTEqualZero(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRCR, EPWM_HRCR_HRLDZRO_Msk) == EPWM_HRCR_HRLDZRO_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRLDZRO    FL_EPWM_DisableHPWMCompareRegisterLoad_CNTEqualZero
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableHPWMCompareRegisterLoad_CNTEqualZero(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->HRCR, EPWM_HRCR_HRLDZRO_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRSHEN    FL_EPWM_EnableHPWMPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableHPWMPreload(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->HRCR, EPWM_HRCR_HRSHEN_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRSHEN    FL_EPWM_IsEnabledHPWMPreload
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledHPWMPreload(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRCR, EPWM_HRCR_HRSHEN_Msk) == EPWM_HRCR_HRSHEN_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRSHEN    FL_EPWM_DisableHPWMPreload
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableHPWMPreload(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->HRCR, EPWM_HRCR_HRSHEN_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRPWMEN    FL_EPWM_EnableHPWMMode
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnableHPWMMode(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->HRCR, EPWM_HRCR_HRPWMEN_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRPWMEN    FL_EPWM_IsEnabledHPWMMode
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledHPWMMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRCR, EPWM_HRCR_HRPWMEN_Msk) == EPWM_HRCR_HRPWMEN_Msk);
}

/**
  * @brief
  * @rmtoll   HRCR    HRPWMEN    FL_EPWM_DisableHPWMMode
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisableHPWMMode(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->HRCR, EPWM_HRCR_HRPWMEN_Msk);
}

/**
  * @brief
  * @rmtoll   HRPRD    HRPRD    FL_EPWM_WriteHPWMPeriod
  * @param    EPWMx EPWM instance
  * @param    period
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteHPWMPeriod(EPWM_Type *EPWMx, uint32_t period)
{
    MODIFY_REG(EPWMx->HRPRD, (0x1fU << 0U), (period << 0U));
}

/**
  * @brief
  * @rmtoll   HRPRD    HRPRD    FL_EPWM_ReadHPWMPeriod
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadHPWMPeriod(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRPRD, (0x1fU << 0U)) >> 0U);
}

/**
  * @brief
  * @rmtoll   HRCMPA    HRCMPA    FL_EPWM_WriteHPWMCompareCHA
  * @param    EPWMx EPWM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteHPWMCompareCHA(EPWM_Type *EPWMx, uint32_t compareValue)
{
    MODIFY_REG(EPWMx->HRCMPA, (0x1fU << 0U), (compareValue << 0U));
}

/**
  * @brief
  * @rmtoll   HRCMPA    HRCMPA    FL_EPWM_ReadHPWMCompareCHA
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadHPWMCompareCHA(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRCMPA, (0x1fU << 0U)) >> 0U);
}

/**
  * @brief
  * @rmtoll   HRCMPB    HRCMPB    FL_EPWM_WriteHPWMCompareCHB
  * @param    EPWMx EPWM instance
  * @param    compareValue
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteHPWMCompareCHB(EPWM_Type *EPWMx, uint32_t compareValue)
{
    MODIFY_REG(EPWMx->HRCMPB, (0x1fU << 0U), (compareValue << 0U));
}

/**
  * @brief
  * @rmtoll   HRCMPB    HRCMPB    FL_EPWM_ReadHPWMCompareCHB
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadHPWMCompareCHB(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRCMPB, (0x1fU << 0U)) >> 0U);
}

/**
  * @brief
  * @rmtoll   HRACR    LOCK    FL_EPWM_IsActiveFlag_LOCK
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsActiveFlag_LOCK(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRACR, EPWM_HRACR_LOCK_Msk) == (EPWM_HRACR_LOCK_Msk));
}

/**
  * @brief
  * @rmtoll   HRACR    PWRESHAPER_EN    FL_EPWM_EnablePulseReshaper
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_EnablePulseReshaper(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->HRACR, EPWM_HRACR_PWRESHAPER_EN_Msk);
}

/**
  * @brief
  * @rmtoll   HRACR    PWRESHAPER_EN    FL_EPWM_IsEnabledPulseReshaper
  * @param    EPWMx EPWM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabledPulseReshaper(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRACR, EPWM_HRACR_PWRESHAPER_EN_Msk) == EPWM_HRACR_PWRESHAPER_EN_Msk);
}

/**
  * @brief
  * @rmtoll   HRACR    PWRESHAPER_EN    FL_EPWM_DisablePulseReshaper
  * @param    EPWMx EPWM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_DisablePulseReshaper(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->HRACR, EPWM_HRACR_PWRESHAPER_EN_Msk);
}

/**
  * @brief
  * @rmtoll   HRACR    ITRIM    FL_EPWM_WriteCurrentTrim
  * @param    EPWMx EPWM instance
  * @param    trimValue
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteCurrentTrim(EPWM_Type *EPWMx, uint32_t trimValue)
{
    MODIFY_REG(EPWMx->HRACR, (0x7U << 4U), (trimValue << 4U));
}

/**
  * @brief
  * @rmtoll   HRACR    ITRIM    FL_EPWM_ReadCurrentTrim
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadCurrentTrim(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRACR, (0x7U << 4U)) >> 4U);
}

/**
  * @brief
  * @rmtoll   HRACR    RTRIM    FL_EPWM_WriteResistorTrim
  * @param    EPWMx EPWM instance
  * @param    trimValue
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_WriteResistorTrim(EPWM_Type *EPWMx, uint32_t trimValue)
{
    MODIFY_REG(EPWMx->HRACR, (0xfU << 0U), (trimValue << 0U));
}

/**
  * @brief
  * @rmtoll   HRACR    RTRIM    FL_EPWM_ReadResistorTrim
  * @param    EPWMx EPWM instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPWM_ReadResistorTrim(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->HRACR, (0xfU << 0U)) >> 0U);
}

/**
  * @brief
  * @rmtoll   LINK    LINK    FL_EPWM_SetLinkMode
  * @param    EPWMx EPWM instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPWM_LINK_NONE
  *           @arg @ref FL_EPWM_LINK_EPWM1
  *           @arg @ref FL_EPWM_LINK_EPWM2
  *           @arg @ref FL_EPWM_LINK_EPWM3
  *           @arg @ref FL_EPWM_LINK_EPWM4
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_SetLinkMode(EPWM_Type *EPWMx, uint32_t mode)
{
    MODIFY_REG(EPWMx->LINK, EPWM_LINK_LINK_Msk, mode);
}

/**
  * @brief
  * @rmtoll   LINK    LINK    FL_EPWM_GetLinkMode
  * @param    EPWMx EPWM instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPWM_LINK_NONE
  *           @arg @ref FL_EPWM_LINK_EPWM0
  *           @arg @ref FL_EPWM_LINK_EPWM1
  *           @arg @ref FL_EPWM_LINK_EPWM2
  *           @arg @ref FL_EPWM_LINK_EPWM3
  */
__STATIC_INLINE uint32_t FL_EPWM_GetLinkMode(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->LINK, EPWM_LINK_LINK_Msk));
}
/**
  * @brief    计数器使能
  * @rmtoll   CR    START    FL_EPWM_Enable
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPWM_Enable(EPWM_Type *EPWMx)
{
    SET_BIT(EPWMx->CR, EPWM_CR_CEN_Msk);
}

/**
  * @brief    读取计数器使能状态
  * @rmtoll   CR    START    FL_EPWM_IsEnabled
  * @param    TIMx TIM instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPWM_IsEnabled(EPWM_Type *EPWMx)
{
    return (uint32_t)(READ_BIT(EPWMx->CR, EPWM_CR_CEN_Msk) == EPWM_CR_CEN_Msk);
}

/**
  * @brief    计数器关闭
  * @rmtoll   CR    START    FL_EPWM_Disable
  * @param    TIMx TIM instance
  * @retval   None
  */
__STATIC_INLINE void FL_EOWM_Disable(EPWM_Type *EPWMx)
{
    CLEAR_BIT(EPWMx->CR, EPWM_CR_CEN_Msk);
}
/**
  * @}
  */

/** @defgroup EPWM_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
//#warning "PLEASE ANNOUCE THE INIT AND DEINIT FUNCTIONS HERE!!!"

/**
  * @}
  */
FL_ErrorStatus FL_EPWM_Init(EPWM_Type *TIMx, FL_EPWM_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_EPWM_OC_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_OC_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_EPWM_CMP_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_CMP_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_EPWM_DT_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_DT_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_EPWM_CHP_Init(EPWM_Type *TIMx, uint32_t channel, FL_EPWM_CHP_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_EPWM_DCEvent_Init(EPWM_Type *TIMx, uint32_t event, FL_EPWM_DCEvent_InitTypeDef *TIM_InitStruct);
FL_ErrorStatus FL_EPWM_SOC_Init(EPWM_Type *TIMx, FL_EPWM_SOC_InitTypeDef *TIM_InitStruct);
/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_EPWM_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-05-11*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
