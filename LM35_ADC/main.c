/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_int.h"
#include "ADC_int.h"

#include "LCD_int.h"


int main()
{
	ADC_vidInit();
	LCD_enuSetLCD();
	LCD_enuInit(1);
/*	LCD_enuWriteString("Temperature = ",0);*/
	DIO_enuSetPinDirection(DIO_u8PIN_7,DIO_u8OUTPUT);
	DIO_enuSetPinValue(DIO_u8PIN_7,DIO_u8HIGH);
	while(1)
	{

		u8 Loc_u8DigitalValue = (ADC_u8Read(0)>>8);
		LCD_enuGoToXY(0,14,0);
		u16 Loc_u8AnalogValue = (Loc_u8DigitalValue * 5000)/256 ;
		DIO_enuSetPortX(Loc_u8AnalogValue);
//		Loc_u8AnalogValue/=10 ;		/*for temp value */
/*
		u16 i = 1000;
		while(i)
		{
			LCD_enuWriteChar((Loc_u8AnalogValue/i)+'0',0);
			Loc_u8AnalogValue %= i ;
			i/=10;
		}
*/


	}
	return 0;
}
