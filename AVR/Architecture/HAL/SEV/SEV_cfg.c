/****************************************************/
/* Author        :  Dyaa                            */
/* Description   :                                  */
/****************************************************/
#include "BIT_math.h"
#include "STD_types.h"

#include "DIO_int.h"

#include "SEV_cfg.h"
#include "SEV_priv.h"



static tstrPinNbCfg astrPinsNbcfg_var1[SEV_u8MAXNB_var1] ={
	
	{DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 ,DIO_u8PIN_2 
	 DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 , DIO_u8PIN_2},
	 
	{DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 ,DIO_u8PIN_2 
	 DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 , DIO_u8PIN_2}
	
}



static tstrPinNbCfg astrPinsNbcfg_var2[SEV_u8MAXNB_var2] ={
	
	{DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 ,DIO_u8PIN_2 
	 DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 , DIO_u8PIN_2},
	 
	{DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_3 ,DIO_u8PIN_2 
	 DIO_u8PIN_2 , DIO_u8PIN_2 ,DIO_u8PIN_2 , DIO_u8PIN_2}
	
}



tstrCompCfg astrCompCfg[u8MAX_NB_VAR]=
{
	{SEV_u8MAXNB_var1 , astrPinsNbcfg_var1 },
	{SEV_u8MAXNB_var2 , astrPinsNbcfg_var2 }
}