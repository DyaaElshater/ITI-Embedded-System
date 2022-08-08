/*
 * KEYBOARD_INT.h
 *
 *  Created on: Jun 21, 2022
 *      Author: Dyaa Elshater
 */

#ifndef KEYBOARD_INT_H_
#define KEYBOARD_INT_H_



void Keyboard_vidInit();
void Keyboard_vidPressKey(uint8_t pu8Char);
void Keyboard_vidClearChars();
void Keyboard_vidSendReport();



#endif /* KEYBOARD_INT_H_ */
