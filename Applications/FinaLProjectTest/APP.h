/*
 * APP.h
 *
 *  Created on: Aug 5, 2019
 *      Author: Dyaa Elshater
 */

#ifndef APP_H_
#define APP_H_

/****************************************/
/*
void Blink_Red		(void);
void Blink_Green	(void);
void Blink_Yellow	(void);
void Send_Uart		(void);
void Update			(void);
void send_LCD		(void);
*/
/*****************************************/

#define GREEN	 DIO_u8PIN_2
#define YELLOW	 DIO_u8PIN_1
#define RED		 DIO_u8PIN_0

void POV_UpdateLeds (void);

#endif /* APP_H_ */
