/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	28/7/2019							*/
/**	Description	:	Timer private file					*/
/**	Version		:	1.0	V								*/
/********************************************************/

#ifndef F_CPU
#define F_CPU	8000000ul
#endif

/**Description	: Timer Resgisters addresses			*/
/*!Comment	:	Timer 0 Registers						*/
#define TCCR0	*((volatile u8*)(0x53))
#define TCNT0	*((volatile u8*)(0x52))

/*!Comment	:	Status and inteerupt registers for Timer*/
#define TIMSK	*((volatile u8*)(0x59))
#define TIFR	*((volatile u8*)(0x58))

/*Specific Bits*/
#define TOIE0 0		/*TIMSK*/
#define TOV0  0		/*TIFR */
/**Description	: Calculating OVERFLOW_TIME				*/
	#define TICK_TIME0		TIMER0_PRESCALLER/F_CPU
	#define	OVERFLOW_TIME0	TICK_TIME0*256 
/**Description	: setting the prescaller				*/
#if 	TIMER0_PRESCALLER==DISABLE
	#define PRESCALLER_0 0
#elif	TIMER0_PRESCALLER==NORMAL
	#define PRESCALLER_0 1
#elif	TIMER0_PRESCALLER==CLKper8
	#define PRESCALLER_0 2
#elif	TIMER0_PRESCALLER==CLKper64
	#define PRESCALLER_0 3
#elif	TIMER0_PRESCALLER==CLKper256
	#define PRESCALLER_0 4
#elif	TIMER0_PRESCALLER==CLKper1042
	#define PRESCALLER_0 5
#elif	TIMER0_PRESCALLER==EXT_FAILLING
	#define PRESCALLER_0 6
#elif	TIMER0_PRESCALLER==EXT_RISING
	#define PRESCALLER_0 7
#else
	#define PRESCALLER_0 0
#endif


/**Description	: setting the Mode				*/
#if 	TIMR0_MODE==NORMAL_MODE
	#define MODE_0 0
#elif	TIMR0_MODE==PWM_PHASE_CORRECT_MODE
	#define MODE_0 1<<6
#elif	TIMR0_MODE==CTC_MODE
	#define MODE_0 1<<3
#elif	TIMR0_MODE==FAST_PWM
	#define MODE_0 (1<<6)|(1<<3)
#else
	#define MODE_0 0
#endif
