/*
 * INTmain.c
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "EXT0_int.h"
#include "EXT1_int.h"
#include "EXT2_int.h"

#define F_CPU 8000000ul
#include <avr/delay.h>

static u8 u8iteration;

void ext0(void);
void ext1(void);
void ext2(void);

int main()
{

	DIO_enuSetPinDirection(DIO_u8PIN_26,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PIN_27,DIO_u8INPUT);
	DIO_enuSetPinDirection(DIO_u8PIN_10,DIO_u8INPUT);

	DIO_enuPullUp(DIO_u8PIN_26);
	DIO_enuPullUp(DIO_u8PIN_27);
	DIO_enuPullUp(DIO_u8PIN_10);


	EXT0_vidInit();
	EXT0_vidEnable();
	EXT0_vidSetCallBack(ext0);

	EXT1_vidInit();
	EXT1_vidEnable();
	EXT1_vidSetCallBack(ext1);



	EXT2_vidInit();
	EXT2_vidEnable();
	EXT2_vidSetCallBack(ext2);

	GIE_vidEnable();
	while(1)
	{
//		DIO_enuSetPortX(0xff&~(1<<(u8iteration++)%8));
//		_delay_ms(500);
	}
	return 0;
}

void ext0(void)
{
	DIO_enuSetPortX(1<<(u8iteration++)%8);
//	_delay_ms(1500);
}
void ext1(void)
{
	DIO_enuSetPortX(1<<(u8iteration--)%8);
//	_delay_ms(1500);
}
void ext2(void)
{
	DIO_enuSetPortX(3<<(u8iteration++)%8);
//	_delay_ms(1500);
}
