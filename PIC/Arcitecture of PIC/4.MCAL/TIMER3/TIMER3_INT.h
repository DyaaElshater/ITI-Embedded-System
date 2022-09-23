/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 11/12/2019                 */
/** Description : TIMER1 Interface File      */
/** Version     : 1.0 V                      */
/*********************************************/

#ifndef _TIMER3_INT_H_
#define _TIMER3_INT_H_

#define TIMER3_TIMER_MODE    (0)
#define TIMER3_SYN_ASYN_MODE (2)

#define TIMER3_DIV_BY_1           (0x00)
#define TIMER3_DIV_BY_2           (0x10)
#define TIMER3_DIV_BY_4           (0x20)
#define TIMER3_DIV_BY_8           (0x30)






 /** Description :                     */
 /* Initializing Timer0 start          */
 /* input : Time in ms                 */
void TIMER3_vidInit();

  /** Description :                     */
  /* Making Timer0 start                */
  /* input : Time in us , ms or s       */
void TIMER3_vidStart_us(u32 u32DesiredTimeIn_usCpy);
void TIMER3_vidStart_ms(u32 u32DesiredTimeIn_msCpy);
void TIMER3_vidStart_s (u32 u32DesiredTimeIn_sCpy) ;

  /** Description :                     */
  /* Setting ISR of OVF                 */
  /* input : Function pointer           */

void TIMER3_vidSetCallBackFunction(vidpfvid pfOvfCpy);


     /** Desciption :                   */
     /*  For Disabling Timer 3          */
void TIMER3_vidDisable();



#endif