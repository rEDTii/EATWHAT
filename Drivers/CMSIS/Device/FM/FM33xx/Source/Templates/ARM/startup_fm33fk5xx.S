/******************************************************************************
 * @file     startup_ARMv8MML.S
 * @brief    CMSIS-Core Device Startup File for Cortex-ARMv8MML Device
 * @version  V2.0.0
 * @date     26. May 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

                .syntax  unified
                .arch    armv8-m.main

                #define __INITIAL_SP     Image$$ARM_LIB_STACK$$ZI$$Limit
                #define __STACK_LIMIT    Image$$ARM_LIB_STACK$$ZI$$Base
                #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
                #define __STACK_SEAL     Image$$STACKSEAL$$ZI$$Base
                #endif

                .section RESET
                .align   2
                .globl   __Vectors
                .globl   __Vectors_End
                .globl   __Vectors_Size
__Vectors:
                .long    __INITIAL_SP                       /*     Initial Stack Pointer */
                .long    Reset_Handler                      /*     Reset Handler */
                .long    NMI_Handler                        /* -14 NMI Handler */
                .long    HardFault_Handler                  /* -13 Hard Fault Handler */
                .long    MemManage_Handler                  /* -12 MPU Fault Handler */
                .long    BusFault_Handler                   /* -11 Bus Fault Handler */
                .long    UsageFault_Handler                 /* -10 Usage Fault Handler */
                .long    0                                  /*  Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    0                                  /*     Reserved */
                .long    SVCall_Handler                        /*  -5 SVC Handler */
                .long    DebugMonitor_Handler                   /*  -4 Debug Monitor Handler */
                .long    0                                  /*     Reserved */
                .long    PendSV_Handler                     /*  -2 PendSV Handler */
                .long    SysTick_Handler                    /*  -1 SysTick Handler */

                /* Interrupts */
                .long    WWDT_IRQHandler                    /* 0   WDT */
                .long    SVD_IRQHandler                     /* 1   SVD */
                .long    RTC_IRQHandler                     /* 2   RTC */
                .long    IWDT_IRQHandler                    /* 3   IWDT */
                .long    FLASH_IRQHandler                   /* 4   FLASH */
                .long    HFDET_SCSE_IRQHandler              /* 5   HFDET & Sysclk selection error */
                .long    LFDET_IRQHandler                   /* 6   LFDET */
                .long    MAP_ERR_IRQHandler                 /* 7   MAP_ERR */
                .long    ADC_IRQHandler                     /* 8   ADC */
                .long    DAC0_IRQHandler                    /* 9   DAC0 */
                .long    DAC1_IRQHandler                    /* 10  DAC1 */
                .long    SPI0_IRQHandler                    /* 11  SPI0 */
                .long    SPI1_IRQHandler                    /* 12  SPI1 */
                .long    SPI2_IRQHandler                    /* 13  SPI2 */
                .long    SPI3_IRQHandler                    /* 14  SPI3 */
                .long    SPI4_IRQHandler                    /* 15  SPI4 */
                .long    0                                  /* 16  Reserved */
                .long    0                                  /* 17  Reserved */
                .long    UART0_IRQHandler                   /* 18  UART0 */
                .long    UART1_IRQHandler                   /* 19  UART1 */
                .long    UART2_IRQHandler                   /* 20  UART2 */
                .long    UART3_IRQHandler                   /* 21  UART3 */
                .long    UART4_IRQHandler                   /* 22  UART4 */
                .long    UART5_IRQHandler                   /* 23  UART5 */
                .long    UART6_IRQHandler                   /* 24  UART6 */
                .long    UART7_IRQHandler                   /* 25  UART7 */
                .long    0                                  /* 26  Reserved */
                .long    0                                  /* 27  Reserved */
                .long    0                                  /* 28  Reserved */
                .long    LPUART0_IRQHandler                 /* 29  LPUART0 */
                .long    LPUART1_IRQHandler                 /* 30  LPUART1 */
                .long    0                                  /* 31  Reserved */
                .long    EXTIA_IRQHandler                   /* 32  EXTIA              */
                .long    EXTIB_IRQHandler                   /* 33  EXTIB */
                .long    EXTIC_IRQHandler                   /* 34  EXTIC              */
                .long    EXTID_IRQHandler                   /* 35  EXTID */
                .long    EXTIE_IRQHandler                   /* 36  EXTIE */
                .long    EXTIF_IRQHandler                   /* 37  EXTIF */
                .long    I2C0_IRQHandler                    /* 38  I2C0 */
                .long    I2C1_IRQHandler                    /* 39  I2C1 */
                .long    I2CSMB0_IRQHandler                 /* 40  I2CSMB0 */
                .long    I2CSMB1_IRQHandler                 /* 41  I2CSMB1  */
                .long    I2CSMB2_IRQHandler                 /* 42  I2CSMB2 */
                .long    0                                  /* 43  Reserved          */
                .long    0                                  /* 44  Reserved       */
                .long    CCL_IRQHandler                     /* 45  CCL    */
                .long    AES_IRQHandler                     /* 46  AES */
                .long    0                                  /* 47  Reserved */
                .long    0                                  /* 48  Reserved */
                .long    0                                  /* 49  Reserved */
                .long    DMA_IRQHandler                     /* 50  DMA */
                .long    WKUPX_IRQHandler                   /* 51  WKUPX */
                .long    LUT_IRQHandler                     /* 52  LUT */
                .long    COMPX_IRQHandler                   /* 53  COMPX */
                .long    CAN_IRQHandler                     /* 54  FSCAN */
                .long    0                                  /* 55  Reserved */
                .long    FDCAN_IRQHandler                   /* 56  FDCAN */
                .long    0                                  /* 57  Reserved */
                .long    0                                  /* 58  Reserved */
                .long    0                                  /* 59  Reserved */
                .long    LPTIM16_IRQHandler                 /* 60  LPTIM16 */
                .long    0                                  /* 61  Reserved */
                .long    BSTIM16_IRQHandler                 /* 62  BSTIM16 */
                .long    0                                  /* 63  Reserved */
                .long    ATIM0_IRQHandler                   /* 64  ATIM0 */
                .long    ATIM1_IRQHandler                   /* 65  ATIM1 */
                .long    0                                  /* 66  Reserved */
                .long    0                                  /* 67  Reserved */
                .long    GPTIM0_IRQHandler                  /* 68  GPTIM0 */
                .long    GPTIM1_IRQHandler                  /* 69  GPTIM1 */
                .long    GPTIM2_IRQHandler                  /* 70  GPTIM2 */
                .long    0                                  /* 71  Reserved */
                .long    EPWM0_IRQHandler                   /* 72  EPWM1 */
                .long    EPWM0_TZ_IRQHandler                /* 73  EPWM1_TZ */
                .long    EPWM1_IRQHandler                   /* 74  EPWM2 */
                .long    EPWM1_TZ_IRQHandler                /* 75  EPWM2_TZ */
                .long    EPWM2_IRQHandler                   /* 76  EPWM3 */
                .long    EPWM2_TZ_IRQHandler                /* 77  EPWM3_TZ */
                .long    EPWM3_IRQHandler                   /* 78  EPWM4 */
                .long    EPWM3_TZ_IRQHandler                /* 79  EPWM4_TZ */
                .long    0                                  /* 80  Reserved */
                .long    0                                  /* 81  Reserved */
                .long    FPU_IRQHandler                     /* 82  FPU */
                .long    USB_IRQHandler                     /* 83  USB */
                .long    0                                  /* 84  Reserved */
                .long    EPSC_IRQHandler                    /* 85  EPSC */

                .space   (394 * 4)                          /* Interrupts 86 .. 480 are left out */
__Vectors_End:
                .equ     __Vectors_Size, __Vectors_End - __Vectors
                .size    __Vectors, . - __Vectors


                .thumb
                .section .text
                .align   2

                .thumb_func
                .type    Reset_Handler, %function
                .globl   Reset_Handler
                .fnstart
Reset_Handler:
                ldr      r0, =__INITIAL_SP
                msr      psp, r0

                ldr      r0, =__STACK_LIMIT
                msr      msplim, r0
                msr      psplim, r0

                #if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
                ldr      r0, =__STACK_SEAL
                ldr      r1, =0xFEF5EDA5U
                strd     r1,r1,[r0,#0]
                #endif

                bl       SystemInit

                bl       __main

                .fnend
                .size    Reset_Handler, . - Reset_Handler


/* The default macro is not used for HardFault_Handler
 * because this results in a poor debug illusion.
 */
                .thumb_func
                .type    HardFault_Handler, %function
                .weak    HardFault_Handler
                .fnstart
HardFault_Handler:
                b        .
                .fnend
                .size    HardFault_Handler, . - HardFault_Handler

                .thumb_func
                .type    Default_Handler, %function
                .weak    Default_Handler
                .fnstart
Default_Handler:
                b        .
                .fnend
                .size    Default_Handler, . - Default_Handler

/* Macro to define default exception/interrupt handlers.
 * Default handler are weak symbols with an endless loop.
 * They can be overwritten by real handlers.
 */
                .macro   Set_Default_Handler  Handler_Name
                .weak    \Handler_Name
                .set     \Handler_Name, Default_Handler
                .endm


/* Default exception/interrupt handler */

                Set_Default_Handler  NMI_Handler
                Set_Default_Handler  MemManage_Handler
                Set_Default_Handler  BusFault_Handler
                Set_Default_Handler  UsageFault_Handler
                Set_Default_Handler  SVCall_Handler
                Set_Default_Handler  DebugMonitor_Handler
                Set_Default_Handler  PendSV_Handler
                Set_Default_Handler  SysTick_Handler

                Set_Default_Handler  WWDT_IRQHandler
                Set_Default_Handler  SVD_IRQHandler
                Set_Default_Handler  RTC_IRQHandler
                Set_Default_Handler  IWDT_IRQHandler
                Set_Default_Handler  FLASH_IRQHandler
                Set_Default_Handler  HFDET_SCSE_IRQHandler
                Set_Default_Handler  LFDET_IRQHandler
                Set_Default_Handler  MAP_ERR_IRQHandler
                Set_Default_Handler  ADC_IRQHandler
                Set_Default_Handler  DAC0_IRQHandler
                Set_Default_Handler  DAC1_IRQHandler
                Set_Default_Handler  SPI0_IRQHandler
                Set_Default_Handler  SPI1_IRQHandler
                Set_Default_Handler  SPI2_IRQHandler
                Set_Default_Handler  SPI3_IRQHandler
                Set_Default_Handler  SPI4_IRQHandler
                Set_Default_Handler  UART0_IRQHandler
                Set_Default_Handler  UART1_IRQHandler
                Set_Default_Handler  UART2_IRQHandler
                Set_Default_Handler  UART3_IRQHandler
                Set_Default_Handler  UART4_IRQHandler
                Set_Default_Handler  UART5_IRQHandler
                Set_Default_Handler  UART6_IRQHandler
                Set_Default_Handler  UART7_IRQHandler
                Set_Default_Handler  LPUART0_IRQHandler
                Set_Default_Handler  LPUART1_IRQHandler
                Set_Default_Handler  EXTIA_IRQHandler
                Set_Default_Handler  EXTIB_IRQHandler
                Set_Default_Handler  EXTIC_IRQHandler
                Set_Default_Handler  EXTID_IRQHandler
                Set_Default_Handler  EXTIE_IRQHandler
                Set_Default_Handler  EXTIF_IRQHandler
                Set_Default_Handler  I2C0_IRQHandler
                Set_Default_Handler  I2C1_IRQHandler
                Set_Default_Handler  I2CSMB0_IRQHandler
                Set_Default_Handler  I2CSMB1_IRQHandler
                Set_Default_Handler  I2CSMB2_IRQHandler
                Set_Default_Handler  CCL_IRQHandler
                Set_Default_Handler  AES_IRQHandler
                Set_Default_Handler  DMA_IRQHandler
                Set_Default_Handler  WKUPX_IRQHandler
                Set_Default_Handler  LUT_IRQHandler
                Set_Default_Handler  COMPX_IRQHandler
                Set_Default_Handler  CAN_IRQHandler
                Set_Default_Handler  FDCAN_IRQHandler
                Set_Default_Handler  LPTIM16_IRQHandler
                Set_Default_Handler  BSTIM16_IRQHandler
                Set_Default_Handler  ATIM0_IRQHandler
                Set_Default_Handler  ATIM1_IRQHandler
                Set_Default_Handler  GPTIM0_IRQHandler
                Set_Default_Handler  GPTIM1_IRQHandler
                Set_Default_Handler  GPTIM2_IRQHandler
                Set_Default_Handler  EPWM0_IRQHandler
                Set_Default_Handler  EPWM0_TZ_IRQHandler
                Set_Default_Handler  EPWM1_IRQHandler
                Set_Default_Handler  EPWM1_TZ_IRQHandler
                Set_Default_Handler  EPWM2_IRQHandler
                Set_Default_Handler  EPWM2_TZ_IRQHandler
                Set_Default_Handler  EPWM3_IRQHandler
                Set_Default_Handler  EPWM3_TZ_IRQHandler
                Set_Default_Handler  FPU_IRQHandler
                Set_Default_Handler  USB_IRQHandler
                Set_Default_Handler  EPSC_IRQHandler
                .end
