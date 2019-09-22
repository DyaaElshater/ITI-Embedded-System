/*
 * main.c
 *
 *  Created on: Aug 23, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_int.h"
#include "TIMER0_int.h"


int main()
{
	DIO_enuInt();
	TIMER0_enuInit(1000000);
	TIMER0_enuChangePwmDutyCycle(0);
	while(1);
	return 0;
}
