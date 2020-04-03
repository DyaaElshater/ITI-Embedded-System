/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        4/12/2019                  */
/** Description : DIO Interface File         */
/*********************************************/

#ifndef _DIO_INT_H_
#define _DIO_INT_H_


/* Description : DIO Interface Macros        */
#define DIO_INPUT    1
#define DIO_OUTPUT   0

#define DIO_HIGH     1
#define DIO_LOW      0

#define DIO_PORT_HIGH     0XFF
#define DIO_PORT_LOW      0X00

/* Ports and Bits */
#define DIO_PORTA     (0XF80)
#define DIO_PORTB     (0XF81)
#define DIO_PORTC     (0XF82)
#define DIO_PORTD     (0XF83)
#define DIO_PORTE     (0XF84)

        /*Port A*/
#define DIO_RA0       0
#define DIO_RA1       1
#define DIO_RA2       2
#define DIO_RA3       3
#define DIO_RA4       4
#define DIO_RA5       5
#define DIO_RA6       6
#define DIO_RA7       7

          /*Port B*/
#define DIO_RB0  0
#define DIO_RB1  1
#define DIO_RB2  2
#define DIO_RB3  3
#define DIO_RB4  4
#define DIO_RB5  5
#define DIO_RB6  6
#define DIO_RB7  7

          /*Port C*/
#define DIO_RC0  0
#define DIO_RC1  1
#define DIO_RC2  2
#define DIO_RC3  3
#define DIO_RC4  4
#define DIO_RC5  5
#define DIO_RC6  6
#define DIO_RC7  7  `

        /*Port D*/
#define DIO_RD0   0
#define DIO_RD1   1
#define DIO_RD2   2
#define DIO_RD3   3
#define DIO_RD4   4
#define DIO_RD5   5
#define DIO_RD6   6
#define DIO_RD7   7

        /*Port E*/
#define DIO_RE0   0
#define DIO_RE1   1
#define DIO_RE2   2
#define DIO_RE3   3
#define DIO_RE4   4
#define DIO_RE5   5
#define DIO_RE6   6
#define DIO_RE7   7

/*Description : For initialization of IO Direction*/
void DIO_vidInit(void);

/*Description : For Setting pin value and direction*/

void DIO_vidSetPinDirection (u32 u32PortCpy , u8 u8PinCpy , u8 u8PinDirectionCpy);

void DIO_vidSetPinValue (u32 u32PortCpy , u8 u8PinCpy , u8 u8ValueCpy );

/*Description : For Setting Port value and direction*/

void DIO_vidSetPortDirection (u32 u32PortCpy , u8 u8DirectionCpy );

void DIO_vidSetPortValue (u32 u32PortCpy , u8 u8ValueCpy );

/*Description : For getting value from pin or port      */

u8 DIO_u8GetPinValue (u32 u32PortCpy , u8 u8PinCpy );

u8 DIO_u8GetPortValue (u32 u32PortCpy);

/*Description : For Toggling pin or port      */
void DIO_vidTogglePin(u32 u32PortCpy , u8 u8PinCpy );

void DIO_vidTogglePort(u32 u32PortCpy);

#endif