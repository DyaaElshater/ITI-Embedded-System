/***********************************************************/
/* Name          : Dyaa Elshater                           */
/* Date          : 22/12/2019                              */
/* Deswcription  : Mouse Implementation File               */
/* Version       : 1.0 V                                   */
/***********************************************************/


  /*MCAL Files*/
#include "usb_device.h"
/*include USB*/

  /*Mouse Files in HAL*/
#include "MOUSE_INT.h"
#include "MOUSE_CFG.h"
#include "MOUSE_PRIv.h"

    /** Description :                                */
    /*     Used for Interrupt                        */

/** Description  :                             */
/*           For initializing the Mouse        */
void MOUSE_VidInit()
{
	  MX_USB_DEVICE_Init();
}


      /** Description :                        */
      /* For moving the mouse pointer manually */
      /* Without using the pins configured in  */
      /* configuration file                    */
void  MOUSE_vidMovePointer_UP()
{
	arrS8MouseReport[BUTTON_INDEX]=0;
	arrS8MouseReport[X_INDEX]=0;
                 /*assign Y movement */
	arrS8MouseReport[Y_INDEX]= - MOUSE_Y_STEP;
                 /* Send Data        */
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
    HAL_Delay(MOUSE_DELAYS);

}
void  MOUSE_vidMovePointer_DOWN()
{
	arrS8MouseReport[BUTTON_INDEX]=0;
	arrS8MouseReport[X_INDEX]=0;
                /*assign Y movement */
	arrS8MouseReport[Y_INDEX]=  MOUSE_Y_STEP;
                 /* Send Data        */
               USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
               HAL_Delay(MOUSE_DELAYS);
}

void  MOUSE_vidMovePointer_RIGHT()
{
	arrS8MouseReport[BUTTON_INDEX]=0;
                /*assign X movement */
	arrS8MouseReport[X_INDEX]=  MOUSE_X_STEP;
	arrS8MouseReport[Y_INDEX]=0;
                 /* Send Data        */
               USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
               HAL_Delay(MOUSE_DELAYS);
}
void  MOUSE_vidMovePointer_LEFT()
{
				arrS8MouseReport[BUTTON_INDEX]=0;
                /*assign X movement */
               arrS8MouseReport[X_INDEX]= - MOUSE_X_STEP;
               arrS8MouseReport[Y_INDEX]=0;
                 /* Send Data        */
               USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
               HAL_Delay(MOUSE_DELAYS);
}



      /** Description :                          */
      /* For Pressing the mouse buttons manually */
      /* Without using the pins configured in    */
      /* configuration file                      */
void MOUSE_vidPressButton_RIGHT()
{
                /*assign Button State */
	arrS8MouseReport[BUTTON_INDEX]=0x02;
	arrS8MouseReport[X_INDEX]= 0;
	arrS8MouseReport[Y_INDEX]=0;
                 /* Send Data        */
               USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
               HAL_Delay(MOUSE_DELAYS);
               MOUSE_vidRelease();
}
void MOUSE_vidPressButton_LEFT()
{

                /*assign Button State */
	arrS8MouseReport[BUTTON_INDEX]=0x01;
	arrS8MouseReport[X_INDEX]= 0;
	arrS8MouseReport[Y_INDEX]=0;
                 /* Send Data        */
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);

//    HAL_Delay(MOUSE_DELAYS);
//    MOUSE_vidRelease();
}

void MOUSE_vidRelease(void)
{
	arrS8MouseReport[BUTTON_INDEX]=0;
	arrS8MouseReport[X_INDEX]= 0;
	arrS8MouseReport[Y_INDEX]=0;
				   /* Send Data        */
	USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
	HAL_Delay(MOUSE_DELAYS);

}

void MOUSE_vidLeftPreesedWithMove_Right()
{
	arrS8MouseReport[BUTTON_INDEX]=0x01;
	arrS8MouseReport[X_INDEX]= MOUSE_X_STEP;
	arrS8MouseReport[Y_INDEX]=0;
                 /* Send Data        */
   USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
   HAL_Delay(MOUSE_DELAYS);


}

void MOUSE_vidLeftPreesedWithMove_Left()
{
	arrS8MouseReport[BUTTON_INDEX]=0x01;
	arrS8MouseReport[X_INDEX]= -MOUSE_X_STEP;
	arrS8MouseReport[Y_INDEX]=0;
                 /* Send Data        */
   USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
   HAL_Delay(MOUSE_DELAYS);


}

void MOUSE_vidLeftPreesedWithMove_Up()
{
	arrS8MouseReport[BUTTON_INDEX]=0x01;
	arrS8MouseReport[X_INDEX]= 0;
	arrS8MouseReport[Y_INDEX]=- MOUSE_Y_STEP;
                 /* Send Data        */
   USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
   HAL_Delay(MOUSE_DELAYS);


}

void MOUSE_vidLeftPreesedWithMove_Down()
{
	arrS8MouseReport[BUTTON_INDEX]=0x01;
	arrS8MouseReport[X_INDEX]= 0;
	arrS8MouseReport[Y_INDEX]= MOUSE_Y_STEP;
                 /* Send Data        */
   USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
   HAL_Delay(MOUSE_DELAYS);


}

/** X : +ve -> Right
 * 	  : -ve -> LEFT
 *
 ** Y : +ve	-> Down
 *    : -ve	-> Up								*/
/**		u8ButtonCpy = 							*/
/*						LEFT					*/
/*						RIGHT					*/

void MOUSE_vidCustom(int8_t u8XCpy,int8_t u8YCpy,enuButtonState u8ButtonCpy)
{
	u8XCpy = (u8XCpy==0)? 0 : (u8XCpy>0)? MOUSE_X_STEP: -MOUSE_X_STEP ;
	u8YCpy = (u8YCpy==0)? 0 : (u8YCpy>0)? MOUSE_Y_STEP: -MOUSE_Y_STEP ;

	arrS8MouseReport[BUTTON_INDEX]=u8ButtonCpy;
	arrS8MouseReport[X_INDEX]= u8XCpy;
	arrS8MouseReport[Y_INDEX]= u8YCpy;
    USBD_CUSTOM_HID_SendReport(&hUsbDeviceFS, arrS8MouseReport, 4);
	HAL_Delay(MOUSE_DELAYS);
}
