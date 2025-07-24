/* 录音和播放任务 */
#ifndef _RECORDER_H_
#define _RECORDER_H_

#include "fm33fk5xx_fl.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

//// 后续定义一个音频格式结构体，里面放该音频格式的各种录制和播放函数，如
//typedef {

//}AudioFormat;

// 读写变量
extern uint32_t writeSize; // 写入的总字节大小
extern uint32_t readSize; // 已读的总字节大小
extern uint32_t pause_read_size;	// 暂停处的readsize记录
extern uint32_t dataSize; // 待读文件的数据总字节大小

// 录制的采样率和播放的采样率
extern const uint32_t sample_rate;
extern uint32_t read_sample_rate;

extern char new_audio_name_path[40];
extern char time_str[30];

extern bool is_alarming;
extern uint8_t volume_value;

//DMA双缓存数组
extern uint32_t data_buffer0[];
extern uint32_t data_buffer1[];
extern uint16_t data_buff_len;
extern uint16_t data_buff_size;
extern uint8_t 	buftemp[];
extern uint16_t buftemp_len;
extern uint32_t * current_buf;
extern bool which_databuffer;

// 任务句柄
extern TaskHandle_t xRecordingStartTaskHandle;
extern TaskHandle_t xAudioRecordingTaskHandle;
extern TaskHandle_t xRecordingPauseTaskHandle;
extern TaskHandle_t xRecordingContinueTaskHandle;
extern TaskHandle_t xPlayerStartTaskHandle;
extern TaskHandle_t xAudioPlayingTaskHandle;
extern TaskHandle_t xPlayingPauseTaskHandle;
extern TaskHandle_t xPlayingContinueTaskHandle;
extern TaskHandle_t xAlarmPlayTaskHandle;

extern SemaphoreHandle_t xGUIAudioSeconds_Sema;
extern SemaphoreHandle_t xGUIRecordInfo_Sema;

void recorder_start();

#endif