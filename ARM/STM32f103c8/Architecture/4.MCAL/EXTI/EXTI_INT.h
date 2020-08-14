/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	8/8/2020									*/
/**	Description	:	External Interrupt Interface file			*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/

#ifndef EXTI_INT_H_
#define EXTI_INT_H_

typedef enum
{
	EXTI0	,
	EXTI1	,
	EXTI2	,
	EXTI3	,
	EXTI4	,
	EXTI5	,
	EXTI6	,
	EXTI7	,
	EXTI8	,
	EXTI9	,
	EXTI10	,
	EXTI11	,
	EXTI12	,
	EXTI13	,
	EXTI14	,
	EXTI15	,
	EXTI16_PVD		,
	EXTI17_RTC_Alarm	,
	EXTI18_USB_Wakeup
}tdefEXTINo;

#define EXTI_ENABLE 	1
#define EXTI_DISABLE 0


typedef enum
{
	EXTIDisable,
	EXTIEnable
}tdefEXTIEn;

void EXTI_vidInit(void);
void EXTI_vidSetInterruptMask(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn);
void EXTI_vidSetEventMask(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn);
void EXTI_vidSetFallingTriggerSelection(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn);
void EXTI_vidSetRisingTriggerSelection(tdefEXTINo enuEXTINoCpy,tdefEXTIEn enuEXTIEn);
void EXTI_vidSetSoftwareInterruptEvent(tdefEXTINo enuEXTINoCpy);
void EXTI_vidClearPending(tdefEXTINo enuEXTINoCpy);
void EXTI_vidSetCallbackFunction(tdefEXTINo enuEXTINoCpy,vidpfvid pfCallbackCpy);
u8 EXTI_u8GetPending(tdefEXTINo enuEXTINoCpy);

#endif /* EXTI_INT_H_ */
