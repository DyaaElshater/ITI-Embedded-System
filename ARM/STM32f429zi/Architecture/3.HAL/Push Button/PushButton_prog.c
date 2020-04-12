/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : Push Button Implementation */
/*********************************************/
		/*MCAL*/
#include "main.h"

#include "PushButton_INT.h"
#include "PushButton_CFG.h"
#include "PushButton_PRIV.h"




GPIO_PinState PB_u8IsPressed(GPIO_TypeDef* tpPortCpy,uint16_t u16PinCpy)
{

	uint8_t loc_u8Result = GPIO_PIN_RESET;
	if(HAL_GPIO_ReadPin(tpPortCpy, u16PinCpy)==GPIO_PIN_SET)
	{
		HAL_Delay(50);
		if(HAL_GPIO_ReadPin(tpPortCpy, u16PinCpy)==GPIO_PIN_SET)
		{
			loc_u8Result = GPIO_PIN_SET ;
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

uint8_t PB_u8IsPressed_RisingEdge(GPIO_TypeDef* tpPortCpy,uint16_t u16PinCpy,uint8_t u8IDCpy)
{
  uint8_t Loc_u8Result=0;
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

uint8_t PB_u8IsPressed_FallingEdge(GPIO_TypeDef* tpPortCpy,uint16_t u16PinCpy,uint8_t u8IDCpy)
{
   uint8_t Loc_u8Result=0;
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


