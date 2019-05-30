/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name		: Interrupt_GPT.c
* Version		: 1.01
* Contents		: Interrupt handlers for the GPT channels
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

#include "r_pdl_gpt.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_GTCIAn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing for A events
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_GPT_GTCIA_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_GPT0_GTCIA0
#pragma interrupt Interrupt_GTCIA0(vect=VECT_GPT0_GTCIA0, fint)
#else
#pragma interrupt Interrupt_GTCIA0(vect=VECT_GPT0_GTCIA0)
#endif
void Interrupt_GTCIA0(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIA_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIA_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT1_GTCIA1
#pragma interrupt Interrupt_GTCIA1(vect=VECT_GPT1_GTCIA1, fint)
#else
#pragma interrupt Interrupt_GTCIA1(vect=VECT_GPT1_GTCIA1)
#endif
void Interrupt_GTCIA1(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIA_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIA_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT2_GTCIA2
#pragma interrupt Interrupt_GTCIA2(vect=VECT_GPT2_GTCIA2, fint)
#else
#pragma interrupt Interrupt_GTCIA2(vect=VECT_GPT2_GTCIA2)
#endif
void Interrupt_GTCIA2(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIA_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIA_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT3_GTCIA3
#pragma interrupt Interrupt_GTCIA3(vect=VECT_GPT3_GTCIA3, fint)
#else
#pragma interrupt Interrupt_GTCIA3(vect=VECT_GPT3_GTCIA3)
#endif
void Interrupt_GTCIA3(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIA_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIA_callback_func[3]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_GTCIBn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing for B events
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_GPT_CMICB_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_GPT0_GTCIB0
#pragma interrupt Interrupt_GTCIB0(vect=VECT_GPT0_GTCIB0, fint)
#else
#pragma interrupt Interrupt_GTCIB0(vect=VECT_GPT0_GTCIB0)
#endif
void Interrupt_GTCIB0(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIB_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIB_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT1_GTCIB1
#pragma interrupt Interrupt_GTCIB1(vect=VECT_GPT1_GTCIB1, fint)
#else
#pragma interrupt Interrupt_GTCIB1(vect=VECT_GPT1_GTCIB1)
#endif
void Interrupt_GTCIB1(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIB_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIB_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT2_GTCIB2
#pragma interrupt Interrupt_GTCIB2(vect=VECT_GPT2_GTCIB2, fint)
#else
#pragma interrupt Interrupt_GTCIB2(vect=VECT_GPT2_GTCIB2)
#endif
void Interrupt_GTCIB2(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIB_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIB_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT3_GTCIB3
#pragma interrupt Interrupt_GTCIB3(vect=VECT_GPT3_GTCIB3, fint)
#else
#pragma interrupt Interrupt_GTCIB3(vect=VECT_GPT3_GTCIB3)
#endif
void Interrupt_GTCIB3(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIB_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIB_callback_func[3]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_GTCICn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing for C / D / dead-time events
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_GPT_GTCIC_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_GPT0_GTCIC0
#pragma interrupt Interrupt_GTCIC0(vect=VECT_GPT0_GTCIC0, fint)
#else
#pragma interrupt Interrupt_GTCIC0(vect=VECT_GPT0_GTCIC0)
#endif
void Interrupt_GTCIC0(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIC_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIC_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT1_GTCIC1
#pragma interrupt Interrupt_GTCIC1(vect=VECT_GPT1_GTCIC1, fint)
#else
#pragma interrupt Interrupt_GTCIC1(vect=VECT_GPT1_GTCIC1)
#endif
void Interrupt_GTCIC1(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIC_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIC_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT2_GTCIC2
#pragma interrupt Interrupt_GTCIC2(vect=VECT_GPT2_GTCIC2, fint)
#else
#pragma interrupt Interrupt_GTCIC2(vect=VECT_GPT2_GTCIC2)
#endif
void Interrupt_GTCIC2(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIC_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIC_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT3_GTCIC3
#pragma interrupt Interrupt_GTCIC3(vect=VECT_GPT3_GTCIC3, fint)
#else
#pragma interrupt Interrupt_GTCIC3(vect=VECT_GPT3_GTCIC3)
#endif
void Interrupt_GTCIC3(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIC_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIC_callback_func[3]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_GTCIEn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing for E / F events
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_GPT_GTCIE_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_GPT0_GTCIE0
#pragma interrupt Interrupt_GTCIE0(vect=VECT_GPT0_GTCIE0, fint)
#else
#pragma interrupt Interrupt_GTCIE0(vect=VECT_GPT0_GTCIE0)
#endif
void Interrupt_GTCIE0(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIE_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIE_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT1_GTCIE1
#pragma interrupt Interrupt_GTCIE1(vect=VECT_GPT1_GTCIE1, fint)
#else
#pragma interrupt Interrupt_GTCIE1(vect=VECT_GPT1_GTCIE1)
#endif
void Interrupt_GTCIE1(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIE_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIE_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT2_GTCIE2
#pragma interrupt Interrupt_GTCIE2(vect=VECT_GPT2_GTCIE2, fint)
#else
#pragma interrupt Interrupt_GTCIE2(vect=VECT_GPT2_GTCIE2)
#endif
void Interrupt_GTCIE2(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIE_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIE_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT3_GTCIE3
#pragma interrupt Interrupt_GTCIE3(vect=VECT_GPT3_GTCIE3, fint)
#else
#pragma interrupt Interrupt_GTCIE3(vect=VECT_GPT3_GTCIE3)
#endif
void Interrupt_GTCIE3(void)
{
	/* Call the user functions */
	if (rpdl_GPT_GTCIE_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIE_callback_func[3]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_GTCIVn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing for over / underflow events
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_GPT_GTCIV_callback_func[n]
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_GPT0_GTCIV0
#pragma interrupt Interrupt_GTCIV0(vect=VECT_GPT0_GTCIV0, fint)
#else
#pragma interrupt Interrupt_GTCIV0(vect=VECT_GPT0_GTCIV0)
#endif
void Interrupt_GTCIV0(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIV_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIV_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT1_GTCIV1
#pragma interrupt Interrupt_GTCIV1(vect=VECT_GPT1_GTCIV1, fint)
#else
#pragma interrupt Interrupt_GTCIV1(vect=VECT_GPT1_GTCIV1)
#endif
void Interrupt_GTCIV1(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIV_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIV_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT2_GTCIV2
#pragma interrupt Interrupt_GTCIV2(vect=VECT_GPT2_GTCIV2, fint)
#else
#pragma interrupt Interrupt_GTCIV2(vect=VECT_GPT2_GTCIV2)
#endif
void Interrupt_GTCIV2(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIV_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIV_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_GPT3_GTCIV3
#pragma interrupt Interrupt_GTCIV3(vect=VECT_GPT3_GTCIV3, fint)
#else
#pragma interrupt Interrupt_GTCIV3(vect=VECT_GPT3_GTCIV3)
#endif
void Interrupt_GTCIV3(void)
{
	/* Call the user function */
	if (rpdl_GPT_GTCIV_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_GPT_GTCIV_callback_func[3]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline : Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_LOCO1(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing for LOCO events
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			:
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_GPT_LOCO_callback_func
*-------------------------------------------------------------------
* Notes			:
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_GPT0_LOCO1
#pragma interrupt Interrupt_LOCO1(vect=VECT_GPT0_LOCO1, fint)
#else
#pragma interrupt Interrupt_LOCO1(vect=VECT_GPT0_LOCO1)
#endif
void Interrupt_LOCO1(void)
{
	/* Call the user function */
	if (rpdl_GPT_LOCO_callback_func != PDL_NO_FUNC)
	{
		rpdl_GPT_LOCO_callback_func();
	}
}

/* End of file */
