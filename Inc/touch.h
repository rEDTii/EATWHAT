/* 提供触摸状态和坐标 */
#ifndef _TOUCH_H_
#define _TOUCH_H_

#include "fm33fk5xx_fl.h"

uint8_t TP_init();
void EXTID_IRQHandler(void);
void TouchHandlerTaskInit(void);

#endif