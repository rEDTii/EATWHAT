/* 存放DMA相关的共用源代码 */
#include "dma.h"
#include "FreeRTOS.h"
#include "semphr.h"
#include "recorder.h"

// 用于SD卡的DMA写的信号量
static SemaphoreHandle_t xSD_DMA_Send_Sema = NULL;
// 用于SD卡的DMA读的信号量
static SemaphoreHandle_t xSD_DMA_Recv_Sema = NULL;


void DMA_IRQHandler(void)
{
    /* DMA CHANNEL_0 全程中断，Mic I2S使用 */
    if((FL_DMA_IsEnabledIT_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL)) && (FL_DMA_IsActiveFlag_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL))){			
				FL_DMA_ClearFlag_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL);
			
				BaseType_t xHigherPriorityTaskWoken = pdFALSE;
				vTaskNotifyGiveFromISR(xAudioRecordingTaskHandle, &xHigherPriorityTaskWoken);
				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
		
    /* DMA CHANNEL_1 全程中断，Speaker I2S使用 */
    if((FL_DMA_IsEnabledIT_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL)) && (FL_DMA_IsActiveFlag_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL))){				
				FL_DMA_ClearFlag_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL);
			
				BaseType_t xHigherPriorityTaskWoken = pdFALSE;
				vTaskNotifyGiveFromISR(xAudioPlayingTaskHandle, &xHigherPriorityTaskWoken);
				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
		
    /* DMA CHANNEL_2 全程中断，SD SPI 写使用 */
    if((FL_DMA_IsEnabledIT_TransferComplete(DMA, SD_SPI_SEND_DMA_CHANNEL)) && (FL_DMA_IsActiveFlag_TransferComplete(DMA, SD_SPI_SEND_DMA_CHANNEL))){				
				FL_DMA_ClearFlag_TransferComplete(DMA, SD_SPI_SEND_DMA_CHANNEL);
			
				BaseType_t xHigherPriorityTaskWoken = pdFALSE;
				xSemaphoreGiveFromISR(xSD_DMA_Send_Sema, &xHigherPriorityTaskWoken);
				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}
		
    /* DMA CHANNEL_3 全程中断，SD SPI 读使用 */
    if((FL_DMA_IsEnabledIT_TransferComplete(DMA, SD_SPI_RECV_DMA_CHANNEL)) && (FL_DMA_IsActiveFlag_TransferComplete(DMA, SD_SPI_RECV_DMA_CHANNEL))){				
				FL_DMA_ClearFlag_TransferComplete(DMA, SD_SPI_RECV_DMA_CHANNEL);
			
				BaseType_t xHigherPriorityTaskWoken = pdFALSE;
				xSemaphoreGiveFromISR(xSD_DMA_Recv_Sema, &xHigherPriorityTaskWoken);
				portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
		}					
}

// DMA NVIC初始化
void DMA_NVIC_Init(void)
{
    FL_NVIC_ConfigTypeDef    InterruptConfigStruct;

    InterruptConfigStruct.preemptPriority = 3;
    FL_NVIC_Init(&InterruptConfigStruct, DMA_IRQn);
}


// 各个DMA初始化
FL_ErrorStatus DMA_init()
{
		DMA_NVIC_Init();    //  interrupt

    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_DMA);
    FL_DMA_InitTypeDef DMA_InitStruct = {0};
    FL_DMA_Disable(DMA);			// DMA全局关
		
		/* 各个DMA初始化开始 */
		// DMA channel_0 init: Microphone I2S DMA
		FL_DMA_ClearFlag_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL);
    DMA_InitStruct.circMode                    = FL_ENABLE;		// 循环模式
    DMA_InitStruct.dataSize                    = FL_DMA_BANDWIDTH_32B;
    DMA_InitStruct.direction                   = FL_DMA_DIR_PERIPHERAL_TO_RAM;
    DMA_InitStruct.priority                    = FL_DMA_PRIORITY_LOW;
    DMA_InitStruct.memoryAddressIncMode        = FL_DMA_MEMORY_INC_MODE_INCREASE;
    DMA_InitStruct.peripheralAddressIncMode    = FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE;
		DMA_InitStruct.periphAddress            	 = FL_DMA_CHANNEL_SPI0_RX;
		DMA_InitStruct.dbufMode										 = FL_ENABLE;		// 配置为双缓冲模式	
		
    FL_DMA_Init(DMA, &DMA_InitStruct, MIC_I2S_DMA_CHANNEL);
		FL_DMA_EnableIT_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL);		// 配置为全程中断		
		FL_DMA_ClearFlag_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL);		
		
		
		// DMA channel_1 init: Speaker I2S DMA
		FL_DMA_ClearFlag_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL);
    DMA_InitStruct.circMode                    = FL_ENABLE;		// 循环模式
    DMA_InitStruct.dataSize                    = FL_DMA_BANDWIDTH_32B;
    DMA_InitStruct.direction                   = FL_DMA_DIR_RAM_TO_PERIPHERAL;
    DMA_InitStruct.priority                    = FL_DMA_PRIORITY_LOW;
    DMA_InitStruct.memoryAddressIncMode        = FL_DMA_MEMORY_INC_MODE_INCREASE;
    DMA_InitStruct.peripheralAddressIncMode    = FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE;
		DMA_InitStruct.periphAddress            	 = FL_DMA_CHANNEL_SPI1_TX;
		DMA_InitStruct.dbufMode										 = FL_ENABLE;		// 配置为双缓冲模式	
		
    FL_DMA_Init(DMA, &DMA_InitStruct, SPEAKER_I2S_DMA_CHANNEL);
		FL_DMA_EnableIT_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL);		// 配置为全程中断
		FL_DMA_ClearFlag_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL);		
		
		
		// DMA channel_2 init: SD SPI write DMA
		FL_DMA_ClearFlag_TransferComplete(DMA, SD_SPI_SEND_DMA_CHANNEL);
    DMA_InitStruct.circMode                    = FL_DISABLE;		// 循环模式关闭
    DMA_InitStruct.dataSize                    = FL_DMA_BANDWIDTH_8B;
    DMA_InitStruct.direction                   = FL_DMA_DIR_RAM_TO_PERIPHERAL;
    DMA_InitStruct.priority                    = FL_DMA_PRIORITY_LOW;
    DMA_InitStruct.memoryAddressIncMode        = FL_DMA_MEMORY_INC_MODE_INCREASE;
    DMA_InitStruct.peripheralAddressIncMode    = FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE;
		DMA_InitStruct.periphAddress            	 = FL_DMA_CHANNEL_SPI3_TX;
		DMA_InitStruct.dbufMode										 = FL_DISABLE;		// 双缓冲模式关闭
		
    FL_DMA_Init(DMA, &DMA_InitStruct, SD_SPI_SEND_DMA_CHANNEL);
		FL_DMA_EnableIT_TransferComplete(DMA, SD_SPI_SEND_DMA_CHANNEL);		// 配置为全程中断
		FL_DMA_ClearFlag_TransferComplete(DMA, SD_SPI_SEND_DMA_CHANNEL);		
		

		// DMA channel_3 init: SD SPI read DMA
		FL_DMA_ClearFlag_TransferComplete(DMA, SD_SPI_RECV_DMA_CHANNEL);
    DMA_InitStruct.circMode                    = FL_DISABLE;		// 循环模式关闭
    DMA_InitStruct.dataSize                    = FL_DMA_BANDWIDTH_8B;
    DMA_InitStruct.direction                   = FL_DMA_DIR_PERIPHERAL_TO_RAM;
    DMA_InitStruct.priority                    = FL_DMA_PRIORITY_LOW;
    DMA_InitStruct.memoryAddressIncMode        = FL_DMA_MEMORY_INC_MODE_INCREASE;
    DMA_InitStruct.peripheralAddressIncMode    = FL_DMA_PERIPHERAL_INC_MODE_NOCHANGE;
		DMA_InitStruct.periphAddress            	 = FL_DMA_CHANNEL_SPI3_RX;
		DMA_InitStruct.dbufMode										 = FL_DISABLE;		// 双缓冲模式关闭
		
    FL_DMA_Init(DMA, &DMA_InitStruct, SD_SPI_RECV_DMA_CHANNEL);
		FL_DMA_EnableIT_TransferComplete(DMA, SD_SPI_RECV_DMA_CHANNEL);		// 配置为全程中断
		FL_DMA_ClearFlag_TransferComplete(DMA, SD_SPI_RECV_DMA_CHANNEL);		
		/* 各个DMA初始化结束 */
		
		FL_DMA_Enable(DMA);			// DMA全局开

		/* FreeRTOS相关 */
		// SD卡DMA读写信号量
		xSD_DMA_Send_Sema = xSemaphoreCreateBinary();
		xSD_DMA_Recv_Sema = xSemaphoreCreateBinary();
		
    return FL_PASS;
}


// Microphone I2S DMA传输启动
void Mic_DMA_Trasnsfer(uint32_t *data_buffer0, uint32_t *data_buffer1, uint32_t data_len)
{
    FL_DMA_ConfigTypeDef DMA_ConfigStruct = {0};
    DMA_ConfigStruct.memoryAddress0 = (uint32_t)data_buffer0;
		DMA_ConfigStruct.memoryAddress1 = (uint32_t)data_buffer1;
    DMA_ConfigStruct.peripheralAddress = (uint32_t)&SPI0->RXBUF;
    DMA_ConfigStruct.transmissionCount = data_len - 1;
		
		FL_DMA_ClearFlag_TransferComplete(DMA, MIC_I2S_DMA_CHANNEL);	
    FL_DMA_StartTransmission(DMA, &DMA_ConfigStruct, MIC_I2S_DMA_CHANNEL);		
}


// Speaker I2S DMA传输启动
void Speaker_DMA_Trasnsfer(uint32_t *data_buffer0, uint32_t *data_buffer1, uint32_t data_len)
{
    FL_DMA_ConfigTypeDef DMA_ConfigStruct = {0};
    DMA_ConfigStruct.memoryAddress0 = (uint32_t)data_buffer0;
		DMA_ConfigStruct.memoryAddress1 = (uint32_t)data_buffer1;
    DMA_ConfigStruct.peripheralAddress = (uint32_t)&SPI1->TXBUF;
    DMA_ConfigStruct.transmissionCount = data_len - 1;		
		
		FL_DMA_ClearFlag_TransferComplete(DMA, SPEAKER_I2S_DMA_CHANNEL);	
    FL_DMA_StartTransmission(DMA, &DMA_ConfigStruct, SPEAKER_I2S_DMA_CHANNEL);	
}


// SD send SPI DMA传输启动
void SD_SEND_DMA_Trasnsfer(uint8_t *data_buffer, uint16_t data_len)
{
    FL_DMA_ConfigTypeDef DMA_ConfigStruct = {0};
    DMA_ConfigStruct.memoryAddress0 = (uint32_t)data_buffer;
    DMA_ConfigStruct.peripheralAddress = (uint32_t)&SPI3->TXBUF;
    DMA_ConfigStruct.transmissionCount = data_len - 1;
    FL_DMA_StartTransmission(DMA, &DMA_ConfigStruct, SD_SPI_SEND_DMA_CHANNEL);		
		
//		// 忙等待方式
//		while(FL_SPI_IsActiveFlag_Busy(SPI3));
		
		
		// 异步调度方式
		// 挂起直到传输完毕
		xSemaphoreTake(xSD_DMA_Send_Sema, portMAX_DELAY);
		/* 当指定长度的DMA传输结束后，软件不能立即关闭SPI，因为此时最后一帧数据还在移位发送中，因此软件需要查询BUSY标志直到移位发送结束 */
		while(FL_SPI_IsActiveFlag_Busy(SPI3));
}


// SD recv SPI DMA传输启动
// SPI recv时还需要同时send 0xFF
// 更新：查阅数据手册发现SPI DMA接收只需要配置接收即可，应该是硬件自动完成了dummy数据发送
void SD_RECV_DMA_Trasnsfer(uint8_t *data_buffer, uint16_t data_len)
{
		// RX
    FL_DMA_ConfigTypeDef DMA_Recv_ConfigStruct = {0};
    DMA_Recv_ConfigStruct.memoryAddress0 = (uint32_t)data_buffer;
    DMA_Recv_ConfigStruct.peripheralAddress = (uint32_t)&SPI3->RXBUF;
    DMA_Recv_ConfigStruct.transmissionCount = data_len - 1;
    FL_DMA_StartTransmission(DMA, &DMA_Recv_ConfigStruct, SD_SPI_RECV_DMA_CHANNEL);	
		
//		// 忙等待方式
//		while(FL_SPI_IsActiveFlag_Busy(SPI3));
		
		
		// 异步调度方式
		// 挂起直到传输完毕
		xSemaphoreTake(xSD_DMA_Recv_Sema, portMAX_DELAY);
}
