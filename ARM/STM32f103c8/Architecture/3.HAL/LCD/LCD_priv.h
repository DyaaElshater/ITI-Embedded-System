/************************************************/
/**	Author		:	Dyaa Elshater				*/
/**	Date		:	30/7/2019					*/
/**	Desription	:	LCD Interface private file	*/
/**	Version		:	2.0 V						*/
/************************************************/

#ifndef	_LCD_PRIV_H
#define _LCD_PRIV_H

/**Desription	:	Define LCD Mode				*/
#define LCD_MODE_4BIT	4
#define LCD_MODE_8BIT	8

/*!Comment LCD Number							*/
#ifndef LCD_NUMBER
#define LCD_NUMBER 1
#endif

/**Array of LCD Structures						*/

typedef struct strNoLCD
	{
		u8 RS	;
		u8 RW   ;
		u8 E    ;
		u8 Data[8] ;
	} LCDNumber ;



/*!Comment	: Function to write data or commands*/

void vidPutData(u8 u8DataCmdCpy,u8 u8LCDNmCpy);
void vid_SetLCDPins(LCDNumber  * PstuctLCDNbCpy , u16 u16NumCpy  );

#endif
