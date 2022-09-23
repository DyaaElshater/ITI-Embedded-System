/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 9/12/2019                  */
/** Description : TIMER0 Interface File      */
/** Version     : 1.0 V                      */
/*********************************************/

#ifndef _TIMER0_INT_H_
#define _TIMER0_INT_H_

        /*TIMER0_MODE*/
#define TIMER0_8BIT_MODE          (0x40)
#define TIMER0_16BIT_MODE         (0x00)

        /*TIMER0_SOURCE*/
#define TIMER0_EXTERNAL_SOURCE    (0X20)
#define TIMER0_INTERNAL_SOURCE    (0x00)

        /*TIMER0_SOURCE_EDGE*/
#define TIMER0_FALLING_EDGE       (0x10)
#define TIMER0_RAISING_EDGE       (0x00)

        /*TIMER0_PRESCALLER*/
#define TIMER0_DIV_BY_1           (0x08)
#define TIMER0_DIV_BY_2           (0x00)
#define TIMER0_DIV_BY_4           (0x01)
#define TIMER0_DIV_BY_8           (0x02)
#define TIMER0_DIV_BY_16          (0x03)
#define TIMER0_DIV_BY_32          (0x04)
#define TIMER0_DIV_BY_64          (0x05)
#define TIMER0_DIV_BY_128         (0x06)
#define TIMER0_DIV_BY_256         (0x07)

 /** Description :                     */
 /* Initializing Timer0 start          */
 /* input : Time in ms                 */
void TIMER0_vidInit();

  /** Description :                     */
  /* Making Timer0 start                */
  /* input : Time in us , ms or s       */
void TIMER0_vidStart_us(u32 u32DesiredTimeIn_usCpy);
void TIMER0_vidStart_ms(u32 u32DesiredTimeIn_msCpy);
void TIMER0_vidStart_s (u32 u32DesiredTimeIn_sCpy) ;

  /** Description :                     */
  /* Setting ISR of OVF                 */
  /* input : Function pointer           */

void TIMER0_vidSetCallBackFunction(vidpfvid pfOvfCpy);

void TIMER0_vidDisable();
/*
u8   TIMER0_u8CheckOvfFlag();
*/

#endif