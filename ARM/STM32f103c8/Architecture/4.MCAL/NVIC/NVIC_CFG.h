/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 15/7/2020											*/
/** Description	: NVIC Configuration file							*/
/** MCU			: STM32F103C8										*/
/** Version 	: 1.0V												*/
/********************************************************************/

#ifndef NVIC_CFG_H_
#define NVIC_CFG_H_

/**	Configure the Interrupt mask for each interrupt					*/
/*		NVIC_(peripheral)		:									*/
/*								  -	NVIC_CFG_DISABLE 				*/
/*								  -	NVIC_CFG_ENABLE					*/
#define NVIC_ENABLE_WWDG				NVIC_CFG_DISABLE
#define NVIC_ENABLE_PVD			    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_TAMPER				NVIC_CFG_DISABLE
#define NVIC_ENABLE_RTC			    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_FLASH				NVIC_CFG_DISABLE
#define NVIC_ENABLE_RCC			    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_SDIO				NVIC_CFG_DISABLE
#define NVIC_ENABLE_RTCAlarm			NVIC_CFG_DISABLE
#define NVIC_ENABLE_FSMC				NVIC_CFG_DISABLE
		/*External Interrupt*/
#define NVIC_ENABLE_EXTI0				NVIC_CFG_DISABLE
#define NVIC_ENABLE_EXTI1				NVIC_CFG_DISABLE
#define NVIC_ENABLE_EXTI2				NVIC_CFG_DISABLE
#define NVIC_ENABLE_EXTI3				NVIC_CFG_DISABLE
#define NVIC_ENABLE_EXTI4				NVIC_CFG_DISABLE
#define NVIC_ENABLE_EXTI9_5		    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_EXTI15_10			NVIC_CFG_DISABLE
		/*Timer*/
#define NVIC_ENABLE_TIM1_BRK			NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM1_UP		    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM1_TRG_COM		NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM1_CC		    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM2				NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM3				NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM4				NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM5				NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM6				NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM7				NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM8_BRK			NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM8_UPv			NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM8_TRG_COM		NVIC_CFG_DISABLE
#define NVIC_ENABLE_TIM8_CC	    		NVIC_CFG_DISABLE
		/*ADC*/
#define NVIC_ENABLE_ADC1_2				NVIC_CFG_DISABLE
#define NVIC_ENABLE_ADC3				NVIC_CFG_DISABLE
		/*DMA*/
#define NVIC_ENABLE_DMA1_Channel1		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA1_Channel2		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA1_Channel3		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA1_Channel4		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA1_Channel5		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA1_Channel6		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA1_Channel7		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA2_Channel1		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA2_Channel2		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA2_Channel3		NVIC_CFG_DISABLE
#define NVIC_ENABLE_DMA2_Channel_4_5	NVIC_CFG_DISABLE
		/**Communication Protocols**/
			/*UART*/
#define NVIC_ENABLE_USART1				NVIC_CFG_DISABLE
#define NVIC_ENABLE_USART2				NVIC_CFG_DISABLE
#define NVIC_ENABLE_USART3				NVIC_CFG_DISABLE
#define NVIC_ENABLE_UART4				NVIC_CFG_DISABLE
#define NVIC_ENABLE_UART5				NVIC_CFG_DISABLE
			/*SPI*/
#define NVIC_ENABLE_SPI1				NVIC_CFG_DISABLE
#define NVIC_ENABLE_SPI2				NVIC_CFG_DISABLE
#define NVIC_ENABLE_SPI3				NVIC_CFG_DISABLE
			/*I2C*/
#define NVIC_ENABLE_I2C1_EV		    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_I2C1_ER		    	NVIC_CFG_DISABLE
#define NVIC_ENABLE_I2C2_EV	    		NVIC_CFG_DISABLE
#define NVIC_ENABLE_I2C2_ER	    		NVIC_CFG_DISABLE
			/*CAN*/
#define NVIC_ENABLE_CAN_RX1			    NVIC_CFG_DISABLE
#define NVIC_ENABLE_CAN_SCE			    NVIC_CFG_DISABLE
			/*USB*/
#define NVIC_ENABLE_USB_HP_CAN_TX		NVIC_CFG_DISABLE
#define NVIC_ENABLE_USB_LP_CAN_RX0		NVIC_CFG_DISABLE
#define NVIC_ENABLE_USBWakeup			NVIC_CFG_DISABLE


/** Configure the Peripheral interrupt priority							*/
/*	{ NVIC_(peripheral) , (priority 0 -> 15 )   }						*/
tdefNVICPriority NVIC_Priority[]=
{
	   { NVIC_MemManage				, 15         }   ,
	   { NVIC_BusFault				, 15         }   ,
	   { NVIC_UsageFault			, 15         }   ,
	   { NVIC_SVCall				, 15         }   ,
	   { NVIC_DebugMonitor			, 15         }   ,
	   { NVIC_PendSV				, 15         }   ,
	   { NVIC_SysTick				, 15         }   ,
       { NVIC_WWDG		            , 15         }   ,
       { NVIC_PVD			        , 15         }   ,
       { NVIC_TAMPER		        , 15         }   ,
       { NVIC_RTC			        , 15         }   ,
       { NVIC_FLASH			        , 15         }   ,
       { NVIC_RCC			        , 15         }   ,
       { NVIC_EXTI0			        , 4         }   ,
       { NVIC_EXTI1			        , 15         }   ,
       { NVIC_EXTI2			        , 15         }   ,
       { NVIC_EXTI3			        , 15         }   ,
       { NVIC_EXTI4			        , 15         }   ,
       { NVIC_DMA1_Channel1         , 15         }   ,
       { NVIC_DMA1_Channel2         , 15         }   ,
       { NVIC_DMA1_Channel3         , 15         }   ,
       { NVIC_DMA1_Channel4         , 15         }   ,
       { NVIC_DMA1_Channel5         , 15         }   ,
       { NVIC_DMA1_Channel6         , 15         }   ,
       { NVIC_DMA1_Channel7         , 15         }   ,
       { NVIC_ADC1_2		        , 15         }   ,    
       { NVIC_USB_HP_CAN_TX         , 15         }   ,
       { NVIC_USB_LP_CAN_RX0        , 15         }   ,
       { NVIC_CAN_RX1		        , 15         }   , 
       { NVIC_CAN_SCE		        , 15         }   , 
       { NVIC_EXTI9_5		        , 15         }   , 
       { NVIC_TIM1_BRK		        , 15         }   , 
       { NVIC_TIM1_UP		        , 15         }   , 
       { NVIC_TIM1_TRG_COM	        , 15         }   , 
       { NVIC_TIM1_CC		        , 15         }   , 
       { NVIC_TIM2			        , 15         }   , 
       { NVIC_TIM3			        , 15         }   , 
       { NVIC_TIM4			        , 15         }   , 
       { NVIC_I2C1_EV		        , 15         }   , 
       { NVIC_I2C1_ER		        , 15         }   , 
       { NVIC_I2C2_EV	            , 15         }   ,
       { NVIC_I2C2_ER	            , 15         }   ,
       { NVIC_SPI1			        , 15         }   , 
       { NVIC_SPI2			        , 15         }   , 
       { NVIC_USART1		        , 15         }   ,    
       { NVIC_USART2		        , 15         }   ,    
       { NVIC_USART3		        , 15         }   ,    
       { NVIC_EXTI15_10		        , 15         }   , 
       { NVIC_RTCAlarm		        , 15         }   , 
       { NVIC_USBWakeup		        , 15         }   , 
       { NVIC_TIM8_BRK		        , 15         }   , 
       { NVIC_TIM8_UPv		        , 15         }   , 
       { NVIC_TIM8_TRG_COM	        , 15         }   , 
       { NVIC_TIM8_CC	            , 15         }   ,
       { NVIC_ADC3			        , 15         }   , 
       { NVIC_FSMC			        , 15         }   , 
       { NVIC_SDIO			        , 15         }   , 
       { NVIC_TIM5			        , 15         }   , 
       { NVIC_SPI3			        , 15         }   , 
       { NVIC_UART4			        , 15         }   , 
       { NVIC_UART5			        , 15         }   , 
       { NVIC_TIM6			        , 15         }   , 
       { NVIC_TIM7			        , 15         }   , 
       { NVIC_DMA2_Channel1         , 15         }   ,
       { NVIC_DMA2_Channel2         , 15         }   ,
       { NVIC_DMA2_Channel3         , 15         }   ,
       { NVIC_DMA2_Channel_4_5      , 15         }
};


/** Configure the software trigger interrupt 						*/
/*			NVIC_SW_TRIGGER_INT		:						 		*/
/*										- NVIC_DISABLE				*/
/*										- NVIC_ENABLE				*/
#define NVIC_SW_TRIGGER_INT		NVIC_DISABLE

#endif /* NVIC_CFG_H_ */
