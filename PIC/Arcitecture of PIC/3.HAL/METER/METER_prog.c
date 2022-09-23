/*********************************************/
/** Name :                                   */
/** Date :                                   */
/** Description : METER Implementation       */
/*********************************************/
#include "Std_types.h"
#include "Bit_Math.h"

#include "DIO_INT.h"
   /* Include UART*/

#include "METER_INT.h"
#include "METER_CFG.h"
#include "METER_PRIV.h"


/****************************************************/
/****************************************************/

void METER_vidCksum(s8* arr)
{
        int i=0;
   char tmp=0;
   char cks=0;
   char sum=0;
   char tmp2=0;
   for(i=2;i<=12;i++)
   {
     sum+=arr[i];

   }
    tmp=sum&0xf0 ;
    tmp = (tmp>>4);
     if (tmp<=9)
    {
       cks = tmp|0x30;
       arr[13]=cks;
    }
    else {
      tmp2 =(int)tmp;
      tmp2 +=55;

     arr[13]=tmp2;
    }


    tmp = sum&0x0f;
    if (tmp<=9)
    {
       cks = tmp|0x30;
        arr[14]=cks;
    }
    else {
      tmp2=(int)tmp;
      tmp2+=55;

     arr[14]=tmp2;
    }


}

/*************************************************/
/** Its position is not here                     */
static void nFloatToStr(float f, short p, char *txt)
{
      unsigned long result;
   char sign = ((char *)&f)[2].B7;
   unsigned long factor = 10;
   short i = p, j = 0;

   while (i--)
      factor *= 10;

   ((char *)&f)[2].B7 = 0;

   result = ((unsigned long)(f * factor) + 5) / 10;

   do {
      txt[j++] = result % 10 + '0';
      if (--p == 0)
         txt[j++] = '.';
   } while (((result /= 10) > 0) || (p > 0));

   if (txt[j - 1] == '.')
      txt[j++] = '0';

   if (sign)
      txt[j++] = '-';

   txt[j] = '\0';

   for (i = 0, j--; i < j; i++, j--)
      p = txt[i], txt[i] = txt[j], txt[j] = p;
}



void FloatToStr(float f32NumberCpy,char ps8StrCpy[])
{
//	char Loc_ps8Real[NUMBER_OF_RAEL];
	unsigned char i ;
	int s32IntValue = (int)f32NumberCpy ;
	f32NumberCpy -= s32IntValue ;
	/*char *  itoa ( int value, char * str, int base );*/
	//itoa(s32IntValue,Loc_ps8Real,10);
	for(i=0;i<NUMBER_OF_RAEL;i++)
	{
		ps8StrCpy[i] = s32IntValue%10 +'0';
		s32IntValue/=10;
	}
	ps8StrCpy[i++]='.';
	for(;i<NUMBER_OF_RAEL+NUMBER_OF_FLOAT+1;i++) /* No. Real + No. Float + floating point */
	{
		f32NumberCpy *= 10;
		ps8StrCpy[i]  = (int)f32NumberCpy + '0' ;
		f32NumberCpy -= (int)f32NumberCpy ;
	}
	
}
/*************************************************/


/*
 * Function:  Send_reading
 * --------------------
 * it convert float numbers to suitable form to be sent to counters
 *
 *  arguments:
 *                meter_num: decided based on the position of the jumber in meters board
 *                datatosend: is the number to be displayed on the meters
 *
 *  returns: 1 in success, or zero in failuer
 */

u16 METER_u16SendReading(u16 meter_num,f32 datatosend)
{
    char tmp=0;
    short i=0;
    short j=4;
    char point_flag=0;
    char arr[16];
    //if (datatosend<1)datatosend=datatosend/10;
    //floattoStr(datatosend,datadisp);
    nFloatToStr(datatosend, 4, datadisp);
    /**************** data frame construction************///
    arr[0]=start_farme;                   //start and headrer
    arr[1]=Header;
    //////////////////////////////////////////////

        /**meter number**/
    if (meter_num>9)
    {
        arr[2]=0x31;
        tmp = meter_num-10;
         arr[3]=0x30|tmp;
    }
    else
    {
        arr[2] = tmp|0x30;
        tmp = meter_num&0x0f;
        arr[3] = tmp|0x30;

    }

        // meter starting position
         // meter starting position/********************************************************/
         if     (meter_num == 6) || (meter_num == 9) || (meter_num == 10)||  (meter_num == 13))         j=3;
                                                                                                                    // j determine the first number to be sent
                                                                                                                    // and it will be the last in the string array
    else if (  (meter_num == 3) || (meter_num == 4)  ||(meter_num == 7) ||                                         //count from right to first digit left
               (meter_num == 8) || (meter_num == 11) ||(meter_num == 15)||  (meter_num == 20))        j=6;

    else if (meter_num == 14)                                                                         j=4;
    else if (meter_num == 18)                                                                         j=5;

    else return 3;
    //////////////////////////////////////////////

    for (i=4;i<=12;i++)
    {
     if (j>=0)
     {
       if (datadisp[j]=='.')
       {
        arr[i]=0x2E;
        point_flag=1;
       }                            //data
       else
       {
        arr[i]=0x30|datadisp[j];
       }
       j--;
     }
      else  arr[i]=0x30;
    }
    if (point_flag==0) arr[12]=0x2E;
    ///////////////////////////////////////////////////////
    METER_vidCksum(arr);     // calculate checksum
    arr[15]=0x66;    // end bit
    /***************** data frame comsstructed*************/

    for (i=0;i<=15;i++)
    {
        UART1_Write(arr[i]);      // sending frame
    }

   if (UART1_Data_Ready() == 1)
    {
     for (i=0;i<=2;i++)
     {
      response[i] =UART_Read();
     }
     if (response[1]==0x41) return 1;
     else return 0;
    }

}



u16 METER_u16ClearMeter(u16 meterNum)
{
          unsigned char tmp=0;
       //char dash = 0X2D;
       unsigned short i=0;
    unsigned char arr[16];

    /**************** data frame construction************///
    arr[0]=start_farme;                   //start and headrer
    arr[1]=Header;
    //////////////////////////////////////////////
    if (meterNum>9)
    {
        arr[2]=0x31;
        tmp = meterNum-10;
        arr[3]=0x30|tmp;
    }
    else
    {

        arr[2] = tmp|0x30;

                                ///  meter number
        tmp = meterNum&0x0f;
        arr[3] = tmp|0x30;

      }

   for (i=4;i<=11;i++)
    {
         arr[i]=dash;
     }
      arr[12]=dash;
     //////////////////////////////////////////////////////
    METER_vidCksum(arr);     // calculate checksum
    arr[15]=0x66;    // end bit
    /***************** data frame constructed*************/

    for (i=0;i<=15;i++)
    {
        UART1_Write(arr[i]);      // sending frame
    }

    if (UART1_Data_Ready() == 1)
    {
     for (i=0;i<=2;i++)
     {
      response[i] =UART_Read();
     }
     if (response[1]==0x41) return 1;
     else return 0;
    }

}



/****************************************************************/
/****************************************************************/