/******************************************************************************
* DISCLAIMER

* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized.

* This software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.

* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES
* REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
* INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
* PARTICULAR PURPOSE AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY 
* DISCLAIMED.

* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES 
* FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS 
* AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

* Renesas reserves the right, without notice, to make changes to this 
* software and to discontinue the availability of this software.  
* By using this software, you agree to the additional terms and 
* conditions found by accessing the following link:
* http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_ExtInterrupt_IRQ1.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 04.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_ExtInterrupt_IRQ1.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ExtInterrupt_Set_IRQ1(void)
*
* Function Name: R_PG_ExtInterrupt_Set_IRQ1
*
* Description  : Set up the external interrupt
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_INTC_CreateExtInterrupt
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ExtInterrupt_Set_IRQ1(void)
{
	return R_INTC_CreateExtInterrupt(
		PDL_INTC_IRQ1,
		PDL_INTC_RISING | PDL_INTC_A | PDL_INTC_DTC_TRIGGER_DISABLE,
		Irq1IntFunc,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ExtInterrupt_Disable_IRQ1(void)
*
* Function Name: R_PG_ExtInterrupt_Disable_IRQ1
*
* Description  : Disable an external interrupt
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_INTC_ControlExtInterrupt
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ExtInterrupt_Disable_IRQ1(void)
{
	return R_INTC_ControlExtInterrupt(
		PDL_INTC_IRQ1,
		PDL_INTC_DISABLE
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ExtInterrupt_GetRequestFlag_IRQ1(bool * flag)
*
* Function Name: R_PG_ExtInterrupt_GetRequestFlag_IRQ1
*
* Description  : Acquire the external interrupt request flag
*
* Arguments    : bool * flag : The address of storage area for the interrupt request flag.
*
* Return Value : true  : Acquisition of the flag succeeded.
*              : false : Acquisition of the flag failed.
*
* Calling Functions : R_INTC_GetExtInterruptStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ExtInterrupt_GetRequestFlag_IRQ1(bool * flag)
{
	uint8_t data;
	bool res;

	res = R_INTC_GetExtInterruptStatus(
		PDL_INTC_IRQ1,
		&data
	);

	if( flag ){ *flag = data & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ExtInterrupt_ClearRequestFlag_IRQ1(void)
*
* Function Name: R_PG_ExtInterrupt_ClearRequestFlag_IRQ1
*
* Description  : Clear the external interrupt request flag
*
* Arguments    : None
*
* Return Value : true  : Clearing succeeded.
*              : false : Clearing failed.
*
* Calling Functions : R_INTC_ControlExtInterrupt
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ExtInterrupt_ClearRequestFlag_IRQ1(void)
{
	return R_INTC_ControlExtInterrupt(
		PDL_INTC_IRQ1,
		PDL_INTC_CLEAR_IR_FLAG
	);

}



