/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_vrefp.h
  * @author  FMSH Application Team
  * @brief   Head file of VREFP FL Module
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
#ifndef __FM33FK5XX_FL_VREFP_H
#define __FM33FK5XX_FL_VREFP_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup VREFP_FL_ES_INIT VREFP Exported Init structures
  * @{
  */

/**
  * @brief FL VREFP Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup VREFP_FL_Exported_Constants VREFP Exported Constants
  * @{
  */

#define    VREFP_CR_PUDEN_Pos                                     (1U)
#define    VREFP_CR_PUDEN_Msk                                     (0x1U << VREFP_CR_PUDEN_Pos)
#define    VREFP_CR_PUDEN                                         VREFP_CR_PUDEN_Msk

#define    VREFP_CR_EN_Pos                                        (0U)
#define    VREFP_CR_EN_Msk                                        (0x1U << VREFP_CR_EN_Pos)
#define    VREFP_CR_EN                                            VREFP_CR_EN_Msk

#define    VREFP_CFGR_VRS_Pos                                     (0U)
#define    VREFP_CFGR_VRS_Msk                                     (0x3U << VREFP_CFGR_VRS_Pos)
#define    VREFP_CFGR_VRS                                         VREFP_CFGR_VRS_Msk

#define    VREFP_TR_TRIM_Pos                                      (0U)
#define    VREFP_TR_TRIM_Msk                                      (0xffU << VREFP_TR_TRIM_Pos)
#define    VREFP_TR_TRIM                                          VREFP_TR_TRIM_Msk

#define    FL_VREFP_VREFP_OUTPUT_VOLTAGE_1P5V                     (0x0U << VREFP_CFGR_VRS_Pos)
#define    FL_VREFP_VREFP_OUTPUT_VOLTAGE_2P0V                     (0x1U << VREFP_CFGR_VRS_Pos)
#define    FL_VREFP_VREFP_OUTPUT_VOLTAGE_2P5V                     (0x2U << VREFP_CFGR_VRS_Pos)
#define    FL_VREFP_VREFP_OUTPUT_VOLTAGE_3P0V                     (0x3U << VREFP_CFGR_VRS_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup VREFP_FL_Exported_Functions VREFP Exported Functions
  * @{
  */

/**
  * @brief    Enable internal pull-down
  * @rmtoll   CR    PUDEN    FL_VREFP_EnablePullDown
  * @param    VREFPx VREFP instance
  * @retval   None
  */
__STATIC_INLINE void FL_VREFP_EnablePullDown(VREFP_Type *VREFPx)
{
    SET_BIT(VREFPx->CR, VREFP_CR_PUDEN_Msk);
}

/**
  * @brief    Get internal pull-down  Enable Status
  * @rmtoll   CR    PUDEN    FL_VREFP_IsEnabledPullDown
  * @param    VREFPx VREFP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VREFP_IsEnabledPullDown(VREFP_Type *VREFPx)
{
    return (uint32_t)(READ_BIT(VREFPx->CR, VREFP_CR_PUDEN_Msk) == VREFP_CR_PUDEN_Msk);
}

/**
  * @brief    Disable internal pull-down
  * @rmtoll   CR    PUDEN    FL_VREFP_DisablePullDown
  * @param    VREFPx VREFP instance
  * @retval   None
  */
__STATIC_INLINE void FL_VREFP_DisablePullDown(VREFP_Type *VREFPx)
{
    CLEAR_BIT(VREFPx->CR, VREFP_CR_PUDEN_Msk);
}

/**
  * @brief    VREFP_VREG enable
  * @rmtoll   CR    EN    FL_VREFP_Enable
  * @param    VREFPx VREFP instance
  * @retval   None
  */
__STATIC_INLINE void FL_VREFP_Enable(VREFP_Type *VREFPx)
{
    SET_BIT(VREFPx->CR, VREFP_CR_EN_Msk);
}

/**
  * @brief    Get VREFP_VREG enable status
  * @rmtoll   CR    EN    FL_VREFP_IsEnabled
  * @param    VREFPx VREFP instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VREFP_IsEnabled(VREFP_Type *VREFPx)
{
    return (uint32_t)(READ_BIT(VREFPx->CR, VREFP_CR_EN_Msk) == VREFP_CR_EN_Msk);
}

/**
  * @brief    VREFP_VREG disable
  * @rmtoll   CR    EN    FL_VREFP_Disable
  * @param    VREFPx VREFP instance
  * @retval   None
  */
__STATIC_INLINE void FL_VREFP_Disable(VREFP_Type *VREFPx)
{
    CLEAR_BIT(VREFPx->CR, VREFP_CR_EN_Msk);
}

/**
  * @brief    Set output voltage
  * @rmtoll   CFGR    VRS    FL_VREFP_SetOutputVoltage
  * @param    VREFPx VREFP instance
  * @param    voltage This parameter can be one of the following values:
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_1P5V
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_2P0V
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_2P5V
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_3P0V
  * @retval   None
  */
__STATIC_INLINE void FL_VREFP_SetOutputVoltage(VREFP_Type *VREFPx, uint32_t voltage)
{
    MODIFY_REG(VREFPx->CFGR, VREFP_CFGR_VRS_Msk, voltage);
}

/**
  * @brief    Get output voltage
  * @rmtoll   CFGR    VRS    FL_VREFP_GetOutputVoltage
  * @param    VREFPx VREFP instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_1P5V
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_2P0V
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_2P5V
  *           @arg @ref FL_VREFP_VREFP_OUTPUT_VOLTAGE_3P0V
  */
__STATIC_INLINE uint32_t FL_VREFP_GetOutputVoltage(VREFP_Type *VREFPx)
{
    return (uint32_t)(READ_BIT(VREFPx->CFGR, VREFP_CFGR_VRS_Msk));
}

/**
  * @brief    Set VREFP output voltage
  * @rmtoll   TR    TRIM    FL_VREFP_WriteOutputVoltageTrim
  * @param    VREFPx VREFP instance
  * @param    trim
  * @retval   None
  */
__STATIC_INLINE void FL_VREFP_WriteOutputVoltageTrim(VREFP_Type *VREFPx, uint32_t trim)
{
    MODIFY_REG(VREFPx->TR, (0xffU << 0U), (trim << 0U));
}

/**
  * @brief    Get VREFP output voltage
  * @rmtoll   TR    TRIM    FL_VREFP_ReadOutputVoltageTrim
  * @param    VREFPx VREFP instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_VREFP_ReadOutputVoltageTrim(VREFP_Type *VREFPx)
{
    return (uint32_t)(READ_BIT(VREFPx->TR, (0xffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup VREFP_FL_EF_Init Initialization and de-initialization functions
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_VREFP_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-08-24*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
