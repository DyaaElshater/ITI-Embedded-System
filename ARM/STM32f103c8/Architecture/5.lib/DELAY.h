/*
 * DELAY.h
 *
 *  Created on: Jun 13, 2020
 *      Author: Dyaa Elshater
 */

	/*The delay for 8 MHZ Frequency*/
#ifndef DELAY_H_
#define DELAY_H_

void Delay_vidInit();

void Delay_us(unsigned int u32DelValueCpy);

void Delay_ms(unsigned int u32DelValueCpy);

void Delay_s(unsigned int u32DelValueCpy);

#endif /* DELAY_H_ */
