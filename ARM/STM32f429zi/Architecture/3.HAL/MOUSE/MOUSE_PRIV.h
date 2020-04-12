/***********************************************************/
/* Name          : Dyaa Elshater                           */
/* Date          : 22/12/2019                              */
/* Deswcription  : Mouse Private File                      */
/* Version       : 1.0 V                                   */
/***********************************************************/

#ifndef _MOUSE_PRIV_H_
#define _MOUSE_PRIV_H_

#ifndef  MOUSE_X_STEP
#define MOUSE_X_STEP         (2)
#endif

#ifndef  MOUSE_Y_STEP
#define MOUSE_Y_STEP         (2)
#endif

#ifndef  MOUSE_LEFT_BUTTON_PORT
#define MOUSE_LEFT_BUTTON_PORT       DIO_PORTA
#endif

#ifndef  MOUSE_LEFT_BUTTON_PIN
#define MOUSE_LEFT_BUTTON_PIN         DIO_RA0
#endif

#ifndef  MOUSE_RIGHT_BUTTON_PORT
#define MOUSE_RIGHT_BUTTON_PORT       DIO_PORTA
#endif

#ifndef  MOUSE_RIGHT_BUTTON_PIN
#define MOUSE_RIGHT_BUTTON_PIN         DIO_RA1
#endif

#ifndef  MOUSE_LEFT_DIRECTION_PORT
#define MOUSE_LEFT_DIRECTION_PORT       DIO_PORTA
#endif

#ifndef  MOUSE_LEFT_DIRECTION_PIN
#define MOUSE_LEFT_DIRECTION_PIN         DIO_RA2
#endif

#ifndef  MOUSE_RIGHT_DIRECTION_PORT
#define MOUSE_RIGHT_DIRECTION_PORT       DIO_PORTA
#endif

#ifndef  MOUSE_RIGHT_DIRECTION_PIN
#define MOUSE_RIGHT_DIRECTION_PIN         DIO_RA3
#endif

#define BUTTON_INDEX      (0)
#define X_INDEX           (1)
#define Y_INDEX           (2)

#define REPORT_SIZE      (4)


#define MOUSE_DELAYS	(50)

static  int8_t   arrS8MouseReport [REPORT_SIZE]  = {0} ;
extern USBD_HandleTypeDef hUsbDeviceFS;




#endif
