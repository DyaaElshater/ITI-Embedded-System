/*
 * DELAY.c
 *
 *  Created on: Jun 16, 2020
 *      Author: Dyaa Elshater
 */


/*
 * DELAY.h
 *
 *  Created on: Jun 13, 2020
 *      Author: Dyaa Elshater
 */

	/*The delay for 8 MHZ Frequency*/
#ifndef DELAY_H_
#define DELAY_H_

#include "DELAY.h"

typedef struct
{
	unsigned int CTRL;
	unsigned int LOAD;
	unsigned int VAL;
	unsigned int CALIB;
}STK_Reg;

#define SYSTICK ((volatile STK_Reg *)(0XE000E010))
static unsigned char __SYSTICK_Flag_ =0;

void Delay_vidInit()
{
	/*Enable exception + clock source = processor clk*/
	SYSTICK->CTRL = 6;
}

void Delay_us(unsigned int u32DelValueCpy)
{
	/*clk cycle = 125 ns -> 1 us = clk * 8  */

	SYSTICK->LOAD = u32DelValueCpy<<3;

	/*Enable Systick to start*/
	SYSTICK->CTRL |=1;
	while(! __SYSTICK_Flag_);
	__SYSTICK_Flag_ =0;

	/*Disable Systick to stop*/
	SYSTICK->CTRL &= ~(1);
}

void Delay_ms(unsigned int u32DelValueCpy)
{
	while(u32DelValueCpy)
	{
		Delay_us(1000);
		u32DelValueCpy--;
	}
}
void Delay_s(unsigned int u32DelValueCpy)
{
	while(u32DelValueCpy)
	{
		Delay_ms(1000);
		u32DelValueCpy--;
	}
}
void SysTick_Handler(void)
{
	__SYSTICK_Flag_ =1;
}
#endif /* DELAY_H_ */
