/****************************************************************************************************
 * @file     FM33FK5XX.h
 *
 * @brief    CMSIS CORTEX-M33 Peripheral Access Layer Header File for
 *           FM33FK5XX from Keil.
 *
 * @version  V0.0.1
 * @date     23 march 2023
 *
 * @note     Generated with SVDConv V2.87e
 *           from CMSIS SVD File 'FM33FK5XX.SVD' Version 1.0,
 *
 * @par      ARM Limited (ARM) is supplying this software for use with Cortex-M
 *           processor based microcontroller, but can be equally used for other
 *           suitable processor architectures. This file can be freely distributed.
 *           Modifications to this file shall be clearly marked.
 *
 *           THIS SOFTWARE IS PROVIDED “AS IS”. NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *           OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *           MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *           ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *           CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *******************************************************************************************************/

/** @addtogroup Keil
  * @{
  */

/** @addtogroup FM33FK5XX
  * @{
  */

#ifndef FM33FK5XX_H
#define FM33FK5XX_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;
typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunState;
typedef enum {FAIL = 0, PASS = !FAIL} ErrorStatus;

#define __RCHF_INITIAL_CLOCK        (8000000)        /* Value of the Internal RC HIGH oscillator in Hz */
#define __RCMF_CLOCK                (4000000)        /* Value of the Internal RC 4M oscillator in Hz */
#define __LPOSC_CLOCK               (32000)          /* Value of the Internal RC LOW oscillator in Hz */
#define __XTHF_CLOCK                (8000000)        /* Value of the EXTERNAL oscillator in Hz */
#define __XTLF_CLOCK                (32768)          /* Value of the EXTERNAL oscillator in Hz */

/* -------------------------  Interrupt Number Definition  ------------------------ */

typedef enum
{

    /* -------------------  FM33FK5XX Processor Exceptions Numbers  -------------------*/
    NMI_IRQn                      = -14,              /*!<   2  不可屏蔽中断 */
    Hardfault_IRQn                = -13,              /*!<   3  处理器内部错误 */
    MemManage_IRQn                = -12,              /*!<   4  MPU错误 */
    BusFault_IRQn                 = -11,              /*!<   5  总线错误 */
    UsageFault_IRQn               = -10,              /*!<   6  指令执行错误 */
    SVCall_IRQn                   = -5,               /*!<  11  SupervisorCall */
    DebugMonitor_IRQn             = -4,               /*!<  11  DebugMonitor */
    PendSV_IRQn                   = -2,               /*!<  14  系统服务请求 */
    SysTick_IRQn                  = -1,               /*!<  15  内核定时器中断 */

    /* --------------------  Cortex-M33 Specific Interrupt Numbers  --------------------*/
    WWDT_IRQn                     = 0,                /*!<   0  WWDT */
    SVD_IRQn                      = 1,                /*!<   1  SVD */
    RTC_IRQn                      = 2,                /*!<   2  RTC */
    IWDT_IRQn                     = 3,                /*!<   3  IWDT */
    FLASH_IRQn                    = 4,                /*!<   4  FLASH */
    HFDET_SCSE_IRQn               = 5,                /*!<   5  HFDET & Sysclk selection error */
    LFDET_IRQn                    = 6,                /*!<   6  LFDET */
    MAP_ERR_IRQn                  = 7,                /*!<   7  MAP_ERR */
    ADC_IRQn                      = 8,                /*!<   8  ADC */
    DAC0_IRQn                     = 9,                /*!<   9  DAC0 */
    DAC1_IRQn                     = 10,               /*!<  10  DAC1 */
    SPI0_IRQn                     = 11,               /*!<  11  SPI0 */
    SPI1_IRQn                     = 12,               /*!<  12  SPI1 */
    SPI2_IRQn                     = 13,               /*!<  13  SPI2 */
    SPI3_IRQn                     = 14,               /*!<  14  SPI3 */
    SPI4_IRQn                     = 15,               /*!<  15  SPI4 */
    UART0_IRQn                    = 18,               /*!<  16  UART0 */
    UART1_IRQn                    = 19,               /*!<  17  UART1 */
    UART2_IRQn                    = 20,               /*!<  18  UART2 */
    UART3_IRQn                    = 21,               /*!<  19  UART3 */
    UART4_IRQn                    = 22,               /*!<  20  UART4 */
    UART5_IRQn                    = 23,               /*!<  21  UART5 */
    UART6_IRQn                    = 24,               /*!<  22  UART6 */
    UART7_IRQn                    = 25,               /*!<  23  UART7 */
    LPUART0_IRQn                  = 29,               /*!<  29  LPUART0 */
    LPUART1_IRQn                  = 30,               /*!<  30  LPUART1 */
    EXTIA_IRQn                    = 32,               /*!<  32  EXTIA */
    EXTIB_IRQn                    = 33,               /*!<  33  EXTIB */
    EXTIC_IRQn                    = 34,               /*!<  34  EXTIC */
    EXTID_IRQn                    = 35,               /*!<  35  EXTID */
    EXTIE_IRQn                    = 36,               /*!<  36  EXTIE */
    EXTIF_IRQn                    = 37,               /*!<  37  EXTIF */
    I2C0_IRQn                    = 38,                /*!<  38  I2C0 */
    I2C1_IRQn                    = 39,                /*!<  39  I2C1 */
    I2CSMB0_IRQn                  = 40,               /*!<  40  I2CSMB0 */
    I2CSMB1_IRQn                  = 41,               /*!<  41  I2CSMB1 */
    I2CSMB2_IRQn                  = 42,               /*!<  42  I2CSMB2 */
    CCL_IRQn                      = 45,               /*!<  45  CCL */
    AES_IRQn                      = 46,               /*!<  46  AES */
    DMA_IRQn                      = 50,               /*!<  50  DMA */
    WKUPX_IRQn                    = 51,               /*!<  51  WKUPX */
    LUT_IRQn                      = 52,               /*!<  52  LUT */
    COMPX_IRQn                    = 53,               /*!<  53  COMPX */
    CAN_IRQn                      = 54,               /*!<  54  FSCAN */
    FDCAN_IRQn                    = 56,               /*!<  56  FDCAN */
    LPTIM16_IRQn                  = 60,               /*!<  60  LPTIM16 */
    BSTIM16_IRQn                  = 62,               /*!<  62  BSTIM16 */
    ATIM0_IRQn                    = 64,               /*!<  64  ATIM0 */
    ATIM1_IRQn                    = 65,               /*!<  65  ATIM1 */
    GPTIM0_IRQn                   = 68,               /*!<  68  GPTIM0 */
    GPTIM1_IRQn                   = 69,               /*!<  69  GPTIM1 */
    GPTIM2_IRQn                   = 70,               /*!<  70  GPTIM2 */
    EPWM0_IRQn                    = 72,               /*!<  72  EPWM0 */
    EPWM0_TZ_IRQn                 = 73,               /*!<  73  EPWM0_TZ */
    EPWM1_IRQn                    = 74,               /*!<  74  EPWM1 */
    EPWM1_TZ_IRQn                 = 75,               /*!<  75  EPWM1_TZ */
    EPWM2_IRQn                    = 76,               /*!<  76  EPWM2 */
    EPWM2_TZ_IRQn                 = 77,               /*!<  77  EPWM2_TZ */
    EPWM3_IRQn                    = 78,               /*!<  78  EPWM3 */
    EPWM3_TZ_IRQn                 = 79,               /*!<  79  EPWM3_TZ */
    FPU_IRQn                      = 82,               /*!<  82  FPU */
    USB_IRQn                      = 83,               /*!<  83  USB */
    EPSC_IRQn                     = 85,               /*!<  85  EPSC */
} IRQn_Type;

/** @addtogroup Configuration_of_CMSIS
  * @{
  */

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of the Cortex-M33 Processor and Core Peripherals  ------ */
#define __SAUREGION_PRESENT       0U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */

/** @} */ /* End of group Configuration_of_CMSIS */

#include "core_starmc1.h"                   /*!< Star-MC1 processor and core peripherals */
#include "system_fm33fk5xx.h"               /*!< FM33FK5XX System */

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/** @addtogroup Device_Peripheral_Registers
  * @{
  */

/* -------------------  Start of section using anonymous unions  ------------------ */
#if defined(__CC_ARM)
#pragma push
#pragma anon_unions
#elif defined(__ICCARM__)
#pragma language=extended
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#pragma warning 586
#else
#warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================                       FLS                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t RDCR;                   /*!<  FlashReadControlRegister,                             Address offset: 0x00 */
    __IO uint32_t RSV1[4];                /*!<  RESERVED REGISTER,                                    Address offset: 0x04 */
    __IO uint32_t EPCR;                   /*!<  FlashErase/ProgramControlRegister,                    Address offset: 0x14 */
    __O  uint32_t KEY;                    /*!<  FlashKeyRegister,                                     Address offset: 0x18 */
    __IO uint32_t IER;                    /*!<  FlashInterruptEnableRegister,                         Address offset: 0x1C */
    __IO uint32_t ISR;                    /*!<  FlashInterruptStatusRegister,                         Address offset: 0x20 */
} FLASH_Type;

/* ================================================================================ */
/* ================                       PMU                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  PowerManagementControlRegister,                       Address offset: 0x00 */
    __IO uint32_t WKTR;                   /*!<  WakeupTimeRegister,                                   Address offset: 0x04 */
    __IO uint32_t WKFR1;                   /*!<  WakeupSourceFlagsRegister1,                          Address offset: 0x08 */
    __IO uint32_t WKFR2;                  /*!<  WakeupSourceFlagsRegister2,                           Address offset: 0x0C */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x10 */
    __IO uint32_t RAMCR;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x14 */
    __IO uint32_t RSV2[9];                /*!<  RESERVED REGISTER,                                    Address offset: 0x18 */
    __IO uint32_t BUFCR;                  /*!<  ,                                                     Address offset: 0x3C */
    __IO uint32_t RSV3[4];                /*!<  ,                                                     Address offset: 0x40 */
    __IO uint32_t PTAT_CR;                /*!<  PTATControlRegister,                                  Address offset: 0x50 */
    __IO uint32_t RSV4[11];               /*!<  ,                                                     Address offset: 0x54 */
    __IO uint32_t PHYCR;                  /*!<  ,                                                     Address offset: 0x80 */
} PMU_Type;

/* ================================================================================ */
/* ================                       VREFP                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t RSV1[16];               /*!<  RESERVED REGISTER,                                    Address offset: 0x00 */
    __IO uint32_t CR;                     /*!<  VREFPControlRegister,                                 Address offset: 0x40 */
    __IO uint32_t CFGR;                   /*!<  VREFPConfigRegister,                                  Address offset: 0x44 */
    __IO uint32_t RSV2;                   /*!<  VREFPStatusandInterruptRegister,                      Address offset: 0x48 */
    __IO uint32_t TR;                     /*!<  VREFPTrimRegister,                                    Address offset: 0x4C */
} VREFP_Type;

/* ================================================================================ */
/* ================                       VAO                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t RSTCR;                  /*!<  VBATResetControlRegister,                             Address offset: 0x00 */
    __IO uint32_t XTLFCR;                 /*!<  XTLFControlRegister,                                  Address offset: 0x04 */
    __IO uint32_t LFDIER;                  /*!<  XTLFOscillationFailDetectionInterruptEnableRegister,  Address offset: 0x08 */
    __IO uint32_t LFDISR;                  /*!<  XTLFOscillationFailDetectionInterruptStatusRegister,  Address offset: 0x0C */
    __IO uint32_t RSV1[252];              /*!<  RESERVED REGISTER,                                    Address offset: 0x10 */
    __IO uint32_t INEN;                   /*!<  VAOIOInputEnableRegister,                             Address offset: 0x400 */
    __IO uint32_t PUPDEN;                 /*!<  VAOIOPull-up Pull-down EnableRegister,                Address offset: 0x404 */
    __IO uint32_t ODEN;                   /*!<  VAOIOOpenDrainEnableRegister,                         Address offset: 0x408 */
    __IO uint32_t FCR;                    /*!<  VAOIOFunctionControlRegister,                         Address offset: 0x40C */
    __IO uint32_t DOR;                    /*!<  VAOIODataOutputRegister,                              Address offset: 0x410 */
    __I  uint32_t DIN;                    /*!<  VAOIODataInputRegister,                               Address offset: 0x414 */
    __IO uint32_t DSR;                    /*!<  VAO IO GPIO Driver Strength Register,                 Address offset: 0x418 */
} VAO_Type;

/* ================================================================================ */
/* ================                      CDIF                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t PRSC;                   /*!<  ,                                                     Address offset: 0x04 */
} CDIF_Type;

/* ================================================================================ */
/* ================                       RMU                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x00 */
    __IO uint32_t BORCR;                  /*!<  BORControlRegister,                                   Address offset: 0x04 */
    __IO uint32_t RSTCFG;                 /*!<  ResetConfigRegister,                                  Address offset: 0x08 */
    __O  uint32_t SOFTRST;                /*!<  SoftwareResetRegister,                                Address offset: 0x0C */
    __IO uint32_t RSTFLAG;                /*!<  ResetFlagRegister,                                    Address offset: 0x10 */
    __O  uint32_t PERHRSTEN;              /*!<  PeripheralResetEnableRegister,                        Address offset: 0x14 */
    __IO uint32_t AHBRST;                 /*!<  AHBPeripheralsResetRegister,                          Address offset: 0x18 */
    __IO uint32_t APBRST1;                /*!<  APBPeripheralsResetRegister1,                         Address offset: 0x1C */
    __IO uint32_t APBRST2;                /*!<  APBPeripheralsResetRegister2,                         Address offset: 0x20 */
} RMU_Type;

/* ================================================================================ */
/* ================                      IWDT                      ================ */
/* ================================================================================ */

typedef struct
{
    __O  uint32_t SERV;                   /*!<  IWDTServiceRegister,                                  Address offset: 0x00 */
    __IO uint32_t CR;                     /*!<  IWDTConfigRegister,                                   Address offset: 0x04 */
    __I  uint32_t CNT;                    /*!<  IWDTCounterRegister,                                  Address offset: 0x08 */
    __IO uint32_t WIN;                    /*!<  IWDTWindowRegister,                                   Address offset: 0x0C */
    __IO uint32_t IER;                    /*!<  IWDTInterruptEnableRegister,                          Address offset: 0x10 */
    __IO uint32_t ISR;                    /*!<  IWDTInterruptStatusRegister,                          Address offset: 0x14 */
} IWDT_Type;

/* ================================================================================ */
/* ================                      WWDT                      ================ */
/* ================================================================================ */

typedef struct
{
    __O  uint32_t CR;                     /*!<  WWDTControlRegister,                                  Address offset: 0x00 */
    __IO uint32_t CFGR;                   /*!<  WWDTConfigRegister,                                   Address offset: 0x04 */
    __I  uint32_t CNT;                    /*!<  WWDTCounterRegister,                                  Address offset: 0x08 */
    __IO uint32_t IER;                    /*!<  WWDTInterruptEnableRegister,                          Address offset: 0x0C */
    __IO uint32_t ISR;                    /*!<  WWDTInterruptStatusRegister,                          Address offset: 0x10 */
    __I  uint32_t PSC;                    /*!<  WWDTPrescalerRegister,                                Address offset: 0x14 */
} WWDT_Type;

/* ================================================================================ */
/* ================                       CMU                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t SYSCLKCR;               /*!<  SystemClockControlRegister,                           Address offset: 0x00 */
    __IO uint32_t RCHFCR;                 /*!<  RCHFControlRegister,                                  Address offset: 0x04 */
    __IO uint32_t RCHFTR;                 /*!<  RCHFTrimRegister,                                     Address offset: 0x08 */
    __IO uint32_t PLLCR;                  /*!<  PLLControlRegister,                                   Address offset: 0x0C */
    __IO uint32_t RCLPCR;                 /*!<  RCLPControlRegister,                                  Address offset: 0x10 */
    __IO uint32_t RCLPTR;                 /*!<  RCLPTrimRegister,                                     Address offset: 0x14 */
    __IO uint32_t RSV1[2];                /*!<  RESERVED REGISTER,                                    Address offset: 0x18 */
    __IO uint32_t XTHFCR;                  /*!<  XTHFControlRegister,                                  Address offset: 0x20 */
    __IO uint32_t RSV2[2];                /*!<  RESERVED REGISTER,                                    Address offset: 0x24 */
    __IO uint32_t IER;                    /*!<  InterruptEnableRegister,                              Address offset: 0x2C */
    __IO uint32_t ISR;                    /*!<  InterruptStatusRegister,                              Address offset: 0x30 */
    __IO uint32_t PCLKCR1;                /*!<  PeripheralbusClockControlRegister1,                   Address offset: 0x34 */
    __IO uint32_t PCLKCR2;                /*!<  PeripheralbusClockControlRegister2,                   Address offset: 0x38 */
    __IO uint32_t PCLKCR3;                /*!<  PeripheralbusClockControlRegister3,                   Address offset: 0x3C */
    __IO uint32_t PCLKCR4;                /*!<  PeripheralbusClockControlRegister4,                   Address offset: 0x40 */
    __IO uint32_t OPCCR1;                 /*!<  PeripheralClockConfigRegister1,                       Address offset: 0x44 */
    __IO uint32_t OPCCR2;                 /*!<  PeripheralClockConfigRegister2,                       Address offset: 0x48 */
    __IO uint32_t OPCER1;                 /*!<  PeripheralClockEnableRegister,                        Address offset: 0x4C */
    __IO uint32_t OPCER2;                 /*!<  PeripheralClockEnableRegister2,                       Address offset: 0x50 */
    __IO uint32_t RSV3;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x54 */
    __IO uint32_t CCCR;                   /*!<  ClockCalibrationControlRegister,                      Address offset: 0x58 */
    __IO uint32_t CCFR;                   /*!<  ClockCalibrationConfigRegister,                       Address offset: 0x5C */
    __I  uint32_t CCNR;                   /*!<  ClockCalibrationCounterRegister,                      Address offset: 0x60 */
    __IO uint32_t CCISR;                  /*!<  ClockCalibrationInterruptStatusRegister,              Address offset: 0x64 */
} CMU_Type;

/* ================================================================================ */
/* ================                       SVD                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CFGR;                   /*!<  SVDConfigRegister,                                    Address offset: 0x00 */
    __IO uint32_t CR;                     /*!<  SVDControlRegister,                                   Address offset: 0x04 */
    __IO uint32_t IER;                    /*!<  SVDInterruptEnableRegister,                           Address offset: 0x08 */
    __IO uint32_t ISR;                    /*!<  SVDInterruptStatusRegister,                           Address offset: 0x0C */
    __IO uint32_t VSR;                    /*!<  SVDreferenceVoltageSelectRegister,                    Address offset: 0x10 */
} SVD_Type;

/* ================================================================================ */
/* ================                       AES                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  AESControlRegister,                                   Address offset: 0x00 */
    __IO uint32_t IER;                    /*!<  AESInterruptEnableRegister,                           Address offset: 0x04 */
    __IO uint32_t ISR;                    /*!<  AESInterruptStatusRegister,                           Address offset: 0x08 */
    __IO uint32_t DIR;                    /*!<  AESDataInputRegister,                                 Address offset: 0x0C */
    __I  uint32_t DOR;                    /*!<  AESDataOutputRegister,                                Address offset: 0x10 */
    __IO uint32_t KEY0;                   /*!<  AESKeyRegister0,                                      Address offset: 0x14 */
    __IO uint32_t KEY1;                   /*!<  AESKeyRegister1,                                      Address offset: 0x18 */
    __IO uint32_t KEY2;                   /*!<  AESKeyRegister2,                                      Address offset: 0x1C */
    __IO uint32_t KEY3;                   /*!<  AESKeyRegister3,                                      Address offset: 0x20 */
    __IO uint32_t KEY4;                   /*!<  AESKeyRegister4,                                      Address offset: 0x24 */
    __IO uint32_t KEY5;                   /*!<  AESKeyRegister5,                                      Address offset: 0x28 */
    __IO uint32_t KEY6;                   /*!<  AESKeyRegister6,                                      Address offset: 0x2C */
    __IO uint32_t KEY7;                   /*!<  AESKeyRegister7,                                      Address offset: 0x30 */
    __IO uint32_t IVR0;                   /*!<  AESInitialVectorRegister0,                            Address offset: 0x34 */
    __IO uint32_t IVR1;                   /*!<  AESInitialVectorRegister1,                            Address offset: 0x38 */
    __IO uint32_t IVR2;                   /*!<  AESInitialVectorRegister2,                            Address offset: 0x3C */
    __IO uint32_t IVR3;                   /*!<  AESInitialVectorRegister3,                            Address offset: 0x40 */
    __IO uint32_t H0;                     /*!<  AESMultHparameterRegister0,                           Address offset: 0x44 */
    __IO uint32_t H1;                     /*!<  AESMultHparameterRegister1,                           Address offset: 0x48 */
    __IO uint32_t H2;                     /*!<  AESMultHparameterRegister2,                           Address offset: 0x4C */
    __IO uint32_t H3;                     /*!<  AESMultHparameterRegister3,                           Address offset: 0x50 */
} AES_Type;

/* ================================================================================ */
/* ================                       RNG                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  RandomNumberGeneratorControlRegister,                 Address offset: 0x00 */
    __I  uint32_t DOR;                    /*!<  RandomNumberGeneratorDataOutputRegister,              Address offset: 0x04 */
    __IO uint32_t RSV1[2];                /*!<  RESERVED REGISTER,                                    Address offset: 0x08 */
    __IO uint32_t SR;                     /*!<  RandomNumberGeneratorStatusRegister,                  Address offset: 0x10 */
    __IO uint32_t CRCCR;                 /*!<  CRCControlRegister,                                   Address offset: 0x14 */
    __IO uint32_t CRCDIR;                /*!<  CRCDatainputRegister,                                 Address offset: 0x18 */
    __IO uint32_t CRCSR;                 /*!<  CRCStatusRegister,                                    Address offset: 0x1C */
} RNG_Type;

/* ================================================================================ */
/* ================                      COMP                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!< ComparatorControl Register 1,                        Address offset: 0x00 */

} COMP_Type;

typedef struct
{
    __IO uint32_t ICR;                    /*!< Comparator Interrupt Config Register,                Address offset: 0x00 */
    __IO uint32_t ISR;                    /*!< Comparator Interrupt Status Register,                Address offset: 0x04 */
    __IO uint32_t RSV0;                   /*!< RESERVED REGISTER0,                                  Address offset: 0x08 */
    __IO uint32_t BUFCR;                  /*!< Comparator Interrupt Status Register,                Address offset: 0x0C */
} COMP_COMMON_Type;

/* ================================================================================ */
/* ================                     I2CSMBx                    ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR1;                    /*!<  I2CSMBusControlRegister,                              Address offset: 0x00 */
    __IO uint32_t CR2;                    /*!<  I2CSMBusControlRegister,                              Address offset: 0x04 */
    __IO uint32_t IER;                    /*!<  I2CSMBusIntteruptEnableRegister,                      Address offset: 0x08 */
    __IO uint32_t ISR;                    /*!<  I2CMasterInterruptStatusRegister,                     Address offset: 0x0C */
    __IO uint32_t BGR;                    /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t TCR;                    /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t TOR;                    /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t RXBUF;                  /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t TXBUF;                  /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t SADR;                   /*!<  ,                                                     Address offset: 0x24 */
    __I  uint32_t CRCDR;                  /*!<  ,                                                     Address offset: 0x28 */
    __IO uint32_t CRCLFSR;                /*!<  ,                                                     Address offset: 0x2C */
    __IO uint32_t CRCPOLY;                /*!<  ,                                                     Address offset: 0x30 */
} I2CSMB_Type;

/* ================================================================================ */
/* ================                      I2Cx                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t MSPCFGR;                /*!<  I2CMasterConfigRegister,                              Address offset: 0x00 */
    __IO uint32_t MSPCR;                  /*!<  I2CMasterControlRegister,                             Address offset: 0x04 */
    __IO uint32_t MSPIER;                 /*!<  I2CMasterIntteruptEnableRegister,                     Address offset: 0x08 */
    __IO uint32_t MSPISR;                 /*!<  I2CMasterInterruptStatusRegister,                     Address offset: 0x0C */
    __IO uint32_t MSPSR;                  /*!<  I2CMasterStatusRegister,                              Address offset: 0x10 */
    __IO uint32_t MSPBGR;                 /*!<  I2CMasterBaudrateGeneratorRegister,                   Address offset: 0x14 */
    __IO uint32_t MSPBUF;                 /*!<  I2CMastertransferBuffer,                              Address offset: 0x18 */
    __IO uint32_t MSPTCR;                 /*!<  I2CMasterTimingControlRegister,                       Address offset: 0x1C */
    __IO uint32_t MSPTOR;                 /*!<  I2CMasterTime-OutRegister,                            Address offset: 0x20 */
} I2C_Type;

/* ================================================================================ */
/* ================                      UART                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t IRCR;                   /*!<  InfraredmodulationControlRegister,                    Address offset: 0x00 */
} UART_COMMON_Type;

/* ================================================================================ */
/* ================                      UARTx                     ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CSR;                    /*!<  UARTxControlStatusRegister,                           Address offset: 0x00 */
    __IO uint32_t IER;                    /*!<  UARTxInterruptEnableRegister,                         Address offset: 0x04 */
    __IO uint32_t ISR;                    /*!<  UARTxInterruptStatusRegister,                         Address offset: 0x08 */
    __IO uint32_t TODR;                   /*!<  UARTxTime-OutandDelayRegister,                        Address offset: 0x0C */
    __I  uint32_t RXBUF;                  /*!<  UARTxReceiveBuffer,                                   Address offset: 0x10 */
    __O  uint32_t TXBUF;                  /*!<  UARTxTransmitBuffer,                                  Address offset: 0x14 */
    __IO uint32_t BGR;                    /*!<  UARTxBaudrateGeneratorRegister,                       Address offset: 0x18 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
    __IO uint32_t MCR;                    /*!<  UARTxModeControlRegister,                             Address offset: 0x20 */
    __IO uint32_t LINCR;                  /*!<  UARTxLINControlRegister,                              Address offset: 0x24 */
    __I  uint32_t LINBSR;                 /*!<  UARTxLINBaudSyncRegister,                             Address offset: 0x28 */
    __IO uint32_t LINFTR;                 /*!<  UARTxLINFrameTimeoutRegister,                         Address offset: 0x2C */
    __IO uint32_t LINTTR;                 /*!<  UARTxLINTransmitTimingRegister,                       Address offset: 0x30 */
    __I  uint32_t LINPSR;                 /*!<  UARTLINPre-syncbaudregister,                          Address offset: 0x34 */
    __IO uint32_t LINBKR;                 /*!<  ,                                                     Address offset: 0x38 */
    __IO uint32_t RSV2;                       /*!<  RESERVED REGISTER,                                    Address offset: 0x3C */
    __IO uint32_t SCISR;                  /*!<  UARTxSmartCardInterruptStatusRegister,                Address offset: 0x40 */
    __IO uint32_t SCIER;                  /*!<  UARTxSmartCardInterruptEnableRegister,                Address offset: 0x44 */
    __IO uint32_t FFCR;                   /*!<  UARTxSmartCardFrameFormatControlRegister,             Address offset: 0x48 */
    __IO uint32_t EGTR;                   /*!<  UARTxSmartCardExtraGuardTimeRegister,                 Address offset: 0x4C */
    __IO uint32_t CODR;                   /*!<  UARTxSmartCardClockOutputRegister,                    Address offset: 0x50 */
    __IO uint32_t RSV3[11];               /*!<  RESERVED REGISTER,                                    Address offset: 0x54 */
    __IO uint32_t LINSCCR;                /*!<  LINSelf-testCwitchControlRegister,                    Address offset: 0x80 */
} UART_Type;

/* ================================================================================ */
/* ================                     LPUARTx                    ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CSR;                    /*!<  LPUARTxControlStatusRegister,                         Address offset: 0x00 */
    __IO uint32_t IER;                    /*!<  LPUARTxInterruptEnableRegister,                       Address offset: 0x04 */
    __IO uint32_t ISR;                    /*!<  LPUARTxInterruptStatusRegister,                       Address offset: 0x08 */
    __IO uint32_t BMR;                    /*!<  LPUARTxBaudrateModulationRegister,                    Address offset: 0x0C */
    __I  uint32_t RXBUF;                  /*!<  LPUARTxReceiveBufferRegister,                         Address offset: 0x10 */
    __IO uint32_t TXBUF;                  /*!<  LPUARTxTransmitBufferRegister,                        Address offset: 0x14 */
    __IO uint32_t DMR;                    /*!<  LPUARTxdataMatchingRegister,                          Address offset: 0x18 */
} LPUART_Type;

/* ================================================================================ */
/* ================                      SPIx                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR1;                    /*!<  SPIxControlRegister1,                                 Address offset: 0x00 */
    __IO uint32_t CR2;                    /*!<  SPIxControlRegister2,                                 Address offset: 0x04 */
    __IO uint32_t CR3;                    /*!<  ControlRegister3,                                     Address offset: 0x08 */
    __IO uint32_t IER;                    /*!<  SPIxInterruptEnableRegister,                          Address offset: 0x0C */
    __IO uint32_t ISR;                    /*!<  SPIxStatusRegister,                                   Address offset: 0x10 */
    __O  uint32_t TXBUF;                  /*!<  SPIxTransmitBuffer,                                   Address offset: 0x14 */
    __I  uint32_t RXBUF;                  /*!<  SPIxReceiveBuffer,                                    Address offset: 0x18 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
    __IO uint32_t I2SCR;                  /*!<  I2SControlRegister,                                   Address offset: 0x20 */
    __IO uint32_t I2SPR;                  /*!<  SPIxI2SPrescalerRegister,                             Address offset: 0x24 */
} SPI_Type;

/* ================================================================================ */
/* ================                      EPSC                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t NCR1;                   /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t NTR1;                   /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t NWTR1;                  /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x0C */
    __IO uint32_t NCR2;                   /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t NTR2;                   /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t NWTR2;                  /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t RSV2;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
    __IO uint32_t NCR3;                   /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t NTR3;                   /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t NWTR3;                  /*!<  ,                                                     Address offset: 0x28 */
    __IO uint32_t RSV3;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x2C */
    __IO uint32_t NCR4;                   /*!<  ,                                                     Address offset: 0x30 */
    __IO uint32_t NTR4;                   /*!<  ,                                                     Address offset: 0x34 */
    __IO uint32_t NWTR4;                  /*!<  ,                                                     Address offset: 0x38 */
    __IO uint32_t RSV4[5];                /*!<  RESERVED REGISTER,                                    Address offset: 0x3C */
    __IO uint32_t ISR;                    /*!<  ,                                                     Address offset: 0x50 */
    __IO uint32_t IER;                    /*!<  ,                                                     Address offset: 0x54 */
    __IO uint32_t TOR;                     /*!<  ,                                                     Address offset: 0x58 */
} EPSC_Type;

/* ================================================================================ */
/* ================                       CAN                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  CANControlRegister,                                   Address offset: 0x00 */
    __IO uint32_t MSR;                    /*!<  CANmodeselectregister,                                Address offset: 0x04 */
    __IO uint32_t BRPR;                   /*!<  CANBaudratePrescalerRegister,                         Address offset: 0x08 */
    __IO uint32_t BTR;                    /*!<  CANBitTimingRegister,                                 Address offset: 0x0C */
    __IO  uint32_t ECR;                    /*!<  CANErrorCounterRegister,                              Address offset: 0x10 */
    __IO uint32_t ESR;                    /*!<  CANErrorStatusRegister,                               Address offset: 0x14 */
    __I  uint32_t SR;                     /*!<  CANStatusRegister,                                    Address offset: 0x18 */
    __IO  uint32_t RX_ISR;                 /*!<  CANInterruptStatusRegister,                           Address offset: 0x1C */
    __IO uint32_t RX_IER;                 /*!<  CANInterruptEnableRegister,                           Address offset: 0x20 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x24 */
    __IO uint32_t TXB_CR;                 /*!<  CANTransmitBufferControlRegister,                     Address offset: 0x28 */
    __IO uint32_t TXB_SR;                 /*!<  CANTransmitBufferStatusRegister,                      Address offset: 0x2C */
    __O  uint32_t TXB0_IDR;               /*!<  CANTransmitBuffer0IDRegister,                         Address offset: 0x30 */
    __O  uint32_t TXB0_DLCR;              /*!<  CANTransmitBuffer0DLCRegister,                        Address offset: 0x34 */
    __O  uint32_t TXB0_DW1R;              /*!<  CANTransmitBuffer0DataWord1Register,                  Address offset: 0x38 */
    __O  uint32_t TXB0_DW2R;              /*!<  CANTransmitBuffer0DataWord2Register,                  Address offset: 0x3C */
    __O  uint32_t TXB1_IDR;               /*!<  CANTransmitBuffer1IDRegister,                         Address offset: 0x40 */
    __O  uint32_t TXB1_DLCR;              /*!<  CANTransmitBuffer1DLCRegister,                        Address offset: 0x44 */
    __O  uint32_t TXB1_DW1R;              /*!<  CANTransmitBuffer1DataWord1Register,                  Address offset: 0x48 */
    __O  uint32_t TXB1_DW2R;              /*!<  CANTransmitBuffer1DataWord2Register,                  Address offset: 0x4C */
    __O  uint32_t TXB2_IDR;               /*!<  CANTransmitBuffer2IDRegister,                         Address offset: 0x50 */
    __O  uint32_t TXB2_DLCR;              /*!<  CANTransmitBuffer2DLCRegister,                        Address offset: 0x54 */
    __O  uint32_t TXB2_DW1R;              /*!<  CANTransmitBuffer2DataWord1Register,                  Address offset: 0x58 */
    __O  uint32_t TXB2_DW2R;              /*!<  CANTransmitBuffer2DataWord2Register,                  Address offset: 0x5C */
    __IO uint32_t AFCR;                   /*!<  AcceptanceFilterControlRegister,                      Address offset: 0x60 */
    __IO uint32_t AFCFGR;                 /*!<  AcceptanceFilterConfigRegister,                       Address offset: 0x64 */
    __IO uint32_t RSV2[6];                /*!<  RESERVED REGISTER,                                    Address offset: 0x68 */
    __IO uint32_t AFMR0;                  /*!<  AcceptanceFilterMaskRegister0,                        Address offset: 0x80 */
    __IO uint32_t AFIR0;                  /*!<  AcceptanceFilterIDRegister0,                          Address offset: 0x84 */
    __IO uint32_t AFMR1;                  /*!<  AcceptanceFilterMaskRegister1,                        Address offset: 0x88 */
    __IO uint32_t AFIR1;                  /*!<  AcceptanceFilterIDRegister1,                          Address offset: 0x8C */
    __IO uint32_t AFMR2;                  /*!<  ,                                                     Address offset: 0x90 */
    __IO uint32_t AFIR2;                  /*!<  ,                                                     Address offset: 0x94 */
    __IO uint32_t AFMR3;                  /*!<  ,                                                     Address offset: 0x98 */
    __IO uint32_t AFIR3;                  /*!<  ,                                                     Address offset: 0x9C */
    __IO uint32_t AFMR4;                  /*!<  ,                                                     Address offset: 0xA0 */
    __IO uint32_t AFIR4;                  /*!<  ,                                                     Address offset: 0xA4 */
    __IO uint32_t AFMR5;                  /*!<  ,                                                     Address offset: 0xA8 */
    __IO uint32_t AFIR5;                  /*!<  ,                                                     Address offset: 0xAC */
    __IO uint32_t AFMR6;                  /*!<  ,                                                     Address offset: 0xB0 */
    __IO uint32_t AFIR6;                  /*!<  ,                                                     Address offset: 0xB4 */
    __IO uint32_t AFMR7;                  /*!<  ,                                                     Address offset: 0xB8 */
    __IO uint32_t AFIR7;                  /*!<  ,                                                     Address offset: 0xBC */
    __IO uint32_t AFMR8;                  /*!<  ,                                                     Address offset: 0xC0 */
    __IO uint32_t AFIR8;                  /*!<  ,                                                     Address offset: 0xC4 */
    __IO uint32_t AFMR9;                  /*!<  ,                                                     Address offset: 0xC8 */
    __IO uint32_t AFIR9;                  /*!<  ,                                                     Address offset: 0xCC */
    __IO uint32_t AFMR10;                 /*!<  ,                                                     Address offset: 0xD0 */
    __IO uint32_t AFIR10;                 /*!<  ,                                                     Address offset: 0xD4 */
    __IO uint32_t AFMR11;                 /*!<  ,                                                     Address offset: 0xD8 */
    __IO uint32_t AFIR11;                 /*!<  ,                                                     Address offset: 0xDC */
    __IO uint32_t AFMR12;                 /*!<  ,                                                     Address offset: 0xE0 */
    __IO uint32_t AFIR12;                 /*!<  ,                                                     Address offset: 0xE4 */
    __IO uint32_t AFMR13;                 /*!<  ,                                                     Address offset: 0xE8 */
    __IO uint32_t AFIR13;                 /*!<  ,                                                     Address offset: 0xEC */
    __IO uint32_t AFMR14;                 /*!<  ,                                                     Address offset: 0xF0 */
    __IO uint32_t AFIR14;                 /*!<  ,                                                     Address offset: 0xF4 */
    __IO uint32_t AFMR15;                 /*!<  AcceptanceFilterMaskRegister15,                       Address offset: 0xF8 */
    __IO uint32_t AFIR15;                 /*!<  AcceptanceFilterIDRegister15,                         Address offset: 0xFC */
    __O  uint32_t RXF_IDR;                /*!<  CANRXFIFOIDRegister,                                  Address offset: 0x100 */
    __O  uint32_t RXF_DLCR;               /*!<  CANRXFIFODLCRegister,                                 Address offset: 0x104 */
    __O  uint32_t RXF_DW1R;               /*!<  CANRXFIFODataWord1Register,                           Address offset: 0x108 */
    __O  uint32_t RXF_DW2R;               /*!<  CANRXFIFODataWord2Register,                           Address offset: 0x10C */
} CAN_Type;

/* ================================================================================ */
/* ================                      FDCAN                     ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  FDCANControlRegister,                                 Address offset: 0x00 */
    __IO uint32_t MSR;                    /*!<  FDCANmodeselectregister,                              Address offset: 0x04 */
    __IO uint32_t NBTR;                   /*!<  FDCANNominalBitTimingRegister,                        Address offset: 0x08 */
    __IO uint32_t DBTR;                   /*!<  FDCANDataBitTimingRegister,                           Address offset: 0x0C */
    __IO uint32_t TDCR;                   /*!<  FDCANTransmissionDelayCompensationRegister,           Address offset: 0x10 */
    __IO uint32_t TSCR;                   /*!<  FDCANTimeStampConfigRegister,                         Address offset: 0x14 */
    __IO uint32_t TSVR;                   /*!<  FDCANTimeStampValueRegister,                          Address offset: 0x18 */
    __IO uint32_t TOCR;                   /*!<  FDCANTimeOutConfigRegister,                           Address offset: 0x1C */
    __IO uint32_t TOVR;                   /*!<  FDCANTimeOutValueRegister,                            Address offset: 0x20 */
    __I  uint32_t ECR;                    /*!<  FDCANErrorCounterRegister,                            Address offset: 0x24 */
    __IO uint32_t ESR;                    /*!<  FDCANErrorStatusRegister,                             Address offset: 0x28 */
    __IO uint32_t SR;                     /*!<  StatusRegister,                                       Address offset: 0x2C */
    __I  uint32_t RXISR;                  /*!<  FDCANInterruptStatusRegister,                         Address offset: 0x30 */
    __IO uint32_t RXIER;                  /*!<  FDCANInterruptEnableRegister,                         Address offset: 0x34 */
    __IO uint32_t TXCR;                   /*!<  TransmitConfigRegister,                               Address offset: 0x38 */
    __IO uint32_t TXSR;                   /*!<  TransmitStatusRegister,                               Address offset: 0x3C */
    __I  uint32_t TXFSR;                  /*!<  ,                                                     Address offset: 0x40 */
    __I  uint32_t RXFSR;                  /*!<  ,                                                     Address offset: 0x44 */
    __O  uint32_t TXB0_IDR;               /*!<  FDCANTransmitBuffer0IDRegister,                       Address offset: 0x48 */
    __O  uint32_t TXB0_DLCR;              /*!<  FDCANTransmitBuffer0DLCRegister,                      Address offset: 0x4C */
    __O  uint32_t TXB0_DW0R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x50 */
    __O  uint32_t TXB0_DW1R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x54 */
    __O  uint32_t TXB0_DW2R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x58 */
    __O  uint32_t TXB0_DW3R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x5C */
    __O  uint32_t TXB0_DW4R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x60 */
    __O  uint32_t TXB0_DW5R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x64 */
    __O  uint32_t TXB0_DW6R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x68 */
    __O  uint32_t TXB0_DW7R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x6C */
    __O  uint32_t TXB0_DW8R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x70 */
    __O  uint32_t TXB0_DW9R;              /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x74 */
    __O  uint32_t TXB0_DW10R;             /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x78 */
    __O  uint32_t TXB0_DW11R;             /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x7C */
    __O  uint32_t TXB0_DW12R;             /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x80 */
    __O  uint32_t TXB0_DW13R;             /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x84 */
    __O  uint32_t TXB0_DW14R;             /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x88 */
    __O  uint32_t TXB0_DW15R;             /*!<  FDCANTransmitBuffer0DataWordRegistery                 Address offset: 0x8C */
    __O  uint32_t TXB1_IDR;               /*!<  FDCANTransmitBuffer1IDRegister,                       Address offset: 0x90 */
    __O  uint32_t TXB1_DLCR;              /*!<  FDCANTransmitBuffer1DLCRegister,                      Address offset: 0x94 */
    __O  uint32_t TXB1_DW0R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0x98 */
    __O  uint32_t TXB1_DW1R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0x9C */
    __O  uint32_t TXB1_DW2R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xA0 */
    __O  uint32_t TXB1_DW3R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xA4 */
    __O  uint32_t TXB1_DW4R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xA8 */
    __O  uint32_t TXB1_DW5R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xAC */
    __O  uint32_t TXB1_DW6R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xB0 */
    __O  uint32_t TXB1_DW7R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xB4 */
    __O  uint32_t TXB1_DW8R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xB8 */
    __O  uint32_t TXB1_DW9R;              /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xBC */
    __O  uint32_t TXB1_DW10R;             /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xC0 */
    __O  uint32_t TXB1_DW11R;             /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xC4 */
    __O  uint32_t TXB1_DW12R;             /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xC8 */
    __O  uint32_t TXB1_DW13R;             /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xCC */
    __O  uint32_t TXB1_DW14R;             /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xD0 */
    __O  uint32_t TXB1_DW15R;             /*!<  FDCANTransmitBuffer1DataWordRegistery                 Address offset: 0xD4 */
    __O  uint32_t TXB2_IDR;               /*!<  FDCANTransmitBuffer2IDRegister,                       Address offset: 0xD8 */
    __O  uint32_t TXB2_DLCR;              /*!<  FDCANTransmitBuffer2DLCRegister,                      Address offset: 0xDC */
    __O  uint32_t TXB2_DW0R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xE0 */
    __O  uint32_t TXB2_DW1R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xE4 */
    __O  uint32_t TXB2_DW2R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xE8 */
    __O  uint32_t TXB2_DW3R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xEC */
    __O  uint32_t TXB2_DW4R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xF0 */
    __O  uint32_t TXB2_DW5R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xF4 */
    __O  uint32_t TXB2_DW6R;              /*!<  FDCANTransmitBuffer2DataWordRegistery                 Address offset: 0xF8 */
    __O  uint32_t TXB2_DW7R;              /*!<  FDCANTransmitBuffer2DataWordRegistery Address offset: 0xFC */
    __O  uint32_t TXB2_DW8R;              /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x100 */
    __O  uint32_t TXB2_DW9R;              /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x104 */
    __O  uint32_t TXB2_DW10R;             /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x108 */
    __O  uint32_t TXB2_DW11R;             /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x10C */
    __O  uint32_t TXB2_DW12R;             /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x110 */
    __O  uint32_t TXB2_DW13R;             /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x114 */
    __O  uint32_t TXB2_DW14R;             /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x118 */
    __O  uint32_t TXB2_DW15R;             /*!<  FDCANTransmitBuffer2DataWordRegistery)
y=0~15,        Address offset: 0x11C */
    __O  uint32_t RXF_IDR;                /*!<  FDCANReceiveFIFOIDRegister,                           Address offset: 0x120 */
    __O  uint32_t RXF_DLCR;               /*!<  FDCANReceiveFIFODLCRegister,                          Address offset: 0x124 */
    __O  uint32_t RXF_DW0R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x128 */
    __O  uint32_t RXF_DW1R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x12C */
    __O  uint32_t RXF_DW2R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x130 */
    __O  uint32_t RXF_DW3R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x134 */
    __O  uint32_t RXF_DW4R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x138 */
    __O  uint32_t RXF_DW5R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x13C */
    __O  uint32_t RXF_DW6R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x140 */
    __O  uint32_t RXF_DW7R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x144 */
    __O  uint32_t RXF_DW8R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x148 */
    __O  uint32_t RXF_DW9R;               /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x14C */
    __O  uint32_t RXF_DW10R;              /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x150 */
    __O  uint32_t RXF_DW11R;              /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x154 */
    __O  uint32_t RXF_DW12R;              /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x158 */
    __O  uint32_t RXF_DW13R;              /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x15C */
    __O  uint32_t RXF_DW14R;              /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x160 */
    __O  uint32_t RXF_DW15R;              /*!<  FDCANReceiveFIFODataWordRegistery)
y=0~15,            Address offset: 0x164 */
    __IO uint32_t AFCR;                   /*!<  FDCANAcceptanceFilterControlRegister,                 Address offset: 0x168 */
    __IO uint32_t AFBIR0;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x16C */
    __IO uint32_t AFBIR1;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x170 */
    __IO uint32_t AFBIR2;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x174 */
    __IO uint32_t AFBIR3;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x178 */
    __IO uint32_t AFBIR4;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x17C */
    __IO uint32_t AFBIR5;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x180 */
    __IO uint32_t AFBIR6;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x184 */
    __IO uint32_t AFBIR7;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x188 */
    __IO uint32_t AFBIR8;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x18C */
    __IO uint32_t AFBIR9;                 /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x190 */
    __IO uint32_t AFBIR10;                /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x194 */
    __IO uint32_t AFBIR11;                /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x198 */
    __IO uint32_t AFBIR12;                /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x19C */
    __IO uint32_t AFBIR13;                /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x1A0 */
    __IO uint32_t AFBIR14;                /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x1A4 */
    __IO uint32_t AFBIR15;                /*!<  FDCANAcceptanceFilterBasicIDRegister,                 Address offset: 0x1A8 */
    __IO uint32_t AFEIR0F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1AC */
    __IO uint32_t AFEIR0F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1B0 */
    __IO uint32_t AFEIR1F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1B4 */
    __IO uint32_t AFEIR1F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1B8 */
    __IO uint32_t AFEIR2F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1BC */
    __IO uint32_t AFEIR2F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1C0 */
    __IO uint32_t AFEIR3F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1C4 */
    __IO uint32_t AFEIR3F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1C8 */
    __IO uint32_t AFEIR4F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1CC */
    __IO uint32_t AFEIR4F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1D0 */
    __IO uint32_t AFEIR5F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1D4 */
    __IO uint32_t AFEIR5F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1D8 */
    __IO uint32_t AFEIR6F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1DC */
    __IO uint32_t AFEIR6F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1E0 */
    __IO uint32_t AFEIR7F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1E4 */
    __IO uint32_t AFEIR7F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1E8 */
    __IO uint32_t AFEIR8F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1EC */
    __IO uint32_t AFEIR8F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1F0 */
    __IO uint32_t AFEIR9F0;               /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1F4 */
    __IO uint32_t AFEIR9F1;               /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x1F8 */
    __IO uint32_t AFEIR10F0;              /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x1FC */
    __IO uint32_t AFEIR10F1;              /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x200 */
    __IO uint32_t AFEIR11F0;              /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x204 */
    __IO uint32_t AFEIR11F1;              /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x208 */
    __IO uint32_t AFEIR12F0;              /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x20C */
    __IO uint32_t AFEIR12F1;              /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x210 */
    __IO uint32_t AFEIR13F0;              /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x214 */
    __IO uint32_t AFEIR13F1;              /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x218 */
    __IO uint32_t AFEIR14F0;              /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x21C */
    __IO uint32_t AFEIR14F1;              /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x220 */
    __IO uint32_t AFEIR15F0;              /*!<  FDCANAcceptanceFilterExtendedIDF0Register,            Address offset: 0x224 */
    __IO uint32_t AFEIR15F1;              /*!<  AcceptanceFilterExtendedIDF1Register,                 Address offset: 0x228 */
} FDCAN_Type;

/* ================================================================================ */
/* ================                       DMA                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CH0CR;                  /*!<  Channel0ControlRegister,                              Address offset: 0x00 */
    __IO uint32_t CH0CFGR;                /*!<  Channel0ConfigRegister,                               Address offset: 0x04 */
    __IO uint32_t CH0PAR;                 /*!<  Channel0PeripheralAddressRegister,                    Address offset: 0x08 */
    __IO uint32_t CH0MAR0;                /*!<  Channel0MemoryAddressRegister0,                       Address offset: 0x0C */
    __IO uint32_t CH0MAR1;                /*!<  Channel0MemoryAddressRegister1,                       Address offset: 0x10 */
    __IO uint32_t RSV1[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x14 */
    __IO uint32_t CH1CR;                  /*!<  Channel1ControlRegister,                              Address offset: 0x20 */
    __IO uint32_t CH1CFGR;                /*!<  Channel1ConfigRegister,                               Address offset: 0x24 */
    __IO uint32_t CH1PAR;                 /*!<  Channel1PeripheralAddressRegister,                    Address offset: 0x28 */
    __IO uint32_t CH1MAR0;                /*!<  Channel1MemoryAddressRegister0,                       Address offset: 0x2C */
    __IO uint32_t CH1MAR1;                /*!<  Channel1MemoryAddressRegister1,                       Address offset: 0x30 */
    __IO uint32_t RSV2[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x34 */
    __IO uint32_t CH2CR;                  /*!<  Channel2ControlRegister,                              Address offset: 0x40 */
    __IO uint32_t CH2CFGR;                /*!<  Channel2ConfigRegister,                               Address offset: 0x44 */
    __IO uint32_t CH2PAR;                 /*!<  Channel2PeripheralAddressRegister,                    Address offset: 0x48 */
    __IO uint32_t CH2MAR0;                /*!<  Channel2MemoryAddressRegister0,                       Address offset: 0x4C */
    __IO uint32_t CH2MAR1;                /*!<  Channel2MemoryAddressRegister1,                       Address offset: 0x50 */
    __IO uint32_t RSV3[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x54 */
    __IO uint32_t CH3CR;                  /*!<  Channel3ControlRegister,                              Address offset: 0x60 */
    __IO uint32_t CH3CFGR;                /*!<  Channel3ConfigRegister,                               Address offset: 0x64 */
    __IO uint32_t CH3PAR;                 /*!<  Channel3PeripheralAddressRegister,                    Address offset: 0x68 */
    __IO uint32_t CH3MAR0;                /*!<  Channel3MemoryAddressRegister0,                       Address offset: 0x6C */
    __IO uint32_t CH3MAR1;                /*!<  Channel3MemoryAddressRegister1,                       Address offset: 0x70 */
    __IO uint32_t RSV4[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x74 */
    __IO uint32_t CH4CR;                  /*!<  Channel4ControlRegister,                              Address offset: 0x80 */
    __IO uint32_t CH4CFGR;                /*!<  Channel4ConfigRegister,                               Address offset: 0x84 */
    __IO uint32_t CH4PAR;                 /*!<  Channel4PeripheralAddressRegister,                    Address offset: 0x88 */
    __IO uint32_t CH4MAR0;                /*!<  Channel4MemoryAddressRegister0,                       Address offset: 0x8C */
    __IO uint32_t CH4MAR1;                /*!<  Channel4MemoryAddressRegister1,                       Address offset: 0x90 */
    __IO uint32_t RSV5[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x94 */
    __IO uint32_t CH5CR;                  /*!<  Channel5ControlRegister,                              Address offset: 0xA0 */
    __IO uint32_t CH5CFGR;                /*!<  Channel5ConfigRegister,                               Address offset: 0xA4 */
    __IO uint32_t CH5PAR;                 /*!<  Channel5PeripheralAddressRegister,                    Address offset: 0xA8 */
    __IO uint32_t CH5MAR0;                /*!<  Channel5MemoryAddressRegister0,                       Address offset: 0xAC */
    __IO uint32_t CH5MAR1;                /*!<  Channel5MemoryAddressRegister1,                       Address offset: 0xB0 */
    __IO uint32_t RSV6[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0xB4 */
    __IO uint32_t CH6CR;                  /*!<  Channel6ControlRegister,                              Address offset: 0xC0 */
    __IO uint32_t CH6CFGR;                /*!<  Channel6ConfigRegister,                               Address offset: 0xC4 */
    __IO uint32_t CH6PAR;                 /*!<  Channel6PeripheralAddressRegister,                    Address offset: 0xC8 */
    __IO uint32_t CH6MAR0;                /*!<  Channel6MemoryAddressRegister0,                       Address offset: 0xCC */
    __IO uint32_t CH6MAR1;                /*!<  Channel6MemoryAddressRegister1,                       Address offset: 0xD0 */
    __IO uint32_t RSV7[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0xD4 */
    __IO uint32_t CH7CR;                  /*!<  Channel7ControlRegister,                              Address offset: 0xE0 */
    __IO uint32_t CH7FAR;                 /*!<  Channel7FlashAddressRegister,                         Address offset: 0xE4 */
    __IO uint32_t CH7RAR;                 /*!<  Channel7RAMAddressRegister,                           Address offset: 0xE8 */
    __IO uint32_t RSV8[69];               /*!<  RESERVED REGISTER,                                    Address offset: 0xEC */
    __IO uint32_t GCR;                    /*!<  DMAGlobalControlRegister,                             Address offset: 0x200 */
    __IO uint32_t SWRR;                   /*!<  DMASoftwareRequestRegister,                           Address offset: 0x204 */
    __IO uint32_t RSV9[62];               /*!<  RESERVED REGISTER,                                    Address offset: 0x208 */
    __IO uint32_t ISR;                    /*!<  DMAInterruptStatusRegister,                           Address offset: 0x300 */
    __I  uint32_t CH0TFSADDR;             /*!<  ,                                                     Address offset: 0x304 */
    __I  uint32_t CH1TFSADDR;             /*!<  ,                                                     Address offset: 0x308 */
    __I  uint32_t CH2TFSADDR;             /*!<  ,                                                     Address offset: 0x30C */
    __I  uint32_t CH3TFSADDR;             /*!<  ,                                                     Address offset: 0x310 */
    __I  uint32_t CH4TFSADDR;             /*!<  ,                                                     Address offset: 0x314 */
    __I  uint32_t CH5TFSADDR;             /*!<  ,                                                     Address offset: 0x318 */
    __I  uint32_t CH6TFSADDR;             /*!<  ,                                                     Address offset: 0x31C */
} DMA_Type;

/* ================================================================================ */
/* ================                       CRC                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t DR;                     /*!<  CRCDataRegister,                                      Address offset: 0x00 */
    __IO uint32_t CR;                     /*!<  CRCControlRegister,                                   Address offset: 0x04 */
    __IO uint32_t LFSR;                   /*!<  CRCLinearFeedbackShiftRegister,                       Address offset: 0x08 */
    __IO uint32_t XOR;                    /*!<  CRCoutputXORRegister,                                 Address offset: 0x0C */
    __IO uint32_t RSV1[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x10 */
    __IO uint32_t POLY;                   /*!<  CRCPolynominalRegister,                               Address offset: 0x1C */
} CRC_Type;

/* ================================================================================ */
/* ================                      ATIMx                     ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR1;                    /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t CR2;                    /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t SMCR;                   /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t DIER;                   /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t ISR;                    /*!<  ,                                                     Address offset: 0x10 */
    __O  uint32_t EGR;                    /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t CCMR1;                  /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t CCMR2;                  /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t CCER;                   /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t CNT;                    /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t PSC;                    /*!<  ,                                                     Address offset: 0x28 */
    __IO uint32_t ARR;                    /*!<  ,                                                     Address offset: 0x2C */
    __IO uint32_t RCR;                    /*!<  ,                                                     Address offset: 0x30 */
    __IO uint32_t CCR1;                   /*!<  ,                                                     Address offset: 0x34 */
    __IO uint32_t CCR2;                   /*!<  ,                                                     Address offset: 0x38 */
    __IO uint32_t CCR3;                   /*!<  ,                                                     Address offset: 0x3C */
    __IO uint32_t CCR4;                   /*!<  ,                                                     Address offset: 0x40 */
    __IO uint32_t BDTR;                   /*!<  ,                                                     Address offset: 0x44 */
    __IO uint32_t CCMR3;                  /*!<  ,                                                     Address offset: 0x48 */
    __IO uint32_t CCR5;                   /*!<  ,                                                     Address offset: 0x4C */
    __IO uint32_t CCR6;                   /*!<  ,                                                     Address offset: 0x50 */
    __IO uint32_t ECR;                    /*!<  ,                                                     Address offset: 0x54 */
    __IO uint32_t TISEL;                  /*!<  ,                                                     Address offset: 0x58 */
    __IO uint32_t AFR;                    /*!<  ,                                                     Address offset: 0x5C */
    __IO uint32_t BRKFLAG;                /*!<  ,                                                     Address offset: 0x60 */
    __IO uint32_t RSV1[37];               /*!<  RESERVED REGISTER,                                    Address offset: 0x64 */
    __IO uint32_t DCR;                    /*!<  ,                                                     Address offset: 0xF8 */
    __IO uint32_t DMAR;                   /*!<  ,                                                     Address offset: 0xFC */
} ATIM_Type;

/* ================================================================================ */
/* ================               GPTIMx                           ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR1;                    /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t CR2;                    /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t SMCR;                   /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t DIER;                   /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t ISR;                    /*!<  ,                                                     Address offset: 0x10 */
    __O  uint32_t EGR;                    /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t CCMR1;                    /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t CCMR2;                      /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t CCER;                   /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t CNT;                    /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t PSC;                    /*!<  ,                                                     Address offset: 0x28 */
    __IO uint32_t ARR;                    /*!<  ,                                                     Address offset: 0x2C */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x30 */
    __IO uint32_t CCR1;                   /*!<  ,                                                     Address offset: 0x34 */
    __IO uint32_t CCR2;                   /*!<  ,                                                     Address offset: 0x38 */
    __IO uint32_t CCR3;                   /*!<  ,                                                     Address offset: 0x3C */
    __IO uint32_t CCR4;                   /*!<  ,                                                     Address offset: 0x40 */
    __IO uint32_t RSV2[4];                /*!<  RESERVED REGISTER,                                    Address offset: 0x44 */
    __IO uint32_t ECR;                    /*!<  ,                                                     Address offset: 0x54 */
    __IO uint32_t TISEL;                  /*!<  ,                                                     Address offset: 0x58 */
    __IO uint32_t AFR;                    /*!<  ,                                                     Address offset: 0x5C */
    __IO uint32_t RSV3[38];               /*!<  RESERVED REGISTER,                                    Address offset: 0x60 */
    __IO uint32_t DCR;                    /*!<  ,                                                     Address offset: 0xF8 */
    __IO uint32_t DMAR;                   /*!<  ,                                                     Address offset: 0xFC */
} GPTIM_Type;

/* ================================================================================ */
/* ================                     BSTIM16                    ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR1;                    /*!<  BSTIM16ControlRegister1,                              Address offset: 0x00 */
    __IO uint32_t CR2;                    /*!<  BSTIM16ControlRegister2,                              Address offset: 0x04 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x08 */
    __IO uint32_t IER;                    /*!<  BSTIM16InterruptEnableRegister,                       Address offset: 0x0C */
    __IO uint32_t ISR;                    /*!<  BSTIM16InterruptStatusRegister,                       Address offset: 0x10 */
    __O  uint32_t EGR;                    /*!<  BSTIM16EventGenerationRegister,                       Address offset: 0x14 */
    __IO uint32_t RSV2[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x18 */
    __IO uint32_t CNT;                    /*!<  BSTIM16CounterRegister,                               Address offset: 0x24 */
    __IO uint32_t PSC;                    /*!<  BSTIM16PrescalerRegister,                             Address offset: 0x28 */
    __IO uint32_t ARR;                    /*!<  BSTIM16Auto-ReloadRegister,                           Address offset: 0x2C */
} BSTIM16_Type;

/* ================================================================================ */
/* ================                     LPTIM16                    ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CFGR;                   /*!<  LPTIM16ConfigRegister,                                Address offset: 0x00 */
    __I  uint32_t CNT;                    /*!<  LPTIM16CounterRegister,                               Address offset: 0x04 */
    __IO uint32_t CCSR;                   /*!<  LPTIM16Capture/CompareControlandStatusRegister,       Address offset: 0x08 */
    __IO uint32_t ARR;                    /*!<  LPTIM16Auto-ReloadRegister,                           Address offset: 0x0C */
    __IO uint32_t IER;                    /*!<  LPTIM16InterruptEnableRegister,                       Address offset: 0x10 */
    __IO uint32_t ISR;                    /*!<  LPTIM16InterruptStatusRegister,                       Address offset: 0x14 */
    __IO uint32_t CR;                     /*!<  LPTIM16ControlRegister,                               Address offset: 0x18 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
    __IO uint32_t CCR1;                   /*!<  LPTIM16Capture/CompareRegister1,                      Address offset: 0x20 */
    __IO uint32_t CCR2;                   /*!<  LPTIM16Capture/CompareRegister2,                      Address offset: 0x24 */
} LPTIM16_Type;

/* ================================================================================ */
/* ================                      EPWMx                     ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t PRD;                    /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t PHSR;                   /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t PSC;                    /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t CNTR;                   /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t TBCR;                   /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t TBSR;                   /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t SYNC;                   /*!<  ,                                                     Address offset: 0x18 */
    __O  uint32_t SWACT;                  /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t CMPA;                   /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t CMPB;                   /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t CMPC;                   /*!<  ,                                                     Address offset: 0x28 */
    __IO uint32_t CMPD;                   /*!<  ,                                                     Address offset: 0x2C */
    __IO uint32_t CCR;                    /*!<  ,                                                     Address offset: 0x30 */
    __IO uint32_t OACR;                   /*!<  ,                                                     Address offset: 0x34 */
    __IO uint32_t OBCR;                   /*!<  ,                                                     Address offset: 0x38 */
    __IO uint32_t SFCR;                   /*!<  ,                                                     Address offset: 0x3C */
    __IO uint32_t SFR;                    /*!<  ,                                                     Address offset: 0x40 */
    __IO uint32_t DTCR;                   /*!<  ,                                                     Address offset: 0x44 */
    __IO uint32_t DTDLY;                  /*!<  ,                                                     Address offset: 0x48 */
    __IO uint32_t CPCR;                   /*!<  ,                                                     Address offset: 0x4C */
    __IO uint32_t BKCFR;                  /*!<  ,                                                     Address offset: 0x50 */
    __IO uint32_t BKCR;                   /*!<  ,                                                     Address offset: 0x54 */
    __IO uint32_t BKIER;                  /*!<  ,                                                     Address offset: 0x58 */
    __IO uint32_t BKISR;                  /*!<  ,                                                     Address offset: 0x5C */
    __O  uint32_t BKCLR;                  /*!<  ,                                                     Address offset: 0x60 */
    __IO  uint32_t BKSFR;                  /*!<  ,                                                     Address offset: 0x64 */
    __IO uint32_t DCINSR;                 /*!<  ,                                                     Address offset: 0x68 */
    __IO uint32_t DCCR;                   /*!<  ,                                                     Address offset: 0x6C */
    __IO uint32_t DCFCR;                  /*!<  ,                                                     Address offset: 0x70 */
    __IO uint32_t DCFWR;                  /*!<  ,                                                     Address offset: 0x74 */
    __I  uint32_t DCFDR;                  /*!<  ,                                                     Address offset: 0x78 */
    __IO uint32_t EIER;                   /*!<  ,                                                     Address offset: 0x7C */
    __IO uint32_t EISR;                   /*!<  ,                                                     Address offset: 0x80 */
    __IO uint32_t EPSR;                   /*!<  ,                                                     Address offset: 0x84 */
    __O  uint32_t SWTR;                   /*!<  ,                                                     Address offset: 0x88 */
    __IO uint32_t HRCR;                   /*!<  ,                                                     Address offset: 0x8C */
    __IO uint32_t HRPRD;                  /*!<  ,                                                     Address offset: 0x90 */
    __IO uint32_t HRCMPA;                 /*!<  ,                                                     Address offset: 0x94 */
    __IO uint32_t HRCMPB;                 /*!<  ,                                                     Address offset: 0x98 */
    __IO uint32_t HRACR;                  /*!<  ,                                                     Address offset: 0x9C */
    __IO uint32_t RSV1[22];               /*!<  RESERVED REGISTER,                                    Address offset: 0xA0 */
    __IO uint32_t LINK;                   /*!<  ,                                                     Address offset: 0xF8 */
    __IO uint32_t CR;                     /*!<  ,                                                     Address offset: 0xFC */
} EPWM_Type;

/* ================================================================================ */
/* ================                      RTCB                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t WER;                    /*!<  RTCBWrite Enable Register,                            Address offset: 0x00 */
    __IO uint32_t IER;                    /*!<  RTCBInterrupt Enable Register,                        Address offset: 0x04 */
    __IO uint32_t ISR;                    /*!<  RTCBInterrupt Status Register,                        Address offset: 0x08 */
    __IO uint32_t BCDSEC;                 /*!<  BCD format time second registers,                     Address offset: 0x0C */
    __IO uint32_t BCDMIN;                 /*!<  BCD format time minute registers,                     Address offset: 0x10 */
    __IO uint32_t BCDHOUR;                /*!<  BCD format time hour registers,                       Address offset: 0x14 */
    __IO uint32_t BCDDAY;                 /*!<  BCD format time day registers,                        Address offset: 0x18 */
    __IO uint32_t BCDWEEK;                /*!<  BCD format time week registers,                       Address offset: 0x1C */
    __IO uint32_t BCDMONTH;               /*!<  BCD format time month registers,                      Address offset: 0x20 */
    __IO uint32_t BCDYEAR;                /*!<  BCD format time year registers,                       Address offset: 0x24 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x28 */
    __IO uint32_t TMSEL;                  /*!<  RTCB Time Mark Select,                                Address offset: 0x2C */
    __IO uint32_t ADJR;                   /*!<  RTCB time Adjust Register,                            Address offset: 0x30 */
    __IO uint32_t RSV2[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x34 */
    __IO uint32_t CR;                     /*!<  RTCB Control Register,                                Address offset: 0x40 */
    __IO uint32_t RSV3;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x44 */
    __IO uint32_t STPCR;                  /*!<  RTCB Time Stamp Control Register,                     Address offset: 0x48 */
    __IO uint32_t STPCLKRR;               /*!<  RTC Time Stamp Clock Record Register,                 Address offset: 0x4C */
    __IO uint32_t STPCALRR;               /*!<  RTCB Time Stamp Calendar Record Register,             Address offset: 0x50 */
    __IO uint32_t RSV4[7];                /*!<  RESERVED REGISTER,                                    Address offset: 0x54 */
    __IO uint32_t BKR0;                   /*!<  RTCBBackup Register0,                                 Address offset: 0x70 */
    __IO uint32_t BKR1;                   /*!<  RTCB Backup Register1,                                Address offset: 0x74 */
    __IO uint32_t BKR2;                   /*!<  RTCB Backup Register2,                                Address offset: 0x78 */
    __IO uint32_t BKR3;                   /*!<  RTCB Backup Register3,                                Address offset: 0x7C */
    __IO uint32_t BKR4;                   /*!<  RTCB Backup Register4,                                Address offset: 0x80 */
} RTCB_Type;

/* ================================================================================ */
/* ================                       ADC                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t ACQ_ISR;                /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t ACQ_IER;                /*!<  ,                                                     Address offset: 0x04 */
    __IO  uint32_t GISR;                   /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t GIER;                   /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t CR1;                    /*!<  ,                                                     Address offset: 0x10 */
    __O  uint32_t CR2;                    /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t CALR;                   /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t CFGR1;                  /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t CFGR2;                  /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t PRICR;                  /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t DMR;                    /*!<  ,                                                     Address offset: 0x28 */
    __IO uint32_t OSR;                    /*!<  ,                                                     Address offset: 0x2C */
    __I  uint32_t ACQ_SR;                 /*!<  ,                                                     Address offset: 0x30 */
    __IO uint32_t RSV1[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x34 */
    __IO uint32_t ACQ0_CR;                /*!<  ,                                                     Address offset: 0x40 */
    __IO uint32_t ACQ1_CR;                /*!<  ,                                                     Address offset: 0x44 */
    __IO uint32_t ACQ2_CR;                /*!<  ,                                                     Address offset: 0x48 */
    __IO uint32_t ACQ3_CR;                /*!<  ,                                                     Address offset: 0x4C */
    __IO uint32_t ACQ4_CR;                /*!<  ,                                                     Address offset: 0x50 */
    __IO uint32_t ACQ5_CR;                /*!<  ,                                                     Address offset: 0x54 */
    __IO uint32_t ACQ6_CR;                /*!<  ,                                                     Address offset: 0x58 */
    __IO uint32_t ACQ7_CR;                /*!<  ,                                                     Address offset: 0x5C */
    __IO uint32_t ACQ8_CR;                /*!<  ,                                                     Address offset: 0x60 */
    __IO uint32_t ACQ9_CR;                /*!<  ,                                                     Address offset: 0x64 */
    __IO uint32_t ACQ10_CR;               /*!<  ,                                                     Address offset: 0x68 */
    __IO uint32_t ACQ11_CR;               /*!<  ,                                                     Address offset: 0x6C */
    __IO uint32_t ACQ12_CR;               /*!<  ,                                                     Address offset: 0x70 */
    __IO uint32_t ACQ13_CR;               /*!<  ,                                                     Address offset: 0x74 */
    __IO uint32_t ACQ14_CR;               /*!<  ,                                                     Address offset: 0x78 */
    __IO uint32_t ACQ15_CR;               /*!<  ,                                                     Address offset: 0x7C */
    __I  uint32_t ACQ0_DR;                /*!<  ,                                                     Address offset: 0x80 */
    __I  uint32_t ACQ1_DR;                /*!<  ,                                                     Address offset: 0x84 */
    __I  uint32_t ACQ2_DR;                /*!<  ,                                                     Address offset: 0x88 */
    __I  uint32_t ACQ3_DR;                /*!<  ,                                                     Address offset: 0x8C */
    __I  uint32_t ACQ4_DR;                /*!<  ,                                                     Address offset: 0x90 */
    __I  uint32_t ACQ5_DR;                /*!<  ,                                                     Address offset: 0x94 */
    __I  uint32_t ACQ6_DR;                /*!<  ,                                                     Address offset: 0x98 */
    __I  uint32_t ACQ7_DR;                /*!<  ,                                                     Address offset: 0x9C */
    __I  uint32_t ACQ8_DR;                /*!<  ,                                                     Address offset: 0xA0 */
    __I  uint32_t ACQ9_DR;                /*!<  ,                                                     Address offset: 0xA4 */
    __I  uint32_t ACQ10_DR;               /*!<  ,                                                     Address offset: 0xA8 */
    __I  uint32_t ACQ11_DR;               /*!<  ,                                                     Address offset: 0xAC */
    __I  uint32_t ACQ12_DR;               /*!<  ,                                                     Address offset: 0xB0 */
    __I  uint32_t ACQ13_DR;               /*!<  ,                                                     Address offset: 0xB4 */
    __I  uint32_t ACQ14_DR;               /*!<  ,                                                     Address offset: 0xB8 */
    __I  uint32_t ACQ15_DR;               /*!<  ,                                                     Address offset: 0xBC */
    __IO  uint32_t DMACOMB_CR;             /*!<  ,                                                     Address offset: 0xC0 */
    __I  uint32_t DMACOMB_DR;             /*!<  ,                                                     Address offset: 0xC4 */
} ADC_Type;

/* ================================================================================ */
/* ================                      DACx                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR1;                    /*!<  DACxControlRegister,                                  Address offset: 0x00 */
    __IO uint32_t CR2;                    /*!<  DACxControlRegister,                                  Address offset: 0x04 */
    __IO uint32_t CFGR;                   /*!<  DACxConfigRegister,                                   Address offset: 0x08 */
    __O  uint32_t SWTRGR;                 /*!<  DACxSoftwareTriggerRegister,                          Address offset: 0x0C */
    __IO uint32_t DHR;                    /*!<  DACxDataHoldingRegister,                              Address offset: 0x10 */
    __IO uint32_t ISR;                    /*!<  DACxInterruptStatusRegister,                          Address offset: 0x14 */
    __IO uint32_t IER;                    /*!<  DACxInterruptEnableRegister,                          Address offset: 0x18 */
    __IO uint32_t SHTR;                   /*!<  DACxSampleHoldTimeRegister,                           Address offset: 0x1C */
} DAC_Type;

/* ================================================================================ */
/* ================                      OPAx                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  OPAxControlRegister,                                  Address offset: 0x00 */
    __IO uint32_t CALR;                   /*!<  OPAxCalibrationRegister,                              Address offset: 0x04 */
    __I  uint32_t COR;                    /*!<  OPAxCalibrationOutputRegister,                        Address offset: 0x08 */
} OPA_Type;

/* ================================================================================ */
/* ================                       PGL                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t CFGR0;                  /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t CFGR1;                  /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t CFGR2;                  /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t CFGR3;                  /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t IER;                    /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t ISR;                    /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t LUT0;                   /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t LUT1;                   /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t LUT2;                   /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t LUT3;                   /*!<  ,                                                     Address offset: 0x28 */
} PGL_Type;

/* ================================================================================ */
/* ================                     USBPHY                     ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t PHYCR;                  /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t BCKCR;                  /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t PHYTEST;                /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t PHYPD;                  /*!<  ,                                                     Address offset: 0x0C */
} USBPHY_Type;

/* ================================================================================ */
/* ================                       USB                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t GCTL;                     /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t GINT;                     /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t GAHBCFG;                /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t GUSBCFG;                /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t GRSTCTL;                /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t GINTSTS;                /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t GINTMSK;                /*!<  ,                                                     Address offset: 0x18 */
    __I  uint32_t GRXSTSR;                /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t GRXSTSP;                /*!<  ,                                                     Address offset: 0x20 */
    __I  uint32_t GRXFSIZ;                /*!<  ,                                                     Address offset: 0x24 */
    __I  uint32_t GNPTXFSIZ;              /*!<  ,                                                     Address offset: 0x28 */
    __I  uint32_t GNPTXSTS;               /*!<  ,                                                     Address offset: 0x2C */
    __IO uint32_t RSV1[4];                /*!<  RESERVED REGISTER,                                    Address offset: 0x30 */
    __IO uint32_t GSNPSID;                /*!<  ,                                                     Address offset: 0x40 */
    __IO uint32_t GHWCFG1;                /*!<  ,                                                     Address offset: 0x44 */
    __IO uint32_t GHWCFG2;                /*!<  ,                                                     Address offset: 0x48 */
    __IO uint32_t GHWCFG3;                /*!<  ,                                                     Address offset: 0x4C */
    __IO uint32_t GHWCFG4;                /*!<  ,                                                     Address offset: 0x50 */
    __IO uint32_t RSV2[43];               /*!<  RESERVED REGISTER,                                    Address offset: 0x54 */
    __IO uint32_t HPTXFSIZ;               /*!<  ,                                                     Address offset: 0x100 */
    __I  uint32_t DIEPTXF1;               /*!<  ,                                                     Address offset: 0x104 */
    __I  uint32_t DIEPTXF2;               /*!<  ,                                                     Address offset: 0x108 */
    __I  uint32_t DIEPTXF3;               /*!<  ,                                                     Address offset: 0x10C */
    __I  uint32_t DIEPTXF4;               /*!<  ,                                                     Address offset: 0x110 */
    __IO uint32_t RSV3[187];              /*!<  RESERVED REGISTER,                                    Address offset: 0x114 */
    __IO uint32_t HCFG;                   /*!<  ,                                                     Address offset: 0x400 */
    __IO uint32_t HFIR;                   /*!<  ,                                                     Address offset: 0x404 */
    __I  uint32_t HFNUM;                  /*!<  ,                                                     Address offset: 0x408 */
    __IO uint32_t RSV4;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x40C */
    __IO uint32_t HPTXSTS;                /*!<  ,                                                     Address offset: 0x410 */
    __I  uint32_t HAINT;                  /*!<  ,                                                     Address offset: 0x414 */
    __I  uint32_t HAINTMSK;               /*!<  ,                                                     Address offset: 0x418 */
    __IO uint32_t RSV5[9];                /*!<  RESERVED REGISTER,                                    Address offset: 0x41C */
    __IO uint32_t HPRT;                   /*!<  ,                                                     Address offset: 0x440 */
    __IO uint32_t RSV6[47];               /*!<  RESERVED REGISTER,                                    Address offset: 0x444 */
    __IO uint32_t HCCHAR0;                /*!<  ,                                                     Address offset: 0x500 */
    __IO uint32_t RSV7;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x504 */
    __IO uint32_t HCINT0;                 /*!<  ,                                                     Address offset: 0x508 */
    __IO uint32_t HCINTMSK0;              /*!<  ,                                                     Address offset: 0x50C */
    __IO uint32_t HCTSIZE0;               /*!<  ,                                                     Address offset: 0x510 */
    __IO uint32_t RSV8[3];                /*!<  RESERVED REGISTER,                                    Address offset: 0x514 */
    __IO uint32_t HCCHAR1;                /*!<  ,                                                     Address offset: 0x520 */
    __IO uint32_t RSV9;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x524 */
    __IO uint32_t HCINT1;                 /*!<  ,                                                     Address offset: 0x528 */
    __IO uint32_t HCINTMSK1;              /*!<  ,                                                     Address offset: 0x52C */
    __IO uint32_t HCTSIZE1;               /*!<  ,                                                     Address offset: 0x530 */
    __IO uint32_t RSV10[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x534 */
    __IO uint32_t HCCHAR2;                /*!<  ,                                                     Address offset: 0x540 */
    __IO uint32_t RSV11;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x544 */
    __IO uint32_t HCINT2;                 /*!<  ,                                                     Address offset: 0x548 */
    __IO uint32_t HCINTMSK2;              /*!<  ,                                                     Address offset: 0x54C */
    __IO uint32_t HCTSIZE2;               /*!<  ,                                                     Address offset: 0x550 */
    __IO uint32_t RSV12[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x554 */
    __IO uint32_t HCCHAR3;                /*!<  ,                                                     Address offset: 0x560 */
    __IO uint32_t RSV13;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x564 */
    __IO uint32_t HCINT3;                 /*!<  ,                                                     Address offset: 0x568 */
    __IO uint32_t HCINTMSK3;              /*!<  ,                                                     Address offset: 0x56C */
    __IO uint32_t HCTSIZE3;               /*!<  ,                                                     Address offset: 0x570 */
    __IO uint32_t RSV14[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x574 */
    __IO uint32_t HCCHAR4;                /*!<  ,                                                     Address offset: 0x580 */
    __IO uint32_t RSV15;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x584 */
    __IO uint32_t HCINT4;                 /*!<  ,                                                     Address offset: 0x588 */
    __IO uint32_t HCINTMSK4;              /*!<  ,                                                     Address offset: 0x58C */
    __IO uint32_t HCTSIZE4;               /*!<  ,                                                     Address offset: 0x590 */
    __IO uint32_t RSV16[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x594 */
    __IO uint32_t HCCHAR5;                /*!<  ,                                                     Address offset: 0x5A0 */
    __IO uint32_t RSV17;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x5A4 */
    __IO uint32_t HCINT5;                 /*!<  ,                                                     Address offset: 0x5A8 */
    __IO uint32_t HCINTMSK5;              /*!<  ,                                                     Address offset: 0x5AC */
    __IO uint32_t HCTSIZE5;               /*!<  ,                                                     Address offset: 0x5B0 */
    __IO uint32_t RSV18[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x5B4 */
    __IO uint32_t HCCHAR6;                /*!<  ,                                                     Address offset: 0x5C0 */
    __IO uint32_t RSV19;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x5C4 */
    __IO uint32_t HCINT6;                 /*!<  ,                                                     Address offset: 0x5C8 */
    __IO uint32_t HCINTMSK6;              /*!<  ,                                                     Address offset: 0x5CC */
    __IO uint32_t HCTSIZE6;               /*!<  ,                                                     Address offset: 0x5D0 */
    __IO uint32_t RSV20[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x5D4 */
    __IO uint32_t HCCHAR7;                /*!<  ,                                                     Address offset: 0x5E0 */
    __IO uint32_t RSV21;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x5E4 */
    __IO uint32_t HCINT7;                 /*!<  ,                                                     Address offset: 0x5E8 */
    __IO uint32_t HCINTMSK7;              /*!<  ,                                                     Address offset: 0x5EC */
    __IO uint32_t HCTSIZE7;               /*!<  ,                                                     Address offset: 0x5F0 */
    __IO uint32_t RSV22[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x5F4 */
    __IO uint32_t HCCHAR8;                /*!<  ,                                                     Address offset: 0x600 */
    __IO uint32_t RSV23;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x604 */
    __IO uint32_t HCINT8;                 /*!<  ,                                                     Address offset: 0x608 */
    __IO uint32_t HCINTMSK8;              /*!<  ,                                                     Address offset: 0x60C */
    __IO uint32_t HCTSIZE8;               /*!<  ,                                                     Address offset: 0x610 */
    __IO uint32_t RSV24[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0x614 */
    __IO uint32_t HCCHAR9;                /*!<  ,                                                     Address offset: 0x620 */
    __IO uint32_t RSV25;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x624 */
    __IO uint32_t HCINT9;                 /*!<  ,                                                     Address offset: 0x628 */
    __IO uint32_t HCINTMSK9;              /*!<  ,                                                     Address offset: 0x62C */
    __IO uint32_t HCTSIZE9;               /*!<  ,                                                     Address offset: 0x630 */
    __IO uint32_t RSV26[116];             /*!<  RESERVED REGISTER,                                    Address offset: 0x634 */
    __IO uint32_t DCTL;                   /*!<  ,                                                     Address offset: 0x804 */
    __I  uint32_t DSTS;                   /*!<  ,                                                     Address offset: 0x808 */
    __IO uint32_t RSV27;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x80C */
    __IO uint32_t DIEPMSK;                /*!<  ,                                                     Address offset: 0x810 */
    __IO uint32_t DOEPMSK;                /*!<  ,                                                     Address offset: 0x814 */
    __I  uint32_t DAINT;                  /*!<  ,                                                     Address offset: 0x818 */
    __IO uint32_t DAINTMSK;               /*!<  ,                                                     Address offset: 0x81C */
    __IO uint32_t RSV28[5];               /*!<  RESERVED REGISTER,                                    Address offset: 0x820 */
    __IO uint32_t DIEPEMPMSK;             /*!<  ,                                                     Address offset: 0x834 */
    __IO uint32_t RSV29[50];              /*!<  RESERVED REGISTER,                                    Address offset: 0x838 */
    __IO uint32_t DIEPCTL0;               /*!<  ,                                                     Address offset: 0x900 */
    __IO uint32_t RSV30;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x904 */
    __IO uint32_t DIEPINT0;               /*!<  ,                                                     Address offset: 0x908 */
    __IO uint32_t RSV31;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x90C */
    __IO uint32_t DIEPTSIZ0;              /*!<  ,                                                     Address offset: 0x910 */
    __IO uint32_t RSV32;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x914 */
    __IO uint32_t DTXFSTS0;               /*!<  ,                                                     Address offset: 0x918 */
    __IO uint32_t RSV33;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x91C */
    __IO uint32_t DIEPCTL1;               /*!<  ,                                                     Address offset: 0x920 */
    __IO uint32_t RSV34;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x924 */
    __IO uint32_t DIEPINT1;               /*!<  ,                                                     Address offset: 0x928 */
    __IO uint32_t RSV35;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x92C */
    __IO uint32_t DIEPTSIZ1;              /*!<  ,                                                     Address offset: 0x930 */
    __IO uint32_t RSV36;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x934 */
    __IO uint32_t DTXFSTS1;               /*!<  ,                                                     Address offset: 0x938 */
    __IO uint32_t RSV37;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x93C */
    __IO uint32_t DIEPCTL2;               /*!<  ,                                                     Address offset: 0x940 */
    __IO uint32_t RSV38;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x944 */
    __IO uint32_t DIEPINT2;               /*!<  ,                                                     Address offset: 0x948 */
    __IO uint32_t RSV39;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x94C */
    __IO uint32_t DIEPTSIZ2;              /*!<  ,                                                     Address offset: 0x950 */
    __IO uint32_t RSV40;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x954 */
    __IO uint32_t DTXFSTS2;               /*!<  ,                                                     Address offset: 0x958 */
    __IO uint32_t RSV41;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x95C */
    __IO uint32_t DIEPCTL3;               /*!<  ,                                                     Address offset: 0x960 */
    __IO uint32_t RSV42;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x964 */
    __IO uint32_t DIEPINT3;               /*!<  ,                                                     Address offset: 0x968 */
    __IO uint32_t RSV43;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x96C */
    __IO uint32_t DIEPTSIZ3;              /*!<  ,                                                     Address offset: 0x970 */
    __IO uint32_t RSV44;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x974 */
    __IO uint32_t DTXFSTS3;               /*!<  ,                                                     Address offset: 0x978 */
    __IO uint32_t RSV45;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x97C */
    __IO uint32_t DIEPCTL4;               /*!<  ,                                                     Address offset: 0x980 */
    __IO uint32_t RSV46;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x984 */
    __IO uint32_t DIEPINT4;               /*!<  ,                                                     Address offset: 0x988 */
    __IO uint32_t RSV47;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x98C */
    __IO uint32_t DIEPTSIZ4;              /*!<  ,                                                     Address offset: 0x990 */
    __IO uint32_t RSV48;                  /*!<  RESERVED REGISTER,                                    Address offset: 0x994 */
    __IO uint32_t DTXFSTS4;               /*!<  ,                                                     Address offset: 0x998 */
    __IO uint32_t RSV49[89];              /*!<  RESERVED REGISTER,                                    Address offset: 0x99C */
    __IO uint32_t DOEPCTL0;               /*!<  ,                                                     Address offset: 0xB00 */
    __IO uint32_t RSV50;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB04 */
    __IO uint32_t DOEPINT0;               /*!<  ,                                                     Address offset: 0xB08 */
    __IO uint32_t RSV51;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB0C */
    __IO uint32_t DOEPTSIZ0;              /*!<  ,                                                     Address offset: 0xB10 */
    __IO uint32_t RSV52[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0xB14 */
    __IO uint32_t DOEPCTL1;               /*!<  ,                                                     Address offset: 0xB20 */
    __IO uint32_t RSV53;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB24 */
    __IO uint32_t DOEPINT1;               /*!<  ,                                                     Address offset: 0xB28 */
    __IO uint32_t RSV54;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB2C */
    __IO uint32_t DOEPTSIZ1;              /*!<  ,                                                     Address offset: 0xB30 */
    __IO uint32_t RSV55[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0xB34 */
    __IO uint32_t DOEPCTL2;               /*!<  ,                                                     Address offset: 0xB40 */
    __IO uint32_t RSV56;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB44 */
    __IO uint32_t DOEPINT2;               /*!<  ,                                                     Address offset: 0xB48 */
    __IO uint32_t RSV57;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB4C */
    __IO uint32_t DOEPTSIZ2;              /*!<  ,                                                     Address offset: 0xB50 */
    __IO uint32_t RSV58[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0xB54 */
    __IO uint32_t DOEPCTL3;               /*!<  ,                                                     Address offset: 0xB60 */
    __IO uint32_t RSV59;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB64 */
    __IO uint32_t DOEPINT3;               /*!<  ,                                                     Address offset: 0xB68 */
    __IO uint32_t RSV60;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB6C */
    __IO uint32_t DOEPTSIZ3;              /*!<  ,                                                     Address offset: 0xB70 */
    __IO uint32_t RSV61[3];               /*!<  RESERVED REGISTER,                                    Address offset: 0xB74 */
    __IO uint32_t DOEPCTL4;               /*!<  ,                                                     Address offset: 0xB80 */
    __IO uint32_t RSV62;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB84 */
    __IO uint32_t DOEPINT4;               /*!<  ,                                                     Address offset: 0xB88 */
    __IO uint32_t RSV63;                  /*!<  RESERVED REGISTER,                                    Address offset: 0xB8C */
    __IO uint32_t DOEPTSIZ4;              /*!<  ,                                                     Address offset: 0xB90 */
    __IO uint32_t RSV64[155];             /*!<  RESERVED REGISTER,                                    Address offset: 0xB94 */
    __IO uint32_t PCGCCTL;                /*!<  ,                                                     Address offset: 0xE00 */
} USB_Type;

/* ================================================================================ */
/* ================                      GPIO                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t EXTISEL0;               /*!<  ExternalInterruptInputSelectRegister0,                Address offset: 0x00 */
    __IO uint32_t EXTISEL1;               /*!<  ExternalInterruptInputSelectRegister1,                Address offset: 0x04 */
    __IO uint32_t EXTIEDS0;               /*!<  ExternalInterruptEdgeSelectandEnableRegister0,        Address offset: 0x08 */
    __IO uint32_t EXTIEDS1;               /*!<  ExternalInterruptEdgeSelectandEnableRegister1,        Address offset: 0x0C */
    __IO uint32_t EXTIDF;                 /*!<  ExternalInterruptDigitalFilterRegister,               Address offset: 0x10 */
    __IO uint32_t EXTIISR;                /*!<  ExternalInterruptandStatusRegister,                   Address offset: 0x14 */
    __IO uint32_t EXTIDI;                 /*!<  ExternalInterruptDataInputRegister,                   Address offset: 0x18 */
    __IO uint32_t RSV4[9];                /*!<  RESERVED REGISTER,                                    Address offset: 0x1C */
    __IO uint32_t FOUTSEL;                /*!<  FrequencyOutputSelectRegister,                        Address offset: 0x40 */
    __IO uint32_t RSV5[63];               /*!<  RESERVED REGISTER,                                    Address offset: 0x44 */
    __IO uint32_t PINWKEN;                /*!<  WakeupEnableRegister,                                 Address offset: 0x140 */
} GPIO_COMMON_Type;

typedef struct
{
    __IO uint32_t INEN;                   /*!<  GPIOxInputEnableRegister,                             Address offset: 0x00 */
    __IO uint32_t PUDEN;                  /*!<  GPIOxPull-UpPull-DownEnableRegister,                  Address offset: 0x04 */
    __IO uint32_t ODEN;                   /*!<  GPIOxOpen-DrainEnableRegister,                        Address offset: 0x08 */
    __IO uint32_t FCR;                    /*!<  GPIOxFunctionControlRegister,                         Address offset: 0x0C */
    __IO uint32_t DO;                     /*!<  GPIOxDataOutputRegister,                              Address offset: 0x10 */
    __O  uint32_t DSET;                   /*!<  GPIOxDataSetRegister,                                 Address offset: 0x14 */
    __O  uint32_t DRST;                   /*!<  GPIOxDataResetRegister,                               Address offset: 0x18 */
    __I  uint32_t DIN;                    /*!<  GPIOxDataInputRegister,                               Address offset: 0x1C */
    __IO uint32_t DFS;                    /*!<  GPIOxDigitalFunctionSelect,                           Address offset: 0x20 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x24 */
    __IO uint32_t ANEN;                   /*!<  GPIOxAnalogchannelEnableRegister,                     Address offset: 0x28 */
    __IO uint32_t DSR;                    /*!<  GPIOxDriverStrengthRegister,                          Address offset: 0x2C */
} GPIO_Type;
/* ================================================================================ */
/* ================                       SFU                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t RAMP_CR;                /*!<  RAMParityControlRegister,                             Address offset: 0x00 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x04 */
    __IO uint32_t MAP_CR;                 /*!<  MemoryAccessProtectionControlRegister,                Address offset: 0x08 */
    __IO uint32_t MAP_SR;                 /*!<  MemoryAccessProtectionControlRegister,                Address offset: 0x0C */
} SFU_Type;

/* ================================================================================ */
/* ================                      QSPI                      ================ */
/* ================================================================================ */

typedef struct
{
    __IO uint32_t CR;                     /*!<  ,                                                     Address offset: 0x00 */
    __IO uint32_t SR;                     /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t RMCR;                   /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t OMCR;                   /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t RABR;                   /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t OABR;                   /*!<  ,                                                     Address offset: 0x14 */
    __IO uint32_t IMAR;                   /*!<  ,                                                     Address offset: 0x18 */
    __IO uint32_t FDR;                    /*!<  ,                                                     Address offset: 0x1C */
    __IO uint32_t DLR;                    /*!<  ,                                                     Address offset: 0x20 */
    __IO uint32_t WCNT;                   /*!<  ,                                                     Address offset: 0x24 */
} QSPI_Type;

/* ================================================================================ */
/* ================                       SCU                      ================ */
/* ================================================================================ */

typedef struct
{
    __I  uint32_t SYSCFG;                 /*!<  ,                                                     Address offset: 0x00 */
    __I  uint32_t USRCFG;                 /*!<  ,                                                     Address offset: 0x04 */
    __IO uint32_t DBGCFG;                 /*!<  ,                                                     Address offset: 0x08 */
    __IO uint32_t RAMCFG;                 /*!<  ,                                                     Address offset: 0x0C */
    __IO uint32_t FLS_ACLOCK1;            /*!<  ,                                                     Address offset: 0x10 */
    __IO uint32_t FLS_ACLOCK2;            /*!<  ,                                                     Address offset: 0x14 */
    __I  uint32_t RAMRP00;                /*!<  ,                                                     Address offset: 0x18 */
    __I  uint32_t RAMRP01;                /*!<  ,                                                     Address offset: 0x1C */
    __I  uint32_t RAMRP10;                /*!<  ,                                                     Address offset: 0x20 */
    __I  uint32_t RAMRP11;                /*!<  ,                                                     Address offset: 0x24 */
    __IO uint32_t RSV1;                   /*!<  RESERVED REGISTER,                                    Address offset: 0x28 */
    __I  uint32_t FLS_TSTEN;              /*!<  ,                                                     Address offset: 0x2C */
    __I  uint32_t SCU_VRSR;               /*!<  ,                                                     Address offset: 0x30 */
    __I  uint32_t FLS_DCT0;               /*!<  ,                                                     Address offset: 0x34 */
    __I  uint32_t FLS_DCT1;               /*!<  ,                                                     Address offset: 0x38 */
} SCU_Type;

/* --------------------  End of section using anonymous unions  ------------------- */
#if defined(__CC_ARM)
#pragma pop
#elif defined(__ICCARM__)
/* leave anonymous unions enabled */
#elif defined(__GNUC__)
/* anonymous unions are enabled by default */
#elif defined(__TMS470__)
/* anonymous unions are enabled by default */
#elif defined(__TASKING__)
#pragma warning restore
#else
#warning Not supported compiler type
#endif

/* ================================================================================ */
/* ================              CPU memory map                    ================ */
/* ================================================================================ */

/* Peripheral and SRAM base address */

#define FLASH_BASE            ((     uint32_t)0x00000000)
#define SRAM_BASE             ((     uint32_t)0x20000000)
#define PERIPH_BASE           ((     uint32_t)0x40000000)

/* ================================================================================ */
/* ================              Peripheral memory map             ================ */
/* ================================================================================ */

/* Peripheral memory map */
#define SCU_BASE                        (PERIPH_BASE        +0x00000000)
#define FLS_BASE                        (PERIPH_BASE        +0x00001000)
#define PMU_BASE                        (PERIPH_BASE        +0x00002000)
#define VAO_BASE                        (PERIPH_BASE        +0x0001F800)
#define CDIF_BASE                       (PERIPH_BASE        +0x0001EC00)
#define RMU_BASE                        (PERIPH_BASE        +0x00002800)
#define IWDT_BASE                       (PERIPH_BASE        +0x00021000)
#define WWDT_BASE                       (PERIPH_BASE        +0x00011800)
#define CMU_BASE                        (PERIPH_BASE        +0x00002400)
#define SVD_BASE                        (PERIPH_BASE        +0x00021400)
#define AES_BASE                        (PERIPH_BASE        +0x0001B800)
#define RNG_BASE                        (PERIPH_BASE        +0x0001BC00)
#define COMP0_BASE                      (PERIPH_BASE        +0x00022400)
#define COMP1_BASE                      (PERIPH_BASE        +0x00022404)
#define COMP2_BASE                      (PERIPH_BASE        +0x00022408)
#define COMP_COMMON_BASE                (PERIPH_BASE        +0x0002240C)
#define I2CSMB0_BASE                    (PERIPH_BASE        +0x00015800)
#define I2CSMB1_BASE                    (PERIPH_BASE        +0x00015C00)
#define I2CSMB2_BASE                    (PERIPH_BASE        +0x00014C00)
#define I2C0_BASE                       (PERIPH_BASE        +0x00015000)
#define I2C1_BASE                       (PERIPH_BASE        +0x00015400)
#define UART_COMMON_BASE                (PERIPH_BASE        +0x00017C00)
#define UART0_BASE                      (PERIPH_BASE        +0x00011C00)
#define UART1_BASE                      (PERIPH_BASE        +0x00012000)
#define UART2_BASE                      (PERIPH_BASE        +0x00017400)
#define UART3_BASE                      (PERIPH_BASE        +0x00017800)
#define UART4_BASE                      (PERIPH_BASE        +0x00016800)
#define UART5_BASE                      (PERIPH_BASE        +0x00016C00)
#define UART6_BASE                      (PERIPH_BASE        +0x00016000)
#define UART7_BASE                      (PERIPH_BASE        +0x00016400)
#define LPUART0_BASE                    (PERIPH_BASE        +0x00020400)
#define LPUART1_BASE                    (PERIPH_BASE        +0x00020800)
#define SPI0_BASE                       (PERIPH_BASE        +0x00019000)
#define SPI1_BASE                       (PERIPH_BASE        +0x00018C00)
#define SPI2_BASE                       (PERIPH_BASE        +0x00010800)
#define SPI3_BASE                       (PERIPH_BASE        +0x00010400)
#define SPI4_BASE                       (PERIPH_BASE        +0x00010000)
#define EPSC_BASE                       (PERIPH_BASE        +0x00001400)
#define CAN_BASE                        (PERIPH_BASE        +0x00019400)
#define FDCAN_BASE                      (PERIPH_BASE        +0x00019800)
#define DMA_BASE                        (PERIPH_BASE        +0x00000400)
#define CRC_BASE                        (PERIPH_BASE        +0x00018000)
#define ATIM0_BASE                      (PERIPH_BASE        +0x00018400)
#define ATIM1_BASE                      (PERIPH_BASE        +0x0001B000)
#define GPTIM0_BASE                     (PERIPH_BASE        +0x00013800)
#define GPTIM1_BASE                     (PERIPH_BASE        +0x00013C00)
#define GPTIM2_BASE                     (PERIPH_BASE        +0x00014000)
#define BSTIM16_BASE                    (PERIPH_BASE        +0x0001B400)
#define LPTIM16_BASE                    (PERIPH_BASE        +0x00020000)
#define EPWM0_BASE                      (PERIPH_BASE        +0x00011000)
#define EPWM1_BASE                      (PERIPH_BASE        +0x00011100)
#define EPWM2_BASE                      (PERIPH_BASE        +0x00011200)
#define EPWM3_BASE                      (PERIPH_BASE        +0x00011300)
#define RTCB_BASE                       (PERIPH_BASE        +0x0001F000)
#define ADC_BASE                        (PERIPH_BASE        +0x0001AC00)
#define DAC0_BASE                       (PERIPH_BASE        +0x00021800)
#define DAC1_BASE                       (PERIPH_BASE        +0x00021C00)
#define OPA0_BASE                       (PERIPH_BASE        +0x00022800)
#define OPA1_BASE                       (PERIPH_BASE        +0x00022820)
#define PGL_BASE                        (PERIPH_BASE        +0x0001DC00)
#define USBPHY_BASE                     (PERIPH_BASE        +0x10010000)
#define USB_BASE                        (PERIPH_BASE        +0x10011000)
#define GPIOA_BASE                      (PERIPH_BASE        +0x00000C00)
#define GPIOB_BASE                      (PERIPH_BASE        +0x00000C40)
#define GPIOC_BASE                      (PERIPH_BASE        +0x00000C80)
#define GPIOD_BASE                      (PERIPH_BASE        +0x00000CC0)
#define GPIOE_BASE                      (PERIPH_BASE        +0x00000D00)
#define GPIOF_BASE                      (PERIPH_BASE        +0x00000D40)
#define GPIO_COMMON_BASE                       (PERIPH_BASE        +0x00000DC0)
#define SFU_BASE                        (PERIPH_BASE        +0x00002C00)
#define QSPI_BASE                       (PERIPH_BASE        +0xA0044000)

/* ================================================================================ */
/* ================             Peripheral declaration             ================ */
/* ================================================================================ */
#define SCU                             ((SCU_Type          *) SCU_BASE         )
#define FLASH                           ((FLASH_Type        *) FLS_BASE         )
#define PMU                             ((PMU_Type          *) PMU_BASE         )
#define VREFP                           ((VREFP_Type        *) PMU_BASE         )
#define VAO                             ((VAO_Type          *) VAO_BASE         )
#define CDIF                            ((CDIF_Type         *) CDIF_BASE        )
#define RMU                             ((RMU_Type          *) RMU_BASE         )
#define IWDT                            ((IWDT_Type         *) IWDT_BASE        )
#define WWDT                            ((WWDT_Type         *) WWDT_BASE        )
#define CMU                             ((CMU_Type          *) CMU_BASE         )
#define SVD                             ((SVD_Type          *) SVD_BASE         )
#define AES                             ((AES_Type          *) AES_BASE         )
#define RNG                             ((RNG_Type          *) RNG_BASE         )
#define COMP0                           ((COMP_Type         *) COMP0_BASE)
#define COMP1                           ((COMP_Type         *) COMP1_BASE)
#define COMP2                           ((COMP_Type         *) COMP2_BASE)
#define COMP                            ((COMP_COMMON_Type*) COMP_COMMON_BASE)
#define I2CSMB0                         ((I2CSMB_Type      *) I2CSMB0_BASE     )
#define I2CSMB1                         ((I2CSMB_Type      *) I2CSMB1_BASE     )
#define I2CSMB2                         ((I2CSMB_Type      *) I2CSMB2_BASE     )
#define I2C0                            ((I2C_Type         *) I2C0_BASE        )
#define I2C1                            ((I2C_Type         *) I2C1_BASE        )
#define UART                            ((UART_COMMON_Type         *) UART_COMMON_BASE        )
#define UART0                           ((UART_Type        *) UART0_BASE       )
#define UART1                           ((UART_Type        *) UART1_BASE       )
#define UART2                           ((UART_Type        *) UART2_BASE       )
#define UART3                           ((UART_Type        *) UART3_BASE       )
#define UART4                           ((UART_Type        *) UART4_BASE       )
#define UART5                           ((UART_Type        *) UART5_BASE       )
#define UART6                           ((UART_Type        *) UART6_BASE       )
#define UART7                           ((UART_Type        *) UART7_BASE       )
#define LPUART0                         ((LPUART_Type      *) LPUART0_BASE     )
#define LPUART1                         ((LPUART_Type      *) LPUART1_BASE     )
#define SPI0                            ((SPI_Type         *) SPI0_BASE        )
#define SPI1                            ((SPI_Type         *) SPI1_BASE        )
#define SPI2                            ((SPI_Type         *) SPI2_BASE        )
#define SPI3                            ((SPI_Type         *) SPI3_BASE        )
#define SPI4                            ((SPI_Type         *) SPI4_BASE        )
#define EPSC                            ((EPSC_Type         *) EPSC_BASE        )
#define CAN                             ((CAN_Type          *) CAN_BASE         )
#define FDCAN                           ((FDCAN_Type        *) FDCAN_BASE       )
#define DMA                             ((DMA_Type          *) DMA_BASE         )
#define CRC                             ((CRC_Type          *) CRC_BASE         )
#define ATIM0                           ((ATIM_Type        *) ATIM0_BASE       )
#define ATIM1                           ((ATIM_Type        *) ATIM1_BASE       )
#define GPTIM0                          ((GPTIM_Type       *) GPTIM0_BASE      )
#define GPTIM1                          ((GPTIM_Type       *) GPTIM1_BASE      )
#define GPTIM2                          ((GPTIM_Type       *) GPTIM2_BASE      )
#define BSTIM16                         ((BSTIM16_Type      *) BSTIM16_BASE     )
#define LPTIM16                         ((LPTIM16_Type      *) LPTIM16_BASE     )
#define EPWM0                           ((EPWM_Type        *) EPWM0_BASE       )
#define EPWM1                           ((EPWM_Type        *) EPWM1_BASE       )
#define EPWM2                           ((EPWM_Type        *) EPWM2_BASE       )
#define EPWM3                           ((EPWM_Type        *) EPWM3_BASE       )
#define RTCB                            ((RTCB_Type         *) RTCB_BASE        )
#define ADC                             ((ADC_Type          *) ADC_BASE         )
#define DAC0                            ((DAC_Type         *) DAC0_BASE        )
#define DAC1                            ((DAC_Type         *) DAC1_BASE        )
#define OPA0                            ((OPA_Type         *) OPA0_BASE        )
#define OPA1                            ((OPA_Type         *) OPA1_BASE        )
#define PGL                             ((PGL_Type          *) PGL_BASE         )
#define USBPHY                          ((USBPHY_Type       *) USBPHY_BASE      )
#define USB                             ((USB_Type          *) USB_BASE         )
#define GPIOA                           ((GPIO_Type        *) GPIOA_BASE       )
#define GPIOB                           ((GPIO_Type        *) GPIOB_BASE       )
#define GPIOC                           ((GPIO_Type        *) GPIOC_BASE       )
#define GPIOD                           ((GPIO_Type        *) GPIOD_BASE       )
#define GPIOE                           ((GPIO_Type        *) GPIOE_BASE       )
#define GPIOF                           ((GPIO_Type        *) GPIOF_BASE       )
#define GPIO                            ((GPIO_COMMON_Type  *) GPIO_COMMON_BASE )
#define SFU                             ((SFU_Type          *) SFU_BASE         )
#define QSPI                            ((QSPI_Type         *) QSPI_BASE        )

/* ================================================================================ */
/* ================             Peripheral include                 ================ */
/* ================================================================================ */

/** @} */ /* End of group Device_Peripheral_Registers */
/** @} */ /* End of group FM33FKXX */
/** @} */ /* End of group Keil */

#ifdef __cplusplus
}
#endif

#endif  /* FM33FK5XX_H */
