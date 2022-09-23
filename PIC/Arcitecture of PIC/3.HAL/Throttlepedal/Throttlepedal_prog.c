/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : Throttlepedal  implementation  */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"
         /*Include ADC*/

#include "Throttlepedal_INT.h"
#include "Throttlepedal_CFG.h"
#include "Throttlepedal_PRIV.h"



void Throttlepedal_vidInit()
{
        DIO_vidSetPinDirection(Throttlepedal_PORT,Throttlepedal_PIN,DIO_INPUT);
//        ANSELC.RC4 = 1;
}

f32 Throttlepedal_f32GetValue()
{
        u32 sumADC = 0;
        u16 i    = 0;

        while (i<samplesNumber){

                sumADC+= ADC_Read(throttlePedalCH);
                delay_us(samplesDelay);
                i++;
        }
        sumADC=sumADC/samplesNumber;
        if(sumADC<0) sumADC=0;
        else if(sumADC>1024) sumADC=1024;

        return sumADC;

}