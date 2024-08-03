/*****************************************************/
/*Description  : TC72 Driver header file      		 */
/*Author       : Marwan Tamer                        */
/*version 	   : 1.0V   on  1 Aug 2024               */
/*****************************************************/

#ifndef TC72_CNFG_H_
#define TC72_CNFG_H_

#include "STD_Types.h"

void TC72_vidInit();
void TC72_vidSelectMode(uint8 u8ModeCpy);
void TC72_vidWriteData(uint8 u8DataCpy);
uint8 TC72_u8ReadData();
void CE_PIN_HIGH();
void CE_PIN_LOW();

#endif /* TC72_CNFG_H_ */
