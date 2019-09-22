/*
 * UART_priv.h
 *
 *  Created on: Jul 31, 2019
 *      Author: Dyaa Elshater
 */

#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UDR 	*((volatile u8*)0x2C)
#define UCSRA 	*((volatile u8*)0x2B)
#define UCSRB	*((volatile u8*)0x2A)
#define UCSRC 	*((volatile u8*)0x40)
#define UBRRH 	*((volatile u8*)0x40)
#define UBRRL 	*((volatile u8*)0x29)


#define UDRE 5
#define RXC 7


#define TXEN 3
#define RXEN 4
#define UCSZ2 2

#define UCSZ0 1
#define UCSZ1 2
#define USBS  0
#define USBS  3
#define UPM0  4
#define UPM1  5
#define UMSEL 6
#define URSEL 7


#endif /* UART_PRIV_H_ */
