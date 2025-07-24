/* wav格式的相关操作 */
#ifndef __WAV_H__
#define __WAV_H__

#include "fm33fk5xx_fl.h"


void wav_create();
void wav_recorder_start();
void wav_write_buffer_once();
void wav_write_pause();
void wav_write_continue();
void wav_stopwrite();

uint32_t audio_duration_compute(uint32_t dataSize, uint32_t read_sample_rate);
void wavheader_read(const char* filename);
void wav_speaker_start();
void wav_read_once();
void wav_read_pause();
void wav_read_continue();
void wav_stopread();
void wav_reload_and_wait();


//wav文件头
typedef struct WAVE_HEADER{  
		char         fccID[4];        
		uint32_t 		 dwSize;            
		char         fccType[4];    
}WAVE_HEADER;  

typedef struct WAVE_FMT{  
		char         fccID[4];        
		uint32_t     dwSize;            
		uint16_t     wFormatTag;    
		uint16_t     wChannels;  
		uint32_t     dwSamplesPerSec;  
		uint32_t     dwAvgBytesPerSec;  
		uint16_t     wBlockAlign;  
		uint16_t     uiBitsPerSample;  
}WAVE_FMT;  
 
typedef struct WAVE_DATA{  
		char     fccID[4];          
		uint32_t dwSize;              
}WAVE_DATA;  


#endif