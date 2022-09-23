/************************************************/
/** Name        : Dyaa Elshater                 */
/** Date        : 10/12/2019                    */
/** Description : Interrupt Private File        */
/** Version     : 1.0 V                         */
/************************************************/

#ifndef _INT_PRIV_H_
#define _INT_PRIV_H_

        /*ISR functions as extern for all peripherals*/
              /*Timers*/
void TIMER0_ISR_Ovf();
void TIMER1_ISR_Ovf();
void TIMER2_ISR_Ovf();
void TIMER3_ISR_Ovf();
              /*External*/
void EXT0_ISR_EdgeDetect();
void EXT1_ISR_EdgeDetect();
void EXT2_ISR_EdgeDetect();






     /*Register Addresses*/

#define INT_INTCON        (*(volatile u8*)(0XFF2))
#define INT_INTCON2       (*(volatile u8*)(0XFF1))
#define INT_INTCON3       (*(volatile u8*)(0XFF0))
#define INT_PIR1          (*(volatile u8*)(0XF9E))
#define INT_PIR2          (*(volatile u8*)(0XFA1))
#define INT_PIE1          (*(volatile u8*)(0XF9D))
#define INT_PIE2          (*(volatile u8*)(0XFA0))
#define INT_IPR1          (*(volatile u8*)(0XF9F))
#define INT_IPR2          (*(volatile u8*)(0XFA2))

#define INT_INTCON_ADDRESS                        (0XFF2)
#define INT_INTCON2_ADDRESS                        (0XFF1)
#define INT_INTCON3_ADDRESS                        (0XFF0)
#define INT_PIR1_ADDRESS                        (0XF9E)
#define INT_PIR2_ADDRESS                           (0XFA1)
#define INT_PIE1_ADDRESS                           (0XF9D)
#define INT_PIE2_ADDRESS                           (0XFA0)
#define INT_IPR1_ADDRESS                           (0XF9F)
#define INT_IPR2_ADDRESS                           (0XFA2)
     /*Register Bits*/
        /*INTCON*/ 
#define GIE_GIEH         (7)
#define PEIE_GIEL         (6)
#define TMR0IE                 (5)
#define INT0IE                 (4)
#define RBIE                 (3)
#define TMR0IF                 (2)
#define INT0IF                 (1)
#define RBIF                (0)

        /*INTCON2*/
#define RBPU                 (7)
#define INTEDG0         (6)
#define INTEDG1         (5)
#define INTEDG2         (4)
#define TMR0IP                 (2)
#define RBIP                (0)

        /*INTCON3*/
#define INT2IP                 (7)
#define INT1IP                 (6)
#define INT2IE                 (4)
#define INT1IE                 (3)
#define INT2IF                 (1)
#define INT1IF                (0)

                /*PIR1*/
#define PSPIF                 (7)
#define ADIF                 (6)
#define RCIF                 (5)
#define TXIF                 (4)
#define SSPIF                 (3)
#define CCP1IF                 (2)
#define TMR2IF                 (1)
#define TMR1IF                (0)

                /*PIR2*/
#define EEIF                 (4)
#define BCLIF                 (3)
#define LVDIF                 (2)
#define TMR3IF                 (1)
#define CCP2IF                (0)

                /*PIE1*/
#define PSPIE                (7) 
#define ADIE                 (6)
#define RCIE                 (5)
#define TXIE                 (4)
#define SSPIE                 (3)
#define CCP1IE                 (2)
#define TMR2IE                 (1)
#define TMR1IE                (0)

                        /*PIE2*/
#define EEIE                 (4)
#define BCLIE                 (3)
#define LVDIE                 (2)
#define TMR3IE                 (1)
#define CCP2IE                (0)

                        /*IPR1*/
#define PSPIP                 (7)
#define ADIP                 (6)
#define RCIP                 (5)
#define TXIP                 (4)
#define SSPIP                 (3)
#define CCP1IP                 (2)
#define TMR2IP                 (1)
#define TMR1IP                (0)

                        /*IPR2*/
#define EEIP                 (4)
#define BCLIP                 (3)
#define LVDIP                 (2)
#define TMR3IP                 (1)
#define CCP2IP                (0)

typedef struct
{
  vidpfvid pfPerphiralFunction ;
  u32      u32Register;
  u8       u8FlagBit;
}PERIORITY;



#define INT_TIMER0 {TIMER0_ISR_Ovf,INT_INTCON_ADDRESS,TMR0IF}
#define INT_TIMER1 {TIMER1_ISR_Ovf,INT_PIR1_ADDRESS,TMR1IF}
#define INT_TIMER2 {TIMER2_ISR_Ovf,INT_PIR1_ADDRESS,TMR2IF}
#define INT_TIMER3 {TIMER3_ISR_Ovf,INT_PIR2_ADDRESS,TMR3IF}

#define INT_EXT0   {EXT0_ISR_EdgeDetect,INT_INTCON_ADDRESS,INT0IF}
#define INT_EXT1   {EXT1_ISR_EdgeDetect,INT_INTCON3_ADDRESS,INT1IF}
#define INT_EXT2   {EXT2_ISR_EdgeDetect,INT_INTCON3_ADDRESS,INT2IF}



/*For Enabled Interrupts */
#define INT_USED         (1)
#define INT_NOT_USED     (0)


#endif