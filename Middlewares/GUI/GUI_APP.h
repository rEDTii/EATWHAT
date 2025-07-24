/* GUI */
#ifndef __GUI_APP_H
#define __GUI_APP_H

#include "ugui.h"
#include "lcd.h"
#include "ff.h"

extern UG_WINDOW  window_1;
extern UG_WINDOW  window_2;
extern UG_WINDOW  window_3;
extern UG_WINDOW  window_4;
extern UG_WINDOW  window_5;
extern UG_WINDOW  window_7;
extern UG_WINDOW  window_8;
extern UG_WINDOW  window_9;
extern UG_GUI gui ;

extern char ui_prompt[];

UG_RESULT _HW_DrawLine( UG_S16 x1,UG_S16 y1,UG_S16 x2,UG_S16 y2,UG_COLOR c);
UG_RESULT _HW_FillFrame( UG_S16 x1,UG_S16 y1,UG_S16 x2,UG_S16 y2,UG_COLOR c);
void _HW_DrawPoint(UG_S16 x,UG_S16 y,UG_COLOR c);
void uGUI_Init(void);
void uGUI_Window1Demo(void);
void uGUI_Demo(void);
void ringing(void);
#endif