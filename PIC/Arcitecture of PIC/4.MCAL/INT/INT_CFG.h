/************************************************/
/** Name        : Dyaa Elshater                 */
/** Date        : 10/12/2019                    */
/** Description : Interrupt Configuration File  */
/** Version     : 1.0 V                         */
/************************************************/

#ifndef _INT_CFG_H_
#define _INT_CFG_H_

/**Configure Interrupt periority Mode                   */
/*        INT_PER_MODE  :                               */
/*                       - INT_PERIORITY_LEVELS_ENABLE  */
/*                       - INT_PERIORITY_LEVELS_DISABLE */

#define  INT_PER_MODE    INT_PERIORITY_LEVELS_DISABLE

/** Configure the number of INTs                     */
#define INT_NO_INTERRUPTS   ( 6 )

         /*Software Interrupt Periority*/

/** In Case of No Periority Level                    */
  /* Arrange the peripheral periority in the array   */
  /*         - INT_TIMER0                            */
  /*         - INT_TIMER1                            */
  /*         - INT_TIMER2                            */
  /*         - INT_TIMER3                            */
  /*         - INT_EXT0                              */
  /*         - INT_EXT1                              */
  /*         - INT_EXT2                              */
  /*                                                 */
  /*                                                 */
  /*                                                 */
  /*                                                 */
  /*                                                 */
static PERIORITY stINT_Periority [] =
{
  INT_TIMER0 ,
  INT_EXT0   ,
  INT_TIMER1 ,
  INT_EXT1   ,
  INT_TIMER3 ,
  INT_TIMER2 ,
  INT_EXT2
  
}  ;

/**Select the enabled Interrupt                  */
/*   for Example      :                          */
/*       INT_TIMER0_USE :                        */
/*                        - INT_USED             */
/*                        - INT_NOT_USED         */

#define INT_TIMER0_USE       INT_USED
#define INT_TIMER1_USE       INT_NOT_USED
#define INT_TIMER2_USE       INT_NOT_USED
#define INT_TIMER3_USE       INT_NOT_USED
#define INT_EXT0_USE         INT_NOT_USED
#define INT_EXT1_USE         INT_NOT_USED
#define INT_EXT2_USE         INT_NOT_USED



/** Use this Hook Function in Application File    */
/*                                                */
/*                                                */
/*    *** Timers Interrupt                        */
/*  void TIMER0_ISR ()
    {

    }                                             */
/*  void TIMER1_ISR ()
    {
    
    }                                             */
/*  void TIMER2_ISR ()
    {
    
    }                                             */
/*  void TIMER3_ISR ()
    {
    
    }                                             */
/*                                                */
/*    *** External Interrupt                      */
/*  void EXT0_ISR()
    {
    
    }                                             */
/*  void EXT1_ISR()
    {
    
    }                                             */
/*  void EXT2_ISR()
    {
    
    }                                             */
/*                                                */

#endif