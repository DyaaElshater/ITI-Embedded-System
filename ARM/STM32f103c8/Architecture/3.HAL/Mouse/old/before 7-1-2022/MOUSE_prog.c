/***********************************************************/
/* Name          : Dyaa Elshater                           */
/* Date          : 27/06/2022                              */
/* Deswcription  : Mouse implementation File               */
/* Version       : 1.0 V                                   */
/***********************************************************/

#include "main.h"
#include "usb_device.h"


#include "MOUSE_PRIV.h"
#include "MOUSE_CFG.h"
#include "MOUSE_INT.h"

typedef struct
{
#if REPORT_ID != NONE
	uint8_t reportId;
#endif

	uint8_t rightButton:1;
	uint8_t middleButton:1;
	uint8_t leftButton:1;
	uint8_t scrolDown:1;
	uint8_t scrolUp:1;
	uint8_t reserved:3;
	uint8_t X_MovementValue;
	uint8_t Y_MovementValue;
}MOUSE_REPORT;

static MOUSE_REPORT mouseReport = {
#if REPORT_ID != NONE
		REPORT_ID,
#endif
0,0,0,0,0,0,0,0};
extern USBD_HandleTypeDef hUsbDeviceFS;

void Mouse_vidInit()
{
	  MX_USB_DEVICE_Init();
}
void Mouse_vidMoveUp(uint8_t pU8Value)
{
	mouseReport.Y_MovementValue= - abs(pU8Value);
}
void Mouse_vidMoveDown(uint8_t pU8Value)
{
	mouseReport.Y_MovementValue= abs(pU8Value);
}
void Mouse_vidMoveRight(uint8_t pU8Value)
{
	mouseReport.X_MovementValue= abs(pU8Value);
}
void Mouse_vidMoveLeft(uint8_t pU8Value)
{
	mouseReport.X_MovementValue= -abs(pU8Value);
}
void Mouse_vidPressRightClick()
{
	mouseReport.rightButton=MOUSE_BUTTON_PRESS;
}
void Mouse_vidReleaseRightClick()
{
	mouseReport.rightButton=MOUSE_BUTTON_RELEASE;
}
void Mouse_vidPressLeftClick()
{
	mouseReport.leftButton=MOUSE_BUTTON_PRESS;
}
void Mouse_vidReleaseLeftClick()
{
	mouseReport.leftButton=MOUSE_BUTTON_RELEASE;
}
void Mouse_vidSendReport()
{
	  USBD_HID_SendReport(&hUsbDeviceFS,&mouseReport, sizeof(mouseReport));
	  HAL_Delay(MOUSE_SEND_REPORT_DELAY_IN_US);
}
void Mouse_vidPressMiddleClick()
{
	mouseReport.middleButton=MOUSE_BUTTON_PRESS;
}
void Mouse_vidReleaseMiddleClick()
{
	mouseReport.middleButton=MOUSE_BUTTON_RELEASE;
}
void Mouse_vidPressScrolUp()
{
	mouseReport.scrolUp=MOUSE_BUTTON_PRESS;
}
void Mouse_vidReleaseScrolUp()
{
	mouseReport.scrolUp=MOUSE_BUTTON_RELEASE;
}
void Mouse_vidPressScrolDown()
{
	mouseReport.scrolDown=MOUSE_BUTTON_PRESS;
}
void Mouse_vidReleaseScrolDown()
{
	mouseReport.scrolDown=MOUSE_BUTTON_RELEASE;
}

