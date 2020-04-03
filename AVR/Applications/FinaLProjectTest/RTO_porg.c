/*
 * RTO_porg2.c
 *
 *  Created on: Aug 20, 2019
 *      Author: Dyaa Elshater
 */


/*
 * RTO_prog.c
 *
 *  Created on: Aug 4, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "timer.h"

#include "APP.h"

#include "RTO_int.h"
#include "RTO_cfg.h"
#include "RTO_priv.h"


/*static void RTO_voidSchedular(void)	*/
/** we will call it using Callback 		*/

static void RTO_voidSchedular(void)
{

	u8 u8LocCtrLoc;
	for (u8LocCtrLoc=0;u8LocCtrLoc<ALL_TASKS_NUMBER;u8LocCtrLoc++)
	{
		if(Tasks_Que[u8LocCtrLoc] !=NULL)
		{
			if(Tasks_Que[u8LocCtrLoc]->u16FirstDelay==0)
			{
				if((Tasks_Que[u8LocCtrLoc]->enuTaskStatus==Run))
				{
					/*Execute Task*/
					Tasks_Que[u8LocCtrLoc]->pfunction();
				}
				else
				{

				}
				/*PREPARE Next Delay*/
				Tasks_Que[u8LocCtrLoc]->u16FirstDelay= Tasks_Que[u8LocCtrLoc]->u16Periodicity-1;

			}
			else
			{
				Tasks_Que[u8LocCtrLoc]->u16FirstDelay--;
			}

		}
		else
		{
			/*skip and Do nothing*/
		}

	}

}
Error_Status RTO_enuInit(void)
{
	Error_Status Loc_enuStatus = OK ;
	u8 u8LopIdx;

	/*calling schedlar function*/
	Timer1_init();
	TIMER1_vidSetCallback(RTO_voidSchedular,3);


	for (u8LopIdx=0;u8LopIdx<NUMBER_OF_TASKS;u8LopIdx++)
	{
		Tasks_Que[u8LopIdx] = &Task_ARRAY[u8LopIdx];
	}

	for (u8LopIdx=NUMBER_OF_TASKS;u8LopIdx<ALL_TASKS_NUMBER;u8LopIdx++)
	{
		Tasks_Que[u8LopIdx] = NULL;
	}

	return Loc_enuStatus;
}

Error_Status RTO_enuTaskPlay(u8 u8TaskPriorityCpy)
{
	Error_Status Loc_enuStatus = OK ;
	if(u8TaskPriorityCpy>ALL_TASKS_NUMBER)
	{
		Loc_enuStatus = INDEX_OUT_OF_RANGE ;
	}
	else if (Tasks_Que[u8TaskPriorityCpy]==NULL)
	{
		Loc_enuStatus = NULL_POINTRE;
	}
	else
	{
		Tasks_Que[u8TaskPriorityCpy]->enuTaskStatus=Run;
	}
	return Loc_enuStatus ;
}

Error_Status RTO_enuTaskPause(u8 u8TaskPriorityCpy)
{
	Error_Status Loc_enuStatus = OK ;
	if(u8TaskPriorityCpy>ALL_TASKS_NUMBER)
	{
		Loc_enuStatus = INDEX_OUT_OF_RANGE ;
	}
	else if (Tasks_Que[u8TaskPriorityCpy]==NULL)
	{
		Loc_enuStatus = NULL_POINTRE;
	}
	else
	{
		Tasks_Que[u8TaskPriorityCpy]->enuTaskStatus=Wait;
	}
	return Loc_enuStatus ;
}


Error_Status RTO_enuCreatTask(u8 u8TaskPriorityCpy, Task_TCB *pstrTaskInfoCpy)
{
	Error_Status Loc_enuStatus = OK ;
	if(u8TaskPriorityCpy>ALL_TASKS_NUMBER)
	{
		Loc_enuStatus = INDEX_OUT_OF_RANGE ;
	}
	else if(pstrTaskInfoCpy==NULL)
	{
		Loc_enuStatus = NULL_POINTRE ;
	}
	else if (Tasks_Que[u8TaskPriorityCpy]!=NULL)
	{
		Loc_enuStatus = NOK;
	}
	else
	{
	Tasks_Que[u8TaskPriorityCpy] = pstrTaskInfoCpy;
	}
	return Loc_enuStatus ;
}


Error_Status RTO_enuDeleteTask(u8 u8TaskPriorityCpy)
{
	Error_Status Loc_enuStatus = OK ;
	if(u8TaskPriorityCpy>ALL_TASKS_NUMBER)
	{
		Loc_enuStatus = INDEX_OUT_OF_RANGE ;
	}
	else if (Tasks_Que[u8TaskPriorityCpy])
	{
		Loc_enuStatus = NOK;
	}
	else
	{
	Tasks_Que[u8TaskPriorityCpy] = NULL;
	}
	return Loc_enuStatus;
}

Error_Status RTO_enuSettingTickTime(u16 u16TickTimeValueCpy)
{
	Error_Status Status = OK ;
	Timer1_vidChangeOCR1AValue(u16TickTimeValueCpy);
}
