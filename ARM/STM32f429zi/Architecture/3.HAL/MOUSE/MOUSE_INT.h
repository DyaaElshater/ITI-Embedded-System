/***********************************************************/
/* Name          : Dyaa Elshater                           */
/* Date          : 22/12/2019                              */
/* Deswcription  : Mouse Interface File                    */
/* Version       : 1.0 V                                   */
/***********************************************************/

#ifndef _MOUSE_INT_H_
#define _MOUSE_INT_H_

typedef enum enuButton {LEFT = 0x01,RIGHT = 0x02} enuButtonState ;

/** Description  :                             */
/*           For initializing the Mouse        */
void MOUSE_VidInit(void) ;


      /** Description :                        */
      /* For moving the mouse pointer manually */
      /* Without using the pins configured in  */
      /* configuration file                    */
void  MOUSE_vidMovePointer_UP(void);
void  MOUSE_vidMovePointer_DOWN(void);
void  MOUSE_vidMovePointer_RIGHT(void);
void  MOUSE_vidMovePointer_LEFT(void);


      /** Description :                          */
      /* For Pressing the mouse buttons manually */
      /* Without using the pins configured in    */
      /* configuration file                      */
void MOUSE_vidPressButton_RIGHT(void);
void MOUSE_vidPressButton_LEFT(void);


      /** Descripyion                             */
      /*      Checking the Mouse state , moving   */
      /*  the mouse pointer and pressing buttons  */
      /*  due to configures pin check             */
      /**   Use this function in the loop or as   */
      /* polling function to be executed all the  */
      /* Program                                  */
void MOUSE_vidUpdate(void);


void MOUSE_vidRelease(void);

void MOUSE_vidLeftPreesedWithMove_Right(void);

void MOUSE_vidLeftPreesedWithMove_Left(void);
void MOUSE_vidLeftPreesedWithMove_Up(void);
void MOUSE_vidLeftPreesedWithMove_Down(void);

/** X : +ve -> Right
 * 	  : -ve -> LEFT
 *
 ** Y : +ve	-> Down
 *    : -ve	-> Up								*/
/**		u8ButtonCpy = 							*/
/*						LEFT					*/
/*						RIGHT					*/
void MOUSE_vidCustom(int8_t u8XCpy,int8_t u8YCpy,enuButtonState u8ButtonCpy);

#endif
