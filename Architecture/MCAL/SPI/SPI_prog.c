/*
 * SPI_prog.c
 *
 *  Created on: Aug 5, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "SPI_int.h"
#include "SPI_priv.h"
#include "SPI_cfg.h"




void SPI_vidMastrInit(void)
{
	SET_BIT(SPCR,SPE);		/*Enable SPI*/

	CLEAR_BIT(SPCR,DORD);	/*MSB First*/

	SET_BIT(SPCR,MSTR);		/*Master mode*/

	CLEAR_BIT(SPCR,CPOL);	/*Leadinf edge is rising*/
	SET_BIT(SPCR,CPHA);		/*Setup first*/

	SET_BIT(SPCR,SPR1);		/*Clock -> Fosc/128*/
	SET_BIT(SPCR,SPR0);		/*Clock -> Fosc/128*/

	CLEAR_BIT(SPSR,SPI2X);	/*Clock -> Fosc/128*/


}

void SPI_vidSlaveInit(void)
{
	SET_BIT(SPCR,SPE);		/*Enable SPI*/

	CLEAR_BIT(SPCR,DORD);	/*MSB First*/

	CLEAR_BIT(SPCR,MSTR);	/*Slave mode*/

	CLEAR_BIT(SPCR,CPOL);	/*Leadinf edge is rising*/
	SET_BIT(SPCR,CPHA);		/*Setup first*/

	SET_BIT(SPCR,SPR1);		/*Clock -> Fosc/128*/
	SET_BIT(SPCR,SPR0);		/*Clock -> Fosc/128*/

	CLEAR_BIT(SPSR,SPI2X);	/*Clock -> Fosc/128*/

}

u8 SPI_u8Transfer(u8 Byte)
{
	SPDR= Byte;
	while(GET_BIT(SPSR,SPIF)==0);	//read spsr with spif flag is high
	return SPDR;	// access the data register
}

/*****************************/
#include "DIO_int.h"
/****************************/


void SPI_vidSlaveSelect(void)
{

	/*****************************/
	DIO_enuSetPinValue(DIO_u8PIN_11,DIO_u8LOW);	/*enable ss*/
	/****************************/

}
