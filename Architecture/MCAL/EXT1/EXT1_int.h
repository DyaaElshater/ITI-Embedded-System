/*
 * EX1_int.h
 *
 *  Created on: Aug 8, 2019
 *      Author: Dyaa Elshater
 */

#ifndef EX1_INT_H_
#define EX1_INT_H_

#define EXT1_u8RISING_EDGE		0
#define EXT1_u8FALLING_EDGE		70
#define EXT1_u8IOC				11
#define EXT1_u8LOW_LEVEL		13

void EXT1_vidInit(void);

void EXT1_vidEnable(void);

void EXT1_vidDisable(void);

void EXT1_vidSetCallBack(vidpfvid pfAddressCpy);

void EXT1_vidChangeMode(u8 ModeCpy);

u8 EXT1_u8GetFlag(void);

/********************************************************/
/**	!Comment	:	ModeCpy : 							*/
/*							EXT0_u8RISING_EDGE			*/
/*							EXT0_u8FALLING_EDGE			*/
/*                          EXT0_u8IOC					*/
/*                          EXT0_u8LOW_LEVEL			*/
/*														*/
/********************************************************/

#endif /* EX1_INT_H_ */
