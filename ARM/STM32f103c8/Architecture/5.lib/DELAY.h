/*
 * DELAY.h
 *
 *  Created on: Oct 21, 2019
 *      Author: Dyaa Elshater
 */

#ifndef DELAY_H_
#define DELAY_H_

#define delay_us(time) do{u32 Loc_u32var,Loc_u32Max=time<<2;\
							for(Loc_u32var=0;Loc_u32var<Loc_u32Max;Loc_u32var++)\
							{__asm__("NOP");\
							}\
						}while(0)

#define delay_ms(time) do{u32 Loc_u32var,Loc_u32Max=(time<<2)*1000;\
							for(Loc_u32var=0;Loc_u32var<Loc_u32Max;Loc_u32var++)\
							{__asm__("NOP");\
							}\
						}while(0)

#define delay_s(time) do{u32 Loc_u32var,Loc_u32Max=(time<<2)*1000000;\
							for(Loc_u32var=0;Loc_u32var<Loc_u32Max;Loc_u32var++)\
							{__asm__("NOP");\
							}\
						}while(0)


#endif /* DELAY_H_ */
