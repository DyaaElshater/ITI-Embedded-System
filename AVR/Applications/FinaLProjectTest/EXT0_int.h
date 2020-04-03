#ifndef EXT0_INT_H
#define EXT0_INT_H


#define EXT0_MODE_u8FALLING_EDGE  	1
#define EXT0_MODE_u8RISING_EDGE 	2
#define EXT0_MODE_u8ON_CHANGE  		3
#define EXT0_MODE_u8LOW_LEVEL	  	4


/*
	preconditions : set the DIO pin direction of EXT0 to input
	in ATmega 32 : D2 -> pin no.26
*/
void EXT0_vidInit(void);

Error_Status EXT0_enuChange_Mode(u8 Mode_Number_Cpy);

void EXT0_vidDisable(void);

u8 EXT0_u8Read_Flag(void);

void EXT0_Set_Call_back(vidpfvid address);


#endif
