/* 提供触摸状态和坐标 */
#include "touch.h"
#include "gt911.h"
#include "FreeRTOS.h"
#include "task.h"
#include "ugui.h"
#include "semphr.h"

TaskHandle_t xScanTaskHandle = NULL;
static void TPScanTask(void *pvParameters);


uint8_t TP_init() {
    return GT911_Init();
}


// 创建扫描任务
void TouchHandlerTaskInit(void) {
    xTaskCreate(TPScanTask, "tp_scan", 256, NULL, 4, &xScanTaskHandle);
}


// 触摸中断处理，负责发送任务通知给TPScanTask
void EXTID_IRQHandler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	
    if(FL_GPIO_IsActiveFlag_EXTI(GPIO, FL_GPIO_EXTI_LINE_14) == 0x01UL) {
        FL_GPIO_ClearFlag_EXTI(GPIO, FL_GPIO_EXTI_LINE_14);  
			
				if (xScanTaskHandle != NULL) {
						// 更新通知值。eIncrement模式会忽略传入的ulValue，设为0无所谓
						xTaskNotifyFromISR(xScanTaskHandle, 0, eIncrement, &xHigherPriorityTaskWoken);
						portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
				}
    }
}


// 进一步优化版本的扫描任务，使用任务通知值的奇偶判断是按下中断还是空闲中断，优化资源占用
static void TPScanTask(void *pvParameters) {
    uint32_t ulNotifiedValue = 0, last_Value = 0;
		uint8_t interval_flag = 0;
		// 已有任务再开启中断
    NVIC_EnableIRQ(EXTID_IRQn);
	
    while (1) {
        // 不阻塞等待通知值被设置
        xTaskNotifyWait(0, 0, &ulNotifiedValue, 0);
			
				// 如果本次任务通知值为奇数，且上次任务通知值为偶数，则判断为开始按下中断发生; 反之如果本次任务通知值为偶数，且上一次为奇数，则判断为空闲中断发生
				if( (ulNotifiedValue & (1<<0)) && (!(last_Value & (1<<0))) ) {
						interval_flag = 1;
				} else if((!(ulNotifiedValue & (1<<0))) && (last_Value & (1<<0))) {
						interval_flag = 0;
				}
					
				if (interval_flag) {
						GT911_Scan_INT();
						// 检测按下
						if (tp_dev.sta & TP_PRES_DOWN) {
								tp_dev.sta &= ~TP_PRES_DOWN;
								UG_TouchUpdate(tp_dev.x[0], tp_dev.y[0],TOUCH_STATE_PRESSED);
						}
				}
				else {
						UG_TouchUpdate(-1,-1,TOUCH_STATE_RELEASED);
				}
				
				// 更新last_value值
				last_Value = ulNotifiedValue;
				UG_Update();
				vTaskDelay(30);
    }
}