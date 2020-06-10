/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 25/12/2019					*/
/* Description	: GPIO Interface File			*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#ifndef GPIO_INT_H_
#define GPIO_INT_H_


#define GPIO_INPUT    1
#define GPIO_OUTPUT   0

#define GPIO_HIGH     1
#define GPIO_LOW      0

#define GPIO_PORT_HIGH     0XFF
#define GPIO_PORT_LOW      0X00

/* Ports and Bits */
typedef struct
{
	u32 MODER;
	u32 OTYPER;
	u32	OSPEEDR;
	u32	PUPDR;
	u32	IDR;
	u32	ODR;
	u32	BSRR;
	u32	LCKR;
	u32	AFRL;
	u32	AFRH;

}GPIO_Register;
//typedef GPIO_Register * stGPIO ;

volatile static GPIO_Register * const GPIOA = (volatile GPIO_Register*)(0x40020000);
volatile static GPIO_Register * const GPIOB = (volatile GPIO_Register*)(0x40020400);
volatile static GPIO_Register * const GPIOC = (volatile GPIO_Register*)(0x40020800);
volatile static GPIO_Register * const GPIOD = (volatile GPIO_Register*)(0x40020C00);
volatile static GPIO_Register * const GPIOE = (volatile GPIO_Register*)(0x40021000);
volatile static GPIO_Register * const GPIOF = (volatile GPIO_Register*)(0x40021400);
volatile static GPIO_Register * const GPIOG = (volatile GPIO_Register*)(0x40021800);
volatile static GPIO_Register * const GPIOH = (volatile GPIO_Register*)(0x40021C00);
volatile static GPIO_Register * const GPIOI = (volatile GPIO_Register*)(0x40022000);
volatile static GPIO_Register * const GPIOJ = (volatile GPIO_Register*)(0x40022400);

        /*Port A*/
#define GPIO_RA0       0
#define GPIO_RA1       1
#define GPIO_RA2       2
#define GPIO_RA3       3
#define GPIO_RA4       4
#define GPIO_RA5       5
#define GPIO_RA6       6
#define GPIO_RA7       7
#define GPIO_RA8		8
#define GPIO_RA9		9
#define GPIO_RA10		10
#define GPIO_RA11		11
#define GPIO_RA12		12
#define GPIO_RA13		13
#define GPIO_RA14		14
#define GPIO_RA15		15

          /*Port B*/
#define GPIO_RB0  0
#define GPIO_RB1  1
#define GPIO_RB2  2
#define GPIO_RB3  3
#define GPIO_RB4  4
#define GPIO_RB5  5
#define GPIO_RB6  6
#define GPIO_RB7  7
#define GPIO_RB8	8
#define GPIO_RB9	9
#define GPIO_RB10	10
#define GPIO_RB11	11
#define GPIO_RB12	12
#define GPIO_RB13	13
#define GPIO_RB14	14
#define GPIO_RB15	15

          /*Port C*/
#define GPIO_RC0  0
#define GPIO_RC1  1
#define GPIO_RC2  2
#define GPIO_RC3  3
#define GPIO_RC4  4
#define GPIO_RC5  5
#define GPIO_RC6  6
#define GPIO_RC7  7  `
#define GPIO_RC8	8
#define GPIO_RC9	9
#define GPIO_RC10	10
#define GPIO_RC11	11
#define GPIO_RC12	12
#define GPIO_RC13	13
#define GPIO_RC14	14
#define GPIO_RC15	15

        /*Port D*/
#define GPIO_RD0   0
#define GPIO_RD1   1
#define GPIO_RD2   2
#define GPIO_RD3   3
#define GPIO_RD4   4
#define GPIO_RD5   5
#define GPIO_RD6   6
#define GPIO_RD7   7
#define GPIO_RD8	8
#define GPIO_RD9	9
#define GPIO_RD10	10
#define GPIO_RD11	11
#define GPIO_RD12	12
#define GPIO_RD13	13
#define GPIO_RD14	14
#define GPIO_RD15	15

        /*Port E*/
#define GPIO_RE0   0
#define GPIO_RE1   1
#define GPIO_RE2   2
#define GPIO_RE3   3
#define GPIO_RE4   4
#define GPIO_RE5   5
#define GPIO_RE6   6
#define GPIO_RE7   7
#define GPIO_RE8	8
#define GPIO_RE9	9
#define GPIO_RE10	10
#define GPIO_RE11	11
#define GPIO_RE12	12
#define GPIO_RE13	13
#define GPIO_RE14	14
#define GPIO_RE15	15

		/*Port F*/
#define GPIO_RF0	0
#define GPIO_RF1	1
#define GPIO_RF2	2
#define GPIO_RF3	3
#define GPIO_RF4	4
#define GPIO_RF5	5
#define GPIO_RF6	6
#define GPIO_RF7	7
#define GPIO_RF8	8
#define GPIO_RF9	9
#define GPIO_RF10	10
#define GPIO_RF11	11
#define GPIO_RF12	12
#define GPIO_RF13	13
#define GPIO_RF14	14
#define GPIO_RF15	15

		/*Port G*/
#define GPIO_RG0	0
#define GPIO_RG1	1
#define GPIO_RG2	2
#define GPIO_RG3	3
#define GPIO_RG4	4
#define GPIO_RG5	5
#define GPIO_RG6	6
#define GPIO_RG7	7
#define GPIO_RG8	8
#define GPIO_RG9	9
#define GPIO_RG10	10
#define GPIO_RG11	11
#define GPIO_RG12	12
#define GPIO_RG13	13
#define GPIO_RG14	14
#define GPIO_RG15	15

		/*Port H*/
#define GPIO_RH0	0
#define GPIO_RH1	1
#define GPIO_RH2	2
#define GPIO_RH3	3
#define GPIO_RH4	4
#define GPIO_RH5	5
#define GPIO_RH6	6
#define GPIO_RH7	7
#define GPIO_RH8	8
#define GPIO_RH9	9
#define GPIO_RH10	10
#define GPIO_RH11	11
#define GPIO_RH12	12
#define GPIO_RH13	13
#define GPIO_RH14	14
#define GPIO_RH15	15

		/*Port I*/
#define GPIO_RI0	0
#define GPIO_RI1	1
#define GPIO_RI2	2
#define GPIO_RI3	3
#define GPIO_RI4	4
#define GPIO_RI5	5
#define GPIO_RI6	6
#define GPIO_RI7	7
#define GPIO_RI8	8
#define GPIO_RI9	9
#define GPIO_RI10	10
#define GPIO_RI11	11
#define GPIO_RI12	12
#define GPIO_RI13	13
#define GPIO_RI14	14
#define GPIO_RI15	15

		/*Port J*/
#define GPIO_RJ0	0
#define GPIO_RJ1	1
#define GPIO_RJ2	2
#define GPIO_RJ3	3
#define GPIO_RJ4	4
#define GPIO_RJ5	5
#define GPIO_RJ6	6
#define GPIO_RJ7	7
#define GPIO_RJ8	8
#define GPIO_RJ9	9
#define GPIO_RJ10	10
#define GPIO_RJ11	11
#define GPIO_RJ12	12
#define GPIO_RJ13	13
#define GPIO_RJ14	14
#define GPIO_RJ15	15


#define GPIO_INPUT_MODE				0
#define GPIO_OUTPUT_MODE			1
#define GPIO_ALTERNATE_FUNCTION		2
#define GPIO_ANALOG					3


#define GPIO_FLOATING				0
#define GPIO_PULL_UP				1
#define GPIO_PULL_DOWN				2

#define GPIO_PUSH_PULL				0
#define GPIO_OPED_DRAIN				1


void GPIO_vidInit(void);
void GPIO_vidSetPinDirection (GPIO_Register* stPortCpy , u8 u8PinCpy , u8 u8PinDirectionCpy);
void GPIO_vidSetPinValue (GPIO_Register* stPortCpy , u8 u8PinCpy , u8 u8ValueCpy );

/*Description : For Setting Port value and direction*/

void GPIO_vidSetPortDirection (GPIO_Register* stPortCpy , u8 u8DirectionCpy );
void GPIO_vidSetPortValue (GPIO_Register* stPortCpy , u16 u16ValueCpy );

/*Description : For getting value from pin or port      */

u16 GPIO_u16GetPinValue (GPIO_Register* stPortCpy , u8 u8PinCpy );
u16 GPIO_u16GetPortValue (GPIO_Register* stPortCpy);

/*Description : For Toggling pin or port      */

void GPIO_vidTogglePin(GPIO_Register* stPortCpy , u8 u8PinCpy );
void GPIO_vidTogglePort(GPIO_Register* stPortCpy);





#endif /* GPIO_INT_H_ */
