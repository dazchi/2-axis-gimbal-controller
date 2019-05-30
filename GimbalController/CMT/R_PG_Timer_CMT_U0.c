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
* File Name    : R_PG_Timer_CMT_U0.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 30.05.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_Timer_CMT_U0.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Start_CMT_U0_C0(void)
*
* Function Name: R_PG_Timer_Start_CMT_U0_C0
*
* Description  : Set up the CMT and start the count
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_CMT_Create
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_Start_CMT_U0_C0(void)
{
	return R_CMT_Create(
		0,
		PDL_CMT_PCLK_DIV_8 | PDL_CMT_DTC_TRIGGER_DISABLE,
		2499,
		Cmt0IntFunc,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_HaltCount_CMT_U0_C0(void)
*
* Function Name: R_PG_Timer_HaltCount_CMT_U0_C0
*
* Description  : Halt the CMT count
*
* Arguments    : None
*
* Return Value : true  : Halting succeeded.
*              : false : Halting failed.
*
* Calling Functions : R_CMT_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_HaltCount_CMT_U0_C0(void)
{
	return R_CMT_Control(
		0,
		PDL_CMT_STOP,
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_ResumeCount_CMT_U0_C0(void)
*
* Function Name: R_PG_Timer_ResumeCount_CMT_U0_C0
*
* Description  : Resume the CMT count
*
* Arguments    : None
*
* Return Value : true  : Resuming count succeeded.
*              : false : Resuming count failed.
*
* Calling Functions : R_CMT_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_ResumeCount_CMT_U0_C0(void)
{
	return R_CMT_Control(
		0,
		PDL_CMT_START,
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterValue_CMT_U0_C0(uint16_t * counter_val)
*
* Function Name: R_PG_Timer_GetCounterValue_CMT_U0_C0
*
* Description  : Acquire the CMT counter value
*
* Arguments    : uint16_t * counter_val : Destination for storage of the counter value.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_CMT_Read
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetCounterValue_CMT_U0_C0(uint16_t * counter_val)
{
	if( counter_val == 0 ){ return false; }

	return R_CMT_Read(
		0,
		PDL_NO_PTR,
		counter_val
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCounterValue_CMT_U0_C0(uint16_t counter_val)
*
* Function Name: R_PG_Timer_SetCounterValue_CMT_U0_C0
*
* Description  : Set the CMT counter value
*
* Arguments    : uint16_t counter_val : Value to be set to the counter.
*
* Return Value : true  : Setting of the counter value succeeded.
*              : false : Setting of the counter value failed.
*
* Calling Functions : R_CMT_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetCounterValue_CMT_U0_C0(uint16_t counter_val)
{
	return R_CMT_Control(
		0,
		PDL_CMT_COUNTER,
		counter_val
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StopModule_CMT_U0(void)
*
* Function Name: R_PG_Timer_StopModule_CMT_U0
*
* Description  : Shut down the CMT unit
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_CMT_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_StopModule_CMT_U0(void)
{
	return R_CMT_Destroy( 0 );

}



