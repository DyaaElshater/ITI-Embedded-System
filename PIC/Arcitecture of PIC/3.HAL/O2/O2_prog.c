/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : Throttlepedal  implementation  */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"
         /*Include ADC*/

#include "O2_INT.h"
#include "O2_CFG.h"
#include "O2_PRIV.h"



void O2_vidInit()
{
        DIO_vidSetPinDirection(O2_PORT,O2_PIN,DIO_INPUT);
//        ANSELC.RC4 = 1;
}

f32 O2_f32GetValue()
{
        u32 sumADC = 0;
        u16 i    = 0;

        while (i<samplesNumber){

                sumADC+= ADC_Read(O2CH);
                  delay_us(samplesDelay);
                i++;
        }
        sumADC=sumADC/samplesNumber;
        if(sumADC<0) sumADC=0;
        else if(sumADC>1024) sumADC=1024;

        return sumADC;

}