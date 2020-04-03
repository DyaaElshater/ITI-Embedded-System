/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : LED Interface File         */
/*********************************************/

#ifndef _LED_INT_H_
#define _LED_INT_H_

#define LED_COM_GND 0
#define LED_COM_VCC 1

void LED_vidLedOn(u32 u32PortCpy,u8 u8PinCpy);

void LED_vidLedOff(u32 u32PortCpy,u8 u8PinCpy);

void LED_vidToggle(u32 u32PortCpy,u8 u8PinCpy);

#endif