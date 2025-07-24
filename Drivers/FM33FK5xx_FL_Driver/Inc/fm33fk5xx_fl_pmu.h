/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_pmu.h
  * @author  FMSH Application Team
  * @brief   Head file of PMU FL Module
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
#ifndef __FM33FK5XX_FL_PMU_H
#define __FM33FK5XX_FL_PMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_ES_INIT PMU Exported Init structures
  * @{
  */

/**
  * @brief FL PMU Init Sturcture definition
  */
typedef struct
{
    /* 低功耗模式配置 */
    uint32_t powerMode;
    /* 睡眠模式配置 */
    uint32_t sleepMode ;
    /* 唤醒后的系统频率，仅对RCHF */
    uint32_t wakeupFrequency;
    /* AVREF采样保持时间 */
    uint32_t avrefHoldTime;
    /* ram0电源控制 */
    uint32_t ram0PowerControl;
    /* ram1电源控制 */
    uint32_t ram1PowerControl;
    /* cache data ram电源控制 */
    uint32_t cacheDramPowerControl;
    /*  cache tag ram电源控制 */
    uint32_t cacheTramPowerControl;

} FL_PMU_SleepInitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_Exported_Constants PMU Exported Constants
  * @{
  */

#define    PMU_CR_SRPG_RST_EN_Pos                                 (30U)
#define    PMU_CR_SRPG_RST_EN_Msk                                 (0x1U << PMU_CR_SRPG_RST_EN_Pos)
#define    PMU_CR_SRPG_RST_EN                                     PMU_CR_SRPG_RST_EN_Msk

#define    PMU_CR_AVREF_SH_Pos                                    (24U)
#define    PMU_CR_AVREF_SH_Msk                                    (0x3U << PMU_CR_AVREF_SH_Pos)
#define    PMU_CR_AVREF_SH                                        PMU_CR_AVREF_SH_Msk

#define    PMU_CR_WKFSEL_Pos                                      (10U)
#define    PMU_CR_WKFSEL_Msk                                      (0x3U << PMU_CR_WKFSEL_Pos)
#define    PMU_CR_WKFSEL                                          PMU_CR_WKFSEL_Msk

#define    PMU_CR_SLPDP_Pos                                       (9U)
#define    PMU_CR_SLPDP_Msk                                       (0x1U << PMU_CR_SLPDP_Pos)
#define    PMU_CR_SLPDP                                           PMU_CR_SLPDP_Msk

#define    PMU_CR_PMOD_Pos                                        (0U)
#define    PMU_CR_PMOD_Msk                                        (0x3U << PMU_CR_PMOD_Pos)
#define    PMU_CR_PMOD                                            PMU_CR_PMOD_Msk

#define    PMU_WKTR_T2B_Pos                                       (6U)
#define    PMU_WKTR_T2B_Msk                                       (0x3U << PMU_WKTR_T2B_Pos)
#define    PMU_WKTR_T2B                                           PMU_WKTR_T2B_Msk

#define    PMU_WKTR_T2A_Pos                                       (4U)
#define    PMU_WKTR_T2A_Msk                                       (0x3U << PMU_WKTR_T2A_Pos)
#define    PMU_WKTR_T2A                                           PMU_WKTR_T2A_Msk

#define    PMU_WKTR_STPCLR_Pos                                    (2U)
#define    PMU_WKTR_STPCLR_Msk                                    (0x1U << PMU_WKTR_STPCLR_Pos)
#define    PMU_WKTR_STPCLR                                        PMU_WKTR_STPCLR_Msk

#define    PMU_WKTR_T1A_Pos                                       (0U)
#define    PMU_WKTR_T1A_Msk                                       (0x3U << PMU_WKTR_T1A_Pos)
#define    PMU_WKTR_T1A                                           PMU_WKTR_T1A_Msk

#define    PMU_WKFR1_RTCWKF_Pos                                    (28U)
#define    PMU_WKFR1_RTCWKF_Msk                                    (0x1U << PMU_WKFR1_RTCWKF_Pos)
#define    PMU_WKFR1_RTCWKF                                        PMU_WKFR1_RTCWKF_Msk

#define    PMU_WKFR1_SVDWKF_Pos                                    (27U)
#define    PMU_WKFR1_SVDWKF_Msk                                    (0x1U << PMU_WKFR1_SVDWKF_Pos)
#define    PMU_WKFR1_SVDWKF                                        PMU_WKFR1_SVDWKF_Msk

#define    PMU_WKFR1_LFDETWKF_Pos                                  (26U)
#define    PMU_WKFR1_LFDETWKF_Msk                                  (0x1U << PMU_WKFR1_LFDETWKF_Pos)
#define    PMU_WKFR1_LFDETWKF                                      PMU_WKFR1_LFDETWKF_Msk

#define    PMU_WKFR1_IOWKF_Pos                                     (24U)
#define    PMU_WKFR1_IOWKF_Msk                                     (0x1U << PMU_WKFR1_IOWKF_Pos)
#define    PMU_WKFR1_IOWKF                                         PMU_WKFR1_IOWKF_Msk

#define    PMU_WKFR1_I2CSMB2WKF_Pos                                (23U)
#define    PMU_WKFR1_I2CSMB2WKF_Msk                                (0x1U << PMU_WKFR1_I2CSMB2WKF_Pos)
#define    PMU_WKFR1_I2CSMB2WKF                                    PMU_WKFR1_I2CSMB2WKF_Msk

#define    PMU_WKFR1_I2CSMB1WKF_Pos                                (22U)
#define    PMU_WKFR1_I2CSMB1WKF_Msk                                (0x1U << PMU_WKFR1_I2CSMB1WKF_Pos)
#define    PMU_WKFR1_I2CSMB1WKF                                    PMU_WKFR1_I2CSMB1WKF_Msk

#define    PMU_WKFR1_I2CSMB0WKF_Pos                                (21U)
#define    PMU_WKFR1_I2CSMB0WKF_Msk                                (0x1U << PMU_WKFR1_I2CSMB0WKF_Pos)
#define    PMU_WKFR1_I2CSMB0WKF                                    PMU_WKFR1_I2CSMB0WKF_Msk

#define    PMU_WKFR1_FSCANWKF_Pos                                   (20U)
#define    PMU_WKFR1_FSCANWKF_Msk                                   (0x1U << PMU_WKFR1_FSCANWKF_Pos)
#define    PMU_WKFR1_FSCANWKF                                       PMU_WKFR1_FSCANWKF_Msk

#define    PMU_WKFR1_FDCANWKF_Pos                                   (19U)
#define    PMU_WKFR1_FDCANWKF_Msk                                   (0x1U << PMU_WKFR1_FDCANWKF_Pos)
#define    PMU_WKFR1_FDCANWKF                                       PMU_WKFR1_FDCANWKF_Msk

#define    PMU_WKFR1_COMP2WKF_Pos                                  (18U)
#define    PMU_WKFR1_COMP2WKF_Msk                                  (0x1U << PMU_WKFR1_COMP2WKF_Pos)
#define    PMU_WKFR1_COMP2WKF                                      PMU_WKFR1_COMP2WKF_Msk

#define    PMU_WKFR1_COMP1WKF_Pos                                  (17U)
#define    PMU_WKFR1_COMP1WKF_Msk                                  (0x1U << PMU_WKFR1_COMP1WKF_Pos)
#define    PMU_WKFR1_COMP1WKF                                      PMU_WKFR1_COMP1WKF_Msk

#define    PMU_WKFR1_COMP0WKF_Pos                                  (16U)
#define    PMU_WKFR1_COMP0WKF_Msk                                  (0x1U << PMU_WKFR1_COMP0WKF_Pos)
#define    PMU_WKFR1_COMP0WKF                                      PMU_WKFR1_COMP0WKF_Msk

#define    PMU_WKFR1_UART3_LINWKF_Pos                              (15U)
#define    PMU_WKFR1_UART3_LINWKF_Msk                              (0x1U << PMU_WKFR1_UART3_LINWKF_Pos)
#define    PMU_WKFR1_UART3_LINWKF                                  PMU_WKFR1_UART3_LINWKF_Msk

#define    PMU_WKFR1_UART2_LINWKF_Pos                              (14U)
#define    PMU_WKFR1_UART2_LINWKF_Msk                              (0x1U << PMU_WKFR1_UART2_LINWKF_Pos)
#define    PMU_WKFR1_UART2_LINWKF                                  PMU_WKFR1_UART2_LINWKF_Msk

#define    PMU_WKFR1_UART1_LINWKF_Pos                              (13U)
#define    PMU_WKFR1_UART1_LINWKF_Msk                              (0x1U << PMU_WKFR1_UART1_LINWKF_Pos)
#define    PMU_WKFR1_UART1_LINWKF                                  PMU_WKFR1_UART1_LINWKF_Msk

#define    PMU_WKFR1_UART0_LINWKF_Pos                              (12U)
#define    PMU_WKFR1_UART0_LINWKF_Msk                              (0x1U << PMU_WKFR1_UART0_LINWKF_Pos)
#define    PMU_WKFR1_UART0_LINWKF                                  PMU_WKFR1_UART0_LINWKF_Msk

#define    PMU_WKFR1_LPT16WKF_Pos                                  (11U)
#define    PMU_WKFR1_LPT16WKF_Msk                                  (0x1U << PMU_WKFR1_LPT16WKF_Pos)
#define    PMU_WKFR1_LPT16WKF                                      PMU_WKFR1_LPT16WKF_Msk

#define    PMU_WKFR1_BST16WKF_Pos                                  (10U)
#define    PMU_WKFR1_BST16WKF_Msk                                  (0x1U << PMU_WKFR1_BST16WKF_Pos)
#define    PMU_WKFR1_BST16WKF                                      PMU_WKFR1_BST16WKF_Msk

#define    PMU_WKFR1_DBGWKF_Pos                                    (8U)
#define    PMU_WKFR1_DBGWKF_Msk                                    (0x1U << PMU_WKFR1_DBGWKF_Pos)
#define    PMU_WKFR1_DBGWKF                                        PMU_WKFR1_DBGWKF_Msk

#define    PMU_WKFR1_UART3WKF_Pos                                  (7U)
#define    PMU_WKFR1_UART3WKF_Msk                                  (0x1U << PMU_WKFR1_UART3WKF_Pos)
#define    PMU_WKFR1_UART3WKF                                      PMU_WKFR1_UART3WKF_Msk

#define    PMU_WKFR1_UART2WKF_Pos                                  (6U)
#define    PMU_WKFR1_UART2WKF_Msk                                  (0x1U << PMU_WKFR1_UART2WKF_Pos)
#define    PMU_WKFR1_UART2WKF                                      PMU_WKFR1_UART2WKF_Msk

#define    PMU_WKFR1_UART1WKF_Pos                                  (5U)
#define    PMU_WKFR1_UART1WKF_Msk                                  (0x1U << PMU_WKFR1_UART1WKF_Pos)
#define    PMU_WKFR1_UART1WKF                                      PMU_WKFR1_UART1WKF_Msk

#define    PMU_WKFR1_UART0WKF_Pos                                  (4U)
#define    PMU_WKFR1_UART0WKF_Msk                                  (0x1U << PMU_WKFR1_UART0WKF_Pos)
#define    PMU_WKFR1_UART0WKF                                      PMU_WKFR1_UART0WKF_Msk

#define    PMU_WKFR1_LPU1WKF_Pos                                   (1U)
#define    PMU_WKFR1_LPU1WKF_Msk                                   (0x1U << PMU_WKFR1_LPU1WKF_Pos)
#define    PMU_WKFR1_LPU1WKF                                       PMU_WKFR1_LPU1WKF_Msk

#define    PMU_WKFR1_LPU0WKF_Pos                                   (0U)
#define    PMU_WKFR1_LPU0WKF_Msk                                   (0x1U << PMU_WKFR1_LPU0WKF_Pos)
#define    PMU_WKFR1_LPU0WKF                                       PMU_WKFR1_LPU0WKF_Msk

#define    PMU_WKFR2_WKPXF_Pos                                    (0U)
#define    PMU_WKFR2_WKPXF_Msk                                    (0xffU << PMU_WKFR2_WKPXF_Pos)
#define    PMU_WKFR2_WKPXF                                        PMU_WKFR2_WKPXF_Msk

#define    PMU_RAMCR_CTRAMPG_Pos                                  (6U)
#define    PMU_RAMCR_CTRAMPG_Msk                                  (0x3U << PMU_RAMCR_CTRAMPG_Pos)
#define    PMU_RAMCR_CTRAMPG                                      PMU_RAMCR_CTRAMPG_Msk

#define    PMU_RAMCR_CDRAMPG_Pos                                  (4U)
#define    PMU_RAMCR_CDRAMPG_Msk                                  (0x3U << PMU_RAMCR_CDRAMPG_Pos)
#define    PMU_RAMCR_CDRAMPG                                      PMU_RAMCR_CDRAMPG_Msk

#define    PMU_RAMCR_RAM1PG_Pos                                   (2U)
#define    PMU_RAMCR_RAM1PG_Msk                                   (0x3U << PMU_RAMCR_RAM1PG_Pos)
#define    PMU_RAMCR_RAM1PG                                       PMU_RAMCR_RAM1PG_Msk

#define    PMU_RAMCR_RAM0PG_Pos                                   (0U)
#define    PMU_RAMCR_RAM0PG_Msk                                   (0x3U << PMU_RAMCR_RAM0PG_Pos)
#define    PMU_RAMCR_RAM0PG                                       PMU_RAMCR_RAM0PG_Msk

#define    PMU_BUFCR_AVREFBUF_OUTEN_Pos                           (5U)
#define    PMU_BUFCR_AVREFBUF_OUTEN_Msk                           (0x1U << PMU_BUFCR_AVREFBUF_OUTEN_Pos)
#define    PMU_BUFCR_AVREFBUF_OUTEN                               PMU_BUFCR_AVREFBUF_OUTEN_Msk

#define    PMU_BUFCR_AVREFBUF_EN_Pos                              (4U)
#define    PMU_BUFCR_AVREFBUF_EN_Msk                              (0x1U << PMU_BUFCR_AVREFBUF_EN_Pos)
#define    PMU_BUFCR_AVREFBUF_EN                                  PMU_BUFCR_AVREFBUF_EN_Msk

#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Pos                        (3U)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN_Msk                        (0x1U << PMU_BUFCR_VPTATBUFFER_OUTEN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_OUTEN                            PMU_BUFCR_VPTATBUFFER_OUTEN_Msk

#define    PMU_BUFCR_VPTATBUFFER_EN_Pos                           (2U)
#define    PMU_BUFCR_VPTATBUFFER_EN_Msk                           (0x1U << PMU_BUFCR_VPTATBUFFER_EN_Pos)
#define    PMU_BUFCR_VPTATBUFFER_EN                               PMU_BUFCR_VPTATBUFFER_EN_Msk

#define    PMU_PHYCR_PONRSTB_Pos                                  (1U)
#define    PMU_PHYCR_PONRSTB_Msk                                  (0x1U << PMU_PHYCR_PONRSTB_Pos)
#define    PMU_PHYCR_PONRSTB                                      PMU_PHYCR_PONRSTB_Msk

#define    PMU_PHYCR_PLVRDY_Pos                                   (0U)
#define    PMU_PHYCR_PLVRDY_Msk                                   (0x1U << PMU_PHYCR_PLVRDY_Pos)
#define    PMU_PHYCR_PLVRDY                                       PMU_PHYCR_PLVRDY_Msk

#define    PMU_PTAT_CR_PTAT_EN_Pos                                (0U)
#define    PMU_PTAT_CR_PTAT_EN_Msk                                (0x1U << PMU_PTAT_CR_PTAT_EN_Pos)
#define    PMU_PTAT_CR_PTAT_EN                                    PMU_PTAT_CR_PTAT_EN_Msk

#define    FL_PMU_WAKEUP0_PIN                                     (0x1U << 0U)
#define    FL_PMU_WAKEUP1_PIN                                     (0x1U << 1U)
#define    FL_PMU_WAKEUP2_PIN                                     (0x1U << 2U)
#define    FL_PMU_WAKEUP3_PIN                                     (0x1U << 3U)
#define    FL_PMU_WAKEUP4_PIN                                     (0x1U << 4U)
#define    FL_PMU_WAKEUP5_PIN                                     (0x1U << 5U)
#define    FL_PMU_WAKEUP6_PIN                                     (0x1U << 6U)
#define    FL_PMU_WAKEUP7_PIN                                     (0x1U << 7U)

#define    FL_PMU_RCHF_WAKEUP_FREQ_8MHZ                           (0x0U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_16MHZ                          (0x1U << PMU_CR_WKFSEL_Pos)
#define    FL_PMU_RCHF_WAKEUP_FREQ_24MHZ                          (0x2U << PMU_CR_WKFSEL_Pos)

#define    FL_PMU_AVREF_HOLDTIME_0P5MS                            (0x0U << PMU_CR_AVREF_SH_Pos)
#define    FL_PMU_AVREF_HOLDTIME_1MS                              (0x1U << PMU_CR_AVREF_SH_Pos)
#define    FL_PMU_AVREF_HOLDTIME_2MS                              (0x2U << PMU_CR_AVREF_SH_Pos)
#define    FL_PMU_AVREF_HOLDTIME_4MS                              (0x3U << PMU_CR_AVREF_SH_Pos)

#define    FL_PMU_SLEEP_MODE_DEEPSLEEP                            (0x1U << PMU_CR_SLPDP_Pos)
#define    FL_PMU_SLEEP_MODE_SLEEP                                (0x0U << PMU_CR_SLPDP_Pos)

#define    FL_PMU_POWER_MODE_ACTIVE                               (0x0U << PMU_CR_PMOD_Pos)
#define    FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP                   (0x2U << PMU_CR_PMOD_Pos)

#define    FL_PMU_WAKEUP_DELAYT2B_4US                             (0x0U << PMU_WKTR_T2B_Pos)
#define    FL_PMU_WAKEUP_DELAYT2B_8US                             (0x1U << PMU_WKTR_T2B_Pos)
#define    FL_PMU_WAKEUP_DELAYT2B_16US                            (0x2U << PMU_WKTR_T2B_Pos)
#define    FL_PMU_WAKEUP_DELAYT2B_32US                            (0x3U << PMU_WKTR_T2B_Pos)

#define    FL_PMU_WAKEUP_DELAYT2A_0US                             (0x0U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAYT2A_2US                             (0x1U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAYT2A_4US                             (0x2U << PMU_WKTR_T2A_Pos)
#define    FL_PMU_WAKEUP_DELAYT2A_8US                             (0x3U << PMU_WKTR_T2A_Pos)

#define    FL_PMU_FLASH_STOP_CLEAR_MODE_SYNCHRONOUS               (0x0U << PMU_WKTR_STPCLR_Pos)
#define    FL_PMU_FLASH_STOP_CLEAR_MODE_ASYNCHRONOUS              (0x1U << PMU_WKTR_STPCLR_Pos)

#define    FL_PMU_WAKEUP_DELAYT1A_0US                                (0x0U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAYT1A_2US                                (0x1U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAYT1A_4US                                (0x2U << PMU_WKTR_T1A_Pos)
#define    FL_PMU_WAKEUP_DELAYT1A_8US                                (0x3U << PMU_WKTR_T1A_Pos)

#define    FL_PMU_CACHETRAM_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION     (0x0U << PMU_RAMCR_CTRAMPG_Pos)
#define    FL_PMU_CACHETRAM_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN     (0x1U << PMU_RAMCR_CTRAMPG_Pos)
#define    FL_PMU_CACHETRAM_SLEEP_OR_DEEPSLEEP_RETENTION            (0x2U << PMU_RAMCR_CTRAMPG_Pos)
#define    FL_PMU_CACHETRAM_SLEEP_OR_DEEPSLEEP_POWERDOWN            (0x3U << PMU_RAMCR_CTRAMPG_Pos)

#define    FL_PMU_CACHEDRAM_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION   (0x0U << PMU_RAMCR_CDRAMPG_Pos)
#define    FL_PMU_CACHEDRAM_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN   (0x1U << PMU_RAMCR_CDRAMPG_Pos)
#define    FL_PMU_CACHEDRAM_SLEEP_OR_DEEPSLEEP_RETENTION          (0x2U << PMU_RAMCR_CDRAMPG_Pos)
#define    FL_PMU_CACHEDRAM_SLEEP_OR_DEEPSLEEP_POWERDOWN          (0x3U << PMU_RAMCR_CDRAMPG_Pos)

#define    FL_PMU_RAM1_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION      (0x0U << PMU_RAMCR_RAM1PG_Pos)
#define    FL_PMU_RAM1_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN      (0x1U << PMU_RAMCR_RAM1PG_Pos)
#define    FL_PMU_RAM1_SLEEP_OR_DEEPSLEEP_RETENTION             (0x2U << PMU_RAMCR_RAM1PG_Pos)
#define    FL_PMU_RAM1_SLEEP_OR_DEEPSLEEP_POWERDOWN             (0x3U << PMU_RAMCR_RAM1PG_Pos)

#define    FL_PMU_RAM0_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION      (0x0U << PMU_RAMCR_RAM0PG_Pos)
#define    FL_PMU_RAM0_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN      (0x1U << PMU_RAMCR_RAM0PG_Pos)
#define    FL_PMU_RAM0_SLEEP_OR_DEEPSLEEP_RETENTION             (0x2U << PMU_RAMCR_RAM0PG_Pos)
#define    FL_PMU_RAM0_SLEEP_OR_DEEPSLEEP_POWERDOWN             (0x3U << PMU_RAMCR_RAM0PG_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup PMU_FL_Exported_Functions PMU Exported Functions
  * @{
  */

/**
  * @brief    Enable reset srpg under deepsleep
  * @rmtoll   CR    SRPG_RST_EN    FL_PMU_EnableResetSrpgUnderDeepSleep
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableResetSrpgUnderDeepSleep(PMU_Type *PMUx)
{
    SET_BIT(PMUx->CR, PMU_CR_SRPG_RST_EN_Msk);
}

/**
  * @brief    Get reset srpg under deepsleep Enable Status
  * @rmtoll   CR    SRPG_RST_EN    FL_PMU_IsEnabledResetSrpgUnderDeepSleep
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledResetSrpgUnderDeepSleep(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_SRPG_RST_EN_Msk) == PMU_CR_SRPG_RST_EN_Msk);
}

/**
  * @brief    Disable reset srpg under deepsleep
  * @rmtoll   CR    SRPG_RST_EN    FL_PMU_DisableResetSrpgUnderDeepSleep
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableResetSrpgUnderDeepSleep(PMU_Type *PMUx)
{
    CLEAR_BIT(PMUx->CR, PMU_CR_SRPG_RST_EN_Msk);
}

/**
  * @brief    Set AVREF Sample-Hold Period
  * @rmtoll   CR    AVREF_SH    FL_PMU_SetSampleHoldPeriod
  * @param    PMUx PMU instance
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_0P5MS
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_1MS
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_2MS
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_4MS
  * @param    Freq This parameter can be one of the following values:
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetSampleHoldPeriod(PMU_Type *PMUx, uint32_t Freq)
{
    MODIFY_REG(PMUx->CR, PMU_CR_AVREF_SH_Msk, Freq);
}

/**
  * @brief    Get AVREF Sample-Hold Period
  * @rmtoll   CR    AVREF_SH    FL_PMU_GetSampleHoldPeriod
  * @param    PMUx PMU instance
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_0P5MS
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_1MS
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_2MS
  *           @arg @ref FL_PMU_AVREF_HOLDTIME_4MS
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PMU_GetSampleHoldPeriod(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_AVREF_SH_Msk));
}

/**
  * @brief    Set RCHF Frequency After Wakeup
  * @rmtoll   CR    WKFSEL    FL_PMU_SetRCHFWakeupFrequency
  * @param    PMUx PMU instance
  * @param    Freq This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_8MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_16MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_24MHZ
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetRCHFWakeupFrequency(PMU_Type *PMUx, uint32_t Freq)
{
    MODIFY_REG(PMUx->CR, PMU_CR_WKFSEL_Msk, Freq);
}

/**
  * @brief    Get RCHF Frequency After Wakeup Setting
  * @rmtoll   CR    WKFSEL    FL_PMU_GetRCHFWakeupFrequency
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_8MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_16MHZ
  *           @arg @ref FL_PMU_RCHF_WAKEUP_FREQ_24MHZ
  */
__STATIC_INLINE uint32_t FL_PMU_GetRCHFWakeupFrequency(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_WKFSEL_Msk));
}

/**
  * @brief    Set Sleep Mode
  * @rmtoll   CR    SLPDP    FL_PMU_SetSleepMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_SLEEP_MODE_DEEPSLEEP
  *           @arg @ref FL_PMU_SLEEP_MODE_SLEEP
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetSleepMode(PMU_Type *PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_SLPDP_Msk, mode);
}

/**
  * @brief    Get Sleep Mode Setting
  * @rmtoll   CR    SLPDP    FL_PMU_GetSleepMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_SLEEP_MODE_DEEPSLEEP
  *           @arg @ref FL_PMU_SLEEP_MODE_SLEEP
  */
__STATIC_INLINE uint32_t FL_PMU_GetSleepMode(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_SLPDP_Msk));
}

/**
  * @brief    Set Low Power Mode
  * @rmtoll   CR    PMOD    FL_PMU_SetLowPowerMode
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_POWER_MODE_ACTIVE
  *           @arg @ref FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetLowPowerMode(PMU_Type *PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->CR, PMU_CR_PMOD_Msk, mode);
}

/**
  * @brief    Get Low Power Mode Setting
  * @rmtoll   CR    PMOD    FL_PMU_GetLowPowerMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PMU_GetLowPowerMode(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->CR, PMU_CR_PMOD_Msk));
}

/**
  * @brief    Set Extra Wakeup Delay T2B Under Sleep/DeepSleep Mode
  * @rmtoll   WKTR    T2B    FL_PMU_SetWakeupDelayT2B
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_8US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_16US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_32US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetWakeupDelayT2B(PMU_Type *PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T2B_Msk, time);
}

/**
  * @brief    Get Extra Wakeup Delay T2B Under Sleep/DeepSleep Mode Setting
  * @rmtoll   WKTR    T2B    FL_PMU_GetWakeupDelayT2B
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_8US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_16US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2B_32US
  */
__STATIC_INLINE uint32_t FL_PMU_GetWakeupDelayT2B(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T2B_Msk));
}

/**
  * @brief    Set Extra Wakeup Delay T2A Under Sleep/DeepSleep Mode
  * @rmtoll   WKTR    T2A    FL_PMU_SetWakeupDelayT2A
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_0US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_2US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_8US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetWakeupDelayT2A(PMU_Type *PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T2A_Msk, time);
}

/**
  * @brief    Get Extra Wakeup Delay T2A Under Sleep/DeepSleep Mode Setting
  * @rmtoll   WKTR    T2A    FL_PMU_GetWakeupDelayT2A
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_0US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_2US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAYT2A_8US
  */
__STATIC_INLINE uint32_t FL_PMU_GetWakeupDelayT2A(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T2A_Msk));
}

/**
  * @brief    Set Flash Stop Signal Clear Way
  * @rmtoll   WKTR    STPCLR    FL_PMU_SetFlashStopSignalClearMode
  * @param    PMUx PMU instance
  * @param    config This parameter can be one of the following values:
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_SYNCHRONOUS
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_ASYNCHRONOUS
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetFlashStopSignalClearMode(PMU_Type *PMUx, uint32_t config)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_STPCLR_Msk, config);
}

/**
  * @brief    Get Flash Stop Signal Clear Way Setting
  * @rmtoll   WKTR    STPCLR    FL_PMU_GetFlashStopSignalClearMode
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_SYNCHRONOUS
  *           @arg @ref FL_PMU_FLASH_STOP_CLEAR_MODE_ASYNCHRONOUS
  */
__STATIC_INLINE uint32_t FL_PMU_GetFlashStopSignalClearMode(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_STPCLR_Msk));
}

/**
  * @brief    Set Extra Wakeup Delay Under Sleep/DeepSleep Mode
  * @rmtoll   WKTR    T1A    FL_PMU_SetWakeupDelay
  * @param    PMUx PMU instance
  * @param    time This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_0US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_2US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_8US
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetWakeupDelayT1A(PMU_Type *PMUx, uint32_t time)
{
    MODIFY_REG(PMUx->WKTR, PMU_WKTR_T1A_Msk, time);
}

/**
  * @brief    Get Extra Wakeup Delay Under Sleep/DeepSleep Mode Setting
  * @rmtoll   WKTR    T1A    FL_PMU_GetWakeupDelay
  * @param    PMUx PMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP_DELAY_0US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_2US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_4US
  *           @arg @ref FL_PMU_WAKEUP_DELAY_8US
  */
__STATIC_INLINE uint32_t FL_PMU_GetWakeupDelayT1A(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKTR, PMU_WKTR_T1A_Msk));
}

/**
  * @brief    Get RTC interrupt wakeup flag
  * @rmtoll   WKFR1    RTCWKF    FL_PMU_IsActiveFlag_WakeupRTC
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupRTC(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_RTCWKF_Msk) == (PMU_WKFR1_RTCWKF_Msk));
}

/**
  * @brief    Get SVD interrupt wakeup flag
  * @rmtoll   WKFR1    SVDWKF    FL_PMU_IsActiveFlag_WakeupSVD
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupSVD(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_SVDWKF_Msk) == (PMU_WKFR1_SVDWKF_Msk));
}

/**
  * @brief    Get LFDET interrupt wakeup flag
  * @rmtoll   WKFR1    LFDETWKF    FL_PMU_IsActiveFlag_WakeupLFDET
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLFDET(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_LFDETWKF_Msk) == (PMU_WKFR1_LFDETWKF_Msk));
}

/**
  * @brief    Get IO interrupt wakeup flag
  * @rmtoll   WKFR1    IOWKF    FL_PMU_IsActiveFlag_WakeupEXTI
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupEXTI(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_IOWKF_Msk) == (PMU_WKFR1_IOWKF_Msk));
}

/**
  * @brief    Get I2CSMB2 interrupt wakeup flag
  * @rmtoll   WKFR1    I2CSMB2WKF    FL_PMU_IsActiveFlag_WakeupI2CSMB2
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2CSMB2(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_I2CSMB2WKF_Msk) == (PMU_WKFR1_I2CSMB2WKF_Msk));
}

/**
  * @brief    Get I2CSMB1 interrupt wakeup flag
  * @rmtoll   WKFR1    I2CSMB1WKF    FL_PMU_IsActiveFlag_WakeupI2CSMB1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2CSMB1(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_I2CSMB1WKF_Msk) == (PMU_WKFR1_I2CSMB1WKF_Msk));
}

/**
  * @brief    Get I2CSMB0 interrupt wakeup flag
  * @rmtoll   WKFR1    I2CSMB0WKF    FL_PMU_IsActiveFlag_WakeupI2CSMB0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupI2CSMB0(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_I2CSMB0WKF_Msk) == (PMU_WKFR1_I2CSMB0WKF_Msk));
}

/**
  * @brief    Get FSCAN interrupt wakeup flag
  * @rmtoll   WKFR1    FSCANWKF    FL_PMU_IsActiveFlag_WakeupCAN1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCAN1(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_FSCANWKF_Msk) == (PMU_WKFR1_FSCANWKF_Msk));
}

/**
  * @brief    Get FDCAN interrupt wakeup flag
  * @rmtoll   WKFR1    FDCANWKF    FL_PMU_IsActiveFlag_WakeupCAN0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupFDCAN(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_FDCANWKF_Msk) == (PMU_WKFR1_FDCANWKF_Msk));
}

/**
  * @brief    Get COMP2 interrrupt wakeup flag
  * @rmtoll   WKFR1    COMP2WKF    FL_PMU_IsActiveFlag_WakeupCOMP2
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCOMP2(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_COMP2WKF_Msk) == (PMU_WKFR1_COMP2WKF_Msk));
}

/**
  * @brief    Get COMP1 interrrupt wakeup flag
  * @rmtoll   WKFR1    COMP1WKF    FL_PMU_IsActiveFlag_WakeupCOMP1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCOMP1(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_COMP1WKF_Msk) == (PMU_WKFR1_COMP1WKF_Msk));
}

/**
  * @brief    Get COMP0 interrrupt wakeup flag
  * @rmtoll   WKFR1    COMP0WKF    FL_PMU_IsActiveFlag_WakeupCOMP0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupCOMP0(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_COMP0WKF_Msk) == (PMU_WKFR1_COMP0WKF_Msk));
}

/**
  * @brief    Get UART3 LIN interrupt wakeup flag
  * @rmtoll   WKFR1    UART3_LINWKF    FL_PMU_IsActiveFlag_WakeupUART3LIN
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART3LIN(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART3_LINWKF_Msk) == (PMU_WKFR1_UART3_LINWKF_Msk));
}

/**
  * @brief    Get UART2 LIN  interrupt wakeup flag
  * @rmtoll   WKFR1    UART2_LINWKF    FL_PMU_IsActiveFlag_WakeupUART2LIN
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART2LIN(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART2_LINWKF_Msk) == (PMU_WKFR1_UART2_LINWKF_Msk));
}

/**
  * @brief    Get UART1 LIN  interrupt wakeup flag
  * @rmtoll   WKFR1    UART1_LINWKF    FL_PMU_IsActiveFlag_WakeupUART1LIN
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART1LIN(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART1_LINWKF_Msk) == (PMU_WKFR1_UART1_LINWKF_Msk));
}

/**
  * @brief    Get UART0 LIN  interrupt wakeup flag
  * @rmtoll   WKFR1    UART0_LINWKF    FL_PMU_IsActiveFlag_WakeupUART0LIN
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART0LIN(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART0_LINWKF_Msk) == (PMU_WKFR1_UART0_LINWKF_Msk));
}

/**
  * @brief    Get LPTIM16 interrupt wakeup flag
  * @rmtoll   WKFR1    LPT16WKF    FL_PMU_IsActiveFlag_WakeupLPTIM16
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPTIM16(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_LPT16WKF_Msk) == (PMU_WKFR1_LPT16WKF_Msk));
}

/**
  * @brief    Get BSTIM16 interrupt wakeup flag
  * @rmtoll   WKFR1    BST16WKF    FL_PMU_IsActiveFlag_WakeupBSTIM16
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupBSTIM16(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_BST16WKF_Msk) == (PMU_WKFR1_BST16WKF_Msk));
}

/**
  * @brief    Get CPU Debugger wakeup flag
  * @rmtoll   WKFR1    DBGWKF    FL_PMU_IsActiveFlag_WakeupDBG
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupDBG(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_DBGWKF_Msk) == (PMU_WKFR1_DBGWKF_Msk));
}

/**
  * @brief    Clear CPU Debugger wakeup flag
  * @rmtoll   WKFR1    DBGWKF    FL_PMU_ClearFlag_WakeupDBG
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_WakeupDBG(PMU_Type *PMUx)
{
    WRITE_REG(PMUx->WKFR1, PMU_WKFR1_DBGWKF_Msk);
}

/**
  * @brief    Get UART3 interrupt wakeup flag
  * @rmtoll   WKFR1    UART3WKF    FL_PMU_IsActiveFlag_WakeupUART3
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART3(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART3WKF_Msk) == (PMU_WKFR1_UART3WKF_Msk));
}

/**
  * @brief    Get UART2 interrupt wakeup flag
  * @rmtoll   WKFR1    UART2WKF    FL_PMU_IsActiveFlag_WakeupUART2
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART2(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART2WKF_Msk) == (PMU_WKFR1_UART2WKF_Msk));
}

/**
  * @brief    Get UART1 interrupt wakeup flag
  * @rmtoll   WKFR1    UART1WKF    FL_PMU_IsActiveFlag_WakeupUART1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART1(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART1WKF_Msk) == (PMU_WKFR1_UART1WKF_Msk));
}

/**
  * @brief    Get UART0 interrupt wakeup flag
  * @rmtoll   WKFR1    UART0WKF    FL_PMU_IsActiveFlag_WakeupUART0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupUART0(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_UART0WKF_Msk) == (PMU_WKFR1_UART0WKF_Msk));
}

/**
  * @brief    Get LPUART1 interrupt wakeup flag
  * @rmtoll   WKFR1    LPU1WKF    FL_PMU_IsActiveFlag_WakeupLPUART1
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPUART1(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_LPU1WKF_Msk) == (PMU_WKFR1_LPU1WKF_Msk));
}

/**
  * @brief    Get LPUART0 interrupt wakeup flag
  * @rmtoll   WKFR1    LPU0WKF    FL_PMU_IsActiveFlag_WakeupLPUART0
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupLPUART0(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR1, PMU_WKFR1_LPU0WKF_Msk) == (PMU_WKFR1_LPU0WKF_Msk));
}

/**
  * @brief    Get pinx wakeup flag
  * @rmtoll   WKFR2    WKPXF    FL_PMU_IsActiveFlag_WakeupPIN
  * @param    PMUx PMU instance
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP0_PIN
  *           @arg @ref FL_PMU_WAKEUP1_PIN
  *           @arg @ref FL_PMU_WAKEUP2_PIN
  *           @arg @ref FL_PMU_WAKEUP3_PIN
  *           @arg @ref FL_PMU_WAKEUP4_PIN
  *           @arg @ref FL_PMU_WAKEUP5_PIN
  *           @arg @ref FL_PMU_WAKEUP6_PIN
  *           @arg @ref FL_PMU_WAKEUP7_PIN
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_WakeupPIN(PMU_Type *PMUx, uint32_t Pin)
{
    return (uint32_t)(READ_BIT(PMUx->WKFR2, ((Pin & 0xff) << 0x0U)) == ((Pin & 0xff) << 0x0U));
}

/**
  * @brief    Clear pinx wakeup flag
  * @rmtoll   WKFR1    WKPXF    FL_PMU_ClearFlag_WakeupPIN
  * @param    PMUx PMU instance
  * @param    Pin This parameter can be one of the following values:
  *           @arg @ref FL_PMU_WAKEUP0_PIN
  *           @arg @ref FL_PMU_WAKEUP1_PIN
  *           @arg @ref FL_PMU_WAKEUP2_PIN
  *           @arg @ref FL_PMU_WAKEUP3_PIN
  *           @arg @ref FL_PMU_WAKEUP4_PIN
  *           @arg @ref FL_PMU_WAKEUP5_PIN
  *           @arg @ref FL_PMU_WAKEUP6_PIN
  *           @arg @ref FL_PMU_WAKEUP7_PIN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_WakeupPIN(PMU_Type *PMUx, uint32_t Pin)
{
    WRITE_REG(PMUx->WKFR2, ((Pin & 0xff) << 0x0U));
}

/**
  * @brief    Set cache tag ram Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    CTRAMPG    FL_PMU_SetCacheTagRamPowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_CTRAMPG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_CTRAMPG_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN
  *           @arg @ref FL_PMU_CTRAMPG_SLEEP_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_CTRAMPG_SLEEP_OR_DEEPSLEEP_POWERDOWN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetCacheTagRamPowerControl(PMU_Type *PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->RAMCR, PMU_RAMCR_CTRAMPG_Msk, mode);
}

/**
  * @brief    Get cache tag ram Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    CTRAMPG    FL_PMU_GetCacheTagRamPowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_CTRAMPG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_CTRAMPG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  */
__STATIC_INLINE uint32_t FL_PMU_GetCacheTagRamPowerControl(PMU_Type *PMUx, uint32_t mode)
{
    return (uint32_t)(READ_BIT(PMUx->RAMCR, PMU_RAMCR_CTRAMPG_Msk));
}

/**
  * @brief    Set cache tag data Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    CDRAMPG    FL_PMU_SetCacheDataRamPowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_CDRAMPGPG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_CDRAMPGPG_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN
  *           @arg @ref FL_PMU_CDRAMPGPG_SLEEP_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_CDRAMPGPG_SLEEP_OR_DEEPSLEEP_POWERDOWN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetCacheDataRamPowerControl(PMU_Type *PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->RAMCR, PMU_RAMCR_CDRAMPG_Msk, mode);
}

/**
  * @brief    Get cache tag data Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    CDRAMPG    FL_PMU_GetCacheDataRamPowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_CDRAMPG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_CDRAMPG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  */
__STATIC_INLINE uint32_t FL_PMU_GetCacheDataRamPowerControl(PMU_Type *PMUx, uint32_t mode)
{
    return (uint32_t)(READ_BIT(PMUx->RAMCR, PMU_RAMCR_CDRAMPG_Msk));
}

/**
  * @brief    Set Ram1 Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    RAM1PG    FL_PMU_SetPdRam1PowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RAM1PG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_RAM1PG_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN
  *           @arg @ref FL_PMU_RAM1PG_SLEEP_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_RAM1PG_SLEEP_OR_DEEPSLEEP_POWERDOWN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetPdRam1PowerControl(PMU_Type *PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->RAMCR, PMU_RAMCR_RAM1PG_Msk, mode);
}

/**
  * @brief    Get Ram1 Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    RAM1PG    FL_PMU_GetPdRam1PowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RAM1PG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_RAM1PG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  */
__STATIC_INLINE uint32_t FL_PMU_GetPdRam1PowerControl(PMU_Type *PMUx, uint32_t mode)
{
    return (uint32_t)(READ_BIT(PMUx->RAMCR, PMU_RAMCR_RAM1PG_Msk));
}

/**
  * @brief    Set Ram0 Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    RAM0PG    FL_PMU_SetPdRam0PowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RAM0PG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_RAM0PG_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN
  *           @arg @ref FL_PMU_RAM0PG_SLEEP_OR_DEEPSLEEP_RETENTION
  *           @arg @ref FL_PMU_RAM0PG_SLEEP_OR_DEEPSLEEP_POWERDOWN
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_SetPdRam0PowerControl(PMU_Type *PMUx, uint32_t mode)
{
    MODIFY_REG(PMUx->RAMCR, PMU_RAMCR_RAM0PG_Msk, mode);
}

/**
  * @brief    Get Ram0 Power control, sleep / deepsleep mode is valid
  * @rmtoll   RAMCR    RAM0PG    FL_PMU_GetPdRam0PowerControl
  * @param    PMUx PMU instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_PMU_RAM0PG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_PMU_RAM0PG_SLEEP_NORMAL_OR_DEEPSLEEP_RETENTION
  */
__STATIC_INLINE uint32_t FL_PMU_GetPdRam0PowerControl(PMU_Type *PMUx, uint32_t mode)
{
    return (uint32_t)(READ_BIT(PMUx->RAMCR, PMU_RAMCR_RAM0PG_Msk));
}

/**
  * @brief    Enable AVREF Buffer Output
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_EnableAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableAVREFBufferOutput(PMU_Type *PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Get AVREF Buffer Output Enable Status
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_IsEnabledAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledAVREFBufferOutput(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk) == PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Disable AVREF Buffer Output
  * @rmtoll   BUFCR    AVREFBUF_OUTEN    FL_PMU_DisableAVREFBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableAVREFBufferOutput(PMU_Type *PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_OUTEN_Msk);
}

/**
  * @brief    Enable AVREF Buffer
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_EnableAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableAVREFBuffer(PMU_Type *PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Get AVREF Buffer Enable Status
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_IsEnabledAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledAVREFBuffer(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk) == PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Disable AVREF Buffer
  * @rmtoll   BUFCR    AVREFBUF_EN    FL_PMU_DisableAVREFBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableAVREFBuffer(PMU_Type *PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_AVREFBUF_EN_Msk);
}

/**
  * @brief    Enable VPTAT Buffer Output
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_EnableVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableVPTATBufferOutput(PMU_Type *PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Get VPTAT Buffer Output Enable Status
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_IsEnabledVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledVPTATBufferOutput(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk) == PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Disable VPTAT Buffer Output
  * @rmtoll   BUFCR    VPTATBUFFER_OUTEN    FL_PMU_DisableVPTATBufferOutput
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableVPTATBufferOutput(PMU_Type *PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_OUTEN_Msk);
}

/**
  * @brief    Enable VPTAT Buffer
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_EnableVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableVPTATBuffer(PMU_Type *PMUx)
{
    SET_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Get VPTAT Buffer Enable Status
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_IsEnabledVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledVPTATBuffer(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk) == PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Disable VPTAT Buffer
  * @rmtoll   BUFCR    VPTATBUFFER_EN    FL_PMU_DisableVPTATBuffer
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableVPTATBuffer(PMU_Type *PMUx)
{
    CLEAR_BIT(PMUx->BUFCR, PMU_BUFCR_VPTATBUFFER_EN_Msk);
}

/**
  * @brief    Get USB PHY Enable Status
  * @rmtoll   PHYCR    PONRSTB    FL_PMU_IsActiveFlag_USBPHYReset
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_USBPHYReset(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->PHYCR, PMU_PHYCR_PONRSTB_Msk) == (PMU_PHYCR_PONRSTB_Msk));
}

/**
  * @brief    Clear USB PHY Enable Status
  * @rmtoll   PHYCR    PONRSTB    FL_PMU_ClearFlag_USBPHYReset
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_USBPHYReset(PMU_Type *PMUx)
{
    WRITE_REG(PMUx->PHYCR, PMU_PHYCR_PONRSTB_Msk);
}

/**
  * @brief    Get USB PHY Power Ready Flag
  * @rmtoll   PHYCR    PLVRDY    FL_PMU_IsActiveFlag_USBPHYPowerReadyFlag
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsActiveFlag_USBPHYPowerReadyFlag(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->PHYCR, PMU_PHYCR_PLVRDY_Msk) == (PMU_PHYCR_PLVRDY_Msk));
}

/**
  * @brief    Clear USB PHY Power Ready Flag
  * @rmtoll   PHYCR    PLVRDY    FL_PMU_ClearFlag_USBPHYPowerReadyFlag
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_ClearFlag_USBPHYPowerReadyFlag(PMU_Type *PMUx)
{
    WRITE_REG(PMUx->PHYCR, PMU_PHYCR_PLVRDY_Msk);
}

/**
  * @brief    Enable Temperatue Sensor
  * @rmtoll   PTAT_CR    PTAT_EN    FL_PMU_EnableTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_EnableTemperatureSensor(PMU_Type *PMUx)
{
    SET_BIT(PMUx->PTAT_CR, PMU_PTAT_CR_PTAT_EN_Msk);
}

/**
  * @brief    Get Temperatue Sensor Enable Status
  * @rmtoll   PTAT_CR    PTAT_EN    FL_PMU_IsEnabledTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_PMU_IsEnabledTemperatureSensor(PMU_Type *PMUx)
{
    return (uint32_t)(READ_BIT(PMUx->PTAT_CR, PMU_PTAT_CR_PTAT_EN_Msk) == PMU_PTAT_CR_PTAT_EN_Msk);
}

/**
  * @brief    Disable Temperatue Sensor
  * @rmtoll   PTAT_CR    PTAT_EN    FL_PMU_DisableTemperatureSensor
  * @param    PMUx PMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_PMU_DisableTemperatureSensor(PMU_Type *PMUx)
{
    CLEAR_BIT(PMUx->PTAT_CR, PMU_PTAT_CR_PTAT_EN_Msk);
}

/**
  * @}
  */

/** @defgroup PMU_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_PMU_Sleep_DeInit(PMU_Type *PMUx);
FL_ErrorStatus FL_PMU_Sleep_Init(PMU_Type *PMUx, FL_PMU_SleepInitTypeDef *LPM_InitStruct);
void FL_PMU_StructInit(FL_PMU_SleepInitTypeDef *LPM_InitStruct);
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_PMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-08-24*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
