/*************************************************/
/** Name :        Dyaa Elshater                  */
/** Date :        5/12/2019                      */
/** Description : LED DIO Driver implementation  */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"

#include "LED_INT.h"
#include "LED_CFG.h"
#include "LED_PRIV.h"


void LED_vidLedOn(u32 u32PortCpy,u8 u8PinCpy)
{
     #if LED_MODE == LED_COM_GND
     DIO_vidSetPinValue(u32PortCpy,u8PinCpy,DIO_HIGH);
     #elif LED_MODE == LED_COM_VCC
     DIO_vidSetPinValue(u32PortCpy,u8PinCpy,DIO_LOW);
     #else
     #endif
}

void LED_vidLedOff(u32 u32PortCpy,u8 u8PinCpy)
{
     #if LED_MODE == LED_COM_GND
     DIO_vidSetPinValue(u32PortCpy,u8PinCpy,DIO_LOW);
     #elif LED_MODE == LED_COM_VCC
     DIO_vidSetPinValue(u32PortCpy,u8PinCpy,DIO_HIGH);
     #else
     #endif

}

void LED_vidToggle(u32 u32PortCpy,u8 u8PinCpy)
{
     DIO_vidTogglePit(u32PortCpy,u8PinCpy);
}