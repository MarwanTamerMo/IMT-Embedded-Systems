/*
 * EXT2.c
 *
 *  Created on: May 7, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"
#include "BitMath.h"

#include "EXT2.h"
#include "EXT2_cnfg.h"
#include "EXT2_priv.h"

pf x;

void EXT2_vidInit(void)
{
	#if EXT2_SENSE_CTR == EXT2_FALLING
			
		CLEAR_BIT(MCUCSR, 6);

	#elif EXT2_SENSE_CTR == EXT2_RISING

		SET_BIT(MCUCSR, 6);

	#endif

}

void EXT2_vidChangeSense(uint8 u8FormCpy)
{
	switch(u8FormCpy)
	{
		case EXT2_RISING:
		SET_BIT(MCUCSR, 6);
		break;

		case EXT2_FALLING:
		CLEAR_BIT(MCUCSR, 6);
		break;

	}
}

void EXT2_vidIntEnable(void)
{
	SET_BIT(GICR, 5);
}
void EXT2_vidIntDisable(void)
{
	CLR_BIT(GICR, 5);
}

void EXT2_vidSetCallback(pf pfCallbackCpy)
{
	x = pfCallbackCpy ;
}

void __vector_3 (void) __attribute__ ((signal,used));
void __vector_3 (void)
{
	x();
}
