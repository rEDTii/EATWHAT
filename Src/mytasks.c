/* 集中存放任务创建 */
/* 关于栈大小选取：
	1)一级调用最多保存9个寄存器，每级调用最多需要9个StackType_t大小；
	2)切换任务保存现场需要16个寄存器，需要16个StackType_t大小
	3)局部变量，每一级函数调用的局部变量都要出入栈 
*/
#include "mytasks.h"
#include "main.h"
#include "task.h"
#include "GUI_APP.h"
#include "rtc.h"
#include "semphr.h"


// 喂狗任务
static void IWDTTask(void* pvParameters) {    
    while (1){
				vTaskDelay(2000);
        FL_IWDT_ReloadCounter(IWDT);
    }
}

// RTOS堆监测
static void vTaskCheckHeap(void *pvParameters) {
    while(1) {
				vTaskDelay(1000);

        // 获取自系统启动以来的最小空闲堆大小
        size_t minEverFreeHeap = xPortGetMinimumEverFreeHeapSize();
				printf("minEverFreeHeap: %u bytes\n", minEverFreeHeap);

//			  UBaseType_t watermark = uxTaskGetStackHighWaterMark(NULL);
//				printf("watermark: %d bytes\n", (uint32_t)watermark);		
			
        vTaskDelay(1000);
    }
}


// 启动任务
void StartTask(void* pvParameters) {
		/* 先挂载fatfs */
		FatfsInit();
		// 获取音频目录文件
		getwavfileList();
	
		/* 初始化GUI */
		uGUI_Demo();

		/* 在调度中创建其他任务 */
		//ui时间更新
		UitimeTaskHandleTaskInit();
		//创建player and recorder时间更新任务
		sectimeTaskHandleTaskInit();
		// 触摸检测
		TouchHandlerTaskInit();
		// 录音
		recorder_start();
		// 喂狗
		xTaskCreate(IWDTTask, "IWDTTask", 128,  NULL, 2, NULL);
//		// RTOS堆监测
//		xTaskCreate(vTaskCheckHeap, "CheckTask", 128,  NULL, 2, NULL);
	
		/* 删除启动任务 */
		vTaskDelete(NULL);
}


// 启动任务创建
void StartTaskInit() {
		xTaskCreate(StartTask, "start", 256, NULL, 6, NULL);
}

