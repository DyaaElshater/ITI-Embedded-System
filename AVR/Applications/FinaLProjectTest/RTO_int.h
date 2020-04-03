/*
 * RTO_int.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Dyaa Elshater
 */

#ifndef RTO_INT_H_
#define RTO_INT_H_

typedef struct
{
	/*Task Periodicity*/
	u16 u16Periodicity;
	/*Task First Delay*/
	u16 u16FirstDelay;
	/*Task Status*/
	enum status{Run,Wait} enuTaskStatus;



	/*Task Function*/
	vidpfvid pfunction;
}Task_TCB ;

Error_Status RTO_enuInit(void);
	/*Pause a task*/
Error_Status RTO_enuTaskPause(u8 u8TaskPriorityCpy);
	/*Run a task*/
Error_Status RTO_enuTaskPlay(u8 u8TaskPriorityCpy);

	/*Create new task in Run Time*/
Error_Status RTO_enuCreatTask(u8 u8TaskPriorityCpy, Task_TCB *pstrTaskInfoCpy) ;

	/*Delete a task in Run Time*/
Error_Status RTO_enuDeleteTask(u8 u8TaskPriorityCpy);

	/*Setting Tick Time*/
Error_Status RTO_enuSettingTickTime(u16 u16TickTimeValueCpy);

#endif /* RTO_INT_H_ */
