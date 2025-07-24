/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_rmu.h
  * @author  FMSH Application Team
  * @brief   Head file of RMU FL Module
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
#ifndef __FM33FK5XX_FL_RMU_H
#define __FM33FK5XX_FL_RMU_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_ES_INIT RMU Exported Init structures
  * @{
  */

/**
  * @brief FL RMU Init Sturcture definition
  */

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_Exported_Constants RMU Exported Constants
  * @{
  */

#define    RMU_BORCR_CFG_Pos                                      (2U)
#define    RMU_BORCR_CFG_Msk                                      (0x3U << RMU_BORCR_CFG_Pos)
#define    RMU_BORCR_CFG                                          RMU_BORCR_CFG_Msk

#define    RMU_BORCR_ENB_Pos                                      (0U)
#define    RMU_BORCR_ENB_Msk                                      (0x1U << RMU_BORCR_ENB_Pos)
#define    RMU_BORCR_ENB                                          RMU_BORCR_ENB_Msk

#define    RMU_RSTCFG_EN_Pos                                      (1U)
#define    RMU_RSTCFG_EN_Msk                                      (0x1U << RMU_RSTCFG_EN_Pos)
#define    RMU_RSTCFG_EN                                          RMU_RSTCFG_EN_Msk

#define    RMU_RSTFLAG_MAP_FLAG_Pos                               (13U)
#define    RMU_RSTFLAG_MAP_FLAG_Msk                               (0x1U << RMU_RSTFLAG_MAP_FLAG_Pos)
#define    RMU_RSTFLAG_MAP_FLAG                                   RMU_RSTFLAG_MAP_FLAG_Msk

#define    RMU_RSTFLAG_MDFN_FLAG_Pos                              (12U)
#define    RMU_RSTFLAG_MDFN_FLAG_Msk                              (0x1U << RMU_RSTFLAG_MDFN_FLAG_Pos)
#define    RMU_RSTFLAG_MDFN_FLAG                                  RMU_RSTFLAG_MDFN_FLAG_Msk

#define    RMU_RSTFLAG_NRSTN_FLAG_Pos                             (11U)
#define    RMU_RSTFLAG_NRSTN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_NRSTN_FLAG_Pos)
#define    RMU_RSTFLAG_NRSTN_FLAG                                 RMU_RSTFLAG_NRSTN_FLAG_Msk

#define    RMU_RSTFLAG_BORN_FLAG_Pos                              (9U)
#define    RMU_RSTFLAG_BORN_FLAG_Msk                              (0x1U << RMU_RSTFLAG_BORN_FLAG_Pos)
#define    RMU_RSTFLAG_BORN_FLAG                                  RMU_RSTFLAG_BORN_FLAG_Msk

#define    RMU_RSTFLAG_PORN_FLAG_Pos                              (8U)
#define    RMU_RSTFLAG_PORN_FLAG_Msk                              (0x1U << RMU_RSTFLAG_PORN_FLAG_Pos)
#define    RMU_RSTFLAG_PORN_FLAG                                  RMU_RSTFLAG_PORN_FLAG_Msk

#define    RMU_RSTFLAG_TESTN_FLAG_Pos                             (6U)
#define    RMU_RSTFLAG_TESTN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_TESTN_FLAG_Pos)
#define    RMU_RSTFLAG_TESTN_FLAG                                 RMU_RSTFLAG_TESTN_FLAG_Msk

#define    RMU_RSTFLAG_SOFTN_FLAG_Pos                             (5U)
#define    RMU_RSTFLAG_SOFTN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_SOFTN_FLAG_Pos)
#define    RMU_RSTFLAG_SOFTN_FLAG                                 RMU_RSTFLAG_SOFTN_FLAG_Msk

#define    RMU_RSTFLAG_IWDTN_FLAG_Pos                             (4U)
#define    RMU_RSTFLAG_IWDTN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_IWDTN_FLAG_Pos)
#define    RMU_RSTFLAG_IWDTN_FLAG                                 RMU_RSTFLAG_IWDTN_FLAG_Msk

#define    RMU_RSTFLAG_WWDTN_FLAG_Pos                             (2U)
#define    RMU_RSTFLAG_WWDTN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_WWDTN_FLAG_Pos)
#define    RMU_RSTFLAG_WWDTN_FLAG                                 RMU_RSTFLAG_WWDTN_FLAG_Msk

#define    RMU_RSTFLAG_LKUPN_FLAG_Pos                             (1U)
#define    RMU_RSTFLAG_LKUPN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_LKUPN_FLAG_Pos)
#define    RMU_RSTFLAG_LKUPN_FLAG                                 RMU_RSTFLAG_LKUPN_FLAG_Msk

#define    RMU_RSTFLAG_NVICN_FLAG_Pos                             (0U)
#define    RMU_RSTFLAG_NVICN_FLAG_Msk                             (0x1U << RMU_RSTFLAG_NVICN_FLAG_Pos)
#define    RMU_RSTFLAG_NVICN_FLAG                                 RMU_RSTFLAG_NVICN_FLAG_Msk

#define    PERHRSTEN_KEY                                          (0x13579BDFUL)
#define    SOFTWARERESET_KEY                                      (0x5C5CAABBUL)

#define    FL_RMU_RSTAHB_DMA                                      (0x1U << 0U)
#define    FL_RMU_RSTAHB_USB                                      (0x1U << 1U)
#define    FL_RMU_RSTAPB_UART5                                    (0x1fU << 0U)
#define    FL_RMU_RSTAPB_UART4                                    (0x1eU << 0U)
#define    FL_RMU_RSTAPB_UART3                                    (0x1dU << 0U)
#define    FL_RMU_RSTAPB_UART2                                    (0x1cU << 0U)
#define    FL_RMU_RSTAPB_UART1                                    (0x1bU << 0U)
#define    FL_RMU_RSTAPB_UART0                                    (0x1aU << 0U)
#define    FL_RMU_RSTAPB_UCIR                                     (0x19U << 0U)
#define    FL_RMU_RSTAPB_GPTIM2                                   (0x17U << 0U)
#define    FL_RMU_RSTAPB_GPTIM1                                   (0x16U << 0U)
#define    FL_RMU_RSTAPB_GPTIM0                                   (0x15U << 0U)
#define    FL_RMU_RSTAPB_BTIM16                                   (0x12U << 0U)
#define    FL_RMU_RSTAPB_UART7                                    (0x11U << 0U)
#define    FL_RMU_RSTAPB_UART6                                    (0x10U << 0U)
#define    FL_RMU_RSTAPB_SPI2                                     (0xfU << 0U)
#define    FL_RMU_RSTAPB_SPI1                                     (0xeU << 0U)
#define    FL_RMU_RSTAPB_SPI0                                     (0xdU << 0U)
#define    FL_RMU_RSTAPB_I2C1                                     (0xcU << 0U)
#define    FL_RMU_RSTAPB_I2C0                                     (0xbU << 0U)
#define    FL_RMU_RSTAPB_LPUART1                                  (0x9U << 0U)
#define    FL_RMU_RSTAPB_LPUART0                                  (0x8U << 0U)
#define    FL_RMU_RSTAPB_SPI4                                     (0x7U << 0U)
#define    FL_RMU_RSTAPB_SPI3                                     (0x6U << 0U)
#define    FL_RMU_RSTAPB_PGL                                      (0x5U << 0U)
#define    FL_RMU_RSTAPB_I2CSMB2                                  (0x4U << 0U)
#define    FL_RMU_RSTAPB_I2CSMB1                                  (0x3U << 0U)
#define    FL_RMU_RSTAPB_I2CSMB0                                  (0x2U << 0U)
#define    FL_RMU_RSTAPB_LPTIM16                                  (0x1U << 0U)
#define    FL_RMU_RSTAPB_OPA                                      (0x3aU << 0U)
#define    FL_RMU_RSTAPB_DAC                                      (0x39U << 0U)
#define    FL_RMU_RSTAPB_ADCCR                                    (0x38U << 0U)
#define    FL_RMU_RSTAPB_ADC                                      (0x37U << 0U)
#define    FL_RMU_RSTAPB_AES                                      (0x32U << 0U)
#define    FL_RMU_RSTAPB_CRC                                      (0x31U << 0U)
#define    FL_RMU_RSTAPB_RNG                                      (0x30U << 0U)
#define    FL_RMU_RSTAPB_EPWM3                                    (0x2fU << 0U)
#define    FL_RMU_RSTAPB_EPWM2                                    (0x2eU << 0U)
#define    FL_RMU_RSTAPB_EPWM1                                    (0x2dU << 0U)
#define    FL_RMU_RSTAPB_EPWM0                                    (0x2cU << 0U)
#define    FL_RMU_RSTAPB_EPSC                                     (0x29U << 0U)
#define    FL_RMU_RSTAPB_QSPI                                     (0x28U << 0U)
#define    FL_RMU_RSTAPB_CAN2                                     (0x27U << 0U)
#define    FL_RMU_RSTAPB_FDCAN                                    (0x26U << 0U)
#define    FL_RMU_RSTAPB_FSCAN                                    (0x25U << 0U)
#define    FL_RMU_RSTAPB_ATIM1                                    (0x23U << 0U)
#define    FL_RMU_RSTAPB_ATIM0                                    (0x22U << 0U)
#define    FL_RMU_RSTAPB_SVD                                      (0x21U << 0U)
#define    FL_RMU_RSTAPB_COMP                                     (0x20U << 0U)

#define    FL_RMU_BOR_THRESHOLD_1P80V                             (0x0U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P00V                             (0x1U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P20V                             (0x2U << RMU_BORCR_CFG_Pos)
#define    FL_RMU_BOR_THRESHOLD_2P40V                             (0x3U << RMU_BORCR_CFG_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup RMU_FL_Exported_Functions RMU Exported Functions
  * @{
  */

/**
  * @brief    Set Brown Out Reset Voltage
  * @rmtoll   BORCR    CFG    FL_RMU_BOR_SetThreshold
  * @param    RMUx RMU instance
  * @param    threshold This parameter can be one of the following values:
  *           @arg @ref FL_RMU_BOR_THRESHOLD_1P80V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P00V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P20V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P40V
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_BOR_SetThreshold(RMU_Type *RMUx, uint32_t threshold)
{
    MODIFY_REG(RMUx->BORCR, RMU_BORCR_CFG_Msk, threshold);
}

/**
  * @brief    Get Brown Out Reset Setting
  * @rmtoll   BORCR    CFG    FL_RMU_BOR_GetThreshold
  * @param    RMUx RMU instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_RMU_BOR_THRESHOLD_1P80V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P00V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P20V
  *           @arg @ref FL_RMU_BOR_THRESHOLD_2P40V
  */
__STATIC_INLINE uint32_t FL_RMU_BOR_GetThreshold(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->BORCR, RMU_BORCR_CFG_Msk));
}

/**
  * @brief    Get Brown Out Reset Enable Status
  * @rmtoll   BORCR    ENB    FL_RMU_BOR_IsEnabled
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_BOR_IsEnabled(RMU_Type *RMUx)
{
    return (uint32_t)!(READ_BIT(RMUx->BORCR, RMU_BORCR_ENB_Msk) == RMU_BORCR_ENB_Msk);
}

/**
  * @brief    Disable Brown Out Reset
  * @rmtoll   BORCR    ENB    FL_RMU_BOR_Disable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_BOR_Disable(RMU_Type *RMUx)
{
    SET_BIT(RMUx->BORCR, RMU_BORCR_ENB_Msk);
}

/**
  * @brief    Enable Brown Out Reset
  * @rmtoll   BORCR    ENB    FL_RMU_BOR_Enable
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_BOR_Enable(RMU_Type *RMUx)
{
    CLEAR_BIT(RMUx->BORCR, RMU_BORCR_ENB_Msk);
}

/**
  * @brief    Get LockUp Reset Enable Status
  * @rmtoll   RSTCFG    EN    FL_RMU_IsEnabledLockUpReset
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsEnabledLockUpReset(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTCFG, RMU_RSTCFG_EN_Msk) == RMU_RSTCFG_EN_Msk);
}

/**
  * @brief    Disable LockUp Reset
  * @rmtoll   RSTCFG    EN    FL_RMU_DisableLockUpReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableLockUpReset(RMU_Type *RMUx)
{
    CLEAR_BIT(RMUx->RSTCFG, RMU_RSTCFG_EN_Msk);
}

/**
  * @brief    Enable LockUp Reset
  * @rmtoll   RSTCFG    EN    FL_RMU_EnableLockUpReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableLockUpReset(RMU_Type *RMUx)
{
    SET_BIT(RMUx->RSTCFG, RMU_RSTCFG_EN_Msk);
}

/**
  * @brief    Soft Reset Chip
  * @rmtoll   SOFTRST        FL_RMU_SetSoftReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_SetSoftReset(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->SOFTRST, SOFTWARERESET_KEY);
}

/**
  * @brief    Get MAP Error Flag
  * @rmtoll   RSTFLAG    MAP_FLAG    FL_RMU_IsActiveFlag_MAP
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_MAP(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_MAP_FLAG_Msk) == (RMU_RSTFLAG_MAP_FLAG_Msk));
}

/**
  * @brief    Clear MAP Reset Flag
  * @rmtoll   RSTFLAG    MAP_FLAG    FL_RMU_ClearFlag_MAP
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_MAP(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_MAP_FLAG_Msk);
}

/**
  * @brief    Get MDF Reset Flag
  * @rmtoll   RSTFLAG    MDFN_FLAG    FL_RMU_IsActiveFlag_MDF
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_MDF(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_MDFN_FLAG_Msk) == (RMU_RSTFLAG_MDFN_FLAG_Msk));
}

/**
  * @brief    Clear MDF Reset Flag
  * @rmtoll   RSTFLAG    MDFN_FLAG    FL_RMU_ClearFlag_MDF
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_MDF(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_MDFN_FLAG_Msk);
}

/**
  * @brief    Get NRST Reset Flag
  * @rmtoll   RSTFLAG    NRSTN_FLAG    FL_RMU_IsActiveFlag_NRSTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_NRSTN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_NRSTN_FLAG_Msk) == (RMU_RSTFLAG_NRSTN_FLAG_Msk));
}

/**
  * @brief    Clear NRST Reset Flag
  * @rmtoll   RSTFLAG    NRSTN_FLAG    FL_RMU_ClearFlag_NRSTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_NRSTN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_NRSTN_FLAG_Msk);
}

/**
  * @brief    Get Power On Reset Flag
  * @rmtoll   RSTFLAG    BORN_FLAG    FL_RMU_IsActiveFlag_PORN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_PORN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_BORN_FLAG_Msk) == (RMU_RSTFLAG_BORN_FLAG_Msk));
}

/**
  * @brief    Clear Power On Reset Flag
  * @rmtoll   RSTFLAG    BORN_FLAG    FL_RMU_ClearFlag_PORN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_PORN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_BORN_FLAG_Msk);
}

/**
  * @brief    Get Power Down Reset Flag
  * @rmtoll   RSTFLAG    PORN_FLAG    FL_RMU_IsActiveFlag_PDRN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_PDRN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_PORN_FLAG_Msk) == (RMU_RSTFLAG_PORN_FLAG_Msk));
}

/**
  * @brief    Clear Power Down Reset Flag
  * @rmtoll   RSTFLAG    PORN_FLAG    FL_RMU_ClearFlag_PDRN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_PDRN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_PORN_FLAG_Msk);
}

/**
  * @brief    Get TESTN Reset Flag
  * @rmtoll   RSTFLAG    TESTN_FLAG    FL_RMU_IsActiveFlag_TESTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_TESTN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_TESTN_FLAG_Msk) == (RMU_RSTFLAG_TESTN_FLAG_Msk));
}

/**
  * @brief    Clear TESTN Reset Flag
  * @rmtoll   RSTFLAG    TESTN_FLAG    FL_RMU_ClearFlag_TESTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_TESTN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_TESTN_FLAG_Msk);
}

/**
  * @brief    Get Software Reset Flag
  * @rmtoll   RSTFLAG    SOFTN_FLAG    FL_RMU_IsActiveFlag_SOFTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_SOFTN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_SOFTN_FLAG_Msk) == (RMU_RSTFLAG_SOFTN_FLAG_Msk));
}

/**
  * @brief    Clear Software Reset Flag
  * @rmtoll   RSTFLAG    SOFTN_FLAG    FL_RMU_ClearFlag_SOFTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_SOFTN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_SOFTN_FLAG_Msk);
}

/**
  * @brief    Get IWDT Reset Flag
  * @rmtoll   RSTFLAG    IWDTN_FLAG    FL_RMU_IsActiveFlag_IWDTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_IWDTN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_IWDTN_FLAG_Msk) == (RMU_RSTFLAG_IWDTN_FLAG_Msk));
}

/**
  * @brief    Clear IWDT Reset Flag
  * @rmtoll   RSTFLAG    IWDTN_FLAG    FL_RMU_ClearFlag_IWDTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_IWDTN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_IWDTN_FLAG_Msk);
}

/**
  * @brief    Get WWDT Reset Flag
  * @rmtoll   RSTFLAG    WWDTN_FLAG    FL_RMU_IsActiveFlag_WWDTN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_WWDTN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_WWDTN_FLAG_Msk) == (RMU_RSTFLAG_WWDTN_FLAG_Msk));
}

/**
  * @brief    Clear WWDT Reset Flag
  * @rmtoll   RSTFLAG    WWDTN_FLAG    FL_RMU_ClearFlag_WWDTN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_WWDTN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_WWDTN_FLAG_Msk);
}

/**
  * @brief    Get LockUp Reset Flag
  * @rmtoll   RSTFLAG    LKUPN_FLAG    FL_RMU_IsActiveFlag_LKUPN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_LKUPN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_LKUPN_FLAG_Msk) == (RMU_RSTFLAG_LKUPN_FLAG_Msk));
}

/**
  * @brief    Clear LockUp Reset Flag
  * @rmtoll   RSTFLAG    LKUPN_FLAG    FL_RMU_ClearFlag_LKUPN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_LKUPN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_LKUPN_FLAG_Msk);
}

/**
  * @brief    Get NVIC Reset Flag
  * @rmtoll   RSTFLAG    NVICN_FLAG    FL_RMU_IsActiveFlag_NVICN
  * @param    RMUx RMU instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_RMU_IsActiveFlag_NVICN(RMU_Type *RMUx)
{
    return (uint32_t)(READ_BIT(RMUx->RSTFLAG, RMU_RSTFLAG_NVICN_FLAG_Msk) == (RMU_RSTFLAG_NVICN_FLAG_Msk));
}

/**
  * @brief    Clear NVIC Reset Flag
  * @rmtoll   RSTFLAG    NVICN_FLAG    FL_RMU_ClearFlag_NVICN
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_ClearFlag_NVICN(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->RSTFLAG, RMU_RSTFLAG_NVICN_FLAG_Msk);
}

/**
  * @brief    Disable Peripheral Reset
  * @rmtoll   PERHRSTEN        FL_RMU_DisablePeripheralReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisablePeripheralReset(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->PERHRSTEN, (~PERHRSTEN_KEY));
}

/**
  * @brief    Enable Peripheral Reset
  * @rmtoll   PERHRSTEN        FL_RMU_EnablePeripheralReset
  * @param    RMUx RMU instance
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnablePeripheralReset(RMU_Type *RMUx)
{
    WRITE_REG(RMUx->PERHRSTEN, PERHRSTEN_KEY);
}

/**
  * @brief    Enable AHB Peripheral Reset
  * @rmtoll   AHBRST        FL_RMU_EnableResetAHBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAHB_USB
  *           @arg @ref FL_RMU_RSTAHB_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableResetAHBPeripheral(RMU_Type *RMUx, uint32_t peripheral)
{
    SET_BIT(RMUx->AHBRST, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Enable APB Peripheral Reset1
  * @rmtoll   APBRST        FL_RMU_EnableResetAPBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAPB_UART5
  *           @arg @ref FL_RMU_RSTAPB_UART4
  *           @arg @ref FL_RMU_RSTAPB_UART3
  *           @arg @ref FL_RMU_RSTAPB_UART2
  *           @arg @ref FL_RMU_RSTAPB_UART1
  *           @arg @ref FL_RMU_RSTAPB_UART0
  *           @arg @ref FL_RMU_RSTAPB_UCIR
  *           @arg @ref FL_RMU_RSTAPB_GPTIM2
  *           @arg @ref FL_RMU_RSTAPB_GPTIM1
  *           @arg @ref FL_RMU_RSTAPB_GPTIM0
  *           @arg @ref FL_RMU_RSTAPB_BTIM16
  *           @arg @ref FL_RMU_RSTAPB_UART7
  *           @arg @ref FL_RMU_RSTAPB_UART6
  *           @arg @ref FL_RMU_RSTAPB_SPI2
  *           @arg @ref FL_RMU_RSTAPB_SPI1
  *           @arg @ref FL_RMU_RSTAPB_SPI0
  *           @arg @ref FL_RMU_RSTAPB_I2C1
  *           @arg @ref FL_RMU_RSTAPB_I2C0
  *           @arg @ref FL_RMU_RSTAPB_LPUART1
  *           @arg @ref FL_RMU_RSTAPB_LPUART0
  *           @arg @ref FL_RMU_RSTAPB_SPI4
  *           @arg @ref FL_RMU_RSTAPB_SPI3
  *           @arg @ref FL_RMU_RSTAPB_PGL
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB2
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB1
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM16
  *           @arg @ref FL_RMU_RSTAPB_OPA
  *           @arg @ref FL_RMU_RSTAPB_DAC
  *           @arg @ref FL_RMU_RSTAPB_ADCCR
  *           @arg @ref FL_RMU_RSTAPB_ADC
  *           @arg @ref FL_RMU_RSTAPB_AES
  *           @arg @ref FL_RMU_RSTAPB_CRC
  *           @arg @ref FL_RMU_RSTAPB_RNG
  *           @arg @ref FL_RMU_RSTAPB_EPWM3
  *           @arg @ref FL_RMU_RSTAPB_EPWM2
  *           @arg @ref FL_RMU_RSTAPB_EPWM1
  *           @arg @ref FL_RMU_RSTAPB_EPWM0
  *           @arg @ref FL_RMU_RSTAPB_EPSC
  *           @arg @ref FL_RMU_RSTAPB_QSPI
  *           @arg @ref FL_RMU_RSTAPB_CAN2
  *           @arg @ref FL_RMU_RSTAPB_FDCAN
  *           @arg @ref FL_RMU_RSTAPB_FSCAN
  *           @arg @ref FL_RMU_RSTAPB_ATIM1
  *           @arg @ref FL_RMU_RSTAPB_ATIM0
  *           @arg @ref FL_RMU_RSTAPB_SVD
  *           @arg @ref FL_RMU_RSTAPB_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_EnableResetAPBPeripheral(RMU_Type *RMUx, uint32_t peripheral)
{
    if(peripheral < FL_RMU_RSTAPB_COMP)
    {
        SET_BIT(RMUx->APBRST1, (0x1U << peripheral));
    }
    else
    {
        SET_BIT(RMUx->APBRST2, (0x1U << (peripheral - 32)));
    }
}

/**
  * @brief    Disable AHB Peripheral Reset
  * @rmtoll   AHBRST        FL_RMU_DisableResetAHBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAHB_USB
  *           @arg @ref FL_RMU_RSTAHB_DMA
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableResetAHBPeripheral(RMU_Type *RMUx, uint32_t peripheral)
{
    CLEAR_BIT(RMUx->AHBRST, ((peripheral & 0xffffffff) << 0x0U));
}

/**
  * @brief    Disable APB Peripheral Reset1
  * @rmtoll   APBRST        FL_RMU_DisableResetAPBPeripheral
  * @param    RMUx RMU instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_RMU_RSTAPB_UART5
  *           @arg @ref FL_RMU_RSTAPB_UART4
  *           @arg @ref FL_RMU_RSTAPB_UART3
  *           @arg @ref FL_RMU_RSTAPB_UART2
  *           @arg @ref FL_RMU_RSTAPB_UART1
  *           @arg @ref FL_RMU_RSTAPB_UART0
  *           @arg @ref FL_RMU_RSTAPB_UCIR
  *           @arg @ref FL_RMU_RSTAPB_GPTIM2
  *           @arg @ref FL_RMU_RSTAPB_GPTIM1
  *           @arg @ref FL_RMU_RSTAPB_GPTIM0
  *           @arg @ref FL_RMU_RSTAPB_BTIM16
  *           @arg @ref FL_RMU_RSTAPB_UART7
  *           @arg @ref FL_RMU_RSTAPB_UART6
  *           @arg @ref FL_RMU_RSTAPB_SPI2
  *           @arg @ref FL_RMU_RSTAPB_SPI1
  *           @arg @ref FL_RMU_RSTAPB_SPI0
  *           @arg @ref FL_RMU_RSTAPB_I2C1
  *           @arg @ref FL_RMU_RSTAPB_I2C0
  *           @arg @ref FL_RMU_RSTAPB_LPUART1
  *           @arg @ref FL_RMU_RSTAPB_LPUART0
  *           @arg @ref FL_RMU_RSTAPB_SPI4
  *           @arg @ref FL_RMU_RSTAPB_SPI3
  *           @arg @ref FL_RMU_RSTAPB_PGL
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB2
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB1
  *           @arg @ref FL_RMU_RSTAPB_I2CSMB0
  *           @arg @ref FL_RMU_RSTAPB_LPTIM16
  *           @arg @ref FL_RMU_RSTAPB_OPA
  *           @arg @ref FL_RMU_RSTAPB_DAC
  *           @arg @ref FL_RMU_RSTAPB_ADCCR
  *           @arg @ref FL_RMU_RSTAPB_ADC
  *           @arg @ref FL_RMU_RSTAPB_AES
  *           @arg @ref FL_RMU_RSTAPB_CRC
  *           @arg @ref FL_RMU_RSTAPB_RNG
  *           @arg @ref FL_RMU_RSTAPB_EPWM3
  *           @arg @ref FL_RMU_RSTAPB_EPWM2
  *           @arg @ref FL_RMU_RSTAPB_EPWM1
  *           @arg @ref FL_RMU_RSTAPB_EPWM0
  *           @arg @ref FL_RMU_RSTAPB_EPSC
  *           @arg @ref FL_RMU_RSTAPB_QSPI
  *           @arg @ref FL_RMU_RSTAPB_CAN2
  *           @arg @ref FL_RMU_RSTAPB_FDCAN
  *           @arg @ref FL_RMU_RSTAPB_FSCAN
  *           @arg @ref FL_RMU_RSTAPB_ATIM1
  *           @arg @ref FL_RMU_RSTAPB_ATIM0
  *           @arg @ref FL_RMU_RSTAPB_SVD
  *           @arg @ref FL_RMU_RSTAPB_COMP
  * @retval   None
  */
__STATIC_INLINE void FL_RMU_DisableResetAPBPeripheral(RMU_Type *RMUx, uint32_t peripheral)
{
    if(peripheral < FL_RMU_RSTAPB_COMP)
    {
        CLEAR_BIT(RMUx->APBRST1, (0x1U << peripheral));
    }
    else
    {
        CLEAR_BIT(RMUx->APBRST2, (0x1U << (peripheral - 32)));
    }
}

/**
  * @}
  */

/** @defgroup RMU_FL_EF_Init Initialization and de-initialization functions
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

#endif /* __FM33FK5XX_FL_RMU_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-09-07*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
