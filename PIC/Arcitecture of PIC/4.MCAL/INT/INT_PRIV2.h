/************************************************/
/** Name        : Dyaa Elshater                 */
/** Date        : 10/12/2019                    */
/** Description : Interrupt Private File 2      */
/** Version     : 1.0 V                         */
/************************************************/

#ifndef _INT_PRIV2_H_
#define _INT_PRIV2_H_

#ifndef  INT_PER_MODE
#define  INT_PER_MODE    INT_PERIORITY_LEVELS_DISABLE
#endif

#ifndef INT_NO_INTERRUPTS
#define INT_NO_INTERRUPTS   ( 6 )
#endif


       /*Timers*/
#if INT_TIMER0_USE         == INT_NOT_USED
    void TIMER0_ISR_Ovf()   {}
    void TIMER0_ISR ()      {}
#else

#endif

#if INT_TIMER1_USE         == INT_NOT_USED
    void TIMER1_ISR_Ovf()   {}
    void TIMER1_ISR (){}
#else

#endif

#if INT_TIMER2_USE         == INT_NOT_USED
     void TIMER2_ISR_Ovf()  {}
     void TIMER2_ISR (){}
#else

#endif

#if INT_TIMER3_USE         == INT_NOT_USED
     void TIMER3_ISR_Ovf()  {}
     void TIMER3_ISR ()     {}
#else

#endif


     /*External Interrupt*/

#if INT_EXT0_USE          == INT_NOT_USED
    void EXT0_ISR_EdgeDetect()  {}
    void EXT0_ISR()  {}
#else

#endif


#if INT_EXT1_USE          == INT_NOT_USED
    void EXT1_ISR_EdgeDetect()  {}
    void EXT1_ISR()  {}
#else

#endif

#if INT_EXT2_USE         == INT_NOT_USED
     void EXT2_ISR_EdgeDetect()  {}
     void EXT2_ISR()  {}
#else

#endif




#endif