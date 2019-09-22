/****************************************************/
/* Author        :  Dyaa                            */
/* Description   :                                  */
/****************************************************/
#include "BIT_math.h"
#include "STD_types.h"

#include "DIO_int.h"

#include "SEV_int.h"
#include "SEV_cfg.h"
#include "SEV_priv.h"

#include "SVAR_int.h"

u8 SEV_u8ActiveVariant ;

void SEV_voidinit(void)
{
	
	SEV_u8ActiveVariant = SVAR_u8GetActivVariant();
}

void SEV_voidWriteDigit(u8 u8sevNbCpy , u8 u8DigitValueCpy)
{
	#if SEV_u8MODE == COMMON_ANODE
	u8 sevseg[10]={0xc0 , 0xf9 ,0xA4 , 0xB0 ,0x99 , 0x92 , 0x82 , 0xf8 , 0x80 ,0x90 };
	#else 
    u8 sevseg[10]={0x3F , 0x06 ,0x5B , 0x4F ,0x66 , 0x6D , 0x7D , 0x07 , 0x7F ,0x6F };
	#endif


DIO_voidSetPinValue(  astrCompCfg[SEV_u8ActiveVariant].pastrsevcfg[u8sevNbCpy].u8pin0 , GET_BIT(sevseg[u8DigitValueCpy],0));

DIO_voidSetPinValue( astrPinsNbcfg[u8sevNbCpy].u8Pin1  ,GET_BIT(sevseg[u8DigitValueCpy], 1));
                       
DIO_voidSetPinValue( astrPinsNbcfg[u8sevNbCpy].u8Pin2  ,GET_BIT(sevseg[u8DigitValueCpy], 2));
                       
DIO_voidSetPinValue(  astrPinsNbcfg[u8sevNbCpy].u8Pin3 ,GET_BIT(sevseg[u8DigitValueCpy], 3));
                       
DIO_voidSetPinValue( astrPinsNbcfg[u8sevNbCpy].u8Pin4  ,GET_BIT(sevseg[u8DigitValueCpy], 4));
                       
DIO_voidSetPinValue( astrPinsNbcfg[u8sevNbCpy].u8Pin5  ,GET_BIT(sevseg[u8DigitValueCpy], 5));
                       
DIO_voidSetPinValue(  astrPinsNbcfg[u8sevNbCpy].u8Pin6 ,GET_BIT(sevseg[u8DigitValueCpy], 6));
                       
DIO_voidSetPinValue(  astrPinsNbcfg[u8sevNbCpy].u8Pin7 ,GET_BIT(sevseg[u8DigitValueCpy], 7));
                       
	                   
	
}




