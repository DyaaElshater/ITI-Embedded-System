/********************************************************/
/** Author		:	Dyaa Elshater						*/
/** Date		:	31/7/2019							*/
/**	Description	:	Keybad Interface implementation		*/
/**	Version		:	1.0	V								*/
/********************************************************/

#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"

#include "KEYBAD_int.h"
#include "KEYBAD_cfg.h"
#include "KEYBAD_priv.h"


Error_Status KEYBAD_enuInit(void)
{
	Error_Status status = OK;
	/*Dirction of Rows are OUTPUT*/
	/*Initialization ROWS = ones */

	u8 Loc_u8Iteration;

/*	for(Loc_u8Iteration=0;Loc_u8Iteration<4;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(arrKeybad[Loc_u8Iteration],DIO_u8OUTPUT);
		DIO_enuSetPinValue(arrKeybad[Loc_u8Iteration],DIO_u8HIGH);
	}*/


	/*Dirction of Columns are OUTPUT*/
	/*Initialization Columns as Pull up */

	for(Loc_u8Iteration=4;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(arrKeybad[Loc_u8Iteration],DIO_u8INPUT);
		DIO_enuPullUp(arrKeybad[Loc_u8Iteration]);
	}
	return status ;
}

Error_Status KEYBAD_enuGetChar(u8 * pu8CharCpy)
{
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<4;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(arrKeybad[Loc_u8Iteration],DIO_u8OUTPUT);
		DIO_enuSetPinValue(arrKeybad[Loc_u8Iteration],DIO_u8HIGH);
	}

	/*For loop to ground very rows*/
	u8 Loc_u8Iteration_ROW,Loc_u8Iteration_COLUMN;
	for(Loc_u8Iteration_ROW=0;Loc_u8Iteration_ROW<4;Loc_u8Iteration_ROW++)
	{
		DIO_enuSetPinValue(arrKeybad[Loc_u8Iteration_ROW],DIO_u8LOW);
		/*for loop to check each coloumn if it's zero or not */

		for(Loc_u8Iteration_COLUMN=0;Loc_u8Iteration_COLUMN<4;Loc_u8Iteration_COLUMN++)
		{
			u8 Loc_u8GetValue,Loc_u8Pressed=0;
				do
				{
					DIO_enuGetPinValue(arrKeybad[Loc_u8Iteration_COLUMN+4],&Loc_u8GetValue);

				}while((Loc_u8GetValue==0) && (++Loc_u8Pressed));
				/*Return the result*/
				if(Loc_u8Pressed)
				{
					*pu8CharCpy = arrKeybadElements[Loc_u8Iteration_ROW][Loc_u8Iteration_COLUMN];
					return PRESSED;	/*Try to use another solution*/
				}




		}
		DIO_enuSetPinValue(arrKeybad[Loc_u8Iteration_ROW],DIO_u8HIGH);
	}
	return NOT_PRESSED;
}
