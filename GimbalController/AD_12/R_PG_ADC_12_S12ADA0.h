/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_ADC_12_S12ADA0.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 10.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_adc_12.h"
#include "r_pdl_adc_12_RX62Txx.h"
#include "R_PG_IntFuncsExtern.h"

bool R_PG_ADC_12_Set_S12ADA0(void);
bool R_PG_ADC_12_StartConversionSW_S12ADA0(void);
bool R_PG_ADC_12_StopConversion_S12ADA0(void);
bool R_PG_ADC_12_GetResult_S12ADA0(uint16_t * result);
bool R_PG_ADC_12_StopModule_S12ADA0(void);



