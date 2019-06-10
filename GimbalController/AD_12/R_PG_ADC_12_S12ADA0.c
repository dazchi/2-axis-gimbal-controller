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
* File Name    : R_PG_ADC_12_S12ADA0.c
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
#include "R_PG_ADC_12_S12ADA0.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ADC_12_Set_S12ADA0(void)
*
* Function Name: R_PG_ADC_12_Set_S12ADA0
*
* Description  : Set up the A/D converter unit
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_ADC_12_CreateUnit
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ADC_12_Set_S12ADA0(void)
{
	return R_ADC_12_CreateUnit(
		0,
		PDL_ADC_12_MODE_SINGLE | PDL_ADC_12_CHANNELS_OPTION_0 | PDL_ADC_12_SAMPLE_AND_HOLD_ENABLE | PDL_ADC_12_DATA_PRECISION_12 | PDL_ADC_12_RETAIN_RESULT | PDL_ADC_12_DATA_ALIGNMENT_RIGHT | PDL_ADC_12_DTC_TRIGGER_DISABLE | PDL_ADC_12_ADSSTR_SPECIFY | PDL_ADC_12_SELF_DIAGNOSTIC_DISABLE,
		PDL_NO_DATA,
		PDL_NO_DATA,
		40000000,
		20,
		S12ad0IntFunc,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ADC_12_StartConversionSW_S12ADA0(void)
*
* Function Name: R_PG_ADC_12_StartConversionSW_S12ADA0
*
* Description  : Start the A/D conversion (Software trigger)
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_ADC_12_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ADC_12_StartConversionSW_S12ADA0(void)
{
	return R_ADC_12_Control( PDL_ADC_12_0_ON );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ADC_12_StopConversion_S12ADA0(void)
*
* Function Name: R_PG_ADC_12_StopConversion_S12ADA0
*
* Description  : Stop the A/D conversion
*
* Arguments    : None
*
* Return Value : true  : Stopping conversion succeeded.
*              : false : Stopping conversion failed.
*
* Calling Functions : R_ADC_12_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ADC_12_StopConversion_S12ADA0(void)
{
	return R_ADC_12_Control( PDL_ADC_12_0_OFF );

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ADC_12_GetResult_S12ADA0(uint16_t * result)
*
* Function Name: R_PG_ADC_12_GetResult_S12ADA0
*
* Description  : Get the A/D conversion result
*
* Arguments    : uint16_t * result : Destination for storage of the result of A/D conversion.
*
* Return Value : true  : Acquisition of the result succeeded.
*              : false : Acquisition of the result failed.
*
* Calling Functions : R_ADC_12_Read
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ADC_12_GetResult_S12ADA0(uint16_t * result)
{
	if( result == 0 )
	{
		return false;
	}

	return R_ADC_12_Read(
		0,
		PDL_NO_PTR,
		result,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_ADC_12_StopModule_S12ADA0(void)
*
* Function Name: R_PG_ADC_12_StopModule_S12ADA0
*
* Description  : Shut down the A/D converter unit
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_ADC_12_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_ADC_12_StopModule_S12ADA0(void)
{
	return R_ADC_12_Destroy( PDL_ADC_12_0_DESTROY );

}



