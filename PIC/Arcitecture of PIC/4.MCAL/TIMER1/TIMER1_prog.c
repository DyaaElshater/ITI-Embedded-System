/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 12/12/2019                 */
/** Description : TIMER1 Implementation File */
/** Version     : 1.0 V                      */
/*********************************************/

#include "Bit_Math.h"
#include "Std_types.h"

#include "TIMER1_INT.h"
#include "TIMER1_CFG.h"
#include "TIMER1_PRIV.h"


 /** Description :                     */
 /* Initializing TIMER1 start          */
 /* input : Time in ms                 */
void TIMER1_vidInit()
{
                     /*(PostScale*prescaller/frequency)*Resolution*/
     TIMER1_T1CON = TIMER1_MODE | TIMER1_PRESCALLER ;
  #if TIMER1_PRESCALLER == TIMER1_DIV_BY_1
     u32OvfTime =  (/*1.0*/ POST_SCALE*1.0 /TIMER1_CPU_Frquency)*Resolution ;
  #elif TIMER1_PRESCALLER ==  TIMER1_DIV_BY_2
     u32OvfTime =  (/*2.0*/ POST_SCALE*2.0 /TIMER1_CPU_Frquency)*Resolution ;
  #elif TIMER1_PRESCALLER ==  TIMER1_DIV_BY_4
     u32OvfTime =  (/*4.0*/ POST_SCALE*4.0 /TIMER1_CPU_Frquency)*Resolution ;
  #elif TIMER1_PRESCALLER == TIMER1_DIV_BY_8
     u32OvfTime =  (/*8.0*/ POST_SCALE*8.0/TIMER1_CPU_Frquency)*Resolution ;
  #else
     u32OvfTime =  (1.0/TIMER1_CPU_Frquency)*Resolution ;
  #endif
  
  #if  TIMER1_MODE ==   TIMER1_SYN_ASYN_MODE
      SET_BIT(TIMER1_T1CON,T1OSCEN);
  #else
      CLEAR_BIT(TIMER1_T1CON,T1OSCEN);
  #endif

}

  /** Description :                     */
  /* Making TIMER1 start                */
  /* input : Time in us , ms or s       */
void TIMER1_vidStart_us(u32 u32DesiredTimeIn_usCpy)
{
        u32NoOvf = u32DesiredTimeIn_usCpy / u32OvfTime ;
        u32Prload = u32DesiredTimeIn_usCpy % u32OvfTime ;
        if(u32Prload)
        {
            u32Prload = 0xFFFF -  u32Prload ;
            u32NoOvf ++;
            TIMER1_TMR1L = (u8) u32Prload ;
            TIMER1_TMR1H = (u8)(u32Prload >> 8)        ;

        }
        /*Enable TIMER1 Interrupt*/
        SET_BIT(TIMER1_PIE1,TMR1IE);

        /*Enable the TIMER1*/
        SET_BIT(TIMER1_T1CON,TMR1ON);
}

void TIMER1_vidStart_ms(u32 u32DesiredTimeIn_msCpy)
{
     TIMER1_vidStart_us(u32DesiredTimeIn_msCpy*1000);
}

void TIMER1_vidStart_s (u32 u32DesiredTimeIn_sCpy)
{
     TIMER1_vidStart_us(u32DesiredTimeIn_sCpy*1000000);
}

  /** Description :                     */
  /* Setting ISR of OVF                 */
  /* input : Function pointer           */

void TIMER1_vidSetCallBackFunction(vidpfvid pfOvfCpy)
{
    pfTimerOvf = pfOvfCpy ;
}

void TIMER1_vidDisable()
{
               /*Disble the TIMER3*/
        CLEAR_BIT(TIMER1_T1CON,TMR1ON);
}



void TIMER1_ISR_Ovf()
{
      static u32 loc_u32counter =0;
      loc_u32counter++;
      if(loc_u32counter == u32NoOvf)
      {
/*************/
        TIMER1_ISR ();
//         pfTimerOvf();
/*MIKRO C doesn't accept callback function here  */
/*It sees it as Recursion                        */
/*************/
//        CLEAR_BIT(TIMER1_PIR1,TMR1IF);
        TIMER1_TMR1L = (u8) u32Prload ;
        TIMER1_TMR1H = (u8)(u32Prload >> 8) ;
        loc_u32counter=0;
      }
}