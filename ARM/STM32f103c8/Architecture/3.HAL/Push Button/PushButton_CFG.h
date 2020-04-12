/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : Push Button Configuration  */
/*********************************************/

#ifndef _PB_CFG_H_
#define _PB_CFG_H_

/**     Determine the mode                     */
/*           PB_MODE =                            */
/*                  - PB_PULL_UP               */
/*                  - PB_PULL_DOWN             */

#define PB_MODE     PB_PULL_DOWN


/**	Determine Max Number of buttons						*/
/*		select ID for each button that you want			*/
/*		to use in Raising anf failling edge detectiom	*/
#define PB_MAX_NUMBER		(10)

#endif
