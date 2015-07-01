/*******************************************************************************/
/**
\file       window_lifter.h
\brief      
\author     Gilberto Ochoa
\version    1.0
\date       25/06/2015
*/
/*******************************************************************************/

#ifndef _WINDOW_LIFTER_H        /*prevent duplicated includes*/
#define _WINDOW_LIFTER_H

/*-- Includes ----------------------------------------------------------------*/

#include "typedefs.h"

#include "GPIO.h"

/** Core modules */
/** Variable types and common definitions */


/*-- Variables ---------------------------------------------------------------*/


/*-- Types Definitions -------------------------------------------------------*/

enum ESTATUS
{
	IDLE,
	MANUAL_UP,
	MANUAL_DOWN,
	AUTOMATIC_UP_ACTION,
	AUTOMATIC_DOWN_ACTION,
	ANTIPINCH,
	DELAY_5_SECONDS
};

/*-- Defines -----------------------------------------------------------------*/

#define ZERO_MILLISECONDS           0
#define TEN_MILLISECONDS            10
#define FIVE_HUNDRED_MILLISECONDS   500
#define FOUR_HUNDRED_MILLISECONDS   400
#define FIVE_SECONDS                5000

/*-- Function Prototypes -----------------------------------------------------*/

void State_Machine(void);

#endif /* _WINDOW_LIFTER_H */

/*******************************************************************************/
