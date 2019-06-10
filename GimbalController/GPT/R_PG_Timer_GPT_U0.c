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
* File Name    : R_PG_Timer_GPT_U0.c
* Version      : 1.00
* Device(s)    : 
* Tool-Chain   : 
* H/W Platform : 
* Description  : 
* Limitations  : 
******************************************************************************
* History : 11.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "R_PG_Timer_GPT_U0.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Set_GPT_U0(void)
*
* Function Name: R_PG_Timer_Set_GPT_U0
*
* Description  : Set up the GPT unit
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_Set
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_Set_GPT_U0(void)
{
	return R_GPT_Set( PDL_GPT_PINS_AB_A );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SynchronouslyStartCount_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3)
*
* Function Name: R_PG_Timer_SynchronouslyStartCount_GPT_U0
*
* Description  : Start the GPT unit count
*
* Arguments    : bool gpt0 : Count start setting for GPT0 (1:set 0:do not set)
*              : bool gpt1 : Count start setting for GPT1 (1:set 0:do not set)
*              : bool gpt2 : Count start setting for GPT2 (1:set 0:do not set)
*              : bool gpt3 : Count start setting for GPT3 (1:set 0:do not set)
*
* Return Value : true  : Starting succeeded.
*              : false : Starting failed.
*
* Calling Functions : R_GPT_ControlUnit
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SynchronouslyStartCount_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3)
{
	uint32_t control = 0;

	if( gpt0 == 1 ){
		control |= PDL_GPT_START_CH_0;
	}
	if( gpt1 == 1 ){
		control |= PDL_GPT_START_CH_1;
	}
	if( gpt2 == 1 ){
		control |= PDL_GPT_START_CH_2;
	}
	if( gpt3 == 1 ){
		control |= PDL_GPT_START_CH_3;
	}

	return R_GPT_ControlUnit(
		0,
		control,
		PDL_NO_DATA,
		PDL_NO_DATA
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SynchronouslyHaltCount_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3)
*
* Function Name: R_PG_Timer_SynchronouslyHaltCount_GPT_U0
*
* Description  : Halt the GPT unit count
*
* Arguments    : bool gpt0 : Count halt setting for GPT0 (1:set 0:do not set)
*              : bool gpt1 : Count halt setting for GPT1 (1:set 0:do not set)
*              : bool gpt2 : Count halt setting for GPT2 (1:set 0:do not set)
*              : bool gpt3 : Count halt setting for GPT3 (1:set 0:do not set)
*
* Return Value : true  : Halting succeeded.
*              : false : Halting failed.
*
* Calling Functions : R_GPT_ControlUnit
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SynchronouslyHaltCount_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3)
{
	uint32_t control = 0;

	if( gpt0 == 1 ){
		control |= PDL_GPT_STOP_CH_0;
	}
	if( gpt1 == 1 ){
		control |= PDL_GPT_STOP_CH_1;
	}
	if( gpt2 == 1 ){
		control |= PDL_GPT_STOP_CH_2;
	}
	if( gpt3 == 1 ){
		control |= PDL_GPT_STOP_CH_3;
	}

	return R_GPT_ControlUnit(
		0,
		control,
		PDL_NO_DATA,
		PDL_NO_DATA
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SynchronouslyClearCounter_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3)
*
* Function Name: R_PG_Timer_SynchronouslyClearCounter_GPT_U0
*
* Description  : Clear the GPT unit counter value
*
* Arguments    : bool gpt0 : Counter clear setting for GPT0 (1:set 0:do not set)
*              : bool gpt1 : Counter clear setting for GPT1 (1:set 0:do not set)
*              : bool gpt2 : Counter clear setting for GPT2 (1:set 0:do not set)
*              : bool gpt3 : Counter clear setting for GPT3 (1:set 0:do not set)
*
* Return Value : true  : Clearing succeeded.
*              : false : Clearing failed.
*
* Calling Functions : R_GPT_ControlUnit
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SynchronouslyClearCounter_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3)
{
	uint32_t control = 0;

	if( gpt0 == 1 ){
		control |= PDL_GPT_CLEAR_CH_0;
	}
	if( gpt1 == 1 ){
		control |= PDL_GPT_CLEAR_CH_1;
	}
	if( gpt2 == 1 ){
		control |= PDL_GPT_CLEAR_CH_2;
	}
	if( gpt3 == 1 ){
		control |= PDL_GPT_CLEAR_CH_3;
	}

	return R_GPT_ControlUnit(
		0,
		control,
		PDL_NO_DATA,
		PDL_NO_DATA
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetRequestFlag_GPT_U0(bool * loco_rising, bool * loco_deviation, bool * loco_ov, bool * ext_rising, bool * ext_falling)
*
* Function Name: R_PG_Timer_GetRequestFlag_GPT_U0
*
* Description  : Acquire and clear the GPT unit interrupt flag
*
* Arguments    : bool * loco_rising : The address of storage area for the frequency-divided LOCO clock rise flag
*              : bool * loco_deviation : The address of storage area for the LOCO count value deviation exceedance flag 
*              : bool * loco_ov : The address of storage area for the LOCO counter overflow flag    
*              : bool * ext_rising : The address of storage area for the external trigger rising input flag
*              : bool * ext_falling : The address of storage area for the external trigger falling input flag
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_GPT_ReadUnit
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetRequestFlag_GPT_U0(bool * loco_rising, bool * loco_deviation, bool * loco_ov, bool * ext_rising, bool * ext_falling)
{
	bool res;
	uint8_t data;

	res = R_GPT_ReadUnit(
		0,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( loco_rising ){
		*loco_rising = data & 0x01;
	}
	if( loco_deviation ){
		*loco_deviation = (data >> 1) & 0x01;
	}
	if( loco_ov ){
		*loco_ov = (data >> 2) & 0x01;
	}
	if( ext_rising ){
		*ext_rising = (data >> 3) & 0x01;
	}
	if( ext_falling ){
		*ext_falling = (data >> 4) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StopModule_GPT_U0(void)
*
* Function Name: R_PG_Timer_StopModule_GPT_U0
*
* Description  : Shut down the GPT unit
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_GPT_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_StopModule_GPT_U0(void)
{
	return R_GPT_Destroy( 0 );

}



