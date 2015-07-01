/*******************************************************************************/
/**

\file       GPIO.h
\brief      Macro definitions for registers access and I/O handling
\author     Gilberto Ochoa
\version    1.2
\date       23/06/2015
*/
/*******************************************************************************/

#ifndef _GPIO_H        /*prevent duplicated includes*/
#define _GPIO_H

/*-- Includes ----------------------------------------------------------------*/

/** Core modules */
/** MCU derivative information */
#include "MCU_derivative.h"
/** Variable types and common definitions */
#include "typedefs.h"


/*-- Defines -----------------------------------------------------------------*/

#define on 0
#define off 1

/****Embedded GPIO's****/

#define _LED1      0
#define _LED2      1
#define _LED3      2
#define _LED4      3
#define _LED5      4
#define _LED6      5
#define _LED7      6
#define _LED8      7
#define _LED9      8
#define _LED10      9 
#define _LED_UP    10
#define _LED_DOWN  11


#define _BUTTON1 64
#define _BUTTON2 65
#define _BUTTON3 66
#define _BUTTON4 67


/* Input Buttons */
#define BUTTON_UP        SIU.GPDI[_BUTTON1].B.PDI
#define BUTTON_DOWN      SIU.GPDI[_BUTTON2].B.PDI
#define BUTTON3          SIU.GPDI[_BUTTON3].B.PDI
#define ANTI_PINCH       SIU.GPDI[_BUTTON4].B.PDI

#define BTN_ACTIVE                  0
#define BTN_INACTIVE                1




/*-- Function Prototypes -----------------------------------------------------*/
void EmbIOs_Config(void);
void LED_ON(T_UBYTE lub_Num);
void LED_OFF(T_UBYTE lub_Num);
void LED_TOGGLE(T_UBYTE lub_Num);




#endif /* _GPIO_H */

/*******************************************************************************/
