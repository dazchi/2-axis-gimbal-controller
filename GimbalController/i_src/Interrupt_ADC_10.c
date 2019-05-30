/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name 	: Interrupt_ADC_10.c
* Version		: 1.01
* Contents		: Interrupt handlers for the 10-bit ADC units
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

#include "r_pdl_adc_10.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline: 10-bit ADC interrupt processing
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
* Use function	: ADC_callback_func[n]()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_AD0_ADI0
#pragma interrupt Interrupt_ADC0(vect=VECT_AD0_ADI0, fint)
#else
#pragma interrupt Interrupt_ADC0(vect=VECT_AD0_ADI0)
#endif
void Interrupt_ADC0(void)
{
#ifdef DEVICE_PACKAGE_LQFP_64
	/* This peripheral is not available on the 64-pin package */
	nop();
#else
	/* Call the user function */
	if (rpdl_ADC_10_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_ADC_10_callback_func[0]();
	}
#endif
}

/* End of file */
