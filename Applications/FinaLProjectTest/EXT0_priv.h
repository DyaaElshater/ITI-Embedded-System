#ifndef EXT0_PRIV_H
#define EXT0_PRIV_H

#define MCUCR (*((volatile u8*)0x55))
#define MCUCSR (*((volatile u8*)0x54))
#define GICR (*((volatile u8*)0x5b))
#define GIFR (*((volatile u8*)0x5a))



#endif