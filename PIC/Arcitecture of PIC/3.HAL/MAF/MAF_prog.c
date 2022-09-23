/*************************************************/
/** Name :                                       */
/** Date :                                       */
/** Description : MAF  implementation            */
/*************************************************/


#include "Bit_Math.h"
#include "Std_types.h"

#include "DIO_INT.h"
         /*Include ADC*/

#include "MAF_INT.h"
#include "MAF_CFG.h"
#include "MAF_PRIV.h"



void MAF_vidInit()
{
    DIO_vidSetPinDirection(MAF_PORT1,MAF_PIN1,DIO_INPUT);
    DIO_vidSetPinDirection(MAF_PORT2,MAF_PIN2,DIO_INPUT);

}

f32 MAF_f32GetMAFAirFlow()
{
        u32 sumADC = 0;
        u16 i    = 0;

        while (i<samplesNumber){

                sumADC+= ADC_Read(MAFAirFlowCH);
                delay_us(samplesDelay);
                i++;
        }


        sumADC=sumADC/samplesNumber;
        if(sumADC<0) sumADC=0;
        else if(sumADC>1024) sumADC=1024;

        return sumADC;
}

f32 MAF_f32GetMAFTemp()
{
        u32 sumADC = 0;
        u16 i    = 0;

        while (i<samplesNumber){

                sumADC+= ADC_Read(MAFTempCH);
                delay_us(samplesDelay);
                i++;
        }
        sumADC=sumADC/samplesNumber;
        if(sumADC<0) sumADC=0;
        else if(sumADC>1024) sumADC=1024;

        return sumADC;
}

void MAF_vidSwitchInit()
{

		DIO_vidSetPinDirection(MAF_SWITCH1,MAF_SWITCH_PIN1,DIO_INPUT);
		DIO_vidSetPinDirection(MAF_SWITCH2,MAF_SWITCH_PIN2,DIO_INPUT);
		DIO_vidSetPinDirection(MAF_SWITCH2,MAF_SWITCH_PIN3,DIO_INPUT);
}