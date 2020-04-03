/*
 * main.c
 *
 *  Created on: Aug 27, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "TIMER0_int.h"
#include "DIO_int.h"

#include "KEYBAD_int.h"

int main()
{
	TIMER0_enuInit(1000000);
	KEYBAD_enuInit();
	while(1)
	{
		u8 Loc_u8Value=0;

		TIMER0_enuChangePwmDutyCycle(200);
/*
		if(KEYBAD_enuGetPressedKey(&Loc_u8Value)==PRESSED)
		{
			if ('0'<=Loc_u8Value && Loc_u8Value <= '9')
			{
				TIMER0_enuChangePwmDutyCycle((Loc_u8Value-'0')*25);
			}
			else
			{
				TIMER0_enuChangePwmDutyCycle(255);
			}
		}
*/

	}
	return 0;
}
