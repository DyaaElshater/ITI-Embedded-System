/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 23/12/2019					*/
/* Description	: RCC Private File				*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

#include <Std_types.h>

typedef struct
{
  u32	CR;
  u32	PLLCFGR;
  u32	CFGR;
  u32	CIR;
  u32	AHB1RSTR;
  u32	AHB2RSTR;
  u32	AHB3RSTR;
  u32	Reserved0;
  u32	APB1RSTR;
  u32	APB2RSTR;
  u32	Reserved1;
  u32	Reserved2;
  u32	AHB1ENR;
  u32	AHB2ENR;
  u32	AHB3ENR;
  u32	Reserved3;
  u32	APB1ENR;
  u32	APB2ENR;
  u32	Reserved4;
  u32	Reserved5;
  u32	AHB1LPENR;
  u32	AHB2LPENR;
  u32	AHB3LPENR;
  u32	Reserved6;
  u32	APB1LPENR;
  u32	APB2LPENR;
  u32	Reserved7;
  u32	Reserved8;
  u32	BDCR;
  u32	CSR;
  u32	Reserved9;
  u32	Reserved10;
  u32	SSCGR;
  u32	PLLI2SCFGR;
  u32	PLLSAICFGR;
  u32	DCKCFGR;
}RCC_REG;

volatile static RCC_REG * const RCC = ( volatile RCC_REG*)0x40023800 ;


	/*	BITs*/

	/*CR*/
	/*CR*/
#define HSION		0
#define HSIRDY		1
#define HSEON		16
#define HSERDY		17
#define HSEBYP		18
#define CSSON		19
#define PLLON		24
#define PLLRDY		25
#define PLLI2SON	26
#define PLLI2SRDY	27
#define PLLSAION	28
#define PLLSAIRDY	29


	/*CFGR*/
#define SW_HSI 0
#define SW_HSE 1
#define SW_PLL 2

#define I2SSRC		23
/*
#define USBPRE		22
#define PLLXTPRE	17
#define PLLSRC		16
*/


	/*CIR*/
#define	CSSC		23
#define	PLLSAIRDYC	22
#define	PLLI2SRDYC	21
#define	PLLRDYC		20
#define	HSERDYC		19
#define	HSIRDYC		18
#define	LSERDYC		17
#define	LSIRDYC		16
#define	PLLSAIRDYIE	14
#define	PLLI2SRDYIE	13
#define	PLLRDYIE	12
#define	HSERDYIE	11
#define	HSIRDYIE	10
#define	LSERDYIE	9
#define	LSIRDYIE	8
#define	CSSF		7
#define	PLLSAIRDYF	6
#define	PLLI2SRDYF	5
#define	PLLRDYF		4
#define	HSERDYF		3
#define	HSIRDYF		2
#define	LSERDYF		1
#define	LSIRDYF		0

	/*AHB1RSTR*/
#define	OTGHSRST	29
#define	ETHMACRST	25
#define	DMA2DRST	23
#define	DMA2RST		22
#define	DMA1RST		21
#define	CRCRST		12
#define	GPIOKRST	10
#define	GPIOJRST	9
#define	GPIOIRST	8
#define	GPIOHRST	7
#define	GPIOGRST	6
#define	GPIOFRST	5
#define	GPIOERST	4
#define	GPIODRST	3
#define	GPIOCRST	2
#define	GPIOBRST	1
#define	GPIOARST	0

	/*AHB2RSTR*/
#define	OTGFSRST	7
#define	RNGRST		6
#define	HASHRST		5
#define	CRYPRST		4
#define	DCMIRST		0

	/*AHB3RSTR*/
#define	FMCRST		0

	/*APB1RSTR*/
#define UART8RST	31
#define UART7RST	30
#define DACRST		29
#define PWRRST		28
#define BKPRST		27
#define CAN2RST		26
#define CAN1RST		25
#define I2C3RST		23
#define I2C2RST		22
#define I2C1RST		21
#define UART5RST	20
#define UART4RST	19
#define USART3RST	18
#define USART2RST	17
#define SPI3RST		15
#define SPI2RST		14
#define WWDGRST		11
#define TIM14RST	8
#define TIM13RST	7
#define TIM12RST	6
#define TIM7RST		5
#define TIM6RST		4
#define TIM5RST		3
#define TIM4RST		2
#define TIM3RST		1
#define TIM2RST		0

	/*APB2RSTR*/
#define LTDCRST		26
#define SAI1RST		22
#define SPI6RST		21
#define SPI5RST		20
#define TIM11RST	18
#define TIM10RST	17
#define TIM9RST		16
#define SYSCFGRST	14
#define SPI4RST		13
#define SPI1RST		12
#define	SDIORST		11
#define ADCRST		8
#define	USART6RST	5
#define	USART1RST	4
#define	TIM8RST		1
#define TIM1RST		0

	/*AHB1ENR*/
#define	OTGHSULPIEN	30
#define	OTGHSEN		29
#define	ETHMACPTPEN	28
#define	ETHMACRXEN	27
#define	ETHMACTXEN	26
#define	ETHMACEN	25
#define	DMA2DEN		23
#define	DMA2EN		22
#define	DMA1EN		21
#define	CCMDATARAMEN	20
#define	BKPSRAMEN	18
#define	CRCEN		12
#define	GPIOKEN		10
#define	GPIOJEN		9
#define	GPIOIEN		8
#define	GPIOHEN		7
#define	GPIOGEN		6
#define	GPIOFEN		5
#define	GPIOEEN		4
#define	GPIODEN		3
#define	GPIOCEN		2
#define	GPIOBEN		1
#define	GPIOAEN		0

	/*AHB2ENR*/
#define	OTGFSEN		7
#define	RNGEN		6
#define	HASHEN		5
#define	CRYPEN		4
#define	DCMIEN		0

	/*AHB3ENR*/
#define	FMCEN		0

	/*APB1ENR*/
#define UART8EN	31
#define UART7EN	30
#define DACEN	29
#define PWREN	28
#define CAN2EN	26
#define CAN1EN	25
#define I2C3EN	23
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

	/*APB2ENR*/
#define LTDCEN		26
#define SAI1EN		22
#define SPI6EN		21
#define SPI5EN		20
#define TIM11EN		18
#define TIM10EN		17
#define TIM9EN		16
#define SYSCFGEN	14
#define SPI4EN		13
#define SPI1EN		12
#define SDIOEN		11
#define ADC3EN		10
#define ADC2EN		9
#define ADC1EN		8
#define USART6EN	5
#define USART1EN	4
#define TIM8EN		1
#define TIM1EN		0

	/*AHB1LPENR*/
#define OTGHSULPILPEN	30
#define OTGHSLPEN		29
#define	ETHMACPTPLPEN2	28
#define	ETHMACRXLPEN	27
#define	ETHMACTXLPEN	26
#define	ETHMACLPEN		25
#define	DMA2DLPEN		23
#define	DMA2LPEN		22
#define	DMA1LPEN		21
#define SRAM3LPEN		19
#define	BKPSRAMLPEN		18
#define	SRAM2LPEN		17
#define	SRAM1LPEN		16
#define	FLITFLPEN		15
#define	CRCLPEN			12
#define	GPIOKLPEN		10
#define	GPIOJLPEN		9
#define	GPIOILPEN		8
#define	GPIOHLPEN		7
#define	GPIOGLPEN		6
#define	GPIOFLPEN		5
#define	GPIOELPEN		4
#define	GPIODLPEN		3
#define	GPIOCLPEN		2
#define	GPIOBLPEN		1
#define	GPIOALPEN		0

	/*AHB2LPENR*/
#define OTGFSLPEN	7
#define RNGLPEN		6
#define HASHLPEN	5
#define CRYPLPEN	4
#define DCMILPEN	0

	/*AHB3LPENR*/
#define FMCLPEN		0

	/*APB1LPENR*/
#define UART8LPEN	31
#define UART7LPEN	30
#define DACLPEN		29
#define PWRLPEN		28
#define CAN2LPEN	26
#define CAN1LPEN	25
#define I2C3LPEN	23
#define I2C2LPEN	22
#define I2C1LPEN	21
#define UART5LPEN	20
#define UART4LPEN	19
#define USART3LPEN	18
#define USART2LPEN	17
#define SPI3LPEN	15
#define SPI2LPEN	14
#define WWDGLPEN	11
#define TIM14LPEN	8
#define TIM13LPEN	7
#define TIM12LPEN	6
#define TIM7LPEN	5
#define TIM6LPEN	4
#define TIM5LPEN	3
#define TIM4LPEN	2
#define TIM3LPEN	1
#define TIM2LPEN	0

	/*APB2LPENR*/
#define LTDCLPEN	26
#define SAI1LPEN	22
#define SPI6LPEN	21
#define SPI5LPEN	20
#define TIM11LPEN	18
#define TIM10LPEN	17
#define TIM9LPEN	16
#define SYSCFGLPEN	14
#define SPI4LPEN	13
#define SPI1LPEN	12
#define SDIOLPEN	11
#define ADC3LPEN	10
#define ADC2LPEN	9
#define ADC1LPEN	8
#define USART6LPEN	5
#define USART1LPEN	4
#define TIM8LPEN	1
#define TIM1LPEN	0

	/*BDCR*/
#define BDRST		16
#define RTCEN		15
#define RTCSEL		8
#define LSEBYP		2
#define LSERDY		1
#define LSEON		0

	/*CSR*/
#define	LPWRRSTF	31
#define	WWDGRSTF	30
#define	IWDGRSTF	29
#define	SFTRSTF		28
#define	PORRSTF		27
#define	PINRSTF		26
#define	BORRSTF		25
#define	RMVF		24
#define	LSIRDY		1
#define	LSION		0

	/*SSCGR*/
#define	SSCGEN		31
#define	SPREADSEL	30
#define	INCSTEP		13
#define	MODPER		0

	/*PLLI2SCFGR*/
#define PLLI2SR		28
#define PLLI2SQ		24
#define PLLI2SN		6

	/*PLLSAICFGR*/
#define PLLSAIR		28
#define PLLSAIQ		24
#define PLLSAIN		6

	/*DCKCFGR*/
#define TIMPRE		24
#define SAI1BSRC	22
#define SAI1ASRC	20
#define PLLSAIDIVR	16
#define PLLSAIDIVQ	8
#define PLLI2SDIVQ	0

#endif /* RCC_PRIV_H_ */
