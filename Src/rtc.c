/* RTC和其他时间相关 */
#include "rtc.h"
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "GUI_APP.h"


//ui时间更新任务
TaskHandle_t xUitimeTaskHandle = NULL;
static void UitimeTask(void *pvParameters);

//player and recorder时间更新任务
//static TaskHandle_t xcountsecondsTaskHandle = NULL;
static void countsecondsTask(void *pvParameters);

//屏幕显示时间
char timeStr[6];
char dateStr[11];
extern uint8_t front_year;
uint8_t daterenew = 0;
//player and recorder显示时间
uint32_t countseconds; // 录制时长（秒）
uint32_t audio_total_seconds;		// 总时长
char ui_seconds[18];
char audio_total_seconds_str[9];


// 软件实现闹钟功能
uint8_t alarm_hour = 0;
uint8_t alarm_minute = 0;
char alarmtimeStr[6];

uint8_t decimal_to_bcd(uint8_t decimal) {
    uint8_t tens = (decimal * 0xCD) >> 11;  // 等价于 decimal / 10（利用定点数乘法）
    return (tens << 4) | (decimal - tens * 10);
}


// 时间字符串获取
void get_rtc_time_str(char* buffer) {
		FL_RTCB_InitTypeDef GetTime;
		RTCB_GetRTCB(&GetTime);
		sprintf(buffer, "%02x%02x%02x%02x%02x%02x", GetTime.year, GetTime.month, GetTime.day, GetTime.hour, GetTime.minute, GetTime.second);
}


// 将秒数转换为 HH:MM:SS/HH:MM:SS 格式
void format_time(uint32_t total_seconds, char* buffer) {
    uint8_t hours = total_seconds / 3600;
    uint8_t mins  = (total_seconds % 3600) / 60;
    uint8_t secs  = total_seconds % 60;
    sprintf(buffer, "%02d:%02d:%02d", hours, mins, secs);
}

// 闰年判断函数
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 获取指定月份的天数
int getDaysInMonth(int year, int month) {
    const int daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year)) {
        return 29; // 闰年二月
    }
    return daysPerMonth[month - 1];
}


// 创建ui时间更新任务
void UitimeTaskHandleTaskInit(void) {
    xTaskCreate(UitimeTask, "ui_timerenew", 256, NULL, 4, &xUitimeTaskHandle);
}
 
// 创建player and recorder时间更新任务
void sectimeTaskHandleTaskInit(void) {
    xTaskCreate(countsecondsTask, "playrecord_timerenew", 128, NULL, 4, NULL);
}


// RTC中断处理函数
void RTC_IRQHandler(void)
{
    uint32_t cdif_temp;
    cdif_temp = CDIF->CR;                                         //将cdif 状态暂存
    FL_CDIF_EnableCPUToVAO(CDIF);
	
		BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    // 秒中断
    if(FL_ENABLE == FL_RTCB_IsEnabledIT_Second(RTCB) &&
            FL_SET == FL_RTCB_IsActiveFlag_Second(RTCB))          //查询标志是否置起
    {
        FL_RTCB_ClearFlag_Second(RTCB);                           //清除中断标志
    }

    // 分钟中断
    if(FL_ENABLE == FL_RTCB_IsEnabledIT_Minute(RTCB) &&
            FL_SET == FL_RTCB_IsActiveFlag_Minute(RTCB))          //查询标志是否置起
    {
        FL_RTCB_ClearFlag_Minute(RTCB);                           //清除中断标志
				
				if ( xUitimeTaskHandle != NULL) {
						// 通知更新时间
						vTaskNotifyGiveFromISR( xUitimeTaskHandle,  &xHigherPriorityTaskWoken);
						portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
				}
    }

    // 小时中断
    if(FL_ENABLE == FL_RTCB_IsEnabledIT_Hour(RTCB) &&
            FL_SET == FL_RTCB_IsActiveFlag_Hour(RTCB))            //查询标志是否置起
    {
        FL_RTCB_ClearFlag_Hour(RTCB);                             //清除中断标志
    }

    // 天中断
    if(FL_ENABLE == FL_RTCB_IsEnabledIT_Day(RTCB) &&
            FL_SET == FL_RTCB_IsActiveFlag_Day(RTCB))             //查询标志是否置起
    {
        FL_RTCB_ClearFlag_Day(RTCB);                              //清除中断标志
				daterenew = 1;
    }

    if(FL_ENABLE == FL_RTCB_IsEnabledIT_Stamp(RTCB) &&
            FL_SET == FL_RTCB_IsActiveFlag_Stamp(RTCB))           //查询时间戳中断标志是否置起
    {
        FL_RTCB_ClearFlag_Stamp(RTCB);                            //清除时间戳中断标志
    }

    CDIF->CR = cdif_temp;                                         //将cdif 状态恢复
}


// CDIF访问速率不能超过8MHz，CDIF模块挂载在APBCLK下,主频过高时需要设置CDIF_PRSC对其进行预分频
void RTCB_Init(void)
{
		// 时钟预分频
		FL_CDIF_SetPrescaler(CDIF, FL_CDIF_PSC_DIV4);
	
		FL_NVIC_ConfigTypeDef    InterruptConfigStruct;	
//    FL_RTCB_InitTypeDef    RTCB_InitStruct;

//    RTCB_InitStruct.year = 		0x25;
//    RTCB_InitStruct.month = 	0x05;
//    RTCB_InitStruct.day = 		0x20;
//    RTCB_InitStruct.week = 		0x00;  // 没有week 寄存器
//    RTCB_InitStruct.hour = 		0x23;
//    RTCB_InitStruct.minute = 	0x55;
//    RTCB_InitStruct.second = 	0x50;

//    FL_RTCB_Init(RTCB, &RTCB_InitStruct);

    FL_CDIF_EnableCPUToVAO(CDIF);
//    FL_CDIF_DisableCPUToVAO(CDIF);                                //关闭cpu通向voa的通道 节省功耗
	
    InterruptConfigStruct.preemptPriority = 4;
    FL_NVIC_Init(&InterruptConfigStruct, RTC_IRQn);
}


static void UitimeTask(void *pvParameters){
		// 已有任务再开启中断
		FL_RTCB_ClearFlag_Minute(RTCB);
		FL_RTCB_EnableIT_Minute(RTCB);
		FL_RTCB_ClearFlag_Day(RTCB);
		FL_RTCB_EnableIT_Day(RTCB);
	
		// 从flash中读取用户配置的闹钟
		W25Q64_ReadData(W25Q64_ALARM_HOUR_ADDR, &alarm_hour, 1);
		W25Q64_ReadData(W25Q64_ALARM_MINUTE_ADDR, &alarm_minute, 1);
	
		while (1) {
				// 阻塞等待通知值被设置
				ulTaskNotifyTake(pdFALSE, portMAX_DELAY);
				FL_RTCB_InitTypeDef RTCB_InitStruct;
				RTCB_GetRTCB(&RTCB_InitStruct);
			
				if ((BCD2Oct(RTCB_InitStruct.hour)==alarm_hour)&&(BCD2Oct(RTCB_InitStruct.minute)==alarm_minute)) {
						is_alarming = 1;
						// 如果处于录音界面，则终止录音关闭文件，跳转到ok界面然后跳转到闹钟界面
						if(&window_3 == gui.active_window ){
								// 通知结束录制
								xTaskNotifyGive(xRecordingStartTaskHandle);
							
								UG_WindowHide(&window_3);
								UG_WindowShow(&window_2);	
							
								// 等待录制收尾结束
								ulTaskNotifyTake(pdFALSE, portMAX_DELAY);								
						}
						else if(&window_4 == gui.active_window) {
								// 通知结束录制
								xTaskNotifyGive(xRecordingStartTaskHandle);
							
								UG_WindowHide(&window_4);
								UG_WindowShow(&window_2);
							
								// 等待播放收尾结束
								ulTaskNotifyTake(pdFALSE, portMAX_DELAY);	
						}
						// 如果处于播放界面，则终止播放关闭文件，跳转到音频文件选择界面然后跳转到闹钟界面
						else if(&window_7 == gui.active_window) {
								// 通知结束播放
								xTaskNotifyGive(xPlayerStartTaskHandle);
							
								UG_WindowHide(&window_7);
								UG_WindowShow(&window_5);
							
								// 等待播放收尾结束
								ulTaskNotifyTake(pdFALSE, portMAX_DELAY);						
						}
						else if(&window_8 == gui.active_window) {
								// 通知结束播放
								xTaskNotifyGive(xPlayerStartTaskHandle);
							
								UG_WindowHide(&window_8);
								UG_WindowShow(&window_5);
							
								// 等待播放收尾结束
								ulTaskNotifyTake(pdFALSE, portMAX_DELAY);	
						}
						vTaskDelay(20);
						
						// 置位状态，显示响铃界面
						ringing();
						// 播放闹钟音频
						xTaskNotifyGive(xAlarmPlayTaskHandle);
				}
			 
				if(daterenew){
						sprintf(dateStr, "%d%02x/%02x/%02x", front_year ,RTCB_InitStruct.year,  RTCB_InitStruct.month,RTCB_InitStruct.day);
						UG_TextboxShow( &window_1, TXB_ID_1 );
						daterenew = 0;
				}
				
				sprintf(timeStr, "%02x:%02x",  RTCB_InitStruct.hour,  RTCB_InitStruct.minute);
				UG_TextboxShow( &window_1, TXB_ID_0 );
	 }
}



static void countsecondsTask(void *pvParameters){
		while (1) {
					//一秒更新一次
				vTaskDelay(1000);
				// 录音界面的计时
				if ( &window_3 == gui.active_window ){
						countseconds++;
						format_time(countseconds, ui_seconds);
						UG_TextboxShow( &window_3, TXB_ID_2 );
				}
				// 播放界面的计时
				if ( &window_7 == gui.active_window ){
						countseconds++;
						// 如果播放时间到达总时长，则跳转至待播放界面
						if (countseconds == audio_total_seconds) {
								countseconds = 0;
								format_time(countseconds, ui_seconds);
								sprintf(ui_seconds, "%s/%s", ui_seconds, audio_total_seconds_str);
								UG_WindowHide(&window_7);
								UG_WindowShow(&window_8);					
						}
						else {
								format_time(countseconds, ui_seconds);
								sprintf(ui_seconds, "%s/%s", ui_seconds, audio_total_seconds_str);
								UG_TextboxShow( &window_7, TXB_ID_9 );				
						}
				}
				
		}
}

//窗口一被切换后关闭rtc中断，避免打断其他任务，应在切换回来后启动
void stopUitimerenew(void){
		
		FL_RTCB_DisableIT_Minute(RTCB);	
		
		FL_RTCB_DisableIT_Day(RTCB);
}

//打开rtc中断，更新时间
void startUitimerenew(void){
	
		FL_RTCB_InitTypeDef    RTCB_InitStruct;
		RTCB_GetRTCB(&RTCB_InitStruct);
	
		sprintf(dateStr, "20%02x/%02x/%02x",  RTCB_InitStruct.year,  RTCB_InitStruct.month,RTCB_InitStruct.day);
		UG_TextboxShow( &window_1, TXB_ID_1 );
	
		sprintf(timeStr, "%02x:%02x",  RTCB_InitStruct.hour,  RTCB_InitStruct.minute);
		UG_TextboxShow( &window_1, TXB_ID_0 );
		
		FL_RTCB_ClearFlag_Minute(RTCB);
		FL_RTCB_EnableIT_Minute(RTCB);	
		FL_RTCB_ClearFlag_Day(RTCB);
		FL_RTCB_EnableIT_Day(RTCB);
	
	
}


//获取RTCB模块的时间到 ram
uint8_t RTCB_GetRTCB(FL_RTCB_InitTypeDef *InitStructer)
{
    uint8_t n, i;
    uint8_t Result = 1;

    FL_RTCB_InitTypeDef TempTime1, TempTime2;

    for(n = 0 ; n < 3; n++)
    {
        FL_RTCB_GetTime(RTCB, &TempTime1);                  //读一次时间
        FL_RTCB_GetTime(RTCB, &TempTime2);                  //再读一次时间

        for(i = 0; i < 7; i++)                              //两者一致, 表示读取成功
        {
            if(((uint32_t *)(&TempTime1))[i] != ((uint32_t *)(&TempTime2))[i]) { break; }
        }

        if(i == 7)
        {
            Result = 0;
            memcpy((uint32_t *)(InitStructer), (uint32_t *)(&TempTime1), 7 * sizeof(uint32_t)); //读取正确则更新新的时间
            break;
        }
    }

    return Result;
}



//设置ram的时间到RTCB模块
uint8_t RTCB_SetRTCB(FL_RTCB_InitTypeDef *InitStructer)
{
    uint8_t n, i;
    uint8_t Result;
    FL_RTCB_InitTypeDef TempTime1;

    for(n = 0 ; n < 3; n++)
    {
        FL_RTCB_ConfigTime(RTCB, InitStructer);
        Result = RTCB_GetRTCB(&TempTime1);                  //读取确认设置结果

        if(Result == 0)
        {
            Result = 1;

            for(i = 0; i < 7; i++)                          //两者一致, 表示设置成功
            {
                if(((uint32_t *)(&TempTime1))[i] != ((uint32_t *)(InitStructer))[i])
                { break; }
            }

            if(i == 7)
            {
                Result = 0;
                break;
            }
        }
    }

    return Result;
}
