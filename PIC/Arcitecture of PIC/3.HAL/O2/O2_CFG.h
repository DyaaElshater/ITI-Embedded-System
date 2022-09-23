/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : O2  Confgiration               */
/*************************************************/

#ifndef _O2_CFG_H_
#define _O2_CFG_H_

/** Select5 the PORT and Pin Number                 */
/*          O2_PORT :                    */
/*                              - DIO_PORTA         */
/*                              - DIO_PORTB         */
/*                              - DIO_PORTC         */
/*                              - DIO_PORTD         */
/*                              - DIO_PORTE         */



#define  O2_PORT     DIO_PORTD

#define  O2_PIN     DIO_RC0


  /*From Inverter Analog Output */
#define O2CH                        (20)

#define samplesNumber                          (3)
#define samplesDelay                           (5)



#endif