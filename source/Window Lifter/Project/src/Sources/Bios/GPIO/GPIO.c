/*******************************************************************************/
/**
\file       GPIO.c
\brief      General purpose IO functions
\author     Gilberto Ochoa
\version    1.2
\date       23/06/2015
*/
/****************************************************************************************************/

/*****************************************************************************************************
* Include files
*****************************************************************************************************/

/** Core modules */

/** MCU derivative information */
#include "MCU_derivative.h"

/** Variable types and common definitions */
#include "typedefs.h"

/** Own headers */
/* GPIO routines prototypes */ 
#include "GPIO.h"


/****************************************************************************************************/
/**
* \brief    Configuration diferentes components Embedded 
* \brief    called periodically to operate. 
* \author   Gilberto Ochoa
* \param    void
* \return   void
*/
void EmbIOs_Config(void)
{
	T_UBYTE lub_i;
  
    /* Set Port A as OUTPUT*/
  	for(lub_i=0;lub_i<12;lub_i++)
  	{
  		SIU.PCR[lub_i].R = 0x200;	
  	}
  	
  	SIU.GPDO[10].B.PDO = off;
  	SIU.GPDO[11].B.PDO = off;
  	
  	
  	/* Embedded board buttons seted as inputs */
  	SIU.PCR[_BUTTON1].R = 0x100;	
  	SIU.PCR[_BUTTON2].R = 0x100;
  	SIU.PCR[_BUTTON3].R = 0x100;
  	SIU.PCR[_BUTTON4].R = 0x100;	
}

/****************************************************************************************************/
/**
* \brief    Set LEDS ON
* \brief    
* \author   Gilberto Ochoa
* \param    Num
* \return   void
*/
void LED_ON(T_UBYTE lub_Num)
{
	SIU.GPDO[lub_Num].B.PDO = on;
}


/****************************************************************************************************/
/**
* \brief    Set LEDS OFF
* \brief    
* \author   Gilberto Ochoa
* \param    void
* \return   void
*/
void LED_OFF(T_UBYTE lub_Num)
{
	SIU.GPDO[lub_Num].B.PDO = off;
}

/****************************************************************************************************/
/**
* \brief    Set LEDS TOGGLE
* \brief    
* \author   Gilberto Ochoa
* \param    Num
* \return   void
*/
void LED_TOGGLE(T_UBYTE lub_Num)
{
	SIU.GPDO[lub_Num].B.PDO ^= off;
}