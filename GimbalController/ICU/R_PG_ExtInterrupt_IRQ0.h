/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_ExtInterrupt_IRQ0.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 11.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_intc.h"
#include "r_pdl_intc_RX62Txx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_ExtInterrupt_Set_IRQ0(void);
bool R_PG_ExtInterrupt_Disable_IRQ0(void);
bool R_PG_ExtInterrupt_GetRequestFlag_IRQ0(bool * flag);
bool R_PG_ExtInterrupt_ClearRequestFlag_IRQ0(void);



