
/****************************************************/
/** Author		:	Dyaa Elshater					*/
/** Date		:	25/7/2019						*/
/** Descrption	: Private file to DIO				*/
/** Version		: 2.0V								*/
/****************************************************/


#ifndef DIO_PRIV_H_
#define DIO_PRIV_H_
/*
#define DIO_u8OUTPUT	1
#define DIO_u8INPUT		0
*/

/****************************************************/
/**Port A addresses									*/
#define PORTA	*((volatile u8 *) 0x3B )
#define DDRA	*((volatile u8 *) 0x3A )
#define PINA	*((volatile u8 *) 0x39 )

/**Port B addresses									*/
#define PORTB	*((volatile u8 *) 0x38 )
#define DDRB	*((volatile u8 *) 0x37 )
#define PINB	*((volatile u8 *) 0x36 )

/**Port C addresses									*/
#define PORTC	*((volatile u8 *) 0x35 )
#define DDRC	*((volatile u8 *) 0x34 )
#define PINC	*((volatile u8 *) 0x33 )

/**Port D addresses									*/
#define PORTD	*((volatile u8 *) 0x32 )
#define DDRD	*((volatile u8 *) 0x31 )
#define PIND	*((volatile u8 *) 0x30 )


/****************************************************/

#define DIO_u8_PORT_SIZE	8
/****************************************************/
/** Descrption	:	Information About PORT A		*/
/****************************************************/
#define DIO_u8_PORTA_START	0
#define DIO_u8_PORTA_SIZE	8
#define DIO_u8_PORTA_STOP	7

/****************************************************/
/** Descrption	:	Information About PORT B		*/
/****************************************************/
#define DIO_u8_PORTB_START	8
#define DIO_u8_PORTB_SIZE	8
#define DIO_u8_PORTB_STOP	15

/****************************************************/
/** Descrption	:	Information About PORT C		*/
/****************************************************/
#define DIO_u8_PORTC_START	16
#define DIO_u8_PORTC_SIZE	8
#define DIO_u8_PORTC_STOP	23

/****************************************************/
/** Descrption	:	Information About PORT D		*/
/****************************************************/
#define DIO_u8_PORTD_START	24
#define DIO_u8_PORTD_SIZE	8
#define DIO_u8_PORTD_STOP	31

/****************************************************/

/** Descrption : New Virsual PORT Structure			*/

static u8	DIO_arrPortX[8]=
{
		PORTX_PIN_0,
		PORTX_PIN_1,
		PORTX_PIN_2,
		PORTX_PIN_3,
		PORTX_PIN_4,
		PORTX_PIN_5,
		PORTX_PIN_6,
		PORTX_PIN_7
} ;
static u8 DIO_arrPortY[8]=
{
		PORTY_PIN_0,
		PORTY_PIN_1,
		PORTY_PIN_2,
		PORTY_PIN_3,
		PORTY_PIN_4,
		PORTY_PIN_5,
		PORTY_PIN_6,
		PORTY_PIN_7
};
static u8 DIO_arrPortZ[8]=
{
	PORTZ_PIN_0,
	PORTZ_PIN_1,
	PORTZ_PIN_2,
	PORTZ_PIN_3,
	PORTZ_PIN_4,
	PORTZ_PIN_5,
	PORTZ_PIN_6,
	PORTZ_PIN_7
};


#endif
