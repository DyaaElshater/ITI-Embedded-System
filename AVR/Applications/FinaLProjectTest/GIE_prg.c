#include"Std_types.h"
#include"Bit_Math.h"

#include"GIE_int.h"
#include"GIE_config.h"
#include"GIE_priv.h"

void Enable_InterruptEnable(void)
{
	SREG |= 0b10000000;
}

void Disable_InterruptEnable(void)
{
	SREG &= 0b01111111;
}