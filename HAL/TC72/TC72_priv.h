/*****************************************************/
/*Description  : TC72 Driver private file            */
/*Author       : Marwan Tamer                        */
/*version 	   : 1.0V   on  1 Aug 2024               */
/*****************************************************/

#ifndef TC72_PRIV_H_
#define TC72_PRIV_H_

#include "STD_Types.h"

#define CONTROL_REG_WRITE  0x80 // Write to control register
#define CONTROL_REG_READ   0x00 // Read from control register
#define MSB_TEMP_REG       0x02 // MSB Temperature Register
#define LSB_TEMP_REG       0x01 // LSB Temperature Register

//? #define TC72_MAX_NUM       1 
/*
 Removed line 17 because it was for experimental reason (making a cnfg.c file that may contain cnfgs for more than one TC72)
*/

#endif /* TC72_PRIV_H_ */
