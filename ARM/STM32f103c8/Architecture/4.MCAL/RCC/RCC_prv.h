/*
 * RCC_prv.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Dyaa Elshater
 */

#ifndef RCC_PRV_H_
#define RCC_PRV_H_

typedef struct
{
  u32	CR;
  u32	CFGR;
  u32	CIR;
  u32	APB2RSTR;
  u32	APB1RSTR;
  u32	AHBENR;
  u32	APB2ENR;
  u32	APB1ENR;
  u32	BDCR;
  u32	CSR;
}RCC_REG;

static volatile RCC_REG * const RCC = (volatile RCC_REG*)0x40021000 ;



	/*	BITs*/

	/*CR*/
#define HSION	0
#define HSIRDY	1
#define HSEON	16
#define HSERDY	17
#define HSEBYP	18
#define CSSON	19
#define PLLON	24
#define PLLRDY	25

	/*CFGR*/
#define SW_HSI 0
#define SW_HSE 1
#define SW_PLL 2

#define USBPRE		22
#define PLLXTPRE	17
#define PLLSRC		16

	/*APB2RSTR*/
#define TIM11RST	21
#define TIM10RST	20
#define TIM9RST		19
#define ADC3RST		15
#define USART1RST	14
#define TIM8RST		13
#define SPI1RST		12
#define	TIM1RST		11
#define	ADC2RST		10
#define	ADC1RST		9
#define IOPGRST		8
#define IOPFRST		7
#define	IOPERST		6
#define	IOPDRST		5
#define	IOPCRST		4
#define	IOPBRST		3
#define	IOPARST		2
#define AFIORST		0

	/*APB1RSTR*/
#define DACRST	29
#define PWRRST	28
#define BKPRST	27
#define CANRST	25
#define USBRST	23
#define I2C2RST	22
#define I2C1RST	21
#define UART5RST	20
#define UART4RST	19
#define USART3RST	18
#define USART2RST	17
#define SPI3RST	15
#define SPI2RST	14
#define WWDGRST	11
#define TIM14RST	8
#define TIM13RST	7
#define TIM12RST	6
#define TIM7RST	5
#define TIM6RST	4
#define TIM5RST	3
#define TIM4RST	2
#define TIM3RST	1
#define TIM2RST	0

	/*AHBENR*/
#define SDIOEN		10
#define FSMCEN		8
#define CRCEN		6
#define FLITFEN		4
#define SRAMEN		2
#define DMA2EN		1
#define DMA1EN		0

	/*APB2ENR*/
#define TIM11EN		21
#define TIM10EN		20
#define TIM9EN		19
#define ADC3EN		15
#define USART1EN	14
#define TIM8EN		13
#define SPI1EN		12
#define TIM1EN		11
#define ADC2EN		10
#define ADC1EN		9
#define IOPGEN		8
#define IOPFEN		7
#define IOPEEN		6
#define IOPDEN		5
#define IOPCEN		4
#define IOPBEN		3
#define IOPAEN		2
#define AFIOEN		0


		/*APB1ENR*/
#define DACEN	29
#define PWREN	28
#define BKPEN	27
#define CANEN	25
#define USBEN	23
#define I2C2EN	22
#define I2C1EN	21
#define UART5EN	20
#define UART4EN	19
#define USART3EN	18
#define USART2EN	17
#define SPI3EN	15
#define SPI2EN	14
#define WWDGEN	11
#define TIM14EN	8
#define TIM13EN	7
#define TIM12EN	6
#define TIM7EN	5
#define TIM6EN	4
#define TIM5EN	3
#define TIM4EN	2
#define TIM3EN	1
#define TIM2EN	0



#endif /* RCC_PRV_H_ */
