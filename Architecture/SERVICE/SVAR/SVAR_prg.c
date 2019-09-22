/****************************************************/
/* LOG                                              */
/****************************************************/
#include "STD_types.h"
#include "BIT_math.h"

#include "DIO_int.h"

#include "SVAR_int.h"
#include "SVAR_cfg.h"
#include "SVAR_priv.h"

u8 SVAR_u8GetActivVariant(void)
{
	u8 u8ActiVarLoc ; 
	
	u8ActiVarLoc  = DIO_u8GetPinValue(SVAR_u8PIN_0);
	u8ActiVarLoc |= DIO_u8GetPinValue(SVAR_u8PIN_1)<<1;
	
	
	
	return u8ActiVarLoc ;
}