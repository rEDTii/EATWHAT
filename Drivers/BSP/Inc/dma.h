/* 存放DMA相关的共用源代码 */
#ifndef _DMA_H_
#define _DMA_H_

#include "fm33fk5xx_fl.h"

#define MIC_I2S_DMA_CHANNEL 			FL_DMA_CHANNEL_0
#define SPEAKER_I2S_DMA_CHANNEL		FL_DMA_CHANNEL_1
#define SD_SPI_SEND_DMA_CHANNEL		FL_DMA_CHANNEL_2
#define SD_SPI_RECV_DMA_CHANNEL		FL_DMA_CHANNEL_3

void DMA_IRQHandler(void);
void DMA_NVIC_Init(void);
FL_ErrorStatus DMA_init();
void Mic_DMA_Trasnsfer(uint32_t *data_buffer0, uint32_t *data_buffer1, uint32_t data_len);
void Speaker_DMA_Trasnsfer(uint32_t *data_buffer0, uint32_t *data_buffer1, uint32_t data_len);
void SD_SEND_DMA_Trasnsfer(uint8_t *data_buffer, uint16_t data_len);
void SD_RECV_DMA_Trasnsfer(uint8_t *data_buffer, uint16_t data_len);

#endif