/********************************************/
/** Author 		: Dyaa Elshater             */
/** Date 		: 9/7/2019					*/
/** Description : Bit Math Library 			*/
/** Virsion     : 1.0v				 		*/
/********************************************/
#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_


/*!Comment : Set bit for any register		*/
#define SET_BIT(Reg , BitNb )  Reg|= (1<<BitNb)
/*!Comment : Clear bit for any register		*/
#define CLEAR_BIT(Reg ,BitNb)  Reg&=~(1<<BitNb)
/*!Comment : Toggle bit for any register	*/
#define TOGGLE_BIT(Reg,BitNb ) Reg^= (1<<BitNb)

/*!Comment : Get a specific bit 			*/	
#define	GET_BIT(Reg,BitNb)	((Reg>>BitNb)&1)

/*!Comment : Concatinate the pins			*/
#define conc(p7,p6,p5,p4,p3,p2,p1,p0) conc_help(p7,p6,p5,p4,p3,p2,p1,p0)
#define conc_help(p7,p6,p5,p4,p3,p2,p1,p0) 0b##p7##p6##p5##p4##p3##p2##p1##p0 

/*!Comment	: Declare NULL POINTER			*/
#define NULL	((void *)0)

#endif