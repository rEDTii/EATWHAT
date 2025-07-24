#ifndef __LCD_H__
#define __LCD_H__

#include "fm33fk5xx_fl.h"


// 笔画颜色
#define WHITE         	 0xFFFF
#define BLACK         	 0x0000	  
#define BLUE         	   0x001F  
#define BRED             0XF81F
#define GRED 			 	     0XFFE0
#define GBLUE			       0X07FF
#define RED           	 0xF800
#define MAGENTA       	 0xF81F
#define GREEN         	 0x07E0
#define CYAN          	 0x7FFF
#define YELLOW        	 0xFFE0
#define BROWN 			     0XBC40
#define BRRED 			     0XFC07
#define GRAY  			     0X8430

//GUI颜色
#define DARKBLUE      	 0X01CF
#define LIGHTBLUE      	 0X7D7C
#define GRAYBLUE       	 0X5458
// 以上三色为PANEL颜色

#define LIGHTGREEN     	 0X841F // 浅绿
#define LIGHTGRAY      	 0XEF5B // 浅灰(PANNEL)
#define LGRAY 			     0XC618 // 浅灰(PANNEL), 窗体背景色

#define LGRAYBLUE        0XA651 // 浅灰蓝色(中间层颜色)
#define LBBLUE           0X2B12 // 浅棕蓝色(选择条目的反色)

// 快刷
#define FAST     1


// 横竖屏显示
#define Landscape 0		//1:横屏  0:竖屏

// 屏幕分辨率
#define LCD_WIDTH  320
#define LCD_HEIGHT 480

// 扫描方向定义
#define L2R_U2D  0 // 从左到右，从上到下
#define L2R_D2U  1 // 从左到右，从下到上
#define R2L_U2D  2 // 从右到左，从上到下
#define R2L_D2U  3 // 从右到左，从下到上

#define U2D_L2R  4 // 从上到下，从左到右
#define U2D_R2L  5 // 从上到下，从右到左
#define D2U_L2R  6 // 从下到上，从左到右
#define D2U_R2L  7 // 从下到上，从右到左

// RGB
#define RGB 0x00
#define BGR 0x08
#define COLORORDER BGR  //RGB BGR切换，可用于修改红蓝反色

//LCD地址结构体
typedef struct
{
    uint16_t LCD_REG;
    uint16_t LCD_RAM;
} LCD_TypeDef;
#define LCD_BASE        ((uint32_t)(0x6C000000 | 0x000007E))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

//LCD重要参数集
typedef struct
{
    uint16_t    width;                  //LCD 宽度
    uint16_t    height;                 //LCD 高度
		uint32_t		total_pixels;
    uint32_t    id;                         //LCD ID
    uint8_t     dir;                        //横屏还是竖屏控制：0，竖屏；1，横屏。
    uint16_t    wramcmd;                //开始写gram指令
    uint16_t  setxcmd;              //设置x坐标指令
    uint16_t  setycmd;              //设置y坐标指令
} lcd_struct;

extern lcd_struct lcdstr;

extern uint8_t brightness;

// 字库
extern const unsigned char asc2_1206[95][12];
extern const unsigned char asc2_1608[95][16];
//extern const uint8_t Chinses_16[32776];

void LCD_Init(void);
void LCD_INIT_CODE(void);

void LCD_WR_REG(uint16_t regval);
void LCD_WR_DATA(uint16_t data);
uint16_t LCD_RD_DATA(void);
void LCD_WriteReg(uint16_t LCD_Reg, uint16_t LCD_RegValue);
void LCD_WriteRAM_Prepare(void);
void LCD_WriteRAM(uint16_t RGB_Code);

void PWM_BL_Init(void);
void Set_PWM_BL(uint8_t value);


void LCD_Clear(uint16_t color);
void LCD_Scan_Dir(uint8_t dir);
void LCD_Display_Dir(uint8_t dir);
void LCD_DrawPoint(uint16_t x,uint16_t y, uint32_t color);
void LCD_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t color);
void LCD_Color_Fill(uint16_t sx,uint16_t sy,uint16_t ex,uint16_t ey,uint16_t *color);
void LCD_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);
void LCD_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2,uint16_t color);
void Draw_Circle(uint16_t x0,uint16_t y0,uint8_t r,uint16_t color);
void LCD_ShowChar(uint16_t x, uint16_t y, char chr, uint8_t size, uint8_t mode, uint16_t color);
uint32_t LCD_Pow(uint8_t m,uint8_t n);
void LCD_ShowNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint16_t color);
void LCD_ShowxNum(uint16_t x,uint16_t y,uint32_t num,uint8_t len,uint8_t size,uint8_t mode,uint16_t color);
void LCD_ShowString(uint16_t x,uint16_t y,uint16_t width,uint16_t height,uint8_t size,char *p,uint16_t color);
void LCD_Set_Window(uint16_t sx,uint16_t sy,uint16_t width,uint16_t height);
void LCD_DisplayChinese(uint16_t x,uint16_t y,uint16_t size,char *Font,uint16_t colour);
#endif
