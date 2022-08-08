/*
 * KEYBOARD_PRIV.h
 *
 *  Created on: Jun 21, 2022
 *      Author: Dyaa Elshater
 */

#ifndef KEYBOARD_PRIV_H_
#define KEYBOARD_PRIV_H_

#define MAX_CHAR_SIZE (255)
#define CAPITAL_LETTER_BIT (5)

typedef struct
{
	uint8_t modifier;
	uint8_t reserved;
	uint8_t keyCode[6];
}keyboardHid;

keyboardHid keyboardhid = {0,0,{0,0,0,0,0,0}};

u_int8_t u8ArrkeyboardCharacters[MAX_CHAR_SIZE];

void Keyboard_vidInitChar();
void Keyboard_vidInitNum();


/*
 * Descriptor :
 	    0x05, 0x01,                    // USAGE_PAGE (Generic Desktop)
	    0x09, 0x06,                    // USAGE (Keyboard)
	    0xa1, 0x01,                    // COLLECTION (Application)
	    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
	    0x19, 0xe0,                    //   USAGE_MINIMUM (Keyboard LeftControl)
	    0x29, 0xe7,                    //   USAGE_MAXIMUM (Keyboard Right GUI)
	    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
	    0x25, 0x01,                    //   LOGICAL_MAXIMUM (1)
	    0x75, 0x01,                    //   REPORT_SIZE (1)
	    0x95, 0x08,                    //   REPORT_COUNT (8)
	    0x81, 0x02,                    //   INPUT (Data,Var,Abs)
	    0x95, 0x01,                    //   REPORT_COUNT (1)
	    0x75, 0x08,                    //   REPORT_SIZE (8)
	    0x81, 0x03,                    //   INPUT (Cnst,Var,Abs)
	    0x95, 0x05,                    //   REPORT_COUNT (5)
	    0x75, 0x01,                    //   REPORT_SIZE (1)
	    0x05, 0x08,                    //   USAGE_PAGE (LEDs)
	    0x19, 0x01,                    //   USAGE_MINIMUM (Num Lock)
	    0x29, 0x05,                    //   USAGE_MAXIMUM (Kana)
	    0x91, 0x02,                    //   OUTPUT (Data,Var,Abs)
	    0x95, 0x01,                    //   REPORT_COUNT (1)
	    0x75, 0x03,                    //   REPORT_SIZE (3)
	    0x91, 0x03,                    //   OUTPUT (Cnst,Var,Abs)
	    0x95, 0x06,                    //   REPORT_COUNT (6)
	    0x75, 0x08,                    //   REPORT_SIZE (8)
	    0x15, 0x00,                    //   LOGICAL_MINIMUM (0)
	    0x25, 0x65,                    //   LOGICAL_MAXIMUM (101)
	    0x05, 0x07,                    //   USAGE_PAGE (Keyboard)
	    0x19, 0x00,                    //   USAGE_MINIMUM (Reserved (no event indicated))
	    0x29, 0x65,                    //   USAGE_MAXIMUM (Keyboard Application)
	    0x81, 0x00,                    //   INPUT (Data,Ary,Abs)
	    0xc0                           // END_COLLECTION

 */

/*
u8ArrkeyboardCharacters['a']=0x04;
u8ArrKeyboardCharacters['b']=0x
u8ArrKeyboardCharacters['c']=0x
u8ArrKeyboardCharacters['d']=0x
u8ArrKeyboardCharacters['e']=0x
u8ArrKeyboardCharacters['f']=0x
u8ArrKeyboardCharacters['g']=0x
u8ArrKeyboardCharacters['h']=0x
u8ArrKeyboardCharacters['i']=0x
u8ArrKeyboardCharacters['j']=0x
u8ArrKeyboardCharacters['k']=0x
u8ArrKeyboardCharacters['l']=0x
u8ArrKeyboardCharacters['m']=0x
u8ArrKeyboardCharacters['n']=0x
u8ArrKeyboardCharacters['o']=0x
u8ArrKeyboardCharacters['p']=0x
u8ArrKeyboardCharacters['q']=0x
u8ArrKeyboardCharacters['r']=0x
u8ArrKeyboardCharacters['s']=0x
u8ArrKeyboardCharacters['t']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
u8ArrKeyboardCharacters['']=0x
*/
#endif /* KEYBOARD_PRIV_H_ */
