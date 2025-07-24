
        MODULE  ?cstartup

        ;; Forward declaration of sections.
        SECTION CSTACK:DATA:NOROOT(3)

        SECTION .intvec:CODE:NOROOT(2)

        EXTERN  __iar_program_start
        PUBLIC  __vector_table

        DATA
        
__vector_table
        DCD     sfe(CSTACK)
        DCD     Reset_Handler             ; Reset Handler
        DCD     NMI_Handler               ; NMI Handler
        DCD     HardFault_Handler         ; Hard Fault Handler
        DCD     MemManage_Handler         ; MemManage_Handler
        DCD     BusFault_Handler          ; BusFault_Handler
        DCD     UsageFault_Handler        ; UsageFault_Handler
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     0                         ; Reserved
        DCD     SVC_Handler               ; SVCall Handler
        DCD     DebugMonitor_Handler      ; Reserved
        DCD     0                         ; Reserved
        DCD     PendSV_Handler            ; PendSV Handler
        DCD     SysTick_Handler           ; SysTick Handler

        ; External Interrupts
        DCD     WWDT_IRQHandler            	; 0:  WWDT 
        DCD     SVD_IRQHandler            	; 1:  SVD 	
        DCD     RTC_IRQHandler            	; 2:  RTC 	
        DCD     IWDT_IRQHandler	      		; 3:  IWDT	
        DCD     FLASH_IRQHandler	        ; 4:  FLASH	
        DCD     CMU_IRQHandler            	; 5:  CMU	
        DCD     LFDET_IRQHandler           	; 6:  LFDET
        DCD     MAP_ERR_IRQHandler          ; 7:  MAP_ERR 	
        DCD     ADC_IRQHandler           	; 8:  ADC
        DCD     DAC0_IRQHandler           	; 9:  DAC0	
        DCD     DAC1_IRQHandler           	; 10:  DAC1	
        DCD     SPI0_IRQHandler           	; 11:  SPI0		
        DCD     SPI1_IRQHandler           	; 12:  SPI1	
        DCD     SPI2_IRQHandler           	; 13:  SPI2	
        DCD     SPI3_IRQHandler           	; 14:  SPI3		
        DCD     SPI4_IRQHandler		  		; 15:  SPI4	
        DCD     0	      					; 16:  Reserved	
        DCD     0       					; 17:  Reserved	
        DCD     UART0_IRQHandler			; 18:  UART0	
        DCD     UART1_IRQHandler         	; 19:  UART1	
        DCD     UART2_IRQHandler			; 20:  UART2
        DCD     UART3_IRQHandler            ; 21:  UART3	
        DCD     UART4_IRQHandler          	; 22:  UART4	
        DCD     UART5_IRQHandler          	; 23:  UART5	
        DCD     UART6_IRQHandler			; 24:  UART6
        DCD     UART7_IRQHandler          	; 25:  UART7
        DCD     0          					; 26:  Reserved	
        DCD     0          					; 27:  Reserved	
        DCD     0           				; 28:  Reserved	
        DCD     LPUART0_IRQHandler          ; 29:  LPUART0	
        DCD     LPUART1_IRQHandler          ; 30:  LPUART1
        DCD     0        					; 31:  Reserved
		DCD     EXTIA_IRQHandler        	; 32:  EXTIA
		DCD     EXTIB_IRQHandler        	; 33:  EXTIB
		DCD     EXTIC_IRQHandler        	; 34:  EXTIC
		DCD     EXTID_IRQHandler        	; 35:  EXTID
		DCD     EXTIE_IRQHandler        	; 36:  EXTIE
		DCD     EXTIF_IRQHandler        	; 37:  EXTIF
		DCD     I2C0_IRQHandler        	        ; 38:  I2C0
		DCD     I2C1_IRQHandler               	; 39:  I2C1
		DCD     I2CSMB0_IRQHandler        	; 40:  I2CSMB0
		DCD     I2CSMB1_IRQHandler        	; 41:  I2CSMB1
		DCD     I2CSMB2_IRQHandler        	; 42:  I2CSMB2
		DCD     0        					; 43:  Reserved
		DCD     0        					; 44:  Reserved
		DCD     CCL_IRQHandler        		; 45:  CCL
		DCD     AES_IRQHandler        		; 46:  AES
		DCD     0        					; 47:  Reserved
		DCD     0        					; 48:  Reserved
		DCD     0        					; 49:  Reserved
		DCD     DMA_IRQHandler        		; 50:  DMA
		DCD     WKUPX_IRQHandler        	; 51:  WKUPX
		DCD     LUT_IRQHandler        		; 52:  LUT
		DCD     COMPX_IRQHandler        	; 53:  COMPX
		DCD     CAN_IRQHandler        	; 54:  CAN
		DCD     0        					; 55:  Reserved
		DCD     FDCAN_IRQHandler        	; 56:  FDCAN
		DCD     0        					; 57:  Reserved
		DCD     0        					; 58:  Reserved
		DCD     0        					; 59:  Reserved
		DCD     LPTIM16_IRQHandler        	; 60:  LPTIM16
		DCD     0        					; 61:  Reserved
		DCD     BSTIM16_IRQHandler        	; 62:  BSTIM16
		DCD     0        					; 63:  Reserved
		DCD     ATIM0_IRQHandler        	; 64:  ATIM0
		DCD     ATIM1_IRQHandler        	; 65:  ATIM1
		DCD     0        					; 66:  Reserved
		DCD     0        					; 67:  Reserved
		DCD     GPTIM0_IRQHandler        	; 68:  GPTIM0
		DCD     GPTIM1_IRQHandler        	; 69:  GPTIM1
		DCD     GPTIM2_IRQHandler        	; 70:  GPTIM2
		DCD     0        					; 71:  Reserved
		DCD     EPWM1_IRQHandler        	; 72:  EPWM1
		DCD     EPWM1_TZ_IRQHandler        	; 73:  EPWM1_TZ
		DCD     EPWM2_IRQHandler        	; 74:  EPWM2
		DCD     EPWM2_TZ_IRQHandler        	; 75:  EPWM2_TZ
		DCD     EPWM3_IRQHandler        	; 76:  EPWM3
		DCD     EPWM3_TZ_IRQHandler        	; 77:  EPWM3_TZ
		DCD     EPWM4_IRQHandler        	; 78:  EPWM4
		DCD     EPWM4_TZ_IRQHandler        	; 79:  EPWM4_TZ
		DCD     0        					; 80:  Reserved
		DCD     0        					; 81:  Reserved
		DCD     FPU_IRQHandler        		; 82:  FPU
		DCD     USB_IRQHandler        		; 83:  USB
		DCD     0        					; 84:  Reserved
		DCD     EPSC_IRQHandler        		; 85:  EPSC
__Vectors_End
                
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB

        PUBWEAK Reset_Handler
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler
        IMPORT  SystemInit
        LDR     R0, =SystemInit
        BLX     R0		
        LDR     R0, =__iar_program_start
        ;LDR     R0, =__main
        BX      R0
        
        PUBWEAK NMI_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
NMI_Handler
        B NMI_Handler
        
        
        PUBWEAK HardFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
HardFault_Handler
        B HardFault_Handler
       
        PUBWEAK MemManage_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
MemManage_Handler
        B MemManage_Handler
				
		
        PUBWEAK BusFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
BusFault_Handler
        B BusFault_Handler

		
        PUBWEAK UsageFault_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
UsageFault_Handler
        B UsageFault_Handler	
			
			        
        PUBWEAK SVC_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVC_Handler
        B SVC_Handler
      
	  
        PUBWEAK DebugMonitor_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
DebugMonitor_Handler
        B DebugMonitor_Handler	  
	    
        
        PUBWEAK PendSV_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
PendSV_Handler  
        B PendSV_Handler
        
        
        PUBWEAK SysTick_Handler
        SECTION .text:CODE:NOROOT:REORDER(1)
SysTick_Handler
        B SysTick_Handler
        
        
        PUBWEAK WWDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WWDT_IRQHandler
        B WWDT_IRQHandler
        
                
        PUBWEAK SVD_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SVD_IRQHandler
        B SVD_IRQHandler
        
                
        PUBWEAK RTC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
RTC_IRQHandler
        B RTC_IRQHandler
        

        PUBWEAK IWDT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
IWDT_IRQHandler
        B IWDT_IRQHandler

                
        PUBWEAK FLASH_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
FLASH_IRQHandler
        B FLASH_IRQHandler
        
                
        PUBWEAK CMU_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CMU_IRQHandler
        B CMU_IRQHandler
        
                
        PUBWEAK LFDET_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LFDET_IRQHandler
        B LFDET_IRQHandler
  
        PUBWEAK MAP_ERR_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
MAP_ERR_IRQHandler
        B MAP_ERR_IRQHandler
       
       
        PUBWEAK ADC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ADC_IRQHandler
        B ADC_IRQHandler
        

        PUBWEAK DAC0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DAC0_IRQHandler
        B DAC0_IRQHandler
        
                                
        PUBWEAK DAC1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DAC1_IRQHandler
        B DAC1_IRQHandler
        
                
        PUBWEAK SPI0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI0_IRQHandler
        B SPI0_IRQHandler
        
                
        PUBWEAK SPI1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI1_IRQHandler
        B SPI1_IRQHandler
        
                
        PUBWEAK SPI2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI2_IRQHandler
        B SPI2_IRQHandler
        
                
        PUBWEAK SPI3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI3_IRQHandler
        B SPI3_IRQHandler
        
                
        PUBWEAK SPI4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
SPI4_IRQHandler
        B SPI4_IRQHandler
        
                 
        PUBWEAK UART0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART0_IRQHandler
        B UART0_IRQHandler
        
                 
        PUBWEAK UART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART1_IRQHandler
        B UART1_IRQHandler
        
                
        PUBWEAK UART2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART2_IRQHandler
        B UART2_IRQHandler
        
        PUBWEAK UART3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART3_IRQHandler
        B UART3_IRQHandler
        
                
        PUBWEAK UART4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART4_IRQHandler
        B UART4_IRQHandler
                  
                  
        PUBWEAK UART5_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART5_IRQHandler
        B UART5_IRQHandler
                
                
        PUBWEAK UART6_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART6_IRQHandler
        B UART6_IRQHandler
        
        
        PUBWEAK UART7_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
UART7_IRQHandler
        B UART7_IRQHandler
   
   
        PUBWEAK LPUART0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPUART0_IRQHandler
        B LPUART0_IRQHandler


        PUBWEAK LPUART1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPUART1_IRQHandler
        B LPUART1_IRQHandler 
      
      
        PUBWEAK EXTIA_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTIA_IRQHandler
        B EXTIA_IRQHandler



        PUBWEAK EXTIB_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTIB_IRQHandler
        B EXTIB_IRQHandler
        
                
        PUBWEAK EXTIC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTIC_IRQHandler
        B EXTIC_IRQHandler
               
        
        
        PUBWEAK EXTID_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTID_IRQHandler
        B EXTID_IRQHandler
         
         
        PUBWEAK EXTIE_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTIE_IRQHandler
        B EXTIE_IRQHandler
        
        
         PUBWEAK EXTIF_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EXTIF_IRQHandler
        B EXTIF_IRQHandler
        
        
         PUBWEAK I2C0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C0_IRQHandler
        B I2C0_IRQHandler


         PUBWEAK I2C1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2C1_IRQHandler
        B I2C1_IRQHandler


         PUBWEAK I2CSMB0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2CSMB0_IRQHandler
        B I2CSMB0_IRQHandler


         PUBWEAK I2CSMB1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2CSMB1_IRQHandler
        B I2CSMB1_IRQHandler


         PUBWEAK I2CSMB2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
I2CSMB2_IRQHandler
        B I2CSMB2_IRQHandler


         PUBWEAK CCL_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CCL_IRQHandler
        B CCL_IRQHandler


         PUBWEAK AES_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
AES_IRQHandler
        B AES_IRQHandler


         PUBWEAK DMA_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
DMA_IRQHandler
        B DMA_IRQHandler


         PUBWEAK WKUPX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
WKUPX_IRQHandler
        B WKUPX_IRQHandler


         PUBWEAK LUT_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LUT_IRQHandler
        B LUT_IRQHandler


         PUBWEAK COMPX_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
COMPX_IRQHandler
        B COMPX_IRQHandler


         PUBWEAK CAN_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
CAN_IRQHandler
        B CAN_IRQHandler


         PUBWEAK FDCAN_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
FDCAN_IRQHandler
        B FDCAN_IRQHandler


         PUBWEAK LPTIM16_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
LPTIM16_IRQHandler
        B LPTIM16_IRQHandler


         PUBWEAK BSTIM16_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
BSTIM16_IRQHandler
        B BSTIM16_IRQHandler


         PUBWEAK ATIM0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ATIM0_IRQHandler
        B ATIM0_IRQHandler


         PUBWEAK ATIM1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
ATIM1_IRQHandler
        B ATIM1_IRQHandler


         PUBWEAK GPTIM0_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
GPTIM0_IRQHandler
        B GPTIM0_IRQHandler


         PUBWEAK GPTIM1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
GPTIM1_IRQHandler
        B GPTIM1_IRQHandler


         PUBWEAK GPTIM2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
GPTIM2_IRQHandler
        B GPTIM2_IRQHandler


         PUBWEAK EPWM1_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM1_IRQHandler
        B EPWM1_IRQHandler


         PUBWEAK EPWM1_TZ_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM1_TZ_IRQHandler
        B EPWM1_TZ_IRQHandler


         PUBWEAK EPWM2_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM2_IRQHandler
        B EPWM2_IRQHandler


         PUBWEAK EPWM2_TZ_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM2_TZ_IRQHandler
        B EPWM2_TZ_IRQHandler


         PUBWEAK EPWM3_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM3_IRQHandler
        B EPWM3_IRQHandler


         PUBWEAK EPWM3_TZ_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM3_TZ_IRQHandler
        B EPWM3_TZ_IRQHandler


         PUBWEAK EPWM4_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM4_IRQHandler
        B EPWM4_IRQHandler


         PUBWEAK EPWM4_TZ_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPWM4_TZ_IRQHandler
        B EPWM4_TZ_IRQHandler


         PUBWEAK FPU_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
FPU_IRQHandler
        B FPU_IRQHandler


         PUBWEAK USB_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
USB_IRQHandler
        B USB_IRQHandler


         PUBWEAK EPSC_IRQHandler
        SECTION .text:CODE:NOROOT:REORDER(1)
EPSC_IRQHandler
        B EPSC_IRQHandler
        END