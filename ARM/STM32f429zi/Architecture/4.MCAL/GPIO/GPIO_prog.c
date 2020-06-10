/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 25/12/2019					*/
/* Description	: GPIO Implementation File		*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#include "Std_types.h"
#include "Bit_Math.h"

#include "GPIO_INT.h"
#include "GPIO_CFG.h"
#include "GPIO_PRIV.h"




void GPIO_vidInit(void)
{
			/*GPIOA*/
	GPIOA->MODER =
			conc16(GPIO_MODE_RA15,GPIO_MODE_RA14,GPIO_MODE_RA13
				  ,GPIO_MODE_RA12,GPIO_MODE_RA11,GPIO_MODE_RA10
				  ,GPIO_MODE_RA9,GPIO_MODE_RA8,GPIO_MODE_RA7
				  ,GPIO_MODE_RA6,GPIO_MODE_RA5,GPIO_MODE_RA4
				  ,GPIO_MODE_RA3,GPIO_MODE_RA2,GPIO_MODE_RA1
				  ,GPIO_MODE_RA0);
	GPIOA->PUPDR =
			conc16(GPIO_PUPD_RA15,GPIO_PUPD_RA14,GPIO_PUPD_RA13
				  ,GPIO_PUPD_RA12,GPIO_PUPD_RA11,GPIO_PUPD_RA10
				  ,GPIO_PUPD_RA9,GPIO_PUPD_RA8,GPIO_PUPD_RA7
				  ,GPIO_PUPD_RA6,GPIO_PUPD_RA5,GPIO_PUPD_RA4
				  ,GPIO_PUPD_RA3,GPIO_PUPD_RA2,GPIO_PUPD_RA1
				  ,GPIO_PUPD_RA0);
	GPIOA->OTYPER =
			conc16(GPIO_ODPP_RA15,GPIO_ODPP_RA14,GPIO_ODPP_RA13
				  ,GPIO_ODPP_RA12,GPIO_ODPP_RA11,GPIO_ODPP_RA10
				  ,GPIO_ODPP_RA9,GPIO_ODPP_RA8,GPIO_ODPP_RA7
				  ,GPIO_ODPP_RA6,GPIO_ODPP_RA5,GPIO_ODPP_RA4
				  ,GPIO_ODPP_RA3,GPIO_ODPP_RA2,GPIO_ODPP_RA1
				  ,GPIO_ODPP_RA0);

		/*GPIOB*/
	GPIOB->MODER =
			conc16(GPIO_MODE_RB15,GPIO_MODE_RB14,GPIO_MODE_RB13
				  ,GPIO_MODE_RB12,GPIO_MODE_RB11,GPIO_MODE_RB10
				  ,GPIO_MODE_RB9,GPIO_MODE_RB8,GPIO_MODE_RB7
				  ,GPIO_MODE_RB6,GPIO_MODE_RB5,GPIO_MODE_RB4
				  ,GPIO_MODE_RB3,GPIO_MODE_RB2,GPIO_MODE_RB1
				  ,GPIO_MODE_RB0);
	GPIOB->PUPDR =
			conc16(GPIO_PUPD_RB15,GPIO_PUPD_RB14,GPIO_PUPD_RB13
				  ,GPIO_PUPD_RB12,GPIO_PUPD_RB11,GPIO_PUPD_RB10
				  ,GPIO_PUPD_RB9,GPIO_PUPD_RB8,GPIO_PUPD_RB7
				  ,GPIO_PUPD_RB6,GPIO_PUPD_RB5,GPIO_PUPD_RB4
				  ,GPIO_PUPD_RB3,GPIO_PUPD_RB2,GPIO_PUPD_RB1
				  ,GPIO_PUPD_RB0);
	GPIOB->OTYPER =
			conc16(GPIO_ODPP_RB15,GPIO_ODPP_RB14,GPIO_ODPP_RB13
				  ,GPIO_ODPP_RB12,GPIO_ODPP_RB11,GPIO_ODPP_RB10
				  ,GPIO_ODPP_RB9,GPIO_ODPP_RB8,GPIO_ODPP_RB7
				  ,GPIO_ODPP_RB6,GPIO_ODPP_RB5,GPIO_ODPP_RB4
				  ,GPIO_ODPP_RB3,GPIO_ODPP_RB2,GPIO_ODPP_RB1
				  ,GPIO_ODPP_RB0);

		/*GPIOC*/
	GPIOC->MODER =
			conc16(GPIO_MODE_RC15,GPIO_MODE_RC14,GPIO_MODE_RC13
				  ,GPIO_MODE_RC12,GPIO_MODE_RC11,GPIO_MODE_RC10
				  ,GPIO_MODE_RC9,GPIO_MODE_RC8,GPIO_MODE_RC7
				  ,GPIO_MODE_RC6,GPIO_MODE_RC5,GPIO_MODE_RC4
				  ,GPIO_MODE_RC3,GPIO_MODE_RC2,GPIO_MODE_RC1
				  ,GPIO_MODE_RC0);
	GPIOC->PUPDR =
			conc16(GPIO_PUPD_RC15,GPIO_PUPD_RC14,GPIO_PUPD_RC13
				  ,GPIO_PUPD_RC12,GPIO_PUPD_RC11,GPIO_PUPD_RC10
				  ,GPIO_PUPD_RC9,GPIO_PUPD_RC8,GPIO_PUPD_RC7
				  ,GPIO_PUPD_RC6,GPIO_PUPD_RC5,GPIO_PUPD_RC4
				  ,GPIO_PUPD_RC3,GPIO_PUPD_RC2,GPIO_PUPD_RC1
				  ,GPIO_PUPD_RC0);
	GPIOC->OTYPER =
			conc16(GPIO_ODPP_RC15,GPIO_ODPP_RC14,GPIO_ODPP_RC13
				  ,GPIO_ODPP_RC12,GPIO_ODPP_RC11,GPIO_ODPP_RC10
				  ,GPIO_ODPP_RC9,GPIO_ODPP_RC8,GPIO_ODPP_RC7
				  ,GPIO_ODPP_RC6,GPIO_ODPP_RC5,GPIO_ODPP_RC4
				  ,GPIO_ODPP_RC3,GPIO_ODPP_RC2,GPIO_ODPP_RC1
				  ,GPIO_ODPP_RC0);

		/*GPIOD*/
	GPIOD->MODER =
			conc16(GPIO_MODE_RD15,GPIO_MODE_RD14,GPIO_MODE_RD13
				  ,GPIO_MODE_RD12,GPIO_MODE_RD11,GPIO_MODE_RD10
				  ,GPIO_MODE_RD9,GPIO_MODE_RD8,GPIO_MODE_RD7
				  ,GPIO_MODE_RD6,GPIO_MODE_RD5,GPIO_MODE_RD4
				  ,GPIO_MODE_RD3,GPIO_MODE_RD2,GPIO_MODE_RD1
				  ,GPIO_MODE_RD0);
	GPIOD->PUPDR =
			conc16(GPIO_PUPD_RD15,GPIO_PUPD_RD14,GPIO_PUPD_RD13
				  ,GPIO_PUPD_RD12,GPIO_PUPD_RD11,GPIO_PUPD_RD10
				  ,GPIO_PUPD_RD9,GPIO_PUPD_RD8,GPIO_PUPD_RD7
				  ,GPIO_PUPD_RD6,GPIO_PUPD_RD5,GPIO_PUPD_RD4
				  ,GPIO_PUPD_RD3,GPIO_PUPD_RD2,GPIO_PUPD_RD1
				  ,GPIO_PUPD_RD0);
	GPIOD->OTYPER =
			conc16(GPIO_ODPP_RD15,GPIO_ODPP_RD14,GPIO_ODPP_RD13
				  ,GPIO_ODPP_RD12,GPIO_ODPP_RD11,GPIO_ODPP_RD10
				  ,GPIO_ODPP_RD9,GPIO_ODPP_RD8,GPIO_ODPP_RD7
				  ,GPIO_ODPP_RD6,GPIO_ODPP_RD5,GPIO_ODPP_RD4
				  ,GPIO_ODPP_RD3,GPIO_ODPP_RD2,GPIO_ODPP_RD1
				  ,GPIO_ODPP_RD0);

		/*GPIOE*/
	GPIOE->MODER =
			conc16(GPIO_MODE_RE15,GPIO_MODE_RE14,GPIO_MODE_RE13
				  ,GPIO_MODE_RE12,GPIO_MODE_RE11,GPIO_MODE_RE10
				  ,GPIO_MODE_RE9,GPIO_MODE_RE8,GPIO_MODE_RE7
				  ,GPIO_MODE_RE6,GPIO_MODE_RE5,GPIO_MODE_RE4
				  ,GPIO_MODE_RE3,GPIO_MODE_RE2,GPIO_MODE_RE1
				  ,GPIO_MODE_RE0);
	GPIOE->PUPDR =
			conc16(GPIO_PUPD_RE15,GPIO_PUPD_RE14,GPIO_PUPD_RE13
				  ,GPIO_PUPD_RE12,GPIO_PUPD_RE11,GPIO_PUPD_RE10
				  ,GPIO_PUPD_RE9,GPIO_PUPD_RE8,GPIO_PUPD_RE7
				  ,GPIO_PUPD_RE6,GPIO_PUPD_RE5,GPIO_PUPD_RE4
				  ,GPIO_PUPD_RE3,GPIO_PUPD_RE2,GPIO_PUPD_RE1
				  ,GPIO_PUPD_RE0);
	GPIOE->OTYPER =
			conc16(GPIO_ODPP_RE15,GPIO_ODPP_RE14,GPIO_ODPP_RE13
				  ,GPIO_ODPP_RE12,GPIO_ODPP_RE11,GPIO_ODPP_RE10
				  ,GPIO_ODPP_RE9,GPIO_ODPP_RE8,GPIO_ODPP_RE7
				  ,GPIO_ODPP_RE6,GPIO_ODPP_RE5,GPIO_ODPP_RE4
				  ,GPIO_ODPP_RE3,GPIO_ODPP_RE2,GPIO_ODPP_RE1
				  ,GPIO_ODPP_RE0);

		/*GPIOF*/
	GPIOF->MODER =
			conc16(GPIO_MODE_RF15,GPIO_MODE_RF14,GPIO_MODE_RF13
				  ,GPIO_MODE_RF12,GPIO_MODE_RF11,GPIO_MODE_RF10
				  ,GPIO_MODE_RF9,GPIO_MODE_RF8,GPIO_MODE_RF7
				  ,GPIO_MODE_RF6,GPIO_MODE_RF5,GPIO_MODE_RF4
				  ,GPIO_MODE_RF3,GPIO_MODE_RF2,GPIO_MODE_RF1
				  ,GPIO_MODE_RF0);
	GPIOF->PUPDR =
			conc16(GPIO_PUPD_RF15,GPIO_PUPD_RF14,GPIO_PUPD_RF13
				  ,GPIO_PUPD_RF12,GPIO_PUPD_RF11,GPIO_PUPD_RF10
				  ,GPIO_PUPD_RF9,GPIO_PUPD_RF8,GPIO_PUPD_RF7
				  ,GPIO_PUPD_RF6,GPIO_PUPD_RF5,GPIO_PUPD_RF4
				  ,GPIO_PUPD_RF3,GPIO_PUPD_RF2,GPIO_PUPD_RF1
				  ,GPIO_PUPD_RF0);
	GPIOF->OTYPER =
			conc16(GPIO_ODPP_RF15,GPIO_ODPP_RF14,GPIO_ODPP_RF13
				  ,GPIO_ODPP_RF12,GPIO_ODPP_RF11,GPIO_ODPP_RF10
				  ,GPIO_ODPP_RF9,GPIO_ODPP_RF8,GPIO_ODPP_RF7
				  ,GPIO_ODPP_RF6,GPIO_ODPP_RF5,GPIO_ODPP_RF4
				  ,GPIO_ODPP_RF3,GPIO_ODPP_RF2,GPIO_ODPP_RF1
				  ,GPIO_ODPP_RF0);

			/*GPIOG*/
	GPIOG->MODER =
				conc16(GPIO_MODE_RG15,GPIO_MODE_RG14,GPIO_MODE_RG13
					  ,GPIO_MODE_RG12,GPIO_MODE_RG11,GPIO_MODE_RG10
					  ,GPIO_MODE_RG9,GPIO_MODE_RG8,GPIO_MODE_RG7
					  ,GPIO_MODE_RG6,GPIO_MODE_RG5,GPIO_MODE_RG4
					  ,GPIO_MODE_RG3,GPIO_MODE_RG2,GPIO_MODE_RG1
					  ,GPIO_MODE_RG0);
	GPIOG->PUPDR =
				conc16(GPIO_PUPD_RG15,GPIO_PUPD_RG14,GPIO_PUPD_RG13
					  ,GPIO_PUPD_RG12,GPIO_PUPD_RG11,GPIO_PUPD_RG10
					  ,GPIO_PUPD_RG9,GPIO_PUPD_RG8,GPIO_PUPD_RG7
					  ,GPIO_PUPD_RG6,GPIO_PUPD_RG5,GPIO_PUPD_RG4
					  ,GPIO_PUPD_RG3,GPIO_PUPD_RG2,GPIO_PUPD_RG1
					  ,GPIO_PUPD_RG0);
	GPIOG->OTYPER =
				conc16(GPIO_ODPP_RG15,GPIO_ODPP_RG14,GPIO_ODPP_RG13
					  ,GPIO_ODPP_RG12,GPIO_ODPP_RG11,GPIO_ODPP_RG10
					  ,GPIO_ODPP_RG9,GPIO_ODPP_RG8,GPIO_ODPP_RG7
					  ,GPIO_ODPP_RG6,GPIO_ODPP_RG5,GPIO_ODPP_RG4
					  ,GPIO_ODPP_RG3,GPIO_ODPP_RG2,GPIO_ODPP_RG1
					  ,GPIO_ODPP_RG0);

			/*GPIOH*/
	GPIOH->MODER =
			conc16(GPIO_MODE_RH15,GPIO_MODE_RH14,GPIO_MODE_RH13
				  ,GPIO_MODE_RH12,GPIO_MODE_RH11,GPIO_MODE_RH10
				  ,GPIO_MODE_RH9,GPIO_MODE_RH8,GPIO_MODE_RH7
				  ,GPIO_MODE_RH6,GPIO_MODE_RH5,GPIO_MODE_RH4
				  ,GPIO_MODE_RH3,GPIO_MODE_RH2,GPIO_MODE_RH1
				  ,GPIO_MODE_RH0);
	GPIOH->PUPDR =
			conc16(GPIO_PUPD_RH15,GPIO_PUPD_RH14,GPIO_PUPD_RH13
				  ,GPIO_PUPD_RH12,GPIO_PUPD_RH11,GPIO_PUPD_RH10
				  ,GPIO_PUPD_RH9,GPIO_PUPD_RH8,GPIO_PUPD_RH7
				  ,GPIO_PUPD_RH6,GPIO_PUPD_RH5,GPIO_PUPD_RH4
				  ,GPIO_PUPD_RH3,GPIO_PUPD_RH2,GPIO_PUPD_RH1
				  ,GPIO_PUPD_RH0);
	GPIOH->OTYPER =
			conc16(GPIO_ODPP_RH15,GPIO_ODPP_RH14,GPIO_ODPP_RH13
				  ,GPIO_ODPP_RH12,GPIO_ODPP_RH11,GPIO_ODPP_RH10
				  ,GPIO_ODPP_RH9,GPIO_ODPP_RH8,GPIO_ODPP_RH7
				  ,GPIO_ODPP_RH6,GPIO_ODPP_RH5,GPIO_ODPP_RH4
				  ,GPIO_ODPP_RH3,GPIO_ODPP_RH2,GPIO_ODPP_RH1
				  ,GPIO_ODPP_RH0);

		/*GPIOI*/
	GPIOI->MODER =
			conc16(GPIO_MODE_RI15,GPIO_MODE_RI14,GPIO_MODE_RI13
				  ,GPIO_MODE_RI12,GPIO_MODE_RI11,GPIO_MODE_RI10
				  ,GPIO_MODE_RI9,GPIO_MODE_RI8,GPIO_MODE_RI7
				  ,GPIO_MODE_RI6,GPIO_MODE_RI5,GPIO_MODE_RI4
				  ,GPIO_MODE_RI3,GPIO_MODE_RI2,GPIO_MODE_RI1
				  ,GPIO_MODE_RI0);
	GPIOI->PUPDR =
			conc16(GPIO_PUPD_RI15,GPIO_PUPD_RI14,GPIO_PUPD_RI13
				  ,GPIO_PUPD_RI12,GPIO_PUPD_RI11,GPIO_PUPD_RI10
				  ,GPIO_PUPD_RI9,GPIO_PUPD_RI8,GPIO_PUPD_RI7
				  ,GPIO_PUPD_RI6,GPIO_PUPD_RI5,GPIO_PUPD_RI4
				  ,GPIO_PUPD_RI3,GPIO_PUPD_RI2,GPIO_PUPD_RI1
				  ,GPIO_PUPD_RI0);
	GPIOI->OTYPER =
			conc16(GPIO_ODPP_RI15,GPIO_ODPP_RI14,GPIO_ODPP_RI13
				  ,GPIO_ODPP_RI12,GPIO_ODPP_RI11,GPIO_ODPP_RI10
				  ,GPIO_ODPP_RI9,GPIO_ODPP_RI8,GPIO_ODPP_RI7
				  ,GPIO_ODPP_RI6,GPIO_ODPP_RI5,GPIO_ODPP_RI4
				  ,GPIO_ODPP_RI3,GPIO_ODPP_RI2,GPIO_ODPP_RI1
				  ,GPIO_ODPP_RI0);

		/*GPIOJ*/
	GPIOJ->MODER =
			conc16(GPIO_MODE_RJ15,GPIO_MODE_RJ14,GPIO_MODE_RJ13
				  ,GPIO_MODE_RJ12,GPIO_MODE_RJ11,GPIO_MODE_RJ10
				  ,GPIO_MODE_RJ9,GPIO_MODE_RJ8,GPIO_MODE_RJ7
				  ,GPIO_MODE_RJ6,GPIO_MODE_RJ5,GPIO_MODE_RJ4
				  ,GPIO_MODE_RJ3,GPIO_MODE_RJ2,GPIO_MODE_RJ1
				  ,GPIO_MODE_RJ0);
	GPIOJ->PUPDR =
			conc16(GPIO_PUPD_RJ15,GPIO_PUPD_RJ14,GPIO_PUPD_RJ13
				  ,GPIO_PUPD_RJ12,GPIO_PUPD_RJ11,GPIO_PUPD_RJ10
				  ,GPIO_PUPD_RJ9,GPIO_PUPD_RJ8,GPIO_PUPD_RJ7
				  ,GPIO_PUPD_RJ6,GPIO_PUPD_RJ5,GPIO_PUPD_RJ4
				  ,GPIO_PUPD_RJ3,GPIO_PUPD_RJ2,GPIO_PUPD_RJ1
				  ,GPIO_PUPD_RJ0);
	GPIOJ->OTYPER =
			conc16(GPIO_ODPP_RJ15,GPIO_ODPP_RJ14,GPIO_ODPP_RJ13
				  ,GPIO_ODPP_RJ12,GPIO_ODPP_RJ11,GPIO_ODPP_RJ10
				  ,GPIO_ODPP_RJ9,GPIO_ODPP_RJ8,GPIO_ODPP_RJ7
				  ,GPIO_ODPP_RJ6,GPIO_ODPP_RJ5,GPIO_ODPP_RJ4
				  ,GPIO_ODPP_RJ3,GPIO_ODPP_RJ2,GPIO_ODPP_RJ1
				  ,GPIO_ODPP_RJ0);

}

void GPIO_vidSetPinDirection (GPIO_Register* stPortCpy , u8 u8PinCpy , u8 u8PinDirectionCpy)
{
 if (u8PinDirectionCpy == GPIO_INPUT)
 {
	 stPortCpy->MODER |= GPIO_INPUT_MODE <<(u8PinCpy*2);
	 /*As Pull Down*/
	 stPortCpy->PUPDR |= GPIO_PULL_DOWN << (u8PinCpy*2);
 }
 else if (u8PinDirectionCpy == GPIO_OUTPUT)
 {
     stPortCpy->MODER |= GPIO_OUTPUT_MODE <<(u8PinCpy*2);
     /*Push Pull*/
     CLEAR_BIT(stPortCpy->OTYPER,u8PinCpy);
 }
 else
 {
 }
}

void GPIO_vidSetPinValue (GPIO_Register* stPortCpy , u8 u8PinCpy , u8 u8ValueCpy )
{
     if (u8ValueCpy == GPIO_HIGH)
     {
        SET_BIT(stPortCpy->BSRR,u8PinCpy);
     }
     else if (u8ValueCpy == GPIO_LOW)
     {
         SET_BIT(stPortCpy->BSRR,(u8PinCpy+16));
     }
     else
     {

     }
}

/*Description : For Setting Port value and direction*/

void GPIO_vidSetPortDirection (GPIO_Register* stPortCpy , u8 u8DirectionCpy )
{
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<16;Loc_u8Iteration++)
	{
		GPIO_vidSetPinDirection(stPortCpy,Loc_u8Iteration,u8DirectionCpy);
	}
/*
     if (u8DirectionCpy == GPIO_OUTPUT)
     {
    	    stPortCpy->MODER |= GPIO_OUTPUT_MODE <<(u8PinCpy*2);
    	     Push Pull
    	     CLEAR_BIT(stPortCpy->OTYPER,u8PinCpy);

    	    stPortCpy->MODER = 	GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|
    	    					GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|
				   	   	   	   	GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|
				       	    	GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE|GPIO_OUTPUT_MODE ;

     }
     else if(u8DirectionCpy == GPIO_INPUT)
     {
        (*(volatile u8*)(u32PortCpy+GPIO_PORT2TRIS)) = GPIO_PORT_HIGH ;
     }
     else
     {

     }
*/
}

void GPIO_vidSetPortValue (GPIO_Register* stPortCpy , u16 u16ValueCpy )
{
	stPortCpy->ODR = u16ValueCpy;
}

/*Description : For getting value from pin or port      */

u16 GPIO_u16GetPinValue (GPIO_Register* stPortCpy , u8 u8PinCpy )
{
   return GET_BIT(stPortCpy->IDR,u8PinCpy);
}

u16 GPIO_u16GetPortValue (GPIO_Register* stPortCpy)
{
   return  stPortCpy->IDR;
}

/*Description : For Toggling pin or port      */
void GPIO_vidTogglePin(GPIO_Register* stPortCpy , u8 u8PinCpy )
{
     TOGGLE_BIT(stPortCpy->ODR,u8PinCpy);
}

void GPIO_vidTogglePort(GPIO_Register* stPortCpy)
{
    stPortCpy->ODR ^= 0XFFFF ;
}

