/*
 * GPIO_INT.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Dyaa Elshater
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_

typedef enum
{
	Disable,
	Enable
}tdefGPIO_AFIO_EN;

/*************************************/
		/*Port A*/
#define GPIO_u8RA_0		0
#define GPIO_u8RA_1		1
#define GPIO_u8RA_2		2
#define GPIO_u8RA_3		3
#define GPIO_u8RA_4		4
#define GPIO_u8RA_5		5
#define GPIO_u8RA_6		6
#define GPIO_u8RA_7		7
#define GPIO_u8RA_8		8
#define GPIO_u8RA_9		9
#define GPIO_u8RA_10	10
#define GPIO_u8RA_11	11
#define GPIO_u8RA_12	12
#define GPIO_u8RA_13	13
#define GPIO_u8RA_14	14
#define GPIO_u8RA_15	15
		/*Port B*/
#define GPIO_u8RB_0		0
#define GPIO_u8RB_1		1
#define GPIO_u8RB_2		2
#define GPIO_u8RB_3		3
#define GPIO_u8RB_4		4
#define GPIO_u8RB_5		5
#define GPIO_u8RB_6		6
#define GPIO_u8RB_7		7
#define GPIO_u8RB_8		8
#define GPIO_u8RB_9		9
#define GPIO_u8RB_10	10
#define GPIO_u8RB_11	11
#define GPIO_u8RB_12	12
#define GPIO_u8RB_13	13
#define GPIO_u8RB_14	14
#define GPIO_u8RB_15	15
		/*Port C*/
#define GPIO_u8RC_0		0
#define GPIO_u8RC_1		1
#define GPIO_u8RC_2		2
#define GPIO_u8RC_3		3
#define GPIO_u8RC_4		4
#define GPIO_u8RC_5		5
#define GPIO_u8RC_6		6
#define GPIO_u8RC_7		7
#define GPIO_u8RC_8		8
#define GPIO_u8RC_9		9
#define GPIO_u8RC_10	10
#define GPIO_u8RC_11	11
#define GPIO_u8RC_12	12
#define GPIO_u8RC_13	13
#define GPIO_u8RC_14	14
#define GPIO_u8RC_15	15
		/*Port D*/
#define GPIO_u8RD_0		0
#define GPIO_u8RD_1		1
#define GPIO_u8RD_2		2
#define GPIO_u8RD_3		3
#define GPIO_u8RD_4		4
#define GPIO_u8RD_5		5
#define GPIO_u8RD_6		6
#define GPIO_u8RD_7		7
#define GPIO_u8RD_8		8
#define GPIO_u8RD_9		9
#define GPIO_u8RD_10	10
#define GPIO_u8RD_11	11
#define GPIO_u8RD_12	12
#define GPIO_u8RD_13	13
#define GPIO_u8RD_14	14
#define GPIO_u8RD_15	15
		/*Port E*/
#define GPIO_u8RE_0		0
#define GPIO_u8RE_1		1
#define GPIO_u8RE_2		2
#define GPIO_u8RE_3		3
#define GPIO_u8RE_4		4
#define GPIO_u8RE_5		5
#define GPIO_u8RE_6		6
#define GPIO_u8RE_7		7
#define GPIO_u8RE_8		8
#define GPIO_u8RE_9		9
#define GPIO_u8RE_10	10
#define GPIO_u8RE_11	11
#define GPIO_u8RE_12	12
#define GPIO_u8RE_13	13
#define GPIO_u8RE_14	14
#define GPIO_u8RE_15	15
		/*Port F*/
#define GPIO_u8RF_0		0
#define GPIO_u8RF_1		1
#define GPIO_u8RF_2		2
#define GPIO_u8RF_3		3
#define GPIO_u8RF_4		4
#define GPIO_u8RF_5		5
#define GPIO_u8RF_6		6
#define GPIO_u8RF_7		7
#define GPIO_u8RF_8		8
#define GPIO_u8RF_9		9
#define GPIO_u8RF_10	10
#define GPIO_u8RF_11	11
#define GPIO_u8RF_12	12
#define GPIO_u8RF_13	13
#define GPIO_u8RF_14	14
#define GPIO_u8RF_15	15
		/*Port G*/
#define GPIO_u8RG_0		0
#define GPIO_u8RG_1		1
#define GPIO_u8RG_2		2
#define GPIO_u8RG_3		3
#define GPIO_u8RG_4		4
#define GPIO_u8RG_5		5
#define GPIO_u8RG_6		6
#define GPIO_u8RG_7		7
#define GPIO_u8RG_8		8
#define GPIO_u8RG_9		9
#define GPIO_u8RG_10	10
#define GPIO_u8RG_11	11
#define GPIO_u8RG_12	12
#define GPIO_u8RG_13	13
#define GPIO_u8RG_14	14
#define GPIO_u8RG_15	15

/*************************************/

#define GPIO_u8OUTPUT					1
#define GPIO_u8OUTPUT_OPEN_DRAIN		3
#define GPIO_u8OUTPUT_AFO				5
#define GPIO_u8OUTPUT_AFO_OPEN_DRAIN	7
#define GPIO_u8INPUT					0
#define GPIO_u8INPUT_PUL_UP				2
#define GPIO_u8INPUT_FLOATING			4

#define GPIO_u8OUTPUT	1
#define GPIO_u8INPUT	0

#define GPIO_INPUT_ANALOG				0000
#define GPIO_INPUT_FLOATING				0100
#define GPIO_INPUT_PULL_UP_DOWN			1000

#define GPIO_OUTPUT_PUSH_PULL_10MHZ		0001
#define GPIO_OUTPUT_OPEN_DRAIN_10MHZ	0101
#define GPIO_AF_PUSH_PULL_10MHZ			1001
#define GPIO_AF_OPEN_DRAIN_10MHZ		1101

#define GPIO_OUTPUT_PUSH_PULL_2MHZ		0010
#define GPIO_OUTPUT_OPEN_DRAIN_2MHZ		0110
#define GPIO_AF_PUSH_PULL_2MHZ			1010
#define GPIO_AF_OPEN_DRAIN_2MHZ			1110

#define GPIO_OUTPUT_PUSH_PULL_50MHZ		0011
#define GPIO_OUTPUT_OPEN_DRAIN_50MHZ	0111
#define GPIO_AF_PUSH_PULL_50MHZ			1011
#define GPIO_AF_OPEN_DRAIN_50MHZ		1111

#define GPIO_PULL_UP					1
#define GPIO_PULL_DOWN					0

#define GPIO_u8HIGH		1
#define GPIO_u8LOW		0




typedef struct
{
	u32 CRL;
	u32 CRH;
	u32 IDR;
	u32 ODR;
	u32 BSRR;
	u32 BRR;
	u32 LCKR;
}GPIO_Register;


/*
static  GPIO_Register * const GPIOA = (volatile GPIO_Register*)(0x40010800);
static  GPIO_Register * const GPIOB = (volatile GPIO_Register*)(0x40010C00);
static  GPIO_Register * const GPIOC = (volatile GPIO_Register*)(0x40011000);
static  GPIO_Register * const GPIOD = (volatile GPIO_Register*)(0x40011400);
static  GPIO_Register * const GPIOE = (volatile GPIO_Register*)(0x40011800);
static  GPIO_Register * const GPIOF = (volatile GPIO_Register*)(0x40011C00);
static  GPIO_Register * const GPIOG = (volatile GPIO_Register*)(0x40012000);
*/
#define GPIOA 	((GPIO_Register*)(0x40010800))
#define GPIOB 	((GPIO_Register*)(0x40010C00))
#define GPIOC	((GPIO_Register*)(0x40011000))
#define GPIOD 	((GPIO_Register*)(0x40011400))
#define GPIOE 	((GPIO_Register*)(0x40011800))
#define GPIOF 	((GPIO_Register*)(0x40011C00))
#define GPIOG 	((GPIO_Register*)(0x40012000))



/****************************************/

		/*Alternate Function*/
#define JTAG_ENABLE_SW_ENABLE_RESET_STATE	0
#define JTAG_ENABLE_SW_ENABLE_WITHOUT_RESET	1
#define JTAG_DISABLE_SW_ENABEL				2
#define JTAG_DISABLE_SW_DISABLE				4

#define ADC2_REGULAR_CONNECTED_TO_EXTI11	0
#define ADC2_REGULAR_CONNECTED_TO_TIM8_TRIGo	1

#define ADC2_INJECTED_CONNECTED_TO_EXTI15	0
#define ADC2_INJECTED_CONNECTED_TO_TIM8_TRICH4	1

#define ADC1_REGULAR_CONNECTED_TO_EXTI11	0
#define ADC1_REGULAR_CONNECTED_TO_TIM8_TRIGo	1

#define ADC1_INJECTED_CONNECTED_TO_EXTI15	0
#define ADC1_INJECTED_CONNECTED_TO_TIM8_TRICH4	1

#define TIM5_CH4_TO_PA3						0
#define TIM5_CH4_TO_LSI						1

#define AFIO_ENABLE							1
#define AFIO_DISABLE						0

#define CAN_MAPPED_TO_PA11_PA12				0
#define CAN_MAPPED_TO_PB8_PB9				2
#define CAN_MAPPED_TO_PD0_PD1				3

#define TIMER4_CH1_PB6_CH2_PB7_CH3_PB8_CH4_PB9			0
#define TIMER4_CH1_PD12_CH2_PD13_CH3_PD14_CH4_PD15		1

#define TIMER3_CH1_PA6_CH2_PA7_CH3_PB0_CH4_PB1			0
#define TIMER3_CH1_PB4_CH2_PB5_CH3_PB0_CH4_PB1			2
#define TIMER3_CH1_PC6_CH2_PC7_CH3_PC8_CH4_PC9			3

#define TIMER2_CH1_ETR_PA0_CH2_PA1_CH3_PA2_CH4_PA3		0
#define TIMER2_CH1_ETR_PA15_CH2_PB3_CH3_PA2_CH4_PA3		1
#define TIMER2_CH1_ETR_PA0_CH2_PA1_CH3_PB10_CH4_PB11	2
#define TIMER2_CH1_ETR_PA15_CH2_PB3_CH3_PB10_CH4_PB11	3

#define TIMER1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PB12_CH1N_PB13_CH2N_PB14_CH3N_PB15	0
#define TIMER1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PA6_CH1N_PA7_CH2N_PB0_CH3N_PB1		1
#define TIMER1_ETR_PE7_CH1_PE9_CH2_PE11_CH3_PE13_CH4_PE14_BKIN_PE15_CH1N_PE8_CH2N_PE10_CH3N_PE12	3

#define USART3_TX_PB10_RX_PB11_CK_PB12_CTS_PB13_RTS_PB14	0
#define USART3_TX_PC10_RX_PC11_CK_PC12_CTS_PB13_RTS_PB14	1
#define USART3_TX_PD8_RX_PD9_CK_PD10_CTS_PD11_RTS_PD12		3

#define USART2_CTS_PA0_RTS_PA1_TX_PA2_RX_PA3_CK_PA4			0
#define USART2_CTS_PD3_RTS_PD4_TX_PD5_RX_PD6_CK_PD7			1

#define USART1_TX_PA9_RX_PA10		0
#define USART1_TX_PB6_RX_PB7		1

#define I2C1_SCL_PB6_SDA_PB7		0
#define I2C1_SCL__B8_SDA_PB9		1

#define SPI1_NSS_PA4_SCK_PA5_MISO_PA6_MOSI_PA7	0
#define SPI1_NSS_PA15_SCK_PB3_MISO_PB4_MOSI_PB5	1

#define EXTI_PA			0
#define EXTI_PB			1
#define EXTI_PC			2
#define EXTI_PD			3
#define EXTI_PE			4
#define EXTI_PF			5
#define EXTI_PG			6

#define TIMER14_CH1_to_PA7	0
#define TIMER14_CH1_to_PF9	1

#define TIMER13_CH1_to_PA6	0
#define TIMER13_CH1_to_PF8	1

#define TIMER11_CH1_to_PB9	0
#define TIMER11_CH1_to_PF7	1

#define TIMER10_CH1_to_PB8	0
#define TIMER10_CH1_to_PF6	1

#define TIMER9_CH1_PA2_CH2_PA9	0
#define TIMER9_CH1_PE5_CH2_PE6	1

/****************************************************/
/** Descrption	: intialization function to GPIO and*/
/* determine the dirction of all pins				*/
/****************************************************/

void GPIO_vidInit(void);
/****************************************************/
/** Descrption	: Finction used to set pin in		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins foom 0 to 31	*/
/*			 u8ValueCpy value mean GPIO_u8HIGH 		*/
/*							or GPIO_u8LOW			*/
/****************************************************/

void GPIO_vidSetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy ,u8 u8ValueCpy);

/****************************************************/
/** Descrption	: Finction used to get pin from		*/
/* microcontroller to be high or low   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : it return the pin Value 				*/
/****************************************************/

void GPIO_vidGetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy,u8*pu8PinValueCpy);

/****************************************************/
/** Descrption	: Finction used to set the pin 		*/
/* direction .						   		 	    */
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidSetPinDirection(GPIO_Register* pstPortCpy ,u8 u8pinNbCpy, u8 u8PinStateCpy);

/****************************************************/
/** Descrption	: Finction used to toggle the pin .	*/
/** Inputs : u8PinNbCpy number of pins from 0 to 31	*/
/** Output : Error Status 							*/
/****************************************************/

void GPIO_vidTogglePin (GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);

/****************************************************/
/** Descrption	: Finction used to make pull up .	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullUp(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);

/****************************************************/
/** Descrption	: Finction used to make pull Down.	*/
/** Inputs : u8PinNbCpy pin number from 0 to 31		*/
/** Output : Error Status  							*/
/****************************************************/

void GPIO_vidPullDown(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);


/****************************************************/
/** Descrption:Function used to get pin value		*/
/** Inputs : pu8ValueCpy pointer to input value 	*/
/** Output : Error Status  							*/
/****************************************************/
u8 GPIO_u8GetPinValue(GPIO_Register* pstPortCpy ,u8 u8PinNbCpy);

/******************** Alternate Function ************/
typedef enum {
	Full_SWJ_ResetState,
	Full_SWJ_WithoutNJTRST,
	JtagDisable_SwEnable,
	JtagDisable_SwDisable
}tdefJtagSw;
void AFIO_vidSetSwJtagRemapping(tdefJtagSw enuJtagSwCpy);

typedef enum
{
	REGULAR_CONNECTED_TO_EXTI11,
	REGULAR_CONNECTED_TO_TIM8_TRIGo
}tdefADCRegulator;
void AFIO_vidSetADC2Regulator (tdefADCRegulator enuAdcRegulatorCpy);
void AFIO_vidSetADC1Regulator (tdefADCRegulator enuAdcRegulatorCpy);

typedef enum
{
	INJECTED_CONNECTED_TO_EXTI15,
	INJECTED_CONNECTED_TO_TIM8_TRICH4
}tdefADCInjected;
void AFIO_vidSetADC2Injected(tdefADCInjected enuADCInjectedCpy);
void AFIO_vidSetADC1Injected(tdefADCInjected enuADCInjectedCpy);

typedef enum
{
	TIM5_CH4_PA3,
	TIM5_CH4_LSI
}tdefTim5Ch4;
void AFIO_vidSetTIM5CH4Remapping(tdefTim5Ch4 enuTim5Cpy);

typedef enum
{
	NoOscRemapping,
	PD0PD1OscRemapping
}tdefOsc;
void AFIO_vidSetOscRemapping(tdefOsc enuOscCpy);

typedef enum
{
	RX_PA11_TX_PA12,
	RX_PB8_TX_PB9 = 2,
	RX_PD0_TX_PD1 =3
}tdefCan;
void AFIO_vidSetCanRemapping(tdefCan enuCanCpy);

typedef enum
{
	TIM4_CH1_PB6_CH2_PB7_CH3_PB8_CH4_PB9	,
	TIM4_CH1_PD12_CH2_PD13_CH3_PD14_CH4_PD15
}tdefTimer4;
void AFIO_vidSetTimer4Remapping(tdefTimer4 enuTimer4);

typedef enum
{
	TIM3_CH1_PA6_CH2_PA7_CH3_PB0_CH4_PB1=0	,
	TIM3_CH1_PB4_CH2_PB5_CH3_PB0_CH4_PB1=2	,
	TIM3_CH1_PC6_CH2_PC7_CH3_PC8_CH4_PC9=3
}tdefTimer3;
void AFIO_vidSetTimer3Remapping(tdefTimer3 enuTimer3Cpy);

typedef enum
{
	TIM2_CH1_ETR_PA0_CH2_PA1_CH3_PA2_CH4_PA3	,
	TIM2_CH1_ETR_PA15_CH2_PB3_CH3_PA2_CH4_PA3	,
	TIM2_CH1_ETR_PA0_CH2_PA1_CH3_PB10_CH4_PB11	,
	TIM2_CH1_ETR_PA15_CH2_PB3_CH3_PB10_CH4_PB11
}tdefTimer2;
void AFIO_vidSetTimer2Remapping(tdefTimer2 enuTimer2Cpy);

typedef enum
{
	TIM1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PB12_CH1N_PB13_CH2N_PB14_CH3N_PB15=0	,
	TIM1_ETR_PA12_CH1_PA8_CH2_PA9_CH3_PA10_CH4_PA11_BKIN_PA6_CH1N_PA7_CH2N_PB0_CH3N_PB1	   =1	,
	TIM1_ETR_PE7_CH1_PE9_CH2_PE11_CH3_PE13_CH4_PE14_BKIN_PE15_CH1N_PE8_CH2N_PE10_CH3N_PE12	=3
}tdefTimer1;
void AFIO_vidSetTimer1Remapping(tdefTimer1 enuTimer1Cpy);

typedef enum
{
	TX_PB10_RX_PB11_CK_PB12_CTS_PB13_RTS_PB14 = 0	,
	TX_PC10_RX_PC11_CK_PC12_CTS_PB13_RTS_PB14 = 1	,
	TX_PD8_RX_PD9_CK_PD10_CTS_PD11_RTS_PD12	 = 3
}tdefUsart3;
void AFIO_vidSetUsart3Remapping(tdefUsart3 enuUsart3Cpy);

typedef enum
{
	CTS_PA0_RTS_PA1_TX_PA2_RX_PA3_CK_PA4	,
	CTS_PD3_RTS_PD4_TX_PD5_RX_PD6_CK_PD7
}tdefUsart2;
void AFIO_vidSetUsart2Remapping(tdefUsart2 enuUsart2Cpy);

typedef enum
{
	TX_PA9_RX_PA10	,
	TX_PB6_RX_PB7
}tdefUsart1;
void AFIO_vidSetUsart1Remapping(tdefUsart1 enuUsart1Cpy);

typedef enum
{
	SCL_PB6_SDA_PB7	,
	SCL__B8_SDA_PB9
}tdefI2c1;
void AFIO_vidSetI2C1Remapping(tdefI2c1 enuI2C1Cpy);

typedef enum
{
	NSS_PA4_SCK_PA5_MISO_PA6_MOSI_PA7	,
	NSS_PA15_SCK_PB3_MISO_PB4_MOSI_PB5
}tdefSPI1;
void AFIO_vidSetSpi1Remapping(tdefSPI1 enuSpi2Cpy);

typedef enum
{
	EXI_PA,
	EXI_PB,
	EXI_PC,
	EXI_PD,
	EXI_PE,
	EXI_PF,
	EXI_PG
}tdefEXTI;
void AFIO_vidSetEXTI0Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI1Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI2Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI3Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI4Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI5Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI6Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI7Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI8Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI9Remapping (tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI10Remapping(tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI11Remapping(tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI12Remapping(tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI13Remapping(tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI14Remapping(tdefEXTI enuExtiCpy);
void AFIO_vidSetEXTI15Remapping(tdefEXTI enuExtiCpy);

void ADIO_vidSetFSMC_NADVRemapping(tdefGPIO_AFIO_EN enuGpioAfioEnCpy);

typedef enum
{
	TIM14_CH1_to_PA7,
	TIM14_CH1_to_PF9
}tdefTimer14;
void AFIO_vidSetTimer14Remapping(tdefTimer14 enuTimer14Cpy);

typedef enum
{
	TIM13_CH1_to_PA6,
	TIM13_CH1_to_PF8
}tdefTimer13;
void AFIO_vidSetTimer13Remapping(tdefTimer13 enuTimer13Cpy);

typedef enum
{
	TIM11_CH1_to_PB9,
	TIM11_CH1_to_PF7
}tdefTimer11;
void AFIO_vidSetTimer11Remapping(tdefTimer11 enuTimer11Cpy);

typedef enum
{
	TIM10_CH1_to_PB8,
	TIM10_CH1_to_PF6
}tdefTimer10;
void AFIO_vidSetTimer10Remapping(tdefTimer10 enuTimer10Cpy);

typedef enum
{
	TIM9_CH1_PA2_CH2_PA9,
	TIM9_CH1_PE5_CH2_PE6
}tdefTimer9;
void AFIO_vidSetTimer9Remapping (tdefTimer9 enuTimer9Cpy);


#endif /* GPIO_INT_H_ */
