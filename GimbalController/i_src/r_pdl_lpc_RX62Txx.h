/*""FILE COMMENT""*******************************************************
* System Name	: LPC API for RX62Txx
* File Name		: r_pdl_lpc_RX62Txx.h
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

#ifndef R_PDL_LPC_RX62Txx_H
#define R_PDL_LPC_RX62Txx_H

#define R_PDL_LPC_BACKUP_AREA_SIZE	32

/* Library prototypes */
bool R_LPC_CreateAll(
	const uint16_t,
	const uint32_t
);
bool R_LPC_ControlAll(
	const uint8_t
);
bool R_LPC_WriteBackupAll(
	volatile const uint8_t * const,
	const uint8_t
);
bool R_LPC_ReadBackupAll(
	volatile uint8_t * const,
	const uint8_t
);
bool R_LPC_GetStatusAll(
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_LPC_Create(a, b) \
( \
R_LPC_CreateAll( (a), (b) ) \
)

#define R_LPC_Control(a) \
( \
R_LPC_ControlAll( (a) ) \
)

#define R_LPC_WriteBackup(a, b) \
( \
( ( ((b) > 0) && ((b) <= R_PDL_LPC_BACKUP_AREA_SIZE) ) ) ? \
R_LPC_WriteBackupAll( (a), (b) ) : \
ReturnFalse() \
)

#define R_LPC_ReadBackup(a, b) \
( \
( ( ((b) > 0) && ((b) <= R_PDL_LPC_BACKUP_AREA_SIZE) ) ) ? \
R_LPC_ReadBackupAll( (a), (b) ) : \
ReturnFalse() \
)

#define R_LPC_GetStatus(a) \
( \
R_LPC_GetStatusAll( (a) ) \
)

#endif
/* End of file */
