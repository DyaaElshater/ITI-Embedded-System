/*
 * UART_int.h
 *
 *  Created on: Jul 31, 2019
 *      Author: Dyaa Elshater
 */

#ifndef _UART_INT_H_
#define _UART_INT_H_
/*fOR sTOP BIT CONFIGURATION*/
#define _1BIT 0x00
#define _2Bits 0x08

#define _5_BITS_SIZE	0x00
#define _6_BITS_SIZE	0x01
#define _7_BITS_SIZE	0x02
#define _8_BITS_SIZE	0x03
#define _9_BITS_SIZE	0x0E


void UART_vidInit();
void UART_vidSendByte(u8 Byte);
u8 UART_vidRecieveByte();



#endif
