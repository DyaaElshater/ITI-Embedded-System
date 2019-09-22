/********************************************/
/** Author 		: Dyaa Elshater             */
/** Date 		: 8/2/2019					*/
/** Description : TIMER Configuration 		*/
/** Virsion     : 1.0v				 		*/
/********************************************/



#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_


/*Configuration*/

/*Configure the compare mode*/

#define COMPARE_VALUE 250
/**********************************************/
/**********************************************/
/**Description	:	Frequency used			*/
#define F_CPU	8000000ul
/**********************************************/
/**********************************************/
/**Description	:	Configure the prescaller for Timer0	*/
/*					-DISABLE
					-NORMAL
                    -CLKper8
                    -CLKper64
                    -CLKper256
                    -CLKper1024
                    -EXT_FAILLING
                    -EXT_RISING							*/


#define TIMER0_PRESCALLER	NORMAL
/**********************************************/
/**********************************************/
/**Description	:Configure the Mode of Timer0 */
/*					- NORMAL_MODE			
					- PWM_PHASE_CORRECT_MODE	
                    - CTC_MODE				
                    - FAST_PWM					
														*/
#define TIMER0_MODE CTC_MODE

	




/**********************************************/
/**********************************************/
 
 
/**Description	:	Configure the Compare mode Action
					for Timer0							*/
/*					-NORMAL_ACTIION	
					-TOGGLE_PIN		
                    -CLEAR_PIN		
                    -SET_PIN			
														*/
#define COMPARE_MODE_ACTION NORMAL_ACTIION
#endif /* TIMER_CFG_H_ */
