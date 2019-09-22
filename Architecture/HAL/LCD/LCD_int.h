/********************************************/
/**	Author		:	Dyaa Elshater			*/
/**	Date		:	28/7/2019				*/
/**	Desription	:	LCD Interface			*/
/**	Version		:	3.0 V					*/
/********************************************/

#ifndef	_LCD_INT_H
#define _LCD_INT_H

/**Desription	: Commands of LCD			*/

/*!Comment	: 8bits 2lines and 7dots		*/
#define	CMD_FUN_SET		0x38
/*!Comment	: Display	clear				*/
#define CMD_DISPLAY_CLEAR 0x01
/*!Comment:Entry Mode Autoincrement shiftOff*/
#define CMD_ENTRY_MODE_SET 0x06
/*!Comment: DisplayOn cursor on cursor blink*/
#define CMD_DISPLAY_ON_CURSOR_ON_BLINK	0x0f



/** Desription	: Functions Protoypes 		*/

Error_Status LCD_enuSetLCD();

Error_Status LCD_enuInit(u8 u8LCDNmCpy);

Error_Status LCD_enuSendCmd(u8 u8cmdCpy,u8 u8LCDNmCpy);

Error_Status LCD_enuWriteChar(u8 u8dataCpy,u8 u8LCDNmCpy);

Error_Status LCD_enuWriteString(u8* pu8StrCpy,u8 u8LCDNmCpy);

Error_Status LCD_enuGoToXY(u8 u8XCpy,u8 u8YCpy,u8 u8LCDNmCpy);

Error_Status LCD_enuWriteSpecifialChar(u8 *pu8PatternCpy , u8 u8BlockCpy , u8 u8XposCpy , u8 u8YposCpy,u8 LcdNb );
#endif
