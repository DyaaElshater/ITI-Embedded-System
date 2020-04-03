/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        4/12/2019                  */
/** Description : DIO Configuration File         */
/*********************************************/

#ifndef _DIO_PRIV_H_
#define _DIO_PRIV_H_


/* Registers Addresses  */

#define DIO_PORTA_VALUE (*(volatile u8*)(0XF80))
#define DIO_PORTB_VALUE (*(volatile u8*)(0XF81))
#define DIO_PORTC_VALUE (*(volatile u8*)(0XF82))
#define DIO_PORTD_VALUE (*(volatile u8*)(0XF83))
#define DIO_PORTE_VALUE (*(volatile u8*)(0XF84))

#define DIO_LATA              (*(volatile u8*)(0XF89))
#define DIO_LATB              (*(volatile u8*)(0XF8A))
#define DIO_LATC              (*(volatile u8*)(0XF8B))
#define DIO_LATD              (*(volatile u8*)(0XF8C))
#define DIO_LATE              (*(volatile u8*)(0XF8D))

#define DIO_TRISA             (*(volatile u8*)(0XF92))
#define DIO_TRISB             (*(volatile u8*)(0XF93))
#define DIO_TRISC             (*(volatile u8*)(0XF94))
#define DIO_TRISD             (*(volatile u8*)(0XF95))
#define DIO_TRISE             (*(volatile u8*)(0XF96))


        /* PRIVATE NUMBERS    */
#define DIO_PORT2TRIS         (0x12)
#define DIO_PORT2LAT          (0x9)


#endif