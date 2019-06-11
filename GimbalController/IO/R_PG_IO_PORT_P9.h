/******************************************************************************
* DISCLAIMER
* Please refer to http://www.renesas.com/disclaimer
******************************************************************************
* Copyright (C) 2010 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
******************************************************************************
* File Name    : R_PG_IO_PORT_P9.h
* Version      : 1.00
* Description  : 
******************************************************************************
* History : 12.06.2019 Version Description
*         :   
******************************************************************************/


/******************************************************************************
Includes   <System Includes> , "Project Includes"
******************************************************************************/
#include "r_pdl_io_port.h"
#include "r_pdl_io_port_RX62TxFM.h"

bool R_PG_IO_PORT_Set_P9(void);
bool R_PG_IO_PORT_Set_P91(void);
bool R_PG_IO_PORT_Set_P92(void);
bool R_PG_IO_PORT_Read_P9(uint8_t * data);
bool R_PG_IO_PORT_Read_P91(uint8_t * data);
bool R_PG_IO_PORT_Read_P92(uint8_t * data);
bool R_PG_IO_PORT_Read_P93(uint8_t * data);
bool R_PG_IO_PORT_Read_P94(uint8_t * data);
bool R_PG_IO_PORT_Write_P9(uint8_t data);
bool R_PG_IO_PORT_Write_P91(uint8_t data);
bool R_PG_IO_PORT_Write_P92(uint8_t data);



