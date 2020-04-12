/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC Configuration file						*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	1.0 V									`	*/
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

#define ADC1_CHANNEL_MODE		ADC_SINGLE_CHANNEL
#define ADC2_CHANNEL_MODE		ADC_MULTI_CHANNEL
#define ADC3_CHANNEL_MODE		ADC_MULTI_CHANNEL

/**	Determine Length of Regular channels of ADC 1,2 and 3	*/
/* 		ADCx_CHANNELS_LENGTH = 1 -> 16						*/
#define ADC1_CHANNELS_LENGTH		1
#define ADC2_CHANNELS_LENGTH		2
#define ADC3_CHANNELS_LENGTH		5

/**	Determine Length of Injected channels of ADC 1,2 and 3	*/
/* 		ADCx_INJECTED_CHANNELS_LENGTH = 1 -> 4				*/
#define ADC1_INJECTED_CHANNELS_LENGTH		1
#define ADC2_INJECTED_CHANNELS_LENGTH		2
#define ADC3_INJECTED_CHANNELS_LENGTH		5

/** Configure the ADC Calibration 						*/
/*		ADCx_CAL	:										*/
/*					- ADC_ENABLE_CAL						*/
/*					- ADC_DISABLE_CAL						*/

#define ADC1_CAL	ADC_DISABLE_CAL
#define ADC2_CAL	ADC_DISABLE_CAL
#define ADC3_CAL	ADC_DISABLE_CAL


/** Configure the Alignment of each ADC						*/
/*		ADCx_ALIGNMENT	:									*/
/*							-	ADC_LEFT_ALIGN				*/
/* 							-	ADC_RIGHT_ALIGN				*/
#define ADC1_ALIGNMENT		ADC_RIGHT_ALIGN
#define ADC2_ALIGNMENT		ADC_RIGHT_ALIGN
#define ADC3_ALIGNMENT		ADC_RIGHT_ALIGN

/** Determine the Regular Sequence 	in the following Array	*/
u8 ADC1_arrU8RegularSequence[ADC1_CHANNELS_LENGTH]=
{
		ADC_CHANNEL1
};
u8 ADC2_arrU8RegularSequence[ADC2_CHANNELS_LENGTH]=
{
		ADC_CHANNEL5,
		ADC_CHANNEL1
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


#endif /* ADC_CFG_H_ */
