/**********************************************/
/** Name        : Dyaa Elshater               */
/** Date        : 11/12/2019                  */
/** Description : TIMER1 Private File         */
/** Version     : 1.0 V                       */
/**********************************************/

#ifndef _TIMER3_PRIV_H_
#define _TIMER3_PRIV_H_


        /* Registers Addresses */
#define TIMER3_T3CON (*(volatile u8*)(0XFB1))
#define TIMER3_PIR2  (*(volatile u8*)(0XFA1))
#define TIMER3_PIE2  (*(volatile u8*)(0XFA0))
#define TIMER3_IPR2  (*(volatile u8*)(0XFA2))
#define TIMER3_TMR3L (*(volatile u8*)(0XFB2))
#define TIMER3_TMR3H (*(volatile u8*)(0XFB3))
#define TIMER3_T1CON (*(volatile u8*)(0XFCD))


        
        /* Registers Bits */
           /*T3CON*/
#define RD16            (7)
#define T3CCP2          (6)
#define T3CKPS1         (5)
#define T3CKPS0         (4)
#define T3CCP1          (3)
#define T3SYNC          (2)
#define TMR3CS          (1)
#define TMR3ON          (0)

                        /*T1CON*/
#define RD16            (7)
#define T1CKPS1         (5)
#define T1CKPS0         (4)
#define T1OSCEN         (3)
#define T1SYNC          (2)
#define TMR1CS          (1)
#define TMR1ON          (0)

                /*PIR2*/
#define EEIF        (4)
#define BCLIF       (3)
#define LVDIF       (2)
#define TMR3IF      (1)
#define CCP2IF      (0)

                /*PIE2*/
#define EEIE        (4)
#define BCLIE       (3)
#define LVDIE       (2)
#define TMR3IE      (1)
#define CCP2IE      (0)

                /*IPR2*/
#define EEIP        (4)
#define BCLIP       (3)
#define LVDIP       (2)
#define TMR3IP      (1)
#define CCP2IP      (0)

#ifndef TIMER3_MODE
        #define TIMER3_MODE    TIMER3_TIMER_MODE
#else
#endif

#ifndef TIMER3_PRESCALLER
        #define TIMER3_PRESCALLER    TIMER3_DIV_BY_8
#else
#endif


#define POST_SCALE   (1.695305)


static void stumb(){}

static vidpfvid pfTimerOvf = stumb ;

static u32 u32TickTime , u32OvfTime=1 ,u32NoOvf , u32Prload ;

#define Resolution              (65536)

void TIMER3_ISR_Ovf ();
void TIMER3_ISR ();


#endif