/*
 * main.c
 *
 *  Created on: Aug 26, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "I2C_int.h"

#include "EEPROM_int.h"
#include "LCD_int.h"

#include "avr/delay.h"

int main()
{

	EEPROM_vidInit();
	LCD_enuSetLCD();
	LCD_enuInit(0);

	u8 RecievedData;
	EEPROM_vidReadByte(0x0000,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0001,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0002,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0003,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0004,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0005,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0006,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0007,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0008,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);
	EEPROM_vidReadByte(0x0009,&RecievedData);
	LCD_enuWriteChar(RecievedData,0);


	while(1)
	{

	}
	return 0;
}

