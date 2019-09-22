/*
 * I2C_int.h
 *
 *  Created on: Aug 21, 2019
 *      Author: Dyaa Elshater
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_


void I2C_vidInit(u8 MyAddress);

void I2C_vidSendStart(void);

void I2C_vidSendStop(void);

void I2C_vidSla_W(u8 Sla);

void I2C_vidSla_R(u8 Sla);

void I2C_vidSendData(u8 Data);

u8 I2C_u8ReceiveData_WithNoAck(void);

u8 I2C_u8CheckStatus(u8 ExpectedStatus);

#endif /* I2C_INT_H_ */
