/*""FILE COMMENT""*******************************************************
* System Name	: Independent Watchdog timer API for RX62Txx
* File Name		: r_pdl_iwdt_RX62Txx.h
* Version		: 1.01
* Contents		: IWDT API header
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

#ifndef R_PDL_IWDT_RX62Txx_H
#define R_PDL_IWDT_RX62Txx_H

/* Library prototypes */
bool R_IWDT_SetAll(
	const uint16_t
);
bool R_IWDT_ControlAll(
	const uint8_t
);
bool R_IWDT_ReadAll(
	volatile uint16_t * const
);

/* Macro definitions */

#define R_IWDT_Set(a) \
( \
R_IWDT_SetAll( (a) ) \
)

#define R_IWDT_Control(a) \
( \
R_IWDT_ControlAll( (a) ) \
)

#define R_IWDT_Read(a) \
( \
R_IWDT_ReadAll( (a) ) \
)

#endif
/* End of file */
