/* RTC和其他时间相关 */
#ifndef _RTC_H_
#define _RTC_H_

#include "fm33fk5xx_fl.h"
#include "ugui.h"
#include "FreeRTOS.h"
#include "task.h"


extern char timeStr[6];
extern char dateStr[11];
extern char ui_seconds[18];
extern char audio_total_seconds_str[9];
extern uint32_t countseconds; // 录制播放时长（秒）
extern uint32_t audio_total_seconds; // 总时长
extern uint32_t playedseconds; // 总时长（秒）
extern TaskHandle_t xUitimeTaskHandle;

extern uint8_t alarm_hour;
extern uint8_t alarm_minute;
extern char alarmtimeStr[6];

// gettime
#define YEAR_H(x)		( (x>>4) &0x0F ) 
#define YEAR_L(x)		(x&0x0F) 
#define MONTH_H(x)	( (x>>4) &0x01 ) 
#define MONTH_L(x)	(x&0x0F) 
#define DAY_H(x)		( (x>>4) &0x03 ) 
#define DAY_L(x)		(x&0x0F) 
#define HOUR_H(x)		( (x>>4) &0x03 ) 
#define HOUR_L(x)		(x&0x0F) 
#define MINUTE_H(x)	( (x>>4) &0x07 ) 
#define MINUTE_L(x)	(x&0x0F) 
#define SECOND_H(x)	( (x>>4) &0x07 ) 
#define SECOND_L(x)	(x&0x0F) 

// 十进制转BCD码
#define Oct2BCD(x)	( (x/10) << 4 | (x%10) )
#define BCD2Oct(x)	( ((x & 0xF0) >> 1) + ((x & 0xF0) >> 3) + (x & 0x0F) )


uint8_t decimal_to_bcd(uint8_t decimal);
void RTCB_Init(void);
uint8_t RTCB_GetRTCB(FL_RTCB_InitTypeDef *InitStructer);
uint8_t RTCB_SetRTCB(FL_RTCB_InitTypeDef *InitStructer);
void UitimeTaskHandleTaskInit(void);
void sectimeTaskHandleTaskInit(void);
void get_rtc_time_str(char* buffer);
extern void stopUitimerenew(void);
extern void startUitimerenew(void);
extern int getDaysInMonth(int year, int month);

#endif