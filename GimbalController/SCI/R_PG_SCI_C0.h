/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_SCI_C0.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 30.05.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_sci.h"
#include "r_pdl_sci_RX62Txx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_SCI_Set_C0(void);
bool R_PG_SCI_StartSending_C0(uint8_t * data, uint16_t count);
bool R_PG_SCI_GetSentDataCount_C0(uint16_t * count);
bool R_PG_SCI_StopCommunication_C0(void);
bool R_PG_SCI_GetTransmitStatus_C0(bool * complete);
bool R_PG_SCI_StopModule_C0(void);



