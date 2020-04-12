/*********************************************/
/** Name :        Dyaa Elshater              */
/** Date :        5/12/2019                  */
/** Description : Push Button Private        */
/*********************************************/

#ifndef _PB_PRIV_H_
#define _PB_PRIV_H_


#ifndef PB_MODE
#define PB_MODE   PB_PULL_DEOWN
#endif


uint8_t arrU8State_Failing[PB_MAX_NUMBER] = {0};
uint8_t arrU8State_Raising[PB_MAX_NUMBER] = {0};

#endif
