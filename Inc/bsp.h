#ifndef _BSP_H_
#define _BSP_H_

#include "uart.h"
#include "lcd.h"
#include "rtc.h"
#include "dma.h"
#include "i2s.h"
#include "w25q64.h"

void showCLKinfo();
void BSP_init();

#endif