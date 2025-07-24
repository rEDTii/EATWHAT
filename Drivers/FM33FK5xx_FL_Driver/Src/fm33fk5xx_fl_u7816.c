/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_u7816.c
  * @author  FMSH Application Team
  * @brief   Src file of U7816 FL Module
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

/** @addtogroup U7816
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup U7816_FL_Private_Macros
  * @{
  */
#define         IS_UART_INSTANCE(INSTANCE)              (((INSTANCE) == UART4)||\
                                                         ((INSTANCE) == UART5)||\
                                                         ((INSTANCE) == UART6)||\
                                                         ((INSTANCE) == UART7))

#define         IS_FL_U7816_CLOCK_FRQUENCE(__VALUE__)               (((__VALUE__) >=1000000)&&\
                                                                     ((__VALUE__) <= 5000000))

#define         IS_FL_U7816_TX_PARITHERROR_AUTO_RETRY(__VALUE__)    (((__VALUE__) == FL_DISABLE)||\
                                                                     ((__VALUE__) == FL_ENABLE))

#define         IS_FL_U7816_RETRY_CNT(__VALUE__)                    (((__VALUE__) == FL_UART_U7816_RETRY_COUNT_1)||\
                                                                     ((__VALUE__) == FL_UART_U7816_RETRY_COUNT_3))

#define         IS_FL_U7816_BLOCKGUARD(__VALUE__)                   (((__VALUE__) == FL_ENABLE)||\
                                                                     ((__VALUE__) == FL_DISABLE))

#define         IS_FL_U7816_PARITH(__VALUE__)                       (((__VALUE__) == FL_UART_U7816_PARITY_SEL_EVEN)||\
                                                                     ((__VALUE__) == FL_UART_U7816_PARITY_SEL_ODD )||\
                                                                     ((__VALUE__) == FL_UART_U7816_PARITY_SEL_ALWAYS_1)||\
                                                                     ((__VALUE__) == FL_UART_U7816_PARITY_SEL_NONE))

#define         IS_FL_U7816_RX_GUARD(__VALUE__)                     (((__VALUE__) == FL_UART_U7816_RX_GUARD_TIME_2ETU)||\
                                                                     ((__VALUE__) == FL_UART_U7816_RX_GUARD_TIME_1ETU))

#define         IS_FL_U7816_ERROR_GUARD(__VALUE__)                   (((__VALUE__) == FL_UART_U7816_ERROR_GUARD_TIME_2ETU)||\
                                                                      ((__VALUE__) == FL_UART_U7816_ERROR_GUARD_TIME_1ETU))

#define         IS_FL_U7816_ERROR_SIGNALWIDTH(__VALUE__)             (((__VALUE__) == FL_UART_U7816_ERROR_SIGNAL_WIDTH_2ETU)||\
                                                                      ((__VALUE__) == FL_UART_U7816_ERROR_SIGNAL_WIDTH_1P5ETU)||\
                                                                      ((__VALUE__) == FL_UART_U7816_ERROR_SIGNAL_WIDTH_1ETU))

#define         IS_FL_U7816_RX_AUTO_ERROR_SIG(__VALUE__)             (((__VALUE__) == FL_DISABLE)||\
                                                                      ((__VALUE__) == FL_ENABLE))

#define         IS_FL_U7816_BIT_DIRECTION(__VALUE__)                (((__VALUE__) == FL_UART_U7816_BIT_ORDER_LSB_FIRST)||\
                                                                     ((__VALUE__) == FL_UART_U7816_BIT_ORDER_MSB_FIRST))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup U7816_FL_Private_Functions U7816 Private Functions
  * @{
  */

/**
  * @}
  */

/** @addtogroup U7816_FL_EF_Init
  * @{
  */

/**
  * @brief  复位U7816 外设寄存器值为复位值
  * @param  外设入口地址
  * @retval 返回错误状态，可能值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 复位未成功
  */
FL_ErrorStatus FL_U7816_DeInit(UART_Type *UARTx)
{
    FL_ErrorStatus status = FL_PASS;
    /* 参数入口合法性 */
    assert_param(IS_UART_INSTANCE(UARTx));
    /*模式选择--UART*/
    FL_UART_SetMode(UARTx, FL_UART_MODESEL_UART);
    /* 外设复位使能 */
    FL_RMU_EnablePeripheralReset(RMU);
    if(UARTx == UART4)
    {
        /*复位UART*/
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART4);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART4);
        /* 总线、工作时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART4);
    }
    else if(UARTx == UART5)
    {
        /*复位UART*/
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART5);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART5);
        /* 总线、工作时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART5);
    }
    else if(UARTx == UART6)
    {
        /*复位UART*/
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART6);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART6);
        /* 总线、工作时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART6);
    }
    else if(UARTx == UART7)
    {
        /*复位UART*/
        FL_RMU_EnableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART7);
        FL_RMU_DisableResetAPBPeripheral(RMU, FL_RMU_RSTAPB_UART7);
        /* 总线（工作）时钟关闭 */
        FL_CMU_DisableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART7);
    }
    else
    {
        status = FL_FAIL;
    }
    /* 锁定外设复位功能 */
    FL_RMU_DisablePeripheralReset(RMU);
    return (status);
}

FL_ErrorStatus FL_U7816_Init(UART_Type *UARTx, FL_UART_U7816_InitTypeDef *U7816_InitStruct)
{
    uint32_t Fclk;
    uint32_t tempClkdiv;
    FL_ErrorStatus status = FL_FAIL;
    if(U7816_InitStruct != NULL)
    {
        /* 参数检查 */
        assert_param(IS_UART_INSTANCE(UARTx));
        assert_param(IS_FL_U7816_CLOCK_FRQUENCE(U7816_InitStruct->outputClockFreqence));
        assert_param(IS_FL_U7816_TX_PARITHERROR_AUTO_RETRY(U7816_InitStruct->txAutoRetry));
        assert_param(IS_FL_U7816_RETRY_CNT(U7816_InitStruct->retryCnt));
        assert_param(IS_FL_U7816_BLOCKGUARD(U7816_InitStruct->blockGuard));
        assert_param(IS_FL_U7816_PARITH(U7816_InitStruct->parity));
        assert_param(IS_FL_U7816_RX_GUARD(U7816_InitStruct->rxGuardTime));
        assert_param(IS_FL_U7816_ERROR_GUARD(U7816_InitStruct->errorGuardTime));
        assert_param(IS_FL_U7816_ERROR_SIGNALWIDTH(U7816_InitStruct->errorSignalWidth));
        assert_param(IS_FL_U7816_RX_AUTO_ERROR_SIG(U7816_InitStruct->rxAutoErrorSignal));
        assert_param(IS_FL_U7816_BIT_DIRECTION(U7816_InitStruct->transferOrder));
        /* 卡时钟 */
        Fclk = FL_CMU_GetAPB1ClockFreq();
        tempClkdiv = Fclk / U7816_InitStruct->outputClockFreqence - 1;
        /* 使能总线时钟*/
        if(UARTx == UART4)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART4);
        }
        else if(UARTx == UART5)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART5);
        }
        else if(UARTx == UART6)
        {
            FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART6);
        }
        else
        {
            if(UARTx == UART7)
            {
                FL_CMU_EnableGroup3BusClock(FL_CMU_GROUP3_BUSCLK_UART7);
            }
        }
        /* 设置工作时钟分频*/
        FL_UART_WriteU7816ClockDivision(UARTx, tempClkdiv);
        /* 发送收到error signal后自动重发 */
        if(U7816_InitStruct->txAutoRetry == FL_ENABLE)
        {
            FL_UART_EnableU7816TXParityErrorAutoRetry(UARTx);
        }
        else
        {
            FL_UART_DisableU7816TXParityErrorAutoRetry(UARTx);
        }
        /* 发送失败重试次数 */
        FL_UART_SetU7816RetryCount(UARTx, U7816_InitStruct->retryCnt);
        /*插入BGT */
        if(U7816_InitStruct->blockGuard == FL_ENABLE)
        {
            FL_UART_EnableU7816BlockGuardTime(UARTx);
        }
        else
        {
            FL_UART_DisableU7816BlockGuardTime(UARTx);
        }
        /* 校验位 */
        FL_UART_SetU7816Parity(UARTx, U7816_InitStruct->parity);
        /* 接收一次之间的保护时间单位etu */
        FL_UART_SetU7816RXGuardTime(UARTx, U7816_InitStruct->rxGuardTime);
        /* 错误之后的保护时间单位etu */
        FL_UART_SetU7816ErrorGuardTime(UARTx, U7816_InitStruct->errorGuardTime);
        /* 错误信号时间 单位etu */
        FL_UART_SetU7816ErrorSignalWidth(UARTx, U7816_InitStruct->errorSignalWidth);
        /* 接收校验错是否自动重发error signal */
        if(U7816_InitStruct->rxAutoErrorSignal == FL_ENABLE)
        {
            FL_UART_EnableU7816RXParityErrorAutoRetry(UARTx);
        }
        else
        {
            FL_UART_DisableU7816RXParityErrorAutoRetry(UARTx);
        }
        /* 传输bit方向 */
        FL_UART_SetU7816BitOrder(UARTx, U7816_InitStruct->transferOrder);
        /* baud */
        FL_UART_WriteBaudRate(UARTx, U7816_InitStruct->baud);
        /* 额外保护时间单位etu */
        FL_UART_WriteU7816ExtraGuardTime(UARTx, U7816_InitStruct->extraGuardTime);
        status = FL_PASS;
    }
    return status;
}

void FL_U7816_StructInit(FL_UART_U7816_InitTypeDef *U7816_InitStruct)
{
    if(U7816_InitStruct != NULL)
    {
        U7816_InitStruct->outputClockFreqence   = 4000000;
        U7816_InitStruct->txAutoRetry           = FL_ENABLE;
        U7816_InitStruct->retryCnt              = FL_UART_U7816_RETRY_COUNT_1;
        U7816_InitStruct->blockGuard            = FL_DISABLE;
        U7816_InitStruct->parity                = FL_UART_U7816_PARITY_SEL_EVEN;
        U7816_InitStruct->rxGuardTime           = FL_UART_U7816_RX_GUARD_TIME_2ETU;
        U7816_InitStruct->errorGuardTime        = FL_UART_U7816_ERROR_GUARD_TIME_1ETU;
        U7816_InitStruct->errorSignalWidth      = FL_UART_U7816_ERROR_SIGNAL_WIDTH_2ETU;
        U7816_InitStruct->rxAutoErrorSignal     = FL_ENABLE;
        U7816_InitStruct->transferOrder         = FL_UART_U7816_BIT_ORDER_LSB_FIRST;
        U7816_InitStruct->baud                  = 372 - 1;
        U7816_InitStruct->extraGuardTime        = 0;
    }
}
/**
  * @}
  */

/* Private function ----------------------------------------------------------*/
/** @defgroup U7816_FL_Private_Functions U7816 Private Functions
  * @{
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
