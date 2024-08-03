/*****************************************************/
/*Discription  : TC72 Driver configuration file      */
/*Author       : Marwan Tamer                        */
/*version 	   : 1.0V   on  1 Aug 2024               */
/*****************************************************/
#include "STD_Types.h"

#include "TC72_cnfg.h"
#include "TC72_priv.h"

tstrTC72Info TC72_astrConfigSet[TC72_MAX_NUM] =
{
		/* All Config  for TC72 0 */
		{
			/*u8SCKpin*/
			4 ,
			/*u8CEpin*/
			5 ,
			/*u8SDIpin*/
			19
			/*u8SDOpin*/
			20
		}
};
