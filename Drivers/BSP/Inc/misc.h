#ifndef __MISC_H
#define __MISC_H

#include "fm33fk5xx_fl.h"

#define LED0_GPIO   GPIOF
#define LED0_PIN    FL_GPIO_PIN_4

#define LED1_GPIO   GPIOF
#define LED1_PIN    FL_GPIO_PIN_2

#define KEY4_GPIO     GPIOB
#define KEY4_PIN      FL_GPIO_PIN_0

#define LED0_ON()   FL_GPIO_ResetOutputPin(LED0_GPIO, LED0_PIN)
#define LED0_OFF()  FL_GPIO_SetOutputPin(LED0_GPIO, LED0_PIN)
#define LED0_TOG()  FL_GPIO_ToggleOutputPin(LED0_GPIO, LED0_PIN)

#define LED1_ON()   FL_GPIO_ResetOutputPin(LED1_GPIO, LED1_PIN)
#define LED1_OFF()  FL_GPIO_SetOutputPin(LED1_GPIO, LED1_PIN)
#define LED1_TOG()  FL_GPIO_ToggleOutputPin(LED1_GPIO, LED1_PIN)

#define KEY4_P      (1 ==FL_GPIO_GetInputPin(KEY4_GPIO, KEY4_PIN))
#define KEY4_N      (0 == FL_GPIO_GetInputPin(KEY4_GPIO, KEY4_PIN))

void LED_IO_Init(void);//LED引脚配置
void FOUT0_IO_OUT(void);
void KEY_IO_Init(void);

#endif /* __MISC_H*/
