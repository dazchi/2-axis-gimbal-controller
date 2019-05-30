/*""FILE COMMENT""*******************************************************
* System Name	: LPC API for RX62Txx
* File Name		: r_pdl_lpc.h
* Version		: 1.01
* Contents		: LPC API header
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

#ifndef R_PDL_LPC_H
#define R_PDL_LPC_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_LPC_Create(
	uint16_t,
	uint32_t
);
bool R_LPC_Control(
	uint8_t
);
bool R_LPC_WriteBackup(
	uint8_t *,
	uint8_t
);
bool R_LPC_ReadBackup(
	uint8_t *,
	uint8_t
);
bool R_LPC_GetStatus(
	uint16_t *
);

/* I/O port retention control */
#define PDL_LPC_IO_SAME				0x0001u
#define PDL_LPC_IO_DELAY			0x0002u
                                           
/* Deep software standby cancel control */ 
#define PDL_LPC_CANCEL_IRQ0_DISABLE	0x0004u
#define PDL_LPC_CANCEL_IRQ0_FALLING	0x0008u
#define PDL_LPC_CANCEL_IRQ0_RISING	0x0010u
#define PDL_LPC_CANCEL_IRQ1_DISABLE	0x0020u
#define PDL_LPC_CANCEL_IRQ1_FALLING	0x0040u
#define PDL_LPC_CANCEL_IRQ1_RISING	0x0080u
#define PDL_LPC_CANCEL_NMI_DISABLE	0x0100u
#define PDL_LPC_CANCEL_NMI_FALLING	0x0200u
#define PDL_LPC_CANCEL_NMI_RISING	0x0400u
#define PDL_LPC_CANCEL_LVD_DISABLE	0x0800u
#define PDL_LPC_CANCEL_LVD_ENABLE	0x1000u

/* Software Standby waiting time */
#define PDL_LPC_STANDBY_64			0x00000001ul
#define PDL_LPC_STANDBY_512			0x00000002ul
#define PDL_LPC_STANDBY_1024		0x00000004ul
#define PDL_LPC_STANDBY_2048		0x00000008ul
#define PDL_LPC_STANDBY_4096		0x00000010ul
#define PDL_LPC_STANDBY_16384		0x00000020ul
#define PDL_LPC_STANDBY_32768		0x00000040ul
#define PDL_LPC_STANDBY_65536		0x00000080ul
#define PDL_LPC_STANDBY_131072		0x00000100ul
#define PDL_LPC_STANDBY_262144		0x00000200ul
#define PDL_LPC_STANDBY_524288		0x00000400ul

/* Deep Software Standby waiting time */
#define PDL_LPC_DEEP_STANDBY_64		0x00000800ul
#define PDL_LPC_DEEP_STANDBY_512	0x00001000ul
#define PDL_LPC_DEEP_STANDBY_1024	0x00002000ul
#define PDL_LPC_DEEP_STANDBY_2048	0x00004000ul
#define PDL_LPC_DEEP_STANDBY_4096	0x00008000ul
#define PDL_LPC_DEEP_STANDBY_16384	0x00010000ul
#define PDL_LPC_DEEP_STANDBY_32768	0x00020000ul
#define PDL_LPC_DEEP_STANDBY_65536	0x00040000ul
#define PDL_LPC_DEEP_STANDBY_131072	0x00080000ul
#define PDL_LPC_DEEP_STANDBY_262144	0x00100000ul
#define PDL_LPC_DEEP_STANDBY_524288	0x00200000ul

/* Error monitoring */
#define PDL_LPC_MODE_SLEEP					0x01u
#define PDL_LPC_MODE_ALL_MODULE_CLOCK_STOP	0x02u
#define PDL_LPC_MODE_SOFTWARE_STANDBY		0x04u
#define PDL_LPC_MODE_DEEP_SOFTWARE_STANDBY	0x08u

/* I/O port retention cancellation */
#define PDL_LPC_IO_RELEASE					0x10u

#endif
/* End of file */
