/*
 * EXT0.c
 *
 *  Created on: May 7, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"
#include "BitMath.h"

#include "EXT0.h"
#include "EXT0_cnfg.h"
#include "EXT0_priv.h"

pf x;

void EXT0_vidInit(void)
{
	#if EXT0_SENSE_CTR == EXT0_LOW_LEVEL
			CLR_BIT(MCUCR, 2);
			CLR_BIT(MCUCR, 3);

	#elif EXT0_SENSE_CTR == EXT0_IOC
			SET_BIT(MCUCR, 2);
			CLR_BIT(MCUCR, 3);

	#elif EXT0_SENSE_CTR == EXT0_FALLING
			CLR_BIT(MCUCR, 2);
			SET_BIT(MCUCR, 3);

	#elif EXT0_SENSE_CTR == EXT0_RISING
			SET_BIT(MCUCR , 2) ;
			SET_BIT(MCUCR , 3) ;
	#endif

}

void EXT0_vidChangeSense(uint8 u8FormCpy)
{
	switch(u8FormCpy)
	{
		case EXT0_RISING:
		SET_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;

		case EXT0_FALLING:
		CLR_BIT(MCUCR , 2);
		SET_BIT(MCUCR , 3);
		break;

		case EXT0_IOC:
		SET_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
		break;

		case EXT0_LOW_LEVEL:
		CLR_BIT(MCUCR , 2);
		CLR_BIT(MCUCR , 3);
		break;

	}
}

void EXT0_vidIntEnable(void)
{
	SET_BIT(GICR, 7);
}
void EXT0_vidIntDisable(void)
{
	CLR_BIT(GICR, 7);
}

void EXT0_vidSetCallback(pf pfCallbackCpy)
{
	x = pfCallbackCpy ;
}

void __vector_1 (void) __attribute__ ((signal,used));
void __vector_1 (void)
{
	x();
}
