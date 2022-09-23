/**********************************************/
/** Name        : Dyaa Elshater               */
/** Date        : 12/12/2019                  */
/** Description : TIMER1 Private File         */
/** Version     : 1.0 V                       */
/**********************************************/

#ifndef _TIMER1_PRIV_H_
#define _TIMER1_PRIV_H_


        /* Registers Addresses */
#define TIMER1_PIR1  (*(volatile u8*)(0XF9E))
#define TIMER1_PIE1  (*(volatile u8*)(0XF9D))
#define TIMER1_IPR1  (*(volatile u8*)(0XF9F))
#define TIMER1_TMR1L (*(volatile u8*)(0XFCE))
#define TIMER1_TMR1H (*(volatile u8*)(0XFCF))
#define TIMER1_T1CON (*(volatile u8*)(0XFCD))


        
        /* Registers Bits */

                        /*T1CON*/
#define RD16            (7)
#define T1CKPS1         (5)
#define T1CKPS0         (4)
#define T1OSCEN         (3)
#define T1SYNC          (2)
#define TMR1CS          (1)
#define TMR1ON          (0)

                /*PIR1*/
#define PSPIF                (7)
#define ADIF                 (6)
#define RCIF                 (5)
#define TXIF                 (4)
#define SSPIF                (3)
#define CCP1IF               (2)
#define TMR2IF               (1)
#define TMR1IF               (0)

                /*PIE1*/
#define PSPIE                (7)
#define ADIE                 (6)
#define RCIE                 (5)
#define TXIE                 (4)
#define SSPIE                (3)
#define CCP1IE               (2)
#define TMR2IE               (1)
#define TMR1IE               (0)

                /*IPR1*/
#define PSPIP                (7)
#define ADIP                 (6)
#define RCIP                 (5)
#define TXIP                 (4)
#define SSPIP                (3)
#define CCP1IP               (2)
#define TMR2IP               (1)
#define TMR1IP               (0)

#ifndef TIMER1_MODE
        #define TIMER1_MODE    TIMER1_TIMER_MODE
#else
#endif

#ifndef TIMER1_PRESCALLER
        #define TIMER1_PRESCALLER    TIMER1_DIV_BY_8
#else
#endif

#define POST_SCALE   (1.695305)


static void stumb(){}

static vidpfvid pfTimerOvf = stumb ;

static u32 u32TickTime , u32OvfTime=1 ,u32NoOvf , u32Prload ;

#define Resolution              (65536)

void TIMER1_ISR_Ovf ();
void TIMER1_ISR ();


#endif