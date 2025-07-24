/* 录音和播放任务 */
#include "recorder.h"
#include "wav.h"
#include "myff.h"
#include "semphr.h"
#include "rtc.h"


// 写入缓冲区大小为BoubleBufferDMASize*3
#define dbBufferDMASize 1024

// 32位双缓存I2S DMA原始数据
__attribute__((aligned(4))) uint32_t data_buffer0[dbBufferDMASize];
__attribute__((aligned(4))) uint32_t data_buffer1[dbBufferDMASize];
uint16_t data_buff_len = sizeof(data_buffer0)>>2;
uint16_t data_buff_size = sizeof(data_buffer0);
uint32_t * current_buf; // 指向当前正在写入的buffer

// 24位写入/读取缓存
uint8_t buftemp[dbBufferDMASize * 3];
uint16_t buftemp_len = sizeof(buftemp);

// 待处理数组标志
bool which_databuffer = 0; 

// 读写暂时变量
uint32_t writeSize = 0; // 写入的总字节大小
uint32_t readSize  = 0; // 已读的总字节大小
uint32_t pause_read_size = 0;	// 暂停处的readsize记录
uint32_t dataSize  = 0; // 待读文件的数据总字节大小

// 录制的采样率和播放的采样率，为防止播放篡改写入采样率故用了两个变量。
const uint32_t sample_rate = FL_I2S_AUDIOFREQ_8K;
uint32_t read_sample_rate;

// 新录制的文件名，同时用于添加进内部链表
char new_audio_name_path[40];
char time_str[30];	// 时间字符串缓冲

// 正在闹钟标志位
bool is_alarming = 0;

// 音量调节
uint8_t volume_value;

// 任务句柄
// 录音
TaskHandle_t xRecordingStartTaskHandle = NULL;
TaskHandle_t xAudioRecordingTaskHandle = NULL;
TaskHandle_t xRecordingPauseTaskHandle = NULL;
TaskHandle_t xRecordingContinueTaskHandle = NULL;
// 播放
TaskHandle_t xPlayerStartTaskHandle = NULL;
TaskHandle_t xAudioPlayingTaskHandle = NULL;
TaskHandle_t xPlayingPauseTaskHandle = NULL;
TaskHandle_t xPlayingContinueTaskHandle = NULL;
// 闹钟
TaskHandle_t xAlarmPlayTaskHandle = NULL;

// 函数原型
// 录音
static void AudioRecordStart(void* pvParameters);
static void AudioRecording(void* pvParameters);
static void RecordingPause(void* pvParameters);
static void RecordingContinue(void* pvParameters);
// 播放
static void AudioPlayStart(void* pvParameters);
static void AudioPlaying(void* pvParameters);
static void PlayingPause(void* pvParameters);
static void PlayingContinue(void* pvParameters);
// 闹钟
static void AlarmPlay(void* pvParameters);

// 信号量
SemaphoreHandle_t xGUIAudioSeconds_Sema = NULL;	// 用于GUI中更新音频时间的信号量
SemaphoreHandle_t xGUIRecordInfo_Sema = NULL;	// 用于GUI中提示录制信息的信号量


#include "stdio.h"
// 启动录音和播放任务，并提供较高的优先级，保证录制播放正常	
void recorder_start() {
		xGUIAudioSeconds_Sema = xSemaphoreCreateBinary();
		xGUIRecordInfo_Sema = xSemaphoreCreateBinary();
	
		// 录制
		xTaskCreate(AudioRecordStart, 	"rcdstt", 	256,  NULL, 6, &xRecordingStartTaskHandle);
		xTaskCreate(AudioRecording, 		"rcding", 	256,  NULL, 6, &xAudioRecordingTaskHandle);
		xTaskCreate(RecordingPause, 		"rcdpau", 	128,  NULL, 6, &xRecordingPauseTaskHandle);
		xTaskCreate(RecordingContinue, 	"rcdctn", 	256,  NULL, 6, &xRecordingContinueTaskHandle);
	
		// 播放
		xTaskCreate(AudioPlayStart, 	"plystt", 	256,  NULL, 6, &xPlayerStartTaskHandle);
		xTaskCreate(AudioPlaying, 		"plying", 	256,  NULL, 6, &xAudioPlayingTaskHandle);	
		xTaskCreate(PlayingPause, 		"plypau", 	128,  NULL, 6, &xPlayingPauseTaskHandle);
		xTaskCreate(PlayingContinue, 	"plyctn", 	256,  NULL, 6, &xPlayingContinueTaskHandle);
	
		// 闹钟
		xTaskCreate(AlarmPlay, "alarm", 	256,  NULL, 6, &xAlarmPlayTaskHandle);	
}



// 开始和结束录音
static void AudioRecordStart(void* pvParameters) {
		while(1) {
				// 创建wav header并开始录制
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_create();
				wav_recorder_start();
				printf("write start.\r\n");
			
				// 关闭写入，处理后事
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_stopwrite();
				if (is_alarming) xTaskNotifyGive(xUitimeTaskHandle);
				printf("write over.\r\n");
		}
}

// 录音中
static void AudioRecording(void* pvParameters) {
		while(1) {
				// 等待来自DMA中断的通知
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
			
				wav_write_buffer_once();	
		}
}

// 录音暂停
static void RecordingPause(void* pvParameters) {
		while(1) {
				// 等待来自DMA中断的通知
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_write_pause();
		}
}

// 录音继续
static void RecordingContinue(void* pvParameters) {
		while(1) {
				// 等待来自DMA中断的通知
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_write_continue();
		}
}


// 开始和结束播放
static void AudioPlayStart(void* pvParameters) {
		char *pcfilename;
		uint32_t ulNotificationValue;
		while(1) {
				// 任务通知实现长度为1的轻量级队列，传递filename的字符串指针
				ulNotificationValue = ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
			
				// 获取文件名字符串
				if(ulNotificationValue) {
						pcfilename = (char *)ulNotificationValue;
						// 读取wav header并开始播放			
						wavheader_read(pcfilename);
						wav_speaker_start();
						printf("read start\n");
				}
				
				// 等待关闭播放
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_stopread();
				if (is_alarming) xTaskNotifyGive(xUitimeTaskHandle);
				printf("read over\n");
		}
}


// 播放中
static void AudioPlaying(void* pvParameters) {
		while(1) {
				// 等待来自DMA中断的通知
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_read_once();
		}
}

// 播放暂停
static void PlayingPause(void* pvParameters) {
		while(1) {
				// 等待来自DMA中断的通知
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_read_pause();
		}
}

// 播放继续
static void PlayingContinue(void* pvParameters) {
		while(1) {
				// 等待来自DMA中断的通知
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_read_continue();
		}
}

// 用于闹钟铃声循环播放，复用AudioPlaying
static void AlarmPlay(void* pvParameters) {
		while(1) {
				// 等待闹钟发送任务通知唤醒
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
			
				// 读取wav header并开始播放			
				wavheader_read("0:/recorder/Alarm.wav");
				wav_speaker_start();			
			
				// 等待关闭闹钟
				ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
				wav_stopread();
				is_alarming = 0;
		}
}


