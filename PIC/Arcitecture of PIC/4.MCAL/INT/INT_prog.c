/************************************************/
/** Name        : Dyaa Elshater                 */
/** Date        : 10/12/2019                    */
/** Description : Interrupt Implementation File */
/** Version     : 1.0 V                         */
/************************************************/

#include "Bit_Math.h"
#include "Std_types.h"

#include "INT_INT.h"
#include "INT_PRIV.h"
#include "INT_CFG.h"
#include "INT_PRIV2.h"



void INT_vidGIE_Enable()
{
// #if INT_PER_MODE == INT_PERIORITY_LEVELS_ENABLE
    SET_BIT(INT_INTCON,GIE_GIEH);
    SET_BIT(INT_INTCON,PEIE_GIEL);
// #else
//    SET_BIT(INT_INTCON,GIE_GIEH);
//    SET_BIT(INT_INTCON,PEIE_GIEL);
// #endif

}

void INT_vidGIE_Disable()
{
 #if INT_PER_MODE == INT_PERIORITY_LEVELS_ENABLE
    CLEAR_BIT(INT_INTCON,GIE_GIEH);
    CLEAR_BIT(INT_INTCON,PEIE_GIEL);
 #else
    CLEAR_BIT(INT_INTCON,GIE_GIEH);
 #endif
}


 void interrupt()
{
   u8 loc_u8I ;
   for(loc_u8I=0 ; loc_u8I<INT_NO_INTERRUPTS;loc_u8I++)
   {
     if(GET_BIT(*(volatile u8*)(stINT_Periority[loc_u8I].u32Register) ,stINT_Periority[loc_u8I].u8FlagBit ))
     {
         stINT_Periority[loc_u8I].pfPerphiralFunction();
                   /*Clear the flag*/
         CLEAR_BIT(*(volatile u8*)(stINT_Periority[loc_u8I].u32Register) ,stINT_Periority[loc_u8I].u8FlagBit ) ;
     }
     else
     {
     }
   }
}