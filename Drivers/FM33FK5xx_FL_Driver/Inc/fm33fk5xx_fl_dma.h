/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_dma.h
  * @author  FMSH Application Team
  * @brief   Head file of DMA FL Module
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
#ifndef __FM33FK5XX_FL_DMA_H
#define __FM33FK5XX_FL_DMA_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup DMA_FL_ES_INIT DMA Exported Init structures
  * @{
  */

/**
  * @brief FL DMA Init Sturcture definition
  */
typedef struct
{
    /* DMA外设映射地址(外设请求源:0~127)*/
    uint32_t periphAddress;
    /*! DMA传输方向 */
    uint32_t direction;
    /*! RAM地址增长方向 */
    uint32_t memoryAddressIncMode;
    /*! 外设地址增长方向 */
    uint32_t peripheralAddressIncMode;
    /*! DAM传输通道数据位宽 */
    uint32_t dataSize;
    /*! DMA通道优先级 */
    uint32_t priority;
    /*! 循环模式使能 */
    uint32_t circMode;
    /*! 双缓冲区模式使能 */
    uint32_t dbufMode;

} FL_DMA_InitTypeDef;

/**
  * @brief FL DMA Config Sturcture definition
  */
typedef struct
{
    /*! 外设地址 */
    uint32_t peripheralAddress;
    /*! RAM0地址 */
    uint32_t memoryAddress0;
    /*! RAM1地址 */
    uint32_t memoryAddress1;
    /*! DMA传输数据字节个数 */
    uint32_t transmissionCount;

} FL_DMA_ConfigTypeDef;

/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */
typedef struct
{
    __IO uint32_t CHCR;
    __IO uint32_t CFGR;
    __IO uint32_t PAR;
    __IO uint32_t CHMAD0;
    __IO uint32_t CHMAD1;
    __IO uint32_t RSV[3];
} CHANNEL;

/**
  * @brief Configuration with temporary structure variable users will not be used directly
  */
typedef struct
{
    __IO CHANNEL  Channel[7];
    __IO uint32_t CH7CR;
    __IO uint32_t CH7FLSAD;
    __IO uint32_t CH7MAD;
    __IO uint32_t RSV5[69];               /*!<  RESERVED REGISTER,                                    Address offset: 0xEC */
    __IO uint32_t GCR;                    /*!<  DMA Global Control Register,                          Address offset: 0x200 */
    __IO uint32_t SWRR;                   /*!<  DMA Software Request Register,                        Address offset: 0x204 */
    __IO uint32_t RSV6[62];               /*!<  RESERVED REGISTER,                                    Address offset: 0x208 */
    __IO uint32_t ISR;                    /*!<  DMA Interrupt Status Register,                        Address offset: 0x300 */
    __I  uint32_t TFSADDR[7];             /*!<  ,                                                     Address offset: 0x304 */
} DMA_ADDR;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup DMA_FL_Exported_Constants DMA Exported Constants
  * @{
  */

#define    DMA_CHCR_MINC_Pos                                      (6U)
#define    DMA_CHCR_MINC_Msk                                      (0x3U << DMA_CHCR_MINC_Pos)
#define    DMA_CHCR_MINC                                          DMA_CHCR_MINC_Msk

#define    DMA_CHCR_PINC_Pos                                      (4U)
#define    DMA_CHCR_PINC_Msk                                      (0x3U << DMA_CHCR_PINC_Pos)
#define    DMA_CHCR_PINC                                          DMA_CHCR_PINC_Msk

#define    DMA_CHCR_DBUF_Pos                                      (3U)
#define    DMA_CHCR_DBUF_Msk                                      (0x1U << DMA_CHCR_DBUF_Pos)
#define    DMA_CHCR_DBUF                                          DMA_CHCR_DBUF_Msk

#define    DMA_CHCR_EN_Pos                                        (0U)
#define    DMA_CHCR_EN_Msk                                        (0x1U << DMA_CHCR_EN_Pos)
#define    DMA_CHCR_EN                                            DMA_CHCR_EN_Msk

#define    DMA_CFGR_TSIZE_Pos                                     (16U)
#define    DMA_CFGR_TSIZE_Msk                                     (0xffffU << DMA_CFGR_TSIZE_Pos)
#define    DMA_CFGR_TSIZE                                         DMA_CFGR_TSIZE_Msk

#define    DMA_CFGR_SUSP_Pos                                      (15U)
#define    DMA_CFGR_SUSP_Msk                                      (0x1U << DMA_CFGR_SUSP_Pos)
#define    DMA_CFGR_SUSP                                          DMA_CFGR_SUSP_Msk

#define    DMA_CFGR_RSEL_Pos                                      (8U)
#define    DMA_CFGR_RSEL_Msk                                      (0x7fU << DMA_CFGR_RSEL_Pos)
#define    DMA_CFGR_RSEL                                          DMA_CFGR_RSEL_Msk

#define    DMA_CFGR_PRI_Pos                                       (6U)
#define    DMA_CFGR_PRI_Msk                                       (0x3U << DMA_CFGR_PRI_Pos)
#define    DMA_CFGR_PRI                                           DMA_CFGR_PRI_Msk

#define    DMA_CFGR_BDW_Pos                                       (4U)
#define    DMA_CFGR_BDW_Msk                                       (0x3U << DMA_CFGR_BDW_Pos)
#define    DMA_CFGR_BDW                                           DMA_CFGR_BDW_Msk

#define    DMA_CFGR_CIRC_Pos                                      (3U)
#define    DMA_CFGR_CIRC_Msk                                      (0x1U << DMA_CFGR_CIRC_Pos)
#define    DMA_CFGR_CIRC                                          DMA_CFGR_CIRC_Msk

#define    DMA_CFGR_FTIE_Pos                                      (2U)
#define    DMA_CFGR_FTIE_Msk                                      (0x1U << DMA_CFGR_FTIE_Pos)
#define    DMA_CFGR_FTIE                                          DMA_CFGR_FTIE_Msk

#define    DMA_CFGR_HTIE_Pos                                      (1U)
#define    DMA_CFGR_HTIE_Msk                                      (0x1U << DMA_CFGR_HTIE_Pos)
#define    DMA_CFGR_HTIE                                          DMA_CFGR_HTIE_Msk

#define    DMA_CFGR_DIR_Pos                                       (0U)
#define    DMA_CFGR_DIR_Msk                                       (0x1U << DMA_CFGR_DIR_Pos)
#define    DMA_CFGR_DIR                                            DMA_CFGR_DIR_Msk

#define    DMA_CH7CR_PRI_Pos                                      (12U)
#define    DMA_CH7CR_PRI_Msk                                      (0x3U << DMA_CH7CR_PRI_Pos)
#define    DMA_CH7CR_PRI                                          DMA_CH7CR_PRI_Msk

#define    DMA_CH7CR_DIR_Pos                                      (10U)
#define    DMA_CH7CR_DIR_Msk                                      (0x1UL << DMA_CH7CR_DIR_Pos)
#define    DMA_CH7CR_DIR                                          DMA_CH7CR_DIR_Msk

#define    DMA_CH7CR_RINC_Pos                                     (9U)
#define    DMA_CH7CR_RINC_Msk                                     (0x1U << DMA_CH7CR_RINC_Pos)
#define    DMA_CH7CR_RINC                                         DMA_CH7CR_RINC_Msk

#define    DMA_CH7CR_FINC_Pos                                     (8U)
#define    DMA_CH7CR_FINC_Msk                                     (0x1U << DMA_CH7CR_FINC_Pos)
#define    DMA_CH7CR_FINC                                         DMA_CH7CR_FINC_Msk

#define    DMA_GCR_ADDRERR_IE_Pos                                 (1U)
#define    DMA_GCR_ADDRERR_IE_Msk                                 (0x1U << DMA_GCR_ADDRERR_IE_Pos)
#define    DMA_GCR_ADDRERR_IE                                     DMA_GCR_ADDRERR_IE_Msk

#define    DMA_GCR_EN_Pos                                         (0U)
#define    DMA_GCR_EN_Msk                                         (0x1U << DMA_GCR_EN_Pos)
#define    DMA_GCR_EN                                             DMA_GCR_EN_Msk

#define    DMA_ISR_ADDRERR_Pos                                    (17U)
#define    DMA_ISR_ADDRERR_Msk                                    (0x1U << DMA_ISR_ADDRERR_Pos)
#define    DMA_ISR_ADDRERR                                        DMA_ISR_ADDRERR_Msk

#define    DMA_ISR_CHFT_Pos                                       (8U)
#define    DMA_ISR_CHFT_Msk                                       (0x1U << DMA_ISR_CHFT_Pos)
#define    DMA_ISR_CHFT                                           DMA_ISR_CHFT_Msk

#define    DMA_ISR_CHHT_Pos                                       (0U)
#define    DMA_ISR_CHHT_Msk                                       (0x1U << DMA_ISR_CHHT_Pos)
#define    DMA_ISR_CHHT                                           DMA_ISR_CHHT_Msk

#define    FL_DMA_CHANNEL_0                                       (0x0U << 0U)
#define    FL_DMA_CHANNEL_1                                       (0x1U << 0U)
#define    FL_DMA_CHANNEL_2                                       (0x2U << 0U)
#define    FL_DMA_CHANNEL_3                                       (0x3U << 0U)
#define    FL_DMA_CHANNEL_4                                       (0x4U << 0U)
#define    FL_DMA_CHANNEL_5                                       (0x5U << 0U)
#define    FL_DMA_CHANNEL_6                                       (0x6U << 0U)
#define    FL_DMA_CHANNEL_7                                       (0x7U << 0U)

#define    FL_DMA_MEMORY_INC_MODE_NOCHANGE                         (0x0U << DMA_CHCR_MINC_Pos)
#define    FL_DMA_MEMORY_INC_MODE_INCREASE                           (0x1U << DMA_CHCR_MINC_Pos)
#define    FL_DMA_MEMORY_INC_MODE_DECREASE                           (0x2U << DMA_CHCR_MINC_Pos)

#define    FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE                  (0x0U << DMA_CHCR_PINC_Pos)
#define    FL_DMA_PERIPHERAL_INC_MODE_INCREASE                    (0x1U << DMA_CHCR_PINC_Pos)
#define    FL_DMA_PERIPHERAL_INC_MODE_DECREASE                    (0x2U << DMA_CHCR_PINC_Pos)

#define    FL_DMA_CHANNEL_SPI0_RX                                 (0x0U)
#define    FL_DMA_CHANNEL_SPI1_RX                                 (0x1U)
#define    FL_DMA_CHANNEL_SPI2_RX                                 (0x2U)
#define    FL_DMA_CHANNEL_SPI3_RX                                 (0x3U)
#define    FL_DMA_CHANNEL_SPI0_TX                                 (0x6U)
#define    FL_DMA_CHANNEL_SPI1_TX                                 (0x7U)
#define    FL_DMA_CHANNEL_SPI2_TX                                 (0x8U)
#define    FL_DMA_CHANNEL_SPI3_TX                                 (0x9U)
#define    FL_DMA_CHANNEL_UART0_RX                                (0xcU)
#define    FL_DMA_CHANNEL_UART1_RX                                (0xdU)
#define    FL_DMA_CHANNEL_UART2_RX                                (0xeU)
#define    FL_DMA_CHANNEL_UART3_RX                                (0xfU)
#define    FL_DMA_CHANNEL_UART4_RX                                (0x10U)
#define    FL_DMA_CHANNEL_UART5_RX                                (0x11U)
#define    FL_DMA_CHANNEL_UART6_RX                                (0x12U)
#define    FL_DMA_CHANNEL_UART7_RX                                (0x16U)
#define    FL_DMA_CHANNEL_UART0_TX                                (0x17U)
#define    FL_DMA_CHANNEL_UART1_TX                                (0x18U)
#define    FL_DMA_CHANNEL_UART2_TX                                (0x19U)
#define    FL_DMA_CHANNEL_UART3_TX                                (0x1aU)
#define    FL_DMA_CHANNEL_UART4_TX                                (0x1bU)
#define    FL_DMA_CHANNEL_UART5_TX                                (0x1cU)
#define    FL_DMA_CHANNEL_UART6_TX                                (0x1dU)
#define    FL_DMA_CHANNEL_UART7_TX                                (0x1eU)
#define    FL_DMA_CHANNEL_LPUART0_RX                              (0x22U)
#define    FL_DMA_CHANNEL_LPUART1_RX                              (0x23U)
#define    FL_DMA_CHANNEL_LPUART0_TX                              (0x25U)
#define    FL_DMA_CHANNEL_LPUART1_TX                              (0x26U)
#define    FL_DMA_CHANNEL_I2C_SMB0_RX                             (0x28U)
#define    FL_DMA_CHANNEL_I2C_SMB1_RX                             (0x29U)
#define    FL_DMA_CHANNEL_I2C_SMB2_RX                             (0x2aU)
#define    FL_DMA_CHANNEL_I2C_SMB0_TX                             (0x2cU)
#define    FL_DMA_CHANNEL_I2C_SMB1_TX                             (0x2dU)
#define    FL_DMA_CHANNEL_I2C_SMB2_TX                             (0x2eU)
#define    FL_DMA_CHANNEL_AES_IN                                  (0x30U)
#define    FL_DMA_CHANNEL_AES_OUT                                 (0x31U)
#define    FL_DMA_CHANNEL_CRC                                     (0x33U)
#define    FL_DMA_CHANNEL_ATIM0_CH1                               (0x35U)
#define    FL_DMA_CHANNEL_ATIM0_CH2                               (0x36U)
#define    FL_DMA_CHANNEL_ATIM0_CH3                               (0x37U)
#define    FL_DMA_CHANNEL_ATIM0_CH4                               (0x38U)
#define    FL_DMA_CHANNEL_ATIM0_TRIG                              (0x39U)
#define    FL_DMA_CHANNEL_ATIM0_COM                               (0x3aU)
#define    FL_DMA_CHANNEL_ATIM0_UEV                               (0x3bU)
#define    FL_DMA_CHANNEL_ATIM1_CH1                               (0x3cU)
#define    FL_DMA_CHANNEL_ATIM1_CH2                               (0x3dU)
#define    FL_DMA_CHANNEL_ATIM1_CH3                               (0x3eU)
#define    FL_DMA_CHANNEL_ATIM1_CH4                               (0x3fU)
#define    FL_DMA_CHANNEL_ATIM1_TRIG                              (0x40U)
#define    FL_DMA_CHANNEL_ATIM1_COM                               (0x41U)
#define    FL_DMA_CHANNEL_ATIM1_UEV                               (0x42U)
#define    FL_DMA_CHANNEL_GPTIM0_CH1                              (0x4aU)
#define    FL_DMA_CHANNEL_GPTIM0_CH2                              (0x4bU)
#define    FL_DMA_CHANNEL_GPTIM0_CH3                              (0x4cU)
#define    FL_DMA_CHANNEL_GPTIM0_CH4                              (0x4dU)
#define    FL_DMA_CHANNEL_GPTIM0_TRIG                             (0x4eU)
#define    FL_DMA_CHANNEL_GPTIM0_UEV                              (0x4fU)
#define    FL_DMA_CHANNEL_GPTIM1_CH1                              (0x50U)
#define    FL_DMA_CHANNEL_GPTIM1_CH2                              (0x51U)
#define    FL_DMA_CHANNEL_GPTIM1_CH3                              (0x52U)
#define    FL_DMA_CHANNEL_GPTIM1_CH4                              (0x53U)
#define    FL_DMA_CHANNEL_GPTIM1_TRIG                             (0x54U)
#define    FL_DMA_CHANNEL_GPTIM1_UEV                              (0x55U)
#define    FL_DMA_CHANNEL_GPTIM2_CH1                              (0x56U)
#define    FL_DMA_CHANNEL_GPTIM2_CH2                              (0x57U)
#define    FL_DMA_CHANNEL_GPTIM2_CH3                              (0x58U)
#define    FL_DMA_CHANNEL_GPTIM2_CH4                              (0x59U)
#define    FL_DMA_CHANNEL_GPTIM2_TRIG                             (0x5aU)
#define    FL_DMA_CHANNEL_GPTIM2_UEV                              (0x5bU)
#define    FL_DMA_CHANNEL_BSTIM0_TRIG                             (0x62U)
#define    FL_DMA_CHANNEL_LPTIM0_TRIG                             (0x63U)
#define    FL_DMA_CHANNEL_ADC_ACQCOMB                             (0x66U)
#define    FL_DMA_CHANNEL_ADC_ACQ0                                (0x67U)
#define    FL_DMA_CHANNEL_ADC_ACQ1                                (0x68U)
#define    FL_DMA_CHANNEL_ADC_ACQ2                                (0x69U)
#define    FL_DMA_CHANNEL_ADC_ACQ3                                (0x6aU)
#define    FL_DMA_CHANNEL_ADC_ACQ4                                (0x6bU)
#define    FL_DMA_CHANNEL_ADC_ACQ5                                (0x6cU)
#define    FL_DMA_CHANNEL_ADC_ACQ6                                (0x6dU)
#define    FL_DMA_CHANNEL_ADC_ACQ7                                (0x6eU)
#define    FL_DMA_CHANNEL_ADC_ACQ8                                (0x6fU)
#define    FL_DMA_CHANNEL_ADC_ACQ9                                (0x70U)
#define    FL_DMA_CHANNEL_ADC_ACQ10                               (0x71U)
#define    FL_DMA_CHANNEL_ADC_ACQ11                               (0x72U)
#define    FL_DMA_CHANNEL_ADC_ACQ12                               (0x73U)
#define    FL_DMA_CHANNEL_ADC_ACQ13                               (0x74U)
#define    FL_DMA_CHANNEL_ADC_ACQ14                               (0x75U)
#define    FL_DMA_CHANNEL_ADC_ACQ15                               (0x76U)
#define    FL_DMA_CHANNEL_DAC0                                    (0x77U)
#define    FL_DMA_CHANNEL_DAC1                                    (0x78U)
#define    FL_DMA_CHANNEL_SWTRIG                                  (0x7fU)
#define    FL_DMA_CHANNEL_MAX                                     (0x80U)

#define    FL_DMA_PRIORITY_LOW                                    (0x0U)
#define    FL_DMA_PRIORITY_MEDIUM                                 (0x1U)
#define    FL_DMA_PRIORITY_HIGH                                   (0x2U)
#define    FL_DMA_PRIORITY_VERYHIGH                               (0x3U)

#define    FL_DMA_BANDWIDTH_8B                                    (0x0U << DMA_CFGR_BDW_Pos)
#define    FL_DMA_BANDWIDTH_16B                                   (0x1U << DMA_CFGR_BDW_Pos)
#define    FL_DMA_BANDWIDTH_32B                                   (0x2U << DMA_CFGR_BDW_Pos)

#define    FL_DMA_DIR_PERIPHERAL_TO_RAM                           (0x0U << DMA_CFGR_DIR_Pos)
#define    FL_DMA_DIR_RAM_TO_PERIPHERAL                           (0x1U << DMA_CFGR_DIR_Pos)
#define    FL_DMA_DIR_FLASH_TO_RAM                                (0x1U << DMA_CH7CR_DIR_Pos)
#define    FL_DMA_DIR_RAM_TO_FLASH                                (0x0U << DMA_CH7CR_DIR_Pos)

#define    FL_DMA_CH7_RAM_INC_MODE_INCREASE                        (0x1U << DMA_CH7CR_RINC_Pos)
#define    FL_DMA_CH7_RAM_INC_MODE_DECREASE                        (0x0U << DMA_CH7CR_RINC_Pos)

#define    FL_DMA_CH7_FLASH_INC_MODE_INCREASE                      (0x1U << DMA_CH7CR_FINC_Pos)
#define    FL_DMA_CH7_FLASH_INC_MODE_DECREASE                      (0x0U << DMA_CH7CR_FINC_Pos)

#define    FL_DMA_TRIGGER_CHANNEL_0                               (0x1U )
#define    FL_DMA_TRIGGER_CHANNEL_1                               (0x2U )
#define    FL_DMA_TRIGGER_CHANNEL_2                               (0x4U )
#define    FL_DMA_TRIGGER_CHANNEL_3                               (0x8U )
#define    FL_DMA_TRIGGER_CHANNEL_4                               (0x10U )
#define    FL_DMA_TRIGGER_CHANNEL_5                               (0x20U )
#define    FL_DMA_TRIGGER_CHANNEL_6                               (0x40U )

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup DMA_FL_Exported_Functions DMA Exported Functions
  * @{
  */

/**
  * @brief    Set channelx RAM address incremental
  * @rmtoll   CHCR    MINC    FL_DMA_SetRamIncrementMode

  * @param    DMAx DMA instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_NOCHANGE
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_INCREASE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetMemoryIncrementMode(DMA_Type *DMAx, uint32_t mode, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, (0x3U << 6U), mode);
    }
}

/**
  * @brief    Get channelx RAM address incremental status
  * @rmtoll   CHCR    MINC    FL_DMA_GetRamIncrementMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_NOCHANGE
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_MEMORY_INC_MODE_INCREASE
  */
__STATIC_INLINE uint32_t FL_DMA_GetRamIncrementMode(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, (0x3U << 6U)) >> 6U);
    }
    return 0;
}

/**
  * @brief    Set channelx Peripheral address incremental
  * @rmtoll   CHCR    PINC    FL_DMA_SetPeripheralIncrementMode

  * @param    DMAx DMA instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE
  *           @arg @ref FL_DMA_PERIPHERAL_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_PERIPHERAL_INC_MODE_DECREASE
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetPeripheralIncrementMode(DMA_Type *DMAx, uint32_t mode, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHCR, (0x3U << 4U), mode);
    }
}

/**
  * @brief    Get channelx Peripheral address incremental status
  * @rmtoll   CHCR    PINC    FL_DMA_GetPeripheralIncrementMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE
  *           @arg @ref FL_DMA_PERIPHERAL_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_PERIPHERAL_INC_MODE_DECREASE
  */
__STATIC_INLINE uint32_t FL_DMA_GetPeripheralIncrementMode(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, (0x3U << 4U)) >> 4U);
    }
    return 0;
}

/**
  * @brief    DMA Double Buffering enable
  * @rmtoll   CHCR    DBUF    FL_DMA_EnableDoubleBuffering
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableDoubleBuffering(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_DBUF_Msk);
    }
}

/**
  * @brief    Get DMA Double Buffering enable status
  * @rmtoll   CHCR    DBUF    FL_DMA_IsEnabledDoubleBuffering
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledDoubleBuffering(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_DBUF_Msk) == DMA_CHCR_DBUF_Msk);
    }
    return 0;
}

/**
  * @brief    DMA Double Buffering disable
  * @rmtoll   CHCR    DBUF    FL_DMA_DisableDoubleBuffering
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableDoubleBuffering(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_DBUF_Msk);
    }
}

/**
  * @brief    Channelx enable
  * @rmtoll   CHCR    EN    FL_DMA_EnableChannel
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableChannel(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_EN_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk);
    }
}

/**
  * @brief    Get channelx enable status
  * @rmtoll   CHCR    EN    FL_DMA_IsEnabledChannel
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledChannel(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_EN_Msk) == DMA_CHCR_EN_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk) == DMA_CHCR_EN_Msk);
    }
}

/**
  * @brief    Channelx disable
  * @rmtoll   CHCR    EN    FL_DMA_DisableChannel
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableChannel(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CHCR, DMA_CHCR_EN_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CHCR_EN_Msk);
    }
}

/**
  * @brief    Set channelx transmission length
  * @rmtoll   CFGR    TSIZE    FL_DMA_WriteTransmissionSize
  * @param    DMAx DMA instance
  * @param    size
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WriteTransmissionSize(DMA_Type *DMAx, uint32_t size, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CFGR, (0xffffU << 16U), (size << 16U));
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, (0x1fffU << 16U), (size << 16U));
    }
}

/**
  * @brief    Get channelx transmission length
  * @rmtoll   CFGR    TSIZE    FL_DMA_ReadTransmissionSize
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval
  */
__STATIC_INLINE uint32_t FL_DMA_ReadTransmissionSize(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, (0xffffU << 16U)) >> 16U);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, (0x1fffU << 16U)) >> 16U);
    }
}

/**
  * @brief    Channelx Suspend enable
  * @rmtoll   CFGR    SUSP    FL_DMA_EnableChannelSuspend
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableChannelSuspend(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_SUSP_Msk);
    }
}

/**
  * @brief    Get channelx Suspend enable status
  * @rmtoll   CFGR    SUSP    FL_DMA_IsEnabledChannelSuspend
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledChannelSuspend(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_SUSP_Msk) == DMA_CFGR_SUSP_Msk);
    }
    return 0;
}

/**
  * @brief    Channelx Suspend disable
  * @rmtoll   CFGR    SUSP    FL_DMA_DisableChannelSuspend
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableChannelSuspend(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_SUSP_Msk);
    }
}

/**
  * @brief    Channelx request source select
  * @rmtoll   CFGR    RSEL    FL_DMA_SetPeripheralMap
  * @param    DMAx DMA instance
  * @param    peripheral This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_SPI0_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI1_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI2_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI3_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI0_TX
  *           @arg @ref FL_DMA_CHANNEL_SPI1_TX
  *           @arg @ref FL_DMA_CHANNEL_SPI2_TX
  *           @arg @ref FL_DMA_CHANNEL_SPI3_TX
  *           @arg @ref FL_DMA_CHANNEL_UART0_RX
  *           @arg @ref FL_DMA_CHANNEL_UART1_RX
  *           @arg @ref FL_DMA_CHANNEL_UART2_RX
  *           @arg @ref FL_DMA_CHANNEL_UART3_RX
  *           @arg @ref FL_DMA_CHANNEL_UART4_RX
  *           @arg @ref FL_DMA_CHANNEL_UART5_RX
  *           @arg @ref FL_DMA_CHANNEL_UART6_RX
  *           @arg @ref FL_DMA_CHANNEL_UART7_RX
  *           @arg @ref FL_DMA_CHANNEL_UART0_TX
  *           @arg @ref FL_DMA_CHANNEL_UART1_TX
  *           @arg @ref FL_DMA_CHANNEL_UART2_TX
  *           @arg @ref FL_DMA_CHANNEL_UART3_TX
  *           @arg @ref FL_DMA_CHANNEL_UART4_TX
  *           @arg @ref FL_DMA_CHANNEL_UART5_TX
  *           @arg @ref FL_DMA_CHANNEL_UART6_TX
  *           @arg @ref FL_DMA_CHANNEL_UART7_TX
  *           @arg @ref FL_DMA_CHANNEL_LPUART0_RX
  *           @arg @ref FL_DMA_CHANNEL_LPUART1_RX
  *           @arg @ref FL_DMA_CHANNEL_LPUART0_TX
  *           @arg @ref FL_DMA_CHANNEL_LPUART1_TX
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB0_R
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB1_R
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB2_R
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB0_T
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB1_T
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB2_T
  *           @arg @ref FL_DMA_CHANNEL_AES_IN
  *           @arg @ref FL_DMA_CHANNEL_AES_OUT
  *           @arg @ref FL_DMA_CHANNEL_CRC
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH1
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH2
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH3
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH4
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_TRIG
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_COM
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_UEV
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH1
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH2
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH3
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH4
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_TRIG
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_COM
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_UEV
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH1
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH2
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH3
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH4
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_TRI
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_UEV
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH1
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH2
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH3
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH4
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_TRI
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_UEV
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH1
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH2
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH3
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH4
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_TRI
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_UEV
  *           @arg @ref FL_DMA_CHANNEL_BSTIM0_TRI
  *           @arg @ref FL_DMA_CHANNEL_LPTIM0_TRI
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ0
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ1
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ2
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ3
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ4
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ5
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ6
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ7
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ8
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ9
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ10
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ11
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ12
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ13
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ14
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ15
  *           @arg @ref FL_DMA_CHANNEL_DAC0
  *           @arg @ref FL_DMA_CHANNEL_DAC1
  *           @arg @ref FL_DMA_CHANNEL_SWTRIG
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetPeripheralMap(DMA_Type *DMAx, uint32_t peripheral, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CFGR, DMA_CFGR_RSEL_Msk, peripheral << 8);
    }
}

/**
  * @brief    Get Channelx request source select status
  * @rmtoll   CFGR    RSEL    FL_DMA_GetPeripheralMap
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_SPI0_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI1_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI2_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI3_RX
  *           @arg @ref FL_DMA_CHANNEL_SPI0_TX
  *           @arg @ref FL_DMA_CHANNEL_SPI1_TX
  *           @arg @ref FL_DMA_CHANNEL_SPI2_TX
  *           @arg @ref FL_DMA_CHANNEL_SPI3_TX
  *           @arg @ref FL_DMA_CHANNEL_UART0_RX
  *           @arg @ref FL_DMA_CHANNEL_UART1_RX
  *           @arg @ref FL_DMA_CHANNEL_UART2_RX
  *           @arg @ref FL_DMA_CHANNEL_UART3_RX
  *           @arg @ref FL_DMA_CHANNEL_UART4_RX
  *           @arg @ref FL_DMA_CHANNEL_UART5_RX
  *           @arg @ref FL_DMA_CHANNEL_UART6_RX
  *           @arg @ref FL_DMA_CHANNEL_UART7_RX
  *           @arg @ref FL_DMA_CHANNEL_UART0_TX
  *           @arg @ref FL_DMA_CHANNEL_UART1_TX
  *           @arg @ref FL_DMA_CHANNEL_UART2_TX
  *           @arg @ref FL_DMA_CHANNEL_UART3_TX
  *           @arg @ref FL_DMA_CHANNEL_UART4_TX
  *           @arg @ref FL_DMA_CHANNEL_UART5_TX
  *           @arg @ref FL_DMA_CHANNEL_UART6_TX
  *           @arg @ref FL_DMA_CHANNEL_UART7_TX
  *           @arg @ref FL_DMA_CHANNEL_LPUART0_RX
  *           @arg @ref FL_DMA_CHANNEL_LPUART1_RX
  *           @arg @ref FL_DMA_CHANNEL_LPUART0_TX
  *           @arg @ref FL_DMA_CHANNEL_LPUART1_TX
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB0_R
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB1_R
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB2_R
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB0_T
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB1_T
  *           @arg @ref FL_DMA_CHANNEL_I2C_SMB2_T
  *           @arg @ref FL_DMA_CHANNEL_AES_IN
  *           @arg @ref FL_DMA_CHANNEL_AES_OUT
  *           @arg @ref FL_DMA_CHANNEL_CRC
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH1
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH2
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH3
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_CH4
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_TRIG
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_COM
  *           @arg @ref FL_DMA_CHANNEL_ATIM0_UEV
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH1
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH2
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH3
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_CH4
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_TRIG
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_COM
  *           @arg @ref FL_DMA_CHANNEL_ATIM1_UEV
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH1
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH2
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH3
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_CH4
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_TRI
  *           @arg @ref FL_DMA_CHANNEL_GPTIM0_UEV
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH1
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH2
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH3
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_CH4
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_TRI
  *           @arg @ref FL_DMA_CHANNEL_GPTIM1_UEV
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH1
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH2
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH3
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_CH4
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_TRI
  *           @arg @ref FL_DMA_CHANNEL_GPTIM2_UEV
  *           @arg @ref FL_DMA_CHANNEL_BSTIM0_TRI
  *           @arg @ref FL_DMA_CHANNEL_LPTIM0_TRI
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ0
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ1
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ2
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ3
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ4
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ5
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ6
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ7
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ8
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ9
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ10
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ11
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ12
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ13
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ14
  *           @arg @ref FL_DMA_CHANNEL_ADC_ACQ15
  *           @arg @ref FL_DMA_CHANNEL_DAC0
  *           @arg @ref FL_DMA_CHANNEL_DAC1
  *           @arg @ref FL_DMA_CHANNEL_SWTRIG
  */
__STATIC_INLINE uint32_t FL_DMA_GetPeripheralMap(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, (0x7fU << 8U)) >> 8U);
    }
    return 0;
}

/**
  * @brief    Set channelx priority
  * @rmtoll   CFGR    PRI    FL_DMA_SetPriority
  * @param    DMAx DMA instance
  * @param    priority This parameter can be one of the following values:
  *           @arg @ref FL_DMA_PRIORITY_LOW
  *           @arg @ref FL_DMA_PRIORITY_MEDIUM
  *           @arg @ref FL_DMA_PRIORITY_HIGH
  *           @arg @ref FL_DMA_PRIORITY_VERYHIGH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetPriority(DMA_Type *DMAx, uint32_t priority, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CFGR, DMA_CFGR_PRI_Msk, priority << 6);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CH7CR_PRI_Msk, priority << 12);
    }
}

/**
  * @brief    Get channelx priority
  * @rmtoll   CFGR    PRI    FL_DMA_GetPriority
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_PRIORITY_LOW
  *           @arg @ref FL_DMA_PRIORITY_MEDIUM
  *           @arg @ref FL_DMA_PRIORITY_HIGH
  *           @arg @ref FL_DMA_PRIORITY_VERYHIGH
  */
__STATIC_INLINE uint32_t FL_DMA_GetPriority(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_PRI_Msk) >> DMA_CFGR_PRI_Pos);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_PRI_Msk) >> DMA_CH7CR_PRI_Pos);
    }
}

/**
  * @brief    Set transmit bandwidth
  * @rmtoll   CFGR    BDW    FL_DMA_SetBandwidth
  * @param    DMAx DMA instance
  * @param    bandwidth This parameter can be one of the following values:
  *           @arg @ref FL_DMA_BANDWIDTH_8B
  *           @arg @ref FL_DMA_BANDWIDTH_16B
  *           @arg @ref FL_DMA_BANDWIDTH_32B
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetBandwidth(DMA_Type *DMAx, uint32_t bandwidth, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CFGR, DMA_CFGR_BDW_Msk, bandwidth);
    }
}

/**
  * @brief    Get transmit bandwidth
  * @rmtoll   CFGR    BDW    FL_DMA_GetBandwidth
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_BANDWIDTH_8B
  *           @arg @ref FL_DMA_BANDWIDTH_16B
  *           @arg @ref FL_DMA_BANDWIDTH_32B
  */
__STATIC_INLINE uint32_t FL_DMA_GetBandwidth(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_BDW_Msk));
    }
    else
    {
        /* FLASH 通道 默认位宽32Bit */
        return FL_DMA_BANDWIDTH_32B;
    }
}

/**
  * @brief    Circular mode enable
  * @rmtoll   CFGR    CIRC    FL_DMA_EnableCircularMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableCircularMode(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_CIRC_Msk);
    }
}

/**
  * @brief    Get circular mode enable status
  * @rmtoll   CFGR    CIRC    FL_DMA_IsEnabledCircularMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledCircularMode(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_CIRC_Msk) == DMA_CFGR_CIRC_Msk);
    }
    return 0;
}

/**
  * @brief    Circular mode disable
  * @rmtoll   CFGR    CIRC    FL_DMA_DisableCircularMode
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableCircularMode(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_CIRC_Msk);
    }
}

/**
  * @brief    channelx transmit finished interrupt enable
  * @rmtoll   CFGR    FTIE    FL_DMA_EnableIT_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableIT_TransferComplete(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_FTIE_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CFGR_FTIE_Msk);
    }
}

/**
  * @brief    Get channelx transmit finished interrupt enable status
  * @rmtoll   CFGR    FTIE    FL_DMA_IsEnabledIT_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledIT_TransferComplete(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_FTIE_Msk) == DMA_CFGR_FTIE_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CFGR_FTIE_Msk) == DMA_CFGR_FTIE_Msk);
    }
}

/**
  * @brief    channelx transmit finished interrupt disable
  * @rmtoll   CFGR    FTIE    FL_DMA_DisableIT_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableIT_TransferComplete(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_FTIE_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CFGR_FTIE_Msk);
    }
}

/**
  * @brief    Channelx Half-transfer interrupt enable
  * @rmtoll   CFGR    HTIE    FL_DMA_EnableIT_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableIT_TransferHalfComplete(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        SET_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_HTIE_Msk);
    }
    else
    {
        SET_BIT(Temp->CH7CR, DMA_CFGR_HTIE_Msk);
    }
}

/**
  * @brief    Get Channelx Half-transfer interrupt enable status
  * @rmtoll   CFGR    HTIE    FL_DMA_IsEnabledIT_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledIT_TransferHalfComplete(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_HTIE_Msk) == DMA_CFGR_HTIE_Msk);
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CFGR_HTIE_Msk) == DMA_CFGR_HTIE_Msk);
    }
}

/**
  * @brief    Channelx Half-transfer interrupt disable
  * @rmtoll   CFGR    HTIE    FL_DMA_DisableIT_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableIT_TransferHalfComplete(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        CLEAR_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_HTIE_Msk);
    }
    else
    {
        CLEAR_BIT(Temp->CH7CR, DMA_CFGR_HTIE_Msk);
    }
}

/**
  * @brief    Set channelx transmit direction
  * @rmtoll   CFGR    DIR    FL_DMA_SetTransmissionDirection
  * @param    DMAx DMA instance
  * @param    direction This parameter can be one of the following values:
  *           @arg @ref FL_DMA_DIR_PERIPHERAL_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_PERIPHERAL
  *           @arg @ref FL_DMA_DIR_FLASH_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_FLASH
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetTransmissionDirection(DMA_Type *DMAx, uint32_t direction, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CFGR, DMA_CFGR_DIR_Msk, direction);
    }
    else
    {
        MODIFY_REG(Temp->CH7CR, DMA_CH7CR_DIR_Msk, direction);
    }
}

/**
  * @brief    Get channelx transmit direction
  * @rmtoll   CFGR    DIR    FL_DMA_GetTransmissionDirection
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_DIR_PERIPHERAL_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_PERIPHERAL
  *           @arg @ref FL_DMA_DIR_FLASH_TO_RAM
  *           @arg @ref FL_DMA_DIR_RAM_TO_FLASH
  */
__STATIC_INLINE uint32_t FL_DMA_GetTransmissionDirection(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CFGR, DMA_CFGR_DIR_Msk));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7CR, DMA_CH7CR_DIR_Msk));
    }
}

/**
  * @brief    Set channelx Peripheral pointer address
  * @rmtoll   PAR        FL_DMA_WritePeripheralAddress
  * @param    DMAx DMA instance
  * @param    data
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WritePeripheralAddress(DMA_Type *DMAx, uint32_t data, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].PAR, (0xffffffffU), (data));
    }
    else
    {
        MODIFY_REG(Temp->CH7FLSAD, (0xffffU), (data));
    }
}

/**
  * @brief    Get channelx Peripheral pointer address
  * @rmtoll   PAR        FL_DMA_ReadPeripheralAddress
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval
  */
__STATIC_INLINE uint32_t FL_DMA_ReadPeripheralAddress(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].PAR, (0xffffffffU)));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7FLSAD, (0xffffU)));
    }
}

/**
  * @brief    Set channelx memory0 pointer address
  * @rmtoll   MEMAD0        FL_DMA_WriteMemoryAddress0
  * @param    DMAx DMA instance
  * @param    data
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WriteMemoryAddress0(DMA_Type *DMAx, uint32_t data, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHMAD0, (0xffffffffU), (data));
    }
    else
    {
        MODIFY_REG(Temp->CH7MAD, (0x3fffU), (data));
    }
}

/**
  * @brief    Get channelx memory0 pointer address
  * @rmtoll   MEMAD0        FL_DMA_ReadMemoryAddress
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval
  */
__STATIC_INLINE uint32_t FL_DMA_ReadMemoryAddress(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHMAD0, (0xffffffffU)));
    }
    else
    {
        return (uint32_t)(READ_BIT(Temp->CH7MAD, (0x3fffU)));
    }
}

/**
  * @brief    Set channelx memory1 pointer address
  * @rmtoll   MEMAD1        FL_DMA_WriteMemoryAddress1
  * @param    DMAx DMA instance
  * @param    data
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_WriteMemoryAddress1(DMA_Type *DMAx, uint32_t data, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->Channel[channel].CHMAD1, (0xffffffffU), (data));
    }
}

/**
  * @brief    Get channelx memory1 pointer address
  * @rmtoll   MEMAD1        FL_DMA_ReadMemoryAddress1
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval
  */
__STATIC_INLINE uint32_t FL_DMA_ReadMemoryAddress1(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->Channel[channel].CHMAD1, (0xffffffffU)));
    }
    return 0;
}

/**
  * @brief    Set Flash channel RAM address incremental
  * @rmtoll   CH7CR    RINC    FL_DMA_SetFlashMemoryIncrementMode

  * @param    DMAx DMA instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CH7_RAM_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_CH7_RAM_INC_MODE_DECREASE
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetFlashMemoryIncrementMode(DMA_Type *DMAx, uint32_t mode)
{
    MODIFY_REG(DMAx->CH7CR, DMA_CH7CR_RINC_Msk, mode);
}

/**
  * @brief    Get  Flash channel RAM address incremental status
  * @rmtoll   CH7CR    RINC    FL_DMA_GetFlashRamIncrementMode
  * @param    DMAx DMA instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_CH7_RAM_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_CH7_RAM_INC_MODE_DECREASE
  */
__STATIC_INLINE uint32_t FL_DMA_GetFlashRamIncrementMode(DMA_Type *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->CH7CR, DMA_CH7CR_RINC_Msk) == DMA_CH7CR_RINC_Msk);
}

/**
  * @brief    Get  Flash channel RAM address incremental status
  * @rmtoll   CH7CR    FINC    FL_DMA_GetFlashAddrIncremental
  * @param    DMAx DMA instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_CH7_RAM_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_CH7_RAM_INC_MODE_DECREASE
  */
__STATIC_INLINE uint32_t FL_DMA_GetFlashAddrIncremental(DMA_Type *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->CH7CR, DMA_CH7CR_FINC_Msk) == DMA_CH7CR_FINC_Msk);
}

/**
  * @brief    Set Flash channel RAM address incremental
  * @rmtoll   CH7CR    FINC    FL_DMA_SetFlashAddrIncremental

  * @param    DMAx DMA instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CH7_FLASH_INC_MODE_INCREASE
  *           @arg @ref FL_DMA_CH7_FLASH_INC_MODE_DECREASE
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetFlashAddrIncremental(DMA_Type *DMAx, uint32_t mode)
{
    MODIFY_REG(DMAx->CH7CR, DMA_CH7CR_FINC_Msk, mode);
}

/**
  * @brief    DMA address error interrupt enable
  * @rmtoll   GCR    ADDRERR_IE    FL_DMA_EnableIT_AddressError
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_EnableIT_AddressError(DMA_Type *DMAx)
{
    SET_BIT(DMAx->GCR, DMA_GCR_ADDRERR_IE_Msk);
}

/**
  * @brief    Get DMA address error interrupt enable status
  * @rmtoll   GCR    ADDRERR_IE    FL_DMA_IsEnabledIT_AddressError
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabledIT_AddressError(DMA_Type *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->GCR, DMA_GCR_ADDRERR_IE_Msk) == DMA_GCR_ADDRERR_IE_Msk);
}

/**
  * @brief    DMA address error interrupt disable
  * @rmtoll   GCR    ADDRERR_IE    FL_DMA_DisableIT_AddressError
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_DisableIT_AddressError(DMA_Type *DMAx)
{
    CLEAR_BIT(DMAx->GCR, DMA_GCR_ADDRERR_IE_Msk);
}

/**
  * @brief    DMA enable
  * @rmtoll   GCR    EN    FL_DMA_Enable
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_Enable(DMA_Type *DMAx)
{
    SET_BIT(DMAx->GCR, DMA_GCR_EN_Msk);
}

/**
  * @brief    Get DMA enable status
  * @rmtoll   GCR    EN    FL_DMA_IsEnabled
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsEnabled(DMA_Type *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->GCR, DMA_GCR_EN_Msk) == DMA_GCR_EN_Msk);
}

/**
  * @brief    DMA disable
  * @rmtoll   GCR    EN    FL_DMA_Disable
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_Disable(DMA_Type *DMAx)
{
    CLEAR_BIT(DMAx->GCR, DMA_GCR_EN_Msk);
}

/**
  * @brief    Set channelx soft trigger
  * @rmtoll   SWRR      SWTRING     FL_DMA_SetChannelxSoftTrigger
  * @param    DMAx DMA instance
  * @param    data This parameter can be one of the following values:
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_0
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_1
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_2
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_3
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_4
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_5
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_6
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6

  * @retval   None
  */
__STATIC_INLINE void FL_DMA_SetChannelxSoftTrigger(DMA_Type *DMAx, uint32_t data, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        MODIFY_REG(Temp->SWRR, (0x3fU), (data));
    }
}

/**
  * @brief    Get channelx soft trigger status
  * @rmtoll   SWRR      SWTRING     FL_DMA_GetChannelxSoftTrigger
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_0
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_1
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_2
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_3
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_4
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_5
  *           @arg @ref FL_DMA_TRIGGER_CHANNEL_6
  */
__STATIC_INLINE uint32_t FL_DMA_GetChannelxSoftTrigger(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->SWRR, (0x3fU)));
    }
    return 0;

}

/**
  * @brief    Get DMA address error flag
  * @rmtoll   ISR    ADDRERR    FL_DMA_IsActiveFlag_AddressError
  * @param    DMAx DMA instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsActiveFlag_AddressError(DMA_Type *DMAx)
{
    return (uint32_t)(READ_BIT(DMAx->ISR, DMA_ISR_ADDRERR_Msk) == (DMA_ISR_ADDRERR_Msk));
}

/**
  * @brief    Clear DMA address error flag
  * @rmtoll   ISR    ADDRERR    FL_DMA_ClearFlag_AddressError
  * @param    DMAx DMA instance
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_ClearFlag_AddressError(DMA_Type *DMAx)
{
    WRITE_REG(DMAx->ISR, DMA_ISR_ADDRERR_Msk);
}

/**
  * @brief    Get DMA channelx finished-transfer flag
  * @rmtoll   ISR    CHFT    FL_DMA_IsActiveFlag_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsActiveFlag_TransferComplete(DMA_Type *DMAx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(DMAx->ISR, ((0x1U << channel) << DMA_ISR_CHFT_Pos)) == ((0x1U << channel) << DMA_ISR_CHFT_Pos));
}

/**
  * @brief    Clear DMA channelx finished-transfer flag
  * @rmtoll   ISR    CHFT    FL_DMA_ClearFlag_TransferComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_ClearFlag_TransferComplete(DMA_Type *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->ISR, (DMA_ISR_CHFT_Msk << channel));
}

/**
  * @brief    Get DMA channel half-transfer flag
  * @rmtoll   ISR    CHHT    FL_DMA_IsActiveFlag_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_DMA_IsActiveFlag_TransferHalfComplete(DMA_Type *DMAx, uint32_t channel)
{
    return (uint32_t)(READ_BIT(DMAx->ISR, ((0x1U << channel) << DMA_ISR_CHHT_Pos)) == ((0x1U << channel) << DMA_ISR_CHHT_Pos));
}

/**
  * @brief    Clear DMA channel half-transfer flag
  * @rmtoll   ISR    CHHT    FL_DMA_ClearFlag_TransferHalfComplete
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  *           @arg @ref FL_DMA_CHANNEL_7
  * @retval   None
  */
__STATIC_INLINE void FL_DMA_ClearFlag_TransferHalfComplete(DMA_Type *DMAx, uint32_t channel)
{
    WRITE_REG(DMAx->ISR, (DMA_ISR_CHHT_Msk << channel));
}

/**
  * @brief    Get channelx transfer remainder length
  * @rmtoll   TFSIZE_CNT        FL_DMA_ReadPeripheralTransferRemainderLength
  * @param    DMAx DMA instance
  * @param    channel This parameter can be one of the following values:
  *           @arg @ref FL_DMA_CHANNEL_0
  *           @arg @ref FL_DMA_CHANNEL_1
  *           @arg @ref FL_DMA_CHANNEL_2
  *           @arg @ref FL_DMA_CHANNEL_3
  *           @arg @ref FL_DMA_CHANNEL_4
  *           @arg @ref FL_DMA_CHANNEL_5
  *           @arg @ref FL_DMA_CHANNEL_6
  * @retval
  */
__STATIC_INLINE uint32_t FL_DMA_ReadPeripheralTransferRemainderLength(DMA_Type *DMAx, uint32_t channel)
{
    DMA_ADDR  *Temp = (DMA_ADDR *)DMAx;
    if(channel <= FL_DMA_CHANNEL_6)
    {
        return (uint32_t)(READ_BIT(Temp->TFSADDR[channel], (0xffffU)));
    }
    return 0;
}

/**
  * @}
  */

/** @defgroup DMA_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
FL_ErrorStatus FL_DMA_DeInit(DMA_Type *DMAx);
FL_ErrorStatus FL_DMA_Init(DMA_Type *DMAx, FL_DMA_InitTypeDef *initStruct, uint32_t channel);
void FL_DMA_StructInit(FL_DMA_InitTypeDef *InitStruct);

FL_ErrorStatus FL_DMA_StartTransmission(DMA_Type *DMAx, FL_DMA_ConfigTypeDef *configStruct, uint32_t channel);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_DMA_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-06-08*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
