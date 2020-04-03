/****************************************************/
/** Author		:	Dyaa Elshater					*/
/** Date		:	25/7/2019						*/
/** Descrption	: driver file to DIO				*/
/** Version		: 2.0V								*/
/****************************************************/


#include "STD_types.h"
#include "BIT_Math.h"

#include "DIO_int.h"
#include "DIO_cfg.h"
#include "DIO_priv.h"	


/****************************************************/
/** Descrption	: intialization function to DIO and	*/
/* determine the dirction of all pins				*/
/****************************************************/


Error_Status DIO_enuInt(void)
{
	Error_Status status = OK;
	DDRA=	conc(DIO_u8PINDIR_7,DIO_u8PINDIR_6,DIO_u8PINDIR_5,DIO_u8PINDIR_4,DIO_u8PINDIR_3,DIO_u8PINDIR_2,DIO_u8PINDIR_1,DIO_u8PINDIR_0);
	DDRB=	conc(DIO_u8PINDIR_15,DIO_u8PINDIR_14,DIO_u8PINDIR_13,DIO_u8PINDIR_12,DIO_u8PINDIR_11,DIO_u8PINDIR_10,DIO_u8PINDIR_9,DIO_u8PINDIR_8);
	DDRC=	conc(DIO_u8PINDIR_23,DIO_u8PINDIR_22,DIO_u8PINDIR_21,DIO_u8PINDIR_20,DIO_u8PINDIR_19,DIO_u8PINDIR_18,DIO_u8PINDIR_17,DIO_u8PINDIR_16);
	DDRD=	conc(DIO_u8PINDIR_31,DIO_u8PINDIR_30,DIO_u8PINDIR_29,DIO_u8PINDIR_28,DIO_u8PINDIR_27,DIO_u8PINDIR_26,DIO_u8PINDIR_25,DIO_u8PINDIR_24);	
	return status ;
	}

/****************************************************/
/** Descrption	: Function used to set pin in		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins foom 0 to 31	*/
/*			 u8ValueCpy value mean DIO_u8HIGH 		*/
/*							or DIO_u8LOW			*/
/****************************************************/

Error_Status DIO_enuSetPinValue(u8 u8PinNbCpy ,u8 u8ValueCpy)
{
	Error_Status Loc_enuStatus=OK;
	
	if(u8ValueCpy!=DIO_u8HIGH	&&	 u8ValueCpy!=DIO_u8LOW	)
	{
		Loc_enuStatus = NOK;
	}
	else if(u8PinNbCpy>DIO_u8PIN_31)
	{
		Loc_enuStatus = INDEX_OUT_OF_RANGE;
	}
	else if(u8PinNbCpy<=DIO_u8PIN_7)
	{
		u8PinNbCpy-= DIO_u8_PORTA_START;
	//	u8PinNbCpy%= DIO_u8_PORT_SIZE;
		if(u8ValueCpy==DIO_u8LOW)
		{
			CLEAR_BIT(PORTA,u8PinNbCpy);
		}
		else
		{
			SET_BIT(PORTA,u8PinNbCpy);
		}
	}
	else if (u8PinNbCpy<=DIO_u8PIN_15)
	{	
		u8PinNbCpy-= DIO_u8_PORTB_START;
		if(u8ValueCpy==DIO_u8LOW)
		{
			CLEAR_BIT(PORTB,u8PinNbCpy);
		}
		else
		{
			SET_BIT(PORTB,u8PinNbCpy);
		}
	}
	else if (u8PinNbCpy<=DIO_u8PIN_23)
	{
		u8PinNbCpy-= DIO_u8_PORTC_START;
		if(u8ValueCpy==DIO_u8LOW)
		{
			CLEAR_BIT(PORTC,u8PinNbCpy);
		}
		else
		{
			SET_BIT(PORTC,u8PinNbCpy);
		}
	}
	//else if (DIO_u8PIN_24<=u8PinNbCpy&&u8PinNbCpy<=DIO_u8PIN_31)
	else
	{
		u8PinNbCpy-= DIO_u8_PORTD_START;
		if(u8ValueCpy==DIO_u8LOW)
		{
			CLEAR_BIT(PORTD,u8PinNbCpy);
		}
		else
		{
			SET_BIT(PORTD,u8PinNbCpy);
		}
	}
	return Loc_enuStatus	;
}

/****************************************************/
/** Descrption	: Function used to get pin from		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins foom 0 to 31	*/
/** Output : it return the pin Value 				*/
/****************************************************/

Error_Status DIO_enuGetPinValue(u8 u8PinNbCpy,u8*pu8PinValueCpy)
{	
	Error_Status Loc_enuStatus = OK ;
	if(u8PinNbCpy>DIO_u8PIN_31)
	{
		Loc_enuStatus=INDEX_OUT_OF_RANGE;
	}
	else if(pu8PinValueCpy==NULL)
	{
		Loc_enuStatus=NULL_POINTRE;
	}
	if(u8PinNbCpy<=DIO_u8PIN_7)
	{
		u8PinNbCpy-= DIO_u8_PORTA_START;
		*pu8PinValueCpy = GET_BIT(PINA,u8PinNbCpy);
	} 
	else if(u8PinNbCpy<=DIO_u8PIN_15)
	{
		u8PinNbCpy-= DIO_u8_PORTB_START;
		*pu8PinValueCpy = GET_BIT(PINB,u8PinNbCpy);
	}
	else if(u8PinNbCpy<=DIO_u8PIN_23)
	{
		u8PinNbCpy-= DIO_u8_PORTC_START;
		*pu8PinValueCpy = GET_BIT(PINC,u8PinNbCpy);
	}
	//else if(DIO_u8PIN_24<=u8PinNbCpy&&u8PinNbCpy<=DIO_u8PIN_31)
	else
	{
		u8PinNbCpy-= DIO_u8_PORTD_START;
		*pu8PinValueCpy = GET_BIT(PIND,u8PinNbCpy);
	}
	return Loc_enuStatus ;
}
/****************************************************/
/** Descrption	: Function used to set the pin 		*/
/* direction .						   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPinDirection(u8 u8PinNbCpy, u8 u8PinStateCpy)
{
	Error_Status Loc_enuStatus = OK;
	if(u8PinStateCpy!=DIO_u8OUTPUT	&&	u8PinStateCpy!=DIO_u8INPUT)
	{
		Loc_enuStatus= NOK;
	}
	else if(u8PinNbCpy>DIO_u8PIN_31)
	{
		Loc_enuStatus= INDEX_OUT_OF_RANGE;
	}
	if(u8PinNbCpy<=DIO_u8PIN_7)
	{
		u8PinNbCpy-= DIO_u8_PORTA_START;
		if(u8PinStateCpy==DIO_u8INPUT)
		{
			CLEAR_BIT(DDRA,u8PinNbCpy);
		}
		else
		{
			SET_BIT(DDRA,u8PinNbCpy);
		}
	}
	else if (u8PinNbCpy<=DIO_u8PIN_15)
	{
		u8PinNbCpy-= DIO_u8_PORTB_START;
		if(u8PinStateCpy==DIO_u8INPUT)
		{
			CLEAR_BIT(DDRB,u8PinNbCpy);
		}
		else
		{
			SET_BIT(DDRB,u8PinNbCpy);
		}
	}
	else if (u8PinNbCpy<=DIO_u8PIN_23)
	{
		u8PinNbCpy-= DIO_u8_PORTC_START;
		if(u8PinStateCpy==DIO_u8INPUT)
		{
			CLEAR_BIT(DDRC,u8PinNbCpy);
		}
		else
		{
			SET_BIT(DDRC,u8PinNbCpy);
		}
	}
	//else if (DIO_u8PIN_24<=u8PinNbCpy&&u8PinNbCpy<=DIO_u8PIN_31)
	else
	{
		u8PinNbCpy-= DIO_u8_PORTD_START;
		if(u8PinStateCpy==DIO_u8INPUT)
		{
			CLEAR_BIT(DDRD,u8PinNbCpy);
		}
		else
		{
			SET_BIT(DDRD,u8PinNbCpy);
		}
	}
	return Loc_enuStatus;
}

/****************************************************/
/** Descrption	: Function used to toggle the pin .	*/
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status 							*/
/****************************************************/

Error_Status DIO_enuTogglePin(u8 u8PinNbCpy)
{
	Error_Status Loc_enuStatus = OK;
	if(u8PinNbCpy>DIO_u8PIN_31)
	{
		Loc_enuStatus=INDEX_OUT_OF_RANGE;
	}
	else if(u8PinNbCpy<=DIO_u8PIN_7)
	{
		u8PinNbCpy-= DIO_u8_PORTA_START;
		TOGGLE_BIT(PORTA,u8PinNbCpy);
	}
	else if (u8PinNbCpy<=DIO_u8PIN_15)
	{
		u8PinNbCpy-= DIO_u8_PORTB_START;
		TOGGLE_BIT(PORTB,u8PinNbCpy);
	}
	else if (u8PinNbCpy<=DIO_u8PIN_23)
	{
		u8PinNbCpy-= DIO_u8_PORTC_START;
		TOGGLE_BIT(PORTC,u8PinNbCpy);
	}
	//else if (u8PinNbCpy<=DIO_u8PIN_31)
	else
	{
		u8PinNbCpy-= DIO_u8_PORTD_START;
		TOGGLE_BIT(PORTD,u8PinNbCpy);
	}
	return Loc_enuStatus;
}

/****************************************************/
/** Descrption	: Function used to make pull up .	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuPullUp(u8 u8PinNbCpy)
{
	return DIO_enuSetPinValue(u8PinNbCpy,DIO_u8OUTPUT);
}
/****************************************************/
/** Descrption:Function used to get value form PORTX*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuGetPortX(u8 *pu8ValueCpy)	// Complete the function
{
	Error_Status status = OK;	
	u8 Loc_u8temp;
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(DIO_arrPortX[Loc_u8Iteration],DIO_u8INPUT);
		DIO_enuPullUp(DIO_arrPortX[Loc_u8Iteration]);
		DIO_enuGetPinValue(DIO_arrPortX[Loc_u8Iteration],&Loc_u8temp);
		*pu8ValueCpy |= Loc_u8temp<<Loc_u8Iteration;
	}
	
	return status ;
}

/****************************************************/
/** Descrption:Function used to set value to PORTX	*/
/** Inputs : u8ValueCpy  input value 				*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPortX(u8 u8ValueCpy)
{	
	Error_Status status = OK;

	/*Setting the Direction*/

	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(DIO_arrPortX[Loc_u8Iteration],DIO_u8OUTPUT);
		if(u8ValueCpy&(1<<Loc_u8Iteration))
		{
			DIO_enuSetPinValue(DIO_arrPortX[Loc_u8Iteration],DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_arrPortX[Loc_u8Iteration],DIO_u8LOW);
		}
	}
	return status;
}

/****************************************************/
/** Descrption:Function used to get value form PORTY*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuGetPortY(u8 *pu8ValueCpy)	// Complete the function
{
	Error_Status status = OK;	
	u8 Loc_u8temp;
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(DIO_arrPortY[Loc_u8Iteration],DIO_u8INPUT);
		DIO_enuPullUp(DIO_arrPortY[Loc_u8Iteration]);
		DIO_enuGetPinValue(DIO_arrPortY[Loc_u8Iteration],&Loc_u8temp);
		*pu8ValueCpy |= Loc_u8temp<<Loc_u8Iteration;
	}


	return status ;
}

/****************************************************/
/** Descrption:Function used to set value to PORTY	*/
/** Inputs : u8ValueCpy  input value 				*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPortY(u8 u8ValueCpy)
{
	Error_Status status = OK;

	/*Setting the Direction*/
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(DIO_arrPortY[Loc_u8Iteration],DIO_u8OUTPUT);
		if(u8ValueCpy&(1<<Loc_u8Iteration))
		{
			DIO_enuSetPinValue(DIO_arrPortY[Loc_u8Iteration],DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_arrPortY[Loc_u8Iteration],DIO_u8LOW);
		}
	}
	return status;
	}

/****************************************************/
/** Descrption:Function used to get value form PORTZ*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuGetPortZ(u8 *pu8ValueCpy)	// Complete the function
{
	*pu8ValueCpy = 0;
	Error_Status status = OK;	
	u8 Loc_u8temp=0;
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(DIO_arrPortZ[Loc_u8Iteration],DIO_u8INPUT);
		DIO_enuPullUp(DIO_arrPortZ[Loc_u8Iteration]);
		DIO_enuGetPinValue(DIO_arrPortZ[Loc_u8Iteration],&Loc_u8temp);
		*pu8ValueCpy |= Loc_u8temp<<Loc_u8Iteration;
	}
	
	return status ;
}

/****************************************************/
/** Descrption:Function used to set value to PORTZ	*/
/** Inputs : u8ValueCpy  input value 				*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPortZ(u8 u8ValueCpy)
{
	Error_Status status = OK;
	/*Setting the Direction*/
	u8 Loc_u8Iteration;
	for(Loc_u8Iteration=0;Loc_u8Iteration<8;Loc_u8Iteration++)
	{
		DIO_enuSetPinDirection(DIO_arrPortZ[Loc_u8Iteration],DIO_u8OUTPUT);
		if(u8ValueCpy&(1<<Loc_u8Iteration))
		{
			DIO_enuSetPinValue(DIO_arrPortZ[Loc_u8Iteration],DIO_u8HIGH);
		}
		else
		{
			DIO_enuSetPinValue(DIO_arrPortZ[Loc_u8Iteration],DIO_u8LOW);
		}
	}
	return status;
	}


//////////////////////////////////////////////////////////
void Set_Port_Direction(u8 port_index,u8 Direction)
{	u8 res=PORT_INPUT ;
	if(Direction== PORT_OUTPUT )
	{
		res = PORT_OUTPUT;
	}
	switch (port_index)
	{
		case PORTA_DIO:
			DDRA = res;
			break;
		case PORTB_DIO:
			DDRB=res;
			break;
		case PORTC_DIO:
			DDRC = res;
			break;
		case PORTD_DIO:
			DDRD=res;
			break;
	}
}
void Set_Port_Value	(u8 port_index,u8 value)
{
	switch (port_index)
	{
		case PORTA_DIO:
			PORTA=value;
			break;
		case PORTB_DIO:
			PORTB=value;
			break;
		case PORTC_DIO:
			PORTC=value;
			break;
		case PORTD_DIO:
			PORTD=value;
			break;
	}
}
//////////////////////////////////////////////////////////

