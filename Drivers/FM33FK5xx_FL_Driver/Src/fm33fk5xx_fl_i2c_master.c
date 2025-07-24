/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_i2c_master.c
  * @author  FMSH Application Team
  * @brief   Src file of I2C FL Module
  *******************************************************************************************************
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
  *******************************************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "fm33fk5xx_fl.h"

/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */

/** @addtogroup I2C
  * @{
  */

#ifdef FL_I2C_MASTER_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup I2C_FL_Private_Macros
  * @{
  */

#define         IS_FL_I2C_INSTANCE(INSTANCE)                    (((INSTANCE) == I2C0)||\
                                                                 ((INSTANCE) == I2C1))

#define         IS_FL_I2C_BAUDRATE(__VALUE__)                   (((__VALUE__) > 0 )&&((__VALUE__) <= 1000000))

#define         IS_FL_I2C_MSATER_TIMEOUT(__VALUE__)             (((__VALUE__) == FL_IWDT_PERIOD_125MS)||\
                                                                 ((__VALUE__) == FL_IWDT_PERIOD_16000MS))

#define         IS_FL_I2C_ADDRSIZE10BIT(__VALUE__)              (((__VALUE__) == FL_ENABLE)||\
                                                                 ((__VALUE__) == FL_DISABLE))

/**
  * @}
  */

/** @addtogroup I2C_FL_EF_Init
  * @{
  */

/**
  * @brief  复位I2C外设.
  * @param  I2Cx 外设入口地址
  * @retval 错误状态，可能值：
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_I2C_DeInit(I2C_Type *I2Cx)
{
    assert_param(IS_FL_I2C_INSTANCE(I2Cx));
    /* 使能外设复位 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(I2Cx == I2C0)
    {
        /* 复位I2C0外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C0);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C0);
    }
    else if(I2Cx == I2C1)
    {
        /* 复位I2C1外设寄存器 */
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_I2C1);
    }
    else
    {
        FL_RMU_DisablePeripheralReset(RMU);
        return FL_FAIL;
    }
    return FL_PASS;
}

/**
  * @brief  配置I2C主机模式.
  * @param  I2Cx 外设入口地址
  * @param  I2C_InitStruct 指向 @ref FL_I2C_MasterMode_InitTypeDef 结构体的指针
  * @retval 错误状态，可能值：
  *         -FL_PASS 配置成功
  *         -FL_FAIL 配置过程发生错误
  */
FL_ErrorStatus FL_I2C_MasterMode_Init(I2C_Type *I2Cx, FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    uint32_t I2C_Clk_Freq = 0, BRG = 0;
    FL_ErrorStatus status = FL_FAIL;
    if(I2C_InitStruct != NULL)
    {
        assert_param(IS_FL_I2C_INSTANCE(I2Cx));
        assert_param(IS_FL_I2C_BAUDRATE(I2C_InitStruct->baudRate));
        /* 外设总线时钟开启 */
        if(I2Cx == I2C0)
        {
            /* 外设总线始时钟 */
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2C0);
        }
        else if(I2Cx == I2C1)
        {
            /* 外设总线始时钟 */
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_I2C1);
        }
        else
        {
            return FL_FAIL;
        }

        /* 获取时钟源速度 */
        I2C_Clk_Freq = FL_CMU_GetAPB1ClockFreq();
        /* 根据不同的时钟源速度计算出配置速率需要的寄存器值并配置相关寄存器 */
        BRG = (uint32_t)(I2C_Clk_Freq / (2 * I2C_InitStruct->baudRate)) - 1;
        FL_I2C_Master_WriteSCLHighWidth(I2Cx, BRG);
        FL_I2C_Master_WriteSCLLowWidth(I2Cx, BRG);
        FL_I2C_Master_WriteSDAHoldTime(I2Cx, (uint32_t)((BRG & 0x1FF) / 2));
        /* 使能外设 */
        FL_I2C_Master_Enable(I2Cx);
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  将 @ref FL_I2C_MasterMode_InitTypeDef 结构体初始化为默认配置
  * @param  I2C_InitStruct 指向 @ref FL_I2C_MasterMode_InitTypeDef 结构体的指针
  *
  * @retval None
  */
void FL_I2C_MasterMode_StructInit(FL_I2C_MasterMode_InitTypeDef *I2C_InitStruct)
{
    if(I2C_InitStruct != NULL)
    {
        I2C_InitStruct->baudRate = 40000;
    }
}

/**
  * @}
  */

#endif /* FL_I2C_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/********************** (C) COPYRIGHT Fudan Microelectronics **** END OF FILE ***********************/
