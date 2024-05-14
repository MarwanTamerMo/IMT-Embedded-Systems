/*
 * DIO.h
 *
 *  Created on: Mar 31, 2024
 *      Author: Marwan
 */

#include "STD_Types.h"

#ifndef DIO_H_
#define DIO_H_

void DIO_vidInit(void); // DIR, Initialize the pins (OUTPUT - INPUT)

tenuErrorStatus DIO_enumWritePin(uint8_t u8pinNumCpy, uint8_t u8pinValCpy); // OUTPUT Value

tenuErrorStatus DIO_enumReadPin(uint8_t u8pinNumCpy, uint8_t* pu8pinValCpy); // Get pin value

tenuErrorStatus DIO_enuActivePullUp(uint8_t u8pinNumCpy, uint8_t u8ResStatusCpy);

#endif /* DIO_H_ */
