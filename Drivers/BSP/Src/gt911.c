#include "gt911.h"
#include "i2csmb.h"
#include "string.h" 
#include "lcd.h"
#include "stdio.h"

//触摸相关参数
_m_tp_dev tp_dev=
{
	0,
	0, 
	0,  	 		
};					


//初始化GT911触摸屏
//返回值:0,初始化成功;1,初始化失败 
uint8_t GT911_Init(void)
{
		uint8_t temp[5]; 

		//初始化电容屏的I2C总线 
		I2C_Init();  
	
		// 初始化RST和INT
		FL_GPIO_InitTypeDef    GPIO_InitStruct;
    FL_EXTI_InitTypeDef extiInitStruct;
    FL_EXTI_CommonInitTypeDef  extiCommonInitStruct;
		
		// RST
		// RST先拉低准备
    GPIO_InitStruct.pin 					= FL_GPIO_PIN_7;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOA, &GPIO_InitStruct);                                /*GPIO初始化*/
		FL_GPIO_ResetOutputPin(GPIOA, FL_GPIO_PIN_7);
		FL_DelayMs(10);
		
		// INT
		// INT拉高
    GPIO_InitStruct.pin 					= FL_GPIO_PIN_10;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOD, &GPIO_InitStruct);                                /*GPIO初始化*/
		FL_GPIO_SetOutputPin(GPIOD, FL_GPIO_PIN_10);
		FL_DelayMs(10);
		
		// 随后RST由低拉高
		FL_GPIO_SetOutputPin(GPIOA, FL_GPIO_PIN_7);
		FL_DelayMs(10);
		// INT拉低
		FL_GPIO_ResetOutputPin(GPIOD, FL_GPIO_PIN_10);
		FL_DelayMs(100);
		
		// 保持至少50ms后INT由拉低输出转为悬浮输入
    // EXTI中断采样时钟选择
    extiCommonInitStruct.clockSource = FL_CMU_EXTI_CLK_SOURCE_RCLP;
    (void)FL_EXTI_CommonInit(&extiCommonInitStruct);
		
    GPIO_InitStruct.pin 					= FL_GPIO_PIN_10;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_INPUT;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOD, &GPIO_InitStruct);                                /*GPIO初始化*/
		
		// EXTI中断使能
    extiInitStruct.input          = FL_GPIO_EXTI_INPUT_GROUP2;          //中断线上对应的IO
    extiInitStruct.filter         = FL_DISABLE;                          //使能数字滤波
    extiInitStruct.triggerEdge    = FL_GPIO_EXTI_TRIGGER_EDGE_BOTH;  //设置触发边沿
    (void)FL_EXTI_Init(FL_GPIO_EXTI_LINE_14, &extiInitStruct);

    /*NVIC中断配置*/
    NVIC_DisableIRQ(EXTID_IRQn);
    NVIC_SetPriority(EXTID_IRQn, 2); //中断优先级配置
//    NVIC_EnableIRQ(EXTID_IRQn);		// 这个开中断放在touch任务里面
		
		FL_DelayMs(20);		
		
		//读取产品ID
		GT911_I2C_Read(GT_PID_REG,temp,4);
		temp[4]=0;
		if(strcmp((char*)temp,"911")==0)//ID==911
		{
			temp[0]=0X02;			
			GT911_I2C_Write(GT_CTRL_REG,temp,1);//软复位GT911
			GT911_I2C_Read(GT_CFGS_REG,temp,1);//读取GT_CFGS_REG寄存器
			
			if(temp[0]<0X60)//默认版本比较低,需要更新flash配置
			{
				printf("Default Ver:%d\r\n",temp[0]);
			}
			FL_DelayMs(10);
			temp[0]=0X00;	 
			GT911_I2C_Write(GT_CTRL_REG,temp,1);//结束复位   
			return 0;
		} 
		return 1;
}

const uint16_t GT911_TPX_TBL[5]={GT_TP1_REG,GT_TP2_REG,GT_TP3_REG,GT_TP4_REG,GT_TP5_REG};
//扫描触摸屏(采用中断方式)
//返回值:读取mode寄存器值.
// printf("x[%d]:%d,y[%d]:%d\r\n",i,tp_dev.x[i],i,tp_dev.y[i]);//串口打印坐标，用于调试
uint8_t GT911_Scan_INT()
{
	uint8_t buf[4];
	uint8_t i=0;
	uint8_t temp;
	uint8_t mode;

	// 读取&清寄存器
	GT911_I2C_Read(GT_GSTID_REG,&mode,1);//读取触摸点的状态 
	if((mode&0XF)&&((mode&0XF)<6))
	{
		temp=0XFF<<(mode&0XF);//将点的个数转换为1的位数,匹配tp_dev.sta定义 
		tp_dev.sta |= (~temp)|TP_PRES_DOWN; 
		for(i=0;i<5;i++)
		{
			if(tp_dev.sta&(1<<i))	//触摸有效?
			{
				GT911_I2C_Read(GT911_TPX_TBL[i],buf,4);	//读取XY坐标值
				if(lcdstr.dir==0)	//竖屏
				{
					tp_dev.x[i]=((uint16_t)buf[1]<<8)+buf[0];
					tp_dev.y[i]=(((uint16_t)buf[3]<<8)+buf[2]);
				}else //横屏
				{
					tp_dev.y[i]=((uint16_t)buf[1]<<8)+buf[0];
					tp_dev.x[i]=lcdstr.width-(((uint16_t)buf[3]<<8)+buf[2]);
				}  
			}			
		} 
		if(tp_dev.x[0]==0 && tp_dev.y[0]==0)mode=0;	//读到的数据都是0,则忽略此次数据
	}
	if(mode&0X80&&((mode&0XF)<6))
	{
		temp=0;
		GT911_I2C_Write(GT_GSTID_REG,&temp,1);//清标志 		
	}

	// 修改标志位
	if((mode&0X8F)==0X80)//无触摸点按下
	{ 
		if(tp_dev.sta&TP_PRES_DOWN)	//之前是被按下的
		{
			tp_dev.sta&=~(1<<7);	//标记按键松开
			tp_dev.sta |= TP_CATH_PENUP;	// 置位pen up标志
			
		}else						//之前就没有被按下
		{ 
			tp_dev.x[0]=0xffff;
			tp_dev.y[0]=0xffff;
			tp_dev.sta&=0XE0;	//清除点有效标记	
		}	 
	} 	
	return mode;
}

