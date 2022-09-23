/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 9/12/2019                  */
/** Description : TIMER0 Configuration File  */
/** Version     : 1.0 V                      */
/*********************************************/

#ifndef _TIMER0_CFG_H_
#define _TIMER0_CFG_H_

  /* Configure the Timer0 mode                 */
  /*    TIMER0_MODE   :                        */
  /*                    - TIMER0_8BIT_MODE     */
  /*                    - TIMER0_16BIT_MODE    */

#define TIMER0_MODE    TIMER0_8BIT_MODE

  /* Configure the Timer0 Source                  */
  /*    TIMER0_SOURCE   :                         */
  /*                    - TIMER0_EXTERNAL_SOURCE  */
  /*                    - TIMER0_INTERNAL_SOURCE  */

#define TIMER0_SOURCE    TIMER0_INTERNAL_SOURCE

  /* In case of External Source Configure the Timer0 Source */
  /*                                                        */
  /*    TIMER0_SOURCE_EDGE   :                              */
  /*                    - TIMER0_FALLING_EDGE               */
  /*                    - TIMER0_RAISING_EDGE               */

#define TIMER0_SOURCE_EDGE   TIMER0_RAISING_EDGE


  /* Configure the Timer0 Prescaller              */
  /*    TIMER0_PRESCALLER :                       */
  /*                        - TIMER0_DIV_BY_1     */
  /*                        - TIMER0_DIV_BY_2     */
  /*                        - TIMER0_DIV_BY_4     */
  /*                        - TIMER0_DIV_BY_8     */
  /*                        - TIMER0_DIV_BY_16    */
  /*                        - TIMER0_DIV_BY_32    */
  /*                        - TIMER0_DIV_BY_64    */
  /*                        - TIMER0_DIV_BY_128   */
  /*                        - TIMER0_DIV_BY_256   */
#define TIMER0_PRESCALLER    TIMER0_DIV_BY_8


  /* Configure the Frquency in MHZ */
#define TIMER0_CPU_Frquency (8)



#endif