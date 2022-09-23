/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 12/12/2019                 */
/** Description : TIMER1 Configuration File  */
/** Version     : 1.0 V                      */
/*********************************************/

#ifndef _TIMER1_CFG_H_
#define _TIMER1_CFG_H_

  /* Configure the TIMER1 mode                 */
  /*    TIMER1_MODE   :                        */
  /*                    - TIMER1_TIMER_MODE    */
  /*                    - TIMER1_SYN_ASYN_MODE */

#define TIMER1_MODE    TIMER1_TIMER_MODE




  /* Configure the TIMER1 Prescaller              */
  /*    TIMER1_PRESCALLER :                       */
  /*                        - TIMER1_DIV_BY_1     */
  /*                        - TIMER1_DIV_BY_2     */
  /*                        - TIMER1_DIV_BY_4     */
  /*                        - TIMER1_DIV_BY_8     */
  
#define TIMER1_PRESCALLER    TIMER1_DIV_BY_8



  /* Configure the Frquency in MHZ */
#define TIMER1_CPU_Frquency (8)





#endif