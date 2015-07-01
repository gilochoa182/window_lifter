
#include "MCU_derivative.h"


/*****************************************************************************************************
* Include files
*****************************************************************************************************/

#include    "GPIO.h"
#include    "PIT.h"
#include    "window_lifter.h"


/****************************************************************************************************
* Declaration of module wide FUNCTIONs 
*****************************************************************************************************/

void disableWatchdog(void) 
{
  SWT.SR.R = 0x0000c520;     /* Write keys to clear soft lock bit */
  SWT.SR.R = 0x0000d928; 
  SWT.CR.R = 0x8000010A;     /* Clear watchdog enable (WEN) */
}
 

/*~~~~~~~ Main Code ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
int main(void) 

{
	initModesAndClock();
	
	/* Disable Watchdog */
	disableWatchdog();
	
	/*Initialize LEDs on TRK-MPC560xB board */
	EmbIOs_Config();
	
	/*Initialize Interrupts */
	INTC_InitINTCInterrupts();
	
	/*Initialize Exception Handlers */
	EXCEP_InitExceptionHandlers();
	
	PIT_device_init();
    PIT_channel_configure(PIT_CHANNEL_0 , State_Machine);	
    PIT_channel_start(PIT_CHANNEL_0);
    
    /* Enable External Interrupts*/
    enableIrq();
    
	/* Infinite loop */	
	for (;;) 
	{	
	}
}