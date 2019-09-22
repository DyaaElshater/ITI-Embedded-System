
#include "Bit_Math.h"
#include "Std_types.h"


#include "DIO_int.h"
#include "ADC_int.h"
#include "TIMER0_int.h"

#include "UART_int.h"

#define F_CPU 8000000ul
#include  <avr/delay.h>

int main()
{

	UART_vidInit();
	ADC_vidInit();
	TIMER0_enuInit(1000000);
	while(1)
	{
		u8 Loc_u8Data = ADC_u8Read(0) >>8 ;
//		UART_vidSendByte(Loc_u8Data);
		UART_vidSendByte('D');

		_delay_ms(1000);
		TIMER0_enuChangePwmDutyCycle(Loc_u8Data);
	}
	return 0;
}
