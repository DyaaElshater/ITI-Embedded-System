/****************************************************************/
/**	Name		:	Dyaa Elshater								*/
/**	Date		:	6/1/2019									*/
/**	Description	:	ADC implementation file						*/
/** MCU			:	STM32F103C8									*/
/**	Version		:	1.0 V									`	*/
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

}


void ADC1_vidRegularChannel_Start()
{
	SET_BIT(ADC1->CR2 , SWSTART);
}
void ADC1_vidRegularChannel_Stop()
{
	CLEAR_BIT(ADC1->CR2 , SWSTART);
}
void ADC2_vidRegularChannel_Start()
{
	SET_BIT(ADC2->CR2 , SWSTART);
}
void ADC2_vidRegularChannel_Stop()
{
	CLEAR_BIT(ADC2->CR2 , SWSTART);
}
void ADC3_vidRegularChannel_Start()
{
	SET_BIT(ADC3->CR2 , SWSTART);
}
void ADC3_vidRegularChannel_Stop()
{
	CLEAR_BIT(ADC3->CR2 , SWSTART);
}


void ADC1_vidInjectedChannel_Start()
{
	SET_BIT(ADC1->CR2,JSWSTART);
}
void ADC1_vidInjectedChannel_Stop()
{
	CLEAR_BIT(ADC1->CR2,JSWSTART);
}
void ADC2_vidInjectedChannel_Start()
{
	SET_BIT(ADC2->CR2,JSWSTART);
}
void ADC2_vidInjectedChannel_Stop()
{
	CLEAR_BIT(ADC2->CR2,JSWSTART);
}
void ADC3_vidInjectedChannel_Start()
{
	SET_BIT(ADC3->CR2,JSWSTART);
}
void ADC3_vidInjectedChannel_Stop()
{
	CLEAR_BIT(ADC3->CR2,JSWSTART);
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
