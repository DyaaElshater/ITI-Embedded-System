/****************************************************/
/**	Author		:	Dyaa Elshater					*/
/**	Date		:	28/7/2019						*/
/**	Desription	:	LCD Interface implementation	*/
/**	Version		:	2.0 V							*/
/****************************************************/

#include "STD_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"	/*	MCAL Drivers	*/
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"
#define F_CPU 8000000ul
#include<util/delay.h>

/*
#if		 LCD_Mode==LCD_MODE_4BIT
	
#elif	 LCD_Mode==LCD_MODE_8BIT
	
#endif
*/

LCDNumber LCDNb[LCD_NUMBER];

Error_Status LCD_enuSetLCD()
{	Error_Status status=OK;
	vid_SetLCDPins(LCDNb,LCD_NUMBER);
	return status;
}


Error_Status LCD_enuInit(u8 u8LCDNmCpy)
{
	Error_Status status = OK;
	u8 Loc_u8Iteration;

	/*Setting Direction*/
	DIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].E,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].RW,DIO_u8OUTPUT);
	DIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].RS,DIO_u8OUTPUT);
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].Data[Loc_u8Iteration],DIO_u8OUTPUT);
	}

	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,DIO_u8LOW);	/*set E pin LOW*/
	_delay_ms(30);
	(void)LCD_enuSendCmd(CMD_FUN_SET,u8LCDNmCpy);	// To Apply MISRA
	_delay_us(40);
	LCD_enuSendCmd(CMD_DISPLAY_ON_CURSOR_ON_BLINK,u8LCDNmCpy);
	_delay_us(40);
	LCD_enuSendCmd(CMD_DISPLAY_CLEAR,u8LCDNmCpy);
	_delay_ms(2);
	LCD_enuSendCmd(CMD_ENTRY_MODE_SET,u8LCDNmCpy);
	return status ;
}

Error_Status LCD_enuSendCmd(u8 u8cmdCpy,u8 u8LCDNmCpy)
{
	Error_Status status = OK;
	/*choose command register 	   */
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].RS,DIO_u8LOW);	/*RS=0*/

	/*Send the Command */

	vidPutData(u8cmdCpy,u8LCDNmCpy);
	
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,DIO_u8HIGH);	/*set E pin HIGH */
	_delay_ms(2);
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,DIO_u8LOW);	/*set E pin LOW */
	return status ;
}

Error_Status LCD_enuWriteChar(u8 u8dataCpy,u8 u8LCDNmCpy)
{
	Error_Status status = OK;
	/*choose Data register 	   */
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].RS,DIO_u8HIGH);	/*RS=1*/


	
	vidPutData(u8dataCpy,u8LCDNmCpy);
	
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,DIO_u8HIGH);	/*set E pin HIGH*/
	_delay_ms(1);
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,DIO_u8LOW);	/*set E pin LOW */
	_delay_us(40);
	return status;
}


void vidPutData(u8 u8DataCmdCpy,u8 u8LCDNmCpy)
{
	DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].RW,DIO_u8LOW);	/*RW=0*/

	u8 Loc_u8DataIteration=0;

		for(Loc_u8DataIteration=0;Loc_u8DataIteration<8;Loc_u8DataIteration++)
		{
			if(GET_BIT(u8DataCmdCpy,Loc_u8DataIteration))
			{

				DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].Data[Loc_u8DataIteration],
									DIO_u8HIGH);
			}
			else
			{

				DIO_enuSetPinValue(LCDNb[u8LCDNmCpy].Data[Loc_u8DataIteration],
									DIO_u8LOW);
			}
		}
}

Error_Status LCD_enuWriteString(u8* pu8StrCpy,u8 u8LCDNmCpy)
{	Error_Status status = OK;
	u8 Loc_u8Iteration =0;
	while(pu8StrCpy[Loc_u8Iteration])
	{
		LCD_enuWriteChar(pu8StrCpy[Loc_u8Iteration],u8LCDNmCpy);
		Loc_u8Iteration++;
	}
	return status;
}

Error_Status LCD_enuGoToXY(u8 u8XCpy,u8 u8YCpy,u8 u8LCDNmCpy)
{
	Error_Status status = OK;
	(u8YCpy==1)?LCD_enuSendCmd(0x80+u8XCpy,u8LCDNmCpy) : LCD_enuSendCmd(0xc0+u8XCpy,u8LCDNmCpy)	;
	return status;
}
