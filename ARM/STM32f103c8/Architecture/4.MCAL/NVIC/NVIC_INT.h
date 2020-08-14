/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 15/7/2020											*/
/** Description	: NVIC Implementation file							*/
/** MCU			: STM32F103C8										*/
/** Version 	: 1.0V												*/
/********************************************************************/

#ifndef NVIC_INT_H_
#define NVIC_INT_H_

typedef enum
{
	NVIC_Diaable ,
	NVIC_Enable
}tdefNvicEn;
typedef enum
{
	NVIC_MemManage=-7		,
	NVIC_BusFault			,
	NVIC_UsageFault			,
	NVIC_SVCall				,
	NVIC_DebugMonitor		,
	NVIC_PendSV				,
	NVIC_SysTick			,
    NVIC_WWDG	=0		    ,
    NVIC_PVD			    ,   
    NVIC_TAMPER			    ,
    NVIC_RTC			    ,   
    NVIC_FLASH			    ,
    NVIC_RCC			    ,   
    NVIC_EXTI0			    ,
    NVIC_EXTI1			    ,
    NVIC_EXTI2			    ,
    NVIC_EXTI3			    ,
    NVIC_EXTI4			    ,
    NVIC_DMA1_Channel1	    ,
    NVIC_DMA1_Channel2	    ,
    NVIC_DMA1_Channel3	    ,
    NVIC_DMA1_Channel4	    ,
    NVIC_DMA1_Channel5	    ,
    NVIC_DMA1_Channel6	    ,
    NVIC_DMA1_Channel7	    ,
    NVIC_ADC1_2			    ,
    NVIC_USB_HP_CAN_TX	    ,
    NVIC_USB_LP_CAN_RX0	    ,
    NVIC_CAN_RX1		    ,	
    NVIC_CAN_SCE		    ,	
    NVIC_EXTI9_5		    ,   
    NVIC_TIM1_BRK		    ,
    NVIC_TIM1_UP		    ,   
    NVIC_TIM1_TRG_COM	    ,
    NVIC_TIM1_CC		    ,   
    NVIC_TIM2			    ,
    NVIC_TIM3			    ,
    NVIC_TIM4			    ,   
    NVIC_I2C1_EV		    ,      
    NVIC_I2C1_ER		    ,   
    NVIC_I2C2_EV	        ,	
    NVIC_I2C2_ER	        ,	
    NVIC_SPI1			    ,
    NVIC_SPI2			    ,
    NVIC_USART1			    ,
    NVIC_USART2			    ,
    NVIC_USART3			    ,
    NVIC_EXTI15_10		    ,
    NVIC_RTCAlarm		    ,
    NVIC_USBWakeup		    ,
    NVIC_TIM8_BRK		    ,
    NVIC_TIM8_UPv		    ,
    NVIC_TIM8_TRG_COM	    ,
    NVIC_TIM8_CC	        ,	
    NVIC_ADC3			    ,
    NVIC_FSMC			    ,
    NVIC_SDIO			    ,
    NVIC_TIM5			    ,
    NVIC_SPI3			    ,
    NVIC_UART4			    ,
    NVIC_UART5			    ,
    NVIC_TIM6			    ,
    NVIC_TIM7			    ,
    NVIC_DMA2_Channel1	    ,
    NVIC_DMA2_Channel2	    ,
    NVIC_DMA2_Channel3	    ,
    NVIC_DMA2_Channel_4_5
}tdefNvicPeripheral;

#define NVIC_CFG_ENABLE		1
#define NVIC_CFG_DISABLE	0


typedef struct
{
	tdefNvicPeripheral peripheral ;
	u8 priority	;
}tdefNVICPriority;

void NVIC_vidInit(void);

void NVIC_vidSetEnable(tdefNvicPeripheral enuNvicPeripheralCpy);
u8 NVIC_u8CheckEnable(tdefNvicPeripheral enuNvicPeripheralCpy);

void NVIC_vidClearEnable(tdefNvicPeripheral enuNvicPeripheralCpy);

void NVIC_vidSetPending(tdefNvicPeripheral enuNvicPeripheralCpy);
u8 NVIC_u8CheckPending(tdefNvicPeripheral enuNvicPeripheralCpy);

void NVIC_vidClearPending(tdefNvicPeripheral enuNvicPeripheralCpy);

u8 NVIC_u8CheckActive(tdefNvicPeripheral enuNvicPeripheralCpy);

void NVIC_vidSetSoftwareTriggerInterrupt(tdefNvicPeripheral enuNvicPeripheralCpy);

void NVIC_vidSetPriority(tdefNvicPeripheral enuNvicPeripheralCpy,u8 u8PriorityValueCpy);
u8 	 NVIC_u8GetPriority (tdefNvicPeripheral enuNvicPeripheralCpy);

void NVIC_vidSetPending_NMI(void);
void NVIC_vidSetPending_Pendsv(void);
void NVIC_vidClearPending_Pendsv(void);
void NVIC_vidSetPending_Systick(void);
void NVIC_vidClearPending_Systick(void);

void NVIC_vidSetPrimaskBit(void);
void NVIC_vidClearPrimaskBit(void);
void NVIC_vidSetFaultMaskBit_DisableInterrupt(void);
void NVIC_vidClearFaultMaskBit_EnableInterrupt(void);

#endif /* NVIC_INT_H_ */
