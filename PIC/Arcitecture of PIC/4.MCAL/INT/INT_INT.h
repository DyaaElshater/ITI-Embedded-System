/************************************************/
/** Name        : Dyaa Elshater                 */
/** Date        : 10/12/2019                    */
/** Description : Interrupt Interface File      */
/** Version     : 1.0 V                         */
/************************************************/

#ifndef _INT_INT_H_
#define _INT_INT_H_

#define INT_PERIORITY_LEVELS_ENABLE    (0X80)
#define INT_PERIORITY_LEVELS_DISABLE   (0X00)

/*    *** Timers Interrupt                        */
  void TIMER0_ISR () ;
  void TIMER1_ISR () ;
  void TIMER2_ISR () ;
  void TIMER3_ISR () ;
/*    *** External Interrupt                      */
  void EXT0_ISR() ;
  void EXT1_ISR() ;
  void EXT2_ISR() ;



void INT_vidGIE_Enable();

void INT_vidGIE_Disable();




#endif