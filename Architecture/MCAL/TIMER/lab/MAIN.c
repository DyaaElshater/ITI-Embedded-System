

#include "Std_types.h"
#include "Bit_Math.h"

#include <avr/interrupt.h>

#include "timer.h"
#include "DIO_int.h"

void main()
{
	DIO_enuSetPinDirection(DIO_u8PIN_0,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(DIO_u8PIN_7,DIO_u8OUTPUT);

	Timer1_init();
	while(1)
	{

	}

}

ISR(TIMER1_COMPA_vect)
{
/*	DIO_enuSetPinValue(DIO_u8PIN_7,DIO_u8HIGH);*/
	static u16 counter = 0;
	counter++;
	if(counter==1000)
	{
		counter=0;
		DIO_enuTogglePin(DIO_u8PIN_0);
	}
}
