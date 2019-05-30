/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name		: Interrupt_MTU3.c
* Version		: 1.01
* Contents		: Interrupt handlers for the MTU channels
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

#include "r_pdl_mtu3.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIA0(void)
*-------------------------------------------------------------------
* Function		: TGIAn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func1_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TGIA0
#pragma interrupt Interrupt_MTU0_TGIA0(vect=VECT_MTU0_TGIA0, fint)
#else
#pragma interrupt Interrupt_MTU0_TGIA0(vect=VECT_MTU0_TGIA0)
#endif
void Interrupt_MTU0_TGIA0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU1_TGIA1
#pragma interrupt Interrupt_MTU1_TGIA1(vect=VECT_MTU1_TGIA1, fint)
#else
#pragma interrupt Interrupt_MTU1_TGIA1(vect=VECT_MTU1_TGIA1)
#endif
void Interrupt_MTU1_TGIA1(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU2_TGIA2
#pragma interrupt Interrupt_MTU2_TGIA2(vect=VECT_MTU2_TGIA2, fint)
#else
#pragma interrupt Interrupt_MTU2_TGIA2(vect=VECT_MTU2_TGIA2)
#endif
void Interrupt_MTU2_TGIA2(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU3_TGIA3
#pragma interrupt Interrupt_MTU3_TGIA3(vect=VECT_MTU3_TGIA3, fint)
#else
#pragma interrupt Interrupt_MTU3_TGIA3(vect=VECT_MTU3_TGIA3)
#endif
void Interrupt_MTU3_TGIA3(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[3]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU4_TGIA4
#pragma interrupt Interrupt_MTU4_TGIA4(vect=VECT_MTU4_TGIA4, fint)
#else
#pragma interrupt Interrupt_MTU4_TGIA4(vect=VECT_MTU4_TGIA4)
#endif
void Interrupt_MTU4_TGIA4(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[4] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[4]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU6_TGIA6
#pragma interrupt Interrupt_MTU6_TGIA6(vect=VECT_MTU6_TGIA6, fint)
#else
#pragma interrupt Interrupt_MTU6_TGIA6(vect=VECT_MTU6_TGIA6)
#endif
void Interrupt_MTU6_TGIA6(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[6] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[6]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU7_TGIA7
#pragma interrupt Interrupt_MTU7_TGIA7(vect=VECT_MTU7_TGIA7, fint)
#else
#pragma interrupt Interrupt_MTU7_TGIA7(vect=VECT_MTU7_TGIA7)
#endif
void Interrupt_MTU7_TGIA7(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[7] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[7]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIBn(void)
*-------------------------------------------------------------------
* Function		: TGIBn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func2_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TGIB0
#pragma interrupt Interrupt_MTU0_TGIB0(vect=VECT_MTU0_TGIB0, fint)
#else
#pragma interrupt Interrupt_MTU0_TGIB0(vect=VECT_MTU0_TGIB0)
#endif
void Interrupt_MTU0_TGIB0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU1_TGIB1
#pragma interrupt Interrupt_MTU1_TGIB1(vect=VECT_MTU1_TGIB1, fint)
#else
#pragma interrupt Interrupt_MTU1_TGIB1(vect=VECT_MTU1_TGIB1)
#endif
void Interrupt_MTU1_TGIB1(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU2_TGIB2
#pragma interrupt Interrupt_MTU2_TGIB2(vect=VECT_MTU2_TGIB2, fint)
#else
#pragma interrupt Interrupt_MTU2_TGIB2(vect=VECT_MTU2_TGIB2)
#endif
void Interrupt_MTU2_TGIB2(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU3_TGIB3
#pragma interrupt Interrupt_MTU3_TGIB3(vect=VECT_MTU3_TGIB3, fint)
#else
#pragma interrupt Interrupt_MTU3_TGIB3(vect=VECT_MTU3_TGIB3)
#endif
void Interrupt_MTU3_TGIB3(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[3]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU4_TGIB4
#pragma interrupt Interrupt_MTU4_TGIB4(vect=VECT_MTU4_TGIB4, fint)
#else
#pragma interrupt Interrupt_MTU4_TGIB4(vect=VECT_MTU4_TGIB4)
#endif
void Interrupt_MTU4_TGIB4(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[4] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[4]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU6_TGIB6
#pragma interrupt Interrupt_MTU6_TGIB6(vect=VECT_MTU6_TGIB6, fint)
#else
#pragma interrupt Interrupt_MTU6_TGIB6(vect=VECT_MTU6_TGIB6)
#endif
void Interrupt_MTU6_TGIB6(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[6] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[6]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU7_TGIB7
#pragma interrupt Interrupt_MTU7_TGIB7(vect=VECT_MTU7_TGIB7, fint)
#else
#pragma interrupt Interrupt_MTU7_TGIB7(vect=VECT_MTU7_TGIB7)
#endif
void Interrupt_MTU7_TGIB7(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[7] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[7]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGICn(void)
*-------------------------------------------------------------------
* Function		: TGICn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func3_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TGIC0
#pragma interrupt Interrupt_MTU0_TGIC0(vect=VECT_MTU0_TGIC0, fint)
#else
#pragma interrupt Interrupt_MTU0_TGIC0(vect=VECT_MTU0_TGIC0)
#endif
void Interrupt_MTU0_TGIC0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func3_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func3_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU3_TGIC3
#pragma interrupt Interrupt_MTU3_TGIC3(vect=VECT_MTU3_TGIC3, fint)
#else
#pragma interrupt Interrupt_MTU3_TGIC3(vect=VECT_MTU3_TGIC3)
#endif
void Interrupt_MTU3_TGIC3(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func3_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func3_callback_func[3]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU4_TGIC4
#pragma interrupt Interrupt_MTU4_TGIC4(vect=VECT_MTU4_TGIC4, fint)
#else
#pragma interrupt Interrupt_MTU4_TGIC4(vect=VECT_MTU4_TGIC4)
#endif
void Interrupt_MTU4_TGIC4(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func3_callback_func[4] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func3_callback_func[4]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU6_TGIC6
#pragma interrupt Interrupt_MTU6_TGIC6(vect=VECT_MTU6_TGIC6, fint)
#else
#pragma interrupt Interrupt_MTU6_TGIC6(vect=VECT_MTU6_TGIC6)
#endif
void Interrupt_MTU6_TGIC6(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func3_callback_func[6] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func3_callback_func[6]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU7_TGIC7
#pragma interrupt Interrupt_MTU7_TGIC7(vect=VECT_MTU7_TGIC7, fint)
#else
#pragma interrupt Interrupt_MTU7_TGIC7(vect=VECT_MTU7_TGIC7)
#endif
void Interrupt_MTU7_TGIC7(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func3_callback_func[7] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func3_callback_func[7]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIDn(void)
*-------------------------------------------------------------------
* Function		: TGIDn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func4_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TGID0
#pragma interrupt Interrupt_MTU0_TGID0(vect=VECT_MTU0_TGID0, fint)
#else
#pragma interrupt Interrupt_MTU0_TGID0(vect=VECT_MTU0_TGID0)
#endif
void Interrupt_MTU0_TGID0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func4_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func4_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU3_TGID3
#pragma interrupt Interrupt_MTU3_TGID3(vect=VECT_MTU3_TGID3, fint)
#else
#pragma interrupt Interrupt_MTU3_TGID3(vect=VECT_MTU3_TGID3)
#endif
void Interrupt_MTU3_TGID3(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func4_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func4_callback_func[3]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU4_TGID4
#pragma interrupt Interrupt_MTU4_TGID4(vect=VECT_MTU4_TGID4, fint)
#else
#pragma interrupt Interrupt_MTU4_TGID4(vect=VECT_MTU4_TGID4)
#endif
void Interrupt_MTU4_TGID4(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func4_callback_func[4] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func4_callback_func[4]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU6_TGID6
#pragma interrupt Interrupt_MTU6_TGID6(vect=VECT_MTU6_TGID6, fint)
#else
#pragma interrupt Interrupt_MTU6_TGID6(vect=VECT_MTU6_TGID6)
#endif
void Interrupt_MTU6_TGID6(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func4_callback_func[6] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func4_callback_func[6]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU7_TGID7
#pragma interrupt Interrupt_MTU7_TGID7(vect=VECT_MTU7_TGID7, fint)
#else
#pragma interrupt Interrupt_MTU7_TGID7(vect=VECT_MTU7_TGID7)
#endif
void Interrupt_MTU7_TGID7(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func4_callback_func[7] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func4_callback_func[7]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIEn(void)
*-------------------------------------------------------------------
* Function		: TGIEn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_TGRE_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TGIE0
#pragma interrupt Interrupt_MTU0_TGIE0(vect=VECT_MTU0_TGIE0, fint)
#else
#pragma interrupt Interrupt_MTU0_TGIE0(vect=VECT_MTU0_TGIE0)
#endif
void Interrupt_MTU0_TGIE0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_TGRE_callback_func != PDL_NO_FUNC)
	{
		rpdl_MTU3_TGRE_callback_func();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIFn(void)
*-------------------------------------------------------------------
* Function		: TGIFn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_TGRF_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TGIF0
#pragma interrupt Interrupt_MTU0_TGIF0(vect=VECT_MTU0_TGIF0, fint)
#else
#pragma interrupt Interrupt_MTU0_TGIF0(vect=VECT_MTU0_TGIF0)
#endif
void Interrupt_MTU0_TGIF0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_TGRF_callback_func != PDL_NO_FUNC)
	{
		rpdl_MTU3_TGRF_callback_func();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TCIVn(void)
*-------------------------------------------------------------------
* Function		: TCIVn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_Overflow_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU0_TCIV0
#pragma interrupt Interrupt_MTU0_TCIV0(vect=VECT_MTU0_TCIV0, fint)
#else
#pragma interrupt Interrupt_MTU0_TCIV0(vect=VECT_MTU0_TCIV0)
#endif
void Interrupt_MTU0_TCIV0(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU1_TCIV1
#pragma interrupt Interrupt_MTU1_TCIV1(vect=VECT_MTU1_TCIV1, fint)
#else
#pragma interrupt Interrupt_MTU1_TCIV1(vect=VECT_MTU1_TCIV1)
#endif
void Interrupt_MTU1_TCIV1(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU2_TCIV2
#pragma interrupt Interrupt_MTU2_TCIV2(vect=VECT_MTU2_TCIV2, fint)
#else
#pragma interrupt Interrupt_MTU2_TCIV2(vect=VECT_MTU2_TCIV2)
#endif
void Interrupt_MTU2_TCIV2(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[2]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU3_TCIV3
#pragma interrupt Interrupt_MTU3_TCIV3(vect=VECT_MTU3_TCIV3, fint)
#else
#pragma interrupt Interrupt_MTU3_TCIV3(vect=VECT_MTU3_TCIV3)
#endif
void Interrupt_MTU3_TCIV3(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[3] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[3]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU4_TCIV4
#pragma interrupt Interrupt_MTU4_TCIV4(vect=VECT_MTU4_TCIV4, fint)
#else
#pragma interrupt Interrupt_MTU4_TCIV4(vect=VECT_MTU4_TCIV4)
#endif
void Interrupt_MTU4_TCIV4(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[4] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[4]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU6_TCIV6
#pragma interrupt Interrupt_MTU6_TCIV6(vect=VECT_MTU6_TCIV6, fint)
#else
#pragma interrupt Interrupt_MTU6_TCIV6(vect=VECT_MTU6_TCIV6)
#endif
void Interrupt_MTU6_TCIV6(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[6] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[6]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU7_TCIV7
#pragma interrupt Interrupt_MTU7_TCIV7(vect=VECT_MTU7_TCIV7, fint)
#else
#pragma interrupt Interrupt_MTU7_TCIV7(vect=VECT_MTU7_TCIV7)
#endif
void Interrupt_MTU7_TCIV7(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Overflow_callback_func[7] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Overflow_callback_func[7]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TCIUn(void)
*-------------------------------------------------------------------
* Function		: TCIUn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_Underflow_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU1_TCIU1
#pragma interrupt Interrupt_MTU1_TCIU1(vect=VECT_MTU1_TCIU1, fint)
#else
#pragma interrupt Interrupt_MTU1_TCIU1(vect=VECT_MTU1_TCIU1)
#endif
void Interrupt_MTU1_TCIU1(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Underflow_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Underflow_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_MTU2_TCIU2
#pragma interrupt Interrupt_MTU2_TCIU2(vect=VECT_MTU2_TCIU2, fint)
#else
#pragma interrupt Interrupt_MTU2_TCIU2(vect=VECT_MTU2_TCIU2)
#endif
void Interrupt_MTU2_TCIU2(void)
{
	/* Call the user function */
	if (rpdl_MTU3_Underflow_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_MTU3_Underflow_callback_func[2]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIUn(void)
*-------------------------------------------------------------------
* Function		: TGIUn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func1_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU5_TGIU5
#pragma interrupt Interrupt_MTU5_TGIU5(vect=VECT_MTU5_TGIU5, fint)
#else
#pragma interrupt Interrupt_MTU5_TGIU5(vect=VECT_MTU5_TGIU5)
#endif
void Interrupt_MTU5_TGIU5(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func1_callback_func[5] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func1_callback_func[5]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIVn(void)
*-------------------------------------------------------------------
* Function		: TGIVn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func2_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU5_TGIV5
#pragma interrupt Interrupt_MTU5_TGIV5(vect=VECT_MTU5_TGIV5, fint)
#else
#pragma interrupt Interrupt_MTU5_TGIV5(vect=VECT_MTU5_TGIV5)
#endif
void Interrupt_MTU5_TGIV5(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func2_callback_func[5] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func2_callback_func[5]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Timer interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_MTUn_TGIWn(void)
*-------------------------------------------------------------------
* Function		: TGIWn interrupt processing
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_MTU3_func3_callback_func[n]
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_MTU5_TGIW5
#pragma interrupt Interrupt_MTU5_TGIW5(vect=VECT_MTU5_TGIW5, fint)
#else
#pragma interrupt Interrupt_MTU5_TGIW5(vect=VECT_MTU5_TGIW5)
#endif
void Interrupt_MTU5_TGIW5(void)
{
	/* Call the user function */
	if (rpdl_MTU3_func3_callback_func[5] != PDL_NO_FUNC)
	{
		rpdl_MTU3_func3_callback_func[5]();
	}
}

/* End of file */
