/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 23/12/2019					*/
/* Description	: RCC Configuration File		*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#ifndef RCC_CFG_H_
#define RCC_CFG_H_


/************************************************/
	/*	Configure the enabled peripheral Clock	*/
	/* By defining it as :						*/
	/*						- RCC_ENABLE		*/
	/*						- RCC_DISABLE		*/

			/*GPIO*/
#define	IO_port_K_EN				RCC_DISABLE
#define	IO_port_J_EN				RCC_DISABLE
#define	IO_port_I_EN				RCC_DISABLE
#define	IO_port_H_EN				RCC_DISABLE
#define	IO_port_G_EN				RCC_DISABLE
#define	IO_port_F_EN				RCC_DISABLE
#define	IO_port_E_EN				RCC_DISABLE
#define	IO_port_D_EN				RCC_DISABLE
#define	IO_port_C_EN				RCC_DISABLE
#define	IO_port_B_EN				RCC_DISABLE
#define	IO_port_A_EN				RCC_DISABLE

			/*Communication Protocols*/
				/*UART*/
#define UART8_EN					RCC_DISABLE
#define UART7_EN					RCC_DISABLE
#define USART6_EN					RCC_DISABLE
#define UART5_EN					RCC_DISABLE
#define UART4_EN					RCC_DISABLE
#define USART3_EN					RCC_DISABLE
#define USART2_EN					RCC_DISABLE
#define USART1_EN					RCC_DISABLE
				/*SPI*/
#define SPI6_EN						RCC_DISABLE
#define SPI5_EN						RCC_DISABLE
#define SPI4_EN						RCC_DISABLE
#define SPI3_EN						RCC_DISABLE
#define SPI2_EN						RCC_DISABLE
#define SPI1_EN						RCC_DISABLE
				/*I2C*/
#define I2C3_EN						RCC_DISABLE
#define I2C2_EN						RCC_DISABLE
#define I2C1_EN						RCC_DISABLE
				/*CAN*/
#define CAN2_EN						RCC_DISABLE
#define CAN1_EN						RCC_DISABLE

			/*Timers*/
#define TIMER14_EN					RCC_DISABLE
#define TIMER13_EN					RCC_DISABLE
#define TIMER12_EN					RCC_DISABLE
#define TIMER11_EN					RCC_DISABLE
#define TIMER10_EN					RCC_DISABLE
#define TIMER9_EN					RCC_DISABLE
#define TIMER8_EN					RCC_DISABLE
#define TIMER7_EN					RCC_DISABLE
#define TIMER6_EN					RCC_DISABLE
#define TIMER5_EN					RCC_DISABLE
#define TIMER4_EN					RCC_DISABLE
#define TIMER3_EN					RCC_DISABLE
#define TIMER2_EN					RCC_DISABLE
#define TIMER1_EN					RCC_DISABLE

			/*ADC*/
#define ADC3_EN						RCC_DISABLE
#define ADC2_EN						RCC_DISABLE
#define ADC1_EN						RCC_DISABLE

			/*DAC*/
#define DAC_EN						RCC_DISABLE

			/*DMA*/
#define	DMA2D_clock_EN				RCC_DISABLE
#define	DMA2_EN						RCC_DISABLE
#define	DMA1_EN						RCC_DISABLE

			/*USB*/
#define	USB_OTG_HS_ULPI_EN			RCC_DISABLE
#define	USB_OTG_HS_EN				RCC_DISABLE
#define	USB_OTG_FS_EN				RCC_DISABLE

			/*Ethernet*/
#define	Ethernet_PTP_EN				RCC_DISABLE
#define	Ethernet_Reception_EN		RCC_DISABLE
#define	Ethernet_Transmission_EN	RCC_DISABLE
#define	Ethernet_MAC_EN				RCC_DISABLE

			/*Others*/
#define	CCM_Data_RAM_EN				RCC_DISABLE
#define	Backup_SRAM_EN				RCC_DISABLE
#define	CRC_EN						RCC_DISABLE
#define	Random_Number_Generator_EN	RCC_DISABLE
#define	Hash_Modules_EN				RCC_DISABLE
#define	Cryptographic_Module_EN		RCC_DISABLE
#define	Camera_Interface_EN			RCC_DISABLE
#define FMC_Module_EN				RCC_DISABLE
#define Power_EN					RCC_DISABLE
#define Window_watchdog_EN			RCC_DISABLE
#define SAI1_EN						RCC_DISABLE
#define LTDC_EN						RCC_DISABLE
#define System_Configuration_EN		RCC_DISABLE
#define SDIO_EN						RCC_DISABLE

/************************************************/









/************************************************/
	/*	Configure the enabled peripheral Clock	*/
	/*			In Low Power Mode (Sleep Mode)	*/
	/* By defining it as :						*/
	/*						- RCC_ENABLE		*/
	/*						- RCC_DISABLE		*/

			/*GPIO*/
#define	IO_port_K_LP_EN					RCC_DISABLE
#define	IO_port_J_LP_EN					RCC_DISABLE
#define	IO_port_I_LP_EN					RCC_DISABLE
#define	IO_port_H_LP_EN					RCC_DISABLE
#define	IO_port_G_LP_EN					RCC_DISABLE
#define	IO_port_F_LP_EN					RCC_DISABLE
#define	IO_port_E_LP_EN					RCC_DISABLE
#define	IO_port_D_LP_EN					RCC_DISABLE
#define	IO_port_C_LP_EN					RCC_DISABLE
#define	IO_port_B_LP_EN					RCC_DISABLE
#define	IO_port_A_LP_EN					RCC_DISABLE

			/*Communication Protocols*/
				/*UART*/
#define UART8_LP_EN						RCC_DISABLE
#define UART7_LP_EN						RCC_DISABLE
#define USART6_LP_EN					RCC_DISABLE
#define UART5_LP_EN						RCC_DISABLE
#define UART4_LP_EN						RCC_DISABLE
#define USART3_LP_EN					RCC_DISABLE
#define USART2_LP_EN					RCC_DISABLE
#define USART1_LP_EN					RCC_DISABLE
				/*SPI*/
#define SPI6_LP_EN						RCC_DISABLE
#define SPI5_LP_EN						RCC_DISABLE
#define SPI4_LP_EN						RCC_DISABLE
#define SPI3_LP_EN						RCC_DISABLE
#define SPI2_LP_EN						RCC_DISABLE
#define SPI1_LP_EN						RCC_DISABLE
				/*I2C*/
#define I2C3_LP_EN						RCC_DISABLE
#define I2C2_LP_EN						RCC_DISABLE
#define I2C1_LP_EN						RCC_DISABLE
				/*CAN*/
#define CAN2_LP_EN						RCC_DISABLE
#define CAN1_LP_EN						RCC_DISABLE

			/*Timers*/
#define TIMER14_LP_EN					RCC_DISABLE
#define TIMER13_LP_EN					RCC_DISABLE
#define TIMER12_LP_EN					RCC_DISABLE
#define TIMER11_LP_EN					RCC_DISABLE
#define TIMER10_LP_EN					RCC_DISABLE
#define TIMER9_LP_EN					RCC_DISABLE
#define TIMER8_LP_EN					RCC_DISABLE
#define TIMER7_LP_EN					RCC_DISABLE
#define TIMER6_LP_EN					RCC_DISABLE
#define TIMER5_LP_EN					RCC_DISABLE
#define TIMER4_LP_EN					RCC_DISABLE
#define TIMER3_LP_EN					RCC_DISABLE
#define TIMER2_LP_EN					RCC_DISABLE
#define TIMER1_LP_EN					RCC_DISABLE

			/*ADC*/
#define ADC3_LP_EN						RCC_DISABLE
#define ADC2_LP_EN						RCC_DISABLE
#define ADC1_LP_EN						RCC_DISABLE

			/*DAC*/
#define DAC_LP_EN						RCC_DISABLE

			/*DMA*/
#define	DMA2D_clock_LP_EN				RCC_DISABLE
#define	DMA2_LP_EN						RCC_DISABLE
#define	DMA1_LP_EN						RCC_DISABLE

			/*USB*/
#define	USB_OTG_HS_ULPI_LP_EN			RCC_DISABLE
#define	USB_OTG_HS_LP_EN				RCC_DISABLE
#define	USB_OTG_FS_LP_EN				RCC_DISABLE

			/*Ethernet*/
#define	Ethernet_PTP_LP_EN				RCC_DISABLE
#define	Ethernet_Reception_LP_EN		RCC_DISABLE
#define	Ethernet_Transmission_LP_EN		RCC_DISABLE
#define	Ethernet_MAC_LP_EN				RCC_DISABLE

			/*Others*/
#define	Backup_SRAM_LP_EN				RCC_DISABLE
#define	CRC_LP_EN						RCC_DISABLE
#define	Random_Number_Generator_LP_EN	RCC_DISABLE
#define	Hash_Modules_LP_EN				RCC_DISABLE
#define	Cryptographic_Module_LP_EN		RCC_DISABLE
#define	Camera_Interface_LP_EN			RCC_DISABLE
#define FMC_Module_LP_EN				RCC_DISABLE
#define Power_LP_EN						RCC_DISABLE
#define Window_watchdog_LP_EN			RCC_DISABLE
#define SAI1_LP_EN						RCC_DISABLE
#define LTDC_LP_EN						RCC_DISABLE
#define System_Configuration_LP_EN		RCC_DISABLE
#define SDIO_LP_EN						RCC_DISABLE
#define SRAM1_Interface_LP_EN			RCC_DISABLE
#define SRAM2_Interface_LP_EN			RCC_DISABLE
#define SRAM3_Interface_LP_EN			RCC_DISABLE
#define Flash_Interface_LP_EN			RCC_DISABLE
/************************************************/


#endif /* RCC_CFG_H_ */
