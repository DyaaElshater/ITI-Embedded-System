/*
 * EX0_prog.c
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "EXT0_int.h"
#include "EXT0_cfg.h"
#include "EXT0_priv.h"

static vidpfvid EXT0_pfCallBack ;

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXT0_pfCallBack	();
}

 static void start (void)
{

}

void EXT0_vidInit(void)
{
		/*Mode*/
#if SENSE_MODE == EXT0_u8RISING_EDGE
	MCUCR |= 0x03 ;
#elif SENSE_MODE == EXT0_u8FALLING_EDGE
	MCUCR &= 0xFC ;				/*clear last two bits for ISC00 ISC01*/
	MCUCR |= 0x02 ;				/*Setting ISC01 */
#elif SENSE_MODE == EXT0_u8IOC
	MCUCR &= 0xFC ;				/*clear last two bits for ISC00 ISC01*/
	MCUCR |= 0x01 ;				/*Setting ISC00 */
#elif SENSE_MODE == EXT0_u8LOW_LEVEL
	MCUCR &= 0xFC ;
#else
	#error "Wrong Configuration for SENSE_MODE	...	"
#endif

	GICR &= 0xBF;	/*Disable INT0*/

	GIFR |= 0x40 ;



	EXT0_pfCallBack = start;



}


void EXT0_vidEnable(void)
{
		/*SET_BIT(GICR,6);*/
	GICR |= 0x40;

}

void EXT0_vidDisable(void)
{
		/*CLEAR_BIT(GICR,6);*/
	GICR &= 0xBF;

}

void EXT0_vidSetCallBack(vidpfvid pfAddressCpy)
{
	EXT0_pfCallBack = pfAddressCpy;
}

void EXT0_vidChangeMode(u8 u8ModeCpy)
{

	if ( u8ModeCpy == EXT0_u8RISING_EDGE )
	{
			MCUCR |= 0x03 ;
	}
	else if (u8ModeCpy == EXT0_u8FALLING_EDGE)

	{
		MCUCR &= 0xFC ;				/*clear last two bits for ISC00 ISC01*/
		MCUCR |= 0x02 ;				/*Setting ISC01 */
	}
	else if ( u8ModeCpy == EXT0_u8IOC )
	{
		MCUCR &= 0xFC ;				/*clear last two bits for ISC00 ISC01*/
		MCUCR |= 0x01 ;				/*Setting ISC00 */

	}
	else if ( u8ModeCpy == EXT0_u8LOW_LEVEL )
	{
		MCUCR &= 0xFC ;
	}
	else
	{

	}


}

u8 EXT0_u8GetFlag(void)
{
	return GET_BIT(GIFR,6);
}
