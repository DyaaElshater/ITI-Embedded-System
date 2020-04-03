/*
 * GPIO_prog.c
 *
 *  Created on: Oct 11, 2019
 *      Author: Dyaa Elshater
 */




#include "Bit_Math.h"
#include "Std_types.h"

#include "GPIO_INT.h"
#include "GPIO_CFG.h"
#include "GPIO_PRIV.h"



/****************************************************/
/** Descrption	: intialization function to GPIO and	*/
/* determine the dirction of all pins				*/
/****************************************************/

void GPIO_vidInit(void)
{
			/*GPIOA*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RA_15,GPIO_MODE_u8RA_14,GPIO_MODE_u8RA_13,
					   GPIO_MODE_u8RA_12,GPIO_MODE_u8RA_11,GPIO_MODE_u8RA_10,
					   GPIO_MODE_u8RA_9,GPIO_MODE_u8RA_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RA_7,GPIO_MODE_u8RA_6,GPIO_MODE_u8RA_5,
					   GPIO_MODE_u8RA_4,GPIO_MODE_u8RA_3,GPIO_MODE_u8RA_2,
					   GPIO_MODE_u8RA_1,GPIO_MODE_u8RA_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RA_15,GPIO_PUPD_u8RA_14,GPIO_PUPD_u8RA_13,
				  GPIO_PUPD_u8RA_12,GPIO_PUPD_u8RA_11,GPIO_PUPD_u8RA_10,
				  GPIO_PUPD_u8RA_9,GPIO_PUPD_u8RA_8,GPIO_PUPD_u8RA_7,
				  GPIO_PUPD_u8RA_6,GPIO_PUPD_u8RA_5,GPIO_PUPD_u8RA_4,
				  GPIO_PUPD_u8RA_3,GPIO_PUPD_u8RA_2,GPIO_PUPD_u8RA_1,
				  GPIO_PUPD_u8RA_0);

			/*GPIOB*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RB_15,GPIO_MODE_u8RB_14,GPIO_MODE_u8RB_13,
					   GPIO_MODE_u8RB_12,GPIO_MODE_u8RB_11,GPIO_MODE_u8RB_10,
					   GPIO_MODE_u8RB_9,GPIO_MODE_u8RB_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RB_7,GPIO_MODE_u8RB_6,GPIO_MODE_u8RB_5,
					   GPIO_MODE_u8RB_4,GPIO_MODE_u8RB_3,GPIO_MODE_u8RB_2,
					   GPIO_MODE_u8RB_1,GPIO_MODE_u8RB_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RB_15,GPIO_PUPD_u8RB_14,GPIO_PUPD_u8RB_13,
				  GPIO_PUPD_u8RB_12,GPIO_PUPD_u8RB_11,GPIO_PUPD_u8RB_10,
				  GPIO_PUPD_u8RB_9,GPIO_PUPD_u8RB_8,GPIO_PUPD_u8RB_7,
				  GPIO_PUPD_u8RB_6,GPIO_PUPD_u8RB_5,GPIO_PUPD_u8RB_4,
				  GPIO_PUPD_u8RB_3,GPIO_PUPD_u8RB_2,GPIO_PUPD_u8RB_1,
				  GPIO_PUPD_u8RB_0);

			/*GPIOC*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RC_15,GPIO_MODE_u8RC_14,GPIO_MODE_u8RC_13,
					   GPIO_MODE_u8RC_12,GPIO_MODE_u8RC_11,GPIO_MODE_u8RC_10,
					   GPIO_MODE_u8RC_9,GPIO_MODE_u8RC_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RC_7,GPIO_MODE_u8RC_6,GPIO_MODE_u8RC_5,
					   GPIO_MODE_u8RC_4,GPIO_MODE_u8RC_3,GPIO_MODE_u8RC_2,
					   GPIO_MODE_u8RC_1,GPIO_MODE_u8RC_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RC_15,GPIO_PUPD_u8RC_14,GPIO_PUPD_u8RC_13,
				  GPIO_PUPD_u8RC_12,GPIO_PUPD_u8RC_11,GPIO_PUPD_u8RC_10,
				  GPIO_PUPD_u8RC_9,GPIO_PUPD_u8RC_8,GPIO_PUPD_u8RC_7,
				  GPIO_PUPD_u8RC_6,GPIO_PUPD_u8RC_5,GPIO_PUPD_u8RC_4,
				  GPIO_PUPD_u8RC_3,GPIO_PUPD_u8RC_2,GPIO_PUPD_u8RC_1,
				  GPIO_PUPD_u8RC_0);

			/*GPIOD*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RD_15,GPIO_MODE_u8RD_14,GPIO_MODE_u8RD_13,
					   GPIO_MODE_u8RD_12,GPIO_MODE_u8RD_11,GPIO_MODE_u8RD_10,
					   GPIO_MODE_u8RD_9,GPIO_MODE_u8RD_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RD_7,GPIO_MODE_u8RD_6,GPIO_MODE_u8RD_5,
					   GPIO_MODE_u8RD_4,GPIO_MODE_u8RD_3,GPIO_MODE_u8RD_2,
					   GPIO_MODE_u8RD_1,GPIO_MODE_u8RD_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RD_15,GPIO_PUPD_u8RD_14,GPIO_PUPD_u8RD_13,
				  GPIO_PUPD_u8RD_12,GPIO_PUPD_u8RD_11,GPIO_PUPD_u8RD_10,
				  GPIO_PUPD_u8RD_9,GPIO_PUPD_u8RD_8,GPIO_PUPD_u8RD_7,
				  GPIO_PUPD_u8RD_6,GPIO_PUPD_u8RD_5,GPIO_PUPD_u8RD_4,
				  GPIO_PUPD_u8RD_3,GPIO_PUPD_u8RD_2,GPIO_PUPD_u8RD_1,
				  GPIO_PUPD_u8RD_0);

			/*GPIOE*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RE_15,GPIO_MODE_u8RE_14,GPIO_MODE_u8RE_13,
					   GPIO_MODE_u8RE_12,GPIO_MODE_u8RE_11,GPIO_MODE_u8RE_10,
					   GPIO_MODE_u8RE_9,GPIO_MODE_u8RE_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RE_7,GPIO_MODE_u8RE_6,GPIO_MODE_u8RE_5,
					   GPIO_MODE_u8RE_4,GPIO_MODE_u8RE_3,GPIO_MODE_u8RE_2,
					   GPIO_MODE_u8RE_1,GPIO_MODE_u8RE_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RE_15,GPIO_PUPD_u8RE_14,GPIO_PUPD_u8RE_13,
				  GPIO_PUPD_u8RE_12,GPIO_PUPD_u8RE_11,GPIO_PUPD_u8RE_10,
				  GPIO_PUPD_u8RE_9,GPIO_PUPD_u8RE_8,GPIO_PUPD_u8RE_7,
				  GPIO_PUPD_u8RE_6,GPIO_PUPD_u8RE_5,GPIO_PUPD_u8RE_4,
				  GPIO_PUPD_u8RE_3,GPIO_PUPD_u8RE_2,GPIO_PUPD_u8RE_1,
				  GPIO_PUPD_u8RE_0);

			/*GPIOF*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RF_15,GPIO_MODE_u8RF_14,GPIO_MODE_u8RF_13,
					   GPIO_MODE_u8RF_12,GPIO_MODE_u8RF_11,GPIO_MODE_u8RF_10,
					   GPIO_MODE_u8RF_9,GPIO_MODE_u8RF_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RF_7,GPIO_MODE_u8RF_6,GPIO_MODE_u8RF_5,
					   GPIO_MODE_u8RF_4,GPIO_MODE_u8RF_3,GPIO_MODE_u8RF_2,
					   GPIO_MODE_u8RF_1,GPIO_MODE_u8RF_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RF_15,GPIO_PUPD_u8RF_14,GPIO_PUPD_u8RF_13,
				  GPIO_PUPD_u8RF_12,GPIO_PUPD_u8RF_11,GPIO_PUPD_u8RF_10,
				  GPIO_PUPD_u8RF_9,GPIO_PUPD_u8RF_8,GPIO_PUPD_u8RF_7,
				  GPIO_PUPD_u8RF_6,GPIO_PUPD_u8RF_5,GPIO_PUPD_u8RF_4,
				  GPIO_PUPD_u8RF_3,GPIO_PUPD_u8RF_2,GPIO_PUPD_u8RF_1,
				  GPIO_PUPD_u8RF_0);

			/*GPIOG*/
	GPIOA->CRH = conc8(GPIO_MODE_u8RG_15,GPIO_MODE_u8RG_14,GPIO_MODE_u8RG_13,
					   GPIO_MODE_u8RG_12,GPIO_MODE_u8RG_11,GPIO_MODE_u8RG_10,
					   GPIO_MODE_u8RG_9,GPIO_MODE_u8RG_8);
	GPIOA->CRL = conc8(GPIO_MODE_u8RG_7,GPIO_MODE_u8RG_6,GPIO_MODE_u8RG_5,
					   GPIO_MODE_u8RG_4,GPIO_MODE_u8RG_3,GPIO_MODE_u8RG_2,
					   GPIO_MODE_u8RG_1,GPIO_MODE_u8RG_0);
			/*FOR PULL up / down*/
	GPIOA->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RG_15,GPIO_PUPD_u8RG_14,GPIO_PUPD_u8RG_13,
				  GPIO_PUPD_u8RG_12,GPIO_PUPD_u8RG_11,GPIO_PUPD_u8RG_10,
				  GPIO_PUPD_u8RG_9,GPIO_PUPD_u8RG_8,GPIO_PUPD_u8RG_7,
				  GPIO_PUPD_u8RG_6,GPIO_PUPD_u8RG_5,GPIO_PUPD_u8RG_4,
				  GPIO_PUPD_u8RG_3,GPIO_PUPD_u8RG_2,GPIO_PUPD_u8RG_1,
				  GPIO_PUPD_u8RG_0);

}

/****************************************************/
/** Descrption	: Finction used to set pin in		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins foom 0 to 15	*/
/*			 u8ValueCpy value mean GPIO_u8HIGH 		*/
/*							or GPIO_u8LOW			*/
/****************************************************/

void GPIO_vidSetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy ,u8 u8ValueCpy)
{

			if(u8ValueCpy == GPIO_u8HIGH)
			{
				SET_BIT(pstPortCpy->BSRR,u8PinNbCpy);
			}
			else
			{
				SET_BIT(pstPortCpy->BRR,u8PinNbCpy);
			}
}

/****************************************************/
/** Descrption	: Finction used to get pin from		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 15	*/
/** Output : it return the pin Value 				*/
/****************************************************/

u8 GPIO_u8GetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy)
{
	return GET_BIT(pstPortCpy->IDR,u8PinNbCpy);
}

/****************************************************/
/** Descrption	: Finction used to set the pin 		*/
/* direction .						   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidSetPinDirection(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy, u8 u8PinStateCpy)
{
	if (0<=u8PinNbCpy   && u8PinNbCpy  <= 7)
	{
			u8 Loc_u8ModeBit = u8PinNbCpy <<2;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;

			if(u8PinStateCpy == GPIO_u8OUTPUT)
			{
				u8 Loc_u8ModeBit = u8PinNbCpy <<2;
				u8 Loc_u8CNFBit = Loc_u8ModeBit+2;

					/*output Push Pull*/
				CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
				CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit+1);

				SET_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
				CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit+1);

			}
			else
			{
				/*Input pull down*/
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRL,Loc_u8CNFBit+1);

			CLEAR_BIT(pstPortCpy->ODR,u8PinNbCpy);

			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit+1);

			}
		}
		else if (u8PinNbCpy  <= 15)
		{
			u8PinNbCpy  %= 8;
			u8 Loc_u8ModeBit = u8PinNbCpy <<2;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
			if(u8PinStateCpy == GPIO_u8OUTPUT)
			{
					/*output Push Pull*/
				CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
				CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit+1);

				SET_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
				CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit+1);

			}
			else
			{
				/*Input pull down*/
			CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRH,Loc_u8CNFBit+1);

			CLEAR_BIT(pstPortCpy->ODR,u8PinNbCpy+8);

			CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit+1);
			}
		}
		else {}

}
/****************************************************/
/** Descrption	: Finction used to toggle the pin .	*/
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status 							*/
/****************************************************/

void GPIO_vidTogglePin (GPIO_Register* pstPortCpy ,u8 u8PinNbCpy)
{
			TOGGLE_BIT(pstPortCpy->ODR,u8PinNbCpy);
}

/****************************************************/
/** Descrption	: Finction used to make pull up .	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullUp(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy)
{
		if (0<=u8PinNbCpy && u8PinNbCpy<=7)
		{
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
				/*Input pull UP*/
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRL,Loc_u8CNFBit+1);

			SET_BIT(pstPortCpy->ODR,u8PinNbCpy);

			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit+1);
		}
		else if (u8PinNbCpy<=15)
		{
			u8PinNbCpy %=8;
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
			/*Input pull Up*/
		CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
		SET_BIT(pstPortCpy->CRH,Loc_u8CNFBit+1);

		SET_BIT(pstPortCpy->ODR,u8PinNbCpy+8);

		CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
		CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit+1);
		}
}

/****************************************************/
/** Descrption	: Finction used to make pull Down.	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullDown(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy)
{
		if (0<=u8PinNbCpy && u8PinNbCpy<=7)
		{
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
				/*Input pull Down*/
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRL,Loc_u8CNFBit+1);

			CLEAR_BIT(pstPortCpy->ODR,u8PinNbCpy);

			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit+1);
		}
		else if (u8PinNbCpy<=15)
		{
			u8PinNbCpy %=8;
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
			/*Input pull Down*/
		CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
		SET_BIT(pstPortCpy->CRH,Loc_u8CNFBit+1);

		CLEAR_BIT(pstPortCpy->ODR,u8PinNbCpy+8);

		CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
		CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit+1);
		}
}
