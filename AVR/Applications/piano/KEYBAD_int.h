/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	31/7/2019							*/
/**	Description	:	Keybad Interface 		*/
/**	Version		:	1.0	V								*/
/********************************************************/

#ifndef _KEYBAD_INT_H_
#define _KEYBAD_INT_H_


#define KEYBAD_u8ROW 4
#define KEYBAD_u8COLUMN 4

#define NOT_PRESSED 1
#define PRESSED 2
Error_Status KEYBAD_enuInit(void);

Error_Status KEYBAD_enuGetPressedKey(u8 * pu8CharCpy);


#endif