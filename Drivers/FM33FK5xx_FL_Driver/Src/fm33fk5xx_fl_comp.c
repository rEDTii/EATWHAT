/**
  ****************************************************************************************************
  * @file    fm33fk5xx_fl_comp.c
  * @author  FMSH Application Team
  * @brief   Src file of COMP FL Module
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

/** @addtogroup FM33FK5XX_FL_Driver
  * @{
  */

/** @addtogroup COMP
  * @{
  */

#ifdef FL_COMP_DRIVER_ENABLED
/* Private macros ------------------------------------------------------------*/
/** @addtogroup COMP_FL_Private_Macros
  * @{
  */
#define         IS_COMP_ALL_INSTANCE(INTENCE)              (((INTENCE) == COMP0)||\
                                                            ((INTENCE) == COMP1)||\
                                                            ((INTENCE) == COMP2))

#define         IS_FL_COMP_POSITIVEINPUT(__VALUE__)        (((__VALUE__) == FL_COMP_INP_SOURCE_INP1)||\
                                                            ((__VALUE__) == FL_COMP_INP_SOURCE_OPA_OUT))

#define         IS_FL_COMP_NEGATIVEINPUT(__VALUE__)        (((__VALUE__) == FL_COMP_INN_SOURCE_INN1)||\
                                                             ((__VALUE__) == FL_COMP_INN_SOURCE_DAC0_OUT2)||\
                                                             ((__VALUE__) == FL_COMP_INN_SOURCE_DAC1_OUT)||\
                                                             ((__VALUE__) == FL_COMP_INN_SOURCE_VREFP)||\
                                                             ((__VALUE__) == FL_COMP_INN_SOURCE_AVREF)||\
                                                             ((__VALUE__) == FL_COMP_INN_SOURCE_AVREF_DIV2))

#define         IS_FL_COMP_POLARITY(__VALUE__)             (((__VALUE__) == FL_COMP_OUTPUT_POLARITY_NORMAL)||\
                                                             ((__VALUE__) == FL_COMP_OUTPUT_POLARITY_INVERT))

#define         IS_FL_COMP_EDGE(__VALUE__)                 (((__VALUE__) == FL_COMP_INTERRUPT_EDGE_BOTH)||\
                                                            ((__VALUE__) == FL_COMP_INTERRUPT_EDGE_RISING )||\
                                                            ((__VALUE__) == FL_COMP_INTERRUPT_EDGE_FALLING))

#define         IS_FL_COMP_TRGOEDGE(__VALUE__)               (((__VALUE__) == FL_COMP_COMPX_TRGOSEL_EDGE_BOTH)||\
                                                            ((__VALUE__) == FL_COMP_COMPX_TRGOSEL_EDGE_RISING )||\
                                                            ((__VALUE__) == FL_COMP_COMPX_TRGOSEL_EDGE_FALLING))

#define         IS_FL_COMP_DIGITAL_FILTER(__VALUE__)       (((__VALUE__) == FL_DISABLE)||\
                                                            ((__VALUE__) == FL_ENABLE))

#define         IS_FL_COMP_DIGITAL_POWERMODE(__VALUE__)       (((__VALUE__) == FL_COMP_POWER_MODE_HIGH)||\
                                                            ((__VALUE__) == FL_COMP_POWER_MODE_LOW))

#define         IS_FL_COMP_DIGITAL_FILTER_LEN(__VALUE__)    (((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_3APBCLK)||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_4APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_5APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_6APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_7APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_8APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_9APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_10APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_11APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_12APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_13APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_14APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_15APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_16APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_17APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_18APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_19APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_20APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_21APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_22APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_23APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_24APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_25APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_26APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_27APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_28APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_29APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_30APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_31APBCLK )||\
                                                            ((__VALUE__) == FL_COMP_OUTPUT_FILTER_WINDOW_32APBCLK))
/**
  * @}
  */

/** @addtogroup COMP_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应COMP控制寄存器.
  * @param  COMPx COMP Port
  * @retval ErrorStatus枚举值:
  *           -FL_PASS 外设寄存器值恢复复位值
  *           -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_COMP_DeInit(COMP_Type *COMPx)
{
    FL_ErrorStatus status = FL_FAIL;
    if(COMPx != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_COMP_ALL_INSTANCE(COMPx));
        /* 恢复寄存器值为默认值 */
        COMPx->CR = 0x00000000U;
        status = FL_PASS;
    }
    return status;
}

/**
  * @brief  根据 COMP_InitStruct的配置信息初始化对应外设.
  * @param  COMPx COMP Port
  * @param  initStruct 指向一个 @ref FL_COMP_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @param  Serial 比较器序号可取值：
  *         1 配置比较器1
  *         2 配置比较器2
  * @retval ErrorStatus枚举值
  *            -FL_FAIL 配置过程发生错误
  *            -FL_PASS COMP配置成功
  */
FL_ErrorStatus FL_COMP_Init(COMP_Type *COMPx, FL_COMP_InitTypeDef *initStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(initStruct != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_COMP_ALL_INSTANCE(COMPx));
        assert_param(IS_FL_COMP_EDGE(initStruct->edge));
        assert_param(IS_FL_COMP_POLARITY(initStruct->polarity));
        assert_param(IS_FL_COMP_POSITIVEINPUT(initStruct->positiveInput));
        assert_param(IS_FL_COMP_NEGATIVEINPUT(initStruct->negativeInput));
        assert_param(IS_FL_COMP_DIGITAL_FILTER(initStruct->digitalFilter));
        assert_param(IS_FL_COMP_DIGITAL_FILTER_LEN(initStruct->digitalFilterLen));
        assert_param(IS_FL_COMP_DIGITAL_POWERMODE(initStruct->powerMode));
        assert_param(IS_FL_COMP_TRGOEDGE(initStruct->TRGOEdgeSrc));
        /* 使能时钟总线 */
        FL_CMU_EnableGroup1BusClock(FL_CMU_GROUP1_BUSCLK_COMP);
        /* 比较器输出极性选择 */
        FL_COMP_SetOutputPolarity(COMPx, initStruct->polarity);
        /* 比较器正向输入选择 */
        FL_COMP_SetINPSource(COMPx, initStruct->positiveInput);
        /* 比较器反向输入选择 */
        FL_COMP_SetINNSource(COMPx, initStruct->negativeInput);
        /* 比较器触发输出边沿选择 */
        FL_COMP_SetTriggerOutputEdge(COMPx, initStruct->TRGOEdgeSrc);
        /* 比较器功耗模式设置 */
        FL_COMP_SetPowerMode(COMPx, initStruct->powerMode);
        if(initStruct->TRGOState == FL_ENABLE)
        {
            FL_COMP_EnableTriggerOutput(COMPx);
        }
        else
        {
            FL_COMP_DisableTriggerOutput(COMPx);
        }
        /* 比较器使用1/2(internal reference) 打开buffer */
        if(initStruct->negativeInput == FL_COMP_INN_SOURCE_AVREF_DIV2)
        {
            FL_COMP_EnableBuffer(COMP);  /* buffer使能 */
            FL_COMP_DisableBufferBypass(COMP);   /* 不bypass buffer */
        }
        /* 比较器数字滤波 */
        if(COMPx == COMP0)
        {
            /* 比较器中断边沿选择 */
            FL_COMP_SetComparator0InterruptEdge(COMP, ((initStruct->edge) << COMP_ICR_CMP0SEL_Pos));
        }
        else if(COMPx == COMP1)
        {
            /* 比较器中断边沿选择 */
            FL_COMP_SetComparator1InterruptEdge(COMP, ((initStruct->edge) << COMP_ICR_CMP1SEL_Pos));
        }
        else
        {
            /* 比较器中断边沿选择 */
            FL_COMP_SetComparator2InterruptEdge(COMP, ((initStruct->edge) << COMP_ICR_CMP2SEL_Pos));
        }
        /* 滤波 */
        if(initStruct->digitalFilter == FL_ENABLE)
        {
            FL_COMP_EnableOutputFilter(COMPx);
        }
        else
        {
            FL_COMP_DisableOutputFilter(COMPx);
        }
        /* 滤波长度 */
        FL_COMP_SetOutputFilterWindow(COMPx, initStruct->digitalFilterLen);
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief    设置 initStruct 为默认配置
  * @param     initStruct 指向需要将值设置为默认配置的结构体 @ref FL_COMP_InitTypeDef 结构体
  *
  * @retval    None
  */
void FL_COMP_StructInit(FL_COMP_InitTypeDef *initStruct)
{
    if(initStruct != NULL)
    {
        /* 复位配置信息 */
        initStruct->edge             = FL_COMP_INTERRUPT_EDGE_BOTH;
        initStruct->polarity         = FL_COMP_OUTPUT_POLARITY_NORMAL;
        initStruct->negativeInput    = FL_COMP_INN_SOURCE_INN1;
        initStruct->positiveInput    = FL_COMP_INP_SOURCE_INP1;
        initStruct->digitalFilter    = FL_ENABLE;
        initStruct->digitalFilterLen = FL_COMP_OUTPUT_FILTER_WINDOW_3APBCLK;
    }
}

/**
  * @}
  */

#endif /* FL_COMP_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */
/*************************************************************END OF FILE************************************************************/
