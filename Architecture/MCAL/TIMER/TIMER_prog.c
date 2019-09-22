/*
 * Timer.c
 *
 *  Created on: Aug 1, 2019
 *      Author: Dyaa Elshater
 */



#include "Std_types.h"
#include "Bit_Math.h"

//#include <avr/io.h>
#include <avr/interrupt.h>

#include "TIMER_int.h"
#include "TIMER_cfg.h"
#include "TIMER_priv.h"

static u16 u16NbOVF , u16NbCompareMatch;
static u8 u8Preload ;
/*Call Back (Pointer to function)*/
static vidpfvid CallBack[8] ;
/*******************************/
/*void eFunctionAlgamila(void);*/
void stub()
{

}
/******************************/




/*Description	: Inializate the  Timer*/
Error_Status TIMER_enuInit(u8 u8TimerNbCpy,u32 u32TimerValueCpy)
{
	Error_Status Loc_u8Status= OK;

	if((u8TimerNbCpy!=TIMER0) && (u8TimerNbCpy!=TIMER1) && (u8TimerNbCpy!=TIMER2))

	{
		Loc_u8Status=NOK;
	}

	else
	{
		volatile u8 *Loc_pTimerControl;
		volatile u8 *Loc_pTimerRegister,*Loc_pCompareRegister;
		u8 Loc_timerInterruptenable_Overflow,Loc_timerInterruptenable_CTC;
		u8 Loc_ControltRegisterValue=0;
		if(u8TimerNbCpy==TIMER0)
		{
			Loc_pTimerControl = ((volatile u8*) TCCR0_ADDRESS);
			Loc_pTimerRegister= ((volatile u8*)TCNT0_ADDRESS);
			Loc_timerInterruptenable_Overflow= TOIE0;

			Loc_pCompareRegister= ((volatile u8*)OCR0_ADDRESS);
			Loc_timerInterruptenable_CTC = OCIE0;

			CallBack[0]=stub;
			CallBack[1]=stub;
		}
		else if(u8TimerNbCpy==TIMER1)
		{
			/*TIMER 1 initialization*/

		}
		else
		{
			/*TIMER 2 initialization*/

		}




		/*Mode*/
		*Loc_pTimerControl = ((TIMER0_MODE&1)<<(WGM00-0) ) | ((TIMER0_MODE&2)<<(WGM01-1) ) ;

		#if TIMER0_MODE==NORMAL_MODE

			/*Edit the desired Time*/
			u8Preload = u32TimerValueCpy%OVF_TIME0;
			if(u8Preload)
			{
				u16NbOVF = u32TimerValueCpy/OVF_TIME0 +1;
			}

			else
			{
				u16NbOVF = u32TimerValueCpy/256;
			}
			u8Preload = 256-u8Preload;
			/*Setting the normal Mode value*/
			*Loc_pTimerRegister = u8Preload;

			/*Enable Normal Mode int*/
				/*TIMSK => TOIE0 */
			SET_BIT(TIMSK,Loc_timerInterruptenable_Overflow);


		#elif TIMER0_MODE==CTC_MODE
			/*Setting the compare match  value*/
			*Loc_pCompareRegister = COMPARE_VALUE ;
			u16NbCompareMatch	  = u32TimerValueCpy / CTC_TIME0 ;


			/*Enable Compare Match int*/
				/*TIMSK => OCIE0 */

			SET_BIT(TIMSK,Loc_timerInterruptenable_CTC);

			/*Hardware Action*/
			*Loc_pTimerControl |= ((COMPARE_MODE_ACTION&1)<<(COM00-0) ) | ((COMPARE_MODE_ACTION&2)<<(COM01-1) ) ;


		#elif TIMER0_MODE==PWM_PHASE_CORRECT_MODE
			/*Setting the  PWM_PHASE CORRECT Mode value*/



		#elif TIMER0_MODE==FAST_PWM
			/*Setting the Fast PWM Mode value*/



		#else
			Loc_u8Status = INDEX_OUT_OF_RANGE ;

		#endif

		/*Setting the prescaler */
			/*Enable Timer */
			/**************************************************************/
			/*Error here in shefting the Loc_pTimerControl*/
			*Loc_pTimerControl |=  ((TIMER0_PRESCALLER&1)<<(CS00-0)) | ((TIMER0_PRESCALLER&2)<<(CS01-1)) | ((TIMER0_PRESCALLER&4)<<(CS02-2)) ;
			/**************************************************************/
			/*Assign to control register
			Loc_pTimerControl = Loc_ControltRegisterValue ;
*/		/*Enable global Inteerupt*/

		sei();
/*		SET_BIT(SREG,7);*/
	}
	return Loc_u8Status ;

}

		/*Setting Callback Timer0 overflow */
Error_Status TIMER0_enuSetCallback_Ovf(vidpfvid Address)
{
	Error_Status Loc_u8Status = OK ;
	 if(Address==NULL)
		{
			Loc_u8Status=NULL_POINTRE;
		}
	CallBack[0]=Address;
	return Loc_u8Status;
}

		/*Setting Callback Timer0 Compare mode*/
Error_Status TIMER0_enuSetCallback_CTC(vidpfvid Address)
{
	Error_Status Loc_u8Status = OK ;
		 if(Address==NULL)
			{
				Loc_u8Status=NULL_POINTRE;
			}
		CallBack[1]=Address;
		return Loc_u8Status;
}

ISR(TIMER0_OVF_vect)
{

	static u16 Loc_u16Counter=0;
	if(Loc_u16Counter>=u16NbOVF)
	{
		/*Setting counter and preload*/
		Loc_u16Counter =0;
		TCNT0=u8Preload;

		/*Code*/
		CallBack[0]();
	}
	else
	{
		Loc_u16Counter++;
	}

}


ISR(TIMER0_COMP_vect)
{
	static u16 Loc_u16CompareCounter=0 ;
	if(Loc_u16CompareCounter>=u16NbCompareMatch)
/*	if(Loc_u16CompareCounter>=16000)*/
	{

		/*Code*/
		CallBack[1]();
	 /***************************/
		/*eFunctionAlgamila();*/
	 /***************************/
		/*Setting the counter*/
		Loc_u16CompareCounter = 0;
	}
	else
	{
		Loc_u16CompareCounter++;
	}
}

/*
void TIMER_vidSetCallBack(u8 u8IntNbCpy,vidpfvid FUNCADDRESS)
{
 *************************
	CallBack[0] = FUNCADDRESS;
 *************************

}
*/

