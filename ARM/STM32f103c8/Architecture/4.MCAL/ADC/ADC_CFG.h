/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC Configuration file						*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/**	Configure the mode for each ADC								*/
/*					-	ADC_CONTINUES_MODE						*/
/*					-	ADC_SINGLE_MODE							*/
#define ADC1_MODE		ADC_CONTINUES_MODE
#define ADC2_MODE		ADC_CONTINUES_MODE
#define ADC3_MODE		ADC_CONTINUES_MODE

/** Configure the Channel Type									*/
/*					-	ADC_SINGLE_CHANNEL						*/
/*					-	ADC_MULTI_CHANNEL						*/

#define ADC1_CHANNEL_MODE		ADC_MULTI_CHANNEL
#define ADC2_CHANNEL_MODE		ADC_SINGLE_CHANNEL
#define ADC3_CHANNEL_MODE		ADC_MULTI_CHANNEL

/**	Determine Length of Regular channels of ADC 1,2 and 3	*/
/* 		ADCx_CHANNELS_LENGTH = 1 -> 16						*/
#define ADC1_CHANNELS_LENGTH		2
#define ADC2_CHANNELS_LENGTH		1
#define ADC3_CHANNELS_LENGTH		5

/**	Determine Length of Injected channels of ADC 1,2 and 3	*/
/* 		ADCx_INJECTED_CHANNELS_LENGTH = 1 -> 4				*/
#define ADC1_INJECTED_CHANNELS_LENGTH		1
#define ADC2_INJECTED_CHANNELS_LENGTH		2
#define ADC3_INJECTED_CHANNELS_LENGTH		5

/** Configure the ADC Calibration 							*/
/*		ADCx_CAL	:										*/
/*					- ADC_Disable							*/
/*					- ADC_Enable							*/

#define ADC1_CAL	ADC_Enable
#define ADC2_CAL	ADC_Disable
#define ADC3_CAL	ADC_Disable

/** Configure the Discontinuous mode 						*/
/* Configure the enable and number of channels of 			*/
/* discontinuous mode and select the channels in 			*/
/* Regular Sequence and Injected Sequence array in this file*/
/* ADCx_DISCONTINUOUS_MODE_ENABLE	:						*/
/* ADCx_INJECtED_DISCONTINUOUS_MODE_ENABLE	:						*/
/*					- ADC_Disable							*/
/*					- ADC_Enable							*/
#define ADC1_DISCONTINUOUS_MODE_ENABLE	ADC_Disable
#define ADC2_DISCONTINUOUS_MODE_ENABLE	ADC_Disable
#define ADC3_DISCONTINUOUS_MODE_ENABLE	ADC_Disable

#define ADC1_INJECtED_DISCONTINUOUS_MODE_ENABLE	ADC_Disable
#define ADC2_INJECtED_DISCONTINUOUS_MODE_ENABLE	ADC_Disable
#define ADC3_INJECtED_DISCONTINUOUS_MODE_ENABLE	ADC_Disable

/* ADCx_DISCONTINUOUS_MODE_NO_CHANNELS	:					*/
/*										-	ADC_1_Channel 	*/
/*										-	ADC_2_Channels	*/
/*										-	ADC_3_Channels	*/
/*										-	ADC_4_Channels	*/
/*										-	ADC_5_Channels	*/
/*										-	ADC_6_Channels	*/
/*										-	ADC_7_Channels	*/
/*										-	ADC_8_Channels	*/
#define ADC1_DISCONTINUOUS_MODE_NO_CHANNELS	ADC_3_Channels
#define ADC2_DISCONTINUOUS_MODE_NO_CHANNELS	ADC_3_Channels
#define ADC3_DISCONTINUOUS_MODE_NO_CHANNELS	ADC_3_Channels

/** Configure the Alignment of each ADC						*/
/*		ADCx_ALIGNMENT	:									*/
/*							-	ADC_LEFT_ALIGN				*/
/* 							-	ADC_RIGHT_ALIGN				*/
#define ADC1_ALIGNMENT		ADC_RIGHT_ALIGN
#define ADC2_ALIGNMENT		ADC_RIGHT_ALIGN
#define ADC3_ALIGNMENT		ADC_RIGHT_ALIGN

/**	The Channels 											*/
/*			-	ADC_CHANNEL0								*/
/*			-	ADC_CHANNEL1								*/
/*			-	ADC_CHANNEL2								*/
/*			-	ADC_CHANNEL3								*/
/*			-	ADC_CHANNEL4								*/
/*			-	ADC_CHANNEL5								*/
/*			-	ADC_CHANNEL6								*/
/*			-	ADC_CHANNEL7								*/
/*			-	ADC_CHANNEL8								*/
/*			-	ADC_CHANNEL9								*/
/*			-	ADC_CHANNEL10								*/
/*			-	ADC_CHANNEL11								*/
/*			-	ADC_CHANNEL12								*/
/*			-	ADC_CHANNEL13								*/
/*			-	ADC_CHANNEL14								*/
/*			-	ADC_CHANNEL15								*/
/*			-	ADC_CHANNEL16								*/
/*			-	ADC_CHANNEL17								*/

/** Determine the Regular Sequence 	in the following Array	*/
u8 ADC1_arrU8RegularSequence[ADC1_CHANNELS_LENGTH]=
{
		ADC_CHANNEL1,
		ADC_CHANNEL3
};
u8 ADC2_arrU8RegularSequence[ADC2_CHANNELS_LENGTH]=
{
		ADC_CHANNEL5
};
u8 ADC3_arrU8RegularSequence[ADC3_CHANNELS_LENGTH]=
{
		ADC_CHANNEL5,
		ADC_CHANNEL2,
		ADC_CHANNEL2,
		ADC_CHANNEL1,
		ADC_CHANNEL7
};


/** Determine the Injected Sequence 	in the following Array	*/
u8 ADC1_arrU8InjectedSequence[ADC1_INJECTED_CHANNELS_LENGTH]=
{
		ADC_CHANNEL3
};
u8 ADC2_arrU8InjectedSequence[ADC2_INJECTED_CHANNELS_LENGTH]=
{
		ADC_CHANNEL4,
		ADC_CHANNEL6
};
u8 ADC3_arrU8InjectedSequence[ADC3_INJECTED_CHANNELS_LENGTH]=
{
		ADC_CHANNEL5,
		ADC_CHANNEL1,
		ADC_CHANNEL2,
		ADC_CHANNEL2,
		ADC_CHANNEL7
};

	/*External Event trigger configuration*/
/*		ADCx_INJECTED_EXTERNAL_EVENT_EN	  :									*/
/*		ADCx_REGULAR_EXTERNAL_EVENT_EN	  :									*/
/*											- ADC_Disable					*/
/*											- ADC_Enable					*/
#define ADC1_INJECTED_EXTERNAL_EVENT_EN	ADC_Disable
#define ADC2_INJECTED_EXTERNAL_EVENT_EN	ADC_Disable
#define ADC3_INJECTED_EXTERNAL_EVENT_EN	ADC_Disable

#define ADC1_REGULAR_EXTERNAL_EVENT_EN	ADC_Disable
#define ADC2_REGULAR_EXTERNAL_EVENT_EN	ADC_Disable
#define ADC3_REGULAR_EXTERNAL_EVENT_EN	ADC_Disable


/*		ADCx_INJECTED_EXT_TRIGGER_EVENT	:									*/
/*			-	TIMER_1_TRGO_EVENT											*/
/*			-	TIMER_1_CC4_EVENT											*/
/*			-	ADC1_2_TIMER2_TRGO_EVENT__ADC3_TIMER4_CC3_EVENT				*/
/*			-	ADC1_2_TIMER2_CC1_EVENT__ADC3_TIMER8_CC2_EVENT				*/
/*			-	ADC1_2_TIMER3__ADC3_TIMER8_CC4_EVENT						*/
/*			-	ADC1_2_TIMER4__ADC3_TIMER5_TRGO_EVENT						*/
/*			-	ADC1_2_EXTI_line15__TIM8_CC4_EVENT___ADC3_TIMER5_CC4_EVENT	*/
/*			-	Injected_SoftWare													*/
#define ADC1_INJECTED_EXT_TRIGGER_EVENT	Injected_SoftWare
#define ADC2_INJECTED_EXT_TRIGGER_EVENT	Injected_SoftWare
#define ADC3_INJECTED_EXT_TRIGGER_EVENT	Injected_SoftWare

/*		ADCx_REGULAR_EXT_TRIGGER_EVENT	:									*/
/*			-	ADC1_2_TIMER1__ADC3_TIMER3_CC1_EVENT						*/
/*			-	TIMER_1_CC4_EVENT											*/
/*			-	ADC1_2_TIMER2_TRGO_EVENT__ADC3_TIMER4_CC3_EVENT				*/
/*			-	ADC1_2_TIMER2_CC1_EVENT__ADC3_TIMER8_CC2_EVENT				*/
/*			-	ADC1_2_TIMER3__ADC3_TIMER8_CC4_EVENT						*/
/*			-	ADC1_2_TIMER4__ADC3_TIMER5_TRGO_EVENT						*/
/*			-	ADC1_2_EXTI_line15__TIM8_CC4_EVENT___ADC3_TIMER5_CC4_EVENT	*/
/*			-	Regular_SoftWare											*/
#define ADC1_REGULAR_EXT_TRIGGER_EVENT	Regular_SoftWare
#define ADC2_REGULAR_EXT_TRIGGER_EVENT	Regular_SoftWare
#define ADC3_REGULAR_EXT_TRIGGER_EVENT	Regular_SoftWare

	/*Temperature Sensor*/
/*					ADCx_TEMPERATURE_SENSOR	:								*/
/*											- ADC_Disable					*/
/*											- ADC_Enable					*/

#define ADC1_TEMPERATURE_SENSOR		ADC_Disable
#define ADC2_TEMPERATURE_SENSOR		ADC_Disable
#define ADC3_TEMPERATURE_SENSOR		ADC_Disable


/** Configure the dual mode 												*/
/*	ADC1_DUAL_MODE	:														*/
/*			-	Independent_mode											*/
/*			-	Combined_regular_simultaneous__injected_simultaneous_mode	*/
/*			-	Combined_regular_simultaneous__alternate_trigger_mode		*/
/*			-	Combined_injected_simultaneous__fast_interleaved_mode		*/
/*			-	Combined_injected_simultaneous__slow_Interleaved_mode		*/
/*			-	Injected_simultaneous_mode_only								*/
/*			-	Regular_simultaneous_mode_only								*/
/*			-	Fast_interleaved_mode_only									*/
/*			-	Slow_interleaved_mode_only									*/
/*			-	Alternate_trigger_mode_only									*/
#define ADC1_DUAL_MODE		Independent_mode


/** Configure the interrupt enable 											*/
/*	ADCx_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE		:			 		*/
/*	ADCx_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE	:			 		*/
/*	ADCx_WATCH_DOG_INTERRUPT_ENABLE	:								 		*/
/*														- ADC_Disable		*/
/*														- ADC_Enable		*/
#define ADC1_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE		ADC_Enable
#define ADC2_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE		ADC_Disable
#define ADC3_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE		ADC_Disable

#define ADC1_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE	ADC_Disable
#define ADC2_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE	ADC_Disable
#define ADC3_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE	ADC_Disable

#define ADC1_WATCH_DOG_INTERRUPT_ENABLE						ADC_Disable
#define ADC2_WATCH_DOG_INTERRUPT_ENABLE						ADC_Disable
#define ADC3_WATCH_DOG_INTERRUPT_ENABLE						ADC_Disable

#endif /* ADC_CFG_H_ */
