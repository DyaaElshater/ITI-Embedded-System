/********************************************/
/** Author 		: Dyaa Elshater             */
/** Date 		: 8/2/2019					*/
/** Description : TIMER Private		 		*/
/** Virsion     : 1.0v				 		*/
/********************************************/

#ifndef TIMER_PRIV_H_
#define TIMER_PRIV_H_

/*Timers Register Addresses*/
#ifndef F_CPU
#define F_CPU	8000000ul
#endif

/**Description	: Timer Resgisters addresses			*/
/*!Comment	:	Timer 0 Registers						*/
#define TCCR0	*((volatile u8*) 0x53)
#define TCCR0_ADDRESS 0x53
#define TCNT0	*((volatile u8*) 0x52)
#define TCNT0_ADDRESS 0x52
#define OCR0	*((volatile u8*) 0x5C)
#define OCR0_ADDRESS 0x52

/*!Comment	:	Status and interupt registers for Timer*/
#define TIMSK	*((volatile u8*)0x59)
#define TIFR	*((volatile u8*)0x58)
#define SREG	*((volatile u8*)0x5f)
/*Specific Bits*/

/*TCCR0*/
#define CS00	0
#define CS01	1
#define CS02	2
#define WGM01	3
#define COM00	4
#define COM01	5
#define WGM00	6
#define FOC0	7

/*TIMSK*/
#define OCIE2	7
#define TOIE2	6
#define TICIE1	5
#define OCIE1A	4
#define OCIE1B	3
#define TOIE1	2
#define OCIE0	1
#define TOIE0	0

/*TIFR */
#define OCF2	7
#define TOV2	6
#define ICF1	5
#define OCF1A	4
#define OCF1B	3
#define TOV1	2
#define OCF0	1
#define TOV0    0


/*Initila Values*/
#ifndef F_CPU
#define F_CPU 8000000ul
#endif

#ifndef TIMER0_PRESCALLER
#define TIMER0_PRESCALLER	DISABLE
#endif

#ifndef TIMER0_MODE
#define TIMER0_MODE NORMAL_MODE
#endif

#ifndef COMPARE_MODE_ACTION
#define COMPARE_MODE_ACTION NORMAL_ACTIION
#endif

#ifndef COMPARE_VALUE
#define COMPARE_VALUE 250
#endif

#if 	TIMER0_PRESCALLER == DISABLE
	#define OVF_TIME0 (1)
	#define CTC_TIME0 (1)
#elif	TIMER0_PRESCALLER == NORMAL
	#define OVF_TIME0 (256/(F_CPU/1000000))
	#define CTC_TIME0 (COMPARE_VALUE/(F_CPU/1000000))
#elif	TIMER0_PRESCALLER == CLKper8
	#define OVF_TIME0 (2048/(F_CPU/1000000))	/*8*256*/
	#define CTC_TIME0 ((/*8* */COMPARE_VALUE)/(F_CPU/1000000))

#elif	TIMER0_PRESCALLER == CLKper64
	#define OVF_TIME0 (16384/(F_CPU/1000000))	/*64*256*/
	#define CTC_TIME0 (/* 64* */COMPARE_VALUE/(F_CPU/1000000))	/*64* */

#elif	TIMER0_PRESCALLER == CLKper256
	#define OVF_TIME0 (65536/(F_CPU/1000000))	/*256*256*/
	#define CTC_TIME0 (/*256* */COMPARE_VALUE/(F_CPU/1000000))

#elif	TIMER0_PRESCALLER == CLKper1024
	#define OVF_TIME0 (262144/(F_CPU/1000000))	/* 1024*256 */
	#define CTC_TIME0 (/*1024* */COMPARE_VALUE/(F_CPU/1000000))

#else


#endif


#endif /* TIMER_PRIV_H_ */
