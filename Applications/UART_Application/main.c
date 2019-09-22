/*
 * main.c
 *
 *  Created on: Jul 31, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"


#include "DIO_int.h"

#include "UART_int.h"

#define F_CPU 8000000ul
#include <avr/delay.h>

int main()
{
	DIO_enuSetPinDirection(DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PIN_2,DIO_u8OUTPUT);

	UART_vidInit();
	while(1)
	{

		UART_vidSendByte('a');
		_delay_ms(1000);
		UART_vidSendByte('b');
		_delay_ms(1000);
	}

}

