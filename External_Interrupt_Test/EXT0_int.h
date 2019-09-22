/*
 * EX0_int.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#ifndef EX0_INT_H_
#define EX0_INT_H_

#define EXT0_u8RISING_EDGE		0
#define EXT0_u8FALLING_EDGE		70
#define EXT0_u8IOC				11
#define EXT0_u8LOW_LEVEL		13

void EXT0_vidInit(void);

void EXT0_vidEnable(void);

void EXT0_vidDisable(void);

void EXT0_vidSetCallBack(vidpfvid pfAddressCpy);

void EXT0_vidChangeMode(u8 ModeCpy);

u8 EXT0_u8GetFlag(void);

/********************************************************/
/**	!Comment	:	ModeCpy : 							*/
/*							EXT0_u8RISING_EDGE			*/
/*							EXT0_u8FALLING_EDGE			*/
/*                          EXT0_u8IOC					*/
/*                          EXT0_u8LOW_LEVEL			*/
/*														*/
/********************************************************/

#endif /* EX0_INT_H_ */
