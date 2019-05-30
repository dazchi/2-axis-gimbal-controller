/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name		: Interrupt_LIN.c
* Version		: 1.01
* Contents		: Interrupt handlers for all LIN channels
* Customer		: 
* Model			: 
* Order			: 
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

#include "r_pdl_lin.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline: LINn interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_LINn_LINn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: None
*-------------------------------------------------------------------
* Use function	: rpdl_LIN_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_LIN0_LIN0
#pragma interrupt Interrupt_LIN0_LIN0(vect=VECT_LIN0_LIN0, fint)
#else
#pragma interrupt Interrupt_LIN0_LIN0(vect=VECT_LIN0_LIN0)
#endif
void Interrupt_LIN0_LIN0(void)
{
	/* Notify the user */
	if (rpdl_LIN_callback_func != PDL_NO_FUNC)
	{
		/* Notify the user */
		rpdl_LIN_callback_func();
	}
}

/* End of file */
