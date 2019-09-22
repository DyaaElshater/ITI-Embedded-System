/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	28/7/2019							*/
/**	Description	:	Timer Interface for differnt modes	*/
/**	Version		:	1.0	V								*/
/********************************************************/

/** Description	:	Prescaller used						*/
#define	DISABLE			0
#define	NORMAL			1
#define CLKper8			2
#define CLKper64		3
#define CLKper256		4
#define CLKper1042		5
#define EXT_FAILLING	6
#define EXT_RISING		7

/**Description	:	Modes use							*/
#define NORMAL_MODE				0
#define CTC_MODE				1
#define	PWM_PHASE_CORRECT_MODE	2
#define	FAST_PWM				3


/**	Description	:	Enable Timer 0 with overflow mode	*/
/**	Input		:	The Desired time					*/
/**	Output		:	void return							*/

Error_Status TIMER_voidSetTimer0_overflow_us(u32 TIMER_u8TimeInUSCpy,u8 *Pu8ResultFlafCpy);
