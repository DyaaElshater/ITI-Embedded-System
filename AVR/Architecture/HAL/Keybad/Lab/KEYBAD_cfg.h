/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	31/7/2019							*/
/**	Description	:	Keybad configuration				*/
/**	Version		:	1.0	V								*/
/********************************************************/

/**Dscription	:	Define Pins	*/

#define KEYBAD_PORT	PORTD_DIO

#define KEYBAD_u8ROW_1 DIO_u8PIN_28
#define KEYBAD_u8ROW_2 DIO_u8PIN_29
#define KEYBAD_u8ROW_3 DIO_u8PIN_30
#define KEYBAD_u8ROW_4 DIO_u8PIN_31


#define KEYBAD_u8COLUMNS_1 DIO_u8PIN_27
#define KEYBAD_u8COLUMNS_2 DIO_u8PIN_26
#define KEYBAD_u8COLUMNS_3 DIO_u8PIN_25
#define KEYBAD_u8COLUMNS_4 DIO_u8PIN_24


u8 arrKeybadElements [KEYBAD_u8ROW][KEYBAD_u8COLUMN] =
{
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}

};
