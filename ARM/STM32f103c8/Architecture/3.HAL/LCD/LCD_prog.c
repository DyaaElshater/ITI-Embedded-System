/****************************************************/
/**	Author		:	Dyaa Elshater					*/
/**	Date		:	28/7/2019						*/
/**	Desription	:	LCD Interface implementation	*/
/**	Version		:	3.0 V							*/
/****************************************************/

#include "STD_types.h"
#include "Bit_Math.h"
#include "DELAY.h"

#include "GPIO_int.h"	/*	MCAL Drivers	*/
#include "LCD_int.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"

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
	GPIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].E,GPIO_u8OUTPUT);
	GPIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].RW,GPIO_u8OUTPUT);
	GPIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].RS,GPIO_u8OUTPUT);
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		GPIO_enuSetPinDirection(LCDNb[u8LCDNmCpy].Data[Loc_u8Iteration],GPIO_u8OUTPUT);
	}

	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,GPIO_u8LOW);	/*set E pin LOW*/
	delay_ms(30);
	(void)LCD_enuSendCmd(CMD_FUN_SET,u8LCDNmCpy);	// To Apply MISRA
	delay_us(40);
	LCD_enuSendCmd(CMD_DISPLAY_ON_CURSOR_ON_BLINK,u8LCDNmCpy);
	delay_us(40);
	LCD_enuSendCmd(CMD_DISPLAY_CLEAR,u8LCDNmCpy);
	delay_ms(2);
	LCD_enuSendCmd(CMD_ENTRY_MODE_SET,u8LCDNmCpy);
	return status ;
}

Error_Status LCD_enuSendCmd(u8 u8cmdCpy,u8 u8LCDNmCpy)
{
	Error_Status status = OK;
	/*choose command register 	   */
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].RS,GPIO_u8LOW);	/*RS=0*/

	/*Send the Command */

	vidPutData(u8cmdCpy,u8LCDNmCpy);
	
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,GPIO_u8HIGH);	/*set E pin HIGH */
	delay_ms(2);
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,GPIO_u8LOW);	/*set E pin LOW */
	return status ;
}

Error_Status LCD_enuWriteChar(u8 u8dataCpy,u8 u8LCDNmCpy)
{
	Error_Status status = OK;
	/*choose Data register 	   */
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].RS,GPIO_u8HIGH);	/*RS=1*/


	
	vidPutData(u8dataCpy,u8LCDNmCpy);
	
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,GPIO_u8HIGH);	/*set E pin HIGH*/
	delay_ms(1);
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].E,GPIO_u8LOW);	/*set E pin LOW */
	delay_us(40);
	return status;
}


void vidPutData(u8 u8DataCmdCpy,u8 u8LCDNmCpy)
{
	GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].RW,GPIO_u8LOW);	/*RW=0*/

	u8 Loc_u8DataIteration=0;

		for(Loc_u8DataIteration=0;Loc_u8DataIteration<8;Loc_u8DataIteration++)
		{
			if(GET_BIT(u8DataCmdCpy,Loc_u8DataIteration))
			{

				GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].Data[Loc_u8DataIteration],
									GPIO_u8HIGH);
			}
			else
			{

				GPIO_enuSetPinValue(LCDNb[u8LCDNmCpy].Data[Loc_u8DataIteration],
									GPIO_u8LOW);
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
	(u8YCpy==0)?LCD_enuSendCmd(0x80+u8XCpy,u8LCDNmCpy) : LCD_enuSendCmd(0xc0+u8XCpy,u8LCDNmCpy)	;
	return status;
}

Error_Status LCD_enuWriteSpecifialChar(u8 *pu8PatternCpy , u8 u8BlockCpy , u8 u8XposCpy , u8 u8YposCpy,u8 LcdNb )
{
	Error_Status status = OK ;
	if(pu8PatternCpy == NULL )
	{
		status = NULL_POINTRE;
	}
	else if (u8BlockCpy>8)
	{
		status = INDEX_OUT_OF_RANGE;
	}
	else
	{
		LCD_enuSendCmd(u8BlockCpy*8 + 64,LcdNb);
		u8 u8Iteration;
		for(u8Iteration=0;u8Iteration<8;u8Iteration++)
		{
			LCD_enuWriteChar(pu8PatternCpy[u8Iteration],LcdNb);
		}
		status = LCD_enuGoToXY(u8XposCpy,u8YposCpy,LcdNb);
		LCD_enuWriteChar(u8BlockCpy,LcdNb);
	}
	return status ;
}
Error_Status LCD_enuWriteNumber(u32 u32numberCpy,u8 u8LcdNbCpy)
{
	Error_Status Loc_enuStatus = OK;
	s8  Loc_8s8String[20] ;
	itoa(u32numberCpy,Loc_8s8String,10);
	LCD_enuWriteString(Loc_8s8String,u8LcdNbCpy);
	return Loc_enuStatus;
}

Error_Status LCD_enuShiftLeft(u8 u8ShiftNbCpy,u8 u8LcdNbCpy)
{
	Error_Status Loc_enuStatus = OK;
	u8 Loc_u8Iteration ;
	for(Loc_u8Iteration=0;Loc_u8Iteration<u8ShiftNbCpy;Loc_u8Iteration++)
	{
		LCD_enuSendCmd(0x18,u8LcdNbCpy);
	}
	return Loc_enuStatus;
}

Error_Status LCD_enuShiftRight(u8 u8ShiftNbCpy,u8 u8LcdNbCpy)
{
	Error_Status Loc_enuStatus = OK;
	u8 Loc_u8Iteration ;
	for(Loc_u8Iteration=0;Loc_u8Iteration<u8ShiftNbCpy;Loc_u8Iteration++)
	{
		LCD_enuSendCmd(0x1C,u8LcdNbCpy);
	}
	return Loc_enuStatus;
}
