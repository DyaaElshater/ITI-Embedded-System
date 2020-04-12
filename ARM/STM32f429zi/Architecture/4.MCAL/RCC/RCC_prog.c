/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 23/12/2019					*/
/* Description	: RCC Implementation File		*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#include "Std_types.h"
#include "Bit_Math.h"
#include "DELAY.h"

#include "RCC_INT.h"
#include "RCC_CFG.h"
#include "RCC_PRIV.h"

void RCC_vidInit()
{
			/***For Normal Mode**/
	RCC->AHB1ENR = conc(0,
						USB_OTG_HS_ULPI_EN,USB_OTG_HS_EN,Ethernet_PTP_EN,
						Ethernet_Reception_EN,Ethernet_Transmission_EN,Ethernet_MAC_EN,
						0,DMA2D_clock_EN,DMA2_EN,DMA1_EN,CCM_Data_RAM_EN,
						0,Backup_SRAM_EN,0,0,0,0,0,CRC_EN,0,IO_port_K_EN,
						IO_port_J_EN,IO_port_I_EN,IO_port_H_EN,IO_port_G_EN,
						IO_port_F_EN,IO_port_E_EN,IO_port_D_EN,IO_port_C_EN,
						IO_port_B_EN,IO_port_A_EN
						);

	RCC->AHB2ENR = conc(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						USB_OTG_FS_EN,Random_Number_Generator_EN,Hash_Modules_EN,
						Cryptographic_Module_EN,0,0,0,Camera_Interface_EN
						);

	RCC->AHB3ENR = FMC_Module_EN;

	RCC->APB2LPENR = conc(
			UART8_EN,UART7_EN,DAC_EN,Power_EN,0,CAN2_EN,CAN1_EN,
			0,I2C3_EN,I2C2_EN,I2C1_EN,UART5_EN,UART4_EN,USART3_EN,
			USART2_EN,0,SPI3_EN,SPI2_EN,0,0,Window_watchdog_EN,
			0,0,TIMER14_EN,TIMER13_EN,TIMER12_EN,TIMER7_EN,
			TIMER6_EN,TIMER5_EN,TIMER4_EN,TIMER3_EN,TIMER2_EN
						);

	RCC->APB2ENR = conc(
			0,0,0,0,0,LTDC_EN,0,0,0,SAI1_EN,SPI6_EN,SPI5_EN,0,
			TIMER11_EN,TIMER10_EN,TIMER9_EN,0,System_Configuration_EN,
			SPI4_EN,SPI1_EN,SDIO_EN,ADC3_EN,ADC2_EN,ADC1_EN,
			0,0,USART6_EN,USART1_EN,0,0,TIMER8_EN,TIMER1_EN
						);

			/***For Low Power Mode**/
	RCC->AHB1LPENR = conc(0,
						USB_OTG_HS_ULPI_LP_EN,USB_OTG_HS_LP_EN,Ethernet_PTP_LP_EN,
						Ethernet_Reception_LP_EN,Ethernet_Transmission_LP_EN,Ethernet_MAC_LP_EN,
						0,DMA2D_clock_LP_EN,DMA2_LP_EN,DMA1_LP_EN,0,SRAM3_Interface_LP_EN,
						Backup_SRAM_LP_EN,SRAM2_Interface_LP_EN,SRAM1_Interface_LP_EN,
						Flash_Interface_LP_EN,0,0,CRC_LP_EN,0,IO_port_K_LP_EN,
						IO_port_J_LP_EN,IO_port_I_LP_EN,IO_port_H_LP_EN,IO_port_G_LP_EN,
						IO_port_F_LP_EN,IO_port_E_LP_EN,IO_port_D_LP_EN,IO_port_C_LP_EN,
						IO_port_B_LP_EN,IO_port_A_LP_EN
						);

	RCC->AHB2LPENR = conc(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
						USB_OTG_FS_LP_EN,Random_Number_Generator_LP_EN,Hash_Modules_LP_EN,
						Cryptographic_Module_LP_EN,0,0,0,Camera_Interface_LP_EN
						);

	RCC->AHB3LPENR = FMC_Module_LP_EN;

	RCC->APB1LPENR= conc(
			UART8_LP_EN,UART7_LP_EN,DAC_LP_EN,Power_LP_EN,0,CAN2_LP_EN,CAN1_LP_EN,
			0,I2C3_LP_EN,I2C2_LP_EN,I2C1_LP_EN,UART5_LP_EN,UART4_LP_EN,USART3_LP_EN,
			USART2_LP_EN,0,SPI3_LP_EN,SPI2_LP_EN,0,0,Window_watchdog_LP_EN,
			0,0,TIMER14_LP_EN,TIMER13_LP_EN,TIMER12_LP_EN,TIMER7_LP_EN,
			TIMER6_LP_EN,TIMER5_LP_EN,TIMER4_LP_EN,TIMER3_LP_EN,TIMER2_LP_EN
						);

	RCC->APB2LPENR = conc(
			0,0,0,0,0,LTDC_LP_EN,0,0,0,SAI1_LP_EN,SPI6_LP_EN,SPI5_LP_EN,0,
			TIMER11_LP_EN,TIMER10_LP_EN,TIMER9_LP_EN,0,System_Configuration_LP_EN,
			SPI4_LP_EN,SPI1_LP_EN,SDIO_LP_EN,ADC3_LP_EN,ADC2_LP_EN,ADC1_LP_EN,
			0,0,USART6_LP_EN,USART1_LP_EN,0,0,TIMER8_LP_EN,TIMER1_LP_EN
						);

}



/** Description	:								*/
/*			Reseting the Modules				*/
				/*AHB1*/
void RCC_vidReset_USB_OTG_HS(void)
{
	SET_BIT(RCC->AHB1RSTR,OTGHSRST);
}
void RCC_vidReset_EthernetMAC (void)
{
	SET_BIT(RCC->AHB1RSTR,ETHMACRST);
}
void RCC_vidReset_DMA2D (void)
{
	SET_BIT(RCC->AHB1RSTR,DMA2DRST);
}
void RCC_vidReset_DMA2 (void)
{
	SET_BIT(RCC->AHB1RSTR,DMA2RST);
}
void RCC_vidReset_DMA1 (void)
{
	SET_BIT(RCC->AHB1RSTR,DMA1RST);
}
void RCC_vidReset_CRC (void)
{
	SET_BIT(RCC->AHB1RSTR,CRCRST);
}
void RCC_vidReset_GPIO_K (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOKRST);
}
void RCC_vidReset_GPIO_J (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOJRST);
}
void RCC_vidReset_GPIO_I (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOIRST);
}
void RCC_vidReset_GPIO_H (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOHRST);
}
void RCC_vidReset_GPIO_G (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOGRST);
}
void RCC_vidReset_GPIO_F (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOFRST);
}
void RCC_vidReset_GPIO_E (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOERST);
}
void RCC_vidReset_GPIO_D (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIODRST);
}
void RCC_vidReset_GPIO_C (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOCRST);
}
void RCC_vidReset_GPIO_B (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOBRST);
}
void RCC_vidReset_GPIO_A (void)
{
	SET_BIT(RCC->AHB1RSTR,GPIOARST);
}
				/*AHB2*/
void RCC_vidReset_USB_OTG_FS (void)
{
	SET_BIT(RCC->AHB2RSTR,OTGFSRST);
}
void RCC_vidReset_RandomNumberGenerator (void)
{
	SET_BIT(RCC->AHB2RSTR,RNGRST);
}
void RCC_vidReset_Hash (void)
{
	SET_BIT(RCC->AHB2RSTR,HASHRST);
}
void RCC_vidReset_Cryptographic (void)
{
	SET_BIT(RCC->AHB2RSTR,CRYPRST);
}
void RCC_vidReset_CameraInterface  (void)
{
	SET_BIT(RCC->AHB2RSTR,DCMIRST);
}
				/*AHB3*/
void RCC_vidReset_FlexibleMemoryController(void)
{
	SET_BIT(RCC->AHB3RSTR,FMCRST);
}
				/*APB1*/
void RCC_vidReset_UART8 (void)
{
	SET_BIT(RCC->APB1RSTR,UART8RST);
}
void RCC_vidReset_UART7 (void)
{
	SET_BIT(RCC->APB1RSTR,UART7RST);
}
void RCC_vidReset_DAC (void)
{
	SET_BIT(RCC->APB1RSTR,DACRST);
}
void RCC_vidReset_PowerInterface (void)
{
	SET_BIT(RCC->APB1RSTR,PWRRST);
}
void RCC_vidReset_CAN2 (void)
{
	SET_BIT(RCC->APB1RSTR,CAN2RST);
}
void RCC_vidReset_CAN1 (void)
{
	SET_BIT(RCC->APB1RSTR,CAN1RST);
}
void RCC_vidReset_I2C3 (void)
{
	SET_BIT(RCC->APB1RSTR,I2C3RST);
}
void RCC_vidReset_I2C2 (void)
{
	SET_BIT(RCC->APB1RSTR,I2C2RST);
}
void RCC_vidReset_I2C1 (void)
{
	SET_BIT(RCC->APB1RSTR,I2C1RST);
}
void RCC_vidReset_UART5 (void)
{
	SET_BIT(RCC->APB1RSTR,UART5RST);
}
void RCC_vidReset_USART4 (void)
{
	SET_BIT(RCC->APB1RSTR,UART4RST);
}
void RCC_vidReset_USART3 (void)
{
	SET_BIT(RCC->APB1RSTR,USART3RST);
}
void RCC_vidReset_USART2 (void)
{
	SET_BIT(RCC->APB1RSTR,USART2RST);
}
void RCC_vidReset_SPI3 (void)
{
	SET_BIT(RCC->APB1RSTR,SPI3RST);
}
void RCC_vidReset_SPI2 (void)
{
	SET_BIT(RCC->APB1RSTR,SPI2RST);
}
void RCC_vidReset_WindowWatchdog (void)
{
	SET_BIT(RCC->APB1RSTR,WWDGRST);
}
void RCC_vidReset_TIMER14 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM14RST);
}
void RCC_vidReset_TIMER13 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM13RST);
}
void RCC_vidReset_TIMER12 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM12RST);
}
void RCC_vidReset_TIMER7 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM7RST);
}
void RCC_vidReset_TIMER6 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM6RST);
}
void RCC_vidReset_TIMER5 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM5RST);
}
void RCC_vidReset_TIMER4 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM4RST);
}
void RCC_vidReset_TIMER3 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM3RST);
}
void RCC_vidReset_TIMER2 (void)
{
	SET_BIT(RCC->APB1RSTR,TIM2RST);
}
				/*APB2*/
void RCC_vidReset_LTDC (void)
{
	SET_BIT(RCC->APB2RSTR,LTDCRST);
}
void RCC_vidReset_SAI1 (void)
{
	SET_BIT(RCC->APB2RSTR,SAI1RST);
}
void RCC_vidReset_SPI6 (void)
{
	SET_BIT(RCC->APB2RSTR,SPI6RST);
}
void RCC_vidReset_SPI5 (void)
{
	SET_BIT(RCC->APB2RSTR,SPI5RST);
}
void RCC_vidReset_TIMER11 (void)
{
	SET_BIT(RCC->APB2RSTR,TIM11RST);
}
void RCC_vidReset_TIMER10 (void)
{
	SET_BIT(RCC->APB2RSTR,TIM10RST);
}
void RCC_vidReset_TIMER9 (void)
{
	SET_BIT(RCC->APB2RSTR,TIM9RST);
}
void RCC_vidReset_SystemConfigurationController (void)
{
	SET_BIT(RCC->APB2RSTR,SYSCFGRST);
}
void RCC_vidReset_SPI4 (void)
{
	SET_BIT(RCC->APB2RSTR,SPI4RST);
}
void RCC_vidReset_SPI1 (void)
{
	SET_BIT(RCC->APB2RSTR,SPI1RST);
}
void RCC_vidReset_SDIO (void)
{
	SET_BIT(RCC->APB2RSTR,SDIORST);
}
void RCC_vidReset_ADC (void)
{
	SET_BIT(RCC->APB2RSTR,ADCRST);
}
void RCC_vidReset_USART6 (void)
{
	SET_BIT(RCC->APB2RSTR,USART6RST);
}
void RCC_vidReset_USART1 (void)
{
	SET_BIT(RCC->APB2RSTR,USART1RST);
}
void RCC_vidReset_TIMER8 (void)
{
	SET_BIT(RCC->APB2RSTR,TIM8RST);
}
void RCC_vidReset_TIMER1 (void)
{
	SET_BIT(RCC->APB2RSTR,TIM1RST);
}


/** Description	:								*/
/*			Enabling the Modules				*/
				/*AHB1*/
void RCC_Enable_USB_OTG_HS_ULPI (void)
{
	SET_BIT(RCC->AHB1ENR,OTGHSULPIEN);
}
void RCC_Enable_USB_OTG_HS (void)
{
	SET_BIT(RCC->AHB1ENR,OTGHSEN);
}
void RCC_Enable_EthernetPTP (void)
{
	SET_BIT(RCC->AHB1ENR,ETHMACPTPEN);
}
void RCC_Enable_EthernetReception (void)
{
	SET_BIT(RCC->AHB1ENR,ETHMACRXEN);
}
void RCC_Enable_EthernetTransmission (void)
{
	SET_BIT(RCC->AHB1ENR,ETHMACTXEN);
}
void RCC_Enable_EthernetMAC (void)
{
	SET_BIT(RCC->AHB1ENR,ETHMACEN);
}
void RCC_Enable_DMA2D (void)
{
	SET_BIT(RCC->AHB1ENR,DMA2DEN);
}
void RCC_Enable_DMA2 (void)
{
	SET_BIT(RCC->AHB1ENR,DMA2EN);
}
void RCC_Enable_DMA1 (void)
{
	SET_BIT(RCC->AHB1ENR,DMA1EN);
}
void RCC_Enable_CCM_Data_RAM (void)
{
	SET_BIT(RCC->AHB1ENR,CCMDATARAMEN);
}
void RCC_Enable_BackupSRAM (void)
{
	SET_BIT(RCC->AHB1ENR,BKPSRAMEN);
}
void RCC_Enable_CRC (void)
{
	SET_BIT(RCC->AHB1ENR,CRCEN);
}
void RCC_Enable_GPIO_A (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOAEN);
}
void RCC_Enable_GPIO_B (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOBEN);
}
void RCC_Enable_GPIO_C (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOCEN);
}
void RCC_Enable_GPIO_D (void)
{
	SET_BIT(RCC->AHB1ENR,GPIODEN);
}
void RCC_Enable_GPIO_E (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOEEN);
}
void RCC_Enable_GPIO_F (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOFEN);
}
void RCC_Enable_GPIO_G (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOGEN);
}
void RCC_Enable_GPIO_H (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOHEN);
}
void RCC_Enable_GPIO_I (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOIEN);
}
void RCC_Enable_GPIO_J (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOJEN);
}
void RCC_Enable_GPIO_K (void)
{
	SET_BIT(RCC->AHB1ENR,GPIOKEN);
}
			/*AHB2*/
void RCC_Enable_USB_OTG_FS (void)
{
	SET_BIT(RCC->AHB2ENR,OTGFSEN);
}
void RCC_Enable_RandomNumberGenerator (void)
{
	SET_BIT(RCC->AHB2ENR,RNGEN);
}
void RCC_Enable_Hash (void)
{
	SET_BIT(RCC->AHB2ENR,HASHEN);
}
void RCC_Enable_Cryptographic (void)
{
	SET_BIT(RCC->AHB2ENR,CRYPEN);
}
void RCC_Enable_CameraInterface (void)
{
	SET_BIT(RCC->AHB2ENR,DCMIEN);
}
			/*AHB3*/
void RCC_Enable_FlexibleMemoryController (void)
{
	SET_BIT(RCC->AHB3ENR,FMCEN);
}
			/*APB1*/
void RCC_Enable_UART8 (void)
{
	SET_BIT(RCC->APB1ENR,UART8EN);
}
void RCC_Enable_UART7 (void)
{
	SET_BIT(RCC->APB1ENR,UART7EN);
}
void RCC_Enable_DAC (void)
{
	SET_BIT(RCC->APB1ENR,DACEN);
}
void RCC_Enable_PowerInterface (void)
{
	SET_BIT(RCC->APB1ENR,PWREN);
}
void RCC_Enable_CAN2 (void)
{
	SET_BIT(RCC->APB1ENR,CAN2EN);
}
void RCC_Enable_CAN1 (void)
{
	SET_BIT(RCC->APB1ENR,CAN1EN);
}
void RCC_Enable_I2C3 (void)
{
	SET_BIT(RCC->APB1ENR,I2C3EN);
}
void RCC_Enable_I2C2 (void)
{
	SET_BIT(RCC->APB1ENR,I2C2EN);
}
void RCC_Enable_I2C1 (void)
{
	SET_BIT(RCC->APB1ENR,I2C1EN);
}
void RCC_Enable_UART5 (void)
{
	SET_BIT(RCC->APB1ENR,UART5EN);
}
void RCC_Enable_UART4 (void)
{
	SET_BIT(RCC->APB1ENR,UART4EN);
}
void RCC_Enable_USART3 (void)
{
	SET_BIT(RCC->APB1ENR,USART3EN);
}
void RCC_Enable_USART2 (void)
{
	SET_BIT(RCC->APB1ENR,USART2EN);
}
void RCC_Enable_SPI3 (void)
{
	SET_BIT(RCC->APB1ENR,SPI3EN);
}
void RCC_Enable_SPI2 (void)
{
	SET_BIT(RCC->APB1ENR,SPI2EN);
}
void RCC_Enable_WindowWatchdog (void)
{
	SET_BIT(RCC->APB1ENR,WWDGEN);
}
void RCC_Enable_TIMER14 (void)
{
	SET_BIT(RCC->APB1ENR,TIM14EN);
}
void RCC_Enable_TIMER13 (void)
{
	SET_BIT(RCC->APB1ENR,TIM13EN);
}
void RCC_Enable_TIMER12 (void)
{
	SET_BIT(RCC->APB1ENR,TIM12EN);
}
void RCC_Enable_TIMER7 (void)
{
	SET_BIT(RCC->APB1ENR,TIM7EN);
}
void RCC_Enable_TIMER6 (void)
{
	SET_BIT(RCC->APB1ENR,TIM6EN);
}
void RCC_Enable_TIMER5 (void)
{
	SET_BIT(RCC->APB1ENR,TIM5EN);
}
void RCC_Enable_TIMER4 (void)
{
	SET_BIT(RCC->APB1ENR,TIM4EN);
}
void RCC_Enable_TIMER3 (void)
{
	SET_BIT(RCC->APB1ENR,TIM3EN);
}
void RCC_Enable_TIMER2 (void)
{
	SET_BIT(RCC->APB1ENR,TIM2EN);
}
			/*APB2*/
void RCC_Enable_LTDC (void)
{
	SET_BIT(RCC->APB2ENR,LTDCEN);
}
void RCC_Enable_SAI1 (void)
{
	SET_BIT(RCC->APB2ENR,SAI1EN);
}
void RCC_Enable_SPI6 (void)
{
	SET_BIT(RCC->APB2ENR,SPI6EN);
}
void RCC_Enable_SPI5 (void)
{
	SET_BIT(RCC->APB2ENR,SPI5EN);
}
void RCC_Enable_TIMER11 (void)
{
	SET_BIT(RCC->APB2ENR,TIM11EN);
}
void RCC_Enable_TIMER10 (void)
{
	SET_BIT(RCC->APB2ENR,TIM10EN);
}
void RCC_Enable_TIMER9 (void)
{
	SET_BIT(RCC->APB2ENR,TIM9EN);
}
void RCC_Enable_SystemConfigurationcontroller (void)
{
	SET_BIT(RCC->APB2ENR,SYSCFGEN);
}
void RCC_Enable_SPI4 (void)
{
	SET_BIT(RCC->APB2ENR,SPI4EN);
}
void RCC_Enable_SPI1 (void)
{
	SET_BIT(RCC->APB2ENR,SPI1EN);
}
void RCC_Enable_SDIO (void)
{
	SET_BIT(RCC->APB2ENR,SDIOEN);
}
void RCC_Enable_ADC3 (void)
{
	SET_BIT(RCC->APB2ENR,ADC3EN);
}
void RCC_Enable_ADC2 (void)
{
	SET_BIT(RCC->APB2ENR,ADC2EN);
}
void RCC_Enable_ADC1 (void)
{
	SET_BIT(RCC->APB2ENR,ADC1EN);
}
void RCC_Enable_USART6 (void)
{
	SET_BIT(RCC->APB2ENR,USART6EN);
}
void RCC_Enable_USART1 (void)
{
	SET_BIT(RCC->APB2ENR,USART1EN);
}
void RCC_Enable_TIMER8 (void)
{
	SET_BIT(RCC->APB2ENR,TIM8EN);
}
void RCC_Enable_TIMER1 (void)
{
	SET_BIT(RCC->APB2ENR,TIM1EN);
}




/** Description	:								*/
/*			Disabling the Modules				*/
				/*AHB1*/
void RCC_Disable_USB_OTG_HS_ULPI (void)
{
	CLEAR_BIT(RCC->AHB1ENR,OTGHSULPIEN);
}
void RCC_Disable_USB_OTG_HS (void)
{
	CLEAR_BIT(RCC->AHB1ENR,OTGHSEN);
}
void RCC_Disable_EthernetPTP (void)
{
	CLEAR_BIT(RCC->AHB1ENR,ETHMACPTPEN);
}
void RCC_Disable_EthernetReception (void)
{
	CLEAR_BIT(RCC->AHB1ENR,ETHMACRXEN);
}
void RCC_Disable_EthernetTransmission (void)
{
	CLEAR_BIT(RCC->AHB1ENR,ETHMACTXEN);
}
void RCC_Disable_EthernetMAC (void)
{
	CLEAR_BIT(RCC->AHB1ENR,ETHMACEN);
}
void RCC_Disable_DMA2D (void)
{
	CLEAR_BIT(RCC->AHB1ENR,DMA2DEN);
}
void RCC_Disable_DMA2 (void)
{
	CLEAR_BIT(RCC->AHB1ENR,DMA2EN);
}
void RCC_Disable_DMA1 (void)
{
	CLEAR_BIT(RCC->AHB1ENR,DMA1EN);
}
void RCC_Disable_CCM_Data_RAM (void)
{
	CLEAR_BIT(RCC->AHB1ENR,CCMDATARAMEN);
}
void RCC_Disable_BackupSRAM (void)
{
	CLEAR_BIT(RCC->AHB1ENR,BKPSRAMEN);
}
void RCC_Disable_CRC (void)
{
	CLEAR_BIT(RCC->AHB1ENR,CRCEN);
}
void RCC_Disable_GPIO_A (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOAEN);
}
void RCC_Disable_GPIO_B (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOBEN);
}
void RCC_Disable_GPIO_C (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOCEN);
}
void RCC_Disable_GPIO_D (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIODEN);
}
void RCC_Disable_GPIO_E (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOEEN);
}
void RCC_Disable_GPIO_F (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOFEN);
}
void RCC_Disable_GPIO_G (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOGEN);
}
void RCC_Disable_GPIO_H (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOHEN);
}
void RCC_Disable_GPIO_I (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOIEN);
}
void RCC_Disable_GPIO_J (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOJEN);
}
void RCC_Disable_GPIO_K (void)
{
	CLEAR_BIT(RCC->AHB1ENR,GPIOKEN);
}
			/*AHB2*/
void RCC_Disable_USB_OTG_FS (void)
{
	CLEAR_BIT(RCC->AHB2ENR,OTGFSEN);
}
void RCC_Disable_RandomNumberGenerator (void)
{
	CLEAR_BIT(RCC->AHB2ENR,RNGEN);
}
void RCC_Disable_Hash (void)
{
	CLEAR_BIT(RCC->AHB2ENR,HASHEN);
}
void RCC_Disable_Cryptographic (void)
{
	CLEAR_BIT(RCC->AHB2ENR,CRYPEN);
}
void RCC_Disable_CameraInterface (void)
{
	CLEAR_BIT(RCC->AHB2ENR,DCMIEN);
}
			/*AHB3*/
void RCC_Disable_FlexibleMemoryController (void)
{
	CLEAR_BIT(RCC->AHB3ENR,FMCEN);
}
			/*APB1*/
void RCC_Disable_UART8 (void)
{
	CLEAR_BIT(RCC->APB1ENR,UART8EN);
}
void RCC_Disable_UART7 (void)
{
	CLEAR_BIT(RCC->APB1ENR,UART7EN);
}
void RCC_Disable_DAC (void)
{
	CLEAR_BIT(RCC->APB1ENR,DACEN);
}
void RCC_Disable_PowerInterface (void)
{
	CLEAR_BIT(RCC->APB1ENR,PWREN);
}
void RCC_Disable_CAN2 (void)
{
	CLEAR_BIT(RCC->APB1ENR,CAN2EN);
}
void RCC_Disable_CAN1 (void)
{
	CLEAR_BIT(RCC->APB1ENR,CAN1EN);
}
void RCC_Disable_I2C3 (void)
{
	CLEAR_BIT(RCC->APB1ENR,I2C3EN);
}
void RCC_Disable_I2C2 (void)
{
	CLEAR_BIT(RCC->APB1ENR,I2C2EN);
}
void RCC_Disable_I2C1 (void)
{
	CLEAR_BIT(RCC->APB1ENR,I2C1EN);
}
void RCC_Disable_UART5 (void)
{
	CLEAR_BIT(RCC->APB1ENR,UART5EN);
}
void RCC_Disable_UART4 (void)
{
	CLEAR_BIT(RCC->APB1ENR,UART4EN);
}
void RCC_Disable_USART3 (void)
{
	CLEAR_BIT(RCC->APB1ENR,USART3EN);
}
void RCC_Disable_USART2 (void)
{
	CLEAR_BIT(RCC->APB1ENR,USART2EN);
}
void RCC_Disable_SPI3 (void)
{
	CLEAR_BIT(RCC->APB1ENR,SPI3EN);
}
void RCC_Disable_SPI2 (void)
{
	CLEAR_BIT(RCC->APB1ENR,SPI2EN);
}
void RCC_Disable_WindowWatchdog (void)
{
	CLEAR_BIT(RCC->APB1ENR,WWDGEN);
}
void RCC_Disable_TIMER14 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM14EN);
}
void RCC_Disable_TIMER13 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM13EN);
}
void RCC_Disable_TIMER12 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM12EN);
}
void RCC_Disable_TIMER7 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM7EN);
}
void RCC_Disable_TIMER6 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM6EN);
}
void RCC_Disable_TIMER5 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM5EN);
}
void RCC_Disable_TIMER4 (void)
{
	CLEAR_BIT(RCC->APB1LPENR,TIM4EN);
}
void RCC_Disable_TIMER3 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM3EN);
}
void RCC_Disable_TIMER2 (void)
{
	CLEAR_BIT(RCC->APB1ENR,TIM2EN);
}
			/*APB2*/
void RCC_Disable_LTDC (void)
{
	CLEAR_BIT(RCC->APB2ENR,LTDCEN);
}
void RCC_Disable_SAI1 (void)
{
	CLEAR_BIT(RCC->APB2ENR,SAI1EN);
}
void RCC_Disable_SPI6 (void)
{
	CLEAR_BIT(RCC->APB2ENR,SPI6EN);
}
void RCC_Disable_SPI5 (void)
{
	CLEAR_BIT(RCC->APB2ENR,SPI5EN);
}
void RCC_Disable_TIMER11 (void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM11EN);
}
void RCC_Disable_TIMER10 (void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM10EN);
}
void RCC_Disable_TIMER9 (void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM9EN);
}
void RCC_Disable_SystemConfigurationcontroller (void)
{
	CLEAR_BIT(RCC->APB2ENR,SYSCFGEN);
}
void RCC_Disable_SPI4 (void)
{
	CLEAR_BIT(RCC->APB2ENR,SPI4EN);
}
void RCC_Disable_SPI1 (void)
{
	CLEAR_BIT(RCC->APB2ENR,SPI1EN);
}
void RCC_Disable_SDIO (void)
{
	CLEAR_BIT(RCC->APB2ENR,SDIOEN);
}
void RCC_Disable_ADC3 (void)
{
	CLEAR_BIT(RCC->APB2ENR,ADC3EN);
}
void RCC_Disable_ADC2 (void)
{
	CLEAR_BIT(RCC->APB2ENR,ADC2EN);
}
void RCC_Disable_ADC1 (void)
{
	CLEAR_BIT(RCC->APB2ENR,ADC1EN);
}
void RCC_Disable_USART6 (void)
{
	CLEAR_BIT(RCC->APB2ENR,USART6EN);
}
void RCC_Disable_USART1 (void)
{
	CLEAR_BIT(RCC->APB2ENR,USART1EN);
}
void RCC_Disable_TIMER8 (void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM8EN);
}
void RCC_Disable_TIMER1 (void)
{
	CLEAR_BIT(RCC->APB2ENR,TIM1EN);
}





/** Description	:								*/
/*			Enabling the Modules in Low Power	*/
				/*AHB1*/
void RCC_EnableLowPower_USB_OTG_HS_ULPI (void)
{
	SET_BIT(RCC->AHB1LPENR,OTGHSULPIEN);
}
void RCC_EnableLowPower_USB_OTG_HS (void)
{
	SET_BIT(RCC->AHB1LPENR,OTGHSEN);
}
void RCC_EnableLowPower_EthernetPTP (void)
{
	SET_BIT(RCC->AHB1LPENR,ETHMACPTPEN);
}
void RCC_EnableLowPower_EthernetReception (void)
{
	SET_BIT(RCC->AHB1LPENR,ETHMACRXEN);
}
void RCC_EnableLowPower_EthernetTransmission (void)
{
	SET_BIT(RCC->AHB1LPENR,ETHMACTXEN);
}
void RCC_EnableLowPower_EthernetMAC (void)
{
	SET_BIT(RCC->AHB1LPENR,ETHMACEN);
}
void RCC_EnableLowPower_DMA2D (void)
{
	SET_BIT(RCC->AHB1LPENR,DMA2DEN);
}
void RCC_EnableLowPower_DMA2 (void)
{
	SET_BIT(RCC->AHB1LPENR,DMA2EN);
}
void RCC_EnableLowPower_DMA1 (void)
{
	SET_BIT(RCC->AHB1LPENR,DMA1EN);
}
void RCC_EnableLowPower_SRAM3Interface (void)
{
	SET_BIT(RCC->AHB1LPENR,SRAM3LPEN);
}
void RCC_EnableLowPower_SRAM2Interface (void)
{
	SET_BIT(RCC->AHB1LPENR,SRAM2LPEN);
}
void RCC_EnableLowPower_SRAM1Interface (void)
{
	SET_BIT(RCC->AHB1LPENR,SRAM1LPEN);
}
void RCC_EnableLowPower_FlashInterface (void)
{
	SET_BIT(RCC->AHB1LPENR,FLITFLPEN);
}
void RCC_EnableLowPower_BackupSRAM (void)
{
	SET_BIT(RCC->AHB1LPENR,BKPSRAMEN);
}
void RCC_EnableLowPower_CRC (void)
{
	SET_BIT(RCC->AHB1LPENR,CRCEN);
}
void RCC_EnableLowPower_GPIO_A (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOAEN);
}
void RCC_EnableLowPower_GPIO_B (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOBEN);
}
void RCC_EnableLowPower_GPIO_C (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOCEN);
}
void RCC_EnableLowPower_GPIO_D (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIODEN);
}
void RCC_EnableLowPower_GPIO_E (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOEEN);
}
void RCC_EnableLowPower_GPIO_F (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOFEN);
}
void RCC_EnableLowPower_GPIO_G (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOGEN);
}
void RCC_EnableLowPower_GPIO_H (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOHEN);
}
void RCC_EnableLowPower_GPIO_I (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOIEN);
}
void RCC_EnableLowPower_GPIO_J (void)
{
	SET_BIT(RCC->AHB1LPENR,GPIOJEN);
}
void RCC_EnableLowPower_GPIO_K (void)
{
	SET_BIT(RCC->AHB2LPENR,GPIOKEN);
}
			/*AHB2*/
void RCC_EnableLowPower_USB_OTG_FS (void)
{
	SET_BIT(RCC->AHB2LPENR,OTGFSEN);
}
void RCC_EnableLowPower_RandomNumberGenerator (void)
{
	SET_BIT(RCC->AHB2LPENR,RNGEN);
}
void RCC_EnableLowPower_Hash (void)
{
	SET_BIT(RCC->AHB2LPENR,HASHEN);
}
void RCC_EnableLowPower_Cryptographic (void)
{
	SET_BIT(RCC->AHB2LPENR,CRYPEN);
}
void RCC_EnableLowPower_CameraInterface (void)
{
	SET_BIT(RCC->AHB2LPENR,DCMIEN);
}
			/*AHB3*/
void RCC_EnableLowPower_FlexibleMemoryController (void)
{
	SET_BIT(RCC->AHB3LPENR,FMCEN);
}
			/*APB1*/
void RCC_EnableLowPower_UART8 (void)
{
	SET_BIT(RCC->APB1LPENR,UART8EN);
}
void RCC_EnableLowPower_UART7 (void)
{
	SET_BIT(RCC->APB1LPENR,UART7EN);
}
void RCC_EnableLowPower_DAC (void)
{
	SET_BIT(RCC->APB1LPENR,DACEN);
}
void RCC_EnableLowPower_PowerInterface (void)
{
	SET_BIT(RCC->APB1LPENR,PWREN);
}
void RCC_EnableLowPower_CAN2 (void)
{
	SET_BIT(RCC->APB1LPENR,CAN2EN);
}
void RCC_EnableLowPower_CAN1 (void)
{
	SET_BIT(RCC->APB1LPENR,CAN1EN);
}
void RCC_EnableLowPower_I2C3 (void)
{
	SET_BIT(RCC->APB1LPENR,I2C3EN);
}
void RCC_EnableLowPower_I2C2 (void)
{
	SET_BIT(RCC->APB1LPENR,I2C2EN);
}
void RCC_EnableLowPower_I2C1 (void)
{
	SET_BIT(RCC->APB1LPENR,I2C1EN);
}
void RCC_EnableLowPower_UART5 (void)
{
	SET_BIT(RCC->APB1LPENR,UART5EN);
}
void RCC_EnableLowPower_UART4 (void)
{
	SET_BIT(RCC->APB1LPENR,UART4EN);
}
void RCC_EnableLowPower_USART3 (void)
{
	SET_BIT(RCC->APB1LPENR,USART3EN);
}
void RCC_EnableLowPower_USART2 (void)
{
	SET_BIT(RCC->APB1LPENR,USART2EN);
}
void RCC_EnableLowPower_SPI3 (void)
{
	SET_BIT(RCC->APB1LPENR,SPI3EN);
}
void RCC_EnableLowPower_SPI2 (void)
{
	SET_BIT(RCC->APB1LPENR,SPI2EN);
}
void RCC_EnableLowPower_WindowWatchdog (void)
{
	SET_BIT(RCC->APB1LPENR,WWDGEN);
}
void RCC_EnableLowPower_TIMER14 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM14EN);
}
void RCC_EnableLowPower_TIMER13 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM13EN);
}
void RCC_EnableLowPower_TIMER12 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM12EN);
}
void RCC_EnableLowPower_TIMER7 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM7EN);
}
void RCC_EnableLowPower_TIMER6 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM6EN);
}
void RCC_EnableLowPower_TIMER5 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM5EN);
}
void RCC_EnableLowPower_TIMER4 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM4EN);
}
void RCC_EnableLowPower_TIMER3 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM3EN);
}
void RCC_EnableLowPower_TIMER2 (void)
{
	SET_BIT(RCC->APB1LPENR,TIM2EN);
}
			/*APB2*/
void RCC_EnableLowPower_LTDC (void)
{
	SET_BIT(RCC->APB2LPENR,LTDCEN);
}
void RCC_EnableLowPower_SAI1 (void)
{
	SET_BIT(RCC->APB2LPENR,SAI1EN);
}
void RCC_EnableLowPower_SPI6 (void)
{
	SET_BIT(RCC->APB2LPENR,SPI6EN);
}
void RCC_EnableLowPower_SPI5 (void)
{
	SET_BIT(RCC->APB2LPENR,SPI5EN);
}
void RCC_EnableLowPower_TIMER11 (void)
{
	SET_BIT(RCC->APB2LPENR,TIM11EN);
}
void RCC_EnableLowPower_TIMER10 (void)
{
	SET_BIT(RCC->APB2LPENR,TIM10EN);
}
void RCC_EnableLowPower_TIMER9 (void)
{
	SET_BIT(RCC->APB2LPENR,TIM9EN);
}
void RCC_EnableLowPower_SystemConfigurationcontroller (void)
{
	SET_BIT(RCC->APB2LPENR,SYSCFGEN);
}
void RCC_EnableLowPower_SPI4 (void)
{
	SET_BIT(RCC->APB2LPENR,SPI4EN);
}
void RCC_EnableLowPower_SPI1 (void)
{
	SET_BIT(RCC->APB2LPENR,SPI1EN);
}
void RCC_EnableLowPower_SDIO (void)
{
	SET_BIT(RCC->APB2LPENR,SDIOEN);
}
void RCC_EnableLowPower_ADC3 (void)
{
	SET_BIT(RCC->APB2LPENR,ADC3EN);
}
void RCC_EnableLowPower_ADC2 (void)
{
	SET_BIT(RCC->APB2LPENR,ADC2EN);
}
void RCC_EnableLowPower_ADC1 (void)
{
	SET_BIT(RCC->APB2LPENR,ADC1EN);
}
void RCC_EnableLowPower_USART6 (void)
{
	SET_BIT(RCC->APB2LPENR,USART6EN);
}
void RCC_EnableLowPower_USART1 (void)
{
	SET_BIT(RCC->APB2LPENR,USART1EN);
}
void RCC_EnableLowPower_TIMER8 (void)
{
	SET_BIT(RCC->APB2LPENR,TIM8EN);
}
void RCC_EnableLowPower_TIMER1 (void)
{
	SET_BIT(RCC->APB2LPENR,TIM1EN);
}
