/*
 * main.c
 *
 *  Created on: Sep 8, 2019
 *      Author: Dyaa Elshater
 */
#include "Bit_Math.h"
#include "Std_types.h"

#include "APP_int.h"
#include "avr/delay.h"

#include "DIO_int.h"

#include "RTO_int.h"

/*************** TEST *****************/
/*
#define F_CPU 8000000ul
#include "avr/delay.h"
*/
//*************************************/


int main(void)
{
//	POV_vidSpecificChar();

	POV_vidWriteString("THANKS ITI");

	POV_vidStart();

	while(1)
	{
/*
		POV_UpdateLeds();
*/

	}
	return 0;
}
