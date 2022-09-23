/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : MAF  Confgiration              */
/*************************************************/

#ifndef _MAF_CFG_H_
#define _MAF_CFG_H_

/** Select5 the PORT and Pin Number                 */
/*          MAF_PORT :                              */
/*                              - DIO_PORTA         */
/*                              - DIO_PORTB         */
/*                              - DIO_PORTC         */
/*                              - DIO_PORTD         */
/*                              - DIO_PORTE         */



#define  MAF_PORT1     DIO_PORTD

#define  MAF_PIN1     DIO_RD4


#define  MAF_PORT2     DIO_PORTD

#define  MAF_PIN2     DIO_RD5




	/*For Switches*/
#define	 MAF_SWITCH1	DIO_PORTA

#define	 MAF_SWITCH_PIN1	DIO_RA1


#define	 MAF_SWITCH2	DIO_PORTA

#define	 MAF_SWITCH_PIN2	DIO_RA2


#define	 MAF_SWITCH3	DIO_PORTA

#define	 MAF_SWITCH_PIN3	DIO_RA3



  /* From Selected MAF // Eternal Multiplixing */
#define MAFAirFlowCH                           (24)
#define MAFTempCH                              (25)


#define samplesNumber                          (3)
#define samplesDelay                           (5)



#endif