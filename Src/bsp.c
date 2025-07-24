#include "bsp.h"

void showCLKinfo() {
		FL_DelayMs(50);
		printf("SystemCoreClock is set to: %d\r\n", SystemCoreClock);
		FL_DelayMs(50);
		printf("CMU APB1 Clock Freq is set to: %d\r\n", FL_CMU_GetAPB1ClockFreq());
		FL_DelayMs(50);
		printf("CMU APB2 Clock Freq is set to: %d\r\n", FL_CMU_GetAPB2ClockFreq());
		FL_DelayMs(50);
}

void BSP_init() {	
		printf("BSP init starting...\r\n");
		// w25q64 spi2 init 字库，文件系统中文名需要，后续添加系统配置进去
		W25Q64_SPI_Init();	
	
		// LCD epsc init
		LCD_Init();
		printf("LCD init ok.\r\n");	
	
		// PWM调光init
		PWM_BL_Init();
		printf("PWM BL init ok.\r\n");	
		// 读取并设置亮度值
		W25Q64_ReadData(W25Q64_BRIGHTNESS_ADDR, &brightness, 1);
		Set_PWM_BL(brightness);
		
		// 读取音量值
		W25Q64_ReadData(W25Q64_VOLUME_ADDR, &volume_value, 1);
	
		// RTC
	  RTCB_Init();
		printf("RTC init ok.\r\n");	
	
		// Mic
		Mic_I2S_Init();
		printf("Mic init ok.\r\n");	
	
		//speaker
		Speaker_I2S_GPIO_Init();
		printf("Speaker init ok.\r\n");	
	
		// DMA
		DMA_init();
		printf("DMA init ok.\r\n");	
}
