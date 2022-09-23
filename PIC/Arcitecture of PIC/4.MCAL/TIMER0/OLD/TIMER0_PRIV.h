/*********************************************/
/** Name        : Dyaa Elshater              */
/** Date        : 9/12/2019                  */
/** Description : TIMER0 Private File        */
/** Version     : 1.0 V                      */
/*********************************************/

#ifndef _TIMER0_PRIV_H_
#define _TIMER0_PRIV_H_

#ifndef TIMER0_MODE
#define TIMER0_MODE    TIMER0_8BIT_MODE
#endif

#ifndef TIMER0_SOURCE
#define TIMER0_SOURCE    TIMER0_INTERNAL_SOURCE
#endif

#ifndef TIMER0_SOURCE_EDGE
#define TIMER0_SOURCE_EDGE   TIMER0_RAISING_EDGE
#endif

#ifndef TIMER0_PRESCALLER
#define TIMER0_PRESCALLER    TIMER0_DIV_BY_8
#endif

#ifndef TIMER0_CPU_Frquency
#define TIMER0_CPU_Frquency (8000000)
#endif


      /*Registers Addresses*/
#define TIMER0_T0CON         (*(volatile u8*)(0XFD5))
#define TIMER0_TMR0L         (*(volatile u8*)(0XFD6))
#define TIMER0_TMR0H         (*(volatile u8*)(0XFD7))

#define TIMER0_INTCON        (*(volatile u8*)(0XFF2))

      /*Registers Bits*/
                        /*T0CON*/
#define TMR0ON          (7)
#define T08BIT          (6)
#define T0CS            (5)
#define T0SE            (4)
#define PSA             (3)

                        /*INTCON*/
#define GIE         (7)
#define TMR0IE      (5)
#define TMR0IF      (2)
          
        /*Pointer to function related to Interrupt */
static void stumb(){}

static vidpfvid pfTimerOvf = stumb ;

static u32 u32TickTime , u32OvfTime=1 ,u32NoOvf , u32Prload ;

#if TIMER0_MODE == TIMER0_8BIT_MODE
    #define Resolution              (256)
#else
    #define Resolution              (65536)
#endif

void TIMER0_ISR_Ovf ();
void TIMER0_ISR ();

#endif