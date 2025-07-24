/**
 *******************************************************************************************************
 * @file    fm33fk5xx_fl_can.h
 * @author  FMSH Application Team
 * @brief   Head file of CAN FL Module
 *******************************************************************************************************
 * @attention
 * Copyright (c) 2023, SHANGHAI FUDAN MICROELECTRONICS GROUP CO., LTD.(FUDAN MICROELECTRONICS./ FUDAN MICRO.)
 * All rights reserved.
 *
 * Processor:                   FM33FK5xx
 * http:                        http://www.fmdevelopers.com.cn/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * 4. To provide the most up-to-date information, the revision of our documents
 *    on the World Wide Web will be the most Current. Your printed copy may be
 *    an earlier revision. To verify you have the latest information avaliable,
 *    refer to: http://www.fmdevelopers.com.cn/.
 *
 * THIS SOFTWARE IS PROVIDED BY FUDAN MICRO "AS IS" AND ANY EXPRESSED:
 * ORIMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.IN NO EVENT SHALL FUDAN MICRO OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISINGIN ANY WAY OUT OF THE
 * USE OF THIS SOFTWARE, EVEN IF ADVISED OFTHE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************************************
 */

/* Define to prevent recursive inclusion---------------------------------------------------------------*/
#ifndef __FM33FK5XX_FL_CAN_H
#define __FM33FK5XX_FL_CAN_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CAN_FL_ES_INIT CAN Exported Init structures
  * @{
  */

/**
  * @brief FL CAN Init Sturcture definition
  */
typedef struct
{
    /*工作模式*/
    uint8_t mode;
    /*同步段长度*/
    uint8_t SJW;
    /*时间段1*/
    uint8_t TS1;
    /*时间段2*/
    uint8_t TS2;
    /*波特率预分频*/
    uint32_t BRP;
    /*时钟源选择*/
    uint32_t clockSource;
    /*发送优先级选择*/
    uint32_t TXPriority;
    /*唤醒使能*/
    FL_FunState wakeup;
    /*自动总线管理*/
    uint32_t ABOM;
    /*自动重发使能*/
    FL_FunState AREN;
} FL_CAN_InitTypeDef;
/**
  * @brief  CAN filter init structure definition
  */
typedef struct
{

    /*滤波器SRR位*/
    uint32_t filterIdSRR;
    /*滤波器IDE位*/
    uint32_t filterIdIDE;
    /*滤波器RTR位*/
    uint32_t filterIdRTR;
    /*滤波器标准ID*/
    uint32_t filterIdStandard;
    /*滤波器扩展ID*/
    uint32_t filterIdExtend;

    /*16位滤波器1IDE位*/
    uint32_t filterSTD1IdIDE;
    /*16位滤波器1SRR位*/
    uint32_t filterSTD1IdSRR;
    /*16位滤波器1标准ID*/
    uint32_t filterSTD1IdStandard;
    /*16位滤波器1扩展ID*/
    uint32_t filterSTD1IdExtend;

    /*16位滤波器2IDE位*/
    uint32_t filterSTD2IdIDE;
    /*16位滤波器2SRR位*/
    uint32_t filterSTD2IdSRR;
    /*16位滤波器2标准ID*/
    uint32_t filterSTD2IdStandard;
    /*16位滤波器2扩展ID*/
    uint32_t filterSTD2IdExtend;

    /*滤波器ID高11位掩码*/
    uint32_t filterMaskIdStandard;
    /*滤波器SRR位掩码*/
    FL_FunState filterMaskIdSRR;
    /*滤波器IDE位掩码*/
    FL_FunState filterMaskIdIDE;
    /*滤波器ID低18位掩码*/
    uint32_t filterMaskIdExtend;
    /*滤波器RTR位掩码*/
    FL_FunState filterMaskIdRTR;

    /*16位滤波器1ID高11位掩码*/
    uint32_t filterSTD1MaskIdStandard;
    /*16位滤波器1IDE位掩码*/
    FL_FunState filterSTD1MaskIdIDE;
    /*16位滤波器1ID低18位掩码*/
    uint32_t filterSTD1MaskIdExtend;
    /*16位滤波器1SRR位掩码*/
    FL_FunState filterSTD1MaskIdSRR;

    /*16位滤波器2ID高11位掩码*/
    uint32_t filterSTD2MaskIdStandard;
    /*16位滤波器2IDE位掩码*/
    FL_FunState filterSTD2MaskIdIDE;
    /*16位滤波器2ID低18位掩码*/
    uint32_t filterSTD2MaskIdExtend;
    /*16位滤波器2SRR位掩码*/
    FL_FunState filterSTD2MaskIdSRR;

    /*滤波器RTR位掩码*/
    uint32_t filterMaskMode;
    /*滤波器RTR位掩码*/
    uint32_t filterIDMode;
    /*滤波器使能*/
    FL_FunState  filterEn;
} FL_CAN_FilterInitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CAN_FL_Exported_Constants CAN Exported Constants
  * @{
  */

#define    CAN_CR_CEN_Pos                                         (1U)
#define    CAN_CR_CEN_Msk                                         (0x1U << CAN_CR_CEN_Pos)
#define    CAN_CR_CEN                                             CAN_CR_CEN_Msk

#define    CAN_CR_SRST_Pos                                        (0U)
#define    CAN_CR_SRST_Msk                                        (0x1U << CAN_CR_SRST_Pos)
#define    CAN_CR_SRST                                            CAN_CR_SRST_Msk

#define    CAN_MSR_RX_PRESYNC_EN_Pos                              (13U)
#define    CAN_MSR_RX_PRESYNC_EN_Msk                              (0x1U << CAN_MSR_RX_PRESYNC_EN_Pos)
#define    CAN_MSR_RX_PRESYNC_EN                                  CAN_MSR_RX_PRESYNC_EN_Msk

#define    CAN_MSR_TPRI_Pos                                       (12U)
#define    CAN_MSR_TPRI_Msk                                       (0x1U << CAN_MSR_TPRI_Pos)
#define    CAN_MSR_TPRI                                           CAN_MSR_TPRI_Msk

#define    CAN_MSR_WUPE_Pos                                       (11U)
#define    CAN_MSR_WUPE_Msk                                       (0x1U << CAN_MSR_WUPE_Pos)
#define    CAN_MSR_WUPE                                           CAN_MSR_WUPE_Msk

#define    CAN_MSR_AREN_Pos                                       (10U)
#define    CAN_MSR_AREN_Msk                                       (0x1U << CAN_MSR_AREN_Pos)
#define    CAN_MSR_AREN                                           CAN_MSR_AREN_Msk

#define    CAN_MSR_ABOM_Pos                                       (8U)
#define    CAN_MSR_ABOM_Msk                                       (0x3U << CAN_MSR_ABOM_Pos)
#define    CAN_MSR_ABOM                                           CAN_MSR_ABOM_Msk

#define    CAN_MSR_RTBO_Pos                                       (7U)
#define    CAN_MSR_RTBO_Msk                                       (0x1U << CAN_MSR_RTBO_Pos)
#define    CAN_MSR_RTBO                                           CAN_MSR_RTBO_Msk

#define    CAN_MSR_LPBACK_Pos                                     (1U)
#define    CAN_MSR_LPBACK_Msk                                     (0x1U << CAN_MSR_LPBACK_Pos)
#define    CAN_MSR_LPBACK                                         CAN_MSR_LPBACK_Msk

#define    CAN_MSR_SLEEP_Pos                                      (0U)
#define    CAN_MSR_SLEEP_Msk                                      (0x1U << CAN_MSR_SLEEP_Pos)
#define    CAN_MSR_SLEEP                                          CAN_MSR_SLEEP_Msk

#define    CAN_BRPR_BRP_Pos                                       (0U)
#define    CAN_BRPR_BRP_Msk                                       (0xffU << CAN_BRPR_BRP_Pos)
#define    CAN_BRPR_BRP                                           CAN_BRPR_BRP_Msk

#define    CAN_BTR_SJW_Pos                                        (7U)
#define    CAN_BTR_SJW_Msk                                        (0x3U << CAN_BTR_SJW_Pos)
#define    CAN_BTR_SJW                                            CAN_BTR_SJW_Msk

#define    CAN_BTR_TS2_Pos                                        (4U)
#define    CAN_BTR_TS2_Msk                                        (0x7U << CAN_BTR_TS2_Pos)
#define    CAN_BTR_TS2                                            CAN_BTR_TS2_Msk

#define    CAN_BTR_TS1_Pos                                        (0U)
#define    CAN_BTR_TS1_Msk                                        (0xfU << CAN_BTR_TS1_Pos)
#define    CAN_BTR_TS1                                            CAN_BTR_TS1_Msk

#define    CAN_ECR_REC_Pos                                        (8U)
#define    CAN_ECR_REC_Msk                                        (0xffU << CAN_ECR_REC_Pos)
#define    CAN_ECR_REC                                            CAN_ECR_REC_Msk

#define    CAN_ECR_TEC_Pos                                        (0U)
#define    CAN_ECR_TEC_Msk                                        (0xffU << CAN_ECR_TEC_Pos)
#define    CAN_ECR_TEC                                            CAN_ECR_TEC_Msk

#define    CAN_ESR_OVLF_Pos                                       (8U)
#define    CAN_ESR_OVLF_Msk                                       (0x1U << CAN_ESR_OVLF_Pos)
#define    CAN_ESR_OVLF                                           CAN_ESR_OVLF_Msk

#define    CAN_ESR_BLF_Pos                                        (7U)
#define    CAN_ESR_BLF_Msk                                        (0x1U << CAN_ESR_BLF_Pos)
#define    CAN_ESR_BLF                                            CAN_ESR_BLF_Msk

#define    CAN_ESR_ADERR_Pos                                      (6U)
#define    CAN_ESR_ADERR_Msk                                      (0x1U << CAN_ESR_ADERR_Pos)
#define    CAN_ESR_ADERR                                          CAN_ESR_ADERR_Msk

#define    CAN_ESR_ACKER_Pos                                      (5U)
#define    CAN_ESR_ACKER_Msk                                      (0x1U << CAN_ESR_ACKER_Pos)
#define    CAN_ESR_ACKER                                          CAN_ESR_ACKER_Msk

#define    CAN_ESR_B0ERR_Pos                                      (4U)
#define    CAN_ESR_B0ERR_Msk                                      (0x1U << CAN_ESR_B0ERR_Pos)
#define    CAN_ESR_B0ERR                                          CAN_ESR_B0ERR_Msk

#define    CAN_ESR_B1ERR_Pos                                      (3U)
#define    CAN_ESR_B1ERR_Msk                                      (0x1U << CAN_ESR_B1ERR_Pos)
#define    CAN_ESR_B1ERR                                          CAN_ESR_B1ERR_Msk

#define    CAN_ESR_STER_Pos                                       (2U)
#define    CAN_ESR_STER_Msk                                       (0x1U << CAN_ESR_STER_Pos)
#define    CAN_ESR_STER                                           CAN_ESR_STER_Msk

#define    CAN_ESR_FMER_Pos                                       (1U)
#define    CAN_ESR_FMER_Msk                                       (0x1U << CAN_ESR_FMER_Pos)
#define    CAN_ESR_FMER                                           CAN_ESR_FMER_Msk

#define    CAN_ESR_CRCER_Pos                                      (0U)
#define    CAN_ESR_CRCER_Msk                                      (0x1U << CAN_ESR_CRCER_Pos)
#define    CAN_ESR_CRCER                                          CAN_ESR_CRCER_Msk

#define    CAN_SR_ACFBSY_Pos                                      (11U)
#define    CAN_SR_ACFBSY_Msk                                      (0x1U << CAN_SR_ACFBSY_Pos)
#define    CAN_SR_ACFBSY                                          CAN_SR_ACFBSY_Msk

#define    CAN_SR_RXFE_Pos                                        (10U)
#define    CAN_SR_RXFE_Msk                                        (0x1U << CAN_SR_RXFE_Pos)
#define    CAN_SR_RXFE                                            CAN_SR_RXFE_Msk

#define    CAN_SR_RSTS_Pos                                        (8U)
#define    CAN_SR_RSTS_Msk                                        (0x3U << CAN_SR_RSTS_Pos)
#define    CAN_SR_RSTS                                            CAN_SR_RSTS_Msk

#define    CAN_SR_TSTS_Pos                                        (6U)
#define    CAN_SR_TSTS_Msk                                        (0x3U << CAN_SR_TSTS_Pos)
#define    CAN_SR_TSTS                                            CAN_SR_TSTS_Msk

#define    CAN_SR_BBSY_Pos                                        (5U)
#define    CAN_SR_BBSY_Msk                                        (0x1U << CAN_SR_BBSY_Pos)
#define    CAN_SR_BBSY                                            CAN_SR_BBSY_Msk

#define    CAN_SR_BIDLE_Pos                                       (4U)
#define    CAN_SR_BIDLE_Msk                                       (0x1U << CAN_SR_BIDLE_Pos)
#define    CAN_SR_BIDLE                                           CAN_SR_BIDLE_Msk

#define    CAN_SR_NORMAL_Pos                                      (3U)
#define    CAN_SR_NORMAL_Msk                                      (0x1U << CAN_SR_NORMAL_Pos)
#define    CAN_SR_NORMAL                                          CAN_SR_NORMAL_Msk

#define    CAN_SR_SLEEP_Pos                                       (2U)
#define    CAN_SR_SLEEP_Msk                                       (0x1U << CAN_SR_SLEEP_Pos)
#define    CAN_SR_SLEEP                                           CAN_SR_SLEEP_Msk

#define    CAN_SR_LBACK_Pos                                       (1U)
#define    CAN_SR_LBACK_Msk                                       (0x1U << CAN_SR_LBACK_Pos)
#define    CAN_SR_LBACK                                           CAN_SR_LBACK_Msk

#define    CAN_SR_CONFIG_Pos                                      (0U)
#define    CAN_SR_CONFIG_Msk                                      (0x1U << CAN_SR_CONFIG_Pos)
#define    CAN_SR_CONFIG                                          CAN_SR_CONFIG_Msk

#define    CAN_RX_ISR_RXFIFO_MC_Pos                               (16U)
#define    CAN_RX_ISR_RXFIFO_MC_Msk                               (0xfU << CAN_RX_ISR_RXFIFO_MC_Pos)
#define    CAN_RX_ISR_RXFIFO_MC                                   CAN_RX_ISR_RXFIFO_MC_Msk

#define    CAN_RX_ISR_BORF_Pos                                    (12U)
#define    CAN_RX_ISR_BORF_Msk                                    (0x1U << CAN_RX_ISR_BORF_Pos)
#define    CAN_RX_ISR_BORF                                        CAN_RX_ISR_BORF_Msk

#define    CAN_RX_ISR_WUPF_Pos                                    (11U)
#define    CAN_RX_ISR_WUPF_Msk                                    (0x1U << CAN_RX_ISR_WUPF_Pos)
#define    CAN_RX_ISR_WUPF                                        CAN_RX_ISR_WUPF_Msk

#define    CAN_RX_ISR_SLPIF_Pos                                   (10U)
#define    CAN_RX_ISR_SLPIF_Msk                                   (0x1U << CAN_RX_ISR_SLPIF_Pos)
#define    CAN_RX_ISR_SLPIF                                       CAN_RX_ISR_SLPIF_Msk

#define    CAN_RX_ISR_ESCF_Pos                                    (9U)
#define    CAN_RX_ISR_ESCF_Msk                                    (0x1U << CAN_RX_ISR_ESCF_Pos)
#define    CAN_RX_ISR_ESCF                                        CAN_RX_ISR_ESCF_Msk

#define    CAN_RX_ISR_ERROR_Pos                                   (8U)
#define    CAN_RX_ISR_ERROR_Msk                                   (0x1U << CAN_RX_ISR_ERROR_Pos)
#define    CAN_RX_ISR_ERROR                                       CAN_RX_ISR_ERROR_Msk

#define    CAN_RX_ISR_RXNEMP_Pos                                  (7U)
#define    CAN_RX_ISR_RXNEMP_Msk                                  (0x1U << CAN_RX_ISR_RXNEMP_Pos)
#define    CAN_RX_ISR_RXNEMP                                      CAN_RX_ISR_RXNEMP_Msk

#define    CAN_RX_ISR_RXOFLW_Pos                                  (6U)
#define    CAN_RX_ISR_RXOFLW_Msk                                  (0x1U << CAN_RX_ISR_RXOFLW_Pos)
#define    CAN_RX_ISR_RXOFLW                                      CAN_RX_ISR_RXOFLW_Msk

#define    CAN_RX_ISR_RXUFLW_Pos                                  (5U)
#define    CAN_RX_ISR_RXUFLW_Msk                                  (0x1U << CAN_RX_ISR_RXUFLW_Pos)
#define    CAN_RX_ISR_RXUFLW                                      CAN_RX_ISR_RXUFLW_Msk

#define    CAN_RX_ISR_RXOK_Pos                                    (4U)
#define    CAN_RX_ISR_RXOK_Msk                                    (0x1U << CAN_RX_ISR_RXOK_Pos)
#define    CAN_RX_ISR_RXOK                                        CAN_RX_ISR_RXOK_Msk

#define    CAN_RX_ISR_ARBLST_Pos                                  (0U)
#define    CAN_RX_ISR_ARBLST_Msk                                  (0x1U << CAN_RX_ISR_ARBLST_Pos)
#define    CAN_RX_ISR_ARBLST                                      CAN_RX_ISR_ARBLST_Msk

#define    CAN_RX_IER_BORFIE_Pos                                  (12U)
#define    CAN_RX_IER_BORFIE_Msk                                  (0x1U << CAN_RX_IER_BORFIE_Pos)
#define    CAN_RX_IER_BORFIE                                      CAN_RX_IER_BORFIE_Msk

#define    CAN_RX_IER_WKUPIE_Pos                                  (11U)
#define    CAN_RX_IER_WKUPIE_Msk                                  (0x1U << CAN_RX_IER_WKUPIE_Pos)
#define    CAN_RX_IER_WKUPIE                                      CAN_RX_IER_WKUPIE_Msk

#define    CAN_RX_IER_SLPIE_Pos                                   (10U)
#define    CAN_RX_IER_SLPIE_Msk                                   (0x1U << CAN_RX_IER_SLPIE_Pos)
#define    CAN_RX_IER_SLPIE                                       CAN_RX_IER_SLPIE_Msk

#define    CAN_RX_IER_EESCFIE_Pos                                 (9U)
#define    CAN_RX_IER_EESCFIE_Msk                                 (0x1U << CAN_RX_IER_EESCFIE_Pos)
#define    CAN_RX_IER_EESCFIE                                     CAN_RX_IER_EESCFIE_Msk

#define    CAN_RX_IER_ERRORIE_Pos                                 (8U)
#define    CAN_RX_IER_ERRORIE_Msk                                 (0x1U << CAN_RX_IER_ERRORIE_Pos)
#define    CAN_RX_IER_ERRORIE                                     CAN_RX_IER_ERRORIE_Msk

#define    CAN_RX_IER_RXNEMPIE_Pos                                (7U)
#define    CAN_RX_IER_RXNEMPIE_Msk                                (0x1U << CAN_RX_IER_RXNEMPIE_Pos)
#define    CAN_RX_IER_RXNEMPIE                                    CAN_RX_IER_RXNEMPIE_Msk

#define    CAN_RX_IER_RXOFLWIE_Pos                                (6U)
#define    CAN_RX_IER_RXOFLWIE_Msk                                (0x1U << CAN_RX_IER_RXOFLWIE_Pos)
#define    CAN_RX_IER_RXOFLWIE                                    CAN_RX_IER_RXOFLWIE_Msk

#define    CAN_RX_IER_RXUFLWIE_Pos                                (5U)
#define    CAN_RX_IER_RXUFLWIE_Msk                                (0x1U << CAN_RX_IER_RXUFLWIE_Pos)
#define    CAN_RX_IER_RXUFLWIE                                    CAN_RX_IER_RXUFLWIE_Msk

#define    CAN_RX_IER_RXOKIE_Pos                                  (4U)
#define    CAN_RX_IER_RXOKIE_Msk                                  (0x1U << CAN_RX_IER_RXOKIE_Pos)
#define    CAN_RX_IER_RXOKIE                                      CAN_RX_IER_RXOKIE_Msk

#define    CAN_RX_IER_ARBLSTIE_Pos                                (0U)
#define    CAN_RX_IER_ARBLSTIE_Msk                                (0x1U << CAN_RX_IER_ARBLSTIE_Pos)
#define    CAN_RX_IER_ARBLSTIE                                    CAN_RX_IER_ARBLSTIE_Msk

#define    CAN_TXBCR_TXAR_Pos                                     (8U)
#define    CAN_TXBCR_TXAR_Msk                                     (0x7U << CAN_TXBCR_TXAR_Pos)
#define    CAN_TXBCR_TXAR                                         CAN_TXBCR_TXAR_Msk

#define    CAN_TXBCR_TXIE_Pos                                     (0U)
#define    CAN_TXBCR_TXIE_Msk                                     (0x7U << CAN_TXBCR_TXIE_Pos)
#define    CAN_TXBCR_TXIE                                         CAN_TXBCR_TXIE_Msk

#define    CAN_TXBSR_TXRF_Pos                                     (8U)
#define    CAN_TXBSR_TXRF_Msk                                     (0x3U << CAN_TXBSR_TXRF_Pos)
#define    CAN_TXBSR_TXRF                                         CAN_TXBSR_TXRF_Msk

#define    CAN_TXBSR_TXS_Pos                                      (3U)
#define    CAN_TXBSR_TXS_Msk                                      (0x7U << CAN_TXBSR_TXS_Pos)
#define    CAN_TXBSR_TXS                                          CAN_TXBSR_TXS_Msk

#define    CAN_TXBSR_TXE0_Pos                                      (0U)
#define    CAN_TXBSR_TXE0_Msk                                      (0x1U << CAN_TXBSR_TXE0_Pos)
#define    CAN_TXBSR_TXE0                                          CAN_TXBSR_TXE0_Msk

#define    CAN_TXBSR_TXE1_Pos                                      (1U)
#define    CAN_TXBSR_TXE1_Msk                                      (0x1U << CAN_TXBSR_TXE1_Pos)
#define    CAN_TXBSR_TXE1                                          CAN_TXBSR_TXE1_Msk

#define    CAN_TXBSR_TXE2_Pos                                      (2U)
#define    CAN_TXBSR_TXE2_Msk                                      (0x1U << CAN_TXBSR_TXE2_Pos)
#define    CAN_TXBSR_TXE2                                          CAN_TXBSR_TXE2_Msk

#define    CAN_TXBIDR_IDR_Pos                                     (0U)
#define    CAN_TXBIDR_IDR_Msk                                     (0xffffffffU << CAN_TXBIDR_IDR_Pos)
#define    CAN_TXBIDR_IDR                                         CAN_TXBIDR_IDR_Msk

#define    CAN_TXBDLCR_DLC_Pos                                    (0U)
#define    CAN_TXBDLCR_DLC_Msk                                    (0xfU << CAN_TXBDLCR_DLC_Pos)
#define    CAN_TXBDLCR_DLC                                        CAN_TXBDLCR_DLC_Msk

#define    CAN_TXBDW1R_DB_Pos                                     (0U)
#define    CAN_TXBDW1R_DB_Msk                                     (0xffffffffU << CAN_TXBDW1R_DB_Pos)
#define    CAN_TXBDW1R_DB                                         CAN_TXBDW1R_DB_Msk

#define    CAN_TXBDW2R_DB_Pos                                     (0U)
#define    CAN_TXBDW2R_DB_Msk                                     (0xffffffffU << CAN_TXBDW2R_DB_Pos)
#define    CAN_TXBDW2R_DB                                         CAN_TXBDW2R_DB_Msk

#define    CAN_RXFIDR_IDR_Pos                                     (0U)
#define    CAN_RXFIDR_IDR_Msk                                     (0xffffffffU << CAN_RXFIDR_IDR_Pos)
#define    CAN_RXFIDR_IDR                                         CAN_RXFIDR_IDR_Msk

#define    CAN_RXFDLCR_DLC_Pos                                    (0U)
#define    CAN_RXFDLCR_DLC_Msk                                    (0xfU << CAN_RXFDLCR_DLC_Pos)
#define    CAN_RXFDLCR_DLC                                        CAN_RXFDLCR_DLC_Msk

#define    CAN_RXFDW1R_DB_Pos                                     (0U)
#define    CAN_RXFDW1R_DB_Msk                                     (0xffffffffU << CAN_RXFDW1R_DB_Pos)
#define    CAN_RXFDW1R_DB                                         CAN_RXFDW1R_DB_Msk

#define    CAN_RXFDW2R_DB_Pos                                     (0U)
#define    CAN_RXFDW2R_DB_Msk                                     (0xffffffffU << CAN_RXFDW2R_DB_Pos)
#define    CAN_RXFDW2R_DB                                         CAN_RXFDW2R_DB_Msk

#define    CAN_AFCR_UAF_Pos                                       (0U)
#define    CAN_AFCR_UAF_Msk                                       (0x1U << CAN_AFCR_UAF_Pos)
#define    CAN_AFCR_UAF                                           CAN_AFCR_UAF_Msk

#define    CAN_AFCFGR_MSKM_Pos                                    (16U)
#define    CAN_AFCFGR_MSKM_Msk                                    (0x1U << CAN_AFCFGR_MSKM_Pos)
#define    CAN_AFCFGR_MSKM                                        CAN_AFCFGR_MSKM_Msk

#define    CAN_AFCFGR_FSC_Pos                                     (0U)
#define    CAN_AFCFGR_FSC_Msk                                     (0x1U << CAN_AFCFGR_FSC_Pos)
#define    CAN_AFCFGR_FSC                                         CAN_AFCFGR_FSC_Msk

#define    CAN_AFMR_AMRTR_Pos                                     (31U)
#define    CAN_AFMR_AMRTR_Msk                                     (0x1U << CAN_AFMR_AMRTR_Pos)
#define    CAN_AFMR_AMRTR                                         CAN_AFMR_AMRTR_Msk

#define    CAN_AFMR_AMID18_Pos                                    (13U)
#define    CAN_AFMR_AMID18_Msk                                    (0x3ffffU << CAN_AFMR_AMID18_Pos)
#define    CAN_AFMR_AMID18                                        CAN_AFMR_AMID18_Msk

#define    CAN_AFMR_AMIDE_Pos                                     (12U)
#define    CAN_AFMR_AMIDE_Msk                                     (0x1U << CAN_AFMR_AMIDE_Pos)
#define    CAN_AFMR_AMIDE                                         CAN_AFMR_AMIDE_Msk

#define    CAN_AFMR_AMSRR_Pos                                     (11U)
#define    CAN_AFMR_AMSRR_Msk                                     (0x1U << CAN_AFMR_AMSRR_Pos)
#define    CAN_AFMR_AMSRR                                         CAN_AFMR_AMSRR_Msk

#define    CAN_AFMR_AMID11_Pos                                    (0U)
#define    CAN_AFMR_AMID11_Msk                                    (0x7ffU << CAN_AFMR_AMID11_Pos)
#define    CAN_AFMR_AMID11                                        CAN_AFMR_AMID11_Msk

#define    CAN_AFMRSTD2_AMID3_Pos                                 (29U)
#define    CAN_AFMRSTD2_AMID3_Msk                                 (0x7U << CAN_AFMRSTD2_AMID3_Pos)
#define    CAN_AFMRSTD2_AMID3                                      CAN_AFMRSTD2_AMID3_Msk

#define    CAN_AFMRSTD2_AMIDE_Pos                                 (28U)
#define    CAN_AFMRSTD2_AMIDE_Msk                                 (0x1U << CAN_AFMRSTD2_AMIDE_Pos)
#define    CAN_AFMRSTD2_AMIDE                                      CAN_AFMRSTD2_AMIDE_Msk

#define    CAN_AFMRSTD2_AMSRR_Pos                                 (27U)
#define    CAN_AFMRSTD2_AMSRR_Msk                                 (0x1U << CAN_AFMRSTD2_AMSRR_Pos)
#define    CAN_AFMRSTD2_AMSRR                                      CAN_AFMRSTD2_AMSRR_Msk

#define    CAN_AFMRSTD2_AMID11_Pos                                (16U)
#define    CAN_AFMRSTD2_AMID11_Msk                                (0x7ffU << CAN_AFMRSTD2_AMID11_Pos)
#define    CAN_AFMRSTD2_AMID11                                     CAN_AFMRSTD2_AMID11_Msk

#define    CAN_AFMRSTD1_AMID3_Pos                                 (13U)
#define    CAN_AFMRSTD1_AMID3_Msk                                 (0x7U << CAN_AFMRSTD1_AMID3_Pos)
#define    CAN_AFMRSTD1_AMID3                                      CAN_AFMRSTD1_AMID3_Msk

#define    CAN_AFMRSTD1_AMIDE_Pos                                 (12U)
#define    CAN_AFMRSTD1_AMIDE_Msk                                 (0x1U << CAN_AFMRSTD1_AMIDE_Pos)
#define    CAN_AFMRSTD1_AMIDE                                     CAN_AFMRSTD1_AMIDE_Msk

#define    CAN_AFMRSTD1_AMSRR_Pos                                 (11U)
#define    CAN_AFMRSTD1_AMSRR_Msk                                 (0x1U << CAN_AFMRSTD1_AMSRR_Pos)
#define    CAN_AFMRSTD1_AMSRR                                      CAN_AFMRSTD1_AMSRR_Msk

#define    CAN_AFMRSTD1_AMID11_Pos                                (0U)
#define    CAN_AFMRSTD1_AMID11_Msk                                (0x7ffU << CAN_AFMRSTD1_AMID11_Pos)
#define    CAN_AFMRSTD1_AMID11                                    CAN_AFMRSTD1_AMID11_Msk

#define    CAN_AFIR_AIRTR_Pos                                     (31U)
#define    CAN_AFIR_AIRTR_Msk                                     (0x1U << CAN_AFIR_AIRTR_Pos)
#define    CAN_AFIR_AIRTR                                         CAN_AFIR_AIRTR_Msk

#define    CAN_AFIR_AIID18_Pos                                    (13U)
#define    CAN_AFIR_AIID18_Msk                                    (0x3ffffU << CAN_AFIR_AIID18_Pos)
#define    CAN_AFIR_AIID18                                        CAN_AFIR_AIID18_Msk

#define    CAN_AFIR_AIIDE_Pos                                     (12U)
#define    CAN_AFIR_AIIDE_Msk                                     (0x1U << CAN_AFIR_AIIDE_Pos)
#define    CAN_AFIR_AIIDE                                         CAN_AFIR_AIIDE_Msk

#define    CAN_AFIR_AISRR_Pos                                     (11U)
#define    CAN_AFIR_AISRR_Msk                                     (0x1U << CAN_AFIR_AISRR_Pos)
#define    CAN_AFIR_AISRR                                         CAN_AFIR_AISRR_Msk

#define    CAN_AFIR_AIID11_Pos                                    (0U)
#define    CAN_AFIR_AIID11_Msk                                    (0x7ffU << CAN_AFIR_AIID11_Pos)
#define    CAN_AFIR_AIID11                                        CAN_AFIR_AIID11_Msk

#define    CAN_AFIRSTD2_AIID3_Pos                                  (29U)
#define    CAN_AFIRSTD2_AIID3_Msk                                  (0x7U << CAN_AFIRSTD2_AIID3_Pos)
#define    CAN_AFIRSTD2_AIID3                                      CAN_AFIRSTD2_AIID3_Msk

#define    CAN_AFIRSTD2_AIIDE_Pos                                  (28U)
#define    CAN_AFIRSTD2_AIIDE_Msk                                  (0x1U << CAN_AFIRSTD2_AIIDE_Pos)
#define    CAN_AFIRSTD2_AIIDE                                      CAN_AFIRSTD2_AIIDE_Msk

#define    CAN_AFIRSTD2_AISRR_Pos                                  (27U)
#define    CAN_AFIRSTD2_AISRR_Msk                                  (0x1U << CAN_AFIRSTD2_AISRR_Pos)
#define    CAN_AFIRSTD2_AISRR                                      CAN_AFIRSTD2_AISRR_Msk

#define    CAN_AFIRSTD2_AIID11_Pos                                 (16U)
#define    CAN_AFIRSTD2_AIID11_Msk                                 (0x7ffU << CAN_AFIRSTD2_AIID11_Pos)
#define    CAN_AFIRSTD2_AIID11                                     CAN_AFIRSTD2_AIID11_Msk

#define    CAN_AFIRSTD1_AIID3_Pos                                  (13U)
#define    CAN_AFIRSTD1_AIID3_Msk                                  (0x7U << CAN_AFIRSTD1_AIID3_Pos)
#define    CAN_AFIRSTD1_AIID3                                      CAN_AFIRSTD1_AIID3_Msk

#define    CAN_AFIRSTD1_AIIDE_Pos                                  (12U)
#define    CAN_AFIRSTD1_AIIDE_Msk                                  (0x1U << CAN_AFIRSTD1_AIIDE_Pos)
#define    CAN_AFIRSTD1_AIIDE                                      CAN_AFIRSTD1_AIIDE_Msk

#define    CAN_AFIRSTD1_AISRR_Pos                                  (11U)
#define    CAN_AFIRSTD1_AISRR_Msk                                  (0x1U << CAN_AFIRSTD1_AISRR_Pos)
#define    CAN_AFIRSTD1_AISRR                                      CAN_AFIRSTD1_AISRR_Msk

#define    CAN_AFIRSTD1_AIID11_Pos                                 (0U)
#define    CAN_AFIRSTD1_AIID11_Msk                                 (0x7ffU << CAN_AFIRSTD1_AIID11_Pos)
#define    CAN_AFIRSTD1_AIID11                                     CAN_AFIRSTD1_AIID11_Msk

#define    FL_CAN_SOFTWARE_NO_RESET                               (0x0U << CAN_CR_SRST_Pos)
#define    FL_CAN_SOFTWARE_RESET                                  (0x1U << CAN_CR_SRST_Pos)

#define    FL_CAN_TX_PRIORITY_ID                                  (0x0U << CAN_MSR_TPRI_Pos)
#define    FL_CAN_TX_PRIORITY_BUFFER                              (0x1U << CAN_MSR_TPRI_Pos)

#define    FL_CAN_AUTO_MANAGE_HARDWARE                            (0x0U << CAN_MSR_ABOM_Pos)
#define    FL_CAN_AUTO_MANAGE_SOFTWARE_WAIT                       (0x1U << CAN_MSR_ABOM_Pos)
#define    FL_CAN_AUTO_MANAGE_SOFTWARE_INTERGRATION               (0x2U << CAN_MSR_ABOM_Pos)

#define    FL_CAN_RX_STATUS_NORMAL                                (0x0U << CAN_SR_RSTS_Pos)
#define    FL_CAN_RX_STATUS_WARNING                               (0x1U << CAN_SR_RSTS_Pos)
#define    FL_CAN_RX_STATUS_ERROR                                 (0x2U << CAN_SR_RSTS_Pos)
#define    FL_CAN_RX_STATUS_BUSOFF                               (0x3U << CAN_SR_RSTS_Pos)

#define    FL_CAN_TX_STATUS_NORMAL                                (0x0U << CAN_SR_TSTS_Pos)
#define    FL_CAN_TX_STATUS_WARNING                               (0x1U << CAN_SR_TSTS_Pos)
#define    FL_CAN_TX_STATUS_ERROR                                 (0x2U << CAN_SR_TSTS_Pos)
#define    FL_CAN_TX_STATUS_BUSOFF                               (0x3U << CAN_SR_TSTS_Pos)

#define    FL_CAN_TX_ABORT_NONE                                   (0x0U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_BUFFER_0                               (0x1U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_BUFFER_1                               (0x2U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_BUFFER_0AND1                           (0x3U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_BUFFER_2                               (0x4U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_BUFFER_0AND2                           (0x5U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_BUFFER_1AND2                           (0x6U << CAN_TXBCR_TXAR_Pos)
#define    FL_CAN_TX_ABORT_ALL                                    (0x7U << CAN_TXBCR_TXAR_Pos)

#define    FL_CAN_TX_RESULT_NONE                                  (0x0U << CAN_TXBSR_TXRF_Pos)
#define    FL_CAN_TX_RESULT_ABORT                                 (0x1U << CAN_TXBSR_TXRF_Pos)
#define    FL_CAN_TX_RESULT_OK_NOABORT                            (0x2U << CAN_TXBSR_TXRF_Pos)
#define    FL_CAN_TX_RESULT_OK_ABORT                              (0x3U << CAN_TXBSR_TXRF_Pos)

#define    FL_CAN_TX_BUFFER_ALL_IDLE                              (0x0U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_0_BUSY                                (0x1U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_1_BUSY                                (0x2U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_0AND1_BUSY                            (0x3U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_2_BUSY                                (0x4U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_0AND2_BUSY                            (0x5U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_1AND2_BUSY                            (0x6U << CAN_TXBSR_TXS_Pos)
#define    FL_CAN_TX_BUFFER_ALL_BUSY                              (0x7U << CAN_TXBSR_TXS_Pos)

#define    FL_CAN_RTR_BIT_LOW                                     (0x0U << CAN_AFIR_AIRTR_Pos)
#define    FL_CAN_RTR_BIT_HIGH                                    (0x1U << CAN_AFIR_AIRTR_Pos)

#define    FL_CAN_IDE_BIT_LOW                                     (0x0U << CAN_AFIR_AIIDE_Pos)
#define    FL_CAN_IDE_BIT_HIGH                                    (0x1U << CAN_AFIR_AIIDE_Pos)

#define    FL_CAN_SRR_BIT_LOW                                     (0x0U << CAN_AFIR_AISRR_Pos)
#define    FL_CAN_SRR_BIT_HIGH                                    (0x1U << CAN_AFIR_AISRR_Pos)

#define    FL_CAN_STD1IDE_BIT_LOW                               (0x0U << CAN_AFIRSTD1_AIIDE_Pos)
#define    FL_CAN_STD1IDE_BIT_HIGH                              (0x1U << CAN_AFIRSTD1_AIIDE_Pos)

#define    FL_CAN_STD1SRR_BIT_LOW                               (0x0U << CAN_AFIRSTD1_AISRR_Pos)
#define    FL_CAN_STD1SRR_BIT_HIGH                              (0x1U << CAN_AFIRSTD1_AISRR_Pos)

#define    FL_CAN_STD2IDE_BIT_LOW                               (0x0U << CAN_AFIRSTD2_AIIDE_Pos)
#define    FL_CAN_STD2IDE_BIT_HIGH                              (0x1U << CAN_AFIRSTD2_AIIDE_Pos)

#define    FL_CAN_STD2SRR_BIT_LOW                               (0x0U << CAN_AFIRSTD2_AISRR_Pos)
#define    FL_CAN_STD2SRR_BIT_HIGH                              (0x1U << CAN_AFIRSTD2_AISRR_Pos)

#define    FL_CAN_MASKMODE_ID                                     (0x1U << CAN_AFCFGR_MSKM_Pos)
#define    FL_CAN_MASKMODE_MASK                                   (0x0U << CAN_AFCFGR_MSKM_Pos)

#define    FL_CAN_IDMODE_16BIT                                     (0x1U << CAN_AFCFGR_FSC_Pos)
#define    FL_CAN_IDMODE_32BIT                                     (0x0U << CAN_AFCFGR_FSC_Pos)

#define    FL_CAN_FILTER1                                         0x0U
#define    FL_CAN_FILTER2                                         0x1U
#define    FL_CAN_FILTER3                                         0x2U
#define    FL_CAN_FILTER4                                         0x3U
#define    FL_CAN_FILTER5                                         0x4U
#define    FL_CAN_FILTER6                                         0x5U
#define    FL_CAN_FILTER7                                         0x6U
#define    FL_CAN_FILTER8                                         0x7U
#define    FL_CAN_FILTER9                                         0x8U
#define    FL_CAN_FILTER10                                        0x9U
#define    FL_CAN_FILTER11                                        0xAU
#define    FL_CAN_FILTER12                                        0xBU
#define    FL_CAN_FILTER13                                        0xCU
#define    FL_CAN_FILTER14                                        0xDU
#define    FL_CAN_FILTER15                                        0xEU
#define    FL_CAN_FILTER16                                        0xFU

#define    FL_CAN_BUFFER0                                         0x1U<<0U
#define    FL_CAN_BUFFER1                                         0x1U<<1U
#define    FL_CAN_BUFFER2                                         0x1U<<2U

#define FL_CAN_TS1_1Tq  0U
#define FL_CAN_TS1_2Tq  1U
#define FL_CAN_TS1_3Tq  2U
#define FL_CAN_TS1_4Tq  3U
#define FL_CAN_TS1_5Tq  4U
#define FL_CAN_TS1_6Tq  5U
#define FL_CAN_TS1_7Tq  6U
#define FL_CAN_TS1_8Tq  7U
#define FL_CAN_TS1_9Tq  8U
#define FL_CAN_TS1_10Tq  9U
#define FL_CAN_TS1_11Tq  10U
#define FL_CAN_TS1_12Tq  11U
#define FL_CAN_TS1_13Tq  12U
#define FL_CAN_TS1_14Tq  13U
#define FL_CAN_TS1_15Tq  14U
#define FL_CAN_TS1_16Tq  15U

#define FL_CAN_TS2_1Tq  0U
#define FL_CAN_TS2_2Tq  1U
#define FL_CAN_TS2_3Tq  2U
#define FL_CAN_TS2_4Tq  3U
#define FL_CAN_TS2_5Tq  4U
#define FL_CAN_TS2_6Tq  5U
#define FL_CAN_TS2_7Tq  6U
#define FL_CAN_TS2_8Tq  7U

#define FL_CAN_SJW_1Tq  0U
#define FL_CAN_SJW_2Tq  1U
#define FL_CAN_SJW_3Tq  2U
#define FL_CAN_SJW_4Tq  3U

#define FL_CAN_MODE_NORMAL    0U
#define FL_CAN_MODE_LOOPBACK  1U
#define FL_CAN_MODE_CONFIG    2U
#define FL_CAN_MODE_SLEEP     3U

#define FL_CAN_FORMAT_STANDARD_DATA    0
#define FL_CAN_FORMAT_STANDARD_REMOTE  1
#define FL_CAN_FORMAT_EXTEND_DATA      2
#define FL_CAN_FORMAT_EXTEND_REMOTE    3

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CAN_FL_Exported_Functions CAN Exported Functions
  * @{
  */

/**
  * @brief    CAN enable
  * @rmtoll   CR    CEN    FL_CAN_Enable
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_Enable(CAN_Type *CANx)
{
    SET_BIT(CANx->CR, CAN_CR_CEN_Msk);
}

/**
  * @brief    Get CAN enable status
  * @rmtoll   CR    CEN    FL_CAN_IsEnabled
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabled(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->CR, CAN_CR_CEN_Msk) == CAN_CR_CEN_Msk);
}

/**
  * @brief    CAN disable
  * @rmtoll   CR    CEN    FL_CAN_Disable
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_Disable(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->CR, CAN_CR_CEN_Msk);
}

/**
  * @brief    Set CAN software reset
  * @rmtoll   CR    SRST    FL_CAN_EnableSoftwareReset
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableSoftwareReset(CAN_Type *CANx)
{
    SET_BIT(CANx->CR, CAN_CR_SRST_Msk);
}

/**
  * @brief    Rx Presync enable
  * @rmtoll   MSR    RX_PRESYNC_EN    FL_CAN_EnableRXPresync
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableRXPresync(CAN_Type *CANx)
{
    SET_BIT(CANx->MSR, CAN_MSR_RX_PRESYNC_EN_Msk);
}

/**
  * @brief    Rx Presync disable
  * @rmtoll   MSR    RX_PRESYNC_EN    FL_CAN_DisableRXPresync
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableRXPresync(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->MSR, CAN_MSR_RX_PRESYNC_EN_Msk);
}

/**
  * @brief    Get Rx Presync enable status
  * @rmtoll   MSR    RX_PRESYNC_EN    FL_CAN_IsEnabledRXPresync
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledRXPresync(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_RX_PRESYNC_EN_Msk) == CAN_MSR_RX_PRESYNC_EN_Msk);
}

/**
  * @brief    Set TX priority
  * @rmtoll   MSR    TPRI    FL_CAN_SetTXPriority
  * @param    CANx CAN instance
  * @param    priority This parameter can be one of the following values:
  *           @arg @ref FL_CAN_TX_PRIORITY_ID
  *           @arg @ref FL_CAN_TX_PRIORITY_BUFFER
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_SetTXPriority(CAN_Type *CANx, uint32_t priority)
{
    MODIFY_REG(CANx->MSR, CAN_MSR_TPRI_Msk, priority);
}

/**
  * @brief    Get Tx priority
  * @rmtoll   MSR    TPRI    FL_CAN_GetTXPriority
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_TX_PRIORITY_ID
  *           @arg @ref FL_CAN_TX_PRIORITY_BUFFER
  */
__STATIC_INLINE uint32_t FL_CAN_GetTXPriority(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_TPRI_Msk));
}

/**
  * @brief    wakeup enable
  * @rmtoll   MSR    WUPE    FL_CAN_EnableWakeup
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableWakeup(CAN_Type *CANx)
{
    SET_BIT(CANx->MSR, CAN_MSR_WUPE_Msk);
}

/**
  * @brief    wakeup disable
  * @rmtoll   MSR    WUPE    FL_CAN_DisableWakeup
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableWakeup(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->MSR, CAN_MSR_WUPE_Msk);
}

/**
  * @brief    Get wakeup enable status
  * @rmtoll   MSR    WUPE    FL_CAN_IsEnabledWakeup
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledWakeup(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_WUPE_Msk) == CAN_MSR_WUPE_Msk);
}

/**
  * @brief    Auto resend enable
  * @rmtoll   MSR    AREN    FL_CAN_EnableAutoResend
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableAutoResend(CAN_Type *CANx)
{
    SET_BIT(CANx->MSR, CAN_MSR_AREN_Msk);
}

/**
  * @brief    Auto resend disable
  * @rmtoll   MSR    AREN    FL_CAN_DisableAutoResend
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableAutoResend(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->MSR, CAN_MSR_AREN_Msk);
}

/**
  * @brief    Get Auto resend enable status
  * @rmtoll   MSR    AREN    FL_CAN_IsEnabledAutoResend
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledAutoResend(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_AREN_Msk) == CAN_MSR_AREN_Msk);
}

/**
  * @brief    Set auto bus off management
  * @rmtoll   MSR    ABOM    FL_CAN_SetAutoBusOffManagement
  * @param    CANx CAN instance
  * @param    state This parameter can be one of the following values:
  *           @arg @ref FL_CAN_AUTO_MANAGE_HARDWARE
  *           @arg @ref FL_CAN_AUTO_MANAGE_SOFTWARE_WAIT
  *           @arg @ref FL_CAN_AUTO_MANAGE_SOFTWARE_INTEERGRATION
  *           @arg @ref FL_CAN_AUTO_MANAGE_HARDWARE
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_SetAutoBusOffManagement(CAN_Type *CANx, uint32_t state)
{
    MODIFY_REG(CANx->MSR, CAN_MSR_ABOM_Msk, state);
}

/**
  * @brief    Get auto bus off management
  * @rmtoll   MSR    ABOM    FL_CAN_GetAutoBusOffManagement
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_AUTO_MANAGE_HARDWARE
  *           @arg @ref FL_CAN_AUTO_MANAGE_SOFTWARE_WAIT
  *           @arg @ref FL_CAN_AUTO_MANAGE_SOFTWARE_INTEERGRATION
  *           @arg @ref FL_CAN_AUTO_MANAGE_HARDWARE
  */
__STATIC_INLINE uint32_t FL_CAN_GetAutoBusOffManagement(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_ABOM_Msk));
}

/**
  * @brief    Software exit busoff enable
  * @rmtoll   MSR    RTBO    FL_CAN_EnableSoftwareExitBusoff
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableSoftwareExitBusoff(CAN_Type *CANx)
{
    SET_BIT(CANx->MSR, CAN_MSR_RTBO_Msk);
}

/**
  * @brief    Software exit busoff disable
  * @rmtoll   MSR    RTBO    FL_CAN_DisableSoftwareExitBusoff
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableSoftwareExitBusoff(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->MSR, CAN_MSR_RTBO_Msk);
}

/**
  * @brief    Get software exit busoff enable status
  * @rmtoll   MSR    RTBO    FL_CAN_IsEnabledSoftwareExitBusoff
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledSoftwareExitBusoff(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_RTBO_Msk) == CAN_MSR_RTBO_Msk);
}

/**
  * @brief    Enable loop back mode
  * @rmtoll   MSR    LPBACK    FL_CAN_EnableLoopBackMode
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableLoopBackMode(CAN_Type *CANx)
{
    SET_BIT(CANx->MSR, CAN_MSR_LPBACK_Msk);
}

/**
  * @brief    Disable loop back mode
  * @rmtoll   MSR    LPBACK    FL_CAN_DisableLoopBackMode
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableLoopBackMode(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->MSR, CAN_MSR_LPBACK_Msk);
}

/**
  * @brief    Get loop back mode Enable Status
  * @rmtoll   MSR    LPBACK    FL_CAN_IsEnabledLoopBackMode
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledLoopBackMode(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_LPBACK_Msk) == CAN_MSR_LPBACK_Msk);
}

/**
  * @brief    Enable Sleep mode
  * @rmtoll   MSR    SLEEP    FL_CAN_EnableSleepMode
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableSleepMode(CAN_Type *CANx)
{
    SET_BIT(CANx->MSR, CAN_MSR_SLEEP_Msk);
}

/**
  * @brief    Disable Sleep mode
  * @rmtoll   MSR    SLEEP    FL_CAN_DisableSleepMode
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableSleepMode(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->MSR, CAN_MSR_SLEEP_Msk);
}

/**
  * @brief    Get Sleep mode Enable Status
  * @rmtoll   MSR    SLEEP    FL_CAN_IsEnabledSleepMode
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledSleepMode(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->MSR, CAN_MSR_SLEEP_Msk) == CAN_MSR_SLEEP_Msk);
}

/**
  * @brief    Set baud rate prescaler
  * @rmtoll   BRPR    BRP    FL_CAN_WriteBaudRatePrescaler
  * @param    CANx CAN instance
  * @param    psc
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteBaudRatePrescaler(CAN_Type *CANx, uint32_t psc)
{
    MODIFY_REG(CANx->BRPR, CAN_BRPR_BRP_Msk, (psc << CAN_BRPR_BRP_Pos));
}

/**
  * @brief    Get baud rate prescaler
  * @rmtoll   BRPR    BRP    FL_CAN_ReadBaudRatePrescaler
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadBaudRatePrescaler(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->BRPR, CAN_BRPR_BRP_Msk) >> CAN_BRPR_BRP_Pos);
}

/**
  * @brief    Set synchronization jump width
  * @rmtoll   BTR    SJW    FL_CAN_WriteSyncJumpWidth
  * @param    CANx CAN instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteSyncJumpWidth(CAN_Type *CANx, uint32_t width)
{
    MODIFY_REG(CANx->BTR, CAN_BTR_SJW_Msk, (width << CAN_BTR_SJW_Pos));
}

/**
  * @brief    Get synchronization jump width
  * @rmtoll   BTR    SJW    FL_CAN_ReadSyncJumpWidth
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadSyncJumpWidth(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->BTR, CAN_BTR_SJW_Msk) >> CAN_BTR_SJW_Pos);
}

/**
  * @brief    Set time segment2 length
  * @rmtoll   BTR    TS2    FL_CAN_WriteTimeSegment2Length
  * @param    CANx CAN instance
  * @param    length
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteTimeSegment2Length(CAN_Type *CANx, uint32_t length)
{
    MODIFY_REG(CANx->BTR, CAN_BTR_TS2_Msk, (length << CAN_BTR_TS2_Pos));
}

/**
  * @brief    Get time segment2 length
  * @rmtoll   BTR    TS2    FL_CAN_ReadTimeSegment2Length
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTimeSegment2Length(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->BTR, CAN_BTR_TS2_Msk) >> CAN_BTR_TS2_Pos);
}

/**
  * @brief    Set time segment1 length
  * @rmtoll   BTR    TS1    FL_CAN_WriteTimeSegment1Length
  * @param    CANx CAN instance
  * @param    length
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteTimeSegment1Length(CAN_Type *CANx, uint32_t length)
{
    MODIFY_REG(CANx->BTR, CAN_BTR_TS1_Msk, (length << CAN_BTR_TS1_Pos));
}

/**
  * @brief    Get time segment1 length
  * @rmtoll   BTR    TS1    FL_CAN_ReadTimeSegment1Length
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTimeSegment1Length(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->BTR, CAN_BTR_TS1_Msk) >> CAN_BTR_TS1_Pos);
}

/**
  * @brief    Get receive error number
  * @rmtoll   ECR    REC    FL_CAN_ReadRXErrorCount
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadRXErrorCount(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ECR, CAN_ECR_REC_Msk) >> CAN_ECR_REC_Pos);
}

/**
  * @brief    Get transmit error number
  * @rmtoll   ECR    TEC    FL_CAN_ReadTXErrorCount
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTXErrorCount(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ECR, CAN_ECR_TEC_Msk) >> CAN_ECR_TEC_Pos);
}

/**
  * @brief    Get Overload flag
  * @rmtoll   ESR    OVLF    FL_CAN_IsActiveFlag_Overload
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Overload(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_OVLF_Msk) == (CAN_ESR_OVLF_Msk));
}

/**
  * @brief    Clear Overload flag
  * @rmtoll   ESR    OVLF    FL_CAN_ClearFlag_Overload
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Overload(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_OVLF_Msk);
}

/**
  * @brief    Get Bus Lock flag
  * @rmtoll   ESR    BLF    FL_CAN_IsActiveFlag_Buslock
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Buslock(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_BLF_Msk) == (CAN_ESR_BLF_Msk));
}

/**
  * @brief    Clear Bus Lock flag
  * @rmtoll   ESR    BLF    FL_CAN_ClearFlag_Buslock
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Buslock(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_BLF_Msk);
}

/**
  * @brief    Get ACK Delimiter error flag
  * @rmtoll   ESR    ADERR    FL_CAN_IsActiveFlag_AckDelimiterError
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_AckDelimiterError(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_ADERR_Msk) == (CAN_ESR_ADERR_Msk));
}

/**
  * @brief    Clear ACK Delimiter error flag
  * @rmtoll   ESR    ADERR    FL_CAN_ClearFlag_AckDelimiterError
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_AckDelimiterError(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_ADERR_Msk);
}

/**
  * @brief    Get ACK error flag
  * @rmtoll   ESR    ACKER    FL_CAN_IsActiveFlag_AckError
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_AckError(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_ACKER_Msk) == (CAN_ESR_ACKER_Msk));
}

/**
  * @brief    Clear ACK error flag
  * @rmtoll   ESR    ACKER    FL_CAN_ClearFlag_AckError
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_AckError(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_ACKER_Msk);
}

/**
  * @brief    Get receive bit 0 error flag
  * @rmtoll   ESR    B0ERR    FL_CAN_IsActiveFlag_Bit0Error
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Bit0Error(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_B0ERR_Msk) == (CAN_ESR_B0ERR_Msk));
}

/**
  * @brief    Clear receive bit 0 error flag
  * @rmtoll   ESR    B0ERR    FL_CAN_ClearFlag_Bit0Error
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Bit0Error(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_B0ERR_Msk);
}

/**
  * @brief    Get receive bit 1 error flag
  * @rmtoll   ESR    B1ERR    FL_CAN_IsActiveFlag_Bit1Error
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Bit1Error(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_B1ERR_Msk) == (CAN_ESR_B1ERR_Msk));
}

/**
  * @brief    Clear receive bit 1 error flag
  * @rmtoll   ESR    B1ERR    FL_CAN_ClearFlag_Bit1Error
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Bit1Error(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_B1ERR_Msk);
}

/**
  * @brief    Get stuffing error flag
  * @rmtoll   ESR    STER    FL_CAN_IsActiveFlag_StuffError
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_StuffError(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_STER_Msk) == (CAN_ESR_STER_Msk));
}

/**
  * @brief    Clear stuffing error flag
  * @rmtoll   ESR    STER    FL_CAN_ClearFlag_StuffError
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_StuffError(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_STER_Msk);
}

/**
  * @brief    Get form error flag
  * @rmtoll   ESR    FMER    FL_CAN_IsActiveFlag_FormatError
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_FormatError(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_FMER_Msk) == (CAN_ESR_FMER_Msk));
}

/**
  * @brief    Clear form error flag
  * @rmtoll   ESR    FMER    FL_CAN_ClearFlag_FormatError
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_FormatError(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_FMER_Msk);
}

/**
  * @brief    Get CRC error fiag
  * @rmtoll   ESR    CRCER    FL_CAN_IsActiveFlag_CRCError
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_CRCError(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->ESR, CAN_ESR_CRCER_Msk) == (CAN_ESR_CRCER_Msk));
}

/**
  * @brief    Clear CRC error flag
  * @rmtoll   ESR    CRCER    FL_CAN_ClearFlag_CRCError
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_CRCError(CAN_Type *CANx)
{
    WRITE_REG(CANx->ESR, CAN_ESR_CRCER_Msk);
}

/**
  * @brief    Get acceptance filter busy flag
  * @rmtoll   SR    ACFBSY    FL_CAN_IsActiveFlag_FilterBusy
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_FilterBusy(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_ACFBSY_Msk) == (CAN_SR_ACFBSY_Msk));
}

/**
  * @brief    Get transmit FIFO FULL interrupt flag
  * @rmtoll   SR    RXFE    FL_CAN_IsActiveFlag_RXBuffEmpty
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_RXBufferEmpty(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_RXFE_Msk) == (CAN_SR_RXFE_Msk));
}

/**
  * @brief    Get RX error status
  * @rmtoll   SR    RSTS    FL_CAN_GetRXErrorStatus
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_RX_STATUS_NORMAL
  *           @arg @ref FL_CAN_RX_STATUS_WARNING
  *           @arg @ref FL_CAN_RX_STATUS_ERROR
  *           @arg @ref FL_CAN_RX_STATUS_BUS_OFF
  */
__STATIC_INLINE uint32_t FL_CAN_GetRXErrorStatus(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_RSTS_Msk));
}

/**
  * @brief    Get TX error status
  * @rmtoll   SR    TSTS    FL_CAN_GetTXErrorStatus
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_TX_STATUS_NORMAL
  *           @arg @ref FL_CAN_TX_STATUS_WARNING
  *           @arg @ref FL_CAN_TX_STATUS_ERROR
  *           @arg @ref FL_CAN_TX_STATUS_BUS_OFF
  */
__STATIC_INLINE uint32_t FL_CAN_GetTXErrorStatus(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_TSTS_Msk));
}

/**
  * @brief    Get bus busy flag
  * @rmtoll   SR    BBSY    FL_CAN_IsActiveFlag_BusBusy
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_BusBusy(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_BBSY_Msk) == (CAN_SR_BBSY_Msk));
}

/**
  * @brief    Get bus IDLE flag
  * @rmtoll   SR    BIDLE    FL_CAN_IsActiveFlag_BusIdle
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_BusIdle(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_BIDLE_Msk) == (CAN_SR_BIDLE_Msk));
}

/**
  * @brief    Get normal mode flag
  * @rmtoll   SR    NORMAL    FL_CAN_IsActiveFlag_NormalMode
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_NormalMode(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_NORMAL_Msk) == (CAN_SR_NORMAL_Msk));
}

/**
  * @brief    Get sleep mode flag
  * @rmtoll   SR    SLEEP    FL_CAN_IsActiveFlag_Sleep
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_SleepMode(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_SLEEP_Msk) == (CAN_SR_SLEEP_Msk));
}

/**
  * @brief    Get loop back mode flag
  * @rmtoll   SR    LBACK    FL_CAN_IsActiveFlag_LoopbackMode
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_LoopbackMode(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_LBACK_Msk) == (CAN_SR_LBACK_Msk));
}

/**
  * @brief    Get configuration mode flag
  * @rmtoll   SR    CONFIG    FL_CAN_IsActiveFlag_ConfigMode
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_ConfigMode(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->SR, CAN_SR_CONFIG_Msk) == (CAN_SR_CONFIG_Msk));
}

/**
  * @brief    Get bus off recovery interrupt flag
  * @rmtoll   RX_ISR    BORF    FL_CAN_IsActiveFlag_BusOffRecovery
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_BusOffRecovery(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_BORF_Msk) == (CAN_RX_ISR_BORF_Msk));
}

/**
  * @brief    Clear bus off recovery interrupt flag
  * @rmtoll   RX_ISR    BORF    FL_CAN_ClearFlag_ErrorStatusChange
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_BusOffRecovery(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_BORF_Msk);
}

/**
  * @brief    Get wakeup interrupt flag
  * @rmtoll   RX_ISR    WUPF    FL_CAN_IsActiveFlag_Wakeup
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Wakeup(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_WUPF_Msk) == (CAN_RX_ISR_WUPF_Msk));
}

/**
  * @brief    Clear wakeup interrupt flag
  * @rmtoll   RX_ISR    WUPF    FL_CAN_ClearFlag_Wakeup
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Wakeup(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_WUPF_Msk);
}

/**
  * @brief    Get wakeup interrupt flag
  * @rmtoll   RX_ISR    SLPIF    FL_CAN_IsActiveFlag_Sleep
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Sleep(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_SLPIF_Msk) == (CAN_RX_ISR_SLPIF_Msk));
}

/**
  * @brief    Clear sleep interrupt flag
  * @rmtoll   RX_ISR    SLPIF    FL_CAN_ClearFlag_Sleep
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Sleep(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_SLPIF_Msk);
}

/**
  * @brief    Get error status change interrupt flag
  * @rmtoll   RX_ISR    ESCF    FL_CAN_IsActiveFlag_ErrorChange
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_ErrorChange(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_ESCF_Msk) == (CAN_RX_ISR_ESCF_Msk));
}

/**
  * @brief    Clear error status change interrupt flag
  * @rmtoll   RX_ISR    ESCF    FL_CAN_ClearFlag_ErrorChange
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_ErrorChange(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_ESCF_Msk);
}

/**
  * @brief    Get error interrupt  flag
  * @rmtoll   RX_ISR    ERROR    FL_CAN_IsActiveFlag_Error
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_Error(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_ERROR_Msk) == (CAN_RX_ISR_ERROR_Msk));
}

/**
  * @brief    Clear error interrupt flag
  * @rmtoll   RX_ISR    ERROR    FL_CAN_ClearFlag_Error
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_Error(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_ERROR_Msk);
}

/**
  * @brief    Get receive FIFO not empty interrupt flag
  * @rmtoll   RX_ISR    RXNEMP    FL_CAN_IsActiveFlag_RXNotEmpty
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_RXNotEmpty(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_RXNEMP_Msk) == (CAN_RX_ISR_RXNEMP_Msk));
}

/**
  * @brief    Clear receive FIFO not empty interrupt flag
  * @rmtoll   RX_ISR    RXNEMP    FL_CAN_ClearFlag_RXNotEmpty
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_RXNotEmpty(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_RXNEMP_Msk);
}

/**
  * @brief    Get receive FIFO overflow interrupt flag
  * @rmtoll   RX_ISR    RXOFLW    FL_CAN_IsActiveFlag_RXOverflow
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_RXOverflow(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_RXOFLW_Msk) == (CAN_RX_ISR_RXOFLW_Msk));
}

/**
  * @brief    Clear  receive FIFO overflow interrupt flag
  * @rmtoll   RX_ISR    RXOFLW    FL_CAN_ClearFlag_RXOverflow
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_RXOverflow(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_RXOFLW_Msk);
}

/**
  * @brief    Get receive FIFO empty interrupt flag
  * @rmtoll   RX_ISR    RXUFLW    FL_CAN_IsActiveFlag_RXEmpty
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_RXUnderflow(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_RXUFLW_Msk) == (CAN_RX_ISR_RXUFLW_Msk));
}

/**
  * @brief    Clear receive FIFO underflow interrupt flag
  * @rmtoll   RX_ISR    RXUFLW    FL_CAN_ClearFlag_RXEmpty
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_RXUnderflow(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_RXUFLW_Msk);
}

/**
  * @brief    Get receive Ok interrupt flag
  * @rmtoll   RX_ISR    RXOK    FL_CAN_IsActiveFlag_RXOK
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_RXOK(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_RXOK_Msk) == (CAN_RX_ISR_RXOK_Msk));
}

/**
  * @brief    Clear receive OK interrupt flag
  * @rmtoll   RX_ISR    RXOK    FL_CAN_ClearFlag_CRXOK
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_RXOK(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_RXOK_Msk);
}

/**
  * @brief    Get arbitration lost interrupt flag
  * @rmtoll   RX_ISR    ARBLST    FL_CAN_IsActiveFlag_ArbitrationLost
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_ArbitrationLost(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_ISR, CAN_RX_ISR_ARBLST_Msk) == (CAN_RX_ISR_ARBLST_Msk));
}

/**
  * @brief    Clear arbitration lost interrupt flag
  * @rmtoll   RX_ISR    ARBLST    FL_CAN_ClearFlag_ArbitrationLost
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_ClearFlag_ArbitrationLost(CAN_Type *CANx)
{
    WRITE_REG(CANx->RX_ISR, CAN_RX_ISR_ARBLST_Msk);
}

/**
  * @brief    Bus off recovery interrupt enable
  * @rmtoll   RX_IER    BORFIE    FL_CAN_EnableIT_BusOffRecovery
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_BusOffRecovery(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_BORFIE_Msk);
}

/**
  * @brief    Bus off recovery  interrupt enable status
  * @rmtoll   RX_IER    BORFIE    FL_CAN_IsEnabledIT_BusOffRecovery
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_BusOffRecovery(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_BORFIE_Msk) == CAN_RX_IER_BORFIE_Msk);
}

/**
  * @brief    Bus off recovery  interrupt disable
  * @rmtoll   RX_IER    BORFIE    FL_CAN_DisableIT_BusOffRecovery
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_BusOffRecovery(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_BORFIE_Msk);
}

/**
  * @brief    Wakeup interrupt enable
  * @rmtoll   RX_IER    WKUPIE    FL_CAN_EnableIT_Wakeup
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_Wakeup(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_WKUPIE_Msk);
}

/**
  * @brief    Wakeup  interrupt enable status
  * @rmtoll   RX_IER    WKUPIE    FL_CAN_IsEnabledIT_Wakeup
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_Wakeup(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_WKUPIE_Msk) == CAN_RX_IER_WKUPIE_Msk);
}

/**
  * @brief    Wakeup  interrupt disable
  * @rmtoll   RX_IER    WKUPIE    FL_CAN_DisableIT_Wakeup
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_Wakeup(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_WKUPIE_Msk);
}

/**
  * @brief    Sleep interrupt enable
  * @rmtoll   RX_IER    SLPIE    FL_CAN_EnableIT_Sleep
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_Sleep(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_SLPIE_Msk);
}

/**
  * @brief    Sleep  interrupt enable status
  * @rmtoll   RX_IER    SLPIE    FL_CAN_IsEnabledIT_Sleep
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_Sleep(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_SLPIE_Msk) == CAN_RX_IER_SLPIE_Msk);
}

/**
  * @brief    Sleep  interrupt disable
  * @rmtoll   RX_IER    SLPIE    FL_CAN_DisableIT_Sleep
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_Sleep(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_SLPIE_Msk);
}

/**
  * @brief    Error change interrupt enable
  * @rmtoll   RX_IER    EESCFIE    FL_CAN_EnableIT_ErrorChange
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_ErrorChange(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_EESCFIE_Msk);
}

/**
  * @brief    Get Error change  interrupt enable status
  * @rmtoll   RX_IER    EESCFIE    FL_CAN_IsEnabledIT_ErrorChange
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_ErrorChange(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_EESCFIE_Msk) == CAN_RX_IER_EESCFIE_Msk);
}

/**
  * @brief    Error change  interrupt disable
  * @rmtoll   RX_IER    EESCFIE    FL_CAN_DisableIT_ErrorChange
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_ErrorChange(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_EESCFIE_Msk);
}

/**
  * @brief    Error interrupt enable
  * @rmtoll   RX_IER    ERRORIE    FL_CAN_EnableIT_Error
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_Error(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_ERRORIE_Msk);
}

/**
  * @brief    Get error interrupt enable status
  * @rmtoll   RX_IER    ERRORIE    FL_CAN_IsEnabledIT_Error
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_Error(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_ERRORIE_Msk) == CAN_RX_IER_ERRORIE_Msk);
}

/**
  * @brief    Error interrupt disable
  * @rmtoll   RX_IER    ERRORIE    FL_CAN_DisableIT_Error
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_Error(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_ERRORIE_Msk);
}

/**
  * @brief    Receive FIFO not empty interrupt enable
  * @rmtoll   RX_IER    RXNEMPIE    FL_CAN_EnableIT_RXNotEmpty
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_RXNotEmpty(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_RXNEMPIE_Msk);
}

/**
  * @brief    Get receive FIFO not empty interrupt enable status
  * @rmtoll   RX_IER    RXNEMPIE    FL_CAN_IsEnabledIT_RXNotEmpty
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_RXNotEmpty(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_RXNEMPIE_Msk) == CAN_RX_IER_RXNEMPIE_Msk);
}

/**
  * @brief    Receive FIFO not empty interrupt disable
  * @rmtoll   RX_IER    RXNEMPIE    FL_CAN_DisableIT_RXNotEmpty
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_RXNotEmpty(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_RXNEMPIE_Msk);
}

/**
  * @brief    Receive FIFO overflow interrupt ennable
  * @rmtoll   RX_IER    RXOFLWIE    FL_CAN_EnableIT_RXOverflow
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_RXOverflow(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_RXOFLWIE_Msk);
}

/**
  * @brief    Get receive FIFO overflow interrupt enable status
  * @rmtoll   RX_IER    RXOFLWIE    FL_CAN_IsEnabledIT_RXOverflow
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_RXOverflow(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_RXOFLWIE_Msk) == CAN_RX_IER_RXOFLWIE_Msk);
}

/**
  * @brief    Receive FIFO overflow interrupt disable
  * @rmtoll   RX_IER    RXOFLWIE    FL_CAN_DisableIT_RXOverflow
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_RXOverflow(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_RXOFLWIE_Msk);
}

/**
  * @brief    Receive FIFO empty interrupt enable
  * @rmtoll   RX_IER    RXUFLWIE    FL_CAN_EnableIT_RXEmpty
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_RXUnderflow(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_RXUFLWIE_Msk);
}

/**
  * @brief    Get receive FIFO empty interrupt enable status
  * @rmtoll   RX_IER    RXUFLWIE    FL_CAN_IsEnabledIT_RXEmpty
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_RXUnderflow(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_RXUFLWIE_Msk) == CAN_RX_IER_RXUFLWIE_Msk);
}

/**
  * @brief    Receive FIFO empty interrupt disable
  * @rmtoll   RX_IER    RXUFLWIE    FL_CAN_DisableIT_RXEmpty
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_RXUnderflow(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_RXUFLWIE_Msk);
}

/**
  * @brief    Receive OK interrupt enable
  * @rmtoll   RX_IER    RXOKIE    FL_CAN_EnableIT_RXOK
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_RXOK(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_RXOKIE_Msk);
}

/**
  * @brief    Get receive OK interrupt enable
  * @rmtoll   RX_IER    RXOKIE    FL_CAN_IsEnabledIT_RXOK
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_RXOK(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_RXOKIE_Msk) == CAN_RX_IER_RXOKIE_Msk);
}

/**
  * @brief    Receive OK interrupt disable
  * @rmtoll   RX_IER    RXOKIE    FL_CAN_DisableIT_RXOK
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_RXOK(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_RXOKIE_Msk);
}

/**
  * @brief    Arbitration lost interrupt enable
  * @rmtoll   RX_IER    ARBLSTIE    FL_CAN_EnableIT_ArbitrationLost
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_ArbitrationLost(CAN_Type *CANx)
{
    SET_BIT(CANx->RX_IER, CAN_RX_IER_ARBLSTIE_Msk);
}

/**
  * @brief    Get arbitration lost interrupt enable
  * @rmtoll   RX_IER    ARBLSTIE    FL_CAN_IsEnabledIT_ArbitrationLost
  * @param    CANx CAN instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_ArbitrationLost(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RX_IER, CAN_RX_IER_ARBLSTIE_Msk) == CAN_RX_IER_ARBLSTIE_Msk);
}

/**
  * @brief    Arbitration lost interrupt disable
  * @rmtoll   RX_IER    ARBLSTIE    FL_CAN_DisableIT_ArbitrationLost
  * @param    CANx CAN instance
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_ArbitrationLost(CAN_Type *CANx)
{
    CLEAR_BIT(CANx->RX_IER, CAN_RX_IER_ARBLSTIE_Msk);
}

/**
  * @brief    Set Tx abort request
  * @rmtoll   TXBCR    TXAR    FL_CAN_SetTXAbortRequest
  * @param    CANx CAN instance
  * @param    buffer This parameter can be one of the following values:
  *           @arg @ref FL_CAN_TX_ABORT_NONE
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_0
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_1
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_0AND1
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_2
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_0AND2
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_1AND2
  *           @arg @ref FL_CAN_TX_ABORT_ALL
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_SetTXAbortRequest(CAN_Type *CANx, uint32_t bufferX)
{
    MODIFY_REG(CANx->TXB_CR, CAN_TXBCR_TXAR_Msk, bufferX);
}

/**
  * @brief    Get TX abort request
  * @rmtoll   TXBCR    TXAR    FL_CAN_GetTXAbortRequest
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_TX_ABORT_NONE
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_0
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_1
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_0AND1
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_2
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_0AND2
  *           @arg @ref FL_CAN_TX_ABORT_BUFFER_1AND2
  *           @arg @ref FL_CAN_TX_ABORT_ALL
  */
__STATIC_INLINE uint32_t FL_CAN_GetTXAbortRequest(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->TXB_CR, CAN_TXBCR_TXAR_Msk));
}

/**
  * @brief    TX buffer empty interrupt enable
  * @rmtoll   TXBCR    TXIE    FL_CAN_EnableIT_TXBufferEmpty
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_EnableIT_TXBufferEmpty(CAN_Type *CANx, uint32_t bufferX)
{
    SET_BIT(CANx->TXB_CR, ((bufferX & 0x7U) << 0x0U));
}

/**
  * @brief    Get TX buffer empty interrupt enable status
  * @rmtoll   TXBCR    TXIE    FL_CAN_IsEnabledIT_TXBufferEmpty
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_IsEnabledIT_TXBufferEmpty(CAN_Type *CANx, uint32_t bufferX)
{
    return (uint32_t)(READ_BIT(CANx->TXB_CR, ((bufferX & 0x7U) << 0x0U)) == ((bufferX & 0x7U) << 0x0U));
}

/**
  * @brief    TX buffer empty interrupt disable
  * @rmtoll   TXBCR    TXIE    FL_CAN_DisableIT_TXBufferEmpty
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_DisableIT_TXBufferEmpty(CAN_Type *CANx, uint32_t bufferX)
{
    CLEAR_BIT(CANx->TXB_CR, ((bufferX & 0x7U) << 0x0U));
}

/**
  * @brief    Get TX result flag
  * @rmtoll   TXBSR    TXRF    FL_CAN_GetTXRsultFlag
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_TX_RESULT_NONE
  *           @arg @ref FL_CAN_TX_RESULT_ABORT
  *           @arg @ref FL_CAN_TX_RESULT_OK_NOABORT
  *           @arg @ref FL_CAN_TX_RESULT_OK_ABORT
  */
__STATIC_INLINE uint32_t FL_CAN_GetTXRsultFlag(CAN_Type *CANx, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER0)
    {
        return (uint32_t)(READ_BIT(CANx->TXB_SR, (CAN_TXBSR_TXRF_Msk << 0U)));
    }
    else
    {
        return (uint32_t)(READ_BIT(CANx->TXB_SR, (CAN_TXBSR_TXRF_Msk << bufferX)));
    }
}

/**
  * @brief    Get TX buffer status
  * @rmtoll   TXBSR    TXS    FL_CAN_GetTXBufferStatus
  * @param    CANx CAN instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_TX_BUFFER_ALL_IDLE
  *           @arg @ref FL_CAN_TX_BUFFER_0_BUSY
  *           @arg @ref FL_CAN_TX_BUFFER_1_BUSY
  *           @arg @ref FL_CAN_TX_BUFFER_0AND1_BUSY
  *           @arg @ref FL_CAN_TX_BUFFER_2_BUSY
  *           @arg @ref FL_CAN_TX_BUFFER_0AND2_BUSY
  *           @arg @ref FL_CAN_TX_BUFFER_1AND2_BUSY
  *           @arg @ref FL_CAN_TX_BUFFER_ALL_BUSY
  */
__STATIC_INLINE uint32_t FL_CAN_GetTXBufferStatus(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->TXB_SR, CAN_TXBSR_TXS_Msk));
}

/**
  * @brief    Clear TX buffer empty flag
  * @rmtoll   TXBSR    TXE    FL_CAN_ClearFlag_TXBufferEmpty
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  */
__STATIC_INLINE void FL_CAN_ClearFlag_TXBufferEmpty(CAN_Type *CANx, uint32_t bufferX)
{
    WRITE_REG(CANx->TXB_SR, (bufferX & 0x07U) << 0x0U);
}

/**
  * @brief    Get TX buffer empty flag
  * @rmtoll   TXBSR    TXE    FL_CAN_IsActiveFlag_TXBuffer1Empty
  * @param    CANx CAN instance
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  */
__STATIC_INLINE uint32_t FL_CAN_IsActiveFlag_TXBufferEmpty(CAN_Type *CANx, uint32_t bufferX)
{
    return (uint32_t)(READ_BIT(CANx->TXB_SR, ((bufferX & 0x07U) << 0x0U)) == ((bufferX & 0x07) << 0x0U));
}

/**
  * @brief    Set TXFIFO message identifier code
  * @rmtoll   TXBIDR    IDR    FL_CAN_WriteTXMessageID
  * @param    CANx CAN instance
  * @param    id
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteTXMessageID(CAN_Type *CANx, uint32_t id, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        MODIFY_REG(*(&(CANx->TXB0_IDR) + 4 * (bufferX - 2)), CAN_TXBIDR_IDR_Msk, (id << CAN_TXBIDR_IDR_Pos));
    }
    else
    {
        MODIFY_REG(*(&(CANx->TXB0_IDR) + 4 * (bufferX - 1)), CAN_TXBIDR_IDR_Msk, (id << CAN_TXBIDR_IDR_Pos));
    }
}

/**
  * @brief    Get TXFIFO message identifier code
  * @rmtoll   TXBIDR    IDR    FL_CAN_ReadTXMessageID
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTXMessageID(CAN_Type *CANx, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_IDR) + 4 * (bufferX - 2)), CAN_TXBIDR_IDR_Msk) >> CAN_TXBIDR_IDR_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_IDR) + 4 * (bufferX - 1)), CAN_TXBIDR_IDR_Msk) >> CAN_TXBIDR_IDR_Pos);
    }
}

/**
  * @brief    Set TXFIFO data length code
  * @rmtoll   TXBDLCR    DLC    FL_CAN_WriteTXMessageLength
  * @param    CANx CAN instance
  * @param    length
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteTXMessageLength(CAN_Type *CANx, uint32_t length, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        MODIFY_REG(*(&(CANx->TXB0_DLCR) + 4 * (bufferX - 2)), CAN_TXBDLCR_DLC_Msk, (length << CAN_TXBDLCR_DLC_Pos));
    }
    else
    {
        MODIFY_REG(*(&(CANx->TXB0_DLCR) + 4 * (bufferX - 1)), CAN_TXBDLCR_DLC_Msk, (length << CAN_TXBDLCR_DLC_Pos));
    }
}

/**
  * @brief    Get TXFIFO data length code
  * @rmtoll   TXBDLCR    DLC    FL_CAN_ReadTXMessageLength
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTXMessageLength(CAN_Type *CANx, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_DLCR) + 4 * (bufferX - 2)), CAN_TXBDLCR_DLC_Msk) >> CAN_TXBDLCR_DLC_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_DLCR) + 4 * (bufferX - 1)), CAN_TXBDLCR_DLC_Msk) >> CAN_TXBDLCR_DLC_Pos);
    }
}

/**
  * @brief    Set TXFIFO data word1
  * @rmtoll   TXBDW1R    DB    FL_CAN_WriteTXMessageWord1
  * @param    CANx CAN instance
  * @param    word
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteTXMessageWord1(CAN_Type *CANx, uint32_t word, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        MODIFY_REG(*(&(CANx->TXB0_DW1R) + 4 * (bufferX - 2)), CAN_TXBDW1R_DB_Msk, (word << CAN_TXBDW1R_DB_Pos));
    }
    else
    {
        MODIFY_REG(*(&(CANx->TXB0_DW1R) + 4 * (bufferX - 1)), CAN_TXBDW1R_DB_Msk, (word << CAN_TXBDW1R_DB_Pos));
    }
}

/**
  * @brief    Get TXFIFO data word1
  * @rmtoll   TXBDW1R    DB    FL_CAN_ReadTXMessageWord1
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTXMessageWord1(CAN_Type *CANx, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_DW1R) + 4 * (bufferX - 2)), CAN_TXBDW1R_DB_Msk) >> CAN_TXBDW1R_DB_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_DW1R) + 4 * (bufferX - 1)), CAN_TXBDW1R_DB_Msk) >> CAN_TXBDW1R_DB_Pos);
    }
}

/**
  * @brief    Set TXFIFO data word2
  * @rmtoll   TXBDW2R    DB    FL_CAN_WriteTXMessageWord2
  * @param    CANx CAN instance
  * @param    word
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteTXMessageWord2(CAN_Type *CANx, uint32_t word, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        MODIFY_REG(*(&(CANx->TXB0_DW2R) + 4 * (bufferX - 2)), CAN_TXBDW2R_DB_Msk, (word << CAN_TXBDW2R_DB_Pos));
    }
    else
    {
        MODIFY_REG(*(&(CANx->TXB0_DW2R) + 4 * (bufferX - 1)), CAN_TXBDW2R_DB_Msk, (word << CAN_TXBDW2R_DB_Pos));
    }
}

/**
  * @brief    Get TXFIFO data word2
  * @rmtoll   TXBDW2R    DB    FL_CAN_ReadTXMessageWord2
  * @param    CANx CAN instance
  * @param    bufferX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_BUFFER0
  *           @arg @ref FL_CAN_BUFFER1
  *           @arg @ref FL_CAN_BUFFER2
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadTXMessageWord2(CAN_Type *CANx, uint32_t bufferX)
{
    if(bufferX == FL_CAN_BUFFER2)
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_DW2R) + 4 * (bufferX - 2)), CAN_TXBDW2R_DB_Msk) >> CAN_TXBDW2R_DB_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(*(&(CANx->TXB0_DW2R) + 4 * (bufferX - 1)), CAN_TXBDW2R_DB_Msk) >> CAN_TXBDW2R_DB_Pos);
    }
}

/**
  * @brief    Set RXFIFO message identifier code
  * @rmtoll   RXFIDR    IDR    FL_CAN_WriteRXMessageID
  * @param    CANx CAN instance
  * @param    id
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteRXMessageID(CAN_Type *CANx, uint32_t id)
{
    MODIFY_REG(CANx->RXF_IDR, CAN_RXFIDR_IDR_Msk, (id << CAN_RXFIDR_IDR_Pos));
}

/**
  * @brief    Get RXFIFO message identifier code
  * @rmtoll   RXFIDR    IDR    FL_CAN_ReadRXMessageID
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadRXMessageID(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RXF_IDR, CAN_RXFIDR_IDR_Msk) >> CAN_RXFIDR_IDR_Pos);
}

/**
  * @brief    Set RXFIFO data length code
  * @rmtoll   RXFDLCR    DLC    FL_CAN_WriteRXMessageLength
  * @param    CANx CAN instance
  * @param    length
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteRXMessageLength(CAN_Type *CANx, uint32_t length)
{
    MODIFY_REG(CANx->RXF_DLCR, CAN_RXFDLCR_DLC_Msk, (length << CAN_RXFDLCR_DLC_Pos));
}

/**
  * @brief    Get RXFIFO data length code
  * @rmtoll   RXFDLCR    DLC    FL_CAN_ReadRXMessageLength
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadRXMessageLength(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RXF_DLCR, CAN_RXFDLCR_DLC_Msk) >> CAN_RXFDLCR_DLC_Pos);
}

/**
  * @brief    Set RXFIFO data word1
  * @rmtoll   RXFDW1R    DB    FL_CAN_WriteRXMessageWord1
  * @param    CANx CAN instance
  * @param    word
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteRXMessageWord1(CAN_Type *CANx, uint32_t word)
{
    MODIFY_REG(CANx->RXF_DW1R, CAN_RXFDW1R_DB_Msk, (word << CAN_RXFDW1R_DB_Pos));
}

/**
  * @brief    Get RXFIFO data word1
  * @rmtoll   RXFDW1R    DB    FL_CAN_ReadRXMessageWord1
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadRXMessageWord1(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RXF_DW1R, CAN_RXFDW1R_DB_Msk) >> CAN_RXFDW1R_DB_Pos);
}

/**
  * @brief    Set RXFIFO data word2
  * @rmtoll   RXFDW2R    DB    FL_CAN_WriteRXMessageWord2
  * @param    CANx CAN instance
  * @param    word
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_WriteRXMessageWord2(CAN_Type *CANx, uint32_t word)
{
    MODIFY_REG(CANx->RXF_DW2R, CAN_RXFDW2R_DB_Msk, (word << CAN_RXFDW2R_DB_Pos));
}

/**
  * @brief    Get RXFIFO data word2
  * @rmtoll   RXFDW2R    DB    FL_CAN_ReadRXMessageWord2
  * @param    CANx CAN instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_ReadRXMessageWord2(CAN_Type *CANx)
{
    return (uint32_t)(READ_BIT(CANx->RXF_DW2R, CAN_RXFDW2R_DB_Msk) >> CAN_RXFDW2R_DB_Pos);
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    MSKM    FL_CAN_Filter_SetMaskMode
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CAN_MASKMODE_MASK
  *           @arg @ref FL_CAN_MASKMODE_ID
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_Filter_SetMaskMode(CAN_Type *CANx, uint32_t filterX, uint32_t mode)
{
    MODIFY_REG(CANx->AFCFGR, (CAN_AFCFGR_MSKM_Msk << filterX), (mode << filterX));
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    MSKM    FL_CAN_Filter_GetMaskMode
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CAN_MASKMODE_MASK
  *           @arg @ref FL_CAN_MASKMODE_ID
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_CAN_Filter_GetMaskMode(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)((READ_BIT(CANx->AFCFGR, (CAN_AFCFGR_MSKM_Msk << filterX))) >> filterX);
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    FSC    FL_CAN_Filter_SetIDMode
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CAN_IDMODE_32BIT
  *           @arg @ref FL_CAN_IDMODE_16BIT
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_Filter_SetIDMode(CAN_Type *CANx, uint32_t filterX, uint32_t mode)
{
    MODIFY_REG(CANx->AFCFGR, (CAN_AFCFGR_FSC_Msk << filterX), (mode << filterX));
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    FSC    FL_CAN_Filter_GetIDMode
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_CAN_MASKMODE_MASK
  *           @arg @ref FL_CAN_MASKMODE_ID
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_CAN_Filter_GetIDMode(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)((READ_BIT(CANx->AFCFGR, (CAN_AFCFGR_FSC_Msk << filterX))) >> filterX);
}

/**
  * @brief    Acceptance filter 4 enable
  * @rmtoll   AFR    UAF    FL_CAN_Filter_Enable
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_Filter_Enable(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(CANx->AFCR, CAN_AFCR_UAF_Msk << filterX);
}

/**
  * @brief    Get acceptance filter 4 enable status
  * @rmtoll   AFR    UAF    FL_CAN_Filter_IsEnabled
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_Filter_IsEnabled(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(CANx->AFCR, ((CAN_AFCR_UAF_Msk << filterX) & 0xf)) == ((CAN_AFCR_UAF_Msk << filterX) & 0xf));
}

/**
  * @brief    Acceptance filter 4 disable
  * @rmtoll   AFR    UAF    FL_CAN_Filter_Disable
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_Filter_Disable(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(CANx->AFCR, ((CAN_AFCR_UAF_Msk << filterX) & 0xf));
}
/**
  * @brief    Enable RTR participate filter compare
  * @rmtoll   AFMR    AMRTR    FL_CAN_FilterEXT_EnableRTRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_EnableRTRCompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMRTR_Msk);
}

/**
  * @brief    Disable RTR participate filter compare
  * @rmtoll   AFMR    AMRTR    FL_CAN_FilterEXT_DisableRTRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE void FL_CAN_FilterEXT_DisableRTRCompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMRTR_Msk);
}

/**
  * @brief    Get RTR participate filter compare Enable Status
  * @rmtoll   AFMR    AMRTR    FL_CAN_FilterEXT_IsEnabledRTRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_IsEnabledRTRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMRTR_Msk) == CAN_AFMR_AMRTR_Msk);
}

/**
  * @brief    Set ID low 18bit participate filter compare
  * @rmtoll   AFMR    AMID18    FL_CAN_FilterEXT_WriteEXTIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_WriteEXTIDCompareMask(CAN_Type *CANx, uint32_t filterX, uint32_t id18)
{
    MODIFY_REG(*(&(CANx->AFMR1) + 2 * filterX), (0x3ffffU << CAN_AFMR_AMID18_Pos), (id18 << CAN_AFMR_AMID18_Pos));
}

/**
  * @brief    Get ID low 18bit participate filter compare
  * @rmtoll   AFMR    AMID18    FL_CAN_FilterEXT_ReadEXTIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_ReadEXTIDCompareMask(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), (0x3ffffU << CAN_AFMR_AMID18_Pos)) >> CAN_AFMR_AMID18_Pos);
}

/**
  * @brief    Set EXTID  high 3bit participate filter compare
  * @rmtoll   AFMR    AMID3    FL_CAN_FilterSTD1_WriteEXTIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_WriteEXTIDCompareMask(CAN_Type *CANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMID3_Msk, (id3 << CAN_AFMRSTD1_AMID3_Pos));
}

/**
  * @brief
  * @rmtoll   AFMR    AMID3    FL_CAN_FilterSTD1_ReadEXTIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_ReadEXTIDCompareMask(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMID3_Msk) >> CAN_AFMRSTD1_AMID3_Pos);
}

/**
  * @brief
  * @rmtoll   AFMR    AMID3    FL_CAN_FilterSTD2_WriteEXTIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_WriteEXTIDCompareMask(CAN_Type *CANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMID3_Msk, (id3 << CAN_AFMRSTD2_AMID3_Pos));
}

/**
  * @brief
  * @rmtoll   AFMR    AMID3    FL_CAN_FilterSTD2_ReadEXTIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_ReadEXTIDCompareMask(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMID3_Msk) >> CAN_AFMRSTD2_AMID3_Pos);
}

/**
  * @brief    Enable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterEXT_EnableIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_EnableIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMIDE_Msk);
}

/**
  * @brief    Disable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterEXT_DisableIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_DisableIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMIDE_Msk);
}

/**
  * @brief    Get IDE participate filter compare Enable Status
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterEXT_IsEnabledIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_IsEnabledIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMIDE_Msk) == CAN_AFMR_AMIDE_Msk);
}

/**
  * @brief    Enable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterSTD1_EnableIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_EnableIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMIDE_Msk);
}

/**
  * @brief    Disable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterSTD1_DisableIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_DisableIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMIDE_Msk);
}

/**
  * @brief    Get IDE participate filter compare Enable Status
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterSTD1_IsEnabledIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_IsEnabledIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMIDE_Msk) == CAN_AFMRSTD1_AMIDE_Msk);
}

/**
  * @brief    Enable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterSTD2_EnableIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_EnableIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMIDE_Msk);
}

/**
  * @brief    Disable IDE participate filter compare
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterSTD2_DisableIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_DisableIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMIDE_Msk);
}

/**
  * @brief    Get IDE participate filter compare Enable Status
  * @rmtoll   AFMR    AMIDE    FL_CAN_FilterSTD2_IsEnabledIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_IsEnabledIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMIDE_Msk) == CAN_AFMRSTD2_AMIDE_Msk);
}

/**
  * @brief    Enable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_CAN_Filter_EnableSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_EnableSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMSRR_Msk);
}

/**
  * @brief    Disable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_CAN_Filter_DisableSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_DisableSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMSRR_Msk);
}

/**
  * @brief    Get SRR participate filter compare Enable Status
  * @rmtoll   AFMR    AMSRR    FL_CAN_Filter_IsEnabledSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_IsEnabledSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMR_AMSRR_Msk) == CAN_AFMR_AMSRR_Msk);
}

/**
  * @brief    Enable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_CAN_FilterSTD1_EnableSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_EnableSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMSRR_Msk);
}

/**
  * @brief    Disable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_CAN_FilterSTD1_DisableSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_DisableSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMSRR_Msk);
}

/**
  * @brief    Get SRR participate filter compare Enable Status
  * @rmtoll   AFMR    AMSRR    FL_CAN_FilterSTD1_IsEnabledSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_IsEnabledSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD1_AMSRR_Msk) == CAN_AFMRSTD1_AMSRR_Msk);
}

/**
  * @brief    Enable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_CAN_FilterSTD2_EnableSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_EnableSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    SET_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMSRR_Msk);
}

/**
  * @brief    Disable SRR participate filter compare
  * @rmtoll   AFMR    AMSRR    FL_CAN_FilterSTD2_DisableSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_DisableSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    CLEAR_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMSRR_Msk);
}

/**
  * @brief    Get SRR participate filter compare Enable Status
  * @rmtoll   AFMR    AMSRR    FL_CAN_FilterSTD2_IsEnabledSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_IsEnabledSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFMR1) + 2 * filterX), CAN_AFMRSTD2_AMSRR_Msk) == CAN_AFMRSTD2_AMSRR_Msk);
}

/**
  * @brief    Set ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_CAN_FilterEXT_WriteIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_WriteIDCompareMask(CAN_Type *CANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(CANx->AFMR1)) + 2 * filterX), (0x7ffU << CAN_AFMR_AMID11_Pos), id11 << CAN_AFMR_AMID11_Pos);
}

/**
  * @brief    Get ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_CAN_FilterEXT_ReadIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_ReadIDCompareMask(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFMR1)) + 2 * filterX), (0x7ffU << CAN_AFMR_AMID11_Pos)) >> CAN_AFMR_AMID11_Pos);
}

/**
  * @brief    Set ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_CAN_FilterSTD1_WriteIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_WriteIDCompareMask(CAN_Type *CANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(CANx->AFMR1)) + 2 * filterX), (0x7ffU << CAN_AFMRSTD1_AMID11_Pos), id11 << CAN_AFMRSTD1_AMID11_Pos);
}

/**
  * @brief    Get ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_CAN_FilterSTD1_ReadIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_ReadIDCompareMask(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFMR1)) + 2 * filterX), (0x7ffU << CAN_AFMRSTD1_AMID11_Pos)) >> CAN_AFMRSTD1_AMID11_Pos);
}

/**
  * @brief    Set ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_CAN_FilterSTD2_WriteIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_WriteIDCompareMask(CAN_Type *CANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(CANx->AFMR1)) + 2 * filterX), (0x7ffU << CAN_AFMRSTD2_AMID11_Pos), id11 << CAN_AFMRSTD2_AMID11_Pos);
}

/**
  * @brief    Get ID high 11bit participate filter compare
  * @rmtoll   AFMR    AMID11    FL_CAN_FilterSTD1_ReadIDCompareMask
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_ReadIDCompareMask(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFMR1)) + 2 * filterX), (0x7ffU << CAN_AFMRSTD2_AMID11_Pos)) >> CAN_AFMRSTD2_AMID11_Pos);
}

/**
  * @brief    Set filter RTR
  * @rmtoll   AFIR    AIRTR    FL_CAN_FilterEXT_SetRTRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    rtr This parameter can be one of the following values:
  *           @arg @ref FL_CAN_RTR_BIT_LOW
  *           @arg @ref FL_CAN_RTR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_SetRTRCompare(CAN_Type *CANx, uint32_t filterX, uint32_t rtr)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AIRTR_Msk, rtr);
}

/**
  * @brief    Get filter RTR
  * @rmtoll   AFIR    AIRTR    FL_CAN_FilterEXT_GetRTRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_RTR_BIT_LOW
  *           @arg @ref FL_CAN_RTR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_GetRTRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AIRTR_Msk));
}

/**
  * @brief    Set filter ID[17:0]
  * @rmtoll   AFIR    AIID18    FL_CAN_FilterEXT_WriteEXTIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_WriteEXTIDCompare(CAN_Type *CANx, uint32_t filterX, uint32_t id18)
{
    MODIFY_REG(*(&(CANx->AFIR1) + 2 * filterX), (0x3ffffU << CAN_AFIR_AIID18_Pos), (id18 << CAN_AFIR_AIID18_Pos));
}

/**
  * @brief    Get filter ID[17:0]
  * @rmtoll   AFIR    AIID18    FL_CAN_FilterEXT_ReadEXTIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_ReadEXTIDCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFIR1) + 2 * filterX), (0x3ffffU << CAN_AFIR_AIID18_Pos)) >> CAN_AFIR_AIID18_Pos);
}

/**
  * @brief    Set filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_CAN_FilterSTD1_WriteEXTIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_WriteEXTIDCompare(CAN_Type *CANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(CANx->AFIR1) + 2 * filterX), CAN_AFIRSTD1_AIID3_Msk, (id3 << CAN_AFIRSTD1_AIID3_Pos));
}

/**
  * @brief    Get filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_CAN_FilterSTD1_ReadEXTIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_ReadEXTIDCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFIR1) + 2 * filterX), CAN_AFIRSTD1_AIID3_Msk) >> CAN_AFIRSTD1_AIID3_Pos);
}

/**
  * @brief    Set filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_CAN_FilterSTD2_WriteEXTIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id18
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_WriteEXTIDCompare(CAN_Type *CANx, uint32_t filterX, uint32_t id3)
{
    MODIFY_REG(*(&(CANx->AFIR1) + 2 * filterX), CAN_AFIRSTD2_AIID3_Msk, (id3 << CAN_AFIRSTD2_AIID3_Pos));
}

/**
  * @brief    Get filter ID[17:15]
  * @rmtoll   AFIR    AIID3    FL_CAN_FilterSTD2_ReadEXTIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_ReadEXTIDCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*(&(CANx->AFIR1) + 2 * filterX), CAN_AFIRSTD2_AIID3_Msk) >> CAN_AFIRSTD2_AIID3_Pos);
}
/**
  * @brief    Set filter IDE
  * @rmtoll   AFIR    AIIDE    FL_CAN_FilterEXT_SetIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CAN_IDE_BIT_LOW
  *           @arg @ref FL_CAN_IDE_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_SetIDECompare(CAN_Type *CANx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AIIDE_Msk, ide);
}

/**
  * @brief    Get filter IDE
  * @rmtoll   AFIR    AIIDE    FL_CAN_FilterEXT_GetIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_IDE_BIT_LOW
  *           @arg @ref FL_CAN_IDE_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_GetIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AIIDE_Msk));
}

/**
  * @brief    Set filter IDE
  * @rmtoll   AFIR    AIIDE    FL_CAN_FilterSTD1_SetIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CAN_STD1IDE_BIT_LOW
  *           @arg @ref FL_CAN_STD1IDE_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_SetIDECompare(CAN_Type *CANx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD1_AIIDE_Msk, ide);
}

/**
  * @brief    Get filter IDE
  * @rmtoll   AFIR    AIIDE    FL_CAN_FilterSTD1_GetIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_STD1IDE_BIT_LOW
  *           @arg @ref FL_CAN_STD1IDE_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_GetIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD1_AIIDE_Msk));
}

/**
  * @brief    Set filter IDE
  * @rmtoll   AFIR    AIIDE    FL_CAN_FilterSTD2_SetIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    ide This parameter can be one of the following values:
  *           @arg @ref FL_CAN_STD2IDE_BIT_LOW
  *           @arg @ref FL_CAN_STD2IDE_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_SetIDECompare(CAN_Type *CANx, uint32_t filterX, uint32_t ide)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD2_AIIDE_Msk, ide);
}

/**
  * @brief    Get filter IDE
  * @rmtoll   AFIR    AIIDE    FL_CAN_FilterSTD2_GetIDECompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_STD2IDE_BIT_LOW
  *           @arg @ref FL_CAN_STD2IDE_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_GetIDECompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD2_AIIDE_Msk));
}
/**
  * @brief    Set filter SRR
  * @rmtoll   AFIR    AISRR    FL_CAN_FilterEXT_SetSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    srr This parameter can be one of the following values:
  *           @arg @ref FL_CAN_SRR_BIT_LOW
  *           @arg @ref FL_CAN_SRR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_SetSRRCompare(CAN_Type *CANx, uint32_t filterX, uint32_t srr)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AISRR_Msk, srr);
}

/**
  * @brief    Get filter SRR
  * @rmtoll   AFIR    AISRR    FL_CAN_FilterEXT_GetSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_SRR_BIT_LOW
  *           @arg @ref FL_CAN_SRR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_GetSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AISRR_Msk));
}

/**
  * @brief    Set filter SRR
  * @rmtoll   AFIR    AISRR    FL_CAN_FilterSTD1_SetSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    srr This parameter can be one of the following values:
  *           @arg @ref FL_CAN_STD1SRR_BIT_LOW
  *           @arg @ref FL_CAN_STD1SRR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_SetSRRCompare(CAN_Type *CANx, uint32_t filterX, uint32_t srr)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD1_AISRR_Msk, srr);
}

/**
  * @brief    Get filter SRR
  * @rmtoll   AFIR    AISRR    FL_CAN_FilterSTD1_GetSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_STD1SRR_BIT_LOW
  *           @arg @ref FL_CAN_STD1SRR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_GetSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD1_AISRR_Msk));
}

/**
  * @brief    Set filter SRR
  * @rmtoll   AFIR    AISRR    FL_CAN_FilterSTD2_SetSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    srr This parameter can be one of the following values:
  *           @arg @ref FL_CAN_STD2SRR_BIT_LOW
  *           @arg @ref FL_CAN_STD2SRR_BIT_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_SetSRRCompare(CAN_Type *CANx, uint32_t filterX, uint32_t srr)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD2_AISRR_Msk, srr);
}

/**
  * @brief    Get filter SRR
  * @rmtoll   AFIR    AISRR    FL_CAN_FilterSTD2_GetSRRCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CAN_STD2SRR_BIT_LOW
  *           @arg @ref FL_CAN_STD2SRR_BIT_HIGH
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_GetSRRCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD2_AISRR_Msk));
}
/**
  * @brief    Set filterID[28:18]
  * @rmtoll   AFIR    AIID11    FL_CAN_FilterEXT_WriteIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterEXT_WriteIDCompare(CAN_Type *CANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AIID11_Msk, id11 << CAN_AFIR_AIID11_Pos);
}

/**
  * @brief    Get filter ID[28:18]
  * @rmtoll   AFIR    AIID11    FL_CAN_FilterEXT_ReadIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterEXT_ReadIDCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIR_AIID11_Msk) >> CAN_AFIR_AIID11_Pos);
}

/**
  * @brief    Set filterID[28:18]
  * @rmtoll   AFIR    AIID11    FL_CAN_FilterSTD1_WriteIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD1_WriteIDCompare(CAN_Type *CANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD1_AIID11_Msk, id11 << CAN_AFIRSTD1_AIID11_Pos);
}

/**
  * @brief    Get filter ID[28:18]
  * @rmtoll   AFIR    AIID11    FL_CAN_FilterSTD1_ReadIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD1_ReadIDCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD1_AIID11_Msk) >> CAN_AFIRSTD1_AIID11_Pos);
}

/**
  * @brief    Set filterID[28:18]
  * @rmtoll   AFIR    AIID11    FL_CAN_FilterSTD2_WriteIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @param    id11
  * @retval   None
  */
__STATIC_INLINE void FL_CAN_FilterSTD2_WriteIDCompare(CAN_Type *CANx, uint32_t filterX, uint32_t id11)
{
    MODIFY_REG(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD2_AIID11_Msk, id11 << CAN_AFIRSTD2_AIID11_Pos);
}

/**
  * @brief    Get filter ID[28:18]
  * @rmtoll   AFIR    AIID11    FL_CAN_FilterSTD2_ReadIDCompare
  * @param    CANx CAN instance
  * @param    filterX This parameter can be one of the following values:
  *           @arg @ref FL_CAN_FILTER1
  *           @arg @ref FL_CAN_FILTER2
  *           @arg @ref FL_CAN_FILTER3
  *           @arg @ref FL_CAN_FILTER4
  *           @arg @ref FL_CAN_FILTER5
  *           @arg @ref FL_CAN_FILTER6
  *           @arg @ref FL_CAN_FILTER7
  *           @arg @ref FL_CAN_FILTER8
  *           @arg @ref FL_CAN_FILTER9
  *           @arg @ref FL_CAN_FILTER10
  *           @arg @ref FL_CAN_FILTER11
  *           @arg @ref FL_CAN_FILTER12
  *           @arg @ref FL_CAN_FILTER13
  *           @arg @ref FL_CAN_FILTER14
  *           @arg @ref FL_CAN_FILTER15
  *           @arg @ref FL_CAN_FILTER16
  * @retval
  */
__STATIC_INLINE uint32_t FL_CAN_FilterSTD2_ReadIDCompare(CAN_Type *CANx, uint32_t filterX)
{
    return (uint32_t)(READ_BIT(*((&(CANx->AFIR1)) + 2 * filterX), CAN_AFIRSTD2_AIID11_Msk) >> CAN_AFIRSTD2_AIID11_Pos);
}
/**
  * @}
  */

/** @defgroup CAN_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_CAN_Init(CAN_Type *CANx, FL_CAN_InitTypeDef *CAN_InitStruct);
FL_ErrorStatus FL_CAN_FilterInit(CAN_Type *CANx, FL_CAN_FilterInitTypeDef *CAN_FilterInitStruct, uint32_t filterX);
void FL_CAN_StructInit(FL_CAN_InitTypeDef *CAN_InitStruct);
void FL_CAN_StructFilterInit(FL_CAN_FilterInitTypeDef *CAN_FilterInitStruct);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_CAN_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-04-07*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
