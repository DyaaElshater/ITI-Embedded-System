/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : Throttlepedal  implementation  */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"
         /*Include ADC*/

#include "WTS_INT.h"
#include "WTS_CFG.h"
#include "WTS_PRIV.h"



void WTS_vidInit()
{
        DIO_vidSetPinDirection(WTS_PORT,WTS_PIN,DIO_INPUT);
//        ANSELC.RC4 = 1;
}

f32 WTS_f32GetValue()
{
        u32 sumADC = 0;
        u16 i    = 0;

        while (i<samplesNumber){

                sumADC+= ADC_Read(WTSCH);
                delay_us(samplesDelay);
                i++;
        }
        sumADC=sumADC/samplesNumber;
        if(sumADC<0) sumADC=0;
        else if(sumADC>1024) sumADC=1024;

        return sumADC;

}