/* i2s接的两个音频设备配置：microphone和speaker */
#ifndef _I2S_H_
#define _I2S_H_

#include "fm33fk5xx_fl.h"

void Mic_I2S_Init();
void Speaker_I2S_GPIO_Init();
void Speaker_I2S_Config(uint32_t sample_rate);

#endif