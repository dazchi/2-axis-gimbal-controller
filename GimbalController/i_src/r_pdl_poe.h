/*""FILE COMMENT""*******************************************************
* System Name	: POE API for RX62Txx
* File Name		: r_pdl_poe.h
* Version		: 1.01
* Contents		: POE API header
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

#ifndef R_PDL_POE_H
#define R_PDL_POE_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_POE_Set(
	uint32_t,
	uint32_t,
	uint16_t,
	uint16_t
);
bool R_POE_Create(
	uint16_t,
	void *,
	void *,
	void *,
	void *,
	uint8_t
);
bool POE_Control(
	uint16_t,
	uint8_t,
	uint16_t
);
bool R_POE_GetStatus(
	uint16_t *
);

/* Input pin detection */
#define PDL_POE_0_MODE_EDGE 	0x00000001ul
#define PDL_POE_0_MODE_LOW_8 	0x00000002ul
#define PDL_POE_0_MODE_LOW_16 	0x00000004ul
#define PDL_POE_0_MODE_LOW_128 	0x00000008ul

#define PDL_POE_4_MODE_EDGE 	0x00000010ul
#define PDL_POE_4_MODE_LOW_8 	0x00000020ul
#define PDL_POE_4_MODE_LOW_16 	0x00000040ul
#define PDL_POE_4_MODE_LOW_128 	0x00000080ul

#define PDL_POE_8_MODE_EDGE 	0x00000100ul
#define PDL_POE_8_MODE_LOW_8 	0x00000200ul
#define PDL_POE_8_MODE_LOW_16 	0x00000400ul
#define PDL_POE_8_MODE_LOW_128 	0x00000800ul

#define PDL_POE_10_MODE_EDGE 	0x00001000ul
#define PDL_POE_10_MODE_LOW_8 	0x00002000ul
#define PDL_POE_10_MODE_LOW_16 	0x00004000ul
#define PDL_POE_10_MODE_LOW_128 0x00008000ul

#define PDL_POE_11_MODE_EDGE 	0x00010000ul
#define PDL_POE_11_MODE_LOW_8 	0x00020000ul
#define PDL_POE_11_MODE_LOW_16 	0x00040000ul
#define PDL_POE_11_MODE_LOW_128 0x00080000ul

/* Pin selection */
#define PDL_POE_10_A 			0x00100000ul
#define PDL_POE_10_B 			0x00200000ul

/* Pin output control */

/* High impedance request detection */
#define PDL_POE_HI_Z_REQ_8_ENABLE		0x00000001ul
#define PDL_POE_HI_Z_REQ_10_ENABLE		0x00000002ul
#define PDL_POE_HI_Z_REQ_11_ENABLE		0x00000004ul

/* Additional event selection */
#define PDL_POE_HI_Z_MT34_ADD_CFLAG		0x00000008ul
#define PDL_POE_HI_Z_MT34_ADD_POE4		0x00000010ul
#define PDL_POE_HI_Z_MT34_ADD_POE8		0x00000020ul
#define PDL_POE_HI_Z_MT34_ADD_POE10		0x00000040ul
#define PDL_POE_HI_Z_MT34_ADD_POE11		0x00000080ul

#define PDL_POE_HI_Z_MT67_ADD_CFLAG		0x00000100ul
#define PDL_POE_HI_Z_MT67_ADD_POE0		0x00000200ul
#define PDL_POE_HI_Z_MT67_ADD_POE8		0x00000400ul
#define PDL_POE_HI_Z_MT67_ADD_POE10		0x00000800ul
#define PDL_POE_HI_Z_MT67_ADD_POE11		0x00001000ul

#define PDL_POE_HI_Z_MT0_ADD_CFLAG		0x00002000ul
#define PDL_POE_HI_Z_MT0_ADD_POE0		0x00004000ul
#define PDL_POE_HI_Z_MT0_ADD_POE4		0x00008000ul
#define PDL_POE_HI_Z_MT0_ADD_POE10		0x00010000ul
#define PDL_POE_HI_Z_MT0_ADD_POE11		0x00020000ul

#define PDL_POE_HI_Z_GPT01_ADD_CFLAG	0x00040000ul
#define PDL_POE_HI_Z_GPT01_ADD_POE0		0x00080000ul
#define PDL_POE_HI_Z_GPT01_ADD_POE4		0x00100000ul
#define PDL_POE_HI_Z_GPT01_ADD_POE8		0x00200000ul
#define PDL_POE_HI_Z_GPT01_ADD_POE11	0x00400000ul

#define PDL_POE_HI_Z_GPT23_ADD_CFLAG	0x00800000ul
#define PDL_POE_HI_Z_GPT23_ADD_POE0		0x01000000ul
#define PDL_POE_HI_Z_GPT23_ADD_POE4		0x02000000ul
#define PDL_POE_HI_Z_GPT23_ADD_POE8		0x04000000ul
#define PDL_POE_HI_Z_GPT23_ADD_POE10	0x08000000ul

/* Output pin selection */
#define PDL_POE_HI_Z_ENABLE_MTIOC0A		0x0001u
#define PDL_POE_HI_Z_ENABLE_MTIOC0B		0x0002u
#define PDL_POE_HI_Z_ENABLE_MTIOC0C		0x0004u
#define PDL_POE_HI_Z_ENABLE_MTIOC0D		0x0008u

#define PDL_POE_HI_Z_ENABLE_MTIOC7BD	0x0010u
#define PDL_POE_HI_Z_ENABLE_MTIOC7AC	0x0020u
#define PDL_POE_HI_Z_ENABLE_MTIOC6BD	0x0040u

#define PDL_POE_HI_Z_ENABLE_MTIOC4BD	0x0080u
#define PDL_POE_HI_Z_ENABLE_MTIOC4AC	0x0100u
#define PDL_POE_HI_Z_ENABLE_MTIOC3BD	0x0200u

#define PDL_POE_HI_Z_ENABLE_GTIOC0		0x0400u
#define PDL_POE_HI_Z_ENABLE_GTIOC1		0x0800u
#define PDL_POE_HI_Z_ENABLE_GTIOC2		0x1000u
#define PDL_POE_HI_Z_ENABLE_GTIOC3		0x2000u

/* Output short detection */
#define PDL_POE_SHORT_USE_MTU		0x0001u
#define PDL_POE_SHORT_SPECIFY		0x0002u
#define PDL_POE_SHORT_P71_LOW		0x0004u
#define PDL_POE_SHORT_P71_HIGH		0x0008u
#define PDL_POE_SHORT_P74_LOW		0x0010u
#define PDL_POE_SHORT_P74_HIGH		0x0020u
#define PDL_POE_SHORT_P72_LOW		0x0040u
#define PDL_POE_SHORT_P72_HIGH		0x0080u
#define PDL_POE_SHORT_P75_LOW		0x0100u
#define PDL_POE_SHORT_P75_HIGH		0x0200u
#define PDL_POE_SHORT_P73_LOW		0x0400u
#define PDL_POE_SHORT_P73_HIGH		0x0800u
#define PDL_POE_SHORT_P76_LOW		0x1000u
#define PDL_POE_SHORT_P76_HIGH		0x2000u

/* Output short response */
#define PDL_POE_SHORT_P7X_HI_Z		0x4000u
#define PDL_POE_SHORT_MTU_67_HI_Z	0x8000u

/* High impedance request response */
#define PDL_POE_IRQ_HI_Z_0_DISABLE		0x0001u
#define PDL_POE_IRQ_HI_Z_0_ENABLE		0x0002u
#define PDL_POE_IRQ_HI_Z_4_DISABLE		0x0004u
#define PDL_POE_IRQ_HI_Z_4_ENABLE		0x0008u
#define PDL_POE_IRQ_HI_Z_8_DISABLE		0x0010u
#define PDL_POE_IRQ_HI_Z_8_ENABLE		0x0020u
#define PDL_POE_IRQ_HI_Z_10_DISABLE		0x0040u
#define PDL_POE_IRQ_HI_Z_10_ENABLE		0x0080u
#define PDL_POE_IRQ_HI_Z_11_DISABLE		0x0100u
#define PDL_POE_IRQ_HI_Z_11_ENABLE		0x0200u

/* Output short detection response */
#define PDL_POE_IRQ_SHORT_34_ENABLE		0x0400u
#define PDL_POE_IRQ_SHORT_34_DISABLE	0x0800u
#define PDL_POE_IRQ_SHORT_67_ENABLE		0x1000u
#define PDL_POE_IRQ_SHORT_67_DISABLE	0x2000u

/* MTU / GPT channel output high impedance control */
#define PDL_POE_MTU34_HI_Z_ON	0x0001u
#define PDL_POE_MTU34_HI_Z_OFF	0x0002u
#define PDL_POE_MTU67_HI_Z_ON	0x0004u
#define PDL_POE_MTU67_HI_Z_OFF	0x0008u
#define PDL_POE_MTU0_HI_Z_ON	0x0010u
#define PDL_POE_MTU0_HI_Z_OFF	0x0020u
#define PDL_POE_GPT01_HI_Z_ON	0x0040u
#define PDL_POE_GPT01_HI_Z_OFF	0x0080u
#define PDL_POE_GPT23_HI_Z_ON	0x0100u
#define PDL_POE_GPT23_HI_Z_OFF	0x0200u

/* Event flag control */
#define PDL_POE_FLAG_POE0_CLEAR		0x01u
#define PDL_POE_FLAG_POE4_CLEAR		0x02u
#define PDL_POE_FLAG_POE8_CLEAR		0x04u
#define PDL_POE_FLAG_POE10_CLEAR	0x08u
#define PDL_POE_FLAG_POE11_CLEAR	0x10u
#define PDL_POE_FLAG_SHORT_34_CLEAR	0x20u
#define PDL_POE_FLAG_SHORT_67_CLEAR	0x40u

#endif
/* End of file */
