
/****************************************************/
/** Author		:	Dyaa Elshater					*/
/** Date		:	25/7/2019						*/
/** Descrption	: Configuration of file to DIO		*/
/** Version		: 1.0V								*/
/****************************************************/
#include "STD_types.h"
#include "Bit_Math.h"

#include "GPIO_int.h"	/*	MCAL Drivers	*/
#include "LCD_int.h"


#include "LCD_cfg.h"
#include "LCD_priv.h"
extern LCDNumber LCDNb[LCD_NUMBER];

void vid_SetLCDPins(LCDNumber* PstructLCDNbCpy , u16 u16NumCpy )
{



	PstructLCDNbCpy[0].RS=		GPIO_u8PB_6;
	PstructLCDNbCpy[0].RW=		GPIO_u8PB_7;
	PstructLCDNbCpy[0].E =		GPIO_u8PB_8;
	PstructLCDNbCpy[0].Data[0]=	GPIO_u8PB_12;
	PstructLCDNbCpy[0].Data[1]=	GPIO_u8PB_13;
	PstructLCDNbCpy[0].Data[2]=	GPIO_u8PB_14;
	PstructLCDNbCpy[0].Data[3]=	GPIO_u8PB_15;
	PstructLCDNbCpy[0].Data[4]=	GPIO_u8PA_8;
	PstructLCDNbCpy[0].Data[5]=	GPIO_u8PA_9;
	PstructLCDNbCpy[0].Data[6]=	GPIO_u8PA_10;
	PstructLCDNbCpy[0].Data[7]=	GPIO_u8PA_11;


	PstructLCDNbCpy[1].RS=		GPIO_u8Pin_31;
	PstructLCDNbCpy[1].RW=		GPIO_u8Pin_31;
	PstructLCDNbCpy[1].E =		GPIO_u8Pin_29;
	PstructLCDNbCpy[1].Data[0]=	GPIO_u8Pin_20;
	PstructLCDNbCpy[1].Data[1]=	GPIO_u8Pin_21;
	PstructLCDNbCpy[1].Data[2]=	GPIO_u8Pin_22;
	PstructLCDNbCpy[1].Data[3]=	GPIO_u8Pin_23;
	PstructLCDNbCpy[1].Data[4]=	GPIO_u8Pin_7;
	PstructLCDNbCpy[1].Data[5]=	GPIO_u8Pin_6;
	PstructLCDNbCpy[1].Data[6]=	GPIO_u8Pin_5;
	PstructLCDNbCpy[1].Data[7]=	GPIO_u8Pin_4;

}
