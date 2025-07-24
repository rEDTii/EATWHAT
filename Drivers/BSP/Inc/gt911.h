#ifndef __GT911_H__
#define __GT911_H__

#include "fm33fk5xx_fl.h"
	
//GT911 部分寄存器定义 
#define GT_CTRL_REG 	0X8040   	//GT911控制寄存器
#define GT_CFGS_REG 	0X8047   	//GT911配置起始地址寄存器
#define GT_CHECK_REG 	0X80FF   	//GT911校验和寄存器
#define GT_PID_REG 		0X8140   	//GT911产品ID寄存器

#define GT_GSTID_REG 	0X814E   	//GT911当前检测到的触摸情况
#define GT_TP1_REG 		0X8150  	//第一个触摸点数据地址
#define GT_TP2_REG 		0X8158		//第二个触摸点数据地址
#define GT_TP3_REG 		0X8160		//第三个触摸点数据地址
#define GT_TP4_REG 		0X8168		//第四个触摸点数据地址
#define GT_TP5_REG 		0X8170		//第五个触摸点数据地址  

#define TP_PRES_DOWN 	0x80  //触屏被按下	  
#define TP_CATH_PENUP 0x40  //捕捉到pen up
#define CT_MAX_TOUCH  5    //电容屏支持的点数,固定为5点

//触摸屏控制器
typedef struct
{ 
	uint16_t x[CT_MAX_TOUCH]; 		//当前坐标
	uint16_t y[CT_MAX_TOUCH];		//电容屏有最多5组坐标,电阻屏则用x[0],y[0]代表:此次扫描时,触屏的坐标,用
								          //x[4],y[4]存储第一次按下时的坐标. 
	uint8_t  sta;					      //笔的状态 
								          //b7:按下1/松开0; 
													//b6:0,没有按键按下;1,有过按键按下（未处理），更新为pen up标志位
								          //b5:保留
								          //b4~b0:电容触摸屏按下的点数(0,表示未按下,1表示按下)
}_m_tp_dev;

extern _m_tp_dev tp_dev;

uint8_t GT911_Init(void);
uint8_t GT911_Scan_INT();
#endif

