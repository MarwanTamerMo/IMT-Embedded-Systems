/*
 * EXT2.h
 *
 *  Created on: May 7, 2024
 *      Author: Marwan
 */

#ifndef EXT2_H_
#define EXT2_H_

#define EXT2_RISING    1
#define EXT2_FALLING   0

typedef void (*pf) (void);

void EXT2_vidInit(void);
void EXT2_vidIntEnable(void);
void EXT2_vidIntDisable(void);
void EXT2_vidChangeSense(uint8 u8FormCpy);
void EXT2_vidSetCallback(pf pfCallbackCpy);

#endif /* EXT2_H_ */