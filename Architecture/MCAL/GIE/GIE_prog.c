/*
 * GIE_prog.c
 *
 *  Created on: Aug 6, 2019
 *      Author: Dyaa Elshater
 */
#include "Std_types.h"
#include "Bit_Math.h"

#include "GIE_int.h"
#include "GIE_priv.h"
void GIE_vidEnable	(void)
{
	SREG |= 0x80;
}

void GIE_vidDisable	(void)
{

	SREG &= ~(0x80);
}


