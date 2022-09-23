/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : WTS  Confgiration              */
/*************************************************/

#ifndef _WTS_CFG_H_
#define _WTS_CFG_H_

/** Select5 the PORT and Pin Number                 */
/*          WTS_PORT :                    */
/*                              - DIO_PORTA         */
/*                              - DIO_PORTB         */
/*                              - DIO_PORTC         */
/*                              - DIO_PORTD         */
/*                              - DIO_PORTE         */



#define  WTS_PORT     DIO_PORTC

#define  WTS_PIN     DIO_RC5


  /*From Inverter Analog Output */
#define WTSCH                        (16)

#define samplesNumber                          (3)
#define samplesDelay                           (5)



#endif