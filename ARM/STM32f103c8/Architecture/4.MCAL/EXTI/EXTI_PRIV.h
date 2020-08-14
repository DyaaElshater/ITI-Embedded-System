/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	8/8/2020									*/
/**	Description	:	External Interrupt Private file				*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/

#ifndef EXTI_PRIV_H_
#define EXTI_PRIV_H_

typedef struct
{
	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_Register;

#define EXTI ((volatile EXTI_Register*)(0x40010400))

#define EXTI_NO	19
void _EXTI_Temp(void){}
vidpfvid EXTI_CALLBACK[EXTI_NO];
#endif /* EXTI_PRIV_H_ */
