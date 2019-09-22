/*
 * TIMER_priv.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Dyaa Elshater
 */

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_


#define TCCR1A *((volatile u8*)0x4f)
#define TCCR1B *((volatile u8*)0x4e)
#define TCNT1H *((volatile u8*)0x4d)
#define TCNT1L *((volatile u8*)0x4c)
#define OCR1AH *((volatile u8*)0x4b)
#define OCR1AL *((volatile u8*)0x4a)
#define OCR1BH *((volatile u8*)0x49)
#define OCR1BL *((volatile u8*)0x48)

#define TIMSK  *((volatile u8*)0x59)
#define TIFR   *((volatile u8*)0x58)


#define SREG   *((volatile u8*)0x5f)


#endif /* TIMER_PRIV_H_ */
