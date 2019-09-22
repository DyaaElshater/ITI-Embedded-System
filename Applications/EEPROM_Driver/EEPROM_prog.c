/*
 * EEPROM_prog.c
 *
 *  Created on: Aug 22, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "I2C_int.h"

#include "EEPROM_int.h"
#include "EEPROM_cfg.h"
#include "EEPROM_priv.h"

void EEPROM_vidInit(void)
{
	I2C_vidInit(1);
}

void EEPROM_vidWriteByte(u16 u16Location , u8 u8Data)
{
	u8 Sla = ((0b00101000)|(u16Location>>8));
	I2C_vidSendStart();
	if(I2C_u8CheckStatus(0x08)==1)
	{
		I2C_vidSla_W(Sla);
		if(I2C_u8CheckStatus(0x18)==1)
		{
			I2C_vidSendData((u8)u16Location);
			if(I2C_u8CheckStatus(0x28)==1)
			{
				I2C_vidSendData(u8Data);
				if(I2C_u8CheckStatus(0x28)==1)
				{
					I2C_vidSendStop();
				}
			}
		}
	}
}

void EEPROM_vidReadByte(u16 u16Location , u8 * pu8Data)
{
	u8 Sla = ((0b00101000)|(u16Location>>8));
	I2C_vidSendStart();
	if(I2C_u8CheckStatus(0x08)==1)
	{
		I2C_vidSla_W(Sla);
		if(I2C_u8CheckStatus(0x18)==1)
		{
			I2C_vidSendData((u8)u16Location);
			if(I2C_u8CheckStatus(0x28)==1)
			{
				I2C_vidSendStart(); 	/*Repeated Start*/
				if(I2C_u8CheckStatus(0x10)==1)
				{
					I2C_vidSla_R(Sla);
					if(I2C_u8CheckStatus(0x40)==1)
					{
						* pu8Data = I2C_u8ReceiveData_WithNoAck();
						if(I2C_u8CheckStatus(0x50)==1)
						{
							I2C_vidSendStop();
						}
					}
				}
			}
		}
	}
}
