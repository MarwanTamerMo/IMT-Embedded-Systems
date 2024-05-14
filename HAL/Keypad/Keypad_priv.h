/*
 * Keypad_priv.h
 *
 *  Created on: May 5, 2024
 *      Author: Marwan
 */

#include "Keypad_cnfg.h"

#ifndef KEYPAD_PRIV_H_
#define KEYPAD_PRIV_H_

#ifndef KEYPAD_MAX_NUM
#define KEYPAD_MAX_NUM       1

#endif

typedef struct
{
	uint8 u8RowInputNum;
	uint8 u8ColOutputNum;

	uint8 au8RowInputDioConc[KEYPAD_MAX_ROW_NUM];
	uint8 au8ColOutputDioConc[KEYPAD_MAX_COL_NUM];

	uint8 au8KeypadMatrix[KEYPAD_MAX_ROW_NUM][KEYPAD_MAX_COL_NUM];

}tstrKeypadInfo;

extern tstrKeypadInfo KEYPAD_astrConfigSet[KEYPAD_MAX_NUM];

#endif /* KEYPAD_PRIV_H_ */
