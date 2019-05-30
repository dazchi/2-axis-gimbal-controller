/*""FILE COMMENT""*******************************************************
* System Name	: BSC API for RX62T
* File Name		: r_pdl_bsc.h
* Version		: 1.01
* Contents		: BSC API header
* Customer		: 
* Model			: 
* Order			: 
* CPU			: RX
* Compiler		: RXC
* OS			: Nothing
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

#ifndef R_PDL_BSC_H
#define R_PDL_BSC_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_BSC_Create(
	uint8_t,
	void *,
	uint8_t
);
bool R_BSC_Control(
	uint8_t
);
bool R_BSC_GetStatus(
	uint8_t *,
	uint16_t *
);

/* R_BSC_Create parameter options */
#define PDL_BSC_ERROR_ILLEGAL_ADDRESS_ENABLE	0x01u
#define PDL_BSC_ERROR_ILLEGAL_ADDRESS_DISABLE	0x02u

/* R_BSC_Control parameter options */
#define PDL_BSC_ERROR_CLEAR						0x01u
#define PDL_BSC_DISABLE_BUSERR_IRQ				0x02u

#endif
/* End of file */
