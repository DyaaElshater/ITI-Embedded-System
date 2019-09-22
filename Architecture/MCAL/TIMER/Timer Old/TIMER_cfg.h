/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	28/7/2019							*/
/**	Description	:	Timer Interface Configuration		*/
/**	Version		:	1.0	V								*/
/********************************************************/

/**Description	:	Configure the prescaller for Timer0	*/
/*					-DISABLE			
					-NORMAL		
                    -CLKper8		
                    -CLKper64	
                    -CLKper256	
                    -CLKper1042	
                    -EXT_FAILLING
                    -EXT_RISING							*/

#define TIMER0_PRESCALLER	DISABLE						

/**Description	:	Configure the Mode of Timer0		*/
/*					-NORMAL_MODE							
                    -PWM_PHASE_CORRECT_MODE			
					-CTC_MODE					
                    -FAST_PWM							*/
#define TIMR0_MODE	NORMAL_MODE

/**Description	:	Frequency used						*/
#define F_CPU	8000000ul
