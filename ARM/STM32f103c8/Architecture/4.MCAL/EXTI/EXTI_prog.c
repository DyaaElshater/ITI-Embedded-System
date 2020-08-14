/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	8/8/2020									*/
/**	Description	:	External Interrupt Implementation file		*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/

#include "Bit_Math.h"
#include "Std_types.h"

#include "EXTI_INT.h"
#include "EXTI_CFG.h"
#include "EXTI_PRIV.h"


void EXTI_vidInit(void)
{
	u8 loc_u8Iteration;
	for(loc_u8Iteration=0;loc_u8Iteration<EXTI_NO;loc_u8Iteration++)
	{
		EXTI_CALLBACK[loc_u8Iteration]=_EXTI_Temp ;
	}
	/*Clearing All external interrupt pending*/
	EXTI->PR = 0XFFFFFFFF;
	/*Configure external interrupt falling trigger*/
	EXTI->FTSR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,
					EXTI19_FALLING_DETECTION_EN,EXTI18_FALLING_DETECTION_EN,EXTI17_FALLING_DETECTION_EN,EXTI16_FALLING_DETECTION_EN,
					EXTI15_FALLING_DETECTION_EN,EXTI14_FALLING_DETECTION_EN,EXTI13_FALLING_DETECTION_EN,EXTI12_FALLING_DETECTION_EN,
					EXTI11_FALLING_DETECTION_EN,EXTI10_FALLING_DETECTION_EN,EXTI9_FALLING_DETECTION_EN,EXTI8_FALLING_DETECTION_EN,
					EXTI7_FALLING_DETECTION_EN,EXTI6_FALLING_DETECTION_EN,EXTI5_FALLING_DETECTION_EN,EXTI4_FALLING_DETECTION_EN,
					EXTI3_FALLING_DETECTION_EN,EXTI2_FALLING_DETECTION_EN,EXTI1_FALLING_DETECTION_EN,EXTI0_FALLING_DETECTION_EN);
	/*Configure external interrupt rising trigger*/
	EXTI->RTSR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,
					EXTI19_RISING_DETECTION_EN,EXTI18_RISING_DETECTION_EN,EXTI17_RISING_DETECTION_EN,EXTI16_RISING_DETECTION_EN,
					EXTI15_RISING_DETECTION_EN,EXTI14_RISING_DETECTION_EN,EXTI13_RISING_DETECTION_EN,EXTI12_RISING_DETECTION_EN,
					EXTI11_RISING_DETECTION_EN,EXTI10_RISING_DETECTION_EN,EXTI9_RISING_DETECTION_EN,EXTI8_RISING_DETECTION_EN,
					EXTI7_RISING_DETECTION_EN,EXTI6_RISING_DETECTION_EN,EXTI5_RISING_DETECTION_EN,EXTI4_RISING_DETECTION_EN,
					EXTI3_RISING_DETECTION_EN,EXTI2_RISING_DETECTION_EN,EXTI1_RISING_DETECTION_EN,EXTI0_RISING_DETECTION_EN);
	/*Configure external interrupt Mask*/
	EXTI->IMR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,
					EXTI19_IMR_EN,EXTI18_IMR_EN,EXTI17_IMR_EN,EXTI16_IMR_EN,
					EXTI15_IMR_EN,EXTI14_IMR_EN,EXTI13_IMR_EN,EXTI12_IMR_EN,
					EXTI11_IMR_EN,EXTI10_IMR_EN,EXTI9_IMR_EN,EXTI8_IMR_EN,
					EXTI7_IMR_EN,EXTI6_IMR_EN,EXTI5_IMR_EN,EXTI4_IMR_EN,
					EXTI3_IMR_EN,EXTI2_IMR_EN,EXTI1_IMR_EN,EXTI0_IMR_EN);
	/*Configure external event Mask*/
	EXTI->EMR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,
					EXTI19_EMR_EN,EXTI18_EMR_EN,EXTI17_EMR_EN,EXTI16_EMR_EN,
					EXTI15_EMR_EN,EXTI14_EMR_EN,EXTI13_EMR_EN,EXTI12_EMR_EN,
					EXTI11_EMR_EN,EXTI10_EMR_EN,EXTI9_EMR_EN,EXTI8_EMR_EN,
					EXTI7_EMR_EN,EXTI6_EMR_EN,EXTI5_EMR_EN,EXTI4_EMR_EN,
					EXTI3_EMR_EN,EXTI2_EMR_EN,EXTI1_EMR_EN,EXTI0_EMR_EN);
}
void EXTI_vidSetInterruptMask(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn)
{
	CLEAR_BIT(EXTI->IMR,enuEXTINoCpy);
	EXTI->IMR |= enuEXTIEn << enuEXTINoCpy ;
}
void EXTI_vidSetEventMask(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn)
{
	CLEAR_BIT(EXTI->EMR,enuEXTINoCpy);
	EXTI->EMR |= enuEXTIEn << enuEXTINoCpy ;
}
void EXTI_vidSetFallingTriggerSelection(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn)
{
	CLEAR_BIT(EXTI->FTSR,enuEXTINoCpy);
	EXTI->FTSR |= enuEXTIEn << enuEXTINoCpy ;
}
void EXTI_vidSetRisingTriggerSelection(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn)
{
	CLEAR_BIT(EXTI->RTSR,enuEXTINoCpy);
	EXTI->RTSR |= enuEXTIEn << enuEXTINoCpy ;
}
void EXTI_vidSetSoftwareInterruptEvent(tdefEXTINo enuEXTINoCpy)
{
	SET_BIT(EXTI->SWIER,enuEXTINoCpy);
}
void EXTI_vidClearPending(tdefEXTINo enuEXTINoCpy)
{
	SET_BIT(EXTI->PR,enuEXTINoCpy);
}
u8 EXTI_u8GetPending(tdefEXTINo enuEXTINoCpy)
{
	return GET_BIT(EXTI->PR,enuEXTINoCpy);
}

void EXTI_vidSetCallbackFunction(tdefEXTINo enuEXTINoCpy,vidpfvid pfCallbackCpy)
{
	EXTI_CALLBACK[enuEXTINoCpy]=pfCallbackCpy;
}


/*EXTI ISR*/

void EXTI0_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI0);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI0]();
}

void EXTI1_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI1);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI1]();
}
void EXTI2_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI2);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI2]();
}
void EXTI3_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI3);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI3]();
}
void EXTI4_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI4);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI4]();
}
void EXTI9_5_IRQHandler(void)
{
	if(EXTI->PR &32)	/*EXTI 5*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI5);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI5]();
	}
	else if (EXTI->PR &64)/*EXTI 6*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI6);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI6]();
	}
	else if(EXTI->PR &128)/*EXTI 7*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI7);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI7]();
	}
	else if(EXTI->PR &256)/*EXTI 8*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI8);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI8]();
	}
	else				/*EXTI 9*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI9);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI9]();
	}
}
void EXTI15_10_IRQHandler(void)
{
	if(EXTI->PR &1024)	/*EXTI 10*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI10);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI10]();
	}
	else if (EXTI->PR &2048)/*EXTI 11*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI11);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI11]();
	}
	else if(EXTI->PR &4096)/*EXTI 12*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI12);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI12]();
	}
	else if(EXTI->PR &8192)/*EXTI 13*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI13);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI13]();
	}
	else if(EXTI->PR &16384)/*EXTI 14*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI14);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI14]();
	}
	else				/*EXTI 15*/
	{
		/*Clear Pending*/
		SET_BIT(EXTI->PR,EXTI15);
		/*Excuting Callback function*/
		EXTI_CALLBACK[EXTI15]();
	}
}
void PVD_IRQHandler (void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI16_PVD);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI16_PVD]();
}
void RTC_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI17_RTC_Alarm);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI17_RTC_Alarm]();
}
void USBWakeUp_IRQHandler(void)
{
	/*Clear Pending*/
	SET_BIT(EXTI->PR,EXTI18_USB_Wakeup);
	/*Excuting Callback function*/
	EXTI_CALLBACK[EXTI18_USB_Wakeup]();
}

