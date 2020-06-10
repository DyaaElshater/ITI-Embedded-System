/************************************************/
/* Name			: Dyaa Elshater					*/
/* Date			: 25/12/2019					*/
/* Description	: GPIO Private File				*/
/* MCU			: STM32F429ZIT60				*/
/* Vendor		: BEDO Innovation Education		*/
/* Version		: 1.0 V							*/
/************************************************/

#ifndef GPIO_PRIV_H_
#define GPIO_PRIV_H_

	/*Register Bits*/
		/*Mode*/
#define GPIO_INPUT_MODE		0
#define GPIO_OUTPUT_MODE	1
#define GPIO_AF_mode		2
#define GPIO_Analog_mode	3

		/*Output Type*/
#define GPIO_OTP_PUSH_POLL	0
#define GPIO_OTP_OPEN_DRAIN	1

		/*Speed*/
#define GPIO_LOW_SPEED			0
#define GPIO_MEDIOM_SPEED		1
#define GPIO_HIGH_SPEED			2
#define GPIO_VERY_HIGH_SPEED	3

		/*Pull Up / Down*/
#define GPIO_NO_PU_PD			0
#define GPIO_PULL_UP			1
#define GPIO_PULL_DOWN			2


#endif /* GPIO_PRIV_H_ */
