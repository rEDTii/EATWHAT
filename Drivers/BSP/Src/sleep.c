#include "main.h"
#include "fm33fk5xx_fl.h"
#include "sleep.h"
// Sleep
void Sleep(void)
{
    FL_PMU_SleepInitTypeDef LPM_InitStruct;
    FL_CMU_EnableGroup2BusClock(FL_CMU_GROUP2_BUSCLK_ADC);
    /*VCM共模控制信号：设置为间歇模式*/
    CLEAR_BIT(ADC->CALR, 1 << 10);
    /* 建议清零 CPU->VAO ，否则会带来十几 uA 的额外电流*/
    FL_CDIF_DisableCPUToVAO(CDIF);

    LPM_InitStruct.sleepMode                   = FL_PMU_SLEEP_MODE_SLEEP;
    LPM_InitStruct.wakeupFrequency             = FL_PMU_RCHF_WAKEUP_FREQ_8MHZ;
    LPM_InitStruct.avrefHoldTime               = FL_PMU_AVREF_HOLDTIME_0P5MS;
    LPM_InitStruct.ram0PowerControl            = FL_PMU_RAM0_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    LPM_InitStruct.ram1PowerControl            = FL_PMU_RAM1_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    LPM_InitStruct.cacheDramPowerControl       = FL_PMU_CACHEDRAM_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    LPM_InitStruct.cacheTramPowerControl       = FL_PMU_CACHETRAM_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    FL_PMU_Sleep_Init(PMU, &LPM_InitStruct);

    /* 睡眠电源模式*/
    FL_PMU_SetLowPowerMode(PMU, FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP);
    __WFI();

}

// DeepSleep
void DeepSleep(void)
{
    FL_PMU_SleepInitTypeDef LPM_InitStruct;

    LPM_InitStruct.sleepMode                   = FL_PMU_SLEEP_MODE_DEEPSLEEP;
    LPM_InitStruct.wakeupFrequency             = FL_PMU_RCHF_WAKEUP_FREQ_8MHZ;
    LPM_InitStruct.avrefHoldTime               = FL_PMU_AVREF_HOLDTIME_0P5MS;
    LPM_InitStruct.ram0PowerControl            = FL_PMU_RAM0_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    LPM_InitStruct.ram1PowerControl            = FL_PMU_RAM1_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    LPM_InitStruct.cacheDramPowerControl       = FL_PMU_CACHEDRAM_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    LPM_InitStruct.cacheTramPowerControl       = FL_PMU_CACHETRAM_SLEEP_NORMAL_OR_DEEPSLEEP_POWERDOWN;
    FL_PMU_Sleep_Init(PMU, &LPM_InitStruct);

    /* 睡眠电源模式*/
    FL_PMU_SetLowPowerMode(PMU, FL_PMU_POWER_MODE_SLEEP_OR_DEEPSLEEP);
    __WFI();

}
