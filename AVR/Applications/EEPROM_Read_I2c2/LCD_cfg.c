
/****************************************************/
/** Author		:	Dyaa Elshater					*/
/** Date		:	25/7/2019						*/
/** Descrption	: Configuration of file to DIO		*/
/** Version		: 1.0V								*/
/****************************************************/
#include "STD_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"	/*	MCAL Drivers	*/
#include "LCD_int.h"


#include "LCD_cfg.h"
#include "LCD_priv.h"
extern LCDNumber LCDNb[LCD_NUMBER];

void vid_SetLCDPins(LCDNumber* PstructLCDNbCpy , u16 u16NumCpy )
{



	PstructLCDNbCpy[0].RS=DIO_u8PIN_28;
	PstructLCDNbCpy[0].RW=DIO_u8PIN_27;
	PstructLCDNbCpy[0].E =DIO_u8PIN_26;
	PstructLCDNbCpy[0].Data[0]=DIO_u8PIN_25;
	PstructLCDNbCpy[0].Data[1]=DIO_u8PIN_24;
	PstructLCDNbCpy[0].Data[2]=DIO_u8PIN_18;
	PstructLCDNbCpy[0].Data[3]=DIO_u8PIN_19;
	PstructLCDNbCpy[0].Data[4]=DIO_u8PIN_20;
	PstructLCDNbCpy[0].Data[5]=DIO_u8PIN_21;
	PstructLCDNbCpy[0].Data[6]=DIO_u8PIN_22;
	PstructLCDNbCpy[0].Data[7]=DIO_u8PIN_23;


	PstructLCDNbCpy[1].RS=DIO_u8PIN_31;
	PstructLCDNbCpy[1].RW=DIO_u8PIN_30;
	PstructLCDNbCpy[1].E =DIO_u8PIN_29;
	PstructLCDNbCpy[1].Data[0]=DIO_u8PIN_20;
	PstructLCDNbCpy[1].Data[1]=DIO_u8PIN_21;
	PstructLCDNbCpy[1].Data[2]=DIO_u8PIN_22;
	PstructLCDNbCpy[1].Data[3]=DIO_u8PIN_23;
	PstructLCDNbCpy[1].Data[4]=DIO_u8PIN_7;
	PstructLCDNbCpy[1].Data[5]=	DIO_u8PIN_6;
	PstructLCDNbCpy[1].Data[6]=	DIO_u8PIN_5;
	PstructLCDNbCpy[1].Data[7]=	DIO_u8PIN_4;

}
