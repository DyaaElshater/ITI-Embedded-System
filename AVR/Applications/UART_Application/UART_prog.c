/*
 * UART_prog.c
 *
 *  Created on: Jul 31, 2019
 *      Author: Dyaa Elshater
 */


#include "Std_types.h"
#include "Bit_Math.h"

#include "UART_int.h"
#include "UART_priv.h"


void UART_vidInit()
{
	/*Enable the rx and tx */
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
	CLEAR_BIT(UCSRB,UCSZ2);

	u8 Loc_u8RegValue = 0b10000000;
	CLEAR_BIT(Loc_u8RegValue,UMSEL);
	CLEAR_BIT(Loc_u8RegValue,USBS);
	CLEAR_BIT(Loc_u8RegValue,UPM0);
	CLEAR_BIT(Loc_u8RegValue,UPM1);

	SET_BIT(Loc_u8RegValue,UCSZ1);
	SET_BIT(Loc_u8RegValue,UCSZ0);
	UCSRC = Loc_u8RegValue;
	UBRRH=0;
	UBRRL = 51;

}
void UART_vidSendByte(u8 Byte)
{
	while(GET_BIT(UCSRA,UDRE)==0);
	UDR = Byte;
}
u8 UART_vidRecieveByte()
{
	while(GET_BIT(UCSRA,RXC)==0);
	return UDR;
}


