/*
 * APP_Project.c
 *
 *  Created on: Sep 9, 2019
 *      Author: Dyaa Elshater
 */



/**	Version		:	V4.1				*/


#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_int.h"
#include "EXT0_int.h"
#include "GIE_int.h"
#include "TIMER0_int.h"

#include "RTO_int.h"

#include "APP_int.h"
#include "APP_cfg.h"
#include "APP_priv.h"


static void POV_INT0HallEffectAction(void)
{
	u8QueueIndexPrint=0;
	u8ArrayIndex=0;
	DIO_enuTogglePin(DIO_u8PIN_7);
}

void POV_UpdateLeds(void);

void POV_vidStart(void)
{

	DIO_enuInt();
	DIO_enuPullUp(DIO_u8PIN_26);
	EXT0_vidInit();
	EXT0_Set_Call_back(POV_INT0HallEffectAction);
/*

	RTO_enuSettingTickTime(2000RTO_TICK_TIME);
	RTO_enuInit();
*/


	TIMER0_enuInit(20);
	TIMER0_enuSetCallback_CTC(POV_UpdateLeds);

	Enable_InterruptEnable();
}

/*static */void POV_UpdateLeds(void)
{

/*	_delay_us(20);*/

	if ((Queue +u8QueueIndexPrint )!= NULL  && (u8QueueIndexPrint<u8QueueIndexMax) )
	{
		Set_Port_Value(PORTC_DIO,((Queue[u8QueueIndexPrint] /*Array*/ )[u8ArrayIndex]));
		DIO_enuTogglePin(DIO_u8PIN_0);
		if(u8ArrayIndex>=7)
		{
			u8ArrayIndex=0;
			u8QueueIndexPrint++;
		}
		else
		{
			u8ArrayIndex++;
		}
	}
	else if(u8QueueIndexPrint>=u8QueueIndexMax)
	{
		Set_Port_Value(PORTC_DIO,0);
	}
	else
	{

	}
}


void POV_vidWriteChar(u8 u8CharCpy)
{
	switch (u8CharCpy)
	{

	case ' ' : Queue[u8QueueIndexMax] = space;break;

	case 'a' : 	Queue[u8QueueIndexMax] = a;break;
	case 'b' : 	Queue[u8QueueIndexMax] = b;break;
	case 'c' : 	Queue[u8QueueIndexMax] = c;break;
	case 'd' : 	Queue[u8QueueIndexMax] = d;break;
	case 'e' : 	Queue[u8QueueIndexMax] = e;break;
	case 'l' : 	Queue[u8QueueIndexMax] = l;break;
	case 'f' : 	Queue[u8QueueIndexMax] = f;break;
	case 'g' : 	Queue[u8QueueIndexMax] = g;break;
	case 'h' : 	Queue[u8QueueIndexMax] = h;break;
	case 'i' : 	Queue[u8QueueIndexMax] = i;break;
	case 'j' : 	Queue[u8QueueIndexMax] = j;break;
	case 'k' : 	Queue[u8QueueIndexMax] = k;break;
	case 'm' : 	Queue[u8QueueIndexMax] = m;break;
	case 'n' : 	Queue[u8QueueIndexMax] = n;break;
	case 'o' : 	Queue[u8QueueIndexMax] = o;break;
	case 'p' : 	Queue[u8QueueIndexMax] = p;break;
	case 'q' : 	Queue[u8QueueIndexMax] = q;break;
	case 'r' : 	Queue[u8QueueIndexMax] = r;break;
	case 's' : 	Queue[u8QueueIndexMax] = s;break;
	case 't' : 	Queue[u8QueueIndexMax] = t;break;
	case 'u' : 	Queue[u8QueueIndexMax] = u;break;
	case 'v' : 	Queue[u8QueueIndexMax] = v;break;
	case 'w' : 	Queue[u8QueueIndexMax] = w;break;
	case 'x' : 	Queue[u8QueueIndexMax] = x;break;
	case 'y' : 	Queue[u8QueueIndexMax] = y;break;
	case 'z' : 	Queue[u8QueueIndexMax] = z;break;


	case 'A' : 	Queue[u8QueueIndexMax] = A;break;
	case 'B' : 	Queue[u8QueueIndexMax] = B;break;
	case 'C' : 	Queue[u8QueueIndexMax] = C;break;
	case 'D' : 	Queue[u8QueueIndexMax] = D;break;
	case 'E' : 	Queue[u8QueueIndexMax] = E;break;
	case 'F' : 	Queue[u8QueueIndexMax] = F;break;
	case 'G' : 	Queue[u8QueueIndexMax] = G;break;
	case 'H' : 	Queue[u8QueueIndexMax] = H;break;
	case 'I' : 	Queue[u8QueueIndexMax] = I;break;
	case 'J' : 	Queue[u8QueueIndexMax] = J;break;
	case 'K' : 	Queue[u8QueueIndexMax] = K;break;
	case 'L' : 	Queue[u8QueueIndexMax] = L;break;
	case 'M' : 	Queue[u8QueueIndexMax] = M;break;
	case 'N' : 	Queue[u8QueueIndexMax] = N;break;
	case 'O' : 	Queue[u8QueueIndexMax] = O;break;
	case 'P' : 	Queue[u8QueueIndexMax] = P;break;
	case 'Q' : 	Queue[u8QueueIndexMax] = Q;break;
	case 'R' : 	Queue[u8QueueIndexMax] = R;break;
	case 'S' : 	Queue[u8QueueIndexMax] = S;break;
	case 'T' : 	Queue[u8QueueIndexMax] = T;break;
	case 'U' : 	Queue[u8QueueIndexMax] = U;break;
	case 'V' : 	Queue[u8QueueIndexMax] = V;break;
	case 'W' : 	Queue[u8QueueIndexMax] = W;break;
	case 'X' : 	Queue[u8QueueIndexMax] = X;break;
	case 'Y' : 	Queue[u8QueueIndexMax] = Y;break;
	case 'Z' : 	Queue[u8QueueIndexMax] = Z;break;

	case '0' : 	Queue[u8QueueIndexMax] = n0;break;
	case '1' : 	Queue[u8QueueIndexMax] = n1;break;
	case '2' : 	Queue[u8QueueIndexMax] = n2;break;
	case '3' : 	Queue[u8QueueIndexMax] = n3;break;
	case '4' : 	Queue[u8QueueIndexMax] = n4;break;
	case '5' : 	Queue[u8QueueIndexMax] = n5;break;
	case '6' : 	Queue[u8QueueIndexMax] = n6;break;
	case '7' : 	Queue[u8QueueIndexMax] = n7;break;
	case '8' : 	Queue[u8QueueIndexMax] = n8;break;
	case '9' : 	Queue[u8QueueIndexMax] = n9;break;
	default	 :	break;

	}
	u8QueueIndexMax++;
}

void POV_vidWriteString(u8 * pu8StringCpy)
{
	u8 u8IndexLoc =0;
	while(pu8StringCpy[u8IndexLoc]!='\0')
	{
		POV_vidWriteChar(pu8StringCpy[u8IndexLoc]);
		u8IndexLoc++;
	}
}

void POV_vidSpecificChar(void)
{
	Queue[u8QueueIndexMax] = SpecificChar;
	u8QueueIndexMax++;
}


void POV_vidClearLastChar(void)
{
	u8QueueIndexMax --;
	Queue[u8QueueIndexMax]=NULL;
}

void POV_vidGoToIndex(u8 u8IndexCpy)
{
	u8QueueIndexPrint = u8IndexCpy ;
	u8ArrayIndex =0;
}
void POV_vidClearAll(void)
{
	u8QueueIndexMax =0;
}
