/*
 * EX0_prog.c
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "EXT2_cfg.h"
#include "EXT2_int.h"
#include "EXT2_priv.h"

static vidpfvid EXT2_pfCallBack ;

void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	EXT2_pfCallBack	();
}

 static void start (void)
{

}

void EXT2_vidInit(void)
{
		/*Mode*/
#if SENSE_MODE == EXT2_u8RISING_EDGE
	MCUCSR |= 0x40 ;
#elif SENSE_MODE == EXT2_u8FALLING_EDGE
	MCUCSR &= 0xBF ;
#else
	#error "Wrong Configuration for SENSE_MODE	...	"
#endif

	GICR &= 0xDF;	/*Disable INT2*/

	GIFR |= 0x20 ;



	EXT2_pfCallBack = start;



}


void EXT2_vidEnable(void)
{
		/*SET_BIT(GICR,6);*/
	GICR |= 0x20;

}

void EXT2_vidDisable(void)
{
		/*CLEAR_BIT(GICR,6);*/
	GICR &= 0xDF;

}

void EXT2_vidSetCallBack(vidpfvid pfAddressCpy)
{
	EXT2_pfCallBack = pfAddressCpy;
}

void EXT2_vidChangeMode(u8 u8ModeCpy)
{

	if ( u8ModeCpy == EXT2_u8RISING_EDGE )
	{
		MCUCSR |= 0x40 ;
	}

	else if (u8ModeCpy == EXT2_u8FALLING_EDGE)
	{
		MCUCSR &= 0xBF ;
	}
	else
	{

	}


}

u8 EXT2_u8GetFlag(void)
{
	return GET_BIT(GIFR,5);
}
