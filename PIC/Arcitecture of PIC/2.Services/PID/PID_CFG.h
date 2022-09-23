/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : PID Configuration              */
/*************************************************/

#ifndef _PID_CFG_H_
#define _PID_CFG_H_

/*                 Configure the Mode                   */
/*                        PID_MODE  :                   */
/*                                   - PID_AUTOMATIC    */
/*                                   - PID_MANUAL       */
/*                                                      */

#define PID_MODE   PID_AUTOMATIC

/*        Configure the controller Direction            */
/*          PID_CONTROLLER_DIRECTION :                  */
/*                                   - PID_DIRECT       */
/*                                   - PID_REVERSE      */
/*                                                      */

#define PID_CONTROLLER_DIRECTION    PID_REVERSE

/*        Configure the PON                             */
/*                          PID_PON :                   */
/*                                   - PID_P_ON_M       */
/*                                   - PID_P_ON_E       */
/*                                                      */
#define PID_PON  PID_P_ON_E

#endif