/********************************************/
/** Author 		: Dyaa Elshater             */
/** Date 		: 8/2/2019					*/
/** Description : TIMER Interfacing 		*/
/** Virsion     : 1.0v				 		*/
/********************************************/

#ifndef TIMER_INT_H_
#define TIMER_INT_H_

/** Description	:	Prescaller used						*/
#define	DISABLE			0
#define	NORMAL			1
#define CLKper8			2
#define CLKper64		3
#define CLKper256		4
#define CLKper1024		5
#define EXT_FAILLING	6
#define EXT_RISING		7

/**Description	:	Modes use							*/
#define NORMAL_MODE				0
#define	PWM_PHASE_CORRECT_MODE	1
#define CTC_MODE				2
#define	FAST_PWM				3

/**Description	: Hardware Action*/
#define NORMAL_ACTIION	0
#define TOGGLE_PIN		1
#define CLEAR_PIN		2
#define SET_PIN			3


/** Description	: Timer numbers		*/
#define TIMER0	0
#define TIMER1	1
#define TIMER2	2

					/*Prototypes*/
/*Description	: Inializate the  Timer*/
Error_Status TIMER_enuInit(u8 u8TimerNbCpy,u32 u32TimerValueCpy);

		/*Setting Callback Timer0 overflow */
Error_Status TIMER0_enuSetCallback_Ovf(vidpfvid Address);


		/*Setting Callback Timer0 Compare mode*/
Error_Status TIMER0_enuSetCallback_CTC(vidpfvid Address);


/*void TIMER0_vidSetCallBack(u8 u8IntNbCpy,vidpfvid FUNCADDRESS);*/


#endif /* TIMER_INT_H_ */
