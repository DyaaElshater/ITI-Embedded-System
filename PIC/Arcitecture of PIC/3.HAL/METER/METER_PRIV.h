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

#ifndef	NUMBER_OF_RAEL
#define NUMBER_OF_RAEL	2
#endif

#ifndef	NUMBER_OF_FLOAT
#define NUMBER_OF_FLOAT	3
#endif



s8 meter_No=1;
s8 response[2]={0};
s8 datadisp[16]={0};






#endif