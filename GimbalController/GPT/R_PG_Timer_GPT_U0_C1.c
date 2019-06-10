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
* File Name    : R_PG_Timer_GPT_U0_C1.c
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
#include "R_PG_Timer_GPT_U0_C1.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Set_GPT_U0_C1(void)
*
* Function Name: R_PG_Timer_Set_GPT_U0_C1
*
* Description  : Set up the GPT
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*                   : R_GPT_Create
*                   : R_GPT_Create_load_defaults
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_Set_GPT_U0_C1(void)
{
	bool res;
	R_GPT_Create_structure create_parameters;
	R_GPT_ControlChannel_structure control_parameters;

	R_GPT_Create_load_defaults( &create_parameters );

	create_parameters.data2 = PDL_GPT_MODE_SAW | PDL_GPT_CLK_ICLK_DIV_1;
	create_parameters.data4 = PDL_GPT_CLEAR_SYNC_CH_0;
	create_parameters.data6 = PDL_GPT_A_CM_HIGH | PDL_GPT_A_LOW_LOW | PDL_GPT_A_CYCLE_LOW;
	create_parameters.data7 = PDL_GPT_B_CM_HIGH | PDL_GPT_B_LOW_LOW | PDL_GPT_B_CYCLE_LOW;
	create_parameters.func1 = PDL_NO_FUNC;
	create_parameters.func2 = PDL_NO_FUNC;
	create_parameters.func3 = PDL_NO_FUNC;
	create_parameters.data11 = 0;
	create_parameters.func4 = PDL_NO_FUNC;
	create_parameters.func5 = PDL_NO_FUNC;
	create_parameters.func6 = PDL_NO_FUNC;
	create_parameters.data12 = 0;

	control_parameters.data4 = 0;
	control_parameters.data11 = 4095;

	res = R_GPT_Create(
		1,
		&create_parameters
	);

	if( !res ){
		return res;
	}

	return R_GPT_ControlChannel(
		1,
		PDL_GPT_COUNT_DIRECTION_DOWN | PDL_GPT_COUNT_DIRECTION_FORCE,
		PDL_GPT_REGISTER_COUNTER | PDL_GPT_REGISTER_CYCLE,
		&control_parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_StartCount_GPT_U0_C1(void)
*
* Function Name: R_PG_Timer_StartCount_GPT_U0_C1
*
* Description  : Start the GPT count
*
* Arguments    : None
*
* Return Value : true  : Starting succeeded.
*              : false : Starting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_StartCount_GPT_U0_C1(void)
{
	R_GPT_ControlChannel_structure parameters;

	return R_GPT_ControlChannel(
		1,
		PDL_GPT_START,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_HaltCount_GPT_U0_C1(void)
*
* Function Name: R_PG_Timer_HaltCount_GPT_U0_C1
*
* Description  : Halt the GPT count
*
* Arguments    : None
*
* Return Value : true  : Halting succeeded.
*              : false : Halting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_HaltCount_GPT_U0_C1(void)
{
	R_GPT_ControlChannel_structure parameters;

	return R_GPT_ControlChannel(
		1,
		PDL_GPT_STOP,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_BufferEnable_GPT_U0_C1(bool gtccr, bool gtpr, bool gtadtr, bool gtdv)
*
* Function Name: R_PG_Timer_BufferEnable_GPT_U0_C1
*
* Description  : Enable the GPT buffer operation
*
* Arguments    : bool gtccr : Buffer operation enable for the general register (1:set 0:do not set)
*              : bool gtpr : Buffer operation enable for the cycle setting register (1:set 0:do not set)
*              : bool gtadtr : Buffer operation enable for the ADC start request register (1:set 0:do not set)
*              : bool gtdv : Buffer operation enable for the dead time value register (1:set 0:do not set)
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_BufferEnable_GPT_U0_C1(bool gtccr, bool gtpr, bool gtadtr, bool gtdv)
{
	uint32_t control = 0;
	R_GPT_ControlChannel_structure parameters;

	if( gtccr == 1 ){
		control |= PDL_GPT_BUFFER_CMIC_START;
	}
	if( gtpr == 1 ){
		control |= PDL_GPT_BUFFER_CYCLE_START;
	}
	if( gtadtr == 1 ){
		control |= PDL_GPT_BUFFER_ADC_TRIG_START;
	}
	if( gtdv == 1 ){
		control |= PDL_GPT_BUFFER_DEAD_TIME_START;
	}

	return R_GPT_ControlChannel(
		1,
		control,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_BufferDisable_GPT_U0_C1(bool gtccr, bool gtpr, bool gtadtr, bool gtdv)
*
* Function Name: R_PG_Timer_BufferDisable_GPT_U0_C1
*
* Description  : Disable the GPT buffer operation
*
* Arguments    : bool gtccr : Buffer operation disable for the general register (1:set 0:do not set)
*              : bool gtpr : Buffer operation disable for the cycle setting register (1:set 0:do not set)
*              : bool gtadtr : Buffer operation disable for the ADC start request register (1:set 0:do not set)
*              : bool gtdv : Buffer operation disable for the dead time value register (1:set 0:do not set)
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_BufferDisable_GPT_U0_C1(bool gtccr, bool gtpr, bool gtadtr, bool gtdv)
{
	uint32_t control = 0;
	R_GPT_ControlChannel_structure parameters;

	if( gtccr == 1 ){
		control |= PDL_GPT_BUFFER_CMIC_STOP;
	}
	if( gtpr == 1 ){
		control |= PDL_GPT_BUFFER_CYCLE_STOP;
	}
	if( gtadtr == 1 ){
		control |= PDL_GPT_BUFFER_ADC_TRIG_STOP;
	}
	if( gtdv == 1 ){
		control |= PDL_GPT_BUFFER_DEAD_TIME_STOP;
	}

	return R_GPT_ControlChannel(
		1,
		control,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_Buffer_Force_GPT_U0_C1(void)
*
* Function Name: R_PG_Timer_Buffer_Force_GPT_U0_C1
*
* Description  : Force the GPT buffer operation
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_Buffer_Force_GPT_U0_C1(void)
{
	R_GPT_ControlChannel_structure parameters;

	return R_GPT_ControlChannel(
		1,
		PDL_GPT_BUFFER_CMIC_FORCE,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_CountDirection_Down_GPT_U0_C1(bool force)
*
* Function Name: R_PG_Timer_CountDirection_Down_GPT_U0_C1
*
* Description  : Set the GPT down-counting
*
* Arguments    : bool force : Forcible count direction setting (1:set 0:do not set)
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_CountDirection_Down_GPT_U0_C1(bool force)
{
	uint32_t control = PDL_GPT_COUNT_DIRECTION_DOWN;
	R_GPT_ControlChannel_structure parameters;

	if( force == 1 ){
		control |= PDL_GPT_COUNT_DIRECTION_FORCE;
	}

	return R_GPT_ControlChannel(
		1,
		control,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_CountDirection_Up_GPT_U0_C1(bool force)
*
* Function Name: R_PG_Timer_CountDirection_Up_GPT_U0_C1
*
* Description  : Set the GPT up-counting
*
* Arguments    : bool force : Forcible count direction setting (1:set 0:do not set)
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_CountDirection_Up_GPT_U0_C1(bool force)
{
	uint32_t control = PDL_GPT_COUNT_DIRECTION_UP;
	R_GPT_ControlChannel_structure parameters;

	if( force == 1 ){
		control |= PDL_GPT_COUNT_DIRECTION_FORCE;
	}

	return R_GPT_ControlChannel(
		1,
		control,
		PDL_NO_DATA,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterValue_GPT_U0_C1(uint16_t * counter_val)
*
* Function Name: R_PG_Timer_GetCounterValue_GPT_U0_C1
*
* Description  : Acquire the GPT counter value
*
* Arguments    : uint16_t * counter_val : The address of storage area for the counter value
*
* Return Value : true  : Acquisition of the counter value succeeded.
*              : false : Acquisition of the counter value failed.
*
* Calling Functions : R_GPT_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetCounterValue_GPT_U0_C1(uint16_t * counter_val)
{
	if( counter_val == 0 ){
		return false;
	}

	return R_GPT_ReadChannel(
		1,
		PDL_NO_PTR,
		counter_val,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCounterValue_GPT_U0_C1(uint16_t counter_val)
*
* Function Name: R_PG_Timer_SetCounterValue_GPT_U0_C1
*
* Description  : Set the GPT counter value
*
* Arguments    : uint16_t counter_val : Value to be set to the counter.
*
* Return Value : true  : Setting of the counter value succeeded.
*              : false : Setting of the counter value failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetCounterValue_GPT_U0_C1(uint16_t counter_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data4 = counter_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_COUNTER,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetGTCCR_GPT_U0_C1(uint16_t * gtccr_a_val, uint16_t * gtccr_b_val, uint16_t * gtccr_c_val, uint16_t * gtccr_d_val, uint16_t * gtccr_e_val, uint16_t * gtccr_f_val)
*
* Function Name: R_PG_Timer_GetGTCCR_GPT_U0_C1
*
* Description  : Acquire the GPT general register value
*
* Arguments    : uint16_t * gtccr_a_val : The address of storage area for the general register A value
*              : uint16_t * gtccr_b_val : The address of storage area for the general register B value
*              : uint16_t * gtccr_c_val : The address of storage area for the general register C value
*              : uint16_t * gtccr_d_val : The address of storage area for the general register D value
*              : uint16_t * gtccr_e_val : The address of storage area for the general register E value
*              : uint16_t * gtccr_f_val : The address of storage area for the general register F value
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_GPT_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetGTCCR_GPT_U0_C1(uint16_t * gtccr_a_val, uint16_t * gtccr_b_val, uint16_t * gtccr_c_val, uint16_t * gtccr_d_val, uint16_t * gtccr_e_val, uint16_t * gtccr_f_val)
{
	uint16_t * local_a = PDL_NO_PTR;
	uint16_t * local_b = PDL_NO_PTR;
	uint16_t * local_c = PDL_NO_PTR;
	uint16_t * local_d = PDL_NO_PTR;
	uint16_t * local_e = PDL_NO_PTR;
	uint16_t * local_f = PDL_NO_PTR;

	if( gtccr_a_val ){
		local_a = gtccr_a_val;
	}
	if( gtccr_b_val ){
		local_b = gtccr_b_val;
	}
	if( gtccr_c_val ){
		local_c = gtccr_c_val;
	}
	if( gtccr_d_val ){
		local_d = gtccr_d_val;
	}
	if( gtccr_e_val ){
		local_e = gtccr_e_val;
	}
	if( gtccr_f_val ){
		local_f = gtccr_f_val;
	}

	return R_GPT_ReadChannel(
		1,
		PDL_NO_PTR,
		PDL_NO_PTR,
		local_a,
		local_b,
		local_c,
		local_d,
		local_e,
		local_f,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetGTCCR_A_GPT_U0_C1(uint16_t gtccr_a_val)
*
* Function Name: R_PG_Timer_SetGTCCR_A_GPT_U0_C1
*
* Description  : Set the GPT general register value(GTCCRA)
*
* Arguments    : uint16_t gtccr_a_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetGTCCR_A_GPT_U0_C1(uint16_t gtccr_a_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data5 = gtccr_a_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_A,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetGTCCR_B_GPT_U0_C1(uint16_t gtccr_b_val)
*
* Function Name: R_PG_Timer_SetGTCCR_B_GPT_U0_C1
*
* Description  : Set the GPT general register value(GTCCRB)
*
* Arguments    : uint16_t gtccr_b_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetGTCCR_B_GPT_U0_C1(uint16_t gtccr_b_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data6 = gtccr_b_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_B,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetGTCCR_C_GPT_U0_C1(uint16_t gtccr_c_val)
*
* Function Name: R_PG_Timer_SetGTCCR_C_GPT_U0_C1
*
* Description  : Set the GPT general register value(GTCCRC)
*
* Arguments    : uint16_t gtccr_c_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetGTCCR_C_GPT_U0_C1(uint16_t gtccr_c_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data7 = gtccr_c_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_C,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetGTCCR_D_GPT_U0_C1(uint16_t gtccr_d_val)
*
* Function Name: R_PG_Timer_SetGTCCR_D_GPT_U0_C1
*
* Description  : Set the GPT general register value(GTCCRD)
*
* Arguments    : uint16_t gtccr_d_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetGTCCR_D_GPT_U0_C1(uint16_t gtccr_d_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data8 = gtccr_d_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_D,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetGTCCR_E_GPT_U0_C1(uint16_t gtccr_e_val)
*
* Function Name: R_PG_Timer_SetGTCCR_E_GPT_U0_C1
*
* Description  : Set the GPT general register value(GTCCRE)
*
* Arguments    : uint16_t gtccr_e_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetGTCCR_E_GPT_U0_C1(uint16_t gtccr_e_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data9 = gtccr_e_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_E,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetGTCCR_F_GPT_U0_C1(uint16_t gtccr_f_val)
*
* Function Name: R_PG_Timer_SetGTCCR_F_GPT_U0_C1
*
* Description  : Set the GPT general register value(GTCCRF)
*
* Arguments    : uint16_t gtccr_f_val : Value to be set to the general register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetGTCCR_F_GPT_U0_C1(uint16_t gtccr_f_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data10 = gtccr_f_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_F,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_SetCycle_GPT_U0_C1(uint16_t gtpr_val)
*
* Function Name: R_PG_Timer_SetCycle_GPT_U0_C1
*
* Description  : Set the GPT cycle setting register value
*
* Arguments    : uint16_t gtpr_val : Value to be set to the cycle setting register
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_GPT_ControlChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_SetCycle_GPT_U0_C1(uint16_t gtpr_val)
{
	R_GPT_ControlChannel_structure parameters;

	parameters.data11 = gtpr_val;

	return R_GPT_ControlChannel(
		1,
		PDL_NO_DATA,
		PDL_GPT_REGISTER_CYCLE,
		&parameters
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetRequestFlag_GPT_U0_C1(bool * cm_ic_a, bool * cm_ic_b, bool * cm_c, bool * cm_d, bool * cm_e, bool * cm_f, bool * ov, bool * un, bool * dt_error)
*
* Function Name: R_PG_Timer_GetRequestFlag_GPT_U0_C1
*
* Description  : Acquire and clear the GPT interrupt flag
*
* Arguments    : bool * cm_ic_a : The address of storage area for the compare match/input capture A flag.
*              : bool * cm_ic_b : The address of storage area for the compare match/input capture B flag.
*              : bool * cm_c : The address of storage area for the compare match C flag
*              : bool * cm_d : The address of storage area for the compare match D flag
*              : bool * cm_e : The address of storage area for the compare match/input capture E flag.
*              : bool * cm_f : The address of storage area for the compare match/input capture F flag.
*              : bool * ov : The address of storage area for the overflow flag.
*              : bool * un : The address of storage area for the underflow flag.
*              : bool * dt_error : The address of storage area for the dead-time error flag
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_GPT_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetRequestFlag_GPT_U0_C1(bool * cm_ic_a, bool * cm_ic_b, bool * cm_c, bool * cm_d, bool * cm_e, bool * cm_f, bool * ov, bool * un, bool * dt_error)
{
	bool res;
	uint16_t data;

	res = R_GPT_ReadChannel(
		1,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( cm_ic_a ){
		*cm_ic_a = data & 0x01;
	}
	if( cm_ic_b ){
		*cm_ic_b = (data >> 1) & 0x01;
	}
	if( cm_c ){
		*cm_c = (data >> 2) & 0x01;
	}
	if( cm_d ){
		*cm_d = (data >> 3) & 0x01;
	}
	if( cm_e ){
		*cm_e = (data >> 4) & 0x01;
	}
	if( cm_f ){
		*cm_f = (data >> 5) & 0x01;
	}
	if( ov ){
		*ov = (data >> 6) & 0x01;
	}
	if( un ){
		*un = (data >> 7) & 0x01;
	}
	if( dt_error ){
		*dt_error = (data >> 11) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_Timer_GetCounterStatus_GPT_U0_C1(bool * active, bool * up)
*
* Function Name: R_PG_Timer_GetCounterStatus_GPT_U0_C1
*
* Description  : Acquire the GPT counter status
*
* Arguments    : bool * active : The address of storage area for the count start flag
*              : bool * up : The address of storage area for the count direction flag 
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_GPT_ReadChannel
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_Timer_GetCounterStatus_GPT_U0_C1(bool * active, bool * up)
{
	bool res;
	uint16_t data;

	res = R_GPT_ReadChannel(
		1,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( active ){
		*active = (data >> 14) & 0x01;
	}
	if( up ){
		*up = (data >> 15) & 0x01;
	}

	return res;
}



