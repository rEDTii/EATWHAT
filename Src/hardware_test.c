#include "hardware_test.h"


void LCD_test() {
		LCD_Fill(80,0,200,100, YELLOW);
		LCD_Fill(80,200,200,300, GREEN);
		LCD_Fill(80,400,200,480, GREEN);
//		LCD_ShowString(0, 0, 600, 16, 16, "Hello world.", BLACK);
//		LCD_DrawRectangle(50, 50, 80, 100, GREEN);
//		LCD_ShowxNum(160, 32, 123456, 8, 16, 0x81, RED);
//		Draw_Circle(200, 180, 20, BLACK);
}

