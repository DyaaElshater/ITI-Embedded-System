/*
 * main.c
 *
 *  Created on: Jul 22, 2019
 *      Author: Dyaa Elshater
 */
#define ARRAY_SIZE 10;
#include <avr/io.h>
#define F_CPU 8000000ul
#include <avr/delay.h>
char sevseg[]={
		  /*0bHGFEDCBA*/
			0b11000000,	//0
			0b11111001,	//1
			0b10100100,	//2
			0b10110000,	//3
			0b10011001,	//4
			0b10010010,	//5
			0b10000010,	//6
			0b11111000,	//7
			0b10000000,	//8
			0b10010000,	//9
		};
int main()
{

	int i;
	DDRA=0xff;while(1)
	{
		for(i=0;i<10;i++)
		{
			PORTA = sevseg[i];
			_delay_ms(500);
		}
	}
	return 0;
}
