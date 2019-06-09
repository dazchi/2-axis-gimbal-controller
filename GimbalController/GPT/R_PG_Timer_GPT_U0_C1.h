/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_Timer_GPT_U0_C1.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 10.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_gpt.h"
#include "r_pdl_gpt_RX62Txx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_Timer_Set_GPT_U0_C1(void);
bool R_PG_Timer_StartCount_GPT_U0_C1(void);
bool R_PG_Timer_HaltCount_GPT_U0_C1(void);
bool R_PG_Timer_BufferEnable_GPT_U0_C1(bool gtccr, bool gtpr, bool gtadtr, bool gtdv);
bool R_PG_Timer_BufferDisable_GPT_U0_C1(bool gtccr, bool gtpr, bool gtadtr, bool gtdv);
bool R_PG_Timer_Buffer_Force_GPT_U0_C1(void);
bool R_PG_Timer_CountDirection_Down_GPT_U0_C1(bool force);
bool R_PG_Timer_CountDirection_Up_GPT_U0_C1(bool force);
bool R_PG_Timer_GetCounterValue_GPT_U0_C1(uint16_t * counter_val);
bool R_PG_Timer_SetCounterValue_GPT_U0_C1(uint16_t counter_val);
bool R_PG_Timer_GetGTCCR_GPT_U0_C1(uint16_t * gtccr_a_val, uint16_t * gtccr_b_val, uint16_t * gtccr_c_val, uint16_t * gtccr_d_val, uint16_t * gtccr_e_val, uint16_t * gtccr_f_val);
bool R_PG_Timer_SetGTCCR_A_GPT_U0_C1(uint16_t gtccr_a_val);
bool R_PG_Timer_SetGTCCR_B_GPT_U0_C1(uint16_t gtccr_b_val);
bool R_PG_Timer_SetGTCCR_C_GPT_U0_C1(uint16_t gtccr_c_val);
bool R_PG_Timer_SetGTCCR_D_GPT_U0_C1(uint16_t gtccr_d_val);
bool R_PG_Timer_SetGTCCR_E_GPT_U0_C1(uint16_t gtccr_e_val);
bool R_PG_Timer_SetGTCCR_F_GPT_U0_C1(uint16_t gtccr_f_val);
bool R_PG_Timer_SetCycle_GPT_U0_C1(uint16_t gtpr_val);
bool R_PG_Timer_GetRequestFlag_GPT_U0_C1(bool * cm_ic_a, bool * cm_ic_b, bool * cm_c, bool * cm_d, bool * cm_e, bool * cm_f, bool * ov, bool * un, bool * dt_error);
bool R_PG_Timer_GetCounterStatus_GPT_U0_C1(bool * active, bool * up);



