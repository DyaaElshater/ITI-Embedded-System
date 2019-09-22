/*
 * main.c
 *
 *  Created on: Aug 1, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"
/*MCAL*/
#include "DIO_int.h"
#include "UART_int.h"
/*HAL*/
#include "LCD_int.h"


/*	Timer			*/
#define NO_OVERFLOW 3907
#define PRELOAD 192
#include <avr/io.h>
#include <avr/interrupt.h>
u32 u16Counter=0;
/*******************/

int main()
{
	LCD_enuSetLCD();
	LCD_enuInit(0);

/*	TCNT0 = PRELOAD ;*/
	UART_vidInit();
	/*LCD_enuWriteString("Enter char : ",0);*/
/*

	CLEAR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS01);
	TIMSK = 1<< TOV0;
	SET_BIT(SREG,7);

*/
	DIO_enuSetPinDirection(DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PIN_7,DIO_u8OUTPUT);

	while(1)
	{

		LCD_enuWriteChar(UART_vidRecieveByte(),0);

	}
	return 0;
}
/*
ISR(TIMER0_OVF_vect)
{
	u16Counter++;
	if(u16Counter>=NO_OVERFLOW)
	{

		TCNT0 = PRELOAD;
		UART_vidSendByte('D');
		UART_vidSendByte('Y');
		UART_vidSendByte('A');
		UART_vidSendByte('A');
		u16Counter=0;
	}
}
*/
