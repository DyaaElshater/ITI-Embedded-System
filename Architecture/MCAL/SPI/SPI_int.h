/*
 * SPI_int.h
 *
 *  Created on: Aug 5, 2019
 *      Author: Dyaa Elshater
 */

#ifndef SPI_INT_H_
#define SPI_INT_H_



void SPI_vidMastrInit(void);

void SPI_vidSlaveInit(void);

u8 SPI_u8Transfer(u8 Byte);

void SPI_vidSlaveSelect(void);

#endif /* SPI_INT_H_ */
