/* wav格式的相关操作 */
#include "wav.h"
#include "myff.h"
#include "dma.h"
#include "recorder.h"
#include "i2s.h"
#include <string.h>
#include "rtc.h"
#include "semphr.h"

WAVE_HEADER   wavHEADER;  
WAVE_FMT    	wavFMT;  
WAVE_DATA   	DATAHEADER;

// 解析数据使用
uint8_t temp[3];
uint8_t* point;

// touch的任务句柄，用于暂时挂起和恢复
extern TaskHandle_t xScanTaskHandle;

#include "stdio.h"
/********************************************************
	音频录制
*********************************************************/
// 录制开始写入，创建文件并添加文件头
void wav_create(){
		uint8_t channels = 2;

		get_rtc_time_str(time_str);
		sprintf(new_audio_name_path, "0:/recorder/%s.wav", time_str);
		
//		printf("%s\n", new_audio_name_path);
//		res = f_open(&file, "0:/recorder/250619223455.wav", FA_WRITE | FA_OPEN_ALWAYS);
//		res = f_open(&file, "0:/recorder/Alarm.wav", FA_WRITE | FA_OPEN_ALWAYS);
		res = f_open(&file, new_audio_name_path, FA_WRITE | FA_OPEN_ALWAYS);
		
		if (res != FR_OK) {
				printf("Open failed, error number: %d\r\n", res);
		}
		
		f_lseek(&file, sizeof(WAVE_HEADER));

		wavFMT.dwSamplesPerSec  = sample_rate;  
    wavFMT.dwAvgBytesPerSec = wavFMT.dwSamplesPerSec*channels*3;  
    wavFMT.uiBitsPerSample  = 24;
    memcpy(wavFMT.fccID,"fmt ",strlen("fmt "));  
    wavFMT.dwSize = 16;  
    wavFMT.wBlockAlign = channels*3;  
    wavFMT.wChannels   = channels;  
    wavFMT.wFormatTag  = 1; 

		res = f_write(&file, &wavFMT, sizeof(wavFMT), &wr_count);
		if (res != FR_OK) {
				printf("Write failed, error number: %d\r\n", res);
		}
		
		f_lseek(&file, sizeof(WAVE_HEADER) + sizeof(WAVE_FMT) + sizeof(WAVE_DATA));		
}


// 启动I2S DMA传输
void wav_recorder_start() {
		// 启动DMA
		which_databuffer = 0;
		vTaskDelay(10);
		Mic_DMA_Trasnsfer(data_buffer0, data_buffer1, data_buff_len);
}


// 录制时DMA I2S满一次时，用于处理该满buffer并写入
void wav_write_buffer_once(){
		point = buftemp;
		// 切换buffer
		current_buf = which_databuffer ? data_buffer1 : data_buffer0;
	
		//24位数据 小端存储
		for(uint16_t i = 0; i < data_buff_len; i++){
				temp[0] = current_buf[i] ;
				temp[1] = current_buf[i] >> 8;
				temp[2] = current_buf[i] >> 16;
				memcpy(point, temp, 3);
				
				point += 3;
		}
		
		vTaskSuspend(xScanTaskHandle);
		f_write(&file, buftemp, buftemp_len, &wr_count);
		vTaskResume(xScanTaskHandle);
		writeSize += wr_count;

		which_databuffer = !which_databuffer;
}



// 录制暂停
void wav_write_pause() {
		// 停止MIC I2S DMA传输
		FL_DMA_DisableChannel(DMA, MIC_I2S_DMA_CHANNEL);
}

// 录制继续
void wav_write_continue() {
		// 启动DMA
		wav_recorder_start();
}



// 录制写入结束
void wav_stopwrite(){
		// 停止MIC I2S DMA传输
		FL_DMA_DisableChannel(DMA, MIC_I2S_DMA_CHANNEL);
		vTaskDelay(10);		// 等待wav_write_buffer_once处理完毕
	
	  // WAVE_HEADER
    memcpy(wavHEADER.fccID,"RIFF",strlen("RIFF"));                    
    memcpy(wavHEADER.fccType,"WAVE",strlen("WAVE")); 
		wavHEADER.dwSize = sizeof(WAVE_HEADER) + sizeof(WAVE_FMT) + writeSize;
	
		memcpy(DATAHEADER.fccID,"data",strlen("data"));   
		DATAHEADER.dwSize = writeSize;
		
		f_lseek(&file, 0);
		
		f_write(&file, &wavHEADER, sizeof(wavHEADER), &wr_count);
		f_lseek(&file, sizeof(WAVE_HEADER) + sizeof(WAVE_FMT));
		f_write(&file, &DATAHEADER, sizeof(DATAHEADER), &wr_count);
	
		f_close(&file);

		// 清除写入个数
		writeSize = 0;
		
		// 新写入的录音挂载到内部链表
		strncat(time_str, ".wav", 4);
		fileList_append(&wavfileList, time_str);
//		fileList_print(&wavfileList);
		
//		printf("%s\n", time_str);
		// 通知GUI可读取新名称字符串
		if (!is_alarming) xSemaphoreGive(xGUIRecordInfo_Sema);
}


/********************************************************
	音频播放
*********************************************************/
// 根据采样率和大小计算音频时长。双声道，每个音频数据3字节，因此read_sample_rate乘6
uint32_t audio_duration_compute(uint32_t dataSize, uint32_t read_sample_rate) {
		return dataSize/(read_sample_rate * 6) + 1; 	// +1是因为向上取整
}


// 播放时用于预装载两个播放buf，load的位置与执行到此处时的readsize有关，可适配从头播放和中途播放
static void preload_buffers() {
		// 预装填buf0
		f_read(&file, &buftemp, buftemp_len, &rd_count);
		readSize += rd_count;
		
		point = buftemp;

		memset(data_buffer0, 0, data_buff_size);
		for(uint16_t i = 0; i < data_buff_len; i++) 
		{
				// 取出一个24位数据
				memcpy(temp, point, 3);	
				point += 3;
				
				// 转换为32位小端格式
				data_buffer0[i] |= (uint32_t)temp[2] << 16;
				data_buffer0[i]	|= (uint32_t)temp[1] << 8;
				data_buffer0[i]	|= (uint32_t)temp[0];		
		}
		
		// 预装填buf1
		f_read(&file, &buftemp, buftemp_len, &rd_count);
		readSize += rd_count;
		
		point = buftemp;

		memset(data_buffer1, 0, data_buff_size);
		for(uint16_t i = 0; i < data_buff_len; i++)
		{
				// 取出一个24位数据
				memcpy(temp, point, 3);
				point += 3;
			
				// 转换为32位小端格式
				data_buffer1[i] |= (uint32_t)temp[2] << 16;
				data_buffer1[i]	|= (uint32_t)temp[1] << 8;
				data_buffer1[i]	|= (uint32_t)temp[0];	
		}
}


// 播放时读取并解析wav文件头
void wavheader_read(const char* filename){
		f_open(&file, filename, FA_READ | FA_OPEN_EXISTING);	

		// 读取三个header
		f_read(&file, &wavHEADER, sizeof(WAVE_HEADER), &rd_count);
		f_read(&file, &wavFMT, sizeof(WAVE_FMT), &rd_count);
		f_read(&file, &DATAHEADER, sizeof(WAVE_DATA), &rd_count);
	
		// 解析音频长度
		dataSize = DATAHEADER.dwSize;
		// 解析采样率，用于初始化播放频率和计算音频时长
		read_sample_rate = wavFMT.dwSamplesPerSec;
		Speaker_I2S_Config(read_sample_rate);
	
		// 调试信息，打印header内容
//		printf("wavHEADER.dwSize %d\n", wavHEADER.dwSize);
//		printf("wavHEADER.fccID %s\n", wavHEADER.fccID);
//		printf("wavHEADER.fccType %s\n", wavHEADER.fccType);
//		printf("wavFMT.dwAvgBytesPerSec %d\n", wavFMT.dwAvgBytesPerSec);
//		printf("wavFMT.dwSamplesPerSec %d\n", wavFMT.dwSamplesPerSec);
//		printf("wavFMT.dwSize %d\n", wavFMT.dwSize);	
//		printf("wavFMT.fccID %s\n", wavFMT.fccID);	
//		printf("wavFMT.uiBitsPerSample %d\n", wavFMT.uiBitsPerSample);	
//		printf("wavFMT.wBlockAlign %d\n", wavFMT.wBlockAlign);	
//		printf("wavFMT.wChannels %d\n", wavFMT.wChannels);	
//		printf("wavFMT.wFormatTag %d\n", wavFMT.wFormatTag);	
//		printf("DATAHEADER.dwSize %d\n", DATAHEADER.dwSize);	
//		printf("DATAHEADER.fccID %s\n", DATAHEADER.fccID);	


		// 计算音频时长
		audio_total_seconds = audio_duration_compute(dataSize, read_sample_rate);
		
		if (!is_alarming) {
				// 通知GUI可读取音频时长
				xSemaphoreGive(xGUIAudioSeconds_Sema);
		}
		
		// 清空readsize
		readSize = 0;
}


// 启动speaker I2S DMA传输
void wav_speaker_start() {
		// 开启DMA前预装填两个DMAbuf，确保第一次双缓冲发送的是已装填的buf
		preload_buffers();

		// 启动DMA
		vTaskDelay(10);	
		which_databuffer = 0;	
		Speaker_DMA_Trasnsfer(data_buffer0, data_buffer1, data_buff_len);
}


// 读取一次并解析到发送buf
void wav_read_once() {
		static uint32_t rest_bytes = 0; // 剩余未读的字节大小
		static uint32_t read_len = 0;		// 单次需要读出的字节大小		
		static uint8_t end_flag = 0;
	
		static uint32_t previous_sample = 0;	// 遍历中保存前一个样本值，用于瞬态抑制滤波
		const int32_t threshold_clip = 524288;	// 0x40000
	
		// 切换buffer
		current_buf = which_databuffer ? data_buffer1 : data_buffer0;
	
		// 若dataSize仍大于readSize，说明有数据未读
		if (dataSize > readSize) {
				rest_bytes = dataSize - readSize;
				read_len = (rest_bytes >= buftemp_len) ? buftemp_len : rest_bytes;		
				
				// 防止最后有脏数据
				if (read_len == rest_bytes)	memset(buftemp, 0, buftemp_len);
			
				vTaskSuspend(xScanTaskHandle);
				f_read(&file, &buftemp, read_len, &rd_count);
				vTaskResume(xScanTaskHandle);
				readSize += rd_count;
				
				point = buftemp;
			
				memset(current_buf, 0, data_buff_size);
				for(uint16_t i = 0; i < data_buff_len; i++) 
				{
						// 取出一个24位数据
						memcpy(temp, point, 3);	
						point += 3;
						
						// 转换为32位小端格式
						current_buf[i] |= (uint32_t)temp[2] << 16;
						current_buf[i] |= (uint32_t)temp[1] << 8;
						current_buf[i] |= (uint32_t)temp[0];		
					
						// 符号位扩展，判断第23位符号
						if (current_buf[i] & 0x800000) {
								current_buf[i] |= 0xFF000000;
						} else {
								current_buf[i] &= 0x00FFFFFF;
						}
						
						// 限幅滤波
						int64_t delta = (int64_t)((int32_t)current_buf[i] - (int32_t)previous_sample);
						const int32_t max_delta = 120000; // 最大允许变化率

						if (delta > max_delta) {
								current_buf[i] = previous_sample + max_delta;
						} else if(delta < -max_delta) {
								current_buf[i] = previous_sample - max_delta;
						} else {
								previous_sample = current_buf[i];						
						}
						
//						if ((int32_t)current_buf[i] > threshold_clip) {
//								current_buf[i] = previous_sample;
//						}
//						else if ((int32_t)current_buf[i] < -threshold_clip) {
//								current_buf[i] = previous_sample;
//						}	
//						else {
//								previous_sample = current_buf[i];
//						}
						
						current_buf[i] <<= volume_value;
				}
				which_databuffer = !which_databuffer;	
		}	
		// 否则已经读完
		else {
				// 第二次进入该分支后停止播放
				if (end_flag) {
						wav_reload_and_wait();
						end_flag = 0;
						previous_sample = 0;
						
						// 如果处于闹钟中，则继续自动循环播放
						if (is_alarming) {
								wav_read_continue();
						}
				} else {
						end_flag = 1;
				}
		}
}


//暂停
void wav_read_pause(){
		FL_DMA_DisableChannel(DMA, SPEAKER_I2S_DMA_CHANNEL);
}

//取消暂停
void wav_read_continue(){ 
		// 重置I2S
		Speaker_I2S_Config(read_sample_rate);
		wav_speaker_start();
}

// 用于播放完成一次之后重新复位而不关闭文件，等待重新开始音频播放
void wav_reload_and_wait() {
		FL_DMA_DisableChannel(DMA, SPEAKER_I2S_DMA_CHANNEL);
		f_lseek(&file, sizeof(WAVE_HEADER) + sizeof(WAVE_FMT) + sizeof(WAVE_DATA));		
		readSize = 0;
}


// 退出播放，关闭音频文件
void wav_stopread() {		
		FL_DMA_DisableChannel(DMA, SPEAKER_I2S_DMA_CHANNEL);
		f_close(&file);
	
//		printf("read over");
	
		readSize = 0;
		dataSize = 0;
}


