/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 11/12/2019                 */
/** Description : TIMER3 Implementation File */
/** Version     : 1.0 V                      */
/*********************************************/

#include "Bit_Math.h"
#include "Std_types.h"

#include "TIMER3_INT.h"
#include "TIMER3_CFG.h"
#include "TIMER3_PRIV.h"


 /** Description :                     */
 /* Initializing Timer3 start          */
 /* input : Time in ms                 */
void TIMER3_vidInit()
{
                     /*(PostScale*prescaller/frequency)*Resolution*/
     TIMER3_T3CON = TIMER3_MODE | TIMER3_PRESCALLER ;
  #if TIMER3_PRESCALLER == TIMER3_DIV_BY_1
     u32OvfTime =  (/*1.0*/ /*1.6953*/ POST_SCALE*1.0 /TIMER3_CPU_Frquency)*Resolution ;
  #elif TIMER3_PRESCALLER ==  TIMER3_DIV_BY_2
     u32OvfTime =  (/*2.0*/ POST_SCALE*2.0 /TIMER3_CPU_Frquency)*Resolution ;
  #elif TIMER3_PRESCALLER ==  TIMER3_DIV_BY_4
     u32OvfTime =  (/*4.0*/ POST_SCALE*4.0 /TIMER3_CPU_Frquency)*Resolution ;
  #elif TIMER3_PRESCALLER == TIMER3_DIV_BY_8
     u32OvfTime =  (/*8.0*/ /*0.006625**/POST_SCALE*8.0/TIMER3_CPU_Frquency)*Resolution ;
  #else
     u32OvfTime =  (1.0/TIMER3_CPU_Frquency)*Resolution ;
  #endif
  
  #if  TIMER3_MODE ==   TIMER3_SYN_ASYN_MODE
      SET_BIT(TIMER3_T1CON,T1OSCEN);
  #else
      CLEAR_BIT(TIMER3_T1CON,T1OSCEN);
  #endif

}

  /** Description :                     */
  /* Making TIMER3 start                */
  /* input : Time in us , ms or s       */
void TIMER3_vidStart_us(u32 u32DesiredTimeIn_usCpy)
{
        u32NoOvf = u32DesiredTimeIn_usCpy / u32OvfTime ;
        u32Prload = u32DesiredTimeIn_usCpy % u32OvfTime ;
        if(u32Prload)
        {
            u32Prload = 0xFFFF -  u32Prload ;
            u32NoOvf ++;
            TIMER3_TMR3L = (u8) u32Prload ;
            TIMER3_TMR3H = (u8)(u32Prload >> 8)        ;

        }
        /*Enable TIMER3 Interrupt*/
        SET_BIT(TIMER3_PIE2,TMR3IE);

        /*Enable the TIMER3*/
        SET_BIT(TIMER3_T3CON,TMR3ON);
}

void TIMER3_vidStart_ms(u32 u32DesiredTimeIn_msCpy)
{
     TIMER3_vidStart_us(u32DesiredTimeIn_msCpy*1000);
}

void TIMER3_vidStart_s (u32 u32DesiredTimeIn_sCpy)
{
     TIMER3_vidStart_us(u32DesiredTimeIn_sCpy*1000000);
}

  /** Description :                     */
  /* Setting ISR of OVF                 */
  /* input : Function pointer           */

void TIMER3_vidSetCallBackFunction(vidpfvid pfOvfCpy)
{
    pfTimerOvf = pfOvfCpy ;
}

void TIMER3_vidDisable()
{
               /*Disble the TIMER3*/
        CLEAR_BIT(TIMER3_T3CON,TMR3ON);
}


    /*********/
     #include "DIO_INT.h"
    /*********/

void TIMER3_ISR_Ovf()
{
      static u32 loc_u32counter =0;

      
      loc_u32counter++;
      if(loc_u32counter >= u32NoOvf)
      {
/*************/
        TIMER3_ISR ();
//         pfTimerOvf();
/*MIKRO C doesn't accept callback function here  */
/*IDE sees it as Recursion                        */
/*************/
//        CLEAR_BIT(TIMER3_PIR2,TMR3IF);
        TIMER3_TMR3L = (u8) u32Prload ;
        TIMER3_TMR3H = (u8)(u32Prload >> 8) ;
        loc_u32counter=0;
      }
}