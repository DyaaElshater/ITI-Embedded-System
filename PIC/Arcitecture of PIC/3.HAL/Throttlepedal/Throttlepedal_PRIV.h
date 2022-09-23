/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : Throttlepedal  Private         */
/*************************************************/

#ifndef _Throttlepedal_PRIV_H_
#define _Throttlepedal_PRIV_H_

#ifndef  Throttlepedal_PORT
#define  Throttlepedal_PORT     DIO_PORTC
#endif

#ifndef  Throttlepedal_PIN
#define  Throttlepedal_PIN     DIO_RC4
#endif



#ifndef throttlePedalCH
#define throttlePedalCH                        (16)
#endif

#ifndef samplesNumber
#define samplesNumber                          (3)
#endif

#ifndef samplesDelay
#define samplesDelay                           (5)
#endif


#endif