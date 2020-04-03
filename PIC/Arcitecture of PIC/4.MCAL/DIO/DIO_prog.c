/*************************************************/
/** Name :        Dyaa Elshater                  */
/** Date :        4/12/2019                      */
/** Description : PIC DIO Driver implementation  */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"
#include "DIO_CFG.h"
#include "DIO_PRIV.h"

/*Description : For initialization of IO Direction*/
void DIO_vidInit(void)
{

 /******************/
 ANSELA = 0;
 ANSELB = 0;
 ANSELC = 0;
 ANSELD = 0;
 ANSELE = 0;
 /******************/

 DIO_LATA = 0;
 
 DIO_LATB = 0;
 
 DIO_LATC = 0;
 
 DIO_LATD = 0;

  DIO_TRISA = conc(DIO_DIRECTION_RA7,DIO_DIRECTION_RA6,DIO_DIRECTION_RA5,
                   DIO_DIRECTION_RA4,DIO_DIRECTION_RA3,DIO_DIRECTION_RA2,
                   DIO_DIRECTION_RA1,DIO_DIRECTION_RA0);
                   
  DIO_TRISB = conc(DIO_DIRECTION_RB7,DIO_DIRECTION_RB6,DIO_DIRECTION_RB5,
                   DIO_DIRECTION_RB4,DIO_DIRECTION_RB3,DIO_DIRECTION_RB2,
                   DIO_DIRECTION_RB1,DIO_DIRECTION_RB0);
                   
  DIO_TRISC = conc(DIO_DIRECTION_RC7,DIO_DIRECTION_RC6,DIO_DIRECTION_RC5,
                   DIO_DIRECTION_RC4,DIO_DIRECTION_RC3,DIO_DIRECTION_RC2,
                   DIO_DIRECTION_RC1,DIO_DIRECTION_RC0);
                   
  DIO_TRISD = conc(DIO_DIRECTION_RD7,DIO_DIRECTION_RD6,DIO_DIRECTION_RD5,
                   DIO_DIRECTION_RD4,DIO_DIRECTION_RD3,DIO_DIRECTION_RD2,
                   DIO_DIRECTION_RD1,DIO_DIRECTION_RD0);

  DIO_TRISE = conc(DIO_DIRECTION_RE7,DIO_DIRECTION_RE6,DIO_DIRECTION_RE5,
                   DIO_DIRECTION_RE4,DIO_DIRECTION_RE3,DIO_DIRECTION_RE2,
                   DIO_DIRECTION_RE1,DIO_DIRECTION_RE0);
}

/*Description : For Setting pin value and direction*/

void DIO_vidSetPinDirection (u32 u32PortCpy , u8 u8PinCpy , u8 u8PinDirectionCpy)
{
 if (u8PinDirectionCpy == DIO_INPUT)
 {
    SET_BIT(*(volatile u8*)(u32PortCpy+DIO_PORT2TRIS),u8PinCpy );
 }
 else if (u8PinDirectionCpy == DIO_OUTPUT)
 {
     CLEAR_BIT(*(volatile u8*)(u32PortCpy+DIO_PORT2TRIS),u8PinCpy );
 }
 else
 {
 }
}

void DIO_vidSetPinValue (u32 u32PortCpy , u8 u8PinCpy , u8 u8ValueCpy )
{
     if (u8ValueCpy == DIO_HIGH)
     {
        SET_BIT(*(volatile u8*)(u32PortCpy + DIO_PORT2LAT),u8PinCpy);
     }
     else if (u8ValueCpy == DIO_LOW)
     {
        CLEAR_BIT(*(volatile u8*)(u32PortCpy+ DIO_PORT2LAT),u8PinCpy);
     }
     else
     {
     
     }
}

/*Description : For Setting Port value and direction*/

void DIO_vidSetPortDirection (u32 u32PortCpy , u8 u8DirectionCpy )
{
     if (u8DirectionCpy == DIO_OUTPUT)
     {
        (*(volatile u8*)(u32PortCpy+DIO_PORT2TRIS)) = DIO_PORT_LOW ;
     }
     else if(u8DirectionCpy == DIO_INPUT)
     {
        (*(volatile u8*)(u32PortCpy+DIO_PORT2TRIS)) = DIO_PORT_HIGH ;
     }
     else
     {
     
     }
}

void DIO_vidSetPortValue (u32 u32PortCpy , u8 u8ValueCpy )
{
     (*(volatile u8*)(u32PortCpy+8)) = u8ValueCpy ;
                               /*There is Bug here */
}

/*Description : For getting value from pin or port      */

u8 DIO_u8GetPinValue (u32 u32PortCpy , u8 u8PinCpy )
{
   return GET_BIT(*(volatile u8*)u32PortCpy,u8PinCpy);
}

u8 DIO_u8GetPortValue (u32 u32PortCpy)
{
   return  (*(volatile u8*)u32PortCpy);
}

/*Description : For Toggling pin or port      */
void DIO_vidTogglePin(u32 u32PortCpy , u8 u8PinCpy )
{
     TOGGLE_BIT(*(volatile u8*)(u32PortCpy + DIO_PORT2LAT),u8PinCpy);
}

void DIO_vidTogglePort(u32 u32PortCpy)
{
    *(volatile u8*)(u32PortCpy + DIO_PORT2LAT) ^= 0XFF ;
}