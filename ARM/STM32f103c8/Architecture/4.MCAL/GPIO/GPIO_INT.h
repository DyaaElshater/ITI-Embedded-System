/*
 * GPIO_INT.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Dyaa Elshater
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_

/*************************************/
		/*Port A*/
#define GPIO_u8RA_0		0
#define GPIO_u8RA_1		1
#define GPIO_u8RA_2		2
#define GPIO_u8RA_3		3
#define GPIO_u8RA_4		4
#define GPIO_u8RA_5		5
#define GPIO_u8RA_6		6
#define GPIO_u8RA_7		7
#define GPIO_u8RA_8		8
#define GPIO_u8RA_9		9
#define GPIO_u8RA_10	10
#define GPIO_u8RA_11	11
#define GPIO_u8RA_12	12
#define GPIO_u8RA_13	13
#define GPIO_u8RA_14	14
#define GPIO_u8RA_15	15
		/*Port B*/
#define GPIO_u8RB_0		0
#define GPIO_u8RB_1		1
#define GPIO_u8RB_2		2
#define GPIO_u8RB_3		3
#define GPIO_u8RB_4		4
#define GPIO_u8RB_5		5
#define GPIO_u8RB_6		6
#define GPIO_u8RB_7		7
#define GPIO_u8RB_8		8
#define GPIO_u8RB_9		9
#define GPIO_u8RB_10	10
#define GPIO_u8RB_11	11
#define GPIO_u8RB_12	12
#define GPIO_u8RB_13	13
#define GPIO_u8RB_14	14
#define GPIO_u8RB_15	15
		/*Port C*/
#define GPIO_u8RC_0		0
#define GPIO_u8RC_1		1
#define GPIO_u8RC_2		2
#define GPIO_u8RC_3		3
#define GPIO_u8RC_4		4
#define GPIO_u8RC_5		5
#define GPIO_u8RC_6		6
#define GPIO_u8RC_7		7
#define GPIO_u8RC_8		8
#define GPIO_u8RC_9		9
#define GPIO_u8RC_10	10
#define GPIO_u8RC_11	11
#define GPIO_u8RC_12	12
#define GPIO_u8RC_13	13
#define GPIO_u8RC_14	14
#define GPIO_u8RC_15	15
		/*Port D*/
#define GPIO_u8RD_0		0
#define GPIO_u8RD_1		1
#define GPIO_u8RD_2		2
#define GPIO_u8RD_3		3
#define GPIO_u8RD_4		4
#define GPIO_u8RD_5		5
#define GPIO_u8RD_6		6
#define GPIO_u8RD_7		7
#define GPIO_u8RD_8		8
#define GPIO_u8RD_9		9
#define GPIO_u8RD_10	10
#define GPIO_u8RD_11	11
#define GPIO_u8RD_12	12
#define GPIO_u8RD_13	13
#define GPIO_u8RD_14	14
#define GPIO_u8RD_15	15
		/*Port E*/
#define GPIO_u8RE_0		0
#define GPIO_u8RE_1		1
#define GPIO_u8RE_2		2
#define GPIO_u8RE_3		3
#define GPIO_u8RE_4		4
#define GPIO_u8RE_5		5
#define GPIO_u8RE_6		6
#define GPIO_u8RE_7		7
#define GPIO_u8RE_8		8
#define GPIO_u8RE_9		9
#define GPIO_u8RE_10	10
#define GPIO_u8RE_11	11
#define GPIO_u8RE_12	12
#define GPIO_u8RE_13	13
#define GPIO_u8RE_14	14
#define GPIO_u8RE_15	15
		/*Port F*/
#define GPIO_u8RF_0		0
#define GPIO_u8RF_1		1
#define GPIO_u8RF_2		2
#define GPIO_u8RF_3		3
#define GPIO_u8RF_4		4
#define GPIO_u8RF_5		5
#define GPIO_u8RF_6		6
#define GPIO_u8RF_7		7
#define GPIO_u8RF_8		8
#define GPIO_u8RF_9		9
#define GPIO_u8RF_10	10
#define GPIO_u8RF_11	11
#define GPIO_u8RF_12	12
#define GPIO_u8RF_13	13
#define GPIO_u8RF_14	14
#define GPIO_u8RF_15	15
		/*Port G*/
#define GPIO_u8RG_0		0
#define GPIO_u8RG_1		1
#define GPIO_u8RG_2		2
#define GPIO_u8RG_3		3
#define GPIO_u8RG_4		4
#define GPIO_u8RG_5		5
#define GPIO_u8RG_6		6
#define GPIO_u8RG_7		7
#define GPIO_u8RG_8		8
#define GPIO_u8RG_9		9
#define GPIO_u8RG_10	10
#define GPIO_u8RG_11	11
#define GPIO_u8RG_12	12
#define GPIO_u8RG_13	13
#define GPIO_u8RG_14	14
#define GPIO_u8RG_15	15

/*************************************/

#define GPIO_u8OUTPUT					1
#define GPIO_u8OUTPUT_OPEN_DRAIN		3
#define GPIO_u8OUTPUT_AFO				5
#define GPIO_u8OUTPUT_AFO_OPEN_DRAIN	7
#define GPIO_u8INPUT					0
#define GPIO_u8INPUT_PUL_UP				2
#define GPIO_u8INPUT_FLOATING			4

#define GPIO_u8OUTPUT	1
#define GPIO_u8INPUT	0

#define GPIO_INPUT_ANALOG				0000
#define GPIO_INPUT_FLOATING				0100
#define GPIO_INPUT_PULL_UP_DOWN			1000

#define GPIO_OUTPUT_PUSH_PULL_10MHZ		0001
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ	0101
#define GPIO_AF_PUSH_PULL_10MHZ			1001
#define GPIO_AF_OPEN_DRAIN_10MHZ		1101

#define GPIO_OUTPUT_PUSH_PULL_2MHZ		0010
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ		0110
#define GPIO_AF_PUSH_PULL_2MHZ			1010
#define GPIO_AF_OPEN_DRAIN_2MHZ			1110

#define GPIO_OUTPUT_PUSH_PULL_50MHZ		0011
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ	0111
#define GPIO_AF_PUSH_PULL_50MHZ			1011
#define GPIO_AF_OPEN_DRAIN_50MHZ		1111

#define GPIO_PULL_UP					1
#define GPIO_PULL_DOWN					0

#define GPIO_u8HIGH		1
#define GPIO_u8LOW		0


typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIO_Register;


static volatile GPIO_Register * const GPIOA = (volatile GPIO_Register*)(0x40010800);
static volatile GPIO_Register * const GPIOB = (volatile GPIO_Register*)(0x40010C00);
static volatile GPIO_Register * const GPIOC = (volatile GPIO_Register*)(0x40011000);
static volatile GPIO_Register * const GPIOD = (volatile GPIO_Register*)(0x40011400);
static volatile GPIO_Register * const GPIOE = (volatile GPIO_Register*)(0x40011800);
static volatile GPIO_Register * const GPIOF = (volatile GPIO_Register*)(0x40011C00);
static volatile GPIO_Register * const GPIOG = (volatile GPIO_Register*)(0x40012000);





/****************************************************/
/** Descrption	: intialization function to GPIO and	*/
/* determine the dirction of all pins				*/
/****************************************************/

void GPIO_vidInit(void);
/****************************************************/
/** Descrption	: Finction used to set pin in		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins foom 0 to 31	*/
/*			 u8ValueCpy value mean GPIO_u8HIGH 		*/
/*							or GPIO_u8LOW			*/
/****************************************************/

void GPIO_vidSetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy ,u8 u8ValueCpy);

/****************************************************/
/** Descrption	: Finction used to get pin from		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : it return the pin Value 				*/
/****************************************************/

void GPIO_vidGetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy,u8*pu8PinValueCpy);

/****************************************************/
/** Descrption	: Finction used to set the pin 		*/
/* direction .						   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidSetPinDirection(GPIO_Register* pstPortCpy ,u8 u8pinNbCpy, u8 u8PinStateCpy);

/****************************************************/
/** Descrption	: Finction used to toggle the pin .	*/
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status 							*/
/****************************************************/

void GPIO_vidTogglePin (GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);

/****************************************************/
/** Descrption	: Finction used to make pull up .	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullUp(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);

/****************************************************/
/** Descrption	: Finction used to make pull Down.	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullDown(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);


/****************************************************/
/** Descrption:Function used to get pin value		*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/
u8 GPIO_u8GetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);

#endif /* GPIO_INT_H_ */
