/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : Push Button Implementation */
/*********************************************/
		/*MCAL*/
#include "Std_types.h"
#include "Bit_Math.h"
#include "DELAY.h"

#include "GPIO_INT.h"

#include "PushButton_INT.h"
#include "PushButton_CFG.h"
#include "PushButton_PRIV.h"




u8 PB_u8IsPressed(GPIO_Register* tpPortCpy,u16 u16PinCpy)
{

	u8 loc_u8Result = GPIO_u8LOW;
	if(GPIO_u8GetPinValue(tpPortCpy, u16PinCpy)==GPIO_u8HIGH)
	{
		delay_ms(80);
		if(GPIO_u8GetPinValue(tpPortCpy, u16PinCpy)==GPIO_u8HIGH)
		{
			loc_u8Result = GPIO_u8HIGH ;
		}
		else {}
	}
	else	{}
 #if PB_MODE == PB_PULL_DEOWN
	return loc_u8Result;
 #elif PB_MODE == PB_PULL_UP
 	return ! loc_u8Result;
;
 #endif
}

u8 PB_u8IsPressed_RisingEdge(GPIO_Register* tpPortCpy,u16 u16PinCpy,u8 u8IDCpy)
{
  u8 Loc_u8Result=0;
  if(!arrU8State_Raising[u8IDCpy] && PB_u8IsPressed(tpPortCpy,u16PinCpy)==0)
  {
	  arrU8State_Raising[u8IDCpy] = 1;
  }
  else if (arrU8State_Raising[u8IDCpy] &&  PB_u8IsPressed(tpPortCpy,u16PinCpy)==1)
  {
    Loc_u8Result = 1;
    arrU8State_Raising[u8IDCpy] = 0;
  }
  else
  {
  
  }
  return Loc_u8Result;
}

u8 PB_u8IsPressed_FallingEdge(GPIO_Register* tpPortCpy,u16 u16PinCpy,u8 u8IDCpy)
{
   u8 Loc_u8Result=0;
  if(! arrU8State_Failing[u8IDCpy] &&  PB_u8IsPressed(tpPortCpy,u16PinCpy)==1)
  {
	  arrU8State_Failing[u8IDCpy] = 1;
  }
  else if (arrU8State_Failing[u8IDCpy]&&  PB_u8IsPressed(tpPortCpy,u16PinCpy)==0)
  {
    Loc_u8Result = 1;
    arrU8State_Failing[u8IDCpy] = 0;
  }
  else
  {

  }
  return Loc_u8Result;
}


