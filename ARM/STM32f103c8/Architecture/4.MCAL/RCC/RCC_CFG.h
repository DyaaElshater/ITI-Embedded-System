/*
* RCC_CFG.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Dyaa Elshater
 */

#ifndef RCC_CFG_H_
#define RCC_CFG_H_

/**	Configure the Systm type in start up using RCC_vidInit() finction	*/
/*		START_UP_SYSCLK  -> HSI_CLK										*/
/*						 -> HSE_CLK 									*/
#define START_UP_SYSCLK HSE_CLK

/** Configure each peripheral as Enabled or not		*/
/*						- RCC_ENABLE				*/
/*						- RCC_DISABLE				*/


			/*GPIO*/
#define RCC_GPIO_G				RCC_ENABLE
#define RCC_GPIO_F				RCC_ENABLE
#define	RCC_GPIO_E				RCC_ENABLE
#define	RCC_GPIO_D				RCC_ENABLE
#define	RCC_GPIO_C				RCC_ENABLE
#define	RCC_GPIO_B				RCC_ENABLE
#define	RCC_GPIO_A				RCC_ENABLE

			/*ALternate Function*/
#define RCC_AFIO				RCC_ENABLE

			/*Timers*/
#define RCC_TIMER14				RCC_DISABLE
#define RCC_TIMER13				RCC_DISABLE
#define RCC_TIMER12				RCC_DISABLE
#define RCC_TIMER11				RCC_DISABLE
#define RCC_TIMER10				RCC_DISABLE
#define RCC_TIMER9				RCC_DISABLE
#define RCC_TIMER8				RCC_DISABLE
#define RCC_TIMER7				RCC_DISABLE
#define RCC_TIMER6				RCC_DISABLE
#define RCC_TIMER5				RCC_DISABLE
#define RCC_TIMER4				RCC_DISABLE
#define RCC_TIMER3				RCC_DISABLE
#define RCC_TIMER2				RCC_DISABLE
#define	RCC_TIMER1				RCC_DISABLE

			/*ADC*/
#define RCC_ADC3				RCC_DISABLE
#define	RCC_ADC2				RCC_DISABLE
#define	RCC_ADC1				RCC_DISABLE

			/*DAC*/
#define RCC_DAC					RCC_DISABLE

		/*Communication Protocol*/
			/*UART/USART*/
#define RCC_UART5				RCC_DISABLE
#define RCC_UART4				RCC_DISABLE
#define RCC_USART3				RCC_DISABLE
#define RCC_USART2				RCC_DISABLE
#define RCC_USART1				RCC_DISABLE
			/*SPI*/
#define RCC_SPI3				RCC_DISABLE
#define RCC_SPI2				RCC_DISABLE
#define RCC_SPI1				RCC_DISABLE

			/*I2C*/
#define RCC_I2C2				RCC_DISABLE
#define RCC_I2C1				RCC_DISABLE

			/*CAN*/
#define RCC_CAN					RCC_DISABLE

			/*USB*/
#define RCC_USB					RCC_DISABLE

		/*DMA*/
#define RCC_DMA2				RCC_DISABLE
#define RCC_DMA1				RCC_DISABLE

		/*Others*/
#define RCC_SDIO				RCC_DISABLE
#define RCC_FSMC				RCC_DISABLE
#define RCC_CRC					RCC_DISABLE
#define RCC_FLITF				RCC_DISABLE
#define RCC_SRAM				RCC_DISABLE
#define RCC_POWER				RCC_DISABLE
#define RCC_BACK_UP				RCC_DISABLE
#define RCC_Window_watchdog		RCC_DISABLE


#endif /* RCC_CFG_H_ */
