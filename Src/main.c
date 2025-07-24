#include "main.h"
#include "task.h"
#include "semphr.h"
#include "hardware_test.h"
#include "mytasks.h"


void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName) {
    (void)xTask;
    printf("Overflowed in %s\n", pcTaskName);
    while(1);
}

int main(void)
{
    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    MF_Clock_Init();

    /* Initialize FL Driver Library */
    FL_Init();
	
    /* Initialize all configured peripherals */
    MF_Config_Init();
   
		/* 模块init */
    Debug_UART_Init();
		FL_DelayMs(10);
		showCLKinfo();
	
		/* BSP init */
		BSP_init();
		FL_DelayMs(10);
		FL_IWDT_ReloadCounter(IWDT);
		TP_init();
	
//		LCD_test();
		FL_DelayMs(10);			
	
		/* 创建任务 */
		StartTaskInit();
		
		/* 启动任务调度 */
		printf("TaskStartScheduler starts.\r\n");
    vTaskStartScheduler();
		
		while(1){
		}
}
