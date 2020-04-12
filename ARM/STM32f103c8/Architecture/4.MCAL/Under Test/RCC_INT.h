/*
 * RCC_INT.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Dyaa Elshater
 */

#ifndef RCC_INT_H_
#define RCC_INT_H_

#define HSI_CLK 0
#define HSE_CLK 1
#define PLL_CLK 2

#define RCC_ENABLE		1
#define RCC_DISABLE		0


static enum PREDIV {CLK_DIV1,CLK_DIV2};

static enum PLLMUL {CLK_X2,CLK_X3,CLK_X4,CLK_X5,CLK_X6,CLK_X7,CLK_X8,CLK_X9,CLK_X10,CLK_X11,CLK_X12,CLK_X13,CLK_X14,CLK_X15,CLK_X16};

static enum SysCLKStatus { HSI,HSE,PLL};

static enum PreScaller { HCLK_DIV2=0,HCLK_DIV4,HCLK_DIV6,HCLK_DIV8};

static enum Bus_PreScaller { BUS_HCLK_NOT_DIVIDED=0,BUS_HCLK_DIV2=4,BUS_HCLK_DIV4,BUS_HCLK_DIV8,BUS_HCLK_DIV16};

static enum AHB_PreScaller { AHB_HCLK_NOT_DIVIDED=0,AHB_HCLK_DIV2=8,AHB_HCLK_DIV4,AHB_HCLK_DIV8,AHB_HCLK_DIV16,AHB_HCLK_DIV64,AHB_HCLK_DIV128,AHB_HCLK_DIV256,AHB_HCLK_DIV512};

/*Microcontroller check output*/
static enum MCO {NO_CLK_OUT,SYSCLK_OUT=4,HSI_OUT,HSE_OUT,PLL_DIV2_OUT};

void RCC_vidInit(void);
void RCC_vidSetHSE(void);
void RCC_vidSetHSI(void);
		/** u8PLLMULCpy = CLK_X2
		*				  ..
		*				  CLK_X16
		*													*/
void RCC_vidSetPll_HSI(u8 u8PLLMULCpy);
		/** u8PREDIVCpy = CLK_DIV1
		 *				  CLK_DIV2
		 *
		 ** u8PLLMULCpy = CLK_X2
		 *				  ..
		 *				  CLK_16
		 * 													*/
void RCC_vidSetPll_HSE(u8 u8PREDIVCpy,u8 u8PLLMULCpy);
u8 	 RCC_u8SysClkStatus();

		/** u8MCOCpu =
			 * 			NO_CLK_OUT
			 * 			SYSCLK_OUT
			 * 			HSI_OUT
			 * 			HSE_OUT
			 * 			PLL_DIV2_OUT
			  																*/
void RCC_vidMcuClkOut(u8 u8MCOCpy);

		/** u8PrescallerCpy =
			 * 				HCLK_DIV2
			 * 				HCLK_DIV4
			 * 				HCLK_DIV6
			 * 				HCLK_DIV8
			  																*/
void RCC_vidADC_Prescaller(u8 u8PrescallerCpy);

		/*** For BUS
		 **  u8PrescallerCpy =
		 * 					  BUS_HCLK_NOT_DIVIDED
		 * 					  BUS_HCLK_DIV2
		 * 					  BUS_HCLK_DIV4
		 * 					  BUS_HCLK_DIV8
		 * 					  BUS_HCLK_DIV16
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 */


void RCC_vidAPB2_Prescaller(u8 u8PrescallerCpy);

void RCC_vidAPB1_Prescaller(u8 u8PrescallerCpy);

		/*** FOR AHB BUS
		 **  u8PrescallerCpy =
		 *						AHB_HCLK_NOT_DIVIDED
		 *						AHB_HCLK_DIV2
		 *						AHB_HCLK_DIV4
		 *						AHB_HCLK_DIV8
		 *						AHB_HCLK_DIV16
		 *						AHB_HCLK_DIV64
		 *						AHB_HCLK_DIV128
		 *						AHB_HCLK_DIV256
		 *						AHB_HCLK_DIV512
		 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 */

void RCC_vidAHB_Prescaller(u8 u8PrescallerCpy);



	/* For Reset */
void RCC_vidReset_Timer11(void);

void RCC_vidReset_Timer10(void);

void RCC_vidReset_Timer9(void);

void RCC_vidReset_ADC3(void);

void RCC_vidReset_USART1(void);

void RCC_vidReset_Timer8(void);

void RCC_vidReset_SPI1(void);

void RCC_vidReset_Timer1(void);

void RCC_vidReset_ADC2(void);

void RCC_vidReset_ADC1(void);

void RCC_vidReset_GPIOG(void);

void RCC_vidReset_GPIOF(void);

void RCC_vidReset_GPIOE(void);

void RCC_vidReset_GPIOD(void);

void RCC_vidReset_GPIOC(void);

void RCC_vidReset_GPIOB(void);

void RCC_vidReset_GPIOA(void);

void RCC_vidReset_AlternateFunction(void);

void RCC_vidReset_DAC(void);

void RCC_vidReset_Power(void);

void RCC_vidReset_Backup(void);

void RCC_vidReset_CAN(void);

void RCC_vidReset_USB(void);

void RCC_vidReset_I2C2(void);

void RCC_vidReset_I2C1(void);

void RCC_vidReset_UART5(void);

void RCC_vidReset_UART4(void);

void RCC_vidReset_USART3(void);

void RCC_vidReset_USART2(void);

void RCC_vidReset_SPI3(void);

void RCC_vidReset_SPI2(void);

void RCC_vidReset_WindowWatchdogReset(void);

void RCC_vidReset_Timer14(void);

void RCC_vidReset_Timer13(void);

void RCC_vidReset_Timer12(void);

void RCC_vidReset_Timer7(void);

void RCC_vidReset_Timer6(void);

void RCC_vidReset_Timer5(void);

void RCC_vidReset_Timer4(void);

void RCC_vidReset_Timer3(void);

void RCC_vidReset_Timer2(void);

		/*For Enabling*/
void RCC_vidEnable_SDIO(void);

void RCC_vidEnable_FSMC(void);

void RCC_vidEnable_CRC(void);

void RCC_vidEnable_FLITF(void);

void RCC_vidEnable_SRAM(void);

void RCC_vidEnable_DMA2(void);

void RCC_vidEnable_DMA1(void);

				/*APB2*/
void RCC_vidEnable_Timer11(void);

void RCC_vidEnable_Timer10(void);

void RCC_vidEnable_Timer9(void);

void RCC_vidEnable_ADC3(void);

void RCC_vidEnable_USART1(void);

void RCC_vidEnable_Timer8(void);

void RCC_vidEnable_SPI1(void);

void RCC_vidEnable_Timer1(void);

void RCC_vidEnable_ADC2(void);

void RCC_vidEnable_ADC1(void);

void RCC_vidEnable_GPIOG(void);

void RCC_vidEnable_GPIOF(void);

void RCC_vidEnable_GPIOE(void);

void RCC_vidEnable_GPIOD(void);

void RCC_vidEnable_GPIOC(void);

void RCC_vidEnable_GPIOB(void);

void RCC_vidEnable_GPIOA(void);

void RCC_vidEnable_AlternateFunctionIO(void);

		/*APB1*/
void RCC_vidEnable_DAC(void);

void RCC_vidEnable_Power(void);

void RCC_vidEnable_Backup(void);

void RCC_vidEnable_CAN(void);

void RCC_vidEnable_USB(void);

void RCC_vidEnable_I2C2(void);

void RCC_vidEnable_I2C1(void);

void RCC_vidEnable_UART5(void);

void RCC_vidEnable_UART4(void);

void RCC_vidEnable_USART3(void);

void RCC_vidEnable_USART2(void);

void RCC_vidEnable_SPI3(void);

void RCC_vidEnable_SPI2(void);

void RCC_vidEnable_WindowWatchdog(void);

void RCC_vidEnable_Timer14(void);

void RCC_vidEnable_Timer13(void);

void RCC_vidEnable_Timer12(void);

void RCC_vidEnable_Timer7(void);

void RCC_vidEnable_Timer6(void);

void RCC_vidEnable_Timer5(void);

void RCC_vidEnable_Timer4(void);

void RCC_vidEnable_Timer3(void);

void RCC_vidEnable_Timer2(void);


		/*For Disabling*/
void RCC_vidDisable_SDIO(void);

void RCC_vidDisable_FSMC(void);

void RCC_vidDisable_CRC(void);

void RCC_vidDisable_FLITF(void);

void RCC_vidDisable_SRAM(void);

void RCC_vidDisable_DMA2(void);

void RCC_vidDisable_DMA1(void);

				/*APB2*/
void RCC_vidDisable_Timer11(void);

void RCC_vidDisable_Timer10(void);

void RCC_vidDisable_Timer9(void);

void RCC_vidDisable_ADC3(void);

void RCC_vidDisable_USART1(void);

void RCC_vidDisable_Timer8(void);

void RCC_vidDisable_SPI1(void);

void RCC_vidDisable_Timer1(void);

void RCC_vidDisable_ADC2(void);

void RCC_vidDisable_ADC1(void);

void RCC_vidDisable_GPIOG(void);

void RCC_vidDisable_GPIOF(void);

void RCC_vidDisable_GPIOE(void);

void RCC_vidDisable_GPIOD(void);

void RCC_vidDisable_GPIOC(void);

void RCC_vidDisable_GPIOB(void);

void RCC_vidDisable_GPIOA(void);

void RCC_vidDisable_AlternateFunctionIO(void);

		/*APB1*/
void RCC_vidDisable_DAC(void);

void RCC_vidDisable_Power(void);

void RCC_vidDisable_Backup(void);

void RCC_vidDisable_CAN(void);

void RCC_vidDisable_USB(void);

void RCC_vidDisable_I2C2(void);

void RCC_vidDisable_I2C1(void);

void RCC_vidDisable_UART5(void);

void RCC_vidDisable_UART4(void);

void RCC_vidDisable_USART3(void);

void RCC_vidDisable_USART2(void);

void RCC_vidDisable_SPI3(void);

void RCC_vidDisable_SPI2(void);

void RCC_vidDisable_WindowWatchdog(void);

void RCC_vidDisable_Timer14(void);

void RCC_vidDisable_Timer13(void);

void RCC_vidDisable_Timer12(void);

void RCC_vidDisable_Timer7(void);

void RCC_vidDisable_Timer6(void);

void RCC_vidDisable_Timer5(void);

void RCC_vidDisable_Timer4(void);

void RCC_vidDisable_Timer3(void);

void RCC_vidDisable_Timer2(void);



#endif /* RCC_INT_H_ */
