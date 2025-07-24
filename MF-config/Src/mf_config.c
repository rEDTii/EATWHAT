/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : mf_config.c
  * @brief          : MCU FUNCTION CONFIG
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 FMSH.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by FMSH under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "mf_config.h"

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  IWDT Initialization function
  * @param  void
  * @retval None
  */
void MF_IWDT_Init(void)
{
    FL_IWDT_InitTypeDef    IWDT_InitStruct;

    IWDT_InitStruct.overflowPeriod = FL_IWDT_PERIOD_16000MS;
    IWDT_InitStruct.iwdtWindows = 0;

    (void)FL_IWDT_Init(IWDT, &IWDT_InitStruct);
}


/**
  * @brief
  * @rmtoll   PLLCR    OSEL    LL_RCC_GetPLLDigitalDomainOutput
  * @param    Source This parameter can be one of the following values:
  *           @arg @ref FL_RCC_PLL_CLK_SOURCE_RCHF
  *           @arg @ref FL_RCC_PLL_CLK_SOURCE_XTHF
  * @param    PLL_R 锁相环的参考时钟需要预分频至1M，再进行PLL倍频 This parameter can be one of the following values:
  *           @arg @ref FL_RCC_PLL_PSC_DIV1
  *           @arg @ref FL_RCC_PLL_PSC_DIV2
  *           @arg @ref FL_RCC_PLL_PSC_DIV4
  *           @arg @ref FL_RCC_PLL_PSC_DIV8
  *           @arg @ref FL_RCC_PLL_PSC_DIV12
  *           @arg @ref FL_RCC_PLL_PSC_DIV16
  *           @arg @ref FL_RCC_PLL_PSC_DIV24
  *           @arg @ref FL_RCC_PLL_PSC_DIV32
  * @retval   None
  */
void RCC_PLL_ConfigDomain_SYS(uint32_t Source, uint32_t PLL_R, uint32_t PLL_DB)
{
    MODIFY_REG(CMU->PLLCR, CMU_PLLCR_DB_Msk | CMU_PLLCR_REFPRSC_Msk | CMU_PLLCR_INSEL_Msk,
               ((PLL_DB - 1) << CMU_PLLCR_DB_Pos) | PLL_R | Source);
}

/**
  * @brief  RCHF Initialization function
  * @param  RCHFclock
  * @retval None
  */
void RCHFInit(uint32_t RCHFclock)
{
    switch(RCHFclock) 
    {
        case FL_CMU_RCHF_FREQUENCY_8MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            break;

        case FL_CMU_RCHF_FREQUENCY_16MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF16M_TRIM);
            break;

        case FL_CMU_RCHF_FREQUENCY_24MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF24M_TRIM);
            break;

        case FL_CMU_RCHF_FREQUENCY_32MHZ:
            FL_CMU_RCHF_WriteTrimValue(RCHF32M_TRIM);
            break;

        default:
            FL_CMU_RCHF_WriteTrimValue(RCHF8M_TRIM);
            break;
    }

    FL_CMU_RCHF_SetFrequency(RCHFclock);
}


/**
  * @brief  选择内部RCHF作为锁相环的参考时钟
  *
  * @note   锁相环的参考时钟需要预分频至1M，再进行PLL倍频
  * @param  rchf  RCHF参考时钟选择    This parameter can be one of the following values:
  *           @arg @ref FL_RCC_RCHF_FREQUENCY_8MHZ
  *           @arg @ref FL_RCC_RCHF_FREQUENCY_16MHZ
  *           @arg @ref FL_RCC_RCHF_FREQUENCY_24MHZ
  *           @arg @ref FL_RCC_RCHF_FREQUENCY_32MHZ
  * @param  clock PLL倍频输出频率
  * @note   输出时钟频率为1M*（clock+1），最高输出频率可达80M
  * @retval none
  */
uint32_t SelRCHFToPLL(uint32_t rchf, uint32_t PLLclock)
{
//    FL_NVIC_ConfigTypeDef    InterruptConfigStruct;

    uint32_t counter = 0;
    uint32_t readystatus = 0;
    uint32_t PLLdiv = FL_CMU_PLL_PSC_DIV8;

    if(PLLclock > 80)
    {
        return 1;    //超出PLL倍频最高范围
    }
    else
    {

        RCHFInit(rchf);

        FL_CMU_ClearFlag_SYSCSEWrong();                  //清除时钟选择错误标志
        FL_CMU_EnableIT_SYSCKEWrong();                   //使能时钟选择错误中断

//        InterruptConfigStruct.preemptPriority = 0x00;
//        FL_NVIC_Init(&InterruptConfigStruct, HFDET_SCSE_IRQn);    //系统时钟选择错误中断

        switch(rchf)
        {
            case FL_CMU_RCHF_FREQUENCY_16MHZ:
                PLLdiv = FL_CMU_PLL_PSC_DIV16;
                break;

            case FL_CMU_RCHF_FREQUENCY_24MHZ:
                PLLdiv = FL_CMU_PLL_PSC_DIV24;
                break;

            case FL_CMU_RCHF_FREQUENCY_32MHZ:
                PLLdiv = FL_CMU_PLL_PSC_DIV32;
                break;

            default:
                PLLdiv = FL_CMU_PLL_PSC_DIV8;
                break;
        }
        RCC_PLL_ConfigDomain_SYS(FL_CMU_PLL_CLK_SOURCE_RCHF, PLLdiv, PLLclock);
        FL_CMU_PLL_Enable();
        do
        {
            readystatus = FL_CMU_IsActiveFlag_PLLReady();
            counter++;

            if((counter % 100) == 0)
            {
                FL_IWDT_ReloadCounter(IWDT);  //清狗
            }
        } while((readystatus != 0x1U) && (counter != PLL_TIMEOUT));

        FL_CMU_SetAHBPrescaler(FL_CMU_AHBCLK_PSC_DIV1);
        FL_CMU_SetAPB1Prescaler(FL_CMU_APB1CLK_PSC_DIV1);
        FL_CMU_SetAPB2Prescaler(FL_CMU_APB1CLK_PSC_DIV1);

        if(PLLclock <= 24)
        {
            FL_FLASH_SetReadWait(FLASH, FL_FLASH_READ_WAIT_0CYCLE);      //  CODE Flash读等待周期配置 0 wait cycle
        }
        else if(PLLclock <= 48)    //(clock > 24) && (clock <= 48)
        {
            FL_FLASH_SetReadWait(FLASH, FL_FLASH_READ_WAIT_1CYCLE);      //  CODE Flash读等待周期配置 1 wait cycle
        }
        else if(PLLclock <= 72)    //(clock > 48) && (clock <= 72)
        {
            FL_FLASH_SetReadWait(FLASH, FL_FLASH_READ_WAIT_2CYCLE);      //  CODE Flash读等待周期配置 2 wait cycle
        }
        else    //(clock > 72) && (clock <= 96)
        {
            FL_FLASH_SetReadWait(FLASH, FL_FLASH_READ_WAIT_3CYCLE);      //  CODE Flash读等待周期配置 3 wait cycle
        }
        
        FL_CMU_SetSystemClockSource(FL_CMU_SYSTEM_CLK_SOURCE_PLL);
    }

    SystemCoreClockUpdate();

    return 0;
}






/**
  * @brief  The application entry point.
  * @retval int
  */
void MF_Clock_Init(void)
{
		// 如果修改时钟，需要修改的地方有：rtc预分频、spi速率
		// 将RCHF时钟配置为最大32MHz
		RCHFInit(FL_CMU_RCHF_FREQUENCY_32MHZ);
		SystemCoreClockUpdate();
	
	
//	//先将RCHF 8M分频到1M，再利用PLL锁相环倍频到80M
//	(void)SelRCHFToPLL(FL_CMU_PLL_PSC_DIV8, 80);  
	
}

void MF_Config_Init(void)
{
		// config IWDT with the biggest overflowperiod
		MF_IWDT_Init();
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */

    /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
    /* USER CODE BEGIN Assert_Failed */
    /* User can add his own implementation to report the file name and line number,
       tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
    /* USER CODE END Assert_Failed */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT FMSH *****END OF FILE****/
