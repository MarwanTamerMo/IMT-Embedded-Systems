/*
 * Keypad_cnfg.c
 *
 *  Created on: May 5, 2024
 *      Author: Marwan
 */
#include "STD_Types.h"

#include "KEYPAD_cnfg.h"
#include "KEYPAD_priv.h"

tstrKeypadInfo KEYPAD_astrConfigSet[KEYPAD_MAX_NUM] =
{
		/* All Config  for Keypad 0 [4x4]*/
		{
			/*u8RowInputNum*/
			4 ,
			/*u8ColOutputNum*/
			4 ,
			/*au8RowInputDioConc*/
			{16,17,18,19},
			/*au8ColOutputDioConc*/
			{20,21,22,23},
			/*au8KeypadMatrix*/
			{
				{'1','2','3','*'},
				{'4','5','6','/'},
				{'7','8','9','+'},
				{'.','0','=','-'}
			}
		}
		#if 0
		,
		/* All Config  for Keypad 1 [5x7]*/
		{
			/*u8RowInputNum*/
			5 ,
			/*u8ColOutputNum*/
			7 ,
			/*au8RowInputDioConc*/
			{0,1,2,3,4},
			/*au8ColOutputDioConc*/
			{5,6,7,8,9,10,11},
			/*au8KeypadMatrix*/
			{
				{'A','B','C','D','E','F','G'},
				{'H','I','J','K','L','M','N'},
				{'O','P','q','r','s','t','u'},
				{'v','w','x','y','z','1','2'},
				{'3','4','5','6','7','8','9'}
			}
		}
		#endif
};
