/*
 * main.c
 *
 *  Created on: Jul 24, 2019
 *      Author: Dyaa Elshater
 */
#include "F:\Courses\Embedded ITI\Lab\Lec\Architecture\lib\Bit_Math.h"
#include "F:\Courses\Embedded ITI\Lab\Lec\Architecture\lib\Std_types.h"

#include <avr/io.h>
#define F_CPU 8000000ul
#include <avr/delay.h>
enum USERS{user1=0,user2=1,user3=2};
u8 LCD_name[3]= {
			 /*GFEDCBA*/
			0b10001000,
			0b10000000,
			0b11000110	};

int main()
{
	//PORTA Switches
	//PORTB BUZZER
	//PORTC LEDs
	//PORTD 7Segment
DDRA=0;
PORTA=0xff;
DDRB=0xff;
DDRC=0xff;
DDRD=0xff;
PORTB=0;
while(1)
	{
		if(PINA==0b01000011)	// 60 + enter bit
		{
			PORTD = LCD_name[user1];
			PORTC = 60;
		}
		else if (PINA==0b01001111)	//48 + enter bit
		{
			PORTD = LCD_name[user2];
			PORTC = 48;
		}
		else if (PINA==0b01011011)	//36 + enter bit
		{
			PORTD = LCD_name[user3];
			PORTC = 36;
		}
		else if (!(PINA&(1<<7)))
		{	/*BUZZER*/
			PORTD=0xff;
			PORTC=0x01;
			PORTB = 1;
		}
		else
		{
			PORTD=0xff;
			PORTC=0x00;
			PORTB = 0;
		}
	}
}
