#include "Std_types.h"
#include"Bit_Math.h"

#include"EXT0_int.h"
#include"EXT0_config.h"
#include"EXT0_priv.h"


vidpfvid call_back;


void EXT0_Set_Call_back(vidpfvid address)
{
	call_back = address;
}


void EXT0_vidInit(void)
{
	/* choose mode according to configuration */
	#if 	EXT0_MODE == EXT0_MODE_u8LOW_LEVEL
		CLEAR_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
	#elif 	EXT0_MODE == EXT0_MODE_u8ON_CHANGE
		CLEAR_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 0);
	#elif	EXT0_MODE == EXT0_MODE_u8FALLING_EDGE
		SET_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
	#elif	EXT0_MODE == EXT0_MODE_u8RISING_EDGE
		SET_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 0);
	#else
		#warning " invalid mode number so we put the default as falling edge "
		SET_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
	#endif
	
	
	/* clear flag before enabling the interrupt */
	SET_BIT(GIFR , 6);
	
	/* enabling the interrupt */
	SET_BIT(GICR , 6);
}

Error_Status EXT0_enuChange_Mode(u8 Mode_Number_Cpy)
{
	u8 status = OK ;
	if 	(Mode_Number_Cpy == EXT0_MODE_u8LOW_LEVEL)
	{
		CLEAR_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
	}
	else if 	(Mode_Number_Cpy == EXT0_MODE_u8ON_CHANGE)
	{
		CLEAR_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 0);
	}
	else if	(Mode_Number_Cpy == EXT0_MODE_u8FALLING_EDGE)
	{
		SET_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
	}
	else if	(Mode_Number_Cpy == EXT0_MODE_u8RISING_EDGE)
	{
		SET_BIT(MCUCR , 1);
		SET_BIT(MCUCR , 0);
	}
	else
	{
		status = NOK;
		SET_BIT(MCUCR , 1);
		CLEAR_BIT(MCUCR , 0);
	}
	return status;
}

void EXT0_vidDisable(void)
{
	CLEAR_BIT(GICR , 6);
}

u8 EXT0_u8Read_Flag(void)
{
	return(GET_BIT(GIFR , 6));
}


void __vector_1 (void) __attribute__((signal ,used));
void __vector_1 (void)
{
	(*call_back)();
}

