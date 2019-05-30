/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name		: Interrupt_WDT.c
* Version		: 1.01
* Contents		: Interrupt handler for the Watchdog timer
* Customer		: 
* Model		 	:
* Order		 	:
* CPU			: RX
* Compiler		: RXC
* OS			: Nothing
* Programmer	: 
* Note			: 
************************************************************************
* Copyright, 2011. Renesas Electronics Corporation
* and Renesas Solutions Corporation
************************************************************************
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FILE COMMENT END""**************************************************/

#include "r_pdl_wdt.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_WDT(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for the WDT
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: WDT_callback_func
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_WDT_WOVI
#pragma interrupt Interrupt_WDT(vect=VECT_WDT_WOVI, fint)
#else
#pragma interrupt Interrupt_WDT(vect=VECT_WDT_WOVI)
#endif
void Interrupt_WDT(void)
{
	/* Call the user function */
	if (rpdl_WDT_callback_func != PDL_NO_FUNC)
	{
		rpdl_WDT_callback_func();
	}
}
/* End of file */
