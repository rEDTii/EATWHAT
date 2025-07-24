/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_uart.h
  * @author  FMSH Application Team
  * @brief   Head file of UART FL Module
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
#ifndef __FM33FK5XX_FL_UART_H
#define __FM33FK5XX_FL_UART_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup UART_FL_ES_INIT UART Exported Init structures
  * @{
  */

/**
  * @brief FL UART Init Sturcture definition
  */
typedef struct
{
    /*! 时钟源选择 */
    uint32_t clockSrc;
    /*! 通信波特率 */
    uint32_t baudRate;
    /*! 数据宽度 */
    uint32_t dataWidth;
    /*! 停止位 */
    uint32_t stopBits;
    /*! 奇偶校验位 */
    uint32_t parity;
    /*! 传输反向 */
    uint32_t transferDirection;

} FL_UART_InitTypeDef;

typedef struct
{
    /*! 调制极性默认bit1调制 */
    uint32_t polarity;
    /*! 红外调制占空比 */
    uint32_t modulationDuty;
    /*! 红外调制频率*/
    uint32_t modulationFrequency;

} FL_UART_InfraRed_InitTypeDef;

typedef struct
{
    /*! 卡时钟频率 */
    uint32_t outputClockFreqence;
    /*! 接口发送失败后自动重装使能 */
    FL_FunState txAutoRetry;
    /*! 自动重装次数 */
    uint32_t retryCnt;
    /*!插入BGT使能 */
    FL_FunState blockGuard;
    /*! 帧格式奇偶校验模式 */
    uint32_t parity;
    /*! 帧格式接收Guard时间 */
    uint32_t rxGuardTime;
    /*! 帧格式错误Guard时间 */
    uint32_t errorGuardTime;
    /*! 帧错误信号长度 */
    uint32_t errorSignalWidth;
    /*! 接收校验错误自动回发error signal使能 */
    FL_FunState rxAutoErrorSignal;
    /*! 传输BIT顺序 */
    uint32_t transferOrder;
    /*! 通讯速率 */
    uint32_t baud;
    /*! 额外发送Guard时间 */
    uint32_t extraGuardTime;

} FL_UART_U7816_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup UART_FL_Exported_Constants UART Exported Constants
  * @{
  */
#define    FL_UART_DIRECTION_NONE                                 0x00000000U
#define    FL_UART_DIRECTION_RX                                   UART_CSR_RXEN
#define    FL_UART_DIRECTION_TX                                   UART_CSR_TXEN
#define    FL_UART_DIRECTION_TX_RX                               (UART_CSR_RXEN | UART_CSR_TXEN)

#define    UART_IRCR_IRFLAG_Pos                                   (15U)
#define    UART_IRCR_IRFLAG_Msk                                   (0x1U << UART_IRCR_IRFLAG_Pos)
#define    UART_IRCR_IRFLAG                                       UART_IRCR_IRFLAG_Msk

#define    UART_IRCR_TH_Pos                                       (11U)
#define    UART_IRCR_TH_Msk                                       (0xfU << UART_IRCR_TH_Pos)
#define    UART_IRCR_TH                                           UART_IRCR_TH_Msk

#define    UART_IRCR_TZBRG_Pos                                    (0U)
#define    UART_IRCR_TZBRG_Msk                                    (0x7ffU << UART_IRCR_TZBRG_Pos)
#define    UART_IRCR_TZBRG                                        UART_IRCR_TZBRG_Msk

#define    UART_MCR_HDSEL_Pos                                     (2U)
#define    UART_MCR_HDSEL_Msk                                     (0x1U << UART_MCR_HDSEL_Pos)
#define    UART_MCR_HDSEL                                         UART_MCR_HDSEL_Msk

#define    UART_MCR_LINMD_Pos                                     (1U)
#define    UART_MCR_LINMD_Msk                                     (0x1U << UART_MCR_LINMD_Pos)
#define    UART_MCR_LINMD                                         UART_MCR_LINMD_Msk

#define    UART_MCR_MODE_Pos                                      (0U)
#define    UART_MCR_MODE_Msk                                      (0x1U << UART_MCR_MODE_Pos)
#define    UART_MCR_MODE                                          UART_MCR_MODE_Msk

#define    UART_LINCR_WKUP_LEN_Pos                                (8U)
#define    UART_LINCR_WKUP_LEN_Msk                                (0xffU << UART_LINCR_WKUP_LEN_Pos)
#define    UART_LINCR_WKUP_LEN                                    UART_LINCR_WKUP_LEN_Msk

#define    UART_LINCR_SYNCEN_Pos                                  (7U)
#define    UART_LINCR_SYNCEN_Msk                                  (0x1U << UART_LINCR_SYNCEN_Pos)
#define    UART_LINCR_SYNCEN                                      UART_LINCR_SYNCEN_Msk

#define    UART_LINCR_FTOEN_Pos                                   (6U)
#define    UART_LINCR_FTOEN_Msk                                   (0x1U << UART_LINCR_FTOEN_Pos)
#define    UART_LINCR_FTOEN                                       UART_LINCR_FTOEN_Msk

#define    UART_LINCR_BREM_Pos                                    (4U)
#define    UART_LINCR_BREM_Msk                                    (0x3U << UART_LINCR_BREM_Pos)
#define    UART_LINCR_BREM                                        UART_LINCR_BREM_Msk

#define    UART_LINCR_NDET_EN_Pos                                 (3U)
#define    UART_LINCR_NDET_EN_Msk                                 (0x1U << UART_LINCR_NDET_EN_Pos)
#define    UART_LINCR_NDET_EN                                     UART_LINCR_NDET_EN_Msk

#define    UART_LINCR_WKDET_EN_Pos                                (2U)
#define    UART_LINCR_WKDET_EN_Msk                                (0x1U << UART_LINCR_WKDET_EN_Pos)
#define    UART_LINCR_WKDET_EN                                    UART_LINCR_WKDET_EN_Msk

#define    UART_LINCR_TX_BF_Pos                                   (1U)
#define    UART_LINCR_TX_BF_Msk                                   (0x1U << UART_LINCR_TX_BF_Pos)
#define    UART_LINCR_TX_BF                                       UART_LINCR_TX_BF_Msk

#define    UART_LINCR_TX_WKUP_Pos                                 (0U)
#define    UART_LINCR_TX_WKUP_Msk                                 (0x1U << UART_LINCR_TX_WKUP_Pos)
#define    UART_LINCR_TX_WKUP                                     UART_LINCR_TX_WKUP_Msk

#define    UART_LINBSR_BAUD_SYNC_Pos                              (0U)
#define    UART_LINBSR_BAUD_SYNC_Msk                              (0xfffffU << UART_LINBSR_BAUD_SYNC_Pos)
#define    UART_LINBSR_BAUD_SYNC                                  UART_LINBSR_BAUD_SYNC_Msk

#define    UART_LINFTR_FTO_Pos                                    (0U)
#define    UART_LINFTR_FTO_Msk                                    (0xfffU << UART_LINFTR_FTO_Pos)
#define    UART_LINFTR_FTO                                        UART_LINFTR_FTO_Msk

#define    UART_LINTTR_IBS_Pos                                    (12U)
#define    UART_LINTTR_IBS_Msk                                    (0x3U << UART_LINTTR_IBS_Pos)
#define    UART_LINTTR_IBS                                        UART_LINTTR_IBS_Msk

#define    UART_LINTTR_RSS_Pos                                    (8U)
#define    UART_LINTTR_RSS_Msk                                    (0x7U << UART_LINTTR_RSS_Pos)
#define    UART_LINTTR_RSS                                        UART_LINTTR_RSS_Msk

#define    UART_LINTTR_BDT_Pos                                    (4U)
#define    UART_LINTTR_BDT_Msk                                    (0x3U << UART_LINTTR_BDT_Pos)
#define    UART_LINTTR_BDT                                        UART_LINTTR_BDT_Msk

#define    UART_LINTTR_BLT_Pos                                    (0U)
#define    UART_LINTTR_BLT_Msk                                    (0xfU << UART_LINTTR_BLT_Pos)
#define    UART_LINTTR_BLT                                        UART_LINTTR_BLT_Msk

#define    UART_LINPSR_PRE_SYNC_Pos                               (0U)
#define    UART_LINPSR_PRE_SYNC_Msk                               (0xfffffU << UART_LINPSR_PRE_SYNC_Pos)
#define    UART_LINPSR_PRE_SYNC                                   UART_LINPSR_PRE_SYNC_Msk

#define    UART_LINBKR_BREAK_LEN_Pos                              (0U)
#define    UART_LINBKR_BREAK_LEN_Msk                              (0xfffffffU << UART_LINBKR_BREAK_LEN_Pos)
#define    UART_LINBKR_BREAK_LEN                                  UART_LINBKR_BREAK_LEN_Msk

#define    UART_LINSCCR_LINSTC_Pos                                (0U)
#define    UART_LINSCCR_LINSTC_Msk                                (0x3U << UART_LINSCCR_LINSTC_Pos)
#define    UART_LINSCCR_LINSTC                                    UART_LINSCCR_LINSTC_Msk

#define    UART_CSR_BUSY_Pos                                      (24U)
#define    UART_CSR_BUSY_Msk                                      (0x1U << UART_CSR_BUSY_Pos)
#define    UART_CSR_BUSY                                          UART_CSR_BUSY_Msk

#define    UART_CSR_RTSEN_Pos                                    (23U)
#define    UART_CSR_RTSEN_Msk                                    (0x1U << UART_CSR_RTSEN_Pos)
#define    UART_CSR_RTSEN                                        UART_CSR_RTSEN_Msk

#define    UART_CSR_CTSEN_Pos                                    (22U)
#define    UART_CSR_CTSEN_Msk                                    (0x1U << UART_CSR_CTSEN_Pos)
#define    UART_CSR_CTSEN                                        UART_CSR_CTSEN_Msk

#define    UART_CSR_TXIREN_Pos                                    (17U)
#define    UART_CSR_TXIREN_Msk                                    (0x1U << UART_CSR_TXIREN_Pos)
#define    UART_CSR_TXIREN                                        UART_CSR_TXIREN_Msk

#define    UART_CSR_RXTOEN_Pos                                    (16U)
#define    UART_CSR_RXTOEN_Msk                                    (0x1U << UART_CSR_RXTOEN_Pos)
#define    UART_CSR_RXTOEN                                        UART_CSR_RXTOEN_Msk

#define    UART_CSR_RESYNCEN_Pos                                  (15U)
#define    UART_CSR_RESYNCEN_Msk                                  (0x1U << UART_CSR_RESYNCEN_Pos)
#define    UART_CSR_RESYNCEN                                      UART_CSR_RESYNCEN_Msk

#define    UART_CSR_CKOEN_Pos                                     (14U)
#define    UART_CSR_CKOEN_Msk                                     (0x1U << UART_CSR_CKOEN_Pos)
#define    UART_CSR_CKOEN                                         UART_CSR_RESYNCEN_Msk

#define    UART_CSR_OVSM_Pos                                      (13U)
#define    UART_CSR_OVSM_Msk                                      (0x1U << UART_CSR_OVSM_Pos)
#define    UART_CSR_OVSM                                          UART_CSR_OVSM_Msk

#define    UART_CSR_IOSWAP_Pos                                    (12U)
#define    UART_CSR_IOSWAP_Msk                                    (0x1U << UART_CSR_IOSWAP_Pos)
#define    UART_CSR_IOSWAP                                        UART_CSR_IOSWAP_Msk

#define    UART_CSR_NEWUP_Pos                                     (11U)
#define    UART_CSR_NEWUP_Msk                                     (0x1U << UART_CSR_NEWUP_Pos)
#define    UART_CSR_NEWUP                                         UART_CSR_NEWUP_Msk

#define    UART_CSR_DMATXIFCFG_Pos                                (10U)
#define    UART_CSR_DMATXIFCFG_Msk                                (0x1U << UART_CSR_DMATXIFCFG_Pos)
#define    UART_CSR_DMATXIFCFG                                    UART_CSR_DMATXIFCFG_Msk

#define    UART_CSR_BITORD_Pos                                    (9U)
#define    UART_CSR_BITORD_Msk                                    (0x1U << UART_CSR_BITORD_Pos)
#define    UART_CSR_BITORD                                        UART_CSR_BITORD_Msk

#define    UART_CSR_STOPCFG_Pos                                   (8U)
#define    UART_CSR_STOPCFG_Msk                                   (0x1U << UART_CSR_STOPCFG_Pos)
#define    UART_CSR_STOPCFG                                       UART_CSR_STOPCFG_Msk

#define    UART_CSR_PDSEL_Pos                                     (6U)
#define    UART_CSR_PDSEL_Msk                                     (0x3U << UART_CSR_PDSEL_Pos)
#define    UART_CSR_PDSEL                                         UART_CSR_PDSEL_Msk

#define    UART_CSR_PARITY_Pos                                    (4U)
#define    UART_CSR_PARITY_Msk                                    (0x3U << UART_CSR_PARITY_Pos)
#define    UART_CSR_PARITY                                        UART_CSR_PARITY_Msk

#define    UART_CSR_RXPOL_Pos                                     (3U)
#define    UART_CSR_RXPOL_Msk                                     (0x1U << UART_CSR_RXPOL_Pos)
#define    UART_CSR_RXPOL                                         UART_CSR_RXPOL_Msk

#define    UART_CSR_TXPOL_Pos                                     (2U)
#define    UART_CSR_TXPOL_Msk                                     (0x1U << UART_CSR_TXPOL_Pos)
#define    UART_CSR_TXPOL                                         UART_CSR_TXPOL_Msk

#define    UART_CSR_RXEN_Pos                                      (1U)
#define    UART_CSR_RXEN_Msk                                      (0x1U << UART_CSR_RXEN_Pos)
#define    UART_CSR_RXEN                                          UART_CSR_RXEN_Msk

#define    UART_CSR_TXEN_Pos                                      (0U)
#define    UART_CSR_TXEN_Msk                                      (0x1U << UART_CSR_TXEN_Pos)
#define    UART_CSR_TXEN                                          UART_CSR_TXEN_Msk

#define    UART_IER_TOERIE_Pos                                    (31U)
#define    UART_IER_TOERIE_Msk                                    (0x1U << UART_IER_TOERIE_Pos)
#define    UART_IER_TOERIE                                        UART_IER_TOERIE_Msk

#define    UART_IER_SERIE_Pos                                     (30U)
#define    UART_IER_SERIE_Msk                                     (0x1U << UART_IER_SERIE_Pos)
#define    UART_IER_SERIE                                         UART_IER_SERIE_Msk

#define    UART_IER_BERIE_Pos                                     (28U)
#define    UART_IER_BERIE_Msk                                     (0x1U << UART_IER_BERIE_Pos)
#define    UART_IER_BERIE                                         UART_IER_BERIE_Msk

#define    UART_IER_NFIE_Pos                                      (27U)
#define    UART_IER_NFIE_Msk                                      (0x1U << UART_IER_NFIE_Pos)
#define    UART_IER_NFIE                                          UART_IER_NFIE_Msk

#define    UART_IER_LINSYNCIE_Pos                                 (26U)
#define    UART_IER_LINSYNCIE_Msk                                 (0x1U << UART_IER_LINSYNCIE_Pos)
#define    UART_IER_LINSYNCIE                                     UART_IER_LINSYNCIE_Msk

#define    UART_IER_LINBIE_Pos                                    (25U)
#define    UART_IER_LINBIE_Msk                                    (0x1U << UART_IER_LINBIE_Pos)
#define    UART_IER_LINBIE                                        UART_IER_LINBIE_Msk

#define    UART_IER_LINWKIE_Pos                                   (24U)
#define    UART_IER_LINWKIE_Msk                                   (0x1U << UART_IER_LINWKIE_Pos)
#define    UART_IER_LINWKIE                                       UART_IER_LINWKIE_Msk

#define    UART_IER_LINWKTFIE_Pos                                 (23U)
#define    UART_IER_LINWKTFIE_Msk                                 (0x1U << UART_IER_LINWKTFIE_Pos)
#define    UART_IER_LINWKTFIE                                     UART_IER_LINWKTFIE_Msk

#define    UART_IER_LINBEFIE_Pos                                  (22U)
#define    UART_IER_LINBEFIE_Msk                                  (0x1U << UART_IER_LINBEFIE_Pos)
#define    UART_IER_LINBEFIE                                      UART_IER_LINBEFIE_Msk

#define    UART_IER_LINBERIE_Pos                                  (21U)
#define    UART_IER_LINBERIE_Msk                                  (0x1U << UART_IER_LINBERIE_Pos)
#define    UART_IER_LINBERIE                                      UART_IER_LINBERIE_Msk

#define    UART_IER_PERRIE_Pos                                    (18U)
#define    UART_IER_PERRIE_Msk                                    (0x1U << UART_IER_PERRIE_Pos)
#define    UART_IER_PERRIE                                        UART_IER_PERRIE_Msk

#define    UART_IER_FERRIE_Pos                                    (17U)
#define    UART_IER_FERRIE_Msk                                    (0x1U << UART_IER_FERRIE_Pos)
#define    UART_IER_FERRIE                                        UART_IER_FERRIE_Msk

#define    UART_IER_OERRIE_Pos                                    (16U)
#define    UART_IER_OERRIE_Msk                                    (0x1U << UART_IER_OERRIE_Pos)
#define    UART_IER_OERRIE                                        UART_IER_OERRIE_Msk

#define    UART_IER_CTSIE_Pos                                     (15U)
#define    UART_IER_CTSIE_Msk                                     (0x1U << UART_IER_CTSIE_Pos)
#define    UART_IER_CTSIE                                         UART_IER_CTSIE_Msk

#define    UART_IER_RXTOIE_Pos                                    (11U)
#define    UART_IER_RXTOIE_Msk                                    (0x1U << UART_IER_RXTOIE_Pos)
#define    UART_IER_RXTOIE                                        UART_IER_RXTOIE_Msk

#define    UART_IER_RXERRIE_Pos                                   (10U)
#define    UART_IER_RXERRIE_Msk                                   (0x1U << UART_IER_RXERRIE_Pos)
#define    UART_IER_RXERRIE                                       UART_IER_RXERRIE_Msk

#define    UART_IER_RXBFIE_Pos                                    (8U)
#define    UART_IER_RXBFIE_Msk                                    (0x1U << UART_IER_RXBFIE_Pos)
#define    UART_IER_RXBFIE                                        UART_IER_RXBFIE_Msk

#define    UART_IER_NEWUPIE_Pos                                   (7U)
#define    UART_IER_NEWUPIE_Msk                                   (0x1U << UART_IER_NEWUPIE_Pos)
#define    UART_IER_NEWUPIE                                       UART_IER_NEWUPIE_Msk

#define    UART_IER_TXBEIE_Pos                                    (1U)
#define    UART_IER_TXBEIE_Msk                                    (0x1U << UART_IER_TXBEIE_Pos)
#define    UART_IER_TXBEIE                                        UART_IER_TXBEIE_Msk

#define    UART_IER_TXSEIE_Pos                                    (0U)
#define    UART_IER_TXSEIE_Msk                                    (0x1U << UART_IER_TXSEIE_Pos)
#define    UART_IER_TXSEIE                                        UART_IER_TXSEIE_Msk

#define    UART_ISR_TOER_Pos                                      (31U)
#define    UART_ISR_TOER_Msk                                      (0x1U << UART_ISR_TOER_Pos)
#define    UART_ISR_TOER                                          UART_ISR_TOER_Msk

#define    UART_ISR_SER_Pos                                       (30U)
#define    UART_ISR_SER_Msk                                       (0x1U << UART_ISR_SER_Pos)
#define    UART_ISR_SER                                           UART_ISR_SER_Msk

#define    UART_ISR_BERIF_Pos                                     (28U)
#define    UART_ISR_BERIF_Msk                                     (0x1U << UART_ISR_BERIF_Pos)
#define    UART_ISR_BERIF                                         UART_ISR_BERIF_Msk

#define    UART_ISR_NF_Pos                                        (27U)
#define    UART_ISR_NF_Msk                                        (0x1U << UART_ISR_NF_Pos)
#define    UART_ISR_NF                                            UART_ISR_NF_Msk

#define    UART_ISR_LINSYNCF_Pos                                  (26U)
#define    UART_ISR_LINSYNCF_Msk                                  (0x1U << UART_ISR_LINSYNCF_Pos)
#define    UART_ISR_LINSYNCF                                      UART_ISR_LINSYNCF_Msk

#define    UART_ISR_LINBF_Pos                                     (25U)
#define    UART_ISR_LINBF_Msk                                     (0x1U << UART_ISR_LINBF_Pos)
#define    UART_ISR_LINBF                                         UART_ISR_LINBF_Msk

#define    UART_ISR_LINWKDF_Pos                                   (24U)
#define    UART_ISR_LINWKDF_Msk                                   (0x1U << UART_ISR_LINWKDF_Pos)
#define    UART_ISR_LINWKDF                                       UART_ISR_LINWKDF_Msk

#define    UART_ISR_LINWKTF_Pos                                   (23U)
#define    UART_ISR_LINWKTF_Msk                                   (0x1U << UART_ISR_LINWKTF_Pos)
#define    UART_ISR_LINWKTF                                       UART_ISR_LINWKTF_Msk

#define    UART_ISR_LINBEF_Pos                                    (22U)
#define    UART_ISR_LINBEF_Msk                                    (0x1U << UART_ISR_LINBEF_Pos)
#define    UART_ISR_LINBEF                                        UART_ISR_LINBEF_Msk

#define    UART_ISR_LINBER_Pos                                    (21U)
#define    UART_ISR_LINBER_Msk                                    (0x1U << UART_ISR_LINBER_Pos)
#define    UART_ISR_LINBER                                        UART_ISR_LINBER_Msk

#define    UART_ISR_PERR_Pos                                      (18U)
#define    UART_ISR_PERR_Msk                                      (0x1U << UART_ISR_PERR_Pos)
#define    UART_ISR_PERR                                          UART_ISR_PERR_Msk

#define    UART_ISR_FERR_Pos                                      (17U)
#define    UART_ISR_FERR_Msk                                      (0x1U << UART_ISR_FERR_Pos)
#define    UART_ISR_FERR                                          UART_ISR_FERR_Msk

#define    UART_ISR_OERR_Pos                                      (16U)
#define    UART_ISR_OERR_Msk                                      (0x1U << UART_ISR_OERR_Pos)
#define    UART_ISR_OERR                                          UART_ISR_OERR_Msk

#define    UART_ISR_CTSIF_Pos                                     (15U)
#define    UART_ISR_CTSIF_Msk                                     (0x1U << UART_ISR_CTSIF_Pos)
#define    UART_ISR_CTSIF                                         UART_ISR_CTSIF_Msk

#define    UART_ISR_RXTO_Pos                                      (11U)
#define    UART_ISR_RXTO_Msk                                      (0x1U << UART_ISR_RXTO_Pos)
#define    UART_ISR_RXTO                                          UART_ISR_RXTO_Msk

#define    UART_ISR_RXBF_Pos                                      (8U)
#define    UART_ISR_RXBF_Msk                                      (0x1U << UART_ISR_RXBF_Pos)
#define    UART_ISR_RXBF                                          UART_ISR_RXBF_Msk

#define    UART_ISR_NEWKF_Pos                                     (7U)
#define    UART_ISR_NEWKF_Msk                                     (0x1U << UART_ISR_NEWKF_Pos)
#define    UART_ISR_NEWKF                                         UART_ISR_NEWKF_Msk

#define    UART_ISR_TXOERR_Pos                                    (2U)
#define    UART_ISR_TXOERR_Msk                                    (0x1U << UART_ISR_TXOERR_Pos)
#define    UART_ISR_TXOERR                                        UART_ISR_TXOERR_Msk

#define    UART_ISR_TXBE_Pos                                      (1U)
#define    UART_ISR_TXBE_Msk                                      (0x1U << UART_ISR_TXBE_Pos)
#define    UART_ISR_TXBE                                          UART_ISR_TXBE_Msk

#define    UART_ISR_TXSE_Pos                                      (0U)
#define    UART_ISR_TXSE_Msk                                      (0x1U << UART_ISR_TXSE_Pos)
#define    UART_ISR_TXSE                                          UART_ISR_TXSE_Msk

#define    UART_TODR_TXDLY_LEN_Pos                                (8U)
#define    UART_TODR_TXDLY_LEN_Msk                                (0xffU << UART_TODR_TXDLY_LEN_Pos)
#define    UART_TODR_TXDLY_LEN                                    UART_TODR_TXDLY_LEN_Msk

#define    UART_TODR_RXTO_LEN_Pos                                 (0U)
#define    UART_TODR_RXTO_LEN_Msk                                 (0xffU << UART_TODR_RXTO_LEN_Pos)
#define    UART_TODR_RXTO_LEN                                     UART_TODR_RXTO_LEN_Msk

#define    UART_FFCR_SFREN_Pos                                    (11U)
#define    UART_FFCR_SFREN_Msk                                    (0x3U << UART_FFCR_SFREN_Pos)
#define    UART_FFCR_SFREN                                         UART_FFCR_SFREN_Msk

#define    UART_FFCR_ERSW_Pos                                      (9U)
#define    UART_FFCR_ERSW_Msk                                      (0x3U << UART_FFCR_ERSW_Pos)
#define    UART_FFCR_ERSW                                          UART_FFCR_ERSW_Msk

#define    UART_FFCR_ERSGD_Pos                                     (8U)
#define    UART_FFCR_ERSGD_Msk                                     (0x1U << UART_FFCR_ERSGD_Pos)
#define    UART_FFCR_ERSGD                                         UART_FFCR_ERSGD_Msk

#define    UART_FFCR_BGTEN_Pos                                     (7U)
#define    UART_FFCR_BGTEN_Msk                                     (0x1U << UART_FFCR_BGTEN_Pos)
#define    UART_FFCR_BGTEN                                         UART_FFCR_BGTEN_Msk

#define    UART_FFCR_REP_T_Pos                                     (6U)
#define    UART_FFCR_REP_T_Msk                                     (0x1U << UART_FFCR_REP_T_Pos)
#define    UART_FFCR_REP_T                                         UART_FFCR_REP_T_Msk

#define    UART_FFCR_PAR_Pos                                       (4U)
#define    UART_FFCR_PAR_Msk                                       (0x3U << UART_FFCR_PAR_Pos)
#define    UART_FFCR_PAR                                           UART_FFCR_PAR_Msk

#define    UART_FFCR_RFREN_Pos                                     (3U)
#define    UART_FFCR_RFREN_Msk                                     (0x1U << UART_FFCR_RFREN_Pos)
#define    UART_FFCR_RFREN                                         UART_FFCR_RFREN_Msk

#define    UART_FFCR_TREPEN_Pos                                    (2U)
#define    UART_FFCR_TREPEN_Msk                                    (0x1U << UART_FFCR_TREPEN_Pos)
#define    UART_FFCR_TREPEN                                        UART_FFCR_TREPEN_Msk

#define    UART_FFCR_RREPEN_Pos                                    (1U)
#define    UART_FFCR_RREPEN_Msk                                    (0x1U << UART_FFCR_RREPEN_Pos)
#define    UART_FFCR_RREPEN                                        UART_FFCR_RREPEN_Msk

#define    UART_FFCR_DICONV_Pos                                    (0U)
#define    UART_FFCR_DICONV_Msk                                    (0x1U << UART_FFCR_DICONV_Pos)
#define    UART_FFCR_DICONV                                        UART_FFCR_DICONV_Msk

#define    UART_SCIER_TXSEIE_Pos                                  (3U)
#define    UART_SCIER_TXSEIE_Msk                                  (0x1U << UART_SCIER_TXSEIE_Pos)
#define    UART_SCIER_TXSEIE                                      UART_SCIER_TXSEIE_Msk

#define    UART_SCIER_RXIE_Pos                                    (2U)
#define    UART_SCIER_RXIE_Msk                                    (0x1U << UART_SCIER_RXIE_Pos)
#define    UART_SCIER_RXIE                                        UART_SCIER_RXIE_Msk

#define    UART_SCIER_TXIE_Pos                                    (1U)
#define    UART_SCIER_TXIE_Msk                                    (0x1U << UART_SCIER_TXIE_Pos)
#define    UART_SCIER_TXIE                                        UART_SCIER_TXIE_Msk

#define    UART_SCIER_LSIE_Pos                                    (0U)
#define    UART_SCIER_LSIE_Msk                                    (0x1U << UART_SCIER_LSIE_Pos)
#define    UART_SCIER_LSIE                                        UART_SCIER_LSIE_Msk

#define    UART_SCISR_WAIT_RPT_Pos                                (18U)
#define    UART_SCISR_WAIT_RPT_Msk                                (0x1U << UART_SCISR_WAIT_RPT_Pos)
#define    UART_SCISR_WAIT_RPT                                    UART_SCISR_WAIT_RPT_Msk

#define    UART_SCISR_TXBUSY_Pos                                  (17U)
#define    UART_SCISR_TXBUSY_Msk                                  (0x1U << UART_SCISR_TXBUSY_Pos)
#define    UART_SCISR_TXBUSY                                      UART_SCISR_TXBUSY_Msk

#define    UART_SCISR_RXBUSY_Pos                                  (16U)
#define    UART_SCISR_RXBUSY_Msk                                  (0x1U << UART_SCISR_RXBUSY_Pos)
#define    UART_SCISR_RXBUSY                                      UART_SCISR_RXBUSY_Msk

#define    UART_SCISR_TPARERR_Pos                                 (11U)
#define    UART_SCISR_TPARERR_Msk                                 (0x1U << UART_SCISR_TPARERR_Pos)
#define    UART_SCISR_TPARERR                                     UART_SCISR_TPARERR_Msk

#define    UART_SCISR_RPARERR_Pos                                 (10U)
#define    UART_SCISR_RPARERR_Msk                                 (0x1U << UART_SCISR_RPARERR_Pos)
#define    UART_SCISR_RPARERR                                     UART_SCISR_RPARERR_Msk

#define    UART_SCISR_FRERR_Pos                                   (9U)
#define    UART_SCISR_FRERR_Msk                                   (0x1U << UART_SCISR_FRERR_Pos)
#define    UART_SCISR_FRERR                                       UART_SCISR_FRERR_Msk

#define    UART_SCISR_OVERR_Pos                                   (8U)
#define    UART_SCISR_OVERR_Msk                                   (0x1U << UART_SCISR_OVERR_Pos)
#define    UART_SCISR_OVERR                                       UART_SCISR_OVERR_Msk

#define    UART_SCISR_TXSE_Pos                                    (3U)
#define    UART_SCISR_TXSE_Msk                                    (0x1U << UART_SCISR_TXSE_Pos)
#define    UART_SCISR_TXSE                                        UART_SCISR_TXSE_Msk

#define    UART_SCISR_RXIF_Pos                                    (2U)
#define    UART_SCISR_RXIF_Msk                                    (0x1U << UART_SCISR_RXIF_Pos)
#define    UART_SCISR_RXIF                                        UART_SCISR_RXIF_Msk

#define    UART_SCISR_TXIF_Pos                                    (1U)
#define    UART_SCISR_TXIF_Msk                                    (0x1U << UART_SCISR_TXIF_Pos)
#define    UART_SCISR_TXIF                                        UART_SCISR_TXIF_Msk

#define    UART_SCISR_ERRIF_Pos                                   (0U)
#define    UART_SCISR_ERRIF_Msk                                   (0x1U << UART_SCISR_ERRIF_Pos)
#define    UART_SCISR_ERRIF                                       UART_SCISR_ERRIF_Msk

#define    FL_UART_INFRARED_POLARITY_NORMAL                       (0x0U << UART_IRCR_IRFLAG_Pos)
#define    FL_UART_INFRARED_POLARITY_INVERT                       (0x1U << UART_IRCR_IRFLAG_Pos)

#define    FL_UART_UART_MODESEL_FULL_DUPLEX                       (0x0U << UART_MCR_HDSEL_Pos)
#define    FL_UART_UART_MODESEL_HALF_DUPLEX                       (0x1U << UART_MCR_HDSEL_Pos)

#define    FL_UART_LIN_MODESEL_MASTER                             (0x0U << UART_MCR_LINMD_Pos)
#define    FL_UART_LIN_MODESEL_SLAVE                              (0x1U << UART_MCR_LINMD_Pos)

#define    FL_UART_MODESEL_UART                                   (0x0U << UART_MCR_MODE_Pos)
#define    FL_UART_MODESEL_NON_UART                               (0x1U << UART_MCR_MODE_Pos)

#define    FL_UART_BER_MODE_NONE                                  (0x0U << UART_LINCR_BREM_Pos)
#define    FL_UART_BER_MODE_EN_BIT9                               (0x1U << UART_LINCR_BREM_Pos)
#define    FL_UART_BER_MODE_EN_BIT13                              (0x2U << UART_LINCR_BREM_Pos)

#define    FL_UART_SELFTEST_MODE_NONE                             (0x0U << UART_LINSCCR_LINSTC_Pos)
#define    FL_UART_SELFTEST_MODE_LIN01                            (0x1U << UART_LINSCCR_LINSTC_Pos)
#define    FL_UART_SELFTEST_MODE_LIN02                            (0x2U << UART_LINSCCR_LINSTC_Pos)
#define    FL_UART_SELFTEST_MODE_LIN03                            (0x3U << UART_LINSCCR_LINSTC_Pos)

#define    FL_UART_OVERSAMPLING_16                                (0x0U << UART_CSR_OVSM_Pos)
#define    FL_UART_OVERSAMPLING_8                                 (0x1U << UART_CSR_OVSM_Pos)

#define    FL_UART_TXIF_MODE_ALWAYS                               (0x0U << UART_CSR_DMATXIFCFG_Pos)
#define    FL_UART_TXIF_MODE_AFTER_DMA                            (0x1U << UART_CSR_DMATXIFCFG_Pos)

#define    FL_UART_BIT_ORDER_LSB_FIRST                            (0x0U << UART_CSR_BITORD_Pos)
#define    FL_UART_BIT_ORDER_MSB_FIRST                            (0x1U << UART_CSR_BITORD_Pos)

#define    FL_UART_STOP_BIT_WIDTH_1B                              (0x0U << UART_CSR_STOPCFG_Pos)
#define    FL_UART_STOP_BIT_WIDTH_2B                              (0x1U << UART_CSR_STOPCFG_Pos)

#define    FL_UART_DATA_WIDTH_7B                                  (0x0U << UART_CSR_PDSEL_Pos)
#define    FL_UART_DATA_WIDTH_8B                                  (0x1U << UART_CSR_PDSEL_Pos)
#define    FL_UART_DATA_WIDTH_9B                                  (0x2U << UART_CSR_PDSEL_Pos)
#define    FL_UART_DATA_WIDTH_6B                                  (0x3U << UART_CSR_PDSEL_Pos)

#define    FL_UART_PARITY_NONE                                    (0x0U << UART_CSR_PARITY_Pos)
#define    FL_UART_PARITY_EVEN                                    (0x1U << UART_CSR_PARITY_Pos)
#define    FL_UART_PARITY_ODD                                     (0x2U << UART_CSR_PARITY_Pos)

#define    FL_UART_RX_POLARITY_NORMAL                             (0x0U << UART_CSR_RXPOL_Pos)
#define    FL_UART_RX_POLARITY_INVERT                             (0x1U << UART_CSR_RXPOL_Pos)

#define    FL_UART_TX_POLARITY_NORMAL                             (0x0U << UART_CSR_TXPOL_Pos)
#define    FL_UART_TX_POLARITY_INVERT                             (0x1U << UART_CSR_TXPOL_Pos)

#define    FL_UART_U7816_ERROR_SIGNAL_WIDTH_2ETU                  (0x1U << UART_FFCR_ERSW_Pos)
#define    FL_UART_U7816_ERROR_SIGNAL_WIDTH_1P5ETU                (0x2U << UART_FFCR_ERSW_Pos)
#define    FL_UART_U7816_ERROR_SIGNAL_WIDTH_1ETU                  (0x3U << UART_FFCR_ERSW_Pos)

#define    FL_UART_U7816_ERROR_GUARD_TIME_2ETU                    (0x0U << UART_FFCR_ERSGD_Pos)
#define    FL_UART_U7816_ERROR_GUARD_TIME_1ETU                    (0x1U << UART_FFCR_ERSGD_Pos)

#define    FL_UART_U7816_RETRY_COUNT_1                            (0x0U << UART_FFCR_REP_T_Pos)
#define    FL_UART_U7816_RETRY_COUNT_3                            (0x1U << UART_FFCR_REP_T_Pos)

#define    FL_UART_U7816_PARITY_SEL_EVEN                          (0x0U << UART_FFCR_PAR_Pos)
#define    FL_UART_U7816_PARITY_SEL_ODD                           (0x1U << UART_FFCR_PAR_Pos)
#define    FL_UART_U7816_PARITY_SEL_ALWAYS_1                      (0x2U << UART_FFCR_PAR_Pos)
#define    FL_UART_U7816_PARITY_SEL_NONE                          (0x3U << UART_FFCR_PAR_Pos)

#define    FL_UART_U7816_TX_GUARD_TIME_2ETU                       (0x0U << UART_FFCR_SFREN_Pos)
#define    FL_UART_U7816_TX_GUARD_TIME_3ETU                       (0x1U << UART_FFCR_SFREN_Pos)

#define    FL_UART_U7816_RX_GUARD_TIME_2ETU                       (0x0U << UART_FFCR_RFREN_Pos)
#define    FL_UART_U7816_RX_GUARD_TIME_1ETU                       (0x1U << UART_FFCR_RFREN_Pos)

#define    FL_UART_U7816_BIT_ORDER_LSB_FIRST                      (0x0U << UART_FFCR_DICONV_Pos)
#define    FL_UART_U7816_BIT_ORDER_MSB_FIRST                      (0x1U << UART_FFCR_DICONV_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup UART_FL_Exported_Functions UART Exported Functions
  * @{
  */

/**
  * @brief    Set Infrared Polarity
  * @rmtoll   IRCR    IRFLAG    FL_UART_SetIRPolarity
  * @param    UART_Common UART_Common instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_UART_INFRARED_POLARITY_NORMAL
  *           @arg @ref FL_UART_INFRARED_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetIRPolarity(UART_COMMON_Type *UART_Common, uint32_t polarity)
{
    MODIFY_REG(UART_Common->IRCR, UART_IRCR_IRFLAG_Msk, polarity);
}

/**
  * @brief    Get Infrared Polarity
  * @rmtoll   IRCR    IRFLAG    FL_UART_GetIRPolarity
  * @param    UART_Common UART_Common instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_INFRARED_POLARITY_NORMAL
  *           @arg @ref FL_UART_INFRARED_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_UART_GetIRPolarity(UART_COMMON_Type *UART_Common)
{
    return (uint32_t)(READ_BIT(UART_Common->IRCR, UART_IRCR_IRFLAG_Msk));
}

/**
  * @brief    Set Infrared Modulation Duty
  * @rmtoll   IRCR    TH    FL_UART_WriteIRModulationDuty
  * @param    UART_Common UART_Common instance
  * @param    duty
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteIRModulationDuty(UART_COMMON_Type *UART_Common, uint32_t duty)
{
    MODIFY_REG(UART_Common->IRCR, (0xfU << 11U), (duty << 11U));
}

/**
  * @brief    Get Infrared Modulation Duty
  * @rmtoll   IRCR    TH    FL_UART_ReadIRModulationDuty
  * @param    UART_Common UART_Common instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadIRModulationDuty(UART_COMMON_Type *UART_Common)
{
    return (uint32_t)(READ_BIT(UART_Common->IRCR, (0xfU << 11U)) >> 11U);
}

/**
  * @brief    Set Infrared Modulation Frequency
  * @rmtoll   IRCR    TZBRG    FL_UART_WriteIRModulationFrequency
  * @param    UART_Common UART_Common instance
  * @param    freq
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteIRModulationFrequency(UART_COMMON_Type *UART_Common, uint32_t freq)
{
    MODIFY_REG(UART_Common->IRCR, (0x7ffU << 0U), (freq << 0U));
}

/**
  * @brief    Get Infrared Modulation Frequency
  * @rmtoll   IRCR    TZBRG    FL_UART_ReadIRModulationFrequency
  * @param    UART_Common UART_Common instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadIRModulationFrequency(UART_COMMON_Type *UART_Common)
{
    return (uint32_t)(READ_BIT(UART_Common->IRCR, (0x7ffU << 0U)) >> 0U);
}

/**
  * @brief    Set UART Mode
  * @rmtoll   MCR    HDSEL    FL_UART_SetUARTMode
  * @param    UARTx UART instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_UART_MODESEL_FULL_DUPLEX
  *           @arg @ref FL_UART_UART_MODESEL_HALF_DUPLEX
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetUARTMode(UART_Type *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->MCR, UART_MCR_HDSEL_Msk, mode);
}

/**
  * @brief    Get UART Mode
  * @rmtoll   MCR    HDSEL    FL_UART_GetUARTMode
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_UART_MODESEL_FULL_DUPLEX
  *           @arg @ref FL_UART_UART_MODESEL_HALF_DUPLEX
  */
__STATIC_INLINE uint32_t FL_UART_GetUARTMode(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCR, UART_MCR_HDSEL_Msk));
}

/**
  * @brief    Set LIN Mode
  * @rmtoll   MCR    LINMD    FL_UART_SetLINMode
  * @param    UARTx UART instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_LIN_MODESEL_MASTER
  *           @arg @ref FL_UART_LIN_MODESEL_SLAVE
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetLINMode(UART_Type *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->MCR, UART_MCR_LINMD_Msk, mode);
}

/**
  * @brief    Get LIN Mode
  * @rmtoll   MCR    LINMD    FL_UART_GetLINMode
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_LIN_MODESEL_MASTER
  *           @arg @ref FL_UART_LIN_MODESEL_SLAVE
  */
__STATIC_INLINE uint32_t FL_UART_GetLINMode(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCR, UART_MCR_LINMD_Msk));
}

/**
  * @brief    Select Module Mode
  * @rmtoll   MCR    MODE    FL_UART_SetMode
  * @param    UARTx UART instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_MODESEL_UART
  *           @arg @ref FL_UART_MODESEL_NON_UART
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetMode(UART_Type *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->MCR, UART_MCR_MODE_Msk, mode);
}

/**
  * @brief    Get Module Mode
  * @rmtoll   MCR    MODE    FL_UART_GetMode
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_MODESEL_UART
  *           @arg @ref FL_UART_MODESEL_NON_UART
  */
__STATIC_INLINE uint32_t FL_UART_GetMode(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->MCR, UART_MCR_MODE_Msk));
}

/**
  * @brief    Set WKUP_LEN
  * @rmtoll   LINCR    WKUP_LEN    FL_UART_SetLINWkupLength
  * @param    UARTx UART instance
  * @param    Length
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetLINWkupLength(UART_Type *UARTx, uint32_t Length)
{
    MODIFY_REG(UARTx->LINCR, (0xffU << 8U), (Length << 8U));
}

/**
  * @brief    Get WKUP_LEN
  * @rmtoll   LINCR    WKUP_LEN    FL_UART_GetLINWkupLength
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_GetLINWkupLength(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINCR, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Enable LIN Slave Sync Reception
  * @rmtoll   LINCR    SYNCEN    FL_UART_EnableLINSlaveSyncReception
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableLINSlaveSyncReception(UART_Type *UARTx)
{
    SET_BIT(UARTx->LINCR, UART_LINCR_SYNCEN_Msk);
}

/**
  * @brief    Disable LIN Slave Sync Reception
  * @rmtoll   LINCR    SYNCEN    FL_UART_DisableLINSlaveSyncReception
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableLINSlaveSyncReception(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->LINCR, UART_LINCR_SYNCEN_Msk);
}

/**
  * @brief    Get LIN Slave Sync Reception Enable Status
  * @rmtoll   LINCR    SYNCEN    FL_UART_IsEnabledLINSlaveSyncReception
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledLINSlaveSyncReception(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINCR, UART_LINCR_SYNCEN_Msk) == UART_LINCR_SYNCEN_Msk);
}

/**
  * @brief    Enable LIN Frame Timeout Detect
  * @rmtoll   LINCR    FTOEN    FL_UART_EnableLINFrameTimeoutDetect
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableLINFrameTimeoutDetect(UART_Type *UARTx)
{
    SET_BIT(UARTx->LINCR, UART_LINCR_FTOEN_Msk);
}

/**
  * @brief    Disable LIN Frame Timeout Detect
  * @rmtoll   LINCR    FTOEN    FL_UART_DisableLINFrameTimeoutDetect
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableLINFrameTimeoutDetect(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->LINCR, UART_LINCR_FTOEN_Msk);
}

/**
  * @brief    Get LIN Frame Timeout Detect Enable Status
  * @rmtoll   LINCR    FTOEN    FL_UART_IsEnabledLINFrameTimeoutDetect
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledLINFrameTimeoutDetect(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINCR, UART_LINCR_FTOEN_Msk) == UART_LINCR_FTOEN_Msk);
}

/**
  * @brief    Set LIN Bus Collision Detection
  * @rmtoll   LINCR    BREM    FL_UART_SetLINBusErrorMode
  * @param    UARTx UART instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_BER_MODE_NONE
  *           @arg @ref FL_UART_BER_MODE_EN_BIT9
  *           @arg @ref FL_UART_BER_MODE_EN_BIT13
  *           @arg @ref FL_UART_BER_MODE_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetLINBusErrorMode(UART_Type *UARTx, uint32_t Mode)
{
    MODIFY_REG(UARTx->LINCR, UART_LINCR_BREM_Msk, Mode);
}

/**
  * @brief    Get LIN Bus Collision Detection
  * @rmtoll   LINCR    BREM    FL_UART_GetLINBusErrorMode
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_BER_MODE_NONE
  */
__STATIC_INLINE uint32_t FL_UART_GetLINBusErrorMode(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINCR, UART_LINCR_BREM_Msk));
}

/**
  * @brief    Enable LIN Noise Detect
  * @rmtoll   LINCR    NDET_EN    FL_UART_EnableLINNoiseDetect
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableLINNoiseDetect(UART_Type *UARTx)
{
    SET_BIT(UARTx->LINCR, UART_LINCR_NDET_EN_Msk);
}

/**
  * @brief    Disable LIN Noise Detect
  * @rmtoll   LINCR    NDET_EN    FL_UART_DisableLINNoiseDetect
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableLINNoiseDetect(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->LINCR, UART_LINCR_NDET_EN_Msk);
}

/**
  * @brief    Get LIN Noise Detect Enable Status
  * @rmtoll   LINCR    NDET_EN    FL_UART_IsEnabledLINNoiseDetect
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledLINNoiseDetect(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINCR, UART_LINCR_NDET_EN_Msk) == UART_LINCR_NDET_EN_Msk);
}

/**
  * @brief    Enable LIN WKUP Detect
  * @rmtoll   LINCR    WKDET_EN    FL_UART_EnableLINWkupDetect
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableLINWkupDetect(UART_Type *UARTx)
{
    SET_BIT(UARTx->LINCR, UART_LINCR_WKDET_EN_Msk);
}

/**
  * @brief    Disable LIN WKUP Detect
  * @rmtoll   LINCR    WKDET_EN    FL_UART_DisableLINWkupDetect
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableLINWkupDetect(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->LINCR, UART_LINCR_WKDET_EN_Msk);
}

/**
  * @brief    Get LIN WKUP Detect Enable Status
  * @rmtoll   LINCR    WKDET_EN    FL_UART_IsEnabledLINWkupDetect
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledLINWkupDetect(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINCR, UART_LINCR_WKDET_EN_Msk) == UART_LINCR_WKDET_EN_Msk);
}

/**
  * @brief    Enable Send LIN Break Signal
  * @rmtoll   LINCR    TX_BF    FL_UART_SendLINBreakSignal
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SendLINBreakSignal(UART_Type *UARTx)
{
    SET_BIT(UARTx->LINCR, UART_LINCR_TX_BF_Msk);
}

/**
  * @brief    Enable Send LIN WKUP Signal
  * @rmtoll   LINCR    TX_WKUP    FL_UART_SendLINWkupSignal
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SendLINWkupSignal(UART_Type *UARTx)
{
    SET_BIT(UARTx->LINCR, UART_LINCR_TX_WKUP_Msk);
}

/**
  * @brief    Get BAUD_SYNC
  * @rmtoll   LINBSR    BAUD_SYNC    FL_UART_ReadSyncFieldCounter
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadSyncFieldCounter(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINBSR, (0xfffffU << 0U)) >> 0U);
}

/**
  * @brief    Set LIN Frame Timeout
  * @rmtoll   LINFTR    FTO    FL_UART_WriteLINFrameTimeout
  * @param    UARTx UART instance
  * @param    timeout
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteLINFrameTimeout(UART_Type *UARTx, uint32_t timeout)
{
    MODIFY_REG(UARTx->LINFTR, (0xfffU << 0U), (timeout << 0U));
}

/**
  * @brief    Get LIN Frame Timeout
  * @rmtoll   LINFTR    FTO    FL_UART_ReadLINFrameTimeout
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINFrameTimeout(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINFTR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Set LIN Inter-byte Space
  * @rmtoll   LINTTR    IBS    FL_UART_WriteLINInterbyteSpace
  * @param    UARTx UART instance
  * @param    space
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteLINInterbyteSpace(UART_Type *UARTx, uint32_t space)
{
    MODIFY_REG(UARTx->LINTTR, (0x3U << 12U), (space << 12U));
}

/**
  * @brief    Get LIN Inter-byte Space
  * @rmtoll   LINTTR    IBS    FL_UART_ReadLINInterbyteSpace
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINInterbyteSpace(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINTTR, (0x3U << 12U)) >> 12U);
}

/**
  * @brief    Set LIN Response Space
  * @rmtoll   LINTTR    RSS    FL_UART_WriteLINResponseSpace
  * @param    UARTx UART instance
  * @param    space
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteLINResponseSpace(UART_Type *UARTx, uint32_t space)
{
    MODIFY_REG(UARTx->LINTTR, (0x7U << 8U), (space << 8U));
}

/**
  * @brief    Get LIN Response Space
  * @rmtoll   LINTTR    RSS    FL_UART_ReadLINResponseSpace
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINResponseSpace(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINTTR, (0x7U << 8U)) >> 8U);
}

/**
  * @brief    Set LIN Break Delimiter
  * @rmtoll   LINTTR    BDT    FL_UART_WriteLINBreakSpace
  * @param    UARTx UART instance
  * @param    space
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteLINBreakSpace(UART_Type *UARTx, uint32_t space)
{
    MODIFY_REG(UARTx->LINTTR, (0x3U << 4U), (space << 4U));
}

/**
  * @brief    Get LIN Break Delimiter
  * @rmtoll   LINTTR    BDT    FL_UART_ReadLINBreakSpace
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINBreakSpace(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINTTR, (0x3U << 4U)) >> 4U);
}

/**
  * @brief    Set LIN Break Length
  * @rmtoll   LINTTR    BLT    FL_UART_WriteLINBreakLength
  * @param    UARTx UART instance
  * @param    length
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteLINBreakLength(UART_Type *UARTx, uint32_t length)
{
    MODIFY_REG(UARTx->LINTTR, (0xfU << 0U), (length << 0U));
}

/**
  * @brief    Get LIN Break Length
  * @rmtoll   LINTTR    BLT    FL_UART_ReadLINBreakLength
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINBreakLength(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINTTR, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Get LIN PRE_SYNC Count
  * @rmtoll   LINPSR    PRE_SYNC    FL_UART_ReadLINPresyncCount
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINPresyncCount(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINPSR, (0xfffffU << 0U)) >> 0U);
}

/**
  * @brief    Get LIN BREAK Length Count
  * @rmtoll   LINBKR    BREAK_LEN    FL_UART_ReadLINBreakLengthCount
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadLINBreakLengthCount(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINBKR, (0xfffU << 0U)) >> 0U);
}

/**
  * @brief    Set LIN Self-test Mode
  * @rmtoll   LINSSCR    LINSTC    FL_UART_SetLINSelftestMode
  * @param    UARTx UART instance
  * @param    Mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_SELFTEST_MODE_NONE
  *           @arg @ref FL_UART_SELFTEST_MODE_LIN01
  *           @arg @ref FL_UART_SELFTEST_MODE_LIN02
  *           @arg @ref FL_UART_SELFTEST_MODE_LIN03
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetLINSelftestMode(UART_Type *UARTx, uint32_t Mode)
{
    MODIFY_REG(UARTx->LINSCCR, UART_LINSCCR_LINSTC_Msk, Mode);
}

/**
  * @brief    Get LIN Self-test Mode
  * @rmtoll   LINSSCR    LINSTC    FL_UART_GetLINSelftestMode
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_SELFTEST_MODE_NONE
  */
__STATIC_INLINE uint32_t FL_UART_GetLINSelftestMode(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->LINSCCR, UART_LINSCCR_LINSTC_Msk));
}

/**
  * @brief    获取UART通信标志
  * @rmtoll   CSR    BUSY    FL_UART_IsActiveFlag_Busy
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_Busy(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_BUSY_Msk) == (UART_CSR_BUSY_Msk));
}

/**
  * @brief    Enable UART RTS
  * @rmtoll   CSR    RTSEN    FL_UART_EnableRTS
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableRTS(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_RTSEN_Msk);
}

/**
  * @brief    Disable UART RTS
  * @rmtoll   CSR    RTSEN    FL_UART_DisableRTS
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableRTS(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_RTSEN_Msk);
}

/**
  * @brief    Get UART RTS Enable Status
  * @rmtoll   CSR    RTSEN    FL_UART_IsEnabledRTS
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledRTS(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RTSEN_Msk) == UART_CSR_RTSEN_Msk);
}

/**
  * @brief    Enable UART CTS
  * @rmtoll   CSR    CTSEN    FL_UART_EnableCTS
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableCTS(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_CTSEN_Msk);
}

/**
  * @brief    Disable UART CTS
  * @rmtoll   CSR    CTSEN    FL_UART_DisableCTS
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableCTS(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_CTSEN_Msk);
}

/**
  * @brief    Get UART CTS Enable Status
  * @rmtoll   CSR    CTSEN    FL_UART_IsEnabledCTS
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledCTS(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_CTSEN_Msk) == UART_CSR_CTSEN_Msk);
}

/**
  * @brief    Enable UART Infrared Modulation
  * @rmtoll   CSR    TXIREN    FL_UART_EnableIRModulation
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIRModulation(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_TXIREN_Msk);
}

/**
  * @brief    Disable UART Infrared Modulation
  * @rmtoll   CSR    TXIREN    FL_UART_DisableIRModulation
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIRModulation(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_TXIREN_Msk);
}

/**
  * @brief    Get UART Infrared Modulation Enable Status
  * @rmtoll   CSR    TXIREN    FL_UART_IsEnabledIRModulation
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIRModulation(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_TXIREN_Msk) == UART_CSR_TXIREN_Msk);
}

/**
  * @brief    Enable UART Receive Time-Out Function
  * @rmtoll   CSR    RXTOEN    FL_UART_EnableRXTimeout
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableRXTimeout(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_RXTOEN_Msk);
}

/**
  * @brief    Disable UART Receive Time-Out Function
  * @rmtoll   CSR    RXTOEN    FL_UART_DisableRXTimeout
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableRXTimeout(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_RXTOEN_Msk);
}

/**
  * @brief    Get UART Receive Time-Out Function Enable Status
  * @rmtoll   CSR    RXTOEN    FL_UART_IsEnabledRXTimeout
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledRXTimeout(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RXTOEN_Msk) == UART_CSR_RXTOEN_Msk);
}

/**
  * @brief    Enable UART Resyncen
  * @rmtoll   CSR    RESYNCEN    FL_UART_EnableResyncen
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableResyncen(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_RESYNCEN_Msk);
}

/**
  * @brief    Disable UART Resyncen
  * @rmtoll   CSR    RESYNCEN    FL_UART_DisableResyncen
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableResyncen(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_RESYNCEN_Msk);
}

/**
  * @brief    Get UART Resyncen Enable Status
  * @rmtoll   CSR    RESYNCEN    FL_UART_IsEnabledResyncen
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledResyncen(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RESYNCEN_Msk) == UART_CSR_RESYNCEN_Msk);
}

/**
  * @brief    Enable U7816  CLK OUTPUT Function
  * @rmtoll   CSR    CKOEN    FL_UART_EnableU7816ClkOutput
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableU7816ClkOutput(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_CKOEN_Msk);
}

/**
  * @brief    Disable U7816 CLK OUTPUT Function
  * @rmtoll   CSR    CKOEN    FL_UART_DisableU7816ClkOutput
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableU7816ClkOutput(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_CKOEN_Msk);
}

/**
  * @brief    Get UART U7816 CLK OUTPUT Function Enable Status
  * @rmtoll   CSR    CKOEN    FL_UART_IsEnabledU7816ClkOutput
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledU7816ClkOutput(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_CKOEN_Msk) == UART_CSR_CKOEN_Msk);
}

/**
  * @brief    Set Oversampling Mode
  * @rmtoll   CSR    OVSM    FL_UART_SetOverSampling
  * @param    UARTx UART instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_OVERSAMPLING_16
  *           @arg @ref FL_UART_OVERSAMPLING_8
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetOverSampling(UART_Type *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_OVSM_Msk, mode);
}

/**
  * @brief    Get Oversampling Mode
  * @rmtoll   CSR    OVSM    FL_UART_GetOverSampling
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_OVERSAMPLING_16
  *           @arg @ref FL_UART_OVERSAMPLING_8
  */
__STATIC_INLINE uint32_t FL_UART_GetOverSampling(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_OVSM_Msk));
}

/**
  * @brief    Enable UART Pin Swap Between UART TX Pin and RX Pin
  * @rmtoll   CSR    IOSWAP    FL_UART_EnablePinSwap
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnablePinSwap(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_IOSWAP_Msk);
}

/**
  * @brief    Disable UART Pin Swap Between UART TX Pin and RX Pin
  * @rmtoll   CSR    IOSWAP    FL_UART_DisablePinSwap
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisablePinSwap(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_IOSWAP_Msk);
}

/**
  * @brief    Get UART Pin Swap Enable Status Between UART TX Pin and RX Pin
  * @rmtoll   CSR    IOSWAP    FL_UART_IsEnabledPinSwap
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledPinSwap(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_IOSWAP_Msk) == UART_CSR_IOSWAP_Msk);
}

/**
  * @brief    Enable UART Negtive Edge Wakeup Function
  * @rmtoll   CSR    NEWUP    FL_UART_EnableFallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableFallingEdgeWakeup(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_NEWUP_Msk);
}

/**
  * @brief    Disable UART Negtive Edge Wakeup Function
  * @rmtoll   CSR    NEWUP    FL_UART_DisableFallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableFallingEdgeWakeup(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_NEWUP_Msk);
}

/**
  * @brief    Get UART Negtive Edge Wakeup Function Enable Status
  * @rmtoll   CSR    NEWUP    FL_UART_IsEnabledFallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledFallingEdgeWakeup(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_NEWUP_Msk) == UART_CSR_NEWUP_Msk);
}

/**
  * @brief    Set UART DMA Transmit Finish Interrupt
  * @rmtoll   CSR    DMATXIFCFG    FL_UART_SetTXIFMode
  * @param    UARTx UART instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_UART_TXIF_MODE_ALWAYS
  *           @arg @ref FL_UART_TXIF_MODE_AFTER_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetTXIFMode(UART_Type *UARTx, uint32_t mode)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_DMATXIFCFG_Msk, mode);
}

/**
  * @brief    Get UART DMA Transmit Finish Interrupt
  * @rmtoll   CSR    DMATXIFCFG    FL_UART_GetTXIFMode
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_TXIF_MODE_ALWAYS
  *           @arg @ref FL_UART_TXIF_MODE_AFTER_DMA
  */
__STATIC_INLINE uint32_t FL_UART_GetTXIFMode(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_DMATXIFCFG_Msk));
}

/**
  * @brief    Set UART Transfer Bit Order
  * @rmtoll   CSR    BITORD    FL_UART_SetBitOrder
  * @param    UARTx UART instance
  * @param    order This parameter can be one of the following values:
  *           @arg @ref FL_UART_BIT_ORDER_LSB_FIRST
  *           @arg @ref FL_UART_BIT_ORDER_MSB_FIRST
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetBitOrder(UART_Type *UARTx, uint32_t order)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_BITORD_Msk, order);
}

/**
  * @brief    Get UART Transfer Bit Order
  * @rmtoll   CSR    BITORD    FL_UART_GetBitOrder
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_BIT_ORDER_LSB_FIRST
  *           @arg @ref FL_UART_BIT_ORDER_MSB_FIRST
  */
__STATIC_INLINE uint32_t FL_UART_GetBitOrder(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_BITORD_Msk));
}

/**
  * @brief    Set UART Stop Bits Length
  * @rmtoll   CSR    STOPCFG    FL_UART_SetStopBitsWidth
  * @param    UARTx UART instance
  * @param    length This parameter can be one of the following values:
  *           @arg @ref FL_UART_STOP_BIT_WIDTH_1B
  *           @arg @ref FL_UART_STOP_BIT_WIDTH_2B
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetStopBitsWidth(UART_Type *UARTx, uint32_t length)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_STOPCFG_Msk, length);
}

/**
  * @brief    Get UART Stop Bits Length
  * @rmtoll   CSR    STOPCFG    FL_UART_GetStopBitsWidth
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_STOP_BIT_WIDTH_1B
  *           @arg @ref FL_UART_STOP_BIT_WIDTH_2B
  */
__STATIC_INLINE uint32_t FL_UART_GetStopBitsWidth(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_STOPCFG_Msk));
}

/**
  * @brief    Set UART Data Width
  * @rmtoll   CSR    PDSEL    FL_UART_SetDataWidth
  * @param    UARTx UART instance
  * @param    dataWidth This parameter can be one of the following values:
  *           @arg @ref FL_UART_DATA_WIDTH_7B
  *           @arg @ref FL_UART_DATA_WIDTH_8B
  *           @arg @ref FL_UART_DATA_WIDTH_9B
  *           @arg @ref FL_UART_DATA_WIDTH_6B
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetDataWidth(UART_Type *UARTx, uint32_t dataWidth)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_PDSEL_Msk, dataWidth);
}

/**
  * @brief    Get UART Data Width
  * @rmtoll   CSR    PDSEL    FL_UART_GetDataWidth
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_DATA_WIDTH_7B
  *           @arg @ref FL_UART_DATA_WIDTH_8B
  *           @arg @ref FL_UART_DATA_WIDTH_9B
  *           @arg @ref FL_UART_DATA_WIDTH_6B
  */
__STATIC_INLINE uint32_t FL_UART_GetDataWidth(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_PDSEL_Msk));
}

/**
  * @brief    Set UART Parity
  * @rmtoll   CSR    PARITY    FL_UART_SetParity
  * @param    UARTx UART instance
  * @param    parity This parameter can be one of the following values:
  *           @arg @ref FL_UART_PARITY_NONE
  *           @arg @ref FL_UART_PARITY_EVEN
  *           @arg @ref FL_UART_PARITY_ODD
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetParity(UART_Type *UARTx, uint32_t parity)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_PARITY_Msk, parity);
}

/**
  * @brief    Get UART Parity
  * @rmtoll   CSR    PARITY    FL_UART_GetParity
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_PARITY_NONE
  *           @arg @ref FL_UART_PARITY_EVEN
  *           @arg @ref FL_UART_PARITY_ODD
  */
__STATIC_INLINE uint32_t FL_UART_GetParity(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_PARITY_Msk));
}

/**
  * @brief    Set UART Receive Polarity
  * @rmtoll   CSR    RXPOL    FL_UART_SetRXPolarity
  * @param    UARTx UART instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_UART_RX_POLARITY_NORMAL
  *           @arg @ref FL_UART_RX_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetRXPolarity(UART_Type *UARTx, uint32_t polarity)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_RXPOL_Msk, polarity);
}

/**
  * @brief    Get UART Receive Polarity
  * @rmtoll   CSR    RXPOL    FL_UART_GetRXPolarity
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_RX_POLARITY_NORMAL
  *           @arg @ref FL_UART_RX_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_UART_GetRXPolarity(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RXPOL_Msk));
}

/**
  * @brief    Set UART Transmit Polarity
  * @rmtoll   CSR    TXPOL    FL_UART_SetTXPolarity
  * @param    UARTx UART instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_UART_TX_POLARITY_NORMAL
  *           @arg @ref FL_UART_TX_POLARITY_INVERT
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetTXPolarity(UART_Type *UARTx, uint32_t polarity)
{
    MODIFY_REG(UARTx->CSR, UART_CSR_TXPOL_Msk, polarity);
}

/**
  * @brief    Get UART Transmit Polarity
  * @rmtoll   CSR    TXPOL    FL_UART_GetTXPolarity
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_TX_POLARITY_NORMAL
  *           @arg @ref FL_UART_TX_POLARITY_INVERT
  */
__STATIC_INLINE uint32_t FL_UART_GetTXPolarity(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_TXPOL_Msk));
}

/**
  * @brief    Enable UART Receive
  * @rmtoll   CSR    RXEN    FL_UART_EnableRX
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableRX(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_RXEN_Msk);
}

/**
  * @brief    Disable UART Receive
  * @rmtoll   CSR    RXEN    FL_UART_DisableRX
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableRX(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_RXEN_Msk);
}

/**
  * @brief    Get UART Receive Enable Status
  * @rmtoll   CSR    RXEN    FL_UART_IsEnabledRX
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledRX(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_RXEN_Msk) == UART_CSR_RXEN_Msk);
}

/**
  * @brief    Enable UART Transmit
  * @rmtoll   CSR    TXEN    FL_UART_EnableTX
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableTX(UART_Type *UARTx)
{
    SET_BIT(UARTx->CSR, UART_CSR_TXEN_Msk);
}

/**
  * @brief    Disable UART Receive
  * @rmtoll   CSR    TXEN    FL_UART_DisableTX
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableTX(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->CSR, UART_CSR_TXEN_Msk);
}

/**
  * @brief    Get UART Receive Enable Status
  * @rmtoll   CSR    TXEN    FL_UART_IsEnabledTX
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledTX(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CSR, UART_CSR_TXEN_Msk) == UART_CSR_TXEN_Msk);
}

/**
  * @brief    使能UART LIN timeout中断
  * @rmtoll   IER    TOERIE    FL_UART_EnableIT_TimeoutError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_TimeoutError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TOERIE_Msk);
}

/**
  * @brief    失能UART LIN timeout中断
  * @rmtoll   IER    TOERIE    FL_UART_DisableIT_TimeoutError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_TimeoutError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_TOERIE_Msk);
}

/**
  * @brief    获取UART LIN timeout中断使能状态
  * @rmtoll   IER    TOERIE    FL_UART_IsEnabledIT_TimeoutError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_TimeoutError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_TOERIE_Msk) == UART_IER_TOERIE_Msk);
}

/**
  * @brief    使能UART LIN sync error中断
  * @rmtoll   IER    SERIE    FL_UART_EnableIT_SyncError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_SyncError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_SERIE_Msk);
}

/**
  * @brief    失能UART LIN sync error中断
  * @rmtoll   IER    SERIE    FL_UART_DisableIT_SyncError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_SyncError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_SERIE_Msk);
}

/**
  * @brief    获取UART LIN sync error中断使能状态
  * @rmtoll   IER    SERIE    FL_UART_IsEnabledIT_SyncError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_SyncError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_SERIE_Msk) == UART_IER_SERIE_Msk);
}

/**
  * @brief    使能UART LIN 发送冲突中断
  * @rmtoll   IER    BERIE    FL_UART_EnableIT_BER
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_BER(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_BERIE_Msk);
}

/**
  * @brief    失能UART LIN 发送冲突中断
  * @rmtoll   IER    BERIE    FL_UART_DisableIT_BER
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_BER(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_BERIE_Msk);
}

/**
  * @brief    获取UART LIN 发送冲突中断使能状态
  * @rmtoll   IER    BERIE    FL_UART_IsEnabledIT_BER
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_BER(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_BERIE_Msk) == UART_IER_BERIE_Msk);
}

/**
  * @brief    使能UART LIN 噪声监测中断
  * @rmtoll   IER    NFIE    FL_UART_EnableIT_Noise
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_Noise(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_NFIE_Msk);
}

/**
  * @brief    失能UART LIN 噪声监测中断
  * @rmtoll   IER    NFIE    FL_UART_DisableIT_Noise
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_Noise(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_NFIE_Msk);
}

/**
  * @brief    获取UART LIN 噪声监测中断使能状态
  * @rmtoll   IER    NFIE    FL_UART_IsEnabledIT_Noise
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_Noise(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_NFIE_Msk) == UART_IER_NFIE_Msk);
}

/**
  * @brief    Enable LIN SyncField Interrupt
  * @rmtoll   IER    LINSYNCIE    FL_UART_EnableIT_LINSyncField
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_LINSYNC(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINSYNCIE_Msk);
}

/**
  * @brief    Disable LIN SyncField Interrupt
  * @rmtoll   IER    LINSYNCIE    FL_UART_DisableIT_LINSyncField
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_LINSYNC(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_LINSYNCIE_Msk);
}

/**
  * @brief    Get LIN SyncField Interrupt Enable Status
  * @rmtoll   IER    LINSYNCIE    FL_UART_IsEnabledIT_LINSyncField
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_LINSYNC(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_LINSYNCIE_Msk) == UART_IER_LINSYNCIE_Msk);
}

/**
  * @brief    Enable LIN BreakField Interrupt
  * @rmtoll   IER    LINBIE    FL_UART_EnableIT_LINBreakField
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_LINBreak(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINBIE_Msk);
}

/**
  * @brief    Disable LIN BreakFieldInterrupt
  * @rmtoll   IER    LINBIE    FL_UART_DisableIT_LINBreakField
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_LINBreak(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_LINBIE_Msk);
}

/**
  * @brief    Get LIN BreakField Interrupt Enable Status
  * @rmtoll   IER    LINBIE    FL_UART_IsEnabledIT_LINBreakField
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_LINBreak(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_LINBIE_Msk) == UART_IER_LINBIE_Msk);
}

/**
  * @brief    Enable LIN WakeUp Interrupt
  * @rmtoll   IER    LINWKIE    FL_UART_EnableIT_LINWakeUp
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_LINWK(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINWKIE_Msk);
}

/**
  * @brief    Disable LIN WakeUp Interrupt
  * @rmtoll   IER    LINWKIE    FL_UART_DisableIT_LINWakeUp
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_LINWK(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_LINWKIE_Msk);
}

/**
  * @brief    Get LIN WakeUp Interrupt Enable Status
  * @rmtoll   IER    LINWKIE    FL_UART_IsEnabledIT_LINWakeUp
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_LINWK(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_LINWKIE_Msk) == UART_IER_LINWKIE_Msk);
}

/**
  * @brief    使能UART LIN唤醒完成中断
  * @rmtoll   IER    LINWKTFIE    FL_UART_EnableIT_LINWKTF
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_LINWKTF(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINWKTFIE_Msk);
}

/**
  * @brief    失能UART LIN唤醒完成中断
  * @rmtoll   IER    LINWKTFIE    FL_UART_DisableIT_LINWKTF
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_LINWKTF(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_LINWKTFIE_Msk);
}

/**
  * @brief    获取UART LIN唤醒完成中断使能状态
  * @rmtoll   IER    LINWKTFIE    FL_UART_IsEnabledIT_LINWKTF
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_LINWKTF(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_LINWKTFIE_Msk) == UART_IER_LINWKTFIE_Msk);
}

/**
  * @brief    使能UART LIN BREAK 结束中断
  * @rmtoll   IER    LINBEFIE    FL_UART_EnableIT_LINBreakEnd
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_LINBreakEnd(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINBEFIE_Msk);
}

/**
  * @brief    失能UART LIN BREAK 结束中断
  * @rmtoll   IER    LINBEFIE    FL_UART_DisableIT_LINBreakEnd
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_LINBreakEnd(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_LINBEFIE_Msk);
}

/**
  * @brief    获取UART LIN BREAK 结束中断使能状态
  * @rmtoll   IER    LINBEFIE    FL_UART_IsEnabledIT_LINBreakEnd
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_LINBreakEnd(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_LINBEFIE_Msk) == UART_IER_LINBEFIE_Msk);
}

/**
  * @brief    使能UART LIN BREAK ERROR中断
  * @rmtoll   IER    LINBERIE    FL_UART_EnableIT_LINBreakError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_LINBreakError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_LINBERIE_Msk);
}

/**
  * @brief    失能UART LIN BREAK ERROR中断
  * @rmtoll   IER    LINBERIE    FL_UART_DisableIT_LINBreakError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_LINBreakError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_LINBERIE_Msk);
}

/**
  * @brief    获取UART LIN BREAK ERROR使能状态
  * @rmtoll   IER    LINBERIE    FL_UART_IsEnabledIT_LINBreakError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_LINBreakError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_LINBERIE_Msk) == UART_IER_LINBERIE_Msk);
}

/**
  * @brief    使能UART奇偶检验错误中断
  * @rmtoll   IER    PERRIE    FL_UART_EnableIT_ParityError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_ParityError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_PERRIE_Msk);
}

/**
  * @brief    失能UART奇偶检验错误中断
  * @rmtoll   IER    PERRIE    FL_UART_DisableIT_ParityError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_ParityError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_PERRIE_Msk);
}

/**
  * @brief    获取UART奇偶检验错误使能状态
  * @rmtoll   IER    PERRIE    FL_UART_IsEnabledIT_ParityError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_ParityError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_PERRIE_Msk) == UART_IER_PERRIE_Msk);
}

/**
  * @brief    使能UART帧格式错误中断
  * @rmtoll   IER    FERRIE    FL_UART_EnableIT_FrameError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_FrameError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_FERRIE_Msk);
}

/**
  * @brief    失能UART帧格式错误中断
  * @rmtoll   IER    FERRIE    FL_UART_DisableIT_FrameError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_FrameError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_FERRIE_Msk);
}

/**
  * @brief    获取UART帧格式错误使能状态
  * @rmtoll   IER    FERRIE    FL_UART_IsEnabledIT_FrameError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_FrameError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_FERRIE_Msk) == UART_IER_FERRIE_Msk);
}

/**
  * @brief    使能UART接收缓存溢出错误中断
  * @rmtoll   IER    OERRIE    FL_UART_EnableIT_OverflowError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_OverflowError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_OERRIE_Msk);
}

/**
  * @brief    失能UART接收缓存溢出错误中断
  * @rmtoll   IER    OERRIE    FL_UART_DisableIT_OverflowError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_OverflowError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_OERRIE_Msk);
}

/**
  * @brief    获取UART接收缓存溢出错误使能状态
  * @rmtoll   IER    OERRIE    FL_UART_IsEnabledIT_OverflowError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_OverflowError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_OERRIE_Msk) == UART_IER_OERRIE_Msk);
}

/**
  * @brief    使能UART nCTS翻转中断
  * @rmtoll   IER    CTSIE    FL_UART_EnableIT_ncts
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_ncts(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_CTSIE_Msk);
}

/**
  * @brief    失能UART nCTS翻转中断
  * @rmtoll   IER    CTSIE    FL_UART_DisableIT_ncts
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_ncts(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_CTSIE_Msk);
}

/**
  * @brief    获取UART nCTS翻转中断使能状态
  * @rmtoll   IER    CTSIE    FL_UART_IsEnabledIT_ncts
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_ncts(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_CTSIE_Msk) == UART_IER_CTSIE_Msk);
}

/**
  * @brief    Enable UART Receive Time-Out Interrupt
  * @rmtoll   IER    RXTOIE    FL_UART_EnableIT_RXTimeout
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_RXTimeout(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXTOIE_Msk);
}

/**
  * @brief    Disable UART Receive Time-Out Interrupt
  * @rmtoll   IER    RXTOIE    FL_UART_DisableIT_RXTimeout
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_RXTimeout(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_RXTOIE_Msk);
}

/**
  * @brief    Get UART Receive Time-Out Interrupt Enable Status
  * @rmtoll   IER    RXTOIE    FL_UART_IsEnabledIT_RXTimeout
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_RXTimeout(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_RXTOIE_Msk) == UART_IER_RXTOIE_Msk);
}

/**
  * @brief    Enable UART Receive Error Interrupt
  * @rmtoll   IER    RXERRIE    FL_UART_EnableIT_RXError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_RXError(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXERRIE_Msk);
}

/**
  * @brief    Disable UART Receive Error Interrupt
  * @rmtoll   IER    RXERRIE    FL_UART_DisableIT_RXError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_RXError(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_RXERRIE_Msk);
}

/**
  * @brief    Get UART Receive Error Interrupt Enable Status
  * @rmtoll   IER    RXERRIE    FL_UART_IsEnabledIT_RXError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_RXError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_RXERRIE_Msk) == UART_IER_RXERRIE_Msk);
}

/**
  * @brief    Enable UART Receive Buffer Full Interrupt
  * @rmtoll   IER    RXBFIE    FL_UART_EnableIT_RXBuffFull
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_RXBuffFull(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_RXBFIE_Msk);
}

/**
  * @brief    Disable UART Receive Buffer Full Interrupt
  * @rmtoll   IER    RXBFIE    FL_UART_DisableIT_RXBuffFull
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_RXBuffFull(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_RXBFIE_Msk);
}

/**
  * @brief    Get UART Receive Buffer Full Interrupt Enable Status
  * @rmtoll   IER    RXBFIE    FL_UART_IsEnabledIT_RXBuffFull
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_RXBuffFull(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_RXBFIE_Msk) == UART_IER_RXBFIE_Msk);
}

/**
  * @brief    Enable UART Negedge Wakeup Interrupt
  * @rmtoll   IER    NEWUPIE    FL_UART_EnableIT_FallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_FallingEdgeWakeup(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_NEWUPIE_Msk);
}

/**
  * @brief    Disable UART Negedge Wakeup Interrupt
  * @rmtoll   IER    NEWUPIE    FL_UART_DisableIT_FallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_FallingEdgeWakeup(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_NEWUPIE_Msk);
}

/**
  * @brief    Get UART Negedge Wakeup Interrupt Enable Status
  * @rmtoll   IER    NEWUPIE    FL_UART_IsEnabledIT_FallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_FallingEdgeWakeup(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_NEWUPIE_Msk) == UART_IER_NEWUPIE_Msk);
}

/**
  * @brief    Enable UART Transmit Buffer Empty Interrupt
  * @rmtoll   IER    TXBEIE    FL_UART_EnableIT_TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_TXBuffEmpty(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TXBEIE_Msk);
}

/**
  * @brief    Disable UART Transmit Buffer Empty Interrupt
  * @rmtoll   IER    TXBEIE    FL_UART_DisableIT_TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_TXBuffEmpty(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_TXBEIE_Msk);
}

/**
  * @brief    Get UART Transmit Buffer Empty Interrupt Enable Status
  * @rmtoll   IER    TXBEIE    FL_UART_IsEnabledIT_TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_TXBuffEmpty(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_TXBEIE_Msk) == UART_IER_TXBEIE_Msk);
}

/**
  * @brief    Enable UART Transmit Shift Register Empty Interrupt
  * @rmtoll   IER    TXSEIE    FL_UART_EnableIT_TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_TXShiftBuffEmpty(UART_Type *UARTx)
{
    SET_BIT(UARTx->IER, UART_IER_TXSEIE_Msk);
}

/**
  * @brief    Disable UART Transmit Shift Register Empty Interrupt
  * @rmtoll   IER    TXSEIE    FL_UART_DisableIT_TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_TXShiftBuffEmpty(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->IER, UART_IER_TXSEIE_Msk);
}

/**
  * @brief    Get UART Transmit Shift Register Empty Interrupt Enable Status
  * @rmtoll   IER    TXSEIE    FL_UART_IsEnabledIT_TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_TXShiftBuffEmpty(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->IER, UART_IER_TXSEIE_Msk) == UART_IER_TXSEIE_Msk);
}

/**
  * @brief    获取UART LIN Timeout error标志
  * @rmtoll   ISR    TOER    FL_UART_IsActiveFlag_TimeoutError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_TimeoutError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_TOER_Msk) == (UART_ISR_TOER_Msk));
}

/**
  * @brief    清除UART LIN Timeout error标志
  * @rmtoll   ISR    TOER    FL_UART_ClearFlag_TimeoutError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_TimeoutError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_TOER_Msk);
}

/**
  * @brief    获取UART LIN sync error标志
  * @rmtoll   ISR    SER    FL_UART_IsActiveFlag_SyncError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_SyncError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_SER_Msk) == (UART_ISR_SER_Msk));
}

/**
  * @brief    清除UART LIN sync error标志
  * @rmtoll   ISR    SER    FL_UART_ClearFlag_SyncError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_SyncError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_SER_Msk);
}

/**
  * @brief    获取UART LIN 发送冲突标志
  * @rmtoll   ISR    BERIF    FL_UART_IsActiveFlag_BER
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_BER(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_BERIF_Msk) == (UART_ISR_BERIF_Msk));
}

/**
  * @brief    清除UART LIN 发送冲突标志
  * @rmtoll   ISR    BERIF    FL_UART_ClearFlag_BER
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_BER(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_BERIF_Msk);
}

/**
  * @brief    获取UART LIN 总线噪声检测标志
  * @rmtoll   ISR    NF    FL_UART_IsActiveFlag_Noise
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_Noise(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_NF_Msk) == (UART_ISR_NF_Msk));
}

/**
  * @brief    清除UART LIN 总线噪声检测标志
  * @rmtoll   ISR    NF    FL_UART_ClearFlag_Noise
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_Noise(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_NF_Msk);
}

/**
  * @brief    Get LIN SyncField Receive Complete Flag
  * @rmtoll   ISR    LINSYNCF    FL_UART_IsActiveFlag_LINSyncFeildReceiveComplete
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_Sync(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_LINSYNCF_Msk) == (UART_ISR_LINSYNCF_Msk));
}

/**
  * @brief    Clear LIN SyncField Receive Complete Flag
  * @rmtoll   ISR    LINSYNCF    FL_UART_ClearFlag_LINSyncFeildReceiveComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_Sync(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_LINSYNCF_Msk);
}

/**
  * @brief    Get LIN BreakField Receive Complete Flag
  * @rmtoll   ISR    LINBF    FL_UART_IsActiveFlag_LINBreakFeildReceiveComplete
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_Break(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_LINBF_Msk) == (UART_ISR_LINBF_Msk));
}

/**
  * @brief    Clear LIN BreakField Receive Complete Flag
  * @rmtoll   ISR    LINBF    FL_UART_ClearFlag_LINSyncBreakReceiveComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_Break(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_LINBF_Msk);
}

/**
  * @brief    Get LIN WakeUp Signal Flag
  * @rmtoll   ISR    LINWKDF    FL_UART_IsActiveFlag_LINDetectWakeUpSignal
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_WakeupDetect(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_LINWKDF_Msk) == (UART_ISR_LINWKDF_Msk));
}

/**
  * @brief    Clear LIN WakeUp Signal Flag
  * @rmtoll   ISR    LINWKDF    FL_UART_ClearFlag_LINDetectWakeUpSignal
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_WakeupDetect(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_LINWKDF_Msk);
}

/**
  * @brief    Get LIN WakeUp Signal Send Complete Flag
  * @rmtoll   ISR    LINWKTF    FL_UART_IsActiveFlag_LINWakeUpSignalSendComplete
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_WakeupTx(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_LINWKTF_Msk) == (UART_ISR_LINWKTF_Msk));
}

/**
  * @brief    Clear LIN WakeUp Signal Send Complete Flag
  * @rmtoll   ISR    LINWKTF    FL_UART_ClearFlag_LINWakeUpSignalSendComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_WakeupTx(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_LINWKTF_Msk);
}

/**
  * @brief    获取UART LIN Break 段结束中断标志
  * @rmtoll   ISR    LINBEF    FL_UART_IsActiveFlag_LINBreakEnd
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_LINBreakEnd(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_LINBEF_Msk) == (UART_ISR_LINBEF_Msk));
}

/**
  * @brief    清除UART LIN Break 段结束中断标志
  * @rmtoll   ISR    LINBEF    FL_UART_ClearFlag_LINBreakEnd
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_LINBreakEnd(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_LINBEF_Msk);
}

/**
  * @brief    获取UART LIN Break error标志
  * @rmtoll   ISR    LINBER    FL_UART_IsActiveFlag_LINBreakError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_LINBreakError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_LINBER_Msk) == (UART_ISR_LINBER_Msk));
}

/**
  * @brief    清除UART LIN Break error标志
  * @rmtoll   ISR    LINBER    FL_UART_ClearFlag_LINBreakError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_LINBreakError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_LINBER_Msk);
}

/**
  * @brief    Get UART Parity Error Flag
  * @rmtoll   ISR    PERR    FL_UART_IsActiveFlag_ParityError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_ParityError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_PERR_Msk) == (UART_ISR_PERR_Msk));
}

/**
  * @brief    Clear UART Parity Error Flag
  * @rmtoll   ISR    PERR    FL_UART_ClearFlag_ParityError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_ParityError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_PERR_Msk);
}

/**
  * @brief    Get UART Frame Error Flag
  * @rmtoll   ISR    FERR    FL_UART_IsActiveFlag_FrameError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_FrameError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_FERR_Msk) == (UART_ISR_FERR_Msk));
}

/**
  * @brief    Clear UART Frame Error Flag
  * @rmtoll   ISR    FERR    FL_UART_ClearFlag_FrameError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_FrameError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_FERR_Msk);
}

/**
  * @brief    Get UART RX buffer Overflow Error Flag
  * @rmtoll   ISR    OERR    FL_UART_IsActiveFlag_RXBuffOverflowError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_RXBuffOverflowError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_OERR_Msk) == (UART_ISR_OERR_Msk));
}

/**
  * @brief    Clear UART RX buffer Overflow Error Flag
  * @rmtoll   ISR    OERR    FL_UART_ClearFlag_RXBuffOverflowError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_RXBuffOverflowError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_OERR_Msk);
}

/**
  * @brief    获取UART nCts信号翻转标志
  * @rmtoll   ISR    CTSIF    FL_UART_IsActiveFlag_nCTS
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_nCTS(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_CTSIF_Msk) == (UART_ISR_CTSIF_Msk));
}

/**
  * @brief    清除UART nCts信号翻转标志
  * @rmtoll   ISR    CTSIF    FL_UART_ClearFlag_nCTS
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_nCTS(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_CTSIF_Msk);
}

/**
  * @brief    Get UART Receive Time-Out Flag
  * @rmtoll   ISR    RXTO    FL_UART_IsActiveFlag_RXBuffTimeout
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_RXBuffTimeout(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_RXTO_Msk) == (UART_ISR_RXTO_Msk));
}

/**
  * @brief    Clear UART Receive Time-Out Flag
  * @rmtoll   ISR    RXTO    FL_UART_ClearFlag_RXBuffTimeout
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_RXBuffTimeout(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_RXTO_Msk);
}

/**
  * @brief    Get UART Receive Buffer Full Flag
  * @rmtoll   ISR    RXBF    FL_UART_IsActiveFlag_RXBuffFull
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_RXBuffFull(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_RXBF_Msk) == (UART_ISR_RXBF_Msk));
}

/**
  * @brief    Clear UART Receive Buffer Full Flag
  * @rmtoll   ISR    RXBF    FL_UART_ClearFlag_RXBuffFull
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_RXBuffFull(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_RXBF_Msk);
}

/**
  * @brief    Get UART Negedge Wakeup Flag
  * @rmtoll   ISR    NEWKF    FL_UART_IsActiveFlag_FallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_FallingEdgeWakeup(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_NEWKF_Msk) == (UART_ISR_NEWKF_Msk));
}

/**
  * @brief    Clear UART Negedge Wakeup Flag
  * @rmtoll   ISR    NEWKF    FL_UART_ClearFlag_FallingEdgeWakeup
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_FallingEdgeWakeup(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_NEWKF_Msk);
}

/**
  * @brief    Get UART TX Overflow Error Flag
  * @rmtoll   ISR    TXOERR    FL_UART_IsActiveFlag_TXBuffOverflow
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_TXBuffOverflow(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_TXOERR_Msk) == (UART_ISR_TXOERR_Msk));
}

/**
  * @brief    Get UART Transmit Buffer Empty Flag
  * @rmtoll   ISR    TXBE    FL_UART_IsActiveFlag_TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE void FL_UART_ClearFlag_TXBuffOverflow(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_TXOERR_Msk);
}

/**
  * @brief    Clear UART Transmit Buffer Empty Flag
  * @rmtoll   ISR    TXBE    FL_UART_ClearFlag_TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_TXBuffEmpty(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_TXBE_Msk) == (UART_ISR_TXBE_Msk));
}

/**
  * @brief    Clear UART Transmit Buffer Empty Flag
  * @rmtoll   ISR    TXBE    FL_UART_ClearFlag_TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_TXBuffEmpty(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_TXBE_Msk);
}

/**
  * @brief    Get UART Transmit Shift register Empty  Flag
  * @rmtoll   ISR    TXSE    FL_UART_IsActiveFlag_TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_TXShiftBuffEmpty(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_ISR_TXSE_Msk) == (UART_ISR_TXSE_Msk));
}

/**
  * @brief    Clear UART Transmit Shift register Empty Flag
  * @rmtoll   ISR    TXSE    FL_UART_ClearFlag_TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_TXShiftBuffEmpty(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_ISR_TXSE_Msk);
}

/**
  * @brief    Set UART Transmit Delay Length
  * @rmtoll   TODR    TXDLY_LEN    FL_UART_WriteTXDelay
  * @param    UARTx UART instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteTXDelay(UART_Type *UARTx, uint32_t time)
{
    MODIFY_REG(UARTx->TODR, (0xffU << 8U), (time << 8U));
}

/**
  * @brief    Get UART Transmit Delay Length
  * @rmtoll   TODR    TXDLY_LEN    FL_UART_ReadTXDelay
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadTXDelay(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->TODR, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Set UART Receive Time-Out Length
  * @rmtoll   TODR    RXTO_LEN    FL_UART_WriteRXTimeout
  * @param    UARTx UART instance
  * @param    time
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteRXTimeout(UART_Type *UARTx, uint32_t time)
{
    MODIFY_REG(UARTx->TODR, (0xffU << 0U), (time << 0U));
}

/**
  * @brief    Get UART Receive Time-Out Length
  * @rmtoll   TODR    RXTO_LEN    FL_UART_ReadRXTimeout
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadRXTimeout(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->TODR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    UART Receive 1 byte of data
  * @rmtoll   RXBUF        FL_UART_ReadRXBuff
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadRXBuff(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->RXBUF, (0x1ffU << 0U)) >> 0U);
}

/**
  * @brief    UART Transmit 1 byte of data
  * @rmtoll   TXBUF        FL_UART_WriteTXBuff
  * @param    UARTx UART instance
  * @param    data
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteTXBuff(UART_Type *UARTx, uint32_t data)
{
    MODIFY_REG(UARTx->TXBUF, (0x1ffU << 0U), (data << 0U));
}

/**
  * @brief    Set UART BaudRate
  * @rmtoll   BGR        FL_UART_WriteBaudRate
  * @param    UARTx UART instance
  * @param    baudRate
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteBaudRate(UART_Type *UARTx, uint32_t baudRate)
{
    MODIFY_REG(UARTx->BGR, (0xffffU << 0U), (baudRate << 0U));
}

/**
  * @brief    Get UART BaudRate
  * @rmtoll   BGR        FL_UART_ReadBaudRate
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadBaudRate(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->BGR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Set U7816 TX Guard Time Length
  * @rmtoll   FFR    SFREN    FL_UART_SetU7816TXGuardTime
  * @param    UARTx UART instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_TX_GUARD_TIME_3ETU
  *           @arg @ref FL_UART_U7816_TX_GUARD_TIME_2ETU
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816TXGuardTime(UART_Type *UARTx, uint32_t config)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_SFREN_Msk, config);
}

/**
  * @brief    Get U7816 TX Guard Time Length
  * @rmtoll   FFR    SFREN    FL_UART_GetU7816TXGuardTime
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_TX_GUARD_TIME_3ETU
  *           @arg @ref FL_UART_U7816_TX_GUARD_TIME_2ETU
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816TXGuardTime(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_SFREN_Msk));
}

/**
  * @brief    Set U7816 TX Error Signal Width
  * @rmtoll   FFR    ERSW    FL_UART_SetU7816ErrorSignalWidth
  * @param    UARTx UART instance
  * @param    width This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_ERROR_SIGNAL_WIDTH_2ETU
  *           @arg @ref FL_UART_U7816_ERROR_SIGNAL_WIDTH_1P5ETU
  *           @arg @ref FL_UART_U7816_ERROR_SIGNAL_WIDTH_1ETU
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816ErrorSignalWidth(UART_Type *UARTx, uint32_t width)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_ERSW_Msk, width);
}

/**
  * @brief    Get U7816 TX Error Signal Width
  * @rmtoll   FFR    ERSW    FL_UART_GetU7816ErrorSignalWidth
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_ERROR_SIGNAL_WIDTH_2ETU
  *           @arg @ref FL_UART_U7816_ERROR_SIGNAL_WIDTH_1P5ETU
  *           @arg @ref FL_UART_U7816_ERROR_SIGNAL_WIDTH_1ETU
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816ErrorSignalWidth(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_ERSW_Msk));
}

/**
  * @brief    Set Error Signal Guard Time
  * @rmtoll   FFR    ERSGD    FL_UART_SetU7816ErrorGuardTime
  * @param    UARTx UART instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_ERROR_GUARD_TIME_2ETU
  *           @arg @ref FL_UART_U7816_ERROR_GUARD_TIME_1ETU
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816ErrorGuardTime(UART_Type *UARTx, uint32_t config)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_ERSGD_Msk, config);
}

/**
  * @brief    Get Error Signal Guard Time
  * @rmtoll   FFR    ERSGD    FL_UART_GetU7816ErrorGuardTime
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_ERROR_GUARD_TIME_2ETU
  *           @arg @ref FL_UART_U7816_ERROR_GUARD_TIME_1ETU
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816ErrorGuardTime(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_ERSGD_Msk));
}

/**
  * @brief    Enable U7816 to Insert Block Guard Time
  * @rmtoll   FFR    BGTEN    FL_UART_EnableU7816BlockGuardTime
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableU7816BlockGuardTime(UART_Type *UARTx)
{
    SET_BIT(UARTx->FFCR, UART_FFCR_BGTEN_Msk);
}

/**
  * @brief    Get U7816 Block Guard Time Enable Status
  * @rmtoll   FFR    BGTEN    FL_UART_IsEnabledU7816BlockGuardTime
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledU7816BlockGuardTime(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_BGTEN_Msk) == UART_FFCR_BGTEN_Msk);
}

/**
  * @brief    Disable U7816 to Insert Block Guard Time
  * @rmtoll   FFR    BGTEN    FL_UART_DisableU7816BlockGuardTime
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableU7816BlockGuardTime(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->FFCR, UART_FFCR_BGTEN_Msk);
}

/**
  * @brief    Set U7816 Retry Counts When Parity Error Occurred
  * @rmtoll   FFR    REP_T    FL_UART_SetU7816RetryCount
  * @param    UARTx UART instance
  * @param    cnt This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_RETRY_COUNT_1
  *           @arg @ref FL_UART_U7816_RETRY_COUNT_3
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816RetryCount(UART_Type *UARTx, uint32_t cnt)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_REP_T_Msk, cnt);
}

/**
  * @brief    Get U7816 Retry Counts When Parity Error Occurred
  * @rmtoll   FFR    REP_T    FL_UART_GetU7816RetryCount
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_RETRY_COUNT_1
  *           @arg @ref FL_UART_U7816_RETRY_COUNT_3
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816RetryCount(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_REP_T_Msk));
}

/**
  * @brief    Set U7816 Parity
  * @rmtoll   FFR    PAR    FL_UART_SetU7816Parity
  * @param    UARTx UART instance
  * @param    parity This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_PARITY_SEL_EVEN
  *           @arg @ref FL_UART_U7816_PARITY_SEL_ODD
  *           @arg @ref FL_UART_U7816_PARITY_SEL_ALWAYS_1
  *           @arg @ref FL_UART_U7816_PARITY_SEL_NONE
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816Parity(UART_Type *UARTx, uint32_t parity)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_PAR_Msk, parity);
}

/**
  * @brief    Get U7816 Parity
  * @rmtoll   FFR    PAR    FL_UART_GetU7816Parity
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_PARITY_SEL_EVEN
  *           @arg @ref FL_UART_U7816_PARITY_SEL_ODD
  *           @arg @ref FL_UART_U7816_PARITY_SEL_ALWAYS_1
  *           @arg @ref FL_UART_U7816_PARITY_SEL_NONE
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816Parity(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_PAR_Msk));
}

/**
  * @brief    Set U7816 RX Guard Time Length
  * @rmtoll   FFR    RFREN    FL_UART_SetU7816RXGuardTime
  * @param    UARTx UART instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_RX_GUARD_TIME_2ETU
  *           @arg @ref FL_UART_U7816_RX_GUARD_TIME_1ETU
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816RXGuardTime(UART_Type *UARTx, uint32_t config)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_RFREN_Msk, config);
}

/**
  * @brief    Get U7816 RX Guard Time Length
  * @rmtoll   FFR    RFREN    FL_UART_GetU7816RXGuardTime
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_RX_GUARD_TIME_2ETU
  *           @arg @ref FL_UART_U7816_RX_GUARD_TIME_1ETU
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816RXGuardTime(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_RFREN_Msk));
}

/**
  * @brief    Set U7816 TX Auto Retry When Parity Error Occurred
  * @rmtoll   FFR    TREPEN    FL_UART_EnableU7816TXParityErrorAutoRetry
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableU7816TXParityErrorAutoRetry(UART_Type *UARTx)
{
    SET_BIT(UARTx->FFCR, UART_FFCR_TREPEN_Msk);
}

/**
  * @brief    Get U7816 TX Auto Retry When Parity Error Occurred
  * @rmtoll   FFR    TREPEN    FL_UART_DisableU7816TXParityErrorAutoRetry
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableU7816TXParityErrorAutoRetry(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->FFCR, UART_FFCR_TREPEN_Msk);
}

/**
  * @brief    Get U7816 TX Auto Retry When Parity Error Occurred
  * @rmtoll   FFR    TREPEN    FL_UART_IsEnabledU7816TXParityErrorAutoRetry
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledU7816TXParityErrorAutoRetry(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_TREPEN_Msk) == UART_FFCR_TREPEN_Msk);
}

/**
  * @brief    Get U7816 RX Auto Retry When Parity Error Occurred
  * @rmtoll   FFR    RREPEN    FL_UART_EnableU7816RXParityErrorAutoRetry
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableU7816RXParityErrorAutoRetry(UART_Type *UARTx)
{
    SET_BIT(UARTx->FFCR, UART_FFCR_RREPEN_Msk);
}

/**
  * @brief    Get U7816 RX Auto Retry When Parity Error Occurred
  * @rmtoll   FFR    RREPEN    FL_UART_DisableU7816RXParityErrorAutoRetry
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableU7816RXParityErrorAutoRetry(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->FFCR, UART_FFCR_RREPEN_Msk);
}

/**
  * @brief    Get U7816 RX Auto Retry When Parity Error Occurred
  * @rmtoll   FFR    RREPEN    FL_UART_IsEnabledU7816RXParityErrorAutoRetry
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledU7816RXParityErrorAutoRetry(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_RREPEN_Msk) == UART_FFCR_RREPEN_Msk);
}

/**
  * @brief    Set U7816 Bit Order
  * @rmtoll   FFR    DICONV    FL_UART_SetU7816BitOrder
  * @param    UARTx UART instance
  * @param    order This parameter can be one of the following values:
  *           @arg @ref FL_UART_U7816_BIT_ORDER_LSB_FIRST
  *           @arg @ref FL_UART_U7816_BIT_ORDER_MSB_FIRST
  * @retval   None
  */
__STATIC_INLINE void FL_UART_SetU7816BitOrder(UART_Type *UARTx, uint32_t order)
{
    MODIFY_REG(UARTx->FFCR, UART_FFCR_DICONV_Msk, order);
}

/**
  * @brief    Get U7816 Bit Order
  * @rmtoll   FFR    DICONV    FL_UART_GetU7816BitOrder
  * @param    UARTx UART instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_UART_U7816_BIT_ORDER_LSB_FIRST
  *           @arg @ref FL_UART_U7816_BIT_ORDER_MSB_FIRST
  */
__STATIC_INLINE uint32_t FL_UART_GetU7816BitOrder(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->FFCR, UART_FFCR_DICONV_Msk));
}

/**
  * @brief    Set U7816 Extra Guard Time
  * @rmtoll   EGTR        FL_UART_WriteU7816ExtraGuardTime
  * @param    UARTx UART instance
  * @param    config
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteU7816ExtraGuardTime(UART_Type *UARTx, uint32_t config)
{
    MODIFY_REG(UARTx->EGTR, (0xffU << 0U), (config << 0U));
}

/**
  * @brief    Get U7816 Extra Guard Time
  * @rmtoll   EGTR        FL_UART_ReadU7816ExtraGuardTime
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadU7816ExtraGuardTime(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->EGTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set U7816 Clock Divide
  * @rmtoll   CODR        FL_UART_WriteU7816ClockDivision
  * @param    UARTx UART instance
  * @param    div
  * @retval   None
  */
__STATIC_INLINE void FL_UART_WriteU7816ClockDivision(UART_Type *UARTx, uint32_t div)
{
    MODIFY_REG(UARTx->CODR, (0x1fU << 0U), (div << 0U));
}

/**
  * @brief    Get U7816 Clock Divide
  * @rmtoll   CODR        FL_UART_ReadU7816ClockDivision
  * @param    UARTx UART instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_UART_ReadU7816ClockDivision(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->CODR, (0x1fU << 0U)) >> 0U);
}

/**
  * @brief    Disable U7816 Receive Complete Interrupt
  * @rmtoll   SCIER    RXIE    FL_UART_DisableIT_U7816RXComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_U7816RXComplete(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->SCIER, UART_SCIER_RXIE_Msk);
}

/**
  * @brief    Enable U7816 Receive Complete Interrupt
  * @rmtoll   SCIER    RXIE    FL_UART_EnableIT_U7816RXComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_U7816RXComplete(UART_Type *UARTx)
{
    SET_BIT(UARTx->SCIER, UART_SCIER_RXIE_Msk);
}

/**
  * @brief    Get U7816 Receive Complete Interrupt Enable Status
  * @rmtoll   SCIER    RXIE    FL_UART_IsEnabledIT_U7816RXComplete
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_U7816RXComplete(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCIER, UART_SCIER_RXIE_Msk) == UART_SCIER_RXIE_Msk);
}

/**
  * @brief    Disable U7816 Transmit Complete Interrupt
  * @rmtoll   SCIER    TXIE    FL_UART_DisableIT_U7816TXComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_U7816TXComplete(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->SCIER, UART_SCIER_TXSEIE_Msk);
}

/**
  * @brief    Enable U7816 Transmit Complete Interrupt
  * @rmtoll   SCIER    TXIE    FL_UART_EnableIT_U7816TXComplete
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_U7816TXComplete(UART_Type *UARTx)
{
    SET_BIT(UARTx->SCIER, UART_SCIER_TXSEIE_Msk);
}

/**
  * @brief    Disable U7816 Line Status Interrupt
  * @rmtoll   SCIER    LSIE    FL_UART_DisableIT_U7816Error
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_DisableIT_U7816Error(UART_Type *UARTx)
{
    CLEAR_BIT(UARTx->SCIER, UART_SCIER_LSIE_Msk);
}

/**
  * @brief    Enable U7816 Line Status Interrupt
  * @rmtoll   SCIER    LSIE    FL_UART_EnableIT_U7816Error
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_EnableIT_U7816Error(UART_Type *UARTx)
{
    SET_BIT(UARTx->SCIER, UART_SCIER_LSIE_Msk);
}

/**
  * @brief    Get U7816 Line Status Interrupt Enable Status
  * @rmtoll   SCIER    LSIE    FL_UART_IsEnabledIT_U7816Error
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsEnabledIT_U7816Error(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCIER, UART_SCIER_LSIE_Msk) == UART_SCIER_LSIE_Msk);
}

/**
  * @brief    Get U7816 Waiting for Retry Flag
  * @rmtoll   SCISR    WAIT_RPT    FL_UART_IsActiveFlag_U7816WaitRetry
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816WaitRetry(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_WAIT_RPT_Msk) == (UART_SCISR_WAIT_RPT_Msk));
}

/**
  * @brief    Get U7816 Transmission Busy Flag
  * @rmtoll   SCISR    TXBUSY    FL_UART_IsActiveFlag_U7816TXBusy
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816TXBusy(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_TXBUSY_Msk) == (UART_SCISR_TXBUSY_Msk));
}

/**
  * @brief    Get U7816 Receivement Busy Flag
  * @rmtoll   SCISR    RXBUSY    FL_UART_IsActiveFlag_U7816RXBusy
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816RXBusy(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_RXBUSY_Msk) == (UART_SCISR_RXBUSY_Msk));
}

/**
  * @brief    Get U7816 Transmit Parity Error Flag
  * @rmtoll   SCISR    TPARERR    FL_UART_IsActiveFlag_U7816TXParityError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816TXParityError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_TPARERR_Msk) == (UART_SCISR_TPARERR_Msk));
}

/**
  * @brief    Clear U7816 Transmit Parity Error Flag
  * @rmtoll   SCISR    TPARERR    FL_UART_ClearFlag_U7816TXParityError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_U7816TXParityError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->SCISR, UART_SCISR_TPARERR_Msk);
}

/**
  * @brief    Get U7816 Receive Parity Error Flag
  * @rmtoll   SCISR    RPARERR    FL_UART_IsActiveFlag_U7816RXParityError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816RXParityError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_RPARERR_Msk) == (UART_SCISR_RPARERR_Msk));
}

/**
  * @brief    Clear U7816 Receive Parity Error Flag
  * @rmtoll   SCISR    RPARERR    FL_UART_ClearFlag_U7816RXParityError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_U7816RXParityError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->SCISR, UART_SCISR_RPARERR_Msk);
}

/**
  * @brief    Get U7816 Receive Frame Error Flag
  * @rmtoll   SCISR    FRERR    FL_UART_IsActiveFlag_U7816RXFrameError
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816RXFrameError(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_FRERR_Msk) == (UART_SCISR_FRERR_Msk));
}

/**
  * @brief    Clear U7816 Receive Frame Error Flag
  * @rmtoll   SCISR    FRERR    FL_UART_ClearFlag_U7816RXFrameError
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_U7816RXFrameError(UART_Type *UARTx)
{
    WRITE_REG(UARTx->SCISR, UART_SCISR_FRERR_Msk);
}

/**
  * @brief    Get U7816 Receive Overflow Error Flag
  * @rmtoll   SCISR    OVERR    FL_UART_IsActiveFlag_U7816RXOverflow
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816RXOverflow(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_OVERR_Msk) == (UART_SCISR_OVERR_Msk));
}

/**
  * @brief    Clear U7816 Receive Overflow Error Flag
  * @rmtoll   SCISR    OVERR    FL_UART_ClearFlag_U7816RXOverflow
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_U7816RXOverflow(UART_Type *UARTx)
{
    WRITE_REG(UARTx->SCISR, UART_SCISR_OVERR_Msk);
}

/**
  * @brief    Get U7816 Transmit Shift register Empty  Flag
  * @rmtoll   SCISR    TXSE    FL_UART_IsActiveFlag_U7816TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816TXShiftBuffEmpty(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->ISR, UART_SCISR_TXSE_Msk) == (UART_SCISR_TXSE_Msk));
}

/**
  * @brief    Clear U7816 Transmit Shift register Empty Flag
  * @rmtoll   SCISR    TXSE    FL_UART_ClearFlag_U7816TXShiftBuffEmpty
  * @param    UARTx UART instance
  * @retval   None
  */
__STATIC_INLINE void FL_UART_ClearFlag_U7816TXShiftBuffEmpty(UART_Type *UARTx)
{
    WRITE_REG(UARTx->ISR, UART_SCISR_TXSE_Msk);
}


/**
  * @brief    Get U7816 Receive Complete Flag
  * @rmtoll   SCISR    RXIF    FL_UART_IsActiveFlag_U7816RXComplete
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816RXComplete(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_RXIF_Msk) == (UART_SCISR_RXIF_Msk));
}

/**
  * @brief    Get U7816 Transmit Buffer Empty Flag
  * @rmtoll   SCISR    TXIF    FL_UART_IsActiveFlag_U7816TXBuffEmpty
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816TXBuffEmpty(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_TXIF_Msk) == (UART_SCISR_TXIF_Msk));
}

/**
  * @brief    Get U7816 Error Flag
  * @rmtoll   SCISR    ERRIF    FL_UART_IsActiveFlag_U7816Error
  * @param    UARTx UART instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_UART_IsActiveFlag_U7816Error(UART_Type *UARTx)
{
    return (uint32_t)(READ_BIT(UARTx->SCISR, UART_SCISR_ERRIF_Msk) == (UART_SCISR_ERRIF_Msk));
}

/**
  * @}
  */

/** @defgroup UART_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_UART_DeInit(UART_Type *UARTx);
FL_ErrorStatus FL_UART_Init(UART_Type *UARTx, FL_UART_InitTypeDef *initStruct);
FL_ErrorStatus FL_UART_InfraRed_Init(UART_Type *UARTx, FL_UART_InfraRed_InitTypeDef *initStruct);
void FL_UART_InfraRed_StructInit(FL_UART_InfraRed_InitTypeDef *initStruct);
void FL_UART_StructInit(FL_UART_InitTypeDef *initStruct);

FL_ErrorStatus FL_U7816_DeInit(UART_Type *UARTx);
FL_ErrorStatus FL_U7816_Init(UART_Type *UARTx, FL_UART_U7816_InitTypeDef *U7816_InitStruct);
void FL_U7816_StructInit(FL_UART_U7816_InitTypeDef *U7816_InitStruct);
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_UART_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-08-04*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
