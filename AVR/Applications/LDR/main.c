/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Dyaa Elshater
 */
#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_int.h"
#include "TIMER0_int.h"
#include "ADC_int.h"


int main()
{
	TIMER0_enuInit(1000000);
	ADC_vidInit();
	while(1)
	{
		u8 value = ADC_u8Read(0)>>8;
		TIMER0_enuChangePwmDutyCycle(value);
	}
	return 0;
}

