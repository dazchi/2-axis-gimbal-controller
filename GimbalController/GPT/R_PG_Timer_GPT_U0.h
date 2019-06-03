/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_Timer_GPT_U0.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 04.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_gpt.h"
#include "r_pdl_gpt_RX62Txx.h"

bool R_PG_Timer_Set_GPT_U0(void);
bool R_PG_Timer_SynchronouslyStartCount_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3);
bool R_PG_Timer_SynchronouslyHaltCount_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3);
bool R_PG_Timer_SynchronouslyClearCounter_GPT_U0(bool gpt0, bool gpt1, bool gpt2, bool gpt3);
bool R_PG_Timer_GetRequestFlag_GPT_U0(bool * loco_rising, bool * loco_deviation, bool * loco_ov, bool * ext_rising, bool * ext_falling);
bool R_PG_Timer_StopModule_GPT_U0(void);



