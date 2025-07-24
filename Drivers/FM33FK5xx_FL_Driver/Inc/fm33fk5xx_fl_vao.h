/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_vao.h
  * @author  FMSH Application Team
  * @brief   Head file of VAO FL Module
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
#ifndef __FM33FK5XX_FL_VAO_H
#define __FM33FK5XX_FL_VAO_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup VAO_FL_ES_INIT VAO Exported Init structures
  * @{
  */

/**
  * @brief FL VAO Init Sturcture definition
  */
typedef struct
{
    uint32_t pin;
    /*! PH输入使能 */
    uint32_t input;
    /*! PH上下拉使能 */
    uint32_t pull;
    /*! PH开漏输出使能 */
    uint32_t opendrainOutput;
    /*! PH功能选择 */
    uint32_t mode;
    /* 驱动强度*/
    uint32_t driveStrength;

} FL_VAO_IO_InitTypeDef;

typedef struct
{
    /*! 驱动能力配置 */
    uint32_t driveMode;
    /*! 工作电流大小*/
    uint32_t workingCurrentMode;

} FL_VAO_XTLF_InitTypeDef;
/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup VAO_FL_Exported_Constants VAO Exported Constants
  * @{
  */

#define    VAO_RSTCR_VBAT_RST_Pos                                 (0U)
#define    VAO_RSTCR_VBAT_RST_Msk                                 (0x1U << VAO_RSTCR_VBAT_RST_Pos)
#define    VAO_RSTCR_VBAT_RST                                     VAO_RSTCR_VBAT_RST_Msk

#define    VAO_XTLFCR_WAIT_Pos                                    (13U)
#define    VAO_XTLFCR_WAIT_Msk                                    (0x7U << VAO_XTLFCR_WAIT_Pos)
#define    VAO_XTLFCR_WAIT                                        VAO_XTLFCR_WAIT_Msk

#define    VAO_XTLFCR_EXCKSEN_Pos                                 (12U)
#define    VAO_XTLFCR_EXCKSEN_Msk                                 (0x1U << VAO_XTLFCR_EXCKSEN_Pos)
#define    VAO_XTLFCR_EXCKSEN                                     VAO_XTLFCR_EXCKSEN_Msk

#define    VAO_XTLFCR_XTLFEN_Pos                                  (8U)
#define    VAO_XTLFCR_XTLFEN_Msk                                  (0xfU << VAO_XTLFCR_XTLFEN_Pos)
#define    VAO_XTLFCR_XTLFEN                                      VAO_XTLFCR_XTLFEN_Msk

#define    VAO_XTLFCR_RDY_Pos                                     (7U)
#define    VAO_XTLFCR_RDY_Msk                                     (0x1U << VAO_XTLFCR_RDY_Pos)
#define    VAO_XTLFCR_RDY                                         VAO_XTLFCR_RDY_Msk

#define    VAO_XTLFCR_DRVCFG_Pos                                  (2U)
#define    VAO_XTLFCR_DRVCFG_Msk                                  (0x7U << VAO_XTLFCR_DRVCFG_Pos)
#define    VAO_XTLFCR_DRVCFG                                      VAO_XTLFCR_DRVCFG_Msk

#define    VAO_XTLFCR_XTLFIPW_Pos                                 (0U)
#define    VAO_XTLFCR_XTLFIPW_Msk                                 (0x3U << VAO_XTLFCR_XTLFIPW_Pos)
#define    VAO_XTLFCR_XTLFIPW                                     VAO_XTLFCR_XTLFIPW_Msk

#define    VAO_LFDIER_LFDET_IE_Pos                                 (0U)
#define    VAO_LFDIER_LFDET_IE_Msk                                 (0x1U << VAO_LFDIER_LFDET_IE_Pos)
#define    VAO_LFDIER_LFDET_IE                                     VAO_LFDIER_LFDET_IE_Msk

#define    VAO_LFDISR_LFDETO_Pos                                   (1U)
#define    VAO_LFDISR_LFDETO_Msk                                   (0x1U << VAO_LFDISR_LFDETO_Pos)
#define    VAO_LFDISR_LFDETO                                       VAO_LFDISR_LFDETO_Msk

#define    VAO_LFDISR_LFDETIF_Pos                                  (0U)
#define    VAO_LFDISR_LFDETIF_Msk                                  (0x1U << VAO_LFDISR_LFDETIF_Pos)
#define    VAO_LFDISR_LFDETIF                                      VAO_LFDISR_LFDETIF_Msk

#define    VAO_INEN_PHINEN_Pos                                    (0U)
#define    VAO_INEN_PHINEN_Msk                                    (0x1U << VAO_INEN_PHINEN_Pos)
#define    VAO_INEN_PHINEN                                        VAO_INEN_PHINEN_Msk

#define    VAO_PUPDEN_PHPDEN_Pos                                  (15U)
#define    VAO_PUPDEN_PHPDEN_Msk                                  (0x1U << VAO_PUPDEN_PHPDEN_Pos)
#define    VAO_PUPDEN_PHPDEN                                      VAO_PUPDEN_PHPDEN_Msk

#define    VAO_PUPDEN_PHPUEN_Pos                                  (0U)
#define    VAO_PUPDEN_PHPUEN_Msk                                  (0x1U << VAO_PUPDEN_PHPUEN_Pos)
#define    VAO_PUPDEN_PHPUEN                                      VAO_PUPDEN_PHPUEN_Msk

#define    VAO_ODEN_PHODEN_Pos                                    (0U)
#define    VAO_ODEN_PHODEN_Msk                                    (0x1U << VAO_ODEN_PHODEN_Pos)
#define    VAO_ODEN_PHODEN                                        VAO_ODEN_PHODEN_Msk

#define    VAO_FCR_PHFCR_Pos                                      (0U)
#define    VAO_FCR_PHFCR_Msk                                      (0x3U << VAO_FCR_PHFCR_Pos)
#define    VAO_FCR_PHFCR                                          VAO_FCR_PHFCR_Msk

#define    VAO_DOR_PHDO_Pos                                       (0U)
#define    VAO_DOR_PHDO_Msk                                       (0x1U << VAO_DOR_PHDO_Pos)
#define    VAO_DOR_PHDO                                           VAO_DOR_PHDO_Msk

#define    VAO_DIN_PHDIN_Pos                                      (0U)
#define    VAO_DIN_PHDIN_Msk                                      (0x1U << VAO_DIN_PHDIN_Pos)
#define    VAO_DIN_PHDIN                                          VAO_DIN_PHDIN_Msk

#define    VAO_DSR_PHDSR_Pos                                      (0U)
#define    VAO_DSR_PHDSR_Msk                                      (0x3U << VAO_DSR_PHDSR_Pos)
#define    VAO_DSR_PHDSR                                           VAO_DSR_PHDSR_Msk

#define    FL_VAO_PH_PIN_13                                       (0x1U << 13U)
#define    FL_VAO_PH_PIN_14                                       (0x1U << 14U)
#define    FL_VAO_PH_PIN_15                                       (0x1U << 15U)

#define    FL_VAO_XTLF_STARTUP_CYCLE_128                          (0x0U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_256                          (0x1U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_512                          (0x2U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_1024                         (0x3U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_2048                         (0x4U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_4096                         (0x5U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_8192                         (0x6U << VAO_XTLFCR_WAIT_Pos)
#define    FL_VAO_XTLF_STARTUP_CYCLE_16384                        (0x7U << VAO_XTLFCR_WAIT_Pos)

#define    FL_VAO_XTLF_EXTERNAL_CLOCK_XTLF                        (0x0U << VAO_XTLFCR_EXCKSEN_Pos)
#define    FL_VAO_XTLF_EXTERNAL_CLOCK_XT32KI                      (0x1U << VAO_XTLFCR_EXCKSEN_Pos)

#define    FL_VAO_XTLF_ENABLE                                     (0x5U << VAO_XTLFCR_XTLFEN_Pos)

#define    FL_VAO_XTLF_DISABLE                                    (0xaU << VAO_XTLFCR_XTLFEN_Pos)

#define    FL_VAO_XTLF_DRIVE_LEVEL_NONE                           (0x0U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_1                              (0x1U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_2                              (0x2U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_3                              (0x3U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_4                              (0x4U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_5                              (0x5U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_6                              (0x6U << VAO_XTLFCR_DRVCFG_Pos)
#define    FL_VAO_XTLF_DRIVE_LEVEL_7                              (0x7U << VAO_XTLFCR_DRVCFG_Pos)

#define    FL_VAO_XTLF_WORK_CURRENT_NONE                          (0x0U << VAO_XTLFCR_XTLFIPW_Pos)
#define    FL_VAO_XTLF_WORK_CURRENT_1                             (0x1U << VAO_XTLFCR_XTLFIPW_Pos)
#define    FL_VAO_XTLF_WORK_CURRENT_2                             (0x2U << VAO_XTLFCR_XTLFIPW_Pos)
#define    FL_VAO_XTLF_WORK_CURRENT_3                             (0x3U << VAO_XTLFCR_XTLFIPW_Pos)

#define    FL_VAO_PH_MODE_INPUT                                   (0x0U << VAO_FCR_PHFCR_Pos)
#define    FL_VAO_PH_MODE_OUTPUT                                  (0x1U << VAO_FCR_PHFCR_Pos)
#define    FL_VAO_PH_MODE_DIGTAL                                  (0x2U << VAO_FCR_PHFCR_Pos)
#define    FL_VAO_PH_MODE_ANALOG                                  (0x3U << VAO_FCR_PHFCR_Pos)

#define    FL_VAO_PH_THRESHOLD_X1                                 (0x0U << VAO_DSR_PHDSR_Pos)
#define    FL_VAO_PH_THRESHOLD_X2                                 (0x1U << VAO_DSR_PHDSR_Pos)
#define    FL_VAO_PH_THRESHOLD_X3                                 (0x2U << VAO_DSR_PHDSR_Pos)
#define    FL_VAO_PH_THRESHOLD_X4                                 (0x3U << VAO_DSR_PHDSR_Pos)

#define    FL_VAO_PH_PULLDOWN_ENABLE                              (0x0U)
#define    FL_VAO_PH_PULLUP_ENABLE                                (0x1U)
#define    FL_VAO_PH_BOTH_DISABLE                                 (0x2U)

#define    FL_VAO_PH_OUTPUT_PUSHPULL                              (0x0U)
#define    FL_VAO_PH_OUTPUT_OPENDRAIN                             (0x1U)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup VAO_FL_Exported_Functions VAO Exported Functions
  * @{
  */

/**
  * @brief    Enable VBT power field register reset
  * @rmtoll   RSTCR    VBAT_RST    FL_VAO_EnableReset
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_EnableReset(VAO_Type *VAOx)
{
    SET_BIT(VAOx->RSTCR, VAO_RSTCR_VBAT_RST_Msk);
}

/**
  * @brief    Get VBT power field register reset Status
  * @rmtoll   RSTCR    VBAT_RST    FL_VAO_IsEnabledReset
  * @param    VAOx VAO instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_IsEnabledReset(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->RSTCR, VAO_RSTCR_VBAT_RST_Msk) == VAO_RSTCR_VBAT_RST_Msk);
}

/**
  * @brief    Disable VBT power field register reset
  * @rmtoll   RSTCR    VBAT_RST    FL_VAO_DisableReset
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_DisableReset(VAO_Type *VAOx)
{
    CLEAR_BIT(VAOx->RSTCR, VAO_RSTCR_VBAT_RST_Msk);
}

/**
  * @brief    Set XTLF Startup Time
  * @rmtoll   XTLFCR    WAIT    FL_VAO_XTLF_SetStartupCycle
  * @param    VAOx VAO instance
  * @param    cycle This parameter can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_128
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_256
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_512
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_1024
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_2048
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_4096
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_8192
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_16384
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_XTLF_SetStartupCycle(VAO_Type *VAOx, uint32_t cycle)
{
    MODIFY_REG(VAOx->XTLFCR, VAO_XTLFCR_WAIT_Msk, cycle);
}

/**
  * @brief    Get XTLF Startup Time
  * @rmtoll   XTLFCR    WAIT    FL_VAO_XTLF_GetStartupCycle
  * @param    VAOx VAO instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_128
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_256
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_512
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_1024
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_2048
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_4096
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_8192
  *           @arg @ref FL_VAO_XTLF_STARTUP_CYCLE_16384
  */
__STATIC_INLINE uint32_t FL_VAO_XTLF_GetStartupCycle(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->XTLFCR, VAO_XTLFCR_WAIT_Msk));
}

/**
  * @brief    Set external input low-frequency clock
  * @rmtoll   XTLFCR    EXCKSEN    FL_VAO_XTLF_SetExternalLowFrequencyClock
  * @param    VAOx VAO instance
  * @param    clock This parameter can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_EXTERNAL_CLOCK_XTLF
  *           @arg @ref FL_VAO_XTLF_EXTERNAL_CLOCK_XT32KI
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_XTLF_SetExternalLowFrequencyClock(VAO_Type *VAOx, uint32_t clock)
{
    MODIFY_REG(VAOx->XTLFCR, VAO_XTLFCR_EXCKSEN_Msk, clock);
}

/**
  * @brief    Get external input low-frequency clock
  * @rmtoll   XTLFCR    EXCKSEN    FL_VAO_XTLF_GetExternalLowFrequencyClock
  * @param    VAOx VAO instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_EXTERNAL_CLOCK_XTLF
  *           @arg @ref FL_VAO_XTLF_EXTERNAL_CLOCK_XT32KI
  */
__STATIC_INLINE uint32_t FL_VAO_XTLF_GetExternalLowFrequencyClock(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->XTLFCR, VAO_XTLFCR_EXCKSEN_Msk));
}

/**
  * @brief    使能XTLF
  * @rmtoll   XTLFCR    XTLFEN    FL_VAO_XTLF_Enable
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_XTLF_Enable(VAO_Type *VAOx)
{
    MODIFY_REG(VAOx->XTLFCR, VAO_XTLFCR_XTLFEN, FL_VAO_XTLF_ENABLE);
}

/**
  * @brief    获取XTLF状态
  * @rmtoll   XTLFCR    XTLFEN    FL_VAO_XTLF_IsEnabled
  * @param    VAOx VAO instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_XTLF_IsEnabled(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->XTLFCR, VAO_XTLFCR_XTLFEN_Msk) == (FL_VAO_XTLF_ENABLE));
}

/**
  * @brief    禁止XTLF
  * @rmtoll   XTLFCR    XTLFEN    FL_VAO_XTLF_Disable
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_XTLF_Disable(VAO_Type *VAOx)
{
    MODIFY_REG(VAOx->XTLFCR, VAO_XTLFCR_XTLFEN, FL_VAO_XTLF_DISABLE);
}
/**
  * @brief    Get XTLF  ready flag
  * @rmtoll   XTLFCR    RDY    FL_VAO_IsActiveFlag_XTLFReady
  * @param    VAOx VAO instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_IsActiveFlag_XTLFReady(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->XTLFCR, VAO_XTLFCR_RDY_Msk) == (VAO_XTLFCR_RDY_Msk));
}

/**
  * @brief    Set output drive Level
  * @rmtoll   XTLFPR    DRVCFG    FL_VAO_XTLF_SetDriveLevel
  * @param    VAOx VAO instance
  * @param    level This parameter can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_NONE
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_1
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_2
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_3
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_4
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_5
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_6
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_XTLF_SetDriveLevel(VAO_Type *VAOx, uint32_t level)
{
    MODIFY_REG(VAOx->XTLFCR, VAO_XTLFCR_DRVCFG_Msk, level);
}

/**
  * @brief    Get output drive  Level
  * @rmtoll   XTLFPR    DRVCFG    FL_VAO_XTLF_GetDriveLevel
  * @param    VAOx VAO instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_NONE
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_1
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_2
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_3
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_4
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_5
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_6
  *           @arg @ref FL_VAO_XTLF_DRIVE_LEVEL_7
  */
__STATIC_INLINE uint32_t FL_VAO_XTLF_GetDriveLevel(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->XTLFCR, VAO_XTLFCR_DRVCFG_Msk));
}

/**
  * @brief    Set XTLF working current
  * @rmtoll   XTLFPR    XTLFIPW    FL_VAO_XTLF_SetWorkCurrent
  * @param    VAOx VAO instance
  * @param    current This parameter can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_NONE
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_1
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_2
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_3
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_XTLF_SetWorkCurrent(VAO_Type *VAOx, uint32_t current)
{
    MODIFY_REG(VAOx->XTLFCR, VAO_XTLFCR_XTLFIPW_Msk, current);
}

/**
  * @brief    Get XTLF working current
  * @rmtoll   XTLFCR    XTLFIPW    FL_VAO_XTLF_GetWorkCurrent
  * @param    VAOx VAO instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_NONE
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_1
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_2
  *           @arg @ref FL_VAO_XTLF_WORK_CURRENT_3
  */
__STATIC_INLINE uint32_t FL_VAO_XTLF_GetWorkCurrent(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->XTLFCR, VAO_XTLFCR_XTLFIPW_Msk));
}

/**
  * @brief    XTLF  detect interrupt enable
  * @rmtoll   LFDIER    LFDET_IE    FL_VAO_EnableIT_XTLFFail
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_EnableIT_XTLFFail(VAO_Type *VAOx)
{
    SET_BIT(VAOx->LFDIER, VAO_LFDIER_LFDET_IE_Msk);
}

/**
  * @brief    Get XTLF detect interrupt enable status
  * @rmtoll   FDIER    LFDET_IE    FL_VAO_IsEnabledIT_XTLFFail
  * @param    VAOx VAO instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_IsEnabledIT_XTLFFail(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->LFDIER, VAO_LFDIER_LFDET_IE_Msk) == VAO_LFDIER_LFDET_IE_Msk);
}

/**
  * @brief    XTLF  detect interrupt disable
  * @rmtoll   LFDIER    LFDET_IE    FL_VAO_DisableIT_XTLFFail
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_DisableIT_XTLFFail(VAO_Type *VAOx)
{
    CLEAR_BIT(VAOx->LFDIER, VAO_LFDIER_LFDET_IE_Msk);
}

/**
  * @brief    Get XTLF  detect output
  * @rmtoll   LFDISR    LFDETO    FL_VAO_GetXTLFFailOutput
  * @param    VAOx VAO instance
  * @retval   Returned value can be one of the following values:
  */
__STATIC_INLINE uint32_t FL_VAO_GetXTLFFailOutput(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->LFDISR, VAO_LFDISR_LFDETO_Msk));
}

/**
  * @brief    Get XTLF  detect interrupt flag
  * @rmtoll   LFDISR    LFDETIF    FL_VAO_IsActiveFlag_XTLFFail
  * @param    VAOx VAO instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_IsActiveFlag_XTLFFail(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->LFDISR, VAO_LFDISR_LFDETIF_Msk) == (VAO_LFDISR_LFDETIF_Msk));
}

/**
  * @brief    Clear XTLF  detect interrupt flag
  * @rmtoll   LFDISR    LFDETIF    FL_VAO_ClearFlag_XTLFFail
  * @param    VAOx VAO instance
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_ClearFlag_XTLFFail(VAO_Type *VAOx)
{
    WRITE_REG(VAOx->LFDISR, VAO_LFDISR_LFDETIF_Msk);
}

/**
  * @brief    PH input enable
  * @rmtoll   INEN    PHINEN    FL_VAO_GPIO_EnablePHInput
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_EnablePHInput(VAO_Type *VAOx, uint32_t pin)
{
    SET_BIT(VAOx->INEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PH input enable status
  * @rmtoll   INEN    PHINEN    FL_VAO_GPIO_IsEnabledPHInput
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_IsEnabledPHInput(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAOx->INEN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PH input disable
  * @rmtoll   INEN    PHINEN    FL_VAO_GPIO_DisablePHInput
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_DisablePHInput(VAO_Type *VAOx, uint32_t pin)
{
    CLEAR_BIT(VAOx->INEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PH pullup enable
  * @rmtoll   PUPDEN    PHPUEN    FL_VAO_GPIO_EnablePHPullup
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_EnablePHPullup(VAO_Type *VAOx, uint32_t pin)
{
    SET_BIT(VAOx->PUPDEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PH pullup enable status
  * @rmtoll   PUPDEN    PHPUEN    FL_VAO_GPIO_IsEnabledPHPullup
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_IsEnabledPHPullup(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAOx->PUPDEN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PH pullup disable
  * @rmtoll   PUEN    PHPUEN    FL_VAO_GPIO_DisablePHPullup
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_DisablePHPullup(VAO_Type *VAOx, uint32_t pin)
{
    CLEAR_BIT(VAOx->PUPDEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PH pulldown enable
  * @rmtoll   PUPDEN    PHPDEN    FL_VAO_GPIO_EnablePHPulldown
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_EnablePHPulldown(VAO_Type *VAOx, uint32_t pin)
{
    SET_BIT(VAOx->PUPDEN, ((pin & 0xffff) << 16U));
}

/**
  * @brief    Get PH pulldown enable status
  * @rmtoll   PUPDEN    PHPDEN    FL_VAO_GPIO_IsEnabledPHPulldown
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_IsEnabledPHPulldown(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAOx->PUPDEN, ((pin & 0xffff) << 16U)) == ((pin & 0xffff) << 16U));
}

/**
  * @brief    PH pulldown disable
  * @rmtoll   PUPDEN    PHPDEN    FL_VAO_GPIO_DisablePHPulldown
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_DisablePHPulldown(VAO_Type *VAOx, uint32_t pin)
{
    CLEAR_BIT(VAOx->PUPDEN, ((pin & 0xffff) << 16U));
}

/**
  * @brief    PH opendrain enable
  * @rmtoll   ODEN    PHODEN    FL_VAO_GPIO_EnablePHOpenDrain
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_EnablePHOpenDrain(VAO_Type *VAOx, uint32_t pin)
{
    SET_BIT(VAOx->ODEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Get PH opendrain enable status
  * @rmtoll   ODEN    PHODEN    FL_VAO_GPIO_IsEnabledPHOpenDrain
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_IsEnabledPHOpenDrain(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAOx->ODEN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    PH opendrain disable
  * @rmtoll   ODEN    PHODEN    FL_VAO_GPIO_DisablePHOpenDrain
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_DisablePHOpenDrain(VAO_Type *VAOx, uint32_t pin)
{
    CLEAR_BIT(VAOx->ODEN, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Set PH mode
  * @rmtoll   FCR    PH15FCR    FL_VAO_GPIO_SetPHMode
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_MODE_INPUT
  *           @arg @ref FL_VAO_PH_MODE_OUTPUT
  *           @arg @ref FL_VAO_PH_MODE_DIGTAL
  *           @arg @ref FL_VAO_PH_MODE_ANALOG
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_SetPHMode(VAO_Type *VAOx, uint32_t pin, uint32_t mode)
{
    MODIFY_REG(VAOx->FCR, ((pin * pin) * VAO_FCR_PHFCR), ((pin * pin) * mode));
}

/**
  * @brief    Get PH mode
  * @rmtoll   FCR    PH15FCR    FL_VAO_GPIO_GetPHMode
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VAO_PH_MODE_INPUT
  *           @arg @ref FL_VAO_PH_MODE_OUTPUT
  *           @arg @ref FL_VAO_PH_MODE_DIGTAL
  *           @arg @ref FL_VAO_PH_MODE_ANALOG
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_GetPHMode(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAOx->FCR, ((pin * pin) * VAO_FCR_PHFCR)) / (pin * pin));
}

/**
  * @brief    Set PH output data register
  * @rmtoll   DOR    PHDO    FL_VAO_GPIO_WritePHOutput
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @param    data
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_WritePHOutput(VAO_Type *VAOx, uint32_t output)
{
    MODIFY_REG(VAOx->DOR, (0xffffU << 0U), (output << 0U));
}

/**
  * @brief    Get PH1 output data
  * @rmtoll   DOR    PHDO    FL_VAO_GPIO_ReadPHOutput
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_ReadPHOutput(VAO_Type *VAOx)
{
    return (uint32_t)(READ_BIT(VAOx->DOR, (0xffffU << 0U)) >> 0U);
}

/**
  * @brief    Get PH1 input data
  * @rmtoll   DIN    PHDIN    FL_VAO_GPIO_ReadPHInput
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_ReadPHInput(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAOx->DIN, ((pin & 0xffff) << 0x0U)) == ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Set PH output driver Strength
  * @rmtoll   DSR    PHDSR    FL_VAO_GPIO_SetPHThreshold
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @param    value This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_THRESHOLD_X1
  *           @arg @ref FL_VAO_PH_THRESHOLD_X2
  *           @arg @ref FL_VAO_PH_THRESHOLD_X3
  *           @arg @ref FL_VAO_PH_THRESHOLD_X4
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_SetPinDriveStrength(VAO_Type *VAOx, uint32_t pin, uint32_t value)
{
    MODIFY_REG(VAO->DSR, ((pin * pin) * VAO_DSR_PHDSR), ((pin * pin) * value));
}

/**
  * @brief    Get PH output driver Strength
  * @rmtoll   DSR    PHDSR    FL_VAO_GPIO_GetPHThreshold
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_VAO_PH_THRESHOLD_X1
  *           @arg @ref FL_VAO_PH_THRESHOLD_X2
  *           @arg @ref FL_VAO_PH_THRESHOLD_X3
  *           @arg @ref FL_VAO_PH_THRESHOLD_X4
  */
__STATIC_INLINE uint32_t FL_VAO_GPIO_GetPHThreshold(VAO_Type *VAOx, uint32_t pin)
{
    return (uint32_t)(READ_BIT(VAO->DSR, ((pin * pin) * VAO_DSR_PHDSR)) / (pin * pin));
}

/**
  * @brief    Set pin output 1
  * @rmtoll   PHDSET    PHDSET    FL_VAO_GPIO_SetPHOutputPin
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_SetPHOutputPin(VAO_Type *VAOx, uint32_t pin)
{
    SET_BIT(VAOx->DOR, ((pin & 0xffff) << 0x0U));
}

/**
  * @brief    Set pin output 0
  * @rmtoll   PHDRESET    PHDRESET    FL_VAO_GPIO_ResetPHOutputPin
  * @param    VAOx VAO instance
  * @param    pin This parameter can be one of the following values:
  *           @arg @ref FL_VAO_PH_PIN_13
  *           @arg @ref FL_VAO_PH_PIN_14
  *           @arg @ref FL_VAO_PH_PIN_15
  * @retval   None
  */
__STATIC_INLINE void FL_VAO_GPIO_ResetPHOutputPin(VAO_Type *VAOx, uint32_t pin)
{
    CLEAR_BIT(VAOx->DOR, ((pin & 0xffff) << 0x0U));
}

/**
  * @}
  */

/** @defgroup VAO_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_VAO_DeInit(VAO_Type *VAOx);
FL_ErrorStatus FL_VAO_IO_Init(VAO_Type *VAOx, FL_VAO_IO_InitTypeDef *VAO_IO_InitStruct);
FL_ErrorStatus FL_VAO_XTLF_Init(VAO_Type *VAOx, FL_VAO_XTLF_InitTypeDef *VAO_XTLF_InitStruct);
void FL_VAO_XTLF_StructInit(FL_VAO_XTLF_InitTypeDef *VAO_XTLF_InitStruct);
void FL_VAO_IO_StructInit(FL_VAO_IO_InitTypeDef *VAO_IO_InitStruct);
/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_VAO_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-08-24*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
