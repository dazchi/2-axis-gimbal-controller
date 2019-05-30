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
* File Name    : R_PG_I2C_C0.c
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
#include "R_PG_I2C_C0.h"


/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_Set_C0(void)
*
* Function Name: R_PG_I2C_Set_C0
*
* Description  : Set up an I2C bus interface channel
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_IIC_Create
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_Set_C0(void)
{
	return R_IIC_Create(
		0,
		PDL_IIC_MODE_IIC | PDL_IIC_INT_PCLK_DIV_1 | PDL_IIC_TIMEOUT_DISABLE | PDL_IIC_SDA_DELAY_0 | PDL_IIC_NF_DISABLE,
		PDL_IIC_NTALD_DISABLE | PDL_IIC_SALD_DISABLE | PDL_IIC_SLAVE_0_DISABLE | PDL_IIC_SLAVE_1_DISABLE | PDL_IIC_SLAVE_2_DISABLE | PDL_IIC_SLAVE_GCA_DISABLE | PDL_IIC_DEVICE_ID_DISABLE | PDL_IIC_HOST_ADDRESS_DISABLE,
		0,
		0,
		0,
		( 1 << 31 ) | ( 23 << 8 ) | 25,
		0
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_MasterReceive_C0(uint16_t slave, uint8_t * data, uint16_t count)
*
* Function Name: R_PG_I2C_MasterReceive_C0
*
* Description  : Master data reception
*
* Arguments    : uint16_t slave : Target slave address.
*              : uint8_t * data : The start address of the storage area for the expected data.
*              : uint16_t count : The number of the data to be received.
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_IIC_MasterReceive
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_MasterReceive_C0(uint16_t slave, uint8_t * data, uint16_t count)
{
	if( data == 0 )
	{
		return false;
	}

	return R_IIC_MasterReceive(
		0,
		PDL_IIC_DTC_TRIGGER_DISABLE,
		slave,
		data,
		count,
		IIC0MasterReFunc,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_MasterSend_C0(uint16_t slave, uint8_t * data, uint16_t count)
*
* Function Name: R_PG_I2C_MasterSend_C0
*
* Description  : Master data transmission
*
* Arguments    : uint16_t slave : Target slave address.
*              : uint8_t * data : The start address of the data to be sent.
*              : uint16_t count : The number of the data to be sent.
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_IIC_MasterSend
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_MasterSend_C0(uint16_t slave, uint8_t * data, uint16_t count)
{
	if( data == 0 )
	{
		return false;
	}

	return R_IIC_MasterSend(
		0,
		PDL_IIC_START_ENABLE | PDL_IIC_STOP_ENABLE | PDL_IIC_DTC_TRIGGER_DISABLE,
		slave,
		data,
		count,
		IIC0MasterTrFunc,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_MasterSendWithoutStop_C0(uint16_t slave, uint8_t * data, uint16_t count)
*
* Function Name: R_PG_I2C_MasterSendWithoutStop_C0
*
* Description  : Master data transmission ( No stop condition )
*
* Arguments    : uint16_t slave : Target slave address.
*              : uint8_t * data : The start address of the data to be sent.
*              : uint16_t count : The number of the data to be sent.
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_IIC_MasterSend
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_MasterSendWithoutStop_C0(uint16_t slave, uint8_t * data, uint16_t count)
{
	if( data == 0 )
	{
		return false;
	}

	return R_IIC_MasterSend(
		0,
		PDL_IIC_START_ENABLE | PDL_IIC_STOP_DISABLE | PDL_IIC_DTC_TRIGGER_DISABLE,
		slave,
		data,
		count,
		IIC0MasterTrFunc,
		15
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_GenerateStopCondition_C0(void)
*
* Function Name: R_PG_I2C_GenerateStopCondition_C0
*
* Description  : Generate a stop condition
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_IIC_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_GenerateStopCondition_C0(void)
{
	return R_IIC_Control(
		0,
		PDL_IIC_STOP
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_GetBusState_C0(bool * busy)
*
* Function Name: R_PG_I2C_GetBusState_C0
*
* Description  : Get the bus state
*
* Arguments    : bool * busy : The address of storage area for the bus busy detection flag.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_IIC_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_GetBusState_C0(bool * busy)
{
	uint32_t data;
	bool res;

	res = R_IIC_GetStatus(
		0,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( busy ){ *busy = (data >> 15) & 0x01; }

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_GetEvent_C0(bool * nack, bool * stop, bool * start, bool * lost, bool * timeout)
*
* Function Name: R_PG_I2C_GetEvent_C0
*
* Description  : Get the detected event
*
* Arguments    : bool * nack : The address of storage area for a NACK detection flag.
*              : bool * stop : The address of storage area for a stop condition detection flag.
*              : bool * start : The address of storage area for a start condition detection flag.
*              : bool * lost : The address of storage area for an arbitration lost.
*              : bool * timeout : The address of storage area for a timeout detection.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_IIC_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_GetEvent_C0(bool * nack, bool * stop, bool * start, bool * lost, bool * timeout)
{
	uint32_t data;
	bool res;

	res = R_IIC_GetStatus(
		0,
		&data,
		PDL_NO_PTR,
		PDL_NO_PTR
	);

	if( nack ){
		*nack = (data >> 12) & 0x01;
	}
	if( stop ){
		*stop = (data >> 11) & 0x01;
	}
	if( start ){
		*start = (data >> 10) & 0x01;
	}
	if( lost ){
		*lost = (data >> 9) & 0x01;
	}
	if( timeout ){
		*timeout = (data >> 8) & 0x01;
	}

	return res;
}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_GetReceivedDataCount_C0(uint16_t * count)
*
* Function Name: R_PG_I2C_GetReceivedDataCount_C0
*
* Description  : Acquires the count of received data
*
* Arguments    : uint16_t * count : The address of storage area for the number of bytes that have been received.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_IIC_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_GetReceivedDataCount_C0(uint16_t * count)
{
	if( count == 0 )
	{
		return false;
	}

	return R_IIC_GetStatus(
		0,
		PDL_NO_PTR,
		PDL_NO_PTR,
		count
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_GetSentDataCount_C0(uint16_t * count)
*
* Function Name: R_PG_I2C_GetSentDataCount_C0
*
* Description  : Acquires the count of transmitted data
*
* Arguments    : uint16_t * count : The address of storage area for the number of bytes that have been transmitted.
*
* Return Value : true  : Acquisition succeeded.
*              : false : Acquisition failed.
*
* Calling Functions : R_IIC_GetStatus
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_GetSentDataCount_C0(uint16_t * count)
{
	if( count == 0 )
	{
		return false;
	}

	return R_IIC_GetStatus(
		0,
		PDL_NO_PTR,
		count,
		PDL_NO_PTR
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_Reset_C0(void)
*
* Function Name: R_PG_I2C_Reset_C0
*
* Description  : Reset the bus
*
* Arguments    : None
*
* Return Value : true  : Setting was made correctly.
*              : false : Setting failed.
*
* Calling Functions : R_IIC_Control
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_Reset_C0(void)
{
	return R_IIC_Control(
		0,
		PDL_IIC_RESET
	);

}

/******************************************************************************
* ID           : 
*
* Include      : 
*
* Declaration  : bool R_PG_I2C_StopModule_C0(void)
*
* Function Name: R_PG_I2C_StopModule_C0
*
* Description  : Shut down the I2C bus interface channel
*
* Arguments    : None
*
* Return Value : true  : Shutting down succeeded.
*              : false : Shutting down failed.
*
* Calling Functions : R_IIC_Destroy
*
* Details      : Please refer to the Reference Manual.
******************************************************************************/
bool R_PG_I2C_StopModule_C0(void)
{
	return R_IIC_Destroy( 0 );

}



