/*""FILE COMMENT""*******************************************************
* System Name	: CGC API for RX62T
* File Name		: r_pdl_cgc.h
* Version		: 1.01
* Contents		: CGC header
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

#ifndef R_PDL_CGC_H
#define R_PDL_CGC_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_CGC_Set(
	uint32_t,
	uint32_t,
	uint32_t,
	uint8_t
);

bool R_CGC_GetStatus(
	uint8_t *
);

/* Oscillation Stop Detection control */
#define PDL_CGC_OSC_STOP_ENABLE		0x01u
#define PDL_CGC_OSC_STOP_DISABLE	0x02u

#endif
/* End of file */
