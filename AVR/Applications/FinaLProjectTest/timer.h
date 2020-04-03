/*
 * timer.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Dyaa Elshater
 */

#ifndef TIMER_H_
#define TIMER_H_
void Timer1_init();
void Timer1_vidChangeOCR1AValue(u16 u16OCR1AValueCpy);
void TIMER1_vidSetCallback(vidpfvid pfFunctionCpy,u8 u8IntNbCpy);


#endif /* TIMER_H_ */
