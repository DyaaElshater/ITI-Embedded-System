/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : Throttlepedal  Confgiration    */
/*************************************************/

#ifndef _Throttlepedal_CFG_H_
#define _Throttlepedal_CFG_H_

/** Select5 the PORT and Pin Number                 */
/*          Throttlepedal_PORT :                    */
/*                              - DIO_PORTA         */
/*                              - DIO_PORTB         */
/*                              - DIO_PORTC         */
/*                              - DIO_PORTD         */
/*                              - DIO_PORTE         */



#define  Throttlepedal_PORT     DIO_PORTC

#define  Throttlepedal_PIN     DIO_RC4


  /*From Inverter Analog Output */
#define throttlePedalCH                        (16)

#define samplesNumber                          (3)
#define samplesDelay                           (5)



#endif