/*""FILE COMMENT""*******************************************************
* System Name	: BSC API for RX62Txx
* File Name		: r_pdl_bsc_RX62Txx.h
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

#ifndef R_PDL_BSC_RX62Txx_H
#define R_PDL_BSC_RX62Txx_H

/* Callback function storage */
extern VoidCallBackFunc rpdl_BSC_callback_func;

/* Library prototypes */
bool R_BSC_CreateAll(
	const uint8_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_BSC_ControlAll(
	const uint8_t
);
bool R_BSC_GetStatusAll(
	volatile uint8_t * const,
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_BSC_Create(a, b, c) \
( \
( (c) <= IPL_MAX ) ? \
R_BSC_CreateAll( (a), (b), (c) ) : \
ReturnFalse() \
)

#define R_BSC_Control(a) \
( \
R_BSC_ControlAll( (a) ) \
)

#define R_BSC_GetStatus(a, b) \
( \
R_BSC_GetStatusAll( (a), (b) ) \
)

#endif
/* End of file */
