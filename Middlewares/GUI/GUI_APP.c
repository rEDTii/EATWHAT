/* GUI */
#include "GUI_APP.h"
#include "uart.h"
#include "picture.h"
#include "myff.h"
#include "task.h"
#include "semphr.h"
#include "wav.h"
#include "recorder.h"
#include "rtc.h"
#include "w25q64.h"
#include "lcd.h"

// player当前页数
static uint8_t playerpage = 1;
// ui显示页数
char  ui_page[9];
//用户操作提示词
char  ui_prompt[30];
// 闹钟提示词
char  alarm_prompt[30];
// player待处理文件
char * file_clicked;
// 年份前缀
uint8_t front_year = 20;
// 亮度和volume的setting str
char setting_str[5];

static bool exitpage = 0;
//窗口复用标志
static bool setting_clicked = 0;
static bool alarm_clicked = 0;
static bool alarm_ringing = 0;
// 亮度和音量是哪个的标志位
static bool brightness_volume_setting = 0;
static uint8_t date_choice = 1;

// 保存闹钟设置的临时值
uint8_t temp_alarm_hour;
uint8_t temp_alarm_minute;


FL_RTCB_InitTypeDef    RTCB_Struct;

/* image */

const UG_BMP mic= { (void*)gImage_mic,
											60,
											59,
											BMP_BPP_16,
											BMP_RGB565
											};

											
const UG_BMP music= { (void*)gImage_music,
											60,
											58,
											BMP_BPP_16,
											BMP_RGB565
											};				


const UG_BMP Start = { (void*)gImage_Start,
											60,
											58,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Exit = { (void*)gImage_Exit,
											39,
											40,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Stop = { (void*)gImage_Stop,
											60,
											58,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Pause = { (void*)gImage_Pause,
											60,
											60,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Continue = { (void*)gImage_continue,
											60,
											60,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Arrow_down = { (void*)gImage_arrow_down,
											38,
											40,
											BMP_BPP_16,
											BMP_RGB565
											};

const UG_BMP Arrow_up = { (void*)gImage_arrow_up,
											38,
											40,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Setting = { (void*)gImage_setting,
											58,
											60,
											BMP_BPP_16,
											BMP_RGB565
											};
const UG_BMP Alarm = { (void*)gImage_alarm,
											60,
											57,
											BMP_BPP_16,
											BMP_RGB565
											};



/* Window 1 */
UG_WINDOW  window_1;
UG_OBJECT  obj_buff_wnd_1[6];

UG_TEXTBOX textbox1_1;
UG_TEXTBOX textbox1_2;

UG_IMAGE image1_1;
UG_IMAGE image1_2;
UG_IMAGE image1_3;
UG_IMAGE image1_4;
							
/* Window 2 */
UG_WINDOW  window_2;
UG_OBJECT  obj_buff_wnd_2[3];

UG_IMAGE image2_1;
UG_IMAGE image_exit;																						
																						
UG_TEXTBOX textbox2_1;
											


/* Window 3 */
UG_WINDOW  window_3;
UG_OBJECT  obj_buff_wnd_3[6];	

UG_IMAGE image3_1;
UG_IMAGE image3_2;


UG_TEXTBOX textbox3_2;	
UG_TEXTBOX textbox3_3;

UG_TEXTBOX playrecordtime;

/* Window 4 */
UG_WINDOW  window_4;
UG_OBJECT  obj_buff_wnd_4[6];	

UG_IMAGE image4_1;
UG_IMAGE image4_2;
//UG_IMAGE image4_3;

//UG_TEXTBOX textbox4_1;
UG_TEXTBOX textbox4_2;	
UG_TEXTBOX textbox4_3;

/* Window 5 */
UG_WINDOW  window_5;
UG_OBJECT  obj_buff_wnd_5[11];	

//UG_IMAGE image5_1;
UG_IMAGE image_arrowdown;
UG_IMAGE image_arrowup;

UG_BUTTON button5_1;
UG_BUTTON button5_2;
UG_BUTTON button5_3;
UG_BUTTON button5_4;
UG_BUTTON button5_5;
UG_BUTTON button5_6;

UG_TEXTBOX textbox5_1;

/* Window 6 */
UG_WINDOW  window_6;
UG_OBJECT  obj_buff_wnd_6[4];

//UG_IMAGE image6_1;

UG_BUTTON button6_1;
UG_BUTTON button6_2;

UG_TEXTBOX textbox6_1;

/* Window 7 */
UG_WINDOW  window_7;
UG_OBJECT  obj_buff_wnd_7[4];	

UG_IMAGE image7_1;

UG_TEXTBOX textbox7_1;

/* Window 8 */
UG_WINDOW  window_8;
UG_OBJECT  obj_buff_wnd_8[4];	

UG_IMAGE image8_1;

UG_TEXTBOX textbox8_1;

/* Window 9 */
UG_WINDOW  window_9;
UG_OBJECT  obj_buff_wnd_9[2];	

UG_BUTTON button_ok;
UG_TEXTBOX textbox9_1;

/* Window 10 */
UG_WINDOW  window_10;
UG_OBJECT  obj_buff_wnd_10[7];

UG_TEXTBOX textbox10_1;

/* Window 11 */
UG_WINDOW  window_11;
UG_OBJECT  obj_buff_wnd_11[9];

UG_TEXTBOX textbox11_1;
UG_TEXTBOX textbox11_2;

UG_BUTTON button11_1;
UG_BUTTON button11_2;
UG_BUTTON button11_3;

/* Window 12 */
UG_WINDOW  window_12;
UG_OBJECT  obj_buff_wnd_12[2];	

UG_BUTTON button_ok;
UG_TEXTBOX textbox12_1;

/* Window 13 */
UG_WINDOW  window_13;
UG_OBJECT  obj_buff_wnd_13[7];

UG_TEXTBOX textbox13_1;

/* Window 14 */
UG_WINDOW  window_14;
UG_OBJECT  obj_buff_wnd_14[5];

UG_TEXTBOX textbox14_1;






/*gui*/
UG_GUI gui ; 

//画线
UG_RESULT _HW_DrawLine( UG_S16 x1,UG_S16 y1,UG_S16 x2,UG_S16 y2,UG_COLOR c){
	
	LCD_DrawLine((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, c);
	
	return UG_RESULT_OK;
}

//填充
UG_RESULT _HW_FillFrame( UG_S16 x1,UG_S16 y1,UG_S16 x2,UG_S16 y2,UG_COLOR c){
	
	LCD_Fill((uint16_t)x1, (uint16_t)y1, (uint16_t)x2, (uint16_t)y2, c);
	
	return UG_RESULT_OK;
}

//画点
void _HW_DrawPoint(UG_S16 x,UG_S16 y,UG_COLOR c){
	
	LCD_DrawPoint((uint16_t)x,(uint16_t)y, (uint32_t)c);
}






//设置player显示的歌曲
void Menu_Update(void){
		fileNameNode* cur = wavfileList.head;
		uint16_t i;
		for (i = 1; cur; i++, cur = cur->next) {        
				if((i >= 1 + (playerpage - 1)*6) && (i <= playerpage*6 )){
						UG_ButtonSetText(&window_5, i - (playerpage - 1)*6,cur->fileName);
				}
				if(i > playerpage*6) break;
		}
		while(i <= playerpage*6){
				UG_ButtonSetText(&window_5, i-(playerpage -1)*6,NULL);
				i++;
		}
}


//闹钟响铃
void ringing(void){
		alarm_ringing = 1;
		sprintf(alarm_prompt, "Ringing!");		
		UG_WindowShow(&window_12);
}




void uGUI_Init(void)
{
    UG_Init( &gui, (void(*)(UG_S16,UG_S16,UG_COLOR))_HW_DrawPoint, 320, 480);
		#if 1
				UG_DriverRegister(DRIVER_DRAW_LINE, (void *)_HW_DrawLine);
				UG_DriverRegister(DRIVER_FILL_FRAME, (void *)_HW_FillFrame);
				UG_DriverEnable(DRIVER_DRAW_LINE);
				UG_DriverEnable(DRIVER_FILL_FRAME);
		#else
				UG_DriverDisable(DRIVER_DRAW_LINE);
				UG_DriverDisable(DRIVER_FILL_FRAME);
		#endif
				UG_FillScreen(C_BLACK);
}


void window_1_callback(UG_MESSAGE* msg){
		
		if( msg->type== MSG_TYPE_OBJECT){
			
			if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED ){
				switch (msg->sub_id){
					case IMG_ID_0 :
					{ 
//						stopUitimerenew();
						UG_WindowSetTitleInactiveColor(&window_1, C_BLACK ); 					
						UG_WindowShow(&window_2);
						UG_Update();
						break;
					}
					case IMG_ID_1 :
					{
//						stopUitimerenew();
						UG_WindowSetTitleInactiveColor(&window_1, C_BLACK ); 					
						playerpage = 1;
						Menu_Update();
						sprintf(ui_page, "%d/%d", playerpage,(wavfileList.size-1)/6+1);
						UG_WindowSetTitleText( &window_5,"Player" );
						UG_WindowShow(&window_5);
						UG_Update();
						break;
					
					}
					case IMG_ID_2 :
					{ 
//						stopUitimerenew();
						UG_WindowSetTitleInactiveColor(&window_1, C_BLACK );
						setting_clicked = 1;
						sprintf(ui_page, "1/1");
						UG_ButtonSetText(&window_5, 1,"Time Setting");
						UG_ButtonSetText(&window_5, 2,"Date Setting");
						UG_ButtonSetText(&window_5, 3,"Brightness Setting");
						UG_ButtonSetText(&window_5, 4,"Volumn Setting");
						UG_ButtonSetText(&window_5, 5,NULL);
						UG_ButtonSetText(&window_5, 6,NULL);
						UG_ButtonSetText(&window_5, 7,NULL);
						UG_ButtonSetText(&window_5, 8,NULL);
						UG_WindowSetTitleText( &window_5,"Setting" );
						UG_WindowShow(&window_5);
						UG_Update();
						break;
					}
					case IMG_ID_3 :  //闹钟
					{
						UG_WindowSetTitleInactiveColor(&window_1, C_BLACK );
						alarm_clicked = 1;
						temp_alarm_hour = alarm_hour;
						temp_alarm_minute = alarm_minute;
						sprintf(alarmtimeStr, "%02d:%02d",  temp_alarm_hour, temp_alarm_minute);
						UG_WindowSetTitleText( &window_13,"Alarm Setting" );
						UG_WindowShow(&window_13);
						UG_Update();
						break;
					
					}
				}
			}
		}
}



void window_2_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
			if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED ){
				switch (msg->sub_id){
					case IMG_ID_2 :
					{  
						// 通知开始录音
						xTaskNotifyGive(xRecordingStartTaskHandle);					
						
						countseconds = 0;
						sprintf(ui_seconds, "00:00:00");
						UG_WindowHide(&window_2);
						UG_WindowShow(&window_3);
						UG_Update();
						break;
					}
					case IMG_ID_3 :
					{
						UG_WindowHide(&window_2);
						UG_WindowShow(&window_1);
						UG_Update();
//						startUitimerenew();
						break;
					}
				}
			}
		}
}

void window_3_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event ==OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){
						case IMG_ID_4 :
						{  
							// 通知暂停录音
							xTaskNotifyGive(xRecordingPauseTaskHandle);				
//							wav_write_pause();
							
							
							UG_WindowHide(&window_3);
							UG_WindowShow(&window_4);
							UG_Update();
							break;
						}
						case IMG_ID_5 :
						{
							// 通知结束录音
							xTaskNotifyGive(xRecordingStartTaskHandle);			

							// 等待recorder处理好新录入文件
							xSemaphoreTake(xGUIRecordInfo_Sema, portMAX_DELAY);
							sprintf(ui_prompt,"%s%s",time_str," saved!");
 					
							UG_WindowHide(&window_3);
							UG_WindowShow(&window_9);
							UG_Update();
							break;
						}
						case IMG_ID_6 :
						{
							// 录音中退出直接结束录音
							xTaskNotifyGive(xRecordingStartTaskHandle);			
							
							// 等待recorder处理好新录入文件
							xSemaphoreTake(xGUIRecordInfo_Sema, portMAX_DELAY);
							sprintf(ui_prompt,"%s%s",time_str," saved!");
							
							UG_WindowHide(&window_3);
							exitpage = 1;
							UG_WindowShow(&window_9);
							UG_Update();
							break;
						}
					}
				}
			}
}

void window_4_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){
						case IMG_ID_7 :
						{  
							// 从暂停状态恢复继续录音
							xTaskNotifyGive(xRecordingContinueTaskHandle);	
							
							UG_WindowHide(&window_4);
							UG_WindowShow(&window_3);
							UG_Update();
							break;
						}
						case IMG_ID_8 :
						{
							// 通知结束录音
							xTaskNotifyGive(xRecordingStartTaskHandle);		
							
							// 等待recorder处理好新录入文件
							xSemaphoreTake(xGUIRecordInfo_Sema, portMAX_DELAY);
							sprintf(ui_prompt,"%s%s",time_str," saved!");
							
							UG_WindowHide(&window_4);
							UG_WindowShow(&window_9);
							UG_Update();
							break;
						}
						case IMG_ID_9 :
						{
							// 录音中退出直接结束录音
							xTaskNotifyGive(xRecordingStartTaskHandle);							
							
							// 等待recorder处理好新录入文件
							xSemaphoreTake(xGUIRecordInfo_Sema, portMAX_DELAY);
							sprintf(ui_prompt,"%s%s",time_str," saved!");
							
							UG_WindowHide(&window_4);
							exitpage = 1;
							UG_WindowShow(&window_9);							
							UG_Update();
							break;
						}
					}
				}
			}
}

void window_5_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED && !setting_clicked ){ //player界面
					switch (msg->sub_id){
						case IMG_ID_10 : //退出键
						{ 
							UG_WindowHide(&window_5);
							UG_WindowShow(&window_1);
							UG_Update();
//							startUitimerenew();
							break;
						}
						case IMG_ID_11 :
						{
							if(playerpage <= (wavfileList.size - 1)/6 ){
								playerpage++;
								sprintf(ui_page, "%d/%d", playerpage,(wavfileList.size-1)/6+1);
								UG_TextboxShow(&window_5, TXB_ID_5 );
								Menu_Update();								
							}
							break;							
						}
						case IMG_ID_12 :
						{
							if(playerpage > 1){
								playerpage--;
								sprintf(ui_page, "%d/%d", playerpage,(wavfileList.size-1)/6+1);
								UG_TextboxShow(&window_5, TXB_ID_5 );
								Menu_Update();
								break;
							}							
						}
							
					}
				} else if( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED && setting_clicked ){  //setting界面
							
						switch (msg->sub_id){
								case IMG_ID_10 : //退出键
								{ 
									setting_clicked = 0;
									UG_WindowHide(&window_5);
									UG_WindowShow(&window_1);
									UG_Update();
//									startUitimerenew();
									break;
								}
								case IMG_ID_11 :
								{
									break;							
								}
								case IMG_ID_12 :
								{
									break;					
								}
									
						}
				}
				
				if ( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && !setting_clicked){ //player界面
					switch (msg->sub_id){
						case BTN_ID_1:
						{  
							if(UG_ButtonGetText(&window_5,BTN_ID_1)){
								file_clicked = UG_ButtonGetText(&window_5,BTN_ID_1);
								UG_TextboxSetText(&window_6, TXB_ID_8,file_clicked);
								UG_WindowSetTitleInactiveColor(&window_5, C_DARK_GRAY); 					
								UG_WindowShow(&window_6);
								UG_Update();
							}
							break;
						}
						case BTN_ID_2:
						{
							if(UG_ButtonGetText(&window_5,BTN_ID_2)){
								file_clicked = UG_ButtonGetText(&window_5,BTN_ID_2);
								UG_TextboxSetText(&window_6, TXB_ID_8,file_clicked);
								UG_WindowSetTitleInactiveColor(&window_5, C_DARK_GRAY); 					
								UG_WindowShow(&window_6);
								UG_Update();
							}
							break;
						}	
						case BTN_ID_3:
						{
							if(UG_ButtonGetText(&window_5,BTN_ID_3)){
								file_clicked = UG_ButtonGetText(&window_5,BTN_ID_3);
								UG_TextboxSetText(&window_6, TXB_ID_8,file_clicked);
								UG_WindowSetTitleInactiveColor(&window_5, C_DARK_GRAY); 					
								UG_WindowShow(&window_6);
								UG_Update();
							}
							break;
						}	
						case BTN_ID_4:
						{
							if(UG_ButtonGetText(&window_5,BTN_ID_4)){
								file_clicked = UG_ButtonGetText(&window_5,BTN_ID_4);
								UG_TextboxSetText(&window_6, TXB_ID_8,file_clicked);
								UG_WindowSetTitleInactiveColor(&window_5, C_DARK_GRAY); 					
								UG_WindowShow(&window_6);
								UG_Update();
							}
							break;
						}	
						case BTN_ID_5:
						{
							if(UG_ButtonGetText(&window_5,BTN_ID_5)){
								file_clicked = UG_ButtonGetText(&window_5,BTN_ID_5);
								UG_TextboxSetText(&window_6, TXB_ID_8,file_clicked);
								UG_WindowSetTitleInactiveColor(&window_5, C_DARK_GRAY); 					
								UG_WindowShow(&window_6);
								UG_Update();
							}
							break;
						}	
						case BTN_ID_6:
						{
							if(UG_ButtonGetText(&window_5,BTN_ID_6)){
								file_clicked = UG_ButtonGetText(&window_5,BTN_ID_6);
								UG_TextboxSetText(&window_6, TXB_ID_8,file_clicked);
								UG_WindowSetTitleInactiveColor(&window_5, C_DARK_GRAY); 					
								UG_WindowShow(&window_6);
								UG_Update();
							}
							break;
						}						
					}
				}	else if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && setting_clicked ){  //setting界面
					
							switch (msg->sub_id){
								case BTN_ID_1: //timesetting
								{
									UG_WindowSetTitleText( &window_10,"Time Setting" );
									RTCB_GetRTCB(&RTCB_Struct);
									sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
									UG_WindowHide(&window_5);
									UG_WindowShow(&window_10);
									UG_Update();
									break;
								}
								case BTN_ID_2: //datesetting
								{ 
									
									/*gettime*/		
									RTCB_GetRTCB(&RTCB_Struct);	
									sprintf(dateStr, "%d%02x", front_year, RTCB_Struct.year);
									UG_TextboxSetText(&window_11, TXB_ID_9,"Year");
									UG_WindowHide(&window_5);
									UG_WindowShow(&window_11);
									UG_Update();	
									break;
								}
								case BTN_ID_3: //brightness setting
								{ 
									brightness_volume_setting = 0;
									sprintf(setting_str, "%3d", brightness);
									UG_TextboxShow( &window_14, TXB_ID_8 );	
									UG_WindowSetTitleText( &window_14,"Brightness Setting" );
									UG_WindowHide(&window_5);
									UG_WindowShow(&window_14);
									UG_Update();	
									break;
								}
								case BTN_ID_4: //volumn setting
								{ 
									brightness_volume_setting = 1;
									sprintf(setting_str, "%2d", volume_value+1);
									UG_TextboxShow( &window_14, TXB_ID_8 );	
									UG_WindowSetTitleText( &window_14,"Volume Setting" );
									UG_WindowHide(&window_5);
									UG_WindowShow(&window_14);
									UG_Update();	
									break;
								}
						}
				}
			}
}




// 用于记录临时文件路径
char dic[40];

void window_6_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){
						case IMG_ID_12 :
						{  
							UG_WindowHide(&window_6);
							UG_WindowShow(&window_5);
							UG_Update();
							break;
						}						
					}
				}
				if ( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){
						case BTN_ID_7 :  //player键
						{ 
							// 通知开始播放，并发送文件名的指针过去
							sprintf(dic, "0:/recorder/");
							if(file_clicked) xTaskNotify(xPlayerStartTaskHandle, (uint32_t)strncat(dic,file_clicked,strlen(file_clicked)), eSetValueWithOverwrite);							
							
							// 等待recorder读取到音频时长
							xSemaphoreTake(xGUIAudioSeconds_Sema, portMAX_DELAY);
							uint8_t hours = audio_total_seconds / 3600;
							uint8_t mins  = (audio_total_seconds % 3600) / 60;
							uint8_t secs  = audio_total_seconds % 60;	
							sprintf(audio_total_seconds_str, "%02d:%02d:%02d", hours, mins, secs);
							
							countseconds = 0;
							sprintf(ui_seconds, "00:00:00/%s", audio_total_seconds_str);	
							UG_WindowHide(&window_6);
							UG_WindowShow(&window_7);
							UG_Update();

							break;
						}
						case BTN_ID_8 :
						{  
							sprintf(dic, "0:/recorder/");
							f_unlink (strncat(dic, file_clicked, strlen(file_clicked)));
							fileList_remove(&wavfileList, file_clicked);
							Menu_Update();
							UG_WindowHide(&window_6);
							UG_WindowShow(&window_5);
							UG_Update();
							break;
						}
					}
				}
			}
}

void window_7_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event ==OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){
						case IMG_ID_13 :   //暂停键
						{  		
							// 暂停player
							xTaskNotifyGive(xPlayingPauseTaskHandle);	
							
							UG_WindowHide(&window_7);
							UG_WindowShow(&window_8);
							UG_Update();
							break;
						}
						case IMG_ID_15 :  //退出键
						{
							// 关闭player	
							xTaskNotifyGive(xPlayerStartTaskHandle);
							
							UG_WindowHide(&window_7);
							UG_WindowShow(&window_5);
							UG_Update();
							break;
						}
					}
				}
			}
}


void window_8_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event ==OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){
						case IMG_ID_16 :   //继续键
						{  		
							// 继续play
							xTaskNotifyGive(xPlayingContinueTaskHandle);	
							
							UG_WindowHide(&window_8);
							UG_WindowShow(&window_7);
							UG_Update();
							break;
						}
						case IMG_ID_18 :  //退出键
						{
							// 关闭play
							xTaskNotifyGive(xPlayerStartTaskHandle);
							
							UG_WindowHide(&window_8);
							UG_WindowShow(&window_5);
							UG_Update();
							break;
						}
					}
				}
			}
}


void window_9_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && !setting_clicked && !alarm_clicked){ //录音完成使用 
					switch (msg->sub_id){
						case BTN_ID_7 : 
						{ 
							if(exitpage){
								UG_WindowHide(&window_9);
								UG_WindowShow(&window_1);
								UG_Update();
//								startUitimerenew();
							}else{
								UG_WindowHide(&window_9);
								UG_WindowShow(&window_2);
								UG_Update();
							}
							
							break;
						}
					}
				}
				else if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && setting_clicked){ //时间setting使用
				
					switch (msg->sub_id){
						case BTN_ID_7 : 
						{ 
							UG_WindowHide(&window_9);
							UG_WindowShow(&window_5);
							UG_Update();							
							break;
						}
					}
				}
				else if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && alarm_clicked){ //闹钟setting使用
				
					switch (msg->sub_id){
						case BTN_ID_7 :							
						{ 
							alarm_clicked = 0;
							UG_WindowHide(&window_9);
							UG_WindowShow(&window_1);
							UG_Update();							
							break;
						}
					}
				}
			}
}


void window_10_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && setting_clicked){  //设置时间
					switch (msg->sub_id){
						case BTN_ID_7 :  //ok键
						{ 
							RTCB_SetRTCB(&RTCB_Struct);
							UG_WindowHide(&window_10);
							sprintf(ui_prompt, "Settings completed!");
							UG_WindowShow(&window_9);
							UG_Update();
							break;
						}
					}				
				}
				
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED && setting_clicked ){
						switch (msg->sub_id){
								case BTN_ID_1: //分钟减
								{ 
									if(RTCB_Struct.minute){
										RTCB_Struct.minute = (BCD2Oct(RTCB_Struct.minute) -1)%60;
										RTCB_Struct.minute = Oct2BCD(RTCB_Struct.minute);
									}else{
										RTCB_Struct.minute = 0x59;
									}
									
									sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,   RTCB_Struct.minute);
									UG_TextboxShow( &window_10, TXB_ID_8 );	
									break;
								}
								case BTN_ID_2: //小时减
								{ 
									if(RTCB_Struct.hour){
										RTCB_Struct.hour =  (BCD2Oct(RTCB_Struct.hour) -1)%24;
										RTCB_Struct.hour =  Oct2BCD(RTCB_Struct.hour);
									}else {
										RTCB_Struct.hour = 0x23;
									}
									
									sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
									UG_TextboxShow( &window_10, TXB_ID_8 );
									break;
									
								}
								case BTN_ID_3: //分钟加
								{ 
									RTCB_Struct.minute = (BCD2Oct(RTCB_Struct.minute) + 1)%60;
									RTCB_Struct.minute =  Oct2BCD(RTCB_Struct.minute);
									sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
									UG_TextboxShow( &window_10, TXB_ID_8 );	
									break;
								}
								case BTN_ID_4: //小时加
								{ 
									
									RTCB_Struct.hour = (BCD2Oct(RTCB_Struct.hour) +1)%24;
									RTCB_Struct.hour = Oct2BCD(RTCB_Struct.hour);
									sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
									UG_TextboxShow( &window_10, TXB_ID_8 );
									break;
									
								}
								case BTN_ID_5: //退出
								{ 
									RTCB_GetRTCB(&RTCB_Struct);  //没有设置，校准时间
			
									sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
									sprintf(dateStr, "%d%02x/%02x/%02x",  front_year ,RTCB_Struct.year,  RTCB_Struct.month,RTCB_Struct.day);

									UG_WindowHide(&window_10);
									UG_WindowShow(&window_5);
									UG_Update();

									break;
								}
						}				
				}
		}
}


void window_11_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if ( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED ){  
					switch (msg->sub_id){
						case BTN_ID_7 :  //ok键
						{
							uint32_t year  =  RTCB_Struct.year;
							uint32_t month =  RTCB_Struct.month;
							int dayinmonth = getDaysInMonth(front_year*100 +  BCD2Oct(RTCB_Struct.year),  BCD2Oct(RTCB_Struct.month));
							if(RTCB_Struct.day >= Oct2BCD(dayinmonth)){										
								RTCB_Struct.day = Oct2BCD(dayinmonth);
							}
							
							uint32_t day   =  RTCB_Struct.day;
							
						
//							if(BCD2Oct(day) > lastday)  day = Oct2BCD(lastday);
							
							RTCB_GetRTCB(&RTCB_Struct);
							RTCB_Struct.year  = year ;
							RTCB_Struct.month = month;
							RTCB_Struct.day   = day  ;
							
							RTCB_SetRTCB(&RTCB_Struct);
							sprintf(dateStr, "%d%02x/%02x/%02x", front_year ,RTCB_Struct.year,  RTCB_Struct.month , RTCB_Struct.day);
							UG_TextboxShow( &window_1, TXB_ID_1 );
							UG_WindowHide(&window_11);
							sprintf(ui_prompt, "Settings completed!");
							UG_WindowShow(&window_9);
							UG_Update();
							break;
						}
					}
						if(date_choice == 1){ //设置年份
							switch (msg->sub_id){
								case BTN_ID_9 :  //month键
								{
									date_choice = 2;
									UG_TextboxSetText(&window_11, TXB_ID_9,"Month");
									UG_TextboxShow( &window_11, TXB_ID_9 );
									sprintf(dateStr, " %02x ",  RTCB_Struct.month);
									UG_TextboxShow( &window_11, TXB_ID_8 );	
									break;
								}
								case BTN_ID_11 :  //day键
								{
									date_choice = 3;
									UG_TextboxSetText(&window_11, TXB_ID_9,"Day");
									UG_TextboxShow( &window_11, TXB_ID_9 );
									int dayinmonth = getDaysInMonth(front_year*100 +  BCD2Oct(RTCB_Struct.year),  BCD2Oct(RTCB_Struct.month));
									if(RTCB_Struct.day >= Oct2BCD(dayinmonth)){										
										RTCB_Struct.day = Oct2BCD(dayinmonth);
									}
									sprintf(dateStr, " %02x ",  RTCB_Struct.day);
									UG_TextboxShow( &window_11, TXB_ID_8 );	
									break;
								}
							}
						}
						if(date_choice == 2){  //设置月份
							switch (msg->sub_id){
								case BTN_ID_8 :  //year键
								{	
									date_choice = 1;
									UG_TextboxSetText(&window_11, TXB_ID_9,"Year");
									UG_TextboxShow( &window_11, TXB_ID_9 );
									sprintf(dateStr, "%d%02x", front_year, RTCB_Struct.year);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
								case BTN_ID_11 :  //day键
								{
									date_choice = 3;
									UG_TextboxSetText(&window_11, TXB_ID_9,"Day");
									UG_TextboxShow( &window_11, TXB_ID_9 );
									int dayinmonth = getDaysInMonth(front_year*100 +  BCD2Oct(RTCB_Struct.year),  BCD2Oct(RTCB_Struct.month));
									if(RTCB_Struct.day >= Oct2BCD(dayinmonth)){										
										RTCB_Struct.day = Oct2BCD(dayinmonth);
									}
									sprintf(dateStr, " %02x ",  RTCB_Struct.day);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
							}
						}
						if(date_choice == 3){ //设置天数
							switch (msg->sub_id){
								case BTN_ID_8 :  //year键
								{	
									date_choice = 1;
									UG_TextboxSetText(&window_11, TXB_ID_9,"Year");
									UG_TextboxShow( &window_11, TXB_ID_9 );
									sprintf(dateStr, "%d%02x", front_year, RTCB_Struct.year);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
								case BTN_ID_9 :  //month键
								{
									date_choice = 2;
									UG_TextboxSetText(&window_11, TXB_ID_9,"Month");
									UG_TextboxShow( &window_11, TXB_ID_9 );
									sprintf(dateStr, " %02x ",  RTCB_Struct.month);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
							}
						}
				} 
					
				
				if ( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED ){
					switch (msg->sub_id){						
							case IMG_ID_5: //退出
							{ 
								date_choice = 1;
								RTCB_GetRTCB(&RTCB_Struct);  //没有设置，校准时间
									
								sprintf(dateStr, "%d%02x/%02x/%02x",front_year,  RTCB_Struct.year,  RTCB_Struct.month,RTCB_Struct.day);
								UG_TextboxShow( &window_1, TXB_ID_1 );								
								UG_WindowHide(&window_10);
								UG_WindowShow(&window_5);
								UG_Update();												
								break;
							}
					}
					if(date_choice == 1){ //设置年份
							switch (msg->sub_id){
								case IMG_ID_1 :  //减键
								{	
									if(RTCB_Struct.year){
										RTCB_Struct.year = BCD2Oct(RTCB_Struct.year) - 1;
										RTCB_Struct.year =  Oct2BCD(RTCB_Struct.year);								
									}else{
										front_year--;
										RTCB_Struct.year = 0x99;
									}
									sprintf(dateStr, "%d%02x", front_year, RTCB_Struct.year);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
								case IMG_ID_2 :  //加键
								{
									if(RTCB_Struct.year == 0x99){
										front_year++;
										RTCB_Struct.year = 0x00;
									}else{
										RTCB_Struct.year = BCD2Oct(RTCB_Struct.year) + 1;
										RTCB_Struct.year =  Oct2BCD(RTCB_Struct.year);
									}
									sprintf(dateStr, "%d%02x", front_year, RTCB_Struct.year);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
							}
						}
						if(date_choice == 2){  //设置月份
							switch (msg->sub_id){
								case IMG_ID_1 :  //减键
								{	
									if(RTCB_Struct.month == 0x01){										
										RTCB_Struct.month = 0x12;
									}else{
										RTCB_Struct.month = BCD2Oct(RTCB_Struct.month) - 1;
										RTCB_Struct.month =  Oct2BCD(RTCB_Struct.month);
									}
									sprintf(dateStr, " %02x ",  RTCB_Struct.month);
									UG_TextboxShow( &window_11, TXB_ID_8 );								
									break;
								}
								case IMG_ID_2 :  //加键
								{
									if(RTCB_Struct.month == 0x12){										
										RTCB_Struct.month = 0x01;
									}else{
										RTCB_Struct.month = BCD2Oct(RTCB_Struct.month) + 1;
										RTCB_Struct.month =  Oct2BCD(RTCB_Struct.month);
									}
									sprintf(dateStr, " %02x ",  RTCB_Struct.month);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
							}
						}
						if(date_choice == 3){ //设置天数
							int dayinmonth = getDaysInMonth(front_year*100 +  BCD2Oct(RTCB_Struct.year),  BCD2Oct(RTCB_Struct.month));
							switch (msg->sub_id){
								case IMG_ID_1 :  //减键
								{
									
									if(RTCB_Struct.day == 0x01){										
										RTCB_Struct.day = Oct2BCD(dayinmonth);
									}else{
										RTCB_Struct.day = BCD2Oct(RTCB_Struct.day) - 1;
										RTCB_Struct.day =  Oct2BCD(RTCB_Struct.day);
									}
									sprintf(dateStr, " %02x ",  RTCB_Struct.day);
									UG_TextboxShow( &window_11, TXB_ID_8 );																	
									break;
								}
								case IMG_ID_2 :  //加键
								{
									if(RTCB_Struct.day == Oct2BCD(dayinmonth)){										
										RTCB_Struct.day = 0x01;
									}else{
										RTCB_Struct.day = BCD2Oct(RTCB_Struct.day) + 1;
										RTCB_Struct.day =  Oct2BCD(RTCB_Struct.day);
									}
									sprintf(dateStr, " %02x ",  RTCB_Struct.day);
									UG_TextboxShow( &window_11, TXB_ID_8 );
									break;
								}
							}
						}									
				}
			}
}



void window_12_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && alarm_ringing ){ //闹钟响了使用
						switch (msg->sub_id){
								case BTN_ID_7 :  //关闭闹钟
								{ 
										// 关闭闹钟
										xTaskNotifyGive(xAlarmPlayTaskHandle);
										
										alarm_ringing = 0;
										UG_WindowHide(&window_12);							
										break;
								}
						}
				}
		}
}


void window_13_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && alarm_clicked ){ //设置闹钟
						switch (msg->sub_id){
								case BTN_ID_7 :  //ok键
								{ 
										// 闹钟设置
										alarm_hour = temp_alarm_hour;
										alarm_minute = temp_alarm_minute;
										
										W25Q64_WriteData(W25Q64_ALARM_HOUR_ADDR, &alarm_hour, 1);
										W25Q64_WriteData(W25Q64_ALARM_MINUTE_ADDR, &alarm_minute, 1);
									
										UG_WindowHide(&window_13);
										sprintf(ui_prompt, "Settings completed!");
										UG_WindowShow(&window_9);
										UG_Update();
										break;
								}
						}
				}
					
				if( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED && alarm_clicked ) {
						switch (msg->sub_id){
								case BTN_ID_1: //分钟减
								{ 
									if(temp_alarm_minute){
										temp_alarm_minute = (temp_alarm_minute -1)%60;
									}else{
										temp_alarm_minute = 59;
									}
									
									sprintf(alarmtimeStr, "%02d:%02d",  temp_alarm_hour, temp_alarm_minute);
									UG_TextboxShow( &window_13, TXB_ID_8 );	
									break;
								}
								case BTN_ID_2: //小时减
								{ 
									if(temp_alarm_hour){
										temp_alarm_hour =  (temp_alarm_hour -1)%24;
									}else {
										temp_alarm_hour = 23;
									}
									
									sprintf(alarmtimeStr, "%02d:%02d",  temp_alarm_hour,  temp_alarm_minute);
									UG_TextboxShow( &window_13, TXB_ID_8 );
									break;
									
								}
								case BTN_ID_3: //分钟加
								{ 
									temp_alarm_minute = (temp_alarm_minute + 1)%60;
									sprintf(alarmtimeStr, "%02d:%02d",  temp_alarm_hour,  temp_alarm_minute);
									UG_TextboxShow( &window_13, TXB_ID_8 );	
									break;
								}
								case BTN_ID_4: //小时加
								{ 		
									temp_alarm_hour = (temp_alarm_hour +1)%24;
									sprintf(alarmtimeStr, "%02d:%02d",  temp_alarm_hour,  temp_alarm_minute);
									UG_TextboxShow( &window_13, TXB_ID_8 );
									break;
									
								}
								case BTN_ID_5: //退出
								{ 
									alarm_clicked = 0;
									UG_WindowHide(&window_13);
									UG_WindowShow(&window_1);
									UG_Update();

									break;
								}
						}		
				}
		}
}



void window_14_callback(UG_MESSAGE* msg){
		if( msg->type== MSG_TYPE_OBJECT){
				if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && !brightness_volume_setting ){ // 设置亮度和音量
						switch (msg->sub_id){
								case BTN_ID_7 :  //ok键
								{ 
										// 亮度值保存，并设置
										Set_PWM_BL(brightness);
									
										// 写入flash
										W25Q64_WriteData(W25Q64_BRIGHTNESS_ADDR, &brightness, 1);
									
										UG_WindowHide(&window_14);
										sprintf(ui_prompt, "Settings completed!");
										UG_WindowShow(&window_9);
										UG_Update();
										break;
								}
						}
				} else if( msg->id == OBJ_TYPE_BUTTON && msg->event == OBJ_EVENT_RELEASED && brightness_volume_setting ) { // 音量设置
						switch (msg->sub_id){
								case BTN_ID_7 :  //ok键
								{ 
										// 写入flash
										W25Q64_WriteData(W25Q64_VOLUME_ADDR, &volume_value, 1);
									
										UG_WindowHide(&window_14);
										sprintf(ui_prompt, "Settings completed!");
										UG_WindowShow(&window_9);
										UG_Update();
										break;
								}
						}
				}
					
				if( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED && !brightness_volume_setting ) {	// 亮度设置
						switch (msg->sub_id){
								case BTN_ID_1: //减
								{ 
									if (brightness > 20) {
											brightness -= 20;
									}
									sprintf(setting_str, "%3d",  brightness);
									UG_TextboxShow( &window_14, TXB_ID_8 );	
									break;
								}
								case BTN_ID_2: //加
								{ 
									if (brightness < 100) {
											brightness += 20;
									}
									sprintf(setting_str, "%3d",  brightness);
									UG_TextboxShow( &window_14, TXB_ID_8 );	
									break;
								}
								case BTN_ID_5: //退出
								{ 
									UG_WindowHide(&window_14);
									UG_WindowShow(&window_5);
									UG_Update();
									break;
								}
						}		
				} else if( msg->id == OBJ_TYPE_IMAGE && msg->event == OBJ_EVENT_RELEASED && brightness_volume_setting ) {	// 音量设置
						switch (msg->sub_id){
								case BTN_ID_1: //减
								{ 
									if (volume_value > 0) {
											volume_value -= 1;
									}
									sprintf(setting_str, "%2d",  volume_value+1);
									UG_TextboxShow( &window_14, TXB_ID_8 );	
									break;
								}
								case BTN_ID_2: //加
								{ 
									if (volume_value < 2) {
											volume_value += 1;
									}
									sprintf(setting_str, "%2d",  volume_value+1);
									UG_TextboxShow( &window_14, TXB_ID_8 );	
									break;
								}
								case BTN_ID_5: //退出
								{ 
									UG_WindowHide(&window_14);
									UG_WindowShow(&window_5);
									UG_Update();
									break;
								}
						}	
				}
		}
}



void uGUI_Window1(void)
{
	  /* Create Window 1 */
    UG_WindowCreate(&window_1, obj_buff_wnd_1, 6, window_1_callback);
    UG_WindowSetStyle(&window_1,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_1, C_BLACK);
		
	
		//window title
		UG_WindowSetTitleColor(  &window_1, C_BLACK );
		UG_WindowSetTitleText( &window_1,"EATWHAT V1.0" );
		UG_WindowSetTitleTextFont( &window_1, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(  &window_1, ALIGN_CENTER );
	
	
		/* Create Image 1 */
		UG_ImageCreate( &window_1, &image1_1, IMG_ID_0, 80, 180, 140, 240 );
		UG_ImageSetBMP( &window_1, IMG_ID_0, &mic);
	
		/* Create Image 2 */
		UG_ImageCreate( &window_1, &image1_2, IMG_ID_1, 80, 270, 140, 330 );
		UG_ImageSetBMP( &window_1, IMG_ID_1, &music);
		
		/* Create Image 3 */
		UG_ImageCreate( &window_1, &image1_3, IMG_ID_2, 180, 270, 240, 330 );
		UG_ImageSetBMP( &window_1, IMG_ID_2, &Setting);
		
		/* Create Image 4 */
		UG_ImageCreate( &window_1, &image1_4, IMG_ID_3, 180, 180, 240, 240 );
		UG_ImageSetBMP( &window_1, IMG_ID_3, &Alarm);
		
  
		/*gettime*/
		RTCB_GetRTCB(&RTCB_Struct);
		
		sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
		sprintf(dateStr, "20%02x/%02x/%02x",  RTCB_Struct.year,  RTCB_Struct.month,RTCB_Struct.day);
		
		
		/* Create Textbox 1 */
		UG_TextboxCreate(&window_1, &textbox1_1, TXB_ID_0, 0, 30, 171, 90);
    
		UG_TextboxSetFont(&window_1, TXB_ID_0, &FONT_32X53);
		UG_TextboxSetForeColor(&window_1, TXB_ID_0,C_WHITE );
    UG_TextboxSetText(&window_1, TXB_ID_0,timeStr);
    //UG_TextboxSetAlignment(&window_1, TXB_ID_0, ALIGN_CENTER );

		
		/* Create Textbox 2 */
		UG_TextboxCreate(&window_1, &textbox1_2, TXB_ID_1, 20, 100, 310, 130);
    
		UG_TextboxSetFont(&window_1, TXB_ID_1,  &FONT_12X20);
		UG_TextboxSetForeColor(&window_1, TXB_ID_1,C_WHITE );
		UG_TextboxSetAlignment(&window_1, TXB_ID_1, ALIGN_CENTER );
    UG_TextboxSetText(&window_1, TXB_ID_1,dateStr);
		
}

void uGUI_Window2(void)
{
    /* Create Window 2 */
    UG_WindowCreate(&window_2, obj_buff_wnd_2, 3, window_2_callback);
    UG_WindowSetStyle(&window_2,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_2, C_DARK_GRAY);
		UG_WindowResize(&window_2, 20, 80, 300, 400);
		
	
		//window title
		UG_WindowSetTitleColor(&window_2, C_GRAY );
		UG_WindowSetTitleText( &window_2,"Recorder" );
		UG_WindowSetTitleTextFont( &window_2, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_2, ALIGN_CENTER );
   
		
		/* Create Image 1 */
		UG_ImageCreate( &window_2, &image2_1, IMG_ID_2, 110, 120, 170, 180 );
		UG_ImageSetBMP( &window_2, IMG_ID_2, &Start);	
		
		/* Create Image 2 */
		UG_ImageCreate( &window_2, &image_exit, IMG_ID_3, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_2, IMG_ID_3, &Exit);


			/* Create Textbox 1 */
    UG_TextboxCreate(&window_2, &textbox2_1, TXB_ID_1, 15, 190, 279, 215 );
    UG_TextboxSetFont(&window_2, TXB_ID_1, &FONT_12X20);
    UG_TextboxSetText(&window_2, TXB_ID_1, "START ");
    UG_TextboxSetAlignment(&window_2, TXB_ID_1, ALIGN_CENTER );
}

void uGUI_Window3(void){
	
	  /* Create Window 3 */
    UG_WindowCreate(&window_3, obj_buff_wnd_3, 6, window_3_callback);
    UG_WindowSetStyle(&window_3,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_3, C_DARK_GRAY);
		UG_WindowResize(&window_3, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_3, C_GRAY );
		UG_WindowSetTitleText( &window_3,"Recorder" );
		UG_WindowSetTitleTextFont( &window_3, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_3, ALIGN_CENTER );
	
		/* Create Image 1  */
		UG_ImageCreate( &window_3, &image3_1, IMG_ID_4, 50, 120, 110, 180 );
		UG_ImageSetBMP( &window_3, IMG_ID_4, &Pause);

		/* Create Image 2 */
		UG_ImageCreate( &window_3, &image3_2, IMG_ID_5, 170, 120, 230, 180 );
		UG_ImageSetBMP( &window_3, IMG_ID_5, &Stop);
		
		/* Create Image 3 */
		UG_ImageCreate( &window_3, &image_exit, IMG_ID_6, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_3, IMG_ID_6, &Exit);
		
		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_3, &playrecordtime, TXB_ID_2, 10, 30, 270, 50);
		UG_TextboxSetFont(&window_3, TXB_ID_2, &FONT_12X20);
		UG_TextboxSetText(&window_3, TXB_ID_2, ui_seconds);
		UG_TextboxSetAlignment(&window_3, TXB_ID_2, ALIGN_CENTER );
		
		/* Create Textbox 2 */
    UG_TextboxCreate(&window_3, &textbox3_2, TXB_ID_3, 50, 190, 110, 230 );
    UG_TextboxSetFont(&window_3, TXB_ID_3, &FONT_12X20);
    UG_TextboxSetText(&window_3, TXB_ID_3, "Pause");
    //UG_TextboxSetAlignment(&window_2, TXB_ID_3, ALIGN_CENTER );
		
		/* Create Textbox 3 */
    UG_TextboxCreate(&window_3, &textbox3_3, TXB_ID_4, 173, 190, 230, 230 );
    UG_TextboxSetFont(&window_3, TXB_ID_4, &FONT_12X20);
    UG_TextboxSetText(&window_3, TXB_ID_4, "Stop");
    //UG_TextboxSetAlignment(&window_2, TXB_ID_4, ALIGN_CENTER );
		
}

void uGUI_Window4(void){
	
	  /* Create Window 4 */
    UG_WindowCreate(&window_4, obj_buff_wnd_4, 6, window_4_callback);
    UG_WindowSetStyle(&window_4,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_4, C_DARK_GRAY);
		UG_WindowResize(&window_4, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_4, C_GRAY );
		UG_WindowSetTitleText( &window_4,"Recorder" );
		UG_WindowSetTitleTextFont( &window_4, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_4, ALIGN_CENTER );
	
		/* Create Image 1  */
		UG_ImageCreate( &window_4, &image4_1, IMG_ID_7, 50, 120, 110, 180 );
		UG_ImageSetBMP( &window_4, IMG_ID_7, &Continue);

		/* Create Image 2 */
		UG_ImageCreate( &window_4, &image4_2, IMG_ID_8, 170, 120, 230, 180 );
		UG_ImageSetBMP( &window_4, IMG_ID_8, &Stop);
		
		/* Create Image 3 */
		UG_ImageCreate( &window_4,&image_exit, IMG_ID_9, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_4, IMG_ID_9, &Exit);
		
		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_4, &playrecordtime, TXB_ID_5, 10, 30, 270, 50);
		UG_TextboxSetFont(&window_4, TXB_ID_5, &FONT_8X14);
		UG_TextboxSetText(&window_4, TXB_ID_5, ui_seconds);
		UG_TextboxSetAlignment(&window_2, TXB_ID_5, ALIGN_CENTER );
		
		/* Create Textbox 2 */
    UG_TextboxCreate(&window_4, &textbox4_2, TXB_ID_6, 32, 190, 128, 230 );
    UG_TextboxSetFont(&window_4, TXB_ID_6, &FONT_12X20);
    UG_TextboxSetText(&window_4, TXB_ID_6, "Continue");
    //UG_TextboxSetAlignment(&window_2, TXB_ID_3, ALIGN_CENTER );
		
		/* Create Textbox 3 */
    UG_TextboxCreate(&window_4, &textbox4_3, TXB_ID_7, 173, 190, 230, 230 );
    UG_TextboxSetFont(&window_4, TXB_ID_7, &FONT_12X20);
    UG_TextboxSetText(&window_4, TXB_ID_7, "Stop");
    //UG_TextboxSetAlignment(&window_2, TXB_ID_4, ALIGN_CENTER );
		

}


void uGUI_Window5(void){

	  /* Create Window 5 */
    UG_WindowCreate(&window_5, obj_buff_wnd_5, 11, window_5_callback);
    UG_WindowSetStyle(&window_5,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_5, C_DARK_GRAY);
		UG_WindowResize(&window_5, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_5, C_GRAY );		
		UG_WindowSetTitleTextFont( &window_5, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_5, ALIGN_CENTER );
	
		/* Create Image 1 */
		UG_ImageCreate( &window_5, &image_exit, IMG_ID_10, 235, 255, 279, 310 );
		UG_ImageSetBMP( &window_5, IMG_ID_10, &Exit);
	
		/* Create Image 2 */
		UG_ImageCreate( &window_5, &image_arrowdown, IMG_ID_11,121, 255,161, 310 );
		UG_ImageSetBMP( &window_5, IMG_ID_11, &Arrow_down);
		
		/* Create Image 3 */
		UG_ImageCreate( &window_5, &image_arrowup, IMG_ID_12,121, 10,161, 50 );
		UG_ImageSetBMP( &window_5, IMG_ID_12, &Arrow_up);
	
		 /* Create Button 1-6*/
    UG_ButtonCreate(&window_5, &button5_1, BTN_ID_1,  0, 60, 280, 90);
    UG_ButtonSetFont(&window_5, BTN_ID_1, &FONT_12X20);
    UG_ButtonSetBackColor(&window_5, BTN_ID_1, C_DIM_GRAY);   
		UG_ButtonSetStyle(&window_5, BTN_ID_1, BTN_STYLE_2D);

		UG_ButtonCreate(&window_5, &button5_2, BTN_ID_2,  0, 90, 280, 120);
    UG_ButtonSetFont(&window_5, BTN_ID_2, &FONT_12X20);
    UG_ButtonSetBackColor(&window_5, BTN_ID_2, C_GRAY);   
		UG_ButtonSetStyle(&window_5, BTN_ID_2, BTN_STYLE_2D);
		
		UG_ButtonCreate(&window_5, &button5_3, BTN_ID_3,  0, 120, 280, 150);
    UG_ButtonSetFont(&window_5, BTN_ID_3, &FONT_12X20);
    UG_ButtonSetBackColor(&window_5, BTN_ID_3, C_DIM_GRAY);   
		UG_ButtonSetStyle(&window_5, BTN_ID_3, BTN_STYLE_2D);	
		
		UG_ButtonCreate(&window_5, &button5_4, BTN_ID_4,  0, 150, 280,180 );
    UG_ButtonSetFont(&window_5, BTN_ID_4, &FONT_12X20);
    UG_ButtonSetBackColor(&window_5, BTN_ID_4, C_GRAY);   
		UG_ButtonSetStyle(&window_5, BTN_ID_4, BTN_STYLE_2D);

		UG_ButtonCreate(&window_5, &button5_5, BTN_ID_5,  0, 180, 280, 210);
    UG_ButtonSetFont(&window_5, BTN_ID_5, &FONT_12X20);
    UG_ButtonSetBackColor(&window_5, BTN_ID_5, C_DIM_GRAY);   
		UG_ButtonSetStyle(&window_5, BTN_ID_5, BTN_STYLE_2D);

		UG_ButtonCreate(&window_5, &button5_6, BTN_ID_6,  0, 210, 280, 240);
    UG_ButtonSetFont(&window_5, BTN_ID_6, &FONT_12X20);
    UG_ButtonSetBackColor(&window_5, BTN_ID_6, C_GRAY);   
		UG_ButtonSetStyle(&window_5, BTN_ID_6, BTN_STYLE_2D);
		
		/* Create Textbox 1 */
		UG_TextboxCreate(&window_5, &textbox5_1, TXB_ID_5, 20, 0, 120,50);
		UG_TextboxSetFont(&window_5, TXB_ID_5, &FONT_12X20);
		UG_TextboxSetText(&window_5, TXB_ID_5, ui_page);
		UG_TextboxSetAlignment(&window_5, TXB_ID_5,ALIGN_CENTER_LEFT  );
}



void uGUI_Window6(void){
	
	  /* Create Window 6 */
    UG_WindowCreate(&window_6, obj_buff_wnd_6, 4, window_6_callback);
    UG_WindowSetStyle(&window_6,WND_STYLE_HIDE_TITLE);
    UG_WindowSetBackColor(&window_6, C_DARK_GRAY);
		UG_WindowResize(&window_6, 40, 180, 280, 330);

	
		/* Create Image 1 */
		UG_ImageCreate( &window_6, &image_exit, IMG_ID_12, 195, 105, 239, 145 );
		UG_ImageSetBMP( &window_6, IMG_ID_12, &Exit);
	
	
		 /* Create Button 1-2*/
		
		UG_ButtonCreate(&window_6, &button6_1, BTN_ID_7,  20, 60, 100, 100);
    UG_ButtonSetFont(&window_6, BTN_ID_7, &FONT_8X14);
    UG_ButtonSetBackColor(&window_6, BTN_ID_7, C_GHOST_WHITE);   
		UG_ButtonSetStyle(&window_6, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_6, BTN_ID_7, "play" );
		
		
		UG_ButtonCreate(&window_6, &button6_2, BTN_ID_8,  140, 60, 220, 100);
    UG_ButtonSetFont(&window_6, BTN_ID_8, &FONT_8X14);
    UG_ButtonSetBackColor(&window_6, BTN_ID_8, C_SNOW);   
		UG_ButtonSetStyle(&window_6, BTN_ID_8, BTN_STYLE_3D);
		UG_ButtonSetText( &window_6, BTN_ID_8, "delete" );
		
		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_6, &textbox6_1, TXB_ID_8, 20, 10, 220, 50);
		UG_TextboxSetFont(&window_6, TXB_ID_8, &FONT_8X14);
		UG_TextboxSetAlignment(&window_6, TXB_ID_8, ALIGN_CENTER );
	
}

void uGUI_Window7(void){
	
	  /* Create Window 3 */
    UG_WindowCreate(&window_7, obj_buff_wnd_7, 4, window_7_callback);
    UG_WindowSetStyle(&window_7,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_7, C_DARK_GRAY);
		UG_WindowResize(&window_7, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_7, C_GRAY );
		UG_WindowSetTitleText( &window_7,"Player" );
		UG_WindowSetTitleTextFont( &window_7, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_7, ALIGN_CENTER );
	
		/* Create Image 1  */
		UG_ImageCreate( &window_7, &image7_1, IMG_ID_13, 110, 120, 170, 180 );
		UG_ImageSetBMP( &window_7, IMG_ID_13, &Pause);

//		/* Create Image 2 */
//		UG_ImageCreate( &window_7, &image7_2, IMG_ID_14, 170, 120, 230, 180 );
//		UG_ImageSetBMP( &window_7, IMG_ID_14, &Stop);
		
		/* Create Image 3 */
		UG_ImageCreate( &window_7, &image_exit, IMG_ID_15, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_7, IMG_ID_15, &Exit);
		
		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_7, &playrecordtime, TXB_ID_9, 10, 20, 270, 50);
		UG_TextboxSetFont(&window_7, TXB_ID_9, &FONT_12X20);
		UG_TextboxSetText(&window_7, TXB_ID_9,  ui_seconds);
		UG_TextboxSetAlignment(&window_7, TXB_ID_9, ALIGN_CENTER );
		
		/* Create Textbox 2 */
    UG_TextboxCreate(&window_7, &textbox7_1, TXB_ID_10, 15, 190, 265, 215 );
    UG_TextboxSetFont(&window_7, TXB_ID_10, &FONT_12X20);
    UG_TextboxSetText(&window_7, TXB_ID_10, "Pause");
    UG_TextboxSetAlignment(&window_7, TXB_ID_10, ALIGN_CENTER );
		
//		/* Create Textbox 3 */
//    UG_TextboxCreate(&window_7, &textbox7_2, TXB_ID_11, 173, 190, 230, 230 );
//    UG_TextboxSetFont(&window_7, TXB_ID_11, &FONT_12X20);
//    UG_TextboxSetText(&window_7, TXB_ID_11, "Stop");
//    //UG_TextboxSetAlignment(&window_2, TXB_ID_11, ALIGN_CENTER );
		
}

void uGUI_Window8(void){
	
	  /* Create Window 8 */
    UG_WindowCreate(&window_8, obj_buff_wnd_8, 4, window_8_callback);
    UG_WindowSetStyle(&window_8,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_8, C_DARK_GRAY);
		UG_WindowResize(&window_8, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_8, C_GRAY );
		UG_WindowSetTitleText( &window_8,"Player" );
		UG_WindowSetTitleTextFont( &window_8, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_8, ALIGN_CENTER );
	
		/* Create Image 1  */
		UG_ImageCreate( &window_8, &image8_1, IMG_ID_16, 110, 120, 170, 180 );
		UG_ImageSetBMP( &window_8, IMG_ID_16, &Continue);

//		/* Create Image 2 */
//		UG_ImageCreate( &window_8, &image8_2, IMG_ID_17, 170, 120, 230, 180 );
//		UG_ImageSetBMP( &window_8, IMG_ID_17, &Stop);
		
		/* Create Image 3 */
		UG_ImageCreate( &window_8, &image_exit, IMG_ID_18, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_8, IMG_ID_18, &Exit);
		
		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_8, &playrecordtime, TXB_ID_12,  10, 20, 270, 50);
		UG_TextboxSetFont(&window_8, TXB_ID_12, &FONT_12X20);
		UG_TextboxSetText(&window_8, TXB_ID_12, ui_seconds);
		UG_TextboxSetAlignment(&window_8, TXB_ID_12, ALIGN_CENTER );
		
		/* Create Textbox 2 */
    UG_TextboxCreate(&window_8, &textbox8_1, TXB_ID_13, 15, 190, 270, 215 );
    UG_TextboxSetFont(&window_8, TXB_ID_13, &FONT_12X20);
    UG_TextboxSetText(&window_8, TXB_ID_13, "Continue");
    UG_TextboxSetAlignment(&window_8, TXB_ID_13, ALIGN_CENTER );
		
//		/* Create Textbox 3 */
//    UG_TextboxCreate(&window_8, &textbox8_3, TXB_ID_14, 173, 190, 230, 230 );
//    UG_TextboxSetFont(&window_8, TXB_ID_14, &FONT_12X20);
//    UG_TextboxSetText(&window_8, TXB_ID_14, "Stop");
//    //UG_TextboxSetAlignment(&window_2, TXB_ID_4, ALIGN_CENTER );
		

}

void uGUI_Window9(void){
	
	  /* Create Window 9 */
    UG_WindowCreate(&window_9, obj_buff_wnd_9, 2, window_9_callback);
    UG_WindowSetStyle(&window_9,WND_STYLE_HIDE_TITLE);
    UG_WindowSetBackColor(&window_9, C_GHOST_WHITE);
		UG_WindowResize(&window_9, 40, 180, 280, 330);
	
	
		 /* Create Button 1*/
		
		UG_ButtonCreate(&window_9, &button_ok, BTN_ID_7,  80, 80, 160, 120);
    UG_ButtonSetFont(&window_9, BTN_ID_7, &FONT_12X20);
    UG_ButtonSetBackColor(&window_9, BTN_ID_7, C_SNOW);   
		UG_ButtonSetStyle(&window_9, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_9, BTN_ID_7, "OK!" );

		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_9, &textbox9_1, TXB_ID_8, 5, 30, 235, 60);
		UG_TextboxSetFont(&window_9, TXB_ID_8,  &FONT_8X14);
//		UG_TextboxSetAlignment(&window_9, TXB_ID_8, ALIGN_CENTER );
		UG_TextboxSetText( &window_9, TXB_ID_8, ui_prompt );
	
}

void uGUI_Window10(void){
	
	  /* Create Window 10 */
    UG_WindowCreate(&window_10, obj_buff_wnd_10, 7, window_10_callback);
    UG_WindowSetStyle(&window_10,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_10, C_DARK_GRAY);
		UG_WindowResize(&window_10, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_10, C_GRAY );		
		UG_WindowSetTitleTextFont( &window_10, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_10, ALIGN_CENTER );
	
	
		 /* Create Button 1*/
		
		UG_ButtonCreate(&window_10, &button_ok, BTN_ID_7,  100, 240, 180, 280);
    UG_ButtonSetFont(&window_10, BTN_ID_7, &FONT_12X20);
    UG_ButtonSetBackColor(&window_10, BTN_ID_7, C_SNOW);   
		UG_ButtonSetStyle(&window_10, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_10, BTN_ID_7, "OK!" );
		
		
		/*gettime*/
		
		RTCB_GetRTCB(&RTCB_Struct);
		
		sprintf(timeStr, "%02x:%02x",  RTCB_Struct.hour,  RTCB_Struct.minute);
//		sprintf(dateStr, "20%02x/%02x/%02x",  RTCB_Struct.year,  RTCB_Struct.month,RTCB_Struct.day);

		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_10, &textbox10_1, TXB_ID_8, 0, 100, 120, 160);
		UG_TextboxSetFont(&window_10, TXB_ID_8,  &FONT_32X53);
		UG_TextboxSetAlignment(&window_10, TXB_ID_8, ALIGN_CENTER );
		UG_TextboxSetText(&window_10, TXB_ID_8,timeStr);
		
		
		/* Create Image 1-4 */
		UG_ImageCreate( &window_10, &image_arrowdown, IMG_ID_1,70, 170,110, 215 );  //小时减
		UG_ImageSetBMP( &window_10, IMG_ID_1, &Arrow_down);
		
		UG_ImageCreate( &window_10, &image_arrowdown, IMG_ID_2,170, 170,210, 215 );  //分钟减
		UG_ImageSetBMP( &window_10, IMG_ID_2, &Arrow_down);
		

		UG_ImageCreate( &window_10, &image_arrowup, IMG_ID_3,70, 45,110, 90 );   //小时加
		UG_ImageSetBMP( &window_10, IMG_ID_3, &Arrow_up);
		
		UG_ImageCreate( &window_10, &image_arrowup, IMG_ID_4,170, 45,210, 90 );
		UG_ImageSetBMP( &window_10, IMG_ID_4, &Arrow_up);
		
		
		/* Create Image 1 */
		UG_ImageCreate( &window_10, &image_exit, IMG_ID_5, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_10, IMG_ID_5, &Exit);
	
}


void uGUI_Window11(void){
	
	  /* Create Window 11 */
    UG_WindowCreate(&window_11, obj_buff_wnd_11, 9, window_11_callback);
    UG_WindowSetStyle(&window_11,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_11, C_DARK_GRAY);
		UG_WindowResize(&window_11, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_11, C_GRAY );		
		UG_WindowSetTitleTextFont( &window_11, &FONT_12X20 );
		UG_WindowSetTitleText( &window_11,"Date Setting" );
		UG_WindowSetTitleTextAlignment(&window_11, ALIGN_CENTER );
	
	
		 /* Create Button 1-4*/
		
		UG_ButtonCreate(&window_11, &button_ok, BTN_ID_7,  100, 240, 180, 280);
    UG_ButtonSetFont(&window_11, BTN_ID_7, &FONT_12X20);
    UG_ButtonSetBackColor(&window_11, BTN_ID_7, C_SNOW);   
		UG_ButtonSetStyle(&window_11, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_11, BTN_ID_7, "OK!" );
		
		UG_ButtonCreate(&window_11, &button11_1, BTN_ID_8,  5, 50, 80, 90);
    UG_ButtonSetFont(&window_11, BTN_ID_8, &FONT_12X20);
    UG_ButtonSetBackColor(&window_11, BTN_ID_8, C_SNOW);   
		UG_ButtonSetStyle(&window_11, BTN_ID_8, BTN_STYLE_3D);
		UG_ButtonSetText( &window_11, BTN_ID_8, "Year" );
		
		UG_ButtonCreate(&window_11, &button11_2, BTN_ID_9,  5, 110, 80, 150);
    UG_ButtonSetFont(&window_11, BTN_ID_9, &FONT_12X20);
    UG_ButtonSetBackColor(&window_11, BTN_ID_9, C_SNOW);   
		UG_ButtonSetStyle(&window_11, BTN_ID_9, BTN_STYLE_3D);
		UG_ButtonSetText( &window_11, BTN_ID_9, "Month" );
		
		UG_ButtonCreate(&window_11, &button11_3, BTN_ID_11,  5, 170, 80, 210);
    UG_ButtonSetFont(&window_11, BTN_ID_11, &FONT_12X20);
    UG_ButtonSetBackColor(&window_11, BTN_ID_11, C_SNOW);   
		UG_ButtonSetStyle(&window_11, BTN_ID_11, BTN_STYLE_3D);
		UG_ButtonSetText( &window_11, BTN_ID_11, "Day" );
		
		
		

		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_11, &textbox11_1, TXB_ID_8, 80, 100, 200, 160);
		UG_TextboxSetFont(&window_11, TXB_ID_8,  &FONT_32X53);
		UG_TextboxSetAlignment(&window_11, TXB_ID_8, ALIGN_CENTER );
		UG_TextboxSetText(&window_11, TXB_ID_8, dateStr);
		
		/* Create Textbox 2 */
		UG_TextboxCreate(&window_11, &textbox11_2, TXB_ID_9, 10, 10, 270, 40);
		UG_TextboxSetFont(&window_11, TXB_ID_9,  &FONT_12X20);
		UG_TextboxSetAlignment(&window_11, TXB_ID_9, ALIGN_CENTER );
		
		
		
		/* Create Image 1-3 */
		UG_ImageCreate( &window_11, &image_arrowdown, IMG_ID_1,185, 170,225, 215 );  //减
		UG_ImageSetBMP( &window_11, IMG_ID_1, &Arrow_down);	

		UG_ImageCreate( &window_11, &image_arrowup, IMG_ID_2,185, 45,225, 90 );   //加
		UG_ImageSetBMP( &window_11, IMG_ID_2, &Arrow_up);

		UG_ImageCreate( &window_11, &image_exit, IMG_ID_5, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_11, IMG_ID_5, &Exit);
	
}

void uGUI_Window12(void){
	
	  /* Create Window 12 */
    UG_WindowCreate(&window_12, obj_buff_wnd_12, 2, window_12_callback);
    UG_WindowSetStyle(&window_12,WND_STYLE_HIDE_TITLE);
    UG_WindowSetBackColor(&window_12, C_GHOST_WHITE);
		UG_WindowResize(&window_12, 40, 180, 280, 330);
	
	
		 /* Create Button 1*/
		
		UG_ButtonCreate(&window_12, &button_ok, BTN_ID_7,  80, 80, 160, 120);
    UG_ButtonSetFont(&window_12, BTN_ID_7, &FONT_12X20);
    UG_ButtonSetBackColor(&window_12, BTN_ID_7, C_SNOW);   
		UG_ButtonSetStyle(&window_12, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_12, BTN_ID_7, "OK!" );

		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_12, &textbox12_1, TXB_ID_8, 5, 30, 235, 60);
		UG_TextboxSetFont(&window_12, TXB_ID_8,  &FONT_8X14);
//		UG_TextboxSetAlignment(&window_9, TXB_ID_8, ALIGN_CENTER );
		UG_TextboxSetText( &window_12, TXB_ID_8, alarm_prompt );
	
}

void uGUI_Window13(void){
	
	  /* Create Window 13 */
    UG_WindowCreate(&window_13, obj_buff_wnd_13, 7, window_13_callback);
    UG_WindowSetStyle(&window_13,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_13, C_DARK_GRAY);
		UG_WindowResize(&window_13, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_13, C_GRAY );		
		UG_WindowSetTitleTextFont( &window_13, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_13, ALIGN_CENTER );
	
	
		 /* Create Button 1*/
		
		UG_ButtonCreate(&window_13, &button_ok, BTN_ID_7,  100, 240, 180, 280);
    UG_ButtonSetFont(&window_13, BTN_ID_7, &FONT_12X20);
    UG_ButtonSetBackColor(&window_13, BTN_ID_7, C_SNOW);   
		UG_ButtonSetStyle(&window_13, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_13, BTN_ID_7, "OK!" );


		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_13, &textbox13_1, TXB_ID_8, 0, 100, 120, 160);
		UG_TextboxSetFont(&window_13, TXB_ID_8,  &FONT_32X53);
		UG_TextboxSetAlignment(&window_13, TXB_ID_8, ALIGN_CENTER );
		UG_TextboxSetText(&window_13, TXB_ID_8,alarmtimeStr);
		
		
		/* Create Image 1-4 */
		UG_ImageCreate( &window_13, &image_arrowdown, IMG_ID_1,70, 170,110, 215 );  //小时减
		UG_ImageSetBMP( &window_13, IMG_ID_1, &Arrow_down);
		
		UG_ImageCreate( &window_13, &image_arrowdown, IMG_ID_2,170, 170,210, 215 );  //分钟减
		UG_ImageSetBMP( &window_13, IMG_ID_2, &Arrow_down);
		

		UG_ImageCreate( &window_13, &image_arrowup, IMG_ID_3,70, 45,110, 90 );   //小时加
		UG_ImageSetBMP( &window_13, IMG_ID_3, &Arrow_up);
		
		UG_ImageCreate( &window_13, &image_arrowup, IMG_ID_4,170, 45,210, 90 );
		UG_ImageSetBMP( &window_13, IMG_ID_4, &Arrow_up);
		
		
		/* Create Image 1 */
		UG_ImageCreate( &window_13,&image_exit, IMG_ID_5, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_13, IMG_ID_5, &Exit);
	
}


void uGUI_Window14(void){
	
	  /* Create Window 13 */
    UG_WindowCreate(&window_14, obj_buff_wnd_14, 5, window_14_callback);
    UG_WindowSetStyle(&window_14,WND_STYLE_SHOW_TITLE);
    UG_WindowSetBackColor(&window_14, C_DARK_GRAY);
		UG_WindowResize(&window_14, 20, 80, 300, 400);
		
		//window title
		UG_WindowSetTitleColor(&window_14, C_GRAY );		
		UG_WindowSetTitleTextFont( &window_14, &FONT_12X20 );
		UG_WindowSetTitleTextAlignment(&window_14, ALIGN_CENTER );
	
	
		 /* Create Button 1*/
		
		UG_ButtonCreate(&window_14, &button_ok, BTN_ID_7,  100, 240, 180, 280);
    UG_ButtonSetFont(&window_14, BTN_ID_7, &FONT_12X20);
    UG_ButtonSetBackColor(&window_14, BTN_ID_7, C_SNOW);   
		UG_ButtonSetStyle(&window_14, BTN_ID_7, BTN_STYLE_3D);
		UG_ButtonSetText( &window_14, BTN_ID_7, "OK!" );


		 /* Create Textbox 1 */
		UG_TextboxCreate(&window_14, &textbox14_1, TXB_ID_8, 32, 100, 152, 160);
		UG_TextboxSetFont(&window_14, TXB_ID_8,  &FONT_32X53);
		UG_TextboxSetText(&window_14, TXB_ID_8, setting_str);		
		UG_TextboxSetAlignment(&window_14, TXB_ID_8, ALIGN_CENTER );

		
		
		/* Create Image 1-4 */
		UG_ImageCreate( &window_14, &image_arrowdown, IMG_ID_1,120, 170,160, 215 );  //减
		UG_ImageSetBMP( &window_14, IMG_ID_1, &Arrow_down);
		
		UG_ImageCreate( &window_14, &image_arrowup, IMG_ID_2,120, 45,160, 90 );   //小时加
		UG_ImageSetBMP( &window_14, IMG_ID_2, &Arrow_up);
		
		
		/* Create Image 1 */
		UG_ImageCreate( &window_14, &image_exit, IMG_ID_5, 225, 250, 269, 310 );
		UG_ImageSetBMP( &window_14, IMG_ID_5, &Exit);
	
}



/**
  * @brief  
  * @param  None
  * @retval None
  */
void uGUI_Demo(void)
{
    uGUI_Init();

    uGUI_Window1();
 	  uGUI_Window2();
		uGUI_Window3();
		uGUI_Window4();
		uGUI_Window5();
		uGUI_Window6();
		uGUI_Window7();
		uGUI_Window8();
		uGUI_Window9();	
		uGUI_Window10();
		uGUI_Window11();	
		uGUI_Window12();
		uGUI_Window13();
		uGUI_Window14();
	
    /* Show Window */
		UG_WindowShow(&window_1);
	
		
    //UG_WindowShow(&window_2);
    //UG_Update();
}