/*""FILE COMMENT""*******************************************************
* System Name	: 12-bit ADC Interrupt program for RX62Txx
* File Name 	: Interrupt_ADC_12.c
* Version		: 1.01
* Contents		: Interrupt handler for ADC_12
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

#include "r_pdl_adc_12.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline: ADC interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_ADCn(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for ADC unit n
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_ADC_12_callback_func[n]()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_S12AD0_S12ADI0
#pragma interrupt Interrupt_ADC_12_0(vect=VECT_S12AD0_S12ADI0, fint)
#else
#pragma interrupt Interrupt_ADC_12_0(vect=VECT_S12AD0_S12ADI0)
#endif
void Interrupt_ADC_12_0(void)
{
	/* Call the user function */
	if (rpdl_ADC_12_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_ADC_12_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_S12AD1_S12ADI1
#pragma interrupt Interrupt_ADC_12_1(vect=VECT_S12AD1_S12ADI1, fint)
#else
#pragma interrupt Interrupt_ADC_12_1(vect=VECT_S12AD1_S12ADI1)
#endif
void Interrupt_ADC_12_1(void)
{
	/* Call the user function */
	if (rpdl_ADC_12_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_ADC_12_callback_func[1]();
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: Comparator interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_ADC_12_Cmp(void)
*-------------------------------------------------------------------
* Function		: Interrupt processing function for comparator
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Input			: 
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_ADC_12_cmp_callback_func()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_S12AD_CMPI
#pragma interrupt Interrupt_ADC_12_Cmp(vect=VECT_S12AD_CMPI, fint)
#else
#pragma interrupt Interrupt_ADC_12_Cmp(vect=VECT_S12AD_CMPI)
#endif
void Interrupt_ADC_12_Cmp(void)
{
	/* Call the user function */
	if (rpdl_ADC_12_cmp_callback_func != PDL_NO_FUNC)
	{
		rpdl_ADC_12_cmp_callback_func();
	}
}

/* End of file */
