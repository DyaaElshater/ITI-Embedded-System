/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : TPS  Confgiration               */
/*************************************************/

#ifndef _TPS_CFG_H_
#define _TPS_CFG_H_

/** Select5 the PORT and Pin Number                 */
/*          TPS_PORT :                    */
/*                              - DIO_PORTA         */
/*                              - DIO_PORTB         */
/*                              - DIO_PORTC         */
/*                              - DIO_PORTD         */
/*                              - DIO_PORTE         */



#define  TPS_PORT     DIO_PORTC

#define  TPS_PIN     DIO_RC3


  /*From Inverter Analog Output */
#define TPSCH                        (15)

#define samplesNumber                          (3)
#define samplesDelay                           (5)



#endif