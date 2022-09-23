/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : TPS  implementation            */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"
         /*Include ADC*/

#include "TPS_INT.h"
#include "TPS_CFG.h"
#include "TPS_PRIV.h"



void TPS_vidInit()
{
        DIO_vidSetPinDirection(TPS_PORT,TPS_PIN,DIO_INPUT);
//        ANSELC.RC4 = 1;
}

f32 TPS_f32GetValue()
{
        u32 sumADC = 0;
        u16 i    = 0;

        while (i<samplesNumber){

                sumADC+= ADC_Read(TPSCH);
                delay_us(samplesDelay);
                i++;
        }
        sumADC=sumADC/samplesNumber;
        if(sumADC<0) sumADC=0;
        else if(sumADC>1024) sumADC=1024;

        return sumADC;
}