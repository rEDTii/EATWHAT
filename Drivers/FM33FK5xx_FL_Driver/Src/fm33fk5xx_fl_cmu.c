/**
  ****************************************************************************************************
  * @file    fm33fk5xx_fl_cmu.c
  * @author  FMSH Application Team
  * @brief   Src file of CMU FL Module
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
/* Includes ------------------------------------------------------------------*/
#include "fm33fk5xx_fl.h"

/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */

/** @addtogroup CMU
  * @{
  */

#ifdef FL_CMU_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup CMU_FL_Private_Macros
  * @{
  */

/**
  * @brief  设置系统工作使用时钟。
  * @param  系统工作时钟源及频率。
  * @note   函数中用到了XTHF_VALUE 宏，这个宏应该被定义为外部晶振的输入频率值。
  * @note   其他时钟源可由应用程序实现，如PLL_RCHF_40M, PLL_XTHF_64M
  * @note   PLL倍频频率范围为32M-64M
  * @note   对功耗由要求的应用，注意关闭未使用到的空闲时钟源
  *
  * @retval 系统时钟设置状态。
  *
  */
FL_ErrorStatus FL_CMU_SetSystemClock(FL_SystemClock systemClock)
{
    FL_ErrorStatus errorStatus = FL_PASS;
    /* <= 24M: 0wait; > 24 and <= 48: 1wait;> 48 and <= 72: 2wait; > 72 and <= 96: 3wait;> 96 and <= 120: 4wait;*/
    switch(systemClock)
    {
        case FL_SYSTEM_CLOCK_RCHF_8M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
            break;
        case FL_SYSTEM_CLOCK_RCHF_16M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_WriteTrimValue(RCHF16M_TRIM);
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_16MHZ);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
            break;
        case FL_SYSTEM_CLOCK_RCHF_24M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_WriteTrimValue(RCHF24M_TRIM);
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_24MHZ);
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCHF);
            break;
        case FL_SYSTEM_CLOCK_PLL_RCHF_32M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
            FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV8);
            FL_CMU_PLL_WriteMultiplier(32 - 1);
            FL_CMU_PLL_Enable();
            while(FL_CMU_IsActiveFlag_PLLReady() == 0x0)
            {
            }
            FLASH->RDCR = 0x1;
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
            break;
        case FL_SYSTEM_CLOCK_PLL_RCHF_48M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
            FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV8);
            FL_CMU_PLL_WriteMultiplier(48 - 1);
            FL_CMU_PLL_Enable();
            while(FL_CMU_IsActiveFlag_PLLReady() == 0x0)
            {
            }
            FLASH->RDCR = 0x1;
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
            break;
        case FL_SYSTEM_CLOCK_PLL_RCHF_64M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
            FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV8);
            FL_CMU_PLL_WriteMultiplier(64 - 1);
            FL_CMU_PLL_Enable();
            while(FL_CMU_IsActiveFlag_PLLReady() == 0x0)
            {
            }
            FLASH->RDCR = 0x2;
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
            break;
        case FL_SYSTEM_CLOCK_PLL_RCHF_80M:
            FL_CMU_RCHF_Enable();
            FL_CMU_RCHF_SetFrequency(FL_CMU_RCHF_FREQUENCY_8MHZ);
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            FL_CMU_PLL_SetClockSource(FL_CMU_PLL_CLK_SOURCE_RCHF);
            FL_CMU_PLL_SetPrescaler(FL_CMU_PLL_PSC_DIV8);
            FL_CMU_PLL_WriteMultiplier(80 - 1);
            FL_CMU_PLL_Enable();
            while(FL_CMU_IsActiveFlag_PLLReady() == 0x0)
            {
            }
            FLASH->RDCR = 0x3;
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
            break;
        case FL_SYSTEM_CLOCK_RCLP:
            FL_CMU_RCLP_Enable();
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_RCLP);
            break;
        case FL_SYSTEM_CLOCK_XTHF:
            FL_CMU_XTHF_Enable();
            FL_DelayMs(100);
            while(FL_CMU_XTHF_IsReady() == 0x0)
            {
            }
            FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_XTHF);
            break;
        case FL_SYSTEM_CLOCK_USB:
            //待补充
            break;
        default:
            // 不应来到此处
            errorStatus = FL_FAIL;
            break;
    }
    return errorStatus;
}

/**
  * @}
  */

/* Private consts ------------------------------------------------------------*/
/** @addtogroup CMU_FL_Private_Consts
  * @{
  */

/**
  * @brief  获取系统当前工作时钟SYSCLK。
  * @param  None
  * @note   函数中用到了XTHF_VALUE 宏，这个宏应该被定义为外部晶振的输入频率值。
  *
  * @retval 系统时钟频率 (Hz)。
  *
  */
uint32_t FL_CMU_GetSystemClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取系统时钟源 */
    switch(FL_CMU_GetSystemClockSource())
    {
        /* 系统时钟源为内部RCHF */
        case FL_CMU_SYSTEM_CLK_SOURCE_RCHF:
            /* 内部RCHF默认为8MHz ,可以配置为16或24M */
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
        /* 系统时钟源为XTHF */
        case FL_CMU_SYSTEM_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        /* 系统时钟源为PLL */
        case FL_CMU_SYSTEM_CLK_SOURCE_PLL:
            frequency = FL_CMU_GetPLLClockFreq();
            break;
        /* 系统时钟源为RCLP */
        case FL_CMU_SYSTEM_CLK_SOURCE_RCLP:
            frequency = 32768;
            break;
        /* 系统时钟源为USB BCK */
        case FL_CMU_SYSTEM_CLK_SOURCE_USB_BCK_PSC:
            /* USB时钟频率获取 */
            frequency = FL_CMU_GetUSBClockFreqToSysclk();
            break;
        default:
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取AHB总线时钟频率
  *
  * @retval AHB总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAHBClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取AHB分频系数，AHB源自系统主时钟 */
    switch(FL_CMU_GetAHBPrescaler())
    {
        case FL_CMU_AHBCLK_PSC_DIV1:
            frequency = FL_CMU_GetSystemClockFreq();
            break;
        case FL_CMU_AHBCLK_PSC_DIV2:
            frequency = FL_CMU_GetSystemClockFreq() / 2;
            break;
        case FL_CMU_AHBCLK_PSC_DIV4:
            frequency = FL_CMU_GetSystemClockFreq() / 4;
            break;
        case FL_CMU_AHBCLK_PSC_DIV8:
            frequency = FL_CMU_GetSystemClockFreq() / 8;
            break;
        case FL_CMU_AHBCLK_PSC_DIV16:
            frequency = FL_CMU_GetSystemClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetSystemClockFreq();
            break;
    }
    return frequency;
}

/**
  * @brief  获取当前系统的APB1总线时钟
  *
  * @retval APB1总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAPB1ClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取APB1分频系数，APB源自AHB */
    switch(FL_CMU_GetAPB1Prescaler())
    {
        case FL_CMU_APB1CLK_PSC_DIV1:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
        case FL_CMU_APB1CLK_PSC_DIV2:
            frequency = FL_CMU_GetAHBClockFreq() / 2;
            break;
        case FL_CMU_APB1CLK_PSC_DIV4:
            frequency = FL_CMU_GetAHBClockFreq() / 4;
            break;
        case FL_CMU_APB1CLK_PSC_DIV8:
            frequency = FL_CMU_GetAHBClockFreq() / 8;
            break;
        case FL_CMU_APB1CLK_PSC_DIV16:
            frequency = FL_CMU_GetAHBClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetAHBClockFreq();
            break;
    }
    return frequency;
}
/**
  * @brief  获取当前系统的APB2总线时钟
  *
  * @retval APB2总线时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetAPB2ClockFreq(void)
{
    uint32_t frequency = 0;
    /* 获取APB2分频系数，APB源自AHB */
    switch(FL_CMU_GetAPB2Prescaler())
    {
        case FL_CMU_APB2CLK_PSC_DIV2:
            frequency = FL_CMU_GetAHBClockFreq() / 2;
            break;
        case FL_CMU_APB2CLK_PSC_DIV4:
            frequency = FL_CMU_GetAHBClockFreq() / 4;
            break;
        case FL_CMU_APB2CLK_PSC_DIV8:
            frequency = FL_CMU_GetAHBClockFreq() / 8;
            break;
        case FL_CMU_APB2CLK_PSC_DIV16:
            frequency = FL_CMU_GetAHBClockFreq() / 16;
            break;
        default:
            frequency = FL_CMU_GetAHBClockFreq() / 2;
            break;
    }
    return frequency;
}

/**
  * @brief  获取RCHF输出时钟频率
  * @param  None
  *
  * @retval 返回RCHF输出时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetRCHFClockFreq(void)
{
    uint32_t frequency = 0;
    switch(FL_CMU_RCHF_GetFrequency())
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            frequency = 8000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            frequency = 16000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            frequency = 24000000;
            break;
        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            frequency = 32000000;
            break;
        default:
            frequency = 8000000;
            break;
    }
    return frequency;
}

/**
  * @brief  获取PLL输出时钟频率
  * @param  None
  *
  * @retval 返回PLL输出时钟频率(Hz)
  *
  */
uint32_t FL_CMU_GetPLLClockFreq(void)
{
    uint32_t frequency = 0;
    uint32_t multiplier = 0;
    /* 获取PLL时钟源 */
    switch(FL_CMU_PLL_GetClockSource())
    {
        case FL_CMU_PLL_CLK_SOURCE_RCHF:
            /* 获取RCHF配置主频 */
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
        case FL_CMU_PLL_CLK_SOURCE_XTHF:
            frequency = XTHFClock;
            break;
        default:
            frequency = FL_CMU_GetRCHFClockFreq();
            break;
    }
    /* 获取PLL时钟分频系数 */
    switch(FL_CMU_PLL_GetPrescaler())
    {
        case FL_CMU_PLL_PSC_DIV1:
            break;
        case FL_CMU_PLL_PSC_DIV2:
            frequency /= 2;
            break;
        case FL_CMU_PLL_PSC_DIV4:
            frequency /= 4;
            break;
        case FL_CMU_PLL_PSC_DIV8:
            frequency /= 8;
            break;
        case FL_CMU_PLL_PSC_DIV12:
            frequency /= 12;
            break;
        case FL_CMU_PLL_PSC_DIV16:
            frequency /= 16;
            break;
        case FL_CMU_PLL_PSC_DIV24:
            frequency /= 24;
            break;
        case FL_CMU_PLL_PSC_DIV32:
            frequency /= 32;
            break;
        default:
            break;
    }
    multiplier = FL_CMU_PLL_ReadMultiplier() + 1;
    frequency *= multiplier;
    return frequency;
}

/**
  * @brief  获取USB提供给系统总线时钟的频率
  *
  * @retval USB提供给SYSCLK的时钟频率(Hz)
  */
uint32_t FL_CMU_GetUSBClockFreqToSysclk(void)
{
    uint32_t frequency = 0;
    switch(FL_CMU_GetUSBClockOutput())
    {
        case FL_CMU_USB_CLK_OUT_48M:
            frequency = 48000000;
            break;
        case FL_CMU_USB_CLK_OUT_96M:
            frequency = 96000000;
            break;
        case FL_CMU_USB_CLK_OUT_120M:
            frequency = 120000000;
            break;
        case FL_CMU_USB_CLK_OUT_240M:
            frequency = 240000000;
            break;
        default:
            frequency = 48000000;
            break;
    }
    return frequency;
}

#endif /* FL_CMU_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
