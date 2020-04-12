/********************************************/
/** Author 		: Dyaa Elshater             */
/** Date 		: 9/7/2019					*/
/** Description : Bit Math Library 			*/
/** Virsion     : 2.0v				 		*/
/** Note		: For 32 Bit				*/
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
#define conc(p31,p30,p29,p28,p27,p26,p25,p24,p23,p22,p21,p20,p19,p18,p17,p16,p15,p14,p13,p12,p11,p10,p9,p8,p7,p6,p5,p4,p3,p2,p1,p0) conc_help(p31,p30,p29,p28,p27,p26,p25,p24,p23,p22,p21,p20,p19,p18,p17,p16,p15,p14,p13,p12,p11,p10,p9,p8,p7,p6,p5,p4,p3,p2,p1,p0)
#define conc_help(p31,p30,p29,p28,p27,p26,p25,p24,p23,p22,p21,p20,p19,p18,p17,p16,p15,p14,p13,p12,p11,p10,p9,p8,p7,p6,p5,p4,p3,p2,p1,p0) 0b##p31##p30##p29##p28##p27##p26##p25##p24##p23##p22##p21##p20##p19##p18##p17##p16##p15##p14##p13##p12##p11##p10##p9##p8##p7##p6##p5##p4##p3##p2##p1##p0

/*!Comment	: Declare NULL POINTER			*/
#define NULL	((void *)0)

#endif
