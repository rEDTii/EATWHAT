#include "lcd.h"
#include <stdlib.h>
#include "w25q64.h"

lcd_struct lcdstr;
uint16_t POINT_COLOR=0x0000;	// 笔画颜色
uint16_t BACK_COLOR=0xFFFF;  // 背景色
uint8_t DFT_SCAN_DIR; //扫描方向变量

/**
  * @brief  The application entry point.
  * @retval int
  */
/**
  * @brief  LCD Initialization function
  * @param  void
  * @retval None
  */
void LCD_Init(void)
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct;
    EPSC_NORSRAM_InitTypeDef    EPSC_NORSRAMInitStructure;
    EPSC_NORSRAM_RWTimingTypeDef  readWriteTiming;
    EPSC_NORSRAM_WTimingTypeDef     writeTiming;
    //D4_D10
    GPIO_InitStruct.pin           = FL_GPIO_PIN_9 | FL_GPIO_PIN_10 | FL_GPIO_PIN_11 | FL_GPIO_PIN_12 | FL_GPIO_PIN_13 | FL_GPIO_PIN_14 | FL_GPIO_PIN_15;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    //D0_D1
    GPIO_InitStruct.pin           = FL_GPIO_PIN_10 | FL_GPIO_PIN_11;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    //D2_D3
    GPIO_InitStruct.pin           = FL_GPIO_PIN_5 | FL_GPIO_PIN_6;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    //D11_D12
    GPIO_InitStruct.pin           = FL_GPIO_PIN_14 | FL_GPIO_PIN_15;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    //D13_D15
    GPIO_InitStruct.pin           = FL_GPIO_PIN_2 | FL_GPIO_PIN_3 | FL_GPIO_PIN_4;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOF, &GPIO_InitStruct);

    //A6_NOE
    GPIO_InitStruct.pin           = FL_GPIO_PIN_15 | FL_GPIO_PIN_9;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    //NE4
    GPIO_InitStruct.pin           = FL_GPIO_PIN_10;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    //NWE_RESET
    GPIO_InitStruct.pin           = FL_GPIO_PIN_10;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    //RESET
    GPIO_InitStruct.pin           = FL_GPIO_PIN_14;
    GPIO_InitStruct.mode          = FL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull          = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.remapPin      = FL_GPIO_PINREMAP_FUNCTON4;
    GPIO_InitStruct.analogSwitch  = FL_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    FL_GPIO_SetOutputPin(GPIOC, FL_GPIO_PIN_14);
    FL_DelayMs(100);
    FL_GPIO_ResetOutputPin(GPIOC, FL_GPIO_PIN_14);
    FL_DelayMs(500);
    FL_GPIO_SetOutputPin(GPIOC, FL_GPIO_PIN_14);
    FL_DelayMs(100);

    readWriteTiming.AddressSetupTime = 4;
		// 这里AddressHoldTime不准设置为0，而modedA不需要AddressHoldTime，所以随意取了1
    readWriteTiming.AddressHoldTime = 1;
    readWriteTiming.DataSetupTime = 0x14;
    readWriteTiming.BusTurnAroundDuration = FL_EPSC_NTR_BUS_TRUNAROUND_0CLK;
    readWriteTiming.CLKDivision = FL_EPSC_NTR_CLK_DIV2;
    readWriteTiming.DataLatency = FL_EPSC_NTR_DATA_LATENCY_2CLK;
    readWriteTiming.AccessMode = FL_EPSC_NTR_EXTMOD_MODE_A;                                                 //模式A

    writeTiming.AddressSetupTime = 4;
		// 这里AddressHoldTime不准设置为0，而modedA不需要AddressHoldTime，所以随意取了1
    writeTiming.AddressHoldTime = 1;
    writeTiming.DataSetupTime = 0x14;
    writeTiming.BusTurnAroundDuration = FL_EPSC_NWTR_BUS_TRUNAROUND_0CLK;
    writeTiming.AccessMode = FL_EPSC_NWTR_EXTMOD_MODE_A;                                                        //模式A

    EPSC_NORSRAMInitStructure.NSBank = FL_EPSC_BANK1_NORSRAM4;                                          //这里我们使用NE4
    EPSC_NORSRAMInitStructure.DataAddressMux = FL_DISABLE;                                                  //不复用数据地址
    EPSC_NORSRAMInitStructure.MemoryType = FL_EPSC_NCR_MEMORY_TYPE_SRAM;                        //SRAM
    EPSC_NORSRAMInitStructure.MemoryDataWidth = FL_EPSC_NCR_MEMORY_WIDTH_16B;               //存储器数据宽度为16bit
    EPSC_NORSRAMInitStructure.BurstAccessMode = FL_DISABLE;
    EPSC_NORSRAMInitStructure.WriteBurst = FL_DISABLE;

    EPSC_NORSRAMInitStructure.WaitSignal = FL_DISABLE;
    EPSC_NORSRAMInitStructure.AsynchronousWait = FL_DISABLE;
    EPSC_NORSRAMInitStructure.WaitSignalPolarity = FL_EPSC_NCR_POLARITY_LOW;
    EPSC_NORSRAMInitStructure.WaitSignalActive = FL_EPSC_NCR_ACTIVE_STATE_BEFORE;
    EPSC_NORSRAMInitStructure.WriteOperation = FL_ENABLE;                                                       //存储器写使能
    EPSC_NORSRAMInitStructure.ExtendedMode = FL_ENABLE;                                                         //读写使用不同的时序
    EPSC_NORSRAMInitStructure.ReadWriteTimingStruct = &readWriteTiming;                         //读写时序
    EPSC_NORSRAMInitStructure.WriteTimingStruct = &writeTiming;                                         //写时序

    FL_EPSC_NORSRAM_Init(EPSC, &EPSC_NORSRAMInitStructure);                                                 //初始化FSMC配置
		
		LCD_INIT_CODE();		// LCD初始化
		LCD_Display_Dir(Landscape);		// 切换横竖屏显示
		LCD_Clear(WHITE);
}

// PWM调光初始化
void PWM_BL_Init(void)
{
    FL_GPTIM_InitTypeDef         TimerBaseInitStruct;
    FL_GPTIM_OC_InitTypeDef      defaultInitStruct;
    FL_GPIO_InitTypeDef          gpioInitStruction;

    //GPTIM0_CH1_PE3
    gpioInitStruction.pin           = FL_GPIO_PIN_3;
    gpioInitStruction.mode          = FL_GPIO_MODE_DIGITAL;
    gpioInitStruction.outputType    = FL_GPIO_OUTPUT_PUSHPULL;
    gpioInitStruction.pull          = FL_GPIO_BOTH_DISABLE;
    gpioInitStruction.remapPin      = FL_GPIO_PINREMAP_FUNCTON2;
    gpioInitStruction.analogSwitch  = FL_DISABLE;
    gpioInitStruction.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    (void)FL_GPIO_Init(GPIOE, &gpioInitStruction);

    TimerBaseInitStruct.prescaler = 8 - 1;
    TimerBaseInitStruct.counterMode = FL_GPTIM_COUNTER_DIR_DOWN;
    TimerBaseInitStruct.autoReload = 1000 - 1;
    TimerBaseInitStruct.autoReloadState = FL_DISABLE;
    TimerBaseInitStruct.clockDivision = FL_GPTIM_CLK_DIVISION_DIV1;
    (void)FL_GPTIM_Init(GPTIM0, &TimerBaseInitStruct);

    defaultInitStruct.OCMode          = FL_GPTIM_OC_MODE_PWM1;
    defaultInitStruct.OCFastMode      = FL_DISABLE;
    defaultInitStruct.OCPreload       = FL_DISABLE;
    defaultInitStruct.compareValue    = 500;
    defaultInitStruct.OCPolarity      = FL_GPTIM_OC_POLARITY_NORMAL;
    defaultInitStruct.OCETRFStatus    = FL_DISABLE;
    (void)FL_GPTIM_OC_Init(GPTIM0, FL_GPTIM_CHANNEL_1, &defaultInitStruct);
    FL_GPTIM_OC_EnableChannel(GPTIM0, FL_GPTIM_CHANNEL_1);

    FL_GPTIM_ClearFlag_CC(GPTIM0, FL_GPTIM_CHANNEL_1);
    FL_GPTIM_EnableIT_CC(GPTIM0, FL_GPTIM_CHANNEL_1);

    FL_GPTIM_Enable(GPTIM0);
}


uint8_t brightness = 80;
// PWM调光, 输入value限制取值为0-100，越大越亮
void Set_PWM_BL(uint8_t value)
{
//	if (value>999) value = 999;
////	value = 1000-value*100;
		FL_GPTIM_WriteCompareCH1(GPTIM0, value*10);
}




// 设置扫描方向
//dir:0,竖屏; 1:横屏
void LCD_Display_Dir(uint8_t dir)
{
	if(dir==0)			 
	{
		lcdstr.dir=0;
		lcdstr.width=LCD_WIDTH;
		lcdstr.height=LCD_HEIGHT;

		lcdstr.wramcmd=0X2C;
		lcdstr.setxcmd=0X2A;
		lcdstr.setycmd=0X2B;  
    DFT_SCAN_DIR=D2U_R2L;

	}else
	{	  				
		lcdstr.dir=1;	 
		lcdstr.width=LCD_HEIGHT;
		lcdstr.height=LCD_WIDTH;

		lcdstr.wramcmd=0X2C;
		lcdstr.setxcmd=0X2A;
		lcdstr.setycmd=0X2B;  
    DFT_SCAN_DIR=L2R_U2D;
		
	} 
	lcdstr.total_pixels = (uint32_t)lcdstr.width * lcdstr.height;
	LCD_Scan_Dir(DFT_SCAN_DIR);
}

// 设置LCD的自动扫描方向
//dir:0~7,代表8个方向   
void LCD_Scan_Dir(uint8_t dir)
{
	uint16_t regval=0;
	uint8_t dirreg=0;

	switch(dir) //方向转换
	{
		case 0:dir=6;break;
		case 1:dir=7;break;
		case 2:dir=4;break;
		case 3:dir=5;break;
		case 4:dir=1;break;
		case 5:dir=0;break;
		case 6:dir=3;break;
		case 7:dir=2;break;	     
	}
	switch(dir)
	{
		case L2R_U2D:
			regval|=(0<<7)|(0<<6)|(0<<5); 
			break;
		case L2R_D2U:
			regval|=(1<<7)|(0<<6)|(0<<5); 
			break;
		case R2L_U2D:
			regval|=(0<<7)|(1<<6)|(0<<5); 
			break;
		case R2L_D2U:
			regval|=(1<<7)|(1<<6)|(0<<5); 
			break;	 
		case U2D_L2R:
			regval|=(0<<7)|(0<<6)|(1<<5); 
			break;
		case U2D_R2L:
			regval|=(0<<7)|(1<<6)|(1<<5); 
			break;
		case D2U_L2R:
			regval|=(1<<7)|(0<<6)|(1<<5); 
			break;
		case D2U_R2L:
			regval|=(1<<7)|(1<<6)|(1<<5); 
			break;	 
	}
	dirreg=0X36; 
  regval|=COLORORDER;	//0x08 0x00  红蓝反色
	LCD_WriteReg(dirreg,regval);
			
	LCD_WR_REG(lcdstr.setxcmd); 
	LCD_WR_DATA(0);LCD_WR_DATA(0);
	LCD_WR_DATA((lcdstr.width-1)>>8);LCD_WR_DATA((lcdstr.width-1)&0XFF);
	LCD_WR_REG(lcdstr.setycmd); 
	LCD_WR_DATA(0);LCD_WR_DATA(0);
	LCD_WR_DATA((lcdstr.height-1)>>8);LCD_WR_DATA((lcdstr.height-1)&0XFF);  
}      


//设置光标位置
//Xpos:横坐标
//Ypos:纵坐标
void LCD_SetCursor(uint16_t Xpos, uint16_t Ypos)
{	 
		LCD_WR_REG(lcdstr.setxcmd); 
		LCD_WR_DATA(Xpos>>8); 
		LCD_WR_DATA(Xpos&0XFF);
		LCD_WR_DATA(Xpos>>8); 
		LCD_WR_DATA(Xpos&0XFF);
			
		LCD_WR_REG(lcdstr.setycmd); 
		LCD_WR_DATA(Ypos>>8); 
		LCD_WR_DATA(Ypos&0XFF);
		LCD_WR_DATA(Ypos>>8); 
		LCD_WR_DATA(Ypos&0XFF);
} 		


//清屏函数
//color:要清屏的填充色
void LCD_Clear(uint16_t color)
{
  uint32_t index=0;      
  LCD_Set_Window(0,0,lcdstr.width,lcdstr.height);
	LCD_WriteRAM_Prepare(); 	
  
	for(index=0; index<lcdstr.total_pixels; index++)
	{
			LCD->LCD_RAM = color;
	}
}  

// 画点
void LCD_DrawPoint(uint16_t x,uint16_t y, uint32_t color)
{
	LCD_SetCursor(x,y);
	LCD_WriteRAM_Prepare();
	LCD_WriteRAM(color); 
}

// 区域填充
// (sx,sy),(ex,ey):填充矩形对角坐标，区域大小为:(ex-sx+1)*(ey-sy+1)   
void LCD_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color) {
    // 计算区域宽度和高度
    uint16_t width = ex - sx + 1;
    uint16_t height = ey - sy + 1;
    // 设置填充窗口
    LCD_Set_Window(sx, sy, width, height);
    // 准备连续写入GRAM数据
    LCD_WriteRAM_Prepare();
    // 计算总像素数
		uint32_t fill_total_pixels = (uint32_t)width * height;
    // 批量写入颜色数据
    for(uint32_t i = 0; i < fill_total_pixels; i++) {
        LCD_WriteRAM(color);
    }
}

// 区域填充指定颜色块
// (sx,sy),(ex,ey):填充矩形对角坐标，区域大小为:(ex-sx+1)*(ey-sy+1)   
void LCD_Color_Fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t *color) {
    uint16_t width = ex - sx + 1;
    uint16_t height = ey - sy + 1;
    uint32_t fill_total_pixels = (uint32_t)width * height;

    // 设置窗口
    LCD_Set_Window(sx, sy, width, height);
    LCD_WriteRAM_Prepare();

    // 批量写入颜色数据
    for (uint32_t i = 0; i < fill_total_pixels; i++) {
        LCD_WriteRAM(color[i]);
    }
}


// 画线
//x1,y1:起点坐标
//x2,y2:终点坐标 
//color:颜色
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color)
{
	uint16_t t; 
	int xerr=0,yerr=0,delta_x,delta_y,distance; 
	int incx,incy,uRow,uCol; 
	delta_x=x2-x1; //计算坐标增量
	delta_y=y2-y1; 
	uRow=x1; 
	uCol=y1; 
	if(delta_x>0)incx=1; //计算单步方向
	else if(delta_x==0)incx=0;//垂直线
	else {incx=-1;delta_x=-delta_x;} 
	if(delta_y>0)incy=1; 
	else if(delta_y==0)incy=0;//水平线 
	else{incy=-1;delta_y=-delta_y;} 
	if( delta_x>delta_y)distance=delta_x; // 选取基本增量坐标轴
	else distance=delta_y; 
	for(t=0;t<=distance+1;t++ )//画线输出
	{  
		LCD_DrawPoint(uRow,uCol,color);//画点 
		xerr+=delta_x ; 
		yerr+=delta_y ; 
		if(xerr>distance) 
		{ 
			xerr-=distance; 
			uRow+=incx; 
		} 
		if(yerr>distance) 
		{ 
			yerr-=distance; 
			uCol+=incy; 
		} 
	}  
}    
//画矩形	  
//(x1,y1),(x2,y2):对角坐标
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color)
{
	LCD_DrawLine(x1,y1,x2,y1,color);
	LCD_DrawLine(x1,y1,x1,y2,color);
	LCD_DrawLine(x1,y2,x2,y2,color);
	LCD_DrawLine(x2,y1,x2,y2,color);
}
//画圆
//(x,y):中心点
//r    :半径
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color)
{
	int a,b;
	int di;
	a=0;b=r;	  
	di=3-(r<<1);             //判断下个点位置的标志
	while(a<=b)
	{
		LCD_DrawPoint(x0+a,y0-b,color);             //5
 		LCD_DrawPoint(x0+b,y0-a,color);             //0           
		LCD_DrawPoint(x0+b,y0+a,color);             //4               
		LCD_DrawPoint(x0+a,y0+b,color);             //6 
		LCD_DrawPoint(x0-a,y0+b,color);             //1       
 		LCD_DrawPoint(x0-b,y0+a,color);             
		LCD_DrawPoint(x0-a,y0-b,color);             //2             
  	LCD_DrawPoint(x0-b,y0-a,color);             //7     	         
		a++;
		// Bresenham算法     
		if(di<0)di +=4*a+6;	  
		else
		{
			di+=10+4*(a-b);   
			b--;
		} 						    
	}
} 									  
//显示字符
//x,y:起始坐标
//chr:要显示的字符:" "--->"~"
//size:字体大小 12/16
//mode:叠加方式(1)，非叠加方式(0)
//color :字符颜色
void LCD_ShowChar(uint16_t x, uint16_t y, char chr, uint8_t size, uint8_t mode, uint16_t color)
{  							  
    uint8_t temp, t1, t;
    uint16_t y0 = y;
    uint8_t csize = 0;
    uint8_t *pfont = 0;

    csize = (size / 8 + ((size % 8) ? 1 : 0)) * (size / 2); 
    chr = chr - ' '; 

    switch (size)
    {
        case 12:
            pfont = (uint8_t *)asc2_1206[chr]; 
            break;

        case 16:
            pfont = (uint8_t *)asc2_1608[chr]; 
            break;

        default:
            return ;
    }

    for (t = 0; t < csize; t++)
    {
        temp = pfont[t];   

        for (t1 = 0; t1 < 8; t1++)   
        {
            if (temp & 0x80)       
            {
                LCD_DrawPoint(x, y, color);      
            }
            else if (mode == 0)   
            {
                LCD_DrawPoint(x, y, BACK_COLOR); 
            }

            temp <<= 1; 
            y++;

            if (y >= lcdstr.height)return; 

            if ((y - y0) == size)  
            {
                y = y0; 
                x++;    

                if (x >= lcdstr.width)return;   

                break;
            }
        }
    }
}   
//m^n函数
uint32_t LCD_Pow(uint8_t m,uint8_t n)
{
	uint32_t result=1;	 
	while(n--)result*=m;    
	return result;
}			 
//显示数字，高位为0，则不显示
//x,y :起点坐标
//len :数字的位数
//size:字体大小
//color:颜色
//num:数值(0~4294967295);	 
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint16_t color)
{         	
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				LCD_ShowChar(x+(size/2)*t,y,' ',size,0,color);
				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,0,color); 
	}
} 

//显示数字，高位为0，还是显示
//x,y :起点坐标
//num:数值(0~999999999);	 
//len:长度，即要显示的位数
//size:字体大小
//mode:
//[7]:0不填充;1填充0
//[6:1]:保留
//[0]:0,非叠加显示;1叠加显示.
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode,uint16_t color)
{  
	uint8_t t,temp;
	uint8_t enshow=0;						   
	for(t=0;t<len;t++)
	{
		temp=(num/LCD_Pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				if(mode&0X80)LCD_ShowChar(x+(size/2)*t,y,'0',size,mode&0X01,color);  
				else LCD_ShowChar(x+(size/2)*t,y,' ',size,mode&0X01,color);  
 				continue;
			}else enshow=1; 
		 	 
		}
	 	LCD_ShowChar(x+(size/2)*t,y,temp+'0',size,mode&0X01,color); 
	}
} 

//显示字符串
//x,y:起点坐标
//width,height:区域大小  
//size:字体大小
//*p:字符串起始地址		  
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,char *p,uint16_t color)
{         
	uint8_t x0=x;
	width+=x;
	height+=y;
	while((*p<='~')&&(*p>=' '))//判断是不是非法字符
    {       
        if(x>=width){x=x0;y+=size;}
        if(y>=height)break;//退出
        LCD_ShowChar(x,y,*p,size,0,color);
        x+=size/2;
        p++;
    }  
}

//设置窗口
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height)
{   
	width=sx+width-1;
	height=sy+height-1;

	LCD_WR_REG(lcdstr.setxcmd);
	LCD_WR_DATA(sx>>8);  
	LCD_WR_DATA(sx&0XFF);	  
	LCD_WR_DATA(width>>8);   
	LCD_WR_DATA(width&0XFF);   
	LCD_WR_REG(lcdstr.setycmd);
	LCD_WR_DATA(sy>>8);   
	LCD_WR_DATA(sy&0XFF);  
	LCD_WR_DATA(height>>8);   
	LCD_WR_DATA(height&0XFF);  
}


/*
	\brief：	显示汉字（行列式，高位在前）
	\param：	x：横坐标，y：列坐标
				w：字符宽度  h字符高度
				size：汉字大小
				Font：保存汉字的首地址
				colour：颜色
	\retval：	none
*/
// 慎用
void LCD_DisplayChinese(uint16_t x,uint16_t y,uint16_t size,char *Font,uint16_t colour)
{
	char *pFont = Font;
	uint8_t GBKL,GBKH,tmp;
	uint16_t SIZE = size*size/8;//计算字节数
	uint16_t y0=y;//记录第一行显示的初始位置
	uint16_t x1=x;//记录显示的初始位置
	uint16_t y1=y;
	uint16_t i,j;
	uint32_t Addr_offset;//汉字的偏移地址
	uint8_t *pBuff = malloc(SIZE);//动态分配空间
	while(*pFont != '\0')
	{
		//计算汉字的偏移地址
		GBKH = *pFont++;//高字节
		GBKL = *pFont++;//低字节
		if(GBKL < 0x7F) 
		{
			Addr_offset = ((GBKH-0x81)*190 + GBKL - 0x40)*(size * 2);
		}
		else
		{
			Addr_offset = ((GBKH-0x81)*190 + GBKL - 0x41)*(size * 2);
		}
		//从flash中取出一个汉字
		switch(size)
		{
			case 16:	W25Q64_ReadData(W25Q64_GBK_ADDR + Addr_offset,pBuff,SIZE);break;
			default : W25Q64_ReadData(W25Q64_GBK_ADDR + Addr_offset,pBuff,SIZE);break;
		}
		//显示一个汉字
		for(i=0;i<SIZE;i++)
		{
			tmp = *(pBuff+i);
			y = y0;
			for(j=0;j<8;j++)
			{
				if(tmp & 0x80)	//高位先发
				{
					LCD_DrawPoint(x,y,colour);
				}
				tmp <<= 1;
				y++;
			}
			x++;
			if(x-x1 == size)
			{
				x = x1;
				y0 += 8;
			}
		}
		//一个汉字显示完成，为下一个汉字显示做准备
		x += size;
		
		if(LCD_WIDTH - x < size)//考虑是否需要换行
		{
			y1 += size+4;
			x = 0;
		}
		x1 = x;
		y0 = y1;
	}
	free(pBuff);//释放空间
}





//写入要写的寄存器序号
void LCD_WR_REG(uint16_t regval)
{
    LCD->LCD_REG = regval;
}
//写LCD数据
//data:要写入的值
void LCD_WR_DATA(uint16_t data)
{
    LCD->LCD_RAM = data;
}
//写GRAM
//data:要写入的值
void LCD_WriteRAM(uint16_t RGB_Code)
{
    LCD->LCD_RAM = RGB_Code;
}
//读LCD数据
//返回值:读到的值
uint16_t LCD_RD_DATA(void)
{
    uint16_t ram;           //防止被优化
    ram = LCD->LCD_RAM;
    return ram;
}
//写寄存器
//LCD_Reg:寄存器地址
//LCD_RegValue:要写入的数据
void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue)
{
    LCD->LCD_REG = LCD_Reg;
    LCD->LCD_RAM = LCD_RegValue;
}

//读寄存器
//LCD_Reg:寄存器地址
//返回值:读到的数据
uint16_t LCD_ReadReg(uint16_t LCD_Reg)
{
    LCD_WR_REG(LCD_Reg);        //写入要读的寄存器序号
    FL_DelayUs(5);
    return LCD_RD_DATA();       //返回读到的值
}

//开始写GRAM
void LCD_WriteRAM_Prepare(void)
{
    LCD->LCD_REG = lcdstr.wramcmd;
}


// 新的LCD初始化代码
void LCD_INIT_CODE(void)
{  
	LCD_WR_REG(0x11);
	FL_DelayMs(120);

	LCD_WR_REG(0Xf0);
	LCD_WR_DATA(0xc3);

	LCD_WR_REG(0Xf0);
	LCD_WR_DATA(0x96);

	LCD_WR_REG(0X36);  
	LCD_WR_DATA(0x48);     //??????

	LCD_WR_REG(0Xb4);
	LCD_WR_DATA(0x01);	  //01

	LCD_WR_REG(0x3a);
	LCD_WR_DATA(0x05);

	LCD_WR_REG(0Xe8);
	LCD_WR_DATA(0x40);
	LCD_WR_DATA(0x82);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0x27);
	LCD_WR_DATA(0x0a);
	LCD_WR_DATA(0xb6);
	LCD_WR_DATA(0x33);

	//LCD_WR_REG(0xc1);
	//LCD_WR_DATA(0x0f);//06 ????????

	LCD_WR_REG(0Xc5);	 //18 ????????
	LCD_WR_DATA(0x23);	 //23

	LCD_WR_REG(0Xc2);	
	LCD_WR_DATA(0xa7);

	LCD_WR_REG(0Xe0);
	LCD_WR_DATA(0xf0);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x06);
	LCD_WR_DATA(0x0f);
	LCD_WR_DATA(0x12);
	LCD_WR_DATA(0x1d);
	LCD_WR_DATA(0x36);
	LCD_WR_DATA(0x54);
	LCD_WR_DATA(0x44);
	LCD_WR_DATA(0x0c);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0x16);
	LCD_WR_DATA(0x13);
	LCD_WR_DATA(0x15);

	LCD_WR_REG(0Xe1);
	LCD_WR_DATA(0xf0);
	LCD_WR_DATA(0x01);
	LCD_WR_DATA(0x05);
	LCD_WR_DATA(0x0a);
	LCD_WR_DATA(0x0b);
	LCD_WR_DATA(0x07);
	LCD_WR_DATA(0x32);
	LCD_WR_DATA(0x44);
	LCD_WR_DATA(0x44);
	LCD_WR_DATA(0x0c);
	LCD_WR_DATA(0x18);
	LCD_WR_DATA(0x17);
	LCD_WR_DATA(0x13);
	LCD_WR_DATA(0x16);

	LCD_WR_REG(0Xf0);
	LCD_WR_DATA(0x3c);

	LCD_WR_REG(0Xf0);
	LCD_WR_DATA(0x69);
	FL_DelayMs(120);

	LCD_WR_REG(0X29);
}
