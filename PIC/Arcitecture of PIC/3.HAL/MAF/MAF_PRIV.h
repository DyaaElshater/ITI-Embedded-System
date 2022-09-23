/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : MAF  Private                   */
/*************************************************/

#ifndef _MAF_PRIV_H_
#define _MAF_PRIV_H_

#ifndef  MAF_PORT1
#define  MAF_PORT1     DIO_PORTD
#endif

#ifndef  MAF_PIN1
#define  MAF_PIN1     DIO_RD4
#endif

#ifndef  MAF_PORT2
#define  MAF_PORT2     DIO_PORTD
#endif

#ifndef  MAF_PIN2
#define  MAF_PIN2     DIO_RD5
#endif

#ifndef	MAF_SWITCH1
#define	 MAF_SWITCH1	DIO_PORTA
#endif

#ifndef	MAF_SWITCH_PIN1
#define	 MAF_SWITCH_PIN1	DIO_RA1
#endif

#ifndef	MAF_SWITCH2
#define	 MAF_SWITCH2	DIO_PORTA
#endif

#ifndef	MAF_SWITCH_PIN2
#define	 MAF_SWITCH_PIN2	DIO_RA2
#endif

#ifndef	MAF_SWITCH3
#define	 MAF_SWITCH3	DIO_PORTA
#endif

#ifndef	MAF_SWITCH_PIN3
#define	 MAF_SWITCH_PIN3	DIO_RA3
#endif


#ifndef  MAFAirFlowCH
#define MAFAirFlowCH                           (24)
#endif

#ifndef  MAFTempCH
#define MAFTempCH                              (25)
#endif


#ifndef samplesNumber
#define samplesNumber                          (3)
#endif

#ifndef samplesDelay
#define samplesDelay                           (5)
#endif


#endif