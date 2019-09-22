/*
 * SPI_priv.h
 *
 *  Created on: Aug 5, 2019
 *      Author: Dyaa Elshater
 */

#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPCR *((volatile u8*)0x2D)
#define SPSR *((volatile u8*)0x2E)
#define SPDR *((volatile u8*)0x2F)



	/*	Define the bits	*/
	/*SPCR*/
#define SPIE	7 
#define SPE 	6
#define DORD	5
#define MSTR	4
#define CPOL	3
#define CPHA	2
#define SPR1	1
#define SPR0	0

	/*SPSR*/
#define SPIF	7
#define WCOL	6
#define SPI2X	0



#endif /* SPI_PRIV_H_ */
