/********************************************************************/
/** Name 		: Dyaa Elshater										*/
/** Date		: 15/7/2020											*/
/** Description	: EXTI Private file									*/
/** MCU			: STM32F103C8										*/
/** Version 	: 1.0V												*/
/********************************************************************/

#ifndef NVIC_PRIV_H_
#define NVIC_PRIV_H_

typedef struct
{
	u32 ISER[3] 	;	/*	Set Enable Register			*/
	u32 ICER[3] 	;	/*	Clear Enable Register		*/
	u32 ISPR[3] 	;	/*	Set Pending Register		*/
	u32 ICPR[3] 	;	/*	Clear Pending Register		*/
	u32 IABR[3] 	;	/*	Get Active Register			*/
	u32 IPR[21]  	;	/*	Interrupt Priority Register	*/
	u32 STIR  		;	/*	Software Trigger Register	*/
}NVIC_Rgisters;

NVIC_Rgisters *NVIC = (volatile NVIC_Rgisters*)(0xE000E100) ;

typedef struct
{
	u32 ACTLR;
	u32 ICSR;
	u32 VTOR;
	u32 AIRCR;
	u32 SCR;
	u32 CCR;
	u32 SHPR[3];
	u32 SHCRS;
	u32 CFSR;
	u32 HFSR;
	u32 MMAR;
	u32 BFAR;

}SCB_Register;

#define SCB ((volatile SCB_Register*)(0xE000E008))
/*
#define SCB_SCR		(*(volatile u32*)(0xE000ED10))
*/
#define SEVEONPEND	4

/*CCR*/
#define USERSETMPEND	1

/*ICSP*/
#define NMIPENDSET	31
#define PENDSVSET	28
#define PENDSVCLR	27
#define PENDSTSET	26
#define PENDSTCLR	25
#define ISRPENDING	22
#define RETOBASE	11
#define VECTACTIVE	0

typedef void (* const vidconstpfvid)(void);


#define NO_INT		67

/*Interrupt handler*/
#endif /* NVIC_PRIV_H_ */
