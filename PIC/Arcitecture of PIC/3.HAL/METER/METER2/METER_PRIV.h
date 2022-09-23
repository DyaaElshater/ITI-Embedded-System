/*********************************************/
/** Name :                                   */
/** Date :                                   */
/** Description : METER Private              */
/*********************************************/

#ifndef _METER_PRIV_H_
#define _METER_PRIV_H_


#define start_farme                           (0X1B)
#define Header                                (0x77)
#define dash                                  (0x2D)
#define emptyCell                             (0x78)
#define numberOfMeters                        (20)

#ifndef        NUMBER_OF_RAEL
#define NUMBER_OF_RAEL        2
#endif

#ifndef        NUMBER_OF_FLOAT
#define NUMBER_OF_FLOAT        3
#endif



s8 meter_No=1;
s8 response[2]={0};
s8 datadisp[16]={0};


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



static void FloatToStr(float f32NumberCpy,char ps8StrCpy[])
{
//        char Loc_ps8Real[NUMBER_OF_RAEL];
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





#endif