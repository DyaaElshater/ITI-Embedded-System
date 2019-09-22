/*
 * EX0_int.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#ifndef EX2_INT_H_
#define EX2_INT_H_

#define EXT2_u8RISING_EDGE		0
#define EXT2_u8FALLING_EDGE		70


void EXT2_vidInit(void);

void EXT2_vidEnable(void);

void EXT2_vidDisable(void);

void EXT2_vidSetCallBack(vidpfvid pfAddressCpy);

void EXT2_vidChangeMode(u8 ModeCpy);

u8 EXT2_u8GetFlag(void);

/********************************************************/
/**	!Comment	:	ModeCpy : 							*/
/*							EXT2_u8RISING_EDGE			*/
/*							EXT2_u8FALLING_EDGE			*/
/*														*/
/********************************************************/

#endif /* EX2_INT_H_ */
