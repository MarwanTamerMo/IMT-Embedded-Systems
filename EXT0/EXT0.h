/*
 * EXT0.h
 *
 *  Created on: May 7, 2024
 *      Author: Marwan
 */

#ifndef EXT0_H_
#define EXT0_H_

#define EXT0_RISING    0
#define EXT0_FALLING   1
#define EXT0_IOC       2
#define EXT0_LOW_LEVEL 3

typedef void (*pf) (void)  ;

void EXT0_vidInit(void);
void EXT0_vidIntEnable(void);
void EXT0_vidIntDisable(void);
void EXT0_vidChangeSense(uint8 u8FormCpy);
void EXT0_vidSetCallback(pf pfCallbackCpy);

#endif /* EXT0_H_ */
