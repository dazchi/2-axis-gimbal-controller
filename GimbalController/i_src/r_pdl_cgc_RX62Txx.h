/*""FILE COMMENT""*******************************************************
* System Name	: CGC API for RX62Txx
* File Name		: r_pdl_cgc_RX62Txx.h
* Version		: 1.01
* Contents		: CGC header
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

#ifndef R_PDL_CGC_RX62Txx_H
#define R_PDL_CGC_RX62Txx_H

/* Library prototypes */
bool R_CGC_SetAll(
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);

bool R_CGC_GetStatusAll(
	volatile uint8_t * const
);

/* Macro definitions */

#define R_CGC_Set(a, b, c, d) \
R_CGC_SetAll( (a), (b), (c), (d) )

#define R_CGC_GetStatus(a) \
R_CGC_GetStatusAll( (a) )

#endif
/* End of file */
