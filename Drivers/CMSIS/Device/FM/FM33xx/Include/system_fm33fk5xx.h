/**************************************************************************//**
 * @file     system_fm33fk5xx.h
 * @brief    CMSIS Cortex-M33 Device Peripheral Access Layer Header File for
 *           Device FM33FK5XX
 * @version  V1.0.0
 * @date     10. Sep 2021
 *
 * @note
 *
 ******************************************************************************/
/* Copyright (c) 2012 ARM LIMITED

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/

#ifndef SYSTEM_FM33FK5XX_H
#define SYSTEM_FM33FK5XX_H

#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief CMSIS Device version number
  */
#define __FM33FK5_CMSIS_VERSION_MAIN   (0x01U) /*!< [31:24] main version */
#define __FM33FK5_CMSIS_VERSION_SUB1   (0x00U) /*!< [23:16] sub1 version */
#define __FM33FK5_CMSIS_VERSION_SUB2   (0x04U) /*!< [15:8]  sub2 version */
#define __FM33FK5_CMSIS_VERSION_RC     (0x00U) /*!< [7:0]  release candidate */
#define __FM33FK5_CMSIS_VERSION        ((__FM33FK5_CMSIS_VERSION_MAIN << 24U)\
                                       |(__FM33FK5_CMSIS_VERSION_SUB1 << 16U)\
                                       |(__FM33FK5_CMSIS_VERSION_SUB2 << 8U )\
                                       |(__FM33FK5_CMSIS_VERSION_RC))

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>

/* Device Includes -----------------------------------------------------------*/
#include "fm33fk5xx.h"

/* Trim Values ---------------------------------------------------------------*/
/* Validate Function */
#define LDT_CHECK(_N_VALUE_, _T_VALUE_)                         \
                            ((((_N_VALUE_ >> 16) & 0xffff) ==   \
                            ((~_N_VALUE_) & 0xffff)) ? _N_VALUE_ : _T_VALUE_)

/* Trim Values Address */
#define RCLP_LDT_TRIM       (*(uint32_t *)0x0010FB20)   // RCLP 常温校准值
#define RCHF8M_LDT_TRIM     (*(uint32_t *)0x0010FB40)   // RC8M 常温校准值
#define RCHF16M_LDT_TRIM    (*(uint32_t *)0x0010FB3C)   // RC16M 常温校准值
#define RCHF24M_LDT_TRIM    (*(uint32_t *)0x0010FB38)   // RC24M 常温校准值
#define RCHF32M_LDT_TRIM    (*(uint32_t *)0x0010FB34)   // RC32M 常温校准值

/* Trim Values */
#define RCLP_TRIM           (LDT_CHECK(RCLP_LDT_TRIM, 0x80) & 0xff)
#define RCHF8M_TRIM         (LDT_CHECK(RCHF8M_LDT_TRIM, 0x80) & 0xff)
#define RCHF16M_TRIM        (LDT_CHECK(RCHF16M_LDT_TRIM, 0x80) & 0xff)
#define RCHF24M_TRIM        (LDT_CHECK(RCHF24M_LDT_TRIM, 0x80) & 0xff)
#define RCHF32M_TRIM        (LDT_CHECK(RCHF32M_LDT_TRIM, 0x80) & 0xff)

/* Default Clock Frequency Values --------------------------------------------*/

#define XTHF_DEFAULT_VALUE    ((uint32_t)8000000U)  /*!< Default value of XTHF in Hz */
#define XTLF_DEFAULT_VALUE    ((uint32_t)32768U)    /*!< Default value of XTLF in Hz */

/* Default system core clock value */
#define HCLK_DEFAULT_VALUE    ((uint32_t)8000000U)

/* Clock Configurations ------------------------------------------------------*/
/**
 *  @brief Handle LSCLK initialization in SystemInit()
 *  @note  Comment following line to disable LSCLK initialization code in SystemInit().
 */

/**
 *  @brief LSCLK source
 *  @note  Comment following line to use LPOSC as LSCLK source.
 */
//#define USE_LSCLK_CLOCK_SRC_XTLF
/**
 *  @brief LSCLK auto switch enable
 *  @note  Comment following line to disable LSCLK auto switch.
 */
//#define USE_LSCLK_AUTO_SWITCH

/* Exported Clock Frequency Variables --------------------------------------- */
/*
    - [SystemCoreClock] holds the value of CPU operation clock freqency, and is initialized
        to HCLK_DEFAULT_VALUE;
    - [XTLFClock] holds the value of external low-frequency oscillator(XTLF),
        and is initialized to XTLF_DEFAULT_VALUE;
    - [XTHFClock] holds the value of external high_frequency oscillator(XTHF),
        and is initialized to XTHF_DEFAULT_VALUE;

    NOTE: If users are using these two external oscillators, they should modify the
    value of XTLFClock and XTHFClock to the correct value, and call the SystemCoreClockUpdate()
    to update the SystemCoreClock variable, otherwise those codes which rely on
    the SystemCoreClock variable will fail to run.
 */
extern uint32_t XTLFClock;        /*!< External Low-freq Osc Clock Frequency (XTLF) */
extern uint32_t XTHFClock;        /*!< External High-freq Osc Clock Frequency (XTHF) */
extern uint32_t SystemCoreClock;  /*!< System Clock Frequency (Core Clock) */

/**
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit(void);

/**
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from cpu registers.
 */
void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTEM_FM33FK5XX_H */
