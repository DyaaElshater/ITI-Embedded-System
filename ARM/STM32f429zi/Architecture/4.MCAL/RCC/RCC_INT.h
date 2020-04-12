/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 23/12/2019					*/
/* Description	: RCC Interface File			*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#ifndef RCC_INT_H_
#define RCC_INT_H_

#define RCC_ENABLE	1
#define RCC_DISABLE	0



/** Description	:								*/
/* 				- Enable the peripherals as 	*/
/*				 		configured				*/
/*				- Select The Clock Sourse as	*/
/*				 		configured				*/
void RCC_vidInit(void);


/** Description	:								*/
/*			Reseting the Modules				*/
				/*AHB1*/
void RCC_vidReset_USB_OTG_HS(void);
void RCC_vidReset_EthernetMAC (void);
void RCC_vidReset_DMA2D (void);
void RCC_vidReset_DMA2 (void);
void RCC_vidReset_DMA1 (void);
void RCC_vidReset_CRC (void);
void RCC_vidReset_GPIO_K (void);
void RCC_vidReset_GPIO_J (void);
void RCC_vidReset_GPIO_I (void);
void RCC_vidReset_GPIO_H (void);
void RCC_vidReset_GPIO_G (void);
void RCC_vidReset_GPIO_F (void);
void RCC_vidReset_GPIO_E (void);
void RCC_vidReset_GPIO_D (void);
void RCC_vidReset_GPIO_C (void);
void RCC_vidReset_GPIO_B (void);
void RCC_vidReset_GPIO_A (void);
				/*AHB2*/
void RCC_vidReset_USB_OTG_FS (void);
void RCC_vidReset_RandomNumberGenerator (void);
void RCC_vidReset_Hash (void);
void RCC_vidReset_Cryptographic (void);
void RCC_vidReset_CameraInterface  (void);
				/*AHB3*/
void RCC_vidReset_FlexibleMemoryController(void);
				/*APB1*/
void RCC_vidReset_UART8 (void);
void RCC_vidReset_UART7 (void);
void RCC_vidReset_DAC (void);
void RCC_vidReset_PowerInterface (void);
void RCC_vidReset_CAN2 (void);
void RCC_vidReset_CAN1 (void);
void RCC_vidReset_I2C3 (void);
void RCC_vidReset_I2C2 (void);
void RCC_vidReset_I2C1 (void);
void RCC_vidReset_UART5 (void);
void RCC_vidReset_USART4 (void);
void RCC_vidReset_USART3 (void);
void RCC_vidReset_USART2 (void);
void RCC_vidReset_SPI3 (void);
void RCC_vidReset_SPI2 (void);
void RCC_vidReset_WindowWatchdog (void);
void RCC_vidReset_TIMER14 (void);
void RCC_vidReset_TIMER13 (void);
void RCC_vidReset_TIMER12 (void);
void RCC_vidReset_TIMER7 (void);
void RCC_vidReset_TIMER6 (void);
void RCC_vidReset_TIMER5 (void);
void RCC_vidReset_TIMER4 (void);
void RCC_vidReset_TIMER3 (void);
void RCC_vidReset_TIMER2 (void);
				/*APB2*/
void RCC_vidReset_LTDC (void);
void RCC_vidReset_SAI1 (void);
void RCC_vidReset_SPI6 (void);
void RCC_vidReset_SPI5 (void);
void RCC_vidReset_TIMER11 (void);
void RCC_vidReset_TIMER10 (void);
void RCC_vidReset_TIMER9 (void);
void RCC_vidReset_SystemConfigurationController (void);
void RCC_vidReset_SPI4 (void);
void RCC_vidReset_SPI1 (void);
void RCC_vidReset_SDIO (void);
void RCC_vidReset_ADC (void);
void RCC_vidReset_USART6 (void);
void RCC_vidReset_USART1 (void);
void RCC_vidReset_TIMER8 (void);
void RCC_vidReset_TIMER1 (void);


/** Description	:								*/
/*			Enabling the Modules				*/
				/*AHB1*/
void RCC_Enable_USB_OTG_HS_ULPI (void);
void RCC_Enable_USB_OTG_HS (void);
void RCC_Enable_EthernetPTP (void);
void RCC_Enable_EthernetReception (void);
void RCC_Enable_EthernetTransmission (void);
void RCC_Enable_EthernetMAC (void);
void RCC_Enable_DMA2D (void);
void RCC_Enable_DMA2 (void);
void RCC_Enable_DMA1 (void);
void RCC_Enable_CCM_Data_RAM (void);
void RCC_Enable_BackupSRAM (void);
void RCC_Enable_CRC (void);
void RCC_Enable_GPIO_A (void);
void RCC_Enable_GPIO_B (void);
void RCC_Enable_GPIO_C (void);
void RCC_Enable_GPIO_D (void);
void RCC_Enable_GPIO_E (void);
void RCC_Enable_GPIO_F (void);
void RCC_Enable_GPIO_G (void);
void RCC_Enable_GPIO_H (void);
void RCC_Enable_GPIO_I (void);
void RCC_Enable_GPIO_J (void);
void RCC_Enable_GPIO_K (void);
			/*AHB2*/
void RCC_Enable_USB_OTG_FS (void);
void RCC_Enable_RandomNumberGenerator (void);
void RCC_Enable_Hash (void);
void RCC_Enable_Cryptographic (void);
void RCC_Enable_CameraInterface (void);
			/*AHB3*/
void RCC_Enable_FlexibleMemoryController (void);
			/*APB1*/
void RCC_Enable_UART8 (void);
void RCC_Enable_UART7 (void);
void RCC_Enable_DAC (void);
void RCC_Enable_PowerInterface (void);
void RCC_Enable_CAN2 (void);
void RCC_Enable_CAN1 (void);
void RCC_Enable_I2C3 (void);
void RCC_Enable_I2C2 (void);
void RCC_Enable_I2C1 (void);
void RCC_Enable_UART5 (void);
void RCC_Enable_UART4 (void);
void RCC_Enable_USART3 (void);
void RCC_Enable_USART2 (void);
void RCC_Enable_SPI3 (void);
void RCC_Enable_SPI2 (void);
void RCC_Enable_WindowWatchdog (void);
void RCC_Enable_TIMER14 (void);
void RCC_Enable_TIMER13 (void);
void RCC_Enable_TIMER12 (void);
void RCC_Enable_TIMER7 (void);
void RCC_Enable_TIMER6 (void);
void RCC_Enable_TIMER5 (void);
void RCC_Enable_TIMER4 (void);
void RCC_Enable_TIMER3 (void);
void RCC_Enable_TIMER2 (void);
			/*APB2*/
void RCC_Enable_LTDC (void);
void RCC_Enable_SAI1 (void);
void RCC_Enable_SPI6 (void);
void RCC_Enable_SPI5 (void);
void RCC_Enable_TIMER11 (void);
void RCC_Enable_TIMER10 (void);
void RCC_Enable_TIMER9 (void);
void RCC_Enable_SystemConfigurationcontroller (void);
void RCC_Enable_SPI4 (void);
void RCC_Enable_SPI1 (void);
void RCC_Enable_SDIO (void);
void RCC_Enable_ADC3 (void);
void RCC_Enable_ADC2 (void);
void RCC_Enable_ADC1 (void);
void RCC_Enable_USART6 (void);
void RCC_Enable_USART1 (void);
void RCC_Enable_TIMER8 (void);
void RCC_Enable_TIMER1 (void);


/** Description	:								*/
/*			Disabling the Modules				*/
				/*AHB1*/
void RCC_Disable_USB_OTG_HS_ULPI (void);
void RCC_Disable_USB_OTG_HS (void);
void RCC_Disable_EthernetPTP (void);
void RCC_Disable_EthernetReception (void);
void RCC_Disable_EthernetTransmission (void);
void RCC_Disable_EthernetMAC (void);
void RCC_Disable_DMA2D (void);
void RCC_Disable_DMA2 (void);
void RCC_Disable_DMA1 (void);
void RCC_Disable_CCM_Data_RAM (void);
void RCC_Disable_BackupSRAM (void);
void RCC_Disable_CRC (void);
void RCC_Disable_GPIO_A (void);
void RCC_Disable_GPIO_B (void);
void RCC_Disable_GPIO_C (void);
void RCC_Disable_GPIO_D (void);
void RCC_Disable_GPIO_E (void);
void RCC_Disable_GPIO_F (void);
void RCC_Disable_GPIO_G (void);
void RCC_Disable_GPIO_H (void);
void RCC_Disable_GPIO_I (void);
void RCC_Disable_GPIO_J (void);
void RCC_Disable_GPIO_K (void);
			/*AHB2*/
void RCC_Disable_USB_OTG_FS (void);
void RCC_Disable_RandomNumberGenerator (void);
void RCC_Disable_Hash (void);
void RCC_Disable_Cryptographic (void);
void RCC_Disable_CameraInterface (void);
			/*AHB3*/
void RCC_Disable_FlexibleMemoryController (void);
			/*APB1*/
void RCC_Disable_UART8 (void);
void RCC_Disable_UART7 (void);
void RCC_Disable_DAC (void);
void RCC_Disable_PowerInterface (void);
void RCC_Disable_CAN2 (void);
void RCC_Disable_CAN1 (void);
void RCC_Disable_I2C3 (void);
void RCC_Disable_I2C2 (void);
void RCC_Disable_I2C1 (void);
void RCC_Disable_UART5 (void);
void RCC_Disable_UART4 (void);
void RCC_Disable_USART3 (void);
void RCC_Disable_USART2 (void);
void RCC_Disable_SPI3 (void);
void RCC_Disable_SPI2 (void);
void RCC_Disable_WindowWatchdog (void);
void RCC_Disable_TIMER14 (void);
void RCC_Disable_TIMER13 (void);
void RCC_Disable_TIMER12 (void);
void RCC_Disable_TIMER7 (void);
void RCC_Disable_TIMER6 (void);
void RCC_Disable_TIMER5 (void);
void RCC_Disable_TIMER4 (void);
void RCC_Disable_TIMER3 (void);
void RCC_Disable_TIMER2 (void);
			/*APB2*/
void RCC_Disable_LTDC (void);
void RCC_Disable_SAI1 (void);
void RCC_Disable_SPI6 (void);
void RCC_Disable_SPI5 (void);
void RCC_Disable_TIMER11 (void);
void RCC_Disable_TIMER10 (void);
void RCC_Disable_TIMER9 (void);
void RCC_Disable_SystemConfigurationcontroller (void);
void RCC_Disable_SPI4 (void);
void RCC_Disable_SPI1 (void);
void RCC_Disable_SDIO (void);
void RCC_Disable_ADC3 (void);
void RCC_Disable_ADC2 (void);
void RCC_Disable_ADC1 (void);
void RCC_Disable_USART6 (void);
void RCC_Disable_USART1 (void);
void RCC_Disable_TIMER8 (void);
void RCC_Disable_TIMER1 (void);



/** Description	:								*/
/*			Enabling the Modules In Low Power	*/
				/*AHB1*/
void RCC_EnableLowPower_USB_OTG_HS_ULPI (void);
void RCC_EnableLowPower_USB_OTG_HS (void);
void RCC_EnableLowPower_EthernetPTP (void);
void RCC_EnableLowPower_EthernetReception (void);
void RCC_EnableLowPower_EthernetTransmission (void);
void RCC_EnableLowPower_EthernetMAC (void);
void RCC_EnableLowPower_DMA2D (void);
void RCC_EnableLowPower_DMA2 (void);
void RCC_EnableLowPower_DMA1 (void);
void RCC_EnableLowPower_SRAM3Interface (void);
void RCC_EnableLowPower_SRAM2Interface (void);
void RCC_EnableLowPower_SRAM1Interface (void);
void RCC_EnableLowPower_FlashInterface (void);
void RCC_EnableLowPower_BackupSRAM (void);
void RCC_EnableLowPower_CRC (void);
void RCC_EnableLowPower_GPIO_A (void);
void RCC_EnableLowPower_GPIO_B (void);
void RCC_EnableLowPower_GPIO_C (void);
void RCC_EnableLowPower_GPIO_D (void);
void RCC_EnableLowPower_GPIO_E (void);
void RCC_EnableLowPower_GPIO_F (void);
void RCC_EnableLowPower_GPIO_G (void);
void RCC_EnableLowPower_GPIO_H (void);
void RCC_EnableLowPower_GPIO_I (void);
void RCC_EnableLowPower_GPIO_J (void);
void RCC_EnableLowPower_GPIO_K (void);
			/*AHB2*/
void RCC_EnableLowPower_USB_OTG_FS (void);
void RCC_EnableLowPower_RandomNumberGenerator (void);
void RCC_EnableLowPower_Hash (void);
void RCC_EnableLowPower_Cryptographic (void);
void RCC_EnableLowPower_CameraInterface (void);
			/*AHB3*/
void RCC_EnableLowPower_FlexibleMemoryController (void);
			/*APB1*/
void RCC_EnableLowPower_UART8 (void);
void RCC_EnableLowPower_UART7 (void);
void RCC_EnableLowPower_DAC (void);
void RCC_EnableLowPower_PowerInterface (void);
void RCC_EnableLowPower_CAN2 (void);
void RCC_EnableLowPower_CAN1 (void);
void RCC_EnableLowPower_I2C3 (void);
void RCC_EnableLowPower_I2C2 (void);
void RCC_EnableLowPower_I2C1 (void);
void RCC_EnableLowPower_UART5 (void);
void RCC_EnableLowPower_UART4 (void);
void RCC_EnableLowPower_USART3 (void);
void RCC_EnableLowPower_USART2 (void);
void RCC_EnableLowPower_SPI3 (void);
void RCC_EnableLowPower_SPI2 (void);
void RCC_EnableLowPower_WindowWatchdog (void);
void RCC_EnableLowPower_TIMER14 (void);
void RCC_EnableLowPower_TIMER13 (void);
void RCC_EnableLowPower_TIMER12 (void);
void RCC_EnableLowPower_TIMER7 (void);
void RCC_EnableLowPower_TIMER6 (void);
void RCC_EnableLowPower_TIMER5 (void);
void RCC_EnableLowPower_TIMER4 (void);
void RCC_EnableLowPower_TIMER3 (void);
void RCC_EnableLowPower_TIMER2 (void);
			/*APB2*/
void RCC_EnableLowPower_LTDC (void);
void RCC_EnableLowPower_SAI1 (void);
void RCC_EnableLowPower_SPI6 (void);
void RCC_EnableLowPower_SPI5 (void);
void RCC_EnableLowPower_TIMER11 (void);
void RCC_EnableLowPower_TIMER10 (void);
void RCC_EnableLowPower_TIMER9 (void);
void RCC_EnableLowPower_SystemConfigurationcontroller (void);
void RCC_EnableLowPower_SPI4 (void);
void RCC_EnableLowPower_SPI1 (void);
void RCC_EnableLowPower_SDIO (void);
void RCC_EnableLowPower_ADC3 (void);
void RCC_EnableLowPower_ADC2 (void);
void RCC_EnableLowPower_ADC1 (void);
void RCC_EnableLowPower_USART6 (void);
void RCC_EnableLowPower_USART1 (void);
void RCC_EnableLowPower_TIMER8 (void);
void RCC_EnableLowPower_TIMER1 (void);



#endif /* RCC_INT_H_ */
