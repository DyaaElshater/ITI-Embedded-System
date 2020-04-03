/*
 * APP_int.h
 *
 *  Created on: Sep 9, 2019
 *      Author: Dyaa Elshater
 */

#ifndef APP_INT_H_
#define APP_INT_H_

void POV_vidWriteChar(u8 u8CharCpy);

void POV_vidWriteString(u8 * pu8StringCpy);

void POV_vidSpecificChar(void);

void POV_vidStart(void);

void POV_vidClearLastChar(void);

void POV_vidGoToIndex(u8 u8IndxCpy);

void POV_vidClearAll(void);

#endif /* APP_INT_H_ */
