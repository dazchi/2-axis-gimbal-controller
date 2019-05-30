/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name		: Interrupt_CMT.c
* Version		: 1.01
* Contents		: Interrupt handlers for the CMT channels
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

#include "r_pdl_cmt.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_CMTn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for CMT channel n
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: CMT_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_CMT0_CMI0
#pragma interrupt Interrupt_CMT0(vect=VECT_CMT0_CMI0, fint)
#else
#pragma interrupt Interrupt_CMT0(vect=VECT_CMT0_CMI0)
#endif
void Interrupt_CMT0(void)
{
	if (rpdl_CMT_one_shot[0] != false)
	{
		/* Stop the channel 0 clock input */
		CMT.CMSTR0.BIT.STR0 = 0;

		/* Clear the interrupt request flag (the timer may have set it again) */
		ICU.IR[IR_CMT0_CMI0].BIT.IR = 0;
	}

	/* Call the user function */
	if (rpdl_CMT_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_CMT_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_CMT1_CMI1
#pragma interrupt Interrupt_CMT1(vect=VECT_CMT1_CMI1, fint)
#else
#pragma interrupt Interrupt_CMT1(vect=VECT_CMT1_CMI1)
#endif
void Interrupt_CMT1(void)
{
	if (rpdl_CMT_one_shot[1] != false)
	{
		/* Stop the channel 0 clock input */
		CMT.CMSTR0.BIT.STR1 = 0;

		/* Clear the interrupt request flag (the timer may have set it again) */
		ICU.IR[IR_CMT1_CMI1].BIT.IR = 0;
	}

	/* Call the user function */
	if (rpdl_CMT_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_CMT_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_CMT2_CMI2
#pragma interrupt Interrupt_CMT2(vect=VECT_CMT2_CMI2, fint)
#else
#pragma interrupt Interrupt_CMT2(vect=VECT_CMT2_CMI2)
#endif
void Interrupt_CMT2(void)
{
	if (rpdl_CMT_one_shot[2] != false)
	{
		/* Stop the channel 0 clock input */
		CMT.CMSTR1.BIT.STR2 = 0;

		/* Clear the interrupt request flag (the timer may have set it again) */
		ICU.IR[IR_CMT2_CMI2].BIT.IR = 0;
	}

	/* Call the user function */
	if (rpdl_CMT_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_CMT_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_CMT3_CMI3
#pragma interrupt Interrupt_CMT3(vect=VECT_CMT3_CMI3, fint)
#else
#pragma interrupt Interrupt_CMT3(vect=VECT_CMT3_CMI3)
#endif
void Interrupt_CMT3(void)
{
	if (rpdl_CMT_one_shot[3] != false)
	{
		/* Stop the channel 0 clock input */
		CMT.CMSTR1.BIT.STR3 = 0;

		/* Clear the interrupt request flag (the timer may have set it again) */
		ICU.IR[IR_CMT3_CMI3].BIT.IR = 0;
	}

	/* Call the user function */
	if (rpdl_CMT_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_CMT_callback_func[3]();
	}
}
/* End of file */
