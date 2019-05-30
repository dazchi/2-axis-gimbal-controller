/*""FILE COMMENT""*******************************************************
* System Name	: LIN module API for RX62Nxx
* File Name		: r_pdl_lin.h
* Version		: 1.01
* Contents		: LIN API header
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

#ifndef R_PDL_LIN_H
#define R_PDL_LIN_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_LIN_Create(
	uint8_t,
	uint8_t,
	uint32_t,
	uint32_t,
	uint32_t,
	void *,
	uint8_t
);
bool R_LIN_Destroy(
	uint8_t
);
bool R_LIN_Transfer(
	uint8_t,
	uint8_t,
	uint8_t,
	uint8_t *,
	uint8_t
);
bool R_LIN_Read(
	uint8_t,
	uint8_t *,
	uint8_t
);
bool R_LIN_Control(
	uint8_t,
	uint8_t,
	uint8_t
);
bool R_LIN_GetStatus(
	uint8_t,
	uint16_t *,
	uint8_t *
);

/* Error detection control */
#define PDL_LIN_ERROR_BIT_DISABLE			0x01u
#define PDL_LIN_ERROR_BIT_ENABLE			0x02u
#define PDL_LIN_ERROR_BUS_DISABLE			0x04u
#define PDL_LIN_ERROR_BUS_ENABLE			0x08u
#define PDL_LIN_ERROR_FRAME_TIMEOUT_DISABLE	0x10u
#define PDL_LIN_ERROR_FRAME_TIMEOUT_ENABLE	0x20u
#define PDL_LIN_ERROR_FRAMING_DISABLE		0x40u
#define PDL_LIN_ERROR_FRAMING_ENABLE		0x80u
#define PDL_LIN_ERROR_ALL_ENABLE	(PDL_LIN_ERROR_BIT_ENABLE | \
PDL_LIN_ERROR_BUS_ENABLE | \
PDL_LIN_ERROR_FRAME_TIMEOUT_ENABLE | \
PDL_LIN_ERROR_FRAMING_ENABLE)

/* Transmit Break (Low) width */
#define PDL_LIN_TB_LOW_13	0x00000001ul
#define PDL_LIN_TB_LOW_14	0x00000002ul
#define PDL_LIN_TB_LOW_15	0x00000004ul
#define PDL_LIN_TB_LOW_16	0x00000008ul
#define PDL_LIN_TB_LOW_17	0x00000010ul
#define PDL_LIN_TB_LOW_18	0x00000020ul
#define PDL_LIN_TB_LOW_19	0x00000040ul
#define PDL_LIN_TB_LOW_20	0x00000080ul
#define PDL_LIN_TB_LOW_21	0x00000100ul
#define PDL_LIN_TB_LOW_22	0x00000200ul
#define PDL_LIN_TB_LOW_23	0x00000400ul
#define PDL_LIN_TB_LOW_24	0x00000800ul
#define PDL_LIN_TB_LOW_25	0x00001000ul
#define PDL_LIN_TB_LOW_26	0x00002000ul
#define PDL_LIN_TB_LOW_27	0x00004000ul
#define PDL_LIN_TB_LOW_28	0x00008000ul

/* Transmit Break Delimiter (High) width */
#define PDL_LIN_TB_HIGH_1	0x00010000ul
#define PDL_LIN_TB_HIGH_2	0x00020000ul
#define PDL_LIN_TB_HIGH_3	0x00040000ul
#define PDL_LIN_TB_HIGH_4	0x00080000ul

/* Interbyte and response space width */
#define PDL_LIN_IBHR_SPACE_0	0x00000001ul
#define PDL_LIN_IBHR_SPACE_1	0x00000002ul
#define PDL_LIN_IBHR_SPACE_2	0x00000004ul
#define PDL_LIN_IBHR_SPACE_3	0x00000008ul
#define PDL_LIN_IBHR_SPACE_4	0x00000010ul
#define PDL_LIN_IBHR_SPACE_5	0x00000020ul
#define PDL_LIN_IBHR_SPACE_6	0x00000040ul
#define PDL_LIN_IBHR_SPACE_7	0x00000080ul

/* Interbyte and response space width */
#define PDL_LIN_IB_SPACE_0		0x00000100ul
#define PDL_LIN_IB_SPACE_1		0x00000200ul
#define PDL_LIN_IB_SPACE_2		0x00000400ul
#define PDL_LIN_IB_SPACE_3		0x00000800ul

/* Wake-up detection control */
#define PDL_LIN_WAKE_SPEC_13	0x00001000ul
#define PDL_LIN_WAKE_SPEC_2		0x00002000ul

/* Wake-up pulse transmission width */
#define PDL_LIN_WAKE_LENGTH_1	0x00004000ul
#define PDL_LIN_WAKE_LENGTH_2	0x00008000ul
#define PDL_LIN_WAKE_LENGTH_3	0x00010000ul
#define PDL_LIN_WAKE_LENGTH_4	0x00020000ul
#define PDL_LIN_WAKE_LENGTH_5	0x00040000ul
#define PDL_LIN_WAKE_LENGTH_6	0x00080000ul
#define PDL_LIN_WAKE_LENGTH_7	0x00100000ul
#define PDL_LIN_WAKE_LENGTH_8	0x00200000ul
#define PDL_LIN_WAKE_LENGTH_9	0x00400000ul
#define PDL_LIN_WAKE_LENGTH_10	0x00800000ul
#define PDL_LIN_WAKE_LENGTH_11	0x01000000ul
#define PDL_LIN_WAKE_LENGTH_12	0x02000000ul
#define PDL_LIN_WAKE_LENGTH_13	0x04000000ul
#define PDL_LIN_WAKE_LENGTH_14	0x08000000ul
#define PDL_LIN_WAKE_LENGTH_15	0x10000000ul
#define PDL_LIN_WAKE_LENGTH_16	0x20000000ul

/* Transfer type */
#define PDL_LIN_TX_DATA				0x01u
#define PDL_LIN_RX_DATA				0x02u

/* ID parity calculation */
#define PDL_LIN_PARITY_CALCULATE	0x04u

/* Checksum type */
#define PDL_LIN_CHECKSUM_CLASSIC	0x08u
#define PDL_LIN_CHECKSUM_ENHANCED	0x10u

/* Reset control */
#define PDL_LIN_RESET				0x01u

/* Operation mode control */
#define PDL_LIN_MODE_OPERATION		0x02u
#define PDL_LIN_MODE_WAKE_UP		0x04u
#define PDL_LIN_MODE_SELFTEST		0x08u

/* Wake-up control */
#define PDL_LIN_WAKE_UP_TX			0x10u
#define PDL_LIN_WAKE_UP_RX			0x20u

/* Check sum register control  */
#define PDL_LIN_CHECKSUM_WRITE		0x40u

#endif
/* End of file */
