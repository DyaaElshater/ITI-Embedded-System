/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 9/12/2019                  */
/** Description : TIMER0 Implementation File */
/** Version     : 1.0 V                      */
/*********************************************/

#include "Bit_Math.h"
#include "Std_types.h"

#include "TIMER0_INT.h"
#include "TIMER0_CFG.h"
#include "TIMER0_PRIV.h"


 /** Description :                     */
 /* Initializing Timer0 start          */
 /* input : Time in ms                 */
void TIMER0_vidInit()
{
  TIMER0_T0CON = TIMER0_MODE | TIMER0_SOURCE | TIMER0_SOURCE_EDGE |
                 TIMER0_PRESCALLER ;
                             /*(PostScale*prescaller/frequency)*Resolution*/
  #if TIMER0_PRESCALLER == TIMER0_DIV_BY_1
     u32OvfTime =  (/*1.0*/  13.5*1.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER ==  TIMER0_DIV_BY_2
     u32OvfTime =  (/*2.0*/  6.6*2.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER ==  TIMER0_DIV_BY_4
     u32OvfTime =  (/*4.0*/  3*4.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER == TIMER0_DIV_BY_8
     u32OvfTime =  (/*8.0*/  1.7*8.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER == TIMER0_DIV_BY_16
     u32OvfTime =  (/*16.0*/ 0.83*16.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER == TIMER0_DIV_BY_32
     u32OvfTime =  (/*32.0*/ 0.42*32.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER == TIMER0_DIV_BY_64
     u32OvfTime =  (/*64.0*/ 0.21*64.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER == TIMER0_DIV_BY_128
     u32OvfTime =  (/*128.0*/0.105*128.0/TIMER0_CPU_Frquency)*Resolution ;
  #elif TIMER0_PRESCALLER == TIMER0_DIV_BY_256
     u32OvfTime =  (/*256.0*/0.053*256.0/TIMER0_CPU_Frquency)*Resolution ;
  #else
     u32OvfTime =  (1.0/TIMER0_CPU_Frquency)*Resolution ;
  #endif
}

  /** Description :                     */
  /* Making Timer0 start                */
  /* input : Time in ms                 */
void TIMER0_vidStart_us(u32 u32DesiredTimeIn_usCpy)
{
        u32NoOvf = u32DesiredTimeIn_usCpy / u32OvfTime ;
        u32Prload = u32DesiredTimeIn_usCpy % u32OvfTime ;
        if(u32Prload)
        {
                u32NoOvf ++;
                TIMER0_TMR0L = (u8) u32Prload ;
        #if TIMER0_MODE == TIMER0_16BIT_MODE
                TIMER0_TMR0H = (u8)(u32Prload >> 8)        ;
        #endif
        }
        /*Enable Timer0 Interrupt*/
        SET_BIT(TIMER0_INTCON,TMR0IE);
        
        /*Enable the Timer0*/
        SET_BIT(TIMER0_T0CON,TMR0ON);
}

void TIMER0_vidStart_ms(u32 u32DesiredTimeIn_msCpy)
{
     TIMER0_vidStart_us(u32DesiredTimeIn_msCpy*1000);
}
void TIMER0_vidStart_s (u32 u32DesiredTimeIn_sCpy)
{
     TIMER0_vidStart_us(u32DesiredTimeIn_sCpy*1000000);
}



  /** Description :                     */
  /* Setting ISR of OVF                 */
  /* input : Function pointer           */

void TIMER0_vidSetCallBackFunction(vidpfvid pfOvfCpy)
{
     pfTimerOvf = pfOvfCpy ;
}



/********************************************************************/
  /** Description :                     */
  /* Checking Timer0 overflow           */
/*
u8   TIMER0_u8CheckOvfFlag()
{
         //if interrupt is disabled and flag is high
     if(!GET_BIT(TIMER0_INTCON,TMR0IE) &&
        GET_BIT(TIMER0_INTCON,TMR0IF)    )
     {
         static u32 loc_u32counter =0;
        loc_u32counter++;
         u8OvfFlag = 0 ;
        if(loc_u32counter == u32NoOvf)
        {
           u8OvfFlag = 1 ;
           TIMER0_TMR0L = (u8) u32Prload ;
          #if TIMER0_MODE == TIMER0_16BIT_MODE
           TIMER0_TMR0H = (u8)(u32Prload >> 8) ;
          #endif
          loc_u32counter=0;
         }
      }
      else
      {

      }
      return u8OvfFlag ;
}
*/
/*********************************************************************/


void TIMER0_vidDisable()
{
         /*Disble the Timer0*/
        CLEAR_BIT(TIMER0_T0CON,TMR0ON);
}



void TIMER0_ISR_Ovf()
{
      static u32 loc_u32counter =0;
      loc_u32counter++;
      if(loc_u32counter == u32NoOvf)
      {
/*************/
        TIMER0_ISR ();
//         pfTimerOvf();
/*MIKRO C doesn't accept callback function here  */
/*It sees it as Recursion                        */
/*************/
         CLEAR_BIT(TIMER0_INTCON,TMR0IF);
         TIMER0_TMR0L = (u8) u32Prload ;
        #if TIMER0_MODE == TIMER0_16BIT_MODE
         TIMER0_TMR0H = (u8)(u32Prload >> 8) ;
        #endif
        loc_u32counter=0;
      }
}