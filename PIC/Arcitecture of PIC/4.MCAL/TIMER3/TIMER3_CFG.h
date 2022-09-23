/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 11/12/2019                 */
/** Description : TIMER3 Configuration File  */
/** Version     : 1.0 V                      */
/*********************************************/

#ifndef _TIMER3_CFG_H_
#define _TIMER3_CFG_H_

  /* Configure the TIMER3 mode                 */
  /*    TIMER3_MODE   :                        */
  /*                    - TIMER3_TIMER_MODE    */
  /*                    - TIMER3_SYN_ASYN_MODE */

#define TIMER3_MODE    TIMER3_TIMER_MODE




  /* Configure the TIMER3 Prescaller              */
  /*    TIMER3_PRESCALLER :                       */
  /*                        - TIMER3_DIV_BY_1     */
  /*                        - TIMER3_DIV_BY_2     */
  /*                        - TIMER3_DIV_BY_4     */
  /*                        - TIMER3_DIV_BY_8     */
  
#define TIMER3_PRESCALLER    TIMER3_DIV_BY_8



  /* Configure the Frquency in MHZ */
#define TIMER3_CPU_Frquency (8)





#endif