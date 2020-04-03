/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	28/7/2019							*/
/**	Description	:	Timer Interface implementation		*/
/**	Version		:	1.0	V								*/
/********************************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "TIMER_int.h"
#include "TIMER_cfg.h"
#include "TIMER_priv.h"	


/**	Description	:	Enable Timer 0 with overflow mode	*/
/**	Input		:	The Desired time					*/
/**	Output		:	void return							*/

Error_Status TIMER_voidSetTimer0_overflow_us(u32 TIMER_u8DesiredTimeInUSCpy,u8 *Pu8ResultFlafCpy)
{
	Error_Status status;
	#if	TIMER0_PRESCALLER!=DISABLE
		status = OK;
		static u8 Loc_u8Started = 0;
		static u16 Loc_u16Counter=0;
		static u16 LOC_u16NbOfOverflow  = TIMER_u8DesiredTimeInUSCpy/OVERFLOW_TIME0;
		static u8	LOC_u8PreloadFlag	= TIMER_u8DesiredTimeInUSCpy%OVERFLOW_TIME0;
		static u8	Loc_u8Preload		;
		if(!Loc_u8Started)
		{	
			Pu8ResultFlafCpy=0;
			Loc_u8Started++;
			if(LOC_u8PreloadFlag)
			{
				LOC_u16NbOfOverflow++;
				LOC_u8Preload=(1-LOC_u8PreloadFlag)*256;
				LOC_u8PreloadFlag=0;
				TCNT0=Loc_u8Preload;
			}
			TCCR0 = ((MODE_0)|PRESCALLER_0);
			TIMSK |= 1<<TOIE0;
			if(TIFR&1<<TOV0)
			{	Loc_u16Counter++;
				Loc_u8Started=0;
				if(Loc_u16Counter>=LOC_u16NbOfOverflow)
				{
					TCNT0=Loc_u8Preload;
					*Pu8ResultFlafCpy=1;
				}
				
			}
		}
	#else
		status = NOK;
		TCCR0 = 0;
		*Pu8ResultFlafCpy=0;
	#endif
	return status;
}
