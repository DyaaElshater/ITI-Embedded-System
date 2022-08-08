/***********************************************************/
/* Name          : Dyaa Elshater                           */
/* Date          : 27/06/2022                              */
/* Deswcription  : Mouse Interface File                    */
/* Version       : 1.0 V                                   */
/***********************************************************/

#ifndef MOUSE_INT_H_
#define MOUSE_INT_H_

void Mouse_vidInit();
void Mouse_vidMoveUp(uint8_t pU8Value);
void Mouse_vidMoveDown(uint8_t pU8Value);
void Mouse_vidMoveRight(uint8_t pU8Value);
void Mouse_vidMoveLeft(uint8_t pU8Value);
void Mouse_vidPressRightClick();
void Mouse_vidReleaseRightClick();
void Mouse_vidPressLeftClick();
void Mouse_vidReleaseLeftClick();
void Mouse_vidSendReport();
void Mouse_vidPressMiddleClick();
void Mouse_vidReleaseMiddleClick();
void Mouse_vidPressScrolUp();
void Mouse_vidReleaseScrolUp();
void Mouse_vidPressScrolDown();
void Mouse_vidReleaseScrolDown();


#endif /* MOUSE_INT_H_ */
