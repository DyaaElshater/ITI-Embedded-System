/*
 * I2C_priv.h
 *
 *  Created on: Aug 21, 2019
 *      Author: Dyaa Elshater
 */

#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_


#define TWBR (*(volatile u8*)0x20) 
#define TWSR (*(volatile u8*)0x21) 
#define TWAR (*(volatile u8*)0x22) 
#define TWDR (*(volatile u8*)0x23) 
#define TWDR (*(volatile u8*)0x23) 
#define TWCR (*(volatile u8*)0x56)


	/*Registers bits*/
	/*TWBR*/
#define TWBR7 7
#define TWBR6 6
#define TWBR5 5
#define TWBR4 4
#define TWBR3 3
#define TWBR2 2
#define TWBR1 1
#define TWBR0 0

	/*TWCR*/
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3
#define TWEN  2
 
#define TWIE  0

	/*TWSR*/
#define TWS7 7
#define TWS6 6
#define TWS5 5
#define TWS4 4
#define TWS3 3

#define TWPS1 1
#define TWPS0 0

	/*TWAR*/
#define TWGCE 0

#endif /* I2C_PRIV_H_ */
