/**
  *******************************************************************************************************
  * @file    fm33fk5xx_fl_flash.c
  * @author  FMSH Application Team
  * @brief   Src file of FLASH FL Module
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

/** @addtogroup FLASH
  * @{
  */

/* Private macros ------------------------------------------------------------*/
/** @addtogroup FLASH_FL_Private_Macros
  * @{
  */

#define         IS_FLASH_ALL_INSTANCE(INTENCE)              (((INTENCE) == FLASH))

#define         IS_FL_FLASH_PAGE_NUM(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (FL_FLASH_MAX_PAGE_NUM)))

#define         IS_FL_FLASH_SECTOR_NUM(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (FL_FLASH_MAX_SECTOR_NUM)))

#define         IS_FL_FLASH_MAX_ADDR(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (FL_FLASH_ADDR_MAXPROGRAM)))

#define         IS_FL_FLASH_MAX_PAGE(__VALUE__)              ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (FL_FLASH_MAX_PAGE_NUM)))

#define         IS_FL_FLASH_MAX_SECTOR(__VALUE__)           ((((uint32_t)0x00000000U) < (__VALUE__)) &&\
                                                             ((__VALUE__) <= (FL_FLASH_MAX_SECTOR_NUM)))

/**
  * @}
  */

/* Private function prototypes -----------------------------------------------*/
/** @defgroup FLASH_FL_Private_Functions FLASH Private Functions
  * @{
  */

/** @addtogroup FLASH_FL_EF_Init
  * @{
  */

/**
  * @brief  Flash 页擦除函数，一个页为512byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的页内任意地址，推荐使用页开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_PageErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_FAIL;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_GetFlashLockStatus(FLASHx) == FL_FLASH_KEY_STATUS_ERROR)
    {
        /*Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
    /*配置擦写类型*/
    FL_FLASH_SetFlashEraseType(FLASHx, FL_FLASH_ERASE_TYPE_PAGE);
    /* 开始擦除页*/
    FL_FLASH_EnableErase(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PAGE_ERASE_KEY);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_EraseComplete(FLASHx);
    FL_FLASH_ClearFlag_ClockError(FLASHx);
    FL_FLASH_ClearFlag_KeyError(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationError(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) =  FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01UL) || (KeyError == 0X01UL) || (AuthenticationError == 0X01UL))
        {
            /* 超时或出现错误 */
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_EraseComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_EraseComplete(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockFlash(FLASHx);
    FL_CMU_DisableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  Flash 扇区擦除函数，一个扇区为2k byte.
  * @param  FLASHx FLASH Port
  * @param  address 为需要擦除的扇区内任意地址，推荐使用扇区开始的首地址（字对齐）

  *         .
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 擦写发生错误
  *         -FL_PASS 擦写成功
  */
FL_ErrorStatus FL_FLASH_SectorErase(FLASH_Type *FLASHx, uint32_t address)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    FL_ErrorStatus ret = FL_FAIL;
    uint32_t ClockError, KeyError, AuthenticationError;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_GetFlashLockStatus(FLASHx) == FL_FLASH_KEY_STATUS_ERROR)
    {
        /*Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
    /*配置擦写类型*/
    FL_FLASH_SetFlashEraseType(FLASHx, FL_FLASH_ERASE_TYPE_SECTOR);
    /* 开始擦除扇区*/
    FL_FLASH_EnableErase(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_ERASE_KEY);
    FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_SECTOR_ERASE_KEY);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_EraseComplete(FLASHx);
    FL_FLASH_ClearFlag_ClockError(FLASHx);
    FL_FLASH_ClearFlag_KeyError(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationError(FLASHx);
    /* 擦请求 */
    *((uint32_t *)address) =  FL_FLASH_ERASE_REQUEST;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_EraseComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_EraseComplete(FLASHx);
                ret =  FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockFlash(FLASHx);
    FL_CMU_DisableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  单次编程函数，编程地址必须对齐到字边界.
  * @param  FLASHx FLASH Port
  * @param  address 为需要编程的已经擦除过的扇区内任意地址，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_Program_Word(FLASH_Type *FLASHx, uint32_t address, uint32_t data)
{
    uint32_t timeout = 0;
    uint32_t primask = 0;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus ret = FL_PASS;
    /* 入口参数检查 */
    assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
    assert_param(IS_FL_FLASH_MAX_ADDR((uint32_t)address));
    /*时钟使能*/
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    /* 地址对齐检查 */
    if((address % FL_FLASH_ADDRS_ALIGN) != 0)
    {
        /*地址未对齐*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    if(FL_FLASH_GetFlashLockStatus(FLASHx) == FL_FLASH_KEY_STATUS_ERROR)
    {
        /*Flash 已经锁定，复位前无法操作*/
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        return FL_FAIL;
    }
    /*FLASH擦写时钟使能*/
    FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
    /* 开始编程*/
    FL_FLASH_EnableProgram(FLASHx);
    /* Key 序列*/
    primask = __get_PRIMASK();
    __disable_irq();
    FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PROGRAM_KEY1);
    FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PROGRAM_KEY2);
    __set_PRIMASK(primask);
    /* 清除中断标志*/
    FL_FLASH_ClearFlag_ProgramComplete(FLASHx);
    FL_FLASH_ClearFlag_ClockError(FLASHx);
    FL_FLASH_ClearFlag_KeyError(FLASHx);
    FL_FLASH_ClearFlag_AuthenticationError(FLASHx);
    /* flash编程 */
    *((uint32_t *)address) =  data;
    while(1)
    {
        timeout++;
        ClockError = FL_FLASH_IsActiveFlag_ClockError(FLASHx);
        KeyError = FL_FLASH_IsActiveFlag_KeyError(FLASHx);
        AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationError(FLASHx);
        if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
        {
            /* 超时或出现错误 */
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            ret = FL_FAIL;
            break;
        }
        else
        {
            if(FL_FLASH_IsActiveFlag_ProgramComplete(FLASHx) == 0X01U)
            {
                /*编程成功*/
                FL_FLASH_ClearFlag_ProgramComplete(FLASHx);
                ret = FL_PASS;
                break;
            }
        }
    }
    FL_FLASH_LockFlash(FLASHx);
    FL_CMU_DisableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    return ret;
}

/**
  * @brief  页编程函数，编程地址必须对齐到页边界.
  * @param  FLASHx FLASH Port
  * @param  PageNum 为需要编程的已经擦除过的页号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_Program_Page(FLASH_Type *FLASHx, uint32_t pageNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_MAX_PAGE((uint32_t)pageNum));
        address = pageNum * FL_FLASH_PAGE_SIZE_BYTE;
        /*时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_PAGE_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            return FL_FAIL;
        }
        /*FLASH擦写时钟使能*/
        FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableProgram(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(primask);
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_ProgramComplete(FLASHx);
        FL_FLASH_ClearFlag_ClockError(FLASHx);
        FL_FLASH_ClearFlag_KeyError(FLASHx);
        FL_FLASH_ClearFlag_AuthenticationError(FLASHx);
        for(count = 0; count < FL_FLASH_PAGE_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableProgram(FLASHx);
            *((uint32_t *)address) =  *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_ClockError(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_KeyError(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationError(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_ProgramComplete(FLASHx) == 0X01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_ProgramComplete(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_LockFlash(FLASHx);
        FL_CMU_DisableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    }
    return status;
}

/**
  * @brief  扇区编程函数，编程地址必须对齐到扇区边界.
  * @param  FLASHx FLASH Port
  * @param  sectorNum 为需要编程的已经擦除过的扇区号，非对齐地址编程将触发fault。

  *
  * @retval ErrorStatus枚举值

  *         -FL_FAIL 编程发生错误
  *         -FL_PASS 编程成功
  */
FL_ErrorStatus FL_FLASH_Program_Sector(FLASH_Type *FLASHx, uint32_t sectorNum, uint32_t *data)
{
    uint32_t count;
    uint32_t primask;
    uint32_t address;
    uint32_t timeout;
    uint32_t ClockError, KeyError, AuthenticationError;
    FL_ErrorStatus status = FL_FAIL;
    if(data != NULL)
    {
        /* 入口参数检查 */
        assert_param(IS_FLASH_ALL_INSTANCE(FLASHx));
        assert_param(IS_FL_FLASH_MAX_SECTOR((uint32_t)sectorNum));
        address = sectorNum * FL_FLASH_SECTOR_SIZE_BYTE;
        /*时钟使能*/
        FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
        /* 页地址对齐检查 */
        if((address % FL_FLASH_SECTOR_SIZE_BYTE) != 0)
        {
            /*地址未对齐*/
            FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
            return FL_FAIL;
        }
        /*FLASH擦写时钟使能*/
        FL_CMU_EnableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
        /* 开始编程*/
        FL_FLASH_EnableProgram(FLASHx);
        /* Key 序列*/
        primask = __get_PRIMASK();
        __disable_irq();
        FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PROGRAM_KEY1);
        FL_FLASH_UnlockFlash(FLASHx, FL_FLASH_PROGRAM_KEY2);
        __set_PRIMASK(primask);
        /* 清除中断标志*/
        FL_FLASH_ClearFlag_ProgramComplete(FLASHx);
        FL_FLASH_ClearFlag_ClockError(FLASHx);
        FL_FLASH_ClearFlag_KeyError(FLASHx);
        FL_FLASH_ClearFlag_AuthenticationError(FLASHx);
        for(count = 0; count < FL_FLASH_SECTOR_SIZE_BYTE; count += 4)
        {
            timeout = 0;
            FL_FLASH_EnableProgram(FLASHx);
            *((uint32_t *)address) =  *data;
            address += 4;
            data++;
            while(1)
            {
                timeout++;
                ClockError = FL_FLASH_IsActiveFlag_ClockError(FLASHx);
                KeyError = FL_FLASH_IsActiveFlag_KeyError(FLASHx);
                AuthenticationError = FL_FLASH_IsActiveFlag_AuthenticationError(FLASHx);
                if((timeout > FL_FLASH_ERASE_TIMEOUT) || (ClockError == 0X01U) || (KeyError == 0X01U) || (AuthenticationError == 0X01U))
                {
                    /* 超时或出现错误 */
                    FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
                    status = FL_FAIL;
                    break;
                }
                else
                {
                    if(FL_FLASH_IsActiveFlag_ProgramComplete(FLASHx) == 0x01U)
                    {
                        /*编程成功*/
                        FL_FLASH_ClearFlag_ProgramComplete(FLASHx);
                        status = FL_PASS;
                        break;
                    }
                }
            }
        }
        FL_FLASH_LockFlash(FLASHx);
        FL_CMU_DisableGroup1OperationClock(FL_CMU_OPCLK_FLASH);
        FL_CMU_DisableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_FLASH);
    }
    return status;
}
/**
  * @}
  */

/* Private function ----------------------------------------------------------*/
/** @defgroup FLASH_FL_Private_Functions FLASH Private Functions
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
