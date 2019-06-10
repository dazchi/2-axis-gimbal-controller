/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_SCI_C2.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 11.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_sci.h"
#include "r_pdl_sci_RX62Txx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_SCI_Set_C2(void);
bool R_PG_SCI_SendAllData_C2(uint8_t * data, uint16_t count);
bool R_PG_SCI_StopCommunication_C2(void);
bool R_PG_SCI_GetTransmitStatus_C2(bool * complete);
bool R_PG_SCI_StopModule_C2(void);



