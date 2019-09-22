/*
 * APP.c
 *
 *  Created on: Aug 5, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

	/*MACL*/
#include "DIO_int.h"
	/*HAL*/

	/*App Prototypes*/
#include "APP.h"

	/*App implementations*/
u8 u8Seconds=0,u8Minutes=0,u8Hours=0;
u8 u8MinEdit=0,u8HEdit=0;


void fun (void)
{
	DIO_enuTogglePin(DIO_u8PIN_20);
}
