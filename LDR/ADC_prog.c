/*
 * ADC_prog.c
 *
 *  Created on: Aug 25, 2019
 *      Author: Dyaa Elshater
 */

#include "Bit_Math.h"
#include "Std_types.h"

#include "ADC_int.h"
#include "ADC_cfg.h"
#include "ADC_priv.h"




void ADC_vidInit()
{
		/*	Enabling ADC*/
	SET_BIT(ADCSRA,ADEN);

		/*Voltage Referrence Selection*/
	SET_BIT(ADMUX,REFS0);
	CLEAR_BIT(ADMUX,REFS1);

		/*Prescaller selection*/
			/*For 13 Clock Cycle of ADC */
	ADCSRA |= (1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

		/*Adjustment*/
			/*Left Adjustment*/
	SET_BIT(ADMUX,ADLAR);


}


u16 ADC_u8Read(u8 u8ChannelCpy)
{

	ADMUX &= 0xE0 ;
	ADMUX |= u8ChannelCpy & 0x07 ;

		/*Start Conversion*/
	SET_BIT(ADCSRA,ADSC);

		/*polling until data is ready*/
	while(GET_BIT(ADCSRA,ADIF)==0);
		/*clear the flag*/
	SET_BIT(ADCSRA,ADIF);
	return ADC ;
}
