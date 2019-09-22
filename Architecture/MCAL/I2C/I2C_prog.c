/*
 * I2C_prog.c
 *
 *  Created on: Aug 21, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "I2C_int.h"
#include "I2C_cfg.h"
#include "I2C_priv.h"

void I2C_vidInit(u8 MyAddress)
{
	/*For 100K HZ*/
	TWBR = 8;
	TWSR = 0;
	/*Enable I2C*/
	SET_BIT(TWCR,TWEN);
	/*Adding slave address*/
	TWAR = MyAddress<<1 ;
}

void I2C_vidSendStart(void)
{

	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0);
}

void I2C_vidSendStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void I2C_vidSla_W(u8 Sla)
{
	TWDR = Sla<<1 ;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0);
}

void I2C_vidSla_R(u8 Sla)
{
	TWDR = (Sla<<1)|1 ;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0);
}

void I2C_vidSendData(u8 Data)
{
	TWDR = Data ;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0);
}

u8 I2C_u8ReceiveData_WithNoAck(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR,TWINT)==0);
	return TWDR ;
}

u8 I2C_u8CheckStatus(u8 ExpectedStatus)
{
	u8 Loc_returnValue ;
	if((TWSR & 0xF8)==ExpectedStatus)
	{
		Loc_returnValue = 1 ;
	}
	else
	{
		Loc_returnValue = 0;
	}
	return Loc_returnValue ;
}
