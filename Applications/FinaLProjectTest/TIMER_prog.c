/*
 * TIMER_prog.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Dyaa Elshater
 */


#include "Std_types.h"
#include "Bit_Math.h"

#include "timer.h"
#include "TIMER_priv.h"
#include "avr/interrupt.h"

/*#include "avr/interrupt.h"*/

static vidpfvid callback[8];

void Timer1_init()
{
/*	u16 OCR_value = 1000;*/
		/*CTC Mode*/
	CLEAR_BIT(TCCR1A,1);
	CLEAR_BIT(TCCR1A,0);

	CLEAR_BIT(TCCR1B,4);
	SET_BIT(TCCR1B,3);

	TCNT1H=0;
	TCNT1L=0;

/*
	OCR1AH = OCR_value >> 8	;
	OCR1AL = OCR_value 		;
*/

	SET_BIT(SREG,7);

	SET_BIT(TIMSK,4);

	/*Setting prescaller to 8*/
	CLEAR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLEAR_BIT(TCCR1B,0);

}

void Timer1_vidChangeOCR1AValue(u16 u16OCR1AValueCpy)
{
	OCR1AH = u16OCR1AValueCpy >> 8	;
	OCR1AL = u16OCR1AValueCpy 		;

}

void TIMER1_vidSetCallback(vidpfvid pfFunctionCpy,u8 u8IntNbCpy)
{
	callback[u8IntNbCpy]=pfFunctionCpy;
}


ISR(TIMER1_COMPA_vect)
{

	SET_BIT(SREG,7); 	/*Setting Global INT on to be Preemptive*/
	callback[3]();

}

