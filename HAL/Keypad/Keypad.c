/*
 * Keypad.c
 *
 *  Created on: May 5, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"

#include "Keypad.h"
#include "KEYPAD_cnfg.h"
#include "KEYPAD_priv.h"

#include "DIO.h"

static void SendSeq(uint8 u8SeqNumCpy, uint8 u8KeypadIndxCpy);
static uint8 SendCheckInput(uint8 u8KeypadIndxCpy);

void KEYPAD_voidInit(void)
{
	/* loop all kepayd available */
	/* activate pullup resistor for input row pins*/
	uint8 u8AvaKeypadCntrLoc;
	uint8 u8InputCntrLoc;

	for (u8AvaKeypadCntrLoc = 0; u8AvaKeypadCntrLoc < KEYPAD_MAX_NUM; ++u8AvaKeypadCntrLoc)
	{
		for (u8InputCntrLoc = 0; u8InputCntrLoc < KEYPAD_astrConfigSet[u8AvaKeypadCntrLoc].u8RowInputNum; ++u8InputCntrLoc)
		{
			DIO_enuActivePullUp(KEYPAD_astrConfigSet[u8AvaKeypadCntrLoc].au8RowInputDioConc[u8InputCntrLoc], 1);
		}
	}
}

uint8 KEYPAD_u8GetPressedKey(uint8 u8KeypadIndxCpy)
{
	// enter cfg for keypad selected by indx
	// loop # of column
	  // send sequence
	  // scan inputs
	  // check scaned input
		// if scaned input  == 0
		// intersection seq and input row is pressed key
		// else Donothing
	// return pressed key or 0xFF in case no button pressed

	uint8 u8CntrLoc;
	uint8 u8ReturnLoc = 0xFF;
	uint8 u8RowIndxLoc;

	for (u8CntrLoc = 0; u8CntrLoc < KEYPAD_astrConfigSet[u8KeypadIndxCpy].u8ColOutputNum; ++u8CntrLoc)
	{
		SendSeq(u8CntrLoc, u8KeypadIndxCpy);
		u8RowIndxLoc = SendCheckInput(u8KeypadIndxCpy);

		if (u8RowIndxLoc != 0xFF)
		{
			u8ReturnLoc = KEYPAD_astrConfigSet[u8KeypadIndxCpy].au8KeypadMatrix[u8RowIndxLoc][u8CntrLoc];
			break;
		}
	}

	return u8ReturnLoc;
}

static void SendSeq(uint8 u8SeqNumCpy, uint8 u8KeypadIndxCpy)
{

	uint8 u8CntrLoc;

	for (u8CntrLoc = 0; u8CntrLoc < KEYPAD_astrConfigSet[u8KeypadIndxCpy].u8ColOutputNum; ++u8CntrLoc)
	{
		if (u8SeqNumCpy == u8CntrLoc)
		{
			DIO_enumWritePin(KEYPAD_astrConfigSet[u8KeypadIndxCpy].au8ColOutputDioConc[u8CntrLoc], 0);
		}
		else
		{
			DIO_enumWritePin(KEYPAD_astrConfigSet[u8KeypadIndxCpy].au8ColOutputDioConc[u8CntrLoc], 1);
		}
	}
}

static uint8 SendCheckInput(uint8 u8KeypadIndxCpy)
{

	uint8 u8CntrLoc ;
	uint8 u8ValLoc ;
	uint8 u8IndxRowLoc = 0xFF ;

	for(u8CntrLoc = 0  ; u8CntrLoc < KEYPAD_astrConfigSet[u8KeypadIndxCpy].u8RowInputNum ; u8CntrLoc++)
	{
		DIO_enumReadPin(KEYPAD_astrConfigSet[u8KeypadIndxCpy].au8RowInputDioConc[u8CntrLoc], &u8ValLoc);

		if (u8ValLoc == 0)
		{
			u8IndxRowLoc = u8CntrLoc ;
			break ;
		}
		else
		{
			/*Do nothing*/
		}
	}

	return 	u8IndxRowLoc ;
}
