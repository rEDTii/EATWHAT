/**************************************************************************//**
 * @file     system_fm33fk5xx.c
 * @brief    CMSIS Cortex-M33 Device Peripheral Access Layer Source File for
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

#include "system_fm33fk5xx.h"

/* Clock Variable definitions ------------------------------------------------*/
uint32_t XTLFClock = XTLF_DEFAULT_VALUE;        /*!< External Low-freq Osc Clock Frequency (XTLF) */
uint32_t XTHFClock = XTHF_DEFAULT_VALUE;        /*!< External High-freq Osc Clock Frequency (XTHF) */
uint32_t SystemCoreClock = HCLK_DEFAULT_VALUE;  /*!< System Clock Frequency (Core Clock) */

/* Clock functions -----------------------------------------------------------*/
/**
 *  @brief Update the core clock frequency variable: SystemCoreClock
 *
 */
static uint32_t SystemPLLClockUpdate(void)
{
    uint32_t clock = 0;
    /* Acquire PLL clock source */
    switch((CMU->PLLCR >> 1) & 0x1)
    {
        case 0:
        case 3:
            switch((CMU->RCHFCR >> 16) & 0xFU)
            {
                case 1: /* 16MHz */
                    clock = 16000000;
                    break;
                case 2: /* 24MHz */
                    clock = 24000000;
                    break;
                case 3: /* 32MHz */
                    clock = 32000000;
                    break;
                case 0: /* 8MHz */
                default:
                    clock = 8000000;
                    break;
            }
            break;
        case 1:
        case 2:
            clock = XTHFClock;
            break;
    }
    /* Acquire PLL prescaler */
    switch((CMU->PLLCR >> 0x4) & 0x7)
    {
        case 0: /* input divided by 1 */
            clock /= 1;
            break;
        case 1: /* input divided by 2 */
            clock /= 2;
            break;
        case 2: /* input divided by 4 */
            clock /= 4;
            break;
        case 3: /* input divided by 8 */
            clock /= 8;
            break;
        case 4: /* input divided by 12 */
            clock /= 12;
            break;
        case 5: /* input divided by 16 */
            clock /= 16;
            break;
        case 6: /* input divided by 24 */
            clock /= 24;
            break;
        case 7: /* input divided by 32 */
            clock /= 32;
            break;
    }
    /* Acquire PLL multiplier and calculate PLL frequency */
    clock = clock * (((CMU->PLLCR >> 16) & 0x7F) + 1);
    return clock;
}

void SystemCoreClockUpdate(void)
{
    switch((CMU->SYSCLKCR >> 0) & 0x7)
    {
        case 1: /* XTHF */
            SystemCoreClock = XTHFClock;
            break;
        case 3: /* PLL 1X */
            SystemCoreClock = SystemPLLClockUpdate();
            break;
        case 5: /* PLL 2X */
            SystemCoreClock = (SystemPLLClockUpdate() << 1);
            break;
        case 6: /* RCLP */
            SystemCoreClock = 32768;
            break;
        case 7: /* USB_BCK */
            SystemCoreClock = 48000000;     /* Only 48M is applicable */
            break;
        default:
            switch((CMU->RCHFCR >> 16) & 0xf)
            {
                case 1: /* 16MHz */
                    SystemCoreClock = 16000000;
                    break;
                case 2: /* 24MHz */
                    SystemCoreClock = 24000000;
                    break;
                case 3: /* 32MHz */
                    SystemCoreClock = 32000000;
                    break;
                case 0: /* 8MHz */
                default:
                    SystemCoreClock = 8000000;
                    break;
            }
            break;
    }
    /* AHB Prescaler */
    switch((CMU->SYSCLKCR >> 8) & 0x7)
    {
        case 4: /* divide by 2 */
            SystemCoreClock /= 2;
            break;
        case 5: /* divide by 4 */
            SystemCoreClock /= 4;
            break;
        case 6: /* divide by 8 */
            SystemCoreClock /= 8;
            break;
        case 7: /* divide by 16 */
            SystemCoreClock /= 16;
            break;
        default: /* no division */
            break;
    }
}

/**
 * @brief  Setup the microcontroller system.
 *         Initialize the System.
 */
void SystemInit(void)
{
#if (__FPU_PRESENT == 1) && (__FPU_USED == 1)
    SCB->CPACR |= ((3UL << 20U) | (3UL << 22U)); /* set CP10 and CP11 Full Access */
#endif

#if (__USE_ICACHE == 1)
    SCB->CCR |= SCB_CCR_IC_Msk;
#endif
    
    /* Reset PLL & SYSCLK selection */
    CMU->PLLCR = 0x00000000U;
    CMU->SYSCLKCR = 0x02000000U;

    /* Enable PAD Operation Clock */
    CMU->PCLKCR1 |= (0x1U << 7);

    /* IWDT config */
    CMU->PCLKCR1 |= (0x1U << 5);
    IWDT->SERV = 0x12345A5AU;
    IWDT->CR |= 0x07U;
    IWDT->SERV = 0x12345A5AU;

    /* BOR Configuration */
    RMU->BORCR = 0x14U;

    /* Disable IWDT & WWDT, enable other peripherals(e.g. timers) under Debug Mode */
    //    DBG->CR = 0x03;
    /* Load clock trim value */
    // CMU->RCHFTR = RCHF8M_TRIM;
    CMU->RCLPTR = RCLP_TRIM;

    /* Enable SWD port pull up */
    GPIOD->PUDEN |= (0x3U << 7);

    /* Update System Core Clock */
    SystemCoreClockUpdate();
    IWDT->SERV = 0x12345A5AU;
}
