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
	GPIOB->CRH = conc8(GPIO_MODE_u8RB_15,GPIO_MODE_u8RB_14,GPIO_MODE_u8RB_13,
					   GPIO_MODE_u8RB_12,GPIO_MODE_u8RB_11,GPIO_MODE_u8RB_10,
					   GPIO_MODE_u8RB_9,GPIO_MODE_u8RB_8);
	GPIOB->CRL = conc8(GPIO_MODE_u8RB_7,GPIO_MODE_u8RB_6,GPIO_MODE_u8RB_5,
					   GPIO_MODE_u8RB_4,GPIO_MODE_u8RB_3,GPIO_MODE_u8RB_2,
					   GPIO_MODE_u8RB_1,GPIO_MODE_u8RB_0);
			/*FOR PULL up / down*/
	GPIOB->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RB_15,GPIO_PUPD_u8RB_14,GPIO_PUPD_u8RB_13,
				  GPIO_PUPD_u8RB_12,GPIO_PUPD_u8RB_11,GPIO_PUPD_u8RB_10,
				  GPIO_PUPD_u8RB_9,GPIO_PUPD_u8RB_8,GPIO_PUPD_u8RB_7,
				  GPIO_PUPD_u8RB_6,GPIO_PUPD_u8RB_5,GPIO_PUPD_u8RB_4,
				  GPIO_PUPD_u8RB_3,GPIO_PUPD_u8RB_2,GPIO_PUPD_u8RB_1,
				  GPIO_PUPD_u8RB_0);

			/*GPIOC*/
	GPIOC->CRH = conc8(GPIO_MODE_u8RC_15,GPIO_MODE_u8RC_14,GPIO_MODE_u8RC_13,
					   GPIO_MODE_u8RC_12,GPIO_MODE_u8RC_11,GPIO_MODE_u8RC_10,
					   GPIO_MODE_u8RC_9,GPIO_MODE_u8RC_8);
	GPIOC->CRL = conc8(GPIO_MODE_u8RC_7,GPIO_MODE_u8RC_6,GPIO_MODE_u8RC_5,
					   GPIO_MODE_u8RC_4,GPIO_MODE_u8RC_3,GPIO_MODE_u8RC_2,
					   GPIO_MODE_u8RC_1,GPIO_MODE_u8RC_0);
			/*FOR PULL up / down*/
	GPIOC->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RC_15,GPIO_PUPD_u8RC_14,GPIO_PUPD_u8RC_13,
				  GPIO_PUPD_u8RC_12,GPIO_PUPD_u8RC_11,GPIO_PUPD_u8RC_10,
				  GPIO_PUPD_u8RC_9,GPIO_PUPD_u8RC_8,GPIO_PUPD_u8RC_7,
				  GPIO_PUPD_u8RC_6,GPIO_PUPD_u8RC_5,GPIO_PUPD_u8RC_4,
				  GPIO_PUPD_u8RC_3,GPIO_PUPD_u8RC_2,GPIO_PUPD_u8RC_1,
				  GPIO_PUPD_u8RC_0);

			/*GPIOD*/
	GPIOD->CRH = conc8(GPIO_MODE_u8RD_15,GPIO_MODE_u8RD_14,GPIO_MODE_u8RD_13,
					   GPIO_MODE_u8RD_12,GPIO_MODE_u8RD_11,GPIO_MODE_u8RD_10,
					   GPIO_MODE_u8RD_9,GPIO_MODE_u8RD_8);
	GPIOD->CRL = conc8(GPIO_MODE_u8RD_7,GPIO_MODE_u8RD_6,GPIO_MODE_u8RD_5,
					   GPIO_MODE_u8RD_4,GPIO_MODE_u8RD_3,GPIO_MODE_u8RD_2,
					   GPIO_MODE_u8RD_1,GPIO_MODE_u8RD_0);
			/*FOR PULL up / down*/
	GPIOD->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RD_15,GPIO_PUPD_u8RD_14,GPIO_PUPD_u8RD_13,
				  GPIO_PUPD_u8RD_12,GPIO_PUPD_u8RD_11,GPIO_PUPD_u8RD_10,
				  GPIO_PUPD_u8RD_9,GPIO_PUPD_u8RD_8,GPIO_PUPD_u8RD_7,
				  GPIO_PUPD_u8RD_6,GPIO_PUPD_u8RD_5,GPIO_PUPD_u8RD_4,
				  GPIO_PUPD_u8RD_3,GPIO_PUPD_u8RD_2,GPIO_PUPD_u8RD_1,
				  GPIO_PUPD_u8RD_0);

			/*GPIOE*/
	GPIOE->CRH = conc8(GPIO_MODE_u8RE_15,GPIO_MODE_u8RE_14,GPIO_MODE_u8RE_13,
					   GPIO_MODE_u8RE_12,GPIO_MODE_u8RE_11,GPIO_MODE_u8RE_10,
					   GPIO_MODE_u8RE_9,GPIO_MODE_u8RE_8);
	GPIOE->CRL = conc8(GPIO_MODE_u8RE_7,GPIO_MODE_u8RE_6,GPIO_MODE_u8RE_5,
					   GPIO_MODE_u8RE_4,GPIO_MODE_u8RE_3,GPIO_MODE_u8RE_2,
					   GPIO_MODE_u8RE_1,GPIO_MODE_u8RE_0);
			/*FOR PULL up / down*/
	GPIOE->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RE_15,GPIO_PUPD_u8RE_14,GPIO_PUPD_u8RE_13,
				  GPIO_PUPD_u8RE_12,GPIO_PUPD_u8RE_11,GPIO_PUPD_u8RE_10,
				  GPIO_PUPD_u8RE_9,GPIO_PUPD_u8RE_8,GPIO_PUPD_u8RE_7,
				  GPIO_PUPD_u8RE_6,GPIO_PUPD_u8RE_5,GPIO_PUPD_u8RE_4,
				  GPIO_PUPD_u8RE_3,GPIO_PUPD_u8RE_2,GPIO_PUPD_u8RE_1,
				  GPIO_PUPD_u8RE_0);

			/*GPIOF*/
	GPIOF->CRH = conc8(GPIO_MODE_u8RF_15,GPIO_MODE_u8RF_14,GPIO_MODE_u8RF_13,
					   GPIO_MODE_u8RF_12,GPIO_MODE_u8RF_11,GPIO_MODE_u8RF_10,
					   GPIO_MODE_u8RF_9,GPIO_MODE_u8RF_8);
	GPIOF->CRL = conc8(GPIO_MODE_u8RF_7,GPIO_MODE_u8RF_6,GPIO_MODE_u8RF_5,
					   GPIO_MODE_u8RF_4,GPIO_MODE_u8RF_3,GPIO_MODE_u8RF_2,
					   GPIO_MODE_u8RF_1,GPIO_MODE_u8RF_0);
			/*FOR PULL up / down*/
	GPIOF->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RF_15,GPIO_PUPD_u8RF_14,GPIO_PUPD_u8RF_13,
				  GPIO_PUPD_u8RF_12,GPIO_PUPD_u8RF_11,GPIO_PUPD_u8RF_10,
				  GPIO_PUPD_u8RF_9,GPIO_PUPD_u8RF_8,GPIO_PUPD_u8RF_7,
				  GPIO_PUPD_u8RF_6,GPIO_PUPD_u8RF_5,GPIO_PUPD_u8RF_4,
				  GPIO_PUPD_u8RF_3,GPIO_PUPD_u8RF_2,GPIO_PUPD_u8RF_1,
				  GPIO_PUPD_u8RF_0);

			/*GPIOG*/
	GPIOG->CRH = conc8(GPIO_MODE_u8RG_15,GPIO_MODE_u8RG_14,GPIO_MODE_u8RG_13,
					   GPIO_MODE_u8RG_12,GPIO_MODE_u8RG_11,GPIO_MODE_u8RG_10,
					   GPIO_MODE_u8RG_9,GPIO_MODE_u8RG_8);
	GPIOG->CRL = conc8(GPIO_MODE_u8RG_7,GPIO_MODE_u8RG_6,GPIO_MODE_u8RG_5,
					   GPIO_MODE_u8RG_4,GPIO_MODE_u8RG_3,GPIO_MODE_u8RG_2,
					   GPIO_MODE_u8RG_1,GPIO_MODE_u8RG_0);
			/*FOR PULL up / down*/
	GPIOG->ODR = conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
				  GPIO_PUPD_u8RG_15,GPIO_PUPD_u8RG_14,GPIO_PUPD_u8RG_13,
				  GPIO_PUPD_u8RG_12,GPIO_PUPD_u8RG_11,GPIO_PUPD_u8RG_10,
				  GPIO_PUPD_u8RG_9,GPIO_PUPD_u8RG_8,GPIO_PUPD_u8RG_7,
				  GPIO_PUPD_u8RG_6,GPIO_PUPD_u8RG_5,GPIO_PUPD_u8RG_4,
				  GPIO_PUPD_u8RG_3,GPIO_PUPD_u8RG_2,GPIO_PUPD_u8RG_1,
				  GPIO_PUPD_u8RG_0);

	AFIO->MAPR = (JTAG_SW_CFG <<MAPR_SWJ_CFG )| (ADC1_REGULAR_CFG << MAPR_ADC1_EXTERNAL_REGULAR)| (ADC1_INJECTED_CFG << MAPR_ADC1_EXTERNAL_INJECTED)|
			(ADC2_REGULAR_CFG << MAPR_ADC2_EXTERNAL_REGULAR)|( ADC2_INJECTED_CFG << MAPR_ADC1_EXTERNAL_INJECTED)| (TIM5_CH4_CGF << MAPR_TIMER5_CH4	)|
			(OSC_CFG<< MAPR_OSC_POTD_01)	|( CAN_CFG<< MAPR_CAN)|( TIM4_Remap_CFG << MAPR_TIM4) | (TIM3_Remap_CFG<< MAPR_TIM3)|
			(TIM2_Remap_CFG<< MAPR_TIM2)|(TIM1_Remap_CFG<< MAPR_TIM1)|(USART3_Remap_CFG << MAPR_USARt3)|(USART2_Remap_CFG<< MAPR_USARt2)|
			(USART1_Remap_CFG<< MAPR_USARt1)|(I2C1_Remap_CFG<< MAPR_I2C1)|(SPI1_Remap_CFG<< MAPR_SPI1);

	AFIO->EXTICR1 =(EXTI0_CFG<<EXTI0)|(EXTI1_CFG<<EXTI1)|(EXTI2_CFG<<EXTI2)|(EXTI3_CFG<<EXTI3);
	AFIO->EXTICR2 =(EXTI4_CFG<<EXTI4)|(EXTI5_CFG<<EXTI5)|(EXTI6_CFG<<EXTI6)|(EXTI7_CFG<<EXTI7);
	AFIO->EXTICR3 =(EXTI8_CFG<<EXTI8)|(EXTI9_CFG<<EXTI9)|(EXTI10_CFG<<EXTI10)|(EXTI11_CFG<<EXTI11);
	AFIO->EXTICR4 =(EXTI12_CFG<<EXTI12)|(EXTI13_CFG<<EXTI13)|(EXTI14_CFG<<EXTI14)|(EXTI15_CFG<<EXTI15);
	AFIO->MAPR2	  =(FSMC_NADV_CFG<<FSMC_NADV)|(TIM14_CFG<<TIM14_REMAP)|
				   (TIM13_CFG<<TIM13_REMAP)|(TIM11_CFG<<TIM11_REMAP)  |
				   (TIM10_CFG<<TIM10_REMAP)|(TIM9_CFG<<TIM9_REMAP);

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
	if (u8PinNbCpy  <= 7)
	{
			u8 Loc_u8ModeBit = u8PinNbCpy <<2;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;

			if(u8PinStateCpy == GPIO_u8OUTPUT)
			{
				u8 Loc_u8ModeBit = u8PinNbCpy <<2;
				u8 Loc_u8CNFBit = Loc_u8ModeBit+2;

					/*output Push Pull*/
				CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
				CLEAR_BIT(pstPortCpy->CRL,(Loc_u8CNFBit+1));

				SET_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
				CLEAR_BIT(pstPortCpy->CRL,(Loc_u8ModeBit+1));

			}
			else
			{
				/*Input pull down*/
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRL,(Loc_u8CNFBit+1));

			CLEAR_BIT(pstPortCpy->ODR,u8PinNbCpy);

			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRL,(Loc_u8ModeBit+1));

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
				CLEAR_BIT(pstPortCpy->CRH,(Loc_u8CNFBit+1));

				SET_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
				CLEAR_BIT(pstPortCpy->CRH,(Loc_u8ModeBit+1));

			}
			else
			{
				/*Input pull down*/
			CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRH,(Loc_u8CNFBit+1));

			CLEAR_BIT(pstPortCpy->ODR,(u8PinNbCpy+8));

			CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRH,(Loc_u8ModeBit+1));
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
		if (u8PinNbCpy<=7)
		{
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
				/*Input pull UP*/
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRL,(Loc_u8CNFBit+1));

			SET_BIT(pstPortCpy->ODR,u8PinNbCpy);

			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRL,(Loc_u8ModeBit+1));
		}
		else if (u8PinNbCpy<=15)
		{
			u8PinNbCpy %=8;
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
			/*Input pull Up*/
		CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
		SET_BIT(pstPortCpy->CRH,(Loc_u8CNFBit+1));

		SET_BIT(pstPortCpy->ODR,(u8PinNbCpy+8));

		CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
		CLEAR_BIT(pstPortCpy->CRH,(Loc_u8ModeBit+1));
		}
}

/****************************************************/
/** Descrption	: Finction used to make pull Down.	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullDown(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy)
{
		if (u8PinNbCpy<=7)
		{
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
				/*Input pull Down*/
			CLEAR_BIT(pstPortCpy->CRL,Loc_u8CNFBit);
			SET_BIT(pstPortCpy->CRL,(Loc_u8CNFBit+1));

			CLEAR_BIT(pstPortCpy->ODR,u8PinNbCpy);

			CLEAR_BIT(pstPortCpy->CRL,Loc_u8ModeBit);
			CLEAR_BIT(pstPortCpy->CRL,(Loc_u8ModeBit+1));
		}
		else if (u8PinNbCpy<=15)
		{
			u8PinNbCpy %=8;
			u8 Loc_u8ModeBit = u8PinNbCpy<<2 ;
			u8 Loc_u8CNFBit = Loc_u8ModeBit+2;
			/*Input pull Down*/
		CLEAR_BIT(pstPortCpy->CRH,Loc_u8CNFBit);
		SET_BIT(pstPortCpy->CRH,(Loc_u8CNFBit+1));

		CLEAR_BIT(pstPortCpy->ODR,(u8PinNbCpy+8));

		CLEAR_BIT(pstPortCpy->CRH,Loc_u8ModeBit);
		CLEAR_BIT(pstPortCpy->CRH,(Loc_u8ModeBit+1));
		}
}


/******************** Alternate Function ************/
void AFIO_vidSetSwJtagRemapping(tdefJtagSw enuJtagSwCpy)
{
	AFIO->MAPR &= ~(3<<MAPR_SWJ_CFG);
	AFIO->MAPR |= enuJtagSwCpy	;
}


void AFIO_vidSetADC2Regulator (tdefADCRegulator enuAdcRegulatorCpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_ADC2_EXTERNAL_REGULAR);
	AFIO->MAPR |= enuAdcRegulatorCpy<<MAPR_ADC2_EXTERNAL_REGULAR ;
}

void AFIO_vidSetADC1Regulator (tdefADCRegulator enuAdcRegulatorCpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_ADC1_EXTERNAL_REGULAR);
	AFIO->MAPR |= enuAdcRegulatorCpy<<MAPR_ADC1_EXTERNAL_REGULAR ;
}

void AFIO_vidSetADC2Injected(tdefADCInjected enuADCInjectedCpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_ADC2_EXTERNAL_INJECTED);
	AFIO->MAPR |= enuADCInjectedCpy<<MAPR_ADC2_EXTERNAL_INJECTED ;
}

void AFIO_vidSetADC1Injected(tdefADCInjected enuADCInjectedCpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_ADC1_EXTERNAL_INJECTED);
	AFIO->MAPR |= enuADCInjectedCpy<<MAPR_ADC1_EXTERNAL_INJECTED ;
}

void AFIO_vidSetTIM5CH4Remapping(tdefTim5Ch4 enuTim5Cpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_TIMER5_CH4);
	AFIO->MAPR |= enuTim5Cpy << MAPR_TIMER5_CH4 ;
}

void AFIO_vidSetOscRemapping(tdefOsc enuOscCpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_OSC_POTD_01);
	AFIO->MAPR |= enuOscCpy<<MAPR_OSC_POTD_01;
}


void AFIO_vidSetCanRemapping(tdefCan enuCanCpy)
{
	AFIO->MAPR &= ~(3<<MAPR_CAN);
	AFIO->MAPR |= enuCanCpy<<MAPR_CAN ;
}

void AFIO_vidSetTimer4Remapping(tdefTimer4 enuTimer4)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_TIM4);
	AFIO->MAPR |= enuTimer4 << MAPR_TIM4 ;
}

void AFIO_vidSetTimer3Remapping(tdefTimer3 enuTimer3Cpy)
{
	AFIO->MAPR &= ~ (3<<MAPR_TIM3);
	AFIO->MAPR |= enuTimer3Cpy<<MAPR_TIM3 ;
}

void AFIO_vidSetTimer2Remapping(tdefTimer2 enuTimer2Cpy)
{
	AFIO->MAPR &= ~ (3<<MAPR_TIM2);
	AFIO->MAPR |= enuTimer2Cpy<<MAPR_TIM2;
}


void AFIO_vidSetTimer1Remapping(tdefTimer1 enuTimer1Cpy)
{
	AFIO->MAPR &= ~(3<<MAPR_TIM1);
	AFIO->MAPR |= enuTimer1Cpy<<MAPR_TIM1 ;
}


void AFIO_vidSetUsart3Remapping(tdefUsart3 enuUsart3Cpy)
{
	AFIO->MAPR &= ~(3<<MAPR_USARt3);
	AFIO->MAPR |= enuUsart3Cpy<<MAPR_USARt3 ;
}

void AFIO_vidSetUsart2Remapping(tdefUsart2 enuUsart2Cpy)
{
	AFIO->MAPR &= ~(3<<MAPR_USARt2);
	AFIO->MAPR |= enuUsart2Cpy<<MAPR_USARt2 ;
}

void AFIO_vidSetUsart1Remapping(tdefUsart1 enuUsart1Cpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_USARt1);
	AFIO->MAPR |= enuUsart1Cpy<<MAPR_USARt1;
}

void AFIO_vidSetI2C1Remapping(tdefI2c1 enuI2C1Cpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_I2C1);
	AFIO->MAPR |= enuI2C1Cpy<<MAPR_I2C1 ;
}

void AFIO_vidSetSpi1Remapping(tdefSPI1 enuSpi2Cpy)
{
	CLEAR_BIT(AFIO->MAPR,MAPR_SPI1);
	AFIO->MAPR |= enuSpi2Cpy<<MAPR_SPI1 ;

}

void AFIO_vidSetEXTI0Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR1 &= ~(0x0f << EXTI0) ;
	AFIO->EXTICR1 |= enuExtiCpy <<EXTI0 ;
}

void AFIO_vidSetEXTI1Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR1 &= ~(0x0f << EXTI1) ;
	AFIO->EXTICR1 |= enuExtiCpy <<EXTI1 ;
}

void AFIO_vidSetEXTI2Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR1 &= ~(0x0f << EXTI2) ;
	AFIO->EXTICR1 |= enuExtiCpy <<EXTI2 ;
}
void AFIO_vidSetEXTI3Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR1 &= ~(0x0f << EXTI3) ;
	AFIO->EXTICR1 |= enuExtiCpy <<EXTI3 ;
}
void AFIO_vidSetEXTI4Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR2 &= ~(0x0f << EXTI4) ;
	AFIO->EXTICR2 |= enuExtiCpy <<EXTI4 ;
}
void AFIO_vidSetEXTI5Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR2 &= ~(0x0f << EXTI5) ;
	AFIO->EXTICR2 |= enuExtiCpy <<EXTI5 ;
}
void AFIO_vidSetEXTI6Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR2 &= ~(0x0f << EXTI6) ;
	AFIO->EXTICR2 |= enuExtiCpy <<EXTI6 ;
}
void AFIO_vidSetEXTI7Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR2 &= ~(0x0f << EXTI7) ;
	AFIO->EXTICR2 |= enuExtiCpy <<EXTI7 ;
}
void AFIO_vidSetEXTI8Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR3 &= ~(0x0f << EXTI8) ;
	AFIO->EXTICR3 |= enuExtiCpy <<EXTI8 ;
}
void AFIO_vidSetEXTI9Remapping (tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR3 &= ~(0x0f << EXTI9) ;
	AFIO->EXTICR3 |= enuExtiCpy <<EXTI9 ;
}
void AFIO_vidSetEXTI10Remapping(tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR3 &= ~(0x0f << EXTI10) ;
	AFIO->EXTICR3 |= enuExtiCpy <<EXTI10 ;
}
void AFIO_vidSetEXTI11Remapping(tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR3 &= ~(0x0f << EXTI11) ;
	AFIO->EXTICR3 |= enuExtiCpy <<EXTI11 ;
}
void AFIO_vidSetEXTI12Remapping(tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR4 &= ~(0x0f << EXTI12) ;
	AFIO->EXTICR4 |= enuExtiCpy <<EXTI12 ;
}
void AFIO_vidSetEXTI13Remapping(tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR4 &= ~(0x0f << EXTI13) ;
	AFIO->EXTICR4 |= enuExtiCpy <<EXTI13 ;
}
void AFIO_vidSetEXTI14Remapping(tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR4 &= ~(0x0f << EXTI14) ;
	AFIO->EXTICR4 |= enuExtiCpy <<EXTI14 ;
}
void AFIO_vidSetEXTI15Remapping(tdefEXTI enuExtiCpy)
{
	AFIO->EXTICR4 &= ~(0x0f << EXTI15) ;
	AFIO->EXTICR4 |= enuExtiCpy <<EXTI15 ;
}

void ADIO_vidSetFSMC_NADVRemapping(tdefGPIO_AFIO_EN enuGpioAfioEnCpy)
{
	CLEAR_BIT(AFIO->MAPR2,FSMC_NADV);
	AFIO->MAPR2 |= enuGpioAfioEnCpy<<FSMC_NADV;
}

void AFIO_vidSetTimer14Remapping(tdefTimer14 enuTimer14Cpy)
{
	CLEAR_BIT(AFIO->MAPR2,TIM14_REMAP);
	AFIO->MAPR2 |= enuTimer14Cpy<<TIM14_REMAP;
}

void AFIO_vidSetTimer13Remapping(tdefTimer13 enuTimer13Cpy)
{
	CLEAR_BIT(AFIO->MAPR2,TIM13_REMAP);
	AFIO->MAPR2 |= enuTimer13Cpy<<TIM13_REMAP;
}

void AFIO_vidSetTimer11Remapping(tdefTimer11 enuTimer11Cpy)
{
	CLEAR_BIT(AFIO->MAPR2,TIM11_REMAP);
	AFIO->MAPR2 |= enuTimer11Cpy<<TIM11_REMAP;
}

void AFIO_vidSetTimer10Remapping(tdefTimer10 enuTimer10Cpy)
{
	CLEAR_BIT(AFIO->MAPR2,TIM10_REMAP);
	AFIO->MAPR2 |= enuTimer10Cpy<<TIM10_REMAP;
}

void AFIO_vidSetTimer9Remapping (tdefTimer9 enuTimer9Cpy)
{
	CLEAR_BIT(AFIO->MAPR2,TIM9_REMAP);
	AFIO->MAPR2 |= enuTimer9Cpy<<TIM9_REMAP;
}
