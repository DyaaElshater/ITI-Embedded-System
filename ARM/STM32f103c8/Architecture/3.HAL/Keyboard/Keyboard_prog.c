/*
#include "Bit_Math.h"
#include "DELAY.h"
#include "Std_types.h"
*/

#include "usb_device.h"
#include "usbd_hid.h"

#include "KEYBOARD_INT.h"
#include "KEYBOARD_PRIV.h"
#include "KEYBOARD_CFG.h"

extern USBD_HandleTypeDef hUsbDeviceFS;
static u_int8_t u8PressedIndex=0;


void Keyboard_vidInit()
{
	MX_USB_DEVICE_Init();
	/* Characters initialization */
	Keyboard_vidInitChar();
	/* Numbers initialization */
	Keyboard_vidInitNum();

}

void Keyboard_vidInitChar()
{
	u_int8_t loc_u8Index,u8KeyboardCharValue;
	for(loc_u8Index='a',u8KeyboardCharValue=KEYBOARD_A_CHAR;loc_u8Index<'z';loc_u8Index++,u8KeyboardCharValue++)
	{
		/* Small letter */
		u8ArrkeyboardCharacters[loc_u8Index]=u8KeyboardCharValue;
		/* Capital letter */
		u_int8_t loc_u8IndexCapital = loc_u8Index;
		/*Clear bit*/
		loc_u8IndexCapital &= ~(1<<CAPITAL_LETTER_BIT);

		u8ArrkeyboardCharacters[loc_u8IndexCapital]=u8KeyboardCharValue;
	}
}
void Keyboard_vidInitNum()
{
	u_int8_t loc_u8Index,u8KeyboardNumValue;
	for(loc_u8Index='1',u8KeyboardNumValue=KEYBOARD_1_NUM;loc_u8Index<'9';loc_u8Index++,u8KeyboardNumValue++)
	{
		u8ArrkeyboardCharacters[loc_u8Index]=u8KeyboardNumValue;
	}
}

void Keyboard_vidPressKey(u_int8_t pu8Char)
{
	if (u8PressedIndex<6)
	{
		keyboardhid.keyCode[u8PressedIndex]=u8ArrkeyboardCharacters[pu8Char];
		u8PressedIndex++;
	}
	else
	{

	}
}

void Keyboard_vidClearChars()
{
	u_int8_t loc_u8Index=0;
	for (loc_u8Index=0;loc_u8Index<u8PressedIndex;loc_u8Index++)
	{
		keyboardhid.keyCode[loc_u8Index]=0;
	}
	u8PressedIndex=0;
}

void Keyboard_vidSendReport()
{
	USBD_HID_SendReport(&hUsbDeviceFS,&keyboardhid, sizeof(keyboardhid));
	HAL_Delay(50);
}

void keyboard_vidSendWord(uint8_t pArrU8Word[])
{
	uint8_t loc_u8Index;
	for(loc_u8Index=0;pArrU8Word[loc_u8Index]!='\0';loc_u8Index++)
	{
		Keyboard_vidPressKey(pArrU8Word[loc_u8Index]);
		Keyboard_vidSendReport();
		Keyboard_vidClearChars();
		Keyboard_vidSendReport();
	}
}
