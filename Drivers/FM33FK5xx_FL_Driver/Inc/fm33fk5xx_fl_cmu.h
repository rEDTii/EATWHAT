/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_cmu.h
  * @author  FMSH Application Team
  * @brief   Head file of CMU FL Module
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
#ifndef __FM33FK5XX_FL_CMU_H
#define __FM33FK5XX_FL_CMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_ES_INIT CMU Exported Init structures
  * @{
  */

/**
  * @brief FL CMU Init Sturcture definition
  */
typedef enum
{
    FL_SYSTEM_CLOCK_RCHF_8M = 0,
    FL_SYSTEM_CLOCK_RCHF_16M,
    FL_SYSTEM_CLOCK_RCHF_24M,
    FL_SYSTEM_CLOCK_PLL_RCHF_32M,
    FL_SYSTEM_CLOCK_PLL_RCHF_48M,
    FL_SYSTEM_CLOCK_PLL_RCHF_64M,
    FL_SYSTEM_CLOCK_PLL_RCHF_80M,
    FL_SYSTEM_CLOCK_RCLP,
    FL_SYSTEM_CLOCK_XTHF,
    FL_SYSTEM_CLOCK_USB,
} FL_SystemClock;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_Exported_Constants CMU Exported Constants
  * @{
  */

#define    CMU_SYSCLKCR_SLP_ENEXTI_Pos                                (25U)
#define    CMU_SYSCLKCR_SLP_ENEXTI_Msk                                (0x1U << CMU_SYSCLKCR_SLP_ENEXTI_Pos)
#define    CMU_SYSCLKCR_SLP_ENEXTI                                    CMU_SYSCLKCR_SLP_ENEXTI_Msk

#define    CMU_SYSCLKCR_APB2PRES_Pos                                  (19U)
#define    CMU_SYSCLKCR_APB2PRES_Msk                                  (0x7U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    CMU_SYSCLKCR_APB2PRES                                      CMU_SYSCLKCR_APB2PRES_Msk

#define    CMU_SYSCLKCR_APB1PRES_Pos                                  (16U)
#define    CMU_SYSCLKCR_APB1PRES_Msk                                  (0x7U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    CMU_SYSCLKCR_APB1PRES                                      CMU_SYSCLKCR_APB1PRES_Msk

#define    CMU_SYSCLKCR_USBCLOKSEL_Pos                                (14U)
#define    CMU_SYSCLKCR_USBCLOKSEL_Msk                                (0x3U << CMU_SYSCLKCR_USBCLOKSEL_Pos)
#define    CMU_SYSCLKCR_USBCLOKSEL                                    CMU_SYSCLKCR_USBCLOKSEL_Msk

#define    CMU_SYSCLKCR_AHBPRES_Pos                                   (8U)
#define    CMU_SYSCLKCR_AHBPRES_Msk                                   (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    CMU_SYSCLKCR_AHBPRES                                       CMU_SYSCLKCR_AHBPRES_Msk

#define    CMU_SYSCLKCR_STCLKSEL_Pos                                  (6U)
#define    CMU_SYSCLKCR_STCLKSEL_Msk                                  (0x3U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    CMU_SYSCLKCR_STCLKSEL                                      CMU_SYSCLKCR_STCLKSEL_Msk

#define    CMU_SYSCLKCR_BCKREFCKS_Pos                                 (5U)
#define    CMU_SYSCLKCR_BCKREFCKS_Msk                                 (0x1U << CMU_SYSCLKCR_BCKREFCKS_Pos)
#define    CMU_SYSCLKCR_BCKREFCKS                                     CMU_SYSCLKCR_BCKREFCKS_Msk

#define    CMU_SYSCLKCR_BCKPRES_Pos                                   (3U)
#define    CMU_SYSCLKCR_BCKPRES_Msk                                   (0x3U << CMU_SYSCLKCR_BCKPRES_Pos)
#define    CMU_SYSCLKCR_BCKPRES                                       CMU_SYSCLKCR_BCKPRES_Msk

#define    CMU_SYSCLKCR_SYSCLKSEL_Pos                                 (0U)
#define    CMU_SYSCLKCR_SYSCLKSEL_Msk                                 (0x7U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    CMU_SYSCLKCR_SYSCLKSEL                                     CMU_SYSCLKCR_SYSCLKSEL_Msk

#define    CMU_RCHFCR_FSEL_Pos                                    (16U)
#define    CMU_RCHFCR_FSEL_Msk                                    (0xfU << CMU_RCHFCR_FSEL_Pos)
#define    CMU_RCHFCR_FSEL                                        CMU_RCHFCR_FSEL_Msk

#define    CMU_RCHFCR_EN_Pos                                      (0U)
#define    CMU_RCHFCR_EN_Msk                                      (0x1U << CMU_RCHFCR_EN_Pos)
#define    CMU_RCHFCR_EN                                          CMU_RCHFCR_EN_Msk

#define    CMU_RCHFTR_TRIM_Pos                                    (0U)
#define    CMU_RCHFTR_TRIM_Msk                                    (0xffU << CMU_RCHFTR_TRIM_Pos)
#define    CMU_RCHFTR_TRIM                                        CMU_RCHFTR_TRIM_Msk

#define    CMU_PLLCR_DB_Pos                                       (16U)
#define    CMU_PLLCR_DB_Msk                                       (0x7fU << CMU_PLLCR_DB_Pos)
#define    CMU_PLLCR_DB                                           CMU_PLLCR_DB_Msk

#define    CMU_PLLCR_LOCKED_Pos                                   (7U)
#define    CMU_PLLCR_LOCKED_Msk                                   (0x1U << CMU_PLLCR_LOCKED_Pos)
#define    CMU_PLLCR_LOCKED                                       CMU_PLLCR_LOCKED_Msk

#define    CMU_PLLCR_REFPRSC_Pos                                  (4U)
#define    CMU_PLLCR_REFPRSC_Msk                                  (0x7U << CMU_PLLCR_REFPRSC_Pos)
#define    CMU_PLLCR_REFPRSC                                      CMU_PLLCR_REFPRSC_Msk

#define    CMU_PLLCR_INSEL_Pos                                    (1U)
#define    CMU_PLLCR_INSEL_Msk                                    (0x3U << CMU_PLLCR_INSEL_Pos)
#define    CMU_PLLCR_INSEL                                        CMU_PLLCR_INSEL_Msk

#define    CMU_PLLCR_EN_Pos                                       (0U)
#define    CMU_PLLCR_EN_Msk                                       (0x1U << CMU_PLLCR_EN_Pos)
#define    CMU_PLLCR_EN                                           CMU_PLLCR_EN_Msk

#define    CMU_RCLPCR_ENB_Pos                                     (0U)
#define    CMU_RCLPCR_ENB_Msk                                     (0x1U << CMU_RCLPCR_ENB_Pos)
#define    CMU_RCLPCR_ENB                                         CMU_RCLPCR_ENB_Msk

#define    CMU_RCLPTR_TRIM_Pos                                    (0U)
#define    CMU_RCLPTR_TRIM_Msk                                    (0xffU << CMU_RCLPTR_TRIM_Pos)
#define    CMU_RCLPTR_TRIM                                        CMU_RCLPTR_TRIM_Msk

#define    CMU_XTHFCR_WAIT_Pos                                    (13U)
#define    CMU_XTHFCR_WAIT_Msk                                    (0x7U << CMU_XTHFCR_WAIT_Pos)
#define    CMU_XTHFCR_WAIT                                        CMU_XTHFCR_WAIT_Msk

#define    CMU_XTHFCR_CFG_Pos                                     (8U)
#define    CMU_XTHFCR_CFG_Msk                                     (0x1fU << CMU_XTHFCR_CFG_Pos)
#define    CMU_XTHFCR_CFG                                         CMU_XTHFCR_CFG_Msk

#define    CMU_XTHFCR_BYPASS_Pos                                  (4U)
#define    CMU_XTHFCR_BYPASS_Msk                                  (0x1U << CMU_XTHFCR_BYPASS_Pos)
#define    CMU_XTHFCR_BYPASS                                      CMU_XTHFCR_BYPASS_Msk

#define    CMU_XTHFCR_RDY_Pos                                     (1U)
#define    CMU_XTHFCR_RDY_Msk                                     (0x1U << CMU_XTHFCR_RDY_Pos)
#define    CMU_XTHFCR_RDY                                         CMU_XTHFCR_RDY_Msk

#define    CMU_XTHFCR_EN_Pos                                      (0U)
#define    CMU_XTHFCR_EN_Msk                                      (0x1U << CMU_XTHFCR_EN_Pos)
#define    CMU_XTHFCR_EN                                          CMU_XTHFCR_EN_Msk

#define    CMU_IER_SYSCSE_IE_Pos                                  (2U)
#define    CMU_IER_SYSCSE_IE_Msk                                  (0x1U << CMU_IER_SYSCSE_IE_Pos)
#define    CMU_IER_SYSCSE_IE                                       CMU_IER_SYSCSE_IE_Msk

#define    CMU_IER_HFDET_IE_Pos                                   (1U)
#define    CMU_IER_HFDET_IE_Msk                                   (0x1U << CMU_IER_HFDET_IE_Pos)
#define    CMU_IER_HFDET_IE                                       CMU_IER_HFDET_IE_Msk

#define    CMU_ISR_HFDETO_Pos                                     (9U)
#define    CMU_ISR_HFDETO_Msk                                     (0x1U << CMU_ISR_HFDETO_Pos)
#define    CMU_ISR_HFDETO                                         CMU_ISR_HFDETO_Msk

#define    CMU_ISR_SYSCSE_IF_Pos                                  (2U)
#define    CMU_ISR_SYSCSE_IF_Msk                                  (0x1U << CMU_ISR_SYSCSE_IF_Pos)
#define    CMU_ISR_SYSCSE_IF                                      CMU_ISR_SYSCSE_IF_Msk

#define    CMU_ISR_HFDET_IF_Pos                                   (1U)
#define    CMU_ISR_HFDET_IF_Msk                                   (0x1U << CMU_ISR_HFDET_IF_Pos)
#define    CMU_ISR_HFDET_IF                                       CMU_ISR_HFDET_IF_Msk

#define    CMU_OPCCR1_EXTICKS_Pos                                 (30U)
#define    CMU_OPCCR1_EXTICKS_Msk                                 (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    CMU_OPCCR1_EXTICKS                                     CMU_OPCCR1_EXTICKS_Msk

#define    CMU_OPCCR1_LINCKS_Pos                                 (30U)
#define    CMU_OPCCR1_LINCKS_Msk                                 (0x1U << CMU_OPCCR1_LINCKS_Pos)
#define    CMU_OPCCR1_LINCKS                                      CMU_OPCCR1_LINCKS_Msk

#define    CMU_OPCCR1_LPUART1CKS_Pos                              (26U)
#define    CMU_OPCCR1_LPUART1CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    CMU_OPCCR1_LPUART1CKS                                  CMU_OPCCR1_LPUART1CKS_Msk

#define    CMU_OPCCR1_LPUART0CKS_Pos                              (24U)
#define    CMU_OPCCR1_LPUART0CKS_Msk                              (0x3U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    CMU_OPCCR1_LPUART0CKS                                  CMU_OPCCR1_LPUART0CKS_Msk

#define    CMU_OPCCR1_I2CSMB2_Pos                                 (20U)
#define    CMU_OPCCR1_I2CSMB2_Msk                                 (0x3U << CMU_OPCCR1_I2CSMB2_Pos)
#define    CMU_OPCCR1_I2CSMB2                                     CMU_OPCCR1_I2CSMB2_Msk

#define    CMU_OPCCR1_I2CSMB1_Pos                                 (18U)
#define    CMU_OPCCR1_I2CSMB1_Msk                                 (0x3U << CMU_OPCCR1_I2CSMB1_Pos)
#define    CMU_OPCCR1_I2CSMB1                                     CMU_OPCCR1_I2CSMB1_Msk

#define    CMU_OPCCR1_I2CSMB0_Pos                                 (16U)
#define    CMU_OPCCR1_I2CSMB0_Msk                                 (0x3U << CMU_OPCCR1_I2CSMB0_Pos)
#define    CMU_OPCCR1_I2CSMB0                                     CMU_OPCCR1_I2CSMB0_Msk

#define    CMU_OPCCR1_BT16CKS_Pos                                 (14U)
#define    CMU_OPCCR1_BT16CKS_Msk                                 (0x3U << CMU_OPCCR1_BT16CKS_Pos)
#define    CMU_OPCCR1_BT16CKS                                     CMU_OPCCR1_BT16CKS_Msk

#define    CMU_OPCCR1_UART3CKS_Pos                                (12U)
#define    CMU_OPCCR1_UART3CKS_Msk                                (0x3U << CMU_OPCCR1_UART3CKS_Pos)
#define    CMU_OPCCR1_UART3CKS                                    CMU_OPCCR1_UART3CKS_Msk

#define    CMU_OPCCR1_LPT16CKS_Pos                                (10U)
#define    CMU_OPCCR1_LPT16CKS_Msk                                (0x3U << CMU_OPCCR1_LPT16CKS_Pos)
#define    CMU_OPCCR1_LPT16CKS                                    CMU_OPCCR1_LPT16CKS_Msk

#define    CMU_OPCCR1_UART2CKS_Pos                                (8U)
#define    CMU_OPCCR1_UART2CKS_Msk                                (0x3U << CMU_OPCCR1_UART2CKS_Pos)
#define    CMU_OPCCR1_UART2CKS                                    CMU_OPCCR1_UART2CKS_Msk

#define    CMU_OPCCR1_AT1CKS_Pos                                  (6U)
#define    CMU_OPCCR1_AT1CKS_Msk                                  (0x3U << CMU_OPCCR1_AT1CKS_Pos)
#define    CMU_OPCCR1_AT1CKS                                      CMU_OPCCR1_AT1CKS_Msk

#define    CMU_OPCCR1_AT0CKS_Pos                                  (4U)
#define    CMU_OPCCR1_AT0CKS_Msk                                  (0x3U << CMU_OPCCR1_AT0CKS_Pos)
#define    CMU_OPCCR1_AT0CKS                                      CMU_OPCCR1_AT0CKS_Msk

#define    CMU_OPCCR1_UART1CKS_Pos                                (2U)
#define    CMU_OPCCR1_UART1CKS_Msk                                (0x3U << CMU_OPCCR1_UART1CKS_Pos)
#define    CMU_OPCCR1_UART1CKS                                    CMU_OPCCR1_UART1CKS_Msk

#define    CMU_OPCCR1_UART0CKS_Pos                                (0U)
#define    CMU_OPCCR1_UART0CKS_Msk                                (0x3U << CMU_OPCCR1_UART0CKS_Pos)
#define    CMU_OPCCR1_UART0CKS                                    CMU_OPCCR1_UART0CKS_Msk

#define    CMU_OPCCR2_EPWM3CKS_Pos                                (30U)
#define    CMU_OPCCR2_EPWM3CKS_Msk                                (0x3U << CMU_OPCCR2_EPWM3CKS_Pos)
#define    CMU_OPCCR2_EPWM3CKS                                    CMU_OPCCR2_EPWM3CKS_Msk

#define    CMU_OPCCR2_EPWM2CKS_Pos                                (28U)
#define    CMU_OPCCR2_EPWM2CKS_Msk                                (0x3U << CMU_OPCCR2_EPWM2CKS_Pos)
#define    CMU_OPCCR2_EPWM2CKS                                    CMU_OPCCR2_EPWM2CKS_Msk

#define    CMU_OPCCR1_EPWM1CKS_Pos                                (26U)
#define    CMU_OPCCR1_EPWM1CKS_Msk                                (0x3U << CMU_OPCCR1_EPWM1CKS_Pos)
#define    CMU_OPCCR1_EPWM1CKS                                    CMU_OPCCR1_EPWM1CKS_Msk

#define    CMU_OPCCR2_EPWM0CKS_Pos                                (24U)
#define    CMU_OPCCR2_EPWM0CKS_Msk                                (0x3U << CMU_OPCCR2_EPWM0CKS_Pos)
#define    CMU_OPCCR2_EPWM0CKS                                    CMU_OPCCR2_EPWM0CKS_Msk

#define    CMU_OPCCR2_FDCANCKS_Pos                                (18U)
#define    CMU_OPCCR2_FDCANCKS_Msk                                (0x3U << CMU_OPCCR2_FDCANCKS_Pos)
#define    CMU_OPCCR2_FDCANCKS                                    CMU_OPCCR2_FDCANCKS_Msk

#define    CMU_OPCCR2_FSCANCKS_Pos                                (16U)
#define    CMU_OPCCR2_FSCANCKS_Msk                                (0x3U << CMU_OPCCR2_FSCANCKS_Pos)
#define    CMU_OPCCR2_FSCANCKS                                    CMU_OPCCR2_FSCANCKS_Msk

#define    CMU_OPCCR2_RNGPRSC_Pos                                 (10U)
#define    CMU_OPCCR2_RNGPRSC_Msk                                 (0x7U << CMU_OPCCR2_RNGPRSC_Pos)
#define    CMU_OPCCR2_RNGPRSC                                     CMU_OPCCR2_RNGPRSC_Msk

#define    CMU_OPCCR2_ADCPRSC_Pos                                 (2U)
#define    CMU_OPCCR2_ADCPRSC_Msk                                 (0x7U << CMU_OPCCR2_ADCPRSC_Pos)
#define    CMU_OPCCR2_ADCPRSC                                     CMU_OPCCR2_ADCPRSC_Msk

#define    CMU_OPCCR2_ADCCKS_Pos                                  (0U)
#define    CMU_OPCCR2_ADCCKS_Msk                                  (0x3U << CMU_OPCCR2_ADCCKS_Pos)
#define    CMU_OPCCR2_ADCCKS                                      CMU_OPCCR2_ADCCKS_Msk


#define    CMU_CCCR_IE_Pos                                        (1U)
#define    CMU_CCCR_IE_Msk                                        (0x1U << CMU_CCCR_IE_Pos)
#define    CMU_CCCR_IE                                            CMU_CCCR_IE_Msk

#define    CMU_CCCR_EN_Pos                                        (0U)
#define    CMU_CCCR_EN_Msk                                        (0x1U << CMU_CCCR_EN_Pos)
#define    CMU_CCCR_EN                                            CMU_CCCR_EN_Msk

#define    CMU_CCFR_CALPSC_Pos                                    (10U)
#define    CMU_CCFR_CALPSC_Msk                                    (0x3U << CMU_CCFR_CALPSC_Pos)
#define    CMU_CCFR_CALPSC                                        CMU_CCFR_CALPSC_Msk

#define    CMU_CCFR_REFPSC_Pos                                    (8U)
#define    CMU_CCFR_REFPSC_Msk                                    (0x3U << CMU_CCFR_REFPSC_Pos)
#define    CMU_CCFR_REFPSC                                        CMU_CCFR_REFPSC_Msk

#define    CMU_CCFR_CALSEL_Pos                                    (1U)
#define    CMU_CCFR_CALSEL_Msk                                    (0x3U << CMU_CCFR_CALSEL_Pos)
#define    CMU_CCFR_CALSEL                                        CMU_CCFR_CALSEL_Msk

#define    CMU_CCFR_REFSEL_Pos                                    (0U)
#define    CMU_CCFR_REFSEL_Msk                                    (0x1U << CMU_CCFR_REFSEL_Pos)
#define    CMU_CCFR_REFSEL                                        CMU_CCFR_REFSEL_Msk

#define    CMU_CCNR_CNT_Pos                                       (0U)
#define    CMU_CCNR_CNT_Msk                                       (0xffffU << CMU_CCNR_CNT_Pos)
#define    CMU_CCNR_CNT                                           CMU_CCNR_CNT_Msk

#define    CMU_CCISR_IF_Pos                                       (0U)
#define    CMU_CCISR_IF_Msk                                       (0x1U << CMU_CCISR_IF_Pos)
#define    CMU_CCISR_IF                                           CMU_CCISR_IF_Msk

#define    FL_CMU_GROUP1_BUSCLK_LPTIM16                           (0x1U << 0U)
#define    FL_CMU_GROUP1_BUSCLK_USB                               (0x1U << 1U)
#define    FL_CMU_GROUP1_BUSCLK_PMU                               (0x1U << 3U)
#define    FL_CMU_GROUP1_BUSCLK_SCU                               (0x1U << 4U)
#define    FL_CMU_GROUP1_BUSCLK_IWDT                              (0x1U << 5U)
#define    FL_CMU_GROUP1_BUSCLK_ANAC                              (0x1U << 6U)
#define    FL_CMU_GROUP1_BUSCLK_PAD                               (0x1U << 7U)
#define    FL_CMU_GROUP1_BUSCLK_SVD                               (0x1U << 8U)
#define    FL_CMU_GROUP1_BUSCLK_COMP                              (0x1U << 9U)
#define    FL_CMU_GROUP2_BUSCLK_CRC                               (0x1U << 0U)
#define    FL_CMU_GROUP2_BUSCLK_RNG                               (0x1U << 1U)
#define    FL_CMU_GROUP2_BUSCLK_AES                               (0x1U << 2U)
#define    FL_CMU_GROUP2_BUSCLK_DMA                               (0x1U << 4U)
#define    FL_CMU_GROUP2_BUSCLK_FLASH                             (0x1U << 5U)
#define    FL_CMU_GROUP2_BUSCLK_RAMBIST                           (0x1U << 6U)
#define    FL_CMU_GROUP2_BUSCLK_WWDT                              (0x1U << 7U)
#define    FL_CMU_GROUP2_BUSCLK_ADC                               (0x1U << 8U)
#define    FL_CMU_GROUP2_BUSCLK_DAC                               (0x1U << 9U)
#define    FL_CMU_GROUP2_BUSCLK_OPA                               (0x1U << 10U)
#define    FL_CMU_GROUP2_BUSCLK_PGL                               (0x1U << 11U)
#define    FL_CMU_GROUP3_BUSCLK_SPI0                              (0x1U << 0U)
#define    FL_CMU_GROUP3_BUSCLK_SPI1                              (0x1U << 1U)
#define    FL_CMU_GROUP3_BUSCLK_SPI2                              (0x1U << 2U)
#define    FL_CMU_GROUP3_BUSCLK_SPI3                              (0x1U << 3U)
#define    FL_CMU_GROUP3_BUSCLK_SPI4                              (0x1U << 4U)
#define    FL_CMU_GROUP3_BUSCLK_EPSC                              (0x1U << 6U)
#define    FL_CMU_GROUP3_BUSCLK_UART0                             (0x1U << 8U)
#define    FL_CMU_GROUP3_BUSCLK_UART1                             (0x1U << 9U)
#define    FL_CMU_GROUP3_BUSCLK_UART2                             (0x1U << 10U)
#define    FL_CMU_GROUP3_BUSCLK_UART3                             (0x1U << 11U)
#define    FL_CMU_GROUP3_BUSCLK_UART4                             (0x1U << 12U)
#define    FL_CMU_GROUP3_BUSCLK_UART5                             (0x1U << 13U)
#define    FL_CMU_GROUP3_BUSCLK_UART6                             (0x1U << 14U)
#define    FL_CMU_GROUP3_BUSCLK_UART7                             (0x1U << 15U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART0                           (0x1U << 16U)
#define    FL_CMU_GROUP3_BUSCLK_LPUART1                           (0x1U << 17U)
#define    FL_CMU_GROUP3_BUSCLK_FSCAN                             (0x1U << 19U)
#define    FL_CMU_GROUP3_BUSCLK_FDCAN                             (0x1U << 20U)
#define    FL_CMU_GROUP3_BUSCLK_UCIR                              (0x1U << 23U)
#define    FL_CMU_GROUP3_BUSCLK_I2C0                              (0x1U << 24U)
#define    FL_CMU_GROUP3_BUSCLK_I2C1                              (0x1U << 25U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB0                           (0x1U << 28U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB1                           (0x1U << 29U)
#define    FL_CMU_GROUP3_BUSCLK_I2CSMB2                           (0x1U << 30U)
#define    FL_CMU_GROUP4_BUSCLK_GTIM0                             (0x1U << 1U)
#define    FL_CMU_GROUP4_BUSCLK_GTIM1                             (0x1U << 2U)
#define    FL_CMU_GROUP4_BUSCLK_GTIM2                             (0x1U << 3U)
#define    FL_CMU_GROUP4_BUSCLK_ATIM0                             (0x1U << 4U)
#define    FL_CMU_GROUP4_BUSCLK_ATIM1                             (0x1U << 5U)
#define    FL_CMU_GROUP4_BUSCLK_BSTIM16                           (0x1U << 8U)
#define    FL_CMU_GROUP4_BUSCLK_EPWM                             (0x1U << 16U)
#define    FL_CMU_OPCLK_EXTI                                      (0x1U << 31U)
#define    FL_CMU_OPCLK_FLASH                                     (0x1U << 30U)
#define    FL_CMU_OPCLK_LPUART1                                   (0x1U << 29U)
#define    FL_CMU_OPCLK_LPUART0                                   (0x1U << 28U)
#define    FL_CMU_OPCLK_RNG                                       (0x1U << 24U)
#define    FL_CMU_OPCLK_I2CSMB2                                   (0x1U << 22U)
#define    FL_CMU_OPCLK_I2CSMB1                                   (0x1U << 21U)
#define    FL_CMU_OPCLK_I2CSMB0                                   (0x1U << 20U)
#define    FL_CMU_OPCLK_ADC                                       (0x1U << 16U)
#define    FL_CMU_OPCLK_ATIM1                                     (0x1U << 15U)
#define    FL_CMU_OPCLK_ATIM0                                     (0x1U << 14U)
#define    FL_CMU_OPCLK_UART3                                     (0x1U << 7U)
#define    FL_CMU_OPCLK_UART2                                     (0x1U << 6U)
#define    FL_CMU_OPCLK_UART1                                     (0x1U << 5U)
#define    FL_CMU_OPCLK_UART0                                     (0x1U << 4U)
#define    FL_CMU_OPCLK_BSTIM16                                   (0x1U << 3U)
#define    FL_CMU_OPCLK_LPTIM16                                   (0x1U << 1U)
#define    FL_CMU_OPCLK_EPWM0                                     (0x1U << 0U)
#define    FL_CMU_OPCLK_EPWM1                                     (0x1U << 1U)
#define    FL_CMU_OPCLK_EPWM2                                     (0x1U << 2U)
#define    FL_CMU_OPCLK_EPWM3                                     (0x1U << 3U)
#define    FL_CMU_OPCLK_FSCAN                                     (0x1U << 8U)
#define    FL_CMU_OPCLK_FDCAN                                     (0x1U << 9U)

#define    FL_CMU_APB2CLK_PSC_DIV2                                (0x0U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV4                                (0x5U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV8                                (0x6U << CMU_SYSCLKCR_APB2PRES_Pos)
#define    FL_CMU_APB2CLK_PSC_DIV16                               (0x7U << CMU_SYSCLKCR_APB2PRES_Pos)

#define    FL_CMU_APB1CLK_PSC_DIV1                                (0x0U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV2                                (0x4U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV4                                (0x5U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV8                                (0x6U << CMU_SYSCLKCR_APB1PRES_Pos)
#define    FL_CMU_APB1CLK_PSC_DIV16                               (0x7U << CMU_SYSCLKCR_APB1PRES_Pos)

#define    FL_CMU_USB_CLK_OUT_48M                                 (0x0U << CMU_SYSCLKCR_USBCLOKSEL_Pos)
#define    FL_CMU_USB_CLK_OUT_96M                                 (0x1U << CMU_SYSCLKCR_USBCLOKSEL_Pos)
#define    FL_CMU_USB_CLK_OUT_120M                                (0x2U << CMU_SYSCLKCR_USBCLOKSEL_Pos)
#define    FL_CMU_USB_CLK_OUT_240M                                (0x3U << CMU_SYSCLKCR_USBCLOKSEL_Pos)

#define    FL_CMU_AHBCLK_PSC_DIV1                                 (0x0U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV2                                 (0x4U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV4                                 (0x5U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV8                                 (0x6U << CMU_SYSCLKCR_AHBPRES_Pos)
#define    FL_CMU_AHBCLK_PSC_DIV16                                (0x7U << CMU_SYSCLKCR_AHBPRES_Pos)

#define    FL_CMU_SYSTICK_CLK_SOURCE_AHB_DIV8                     (0x0U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_XTLF                         (0x1U << CMU_SYSCLKCR_STCLKSEL_Pos)
#define    FL_CMU_SYSTICK_CLK_SOURCE_RCLP                         (0x2U << CMU_SYSCLKCR_STCLKSEL_Pos)

#define    FL_CMU_USB_REF_CLK_XTLF                                (0x0U << CMU_SYSCLKCR_BCKREFCKS_Pos)
#define    FL_CMU_USB_REF_CLK_XTHF                                (0x1U << CMU_SYSCLKCR_BCKREFCKS_Pos)

#define    FL_CMU_USB_CLK_PSC_DIV1                                (0x0U << CMU_SYSCLKCR_BCKPRES_Pos)
#define    FL_CMU_USB_CLK_PSC_DIV2                                (0x1U << CMU_SYSCLKCR_BCKPRES_Pos)
#define    FL_CMU_USB_CLK_PSC_DIV4                                (0x2U << CMU_SYSCLKCR_BCKPRES_Pos)
#define    FL_CMU_USB_CLK_PSC_DIV8                                (0x3U << CMU_SYSCLKCR_BCKPRES_Pos)

#define    FL_CMU_SYSTEM_CLK_SOURCE_RCHF                          (0x0U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_XTHF                          (0x1U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_PLL                           (0x3U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_PLL_VC0                       (0x5U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_RCLP                          (0x6U << CMU_SYSCLKCR_SYSCLKSEL_Pos)
#define    FL_CMU_SYSTEM_CLK_SOURCE_USB_BCK_PSC                   (0x7U << CMU_SYSCLKCR_SYSCLKSEL_Pos)

#define    FL_CMU_RCHF_FREQUENCY_8MHZ                             (0x0U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_16MHZ                            (0x1U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_24MHZ                            (0x2U << CMU_RCHFCR_FSEL_Pos)
#define    FL_CMU_RCHF_FREQUENCY_32MHZ                            (0x3U << CMU_RCHFCR_FSEL_Pos)

#define    FL_CMU_PLL_PSC_DIV1                                    (0x0U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV2                                    (0x1U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV4                                    (0x2U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV8                                    (0x3U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV12                                   (0x4U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV16                                   (0x5U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV24                                   (0x6U << CMU_PLLCR_REFPRSC_Pos)
#define    FL_CMU_PLL_PSC_DIV32                                   (0x7U << CMU_PLLCR_REFPRSC_Pos)

#define    FL_CMU_PLL_CLK_SOURCE_RCHF                             (0x0U << CMU_PLLCR_INSEL_Pos)
#define    FL_CMU_PLL_CLK_SOURCE_XTHF                             (0x1U << CMU_PLLCR_INSEL_Pos)

#define    FL_CMU_XTHF_START_WAIT_CYCLE_128                       (0x0U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_256                       (0x1U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_512                       (0x2U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_1024                      (0x3U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_2048                      (0x4U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_4096                      (0x5U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_8192                      (0x6U << CMU_XTHFCR_WAIT_Pos)
#define    FL_CMU_XTHF_START_WAIT_CYCLE_16384                     (0x7U << CMU_XTHFCR_WAIT_Pos)

#define    FL_CMU_EXTI_CLK_SOURCE_RCLP                            (0x1U << CMU_OPCCR1_EXTICKS_Pos)
#define    FL_CMU_EXTI_CLK_SOURCE_HCLK                            (0x0U << CMU_OPCCR1_EXTICKS_Pos)

#define    FL_CMU_LINWKUP_CLK_SOURCE_RCLP                         (0x1U << CMU_OPCCR1_LINCKS_Pos)
#define    FL_CMU_LINWKUP_CLK_SOURCE_XTLF                         (0x0U << CMU_OPCCR1_LINCKS_Pos)

#define    FL_CMU_LPUART1_CLK_SOURCE_XTLF                         (0x0U << CMU_OPCCR1_LPUART1CKS_Pos)
#define    FL_CMU_LPUART1_CLK_SOURCE_RCHF_PSC                     (0x1U << CMU_OPCCR1_LPUART1CKS_Pos)

#define    FL_CMU_LPUART0_CLK_SOURCE_XTLF                         (0x0U << CMU_OPCCR1_LPUART0CKS_Pos)
#define    FL_CMU_LPUART0_CLK_SOURCE_RCHF_PSC                     (0x1U << CMU_OPCCR1_LPUART0CKS_Pos)

#define    FL_CMU_I2CSMB2_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB2_Pos)
#define    FL_CMU_I2CSMB2_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB2_Pos)
#define    FL_CMU_I2CSMB2_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB2_Pos)

#define    FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB1_Pos)
#define    FL_CMU_I2CSMB1_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB1_Pos)
#define    FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB1_Pos)

#define    FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_I2CSMB0_Pos)
#define    FL_CMU_I2CSMB0_CLK_SOURCE_RCHF                         (0x1U << CMU_OPCCR1_I2CSMB0_Pos)
#define    FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK                       (0x2U << CMU_OPCCR1_I2CSMB0_Pos)

#define    FL_CMU_BSTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_XTLF                         (0x1U << CMU_OPCCR1_BT16CKS_Pos)
#define    FL_CMU_BSTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_BT16CKS_Pos)

#define    FL_CMU_UART3_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART3CKS_Pos)
#define    FL_CMU_UART3_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART3CKS_Pos)

#define    FL_CMU_LPTIM16_CLK_SOURCE_APBCLK                       (0x0U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_XTLF                         (0x1U << CMU_OPCCR1_LPT16CKS_Pos)
#define    FL_CMU_LPTIM16_CLK_SOURCE_RCLP                         (0x2U << CMU_OPCCR1_LPT16CKS_Pos)

#define    FL_CMU_UART2_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART2CKS_Pos)
#define    FL_CMU_UART2_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART2CKS_Pos)

#define    FL_CMU_ATIM1_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_AT1CKS_Pos)
#define    FL_CMU_ATIM1_CLK_SOURCE_PLLx2                          (0x1U << CMU_OPCCR1_AT1CKS_Pos)

#define    FL_CMU_ATIM0_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_AT0CKS_Pos)
#define    FL_CMU_ATIM0_CLK_SOURCE_PLLx2                          (0x1U << CMU_OPCCR1_AT0CKS_Pos)

#define    FL_CMU_UART1_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART1CKS_Pos)
#define    FL_CMU_UART1_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART1CKS_Pos)

#define    FL_CMU_UART0_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_RCHF                           (0x1U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_SYSCLK                         (0x2U << CMU_OPCCR1_UART0CKS_Pos)
#define    FL_CMU_UART0_CLK_SOURCE_XTHF                           (0x3U << CMU_OPCCR1_UART0CKS_Pos)

#define    FL_CMU_UARTx_CLK_SOURCE_NONE                           (0)

#define    FL_CMU_EPWM3_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR2_EPWM3CKS_Pos)
#define    FL_CMU_EPWM3_CLK_SOURCE_USB_BCK_PSC                    (0x1U << CMU_OPCCR2_EPWM3CKS_Pos)
#define    FL_CMU_EPWM3_CLK_SOURCE_PLLx2                          (0x2U << CMU_OPCCR2_EPWM3CKS_Pos)
#define    FL_CMU_EPWM3_CLK_SOURCE_PLLx1                          (0x3U << CMU_OPCCR2_EPWM3CKS_Pos)

#define    FL_CMU_EPWM2_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR2_EPWM2CKS_Pos)
#define    FL_CMU_EPWM2_CLK_SOURCE_USB_BCK_PSC                    (0x1U << CMU_OPCCR2_EPWM2CKS_Pos)
#define    FL_CMU_EPWM2_CLK_SOURCE_PLLx2                          (0x2U << CMU_OPCCR2_EPWM2CKS_Pos)
#define    FL_CMU_EPWM2_CLK_SOURCE_PLLx1                          (0x3U << CMU_OPCCR2_EPWM2CKS_Pos)

#define    FL_CMU_EPWM1_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR1_EPWM1CKS_Pos)
#define    FL_CMU_EPWM1_CLK_SOURCE_USB_BCK_PSC                    (0x1U << CMU_OPCCR1_EPWM1CKS_Pos)
#define    FL_CMU_EPWM1_CLK_SOURCE_PLLx2                          (0x2U << CMU_OPCCR1_EPWM1CKS_Pos)
#define    FL_CMU_EPWM1_CLK_SOURCE_PLLx1                          (0x3U << CMU_OPCCR1_EPWM1CKS_Pos)

#define    FL_CMU_EPWM_CLK_SOURCE_APBCLK                         (0x0U << CMU_OPCCR2_EPWM0CKS_Pos)
#define    FL_CMU_EPWM_CLK_SOURCE_USB_BCK_PSC                    (0x1U << CMU_OPCCR2_EPWM0CKS_Pos)
#define    FL_CMU_EPWM_CLK_SOURCE_PLLx2                          (0x2U << CMU_OPCCR2_EPWM0CKS_Pos)
#define    FL_CMU_EPWM_CLK_SOURCE_PLLx1                          (0x3U << CMU_OPCCR2_EPWM0CKS_Pos)

#define    FL_CMU_FDCAN_CLK_SOURCE_RCHF                           (0x0U << CMU_OPCCR2_FDCANCKS_Pos)
#define    FL_CMU_FDCAN_CLK_SOURCE_XTHF                           (0x1U << CMU_OPCCR2_FDCANCKS_Pos)
#define    FL_CMU_FDCAN_CLK_SOURCE_PLL                            (0x2U << CMU_OPCCR2_FDCANCKS_Pos)
#define    FL_CMU_FDCAN_CLK_SOURCE_APBCLK                         (0x3U << CMU_OPCCR2_FDCANCKS_Pos)

#define    FL_CMU_FSCAN_CLK_SOURCE_RCHF                           (0x0U << CMU_OPCCR2_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_XTHF                           (0x1U << CMU_OPCCR2_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_PLL                            (0x2U << CMU_OPCCR2_FSCANCKS_Pos)
#define    FL_CMU_FSCAN_CLK_SOURCE_APBCLK                         (0x3U << CMU_OPCCR2_FSCANCKS_Pos)

#define    FL_CMU_RNG_PSC_DIV1                                    (0x0U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV2                                    (0x1U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV4                                    (0x2U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV8                                    (0x3U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV16                                   (0x4U << CMU_OPCCR2_RNGPRSC_Pos)
#define    FL_CMU_RNG_PSC_DIV32                                   (0x5U << CMU_OPCCR2_RNGPRSC_Pos)

#define    FL_CMU_ADC_PSC_DIV1                                    (0x0U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV2                                    (0x1U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV4                                    (0x2U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV8                                    (0x3U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV16                                   (0x4U << CMU_OPCCR2_ADCPRSC_Pos)
#define    FL_CMU_ADC_PSC_DIV32                                   (0x5U << CMU_OPCCR2_ADCPRSC_Pos)

#define    FL_CMU_ADC_CLK_SOURCE_APBCLK                           (0x0U << CMU_OPCCR2_ADCCKS_Pos)
#define    FL_CMU_ADC_CLK_SOURCE_RCHF                             (0x1U << CMU_OPCCR2_ADCCKS_Pos)
#define    FL_CMU_ADC_CLK_SOURCE_XTHF                             (0x2U << CMU_OPCCR2_ADCCKS_Pos)
#define    FL_CMU_ADC_CLK_SOURCE_PLL                              (0x3U << CMU_OPCCR2_ADCCKS_Pos)

#define    FL_CMU_AHB_MASTER_PRIORITY_DMA                         (0x0U << CMU_AHBMCR_MPRIL_Pos)
#define    FL_CMU_AHB_MASTER_PRIORITY_CPU                         (0x1U << CMU_AHBMCR_MPRIL_Pos)

#define    FL_CMU_CCL_CALCLK_PSC_DIV1                             (0x0U << CMU_CCFR_CALPSC_Pos)
#define    FL_CMU_CCL_CALCLK_PSC_DIV2                             (0x1U << CMU_CCFR_CALPSC_Pos)
#define    FL_CMU_CCL_CALCLK_PSC_DIV4                             (0x2U << CMU_CCFR_CALPSC_Pos)
#define    FL_CMU_CCL_CALCLK_PSC_DIV8                             (0x3U << CMU_CCFR_CALPSC_Pos)

#define    FL_CMU_CCL_REFCLK_PSC_DIV8                             (0x0U << CMU_CCFR_REFPSC_Pos)
#define    FL_CMU_CCL_REFCLK_PSC_DIV16                            (0x1U << CMU_CCFR_REFPSC_Pos)
#define    FL_CMU_CCL_REFCLK_PSC_DIV32                            (0x2U << CMU_CCFR_REFPSC_Pos)
#define    FL_CMU_CCL_REFCLK_PSC_DIV64                            (0x3U << CMU_CCFR_REFPSC_Pos)

#define    FL_CMU_CCL_CALCLK_SOURCE_RCHF                          (0x1U << CMU_CCFR_CALSEL_Pos)
#define    FL_CMU_CCL_CALCLK_SOURCE_XTHF                          (0x3U << CMU_CCFR_CALSEL_Pos)

#define    FL_CMU_CCL_REFCLK_SOURCE_XTLF                          (0x0U << CMU_CCFR_REFSEL_Pos)
#define    FL_CMU_CCL_REFCLK_SOURCE_RCLP                          (0x1U << CMU_CCFR_REFSEL_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup CMU_FL_Exported_Functions CMU Exported Functions
  * @{
  */

/**
  * @brief    Enable Sleep/DeepSleep Mode External Interrupt
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_EnableEXTIOnSleep
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableEXTIOnSleep(void)
{
    SET_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Get Sleep/DeepSleep Mode External Interrupt Enable Status
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_IsEnabledEXTIOnSleep
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledEXTIOnSleep(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk) == CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Disable Sleep/DeepSleep Mode External Interrupt
  * @rmtoll   SYSCLKCR    SLP_ENEXTI    FL_CMU_DisableEXTIOnSleep
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableEXTIOnSleep(void)
{
    CLEAR_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SLP_ENEXTI_Msk);
}

/**
  * @brief    Set APB2 Prescaler
  * @rmtoll   SYSCLKCR    APB2PRES    FL_CMU_SetAPB2Prescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAPB2Prescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_APB2PRES_Msk, prescaler);
}

/**
  * @brief    Get APB2 Prescaler
  * @rmtoll   SYSCLKCR    APB2PRES    FL_CMU_GetAPB2Prescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB2CLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAPB2Prescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_APB2PRES_Msk));
}

/**
  * @brief    Set APB1 Prescaler
  * @rmtoll   SYSCLKCR    APB1PRES    FL_CMU_SetAPB1Prescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV1
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAPB1Prescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_APB1PRES_Msk, prescaler);
}

/**
  * @brief    Get APB1 Prescaler
  * @rmtoll   SYSCLKCR    APB1PRES    FL_CMU_GetAPB1Prescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV1
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV2
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV4
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV8
  *           @arg @ref FL_CMU_APB1CLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAPB1Prescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_APB1PRES_Msk));
}

/**
  * @brief    Set USB PHY Clock
  * @rmtoll   SYSCLKCR    USBCLOKSEL    FL_CMU_SetUSBClockOutput
  * @param    output This parameter can be one of the following values:
  *           @arg @ref FL_CMU_USB_CLK_OUT_48M
  *           @arg @ref FL_CMU_USB_CLK_OUT_96M
  *           @arg @ref FL_CMU_USB_CLK_OUT_120M
  *           @arg @ref FL_CMU_USB_CLK_OUT_240M
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUSBClockOutput(uint32_t output)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_USBCLOKSEL_Msk, output);
}

/**
  * @brief    Get USB PHY BCK Output Clock Source Setting
  * @rmtoll   SYSCLKCR    USBCLOKSEL    FL_CMU_GetUSBClockOutput
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_USB_CLK_OUT_48M
  *           @arg @ref FL_CMU_USB_CLK_OUT_96M
  *           @arg @ref FL_CMU_USB_CLK_OUT_120M
  *           @arg @ref FL_CMU_USB_CLK_OUT_240M
  */
__STATIC_INLINE uint32_t FL_CMU_GetUSBClockOutput(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_USBCLOKSEL_Msk));
}

/**
  * @brief    Set AHB Prescaler
  * @rmtoll   SYSCLKCR    AHBPRES    FL_CMU_SetAHBPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetAHBPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_AHBPRES_Msk, prescaler);
}

/**
  * @brief    Get AHB Prescaler
  * @rmtoll   SYSCLKCR    AHBPRES    FL_CMU_GetAHBPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV1
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV2
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV4
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV8
  *           @arg @ref FL_CMU_AHBCLK_PSC_DIV16
  */
__STATIC_INLINE uint32_t FL_CMU_GetAHBPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_AHBPRES_Msk));
}

/**
  * @brief    Set SysTick Clock Source
  * @rmtoll   SYSCLKCR    STCLKSEL    FL_CMU_SetSysTickClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_AHB/8
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetSysTickClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_STCLKSEL_Msk, clock);
}

/**
  * @brief    Get SysTick Clock Source
  * @rmtoll   SYSCLKCR    STCLKSEL    FL_CMU_GetSysTickClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_AHB/8
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_SYSTICK_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetSysTickClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_STCLKSEL_Msk));
}

/**
  * @brief    Set USB PHY BCK Reference Clock
  * @rmtoll   SYSCLKCR    BCKREFCKS    FL_CMU_SetUSBReferenceClock
  * @param    output This parameter can be one of the following values:
  *           @arg @ref FL_CMU_USB_REF_CLK_XTLF
  *           @arg @ref FL_CMU_USB_REF_CLK_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUSBReferenceClock(uint32_t output)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_BCKREFCKS_Msk, output);
}

/**
  * @brief    Get USB PHY BCK Reference Clock
  * @rmtoll   SYSCLKCR    BCKREFCKS    FL_RCC_GetUSBReferenceClock
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_USB_REF_CLK_XTLF
  *           @arg @ref FL_CMU_USB_REF_CLK_XTHF
  */
__STATIC_INLINE uint32_t FL_RCC_GetUSBReferenceClock(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_BCKREFCKS_Msk));
}

/**
  * @brief    Set USB Prescaler
  * @rmtoll   SYSCLKCR    BCKPRES    FL_CMU_SetUSBClockPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV1
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV2
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV4
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV8
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUSBClockPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_BCKPRES_Msk, prescaler);
}

/**
  * @brief    Get USB Prescaler
  * @rmtoll   SYSCLKCR    BCKPRES    FL_CMU_GetUSBClockPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV1
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV2
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV4
  *           @arg @ref FL_CMU_USB_CLK_PSC_DIV8
  */
__STATIC_INLINE uint32_t FL_CMU_GetUSBClockPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_BCKPRES_Msk));
}

/**
  * @brief    Set System Clock Source
  * @rmtoll   SYSCLKCR    SYSCLKSEL    FL_CMU_SetSystemClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLLx1
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLLx2
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCLP
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_USB_BCK_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetSystemClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->SYSCLKCR, CMU_SYSCLKCR_SYSCLKSEL_Msk, clock);
}

/**
  * @brief    Set System Clock Source Setting
  * @rmtoll   SYSCLKCR    SYSCLKSEL    FL_CMU_GetSystemClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLLx1
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_PLLx2
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_RCLP
  *           @arg @ref FL_CMU_SYSTEM_CLK_SOURCE_USB_BCK_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetSystemClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->SYSCLKCR, CMU_SYSCLKCR_SYSCLKSEL_Msk));
}

/**
  * @brief    Set RCHF Frequency
  * @rmtoll   RCHFCR    FSEL    FL_CMU_RCHF_SetFrequency
  * @param    frequency This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_SetFrequency(uint32_t frequency)
{
    MODIFY_REG(CMU->RCHFCR, CMU_RCHFCR_FSEL_Msk, frequency);
}

/**
  * @brief    Get RCHF Frequency Setting
  * @rmtoll   RCHFCR    FSEL    FL_CMU_RCHF_GetFrequency
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_CMU_RCHF_FREQUENCY_32MHZ
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_GetFrequency(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFCR, CMU_RCHFCR_FSEL_Msk));
}

/**
  * @brief    Enable RCHF
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_Enable(void)
{
    SET_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Get RCHF Enable Status
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk) == CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Disable RCHF
  * @rmtoll   RCHFCR    EN    FL_CMU_RCHF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_Disable(void)
{
    CLEAR_BIT(CMU->RCHFCR, CMU_RCHFCR_EN_Msk);
}

/**
  * @brief    Set RCHF Freqency Trim Value
  * @rmtoll   RCHFTR    TRIM    FL_CMU_RCHF_WriteTrimValue
  * @param    value TrimValue The value of RCHF trim
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCHF_WriteTrimValue(uint32_t value)
{
    MODIFY_REG(CMU->RCHFTR, (0xffU << 0U), (value << 0U));
}

/**
  * @brief    Get RCHF Freqency Trim Value
  * @rmtoll   RCHFTR    TRIM    FL_CMU_RCHF_ReadTrimValue
  * @retval   The value of RCHF trim
  */
__STATIC_INLINE uint32_t FL_CMU_RCHF_ReadTrimValue(void)
{
    return (uint32_t)(READ_BIT(CMU->RCHFTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set PLL Multiplier
  * @rmtoll   PLLCR    DB    FL_CMU_PLL_WriteMultiplier
  * @param    multiplier
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_WriteMultiplier(uint32_t multiplier)
{
    MODIFY_REG(CMU->PLLCR, (0x7fU << 16U), (multiplier << 16U));
}

/**
  * @brief    Get PLL Multiplier Setting
  * @rmtoll   PLLCR    DB    FL_CMU_PLL_ReadMultiplier
  * @retval
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_ReadMultiplier(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, (0x7fU << 16U)) >> 16U);
}

/**
  * @brief    Get PLL Ready Status
  * @rmtoll   PLLCR    LOCKED    FL_CMU_IsActiveFlag_PLLReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_PLLReady(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_LOCKED_Msk) == (CMU_PLLCR_LOCKED_Msk));
}

/**
  * @brief    Set PLL Prescaler
  * @rmtoll   PLLCR    REFPRSC    FL_CMU_PLL_SetPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_PLL_PSC_DIV1
  *           @arg @ref FL_CMU_PLL_PSC_DIV2
  *           @arg @ref FL_CMU_PLL_PSC_DIV4
  *           @arg @ref FL_CMU_PLL_PSC_DIV8
  *           @arg @ref FL_CMU_PLL_PSC_DIV12
  *           @arg @ref FL_CMU_PLL_PSC_DIV16
  *           @arg @ref FL_CMU_PLL_PSC_DIV24
  *           @arg @ref FL_CMU_PLL_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_SetPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_REFPRSC_Msk, prescaler);
}

/**
  * @brief    Get PLL Prescaler Setting
  * @rmtoll   PLLCR    REFPRSC    FL_CMU_PLL_GetPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_PLL_PSC_DIV1
  *           @arg @ref FL_CMU_PLL_PSC_DIV2
  *           @arg @ref FL_CMU_PLL_PSC_DIV4
  *           @arg @ref FL_CMU_PLL_PSC_DIV8
  *           @arg @ref FL_CMU_PLL_PSC_DIV12
  *           @arg @ref FL_CMU_PLL_PSC_DIV16
  *           @arg @ref FL_CMU_PLL_PSC_DIV24
  *           @arg @ref FL_CMU_PLL_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_GetPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_REFPRSC_Msk));
}

/**
  * @brief    Set PLL Input Source
  * @rmtoll   PLLCR    INSEL    FL_CMU_PLL_SetClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_SetClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_INSEL_Msk, clock);
}

/**
  * @brief    Get PLL Input Source Setting
  * @rmtoll   PLLCR    INSEL    FL_CMU_PLL_GetClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_PLL_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_GetClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_INSEL_Msk));
}

/**
  * @brief    Enable PLL
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_Enable(void)
{
    SET_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Disable PLL
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_PLL_Disable(void)
{
    CLEAR_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Get PLL Enable Status
  * @rmtoll   PLLCR    EN    FL_CMU_PLL_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_PLL_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->PLLCR, CMU_PLLCR_EN_Msk) == CMU_PLLCR_EN_Msk);
}

/**
  * @brief    Set RCLP Enable
  * @rmtoll   RCLPCR    ENB    FL_CMU_RCLP_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_Enable(void)
{
    SET_BIT(CMU->RCLPCR, CMU_RCLPCR_ENB_Msk);
}

/**
  * @brief    Get RCLP Enable Flag
  * @rmtoll   RCLPCR    ENB    FL_CMU_RCLP_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_RCLP_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->RCLPCR, CMU_RCLPCR_ENB_Msk) == CMU_RCLPCR_ENB_Msk);
}

/**
  * @brief    Set RCLP Disable
  * @rmtoll   RCLPCR    ENB    FL_CMU_RCLP_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_Disable(void)
{
    CLEAR_BIT(CMU->RCLPCR, CMU_RCLPCR_ENB_Msk);
}

/**
  * @brief    Set RCLP Frequency Trim Value
  * @rmtoll   RCLPTR    TRIM    FL_CMU_RCLP_WriteTrimValue
  * @param    value TrimValue The value of RCLP trim
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_RCLP_WriteTrimValue(uint32_t value)
{
    MODIFY_REG(CMU->RCLPTR, (0xffU << 0U), (value << 0U));
}

/**
  * @brief    Get RCLP Frequency Trim Value
  * @rmtoll   RCLPTR    TRIM    FL_CMU_RCLP_ReadTrimValue
  * @retval   The Value of RCLP trim
  */
__STATIC_INLINE uint32_t FL_CMU_RCLP_ReadTrimValue(void)
{
    return (uint32_t)(READ_BIT(CMU->RCLPTR, (0xffU << 0U)) >> 0U);
}

/**
  * @brief    Set XTHF Start Wait Time
  * @rmtoll   XTHFCR    WAIT    FL_CMU_XTHF_SetStartWaitTime
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_16384
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_SetStartWaitTime(uint32_t clock)
{
    MODIFY_REG(CMU->XTHFCR, CMU_XTHFCR_WAIT_Msk, clock);
}

/**
  * @brief    Get XTHF Start Wait Time
  * @rmtoll   XTHFCR    WAIT    FL_CMU_XTHF_GetStartWaitTime
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_128
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_256
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_512
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_1024
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_2048
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_4096
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_8192
  *           @arg @ref FL_CMU_XTHF_START_WAIT_CYCLE_16384
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_GetStartWaitTime(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_WAIT_Msk));
}

/**
  * @brief    Set XTHF Oscillation Strength
  * @rmtoll   XTHFCR    CFG    FL_CMU_XTHF_WriteDriverStrength
  * @param    strength
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_WriteDriverStrength(uint32_t strength)
{
    MODIFY_REG(CMU->XTHFCR, (0x1fU << 8U), (strength << 8U));
}

/**
  * @brief    Get XTHF Oscillation Strength Setting
  * @rmtoll   XTHFCR    CFG    FL_CMU_XTHF_ReadDriverStrength
  * @retval
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_ReadDriverStrength(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, (0x1fU << 8U)) >> 8U);
}

/**
  * @brief    Enable XTHF Bypass
  * @rmtoll   XTHFCR    BYPASS    FL_CMU_XTHF_EnableBypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_EnableBypass(void)
{
    SET_BIT(CMU->XTHFCR, CMU_XTHFCR_BYPASS_Msk);
}

/**
  * @brief    Get XTHF Bypass Status
  * @rmtoll   XTHFCR    BYPASS    FL_CMU_XTHF_IsEnabledBypass
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsEnabledBypass(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_BYPASS_Msk) == CMU_XTHFCR_BYPASS_Msk);
}

/**
  * @brief    Disable XTHF Bypass
  * @rmtoll   XTHFCR    BYPASS    FL_CMU_XTHF_DisableBypass
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_DisableBypass(void)
{
    CLEAR_BIT(CMU->XTHFCR, CMU_XTHFCR_BYPASS_Msk);
}

/**
  * @brief    Get XTHF Ready Status
  * @rmtoll   XTHFCR    RDY    FL_CMU_XTHF_IsReady
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsReady(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_RDY_Msk) == CMU_XTHFCR_RDY_Msk);
}

/**
  * @brief    Enable XTHF
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_Enable(void)
{
    SET_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Get XTHF Enable Status
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_XTHF_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk) == CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Disable XTHF
  * @rmtoll   XTHFCR    EN    FL_CMU_XTHF_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_XTHF_Disable(void)
{
    CLEAR_BIT(CMU->XTHFCR, CMU_XTHFCR_EN_Msk);
}

/**
  * @brief    Enable SYSCSE Wrong Interrupt
  * @rmtoll   IER    SYSCSE_IE    FL_CMU_EnableIT_SYSCKEWrong
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_SYSCKEWrong(void)
{
    SET_BIT(CMU->IER, CMU_IER_SYSCSE_IE_Msk);
}

/**
  * @brief    Get SYSCSE Wrong Interrupt Enable Status
  * @rmtoll   IER    SYSCSE_IE    FL_CMU_IsEnabledIT_SYSCKEWrong
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_SYSCKEWrong(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_SYSCSE_IE_Msk) == CMU_IER_SYSCSE_IE_Msk);
}

/**
  * @brief    Disable SYSCSE Wrong Interrupt
  * @rmtoll   IER    SYSCSE_IE    FL_CMU_DisableIT_SYSCKEWrong
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_SYSCKEWrong(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_SYSCSE_IE_Msk);
}

/**
  * @brief    Enable XTHF Fail Interrupt
  * @rmtoll   IER    HFDET_IE    FL_CMU_EnableIT_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableIT_XTHFFail(void)
{
    SET_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Get XTHF Fail Interrupt Enable Status
  * @rmtoll   IER    HFDET_IE    FL_CMU_IsEnabledIT_XTHFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledIT_XTHFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk) == CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Disable XTHF Fail Interrupt
  * @rmtoll   IER    HFDET_IE    FL_CMU_DisableIT_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableIT_XTHFFail(void)
{
    CLEAR_BIT(CMU->IER, CMU_IER_HFDET_IE_Msk);
}

/**
  * @brief    Get XTHF Vibrating Output
  * @rmtoll   ISR    HFDETO    FL_CMU_IsActiveFlag_XTHFFailOutput
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTHFFailOutput(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_HFDETO_Msk) == (CMU_ISR_HFDETO_Msk));
}

/**
  * @brief    Get SYSCKE Wrong Flag
  * @rmtoll   ISR    SYSCSE_IF    FL_CMU_IsActiveFlag_SYSCSEWrong
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_SYSCSEWrong(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_SYSCSE_IF_Msk) == (CMU_ISR_SYSCSE_IF_Msk));
}

/**
  * @brief    Clear SYSCKE Wrong Flag
  * @rmtoll   ISR    SYSCSE_IF    FL_CMU_ClearFlag_SYSCSEWrong
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_SYSCSEWrong(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_SYSCSE_IF_Msk);
}

/**
  * @brief    Get XTHF Vibrating Flag
  * @rmtoll   ISR    HFDET_IF    FL_CMU_IsActiveFlag_XTHFFail
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_XTHFFail(void)
{
    return (uint32_t)(READ_BIT(CMU->ISR, CMU_ISR_HFDET_IF_Msk) == (CMU_ISR_HFDET_IF_Msk));
}

/**
  * @brief    Clear XTHF Vibrating Flag
  * @rmtoll   ISR    HFDET_IF    FL_CMU_ClearFlag_XTHFFail
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_XTHFFail(void)
{
    WRITE_REG(CMU->ISR, CMU_ISR_HFDET_IF_Msk);
}

/**
  * @brief    Enable Group1 Periph Bus Clock
  * @rmtoll   PCLKCR1        FL_CMU_EnableGroup1BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_USB
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup1BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR1, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group2 Periph Bus Clock
  * @rmtoll   PCLKCR2        FL_CMU_EnableGroup2BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_OPA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup2BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR2, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group3 Periph Bus Clock
  * @rmtoll   PCLKCR3        FL_CMU_EnableGroup3BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_EPSC
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART5
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART6
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART7
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FDCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UCIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB2
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup3BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR3, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Group4 Periph Bus Clock
  * @rmtoll   PCLKCR4        FL_CMU_EnableGroup4BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM2
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_EPWM
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup4BusClock(uint32_t peripheral)
{
    SET_BIT(CMU->PCLKCR4, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group1 Periph Bus Clock
  * @rmtoll   PCLKCR1        FL_CMU_DisableGroup1BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_USB
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup1BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR1, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group2 Periph Bus Clock
  * @rmtoll   PCLKCR2        FL_CMU_DisableGroup2BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_OPA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup2BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR2, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group3 Periph Bus Clock
  * @rmtoll   PCLKCR3        FL_CMU_DisableGroup3BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_EPSC
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART5
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART6
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART7
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FDCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UCIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB2
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup3BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR3, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Group4 Periph Bus Clock
  * @rmtoll   PCLKCR4        FL_CMU_DisableGroup4BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM2
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_EPWM
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup4BusClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->PCLKCR4, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group1 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR1        FL_CMU_IsEnabledGroup1BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_LPTIM16
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_USB
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PMU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SCU
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_IWDT
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_ANAC
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_PAD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_SVD
  *           @arg @ref FL_CMU_GROUP1_BUSCLK_COMP
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup1BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR1, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group2 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR2        FL_CMU_IsEnabledGroup2BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_CRC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RNG
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_AES
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DMA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_FLASH
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_RAMBIST
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_WWDT
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_ADC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_DAC
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_OPA
  *           @arg @ref FL_CMU_GROUP2_BUSCLK_PGL
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup2BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR2, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group3 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR3        FL_CMU_IsEnabledGroup3BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_SPI4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_EPSC
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART2
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART3
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART4
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART5
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART6
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UART7
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_LPUART1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FSCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_FDCAN
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_UCIR
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2C1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB0
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB1
  *           @arg @ref FL_CMU_GROUP3_BUSCLK_I2CSMB2
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup3BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR3, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Group4 Periph Bus Clock Enable Status
  * @rmtoll   PCLKCR4        FL_CMU_IsEnabledGroup4BusClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_GTIM2
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM0
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_ATIM1
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_BSTIM16
  *           @arg @ref FL_CMU_GROUP4_BUSCLK_EPWM
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup4BusClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->PCLKCR4, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Periph Operation Clock
  * @rmtoll   PCLKCR1        FL_CMU_EnableGroup1OperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EXTI
  *           @arg @ref FL_CMU_OPCLK_FLASH
  *           @arg @ref FL_CMU_OPCLK_LPUART1
  *           @arg @ref FL_CMU_OPCLK_LPUART0
  *           @arg @ref FL_CMU_OPCLK_RNG
  *           @arg @ref FL_CMU_OPCLK_I2CSMB2
  *           @arg @ref FL_CMU_OPCLK_I2CSMB1
  *           @arg @ref FL_CMU_OPCLK_I2CSMB0
  *           @arg @ref FL_CMU_OPCLK_ADC
  *           @arg @ref FL_CMU_OPCLK_ATIM1
  *           @arg @ref FL_CMU_OPCLK_ATIM0
  *           @arg @ref FL_CMU_OPCLK_UART3
  *           @arg @ref FL_CMU_OPCLK_UART2
  *           @arg @ref FL_CMU_OPCLK_UART1
  *           @arg @ref FL_CMU_OPCLK_UART0
  *           @arg @ref FL_CMU_OPCLK_BSTIM16
  *           @arg @ref FL_CMU_OPCLK_LPTIM16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup1OperationClock(uint32_t peripheral)
{
    SET_BIT(CMU->OPCER1, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Periph Operation Clock
  * @rmtoll   PCLKCR1        FL_CMU_DisableGroup1OperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EXTI
  *           @arg @ref FL_CMU_OPCLK_FLASH
  *           @arg @ref FL_CMU_OPCLK_LPUART1
  *           @arg @ref FL_CMU_OPCLK_LPUART0
  *           @arg @ref FL_CMU_OPCLK_RNG
  *           @arg @ref FL_CMU_OPCLK_I2CSMB2
  *           @arg @ref FL_CMU_OPCLK_I2CSMB1
  *           @arg @ref FL_CMU_OPCLK_I2CSMB0
  *           @arg @ref FL_CMU_OPCLK_ADC
  *           @arg @ref FL_CMU_OPCLK_ATIM1
  *           @arg @ref FL_CMU_OPCLK_ATIM0
  *           @arg @ref FL_CMU_OPCLK_UART3
  *           @arg @ref FL_CMU_OPCLK_UART2
  *           @arg @ref FL_CMU_OPCLK_UART1
  *           @arg @ref FL_CMU_OPCLK_UART0
  *           @arg @ref FL_CMU_OPCLK_BSTIM16
  *           @arg @ref FL_CMU_OPCLK_LPTIM16
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup1OperationClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->OPCER1, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Periph Operation Clock Enable Status
  * @rmtoll   PCLKCR1        FL_CMU_IsEnabledGroup1OperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EXTI
  *           @arg @ref FL_CMU_OPCLK_FLASH
  *           @arg @ref FL_CMU_OPCLK_LPUART1
  *           @arg @ref FL_CMU_OPCLK_LPUART0
  *           @arg @ref FL_CMU_OPCLK_RNG
  *           @arg @ref FL_CMU_OPCLK_I2CSMB2
  *           @arg @ref FL_CMU_OPCLK_I2CSMB1
  *           @arg @ref FL_CMU_OPCLK_I2CSMB0
  *           @arg @ref FL_CMU_OPCLK_ADC
  *           @arg @ref FL_CMU_OPCLK_ATIM1
  *           @arg @ref FL_CMU_OPCLK_ATIM0
  *           @arg @ref FL_CMU_OPCLK_UART3
  *           @arg @ref FL_CMU_OPCLK_UART2
  *           @arg @ref FL_CMU_OPCLK_UART1
  *           @arg @ref FL_CMU_OPCLK_UART0
  *           @arg @ref FL_CMU_OPCLK_BSTIM16
  *           @arg @ref FL_CMU_OPCLK_LPTIM16
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup1OperationClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->OPCER1, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable Periph Operation Clock
  * @rmtoll   PCLKCR2        FL_CMU_EnableGroup2OperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EPWM0
  *           @arg @ref FL_CMU_OPCLK_EPWM1
  *           @arg @ref FL_CMU_OPCLK_EPWM2
  *           @arg @ref FL_CMU_OPCLK_EPWM3
  *           @arg @ref FL_CMU_OPCLK_FSCAN
  *           @arg @ref FL_CMU_OPCLK_FDCAN
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_EnableGroup2OperationClock(uint32_t peripheral)
{
    SET_BIT(CMU->OPCER2, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable Periph Operation Clock
  * @rmtoll   PCLKCR2        FL_CMU_DisableGroup2OperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EPWM0
  *           @arg @ref FL_CMU_OPCLK_EPWM1
  *           @arg @ref FL_CMU_OPCLK_EPWM2
  *           @arg @ref FL_CMU_OPCLK_EPWM3
  *           @arg @ref FL_CMU_OPCLK_FSCAN
  *           @arg @ref FL_CMU_OPCLK_FDCAN
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_DisableGroup2OperationClock(uint32_t peripheral)
{
    CLEAR_BIT(CMU->OPCER2, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Get Periph Operation Clock Enable Status
  * @rmtoll   PCLKCR2        FL_CMU_IsEnabledGroup2OperationClock
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_CMU_OPCLK_EPWM0
  *           @arg @ref FL_CMU_OPCLK_EPWM1
  *           @arg @ref FL_CMU_OPCLK_EPWM2
  *           @arg @ref FL_CMU_OPCLK_EPWM3
  *           @arg @ref FL_CMU_OPCLK_FSCAN
  *           @arg @ref FL_CMU_OPCLK_FDCAN
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsEnabledGroup2OperationClock(uint32_t peripheral)
{
    return (uint32_t)(READ_BIT(CMU->OPCER2, ((peripheral & 0xffffffff) << 0x0U)) == ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Set EXTI Clock Source
  * @rmtoll   OPCCR1    EXTICKS    FL_CMU_SetEXTIClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_HCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetEXTIClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_EXTICKS_Msk, clock);
}

/**
  * @brief    Get EXTI Clock Source Setting
  * @rmtoll   OPCCR1    EXTICKS    FL_CMU_GetEXTIClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_LSCLK
  *           @arg @ref FL_CMU_EXTI_CLK_SOURCE_HCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetEXTIClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_EXTICKS_Msk));
}

/**
  * @brief    Set LIN WKUP Clock Source
  * @rmtoll   OPCCR1    LINCKS    FL_CMU_SetLINWKUPClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LINWKUP_CLK_SOURCE_RCLP
  *           @arg @ref FL_CMU_LINWKUP_CLK_SOURCE_XTLF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLINWKUPClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LINCKS_Msk, clock);
}

/**
  * @brief    Get LIN WKUP Clock Source Setting
  * @rmtoll   OPCCR1    LINCKS    FL_CMU_GetLINWKUPClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LINWKUP_CLK_SOURCE_RCLP
  *           @arg @ref FL_CMU_LINWKUP_CLK_SOURCE_XTLF
  */
__STATIC_INLINE uint32_t FL_CMU_GetLINWKUPClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LINCKS_Msk));
}

/**
  * @brief    Set LPUART Clock Source
  * @rmtoll   OPCCR1    LPUART1CKS    FL_CMU_SetLPUART1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCHF_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART1CKS_Msk, clock);
}

/**
  * @brief    Get LPUART Clock Source Setting
  * @rmtoll   OPCCR1    LPUART1CKS    FL_CMU_GetLPUART1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART1_CLK_SOURCE_RCHF_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART1CKS_Msk));
}

/**
  * @brief    Set LPUART Clock Source
  * @rmtoll   OPCCR1    LPUART0CKS    FL_CMU_SetLPUART0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCHF_PSC
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPUART0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPUART0CKS_Msk, clock);
}

/**
  * @brief    Get LPUART Clock Source Setting
  * @rmtoll   OPCCR1    LPUART0CKS    FL_CMU_GetLPUART0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPUART0_CLK_SOURCE_RCHF_PSC
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPUART0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPUART0CKS_Msk));
}

/**
  * @brief    Set I2C_SMB0 Clock Source
  * @rmtoll   OPCCR1    I2CSMB2    FL_CMU_SetI2CSMB2ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB2_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB2ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB2_Msk, clock);
}

/**
  * @brief    Get I2C_SMB0 Source Setting
  * @rmtoll   OPCCR1    I2CSMB2    FL_CMU_GetI2CSMB2ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB2_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB2ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB2_Msk));
}

/**
  * @brief    Set I2C_SMB1 Clock Source
  * @rmtoll   OPCCR1    I2CSMB1    FL_CMU_SetI2CSMB1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB1_Msk, clock);
}

/**
  * @brief    Get I2C_SMB1 Source Setting
  * @rmtoll   OPCCR1    I2CSMB1    FL_CMU_GetI2CSMB1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB1_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB1_Msk));
}

/**
  * @brief    Set I2C_SMB0 Clock Source
  * @rmtoll   OPCCR1    I2CSMB0    FL_CMU_SetI2CSMB0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetI2CSMB0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_I2CSMB0_Msk, clock);
}

/**
  * @brief    Get I2C_SMB0 Source Setting
  * @rmtoll   OPCCR1    I2CSMB0    FL_CMU_GetI2CSMB0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_I2CSMB0_CLK_SOURCE_SYSCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetI2CSMB0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_I2CSMB0_Msk));
}

/**
  * @brief    Set BSTIM16 Clock Source
  * @rmtoll   OPCCR1    BT16CKS    FL_CMU_SetBSTIM16ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetBSTIM16ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_BT16CKS_Msk, clock);
}

/**
  * @brief    Get BSTIM16 Clock Source Setting
  * @rmtoll   OPCCR1    BT16CKS    FL_CMU_GetBSTIM16ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_BSTIM16_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetBSTIM16ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_BT16CKS_Msk));
}

/**
  * @brief    Set UART1 Clock Source
  * @rmtoll   OPCCR1    UART3CKS    FL_CMU_SetUART3ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART3ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART3CKS_Msk, clock);
}

/**
  * @brief    Get UART1 Clock Source Setting
  * @rmtoll   OPCCR1    UART3CKS    FL_CMU_GetUART3ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART3_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART3ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART3CKS_Msk));
}

/**
  * @brief    Set LPTIM16 Clock Source
  * @rmtoll   OPCCR1    LPT16CKS    FL_CMU_SetLPTIM16ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetLPTIM16ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_LPT16CKS_Msk, clock);
}

/**
  * @brief    Get LPTIM16 Clock Source Setting
  * @rmtoll   OPCCR1    LPT16CKS    FL_CMU_GetLPTIM16ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_LPTIM16_CLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_GetLPTIM16ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_LPT16CKS_Msk));
}

/**
  * @brief    Set UART1 Clock Source
  * @rmtoll   OPCCR1    UART2CKS    FL_CMU_SetUART2ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART2ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART2CKS_Msk, clock);
}

/**
  * @brief    Get UART1 Clock Source Setting
  * @rmtoll   OPCCR1    UART2CKS    FL_CMU_GetUART2ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART2_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART2ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART2CKS_Msk));
}

/**
  * @brief    Set ATIM Clock Source
  * @rmtoll   OPCCR1    AT1CKS    FL_CMU_SetATIM1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ATIM1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM1_CLK_SOURCE_PLLx2
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetATIM1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_AT1CKS_Msk, clock);
}

/**
  * @brief    Get ATIM Clock Source Setting
  * @rmtoll   OPCCR1    AT1CKS    FL_CMU_GetATIM1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ATIM1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM1_CLK_SOURCE_PLLx2
  */
__STATIC_INLINE uint32_t FL_CMU_GetATIM1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_AT1CKS_Msk));
}

/**
  * @brief    Set ATIM Clock Source
  * @rmtoll   OPCCR1    AT0CKS    FL_CMU_SetATIM0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ATIM0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM0_CLK_SOURCE_PLLx2
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetATIM0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_AT0CKS_Msk, clock);
}

/**
  * @brief    Get ATIM Clock Source Setting
  * @rmtoll   OPCCR1    AT0CKS    FL_CMU_GetATIM0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ATIM0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ATIM0_CLK_SOURCE_PLLx2
  */
__STATIC_INLINE uint32_t FL_CMU_GetATIM0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_AT0CKS_Msk));
}

/**
  * @brief    Set UART1 Clock Source
  * @rmtoll   OPCCR1    UART1CKS    FL_CMU_SetUART1ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART1ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART1CKS_Msk, clock);
}

/**
  * @brief    Get UART1 Clock Source Setting
  * @rmtoll   OPCCR1    UART1CKS    FL_CMU_GetUART1ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART1_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART1ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART1CKS_Msk));
}

/**
  * @brief    Set UART0 Clock Source
  * @rmtoll   OPCCR1    UART0CKS    FL_CMU_SetUART0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetUART0ClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR1, CMU_OPCCR1_UART0CKS_Msk, clock);
}

/**
  * @brief    Get UART0 Clock Source Setting
  * @rmtoll   OPCCR1    UART0CKS    FL_CMU_GetUART0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_SYSCLK
  *           @arg @ref FL_CMU_UART0_CLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_GetUART0ClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR1, CMU_OPCCR1_UART0CKS_Msk));
}

/**
  * @brief    Set EPWM0 Clock Source
  * @rmtoll   OPCCR2    EPWM0CKS    FL_CMU_SetEPWM0ClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_USB_BCK_PSC
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_PLLx2
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_PLLx1
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetEPWMClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_EPWM0CKS_Msk, clock);
}

/**
  * @brief    Get EPWM0 Clock Source Setting
  * @rmtoll   OPCCR2    EPWM0CKS    FL_CMU_GetEPWM0ClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_USB_BCK_PSC
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_PLLx2
  *           @arg @ref FL_CMU_EPWM_CLK_SOURCE_PLLx1
  */
__STATIC_INLINE uint32_t FL_CMU_GetEPWMClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_EPWM0CKS_Msk));
}

/**
  * @brief    Set FDCAN Clock Source
  * @rmtoll   OPCCR2    FDCANCKS    FL_CMU_SetFDCANClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_APBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetFDCANClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_FDCANCKS_Msk, clock);
}

/**
  * @brief    Get FDCAN Clock Source Setting
  * @rmtoll   OPCCR2    FDCANCKS    FL_CMU_GetFDCANClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FDCAN_CLK_SOURCE_APBCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetFDCANClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_FDCANCKS_Msk));
}

/**
  * @brief    Set FSCAN Clock Source
  * @rmtoll   OPCCR2    FSCANCKS    FL_CMU_SetFSCANClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_APBCLK
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetFSCANClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_FSCANCKS_Msk, clock);
}

/**
  * @brief    Get FSCAN Clock Source Setting
  * @rmtoll   OPCCR2    FSCANCKS    FL_CMU_GetFSCANClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_PLL
  *           @arg @ref FL_CMU_FSCAN_CLK_SOURCE_APBCLK
  */
__STATIC_INLINE uint32_t FL_CMU_GetFSCANClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_FSCANCKS_Msk));
}

/**
  * @brief    Set RNG Prescaler
  * @rmtoll   OPCCR2    RNGPRSC    FL_CMU_SetRNGPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_RNG_PSC_DIV1
  *           @arg @ref FL_CMU_RNG_PSC_DIV2
  *           @arg @ref FL_CMU_RNG_PSC_DIV4
  *           @arg @ref FL_CMU_RNG_PSC_DIV8
  *           @arg @ref FL_CMU_RNG_PSC_DIV16
  *           @arg @ref FL_CMU_RNG_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetRNGPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_RNGPRSC_Msk, prescaler);
}

/**
  * @brief    Get RNG Prescaler Setting
  * @rmtoll   OPCCR2    RNGPRSC    FL_CMU_GetRNGPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_RNG_PSC_DIV1
  *           @arg @ref FL_CMU_RNG_PSC_DIV2
  *           @arg @ref FL_CMU_RNG_PSC_DIV4
  *           @arg @ref FL_CMU_RNG_PSC_DIV8
  *           @arg @ref FL_CMU_RNG_PSC_DIV16
  *           @arg @ref FL_CMU_RNG_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_GetRNGPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_RNGPRSC_Msk));
}

/**
  * @brief    Set ADC Prescaler
  * @rmtoll   OPCCR2    ADCPRSC    FL_CMU_SetADCPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ADC_PSC_DIV1
  *           @arg @ref FL_CMU_ADC_PSC_DIV2
  *           @arg @ref FL_CMU_ADC_PSC_DIV4
  *           @arg @ref FL_CMU_ADC_PSC_DIV8
  *           @arg @ref FL_CMU_ADC_PSC_DIV16
  *           @arg @ref FL_CMU_ADC_PSC_DIV32
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetADCPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_ADCPRSC_Msk, prescaler);
}

/**
  * @brief    Get ADC Prescaler Setting
  * @rmtoll   OPCCR2    ADCPRSC    FL_CMU_GetADCPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ADC_PSC_DIV1
  *           @arg @ref FL_CMU_ADC_PSC_DIV2
  *           @arg @ref FL_CMU_ADC_PSC_DIV4
  *           @arg @ref FL_CMU_ADC_PSC_DIV8
  *           @arg @ref FL_CMU_ADC_PSC_DIV16
  *           @arg @ref FL_CMU_ADC_PSC_DIV32
  */
__STATIC_INLINE uint32_t FL_CMU_GetADCPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_ADCPRSC_Msk));
}

/**
  * @brief    Set ADC Clock Source
  * @rmtoll   OPCCR2    ADCCKS    FL_CMU_SetADCClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_PLL
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_SetADCClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->OPCCR2, CMU_OPCCR2_ADCCKS_Msk, clock);
}

/**
  * @brief    Get ADC Clock Source Setting
  * @rmtoll   OPCCR2    ADCCKS    FL_CMU_GetADCClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_APBCLK
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_XTHF
  *           @arg @ref FL_CMU_ADC_CLK_SOURCE_PLL
  */
__STATIC_INLINE uint32_t FL_CMU_GetADCClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->OPCCR2, CMU_OPCCR2_ADCCKS_Msk));
}

/**
  * @brief    Disable CCL Interrupt
  * @rmtoll   CCCR    CCLIE    FL_CMU_CCL_DisableIT
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_DisableIT(void)
{
    CLEAR_BIT(CMU->CCCR, CMU_CCCR_IE_Msk);
}

/**
  * @brief    Enable CCL Interrupt
  * @rmtoll   CCCR    CCLIE    FL_CMU_CCL_EnableIT
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_EnableIT(void)
{
    SET_BIT(CMU->CCCR, CMU_CCCR_IE_Msk);
}

/**
  * @brief    Get CCL Interrupt Enable Status
  * @rmtoll   CCCR    CCLIE    FL_CMU_CCL_IsEnabledIT
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_IsEnabledIT(void)
{
    return (uint32_t)(READ_BIT(CMU->CCCR, CMU_CCCR_IE_Msk) == CMU_CCCR_IE_Msk);
}

/**
  * @brief    Enable CCL
  * @rmtoll   CCCR    EN    FL_CMU_CCL_Enable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_Enable(void)
{
    SET_BIT(CMU->CCCR, CMU_CCCR_EN_Msk);
}

/**
  * @brief    Get CCL Enable Status
  * @rmtoll   CCCR    EN    FL_CMU_CCL_IsEnabled
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_IsEnabled(void)
{
    return (uint32_t)(READ_BIT(CMU->CCCR, CMU_CCCR_EN_Msk) == CMU_CCCR_EN_Msk);
}

/**
  * @brief    Disable CCL
  * @rmtoll   CCCR    EN    FL_CMU_CCL_Disable
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_Disable(void)
{
    CLEAR_BIT(CMU->CCCR, CMU_CCCR_EN_Msk);
}

/**
  * @brief    Set CCL Calibration Clock Prescaler
  * @rmtoll   CCFR    CALPSC    FL_CMU_CCL_SetCalibrationClockPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV1
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV2
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV4
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV8
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_SetCalibrationClockPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->CCFR, CMU_CCFR_CALPSC_Msk, prescaler);
}

/**
  * @brief    Get CCL Calibration Clock Prescaler
  * @rmtoll   CCFR    CALPSC    FL_CMU_CCL_GetCalibrationClockPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV1
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV2
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV4
  *           @arg @ref FL_CMU_CCL_CALCLK_PSC_DIV8
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_GetCalibrationClockPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->CCFR, CMU_CCFR_CALPSC_Msk));
}

/**
  * @brief    Set CCL Reference Clock Prescaler
  * @rmtoll   CCFR    REFPSC    FL_CMU_CCL_SetReferenceClockPrescaler
  * @param    prescaler This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV8
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV16
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV32
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV64
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_SetReferenceClockPrescaler(uint32_t prescaler)
{
    MODIFY_REG(CMU->CCFR, CMU_CCFR_REFPSC_Msk, prescaler);
}

/**
  * @brief    Get CCL Reference Clock Prescaler
  * @rmtoll   CCFR    REFPSC    FL_CMU_CCL_GetReferenceClockPrescaler
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV8
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV16
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV32
  *           @arg @ref FL_CMU_CCL_REFCLK_PSC_DIV64
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_GetReferenceClockPrescaler(void)
{
    return (uint32_t)(READ_BIT(CMU->CCFR, CMU_CCFR_REFPSC_Msk));
}

/**
  * @brief    Set CCL Calibration Clock Source
  * @rmtoll   CCFR    CALSEL    FL_CMU_CCL_SetCalibrationClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CCL_CALCLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_CCL_CALCLK_SOURCE_XTHF
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_SetCalibrationClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->CCFR, CMU_CCFR_CALSEL_Msk, clock);
}

/**
  * @brief    Get CCL Calibration Clock Source Setting
  * @rmtoll   CCFR    CALSEL    FL_CMU_CCL_GetCalibrationClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CCL_CALCLK_SOURCE_RCHF
  *           @arg @ref FL_CMU_CCL_CALCLK_SOURCE_XTHF
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_GetCalibrationClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->CCFR, CMU_CCFR_CALSEL_Msk));
}

/**
  * @brief    Set CCL Reference Clock Source
  * @rmtoll   CCFR    REFSEL    FL_CMU_CCL_SetReferenceClockSource
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_CMU_CCL_REFCLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_CCL_REFCLK_SOURCE_RCLP
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_CCL_SetReferenceClockSource(uint32_t clock)
{
    MODIFY_REG(CMU->CCFR, CMU_CCFR_REFSEL_Msk, clock);
}

/**
  * @brief    Get CCL Reference Clock Source Setting
  * @rmtoll   CCFR    REFSEL    FL_CMU_CCL_GetReferenceClockSource
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_CMU_CCL_REFCLK_SOURCE_XTLF
  *           @arg @ref FL_CMU_CCL_REFCLK_SOURCE_RCLP
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_GetReferenceClockSource(void)
{
    return (uint32_t)(READ_BIT(CMU->CCFR, CMU_CCFR_REFSEL_Msk));
}

/**
  * @brief    Get CCL Counter value
  * @rmtoll   CCNR    CCNT    FL_CMU_CCL_ReadCounter
  * @retval
  */
__STATIC_INLINE uint32_t FL_CMU_CCL_ReadCounter(void)
{
    return (uint32_t)(READ_BIT(CMU->CCNR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get CCL interrupt flag
  * @rmtoll   CCISR    CCLIF    FL_CMU_IsActiveFlag_CCLComplete
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_CMU_IsActiveFlag_CCLComplete(void)
{
    return (uint32_t)(READ_BIT(CMU->CCISR, CMU_CCISR_IF_Msk) == (CMU_CCISR_IF_Msk));
}

/**
  * @brief    Clear CCL interrupt flag
  * @rmtoll   CCISR    CCLIF    FL_CMU_ClearFlag_CCLComplete
  * @retval   None
  */
__STATIC_INLINE void FL_CMU_ClearFlag_CCLComplete(void)
{
    WRITE_REG(CMU->CCISR, CMU_CCISR_IF_Msk);
}

/**
  * @}
  */

/** @defgroup CMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

FL_ErrorStatus FL_CMU_SetSystemClock(FL_SystemClock systemClock);

uint32_t FL_CMU_GetSystemClockFreq(void);
uint32_t FL_CMU_GetAHBClockFreq(void);
uint32_t FL_CMU_GetAPB1ClockFreq(void);
uint32_t FL_CMU_GetAPB2ClockFreq(void);

uint32_t FL_CMU_GetRCHFClockFreq(void);
uint32_t FL_CMU_GetPLLClockFreq(void);
uint32_t FL_CMU_GetUSBClockFreqToSysclk(void);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_CMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-03-22*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
