/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_vao.c
  * @author  FMSH Application Team
  * @brief   Src file of DMA FL Module
  *******************************************************************************************************
  * @attention
  *
  * Copyright (c) [2021] [Fudan Microelectronics]
  * THIS SOFTWARE is licensed under Mulan PSL v2.
  * You can use this software according to the terms and conditions of the Mulan PSL v2.
  * You may obtain a copy of Mulan PSL v2 at:
  *          http://license.coscl.org.cn/MulanPSL2
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

/** @addtogroup VAO
  * @{
  */

#ifdef FL_VAO_DRIVER_ENABLED

/* Private macros ------------------------------------------------------------*/
/** @addtogroup VAO_FL_Private_Macros
  * @{
  */
#define         IS_FL_VAO_INSTANCE(INTANCE)                     ((INTANCE) == VAO)

#define         IS_FL_VAO_OUTPUT_DRIVE_ABILITY(__VALUE__)       (((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_NONE)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_1)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_2)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_3)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_4)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_5)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_6)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_DRIVE_LEVEL_7))

#define         IS_FL_VAO_WORKING_CURRENT(__VALUE__)            (((__VALUE__) == FL_VAO_XTLF_WORK_CURRENT_NONE)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_WORK_CURRENT_1)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_WORK_CURRENT_2)||\
                                                                  ((__VALUE__) == FL_VAO_XTLF_WORK_CURRENT_3))

#define         IS_FL_VAO_PH_INPUT(__VALUE__)                   (((__VALUE__) == FL_DISABLE)||\
                                                                  ((__VALUE__) == FL_ENABLE))

#define         IS_FL_VAO_PH_PULL(__VALUE__)                    (((__VALUE__) == FL_VAO_PH_BOTH_DISABLE)||\
                                                                  ((__VALUE__) == FL_VAO_PH_PULLDOWN_ENABLE)||\
                                                                  ((__VALUE__) == FL_VAO_PH_PULLUP_ENABLE))

#define         IS_FL_VAO_PH_OPENDRAIN_OUTPUT(__VALUE__)        (((__VALUE__) == FL_DISABLE)||\
                                                                  ((__VALUE__) == FL_ENABLE))

#define         IS_FL_VAO_PH_MODE(__VALUE__)                    (((__VALUE__) == FL_VAO_PH_MODE_INPUT)||\
                                                                 ((__VALUE__) == FL_VAO_PH_MODE_OUTPUT)||\
                                                                 ((__VALUE__) == FL_VAO_PH_MODE_DIGTAL))

#define         IS_FL_VAO_PH_THRESHOLD(__VALUE__)                (((__VALUE__) == FL_VAO_PH_THRESHOLD_X1)||\
                                                                 ((__VALUE__) == FL_VAO_PH_THRESHOLD_X2)||\
                                                                 ((__VALUE__) == FL_VAO_PH_THRESHOLD_X3)||\
                                                                 ((__VALUE__) == FL_VAO_PH_THRESHOLD_X4))

/**
  * @}
  */

/* Exported functions --------------------------------------------------------*/
/** @addtogroup VAO_FL_EF_Init
  * @{
  */

/**
  * @brief  复位对应VAO寄存器
  * @param  VAOx VAO Port
  * @retval ErrorStatus枚举值:
  *         -FL_PASS 外设寄存器值恢复复位值
  *         -FL_FAIL 未成功执行
  */
FL_ErrorStatus FL_VAO_DeInit(VAO_Type *VAOx)
{
    /* 入口参数检查 */
    assert_param(IS_FL_VAO_INSTANCE(VAOx));
    /* 使能vao复位 */
    FL_VAO_EnableReset(VAOx);
    /* 关闭CDIF */
    FL_CDIF_DisableCPUToVAO(CDIF);
    /* 撤销vao复位 */
    FL_VAO_DisableReset(VAOx);
    return FL_PASS;
}

/**
  * @brief  根据 VAO_IO_StructInit 的配置信息初始化对应外设入口地址的寄存器值
  * @param  VAOx VAOx
  * @param  VAO_IO_StructInit 指向一个 @ref FL_VAO_IO_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */

FL_ErrorStatus FL_VAO_IO_Init(VAO_Type *VAOx, FL_VAO_IO_InitTypeDef *VAO_IO_InitStruct)
{
    FL_ErrorStatus status = FL_FAIL;
    if(VAO_IO_InitStruct != NULL)
    {
        uint32_t pinPos     = 0x00000000U;
        uint32_t currentPin = 0x00000000U;

        /* 参数检查 */
        assert_param(IS_FL_VAO_INSTANCE(VAOx));
        assert_param(IS_FL_VAO_PH_INPUT(VAO_IO_InitStruct->input));
        assert_param(IS_FL_VAO_PH_PULL(VAO_IO_InitStruct->pull));
        assert_param(IS_FL_VAO_PH_OPENDRAIN_OUTPUT(VAO_IO_InitStruct->opendrainOutput));
        assert_param(IS_FL_VAO_PH_MODE(VAO_IO_InitStruct->mode));
        assert_param(IS_FL_VAO_PH_THRESHOLD(VAO_IO_InitStruct->driveStrength));

        /*使能CDIF*/
        FL_CDIF_EnableCPUToVAO(CDIF);

        /* 这里考虑到PIN有可能不止一个因此需要遍历 */
        while(((VAO_IO_InitStruct->pin) >> pinPos) != 0x00000000U)
        {
            /* 获取当前遍历到的Pin脚 */
            currentPin = (VAO_IO_InitStruct->pin) & (0x1UL << pinPos);
            if(currentPin != 0X0U)
            {
                /* Pin脚模拟模式设置 */
                if(VAO_IO_InitStruct->mode == FL_VAO_PH_MODE_ANALOG)
                {
                    FL_VAO_GPIO_DisablePHInput(VAOx, currentPin);
                    FL_VAO_GPIO_DisablePHPullup(VAOx, VAO_IO_InitStruct->pin);
                    FL_VAO_GPIO_DisablePHPulldown(VAOx, VAO_IO_InitStruct->pin);
                    FL_VAO_GPIO_DisablePHOpenDrain(VAOx, currentPin);
                }
                else
                {
                    /* Pin脚输入使能控制 */
                    if(VAO_IO_InitStruct->mode == FL_VAO_PH_MODE_INPUT)
                    {
                        FL_VAO_GPIO_EnablePHInput(VAOx, currentPin);
                    }
                    else
                    {
                        FL_VAO_GPIO_DisablePHInput(VAOx, currentPin);
                    }
                    /* Pin脚输出模式设置 */
                    if(VAO_IO_InitStruct->opendrainOutput == FL_VAO_PH_OUTPUT_PUSHPULL)
                    {
                        FL_VAO_GPIO_DisablePHOpenDrain(VAOx, currentPin);
                    }
                    else
                    {
                        FL_VAO_GPIO_EnablePHOpenDrain(VAOx, currentPin);
                    }

                    /* 输出模式 Pin脚驱动强度设置 */
                    FL_VAO_GPIO_SetPinDriveStrength(VAOx, currentPin, VAO_IO_InitStruct->driveStrength);

                    /* Pin脚上拉/下拉模式设置 */
                    if(VAO_IO_InitStruct->pull == FL_VAO_PH_PULLUP_ENABLE)
                    {
                        FL_VAO_GPIO_DisablePHPulldown(VAOx, currentPin);
                        FL_VAO_GPIO_EnablePHPullup(VAOx, currentPin);
                    }
                    else if(VAO_IO_InitStruct->pull == FL_VAO_PH_PULLDOWN_ENABLE)
                    {
                        FL_VAO_GPIO_DisablePHPullup(VAOx, currentPin);
                        FL_VAO_GPIO_EnablePHPulldown(VAOx, currentPin);
                    }
                    else
                    {
                        FL_VAO_GPIO_DisablePHPullup(VAOx, currentPin);
                        FL_VAO_GPIO_DisablePHPulldown(VAOx, currentPin);
                    }
                }
                /*! PH功能选择 */
                FL_VAO_GPIO_SetPHMode(VAOx, VAO_IO_InitStruct->pin, VAO_IO_InitStruct->mode);
            }
            pinPos++;
        }
        status = FL_PASS;
    }
    return status;
}
/**
  * @brief  根据 VAO_XTLF_StructInit 的配置信息初始化对应外设入口地址的寄存器值
  * @param  VAOx VAOx
  * @param  VAO_XTLF_StructInit 指向一个 @ref FL_VAO_XTLF_InitTypeDef 结构体
  *         其中包含了外设的相关配置信息.
  * @retval ErrorStatus枚举值
  *         -FL_FAIL 配置过程发生错误
  *         -FL_PASS 配置成功
  */
FL_ErrorStatus FL_VAO_XTLF_Init(VAO_Type *VAOx, FL_VAO_XTLF_InitTypeDef *VAO_XTLF_InitStruct)
{
    /* 参数检查 */
    assert_param(IS_FL_VAO_INSTANCE(VAOx));
    assert_param(IS_FL_VAO_OUTPUT_DRIVE_ABILITY(VAO_XTLF_InitStruct->driveMode));
    assert_param(IS_FL_VAO_WORKING_CURRENT(VAO_XTLF_InitStruct->workingCurrentMode));
    /*使能CDIF*/

    FL_CDIF_EnableCPUToVAO(CDIF);
    /*! XTLF工作电流选择 */
    FL_VAO_XTLF_SetWorkCurrent(VAOx, VAO_XTLF_InitStruct->workingCurrentMode);
    /*! XTLF输出级驱动能力配置 */
    FL_VAO_XTLF_SetDriveLevel(VAOx, VAO_XTLF_InitStruct->driveMode);
    return FL_PASS;
}

/**
* @brief   设置 VAO_IO_StructInit 为默认配置
* @param   VAO_IO_StructInit 指向需要将值设置为默认配置的结构体 @ref FL_VAO_IO_InitTypeDef 结构体
*
* @retval  None
*/

void FL_VAO_IO_StructInit(FL_VAO_IO_InitTypeDef *VAO_IO_InitStruct)
{
    VAO_IO_InitStruct->mode                       = FL_VAO_PH_MODE_INPUT;
    VAO_IO_InitStruct->input                      = FL_DISABLE;
    VAO_IO_InitStruct->pull                       = FL_VAO_PH_BOTH_DISABLE;
    VAO_IO_InitStruct->opendrainOutput            = FL_DISABLE;
    VAO_IO_InitStruct->driveStrength              = FL_VAO_PH_THRESHOLD_X3;
}
/**
* @brief   设置 VAO_XTLF_StructInit 为默认配置
* @param   VAO_XTLF_StructInit 指向需要将值设置为默认配置的结构体 @ref FL_VAO_XTLF_InitTypeDef 结构体
*
* @retval  None
*/

void FL_VAO_XTLF_StructInit(FL_VAO_XTLF_InitTypeDef *VAO_XTLF_InitStruct)
{
    VAO_XTLF_InitStruct->driveMode                   = FL_VAO_XTLF_DRIVE_LEVEL_4;
    VAO_XTLF_InitStruct->workingCurrentMode          = FL_VAO_XTLF_WORK_CURRENT_1;
}

/**
  * @}
  */

#endif /* FL_VAO_DRIVER_ENABLED */

/**
  * @}
  */

/**
  * @}
  */

/*************************(C) COPYRIGHT Fudan Microelectronics **** END OF FILE*************************/
