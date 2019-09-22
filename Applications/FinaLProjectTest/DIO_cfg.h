
/****************************************************/
/** Author		:	Dyaa Elshater					*/
/** Date		:	25/7/2019						*/
/** Descrption	: Configuration of file to DIO		*/
/** Version		: 2.0V								*/
/****************************************************/


#ifndef DIO_CGF_H_
#define DIO_CGF_H_
/****************************************************/
/** Descrption	:	Input and Output decleration	*/
/****************************************************/
#define DIO_u8OUTPUT	1
#define DIO_u8INPUT		0
/****************************************************/
		/*Port A*/
#define DIO_u8PINDIR_0	DIO_u8OUTPUT	
#define DIO_u8PINDIR_1	DIO_u8OUTPUT
#define DIO_u8PINDIR_2	DIO_u8OUTPUT
#define DIO_u8PINDIR_3	DIO_u8OUTPUT
#define DIO_u8PINDIR_4	DIO_u8OUTPUT
#define DIO_u8PINDIR_5	DIO_u8OUTPUT
#define DIO_u8PINDIR_6	DIO_u8OUTPUT
#define DIO_u8PINDIR_7	DIO_u8OUTPUT
		/*Port B*/
#define DIO_u8PINDIR_8	DIO_u8INPUT
#define DIO_u8PINDIR_9	DIO_u8INPUT
#define DIO_u8PINDIR_10	DIO_u8INPUT
#define DIO_u8PINDIR_11	DIO_u8INPUT
#define DIO_u8PINDIR_12	DIO_u8INPUT	
#define DIO_u8PINDIR_13	DIO_u8INPUT
#define DIO_u8PINDIR_14	DIO_u8INPUT
#define DIO_u8PINDIR_15	DIO_u8INPUT
		/*Port C*/
#define DIO_u8PINDIR_16	DIO_u8OUTPUT
#define DIO_u8PINDIR_17	DIO_u8OUTPUT
#define DIO_u8PINDIR_18	DIO_u8OUTPUT
#define DIO_u8PINDIR_19	DIO_u8OUTPUT
#define DIO_u8PINDIR_20	DIO_u8OUTPUT
#define DIO_u8PINDIR_21	DIO_u8OUTPUT
#define DIO_u8PINDIR_22	DIO_u8OUTPUT
#define DIO_u8PINDIR_23	DIO_u8OUTPUT
		/*Port D*/
#define DIO_u8PINDIR_24	DIO_u8INPUT
#define DIO_u8PINDIR_25	DIO_u8INPUT
#define DIO_u8PINDIR_26	DIO_u8INPUT
#define DIO_u8PINDIR_27	DIO_u8INPUT
#define DIO_u8PINDIR_28	DIO_u8INPUT
#define DIO_u8PINDIR_29	DIO_u8INPUT
#define DIO_u8PINDIR_30	DIO_u8INPUT
#define DIO_u8PINDIR_31	DIO_u8INPUT
#define DIO_u8PINDIR_32	DIO_u8INPUT

/**Descrption	:	New Virsual PORT 		*/

/**Descrption	:	New Virsual PORTX 		*/
#define PORTX_PIN_0	DIO_u8PIN_0
#define PORTX_PIN_1	DIO_u8PIN_1
#define PORTX_PIN_2	DIO_u8PIN_2
#define PORTX_PIN_3	DIO_u8PIN_3
#define PORTX_PIN_4	DIO_u8PIN_4
#define PORTX_PIN_5	DIO_u8PIN_5
#define PORTX_PIN_6	DIO_u8PIN_6
#define PORTX_PIN_7	DIO_u8PIN_7


/**Descrption	:	New Virsual PORTY 		*/
#define PORTY_PIN_0	DIO_u8PIN_0
#define PORTY_PIN_1	DIO_u8PIN_7
#define PORTY_PIN_2	DIO_u8PIN_3
#define PORTY_PIN_3	DIO_u8PIN_18
#define PORTY_PIN_4	DIO_u8PIN_20
#define PORTY_PIN_5	DIO_u8PIN_17
#define PORTY_PIN_6	DIO_u8PIN_19
#define PORTY_PIN_7	DIO_u8PIN_30


/**Descrption	:	New Virsual PORTX 		*/
#define PORTZ_PIN_0	DIO_u8PIN_10
#define PORTZ_PIN_1	DIO_u8PIN_11
#define PORTZ_PIN_2	DIO_u8PIN_12
#define PORTZ_PIN_3	DIO_u8PIN_13
#define PORTZ_PIN_4	DIO_u8PIN_14
#define PORTZ_PIN_5	DIO_u8PIN_15
#define PORTZ_PIN_6	DIO_u8PIN_16
#define PORTZ_PIN_7	DIO_u8PIN_17

#endif
