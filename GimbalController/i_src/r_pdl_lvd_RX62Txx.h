/*""FILE COMMENT""*******************************************************
* System Name	: Voltage detection circuit API for RX62Txx
* File Name		: r_pdl_lvd_RX62Txx.h
* Version		: 1.01
* Contents		: LVD API header
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

#ifndef R_PDL_LVD_RX62Txx_H
#define R_PDL_LVD_RX62Txx_H

/* Library prototypes */
bool R_LVD_ControlAll(
	const uint8_t
);

/* Macro definitions */

#define R_LVD_Control(a) \
( \
R_LVD_ControlAll( (a) ) \
)

#endif
/* End of file */
