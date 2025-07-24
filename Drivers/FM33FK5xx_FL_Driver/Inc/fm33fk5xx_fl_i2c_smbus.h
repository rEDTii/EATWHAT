/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_i2c_smbus.h
  * @author  FMSH Application Team
  * @brief   Head file of I2C_SMBUS FL Module
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
#ifndef __FM33FK5XX_FL_I2C_SMBUS_H
#define __FM33FK5XX_FL_I2C_SMBUS_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup I2C_SMBUS_FL_ES_INIT I2C_SMBUS Exported Init structures
  * @{
  */

typedef struct
{
    /** 主机时使用的时钟源*/
    uint32_t clockSource;

    /** I2C通讯速率*/
    uint32_t baudRate;

} FL_I2C_SMBUS_MasterMode_InitTypeDef;

/**
  * @brief I2C Slavemode Init Sturcture Definition
  */
typedef struct
{
    /** 从机模式从机地址 */
    uint32_t ownAddr;

    /** 从机模式地址位宽 */
    uint32_t ownAddrSize10bit;

    /** 从机时钟延展*/
    uint32_t SCLSEN;

} FL_I2C_SMBUS_SlaveMode_InitTypeDef;

/**
  * @brief FL I2C_SMBUS Init Sturcture definition
  */
//#warning "PLEASE INPUT THE INIT OR OTHER STRUCTURES DEFINITION HERE!!!"
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup I2C_SMBUS_FL_Exported_Constants I2C_SMBUS Exported Constants
  * @{
  */

#define    I2CSMB_CR1_EN_Pos                                      (0U)
#define    I2CSMB_CR1_EN_Msk                                      (0x1U << I2CSMB_CR1_EN_Pos)
#define    I2CSMB_CR1_EN                                          I2CSMB_CR1_EN_Msk

#define    I2CSMB_CR1_A10EN_Pos                                   (2U)
#define    I2CSMB_CR1_A10EN_Msk                                   (0x1U << I2CSMB_CR1_A10EN_Pos)
#define    I2CSMB_CR1_A10EN                                       I2CSMB_CR1_A10EN_Msk

#define    I2CSMB_CR1_CRCEN_Pos                                   (3U)
#define    I2CSMB_CR1_CRCEN_Msk                                   (0x1U << I2CSMB_CR1_CRCEN_Pos)
#define    I2CSMB_CR1_CRCEN                                       I2CSMB_CR1_CRCEN_Msk

#define    I2CSMB_CR1_DNF_Pos                                     (8U)
#define    I2CSMB_CR1_DNF_Msk                                     (0xfU << I2CSMB_CR1_DNF_Pos)
#define    I2CSMB_CR1_DNF                                         I2CSMB_CR1_DNF_Msk

#define    I2CSMB_CR1_ANFEN_Pos                                   (12U)
#define    I2CSMB_CR1_ANFEN_Msk                                   (0x1U << I2CSMB_CR1_ANFEN_Pos)
#define    I2CSMB_CR1_ANFEN                                       I2CSMB_CR1_ANFEN_Msk

#define    I2CSMB_CR1_TXDMAEN_Pos                                 (14U)
#define    I2CSMB_CR1_TXDMAEN_Msk                                 (0x1U << I2CSMB_CR1_TXDMAEN_Pos)
#define    I2CSMB_CR1_TXDMAEN                                     I2CSMB_CR1_TXDMAEN_Msk

#define    I2CSMB_CR1_RXDMAEN_Pos                                 (15U)
#define    I2CSMB_CR1_RXDMAEN_Msk                                 (0x1U << I2CSMB_CR1_RXDMAEN_Pos)
#define    I2CSMB_CR1_RXDMAEN                                     I2CSMB_CR1_RXDMAEN_Msk

#define    I2CSMB_CR1_SCLSEN_Pos                                  (16U)
#define    I2CSMB_CR1_SCLSEN_Msk                                  (0x1U << I2CSMB_CR1_SCLSEN_Pos)
#define    I2CSMB_CR1_SCLSEN                                      I2CSMB_CR1_SCLSEN_Msk

#define    I2CSMB_CR1_WKUPEN_Pos                                  (17U)
#define    I2CSMB_CR1_WKUPEN_Msk                                  (0x3U << I2CSMB_CR1_WKUPEN_Pos)
#define    I2CSMB_CR1_WKUPEN                                      I2CSMB_CR1_WKUPEN_Msk

#define    I2CSMB_CR1_GCEN_Pos                                    (19U)
#define    I2CSMB_CR1_GCEN_Msk                                    (0x1U << I2CSMB_CR1_GCEN_Pos)
#define    I2CSMB_CR1_GCEN                                        I2CSMB_CR1_GCEN_Msk

#define    I2CSMB_CR1_SMBHEN_Pos                                  (20U)
#define    I2CSMB_CR1_SMBHEN_Msk                                  (0x1U << I2CSMB_CR1_SMBHEN_Pos)
#define    I2CSMB_CR1_SMBHEN                                      I2CSMB_CR1_SMBHEN_Msk

#define    I2CSMB_CR1_SMBDEN_Pos                                  (21U)
#define    I2CSMB_CR1_SMBDEN_Msk                                  (0x1U << I2CSMB_CR1_SMBDEN_Pos)
#define    I2CSMB_CR1_SMBDEN                                      I2CSMB_CR1_SMBDEN_Msk

#define    I2CSMB_CR1_ALERTEN_Pos                                 (22U)
#define    I2CSMB_CR1_ALERTEN_Msk                                 (0x1U << I2CSMB_CR1_ALERTEN_Pos)
#define    I2CSMB_CR1_ALERTEN                                     I2CSMB_CR1_ALERTEN_Msk

#define    I2CSMB_CR1_AUTOEND_Pos                                 (23U)
#define    I2CSMB_CR1_AUTOEND_Msk                                 (0x1U << I2CSMB_CR1_AUTOEND_Pos)
#define    I2CSMB_CR1_AUTOEND                                     I2CSMB_CR1_AUTOEND_Msk

#define    I2CSMB_CR2_ALERT_Pos                                   (5U)
#define    I2CSMB_CR2_ALERT_Msk                                   (0x1U << I2CSMB_CR2_ALERT_Pos)
#define    I2CSMB_CR2_ALERT                                       I2CSMB_CR2_ALERT_Msk

#define    I2CSMB_CR2_ACKEN_Pos                                   (4U)
#define    I2CSMB_CR2_ACKEN_Msk                                   (0x1U << I2CSMB_CR2_ACKEN_Pos)
#define    I2CSMB_CR2_ACKEN                                       I2CSMB_CR2_ACKEN_Msk

#define    I2CSMB_CR2_RWN_Pos                                     (3U)
#define    I2CSMB_CR2_RWN_Msk                                     (0x1U << I2CSMB_CR2_RWN_Pos)
#define    I2CSMB_CR2_RWN                                         I2CSMB_CR2_RWN_Msk

#define    I2CSMB_CR2_STOP_Pos                                    (2U)
#define    I2CSMB_CR2_STOP_Msk                                    (0x1U << I2CSMB_CR2_STOP_Pos)
#define    I2CSMB_CR2_STOP                                        I2CSMB_CR2_STOP_Msk

#define    I2CSMB_CR2_RESTART_Pos                                 (1U)
#define    I2CSMB_CR2_RESTART_Msk                                 (0x1U << I2CSMB_CR2_RESTART_Pos)
#define    I2CSMB_CR2_RESTART                                     I2CSMB_CR2_RESTART_Msk

#define    I2CSMB_CR2_START_Pos                                   (0U)
#define    I2CSMB_CR2_START_Msk                                   (0x1U << I2CSMB_CR2_START_Pos)
#define    I2CSMB_CR2_START                                       I2CSMB_CR2_START_Msk

#define    I2CSMB_IER_IDLIE_Pos                                   (7U)
#define    I2CSMB_IER_IDLIE_Msk                                   (0x1U << I2CSMB_IER_IDLIE_Pos)
#define    I2CSMB_IER_IDLIE                                       I2CSMB_IER_IDLIE_Msk

#define    I2CSMB_IER_ERRIE_Pos                                   (6U)
#define    I2CSMB_IER_ERRIE_Msk                                   (0x1U << I2CSMB_IER_ERRIE_Pos)
#define    I2CSMB_IER_ERRIE                                       I2CSMB_IER_ERRIE_Msk

#define    I2CSMB_IER_SIE_Pos                                     (5U)
#define    I2CSMB_IER_SIE_Msk                                     (0x1U << I2CSMB_IER_SIE_Pos)
#define    I2CSMB_IER_SIE                                         I2CSMB_IER_SIE_Msk

#define    I2CSMB_IER_PIE_Pos                                     (4U)
#define    I2CSMB_IER_PIE_Msk                                     (0x1U << I2CSMB_IER_PIE_Pos)
#define    I2CSMB_IER_PIE                                         I2CSMB_IER_PIE_Msk

#define    I2CSMB_IER_NACKIE_Pos                                  (3U)
#define    I2CSMB_IER_NACKIE_Msk                                  (0x1U << I2CSMB_IER_NACKIE_Pos)
#define    I2CSMB_IER_NACKIE                                      I2CSMB_IER_NACKIE_Msk

#define    I2CSMB_IER_ADIE_Pos                                    (2U)
#define    I2CSMB_IER_ADIE_Msk                                    (0x1U << I2CSMB_IER_ADIE_Pos)
#define    I2CSMB_IER_ADIE                                        I2CSMB_IER_ADIE_Msk

#define    I2CSMB_IER_TXIE_Pos                                    (1U)
#define    I2CSMB_IER_TXIE_Msk                                    (0x1U << I2CSMB_IER_TXIE_Pos)
#define    I2CSMB_IER_TXIE                                        I2CSMB_IER_TXIE_Msk

#define    I2CSMB_IER_RXIE_Pos                                    (0U)
#define    I2CSMB_IER_RXIE_Msk                                    (0x1U << I2CSMB_IER_RXIE_Pos)
#define    I2CSMB_IER_RXIE                                        I2CSMB_IER_RXIE_Msk

#define    I2CSMB_ISR_SDIR_Pos                                    (16U)
#define    I2CSMB_ISR_SDIR_Msk                                    (0x1U << I2CSMB_ISR_SDIR_Pos)
#define    I2CSMB_ISR_SDIR                                        I2CSMB_ISR_SDIR_Msk

#define    I2CSMB_ISR_ALIF_Pos                                    (13U)
#define    I2CSMB_ISR_ALIF_Msk                                    (0x1U << I2CSMB_ISR_ALIF_Pos)
#define    I2CSMB_ISR_ALIF                                        I2CSMB_ISR_ALIF_Msk

#define    I2CSMB_ISR_TOB_Pos                                     (12U)
#define    I2CSMB_ISR_TOB_Msk                                     (0x1U << I2CSMB_ISR_TOB_Pos)
#define    I2CSMB_ISR_TOB                                         I2CSMB_ISR_TOB_Msk

#define    I2CSMB_ISR_TOA_Pos                                     (11U)
#define    I2CSMB_ISR_TOA_Msk                                     (0x1U << I2CSMB_ISR_TOA_Pos)
#define    I2CSMB_ISR_TOA                                         I2CSMB_ISR_TOA_Msk

#define    I2CSMB_ISR_OVF_Pos                                     (10U)
#define    I2CSMB_ISR_OVF_Msk                                     (0x1U << I2CSMB_ISR_OVF_Pos)
#define    I2CSMB_ISR_OVF                                         I2CSMB_ISR_OVF_Msk

#define    I2CSMB_ISR_BERR_Pos                                    (9U)
#define    I2CSMB_ISR_BERR_Msk                                    (0x1U << I2CSMB_ISR_BERR_Pos)
#define    I2CSMB_ISR_BERR                                        I2CSMB_ISR_BERR_Msk

#define    I2CSMB_ISR_ARLO_Pos                                    (8U)
#define    I2CSMB_ISR_ARLO_Msk                                    (0x1U << I2CSMB_ISR_ARLO_Pos)
#define    I2CSMB_ISR_ARLO                                        I2CSMB_ISR_ARLO_Msk

#define    I2CSMB_ISR_BUSY_Pos                                    (7U)
#define    I2CSMB_ISR_BUSY_Msk                                    (0x1U << I2CSMB_ISR_BUSY_Pos)
#define    I2CSMB_ISR_BUSY                                        I2CSMB_ISR_BUSY_Msk

#define    I2CSMB_ISR_IDLIF_Pos                                   (6U)
#define    I2CSMB_ISR_IDLIF_Msk                                   (0x1U << I2CSMB_ISR_IDLIF_Pos)
#define    I2CSMB_ISR_IDLIF                                       I2CSMB_ISR_IDLIF_Msk

#define    I2CSMB_ISR_SIF_Pos                                     (5U)
#define    I2CSMB_ISR_SIF_Msk                                     (0x1U << I2CSMB_ISR_SIF_Pos)
#define    I2CSMB_ISR_SIF                                         I2CSMB_ISR_SIF_Msk

#define    I2CSMB_ISR_PIF_Pos                                     (4U)
#define    I2CSMB_ISR_PIF_Msk                                     (0x1U << I2CSMB_ISR_PIF_Pos)
#define    I2CSMB_ISR_PIF                                         I2CSMB_ISR_PIF_Msk

#define    I2CSMB_ISR_NACKIF_Pos                                  (3U)
#define    I2CSMB_ISR_NACKIF_Msk                                  (0x1U << I2CSMB_ISR_NACKIF_Pos)
#define    I2CSMB_ISR_NACKIF                                      I2CSMB_ISR_NACKIF_Msk

#define    I2CSMB_ISR_ADIF_Pos                                    (2U)
#define    I2CSMB_ISR_ADIF_Msk                                    (0x1U << I2CSMB_ISR_ADIF_Pos)
#define    I2CSMB_ISR_ADIF                                        I2CSMB_ISR_ADIF_Msk

#define    I2CSMB_ISR_TXIF_Pos                                    (1U)
#define    I2CSMB_ISR_TXIF_Msk                                    (0x1U << I2CSMB_ISR_TXIF_Pos)
#define    I2CSMB_ISR_TXIF                                        I2CSMB_ISR_TXIF_Msk

#define    I2CSMB_ISR_RXIF_Pos                                    (0U)
#define    I2CSMB_ISR_RXIF_Msk                                    (0x1U << I2CSMB_ISR_RXIF_Pos)
#define    I2CSMB_ISR_RXIF                                        I2CSMB_ISR_RXIF_Msk

#define    I2CSMB_BGR_BGRH_Pos                                    (16U)
#define    I2CSMB_BGR_BGRH_Msk                                    (0x1ffU << I2CSMB_BGR_BGRH_Pos)
#define    I2CSMB_BGR_BGRH                                        I2CSMB_BGR_BGRH_Msk

#define    I2CSMB_BGR_BGRL_Pos                                    (0U)
#define    I2CSMB_BGR_BGRL_Msk                                    (0x1ffU << I2CSMB_BGR_BGRL_Pos)
#define    I2CSMB_BGR_BGRL                                        I2CSMB_BGR_BGRL_Msk

#define    I2CSMB_TCR_SDAHD_Pos                                   (0U)
#define    I2CSMB_TCR_SDAHD_Msk                                   (0x1ffU << I2CSMB_TCR_SDAHD_Pos)
#define    I2CSMB_TCR_SDAHD                                       I2CSMB_TCR_SDAHD_Msk

#define    I2CSMB_TOR_TEXTEN_Pos                                  (31U)
#define    I2CSMB_TOR_TEXTEN_Msk                                  (0x1U << I2CSMB_TOR_TEXTEN_Pos)
#define    I2CSMB_TOR_TEXTEN                                      I2CSMB_TOR_TEXTEN_Msk

#define    I2CSMB_TOR_TIMEOUTB_Pos                                (16U)
#define    I2CSMB_TOR_TIMEOUTB_Msk                                (0xfffU << I2CSMB_TOR_TIMEOUTB_Pos)
#define    I2CSMB_TOR_TIMEOUTB                                    I2CSMB_TOR_TIMEOUTB_Msk

#define    I2CSMB_TOR_TOEN_Pos                                    (15U)
#define    I2CSMB_TOR_TOEN_Msk                                    (0x1U << I2CSMB_TOR_TOEN_Pos)
#define    I2CSMB_TOR_TOEN                                        I2CSMB_TOR_TOEN_Msk

#define    I2CSMB_TOR_TIDLE_Pos                                   (12U)
#define    I2CSMB_TOR_TIDLE_Msk                                   (0x1U << I2CSMB_TOR_TIDLE_Pos)
#define    I2CSMB_TOR_TIDLE                                       I2CSMB_TOR_TIDLE_Msk

#define    I2CSMB_TOR_TIMEOUTA_Pos                                (0U)
#define    I2CSMB_TOR_TIMEOUTA_Msk                                (0xfffU << I2CSMB_TOR_TIMEOUTA_Pos)
#define    I2CSMB_TOR_TIMEOUTA                                    I2CSMB_TOR_TIMEOUTA_Msk

#define    I2CSMB_RXBUF_RXDATA_Pos                                (0U)
#define    I2CSMB_RXBUF_RXDATA_Msk                                (0xffU << I2CSMB_RXBUF_RXDATA_Pos)
#define    I2CSMB_RXBUF_RXDATA                                    I2CSMB_RXBUF_RXDATA_Msk

#define    I2CSMB_TXBUF_TXDATA_Pos                                (0U)
#define    I2CSMB_TXBUF_TXDATA_Msk                                (0xffU << I2CSMB_TXBUF_TXDATA_Pos)
#define    I2CSMB_TXBUF_TXDATA                                    I2CSMB_TXBUF_TXDATA_Msk

#define    I2CSMB_SADR_SAEN_Pos                                   (15U)
#define    I2CSMB_SADR_SAEN_Msk                                   (0x1U << I2CSMB_SADR_SAEN_Pos)
#define    I2CSMB_SADR_SAEN                                       I2CSMB_SADR_SAEN_Msk

#define    I2CSMB_SADR_MASK_Pos                                   (12U)
#define    I2CSMB_SADR_MASK_Msk                                   (0x7U << I2CSMB_SADR_MASK_Pos)
#define    I2CSMB_SADR_MASK                                       I2CSMB_SADR_MASK_Msk

#define    I2CSMB_SADR_ADDR_Pos                                   (0U)
#define    I2CSMB_SADR_ADDR_Msk                                   (0x3ffU << I2CSMB_SADR_ADDR_Pos)
#define    I2CSMB_SADR_ADDR                                       I2CSMB_SADR_ADDR_Msk

#define    I2CSMB_CRCDR_DR_Pos                                    (0U)
#define    I2CSMB_CRCDR_DR_Msk                                    (0xffU << I2CSMB_CRCDR_DR_Pos)
#define    I2CSMB_CRCDR_DR                                        I2CSMB_CRCDR_DR_Msk

#define    I2CSMB_CRCLFSR_LFSR_Pos                                (0U)
#define    I2CSMB_CRCLFSR_LFSR_Msk                                (0xffU << I2CSMB_CRCLFSR_LFSR_Pos)
#define    I2CSMB_CRCLFSR_LFSR                                    I2CSMB_CRCLFSR_LFSR_Msk

#define    I2CSMB_CRCPOLY_POLY_Pos                                (0U)
#define    I2CSMB_CRCPOLY_POLY_Msk                                (0xffU << I2CSMB_CRCPOLY_POLY_Pos)
#define    I2CSMB_CRCPOLY_POLY                                    I2CSMB_CRCPOLY_POLY_Msk

#define    FL_I2CSMB_DIGITAL_FILTER_CLK_DISABLE                   (0x0U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_1                         (0x1U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_2                         (0x2U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_3                         (0x3U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_4                         (0x4U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_5                         (0x5U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_6                         (0x6U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_7                         (0x7U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_8                         (0x8U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_9                         (0x9U << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_10                        (0xaU << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_11                        (0xbU << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_12                        (0xcU << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_13                        (0xdU << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_14                        (0xeU << I2CSMB_CR1_DNF_Pos)
#define    FL_I2CSMB_DIGITAL_FILTER_CLK_15                        (0xfU << I2CSMB_CR1_DNF_Pos)

#define    FL_I2CSMB_WAKEUP_DISABLE                               (0x0U << I2CSMB_CR1_WKUPEN_Pos)
#define    FL_I2CSMB_WAKEUP_START_ONLY                            (0x1U << I2CSMB_CR1_WKUPEN_Pos)
#define    FL_I2CSMB_WAKEUP_START_BOTH                            (0x2U << I2CSMB_CR1_WKUPEN_Pos)
#define    FL_I2CSMB_WAKEUP_START_ADDRESS                         (0x3U << I2CSMB_CR1_WKUPEN_Pos)

#define    FL_I2CSMB_ALERT_STATUS_HIGH                            (0x0U << I2CSMB_CR2_ALERT_Pos)
#define    FL_I2CSMB_ALERT_STATUS_LOW                             (0x1U << I2CSMB_CR2_ALERT_Pos)

#define    FL_I2CSMB_RESPOND_ACK                                  (0x0U << I2CSMB_CR2_ACKEN_Pos)
#define    FL_I2CSMB_RESPOND_NACK                                 (0x1U << I2CSMB_CR2_ACKEN_Pos)

#define    FL_I2CSMB_MASTER_WRITE                                 (0x0U << I2CSMB_CR2_RWN_Pos)
#define    FL_I2CSMB_MASTER_READ                                  (0x1U << I2CSMB_CR2_RWN_Pos)

#define    FL_I2CSMB_TIMEOUTA_MODE_SCL                            (0x0U << I2CSMB_TOR_TIDLE_Pos)
#define    FL_I2CSMB_TIMEOUTA_MODE_IDLE                           (0x1U << I2CSMB_TOR_TIDLE_Pos)

#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_NONE                      (0x0U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT0                      (0x1U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT1                      (0x2U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT2                      (0x3U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT3                      (0x4U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT4                      (0x5U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT5                      (0x6U << I2CSMB_SADR_MASK_Pos)
#define    FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT6                      (0x7U << I2CSMB_SADR_MASK_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup I2C_SMBUS_FL_Exported_Functions I2C_SMBUS Exported Functions
  * @{
  */

/**
  * @brief    I2C_SMB enable
  * @rmtoll   CR1    EN    FL_I2CSMB_Enable
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_Enable(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_EN_Msk);
}

/**
  * @brief    Get I2C_SMB enable status
  * @rmtoll   CR1    EN    FL_I2CSMB_IsEnabled
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabled(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_EN_Msk) == I2CSMB_CR1_EN_Msk);
}

/**
  * @brief    I2C_SMB disable
  * @rmtoll   CR1    EN    FL_I2CSMB_Disable
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_Disable(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_EN_Msk);
}

/**
  * @brief    SCL time out enable
  * @rmtoll   CR1    A10EN    FL_I2CSMB_Enable10BitAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_Enable10BitAddress(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_A10EN_Msk);
}

/**
  * @brief    Get SCL time out enable status
  * @rmtoll   CR1    A10EN    FL_I2CSMB_IsEnabled10BitAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabled10BitAddress(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_A10EN_Msk) == I2CSMB_CR1_A10EN_Msk);
}

/**
  * @brief    SCL time out disable
  * @rmtoll   CR1    A10EN    FL_I2CSMB_Disable10BitAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_Disable10BitAddress(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_A10EN_Msk);
}

/**
  * @brief    CRC enable
  * @rmtoll   CR1    CRCEN    FL_I2CSMB_EnableCRC
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableCRC(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_CRCEN_Msk);
}

/**
  * @brief    Get CRC enable status
  * @rmtoll   CR1    CRCEN    FL_I2CSMB_IsEnabledCRC
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledCRC(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_CRCEN_Msk) == I2CSMB_CR1_CRCEN_Msk);
}

/**
  * @brief    CRC disable
  * @rmtoll   CR1    CRCEN    FL_I2CSMB_DisableCRC
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableCRC(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_CRCEN_Msk);
}

/**
  * @brief    Set digitalfilter length
  * @rmtoll   CR1    DNF    FL_I2CSMB_SetDigitalFilterLength
  * @param    I2CSMBx I2CSMB instance
  * @param    length This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_DISABLE
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_1
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_2
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_3
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_4
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_5
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_6
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_7
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_8
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_9
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_10
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_11
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_12
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_13
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_14
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_15
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetDigitalFilterLength(I2CSMB_Type *I2CSMBx, uint32_t length)
{
    MODIFY_REG(I2CSMBx->CR1, I2CSMB_CR1_DNF_Msk, length);
}

/**
  * @brief    Get digital filter length
  * @rmtoll   CR1    DNF    FL_I2CSMB_GetDigitalFilterLength
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_DISABLE
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_1
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_2
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_3
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_4
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_5
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_6
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_7
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_8
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_9
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_10
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_11
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_12
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_13
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_14
  *           @arg @ref FL_I2CSMB_DIGITAL_FILTER_CLK_15
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetDigitalFilterLength(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_DNF_Msk));
}

/**
  * @brief    Analog Noise Filter enable
  * @rmtoll   CR1    ANFEN    FL_I2CSMB_EnableAnalogNoiseFilter
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableAnalogNoiseFilter(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_ANFEN_Msk);
}

/**
  * @brief    Get Analog Noise Filter enable status
  * @rmtoll   CR1    ANFEN    FL_I2CSMB_IsEnabledAnalogNoiseFilter
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledAnalogNoiseFilter(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_ANFEN_Msk) == I2CSMB_CR1_ANFEN_Msk);
}

/**
  * @brief    Analog Noise Filter disable
  * @rmtoll   CR1    ANFEN    FL_I2CSMB_DisableAnalogNoiseFilter
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableAnalogNoiseFilter(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_ANFEN_Msk);
}

/**
  * @brief    Transmit DMA enable
  * @rmtoll   CR1    TXDMAEN    FL_I2CSMB_EnableTXDMA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableTXDMA(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_TXDMAEN_Msk);
}

/**
  * @brief    GetTransmit DMA enable status
  * @rmtoll   CR1    TXDMAEN    FL_I2CSMB_IsEnabledTXDMA
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledTXDMA(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_TXDMAEN_Msk) == I2CSMB_CR1_TXDMAEN_Msk);
}

/**
  * @brief    Transmit DMA disable
  * @rmtoll   CR1    TXDMAEN    FL_I2CSMB_DisableTXDMA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableTXDMA(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_TXDMAEN_Msk);
}

/**
  * @brief    Receive DMA enable
  * @rmtoll   CR1    RXDMAEN    FL_I2CSMB_EnableRXDMA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableRXDMA(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_RXDMAEN_Msk);
}

/**
  * @brief    GetReceive DMA enable status
  * @rmtoll   CR1    RXDMAEN    FL_I2CSMB_IsEnabledRXDMA
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledRXDMA(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_RXDMAEN_Msk) == I2CSMB_CR1_RXDMAEN_Msk);
}

/**
  * @brief    Receive DMA disable
  * @rmtoll   CR1    RXDMAEN    FL_I2CSMB_DisableRXDMA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableRXDMA(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_RXDMAEN_Msk);
}

/**
  * @brief    SlaveSCLStretching enable
  * @rmtoll   CR1    SCLSEN    FL_I2CSMB_EnableSlaveSCLStretching
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableSlaveSCLStretching(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_SCLSEN_Msk);
}

/**
  * @brief    Get SlaveSCLStretching enable status
  * @rmtoll   CR1    SCLSEN    FL_I2CSMB_IsEnabledSlaveSCLStretching
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledSlaveSCLStretching(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_SCLSEN_Msk) == I2CSMB_CR1_SCLSEN_Msk);
}

/**
  * @brief    SlaveSCLStretching disable
  * @rmtoll   CR1    SCLSEN    FL_I2CSMB_DisableSlaveSCLStretching
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableSlaveSCLStretching(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_SCLSEN_Msk);
}

/**
  * @brief    SMBus wakeup enable
  * @rmtoll   CR1    WKUPEN    FL_I2CSMB_SetWakeupSource
  * @param    I2CSMBx I2CSMB instance
  * @param    source This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_WAKEUP_DISABLE
  *           @arg @ref FL_I2CSMB_WAKEUP_START_ONLY
  *           @arg @ref FL_I2CSMB_WAKEUP_START_BOTH
  *           @arg @ref FL_I2CSMB_WAKEUP_START_ADDRESS
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetWakeupSource(I2CSMB_Type *I2CSMBx, uint32_t source)
{
    MODIFY_REG(I2CSMBx->CR1, I2CSMB_CR1_WKUPEN_Msk, source);
}

/**
  * @brief    Get SMBus wakeup enable status
  * @rmtoll   CR1    WKUPEN    FL_I2CSMB_GetWakeupSource
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_WAKEUP_DISABLE
  *           @arg @ref FL_I2CSMB_WAKEUP_START_ONLY
  *           @arg @ref FL_I2CSMB_WAKEUP_START_BOTH
  *           @arg @ref FL_I2CSMB_WAKEUP_START_ADDRESS
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetWakeupSource(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_WKUPEN_Msk));
}

/**
  * @brief    General Call enable
  * @rmtoll   CR1    GCEN    FL_I2CSMB_EnableGeneralCall
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableGeneralCall(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_GCEN_Msk);
}

/**
  * @brief    Get General Call enable status
  * @rmtoll   CR1    GCEN    FL_I2CSMB_IsEnabledGeneralCall
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledGeneralCall(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_GCEN_Msk) == I2CSMB_CR1_GCEN_Msk);
}

/**
  * @brief    General Call disable
  * @rmtoll   CR1    GCEN    FL_I2CSMB_DisableGeneralCall
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableGeneralCall(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_GCEN_Msk);
}

/**
  * @brief    SMBus host address enable
  * @rmtoll   CR1    SMBHEN    FL_I2CSMB_EnableHostAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableHostAddress(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_SMBHEN_Msk);
}

/**
  * @brief    Get SMBus host address enable status
  * @rmtoll   CR1    SMBHEN    FL_I2CSMB_IsEnabledHostAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledHostAddress(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_SMBHEN_Msk) == I2CSMB_CR1_SMBHEN_Msk);
}

/**
  * @brief    SMBus host address disable
  * @rmtoll   CR1    SMBHEN    FL_I2CSMB_DisableHostAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableHostAddress(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_SMBHEN_Msk);
}

/**
  * @brief    SMBus device default address enable
  * @rmtoll   CR1    SMBDEN    FL_I2CSMB_EnableDeviceDefaultAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableDeviceDefaultAddress(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_SMBDEN_Msk);
}

/**
  * @brief    Get SMBus device default address enable status
  * @rmtoll   CR1    SMBDEN    FL_I2CSMB_IsEnabledDeviceDefaultAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledDeviceDefaultAddress(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_SMBDEN_Msk) == I2CSMB_CR1_SMBDEN_Msk);
}

/**
  * @brief    SMBus device default address disable
  * @rmtoll   CR1    SMBDEN    FL_I2CSMB_DisableDeviceDefaultAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableDeviceDefaultAddress(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_SMBDEN_Msk);
}

/**
  * @brief    SMBus Alert pin enable
  * @rmtoll   CR1    ALERTEN    FL_I2CSMB_EnableAlert
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableAlert(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_ALERTEN_Msk);
}

/**
  * @brief    Get SMBus Alert pin enable status
  * @rmtoll   CR1    ALERTEN    FL_I2CSMB_IsEnabledAlert
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledAlert(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_ALERTEN_Msk) == I2CSMB_CR1_ALERTEN_Msk);
}

/**
  * @brief    SMBus Alert pin disable
  * @rmtoll   CR1    ALERTEN    FL_I2CSMB_DisableMasterAlert
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableMasterAlert(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_ALERTEN_Msk);
}

/**
  * @brief    Master DMA automatic transfer end enable
  * @rmtoll   CR1    AUTOEND    FL_I2CSMB_EnableMasterAutoStop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableMasterAutoStop(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR1, I2CSMB_CR1_AUTOEND_Msk);
}

/**
  * @brief    Get master DMA automatic transfer end enable status
  * @rmtoll   CR1    AUTOEND    FL_I2CSMB_IsEnabledMasterAutoStop
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledMasterAutoStop(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR1, I2CSMB_CR1_AUTOEND_Msk) == I2CSMB_CR1_AUTOEND_Msk);
}

/**
  * @brief    Master DMA automatic transfer end disable
  * @rmtoll   CR1    AUTOEND    FL_I2CSMB_DisableMasterAutoStop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableMasterAutoStop(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR1, I2CSMB_CR1_AUTOEND_Msk);
}

/**
  * @brief    Set Alert pin status
  * @rmtoll   CR2    ALERT    FL_I2CSMB_SetAlertPinStatus
  * @param    I2CSMBx I2CSMB instance
  * @param    status This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_ALERT_STATUS_HIGH
  *           @arg @ref FL_I2CSMB_ALERT_STATUS_LOW
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetAlertPinStatus(I2CSMB_Type *I2CSMBx, uint32_t status)
{
    MODIFY_REG(I2CSMBx->CR2, I2CSMB_CR2_ALERT_Msk, status);
}

/**
  * @brief    Get Alert pin status
  * @rmtoll   CR2    ALERT    FL_I2CSMB_GetAlertPinStatus
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_ALERT_STATUS_HIGH
  *           @arg @ref FL_I2CSMB_ALERT_STATUS_LOW
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetAlertPinStatus(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR2, I2CSMB_CR2_ALERT_Msk));
}

/**
  * @brief    Set ACK  output
  * @rmtoll   CR2    ACKEN    FL_I2CSMB_SetRespond
  * @param    I2CSMBx I2CSMB instance
  * @param    respond This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_RESPOND_ACK
  *           @arg @ref FL_I2CSMB_RESPOND_NACK
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetRespond(I2CSMB_Type *I2CSMBx, uint32_t respond)
{
    MODIFY_REG(I2CSMBx->CR2, I2CSMB_CR2_ACKEN_Msk, respond);
}

/**
  * @brief    Get ACK  output
  * @rmtoll   CR2    ACKEN    FL_I2CSMB_GetRespond
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_RESPOND_ACK
  *           @arg @ref FL_I2CSMB_RESPOND_NACK
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetRespond(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR2, I2CSMB_CR2_ACKEN_Msk));
}

/**
  * @brief    Set master transmit direction
  * @rmtoll   CR2    RWN    FL_I2CSMB_SetMasterDirection
  * @param    I2CSMBx I2CSMB instance
  * @param    direction This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_MASTER_WRITE
  *           @arg @ref FL_I2CSMB_MASTER_READ
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetMasterDirection(I2CSMB_Type *I2CSMBx, uint32_t direction)
{
    MODIFY_REG(I2CSMBx->CR2, I2CSMB_CR2_RWN_Msk, direction);
}

/**
  * @brief    Get master transmit direction
  * @rmtoll   CR2    RWN    FL_I2CSMB_GetMasterDirection
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_MASTER_WRITE
  *           @arg @ref FL_I2CSMB_MASTER_READ
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetMasterDirection(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR2, I2CSMB_CR2_RWN_Msk));
}

/**
  * @brief    Stop enable
  * @rmtoll   CR2    STOP    FL_I2CSMB_EnableStop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableStop(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR2, I2CSMB_CR2_STOP_Msk);
}

/**
  * @brief    Get Stop enable status
  * @rmtoll   CR2    STOP    FL_I2CSMB_IsEnabledStop
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledStop(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR2, I2CSMB_CR2_STOP_Msk) == I2CSMB_CR2_STOP_Msk);
}

/**
  * @brief    Stop disable
  * @rmtoll   CR2    STOP    FL_I2CSMB_DisableStop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableStop(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR2, I2CSMB_CR2_STOP_Msk);
}

/**
  * @brief    Reatart enable
  * @rmtoll   CR2    RESTART    FL_I2CSMB_EnableRestart
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableRestart(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR2, I2CSMB_CR2_RESTART_Msk);
}

/**
  * @brief    Get Reatart enable status
  * @rmtoll   CR2    RESTART    FL_I2CSMB_IsEnabledRestart
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledRestart(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR2, I2CSMB_CR2_RESTART_Msk) == I2CSMB_CR2_RESTART_Msk);
}

/**
  * @brief    Reatart disable
  * @rmtoll   CR2    RESTART    FL_I2CSMB_DisableRestart
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableRestart(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR2, I2CSMB_CR2_RESTART_Msk);
}

/**
  * @brief    Start enable
  * @rmtoll   CR2    START    FL_I2CSMB_EnableStart
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableStart(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->CR2, I2CSMB_CR2_START_Msk);
}

/**
  * @brief    Get Start enable status
  * @rmtoll   CR2    START    FL_I2CSMB_IsEnabledStart
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledStart(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CR2, I2CSMB_CR2_START_Msk) == I2CSMB_CR2_START_Msk);
}

/**
  * @brief    Start disable
  * @rmtoll   CR2    START    FL_I2CSMB_DisableStart
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableStart(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->CR2, I2CSMB_CR2_START_Msk);
}

/**
  * @brief    IDLE disable
  * @rmtoll   IER    IDLIE    FL_I2CSMB_DisableIT_IDLE
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_IDLE(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_IDLIE_Msk);
}

/**
  * @brief    IDLE enable
  * @rmtoll   IER    IDLIE    FL_I2CSMB_EnableIT_IDLE
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_IDLE(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_IDLIE_Msk);
}

/**
  * @brief    Get IDLE enable status
  * @rmtoll   IER    IDLIE    FL_I2CSMB_IsEnabledIT_IDLE
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_IDLE(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_IDLIE_Msk) == I2CSMB_IER_IDLIE_Msk);
}

/**
  * @brief    ErrorEvent interrupt disable
  * @rmtoll   IER    ERRIE    FL_I2CSMB_DisableIT_ErrorEvent
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_ErrorEvent(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_ERRIE_Msk);
}

/**
  * @brief    ErrorEvent interrupt enable
  * @rmtoll   IER    ERRIE    FL_I2CSMB_EnableIT_ErrorEvent
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_ErrorEvent(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_ERRIE_Msk);
}

/**
  * @brief    Get ErrorEvent interrupt enable status
  * @rmtoll   IER    ERRIE    FL_I2CSMB_IsEnabledIT_ErrorEvent
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_ErrorEvent(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_ERRIE_Msk) == I2CSMB_IER_ERRIE_Msk);
}

/**
  * @brief    START interrupt disable
  * @rmtoll   IER    SIE    FL_I2CSMB_DisableIT_Start
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_Start(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_SIE_Msk);
}

/**
  * @brief    START interrupt enable
  * @rmtoll   IER    SIE    FL_I2CSMB_EnableIT_Start
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_Start(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_SIE_Msk);
}

/**
  * @brief    Get START interrupt enable status
  * @rmtoll   IER    SIE    FL_I2CSMB_IsEnabledIT_Start
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_Start(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_SIE_Msk) == I2CSMB_IER_SIE_Msk);
}

/**
  * @brief    Stop interrupt enable
  * @rmtoll   IER    PIE    FL_I2CSMB_EnableIT_Stop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_Stop(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_PIE_Msk);
}

/**
  * @brief    Get Stop interrupt enable status
  * @rmtoll   IER    PIE    FL_I2CSMB_IsEnabledIT_Stop
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_Stop(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_PIE_Msk) == I2CSMB_IER_PIE_Msk);
}

/**
  * @brief    Stop interrupt disable
  * @rmtoll   IER    PIE    FL_I2CSMB_DisableIT_Stop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_Stop(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_PIE_Msk);
}

/**
  * @brief    Non-ACK interrupt enable
  * @rmtoll   IER    NACKIE    FL_I2CSMB_EnableIT_NACK
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_NACK(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_NACKIE_Msk);
}

/**
  * @brief    Get Non-ACK interrupt enable status
  * @rmtoll   IER    NACKIE    FL_I2CSMB_IsEnabledIT_NACK
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_NACK(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_NACKIE_Msk) == I2CSMB_IER_NACKIE_Msk);
}

/**
  * @brief    Non-ACK interrupt disable
  * @rmtoll   IER    NACKIE    FL_I2CSMB_DisableIT_NACK
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_NACK(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_NACKIE_Msk);
}

/**
  * @brief    Address match interrupt enable
  * @rmtoll   IER    ADIE    FL_I2CSMB_EnableIT_SlaveAddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_SlaveAddressMatch(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_ADIE_Msk);
}

/**
  * @brief    Get slave address match interrupt enable status
  * @rmtoll   IER    ADIE    FL_I2CSMB_IsEnabledIT_SlaveAddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_SlaveAddressMatch(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_ADIE_Msk) == I2CSMB_IER_ADIE_Msk);
}

/**
  * @brief    Slave address match interrupt disable
  * @rmtoll   IER    ADIE    FL_I2CSMB_DisableIT_SlaveAddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_SlaveAddressMatch(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_ADIE_Msk);
}

/**
  * @brief    Trasnmit done interrupt enable
  * @rmtoll   IER    TXIE    FL_I2CSMB_EnableIT_TXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_TXComplete(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_TXIE_Msk);
}

/**
  * @brief    Get trasnmit done interrupt enable
  * @rmtoll   IER    TXIE    FL_I2CSMB_IsEnabledIT_TXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_TXComplete(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_TXIE_Msk) == I2CSMB_IER_TXIE_Msk);
}

/**
  * @brief    Trasnmit done interrupt disable
  * @rmtoll   IER    TXIE    FL_I2CSMB_DisableIT_TXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_TXComplete(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_TXIE_Msk);
}

/**
  * @brief    Receive done interrupt enable
  * @rmtoll   IER    RXIE    FL_I2CSMB_EnableIT_RXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableIT_RXComplete(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->IER, I2CSMB_IER_RXIE_Msk);
}

/**
  * @brief    Get receive done interrupt enable status
  * @rmtoll   IER    RXIE    FL_I2CSMB_IsEnabledIT_RXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledIT_RXComplete(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->IER, I2CSMB_IER_RXIE_Msk) == I2CSMB_IER_RXIE_Msk);
}

/**
  * @brief    Receive done interrupt disable
  * @rmtoll   IER    RXIE    FL_I2CSMB_DisableIT_RXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableIT_RXComplete(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->IER, I2CSMB_IER_RXIE_Msk);
}

/**
  * @brief    Get Slave Direction
  * @rmtoll   ISR    SDIR    FL_I2CSMB_IsActiveFlag_SlaveDirection
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_SlaveDirection(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_SDIR_Msk) == (I2CSMB_ISR_SDIR_Msk));
}

/**
  * @brief    Get Alert flag
  * @rmtoll   ISR    ALIF    FL_I2CSMB_IsActiveFlag_Alert
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_Alert(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_ALIF_Msk) == (I2CSMB_ISR_ALIF_Msk));
}

/**
  * @brief    Clear Alert flag
  * @rmtoll   ISR    ALIF    FL_I2CSMB_ClearFlag_Alert
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_Alert(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_ALIF_Msk);
}

/**
  * @brief    Get Timeout B Flag
  * @rmtoll   ISR    TOB    FL_I2CSMB_IsActiveFlag_TimeoutB
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_TimeoutB(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_TOB_Msk) == (I2CSMB_ISR_TOB_Msk));
}

/**
  * @brief    Clear Timeout B flag
  * @rmtoll   ISR    TOB    FL_I2CSMB_ClearFlag_TimeoutB
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_TimeoutB(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_TOB_Msk);
}

/**
  * @brief    Get Timeout A Flag
  * @rmtoll   ISR    TOA    FL_I2CSMB_IsActiveFlag_TimeoutA
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_TimeoutA(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_TOA_Msk) == (I2CSMB_ISR_TOA_Msk));
}

/**
  * @brief    Clear Timeout A flag
  * @rmtoll   ISR    TOA    FL_I2CSMB_ClearFlag_TimeoutA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_TimeoutA(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_TOA_Msk);
}

/**
  * @brief    Get overflow interrupt flag
  * @rmtoll   ISR    OVF    FL_I2CSMB_IsActiveFlag_Overflow
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_Overflow(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_OVF_Msk) == (I2CSMB_ISR_OVF_Msk));
}

/**
  * @brief    Clear overflow interrupt flag
  * @rmtoll   ISR    OVF    FL_I2CSMB_ClearFlag_Overflow
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_Overflow(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_OVF_Msk);
}

/**
  * @brief    Get bus error interrupt flag
  * @rmtoll   ISR    BERR    FL_I2CSMB_IsActiveFlag_BusError
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_BusError(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_BERR_Msk) == (I2CSMB_ISR_BERR_Msk));
}

/**
  * @brief    Clear bus error interrupt flag
  * @rmtoll   ISR    BERR    FL_I2CSMB_ClearFlag_BusError
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_BusError(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_BERR_Msk);
}

/**
  * @brief    Get bus IDLE interrupt flag
  * @rmtoll   ISR    IDLIF    FL_I2CSMB_IsActiveFlag_BusIDLE
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_BusIDLE(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_IDLIF_Msk) == (I2CSMB_ISR_IDLIF_Msk));
}

/**
  * @brief    Clear bus IDLE interrupt flag
  * @rmtoll   ISR    IDLIF    FL_I2CSMB_ClearFlag_BusIDLE
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_BusIDLE(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_IDLIF_Msk);
}

/**
  * @brief    Get Start interrupt flag
  * @rmtoll   ISR    SIF    FL_I2CSMB_IsActiveFlag_Start
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_Start(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_SIF_Msk) == (I2CSMB_ISR_SIF_Msk));
}

/**
  * @brief    Clear Start interrupt flag
  * @rmtoll   ISR    SIF    FL_I2CSMB_ClearFlag_Start
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_Start(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_SIF_Msk);
}

/**
  * @brief    Get Stop interrupt flag
  * @rmtoll   ISR    PIF    FL_I2CSMB_IsActiveFlag_Stop
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_Stop(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_PIF_Msk) == (I2CSMB_ISR_PIF_Msk));
}

/**
  * @brief    Clear Stor interrupt flag
  * @rmtoll   ISR    PIF    FL_I2CSMB_ClearFlag_Stop
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_Stop(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_PIF_Msk);
}

/**
  * @brief    Get acknowledge status flag
  * @rmtoll   ISR    NACKIF    FL_I2CSMB_IsActiveFlag_NACK
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_NACK(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_NACKIF_Msk) == (I2CSMB_ISR_NACKIF_Msk));
}

/**
  * @brief    Clear acknowledge status flag
  * @rmtoll   ISR    NACKIF    FL_I2CSMB_ClearFlag_NACK
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_NACK(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_NACKIF_Msk);
}

/**
  * @brief    Get address match interrupt flag
  * @rmtoll   ISR    ADIF    FL_I2CSMB_IsActiveFlag_AddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_AddressMatch(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_ADIF_Msk) == (I2CSMB_ISR_ADIF_Msk));
}

/**
  * @brief    Clear address match interrupt flag
  * @rmtoll   ISR    ADIF    FL_I2CSMB_ClearFlag_AddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_AddressMatch(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_ADIF_Msk);
}

/**
  * @brief    Get trasnmit done interrupt flag
  * @rmtoll   ISR    TXIF    FL_I2CSMB_IsActiveFlag_TXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_TXComplete(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_TXIF_Msk) == (I2CSMB_ISR_TXIF_Msk));
}

/**
  * @brief    Clear trasnmit done interrupt flag
  * @rmtoll   ISR    TXIF    FL_I2CSMB_ClearFlag_TXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_TXComplete(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_TXIF_Msk);
}

/**
  * @brief    Get receive done interrupt flag
  * @rmtoll   ISR    RXIF    FL_I2CSMB_IsActiveFlag_RXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsActiveFlag_RXComplete(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->ISR, I2CSMB_ISR_RXIF_Msk) == (I2CSMB_ISR_RXIF_Msk));
}

/**
  * @brief    Clear receive done interrupt flag
  * @rmtoll   ISR    RXIF    FL_I2CSMB_ClearFlag_RXComplete
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_ClearFlag_RXComplete(I2CSMB_Type *I2CSMBx)
{
    WRITE_REG(I2CSMBx->ISR, I2CSMB_ISR_RXIF_Msk);
}

/**
  * @brief    Set master SCL high level length
  * @rmtoll   BGR    BGRH    FL_I2CSMB_WriteSCLHighWidth
  * @param    I2CSMBx I2CSMB instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteSCLHighWidth(I2CSMB_Type *I2CSMBx, uint32_t width)
{
    MODIFY_REG(I2CSMBx->BGR, (0x1ffU << 16U), (width << 16U));
}

/**
  * @brief    Get master SCL high level length
  * @rmtoll   BGR    BGRH    FL_I2CSMB_ReadSCLHighWidth
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadSCLHighWidth(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->BGR, (0x1ffU << 16U)) >> 16U);
}

/**
  * @brief    Set master SCL low level length
  * @rmtoll   BGR    BGRL    FL_I2CSMB_WriteSCLLowWidth
  * @param    I2CSMBx I2CSMB instance
  * @param    width
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteSCLLowWidth(I2CSMB_Type *I2CSMBx, uint32_t width)
{
    MODIFY_REG(I2CSMBx->BGR, (0x1ffU << 0U), (width << 0U));
}

/**
  * @brief    Get master SCL low level length
  * @rmtoll   BGR    BGRL    FL_I2CSMB_ReadSCLLowWidth
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadSCLLowWidth(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->BGR, (0x1ffU << 0U)) >> 0U);
}

/**
  * @brief    Set SDA hold time
  * @rmtoll   TCR    SDAHD    FL_I2CSMB_WriteSDAHoldTime
  * @param    I2CSMBx I2CSMB instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteSDAHoldTime(I2CSMB_Type *I2CSMBx, uint32_t time)
{
    MODIFY_REG(I2CSMBx->TCR, (0x1ffU << 0U), (time << 0U));
}

/**
  * @brief    Get SDA hold time
  * @rmtoll   TCR    SDAHD    FL_I2CSMB_ReadSDAHoldTime
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadSDAHoldTime(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TCR, (0x1ffU << 0U)) >> 0U);
}

/**
  * @brief    Timeout enable
  * @rmtoll   TOR    TEXTEN    FL_I2CSMB_EnableTimeOutB
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableTimeOutB(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->TOR, I2CSMB_TOR_TEXTEN_Msk);
}

/**
  * @brief    Get timeout enable status
  * @rmtoll   TOR    TEXTEN    FL_I2CSMB_IsEnabledTimeOutB
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledTimeOutB(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TOR, I2CSMB_TOR_TEXTEN_Msk) == I2CSMB_TOR_TEXTEN_Msk);
}

/**
  * @brief    Timeout disable
  * @rmtoll   TOR    TEXTEN    FL_I2CSMB_DisableTimeOutB
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableTimeOutB(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->TOR, I2CSMB_TOR_TEXTEN_Msk);
}

/**
  * @brief    Set timeout numbers
  * @rmtoll   TOR    TIMEOUTB    FL_I2CSMB_WriteTimeOutBTime
  * @param    I2CSMBx I2CSMB instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteTimeOutBTime(I2CSMB_Type *I2CSMBx, uint32_t time)
{
    MODIFY_REG(I2CSMBx->TOR, (0xfffU << 16U), (time << 16U));
}

/**
  * @brief    Get timeout numbers
  * @rmtoll   TOR    TIMEOUTB    FL_I2CSMB_ReadTimeOutBTime
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadTimeOutBTime(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TOR, (0xfffU << 16U)) >> 16U);
}

/**
  * @brief    Timeout enable
  * @rmtoll   TOR    TOEN    FL_I2CSMB_EnableTimeOutA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableTimeOutA(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->TOR, I2CSMB_TOR_TOEN_Msk);
}

/**
  * @brief    Get timeout enable status
  * @rmtoll   TOR    TOEN    FL_I2CSMB_IsEnabledTimeOutA
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledTimeOutA(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TOR, I2CSMB_TOR_TOEN_Msk) == I2CSMB_TOR_TOEN_Msk);
}

/**
  * @brief    Timeout disable
  * @rmtoll   TOR    TOEN    FL_I2CSMB_DisableTimeOutA
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableTimeOutA(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->TOR, I2CSMB_TOR_TOEN_Msk);
}

/**
  * @brief    Set timeoutA mode
  * @rmtoll   TOR    TIDLE    FL_I2CSMB_SetTimeOutAMode
  * @param    I2CSMBx I2CSMB instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_TIMEOUTA_MODE_SCL
  *           @arg @ref FL_I2CSMB_TIMEOUTA_MODE_IDLE
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetTimeOutAMode(I2CSMB_Type *I2CSMBx, uint32_t mode)
{
    MODIFY_REG(I2CSMBx->TOR, I2CSMB_TOR_TIDLE_Msk, mode);
}

/**
  * @brief    Get timeoutA mode
  * @rmtoll   TOR    TIDLE    FL_I2CSMB_GetTimeOutAMode
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_TIMEOUTA_MODE_SCL
  *           @arg @ref FL_I2CSMB_TIMEOUTA_MODE_IDLE
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetTimeOutAMode(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TOR, I2CSMB_TOR_TIDLE_Msk));
}

/**
  * @brief    Set timeout numbers
  * @rmtoll   TOR    TIMEOUTA    FL_I2CSMB_WriteTimeOutATime
  * @param    I2CSMBx I2CSMB instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteTimeOutATime(I2CSMB_Type *I2CSMBx, uint32_t time)
{
    MODIFY_REG(I2CSMBx->TOR, (0xfffU << 0U), (time << 0U));
}

/**
  * @brief    Get timeout numbers
  * @rmtoll   TOR    TIMEOUTA    FL_I2CSMB_ReadTimeOutATime
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadTimeOutATime(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TOR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Get Rxbuff
  * @rmtoll   RXBUF    RXDATA    FL_I2CSMB_ReadRXBuff
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadRXBuff(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->RXBUF, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set TX Buff
  * @rmtoll   TXBUF    TXDATA    FL_I2CSMB_WriteTXBuff
  * @param    I2CSMBx I2CSMB instance
  * @param    data
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteTXBuff(I2CSMB_Type *I2CSMBx, uint32_t data)
{
    MODIFY_REG(I2CSMBx->TXBUF, (0xffU << 0U), (data << 0U));
}

/**
  * @brief    Get TX Buff
  * @rmtoll   TXBUF    TXDATA    FL_I2CSMB_ReadTXBuff
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadTXBuff(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->TXBUF, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    slave address match enable
  * @rmtoll   SADR    SAEN    FL_I2CSMB_EnableSlaveAddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_EnableSlaveAddressMatch(I2CSMB_Type *I2CSMBx)
{
    SET_BIT(I2CSMBx->SADR, I2CSMB_SADR_SAEN_Msk);
}

/**
  * @brief    Get slave address match enable status
  * @rmtoll   SADR    SAEN    FL_I2CSMB_IsEnabledSlaveAddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_I2CSMB_IsEnabledSlaveAddressMatch(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->SADR, I2CSMB_SADR_SAEN_Msk) == I2CSMB_SADR_SAEN_Msk);
}

/**
  * @brief    Slave address match disable
  * @rmtoll   SADR    SAEN    FL_I2CSMB_DisableSlaveAddressMatch
  * @param    I2CSMBx I2CSMB instance
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_DisableSlaveAddressMatch(I2CSMB_Type *I2CSMBx)
{
    CLEAR_BIT(I2CSMBx->SADR, I2CSMB_SADR_SAEN_Msk);
}

/**
  * @brief    Set slave address mask
  * @rmtoll   SADR    MASK    FL_I2CSMB_SetSlaveAddressMask
  * @param    I2CSMBx I2CSMB instance
  * @param    address This parameter can be one of the following values:
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_NONE
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT0
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT1
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT2
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT3
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT4
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT5
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT6
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_SetSlaveAddressMask(I2CSMB_Type *I2CSMBx, uint32_t address)
{
    MODIFY_REG(I2CSMBx->SADR, I2CSMB_SADR_MASK_Msk, address);
}

/**
  * @brief    Get slave address mask
  * @rmtoll   SADR    MASK    FL_I2CSMB_GetSlaveAddressMask
  * @param    I2CSMBx I2CSMB instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_NONE
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT0
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT1
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT2
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT3
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT4
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT5
  *           @arg @ref FL_I2CSMB_SLAVE_ADDRESS_MASK_BIT6
  */
__STATIC_INLINE uint32_t FL_I2CSMB_GetSlaveAddressMask(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->SADR, I2CSMB_SADR_MASK_Msk));
}

/**
  * @brief    Set Slave10BitAddress
  * @rmtoll   SADR    ADDR    FL_I2CSMB_WriteSlave10BitAddress
  * @param    I2CSMBx I2CSMB instance
  * @param    address
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteSlave10BitAddress(I2CSMB_Type *I2CSMBx, uint32_t address)
{
    MODIFY_REG(I2CSMBx->SADR, (0x3ffU << 0U), (address << 0U));
}

/**
  * @brief    Get Slave10BitAddress
  * @rmtoll   SADR    ADDR    FL_I2CSMB_ReadSlave10BitAddress
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadSlave10BitAddress(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->SADR, (0x3ffU << 0U)) >> 0U);
}

/**
  * @brief    Get CRC data
  * @rmtoll   CRCDR    DR    FL_I2CSMB_ReadCRCData
  * @param    I2CSMBx I2CSMB instance
  * @param    data This parameter can be one of the following values:
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadCRCData(I2CSMB_Type *I2CSMBx, uint32_t data)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CRCDR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set CRC initial value
  * @rmtoll   CRCLFSR    LFSR    FL_I2CSMB_WriteCRCInitialValue
  * @param    I2CSMBx I2CSMB instance
  * @param    data
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteCRCInitialValue(I2CSMB_Type *I2CSMBx, uint32_t data)
{
    MODIFY_REG(I2CSMBx->CRCLFSR, (0xffU << 0U), (data << 0U));
}

/**
  * @brief    Get CRC initial value
  * @rmtoll   CRCLFSR    LFSR    FL_I2CSMB_ReadCRCInitialValue
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadCRCInitialValue(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CRCLFSR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set CRC Polynominals
  * @rmtoll   CRCPOLY    POLY    FL_I2CSMB_WriteCRCPolynominals
  * @param    I2CSMBx I2CSMB instance
  * @param    data
  * @retval   None
  */
__STATIC_INLINE void FL_I2CSMB_WriteCRCPolynominals(I2CSMB_Type *I2CSMBx, uint32_t data)
{
    MODIFY_REG(I2CSMBx->CRCPOLY, (0xffU << 0U), (data << 0U));
}

/**
  * @brief    Get CRC Polynominals
  * @rmtoll   CRCPOLY    POLY    FL_I2CSMB_ReadCRCPolynominals
  * @param    I2CSMBx I2CSMB instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_I2CSMB_ReadCRCPolynominals(I2CSMB_Type *I2CSMBx)
{
    return (uint32_t)(READ_BIT(I2CSMBx->CRCPOLY, (0xffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup I2C_SMBUS_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
//#warning "PLEASE ANNOUCE THE INIT AND DEINIT FUNCTIONS HERE!!!"

FL_ErrorStatus FL_I2C_SMBUS_DeInit(I2CSMB_Type *I2CSMBx);
FL_ErrorStatus FL_I2C_SMBUS_MasterMode_Init(I2CSMB_Type *I2CSMBx, FL_I2C_SMBUS_MasterMode_InitTypeDef *I2CSMB_InitStruct);
void FL_I2C_SMBUS_MasterMode_StructInit(FL_I2C_SMBUS_MasterMode_InitTypeDef *I2CSMB_InitStruct);
FL_ErrorStatus FL_I2C_SMBUS_SlaveMode_Init(I2CSMB_Type *I2CSMBx, FL_I2C_SMBUS_SlaveMode_InitTypeDef *I2CSMB_InitStruct);
void FL_I2C_SMBUS_SlaveMode_StructInit(FL_I2C_SMBUS_SlaveMode_InitTypeDef *I2CSMB_InitStruct);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_I2C_SMBUS_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.2 @ 2023-09-04*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
