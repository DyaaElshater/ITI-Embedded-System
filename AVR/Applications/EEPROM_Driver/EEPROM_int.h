/*
 * EEPROM_int.h
 *
 *  Created on: Aug 22, 2019
 *      Author: Dyaa Elshater
 */

#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

void EEPROM_vidInit(void);

void EEPROM_vidWriteByte(u16 u16Location , u8 u8Data);

void EEPROM_vidReadByte(u16 u16Location , u8 * pu8Data);


#endif /* EEPROM_INT_H_ */
