/*""FILE COMMENT""*******************************************************
* System Name	: PFC API for RX62T
* File Name		: r_pdl_pfc.h
* Version		: 1.01
* Contents		: PFC API header
* Customer		: 
* Model			: 
* Order			: 
* CPU			: RX
* Compiler		: RXC
* OS			:
* Programmer	: 
* Note			: 
************************************************************************
* Copyright, 2011. Renesas Electronics Corporation
* and Renesas Solutions Corporation
************************************************************************
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FILE COMMENT END""**************************************************/

#ifndef R_PDL_PFC_H
#define R_PDL_PFC_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_PFC_Read(
	uint8_t,
	uint8_t *
);
bool R_PFC_Write(
	uint8_t,
	uint8_t
);
bool R_PFC_Modify(
	uint8_t,
	uint8_t,
	uint8_t
);

/* PFC register definitions */
#define PDL_PFC_PF8IRQ	0x08u
#define PDL_PFC_PF9IRQ	0x09u
#define PDL_PFC_PFAADC	0x0Au
#define PDL_PFC_PFCMTU	0x0Cu
#define PDL_PFC_PFDGPT	0x0Du
#define PDL_PFC_PFFSCI	0x0Fu
#define PDL_PFC_PFGSPI	0x10u
#define PDL_PFC_PFHSPI	0x11u
#define PDL_PFC_PFJCAN	0x13u
#define PDL_PFC_PFKLIN	0x14u
#define PDL_PFC_PFMPOE	0x16u
#define PDL_PFC_PFNPOE	0x17u

/* Logical operations */
#define PDL_PFC_AND	0x01u
#define PDL_PFC_OR	0x02u
#define PDL_PFC_XOR	0x04u

#endif
/* End of file */
