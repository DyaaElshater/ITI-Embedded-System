/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 16/7/2020											*/
/** Description	: NVIC Implementation file							*/
/** MCU			: STM32F103C8										*/
/** Version 	: 1.0V												*/
/********************************************************************/

#include "Std_types.h"
#include "Bit_Math.h"

#include "NVIC_INT.h"
#include "NVIC_CFG.h"
#include "NVIC_PRIV.h"



void NVIC_vidInit(void)
{
#if NVIC_SW_TRIGGER_INT == NVIC_ENABLE
	SET_BIT(SCB->SCR,SEVEONPEND);
#else
#endif


	NVIC->ISER[0] = conc32(NVIC_ENABLE_I2C1_EV,NVIC_ENABLE_TIM4,NVIC_ENABLE_TIM3,NVIC_ENABLE_TIM2,NVIC_ENABLE_TIM1_CC,NVIC_ENABLE_TIM1_TRG_COM,NVIC_ENABLE_TIM1_UP,NVIC_ENABLE_TIM1_BRK,NVIC_ENABLE_EXTI9_5,NVIC_ENABLE_CAN_SCE,NVIC_ENABLE_CAN_RX1,NVIC_ENABLE_USB_LP_CAN_RX0,NVIC_ENABLE_USB_HP_CAN_TX,NVIC_ENABLE_ADC1_2,NVIC_ENABLE_DMA1_Channel7,NVIC_ENABLE_DMA1_Channel6,NVIC_ENABLE_DMA1_Channel5,NVIC_ENABLE_DMA1_Channel4,NVIC_ENABLE_DMA1_Channel3,NVIC_ENABLE_DMA1_Channel2,NVIC_ENABLE_DMA1_Channel1,NVIC_ENABLE_EXTI4,NVIC_ENABLE_EXTI3,NVIC_ENABLE_EXTI2,NVIC_ENABLE_EXTI1,NVIC_ENABLE_EXTI0,NVIC_ENABLE_RCC,NVIC_ENABLE_FLASH,NVIC_ENABLE_RTC,NVIC_ENABLE_TAMPER,NVIC_ENABLE_PVD,NVIC_ENABLE_WWDG);
	NVIC->ISER[1] = conc32(0,0,0,0,NVIC_ENABLE_DMA2_Channel_4_5,NVIC_ENABLE_DMA2_Channel3,NVIC_ENABLE_DMA2_Channel2,NVIC_ENABLE_DMA2_Channel1,NVIC_ENABLE_TIM7,NVIC_ENABLE_TIM6,NVIC_ENABLE_UART5,NVIC_ENABLE_UART4,NVIC_ENABLE_SPI3,NVIC_ENABLE_TIM5,NVIC_ENABLE_SDIO,NVIC_ENABLE_FSMC,NVIC_ENABLE_ADC3,NVIC_ENABLE_TIM8_CC,NVIC_ENABLE_TIM8_TRG_COM,NVIC_ENABLE_TIM8_UPv,NVIC_ENABLE_TIM8_BRK,NVIC_ENABLE_USBWakeup,NVIC_ENABLE_RTCAlarm,NVIC_ENABLE_EXTI15_10,NVIC_ENABLE_USART3,NVIC_ENABLE_USART2,NVIC_ENABLE_USART1,NVIC_ENABLE_SPI2,NVIC_ENABLE_SPI1,NVIC_ENABLE_I2C2_ER,NVIC_ENABLE_I2C2_EV,NVIC_ENABLE_I2C1_ER);

	u8 loc_u8Iteration;
	for(loc_u8Iteration/* N */=0;loc_u8Iteration<NO_INT;loc_u8Iteration++)
	{
		if (NVIC_Priority[loc_u8Iteration].peripheral<0)
		{
			NVIC_vidSetPriority(NVIC_Priority[loc_u8Iteration].peripheral,NVIC_Priority[loc_u8Iteration].priority);
		}
		else
		{
			NVIC->IPR[(NVIC_Priority[loc_u8Iteration].peripheral>>2)/*M*/]=NVIC_Priority[loc_u8Iteration].priority<<(8*(NVIC_Priority[loc_u8Iteration].peripheral&(0x3)))/*N mod 4*/ ;
		}
	}
}

void NVIC_vidSetEnable(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	SET_BIT(NVIC->ISER[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}
u8 NVIC_u8CheckEnable(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	return GET_BIT(NVIC->ISER[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}

void NVIC_vidClearEnable(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	SET_BIT(NVIC->ICER[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}

void NVIC_vidSetPending(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	SET_BIT(NVIC->ISPR[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}
u8 NVIC_u8CheckPending(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	return GET_BIT(NVIC->ISPR[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}

void NVIC_vidClearPending(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	SET_BIT(NVIC->ICPR[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}

u8 NVIC_u8CheckActive(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	return GET_BIT(NVIC->IABR[enuNvicPeripheralCpy>>5],(enuNvicPeripheralCpy&(0x1F)));
}

void NVIC_vidSetSoftwareTriggerInterrupt(tdefNvicPeripheral enuNvicPeripheralCpy)
{
	SET_BIT(SCB->CCR,USERSETMPEND)		;
	NVIC->STIR = enuNvicPeripheralCpy 	;
	CLEAR_BIT(SCB->CCR,USERSETMPEND)	;
}

void NVIC_vidSetPriority(tdefNvicPeripheral enuNvicPeripheralCpy,u8 u8PriorityValueCpy)
{
	if (enuNvicPeripheralCpy<-4)
	{
		SCB->SHPR[0] &= ~((u32)(0xF<<(8*(enuNvicPeripheralCpy+7)+4)));
		SCB->SHPR[0] |= (u8PriorityValueCpy<<(8*(enuNvicPeripheralCpy+7)+4));
	}
	else if (enuNvicPeripheralCpy==NVIC_SVCall)
	{
		SCB->SHPR[1] &= ~((u32)(0xF<<28));
		SCB->SHPR[1] |= u8PriorityValueCpy<<28	;
	}
	else if (enuNvicPeripheralCpy == NVIC_PendSV || enuNvicPeripheralCpy == NVIC_SysTick)
	{
		SCB->SHPR[2] &= ~((u32)(0xF<<(8*(enuNvicPeripheralCpy+4)+4)));
		SCB->SHPR[2] |= u8PriorityValueCpy<<(8*(enuNvicPeripheralCpy-3)+4);
	}
	else if (enuNvicPeripheralCpy == 4) {}
	else
	{
		NVIC->IPR[enuNvicPeripheralCpy>>2] &=~((u32)(0XF)<< (8*(enuNvicPeripheralCpy &0x3)));
		NVIC->IPR[enuNvicPeripheralCpy>>2] |= u8PriorityValueCpy << (8*(enuNvicPeripheralCpy &0x3));
	}
}
u8 	 NVIC_u8GetPriority (tdefNvicPeripheral enuNvicPeripheralCpy)
{
	u8 loc_u8ReturnValue = 0;
	if (enuNvicPeripheralCpy<3)
	{
		loc_u8ReturnValue= (u8)(SCB->SHPR[0]>>(8*enuNvicPeripheralCpy+4));
	}
	else if (enuNvicPeripheralCpy==3)
	{
		loc_u8ReturnValue = (u8)(SCB->SHPR[1]>>28)	;
	}
	else if (enuNvicPeripheralCpy == 5 || enuNvicPeripheralCpy == 6)
	{
		loc_u8ReturnValue = (u8)(SCB->SHPR[2]>>(8*(enuNvicPeripheralCpy-3)+4));
	}
	else if (enuNvicPeripheralCpy == 4) {}
	else
	{
		loc_u8ReturnValue = (u8)((NVIC->IPR[enuNvicPeripheralCpy>>2])>>(8*(enuNvicPeripheralCpy &0x3)));
	}
	return loc_u8ReturnValue ;
}

void NVIC_vidSetPending_NMI(void)
{
	SET_BIT(SCB->ICSR,NMIPENDSET);
}
void NVIC_vidSetPending_Pendsv(void)
{
	SET_BIT(SCB->ICSR,PENDSVSET);
}
void NVIC_vidClearPending_Pendsv(void)
{
	SET_BIT(SCB->ICSR,PENDSVCLR);
}
void NVIC_vidSetPending_Systick(void)
{
	SET_BIT(SCB->ICSR,PENDSTSET);
}
void NVIC_vidClearPending_Systick(void)
{
	SET_BIT(SCB->ICSR,PENDSTCLR);
}
void NVIC_vidSetPrimaskBit_DisableInterrupt(void)
{
	__asm__("CPSID i");
}
void NVIC_vidClearPrimaskBit_EnableInterrupt(void)
{
	__asm__("CPSIE i");
}

void NVIC_vidSetFaultMaskBit_DisableInterrupt(void)
{
	__asm__("CPSID f");
}
void NVIC_vidClearFaultMaskBit_EnableInterrupt(void)
{
	__asm__("CPSIE f");
}
