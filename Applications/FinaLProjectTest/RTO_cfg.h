/*
 * RTO_cfg.h
 *
 *  Created on: Aug 4, 2019
 *      Author: Dyaa Elshater
 */

#ifndef RTO_CFG_H_
#define RTO_CFG_H_


#define NUMBER_OF_TASKS 1
Task_TCB Task_ARRAY[/*NUMBER_OF_TASKS*/]=
{

	{	1000,0,Run,POV_UpdateLeds}/*,
	{	500	,0,Run,Blink_Green	},
	{	2000,0,Run,Blink_Yellow	},
	{	1000,0,Run,Update		},
	{	1000,0,Run,Send_Uart	}
	{	1000,0,Run,send_LCD		}
*/
};

#endif /* RTO_CFG_H_ */
