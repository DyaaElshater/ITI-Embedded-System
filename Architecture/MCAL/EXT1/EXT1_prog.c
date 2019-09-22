/*
 * EX0_prog.c
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "EXT1_int.h"
#include "EXT1_cfg.h"
#include "EXT1_priv.h"

static vidpfvid EXT1_pfCallBack ;

void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	EXT1_pfCallBack	();
}

 static void start (void)
{

}

 void EXT1_vidInit(void)
{
		/*Mode*/
#if SENSE_MODE == EXT1_u8RISING_EDGE
	MCUCR |= 0x0C ;
#elif SENSE_MODE == EXT1_u8FALLING_EDGE
	MCUCR &= 0xF3 ;				/*clear last two bits for ISC00 ISC01*/
	MCUCR |= 0x08 ;				/*Setting ISC01 */
#elif SENSE_MODE == EXT1_u8IOC
	MCUCR &= 0xF3 ;				/*clear last two bits for ISC00 ISC01*/
	MCUCR |= 0x04 ;				/*Setting ISC00 */
#elif SENSE_MODE == EXT1_u8LOW_LEVEL
	MCUCR &= 0xF3 ;
#else
	#error "Wrong Configuration for SENSE_MODE	...	"
#endif

	GICR &= 0x7F;	/*Disable INT0*/

	GIFR |= 0x80 ;

	EXT1_pfCallBack = 	start;

}


void EXT1_vidEnable(void)
{
		/*SET_BIT(GICR,6);*/
	GICR |= 0x80 ;

}

void EXT1_vidDisable(void)
{
		/*CLEAR_BIT(GICR,6);*/
	GICR &= 0x7F;
}

void EXT1_vidSetCallBack(vidpfvid pfAddressCpy)
{
	EXT1_pfCallBack = pfAddressCpy;
}

void EXT1_vidChangeMode(u8 u8ModeCpy)
{

	if ( u8ModeCpy == EXT1_u8RISING_EDGE )
	{
			MCUCR |= 0x0C ;
	}
	else if (u8ModeCpy == EXT1_u8FALLING_EDGE)

	{
		MCUCR &= 0xF3 ;				/*clear last two bits for ISC00 ISC01*/
		MCUCR |= 0x08 ;				/*Setting ISC01 */
	}
	else if ( u8ModeCpy == EXT1_u8IOC )
	{
		MCUCR &= 0xF3 ;				/*clear last two bits for ISC00 ISC01*/
		MCUCR |= 0x04 ;				/*Setting ISC00 */

	}
	else if ( u8ModeCpy == EXT1_u8LOW_LEVEL )
	{
		MCUCR &= 0xF3 ;
	}
	else
	{

	}
}

u8 EXT1_u8GetFlag(void)
{
	return GET_BIT(GIFR,7);
}
