/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC implementation file						*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	2.0 V									`	*/
/****************************************************************/
#include "Std_types.h"
#include "DELAY.h"
#include "Bit_Math.h"

#include "ADC_INT.h"
#include "ADC_CFG.h"
#include "ADC_PRIV.h"


void ADC1_vidINIT()
{
	/*Enable ADC1*/
	SET_BIT(ADC1->CR2,ADON);

	/*Setting ADC1 MODE*/
#if	ADC1_MODE == ADC_CONTINUES_MODE || ADC1_MODE  == ADC_SINGLE_MODE
	ADC1->CR2 |= ADC1_MODE <<CONT ;
#else
	#error "ADC_ERROR : Configure the mode in ADC1 'ADC_CGF.h' "
#endif

#if ADC1_CHANNEL_MODE == ADC_SINGLE_CHANNEL || ADC1_CHANNEL_MODE == ADC_MULTI_CHANNEL
	ADC1->CR1 |= ADC1_CHANNEL_MODE <<SCAN ;
#else
	#error "ADC_ERROR : Configure the mode of Channel in ADC1 'ADC_CGF.h' "
#endif

	/*Setting Caliberation*/
#if ADC1_CAL == ADC_ENABLE_CAL || ADC1_CAL == ADC_DISABLE_CAL
	ADC1->CR2 |= ADC1_CAL <<CAL;
#else
	#error "ADC_ERROR : Configure the Calibration in ADC1 'ADC_CGF.h' "
#endif

	/*Setting Alignment */
#if ADC1_ALIGNMENT == ADC_RIGHT_ALIGN || ADC1_ALIGNMENT  == ADC_LEFT_ALIGN
	ADC1->CR2 |=  ADC1_ALIGNMENT <<ALIGN ;
#else
	#error"ADC_ERROR : Configure the Alignment in ADC1 'ADC_CGF.h' "
#endif

	/*Setting the Regular Sequence*/
	ADC1->SQR1 = ADC1_CHANNELS_LENGTH <<L ;
	ADC1->SQR2 = 0;
	ADC1->SQR3 = 0;

	s8 Loc_s8Index ;
			/*1 -> 6*/
	if (ADC1_CHANNELS_LENGTH>=6)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<6;Loc_s8Index++ )
		{
			ADC1->SQR3 |= ADC1_arrU8RegularSequence[Loc_s8Index] <<(Loc_s8Index*5);
		}
	}
	else
	{
		for (Loc_s8Index =0 ;Loc_s8Index<ADC1_CHANNELS_LENGTH;Loc_s8Index++ )
		{
			ADC1->SQR3 |= ADC1_arrU8RegularSequence[Loc_s8Index] <<(Loc_s8Index*5);
		}
	}
				/*7 -> 12*/
	if (ADC1_CHANNELS_LENGTH>=12)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<6;Loc_s8Index++ )
		{
			ADC1->SQR2 |= ADC1_arrU8RegularSequence[Loc_s8Index+6] <<(Loc_s8Index*5);
		}
	}
	else if (6<ADC1_CHANNELS_LENGTH)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<ADC1_CHANNELS_LENGTH-6;Loc_s8Index++ )
		{
			ADC1->SQR2 |= ADC1_arrU8RegularSequence[Loc_s8Index+6] <<(Loc_s8Index*5);
		}
	}
	else	{}
				/*13 -> 16*/
	if (12<ADC1_CHANNELS_LENGTH &&ADC1_CHANNELS_LENGTH<17 )
	{
		for (Loc_s8Index =0 ;Loc_s8Index<4;Loc_s8Index++ )
		{
			ADC1->SQR1 |= ADC1_arrU8RegularSequence[Loc_s8Index+12] <<(Loc_s8Index*5);
		}
	}
	else	{}

	/*Setting the Injected Sequence*/

	ADC1->JSQR = ADC1_INJECTED_CHANNELS_LENGTH<<JL;
	if (ADC1_INJECTED_CHANNELS_LENGTH<=4)
	{
		u8 loc_u8Shift=15;
		for(Loc_s8Index =ADC1_INJECTED_CHANNELS_LENGTH-1;Loc_s8Index>=0;Loc_s8Index--)
		{
			ADC1->JSQR=ADC1_arrU8InjectedSequence[Loc_s8Index]<<(loc_u8Shift);
			loc_u8Shift-=5 ;
		}
	}
	else {}

	/*Setting the injected triggered event*/
	ADC1->CR2 |= (ADC1_INJECTED_EXT_TRIGGER_EVENT<<JEXTSEL);
	ADC1->CR2 |= (ADC1_INJECTED_EXTERNAL_EVENT_EN<<JEXTTRIG);

	/*Setting the Regular triggered event*/
	ADC1->CR2 |= (ADC1_REGULAR_EXT_TRIGGER_EVENT<<JEXTSEL);
	ADC1->CR2 |= (ADC1_REGULAR_EXTERNAL_EVENT_EN<<JEXTTRIG);

	/*setting temperature sensor*/
	ADC1->CR2 |= ADC1_TEMPERATURE_SENSOR <<TSVREFE ;

	/*Setting Discontinuous mode*/
	ADC1->CR1 |= ADC1_DISCONTINUOUS_MODE_ENABLE<<DISCEN;
	ADC1->CR1 |= ADC1_INJECtED_DISCONTINUOUS_MODE_ENABLE<<JDISCEN;
	ADC1->CR1 |= ADC1_DISCONTINUOUS_MODE_NO_CHANNELS <<DISCNUM;

	/*Setting Dual Mode */
	ADC1->CR1 |= ADC1_DUAL_MODE<<DUALMOD;

	/*Setting interrupt enable*/
	ADC1->CR1 |=ADC1_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE <<EOCIE;
	ADC1->CR1 |=ADC1_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE <<JEOCIE;
	ADC1->CR1 |=ADC1_WATCH_DOG_INTERRUPT_ENABLE<<AWDIE;
}


void ADC2_vidINIT()
{
	/*Enable ADC2*/
	SET_BIT(ADC2->CR2,ADON);

	/*Setting ADC2 MODE*/
#if	ADC2_MODE == ADC_CONTINUES_MODE || ADC2_MODE  == ADC_SINGLE_MODE
	ADC2->CR2 |= ADC2_MODE <<CONT ;
#else
	#error "ADC_ERROR : Configure the mode in ADC2 'ADC_CGF.h' "
#endif

#if ADC2_CHANNEL_MODE == ADC_SINGLE_CHANNEL || ADC2_CHANNEL_MODE == ADC_MULTI_CHANNEL
	ADC2->CR1 |= ADC2_CHANNEL_MODE <<SCAN ;
#else
	#error "ADC_ERROR : Configure the mode of Channel in ADC2 'ADC_CGF.h' "
#endif

	/*Setting Caliberation*/
#if ADC2_CAL == ADC_ENABLE_CAL || ADC2_CAL == ADC_DISABLE_CAL
	ADC2->CR2 |= ADC2_CAL <<CAL;
#else
	#error "ADC_ERROR : Configure the Calibration in ADC2 'ADC_CGF.h' "
#endif

	/*Setting Alignment */
#if ADC2_ALIGNMENT == ADC_RIGHT_ALIGN || ADC2_ALIGNMENT  == ADC_LEFT_ALIGN
	ADC2->CR2 |=  ADC2_ALIGNMENT <<ALIGN ;
#else
	#error"ADC_ERROR : Configure the Alignment in ADC2 'ADC_CGF.h' "
#endif

	/*Setting the Regular Sequence*/
	ADC2->SQR1 = ADC2_CHANNELS_LENGTH <<L ;
	ADC2->SQR2 = 0;
	ADC2->SQR3 = 0;

	s8 Loc_s8Index ;
			/*1 -> 6*/
	if (ADC2_CHANNELS_LENGTH>=6)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<6;Loc_s8Index++ )
		{
			ADC2->SQR3 |= ADC2_arrU8RegularSequence[Loc_s8Index] <<(Loc_s8Index*5);
		}
	}
	else
	{
		for (Loc_s8Index =0 ;Loc_s8Index<ADC2_CHANNELS_LENGTH;Loc_s8Index++ )
		{
			ADC2->SQR3 |= ADC2_arrU8RegularSequence[Loc_s8Index] <<(Loc_s8Index*5);
		}
	}
				/*7 -> 12*/
	if (ADC2_CHANNELS_LENGTH>=12)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<6;Loc_s8Index++ )
		{
			ADC2->SQR2 |= ADC2_arrU8RegularSequence[Loc_s8Index+6] <<(Loc_s8Index*5);
		}
	}
	else if (6<ADC2_CHANNELS_LENGTH)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<ADC2_CHANNELS_LENGTH-6;Loc_s8Index++ )
		{
			ADC2->SQR2 |= ADC2_arrU8RegularSequence[Loc_s8Index+6] <<(Loc_s8Index*5);
		}
	}
	else	{}
				/*13 -> 16*/
	if (12<ADC2_CHANNELS_LENGTH &&ADC2_CHANNELS_LENGTH<17 )
	{
		for (Loc_s8Index =0 ;Loc_s8Index<4;Loc_s8Index++ )
		{
			ADC2->SQR1 |= ADC2_arrU8RegularSequence[Loc_s8Index+12] <<(Loc_s8Index*5);
		}
	}
	else	{}

	/*Setting the Injected Sequence*/

	ADC2->JSQR = ADC2_INJECTED_CHANNELS_LENGTH<<JL;
	if (ADC2_INJECTED_CHANNELS_LENGTH<=4)
	{
		u8 loc_u8Shift=15;
		for(Loc_s8Index =ADC2_INJECTED_CHANNELS_LENGTH-1;Loc_s8Index>=0;Loc_s8Index--)
		{
			ADC2->JSQR=ADC2_arrU8InjectedSequence[Loc_s8Index]<<(loc_u8Shift);
			loc_u8Shift-=5 ;
		}
	}
	else {}
	/*Setting the injected triggered event*/
	ADC2->CR2 |= (ADC2_INJECTED_EXT_TRIGGER_EVENT<<JEXTSEL);
	ADC2->CR2 |= (ADC2_INJECTED_EXTERNAL_EVENT_EN<<JEXTTRIG);

	/*Setting the Regular triggered event*/
	ADC2->CR2 |= (ADC2_REGULAR_EXT_TRIGGER_EVENT<<JEXTSEL);
	ADC2->CR2 |= (ADC2_REGULAR_EXTERNAL_EVENT_EN<<JEXTTRIG);

	/*setting temperature sensor*/
	ADC2->CR2 |= ADC2_TEMPERATURE_SENSOR <<TSVREFE ;

	/*Setting Discontinuous mode*/
	ADC2->CR1 |= ADC2_DISCONTINUOUS_MODE_ENABLE<<DISCEN;
	ADC2->CR1 |= ADC2_INJECtED_DISCONTINUOUS_MODE_ENABLE<<JDISCEN;
	ADC2->CR1 |= ADC2_DISCONTINUOUS_MODE_NO_CHANNELS <<DISCNUM;

	/*Setting interrupt enable*/
	ADC2->CR1 |=ADC2_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE <<EOCIE;
	ADC2->CR1 |=ADC2_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE <<JEOCIE;
	ADC2->CR1 |=ADC2_WATCH_DOG_INTERRUPT_ENABLE<<AWDIE;

}
void ADC3_vidINIT()
{
	/*Enable ADC3*/
	SET_BIT(ADC3->CR2,ADON);

	/*Setting ADC3 MODE*/
#if	ADC3_MODE == ADC_CONTINUES_MODE || ADC3_MODE  == ADC_SINGLE_MODE
	ADC3->CR2 |= ADC3_MODE <<CONT ;
#else
	#error "ADC_ERROR : Configure the mode in ADC3 'ADC_CGF.h' "
#endif

#if ADC3_CHANNEL_MODE == ADC_SINGLE_CHANNEL || ADC3_CHANNEL_MODE == ADC_MULTI_CHANNEL
	ADC3->CR1 |= ADC3_CHANNEL_MODE <<SCAN ;
#else
	#error "ADC_ERROR : Configure the mode of Channel in ADC3 'ADC_CGF.h' "
#endif

	/*Setting Caliberation*/
#if ADC3_CAL == ADC_ENABLE_CAL || ADC3_CAL == ADC_DISABLE_CAL
	ADC3->CR2 |= ADC3_CAL <<CAL;
#else
	#error "ADC_ERROR : Configure the Calibration in ADC3 'ADC_CGF.h' "
#endif

	/*Setting Alignment */
#if ADC3_ALIGNMENT == ADC_RIGHT_ALIGN || ADC3_ALIGNMENT  == ADC_LEFT_ALIGN
	ADC3->CR2 |=  ADC3_ALIGNMENT <<ALIGN ;
#else
	#error"ADC_ERROR : Configure the Alignment in ADC3 'ADC_CGF.h' "
#endif

	/*Setting the Regular Sequence*/
	ADC3->SQR1 = ADC3_CHANNELS_LENGTH <<L ;
	ADC3->SQR2 = 0;
	ADC3->SQR3 = 0;

	s8 Loc_s8Index ;
			/*1 -> 6*/
	if (ADC3_CHANNELS_LENGTH>=6)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<6;Loc_s8Index++ )
		{
			ADC3->SQR3 |= ADC3_arrU8RegularSequence[Loc_s8Index] <<(Loc_s8Index*5);
		}
	}
	else
	{
		for (Loc_s8Index =0 ;Loc_s8Index<ADC3_CHANNELS_LENGTH;Loc_s8Index++ )
		{
			ADC3->SQR3 |= ADC3_arrU8RegularSequence[Loc_s8Index] <<(Loc_s8Index*5);
		}
	}
				/*7 -> 12*/
	if (ADC3_CHANNELS_LENGTH>=12)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<6;Loc_s8Index++ )
		{
			ADC3->SQR2 |= ADC3_arrU8RegularSequence[Loc_s8Index+6] <<(Loc_s8Index*5);
		}
	}
	else if (6<ADC3_CHANNELS_LENGTH)
	{
		for (Loc_s8Index =0 ;Loc_s8Index<ADC3_CHANNELS_LENGTH-6;Loc_s8Index++ )
		{
			ADC3->SQR2 |= ADC3_arrU8RegularSequence[Loc_s8Index+6] <<(Loc_s8Index*5);
		}
	}
	else	{}
				/*13 -> 16*/
	if (12<ADC3_CHANNELS_LENGTH &&ADC3_CHANNELS_LENGTH<17 )
	{
		for (Loc_s8Index =0 ;Loc_s8Index<4;Loc_s8Index++ )
		{
			ADC3->SQR1 |= ADC3_arrU8RegularSequence[Loc_s8Index+12] <<(Loc_s8Index*5);
		}
	}
	else	{}

	/*Setting the Injected Sequence*/

	ADC3->JSQR = ADC3_INJECTED_CHANNELS_LENGTH<<JL;
	if (ADC3_INJECTED_CHANNELS_LENGTH<=4)
	{
		u8 loc_u8Shift=15;
		for(Loc_s8Index =ADC3_INJECTED_CHANNELS_LENGTH-1;Loc_s8Index>=0;Loc_s8Index--)
		{
			ADC3->JSQR=ADC3_arrU8InjectedSequence[Loc_s8Index]<<(loc_u8Shift);
			loc_u8Shift-=5 ;
		}
	}
	else {}
	/*Setting the injected triggered event*/
	ADC3->CR2 |= (ADC1_INJECTED_EXT_TRIGGER_EVENT<<JEXTSEL);
	ADC3->CR2 |= (ADC3_INJECTED_EXTERNAL_EVENT_EN<<JEXTTRIG);

	/*Setting the Regular triggered event*/
	ADC3->CR2 |= (ADC3_REGULAR_EXT_TRIGGER_EVENT<<JEXTSEL);
	ADC3->CR2 |= (ADC3_REGULAR_EXTERNAL_EVENT_EN<<JEXTTRIG);

	/*setting temperature sensor*/
	ADC3->CR2 |= ADC3_TEMPERATURE_SENSOR <<TSVREFE ;

	/*Setting Discontinuous mode*/
	ADC3->CR1 |= ADC3_DISCONTINUOUS_MODE_ENABLE<<DISCEN;
	ADC3->CR1 |= ADC3_INJECtED_DISCONTINUOUS_MODE_ENABLE<<JDISCEN;
	ADC3->CR1 |= ADC3_DISCONTINUOUS_MODE_NO_CHANNELS <<DISCNUM;

	/*Setting interrupt enable*/
	ADC3->CR1 |=ADC3_REGULAR_END_OF_CONVERSION_INTERRUPT_ENABLE <<EOCIE;
	ADC3->CR1 |=ADC3_INJECTED_END_OF_CONVERSION_INTERRUPT_ENABLE <<JEOCIE;
	ADC3->CR1 |=ADC3_WATCH_DOG_INTERRUPT_ENABLE<<AWDIE;
}


void ADC1_vidRegularChannel_Start()
{
	SET_BIT(ADC1->CR2 , SWSTART);
}
void ADC2_vidRegularChannel_Start()
{
	SET_BIT(ADC2->CR2 , SWSTART);
}
void ADC3_vidRegularChannel_Start()
{
	SET_BIT(ADC3->CR2 , SWSTART);
}


void ADC1_vidInjectedChannel_Start()
{
	SET_BIT(ADC1->CR2,JSWSTART);
}
void ADC2_vidInjectedChannel_Start()
{
	SET_BIT(ADC2->CR2,JSWSTART);
}
void ADC3_vidInjectedChannel_Start()
{
	SET_BIT(ADC3->CR2,JSWSTART);
}


u32 ADC1_u32RegularRead()
{
	return ADC1->DR ;
}
u32 ADC1_u32InjectedRead_JDR1()
{
	return ADC1->JDR1 ;
}
u32 ADC1_u32InjectedRead_JDR2()
{
	return ADC1->JDR2 ;
}
u32 ADC1_u32InjectedRead_JDR3()
{
	return ADC1->JDR3 ;
}
u32 ADC1_u32InjectedRead_JDR4()
{
	return ADC1->JDR4 ;
}

u32 ADC2_u32RegularRead()
{
	return ADC2->DR ;
}

u32 ADC2_u32InjectedRead_JDR1()
{
	return ADC2->JDR1	;
}
u32 ADC2_u32InjectedRead_JDR2()
{
	return ADC2->JDR2;
}
u32 ADC2_u32InjectedRead_JDR3()
{
	return ADC2->JDR3;
}
u32 ADC2_u32InjectedRead_JDR4()
{
	return ADC2->JDR4;
}

u32 ADC3_u32RegularRead()
{
	return ADC3->DR ;
}

u32 ADC3_u32InjectedRead_JDR1()
{
	return ADC3->JDR1;
}
u32 ADC3_u32InjectedRead_JDR2()
{
	return ADC3->JDR2;
}
u32 ADC3_u32InjectedRead_JDR3()
{
	return ADC3->JDR3;
}
u32 ADC3_u32InjectedRead_JDR4()
{
	return ADC3->JDR4;
}

void ADC1_vidResetCalibration(void)
{
	SET_BIT(ADC1->CR2,RSTCAL);
}
void ADC2_vidResetCalibration(void)
{
	SET_BIT(ADC2->CR2,RSTCAL);
}
void ADC3_vidResetCalibration(void)
{
	SET_BIT(ADC3->CR2,RSTCAL);
}

void ADC1_vidSetAlign(tdefADC_ALIGN enuAdcAlignCpy)
{
	ADC1->CR2 &= ~(1<<ALIGN);
	ADC1->CR2 |= enuAdcAlignCpy<<ALIGN ;
}
void ADC2_vidSetAlign(tdefADC_ALIGN enuAdcAlignCpy)
{
	ADC2->CR2 &= ~(1<<ALIGN);
	ADC2->CR2 |= enuAdcAlignCpy<<ALIGN ;
}
void ADC3_vidSetAlign(tdefADC_ALIGN enuAdcAlignCpy)
{
	ADC3->CR2 &= ~(1<<ALIGN);
	ADC3->CR2 |= enuAdcAlignCpy<<ALIGN ;
}

void ADC1_vidSetInjectedExtTriggeredEvent(tdefInjectedExtTrigger enuInjectedExtTriggerCpy)
{
	ADC1->CR2 &= ~(7<<JEXTSEL);
	ADC1->CR2 |= (enuInjectedExtTriggerCpy<<JEXTSEL);
}
void ADC2_vidSetInjectedExtTriggeredEvent(tdefInjectedExtTrigger enuInjectedExtTriggerCpy)
{
	ADC2->CR2 &= ~(7<<JEXTSEL);
	ADC2->CR2 |= (enuInjectedExtTriggerCpy<<JEXTSEL);
}
void ADC3_vidSetInjectedExtTriggeredEvent(tdefInjectedExtTrigger enuInjectedExtTriggerCpy)
{
	ADC3->CR2 &= ~(7<<JEXTSEL);
	ADC3->CR2 |= (enuInjectedExtTriggerCpy<<JEXTSEL);
}

void ADC1_vidEnableInjectedExternalEvent(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR2,JEXTTRIG);
	ADC1->CR2 |= enuAdcEnCpy<<JEXTTRIG ;
}
void ADC2_vidEnableInjectedExternalEvent(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR2,JEXTTRIG);
	ADC2->CR2 |= enuAdcEnCpy<<JEXTTRIG ;
}
void ADC3_vidEnableInjectedExternalEvent(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR2,JEXTTRIG);
	ADC2->CR2 |= enuAdcEnCpy<<JEXTTRIG ;
}


void ADC1_vidSetRegularExtTriggeredEvent(tdefRegularExtTrigger enuRegularExtTriggerCpy)
{
	ADC1->CR2 &= ~(7<<EXTSEL);
	ADC1->CR2 |= (enuRegularExtTriggerCpy<<EXTSEL);
}
void ADC2_vidSetRegularExtTriggeredEvent(tdefRegularExtTrigger enuRegularExtTriggerCpy)
{
	ADC2->CR2 &= ~(7<<EXTSEL);
	ADC2->CR2 |= (enuRegularExtTriggerCpy<<EXTSEL);
}
void ADC3_vidSetRegularExtTriggeredEvent(tdefRegularExtTrigger enuRegularExtTriggerCpy)
{
	ADC3->CR2 &= ~(7<<EXTSEL);
	ADC3->CR2 |= (enuRegularExtTriggerCpy<<EXTSEL);
}

void ADC1_vidEnableRegularExternalEvent(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR2,EXTTRIG);
	ADC1->CR2 |= enuAdcEnCpy<<EXTTRIG ;
}
void ADC2_vidEnableRegularExternalEvent(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR2,EXTTRIG);
	ADC2->CR2 |= enuAdcEnCpy<<EXTTRIG ;
}
void ADC3_vidEnableRegularExternalEvent(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR2,EXTTRIG);
	ADC3->CR2 |= enuAdcEnCpy<<EXTTRIG ;
}

void ADC1_vidSetRegularSoftwareTrigger(void)
{
	SET_BIT(ADC1->CR2,SWSTART);
}
void ADC2_vidSetRegularSoftwareTrigger(void)
{
	SET_BIT(ADC2->CR2,SWSTART);
}
void ADC3_vidSetRegularSoftwareTrigger(void)
{
	SET_BIT(ADC3->CR2,SWSTART);
}

void ADC1_vidSetInjectedSoftwareTrigger(void)
{
	SET_BIT(ADC1->CR2,JSWSTART);
}
void ADC2_vidSetInjectedSoftwareTrigger(void)
{
	SET_BIT(ADC2->CR2,JSWSTART);
}
void ADC3_vidSetInjectedSoftwareTrigger(void)
{
	SET_BIT(ADC3->CR2,JSWSTART);
}

void ADC1_vidSetTemperatureEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR2,TSVREFE);
	ADC1->CR2 |= enuAdcEnCpy<<TSVREFE ;
}
void ADC2_vidSetTemperatureEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR2,TSVREFE);
	ADC2->CR2 |= enuAdcEnCpy<<TSVREFE ;
}
void ADC3_vidSetTemperatureEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR2,TSVREFE);
	ADC3->CR2 |= enuAdcEnCpy<<TSVREFE ;
}

u16 ADC1_u16GetTemperatureValue(void)
{
	CLEAR_BIT(ADC1->CR1,SCAN);
	u32 Loc_u32Template = ADC1->SQR3 ;
	ADC1->SQR3 &= ~(0x0f);
	ADC1->SQR3 |= ADC_CHANNEL16;
	SET_BIT(ADC1->CR2 , SWSTART);
	SET_BIT(ADC1->CR2 , TSVREFE);

	u32 loc_u32Result = ADC1->DR ;
	CLEAR_BIT(ADC1->CR2 , TSVREFE);
	ADC1->SQR3 = Loc_u32Template;
	ADC1->CR1 |= ADC1_CHANNEL_MODE <<SCAN ;
	return loc_u32Result;
}
u16 ADC2_u16GetTemperatureValue(void)
{
	CLEAR_BIT(ADC2->CR1,SCAN);
	u32 Loc_u32Template = ADC2->SQR3 ;
	ADC2->SQR3 &= ~(0x0f);
	ADC2->SQR3 |= ADC_CHANNEL16;
	SET_BIT(ADC2->CR2 , SWSTART);
	SET_BIT(ADC2->CR2 , TSVREFE);
	u32 loc_u32Result = ADC2->DR ;
	CLEAR_BIT(ADC2->CR2 , TSVREFE);
	ADC2->SQR3 = Loc_u32Template;
	ADC2->CR1 |= ADC1_CHANNEL_MODE <<SCAN ;
	return loc_u32Result;
}
u16 ADC3_u16GetTemperatureValue(void)
{
	CLEAR_BIT(ADC3->CR1,SCAN);
	u32 Loc_u32Template = ADC3->SQR3 ;
	ADC3->SQR3 &= ~(0x0f);
	ADC3->SQR3 |= ADC_CHANNEL16;
	SET_BIT(ADC3->CR2 , SWSTART);
	SET_BIT(ADC3->CR2 , TSVREFE);
	u32 loc_u32Result = ADC3->DR ;
	CLEAR_BIT(ADC3->CR2 , TSVREFE);
	ADC3->SQR3 = Loc_u32Template;
	ADC3->CR1 |= ADC1_CHANNEL_MODE <<SCAN ;
	return loc_u32Result;
}

void ADC1_vidDMA_Enable(void)
{
	SET_BIT(ADC1->CR1,DMA);
}
void ADC1_vidDMA_Disable(void)
{
	CLEAR_BIT(ADC1->CR1,DMA);
}
void ADC2_vidDMA_Enable(void)
{
	SET_BIT(ADC2->CR2,DMA);
}
void ADC2_vidDMA_Disable(void)
{
	CLEAR_BIT(ADC2->CR1,DMA);
}
void ADC3_vidDMA_Enable(void)
{
	SET_BIT(ADC3->CR1,DMA);
}
void ADC3_vidDMA_Disable(void)
{
	CLEAR_BIT(ADC3->CR1,DMA);
}

void ADC1_vidSelectWatchDogChannels(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->CR1 &= ~(0x1f);
	ADC1->CR1 |= enuAdcChannelCpy;
}
void ADC2_vidSelectWatchDogChannels(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->CR1 &= ~(0x1f);
	ADC2->CR1 |= enuAdcChannelCpy;
}
void ADC3_vidSelectWatchDogChannels(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->CR1 &= ~(0x1f);
	ADC3->CR1 |= enuAdcChannelCpy;
}

void ADC1_vidWatchDogEnableScanMode(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC1->CR1,AWDSGL);
	ADC1->CR1 |= enuAdcEn<<AWDSGL;
}
void ADC2_vidWatchDogEnableScanMode(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC2->CR1,AWDSGL);
	ADC2->CR1 |= enuAdcEn<<AWDSGL;
}
void ADC3_vidWatchDogEnableScanMode(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC3->CR1,AWDSGL);
	ADC3->CR1 |= enuAdcEn<<AWDSGL;
}

void ADC1_vidEnableEndOfConvertionInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC1->CR1,EOCIE);
	ADC1->CR1 |= enuAdcEn<<EOCIE;
}
void ADC2_vidEnableEndOfConvertionInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC2->CR1,EOCIE);
	ADC2->CR1 |= enuAdcEn<<EOCIE;
}
void ADC3_vidEnableEndOfConvertionInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC3->CR1,EOCIE);
	ADC3->CR1 |= enuAdcEn<<EOCIE;
}


void ADC1_vidSetEndOfConvertionCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_EOC[0]=pfCallBackCpy;
}
void ADC2_vidSetEndOfConvertionCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_EOC[1]=pfCallBackCpy;
}
void ADC3_vidSetEndOfConvertionCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_EOC[2]=pfCallBackCpy;
}

void ADC1_vidEnableWatchDogInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC1->CR1,AWDIE);
	ADC1->CR1 |= enuAdcEn<<AWDIE;
}
void ADC2_vidEnableWatchDogInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC2->CR1,AWDIE);
	ADC2->CR1 |= enuAdcEn<<AWDIE;
}
void ADC3_vidEnableWatchDogInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC3->CR1,AWDIE);
	ADC3->CR1 |= enuAdcEn<<AWDIE;
}

void ADC1_vidSetWatchDogCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_WD[0]=pfCallBackCpy;
}
void ADC2_vidSetWatchDogCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_WD[1]=pfCallBackCpy;
}
void ADC3_vidSetWatchDogCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_WD[2]=pfCallBackCpy;
}

void ADC1_vidEnableEndOfConvertionInjectedChannelsInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC1->CR1,JEOCIE);
	ADC1->CR1 |= enuAdcEn<<JEOCIE;
}
void ADC2_vidEnableEndOfConvertionInjectedChannelsInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC2->CR1,JEOCIE);
	ADC2->CR1 |= enuAdcEn<<JEOCIE;
}
void ADC3_vidEnableEndOfConvertionInjectedChannelsInterrupt(tdefAdcEn enuAdcEn)
{
	CLEAR_BIT(ADC3->CR1,JEOCIE);
	ADC3->CR1 |= enuAdcEn<<JEOCIE;
}

void ADC1_vidSetEndOfConvertionInjectedChannelsCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_JEOC[0]=pfCallBackCpy;
}
void ADC2_vidSetEndOfConvertionInjectedChannelsCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_JEOC[1]=pfCallBackCpy;
}
void ADC3_vidSetEndOfConvertionInjectedChannelsCallBackFunction(vidpfvid pfCallBackCpy)
{
	ADC_JEOC[2]=pfCallBackCpy;
}

void ADC1_vidAutomaticInjectedGroupconversionEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR1,JAUTO);
	ADC1->CR1 |= enuAdcEnCpy<<JAUTO ;
}
void ADC2_vidAutomaticInjectedGroupconversionEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR1,JAUTO);
	ADC2->CR1 |= enuAdcEnCpy<<JAUTO ;
}
void ADC3_vidAutomaticInjectedGroupconversionEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR1,JAUTO);
	ADC3->CR1 |= enuAdcEnCpy<<JAUTO ;
}

void ADC1_vidDiscontinuousModeEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR1,DISCEN);
	ADC1->CR1 |= enuAdcEnCpy<<DISCEN ;
}
void ADC2_vidDiscontinuousModeEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR1,DISCEN);
	ADC2->CR1 |= enuAdcEnCpy<<DISCEN ;
}
void ADC3_vidDiscontinuousModeEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR1,DISCEN);
	ADC3->CR1 |= enuAdcEnCpy<<DISCEN ;
}

void ADC1_vidDiscontinuousModeInjectedChannelEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR1,JDISCEN);
	ADC1->CR1 |= enuAdcEnCpy<<JDISCEN ;
}
void ADC2_vidDiscontinuousModeInjectedChannelEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR1,JDISCEN);
	ADC2->CR1 |= enuAdcEnCpy<<JDISCEN ;
}
void ADC3_vidDiscontinuousModeInjectedChannelEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR1,JDISCEN);
	ADC3->CR1 |= enuAdcEnCpy<<JDISCEN ;
}

void ADC1_vidSetDiscontinuousChannelNumber(tdefAdcNODiscontinuousCh enuAdcNODiscontinuousCh)
{
	ADC1->CR1 &= ~(0x7<<DISCNUM);
	ADC1->CR1 |= enuAdcNODiscontinuousCh<<DISCNUM ;
}
void ADC2_vidSetDiscontinuousChannelNumber(tdefAdcNODiscontinuousCh enuAdcNODiscontinuousCh)
{
	ADC2->CR1 &= ~(0x7<<DISCNUM);
	ADC2->CR1 |= enuAdcNODiscontinuousCh<<DISCNUM ;
}
void ADC3_vidSetDiscontinuousChannelNumber(tdefAdcNODiscontinuousCh enuAdcNODiscontinuousCh)
{
	ADC3->CR1 &= ~(0x7<<DISCNUM);
	ADC3->CR1 |= enuAdcNODiscontinuousCh<<DISCNUM ;
}

void ADC1_vidDualMode(tdefAdcDualMode enumAdcDualModeCpy)
{
	ADC1->CR1 &= ~(0XF<<DUALMOD);
	ADC1->CR1 |= enumAdcDualModeCpy<<DUALMOD;
}

void ADC1_vidWatchDogEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR1,AWDEN);
	ADC1->CR1 |= enuAdcEnCpy<<AWDEN;
}
void ADC2_vidWatchDogEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR1,AWDEN);
	ADC2->CR1 |= enuAdcEnCpy<<AWDEN;
}
void ADC3_vidWatchDogEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR1,AWDEN);
	ADC3->CR1 |= enuAdcEnCpy<<AWDEN;
}

void ADC1_vidInjectedWatchDogEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC1->CR1,JAWDEN);
	ADC1->CR1 |= enuAdcEnCpy<<JAWDEN;
}
void ADC2_vidInjectedWatchDogEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC2->CR1,JAWDEN);
	ADC2->CR1 |= enuAdcEnCpy<<JAWDEN;
}
void ADC3_vidInjectedWatchDogEnable(tdefAdcEn enuAdcEnCpy)
{
	CLEAR_BIT(ADC3->CR1,JAWDEN);
	ADC3->CR1 |= enuAdcEnCpy<<JAWDEN;
}


void ADC1_vidSetRegularLength(u8 u8LengthCpy)
{
	ADC1->SQR1 &= ~(0xf<<L) ;
	ADC1->SQR1 |= u8LengthCpy<<L;
}
void ADC1_vidSetSQR1(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR3 &= ~(0xf<<SQ1) ;
	ADC1->SQR3 |= enuAdcChannelCpy<<SQ1;
}
void ADC1_vidSetSQR2(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR3 &= ~(0xf<<SQ2) ;
	ADC1->SQR3 |= enuAdcChannelCpy<<SQ2;
}
void ADC1_vidSetSQR3(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR3 &= ~(0xf<<SQ3 );
	ADC1->SQR3 |= enuAdcChannelCpy<<SQ3;
}
void ADC1_vidSetSQR4(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR3 &= ~(0xf<<SQ4) ;
	ADC1->SQR3 |= enuAdcChannelCpy<<SQ4;
}
void ADC1_vidSetSQR5(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR3 &= ~(0xf<<SQ5 );
	ADC1->SQR3 |= enuAdcChannelCpy<<SQ5;
}
void ADC1_vidSetSQR6(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR3 &= ~(0xf<<SQ6 );
	ADC1->SQR3 |= enuAdcChannelCpy<<SQ6;
}
void ADC1_vidSetSQR7(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR2 &= ~(0xf<<SQ7 );
	ADC1->SQR2 |= enuAdcChannelCpy<<SQ7;
}
void ADC1_vidSetSQR8(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR2 &= ~(0xf<<SQ8);
	ADC1->SQR2 |= enuAdcChannelCpy<<SQ8;
}
void ADC1_vidSetSQR9(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR2 &= ~(0xf<<SQ9);
	ADC1->SQR2 |= enuAdcChannelCpy<<SQ9;
}
void ADC1_vidSetSQR10(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR2 &= ~(0xf<<SQ10);
	ADC1->SQR2 |= enuAdcChannelCpy<<SQ10;
}
void ADC1_vidSetSQR11(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR2 &= ~(0xf<<SQ11);
	ADC1->SQR2 |= enuAdcChannelCpy<<SQ11;
}
void ADC1_vidSetSQR12(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR2 &= ~(0xf<<SQ12);
	ADC1->SQR2 |= enuAdcChannelCpy<<SQ12;
}
void ADC1_vidSetSQR13(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR1 &= ~(0xf<<SQ13);
	ADC1->SQR1 |= enuAdcChannelCpy<<SQ13;
}
void ADC1_vidSetSQR14(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR1 &= ~(0xf<<SQ14);
	ADC1->SQR1 |= enuAdcChannelCpy<<SQ14;
}
void ADC1_vidSetSQR15(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR1 &= ~(0xf<<SQ15);
	ADC1->SQR1 |= enuAdcChannelCpy<<SQ15;
}
void ADC1_vidSetSQR16(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->SQR1 &= ~(0xf<<SQ16);
	ADC1->SQR1 |= enuAdcChannelCpy<<SQ16;
}
void ADC1_vidSetInjectedLength(u8 u8Length)
{
	ADC1->JSQR &= ~(0xf<<JL);
	ADC1->JSQR |= u8Length<<JL;
}
void ADC1_vidSetJSQR1(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->JSQR &= ~(0xf<<JSQ1);
	ADC1->JSQR |= enuAdcChannelCpy<<JSQ1;
}
void ADC1_vidSetJSQR2(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->JSQR &= ~(0xf<<JSQ2);
	ADC1->JSQR |= enuAdcChannelCpy<<JSQ2;
}
void ADC1_vidSetJSQR3(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->JSQR &= ~(0xf<<JSQ3);
	ADC1->JSQR |= enuAdcChannelCpy<<JSQ3;
}
void ADC1_vidSetJSQR4(tdefAdcChannels enuAdcChannelCpy)
{
	ADC1->JSQR &= ~(0xf<<JSQ4);
	ADC1->JSQR |= enuAdcChannelCpy<<JSQ4;
}


void ADC2_vidSetRegularLength(u8 u8LengthCpy)
{
	ADC2->SQR1 &= ~(0xf<<L) ;
	ADC2->SQR1 |= u8LengthCpy<<L;
}
void ADC2_vidSetSQR1(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR3 &= ~(0xf<<SQ1) ;
	ADC2->SQR3 |= enuAdcChannelCpy<<SQ1;
}
void ADC2_vidSetSQR2(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR3 &= ~(0xf<<SQ2) ;
	ADC2->SQR3 |= enuAdcChannelCpy<<SQ2;
}
void ADC2_vidSetSQR3(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR3 &= ~(0xf<<SQ3 );
	ADC2->SQR3 |= enuAdcChannelCpy<<SQ3;
}
void ADC2_vidSetSQR4(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR3 &= ~(0xf<<SQ4) ;
	ADC2->SQR3 |= enuAdcChannelCpy<<SQ4;
}
void ADC2_vidSetSQR5(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR3 &= ~(0xf<<SQ5 );
	ADC2->SQR3 |= enuAdcChannelCpy<<SQ5;
}
void ADC2_vidSetSQR6(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR3 &= ~(0xf<<SQ6 );
	ADC2->SQR3 |= enuAdcChannelCpy<<SQ6;
}
void ADC2_vidSetSQR7(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR2 &= ~(0xf<<SQ7 );
	ADC2->SQR2 |= enuAdcChannelCpy<<SQ7;
}
void ADC2_vidSetSQR8(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR2 &= ~(0xf<<SQ8);
	ADC2->SQR2 |= enuAdcChannelCpy<<SQ8;
}
void ADC2_vidSetSQR9(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR2 &= ~(0xf<<SQ9);
	ADC2->SQR2 |= enuAdcChannelCpy<<SQ9;
}
void ADC2_vidSetSQR10(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR2 &= ~(0xf<<SQ10);
	ADC2->SQR2 |= enuAdcChannelCpy<<SQ10;
}
void ADC2_vidSetSQR11(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR2 &= ~(0xf<<SQ11);
	ADC2->SQR2 |= enuAdcChannelCpy<<SQ11;
}
void ADC2_vidSetSQR12(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR2 &= ~(0xf<<SQ12);
	ADC2->SQR2 |= enuAdcChannelCpy<<SQ12;
}
void ADC2_vidSetSQR13(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR1 &= ~(0xf<<SQ13);
	ADC2->SQR1 |= enuAdcChannelCpy<<SQ13;
}
void ADC2_vidSetSQR14(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR1 &= ~(0xf<<SQ14);
	ADC2->SQR1 |= enuAdcChannelCpy<<SQ14;
}
void ADC2_vidSetSQR15(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR1 &= ~(0xf<<SQ15);
	ADC2->SQR1 |= enuAdcChannelCpy<<SQ15;
}
void ADC2_vidSetSQR16(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->SQR1 &= ~(0xf<<SQ16);
	ADC2->SQR1 |= enuAdcChannelCpy<<SQ16;
}
void ADC2_vidSetInjectedLength(u8 u8Length)
{
	ADC2->JSQR &= ~(0xf<<JL);
	ADC2->JSQR |= u8Length<<JL;
}
void ADC2_vidSetJSQR1(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->JSQR &= ~(0xf<<JSQ1);
	ADC2->JSQR |= enuAdcChannelCpy<<JSQ1;
}
void ADC2_vidSetJSQR2(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->JSQR &= ~(0xf<<JSQ2);
	ADC2->JSQR |= enuAdcChannelCpy<<JSQ2;
}
void ADC2_vidSetJSQR3(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->JSQR &= ~(0xf<<JSQ3);
	ADC2->JSQR |= enuAdcChannelCpy<<JSQ3;
}
void ADC2_vidSetJSQR4(tdefAdcChannels enuAdcChannelCpy)
{
	ADC2->JSQR &= ~(0xf<<JSQ4);
	ADC2->JSQR |= enuAdcChannelCpy<<JSQ4;
}


void ADC3_vidSetRegularLength(u8 u8LengthCpy)
{
	ADC3->SQR1 &= ~(0xf<<L) ;
	ADC3->SQR1 |= u8LengthCpy<<L;
}
void ADC3_vidSetSQR1(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR3 &= ~(0xf<<SQ1) ;
	ADC3->SQR3 |= enuAdcChannelCpy<<SQ1;
}
void ADC3_vidSetSQR2(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR3 &= ~(0xf<<SQ2) ;
	ADC3->SQR3 |= enuAdcChannelCpy<<SQ2;
}
void ADC3_vidSetSQR3(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR3 &= ~(0xf<<SQ3 );
	ADC3->SQR3 |= enuAdcChannelCpy<<SQ3;
}
void ADC3_vidSetSQR4(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR3 &= ~(0xf<<SQ4) ;
	ADC3->SQR3 |= enuAdcChannelCpy<<SQ4;
}
void ADC3_vidSetSQR5(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR3 &= ~(0xf<<SQ5 );
	ADC3->SQR3 |= enuAdcChannelCpy<<SQ5;
}
void ADC3_vidSetSQR6(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR3 &= ~(0xf<<SQ6 );
	ADC3->SQR3 |= enuAdcChannelCpy<<SQ6;
}
void ADC3_vidSetSQR7(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR2 &= ~(0xf<<SQ7 );
	ADC3->SQR2 |= enuAdcChannelCpy<<SQ7;
}
void ADC3_vidSetSQR8(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR2 &= ~(0xf<<SQ8);
	ADC3->SQR2 |= enuAdcChannelCpy<<SQ8;
}
void ADC3_vidSetSQR9(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR2 &= ~(0xf<<SQ9);
	ADC3->SQR2 |= enuAdcChannelCpy<<SQ9;
}
void ADC3_vidSetSQR10(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR2 &= ~(0xf<<SQ10);
	ADC3->SQR2 |= enuAdcChannelCpy<<SQ10;
}
void ADC3_vidSetSQR11(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR2 &= ~(0xf<<SQ11);
	ADC3->SQR2 |= enuAdcChannelCpy<<SQ11;
}
void ADC3_vidSetSQR12(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR2 &= ~(0xf<<SQ12);
	ADC3->SQR2 |= enuAdcChannelCpy<<SQ12;
}
void ADC3_vidSetSQR13(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR1 &= ~(0xf<<SQ13);
	ADC3->SQR1 |= enuAdcChannelCpy<<SQ13;
}
void ADC3_vidSetSQR14(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR1 &= ~(0xf<<SQ14);
	ADC3->SQR1 |= enuAdcChannelCpy<<SQ14;
}
void ADC3_vidSetSQR15(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR1 &= ~(0xf<<SQ15);
	ADC3->SQR1 |= enuAdcChannelCpy<<SQ15;
}
void ADC3_vidSetSQR16(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->SQR1 &= ~(0xf<<SQ16);
	ADC3->SQR1 |= enuAdcChannelCpy<<SQ16;
}
void ADC3_vidSetInjectedLength(u8 u8Length)
{
	ADC3->JSQR &= ~(0xf<<JL);
	ADC3->JSQR |= u8Length<<JL;
}
void ADC3_vidSetJSQR1(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->JSQR &= ~(0xf<<JSQ1);
	ADC3->JSQR |= enuAdcChannelCpy<<JSQ1;
}
void ADC3_vidSetJSQR2(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->JSQR &= ~(0xf<<JSQ2);
	ADC3->JSQR |= enuAdcChannelCpy<<JSQ2;
}
void ADC3_vidSetJSQR3(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->JSQR &= ~(0xf<<JSQ3);
	ADC3->JSQR |= enuAdcChannelCpy<<JSQ3;
}
void ADC3_vidSetJSQR4(tdefAdcChannels enuAdcChannelCpy)
{
	ADC3->JSQR &= ~(0xf<<JSQ4);
	ADC3->JSQR |= enuAdcChannelCpy<<JSQ4;
}

u8 ADC1_u8CheckAnalogWatchDogFlag()
{
	return GET_BIT(ADC1->SR,AWD);
}
u8 ADC2_u8CheckAnalogWatchDogFlag()
{
	return GET_BIT(ADC2->SR,AWD);
}
u8 ADC3_u8CheckAnalogWatchDogFlag()
{
	return GET_BIT(ADC3->SR,AWD);
}

u8 ADC1_u8CheckRegularEndOfConversionFlag()
{
	return GET_BIT(ADC1->SR,EOC);
}
u8 ADC2_u8CheckRegularEndOfConversionFlag()
{
	return GET_BIT(ADC2->SR,EOC);
}
u8 ADC3_u8CheckRegularEndOfConversionFlag()
{
	return GET_BIT(ADC3->SR,EOC);
}

u8 ADC1_u8CheckInjectedEndOfConversion()
{
	return GET_BIT(ADC1->SR,JEOC);
}
u8 ADC2_u8CheckInjectedEndOfConversion()
{
	return GET_BIT(ADC2->SR,JEOC);
}
u8 ADC3_u8CheckInjectedEndOfConversion()
{
	return GET_BIT(ADC3->SR,JEOC);
}

u8 ADC1_u8CheckRegularStartFlag()
{
	return GET_BIT(ADC1->SR,STRT);
}
u8 ADC2_u8CheckRegularStartFlag()
{
	return GET_BIT(ADC2->SR,STRT);
}
u8 ADC3_u8CheckRegularStartFlag()
{
	return GET_BIT(ADC3->SR,STRT);
}

u8 ADC1_u8CheckInjectedStartFlag()
{
	return GET_BIT(ADC1->SR,JSTRT);
}
u8 ADC2_u8CheckInjectedStartFlag()
{
	return GET_BIT(ADC2->SR,JSTRT);
}
u8 ADC3_u8CheckInjectedStartFlag()
{
	return GET_BIT(ADC3->SR,JSTRT);
}


/********* Interrupts ***********/

void ADC1_2_IRQHandler(void)
{

	if(ADC1->SR & ADC_CHECK_EOC_BIT)
	{
		CLEAR_BIT(ADC1->SR,EOC);
		ADC_EOC[0]();
	}
	else if(ADC2->SR&ADC_CHECK_EOC_BIT)
	{
		CLEAR_BIT(ADC2->SR,EOC);
		ADC_EOC[1]();
	}
	else if(ADC1->SR & ADC_CHECK_JEOC_BIT)
	{
		CLEAR_BIT(ADC1->SR,JEOC);
		ADC_JEOC[0]();
	}
	else if(ADC2->SR & ADC_CHECK_JEOC_BIT)
	{
		CLEAR_BIT(ADC2->SR,JEOC);
		ADC_JEOC[1]();
	}
	else if(ADC1->SR & ADC_CHECK_AWD_BIT)
	{
		CLEAR_BIT(ADC1->SR,AWD);
		ADC_WD[0]();
	}
	else if(ADC2->SR & ADC_CHECK_AWD_BIT)
	{
		CLEAR_BIT(ADC2->SR,AWD);
		ADC_WD[1]();
	}
	else
	{}
}
void ADC3_IRQHandler(void)
{
	if(ADC3->SR & ADC_CHECK_EOC_BIT)
	{
		CLEAR_BIT(ADC3->SR,EOC);
		ADC_EOC[2]();
	}
	else if(ADC3->SR & ADC_CHECK_JEOC_BIT)
	{
		CLEAR_BIT(ADC3->SR,JEOC);
		ADC_JEOC[2]();
	}
	else if(ADC3->SR & ADC_CHECK_AWD_BIT)
	{
		CLEAR_BIT(ADC3->SR,AWD);
		ADC_WD[2]();
	}
	else {}
}
