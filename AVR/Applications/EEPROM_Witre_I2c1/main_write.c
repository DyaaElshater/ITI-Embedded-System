/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "I2C_int.h"
#include "DIO_int.h"

#include "EEPROM_int.h"
#include "LCD_int.h"

#include "avr/delay.h"

int main()
{

	EEPROM_vidInit();
	LCD_enuSetLCD();
	LCD_enuInit(0);
	LCD_enuWriteString("Writing ... ",0);

	EEPROM_vidWriteByte(0x0000,'D');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0001,'Y');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0002,'A');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0003,'A');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0004,' ');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0005,' ');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0006,' ');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0007,' ');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0008,' ');
	_delay_ms(5);
	EEPROM_vidWriteByte(0x0009,' ');
	_delay_ms(5);

	LCD_enuWriteString("Done",0);



	while(1)
	{

	}
	return 0;
}

