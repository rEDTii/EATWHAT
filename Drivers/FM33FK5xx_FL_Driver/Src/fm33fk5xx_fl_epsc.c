/**
  ****************************************************************************************************
  * @file    fm33fk5xx_fl_adc.c
  * @author  FMSH Application Team
  * @brief   Src file of EPSC FL Module
  ****************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
  * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
  * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
  * See the Mulan PSL v2 for more details.
  *
  ****************************************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fm33fk5xx_fl.h"

/** @addtogroup fm33fk5xx_FL_Driver
  * @{
  */

/** @addtogroup EPSC
  * @{
  */

#ifdef FL_EPSC_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup EPSC_FL_Private_Macros
  * @{
  */

#define         IS_FL_EPSC_INSTANCE(INSTANCE)                   ((INSTANCE) == EPSC)

#define         IS_FL_EPSC_NORSRAM_BANK(__VALUE__)              (((__VALUE__) == FL_EPSC_BANK1_NORSRAM1)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_BANK1_NORSRAM2)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_BANK1_NORSRAM3)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_BANK1_NORSRAM4))

#define         IS_FL_EPSC_MUX(__VALUE__)                       (((__VALUE__) == FL_DISABLE)||\
                                                                                                                                    ((__VALUE__) == FL_ENABLE))

#define         IS_FL_EPSC_MEMORY(__VALUE__)                    (((__VALUE__) == FL_EPSC_NCR_MEMORY_TYPE_SRAM)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NCR_MEMORY_TYPE_PSRAM)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NCR_MEMORY_TYPE_NOR_FLASH))

#define         IS_FL_EPSC_MEMORY_WIDTH(__VALUE__)              (((__VALUE__) == FL_EPSC_NCR_MEMORY_WIDTH_8B)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NCR_MEMORY_WIDTH_16B))

#define         IS_FL_EPSC_BURSTMODE(__VALUE__)                 (((__VALUE__) == FL_DISABLE)||\
                                                                  ((__VALUE__) == FL_ENABLE))

#define         IS_FL_EPSC_WRITE_BURST(__VALUE__)               (((__VALUE__) == FL_EPSC_NCR_SYNC_MODE_ASYNC)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NCR_SYNC_MODE_SYNC))

#define         IS_FL_EPSC_WAITE_SIGNAL(__VALUE__)              (((__VALUE__) == FL_DISABLE)||\
                                                                                                                                    ((__VALUE__) == FL_ENABLE))

#define         IS_FL_EPSC_ASYNWAIT(__VALUE__)                  (((__VALUE__) == FL_DISABLE)||\
                                                                  ((__VALUE__) == FL_ENABLE))

#define         IS_FL_EPSC_WAIT_POLARITY(__VALUE__)             (((__VALUE__) == FL_EPSC_NCR_POLARITY_LOW)||\
                                                                  ((__VALUE__) == FL_EPSC_NCR_POLARITY_HIGH))

#define         IS_FL_EPSC_WAIT_SIGNAL_ACTIVE(__VALUE__)        (((__VALUE__) == FL_EPSC_NCR_ACTIVE_STATE_BEFORE)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NCR_ACTIVE_STATE_DURING))

#define         IS_FL_EPSC_WRITE_OPERATION(__VALUE__)           (((__VALUE__) == FL_DISABLE)||\
                                                                  ((__VALUE__) == FL_ENABLE))

#define         IS_FL_EPSC_EXTENDED_MODE(__VALUE__)             (((__VALUE__) == FL_DISABLE)||\
                                                                  ((__VALUE__) == FL_ENABLE))

#define         IS_FL_EPSC_ADDRESS_SETUP_TIME(__VALUE__)        ((__VALUE__) <= 0xF)

#define         IS_FL_EPSC_ADDRESS_HOLD_TIME(__VALUE__)         (((__VALUE__) > 0) && ((__VALUE__) <= 0xF))

#define         IS_FL_EPSC_DATASETUP_TIME(__VALUE__)            (((__VALUE__) > 0) && ((__VALUE__) <= 0xFF))

#define         IS_FL_EPSC_NTR_TURNAROUND_TIME(__VALUE__)       (((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_0CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_1CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_2CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_3CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_4CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_5CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_6CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_7CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_8CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_9CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_10CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_11CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_12CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_13CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_14CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_BUS_TRUNAROUND_15CLK))

#define         IS_FL_EPSC_NTR_CLK_DIV(__VALUE__)                   (((__VALUE__) == FL_EPSC_NTR_CLK_DIV2)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV3)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV4)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV5)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV6)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV7)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV8)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV9)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV10)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV11)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV12)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV13)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV14)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV15)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_CLK_DIV16))

#define         IS_FL_EPSC_NTR_DATA_LATENCY(__VALUE__)          (((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_2CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_3CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_4CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_5CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_6CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_7CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_8CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_9CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_10CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_11CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_12CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_13CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_14CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_15CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_16CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_DATA_LATENCY_17CLK))

#define         IS_FL_EPSC_NTR_ACCESS_MODE(__VALUE__)           (((__VALUE__) == FL_EPSC_NTR_EXTMOD_MODE_A)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_EXTMOD_MODE_B)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_EXTMOD_MODE_C||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NTR_EXTMOD_MODE_D)))

#define         IS_FL_EPSC_NWTR_TURNAROUND_TIME(__VALUE__)      (((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_1CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_2CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_3CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_4CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_5CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_6CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_7CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_8CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_9CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_10CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_11CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_12CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_13CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_14CLK)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK))

#define         IS_FL_EPSC_NWTR_ACCESS_MODE(__VALUE__)          (((__VALUE__) == FL_EPSC_NWTR_EXTMOD_MODE_A)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_EXTMOD_MODE_B)||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_EXTMOD_MODE_C||\
                                                                                                                                    ((__VALUE__) == FL_EPSC_NWTR_EXTMOD_MODE_D)))
/**
  * @brief  恢复对应的EPSC入口地址寄存器为默认值
  *
  * @param  EPSCx  外设入口地址
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS EPSC配置成功
  */
FL_ErrorStatus  FL_EPSC_NORSRAM_DeInit(EPSC_Type *EPSCx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 入口合法性检查 */
    assert_param(IS_FL_EPSC_INSTANCE(EPSCx));
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_EPSC);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_EPSC);
    FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_EPSC);
    FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_EPSC);
    FL_RMU_DisablePeripheralReset(RMU);
    return status;
}
/**
  * @brief  初始化EPSCx指定的入口地址的外设寄存器
  *
  * @param  EPSCx  外设入口地址
  * @param  EPSC_InitStruct 指向一 @ref EPSC_NORSRAM_InitTypeDef 结构体，它包含指定EPSC外设的配置信息
  *
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS EPSC配置成功
  */
FL_ErrorStatus FL_EPSC_NORSRAM_Init(EPSC_Type *EPSCx, EPSC_NORSRAM_InitTypeDef  *EPSC_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;

    if(EPSC_InitStruct != NULL)
    {
        assert_param(IS_FL_EPSC_NORSRAM_BANK(EPSC_InitStruct->NSBank));
        assert_param(IS_FL_EPSC_MUX(EPSC_InitStruct->DataAddressMux));
        assert_param(IS_FL_EPSC_MEMORY(EPSC_InitStruct->MemoryType));
        assert_param(IS_FL_EPSC_MEMORY_WIDTH(EPSC_InitStruct->MemoryDataWidth));
        assert_param(IS_FL_EPSC_BURSTMODE(EPSC_InitStruct->BurstAccessMode));
        assert_param(IS_FL_EPSC_WRITE_BURST(EPSC_InitStruct->WriteBurst));
        assert_param(IS_FL_EPSC_WAITE_SIGNAL(EPSC_InitStruct->WaitSignal));
        assert_param(IS_FL_EPSC_ASYNWAIT(EPSC_InitStruct->AsynchronousWait));
        assert_param(IS_FL_EPSC_WAIT_POLARITY(EPSC_InitStruct->WaitSignalPolarity));
        assert_param(IS_FL_EPSC_WAIT_SIGNAL_ACTIVE(EPSC_InitStruct->WaitSignalActive));
        assert_param(IS_FL_EPSC_WRITE_OPERATION(EPSC_InitStruct->WriteOperation));
        assert_param(IS_FL_EPSC_EXTENDED_MODE(EPSC_InitStruct->ExtendedMode));
        assert_param(IS_FL_EPSC_ADDRESS_SETUP_TIME(EPSC_InitStruct->ReadWriteTimingStruct->AddressSetupTime));
        assert_param(IS_FL_EPSC_ADDRESS_HOLD_TIME(EPSC_InitStruct->ReadWriteTimingStruct->AddressHoldTime));
        assert_param(IS_FL_EPSC_DATASETUP_TIME(EPSC_InitStruct->ReadWriteTimingStruct->DataSetupTime));
        assert_param(IS_FL_EPSC_NTR_TURNAROUND_TIME(EPSC_InitStruct->ReadWriteTimingStruct->BusTurnAroundDuration));
        assert_param(IS_FL_EPSC_NTR_CLK_DIV(EPSC_InitStruct->ReadWriteTimingStruct->CLKDivision));
        assert_param(IS_FL_EPSC_NTR_DATA_LATENCY(EPSC_InitStruct->ReadWriteTimingStruct->DataLatency));
        assert_param(IS_FL_EPSC_NTR_ACCESS_MODE(EPSC_InitStruct->ReadWriteTimingStruct->AccessMode));

				
        FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_EPSC);
        switch(EPSC_InitStruct->NSBank)
        {
            case FL_EPSC_BANK1_NORSRAM1:
            {
                /*地址数据复用使能配置*/
                if(EPSC_InitStruct->DataAddressMux)
                {
                    FL_EPSC_EnableNCR1_DataAddressMux(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR1_DataAddressMux(EPSC);
                }
                /*存储器类型配置*/
                FL_EPSC_SetNCR1_MemoryType(EPSC, EPSC_InitStruct->MemoryType);
                /*存储器总线宽度配置*/
                FL_EPSC_SetNCR1_MemoryBusWidth(EPSC, EPSC_InitStruct->MemoryDataWidth);
                /*存储器突发模式使能配置*/
                if(EPSC_InitStruct->BurstAccessMode)
                {
                    FL_EPSC_EnableNCR1_BurstMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR1_BurstMode(EPSC);
                }
                /*burst模式写操作配置*/
                FL_EPSC_SetNCR1_writeBurstMode(EPSC, EPSC_InitStruct->WriteBurst);
                /*wait使能配置*/
                if(EPSC_InitStruct->WaitSignal)
                {
                    FL_EPSC_EnableNCR1_WaitMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR1_WaitMode(EPSC);
                }
                /*异步模式下wait配置*/
                if(EPSC_InitStruct->AsynchronousWait)
                {
                    FL_EPSC_EnableNCR1_AsynchronousWait(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR1_AsynchronousWait(EPSC);
                }
                /*wait模式信号配置*/
                FL_EPSC_SetNCR1_WaitPolarity(EPSC, EPSC_InitStruct->WaitSignalPolarity);
                /*wait时序配置*/
                FL_EPSC_SetNCR1_WaitTimingMode(EPSC, EPSC_InitStruct->WaitSignalActive);
                /*写操作配置*/
                if(EPSC_InitStruct->WriteOperation)
                {
                    FL_EPSC_EnableNCR1_WriteMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR1_WriteMode(EPSC);
                }
                /*扩展模式配置*/
                if(EPSC_InitStruct->ExtendedMode)
                {
                    FL_EPSC_EnableNCR1_ExtendedMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR1_ExtendedMode(EPSC);
                }
                /*地址建立时间配置*/
                FL_EPSC_WriteNTR1_AddressSetState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressSetupTime);
                /*地址保持时间配置*/
                FL_EPSC_WriteNTR1_AddressHoldState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressHoldTime);
                /*数据段长度配置*/
                FL_EPSC_WriteNTR1_DataState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataSetupTime);
                /*总线转空闲时间配置*/
                FL_EPSC_SetNTR1_BusTurnaroundCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->BusTurnAroundDuration);
                /*EPSC_CLK分频比配置*/
                FL_EPSC_SetNTR1_ClkPerscale(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->CLKDivision);
                /*同步存储器数据延迟配置*/
                FL_EPSC_SetNTR1_DataLatencyCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataLatency);
                /*扩展模式选择配置*/
                FL_EPSC_SetNTR1_ExtendedMode(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AccessMode);
                if(EPSC_InitStruct->ExtendedMode == FL_ENABLE)
                {
                    assert_param(IS_FL_EPSC_ADDRESS_SETUP_TIME(EPSC_InitStruct->WriteTimingStruct->AddressSetupTime));
                    assert_param(IS_FL_EPSC_ADDRESS_HOLD_TIME(EPSC_InitStruct->WriteTimingStruct->AddressHoldTime));
                    assert_param(IS_FL_EPSC_DATASETUP_TIME(EPSC_InitStruct->WriteTimingStruct->DataSetupTime));
                    assert_param(IS_FL_EPSC_NWTR_TURNAROUND_TIME(EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration));
                    assert_param(IS_FL_EPSC_NWTR_ACCESS_MODE(EPSC_InitStruct->WriteTimingStruct->AccessMode));
                    /*地址建立时间配置*/
                    FL_EPSC_WriteNWTR1_AddressSetState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressSetupTime);
                    /*地址保持时间配置*/
                    FL_EPSC_WriteNWTR1_AddressHoldState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressHoldTime);
                    /*数据段长度配置*/
                    FL_EPSC_WriteNWTR1_DataState(EPSC, EPSC_InitStruct->WriteTimingStruct->DataSetupTime);
                    /*总线转空闲时间配置*/
                    FL_EPSC_SetNWTR1_BusTurnaroundCycle(EPSC, EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration);
                    /*扩展模式选择配置*/
                    FL_EPSC_SetNWTR1_ExtendedMode(EPSC, EPSC_InitStruct->WriteTimingStruct->AccessMode);
                }
                FL_EPSC_EnableNCR1_MemoryBank(EPSC);
                status = FL_PASS;
                break;
            }
            case FL_EPSC_BANK1_NORSRAM2:
            {
                /*地址数据复用使能配置*/
                if(EPSC_InitStruct->DataAddressMux)
                {
                    FL_EPSC_EnableNCR2_DataAddressMux(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR2_DataAddressMux(EPSC);
                }
                /*存储器类型配置*/
                FL_EPSC_SetNCR2_MemoryType(EPSC, EPSC_InitStruct->MemoryType);
                /*存储器总线宽度配置*/
                FL_EPSC_SetNCR2_MemoryBusWidth(EPSC, EPSC_InitStruct->MemoryDataWidth);
                /*存储器突发模式使能配置*/
                if(EPSC_InitStruct->BurstAccessMode)
                {
                    FL_EPSC_EnableNCR2_BurstMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR2_BurstMode(EPSC);
                }
                /*burst模式写操作配置*/
                FL_EPSC_SetNCR2_writeBurstMode(EPSC, EPSC_InitStruct->WriteBurst);
                /*wait使能配置*/
                if(EPSC_InitStruct->WaitSignal)
                {
                    FL_EPSC_EnableNCR2_WaitMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR2_WaitMode(EPSC);
                }
                /*异步模式下wait配置*/
                if(EPSC_InitStruct->AsynchronousWait)
                {
                    FL_EPSC_EnableNCR2_AsynchronousWait(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR2_AsynchronousWait(EPSC);
                }
                /*wait模式信号配置*/
                FL_EPSC_SetNCR2_WaitPolarity(EPSC, EPSC_InitStruct->WaitSignalPolarity);
                /*wait时序配置*/
                FL_EPSC_SetNCR2_WaitTimingMode(EPSC, EPSC_InitStruct->WaitSignalActive);
                /*写操作配置*/
                if(EPSC_InitStruct->WriteOperation)
                {
                    FL_EPSC_EnableNCR2_WriteMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR2_WriteMode(EPSC);
                }
                /*扩展模式配置*/
                if(EPSC_InitStruct->ExtendedMode)
                {
                    FL_EPSC_EnableNCR2_ExtendedMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR2_ExtendedMode(EPSC);
                }
                /*地址建立时间配置*/
                FL_EPSC_WriteNTR2_AddressSetState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressSetupTime);
                /*地址保持时间配置*/
                FL_EPSC_WriteNTR2_AddressHoldState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressHoldTime);
                /*数据段长度配置*/
                FL_EPSC_WriteNTR2_DataState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataSetupTime);
                /*总线转空闲时间配置*/
                FL_EPSC_SetNTR2_BusTurnaroundCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->BusTurnAroundDuration);
                /*EPSC_CLK分频比配置*/
                FL_EPSC_SetNTR2_ClkPerscale(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->CLKDivision);
                /*同步存储器数据延迟配置*/
                FL_EPSC_SetNTR2_DataLatencyCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataLatency);
                /*扩展模式选择配置*/
                FL_EPSC_SetNTR2_ExtendedMode(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AccessMode);
                if(EPSC_InitStruct->ExtendedMode == FL_ENABLE)
                {
                    assert_param(IS_FL_EPSC_ADDRESS_SETUP_TIME(EPSC_InitStruct->WriteTimingStruct->AddressSetupTime));
                    assert_param(IS_FL_EPSC_ADDRESS_HOLD_TIME(EPSC_InitStruct->WriteTimingStruct->AddressHoldTime));
                    assert_param(IS_FL_EPSC_DATASETUP_TIME(EPSC_InitStruct->WriteTimingStruct->DataSetupTime));
                    assert_param(IS_FL_EPSC_NWTR_TURNAROUND_TIME(EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration));
                    assert_param(IS_FL_EPSC_NWTR_ACCESS_MODE(EPSC_InitStruct->WriteTimingStruct->AccessMode));
                    /*地址建立时间配置*/
                    FL_EPSC_WriteNWTR2_AddressSetState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressSetupTime);
                    /*地址保持时间配置*/
                    FL_EPSC_WriteNWTR2_AddressHoldState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressHoldTime);
                    /*数据段长度配置*/
                    FL_EPSC_WriteNWTR2_DataState(EPSC, EPSC_InitStruct->WriteTimingStruct->DataSetupTime);
                    /*总线转空闲时间配置*/
                    FL_EPSC_SetNWTR2_BusTurnaroundCycle(EPSC, EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration);
                    /*扩展模式选择配置*/
                    FL_EPSC_SetNWTR2_ExtendedMode(EPSC, EPSC_InitStruct->WriteTimingStruct->AccessMode);
                }
                FL_EPSC_EnableNCR2_MemoryBank(EPSC);
                status = FL_PASS;
                break;
            }
            case FL_EPSC_BANK1_NORSRAM3:
            {
                /*地址数据复用使能配置*/
                if(EPSC_InitStruct->DataAddressMux)
                {
                    FL_EPSC_EnableNCR3_DataAddressMux(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR3_DataAddressMux(EPSC);
                }
                /*存储器类型配置*/
                FL_EPSC_SetNCR3_MemoryType(EPSC, EPSC_InitStruct->MemoryType);
                /*存储器总线宽度配置*/
                FL_EPSC_SetNCR3_MemoryBusWidth(EPSC, EPSC_InitStruct->MemoryDataWidth);
                /*存储器突发模式使能配置*/
                if(EPSC_InitStruct->BurstAccessMode)
                {
                    FL_EPSC_EnableNCR3_BurstMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR3_BurstMode(EPSC);
                }
                /*burst模式写操作配置*/
                FL_EPSC_SetNCR3_writeBurstMode(EPSC, EPSC_InitStruct->WriteBurst);
                /*wait使能配置*/
                if(EPSC_InitStruct->WaitSignal)
                {
                    FL_EPSC_EnableNCR3_WaitMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR3_WaitMode(EPSC);
                }
                /*异步模式下wait配置*/
                if(EPSC_InitStruct->AsynchronousWait)
                {
                    FL_EPSC_EnableNCR3_AsynchronousWait(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR3_AsynchronousWait(EPSC);
                }
                /*wait模式信号配置*/
                FL_EPSC_SetNCR3_WaitPolarity(EPSC, EPSC_InitStruct->WaitSignalPolarity);
                /*wait时序配置*/
                FL_EPSC_SetNCR3_WaitTimingMode(EPSC, EPSC_InitStruct->WaitSignalActive);
                /*写操作配置*/
                if(EPSC_InitStruct->WriteOperation)
                {
                    FL_EPSC_EnableNCR3_WriteMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR3_WriteMode(EPSC);
                }
                /*扩展模式配置*/
                if(EPSC_InitStruct->ExtendedMode)
                {
                    FL_EPSC_EnableNCR3_ExtendedMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR3_ExtendedMode(EPSC);
                }
                /*地址建立时间配置*/
                FL_EPSC_WriteNTR3_AddressSetState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressSetupTime);
                /*地址保持时间配置*/
                FL_EPSC_WriteNTR3_AddressHoldState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressHoldTime);
                /*数据段长度配置*/
                FL_EPSC_WriteNTR3_DataState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataSetupTime);
                /*总线转空闲时间配置*/
                FL_EPSC_SetNTR3_BusTurnaroundCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->BusTurnAroundDuration);
                /*EPSC_CLK分频比配置*/
                FL_EPSC_SetNTR3_ClkPerscale(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->CLKDivision);
                /*同步存储器数据延迟配置*/
                FL_EPSC_SetNTR3_DataLatencyCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataLatency);
                /*扩展模式选择配置*/
                FL_EPSC_SetNTR3_ExtendedMode(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AccessMode);
                if(EPSC_InitStruct->ExtendedMode == FL_ENABLE)
                {
                    assert_param(IS_FL_EPSC_ADDRESS_SETUP_TIME(EPSC_InitStruct->WriteTimingStruct->AddressSetupTime));
                    assert_param(IS_FL_EPSC_ADDRESS_HOLD_TIME(EPSC_InitStruct->WriteTimingStruct->AddressHoldTime));
                    assert_param(IS_FL_EPSC_DATASETUP_TIME(EPSC_InitStruct->WriteTimingStruct->DataSetupTime));
                    assert_param(IS_FL_EPSC_NWTR_TURNAROUND_TIME(EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration));
                    assert_param(IS_FL_EPSC_NWTR_ACCESS_MODE(EPSC_InitStruct->WriteTimingStruct->AccessMode));
                    /*地址建立时间配置*/
                    FL_EPSC_WriteNWTR3_AddressSetState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressSetupTime);
                    /*地址保持时间配置*/
                    FL_EPSC_WriteNWTR3_AddressHoldState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressHoldTime);
                    /*数据段长度配置*/
                    FL_EPSC_WriteNWTR3_DataState(EPSC, EPSC_InitStruct->WriteTimingStruct->DataSetupTime);
                    /*总线转空闲时间配置*/
                    FL_EPSC_SetNWTR3_BusTurnaroundCycle(EPSC, EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration);
                    /*扩展模式选择配置*/
                    FL_EPSC_SetNWTR3_ExtendedMode(EPSC, EPSC_InitStruct->WriteTimingStruct->AccessMode);
                }
                FL_EPSC_EnableNCR3_MemoryBank(EPSC);
                status = FL_PASS;
                break;
            }
            case FL_EPSC_BANK1_NORSRAM4:
            {
                /*地址数据复用使能配置*/
                if(EPSC_InitStruct->DataAddressMux)
                {
                    FL_EPSC_EnableNCR4_DataAddressMux(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR4_DataAddressMux(EPSC);
                }
                /*存储器类型配置*/
                FL_EPSC_SetNCR4_MemoryType(EPSC, EPSC_InitStruct->MemoryType);
                /*存储器总线宽度配置*/
                FL_EPSC_SetNCR4_MemoryBusWidth(EPSC, EPSC_InitStruct->MemoryDataWidth);
                /*存储器突发模式使能配置*/
                if(EPSC_InitStruct->BurstAccessMode)
                {
                    FL_EPSC_EnableNCR4_BurstMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR4_BurstMode(EPSC);
                }
                /*burst模式写操作配置*/
                FL_EPSC_SetNCR4_writeBurstMode(EPSC, EPSC_InitStruct->WriteBurst);
                /*wait使能配置*/
                if(EPSC_InitStruct->WaitSignal)
                {
                    FL_EPSC_EnableNCR4_WaitMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR4_WaitMode(EPSC);
                }
                /*异步模式下wait配置*/
                if(EPSC_InitStruct->AsynchronousWait)
                {
                    FL_EPSC_EnableNCR4_AsynchronousWait(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR4_AsynchronousWait(EPSC);
                }
                /*wait模式信号配置*/
                FL_EPSC_SetNCR4_WaitPolarity(EPSC, EPSC_InitStruct->WaitSignalPolarity);
                /*wait时序配置*/
                FL_EPSC_SetNCR4_WaitTimingMode(EPSC, EPSC_InitStruct->WaitSignalActive);
                /*写操作配置*/
                if(EPSC_InitStruct->WriteOperation)
                {
                    FL_EPSC_EnableNCR4_WriteMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR4_WriteMode(EPSC);
                }
                /*扩展模式配置*/
                if(EPSC_InitStruct->ExtendedMode)
                {
                    FL_EPSC_EnableNCR4_ExtendedMode(EPSC);
                }
                else
                {
                    FL_EPSC_DisableNCR4_ExtendedMode(EPSC);
                }
                /*地址建立时间配置*/
                FL_EPSC_WriteNTR4_AddressSetState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressSetupTime);
                /*地址保持时间配置*/
                FL_EPSC_WriteNTR4_AddressHoldState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AddressHoldTime);
                /*数据段长度配置*/
                FL_EPSC_WriteNTR4_DataState(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataSetupTime);
                /*总线转空闲时间配置*/
                FL_EPSC_SetNTR4_BusTurnaroundCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->BusTurnAroundDuration);
                /*EPSC_CLK分频比配置*/
                FL_EPSC_SetNTR4_ClkPerscale(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->CLKDivision);
                /*同步存储器数据延迟配置*/
                FL_EPSC_SetNTR4_DataLatencyCycle(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->DataLatency);
                /*扩展模式选择配置*/
                FL_EPSC_SetNTR4_ExtendedMode(EPSC, EPSC_InitStruct->ReadWriteTimingStruct->AccessMode);
                if(EPSC_InitStruct->ExtendedMode == FL_ENABLE)
                {
                    assert_param(IS_FL_EPSC_ADDRESS_SETUP_TIME(EPSC_InitStruct->WriteTimingStruct->AddressSetupTime));
                    assert_param(IS_FL_EPSC_ADDRESS_HOLD_TIME(EPSC_InitStruct->WriteTimingStruct->AddressHoldTime));
                    assert_param(IS_FL_EPSC_DATASETUP_TIME(EPSC_InitStruct->WriteTimingStruct->DataSetupTime));
                    assert_param(IS_FL_EPSC_NWTR_TURNAROUND_TIME(EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration));
                    assert_param(IS_FL_EPSC_NWTR_ACCESS_MODE(EPSC_InitStruct->WriteTimingStruct->AccessMode));
                    /*地址建立时间配置*/
                    FL_EPSC_WriteNWTR4_AddressSetState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressSetupTime);
                    /*地址保持时间配置*/
                    FL_EPSC_WriteNWTR4_AddressHoldState(EPSC, EPSC_InitStruct->WriteTimingStruct->AddressHoldTime);
                    /*数据段长度配置*/
                    FL_EPSC_WriteNWTR4_DataState(EPSC, EPSC_InitStruct->WriteTimingStruct->DataSetupTime);
                    /*总线转空闲时间配置*/
                    FL_EPSC_SetNWTR4_BusTurnaroundCycle(EPSC, EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration);
                    /*扩展模式选择配置*/
                    FL_EPSC_SetNWTR4_ExtendedMode(EPSC, EPSC_InitStruct->WriteTimingStruct->AccessMode);
                }
                FL_EPSC_EnableNCR4_MemoryBank(EPSC);
                status = FL_PASS;
                break;
            }
            default:
                status = FL_FAIL;
        }
    }

    return status;
}

/**
  * @brief  设置 EPSC_InitStruct 为默认配置
  * @param  EPSC_InitStruct 指向需要将值设置为默认配置的结构体 @ref EPSC_NORSRAM_InitTypeDef 结构体
  *
  * @retval None
  */
void FL_EPSC_NORSRAM_StructInit(EPSC_NORSRAM_InitTypeDef *EPSC_InitStruct)
{
    if(EPSC_InitStruct != NULL)
    {
        EPSC_InitStruct->NSBank = FL_EPSC_BANK1_NORSRAM4;
        EPSC_InitStruct->DataAddressMux = FL_DISABLE;
        EPSC_InitStruct->MemoryType = FL_EPSC_NCR_MEMORY_TYPE_SRAM;
        EPSC_InitStruct->MemoryDataWidth = FL_EPSC_NCR_MEMORY_WIDTH_16B;
        EPSC_InitStruct->BurstAccessMode = FL_DISABLE;
        EPSC_InitStruct->WriteBurst = FL_DISABLE;
        EPSC_InitStruct->WaitSignal = FL_DISABLE;
        EPSC_InitStruct->AsynchronousWait = FL_DISABLE;
        EPSC_InitStruct->WaitSignalPolarity = FL_EPSC_NCR_POLARITY_LOW;
        EPSC_InitStruct->WaitSignalActive = FL_EPSC_NCR_ACTIVE_STATE_BEFORE;
        EPSC_InitStruct->WriteOperation = FL_ENABLE;
        EPSC_InitStruct->ExtendedMode = FL_ENABLE;

        EPSC_InitStruct->ReadWriteTimingStruct->AddressSetupTime = 0xFF;
        EPSC_InitStruct->ReadWriteTimingStruct->AddressHoldTime = 0xFF;
        EPSC_InitStruct->ReadWriteTimingStruct->DataSetupTime = 0xFF;
        EPSC_InitStruct->ReadWriteTimingStruct->BusTurnAroundDuration = FL_EPSC_NTR_BUS_TRUNAROUND_15CLK;
        EPSC_InitStruct->ReadWriteTimingStruct->CLKDivision = FL_EPSC_NTR_CLK_DIV16;
        EPSC_InitStruct->ReadWriteTimingStruct->DataLatency = FL_EPSC_NTR_DATA_LATENCY_17CLK;
        EPSC_InitStruct->ReadWriteTimingStruct->AccessMode = FL_EPSC_NTR_EXTMOD_MODE_A;

        EPSC_InitStruct->WriteTimingStruct->AddressSetupTime = 0xFF;
        EPSC_InitStruct->WriteTimingStruct->AddressHoldTime = 0xFF;
        EPSC_InitStruct->WriteTimingStruct->DataSetupTime = 0xFF;
        EPSC_InitStruct->WriteTimingStruct->BusTurnAroundDuration = FL_EPSC_NWTR_BUS_TRUNAROUND_15CLK;
        EPSC_InitStruct->WriteTimingStruct->AccessMode = FL_EPSC_NWTR_EXTMOD_MODE_A;

    }
}

/**
  * @}
  */

#endif /* FL_EPSC_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
