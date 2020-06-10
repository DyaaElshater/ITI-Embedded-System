/*
 * GPIO_PRV.h
 *
 *  Created on: Oct 11, 2019
 *      Author: Dyaa Elshater
 */

#ifndef GPIO_PRV_H_
#define GPIO_PRV_H_


typedef struct
{
	u32 EVCR;
	u32 MAPR;
	u32	EXTICR1;
	u32	EXTICR2;
	u32	EXTICR3;
	u32	EXTICR4;
	u32	MAPR2;
}AFIO_REGISTER;

AFIO_REGISTER * AFIO = (AFIO_REGISTER*)(0x40010000);


	/*MAPR*/

#define MAPR_SWJ_CFG				24
#define MAPR_ADC2_EXTERNAL_INJECTED	19
#define MAPR_ADC2_EXTERNAL_REGULAR	20
#define MAPR_ADC1_EXTERNAL_REGULAR	18
#define MAPR_ADC1_EXTERNAL_INJECTED	17
#define MAPR_TIMER5_CH4				16
#define MAPR_OSC_POTD_01			15
#define MAPR_CAN					13
#define MAPR_TIM4					12
#define MAPR_TIM3					10
#define MAPR_TIM2					8
#define MAPR_TIM1					6
#define MAPR_USARt3					4
#define MAPR_USARt2					3
#define MAPR_USARt1					2
#define MAPR_I2C1					1
#define MAPR_SPI1					0

/*EXTICR1*/
#define EXTI0		0
#define EXTI1		4
#define EXTI2		8
#define EXTI3		12

/*EXTICR2*/
#define EXTI4		0
#define EXTI5		4
#define EXTI6		8
#define EXTI7		12

/*EXTICR3*/
#define EXTI8		0
#define EXTI9		4
#define EXTI10		8
#define EXTI11		12

/*EXTICR4*/
#define EXTI12		0
#define EXTI13		4
#define EXTI14		8
#define EXTI15		12

/*MAPR2*/
#define FSMC_NADV	10
#define TIM14_REMAP	9
#define TIM13_REMAP	8
#define TIM11_REMAP	7
#define TIM10_REMAP	6
#define TIM9_REMAP	5

#define LEAST_PIN	0
#define LAST_PIN	15




#endif /* GPIO_PRV_H_ */
