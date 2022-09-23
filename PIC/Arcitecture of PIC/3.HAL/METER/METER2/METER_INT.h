/*********************************************/
/** Name :                                   */
/** Date :                                   */
/** Description : METER Interface            */
/*********************************************/

#ifndef _METER_INT_H_
#define _METER_INT_H_


void METER_vidCksum(s8* arr);

/*************************************************/
/** Its position is not here                     */
//void nFloatToStr(float f, short p, char *txt) ;
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

u16 METER_u16SendReading_ScientificFormat(u16 meter_num,f32 datatosend);

u16 METER_u16SendReading(u16 meter_num,f32 datatosend);



u16 METER_u16ClearMeter(u16 meterNum);



#endif