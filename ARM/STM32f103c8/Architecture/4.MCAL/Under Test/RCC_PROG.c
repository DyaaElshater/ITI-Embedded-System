/*
 * RCC_PROG.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Dyaa Elshater
 */

#include "Std_types.h"
#include "Bit_Math.h"

#include "RCC_INT.h"
#include "RCC_CFG.h"
#include "RCC_prv.h"


void RCC_vidInit()
{
	SET_BIT(RCC->CR,CSSON);
#if (START_UP_SYSCLK == HSE_CLK)

	SET_BIT(RCC->CR,HSEON);
	while(!GET_BIT(RCC->CR,HSERDY));
	RCC->CFGR |= SW_HSE ;
#else
	SET_BIT(RCC->CR,HSION);
	while(!GET_BIT(RCC->CR,HSIRDY));
	RCC->CFGR |= SW_HSI ;
#endif





	RCC->AHBENR = 	conc32(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						   RCC_SDIO,0,RCC_FSMC,0,RCC_CRC,0,RCC_FLITF,0,
						   RCC_SRAM,RCC_DMA2,RCC_DMA1);

	RCC->APB2ENR = conc32(0,0,0,0,0,0,0,0,0,0,
						  RCC_TIMER11,RCC_TIMER10,RCC_TIMER9,0,0,0,
						  RCC_ADC3,RCC_USART1,RCC_TIMER8,RCC_SPI1,
						  RCC_TIMER1,RCC_ADC2,RCC_ADC1,RCC_GPIO_G,
						  RCC_GPIO_F,RCC_GPIO_E,RCC_GPIO_D,RCC_GPIO_C,
						  RCC_GPIO_B,RCC_GPIO_A,0,RCC_AFIO);


	RCC->APB1ENR = conc32(0,0,RCC_DAC,RCC_POWER,RCC_BACK_UP,0,RCC_CAN,0,
						  RCC_USB,RCC_I2C2,RCC_I2C1,RCC_UART5,RCC_UART4,
						  RCC_USART3,RCC_USART2,0,RCC_SPI3,RCC_SPI2,0,0,
						  RCC_Window_watchdog,0,0,RCC_TIMER14,RCC_TIMER13,
						  RCC_TIMER12,RCC_TIMER7,RCC_TIMER6,RCC_TIMER5,
						  RCC_TIMER4,RCC_TIMER3,RCC_TIMER2);

}
void RCC_vidSetHSE()
{
	SET_BIT(RCC->CR,HSEON);
	while(!GET_BIT(RCC->CR,HSERDY));
	RCC->CFGR |= SW_HSE ;

}
void RCC_vidSetHSI()
{
	SET_BIT(RCC->CR,HSION);
	while(!GET_BIT(RCC->CR,HSIRDY));
	RCC->CFGR |= SW_HSI ;
}
void RCC_vidSetPll_HSI(u8 u8PLLMULCpy)
{
	if(RCC_u8SysClkStatus()!=HSI)
	{
		SET_BIT(RCC->CR,HSION);
		while(!GET_BIT(RCC->CR,HSIRDY));
	}
	else
	{

	}
	CLEAR_BIT(RCC->CFGR,PLLSRC);
	RCC->CFGR |= (u8PLLMULCpy&0x0f)<<18;
	RCC->CFGR |= SW_PLL ;
}
void RCC_vidSetPll_HSE(u8 u8PREDIVCpy,u8 u8PLLMULCpy)
{
	if(RCC_u8SysClkStatus()!= HSE)
	{
		SET_BIT(RCC->CR,HSEON);
		while(!GET_BIT(RCC->CR,HSERDY));
	}
	else
	{

	}
	RCC->CFGR |= (u8PREDIVCpy & 0x01)	<<PLLXTPRE	;
	SET_BIT(RCC->CFGR,PLLSRC);
	RCC->CFGR  |= (u8PLLMULCpy	& 0x0f) <<18;
	RCC->CFGR  |= SW_PLL ;
}

u8 	 RCC_u8SysClkStatus()
{
	return (RCC->CFGR  & 0b1100)>>2;
}

void RCC_vidMcuClkOut(u8 u8MCOCpy)
{
	RCC->CR |= (u8MCOCpy & 0x07) <<24 ;
}


void RCC_vidADC_Prescaller(u8 u8PrescallerCpy)
{
	RCC->CFGR |= (u8PrescallerCpy & 0x03) <<14 ;
}

void RCC_vidAPB2_Prescaller(u8 u8PrescallerCpy)
{
	RCC->CFGR |= (u8PrescallerCpy & 0x07) <<11 ;
}

void RCC_vidAPB1_Prescaller(u8 u8PrescallerCpy)
{
	RCC->CFGR |= (u8PrescallerCpy & 0x07) <<8 ;
}

void RCC_vidAHB_Prescaller(u8 u8PrescallerCpy)
{
	RCC->CFGR |= (u8PrescallerCpy & 0x0f) <<4 ;
}


/* For Reset */
void RCC_vidReset_Timer11(void)
{
	SET_BIT(RCC->APB2RSTR,TIM11RST);
}

void RCC_vidReset_Timer10(void)
{
	SET_BIT(RCC->APB2RSTR,TIM10RST);
}

void RCC_vidReset_Timer9(void)
{
	SET_BIT(RCC->APB2RSTR,TIM9RST);
}

void RCC_vidReset_ADC3(void)
{
	SET_BIT(RCC->APB2RSTR,ADC3RST);
}

void RCC_vidReset_USART1(void)
{
	SET_BIT(RCC->APB2RSTR,USART1RST);
}
void RCC_vidReset_Timer8(void)
{
	SET_BIT(RCC->APB2RSTR,TIM8RST);
}

void RCC_vidReset_SPI1(void)
{
	SET_BIT(RCC->APB2RSTR,SPI1RST);
}

void RCC_vidReset_Timer1(void)
{
	SET_BIT(RCC->APB2RSTR,TIM1RST);
}

void RCC_vidReset_ADC2(void)
{
	SET_BIT(RCC->APB2RSTR,ADC2RST);
}

void RCC_vidReset_ADC1(void)
{
	SET_BIT(RCC->APB2RSTR,ADC1RST);
}

void RCC_vidReset_GPIOG(void)
{
	SET_BIT(RCC->APB2RSTR,IOPGRST);
}

void RCC_vidReset_GPIOF(void)
{
	SET_BIT(RCC->APB2RSTR,IOPFRST);
}

void RCC_vidReset_GPIOE(void)
{
	SET_BIT(RCC->APB2RSTR,IOPERST);
}

void RCC_vidReset_GPIOD(void)
{
	SET_BIT(RCC->APB2RSTR,IOPDRST);
}

void RCC_vidReset_GPIOC(void)
{
	SET_BIT(RCC->APB2RSTR,IOPCRST);
}

void RCC_vidReset_GPIOB(void)
{
	SET_BIT(RCC->APB2RSTR,IOPBRST);
}

void RCC_vidReset_GPIOA(void)
{
	SET_BIT(RCC->APB2RSTR,IOPARST);
}

void RCC_vidReset_AlternateFunction(void)
{
	SET_BIT(RCC->APB2RSTR,AFIORST);
}

void RCC_vidReset_DAC(void)
{
	SET_BIT(RCC->APB1RSTR,DACRST);
}

void RCC_vidReset_Power(void)
{
	SET_BIT(RCC->APB1RSTR,PWRRST);
}

void RCC_vidReset_Backup(void)
{
	SET_BIT(RCC->APB1RSTR,BKPRST);
}

void RCC_vidReset_CAN(void)
{
	SET_BIT(RCC->APB1RSTR,CANRST);
}

void RCC_vidReset_USB(void)
{
	SET_BIT(RCC->APB1RSTR,USBRST);
}

void RCC_vidReset_I2C2(void)
{
	SET_BIT(RCC->APB1RSTR,I2C2RST);
}

void RCC_vidReset_I2C1(void)
{
	SET_BIT(RCC->APB1RSTR,I2C1RST);
}

void RCC_vidReset_UART5(void)
{
	SET_BIT(RCC->APB1RSTR,UART5RST);
}

void RCC_vidReset_UART4(void)
{
	SET_BIT(RCC->APB1RSTR,UART4RST);
}

void RCC_vidReset_USART3(void)
{
	SET_BIT(RCC->APB1RSTR,USART3RST);
}

void RCC_vidReset_USART2(void)
{
	SET_BIT(RCC->APB1RSTR,USART2RST);
}

void RCC_vidReset_SPI3(void)
{
	SET_BIT(RCC->APB1RSTR,SPI3RST);
}

void RCC_vidReset_SPI2(void)
{
	SET_BIT(RCC->APB1RSTR,SPI2RST);
}

void RCC_vidReset_WindowWatchdogReset(void)
{
	SET_BIT(RCC->APB1RSTR,WWDGRST);
}

void RCC_vidReset_Timer14(void)
{
	SET_BIT(RCC->APB1RSTR,TIM14RST);
}

void RCC_vidReset_Timer13(void)
{
	SET_BIT(RCC->APB1RSTR,TIM13RST);
}

void RCC_vidReset_Timer12(void)
{
	SET_BIT(RCC->APB1RSTR,TIM12RST);
}

void RCC_vidReset_Timer7(void)
{
	SET_BIT(RCC->APB1RSTR,TIM7RST);
}

void RCC_vidReset_Timer6(void)
{
	SET_BIT(RCC->APB1RSTR,TIM6RST);
}

void RCC_vidReset_Timer5(void)
{
	SET_BIT(RCC->APB1RSTR,TIM5RST);
}

void RCC_vidReset_Timer4(void)
{
	SET_BIT(RCC->APB1RSTR,TIM4RST);
}

void RCC_vidReset_Timer3(void)
{
	SET_BIT(RCC->APB1RSTR,TIM3RST);
}

void RCC_vidReset_Timer2(void)
{
	SET_BIT(RCC->APB1RSTR,TIM2RST);
}


/*For Enabling*/
void RCC_vidEnable_SDIO(void)
{
	SET_BIT(RCC->AHBENR,SDIOEN);
}

void RCC_vidEnable_FSMC(void)
{
	SET_BIT(RCC->AHBENR,FSMCEN);
}

void RCC_vidEnable_CRC(void)
{
	SET_BIT(RCC->AHBENR,CRCEN);
}

void RCC_vidEnable_FLITF(void)
{
	SET_BIT(RCC->AHBENR,FLITFEN);
}

void RCC_vidEnable_SRAM(void)
{
	SET_BIT(RCC->AHBENR,SRAMEN);
}

void RCC_vidEnable_DMA2(void)
{
	SET_BIT(RCC->AHBENR,DMA2EN);
}

void RCC_vidEnable_DMA1(void)
{
	SET_BIT(RCC->AHBENR,DMA1EN);
}


			/*APB2*/
void RCC_vidEnable_Timer11(void)
{
	SET_BIT(RCC->APB2ENR,TIM11EN);
}

void RCC_vidEnable_Timer10(void)
{
	SET_BIT(RCC->APB2ENR,TIM10EN);
}

void RCC_vidEnable_Timer9(void)
{
	SET_BIT(RCC->APB2ENR,TIM9EN);
}

void RCC_vidEnable_ADC3(void)
{
	SET_BIT(RCC->APB2ENR,ADC3EN);
}

void RCC_vidEnable_USART1(void)
{
	SET_BIT(RCC->APB2ENR,USART1EN);
}

void RCC_vidEnable_Timer8(void)
{
	SET_BIT(RCC->APB2ENR,TIM8EN);
}

void RCC_vidEnable_SPI1(void)
{
	SET_BIT(RCC->APB2ENR,SPI1EN);
}

void RCC_vidEnable_Timer1(void)
{
	SET_BIT(RCC->APB2ENR,TIM1EN);
}

void RCC_vidEnable_ADC2(void)
{
	SET_BIT(RCC->APB2ENR,ADC2EN);
}

void RCC_vidEnable_ADC1(void)
{
	SET_BIT(RCC->APB2ENR,ADC1EN);
}

void RCC_vidEnable_GPIOG(void)
{
	SET_BIT(RCC->APB2ENR,IOPGEN);
}

void RCC_vidEnable_GPIOF(void)
{
	SET_BIT(RCC->APB2ENR,IOPFEN);
}

void RCC_vidEnable_GPIOE(void)
{
	SET_BIT(RCC->APB2ENR,IOPEEN);
}

void RCC_vidEnable_GPIOD(void)
{
	SET_BIT(RCC->APB2ENR,IOPDEN);
}

void RCC_vidEnable_GPIOC(void)
{
	SET_BIT(RCC->APB2ENR,IOPCEN);
}

void RCC_vidEnable_GPIOB(void)
{
	SET_BIT(RCC->APB2ENR,IOPBEN);
}

void RCC_vidEnable_GPIOA(void)
{
	SET_BIT(RCC->APB2ENR,IOPAEN);
}

void RCC_vidEnable_AlternateFunctionIO(void)
{
	SET_BIT(RCC->APB2ENR,AFIOEN);
}


/*APB1*/
void RCC_vidEnable_DAC(void)
{
	SET_BIT(RCC->APB1ENR,DACEN);
}

void RCC_vidEnable_Power(void)
{
	SET_BIT(RCC->APB1ENR,PWREN);
}

void RCC_vidEnable_Backup(void)
{
	SET_BIT(RCC->APB1ENR,BKPEN);
}

void RCC_vidEnable_CAN(void)
{
	SET_BIT(RCC->APB1ENR,CANEN);
}

void RCC_vidEnable_USB(void)
{
	SET_BIT(RCC->APB1ENR,USBEN);
}

void RCC_vidEnable_I2C2(void)
{
	SET_BIT(RCC->APB1ENR,I2C2EN);
}

void RCC_vidEnable_I2C1(void)
{
	SET_BIT(RCC->APB1ENR,I2C1EN);
}

void RCC_vidEnable_UART5(void)
{
	SET_BIT(RCC->APB1ENR,UART5EN);
}

void RCC_vidEnable_UART4(void)
{
	SET_BIT(RCC->APB1ENR,UART4EN);
}

void RCC_vidEnable_USART3(void)
{
	SET_BIT(RCC->APB1ENR,USART3EN);
}

void RCC_vidEnable_USART2(void)
{
	SET_BIT(RCC->APB1ENR,USART2EN);
}

void RCC_vidEnable_SPI3(void)
{
	SET_BIT(RCC->APB1ENR,SPI3EN);
}

void RCC_vidEnable_SPI2(void)
{
	SET_BIT(RCC->APB1ENR,SPI2EN);
}

void RCC_vidEnable_WindowWatchdog(void)
{
	SET_BIT(RCC->APB1ENR,WWDGEN);
}

void RCC_vidEnable_Timer14(void)
{
	SET_BIT(RCC->APB1ENR,TIM14EN);
}

void RCC_vidEnable_Timer13(void)
{
	SET_BIT(RCC->APB1ENR,TIM13EN);
}

void RCC_vidEnable_Timer12(void)
{
	SET_BIT(RCC->APB1ENR,TIM12EN);
}

void RCC_vidEnable_Timer7(void)
{
	SET_BIT(RCC->APB1ENR,TIM7EN);
}

void RCC_vidEnable_Timer6(void)
{
	SET_BIT(RCC->APB1ENR,TIM6EN);
}

void RCC_vidEnable_Timer5(void)
{
	SET_BIT(RCC->APB1ENR,TIM5EN);
}

void RCC_vidEnable_Timer4(void)
{
	SET_BIT(RCC->APB1ENR,TIM4EN);
}

void RCC_vidEnable_Timer3(void)
{
	SET_BIT(RCC->APB1ENR,TIM3EN);
}

void RCC_vidEnable_Timer2(void)
{
	SET_BIT(RCC->APB1ENR,TIM2EN);
}


		/*For Disabling*/

/*For Enabling*/
void RCC_vidDisable_SDIO(void)
{
	CLEAR_BIT(RCC->AHBENR,SDIOEN);
}

void RCC_vidDisable_FSMC(void)
{
	CLEAR_BIT(RCC->AHBENR,FSMCEN);
}

void RCC_vidDisable_CRC(void)
{
	CLEAR_BIT(RCC->AHBENR,CRCEN);
}

void RCC_vidDisable_FLITF(void)
{
	CLEAR_BIT(RCC->AHBENR,FLITFEN);
}

void RCC_vidDisable_SRAM(void)
{
	CLEAR_BIT(RCC->AHBENR,SRAMEN);
}

void RCC_vidDisable_DMA2(void)
{
	CLEAR_BIT(RCC->AHBENR,DMA2EN);
}

void RCC_vidDisable_DMA1(void)
{
	CLEAR_BIT(RCC->AHBENR,DMA1EN);
}


			/*APB2*/
void RCC_vidDisable_Timer11(void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM11EN);
}

void RCC_vidDisable_Timer10(void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM10EN);
}

void RCC_vidDisable_Timer9(void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM9EN);
}

void RCC_vidDisable_ADC3(void)
{
	CLEAR_BIT(RCC->APB2ENR,ADC3EN);
}

void RCC_vidDisable_USART1(void)
{
	CLEAR_BIT(RCC->APB2ENR,USART1EN);
}

void RCC_vidDisable_Timer8(void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM8EN);
}

void RCC_vidDisable_SPI1(void)
{
	CLEAR_BIT(RCC->APB2ENR,SPI1EN);
}

void RCC_vidDisable_Timer1(void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM1EN);
}

void RCC_vidDisable_ADC2(void)
{
	CLEAR_BIT(RCC->APB2ENR,ADC2EN);
}

void RCC_vidDisable_ADC1(void)
{
	CLEAR_BIT(RCC->APB2ENR,ADC1EN);
}

void RCC_vidDisable_GPIOG(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPGEN);
}

void RCC_vidDisable_GPIOF(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPFEN);
}

void RCC_vidDisable_GPIOE(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPEEN);
}

void RCC_vidDisable_GPIOD(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPDEN);
}

void RCC_vidDisable_GPIOC(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPCEN);
}

void RCC_vidDisable_GPIOB(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPBEN);
}

void RCC_vidDisable_GPIOA(void)
{
	CLEAR_BIT(RCC->APB2ENR,IOPAEN);
}

void RCC_vidDisable_AlternateFunctionIO(void)
{
	CLEAR_BIT(RCC->APB2ENR,AFIOEN);
}


/*APB1*/
void RCC_vidDisable_DAC(void)
{
	CLEAR_BIT(RCC->APB1ENR,DACEN);
}

void RCC_vidDisable_Power(void)
{
	CLEAR_BIT(RCC->APB1ENR,PWREN);
}

void RCC_vidDisable_Backup(void)
{
	CLEAR_BIT(RCC->APB1ENR,BKPEN);
}

void RCC_vidDisable_CAN(void)
{
	CLEAR_BIT(RCC->APB1ENR,CANEN);
}

void RCC_vidDisable_USB(void)
{
	CLEAR_BIT(RCC->APB1ENR,USBEN);
}

void RCC_vidDisable_I2C2(void)
{
	CLEAR_BIT(RCC->APB1ENR,I2C2EN);
}

void RCC_vidDisable_I2C1(void)
{
	CLEAR_BIT(RCC->APB1ENR,I2C1EN);
}

void RCC_vidDisable_UART5(void)
{
	CLEAR_BIT(RCC->APB1ENR,UART5EN);
}

void RCC_vidDisable_UART4(void)
{
	CLEAR_BIT(RCC->APB1ENR,UART4EN);
}

void RCC_vidDisable_USART3(void)
{
	CLEAR_BIT(RCC->APB1ENR,USART3EN);
}

void RCC_vidDisable_USART2(void)
{
	CLEAR_BIT(RCC->APB1ENR,USART2EN);
}

void RCC_vidDisable_SPI3(void)
{
	CLEAR_BIT(RCC->APB1ENR,SPI3EN);
}

void RCC_vidDisable_SPI2(void)
{
	CLEAR_BIT(RCC->APB1ENR,SPI2EN);
}

void RCC_vidDisable_WindowWatchdog(void)
{
	CLEAR_BIT(RCC->APB1ENR,WWDGEN);
}

void RCC_vidDisable_Timer14(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM14EN);
}

void RCC_vidDisable_Timer13(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM13EN);
}

void RCC_vidDisable_Timer12(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM12EN);
}

void RCC_vidDisable_Timer7(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM7EN);
}

void RCC_vidDisable_Timer6(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM6EN);
}

void RCC_vidDisable_Timer5(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM5EN);
}

void RCC_vidDisable_Timer4(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM4EN);
}

void RCC_vidDisable_Timer3(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM3EN);
}

void RCC_vidDisable_Timer2(void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM2EN);
}


