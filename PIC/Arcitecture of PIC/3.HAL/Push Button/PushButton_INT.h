/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : Push Button Interface      */
/*********************************************/

#ifndef _PB_INT_H_
#define _PB_INT_H_

#define PB_PULL_UP     1
#define PB_PULL_DEOWN  0

  /*  return 1 if the pushbutton is pressed    */
u8 PB_u8IsPressed(u32 u32PortCpy,u8 u8PinCpy);

   /* return 1 in rising edge */
u8 PB_u8IsPressed_RisingEdge(u32 u32PortCpy,u8 u8PinCpy);

   /* return 1 in falling edge */
u8 PB_u8IsPressed_FallingEdge(u32 u32PortCpy,u8 u8PinCpy);

#endif