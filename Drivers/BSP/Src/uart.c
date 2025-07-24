#include "main.h"
#include "uart.h"
#if 1
#include <stdio.h>

int fputc(int ch, FILE *f)
{
    UART0->TXBUF = ch;
    while(!(UART0->ISR & (0x1 << 0)));
		// 注意这里ISR寄存器是写1清零，而不是写0 
    UART0->ISR |= (0x1 << 0);

    return ch;
}
#endif



void Debug_UART_Init()
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct;
    FL_UART_InitTypeDef    defaultInitStruct;

		GPIO_InitStruct.pin = FL_GPIO_PIN_0 | FL_GPIO_PIN_1;
		GPIO_InitStruct.mode = FL_GPIO_MODE_DIGITAL;
		GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
		GPIO_InitStruct.pull = FL_GPIO_PULLUP_ENABLE;
		GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON1;
		GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
		GPIO_InitStruct.analogSwitch = FL_DISABLE;
		FL_GPIO_Init(GPIOF, &GPIO_InitStruct);
	
		defaultInitStruct.clockSrc = FL_CMU_UART0_CLK_SOURCE_APBCLK;
    defaultInitStruct.baudRate = 115200;
    defaultInitStruct.dataWidth = FL_UART_DATA_WIDTH_8B;
    defaultInitStruct.stopBits = FL_UART_STOP_BIT_WIDTH_1B;
    defaultInitStruct.parity = FL_UART_PARITY_NONE;
    defaultInitStruct.transferDirection = FL_UART_DIRECTION_TX_RX;
    FL_UART_Init(UART0, &defaultInitStruct);
}




