/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : mf_config.h
  * @brief          : Header for mf_config.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
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
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MF_CONFIG_H
#define __MF_CONFIG_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#if defined(FM33FK5XX)
#include "fm33fk5xx_fl.h"
#endif

#define PLL_TIMEOUT      0xFFFFFFFFU

/* Exported functions prototypes ---------------------------------------------*/
void MF_IWDT_Init(void);
void RCC_PLL_ConfigDomain_SYS(uint32_t Source, uint32_t PLL_R, uint32_t PLL_DB);
void RCHFInit(uint32_t RCHFclock);
uint32_t SelRCHFToPLL(uint32_t rchf, uint32_t PLLclock);
void MF_Clock_Init(void);
void MF_SystemClock_Config(void);
void MF_Config_Init(void);
void Error_Handler(void);
void MF_PMU_Init(void);

#ifdef __cplusplus
}
#endif

#endif /* __MF_CONFIG_H */

/************************ (C) COPYRIGHT FMSH *****END OF FILE****/
