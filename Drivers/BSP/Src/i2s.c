/* i2s接的两个音频设备配置：microphone和speaker */
#include "i2s.h"
#include "recorder.h"

//Mic 初始化
void Mic_I2S_Init()
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct;
    FL_I2S_InitTypeDef    I2S_InitStruct;

		GPIO_InitStruct.pin = FL_GPIO_PIN_0 | FL_GPIO_PIN_1 | FL_GPIO_PIN_3 ;
		GPIO_InitStruct.mode = FL_GPIO_MODE_DIGITAL;
		GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
		GPIO_InitStruct.pull = FL_GPIO_PULLUP_ENABLE;
		GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON3;
		GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X4;
		GPIO_InitStruct.analogSwitch = FL_DISABLE;
		FL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		
		I2S_InitStruct.mode = FL_I2S_MODE_MASTER_RX;
		I2S_InitStruct.standard = FL_I2S_STANDARD_PHILIPS;
		I2S_InitStruct.dataFormat =  FL_I2S_DATAFORMAT_24B;
		I2S_InitStruct.mclkOutput = FL_I2S_MASTER_CLKOUTPUT_CONTINUOUS;
		I2S_InitStruct.audioFreq = sample_rate ;
		I2S_InitStruct.clockPolarity = FL_I2S_IDLE_POLARITY_HIGHT;
		FL_I2S_Init(SPI0,&I2S_InitStruct);
}


//speaker初始化
void Speaker_I2S_GPIO_Init()
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct1;
		FL_GPIO_InitTypeDef    GPIO_InitStruct2;

		GPIO_InitStruct1.pin = FL_GPIO_PIN_0 | FL_GPIO_PIN_3 ;
		GPIO_InitStruct1.mode = FL_GPIO_MODE_DIGITAL;
		GPIO_InitStruct1.outputType = FL_GPIO_OUTPUT_PUSHPULL;
		GPIO_InitStruct1.pull = FL_GPIO_PULLUP_ENABLE;
		GPIO_InitStruct1.remapPin = FL_GPIO_PINREMAP_FUNCTON2;
		GPIO_InitStruct1.driveStrength = FL_GPIO_DRIVESTRENGTH_X4;
		GPIO_InitStruct1.analogSwitch = FL_DISABLE;
		FL_GPIO_Init(GPIOA, &GPIO_InitStruct1);
	
		GPIO_InitStruct2.pin = FL_GPIO_PIN_1 ;
		GPIO_InitStruct2.mode = FL_GPIO_MODE_DIGITAL;
		GPIO_InitStruct2.outputType = FL_GPIO_OUTPUT_PUSHPULL;
		GPIO_InitStruct2.pull = FL_GPIO_PULLUP_ENABLE;
		GPIO_InitStruct2.remapPin = FL_GPIO_PINREMAP_FUNCTON3;
		GPIO_InitStruct2.driveStrength = FL_GPIO_DRIVESTRENGTH_X4;
		GPIO_InitStruct2.analogSwitch = FL_DISABLE;
		FL_GPIO_Init(GPIOA, &GPIO_InitStruct2);
}


//speaker I2S 配置
void Speaker_I2S_Config(uint32_t sample_rate)
{
    FL_I2S_InitTypeDef    I2S_InitStruct;
	
		I2S_InitStruct.mode = FL_I2S_MODE_MASTER_TX;
		I2S_InitStruct.standard = FL_I2S_STANDARD_PHILIPS;
		I2S_InitStruct.dataFormat =  FL_I2S_DATAFORMAT_24B;
		I2S_InitStruct.mclkOutput = FL_I2S_MASTER_CLKOUTPUT_CONTINUOUS;
		I2S_InitStruct.audioFreq = sample_rate;
		I2S_InitStruct.clockPolarity = FL_I2S_IDLE_POLARITY_HIGHT;
		FL_I2S_Init(SPI1,&I2S_InitStruct);
}

