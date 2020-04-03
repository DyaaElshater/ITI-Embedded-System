/****************************************************/
/** Author		:	Dyaa Elshater					*/
/** Date		:	25/7/2019						*/
/** Descrption	: interface file to DIO				*/
/** Version		: 2.0V								*/
/****************************************************/

#ifndef DIO_INT_H_
#define DIO_INT_H_

#define DIO_u8PIN_0		0
#define DIO_u8PIN_1		1
#define DIO_u8PIN_2		2
#define DIO_u8PIN_3		3
#define DIO_u8PIN_4		4
#define DIO_u8PIN_5		5
#define DIO_u8PIN_6		6
#define DIO_u8PIN_7		7
						
#define DIO_u8PIN_8		8
#define DIO_u8PIN_9		9
#define DIO_u8PIN_10	10
#define DIO_u8PIN_11	11
#define DIO_u8PIN_12	12
#define DIO_u8PIN_13	13
#define DIO_u8PIN_14	14
#define DIO_u8PIN_15	15
					    
#define DIO_u8PIN_16	16
#define DIO_u8PIN_17	17
#define DIO_u8PIN_18	18
#define DIO_u8PIN_19	19
#define DIO_u8PIN_20	20
#define DIO_u8PIN_21	21
#define DIO_u8PIN_22	22
#define DIO_u8PIN_23	23
					    
#define DIO_u8PIN_24	24
#define DIO_u8PIN_25	25
#define DIO_u8PIN_26	26
#define DIO_u8PIN_27	27
#define DIO_u8PIN_28	28
#define DIO_u8PIN_29	29
#define DIO_u8PIN_30	30
#define DIO_u8PIN_31	31

#define DIO_u8HIGH		1
#define DIO_u8LOW		0

/** Descrption	: Input and Output 					*/
#define DIO_u8OUTPUT	1
#define DIO_u8INPUT		0


/****************************************************/
/** Descrption	: intialization function to DIO and	*/
/* determine the dirction of all pins				*/
/****************************************************/

Error_Status DIO_enuInt(void);
/****************************************************/
/** Descrption	: Finction used to set pin in		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins foom 0 to 31	*/
/*			 u8ValueCpy value mean DIO_u8HIGH 		*/
/*							or DIO_u8LOW			*/
/****************************************************/

Error_Status DIO_enuSetPinValue(u8 u8PinNbCpy ,u8 u8ValueCpy);

/****************************************************/
/** Descrption	: Finction used to get pin from		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : it return the pin Value 				*/
/****************************************************/

Error_Status DIO_enuGetPinValue(u8 u8PinNbCpy,u8*pu8PinValueCpy);

/****************************************************/
/** Descrption	: Finction used to set the pin 		*/
/* direction .						   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPinDirection(u8 u8pinNbCpy, u8 u8PinStateCpy);

/****************************************************/
/** Descrption	: Finction used to toggle the pin .	*/
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status 							*/
/****************************************************/

Error_Status DIO_enuTogglePin (u8 u8PinNbCpy);

/****************************************************/
/** Descrption	: Finction used to make pull up .	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuPullUp(u8 u8PinNbCpy);


/****************************************************/
/** Descrption:Function used to get value form PORTX*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuGetPortX(u8 *pu8ValueCpy);

/****************************************************/
/** Descrption:Function used to set value to PORTX	*/
/** Inputs : u8ValueCpy  input value 				*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPortX(u8 u8ValueCpy);

/****************************************************/
/** Descrption:Function used to get value form PORTY*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuGetPortY(u8 *pu8ValueCpy);

/****************************************************/
/** Descrption:Function used to set value to PORTY	*/
/** Inputs : u8ValueCpy  input value 				*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPortY(u8 u8ValueCpy);

/****************************************************/
/** Descrption:Function used to get value form PORTZ*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuGetPortZ(u8 *pu8ValueCpy);

/****************************************************/
/** Descrption:Function used to set value to PORTZ	*/
/** Inputs : u8ValueCpy  input value 				*/
/** Output : Error Status  							*/
/****************************************************/

Error_Status DIO_enuSetPortZ(u8 u8ValueCpy);

//////////////////////////////////////////////////////////
void Set_Port_Direction(u8 port_index,u8 Directiopn);
void Set_Port_Value	(u8 port_index,u8 value);
#define PORTA_DIO	0
#define PORTB_DIO	1
#define PORTC_DIO	2
#define PORTD_DIO	3

#define PORT_OUTPUT	0xff
#define PORT_INPUT	0x00

//////////////////////////////////////////////////////////

#endif
