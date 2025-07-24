#include "misc.h"

// led0和led1和lcd存在io冲突，避免同时使用
//LED引脚配置
void LED_IO_Init(void)
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct = {0};
    //LED引脚
    GPIO_InitStruct.pin = LED0_PIN;
    GPIO_InitStruct.mode = FL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON1;
    FL_GPIO_Init(LED0_GPIO, &GPIO_InitStruct);

    FL_GPIO_SetOutputPin(LED0_GPIO, LED0_PIN);

    GPIO_InitStruct.pin = LED1_PIN;
    GPIO_InitStruct.mode = FL_GPIO_MODE_OUTPUT;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON1;
    FL_GPIO_Init(LED1_GPIO, &GPIO_InitStruct);

    FL_GPIO_SetOutputPin(LED1_GPIO, LED1_PIN);
}

//KEY引脚配置
void KEY_IO_Init(void)
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct = {0};
    //LED引脚
    GPIO_InitStruct.pin = KEY4_PIN;
    GPIO_InitStruct.mode = FL_GPIO_MODE_INPUT;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON1;
    FL_GPIO_Init(KEY4_GPIO, &GPIO_InitStruct);
}

//fout 输出 clk
void FOUT0_IO_OUT(void)
{
    FL_GPIO_InitTypeDef    GPIO_InitStruct = {0};

    GPIO_InitStruct.pin = FL_GPIO_PIN_0;
    GPIO_InitStruct.mode = FL_GPIO_MODE_DIGITAL;
    GPIO_InitStruct.outputType = FL_GPIO_OUTPUT_PUSHPULL;
    GPIO_InitStruct.pull = FL_GPIO_BOTH_DISABLE;
    GPIO_InitStruct.driveStrength = FL_GPIO_DRIVESTRENGTH_X3;
    GPIO_InitStruct.remapPin = FL_GPIO_PINREMAP_FUNCTON1;
    FL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    //fout  输出
    FL_GPIO_SetFOUT0(GPIO, FL_GPIO_FOUT0_SELECT_RCHF_DIV64);
    //      FL_GPIO_SetFOUT0(GPIO, FL_GPIO_FOUT0_SELECT_AHBCLK_DIV64);
    //  FL_GPIO_SetFOUT0(GPIO, FL_GPIO_FOUT0_SELECT_XTHF_DIV64);
    //  FL_GPIO_SetFOUT0(GPIO, FL_GPIO_FOUT0_SELECT_LSCLK);
    //  FL_GPIO_SetFOUT0(GPIO, FL_GPIO_FOUT0_SELECT_XTLF);

}
