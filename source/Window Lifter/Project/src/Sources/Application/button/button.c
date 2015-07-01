/*============================================================================*/
/*                        SV C CE SOFTWARE GROUP                              */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*
* C Source:        button,c         
* version:         1.0
* created_by:      Gilberto Ochoa
* date_created:    Mon Jun 22 2015
*=============================================================================*/
/* DESCRIPTION : C source template file                                       */
/*============================================================================*/
/* FUNCTION COMMENT : This file works with the buttons selection              */
/* Button Up & Button Down, Evaluate the rebound in the button                */
/*                                                                            */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |                               |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/*  1.0      | 22/06/2015  |                               | Gilberto Ochoa   */
/* Start of this file                                                         */
/*============================================================================*/
/*  1.1      | 30/06/2015  |                               | Gilberto Ochoa   */
/* Organization of Private functions prototypes                               */
/*============================================================================*/


/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */

/** Own headers */
#include "button.h"

/* GPIO routines prototypes */ 
#include "GPIO.h"

/* GPIO routines prototypes */ 
#include "window_lifter.h"


/* Functions macros, constants, types and datas         */
/* ---------------------------------------------------- */
/* Functions macros */

/*==================================================*/ 
/* Definition of constants                          */
/*==================================================*/ 
/* BYTE constants */


/* WORD constants */


/* LONG and STRUCTURE constants */



/*======================================================*/ 
/* Definition of RAM variables                          */
/*======================================================*/ 
/* BYTE RAM variables */
extern T_UBYTE rub_State;
extern T_UWORD ruw_time_button;

/* WORD RAM variables */


/* LONG and STRUCTURE RAM variables */


/*======================================================*/ 
/* close variable declaration sections                  */
/*======================================================*/ 

/* Private defines */


/* Private functions prototypes */
/* ---------------------------- */
void selector_down(void);
void selector_up(void);


/* Exported functions prototypes */
/* ----------------------------- */


/* Exported functions */
/* ------------------ */
/**************************************************************
 *  Name                 :	Evaluate_bounce_button
 *  Created by           :  Gilberto Ochoa
 *  Description          :  Evaluate if the button is pressed for more than 10 milliseconds
 *  Parameters           :  void
 *  Return               :  void
 *  Critical/explanation :  NO
 **************************************************************/
void Evaluate_bounce_button(void)
{
	if((BUTTON_DOWN == BTN_ACTIVE) && (BUTTON_UP == BTN_INACTIVE))
	{	
		ruw_time_button++;                       /*Increases time to 10 milliseconds*/
		if(ruw_time_button>=TEN_MILLISECONDS)
		{
			selector_down();                     /* In this Part the time is 10 milliseconds*/
		}
	}
			
			
	else if((BUTTON_DOWN == BTN_INACTIVE) && (BUTTON_UP == BTN_ACTIVE))
	{		
		ruw_time_button++;	             /*Increases time to 10 milliseconds*/
		if(ruw_time_button>=TEN_MILLISECONDS)
		{
			selector_up();
		}
	}
			
	else
	{
		ruw_time_button=ZERO_MILLISECONDS;
	}
}    /* End Evaluate_bounce_button*/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : selector_down
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate if the button is pressed for 500 Milliseconds to send the next state
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : NO
 **************************************************************/
void selector_down(void)
{
	if(BUTTON_DOWN == BTN_ACTIVE)
	{
		ruw_time_button++;     /* In this Part the time is 11 milliseconds*/
		if((ruw_time_button>TEN_MILLISECONDS) && (ruw_time_button<FIVE_HUNDRED_MILLISECONDS)) 
		{
			rub_State=AUTOMATIC_DOWN_ACTION;
		}
	}
			
	else
	{
		rub_State=IDLE;
		ruw_time_button=ZERO_MILLISECONDS;
	}
}   /* End selector_down*/



/* Private functions */
/* ----------------- */
/**************************************************************
 *  Name                 : selector_up
 *  Created by           : Gilberto Ochoa
 *  Description          : Evaluate if the button is pressed for 500 Milliseconds to send the next state
 *  Parameters           : void
 *  Return               : void
 *  Critical/explanation : NO
 **************************************************************/
void selector_up(void)
{
	if(BUTTON_UP == BTN_ACTIVE)
	{	
		ruw_time_button++;   /* In this Part the time is 11 seconds*/
		if((ruw_time_button>TEN_MILLISECONDS) && (ruw_time_button<FIVE_HUNDRED_MILLISECONDS))
		{
			rub_State=AUTOMATIC_UP_ACTION;
	    }
	}
			
	else
	{
		ruw_time_button=ZERO_MILLISECONDS;
		rub_State=IDLE;
	}
}   /* End selector_up*/