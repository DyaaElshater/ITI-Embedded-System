/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : Push Button Implementation */
/*********************************************/
#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_INT.h"

#include "PushButton_INT.h"
#include "PushButton_CFG.h"
#include "PushButton_PRIV.h"


u8 PB_u8IsPressed(u32 u32PortCpy,u8 u8PinCpy)
{
 #if PB_MODE == PB_PULL_DEOWN
  return DIO_u8GetPinValue(u32PortCpy , u8PinCpy);
 #elif PB_MODE == PB_PULL_UP
  return ! (DIO_u8GetPinValue(u32PortCpy , u8PinCpy));
 #endif
}

u8 PB_u8IsPressed_RisingEdge(u32 u32PortCpy,u8 u8PinCpy)
{
  static u8 Loc_u8Flag=0;
  u8 Loc_u8Result=0;
  if(!Loc_u8Flag && DIO_u8GetPinValue(u32PortCpy,u8PinCpy)==0)
  {
    Loc_u8Flag = 1;
  }
  else if (Loc_u8Flag && DIO_u8GetPinValue(u32PortCpy,u8PinCpy)==1)
  {
    Loc_u8Result = 1;
    Loc_u8Flag = 0;
  }
  else
  {
  
  }
  return Loc_u8Result;
}

u8 PB_u8IsPressed_FallingEdge(u32 u32PortCpy,u8 u8PinCpy)
{
   static u8 Loc_u8Flag=0;
  u8 Loc_u8Result=0;
  if(!Loc_u8Flag && DIO_u8GetPinValue(u32PortCpy,u8PinCpy)==1)
  {
    Loc_u8Flag = 1;
  }
  else if (Loc_u8Flag && DIO_u8GetPinValue(u32PortCpy,u8PinCpy)==0)
  {
    Loc_u8Result = 1;
    Loc_u8Flag = 0;
  }
  else
  {

  }
  return Loc_u8Result;
}


