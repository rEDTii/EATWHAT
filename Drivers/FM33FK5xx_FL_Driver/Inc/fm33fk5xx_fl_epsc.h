/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_epsc.h
  * @author  FMSH Application Team
  * @brief   Head file of EPSC FL Module
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
#ifndef __FM33FK5XX_FL_EPSC_H
#define __FM33FK5XX_FL_EPSC_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes -------------------------------------------------------------------------------------------*/
#include "fm33fk5xx_fl_def.h"
/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */
/* Exported types -------------------------------------------------------------------------------------*/
/** @defgroup EPSC_FL_ES_INIT EPSC Exported Init structures
  * @{
  */
/**
  * @brief  EPSC_NORSRAM Timing parameters structure definition
  */
typedef struct
{
    uint32_t AddressSetupTime;                /** 地址建立时间配置 */

    uint32_t AddressHoldTime;                 /** 地址保持时间配置 */

    uint32_t DataSetupTime;                   /** 数据时间配置 */

    uint32_t BusTurnAroundDuration;           /** 总线转向空闲时间配置 */

    uint32_t CLKDivision;                     /** 时钟分频配置*/

    uint32_t DataLatency;                     /** 数据延时配置*/

    uint32_t AccessMode;                      /** 扩展模式选择 */

} EPSC_NORSRAM_RWTimingTypeDef;

typedef struct
{
    uint32_t AddressSetupTime;                /** 地址建立时间配置 */

    uint32_t AddressHoldTime;                 /** 地址保持时间配置 */

    uint32_t DataSetupTime;                   /** 数据时间配置 */

    uint32_t BusTurnAroundDuration;           /** 总线转向空闲时间配置 */

    uint32_t AccessMode;                      /** 扩展模式选择 */

} EPSC_NORSRAM_WTimingTypeDef;
/**
  * @brief  EPSC_NORSRAM Configuration Structure definition
  */
typedef struct
{

    uint32_t NSBank;                                              /** Bank1选择 */

    FL_FunState DataAddressMux;                       /** 地址数据复用配置 */

    uint32_t MemoryType;                                      /** 存储类型配置 */

    uint32_t MemoryDataWidth;                             /** 存储数据位宽 */

    FL_FunState BurstAccessMode;            /** 突发模式配置 */

    uint32_t WriteBurst;                      /** 突发模式写配置 */

    FL_FunState WaitSignal;                 /** wait信号使能配置 */

    FL_FunState AsynchronousWait;           /** 异步wait模式配置*/

    uint32_t WaitSignalPolarity;              /** wait信号极性配置 */

    uint32_t WaitSignalActive;                /** wait信号时序有效配置 */

    FL_FunState WriteOperation;             /** 写使能配置 */

    FL_FunState ExtendedMode;               /** 扩展模式配置 */

    EPSC_NORSRAM_RWTimingTypeDef *ReadWriteTimingStruct;

    EPSC_NORSRAM_WTimingTypeDef *WriteTimingStruct;

} EPSC_NORSRAM_InitTypeDef;

/**
  * @}
  */
/* Exported constants ---------------------------------------------------------------------------------*/
/** @defgroup EPSC_FL_Exported_Constants EPSC Exported Constants
  * @{
  */

#define    EPSC_NCR1_FIFOEN_Pos                                   (27U)
#define    EPSC_NCR1_FIFOEN_Msk                                   (0x1U << EPSC_NCR1_FIFOEN_Pos)
#define    EPSC_NCR1_FIFOEN                                       EPSC_NCR1_FIFOEN_Msk

#define    EPSC_NCR1_TCEN_Pos                                     (24U)
#define    EPSC_NCR1_TCEN_Msk                                     (0x1U << EPSC_NCR1_TCEN_Pos)
#define    EPSC_NCR1_TCEN                                         EPSC_NCR1_TCEN_Msk

#define    EPSC_NCR1_CCLKEN_Pos                                   (20U)
#define    EPSC_NCR1_CCLKEN_Msk                                   (0x1U << EPSC_NCR1_CCLKEN_Pos)
#define    EPSC_NCR1_CCLKEN                                       EPSC_NCR1_CCLKEN_Msk

#define    EPSC_NCR1_CBURSTWR_Pos                                 (19U)
#define    EPSC_NCR1_CBURSTWR_Msk                                 (0x1U << EPSC_NCR1_CBURSTWR_Pos)
#define    EPSC_NCR1_CBURSTWR                                     EPSC_NCR1_CBURSTWR_Msk

#define    EPSC_NCR1_ASYNCWAIT_Pos                                (15U)
#define    EPSC_NCR1_ASYNCWAIT_Msk                                (0x1U << EPSC_NCR1_ASYNCWAIT_Pos)
#define    EPSC_NCR1_ASYNCWAIT                                    EPSC_NCR1_ASYNCWAIT_Msk

#define    EPSC_NCR1_EXTMOD_Pos                                   (14U)
#define    EPSC_NCR1_EXTMOD_Msk                                   (0x1U << EPSC_NCR1_EXTMOD_Pos)
#define    EPSC_NCR1_EXTMOD                                       EPSC_NCR1_EXTMOD_Msk

#define    EPSC_NCR1_WAITEN_Pos                                   (13U)
#define    EPSC_NCR1_WAITEN_Msk                                   (0x1U << EPSC_NCR1_WAITEN_Pos)
#define    EPSC_NCR1_WAITEN                                       EPSC_NCR1_WAITEN_Msk

#define    EPSC_NCR1_WREN_Pos                                     (12U)
#define    EPSC_NCR1_WREN_Msk                                     (0x1U << EPSC_NCR1_WREN_Pos)
#define    EPSC_NCR1_WREN                                         EPSC_NCR1_WREN_Msk

#define    EPSC_NCR1_WAITCFG_Pos                                  (11U)
#define    EPSC_NCR1_WAITCFG_Msk                                  (0x1U << EPSC_NCR1_WAITCFG_Pos)
#define    EPSC_NCR1_WAITCFG                                      EPSC_NCR1_WAITCFG_Msk

#define    EPSC_NCR1_WAITPOL_Pos                                  (9U)
#define    EPSC_NCR1_WAITPOL_Msk                                  (0x1U << EPSC_NCR1_WAITPOL_Pos)
#define    EPSC_NCR1_WAITPOL                                      EPSC_NCR1_WAITPOL_Msk

#define    EPSC_NCR1_BURSTEN_Pos                                  (8U)
#define    EPSC_NCR1_BURSTEN_Msk                                  (0x1U << EPSC_NCR1_BURSTEN_Pos)
#define    EPSC_NCR1_BURSTEN                                      EPSC_NCR1_BURSTEN_Msk

#define    EPSC_NCR1_MWID_Pos                                     (4U)
#define    EPSC_NCR1_MWID_Msk                                     (0x3U << EPSC_NCR1_MWID_Pos)
#define    EPSC_NCR1_MWID                                         EPSC_NCR1_MWID_Msk

#define    EPSC_NCR1_MTYP_Pos                                     (2U)
#define    EPSC_NCR1_MTYP_Msk                                     (0x3U << EPSC_NCR1_MTYP_Pos)
#define    EPSC_NCR1_MTYP                                         EPSC_NCR1_MTYP_Msk

#define    EPSC_NCR1_MUXEN_Pos                                    (1U)
#define    EPSC_NCR1_MUXEN_Msk                                    (0x1U << EPSC_NCR1_MUXEN_Pos)
#define    EPSC_NCR1_MUXEN                                        EPSC_NCR1_MUXEN_Msk

#define    EPSC_NCR1_MBKEN_Pos                                    (0U)
#define    EPSC_NCR1_MBKEN_Msk                                    (0x1U << EPSC_NCR1_MBKEN_Pos)
#define    EPSC_NCR1_MBKEN                                        EPSC_NCR1_MBKEN_Msk

#define    EPSC_NTR1_ACCMOD_Pos                                   (28U)
#define    EPSC_NTR1_ACCMOD_Msk                                   (0x3U << EPSC_NTR1_ACCMOD_Pos)
#define    EPSC_NTR1_ACCMOD                                       EPSC_NTR1_ACCMOD_Msk

#define    EPSC_NTR1_DATLAT_Pos                                   (24U)
#define    EPSC_NTR1_DATLAT_Msk                                   (0xfU << EPSC_NTR1_DATLAT_Pos)
#define    EPSC_NTR1_DATLAT                                       EPSC_NTR1_DATLAT_Msk

#define    EPSC_NTR1_CLKDIV_Pos                                   (20U)
#define    EPSC_NTR1_CLKDIV_Msk                                   (0xfU << EPSC_NTR1_CLKDIV_Pos)
#define    EPSC_NTR1_CLKDIV                                       EPSC_NTR1_CLKDIV_Msk

#define    EPSC_NTR1_BUSTURN_Pos                                  (16U)
#define    EPSC_NTR1_BUSTURN_Msk                                  (0xfU << EPSC_NTR1_BUSTURN_Pos)
#define    EPSC_NTR1_BUSTURN                                      EPSC_NTR1_BUSTURN_Msk

#define    EPSC_NTR1_DATAST_Pos                                   (8U)
#define    EPSC_NTR1_DATAST_Msk                                   (0xffU << EPSC_NTR1_DATAST_Pos)
#define    EPSC_NTR1_DATAST                                       EPSC_NTR1_DATAST_Msk

#define    EPSC_NTR1_ADDHLD_Pos                                   (4U)
#define    EPSC_NTR1_ADDHLD_Msk                                   (0xfU << EPSC_NTR1_ADDHLD_Pos)
#define    EPSC_NTR1_ADDHLD                                       EPSC_NTR1_ADDHLD_Msk

#define    EPSC_NTR1_ADDSET_Pos                                   (0U)
#define    EPSC_NTR1_ADDSET_Msk                                   (0xfU << EPSC_NTR1_ADDSET_Pos)
#define    EPSC_NTR1_ADDSET                                       EPSC_NTR1_ADDSET_Msk

#define    EPSC_NWTR1_ACCMOD_Pos                                  (28U)
#define    EPSC_NWTR1_ACCMOD_Msk                                  (0x3U << EPSC_NWTR1_ACCMOD_Pos)
#define    EPSC_NWTR1_ACCMOD                                      EPSC_NWTR1_ACCMOD_Msk

#define    EPSC_NWTR1_BUSTURN_Pos                                 (16U)
#define    EPSC_NWTR1_BUSTURN_Msk                                 (0xfU << EPSC_NWTR1_BUSTURN_Pos)
#define    EPSC_NWTR1_BUSTURN                                     EPSC_NWTR1_BUSTURN_Msk

#define    EPSC_NWTR1_DATAST_Pos                                  (8U)
#define    EPSC_NWTR1_DATAST_Msk                                  (0xffU << EPSC_NWTR1_DATAST_Pos)
#define    EPSC_NWTR1_DATAST                                      EPSC_NWTR1_DATAST_Msk

#define    EPSC_NWTR1_ADDHLD_Pos                                  (4U)
#define    EPSC_NWTR1_ADDHLD_Msk                                  (0xfU << EPSC_NWTR1_ADDHLD_Pos)
#define    EPSC_NWTR1_ADDHLD                                      EPSC_NWTR1_ADDHLD_Msk

#define    EPSC_NWTR1_ADDSET_Pos                                  (0U)
#define    EPSC_NWTR1_ADDSET_Msk                                  (0xfU << EPSC_NWTR1_ADDSET_Pos)
#define    EPSC_NWTR1_ADDSET                                      EPSC_NWTR1_ADDSET_Msk

#define    EPSC_NCR2_FIFOEN_Pos                                   (27U)
#define    EPSC_NCR2_FIFOEN_Msk                                   (0x1U << EPSC_NCR2_FIFOEN_Pos)
#define    EPSC_NCR2_FIFOEN                                       EPSC_NCR2_FIFOEN_Msk

#define    EPSC_NCR2_TCEN_Pos                                     (24U)
#define    EPSC_NCR2_TCEN_Msk                                     (0x1U << EPSC_NCR2_TCEN_Pos)
#define    EPSC_NCR2_TCEN                                         EPSC_NCR2_TCEN_Msk

#define    EPSC_NCR2_CCLKEN_Pos                                   (20U)
#define    EPSC_NCR2_CCLKEN_Msk                                   (0x1U << EPSC_NCR2_CCLKEN_Pos)
#define    EPSC_NCR2_CCLKEN                                       EPSC_NCR2_CCLKEN_Msk

#define    EPSC_NCR2_CBURSTWR_Pos                                 (19U)
#define    EPSC_NCR2_CBURSTWR_Msk                                 (0x1U << EPSC_NCR2_CBURSTWR_Pos)
#define    EPSC_NCR2_CBURSTWR                                     EPSC_NCR2_CBURSTWR_Msk

#define    EPSC_NCR2_ASYNCWAIT_Pos                                (15U)
#define    EPSC_NCR2_ASYNCWAIT_Msk                                (0x1U << EPSC_NCR2_ASYNCWAIT_Pos)
#define    EPSC_NCR2_ASYNCWAIT                                    EPSC_NCR2_ASYNCWAIT_Msk

#define    EPSC_NCR2_EXTMOD_Pos                                   (14U)
#define    EPSC_NCR2_EXTMOD_Msk                                   (0x1U << EPSC_NCR2_EXTMOD_Pos)
#define    EPSC_NCR2_EXTMOD                                       EPSC_NCR2_EXTMOD_Msk

#define    EPSC_NCR2_WAITEN_Pos                                   (13U)
#define    EPSC_NCR2_WAITEN_Msk                                   (0x1U << EPSC_NCR2_WAITEN_Pos)
#define    EPSC_NCR2_WAITEN                                       EPSC_NCR2_WAITEN_Msk

#define    EPSC_NCR2_WREN_Pos                                     (12U)
#define    EPSC_NCR2_WREN_Msk                                     (0x1U << EPSC_NCR2_WREN_Pos)
#define    EPSC_NCR2_WREN                                         EPSC_NCR2_WREN_Msk

#define    EPSC_NCR2_WAITCFG_Pos                                  (11U)
#define    EPSC_NCR2_WAITCFG_Msk                                  (0x1U << EPSC_NCR2_WAITCFG_Pos)
#define    EPSC_NCR2_WAITCFG                                      EPSC_NCR2_WAITCFG_Msk

#define    EPSC_NCR2_WAITPOL_Pos                                  (9U)
#define    EPSC_NCR2_WAITPOL_Msk                                  (0x1U << EPSC_NCR2_WAITPOL_Pos)
#define    EPSC_NCR2_WAITPOL                                      EPSC_NCR2_WAITPOL_Msk

#define    EPSC_NCR2_BURSTEN_Pos                                  (8U)
#define    EPSC_NCR2_BURSTEN_Msk                                  (0x1U << EPSC_NCR2_BURSTEN_Pos)
#define    EPSC_NCR2_BURSTEN                                      EPSC_NCR2_BURSTEN_Msk

#define    EPSC_NCR2_MWID_Pos                                     (4U)
#define    EPSC_NCR2_MWID_Msk                                     (0x3U << EPSC_NCR2_MWID_Pos)
#define    EPSC_NCR2_MWID                                         EPSC_NCR2_MWID_Msk

#define    EPSC_NCR2_MTYP_Pos                                     (2U)
#define    EPSC_NCR2_MTYP_Msk                                     (0x3U << EPSC_NCR2_MTYP_Pos)
#define    EPSC_NCR2_MTYP                                         EPSC_NCR2_MTYP_Msk

#define    EPSC_NCR2_MUXEN_Pos                                    (1U)
#define    EPSC_NCR2_MUXEN_Msk                                    (0x1U << EPSC_NCR2_MUXEN_Pos)
#define    EPSC_NCR2_MUXEN                                        EPSC_NCR2_MUXEN_Msk

#define    EPSC_NCR2_MBKEN_Pos                                    (0U)
#define    EPSC_NCR2_MBKEN_Msk                                    (0x1U << EPSC_NCR2_MBKEN_Pos)
#define    EPSC_NCR2_MBKEN                                        EPSC_NCR2_MBKEN_Msk

#define    EPSC_NTR2_ACCMOD_Pos                                   (28U)
#define    EPSC_NTR2_ACCMOD_Msk                                   (0x3U << EPSC_NTR2_ACCMOD_Pos)
#define    EPSC_NTR2_ACCMOD                                       EPSC_NTR2_ACCMOD_Msk

#define    EPSC_NTR2_DATLAT_Pos                                   (24U)
#define    EPSC_NTR2_DATLAT_Msk                                   (0xfU << EPSC_NTR2_DATLAT_Pos)
#define    EPSC_NTR2_DATLAT                                       EPSC_NTR2_DATLAT_Msk

#define    EPSC_NTR2_CLKDIV_Pos                                   (20U)
#define    EPSC_NTR2_CLKDIV_Msk                                   (0xfU << EPSC_NTR2_CLKDIV_Pos)
#define    EPSC_NTR2_CLKDIV                                       EPSC_NTR2_CLKDIV_Msk

#define    EPSC_NTR2_BUSTURN_Pos                                  (16U)
#define    EPSC_NTR2_BUSTURN_Msk                                  (0xfU << EPSC_NTR2_BUSTURN_Pos)
#define    EPSC_NTR2_BUSTURN                                      EPSC_NTR2_BUSTURN_Msk

#define    EPSC_NTR2_DATAST_Pos                                   (8U)
#define    EPSC_NTR2_DATAST_Msk                                   (0xffU << EPSC_NTR2_DATAST_Pos)
#define    EPSC_NTR2_DATAST                                       EPSC_NTR2_DATAST_Msk

#define    EPSC_NTR2_ADDHLD_Pos                                   (4U)
#define    EPSC_NTR2_ADDHLD_Msk                                   (0xfU << EPSC_NTR2_ADDHLD_Pos)
#define    EPSC_NTR2_ADDHLD                                       EPSC_NTR2_ADDHLD_Msk

#define    EPSC_NTR2_ADDSET_Pos                                   (0U)
#define    EPSC_NTR2_ADDSET_Msk                                   (0xfU << EPSC_NTR2_ADDSET_Pos)
#define    EPSC_NTR2_ADDSET                                       EPSC_NTR2_ADDSET_Msk

#define    EPSC_NWTR2_ACCMOD_Pos                                  (28U)
#define    EPSC_NWTR2_ACCMOD_Msk                                  (0x3U << EPSC_NWTR2_ACCMOD_Pos)
#define    EPSC_NWTR2_ACCMOD                                      EPSC_NWTR2_ACCMOD_Msk

#define    EPSC_NWTR2_BUSTURN_Pos                                 (16U)
#define    EPSC_NWTR2_BUSTURN_Msk                                 (0xfU << EPSC_NWTR2_BUSTURN_Pos)
#define    EPSC_NWTR2_BUSTURN                                     EPSC_NWTR2_BUSTURN_Msk

#define    EPSC_NWTR2_DATAST_Pos                                  (8U)
#define    EPSC_NWTR2_DATAST_Msk                                  (0xffU << EPSC_NWTR2_DATAST_Pos)
#define    EPSC_NWTR2_DATAST                                      EPSC_NWTR2_DATAST_Msk

#define    EPSC_NWTR2_ADDHLD_Pos                                  (4U)
#define    EPSC_NWTR2_ADDHLD_Msk                                  (0xfU << EPSC_NWTR2_ADDHLD_Pos)
#define    EPSC_NWTR2_ADDHLD                                      EPSC_NWTR2_ADDHLD_Msk

#define    EPSC_NWTR2_ADDSET_Pos                                  (0U)
#define    EPSC_NWTR2_ADDSET_Msk                                  (0xfU << EPSC_NWTR2_ADDSET_Pos)
#define    EPSC_NWTR2_ADDSET                                      EPSC_NWTR2_ADDSET_Msk

#define    EPSC_NCR3_FIFOEN_Pos                                   (27U)
#define    EPSC_NCR3_FIFOEN_Msk                                   (0x1U << EPSC_NCR3_FIFOEN_Pos)
#define    EPSC_NCR3_FIFOEN                                       EPSC_NCR3_FIFOEN_Msk

#define    EPSC_NCR3_TCEN_Pos                                     (24U)
#define    EPSC_NCR3_TCEN_Msk                                     (0x1U << EPSC_NCR3_TCEN_Pos)
#define    EPSC_NCR3_TCEN                                         EPSC_NCR3_TCEN_Msk

#define    EPSC_NCR3_CCLKEN_Pos                                   (20U)
#define    EPSC_NCR3_CCLKEN_Msk                                   (0x1U << EPSC_NCR3_CCLKEN_Pos)
#define    EPSC_NCR3_CCLKEN                                       EPSC_NCR3_CCLKEN_Msk

#define    EPSC_NCR3_CBURSTWR_Pos                                 (19U)
#define    EPSC_NCR3_CBURSTWR_Msk                                 (0x1U << EPSC_NCR3_CBURSTWR_Pos)
#define    EPSC_NCR3_CBURSTWR                                     EPSC_NCR3_CBURSTWR_Msk

#define    EPSC_NCR3_ASYNCWAIT_Pos                                (15U)
#define    EPSC_NCR3_ASYNCWAIT_Msk                                (0x1U << EPSC_NCR3_ASYNCWAIT_Pos)
#define    EPSC_NCR3_ASYNCWAIT                                    EPSC_NCR3_ASYNCWAIT_Msk

#define    EPSC_NCR3_EXTMOD_Pos                                   (14U)
#define    EPSC_NCR3_EXTMOD_Msk                                   (0x1U << EPSC_NCR3_EXTMOD_Pos)
#define    EPSC_NCR3_EXTMOD                                       EPSC_NCR3_EXTMOD_Msk

#define    EPSC_NCR3_WAITEN_Pos                                   (13U)
#define    EPSC_NCR3_WAITEN_Msk                                   (0x1U << EPSC_NCR3_WAITEN_Pos)
#define    EPSC_NCR3_WAITEN                                       EPSC_NCR3_WAITEN_Msk

#define    EPSC_NCR3_WREN_Pos                                     (12U)
#define    EPSC_NCR3_WREN_Msk                                     (0x1U << EPSC_NCR3_WREN_Pos)
#define    EPSC_NCR3_WREN                                         EPSC_NCR3_WREN_Msk

#define    EPSC_NCR3_WAITCFG_Pos                                  (11U)
#define    EPSC_NCR3_WAITCFG_Msk                                  (0x1U << EPSC_NCR3_WAITCFG_Pos)
#define    EPSC_NCR3_WAITCFG                                      EPSC_NCR3_WAITCFG_Msk

#define    EPSC_NCR3_WAITPOL_Pos                                  (9U)
#define    EPSC_NCR3_WAITPOL_Msk                                  (0x1U << EPSC_NCR3_WAITPOL_Pos)
#define    EPSC_NCR3_WAITPOL                                      EPSC_NCR3_WAITPOL_Msk

#define    EPSC_NCR3_BURSTEN_Pos                                  (8U)
#define    EPSC_NCR3_BURSTEN_Msk                                  (0x1U << EPSC_NCR3_BURSTEN_Pos)
#define    EPSC_NCR3_BURSTEN                                      EPSC_NCR3_BURSTEN_Msk

#define    EPSC_NCR3_MWID_Pos                                     (4U)
#define    EPSC_NCR3_MWID_Msk                                     (0x3U << EPSC_NCR3_MWID_Pos)
#define    EPSC_NCR3_MWID                                         EPSC_NCR3_MWID_Msk

#define    EPSC_NCR3_MTYP_Pos                                     (2U)
#define    EPSC_NCR3_MTYP_Msk                                     (0x3U << EPSC_NCR3_MTYP_Pos)
#define    EPSC_NCR3_MTYP                                         EPSC_NCR3_MTYP_Msk

#define    EPSC_NCR3_MUXEN_Pos                                    (1U)
#define    EPSC_NCR3_MUXEN_Msk                                    (0x1U << EPSC_NCR3_MUXEN_Pos)
#define    EPSC_NCR3_MUXEN                                        EPSC_NCR3_MUXEN_Msk

#define    EPSC_NCR3_MBKEN_Pos                                    (0U)
#define    EPSC_NCR3_MBKEN_Msk                                    (0x1U << EPSC_NCR3_MBKEN_Pos)
#define    EPSC_NCR3_MBKEN                                        EPSC_NCR3_MBKEN_Msk

#define    EPSC_NTR3_ACCMOD_Pos                                   (28U)
#define    EPSC_NTR3_ACCMOD_Msk                                   (0x3U << EPSC_NTR3_ACCMOD_Pos)
#define    EPSC_NTR3_ACCMOD                                       EPSC_NTR3_ACCMOD_Msk

#define    EPSC_NTR3_DATLAT_Pos                                   (24U)
#define    EPSC_NTR3_DATLAT_Msk                                   (0xfU << EPSC_NTR3_DATLAT_Pos)
#define    EPSC_NTR3_DATLAT                                       EPSC_NTR3_DATLAT_Msk

#define    EPSC_NTR3_CLKDIV_Pos                                   (20U)
#define    EPSC_NTR3_CLKDIV_Msk                                   (0xfU << EPSC_NTR3_CLKDIV_Pos)
#define    EPSC_NTR3_CLKDIV                                       EPSC_NTR3_CLKDIV_Msk

#define    EPSC_NTR3_BUSTURN_Pos                                  (16U)
#define    EPSC_NTR3_BUSTURN_Msk                                  (0xfU << EPSC_NTR3_BUSTURN_Pos)
#define    EPSC_NTR3_BUSTURN                                      EPSC_NTR3_BUSTURN_Msk

#define    EPSC_NTR3_DATAST_Pos                                   (8U)
#define    EPSC_NTR3_DATAST_Msk                                   (0xffU << EPSC_NTR3_DATAST_Pos)
#define    EPSC_NTR3_DATAST                                       EPSC_NTR3_DATAST_Msk

#define    EPSC_NTR3_ADDHLD_Pos                                   (4U)
#define    EPSC_NTR3_ADDHLD_Msk                                   (0xfU << EPSC_NTR3_ADDHLD_Pos)
#define    EPSC_NTR3_ADDHLD                                       EPSC_NTR3_ADDHLD_Msk

#define    EPSC_NTR3_ADDSET_Pos                                   (0U)
#define    EPSC_NTR3_ADDSET_Msk                                   (0xfU << EPSC_NTR3_ADDSET_Pos)
#define    EPSC_NTR3_ADDSET                                       EPSC_NTR3_ADDSET_Msk

#define    EPSC_NWTR3_ACCMOD_Pos                                  (28U)
#define    EPSC_NWTR3_ACCMOD_Msk                                  (0x3U << EPSC_NWTR3_ACCMOD_Pos)
#define    EPSC_NWTR3_ACCMOD                                      EPSC_NWTR3_ACCMOD_Msk

#define    EPSC_NWTR3_BUSTURN_Pos                                 (16U)
#define    EPSC_NWTR3_BUSTURN_Msk                                 (0xfU << EPSC_NWTR3_BUSTURN_Pos)
#define    EPSC_NWTR3_BUSTURN                                     EPSC_NWTR3_BUSTURN_Msk

#define    EPSC_NWTR3_DATAST_Pos                                  (8U)
#define    EPSC_NWTR3_DATAST_Msk                                  (0xffU << EPSC_NWTR3_DATAST_Pos)
#define    EPSC_NWTR3_DATAST                                      EPSC_NWTR3_DATAST_Msk

#define    EPSC_NWTR3_ADDHLD_Pos                                  (4U)
#define    EPSC_NWTR3_ADDHLD_Msk                                  (0xfU << EPSC_NWTR3_ADDHLD_Pos)
#define    EPSC_NWTR3_ADDHLD                                      EPSC_NWTR3_ADDHLD_Msk

#define    EPSC_NWTR3_ADDSET_Pos                                  (0U)
#define    EPSC_NWTR3_ADDSET_Msk                                  (0xfU << EPSC_NWTR3_ADDSET_Pos)
#define    EPSC_NWTR3_ADDSET                                      EPSC_NWTR3_ADDSET_Msk

#define    EPSC_NCR4_FIFOEN_Pos                                   (27U)
#define    EPSC_NCR4_FIFOEN_Msk                                   (0x1U << EPSC_NCR4_FIFOEN_Pos)
#define    EPSC_NCR4_FIFOEN                                       EPSC_NCR4_FIFOEN_Msk

#define    EPSC_NCR4_TCEN_Pos                                     (24U)
#define    EPSC_NCR4_TCEN_Msk                                     (0x1U << EPSC_NCR4_TCEN_Pos)
#define    EPSC_NCR4_TCEN                                         EPSC_NCR4_TCEN_Msk

#define    EPSC_NCR4_CCLKEN_Pos                                   (20U)
#define    EPSC_NCR4_CCLKEN_Msk                                   (0x1U << EPSC_NCR4_CCLKEN_Pos)
#define    EPSC_NCR4_CCLKEN                                       EPSC_NCR4_CCLKEN_Msk

#define    EPSC_NCR4_CBURSTWR_Pos                                 (19U)
#define    EPSC_NCR4_CBURSTWR_Msk                                 (0x1U << EPSC_NCR4_CBURSTWR_Pos)
#define    EPSC_NCR4_CBURSTWR                                     EPSC_NCR4_CBURSTWR_Msk

#define    EPSC_NCR4_ASYNCWAIT_Pos                                (15U)
#define    EPSC_NCR4_ASYNCWAIT_Msk                                (0x1U << EPSC_NCR4_ASYNCWAIT_Pos)
#define    EPSC_NCR4_ASYNCWAIT                                    EPSC_NCR4_ASYNCWAIT_Msk

#define    EPSC_NCR4_EXTMOD_Pos                                   (14U)
#define    EPSC_NCR4_EXTMOD_Msk                                   (0x1U << EPSC_NCR4_EXTMOD_Pos)
#define    EPSC_NCR4_EXTMOD                                       EPSC_NCR4_EXTMOD_Msk

#define    EPSC_NCR4_WAITEN_Pos                                   (13U)
#define    EPSC_NCR4_WAITEN_Msk                                   (0x1U << EPSC_NCR4_WAITEN_Pos)
#define    EPSC_NCR4_WAITEN                                       EPSC_NCR4_WAITEN_Msk

#define    EPSC_NCR4_WREN_Pos                                     (12U)
#define    EPSC_NCR4_WREN_Msk                                     (0x1U << EPSC_NCR4_WREN_Pos)
#define    EPSC_NCR4_WREN                                         EPSC_NCR4_WREN_Msk

#define    EPSC_NCR4_WAITCFG_Pos                                  (11U)
#define    EPSC_NCR4_WAITCFG_Msk                                  (0x1U << EPSC_NCR4_WAITCFG_Pos)
#define    EPSC_NCR4_WAITCFG                                      EPSC_NCR4_WAITCFG_Msk

#define    EPSC_NCR4_WAITPOL_Pos                                  (9U)
#define    EPSC_NCR4_WAITPOL_Msk                                  (0x1U << EPSC_NCR4_WAITPOL_Pos)
#define    EPSC_NCR4_WAITPOL                                      EPSC_NCR4_WAITPOL_Msk

#define    EPSC_NCR4_BURSTEN_Pos                                  (8U)
#define    EPSC_NCR4_BURSTEN_Msk                                  (0x1U << EPSC_NCR4_BURSTEN_Pos)
#define    EPSC_NCR4_BURSTEN                                      EPSC_NCR4_BURSTEN_Msk

#define    EPSC_NCR4_MWID_Pos                                     (4U)
#define    EPSC_NCR4_MWID_Msk                                     (0x3U << EPSC_NCR4_MWID_Pos)
#define    EPSC_NCR4_MWID                                         EPSC_NCR4_MWID_Msk

#define    EPSC_NCR4_MTYP_Pos                                     (2U)
#define    EPSC_NCR4_MTYP_Msk                                     (0x3U << EPSC_NCR4_MTYP_Pos)
#define    EPSC_NCR4_MTYP                                         EPSC_NCR4_MTYP_Msk

#define    EPSC_NCR4_MUXEN_Pos                                    (1U)
#define    EPSC_NCR4_MUXEN_Msk                                    (0x1U << EPSC_NCR4_MUXEN_Pos)
#define    EPSC_NCR4_MUXEN                                        EPSC_NCR4_MUXEN_Msk

#define    EPSC_NCR4_MBKEN_Pos                                    (0U)
#define    EPSC_NCR4_MBKEN_Msk                                    (0x1U << EPSC_NCR4_MBKEN_Pos)
#define    EPSC_NCR4_MBKEN                                        EPSC_NCR4_MBKEN_Msk

#define    EPSC_NTR4_ACCMOD_Pos                                   (28U)
#define    EPSC_NTR4_ACCMOD_Msk                                   (0x3U << EPSC_NTR4_ACCMOD_Pos)
#define    EPSC_NTR4_ACCMOD                                       EPSC_NTR4_ACCMOD_Msk

#define    EPSC_NTR4_DATLAT_Pos                                   (24U)
#define    EPSC_NTR4_DATLAT_Msk                                   (0xfU << EPSC_NTR4_DATLAT_Pos)
#define    EPSC_NTR4_DATLAT                                       EPSC_NTR4_DATLAT_Msk

#define    EPSC_NTR4_CLKDIV_Pos                                   (20U)
#define    EPSC_NTR4_CLKDIV_Msk                                   (0xfU << EPSC_NTR4_CLKDIV_Pos)
#define    EPSC_NTR4_CLKDIV                                       EPSC_NTR4_CLKDIV_Msk

#define    EPSC_NTR4_BUSTURN_Pos                                  (16U)
#define    EPSC_NTR4_BUSTURN_Msk                                  (0xfU << EPSC_NTR4_BUSTURN_Pos)
#define    EPSC_NTR4_BUSTURN                                      EPSC_NTR4_BUSTURN_Msk

#define    EPSC_NTR4_DATAST_Pos                                   (8U)
#define    EPSC_NTR4_DATAST_Msk                                   (0xffU << EPSC_NTR4_DATAST_Pos)
#define    EPSC_NTR4_DATAST                                       EPSC_NTR4_DATAST_Msk

#define    EPSC_NTR4_ADDHLD_Pos                                   (4U)
#define    EPSC_NTR4_ADDHLD_Msk                                   (0xfU << EPSC_NTR4_ADDHLD_Pos)
#define    EPSC_NTR4_ADDHLD                                       EPSC_NTR4_ADDHLD_Msk

#define    EPSC_NTR4_ADDSET_Pos                                   (0U)
#define    EPSC_NTR4_ADDSET_Msk                                   (0xfU << EPSC_NTR4_ADDSET_Pos)
#define    EPSC_NTR4_ADDSET                                       EPSC_NTR4_ADDSET_Msk

#define    EPSC_NWTR4_ACCMOD_Pos                                  (28U)
#define    EPSC_NWTR4_ACCMOD_Msk                                  (0x3U << EPSC_NWTR4_ACCMOD_Pos)
#define    EPSC_NWTR4_ACCMOD                                      EPSC_NWTR4_ACCMOD_Msk

#define    EPSC_NWTR4_BUSTURN_Pos                                 (16U)
#define    EPSC_NWTR4_BUSTURN_Msk                                 (0xfU << EPSC_NWTR4_BUSTURN_Pos)
#define    EPSC_NWTR4_BUSTURN                                     EPSC_NWTR4_BUSTURN_Msk

#define    EPSC_NWTR4_DATAST_Pos                                  (8U)
#define    EPSC_NWTR4_DATAST_Msk                                  (0xffU << EPSC_NWTR4_DATAST_Pos)
#define    EPSC_NWTR4_DATAST                                      EPSC_NWTR4_DATAST_Msk

#define    EPSC_NWTR4_ADDHLD_Pos                                  (4U)
#define    EPSC_NWTR4_ADDHLD_Msk                                  (0xfU << EPSC_NWTR4_ADDHLD_Pos)
#define    EPSC_NWTR4_ADDHLD                                      EPSC_NWTR4_ADDHLD_Msk

#define    EPSC_NWTR4_ADDSET_Pos                                  (0U)
#define    EPSC_NWTR4_ADDSET_Msk                                  (0xfU << EPSC_NWTR4_ADDSET_Pos)
#define    EPSC_NWTR4_ADDSET                                      EPSC_NWTR4_ADDSET_Msk

#define    EPSC_ISR_FULL_Pos                                      (9U)
#define    EPSC_ISR_FULL_Msk                                      (0x1U << EPSC_ISR_FULL_Pos)
#define    EPSC_ISR_FULL                                          EPSC_ISR_FULL_Msk

#define    EPSC_ISR_HALF_FULL_Pos                                 (8U)
#define    EPSC_ISR_HALF_FULL_Msk                                 (0x1U << EPSC_ISR_HALF_FULL_Pos)
#define    EPSC_ISR_HALF_FULL                                     EPSC_ISR_HALF_FULL_Msk

#define    EPSC_ISR_TCF_Pos                                       (7U)
#define    EPSC_ISR_TCF_Msk                                       (0x1U << EPSC_ISR_TCF_Pos)
#define    EPSC_ISR_TCF                                           EPSC_ISR_TCF_Msk

#define    EPSC_ISR_TEF_Pos                                       (6U)
#define    EPSC_ISR_TEF_Msk                                       (0x1U << EPSC_ISR_TEF_Pos)
#define    EPSC_ISR_TEF                                           EPSC_ISR_TEF_Msk

#define    EPSC_ISR_BUSY_Pos                                      (5U)
#define    EPSC_ISR_BUSY_Msk                                      (0x1U << EPSC_ISR_BUSY_Pos)
#define    EPSC_ISR_BUSY                                          EPSC_ISR_BUSY_Msk

#define    EPSC_ISR_TOF_Pos                                       (4U)
#define    EPSC_ISR_TOF_Msk                                       (0x1U << EPSC_ISR_TOF_Pos)
#define    EPSC_ISR_TOF                                           EPSC_ISR_TOF_Msk

#define    EPSC_ISR_NER_Pos                                       (2U)
#define    EPSC_ISR_NER_Msk                                       (0x1U << EPSC_ISR_NER_Pos)
#define    EPSC_ISR_NER                                           EPSC_ISR_NER_Msk

#define    EPSC_ISR_NEF_Pos                                       (1U)
#define    EPSC_ISR_NEF_Msk                                       (0x1U << EPSC_ISR_NEF_Pos)
#define    EPSC_ISR_NEF                                           EPSC_ISR_NEF_Msk

#define    EPSC_ISR_FEMPT_Pos                                     (0U)
#define    EPSC_ISR_FEMPT_Msk                                     (0x1U << EPSC_ISR_FEMPT_Pos)
#define    EPSC_ISR_FEMPT                                         EPSC_ISR_FEMPT_Msk

#define    EPSC_IER_FFIE_Pos                                      (9U)
#define    EPSC_IER_FFIE_Msk                                      (0x1U << EPSC_IER_FFIE_Pos)
#define    EPSC_IER_FFIE                                          EPSC_IER_FFIE_Msk

#define    EPSC_IER_FHFIE_Pos                                     (8U)
#define    EPSC_IER_FHFIE_Msk                                     (0x1U << EPSC_IER_FHFIE_Pos)
#define    EPSC_IER_FHFIE                                         EPSC_IER_FHFIE_Msk

#define    EPSC_IER_TCIE_Pos                                      (7U)
#define    EPSC_IER_TCIE_Msk                                      (0x1U << EPSC_IER_TCIE_Pos)
#define    EPSC_IER_TCIE                                          EPSC_IER_TCIE_Msk

#define    EPSC_IER_TEIE_Pos                                      (6U)
#define    EPSC_IER_TEIE_Msk                                      (0x1U << EPSC_IER_TEIE_Pos)
#define    EPSC_IER_TEIE                                          EPSC_IER_TEIE_Msk

#define    EPSC_IER_TOIE_Pos                                      (4U)
#define    EPSC_IER_TOIE_Msk                                      (0x1U << EPSC_IER_TOIE_Pos)
#define    EPSC_IER_TOIE                                          EPSC_IER_TOIE_Msk

#define    EPSC_IER_NERIE_Pos                                     (2U)
#define    EPSC_IER_NERIE_Msk                                     (0x1U << EPSC_IER_NERIE_Pos)
#define    EPSC_IER_NERIE                                         EPSC_IER_NERIE_Msk

#define    EPSC_IER_NEFIE_Pos                                     (1U)
#define    EPSC_IER_NEFIE_Msk                                     (0x1U << EPSC_IER_NEFIE_Pos)
#define    EPSC_IER_NEFIE                                         EPSC_IER_NEFIE_Msk

#define    EPSC_IER_FEIE_Pos                                      (0U)
#define    EPSC_IER_FEIE_Msk                                      (0x1U << EPSC_IER_FEIE_Pos)
#define    EPSC_IER_FEIE                                          EPSC_IER_FEIE_Msk

#define    EPSC_TOR_TO_Pos                                        (0U)
#define    EPSC_TOR_TO_Msk                                        (0xffffU << EPSC_TOR_TO_Pos)
#define    EPSC_TOR_TO                                             EPSC_TOR_TO_Msk

#define    FL_EPSC_BANK1_NORSRAM1                                 (0x1U << 0U)
#define    FL_EPSC_BANK1_NORSRAM2                                 (0x1U << 1U)
#define    FL_EPSC_BANK1_NORSRAM3                                 (0x1U << 2U)
#define    FL_EPSC_BANK1_NORSRAM4                                 (0x1U << 3U)
#define    FL_EPSC_NCR_SYNC_MODE_ASYNC                            (0x0U << 19U)
#define    FL_EPSC_NCR_SYNC_MODE_SYNC                             (0x1U << 19U)
#define    FL_EPSC_NCR_ACTIVE_STATE_BEFORE                        (0x0U << 11U)
#define    FL_EPSC_NCR_ACTIVE_STATE_DURING                        (0x1U << 11U)
#define    FL_EPSC_NCR_POLARITY_LOW                               (0x0U << 9U)
#define    FL_EPSC_NCR_POLARITY_HIGH                              (0x1U << 9U)
#define    FL_EPSC_NCR_MEMORY_WIDTH_8B                            (0x0U << 4U)
#define    FL_EPSC_NCR_MEMORY_WIDTH_16B                           (0x1U << 4U)
#define    FL_EPSC_NCR_MEMORY_TYPE_SRAM                           (0x0U << 2U)
#define    FL_EPSC_NCR_MEMORY_TYPE_PSRAM                          (0x1U << 2U)
#define    FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH                      (0x2U << 2U)
#define    FL_EPSC_NTR_EXTMOD_MODE_A                              (0x0U << 28U)
#define    FL_EPSC_NTR_EXTMOD_MODE_B                              (0x1U << 28U)
#define    FL_EPSC_NTR_EXTMOD_MODE_C                              (0x2U << 28U)
#define    FL_EPSC_NTR_EXTMOD_MODE_D                              (0x3U << 28U)
#define    FL_EPSC_NTR_DATA_LATENCY_2CLK                          (0x0U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_3CLK                          (0x1U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_4CLK                          (0x2U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_5CLK                          (0x3U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_6CLK                          (0x4U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_7CLK                          (0x5U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_8CLK                          (0x6U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_9CLK                          (0x7U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_10CLK                         (0x8U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_11CLK                         (0x9U << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_12CLK                         (0xaU << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_13CLK                         (0xbU << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_14CLK                         (0xcU << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_15CLK                         (0xdU << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_16CLK                         (0xeU << 24U)
#define    FL_EPSC_NTR_DATA_LATENCY_17CLK                         (0xfU << 24U)
#define    FL_EPSC_NTR_CLK_DIV2                                  (0x1U << 20U)
#define    FL_EPSC_NTR_CLK_DIV3                                  (0x2U << 20U)
#define    FL_EPSC_NTR_CLK_DIV4                                  (0x3U << 20U)
#define    FL_EPSC_NTR_CLK_DIV5                                  (0x4U << 20U)
#define    FL_EPSC_NTR_CLK_DIV6                                  (0x5U << 20U)
#define    FL_EPSC_NTR_CLK_DIV7                                  (0x6U << 20U)
#define    FL_EPSC_NTR_CLK_DIV8                                  (0x7U << 20U)
#define    FL_EPSC_NTR_CLK_DIV9                                  (0x8U << 20U)
#define    FL_EPSC_NTR_CLK_DIV10                                 (0x9U << 20U)
#define    FL_EPSC_NTR_CLK_DIV11                                 (0xaU << 20U)
#define    FL_EPSC_NTR_CLK_DIV12                                 (0xbU << 20U)
#define    FL_EPSC_NTR_CLK_DIV13                                 (0xcU << 20U)
#define    FL_EPSC_NTR_CLK_DIV14                                 (0xdU << 20U)
#define    FL_EPSC_NTR_CLK_DIV15                                 (0xeU << 20U)
#define    FL_EPSC_NTR_CLK_DIV16                                 (0xfU << 20U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_0CLK                        (0x0U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_1CLK                        (0x1U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_2CLK                        (0x2U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_3CLK                        (0x3U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_4CLK                        (0x4U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_5CLK                        (0x5U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_6CLK                        (0x6U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_7CLK                        (0x7U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_8CLK                        (0x8U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_9CLK                        (0x9U << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_10CLK                       (0xaU << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_11CLK                       (0xbU << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_12CLK                       (0xcU << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_13CLK                       (0xdU << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_14CLK                       (0xeU << 16U)
#define    FL_EPSC_NTR_BUS_TRUNAROUND_15CLK                       (0xfU << 16U)
#define    FL_EPSC_NWTR_EXTMOD_MODE_A                             (0x0U << 28U)
#define    FL_EPSC_NWTR_EXTMOD_MODE_B                             (0x1U << 28U)
#define    FL_EPSC_NWTR_EXTMOD_MODE_C                             (0x2U << 28U)
#define    FL_EPSC_NWTR_EXTMOD_MODE_D                             (0x3U << 28U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK                       (0x0U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK                       (0x1U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK                       (0x2U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK                       (0x3U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK                       (0x4U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK                       (0x5U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK                       (0x6U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK                       (0x7U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK                       (0x8U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK                       (0x9U << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK                      (0xaU << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK                      (0xbU << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK                      (0xcU << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK                      (0xdU << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK                      (0xeU << 16U)
#define    FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK                      (0xfU << 16U)

//#define    FL_EPSC_NCR_SYNC_MODE_ASYNC                            (0x0U << EPSC_NCR1_CBURSTWR_Pos)
//#define    FL_EPSC_NCR_SYNC_MODE_SYNC                             (0x1U << EPSC_NCR1_CBURSTWR_Pos)

//#define    FL_EPSC_NCR_ACTIVE_STATE_BEFORE                        (0x0U << EPSC_NCR1_WAITCFG_Pos)
//#define    FL_EPSC_NCR_ACTIVE_STATE_DURING                        (0x1U << EPSC_NCR1_WAITCFG_Pos)

//#define    FL_EPSC_NCR_POLARITY_LOW                               (0x0U << EPSC_NCR1_WAITPOL_Pos)
//#define    FL_EPSC_NCR_POLARITY_HIGH                              (0x1U << EPSC_NCR1_WAITPOL_Pos)

//#define    FL_EPSC_NCR_MEMORY_WIDTH_8B                            (0x0U << EPSC_NCR1_MWID_Pos)
//#define    FL_EPSC_NCR_MEMORY_WIDTH_16B                           (0x1U << EPSC_NCR1_MWID_Pos)

//#define    FL_EPSC_NCR_MEMORY_TYPE_SRAM                           (0x0U << EPSC_NCR1_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_PSRAM                          (0x1U << EPSC_NCR1_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH                      (0x2U << EPSC_NCR1_MTYP_Pos)

//#define    FL_EPSC_NTR_EXTMOD_MODE_A                              (0x0U << EPSC_NTR1_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_B                              (0x1U << EPSC_NTR1_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_C                              (0x2U << EPSC_NTR1_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_D                              (0x3U << EPSC_NTR1_ACCMOD_Pos)

//#define    FL_EPSC_NTR_DATA_LATENCY_2CLK                          (0x0U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_3CLK                          (0x1U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_4CLK                          (0x2U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_5CLK                          (0x3U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_6CLK                          (0x4U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_7CLK                          (0x5U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_8CLK                          (0x6U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_9CLK                          (0x7U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_10CLK                         (0x8U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_11CLK                         (0x9U << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_12CLK                         (0xaU << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_13CLK                         (0xbU << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_14CLK                         (0xcU << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_15CLK                         (0xdU << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_16CLK                         (0xeU << EPSC_NTR1_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_17CLK                         (0xfU << EPSC_NTR1_DATLAT_Pos)

//#define    FL_EPSC_NTR_CLK_DIV2                                  (0x1U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV3                                  (0x2U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV4                                  (0x3U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV5                                  (0x4U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV6                                  (0x5U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV7                                  (0x6U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV8                                  (0x7U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV9                                  (0x8U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV10                                 (0x9U << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV11                                 (0xaU << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV12                                 (0xbU << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV13                                 (0xcU << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV14                                 (0xdU << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV15                                 (0xeU << EPSC_NTR1_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV16                                 (0xfU << EPSC_NTR1_CLKDIV_Pos)

//#define    FL_EPSC_NTR_BUS_TRUNAROUND_0CLK                        (0x0U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_1CLK                        (0x1U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_2CLK                        (0x2U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_3CLK                        (0x3U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_4CLK                        (0x4U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_5CLK                        (0x5U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_6CLK                        (0x6U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_7CLK                        (0x7U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_8CLK                        (0x8U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_9CLK                        (0x9U << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_10CLK                       (0xaU << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_11CLK                       (0xbU << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_12CLK                       (0xcU << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_13CLK                       (0xdU << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_14CLK                       (0xeU << EPSC_NTR1_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_15CLK                       (0xfU << EPSC_NTR1_BUSTURN_Pos)

//#define    FL_EPSC_NWTR_EXTMOD_MODE_A                             (0x0U << EPSC_NWTR1_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_B                             (0x1U << EPSC_NWTR1_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_C                             (0x2U << EPSC_NWTR1_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_D                             (0x3U << EPSC_NWTR1_ACCMOD_Pos)

//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK                       (0x0U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK                       (0x1U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK                       (0x2U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK                       (0x3U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK                       (0x4U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK                       (0x5U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK                       (0x6U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK                       (0x7U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK                       (0x8U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK                       (0x9U << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK                      (0xaU << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK                      (0xbU << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK                      (0xcU << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK                      (0xdU << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK                      (0xeU << EPSC_NWTR1_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK                      (0xfU << EPSC_NWTR1_BUSTURN_Pos)

//#define    FL_EPSC_NCR_SYNC_MODE_ASYNC                            (0x0U << EPSC_NCR2_CBURSTWR_Pos)
//#define    FL_EPSC_NCR_SYNC_MODE_SYNC                             (0x1U << EPSC_NCR2_CBURSTWR_Pos)

//#define    FL_EPSC_NCR_ACTIVE_STATE_BEFORE                        (0x0U << EPSC_NCR2_WAITCFG_Pos)
//#define    FL_EPSC_NCR_ACTIVE_STATE_DURING                        (0x1U << EPSC_NCR2_WAITCFG_Pos)

//#define    FL_EPSC_NCR_POLARITY_LOW                               (0x0U << EPSC_NCR2_WAITPOL_Pos)
//#define    FL_EPSC_NCR_POLARITY_HIGH                              (0x1U << EPSC_NCR2_WAITPOL_Pos)

//#define    FL_EPSC_NCR_MEMORY_WIDTH_8B                            (0x0U << EPSC_NCR2_MWID_Pos)
//#define    FL_EPSC_NCR_MEMORY_WIDTH_16B                           (0x1U << EPSC_NCR2_MWID_Pos)

//#define    FL_EPSC_NCR_MEMORY_TYPE_SRAM                           (0x0U << EPSC_NCR2_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_PSRAM                          (0x1U << EPSC_NCR2_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH                      (0x2U << EPSC_NCR2_MTYP_Pos)

//#define    FL_EPSC_NTR_EXTMOD_MODE_A                              (0x0U << EPSC_NTR2_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_B                              (0x1U << EPSC_NTR2_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_C                              (0x2U << EPSC_NTR2_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_D                              (0x3U << EPSC_NTR2_ACCMOD_Pos)

//#define    FL_EPSC_NTR_DATA_LATENCY_2CLK                          (0x0U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_3CLK                          (0x1U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_4CLK                          (0x2U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_5CLK                          (0x3U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_6CLK                          (0x4U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_7CLK                          (0x5U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_8CLK                          (0x6U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_9CLK                          (0x7U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_10CLK                         (0x8U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_11CLK                         (0x9U << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_12CLK                         (0xaU << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_13CLK                         (0xbU << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_14CLK                         (0xcU << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_15CLK                         (0xdU << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_16CLK                         (0xeU << EPSC_NTR2_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_17CLK                         (0xfU << EPSC_NTR2_DATLAT_Pos)

//#define    FL_EPSC_NTR_CLK_DIV2                                  (0x1U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV3                                  (0x2U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV4                                  (0x3U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV5                                  (0x4U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV6                                  (0x5U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV7                                  (0x6U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV8                                  (0x7U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV9                                  (0x8U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV10                                 (0x9U << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV11                                 (0xaU << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV12                                 (0xbU << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV13                                 (0xcU << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV14                                 (0xdU << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV15                                 (0xeU << EPSC_NTR2_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV16                                 (0xfU << EPSC_NTR2_CLKDIV_Pos)

//#define    FL_EPSC_NTR_BUS_TRUNAROUND_0CLK                        (0x0U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_1CLK                        (0x1U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_2CLK                        (0x2U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_3CLK                        (0x3U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_4CLK                        (0x4U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_5CLK                        (0x5U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_6CLK                        (0x6U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_7CLK                        (0x7U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_8CLK                        (0x8U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_9CLK                        (0x9U << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_10CLK                       (0xaU << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_11CLK                       (0xbU << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_12CLK                       (0xcU << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_13CLK                       (0xdU << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_14CLK                       (0xeU << EPSC_NTR2_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_15CLK                       (0xfU << EPSC_NTR2_BUSTURN_Pos)

//#define    FL_EPSC_NWTR_EXTMOD_MODE_A                             (0x0U << EPSC_NWTR2_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_B                             (0x1U << EPSC_NWTR2_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_C                             (0x2U << EPSC_NWTR2_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_D                             (0x3U << EPSC_NWTR2_ACCMOD_Pos)

//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK                       (0x0U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK                       (0x1U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK                       (0x2U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK                       (0x3U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK                       (0x4U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK                       (0x5U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK                       (0x6U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK                       (0x7U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK                       (0x8U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK                       (0x9U << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK                      (0xaU << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK                      (0xbU << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK                      (0xcU << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK                      (0xdU << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK                      (0xeU << EPSC_NWTR2_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK                      (0xfU << EPSC_NWTR2_BUSTURN_Pos)

//#define    FL_EPSC_NCR_SYNC_MODE_ASYNC                            (0x0U << EPSC_NCR3_CBURSTWR_Pos)
//#define    FL_EPSC_NCR_SYNC_MODE_SYNC                             (0x1U << EPSC_NCR3_CBURSTWR_Pos)

//#define    FL_EPSC_NCR_ACTIVE_STATE_BEFORE                        (0x0U << EPSC_NCR3_WAITCFG_Pos)
//#define    FL_EPSC_NCR_ACTIVE_STATE_DURING                        (0x1U << EPSC_NCR3_WAITCFG_Pos)

//#define    FL_EPSC_NCR_POLARITY_LOW                               (0x0U << EPSC_NCR3_WAITPOL_Pos)
//#define    FL_EPSC_NCR_POLARITY_HIGH                              (0x1U << EPSC_NCR3_WAITPOL_Pos)

//#define    FL_EPSC_NCR_MEMORY_WIDTH_8B                            (0x0U << EPSC_NCR3_MWID_Pos)
//#define    FL_EPSC_NCR_MEMORY_WIDTH_16B                           (0x1U << EPSC_NCR3_MWID_Pos)

//#define    FL_EPSC_NCR_MEMORY_TYPE_SRAM                           (0x0U << EPSC_NCR3_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_PSRAM                          (0x1U << EPSC_NCR3_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH                      (0x2U << EPSC_NCR3_MTYP_Pos)

//#define    FL_EPSC_NTR_EXTMOD_MODE_A                              (0x0U << EPSC_NTR3_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_B                              (0x1U << EPSC_NTR3_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_C                              (0x2U << EPSC_NTR3_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_D                              (0x3U << EPSC_NTR3_ACCMOD_Pos)

//#define    FL_EPSC_NTR_DATA_LATENCY_2CLK                          (0x0U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_3CLK                          (0x1U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_4CLK                          (0x2U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_5CLK                          (0x3U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_6CLK                          (0x4U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_7CLK                          (0x5U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_8CLK                          (0x6U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_9CLK                          (0x7U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_10CLK                         (0x8U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_11CLK                         (0x9U << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_12CLK                         (0xaU << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_13CLK                         (0xbU << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_14CLK                         (0xcU << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_15CLK                         (0xdU << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_16CLK                         (0xeU << EPSC_NTR3_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_17CLK                         (0xfU << EPSC_NTR3_DATLAT_Pos)

//#define    FL_EPSC_NTR_CLK_DIV2                                  (0x1U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV3                                  (0x2U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV4                                  (0x3U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV5                                  (0x4U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV6                                  (0x5U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV7                                  (0x6U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV8                                  (0x7U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV9                                  (0x8U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV10                                 (0x9U << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV11                                 (0xaU << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV12                                 (0xbU << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV13                                 (0xcU << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV14                                 (0xdU << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV15                                 (0xeU << EPSC_NTR3_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV16                                 (0xfU << EPSC_NTR3_CLKDIV_Pos)

//#define    FL_EPSC_NTR_BUS_TRUNAROUND_0CLK                        (0x0U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_1CLK                        (0x1U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_2CLK                        (0x2U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_3CLK                        (0x3U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_4CLK                        (0x4U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_5CLK                        (0x5U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_6CLK                        (0x6U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_7CLK                        (0x7U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_8CLK                        (0x8U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_9CLK                        (0x9U << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_10CLK                       (0xaU << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_11CLK                       (0xbU << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_12CLK                       (0xcU << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_13CLK                       (0xdU << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_14CLK                       (0xeU << EPSC_NTR3_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_15CLK                       (0xfU << EPSC_NTR3_BUSTURN_Pos)

//#define    FL_EPSC_NWTR_EXTMOD_MODE_A                             (0x0U << EPSC_NWTR3_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_B                             (0x1U << EPSC_NWTR3_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_C                             (0x2U << EPSC_NWTR3_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_D                             (0x3U << EPSC_NWTR3_ACCMOD_Pos)

//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK                       (0x0U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK                       (0x1U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK                       (0x2U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK                       (0x3U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK                       (0x4U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK                       (0x5U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK                       (0x6U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK                       (0x7U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK                       (0x8U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK                       (0x9U << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK                      (0xaU << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK                      (0xbU << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK                      (0xcU << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK                      (0xdU << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK                      (0xeU << EPSC_NWTR3_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK                      (0xfU << EPSC_NWTR3_BUSTURN_Pos)

//#define    FL_EPSC_NCR_SYNC_MODE_ASYNC                            (0x0U << EPSC_NCR4_CBURSTWR_Pos)
//#define    FL_EPSC_NCR_SYNC_MODE_SYNC                             (0x1U << EPSC_NCR4_CBURSTWR_Pos)

//#define    FL_EPSC_NCR_ACTIVE_STATE_BEFORE                        (0x0U << EPSC_NCR4_WAITCFG_Pos)
//#define    FL_EPSC_NCR_ACTIVE_STATE_DURING                        (0x1U << EPSC_NCR4_WAITCFG_Pos)

//#define    FL_EPSC_NCR_POLARITY_LOW                               (0x0U << EPSC_NCR4_WAITPOL_Pos)
//#define    FL_EPSC_NCR_POLARITY_HIGH                              (0x1U << EPSC_NCR4_WAITPOL_Pos)

//#define    FL_EPSC_NCR_MEMORY_WIDTH_8B                            (0x0U << EPSC_NCR4_MWID_Pos)
//#define    FL_EPSC_NCR_MEMORY_WIDTH_16B                           (0x1U << EPSC_NCR4_MWID_Pos)

//#define    FL_EPSC_NCR_MEMORY_TYPE_SRAM                           (0x0U << EPSC_NCR4_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_PSRAM                          (0x1U << EPSC_NCR4_MTYP_Pos)
//#define    FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH                      (0x2U << EPSC_NCR4_MTYP_Pos)

//#define    FL_EPSC_NTR_EXTMOD_MODE_A                              (0x0U << EPSC_NTR4_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_B                              (0x1U << EPSC_NTR4_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_C                              (0x2U << EPSC_NTR4_ACCMOD_Pos)
//#define    FL_EPSC_NTR_EXTMOD_MODE_D                              (0x3U << EPSC_NTR4_ACCMOD_Pos)

//#define    FL_EPSC_NTR_DATA_LATENCY_2CLK                          (0x0U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_3CLK                          (0x1U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_4CLK                          (0x2U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_5CLK                          (0x3U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_6CLK                          (0x4U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_7CLK                          (0x5U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_8CLK                          (0x6U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_9CLK                          (0x7U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_10CLK                         (0x8U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_11CLK                         (0x9U << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_12CLK                         (0xaU << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_13CLK                         (0xbU << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_14CLK                         (0xcU << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_15CLK                         (0xdU << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_16CLK                         (0xeU << EPSC_NTR4_DATLAT_Pos)
//#define    FL_EPSC_NTR_DATA_LATENCY_17CLK                         (0xfU << EPSC_NTR4_DATLAT_Pos)

//#define    FL_EPSC_NTR_CLK_DIV2                                  (0x1U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV3                                  (0x2U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV4                                  (0x3U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV5                                  (0x4U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV6                                  (0x5U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV7                                  (0x6U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV8                                  (0x7U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV9                                  (0x8U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV10                                 (0x9U << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV11                                 (0xaU << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV12                                 (0xbU << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV13                                 (0xcU << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV14                                 (0xdU << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV15                                 (0xeU << EPSC_NTR4_CLKDIV_Pos)
//#define    FL_EPSC_NTR_CLK_DIV16                                 (0xfU << EPSC_NTR4_CLKDIV_Pos)

//#define    FL_EPSC_NTR_BUS_TRUNAROUND_0CLK                        (0x0U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_1CLK                        (0x1U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_2CLK                        (0x2U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_3CLK                        (0x3U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_4CLK                        (0x4U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_5CLK                        (0x5U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_6CLK                        (0x6U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_7CLK                        (0x7U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_8CLK                        (0x8U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_9CLK                        (0x9U << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_10CLK                       (0xaU << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_11CLK                       (0xbU << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_12CLK                       (0xcU << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_13CLK                       (0xdU << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_14CLK                       (0xeU << EPSC_NTR4_BUSTURN_Pos)
//#define    FL_EPSC_NTR_BUS_TRUNAROUND_15CLK                       (0xfU << EPSC_NTR4_BUSTURN_Pos)

//#define    FL_EPSC_NWTR_EXTMOD_MODE_A                             (0x0U << EPSC_NWTR4_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_B                             (0x1U << EPSC_NWTR4_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_C                             (0x2U << EPSC_NWTR4_ACCMOD_Pos)
//#define    FL_EPSC_NWTR_EXTMOD_MODE_D                             (0x3U << EPSC_NWTR4_ACCMOD_Pos)

//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK                       (0x0U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK                       (0x1U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK                       (0x2U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK                       (0x3U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK                       (0x4U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK                       (0x5U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK                       (0x6U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK                       (0x7U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK                       (0x8U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK                       (0x9U << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK                      (0xaU << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK                      (0xbU << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK                      (0xcU << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK                      (0xdU << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK                      (0xeU << EPSC_NWTR4_BUSTURN_Pos)
//#define    FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK                      (0xfU << EPSC_NWTR4_BUSTURN_Pos)

/**
  * @}
  */
/* Exported functions ---------------------------------------------------------------------------------*/
/** @defgroup EPSC_FL_Exported_Functions EPSC Exported Functions
  * @{
  */

/**
  * @brief    Enable FIFO Function
  * @rmtoll   NCR1    FIFOEN    FL_EPSC_EnableNCR1_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_FIFO(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_FIFOEN_Msk);
}

/**
  * @brief    Disable FIFO Function
  * @rmtoll   NCR1    FIFOEN    FL_EPSC_DisableNCR1_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_FIFO(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_FIFOEN_Msk);
}

/**
  * @brief    Get FIFO Function Status
  * @rmtoll   NCR1    FIFOEN    FL_EPSC_IsEnabledNCR1_FIFO
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_FIFO(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_FIFOEN_Msk) == EPSC_NCR1_FIFOEN_Msk);
}

/**
  * @brief    Enable Timeout Function
  * @rmtoll   NCR1    TCEN    FL_EPSC_EnableNCR1_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_Timeout(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_TCEN_Msk);
}

/**
  * @brief    Disable Timeout Function
  * @rmtoll   NCR1    TCEN    FL_EPSC_DisableNCR1_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_Timeout(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_TCEN_Msk);
}

/**
  * @brief    Get Timeout Function Status
  * @rmtoll   NCR1    TCEN    FL_EPSC_IsEnabledNCR1_Timeout
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_Timeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_TCEN_Msk) == EPSC_NCR1_TCEN_Msk);
}

/**
  * @brief    Enable Contiunous CLK Function
  * @rmtoll   NCR1    CCLKEN    FL_EPSC_EnableNCR1_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_ContiunousCLK(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_CCLKEN_Msk);
}

/**
  * @brief    Disable  Contiunous CLK Function
  * @rmtoll   NCR1    CCLKEN    FL_EPSC_DisableNCR1_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_ContiunousCLK(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_CCLKEN_Msk);
}

/**
  * @brief    Get  Contiunous CLK Function Status
  * @rmtoll   NCR1    CCLKEN    FL_EPSC_IsEnabledNCR1_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_ContiunousCLK(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_CCLKEN_Msk) == EPSC_NCR1_CCLKEN_Msk);
}

/**
  * @brief    Set PSRAM write Burst Mode
  * @rmtoll   NCR1    CBURSTWR    FL_EPSC_SetNCR1_writeBurstMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR1_writeBurstMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR1, EPSC_NCR1_CBURSTWR_Msk, mode);
}

/**
  * @brief    Get PSRAM write Burst Mode
  * @rmtoll   NCR1    CBURSTWR    FL_EPSC_GetNCR1_writeBurstMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR1_writeBurstMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_CBURSTWR_Msk));
}

/**
  * @brief    Enable Asynchronous Wait Mode
  * @rmtoll   NCR1    ASYNCWAIT    FL_EPSC_EnableNCR1_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_AsynchronousWait(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_ASYNCWAIT_Msk);
}

/**
  * @brief    Disable Asynchronous Wait Mode
  * @rmtoll   NCR1    ASYNCWAIT    FL_EPSC_DisableNCR1_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_AsynchronousWait(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_ASYNCWAIT_Msk);
}

/**
  * @brief    Get Asynchronous Wait Mode Status
  * @rmtoll   NCR1    ASYNCWAIT    FL_EPSC_IsEnabledNCR1_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_AsynchronousWait(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_ASYNCWAIT_Msk) == EPSC_NCR1_ASYNCWAIT_Msk);
}

/**
  * @brief    Enable Extended Mode
  * @rmtoll   NCR1    EXTMOD    FL_EPSC_EnableNCR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_ExtendedMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_EXTMOD_Msk);
}

/**
  * @brief    Disable Extended Mode
  * @rmtoll   NCR1    EXTMOD    FL_EPSC_DisableNCR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_ExtendedMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_EXTMOD_Msk);
}

/**
  * @brief    Get Extended Mode Status
  * @rmtoll   NCR1    EXTMOD    FL_EPSC_IsEnabledNCR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_EXTMOD_Msk) == EPSC_NCR1_EXTMOD_Msk);
}

/**
  * @brief    Enable Wait Mode
  * @rmtoll   NCR1    WAITEN    FL_EPSC_EnableNCR1_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_WaitMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_WAITEN_Msk);
}

/**
  * @brief    Disable Wait Mode
  * @rmtoll   NCR1    WAITEN    FL_EPSC_DisableNCR1_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_WaitMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_WAITEN_Msk);
}

/**
  * @brief    Get Wait Mode Status
  * @rmtoll   NCR1    WAITEN    FL_EPSC_IsEnabledNCR1_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_WaitMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_WAITEN_Msk) == EPSC_NCR1_WAITEN_Msk);
}

/**
  * @brief    Enable Write Mode
  * @rmtoll   NCR1    WREN    FL_EPSC_EnableNCR1_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_WriteMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_WREN_Msk);
}

/**
  * @brief    Disable Write Mode
  * @rmtoll   NCR1    WREN    FL_EPSC_DisableNCR1_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_WriteMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_WREN_Msk);
}

/**
  * @brief    Get Write Mode Status
  * @rmtoll   NCR1    WREN    FL_EPSC_IsEnabledNCR1_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_WriteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_WREN_Msk) == EPSC_NCR1_WREN_Msk);
}

/**
  * @brief    Set Wait Timing Mode
  * @rmtoll   NCR1    WAITCFG    FL_EPSC_SetNCR1_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR1_WaitTimingMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR1, EPSC_NCR1_WAITCFG_Msk, mode);
}

/**
  * @brief    Get Wait Timing Mode
  * @rmtoll   NCR1    WAITCFG    FL_EPSC_GetNCR1_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR1_WaitTimingMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_WAITCFG_Msk));
}

/**
  * @brief    Set Wait Polarity
  * @rmtoll   NCR1    WAITPOL    FL_EPSC_SetNCR1_WaitPolarity
  * @param    EPSCx EPSC instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR1_WaitPolarity(EPSC_Type *EPSCx, uint32_t polarity)
{
    MODIFY_REG(EPSCx->NCR1, EPSC_NCR1_WAITPOL_Msk, polarity);
}

/**
  * @brief    Get Wait Polarity
  * @rmtoll   NCR1    WAITPOL    FL_EPSC_GetNCR1_WaitPolarity
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR1_WaitPolarity(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_WAITPOL_Msk));
}

/**
  * @brief    Enable Burst Mode
  * @rmtoll   NCR1    BURSTEN    FL_EPSC_EnableNCR1_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_BurstMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_BURSTEN_Msk);
}

/**
  * @brief    Disable Burst Mode
  * @rmtoll   NCR1    BURSTEN    FL_EPSC_DisableNCR1_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_BurstMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_BURSTEN_Msk);
}

/**
  * @brief    Get Burst Mode Status
  * @rmtoll   NCR1    BURSTEN    FL_EPSC_IsEnabledNCR1_BursteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_BursteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_BURSTEN_Msk) == EPSC_NCR1_BURSTEN_Msk);
}

/**
  * @brief    Set Memory Bus Width
  * @rmtoll   NCR1    MWID    FL_EPSC_SetNCR1_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @param    width This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR1_MemoryBusWidth(EPSC_Type *EPSCx, uint32_t width)
{
    MODIFY_REG(EPSCx->NCR1, EPSC_NCR1_MWID_Msk, width);
}

/**
  * @brief    Get Memory Bus Width
  * @rmtoll   NCR1    MWID    FL_EPSC_GetNCR1_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR1_MemoryBusWidth(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_MWID_Msk));
}

/**
  * @brief    Set Memory Type
  * @rmtoll   NCR1    MTYP    FL_EPSC_SetNCR1_MemoryType
  * @param    EPSCx EPSC instance
  * @param    memorytype This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR1_MemoryType(EPSC_Type *EPSCx, uint32_t memorytype)
{
    MODIFY_REG(EPSCx->NCR1, EPSC_NCR1_MTYP_Msk, memorytype);
}

/**
  * @brief    Get Memory Type
  * @rmtoll   NCR1    MTYP    FL_EPSC_GetNCR1_MemoryType
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR1_MemoryType(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_MTYP_Msk));
}

/**
  * @brief    Enable Data Address Multiplex
  * @rmtoll   NCR1    MUXEN    FL_EPSC_EnableNCR1_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_DataAddressMux(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_MUXEN_Msk);
}

/**
  * @brief    Disable Burst ModeData Address Multiplex
  * @rmtoll   NCR1    MUXEN    FL_EPSC_DisableNCR1_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_DataAddressMux(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_MUXEN_Msk);
}

/**
  * @brief    Get Data Address Multiplex  Status
  * @rmtoll   NCR1    MUXEN    FL_EPSC_IsEnabledNCR1_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_DataAddressMux(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_MUXEN_Msk) == EPSC_NCR1_MUXEN_Msk);
}

/**
  * @brief    Enable Memory Bank
  * @rmtoll   NCR1    MBKEN    FL_EPSC_EnableNCR1_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR1_MemoryBank(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR1, EPSC_NCR1_MBKEN_Msk);
}

/**
  * @brief    Disable Memory Bank
  * @rmtoll   NCR1    MBKEN    FL_EPSC_DisableNCR1_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR1_MemoryBank(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR1, EPSC_NCR1_MBKEN_Msk);
}

/**
  * @brief    Get Memory Bank Status
  * @rmtoll   NCR1    MBKEN    FL_EPSC_IsEnabledNCR1_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR1_MemoryBank(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR1, EPSC_NCR1_MBKEN_Msk) == EPSC_NCR1_MBKEN_Msk);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NTR1    ACCMOD    FL_EPSC_SetNTR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR1_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NTR1, EPSC_NTR1_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NTR1    ACCMOD    FL_EPSC_GetNTR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR1_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, EPSC_NTR1_ACCMOD_Msk));
}

/**
  * @brief    Set Data Latency Cycle
  * @rmtoll   NTR1    DATLAT    FL_EPSC_SetNTR1_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR1_DataLatencyCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR1, EPSC_NTR1_DATLAT_Msk, cyclce);
}

/**
  * @brief    Read Data Latency Cycle
  * @rmtoll   NTR1    DATLAT    FL_EPSC_GetNTR1_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR1_DataLatencyCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, EPSC_NTR1_DATLAT_Msk));
}

/**
  * @brief    Set Clk Perscale
  * @rmtoll   NTR1    CLKDIV    FL_EPSC_SetNTR1_ClkPerscale
  * @param    EPSCx EPSC instance
  * @param    Perscale This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR1_ClkPerscale(EPSC_Type *EPSCx, uint32_t Perscale)
{
    MODIFY_REG(EPSCx->NTR1, EPSC_NTR1_CLKDIV_Msk, Perscale);
}

/**
  * @brief    Read Clk Perscale
  * @rmtoll   NTR1    CLKDIV    FL_EPSC_GetNTR1_ClkPerscale
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR1_ClkPerscale(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, EPSC_NTR1_CLKDIV_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NTR1    BUSTURN    FL_EPSC_SetNTR1_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR1_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR1, EPSC_NTR1_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NTR1    BUSTURN    FL_EPSC_GetNTR1_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR1_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, EPSC_NTR1_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NTR1    DATAST    FL_EPSC_WriteNTR1_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR1_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR1, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NTR1    DATAST    FL_EPSC_ReadNTR1_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR1_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NTR1    ADDHLD    FL_EPSC_WriteNTR1_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR1_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR1, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NTR1    ADDHLD    FL_EPSC_ReadNTR1_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR1_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NTR1    ADDSET    FL_EPSC_WriteNTR1_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR1_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR1, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NTR1    ADDSET    FL_EPSC_ReadNTR1_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR1_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR1, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NWTR1    ACCMOD    FL_EPSC_SetNWTR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR1_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NWTR1, EPSC_NWTR1_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NWTR1    ACCMOD    FL_EPSC_GetNWTR1_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR1_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR1, EPSC_NWTR1_ACCMOD_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NWTR1    BUSTURN    FL_EPSC_SetNWTR1_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR1_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NWTR1, EPSC_NWTR1_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NWTR1    BUSTURN    FL_EPSC_GetNWTR1_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR1_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR1, EPSC_NWTR1_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NWTR1    DATAST    FL_EPSC_WriteNWTR1_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR1_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR1, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NWTR1    DATAST    FL_EPSC_ReadNWTR1_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR1_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR1, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NWTR1    ADDHLD    FL_EPSC_WriteNWTR1_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR1_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR1, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NWTR1    ADDHLD    FL_EPSC_ReadNWTR1_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR1_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR1, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NWTR1    ADDSET    FL_EPSC_WriteNWTR1_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR1_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR1, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NWTR1    ADDSET    FL_EPSC_ReadNWTR1_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR1_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR1, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Enable FIFO Function
  * @rmtoll   NCR2    FIFOEN    FL_EPSC_EnableNCR2_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_FIFO(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_FIFOEN_Msk);
}

/**
  * @brief    Disable FIFO Function
  * @rmtoll   NCR2    FIFOEN    FL_EPSC_DisableNCR2_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_FIFO(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_FIFOEN_Msk);
}

/**
  * @brief    Get FIFO Function Status
  * @rmtoll   NCR2    FIFOEN    FL_EPSC_IsEnabledNCR2_FIFO
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_FIFO(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_FIFOEN_Msk) == EPSC_NCR2_FIFOEN_Msk);
}

/**
  * @brief    Enable Timeout Function
  * @rmtoll   NCR2    TCEN    FL_EPSC_EnableNCR2_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_Timeout(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_TCEN_Msk);
}

/**
  * @brief    Disable Timeout Function
  * @rmtoll   NCR2    TCEN    FL_EPSC_DisableNCR2_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_Timeout(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_TCEN_Msk);
}

/**
  * @brief    Get Timeout Function Status
  * @rmtoll   NCR2    TCEN    FL_EPSC_IsEnabledNCR2_Timeout
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_Timeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_TCEN_Msk) == EPSC_NCR2_TCEN_Msk);
}

/**
  * @brief    Enable Contiunous CLK Function
  * @rmtoll   NCR2    CCLKEN    FL_EPSC_EnableNCR2_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_ContiunousCLK(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_CCLKEN_Msk);
}

/**
  * @brief    Disable  Contiunous CLK Function
  * @rmtoll   NCR2    CCLKEN    FL_EPSC_DisableNCR2_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_ContiunousCLK(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_CCLKEN_Msk);
}

/**
  * @brief    Get  Contiunous CLK Function Status
  * @rmtoll   NCR2    CCLKEN    FL_EPSC_IsEnabledNCR2_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_ContiunousCLK(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_CCLKEN_Msk) == EPSC_NCR2_CCLKEN_Msk);
}

/**
  * @brief    Set PSRAM write Burst Mode
  * @rmtoll   NCR2    CBURSTWR    FL_EPSC_SetNCR2_writeBurstMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR2_writeBurstMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR2, EPSC_NCR2_CBURSTWR_Msk, mode);
}

/**
  * @brief    Get PSRAM write Burst Mode
  * @rmtoll   NCR2    CBURSTWR    FL_EPSC_GetNCR2_writeBurstMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR2_writeBurstMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_CBURSTWR_Msk));
}

/**
  * @brief    Enable Asynchronous Wait Mode
  * @rmtoll   NCR2    ASYNCWAIT    FL_EPSC_EnableNCR2_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_AsynchronousWait(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_ASYNCWAIT_Msk);
}

/**
  * @brief    Disable Asynchronous Wait Mode
  * @rmtoll   NCR2    ASYNCWAIT    FL_EPSC_DisableNCR2_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_AsynchronousWait(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_ASYNCWAIT_Msk);
}

/**
  * @brief    Get Asynchronous Wait Mode Status
  * @rmtoll   NCR2    ASYNCWAIT    FL_EPSC_IsEnabledNCR2_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_AsynchronousWait(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_ASYNCWAIT_Msk) == EPSC_NCR2_ASYNCWAIT_Msk);
}

/**
  * @brief    Enable Extended Mode
  * @rmtoll   NCR2    EXTMOD    FL_EPSC_EnableNCR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_ExtendedMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_EXTMOD_Msk);
}

/**
  * @brief    Disable Extended Mode
  * @rmtoll   NCR2    EXTMOD    FL_EPSC_DisableNCR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_ExtendedMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_EXTMOD_Msk);
}

/**
  * @brief    Get Extended Mode Status
  * @rmtoll   NCR2    EXTMOD    FL_EPSC_IsEnabledNCR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_EXTMOD_Msk) == EPSC_NCR2_EXTMOD_Msk);
}

/**
  * @brief    Enable Wait Mode
  * @rmtoll   NCR2    WAITEN    FL_EPSC_EnableNCR2_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_WaitMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_WAITEN_Msk);
}

/**
  * @brief    Disable Wait Mode
  * @rmtoll   NCR2    WAITEN    FL_EPSC_DisableNCR2_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_WaitMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_WAITEN_Msk);
}

/**
  * @brief    Get Wait Mode Status
  * @rmtoll   NCR2    WAITEN    FL_EPSC_IsEnabledNCR2_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_WaitMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_WAITEN_Msk) == EPSC_NCR2_WAITEN_Msk);
}

/**
  * @brief    Enable Write Mode
  * @rmtoll   NCR2    WREN    FL_EPSC_EnableNCR2_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_WriteMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_WREN_Msk);
}

/**
  * @brief    Disable Write Mode
  * @rmtoll   NCR2    WREN    FL_EPSC_DisableNCR2_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_WriteMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_WREN_Msk);
}

/**
  * @brief    Get Write Mode Status
  * @rmtoll   NCR2    WREN    FL_EPSC_IsEnabledNCR2_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_WriteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_WREN_Msk) == EPSC_NCR2_WREN_Msk);
}

/**
  * @brief    Set Wait Timing Mode
  * @rmtoll   NCR2    WAITCFG    FL_EPSC_SetNCR2_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR2_WaitTimingMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR2, EPSC_NCR2_WAITCFG_Msk, mode);
}

/**
  * @brief    Get Wait Timing Mode
  * @rmtoll   NCR2    WAITCFG    FL_EPSC_GetNCR2_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR2_WaitTimingMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_WAITCFG_Msk));
}

/**
  * @brief    Set Wait Polarity
  * @rmtoll   NCR2    WAITPOL    FL_EPSC_SetNCR2_WaitPolarity
  * @param    EPSCx EPSC instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR2_WaitPolarity(EPSC_Type *EPSCx, uint32_t polarity)
{
    MODIFY_REG(EPSCx->NCR2, EPSC_NCR2_WAITPOL_Msk, polarity);
}

/**
  * @brief    Get Wait Polarity
  * @rmtoll   NCR2    WAITPOL    FL_EPSC_GetNCR2_WaitPolarity
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR2_WaitPolarity(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_WAITPOL_Msk));
}

/**
  * @brief    Enable Burst Mode
  * @rmtoll   NCR2    BURSTEN    FL_EPSC_EnableNCR2_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_BurstMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_BURSTEN_Msk);
}

/**
  * @brief    Disable Burst Mode
  * @rmtoll   NCR2    BURSTEN    FL_EPSC_DisableNCR2_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_BurstMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_BURSTEN_Msk);
}

/**
  * @brief    Get Burst Mode Status
  * @rmtoll   NCR2    BURSTEN    FL_EPSC_IsEnabledNCR2_BursteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_BursteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_BURSTEN_Msk) == EPSC_NCR2_BURSTEN_Msk);
}

/**
  * @brief    Set Memory Bus Width
  * @rmtoll   NCR2    MWID    FL_EPSC_SetNCR2_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @param    width This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR2_MemoryBusWidth(EPSC_Type *EPSCx, uint32_t width)
{
    MODIFY_REG(EPSCx->NCR2, EPSC_NCR2_MWID_Msk, width);
}

/**
  * @brief    Get Memory Bus Width
  * @rmtoll   NCR2    MWID    FL_EPSC_GetNCR2_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR2_MemoryBusWidth(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_MWID_Msk));
}

/**
  * @brief    Set Memory Type
  * @rmtoll   NCR2    MTYP    FL_EPSC_SetNCR2_MemoryType
  * @param    EPSCx EPSC instance
  * @param    memorytype This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR2_MemoryType(EPSC_Type *EPSCx, uint32_t memorytype)
{
    MODIFY_REG(EPSCx->NCR2, EPSC_NCR2_MTYP_Msk, memorytype);
}

/**
  * @brief    Get Memory Type
  * @rmtoll   NCR2    MTYP    FL_EPSC_GetNCR2_MemoryType
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR2_MemoryType(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_MTYP_Msk));
}

/**
  * @brief    Enable Data Address Multiplex
  * @rmtoll   NCR2    MUXEN    FL_EPSC_EnableNCR2_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_DataAddressMux(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_MUXEN_Msk);
}

/**
  * @brief    Disable Burst ModeData Address Multiplex
  * @rmtoll   NCR2    MUXEN    FL_EPSC_DisableNCR2_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_DataAddressMux(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_MUXEN_Msk);
}

/**
  * @brief    Get Data Address Multiplex  Status
  * @rmtoll   NCR2    MUXEN    FL_EPSC_IsEnabledNCR2_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_DataAddressMux(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_MUXEN_Msk) == EPSC_NCR2_MUXEN_Msk);
}

/**
  * @brief    Enable Memory Bank
  * @rmtoll   NCR2    MBKEN    FL_EPSC_EnableNCR2_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR2_MemoryBank(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR2, EPSC_NCR2_MBKEN_Msk);
}

/**
  * @brief    Disable Memory Bank
  * @rmtoll   NCR2    MBKEN    FL_EPSC_DisableNCR2_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR2_MemoryBank(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR2, EPSC_NCR2_MBKEN_Msk);
}

/**
  * @brief    Get Memory Bank Status
  * @rmtoll   NCR2    MBKEN    FL_EPSC_IsEnabledNCR2_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR2_MemoryBank(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR2, EPSC_NCR2_MBKEN_Msk) == EPSC_NCR2_MBKEN_Msk);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NTR2    ACCMOD    FL_EPSC_SetNTR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR2_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NTR2, EPSC_NTR2_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NTR2    ACCMOD    FL_EPSC_GetNTR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR2_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, EPSC_NTR2_ACCMOD_Msk));
}

/**
  * @brief    Set Data Latency Cycle
  * @rmtoll   NTR2    DATLAT    FL_EPSC_SetNTR2_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR2_DataLatencyCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR2, EPSC_NTR2_DATLAT_Msk, cyclce);
}

/**
  * @brief    Read Data Latency Cycle
  * @rmtoll   NTR2    DATLAT    FL_EPSC_GetNTR2_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR2_DataLatencyCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, EPSC_NTR2_DATLAT_Msk));
}

/**
  * @brief    Set Clk Perscale
  * @rmtoll   NTR2    CLKDIV    FL_EPSC_SetNTR2_ClkPerscale
  * @param    EPSCx EPSC instance
  * @param    Perscale This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR2_ClkPerscale(EPSC_Type *EPSCx, uint32_t Perscale)
{
    MODIFY_REG(EPSCx->NTR2, EPSC_NTR2_CLKDIV_Msk, Perscale);
}

/**
  * @brief    Read Clk Perscale
  * @rmtoll   NTR2    CLKDIV    FL_EPSC_GetNTR2_ClkPerscale
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR2_ClkPerscale(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, EPSC_NTR2_CLKDIV_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NTR2    BUSTURN    FL_EPSC_SetNTR2_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR2_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR2, EPSC_NTR2_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NTR2    BUSTURN    FL_EPSC_GetNTR2_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR2_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, EPSC_NTR2_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NTR2    DATAST    FL_EPSC_WriteNTR2_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR2_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR2, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NTR2    DATAST    FL_EPSC_ReadNTR2_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR2_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NTR2    ADDHLD    FL_EPSC_WriteNTR2_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR2_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR2, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NTR2    ADDHLD    FL_EPSC_ReadNTR2_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR2_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NTR2    ADDSET    FL_EPSC_WriteNTR2_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR2_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR2, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NTR2    ADDSET    FL_EPSC_ReadNTR2_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR2_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR2, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NWTR2    ACCMOD    FL_EPSC_SetNWTR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR2_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NWTR2, EPSC_NWTR2_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NWTR2    ACCMOD    FL_EPSC_GetNWTR2_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR2_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR2, EPSC_NWTR2_ACCMOD_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NWTR2    BUSTURN    FL_EPSC_SetNWTR2_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR2_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NWTR2, EPSC_NWTR2_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NWTR2    BUSTURN    FL_EPSC_GetNWTR2_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR2_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR2, EPSC_NWTR2_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NWTR2    DATAST    FL_EPSC_WriteNWTR2_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR2_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR2, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NWTR2    DATAST    FL_EPSC_ReadNWTR2_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR2_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR2, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NWTR2    ADDHLD    FL_EPSC_WriteNWTR2_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR2_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR2, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NWTR2    ADDHLD    FL_EPSC_ReadNWTR2_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR2_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR2, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NWTR2    ADDSET    FL_EPSC_WriteNWTR2_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR2_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR2, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NWTR2    ADDSET    FL_EPSC_ReadNWTR2_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR2_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR2, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Enable FIFO Function
  * @rmtoll   NCR3    FIFOEN    FL_EPSC_EnableNCR3_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_FIFO(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_FIFOEN_Msk);
}

/**
  * @brief    Disable FIFO Function
  * @rmtoll   NCR3    FIFOEN    FL_EPSC_DisableNCR3_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_FIFO(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_FIFOEN_Msk);
}

/**
  * @brief    Get FIFO Function Status
  * @rmtoll   NCR3    FIFOEN    FL_EPSC_IsEnabledNCR3_FIFO
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_FIFO(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_FIFOEN_Msk) == EPSC_NCR3_FIFOEN_Msk);
}

/**
  * @brief    Enable Timeout Function
  * @rmtoll   NCR3    TCEN    FL_EPSC_EnableNCR3_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_Timeout(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_TCEN_Msk);
}

/**
  * @brief    Disable Timeout Function
  * @rmtoll   NCR3    TCEN    FL_EPSC_DisableNCR3_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_Timeout(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_TCEN_Msk);
}

/**
  * @brief    Get Timeout Function Status
  * @rmtoll   NCR3    TCEN    FL_EPSC_IsEnabledNCR3_Timeout
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_Timeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_TCEN_Msk) == EPSC_NCR3_TCEN_Msk);
}

/**
  * @brief    Enable Contiunous CLK Function
  * @rmtoll   NCR3    CCLKEN    FL_EPSC_EnableNCR3_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_ContiunousCLK(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_CCLKEN_Msk);
}

/**
  * @brief    Disable  Contiunous CLK Function
  * @rmtoll   NCR3    CCLKEN    FL_EPSC_DisableNCR3_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_ContiunousCLK(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_CCLKEN_Msk);
}

/**
  * @brief    Get  Contiunous CLK Function Status
  * @rmtoll   NCR3    CCLKEN    FL_EPSC_IsEnabledNCR3_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_ContiunousCLK(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_CCLKEN_Msk) == EPSC_NCR3_CCLKEN_Msk);
}

/**
  * @brief    Set PSRAM write Burst Mode
  * @rmtoll   NCR3    CBURSTWR    FL_EPSC_SetNCR3_writeBurstMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR3_writeBurstMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR3, EPSC_NCR3_CBURSTWR_Msk, mode);
}

/**
  * @brief    Get PSRAM write Burst Mode
  * @rmtoll   NCR3    CBURSTWR    FL_EPSC_GetNCR3_writeBurstMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR3_writeBurstMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_CBURSTWR_Msk));
}

/**
  * @brief    Enable Asynchronous Wait Mode
  * @rmtoll   NCR3    ASYNCWAIT    FL_EPSC_EnableNCR3_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_AsynchronousWait(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_ASYNCWAIT_Msk);
}

/**
  * @brief    Disable Asynchronous Wait Mode
  * @rmtoll   NCR3    ASYNCWAIT    FL_EPSC_DisableNCR3_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_AsynchronousWait(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_ASYNCWAIT_Msk);
}

/**
  * @brief    Get Asynchronous Wait Mode Status
  * @rmtoll   NCR3    ASYNCWAIT    FL_EPSC_IsEnabledNCR3_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_AsynchronousWait(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_ASYNCWAIT_Msk) == EPSC_NCR3_ASYNCWAIT_Msk);
}

/**
  * @brief    Enable Extended Mode
  * @rmtoll   NCR3    EXTMOD    FL_EPSC_EnableNCR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_ExtendedMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_EXTMOD_Msk);
}

/**
  * @brief    Disable Extended Mode
  * @rmtoll   NCR3    EXTMOD    FL_EPSC_DisableNCR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_ExtendedMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_EXTMOD_Msk);
}

/**
  * @brief    Get Extended Mode Status
  * @rmtoll   NCR3    EXTMOD    FL_EPSC_IsEnabledNCR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_EXTMOD_Msk) == EPSC_NCR3_EXTMOD_Msk);
}

/**
  * @brief    Enable Wait Mode
  * @rmtoll   NCR3    WAITEN    FL_EPSC_EnableNCR3_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_WaitMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_WAITEN_Msk);
}

/**
  * @brief    Disable Wait Mode
  * @rmtoll   NCR3    WAITEN    FL_EPSC_DisableNCR3_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_WaitMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_WAITEN_Msk);
}

/**
  * @brief    Get Wait Mode Status
  * @rmtoll   NCR3    WAITEN    FL_EPSC_IsEnabledNCR3_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_WaitMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_WAITEN_Msk) == EPSC_NCR3_WAITEN_Msk);
}

/**
  * @brief    Enable Write Mode
  * @rmtoll   NCR3    WREN    FL_EPSC_EnableNCR3_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_WriteMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_WREN_Msk);
}

/**
  * @brief    Disable Write Mode
  * @rmtoll   NCR3    WREN    FL_EPSC_DisableNCR3_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_WriteMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_WREN_Msk);
}

/**
  * @brief    Get Write Mode Status
  * @rmtoll   NCR3    WREN    FL_EPSC_IsEnabledNCR3_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_WriteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_WREN_Msk) == EPSC_NCR3_WREN_Msk);
}

/**
  * @brief    Set Wait Timing Mode
  * @rmtoll   NCR3    WAITCFG    FL_EPSC_SetNCR3_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR3_WaitTimingMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR3, EPSC_NCR3_WAITCFG_Msk, mode);
}

/**
  * @brief    Get Wait Timing Mode
  * @rmtoll   NCR3    WAITCFG    FL_EPSC_GetNCR3_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR3_WaitTimingMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_WAITCFG_Msk));
}

/**
  * @brief    Set Wait Polarity
  * @rmtoll   NCR3    WAITPOL    FL_EPSC_SetNCR3_WaitPolarity
  * @param    EPSCx EPSC instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR3_WaitPolarity(EPSC_Type *EPSCx, uint32_t polarity)
{
    MODIFY_REG(EPSCx->NCR3, EPSC_NCR3_WAITPOL_Msk, polarity);
}

/**
  * @brief    Get Wait Polarity
  * @rmtoll   NCR3    WAITPOL    FL_EPSC_GetNCR3_WaitPolarity
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR3_WaitPolarity(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_WAITPOL_Msk));
}

/**
  * @brief    Enable Burst Mode
  * @rmtoll   NCR3    BURSTEN    FL_EPSC_EnableNCR3_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_BurstMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_BURSTEN_Msk);
}

/**
  * @brief    Disable Burst Mode
  * @rmtoll   NCR3    BURSTEN    FL_EPSC_DisableNCR3_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_BurstMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_BURSTEN_Msk);
}

/**
  * @brief    Get Burst Mode Status
  * @rmtoll   NCR3    BURSTEN    FL_EPSC_IsEnabledNCR3_BursteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_BursteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_BURSTEN_Msk) == EPSC_NCR3_BURSTEN_Msk);
}

/**
  * @brief    Set Memory Bus Width
  * @rmtoll   NCR3    MWID    FL_EPSC_SetNCR3_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @param    width This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR3_MemoryBusWidth(EPSC_Type *EPSCx, uint32_t width)
{
    MODIFY_REG(EPSCx->NCR3, EPSC_NCR3_MWID_Msk, width);
}

/**
  * @brief    Get Memory Bus Width
  * @rmtoll   NCR3    MWID    FL_EPSC_GetNCR3_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR3_MemoryBusWidth(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_MWID_Msk));
}

/**
  * @brief    Set Memory Type
  * @rmtoll   NCR3    MTYP    FL_EPSC_SetNCR3_MemoryType
  * @param    EPSCx EPSC instance
  * @param    memorytype This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR3_MemoryType(EPSC_Type *EPSCx, uint32_t memorytype)
{
    MODIFY_REG(EPSCx->NCR3, EPSC_NCR3_MTYP_Msk, memorytype);
}

/**
  * @brief    Get Memory Type
  * @rmtoll   NCR3    MTYP    FL_EPSC_GetNCR3_MemoryType
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR3_MemoryType(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_MTYP_Msk));
}

/**
  * @brief    Enable Data Address Multiplex
  * @rmtoll   NCR3    MUXEN    FL_EPSC_EnableNCR3_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_DataAddressMux(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_MUXEN_Msk);
}

/**
  * @brief    Disable Burst ModeData Address Multiplex
  * @rmtoll   NCR3    MUXEN    FL_EPSC_DisableNCR3_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_DataAddressMux(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_MUXEN_Msk);
}

/**
  * @brief    Get Data Address Multiplex  Status
  * @rmtoll   NCR3    MUXEN    FL_EPSC_IsEnabledNCR3_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_DataAddressMux(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_MUXEN_Msk) == EPSC_NCR3_MUXEN_Msk);
}

/**
  * @brief    Enable Memory Bank
  * @rmtoll   NCR3    MBKEN    FL_EPSC_EnableNCR3_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR3_MemoryBank(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR3, EPSC_NCR3_MBKEN_Msk);
}

/**
  * @brief    Disable Memory Bank
  * @rmtoll   NCR3    MBKEN    FL_EPSC_DisableNCR3_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR3_MemoryBank(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR3, EPSC_NCR3_MBKEN_Msk);
}

/**
  * @brief    Get Memory Bank Status
  * @rmtoll   NCR3    MBKEN    FL_EPSC_IsEnabledNCR3_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR3_MemoryBank(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR3, EPSC_NCR3_MBKEN_Msk) == EPSC_NCR3_MBKEN_Msk);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NTR3    ACCMOD    FL_EPSC_SetNTR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR3_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NTR3, EPSC_NTR3_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NTR3    ACCMOD    FL_EPSC_GetNTR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR3_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, EPSC_NTR3_ACCMOD_Msk));
}

/**
  * @brief    Set Data Latency Cycle
  * @rmtoll   NTR3    DATLAT    FL_EPSC_SetNTR3_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR3_DataLatencyCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR3, EPSC_NTR3_DATLAT_Msk, cyclce);
}

/**
  * @brief    Read Data Latency Cycle
  * @rmtoll   NTR3    DATLAT    FL_EPSC_GetNTR3_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR3_DataLatencyCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, EPSC_NTR3_DATLAT_Msk));
}

/**
  * @brief    Set Clk Perscale
  * @rmtoll   NTR3    CLKDIV    FL_EPSC_SetNTR3_ClkPerscale
  * @param    EPSCx EPSC instance
  * @param    Perscale This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR3_ClkPerscale(EPSC_Type *EPSCx, uint32_t Perscale)
{
    MODIFY_REG(EPSCx->NTR3, EPSC_NTR3_CLKDIV_Msk, Perscale);
}

/**
  * @brief    Read Clk Perscale
  * @rmtoll   NTR3    CLKDIV    FL_EPSC_GetNTR3_ClkPerscale
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR3_ClkPerscale(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, EPSC_NTR3_CLKDIV_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NTR3    BUSTURN    FL_EPSC_SetNTR3_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR3_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR3, EPSC_NTR3_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NTR3    BUSTURN    FL_EPSC_GetNTR3_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR3_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, EPSC_NTR3_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NTR3    DATAST    FL_EPSC_WriteNTR3_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR3_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR3, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NTR3    DATAST    FL_EPSC_ReadNTR3_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR3_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NTR3    ADDHLD    FL_EPSC_WriteNTR3_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR3_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR3, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NTR3    ADDHLD    FL_EPSC_ReadNTR3_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR3_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NTR3    ADDSET    FL_EPSC_WriteNTR3_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR3_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR3, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NTR3    ADDSET    FL_EPSC_ReadNTR3_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR3_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR3, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NWTR3    ACCMOD    FL_EPSC_SetNWTR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR3_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NWTR3, EPSC_NWTR3_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NWTR3    ACCMOD    FL_EPSC_GetNWTR3_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR3_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR3, EPSC_NWTR3_ACCMOD_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NWTR3    BUSTURN    FL_EPSC_SetNWTR3_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR3_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NWTR3, EPSC_NWTR3_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NWTR3    BUSTURN    FL_EPSC_GetNWTR3_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR3_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR3, EPSC_NWTR3_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NWTR3    DATAST    FL_EPSC_WriteNWTR3_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR3_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR3, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NWTR3    DATAST    FL_EPSC_ReadNWTR3_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR3_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR3, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NWTR3    ADDHLD    FL_EPSC_WriteNWTR3_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR3_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR3, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NWTR3    ADDHLD    FL_EPSC_ReadNWTR3_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR3_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR3, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NWTR3    ADDSET    FL_EPSC_WriteNWTR3_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR3_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR3, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NWTR3    ADDSET    FL_EPSC_ReadNWTR3_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR3_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR3, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Enable FIFO Function
  * @rmtoll   NCR4    FIFOEN    FL_EPSC_EnableNCR4_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_FIFO(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_FIFOEN_Msk);
}

/**
  * @brief    Disable FIFO Function
  * @rmtoll   NCR4    FIFOEN    FL_EPSC_DisableNCR4_FIFO
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_FIFO(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_FIFOEN_Msk);
}

/**
  * @brief    Get FIFO Function Status
  * @rmtoll   NCR4    FIFOEN    FL_EPSC_IsEnabledNCR4_FIFO
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_FIFO(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_FIFOEN_Msk) == EPSC_NCR4_FIFOEN_Msk);
}

/**
  * @brief    Enable Timeout Function
  * @rmtoll   NCR4    TCEN    FL_EPSC_EnableNCR4_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_Timeout(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_TCEN_Msk);
}

/**
  * @brief    Disable Timeout Function
  * @rmtoll   NCR4    TCEN    FL_EPSC_DisableNCR4_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_Timeout(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_TCEN_Msk);
}

/**
  * @brief    Get Timeout Function Status
  * @rmtoll   NCR4    TCEN    FL_EPSC_IsEnabledNCR4_Timeout
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_Timeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_TCEN_Msk) == EPSC_NCR4_TCEN_Msk);
}

/**
  * @brief    Enable Contiunous CLK Function
  * @rmtoll   NCR4    CCLKEN    FL_EPSC_EnableNCR4_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_ContiunousCLK(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_CCLKEN_Msk);
}

/**
  * @brief    Disable  Contiunous CLK Function
  * @rmtoll   NCR4    CCLKEN    FL_EPSC_DisableNCR4_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_ContiunousCLK(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_CCLKEN_Msk);
}

/**
  * @brief    Get  Contiunous CLK Function Status
  * @rmtoll   NCR4    CCLKEN    FL_EPSC_IsEnabledNCR4_ContiunousCLK
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_ContiunousCLK(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_CCLKEN_Msk) == EPSC_NCR4_CCLKEN_Msk);
}

/**
  * @brief    Set PSRAM write Burst Mode
  * @rmtoll   NCR4    CBURSTWR    FL_EPSC_SetNCR4_writeBurstMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR4_writeBurstMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR4, EPSC_NCR4_CBURSTWR_Msk, mode);
}

/**
  * @brief    Get PSRAM write Burst Mode
  * @rmtoll   NCR4    CBURSTWR    FL_EPSC_GetNCR4_writeBurstMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_ASYNC
  *           @arg @ref FL_EPSC_NCR_SYNC_MODE_SYNC
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR4_writeBurstMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_CBURSTWR_Msk));
}

/**
  * @brief    Enable Asynchronous Wait Mode
  * @rmtoll   NCR4    ASYNCWAIT    FL_EPSC_EnableNCR4_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_AsynchronousWait(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_ASYNCWAIT_Msk);
}

/**
  * @brief    Disable Asynchronous Wait Mode
  * @rmtoll   NCR4    ASYNCWAIT    FL_EPSC_DisableNCR4_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_AsynchronousWait(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_ASYNCWAIT_Msk);
}

/**
  * @brief    Get Asynchronous Wait Mode Status
  * @rmtoll   NCR4    ASYNCWAIT    FL_EPSC_IsEnabledNCR4_AsynchronousWait
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_AsynchronousWait(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_ASYNCWAIT_Msk) == EPSC_NCR4_ASYNCWAIT_Msk);
}

/**
  * @brief    Enable Extended Mode
  * @rmtoll   NCR4    EXTMOD    FL_EPSC_EnableNCR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_ExtendedMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_EXTMOD_Msk);
}

/**
  * @brief    Disable Extended Mode
  * @rmtoll   NCR4    EXTMOD    FL_EPSC_DisableNCR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_ExtendedMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_EXTMOD_Msk);
}

/**
  * @brief    Get Extended Mode Status
  * @rmtoll   NCR4    EXTMOD    FL_EPSC_IsEnabledNCR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_EXTMOD_Msk) == EPSC_NCR4_EXTMOD_Msk);
}

/**
  * @brief    Enable Wait Mode
  * @rmtoll   NCR4    WAITEN    FL_EPSC_EnableNCR4_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_WaitMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_WAITEN_Msk);
}

/**
  * @brief    Disable Wait Mode
  * @rmtoll   NCR4    WAITEN    FL_EPSC_DisableNCR4_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_WaitMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_WAITEN_Msk);
}

/**
  * @brief    Get Wait Mode Status
  * @rmtoll   NCR4    WAITEN    FL_EPSC_IsEnabledNCR4_WaitMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_WaitMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_WAITEN_Msk) == EPSC_NCR4_WAITEN_Msk);
}

/**
  * @brief    Enable Write Mode
  * @rmtoll   NCR4    WREN    FL_EPSC_EnableNCR4_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_WriteMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_WREN_Msk);
}

/**
  * @brief    Disable Write Mode
  * @rmtoll   NCR4    WREN    FL_EPSC_DisableNCR4_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_WriteMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_WREN_Msk);
}

/**
  * @brief    Get Write Mode Status
  * @rmtoll   NCR4    WREN    FL_EPSC_IsEnabledNCR4_WriteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_WriteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_WREN_Msk) == EPSC_NCR4_WREN_Msk);
}

/**
  * @brief    Set Wait Timing Mode
  * @rmtoll   NCR4    WAITCFG    FL_EPSC_SetNCR4_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR4_WaitTimingMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NCR4, EPSC_NCR4_WAITCFG_Msk, mode);
}

/**
  * @brief    Get Wait Timing Mode
  * @rmtoll   NCR4    WAITCFG    FL_EPSC_GetNCR4_WaitTimingMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_BEFORE
  *           @arg @ref FL_EPSC_NCR_ACTIVE_STATE_DURING
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR4_WaitTimingMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_WAITCFG_Msk));
}

/**
  * @brief    Set Wait Polarity
  * @rmtoll   NCR4    WAITPOL    FL_EPSC_SetNCR4_WaitPolarity
  * @param    EPSCx EPSC instance
  * @param    polarity This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR4_WaitPolarity(EPSC_Type *EPSCx, uint32_t polarity)
{
    MODIFY_REG(EPSCx->NCR4, EPSC_NCR4_WAITPOL_Msk, polarity);
}

/**
  * @brief    Get Wait Polarity
  * @rmtoll   NCR4    WAITPOL    FL_EPSC_GetNCR4_WaitPolarity
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_POLARITY_LOW
  *           @arg @ref FL_EPSC_NCR_POLARITY_HIGH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR4_WaitPolarity(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_WAITPOL_Msk));
}

/**
  * @brief    Enable Burst Mode
  * @rmtoll   NCR4    BURSTEN    FL_EPSC_EnableNCR4_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_BurstMode(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_BURSTEN_Msk);
}

/**
  * @brief    Disable Burst Mode
  * @rmtoll   NCR4    BURSTEN    FL_EPSC_DisableNCR4_BurstMode
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_BurstMode(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_BURSTEN_Msk);
}

/**
  * @brief    Get Burst Mode Status
  * @rmtoll   NCR4    BURSTEN    FL_EPSC_IsEnabledNCR4_BursteMode
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_BursteMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_BURSTEN_Msk) == EPSC_NCR4_BURSTEN_Msk);
}

/**
  * @brief    Set Memory Bus Width
  * @rmtoll   NCR4    MWID    FL_EPSC_SetNCR4_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @param    width This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR4_MemoryBusWidth(EPSC_Type *EPSCx, uint32_t width)
{
    MODIFY_REG(EPSCx->NCR4, EPSC_NCR4_MWID_Msk, width);
}

/**
  * @brief    Get Memory Bus Width
  * @rmtoll   NCR4    MWID    FL_EPSC_GetNCR4_MemoryBusWidth
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_8B
  *           @arg @ref FL_EPSC_NCR_MEMORY_WIDTH_16B
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR4_MemoryBusWidth(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_MWID_Msk));
}

/**
  * @brief    Set Memory Type
  * @rmtoll   NCR4    MTYP    FL_EPSC_SetNCR4_MemoryType
  * @param    EPSCx EPSC instance
  * @param    memorytype This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNCR4_MemoryType(EPSC_Type *EPSCx, uint32_t memorytype)
{
    MODIFY_REG(EPSCx->NCR4, EPSC_NCR4_MTYP_Msk, memorytype);
}

/**
  * @brief    Get Memory Type
  * @rmtoll   NCR4    MTYP    FL_EPSC_GetNCR4_MemoryType
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_SRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_PSRAM
  *           @arg @ref FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNCR4_MemoryType(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_MTYP_Msk));
}

/**
  * @brief    Enable Data Address Multiplex
  * @rmtoll   NCR4    MUXEN    FL_EPSC_EnableNCR4_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_DataAddressMux(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_MUXEN_Msk);
}

/**
  * @brief    Disable Burst ModeData Address Multiplex
  * @rmtoll   NCR4    MUXEN    FL_EPSC_DisableNCR4_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_DataAddressMux(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_MUXEN_Msk);
}

/**
  * @brief    Get Data Address Multiplex  Status
  * @rmtoll   NCR4    MUXEN    FL_EPSC_IsEnabledNCR4_DataAddressMux
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_DataAddressMux(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_MUXEN_Msk) == EPSC_NCR4_MUXEN_Msk);
}

/**
  * @brief    Enable Memory Bank
  * @rmtoll   NCR4    MBKEN    FL_EPSC_EnableNCR4_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableNCR4_MemoryBank(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->NCR4, EPSC_NCR4_MBKEN_Msk);
}

/**
  * @brief    Disable Memory Bank
  * @rmtoll   NCR4    MBKEN    FL_EPSC_DisableNCR4_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_DisableNCR4_MemoryBank(EPSC_Type *EPSCx)
{
    CLEAR_BIT(EPSCx->NCR4, EPSC_NCR4_MBKEN_Msk);
}

/**
  * @brief    Get Memory Bank Status
  * @rmtoll   NCR4    MBKEN    FL_EPSC_IsEnabledNCR4_MemoryBank
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledNCR4_MemoryBank(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NCR4, EPSC_NCR4_MBKEN_Msk) == EPSC_NCR4_MBKEN_Msk);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NTR4    ACCMOD    FL_EPSC_SetNTR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR4_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NTR4, EPSC_NTR4_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NTR4    ACCMOD    FL_EPSC_GetNTR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR4_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, EPSC_NTR4_ACCMOD_Msk));
}

/**
  * @brief    Set Data Latency Cycle
  * @rmtoll   NTR4    DATLAT    FL_EPSC_SetNTR4_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR4_DataLatencyCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR4, EPSC_NTR4_DATLAT_Msk, cyclce);
}

/**
  * @brief    Read Data Latency Cycle
  * @rmtoll   NTR4    DATLAT    FL_EPSC_GetNTR4_DataLatencyCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_2CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_3CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_4CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_5CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_6CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_7CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_8CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_9CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_10CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_11CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_12CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_13CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_14CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_15CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_16CLK
  *           @arg @ref FL_EPSC_NTR_DATA_LATENCY_17CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR4_DataLatencyCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, EPSC_NTR4_DATLAT_Msk));
}

/**
  * @brief    Set Clk Perscale
  * @rmtoll   NTR4    CLKDIV    FL_EPSC_SetNTR4_ClkPerscale
  * @param    EPSCx EPSC instance
  * @param    Perscale This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR4_ClkPerscale(EPSC_Type *EPSCx, uint32_t Perscale)
{
    MODIFY_REG(EPSCx->NTR4, EPSC_NTR4_CLKDIV_Msk, Perscale);
}

/**
  * @brief    Read Clk Perscale
  * @rmtoll   NTR4    CLKDIV    FL_EPSC_GetNTR4_ClkPerscale
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_CLK_DIV2
  *           @arg @ref FL_EPSC_NTR_CLK_DIV3
  *           @arg @ref FL_EPSC_NTR_CLK_DIV4
  *           @arg @ref FL_EPSC_NTR_CLK_DIV5
  *           @arg @ref FL_EPSC_NTR_CLK_DIV6
  *           @arg @ref FL_EPSC_NTR_CLK_DIV7
  *           @arg @ref FL_EPSC_NTR_CLK_DIV8
  *           @arg @ref FL_EPSC_NTR_CLK_DIV9
  *           @arg @ref FL_EPSC_NTR_CLK_DIV10
  *           @arg @ref FL_EPSC_NTR_CLK_DIV11
  *           @arg @ref FL_EPSC_NTR_CLK_DIV12
  *           @arg @ref FL_EPSC_NTR_CLK_DIV13
  *           @arg @ref FL_EPSC_NTR_CLK_DIV14
  *           @arg @ref FL_EPSC_NTR_CLK_DIV15
  *           @arg @ref FL_EPSC_NTR_CLK_DIV16
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR4_ClkPerscale(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, EPSC_NTR4_CLKDIV_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NTR4    BUSTURN    FL_EPSC_SetNTR4_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNTR4_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NTR4, EPSC_NTR4_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NTR4    BUSTURN    FL_EPSC_GetNTR4_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNTR4_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, EPSC_NTR4_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NTR4    DATAST    FL_EPSC_WriteNTR4_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR4_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR4, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NTR4    DATAST    FL_EPSC_ReadNTR4_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR4_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NTR4    ADDHLD    FL_EPSC_WriteNTR4_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR4_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR4, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NTR4    ADDHLD    FL_EPSC_ReadNTR4_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR4_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NTR4    ADDSET    FL_EPSC_WriteNTR4_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNTR4_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NTR4, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NTR4    ADDSET    FL_EPSC_ReadNTR4_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNTR4_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NTR4, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Set Extended Mode
  * @rmtoll   NWTR4    ACCMOD    FL_EPSC_SetNWTR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @param    mode This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR4_ExtendedMode(EPSC_Type *EPSCx, uint32_t mode)
{
    MODIFY_REG(EPSCx->NWTR4, EPSC_NWTR4_ACCMOD_Msk, mode);
}

/**
  * @brief    Read Extended Mode
  * @rmtoll   NWTR4    ACCMOD    FL_EPSC_GetNWTR4_ExtendedMode
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_A
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_B
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_C
  *           @arg @ref FL_EPSC_NWTR_EXTMOD_MODE_D
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR4_ExtendedMode(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR4, EPSC_NWTR4_ACCMOD_Msk));
}

/**
  * @brief    Set Bus Turnaround Cycle
  * @rmtoll   NWTR4    BUSTURN    FL_EPSC_SetNWTR4_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @param    cyclce This parameter can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_SetNWTR4_BusTurnaroundCycle(EPSC_Type *EPSCx, uint32_t cyclce)
{
    MODIFY_REG(EPSCx->NWTR4, EPSC_NWTR4_BUSTURN_Msk, cyclce);
}

/**
  * @brief    Read Bus Turnaround Cycle
  * @rmtoll   NWTR4    BUSTURN    FL_EPSC_GetNWTR4_BusTurnaroundCycle
  * @param    EPSCx EPSC instance
  * @retval   Returned value can be one of the following values:
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK
  *           @arg @ref FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK
  */
__STATIC_INLINE uint32_t FL_EPSC_GetNWTR4_BusTurnaroundCycle(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR4, EPSC_NWTR4_BUSTURN_Msk));
}

/**
  * @brief    Write Data State Value
  * @rmtoll   NWTR4    DATAST    FL_EPSC_WriteNWTR4_DataState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR4_DataState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR4, (0xffU << 8U), (clk << 8U));
}

/**
  * @brief    Get Data State Value
  * @rmtoll   NWTR4    DATAST    FL_EPSC_ReadNWTR4_DataState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR4_DataState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR4, (0xffU << 8U)) >> 8U);
}

/**
  * @brief    Write Address Hold State Value
  * @rmtoll   NWTR4    ADDHLD    FL_EPSC_WriteNWTR4_AddressHoldState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR4_AddressHoldState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR4, (0xfU << 4U), (clk << 4U));
}

/**
  * @brief    Get Address Hold State Value
  * @rmtoll   NWTR4    ADDHLD    FL_EPSC_ReadNWTR4_AddressHoldState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR4_AddressHoldState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR4, (0xfU << 4U)) >> 4U);
}

/**
  * @brief    Write Address Set State Value
  * @rmtoll   NWTR4    ADDSET    FL_EPSC_WriteNWTR4_AddressSetState
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteNWTR4_AddressSetState(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->NWTR4, (0xfU << 0U), (clk << 0U));
}

/**
  * @brief    Get Address Set State Value
  * @rmtoll   NWTR4    ADDSET    FL_EPSC_ReadNWTR4_AddressSetState
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadNWTR4_AddressSetState(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->NWTR4, (0xfU << 0U)) >> 0U);
}

/**
  * @brief    Clear FIFO FULL Flag
  * @rmtoll   ISR    FULL    FL_EPSC_ClearFlag_FIFOFull
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_FIFOFull(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_FULL_Msk);
}

/**
  * @brief    Get FIFO FULL Flag
  * @rmtoll   ISR    FULL    FL_EPSC_IsActiveFlag_FIFOFull
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_FIFOFull(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_FULL_Msk) == (EPSC_ISR_FULL_Msk));
}

/**
  * @brief    Clear FIFO Half FULL Flag
  * @rmtoll   ISR    HALF_FULL    FL_EPSC_ClearFlag_FIFOHalfFull
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_FIFOHalfFull(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_HALF_FULL_Msk);
}

/**
  * @brief    Get FIFO Half FULL Flag
  * @rmtoll   ISR    HALF_FULL    FL_EPSC_IsActiveFlag_FIFOHalfFull
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_FIFOHalfFull(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_HALF_FULL_Msk) == (EPSC_ISR_HALF_FULL_Msk));
}

/**
  * @brief    Clear Transfer Completed Flag
  * @rmtoll   ISR    TCF    FL_EPSC_ClearFlag_TransferCompleted
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_TransferCompleted(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_TCF_Msk);
}

/**
  * @brief    Get Transfer Completed Flag
  * @rmtoll   ISR    TCF    FL_EPSC_IsActiveFlag_TransferCompleted
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_TransferCompleted(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_TCF_Msk) == (EPSC_ISR_TCF_Msk));
}

/**
  * @brief    Clear Transfer Error Flag
  * @rmtoll   ISR    TEF    FL_EPSC_ClearFlag_TransferError
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_TransferError(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_TEF_Msk);
}

/**
  * @brief    Get Transfer Error Flag
  * @rmtoll   ISR    TEF    FL_EPSC_IsActiveFlag_TransferError
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_TransferError(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_TEF_Msk) == (EPSC_ISR_TEF_Msk));
}

/**
  * @brief    Get Transfer Busy Flag
  * @rmtoll   ISR    BUSY    FL_EPSC_IsActiveFlag_Busy
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_Busy(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_BUSY_Msk) == (EPSC_ISR_BUSY_Msk));
}

/**
  * @brief    Clear Timeout Flag
  * @rmtoll   ISR    TOF    FL_EPSC_ClearFlag_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_Timeout(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_TOF_Msk);
}

/**
  * @brief    Get Timeout Flag
  * @rmtoll   ISR    TOF    FL_EPSC_IsActiveFlag_Timeout
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_Timeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_TOF_Msk) == (EPSC_ISR_TOF_Msk));
}

/**
  * @brief    Clear NE Rise Edge Flag
  * @rmtoll   ISR    NER    FL_EPSC_ClearFlag_NERiseEdge
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_NERiseEdge(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_NER_Msk);
}

/**
  * @brief    Get NE Rise Edge  Flag
  * @rmtoll   ISR    NER    FL_EPSC_IsActiveFlag_NERiseEdge
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_NERiseEdge(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_NER_Msk) == (EPSC_ISR_NER_Msk));
}

/**
  * @brief    Clear NE Fall Edge Flag
  * @rmtoll   ISR    NEF    FL_EPSC_ClearFlag_NEFallEdge
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_NEFallEdge(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_NEF_Msk);
}

/**
  * @brief    Get NE Fall Edge Flag
  * @rmtoll   ISR    NEF    FL_EPSC_IsActiveFlag_NEFallEdge
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_NEFallEdge(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_NEF_Msk) == (EPSC_ISR_NEF_Msk));
}

/**
  * @brief    Clear FIFO Empty Flag
  * @rmtoll   ISR    FEMPT    FL_EPSC_ClearFlag_FIFOEmpty
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_ClearFlag_FIFOEmpty(EPSC_Type *EPSCx)
{
    WRITE_REG(EPSCx->ISR, EPSC_ISR_FEMPT_Msk);
}

/**
  * @brief    Get FIFO Empty Flag
  * @rmtoll   ISR    FEMPT    FL_EPSC_IsActiveFlag_FIFOEmpty
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsActiveFlag_FIFOEmpty(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->ISR, EPSC_ISR_FEMPT_Msk) == (EPSC_ISR_FEMPT_Msk));
}

/**
  * @brief    Enable FIFO FULL interrupt
  * @note     ADC
  * @rmtoll   IER    FFIE    FL_EPSC_EnableIT_FIFOFull
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_FIFOFull(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_FFIE_Msk);
}

/**
  * @brief    Get FIFO FULL interrupt Status
  * @note     ADC
  * @rmtoll   IER    FFIE    FL_EPSC_IsEnabledIT_FIFOFull
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_FIFOFull(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_FFIE_Msk) == EPSC_IER_FFIE_Msk);
}

/**
  * @brief    Enable FIFO Half FULL interrupt
  * @note     ADC
  * @rmtoll   IER    FHFIE    FL_EPSC_EnableIT_FIFOHalfFull
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_FIFOHalfFull(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_FHFIE_Msk);
}

/**
  * @brief    Get FIFO Half FULL interrupt Status
  * @note     ADC
  * @rmtoll   IER    FHFIE    FL_EPSC_IsEnabledIT_FIFOHalfFull
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_FIFOHalfFull(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_FHFIE_Msk) == EPSC_IER_FHFIE_Msk);
}

/**
  * @brief    Enable Transfer Completed interrupt
  * @note     ADC
  * @rmtoll   IER    TCIE    FL_EPSC_EnableIT_TransferCompleted
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_TransferCompleted(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_TCIE_Msk);
}

/**
  * @brief    Get Transfer Completed  interrupt Status
  * @note     ADC
  * @rmtoll   IER    TCIE    FL_EPSC_IsEnabledIT_TransferCompleted
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_TransferCompleted(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_TCIE_Msk) == EPSC_IER_TCIE_Msk);
}

/**
  * @brief    Enable Transfer Error  interrupt
  * @note     ADC
  * @rmtoll   IER    TEIE    FL_EPSC_EnableIT_TransferError
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_TransferError(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_TEIE_Msk);
}

/**
  * @brief    Get Transfer Error t Status
  * @note     ADC
  * @rmtoll   IER    TEIE    FL_EPSC_IsEnabledIT_TransferError
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_TransferError(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_TEIE_Msk) == EPSC_IER_TEIE_Msk);
}

/**
  * @brief    Enable Timeout interrupt
  * @note     ADC
  * @rmtoll   IER    TOIE    FL_EPSC_EnableIT_Timeout
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_Timeout(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_TOIE_Msk);
}

/**
  * @brief    Get Timeout interrupt Status
  * @note     ADC
  * @rmtoll   IER    TOIE    FL_EPSC_IsEnabledIT_Timeout
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_Timeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_TOIE_Msk) == EPSC_IER_TOIE_Msk);
}

/**
  * @brief    Enable NE Rise Edge interrupt
  * @note     ADC
  * @rmtoll   IER    NERIE    FL_EPSC_EnableIT_NERiseEdge
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_NERiseEdge(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_NERIE_Msk);
}

/**
  * @brief    Get NE Rise Edge interrupt Status
  * @note     ADC
  * @rmtoll   IER    NERIE    FL_EPSC_IsEnabledIT_NERiseEdge
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_NERiseEdge(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_NERIE_Msk) == EPSC_IER_NERIE_Msk);
}

/**
  * @brief    Enable NE Fall Edge interrupt
  * @note     ADC
  * @rmtoll   IER    NEFIE    FL_EPSC_EnableIT_NEFallEdge
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_NEFallEdge(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_NEFIE_Msk);
}

/**
  * @brief    Get NE Fall Edge interrupt Status
  * @note     ADC
  * @rmtoll   IER    NEFIE    FL_EPSC_IsEnabledIT_NEFallEdge
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_NEFallEdge(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_NEFIE_Msk) == EPSC_IER_NEFIE_Msk);
}

/**
  * @brief    Enable FIFO Empty interrupt
  * @note     ADC
  * @rmtoll   IER    FEIE    FL_EPSC_EnableIT_FIFOEmpty
  * @param    EPSCx EPSC instance
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_EnableIT_FIFOEmpty(EPSC_Type *EPSCx)
{
    SET_BIT(EPSCx->IER, EPSC_IER_FEIE_Msk);
}

/**
  * @brief    Get FIFO Empty interrupt Status
  * @note     ADC
  * @rmtoll   IER    FEIE    FL_EPSC_IsEnabledIT_FIFOEmpty
  * @param    EPSCx EPSC instance
  * @retval   State of bit (1 or 0).
  */
__STATIC_INLINE uint32_t FL_EPSC_IsEnabledIT_FIFOEmpty(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->IER, EPSC_IER_FEIE_Msk) == EPSC_IER_FEIE_Msk);
}

/**
  * @brief    Write Timeout Value
  * @rmtoll   TOR    TO    FL_EPSC_WriteTimeout
  * @param    EPSCx EPSC instance
  * @param    clk
  * @retval   None
  */
__STATIC_INLINE void FL_EPSC_WriteTimeout(EPSC_Type *EPSCx, uint32_t clk)
{
    MODIFY_REG(EPSCx->TOR, (0xffffU << 0U), (clk << 0U));
}

/**
  * @brief    Get Timeoute Value
  * @rmtoll   TOR    TO    FL_EPSC_ReadTimeout
  * @param    EPSCx EPSC instance
  * @retval
  */
__STATIC_INLINE uint32_t FL_EPSC_ReadTimeout(EPSC_Type *EPSCx)
{
    return (uint32_t)(READ_BIT(EPSCx->TOR, (0xffffU << 0U)) >> 0U);
}

/**
  * @}
  */

/** @defgroup EPSC_FL_EF_Init Initialization and de-initialization functions
  * @{
  */
extern FL_ErrorStatus FL_EPSC_NORSRAM_Init(EPSC_Type *EPSCx, EPSC_NORSRAM_InitTypeDef  *EPSC_InitStruct);

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __FM33FK5XX_FL_EPSC_H*/

/*************************Py_Code_Generator Version: 0.1-0.14-0.1 @ 2023-08-25*************************/
/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
