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
u8 PB_u8IsPressed(GPIO_Register* tpPortCpy,u16 u16PinCpy);

	/* Put the button ID	  */
   /* return 1 in rising edge */
u8 PB_u8IsPressed_RisingEdge(GPIO_Register* tpPortCpy,u16 u16PinCpy,u8 u8IDCpy);

	/* Put the button ID	  */
   /* return 1 in falling edge */
u8 PB_u8IsPressed_FallingEdge(GPIO_Register* tpPortCpy,u16 u16PinCpy,u8 u8IDCpy);

#endif
