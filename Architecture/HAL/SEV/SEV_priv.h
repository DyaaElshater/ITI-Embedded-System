/****************************************************/
/* Author        :  Dyaa                            */
/* Description   :                                  */
/****************************************************/

#ifndef SEV_PRIV_H
#define SEV_PRIV_H

typedef struct {
	u8 u8Pin0;
	u8 u8Pin1;
	u8 u8Pin2;
	u8 u8Pin3;
	u8 u8Pin4;
	u8 u8Pin5;
	u8 u8Pin6;
	u8 u8Pin7;
}tstrPinNbCfg;

typedef struct{
	u8 u8MaxNbchips;
	tstrPinNbCfg * pastrsevcfg ;
	
}tstrCompCfg;

extern tstrCompCfg astrCompCfg[u8MAX_NB_VAR];

#endif








