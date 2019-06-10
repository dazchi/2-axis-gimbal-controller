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
* File Name    : R_PG_SCI_C2.c
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
#include "R_PG_SCI_C2.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_Set_C2(void)
*
* Function Name: R_PG_SCI_Set_C2
*
* Description  : Set up the serial I/O
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Create
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_Set_C2(void)
{
	return R_SCI_Create(
		2,
		PDL_SCI_ASYNC | PDL_SCI_TX_CONNECTED | PDL_SCI_RX_DISCONNECTED | PDL_SCI_CLK_INT_IO | PDL_SCI_8_BIT_LENGTH | PDL_SCI_PARITY_NONE | PDL_SCI_STOP_1,
		BIT_31 | PDL_SCI_PCLK_DIV_1 | PDL_SCI_CYCLE_BIT_8 | 0x15 | (113636 & 0x00FFFF00ul),
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_SendAllData_C2(uint8_t * data, uint16_t count)
*
* Function Name: R_PG_SCI_SendAllData_C2
*
* Description  : Send all serial data
*
* Arguments    : uint8_t * data : The start address of the data to be sent.
*              : uint16_t count : The number of the data to be sent.
*              :                : Set this to 0 if the transmit data is a character string
*              :                : (ending with a null character).
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Send
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_SendAllData_C2(uint8_t * data, uint16_t count)
{
	if( data == 0 ){ return false; }

	return R_SCI_Send(
		2,
		PDL_SCI_DTC_TRIGGER_DISABLE,
		data,
		count,
		PDL_NO_FUNC
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StopCommunication_C2(void)
*
* Function Name: R_PG_SCI_StopCommunication_C2
*
* Description  : Stop transmission and reception of serial data
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_SCI_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_StopCommunication_C2(void)
{
	return R_SCI_Control(
		2,
		PDL_SCI_STOP_TX_AND_RX
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_GetTransmitStatus_C2(bool * complete)
*
* Function Name: R_PG_SCI_GetTransmitStatus_C2
*
* Description  : Get the serial data transmission status
*
* Arguments    : bool * complete : The address of storage area for the transmission completion flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_SCI_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_GetTransmitStatus_C2(bool * complete)
{
	uint8_t status;
	bool res;

	res = R_SCI_GetStatus(
		2,
		&status,
		PDL_NO_PTR,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( complete ){ *complete = (status >> 2) & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_SCI_StopModule_C2(void)
*
* Function Name: R_PG_SCI_StopModule_C2
*
* Description  : Shut down the serial I/O channel
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_SCI_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_SCI_StopModule_C2(void)
{
	return R_SCI_Destroy( 2 );

}



