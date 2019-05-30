/*""FILE COMMENT""*******************************************************
* System Name	: DTC API for RX62T
* File Name		: r_pdl_dtc.h
* Version		: 1.01
* Contents		: DTC API header
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

#ifndef R_PDL_DTC_H
#define R_PDL_DTC_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_DTC_Set(
	uint8_t,
	uint32_t *
);
bool R_DTC_Create(
	uint32_t,
	uint32_t *,
	void *,
	void *,
	uint16_t,
	uint8_t
);
bool R_DTC_Destroy(
	void
);
bool R_DTC_Control(
	uint32_t,
	uint32_t *,
	void *,
	void *,
	uint16_t,
	uint8_t
);
bool R_DTC_GetStatus(
	uint32_t *,
	uint16_t *,
	uint32_t *,
	uint32_t *,
 	uint16_t *,
 	uint8_t *
);

/* Read skip control */
#define PDL_DTC_READ_SKIP_DISABLE			0x01u
#define PDL_DTC_READ_SKIP_ENABLE			0x02u

/* Address size control */
#define PDL_DTC_ADDRESS_FULL				0x04u
#define PDL_DTC_ADDRESS_SHORT				0x08u

/* Transfer mode selection */
#define PDL_DTC_NORMAL						0x00000001ul
#define PDL_DTC_REPEAT						0x00000002ul
#define PDL_DTC_BLOCK						0x00000004ul
#define PDL_DTC_SOURCE						0x00000008ul
#define PDL_DTC_DESTINATION					0x00000010ul

/* Address direction selection */
#define PDL_DTC_SOURCE_ADDRESS_FIXED		0x00000020ul
#define PDL_DTC_SOURCE_ADDRESS_PLUS			0x00000040ul
#define PDL_DTC_SOURCE_ADDRESS_MINUS		0x00000080ul
#define PDL_DTC_DESTINATION_ADDRESS_FIXED	0x00000100ul
#define PDL_DTC_DESTINATION_ADDRESS_PLUS	0x00000200ul
#define PDL_DTC_DESTINATION_ADDRESS_MINUS	0x00000400ul

/* Transfer data size */
#define PDL_DTC_SIZE_8						0x00000800ul
#define PDL_DTC_SIZE_16						0x00001000ul
#define PDL_DTC_SIZE_32						0x00002000ul

/* Chain transfer control */
#define PDL_DTC_CHAIN_DISABLE				0x00004000ul
#define PDL_DTC_CHAIN_CONTINUOUS			0x00008000ul
#define PDL_DTC_CHAIN_0						0x00010000ul

/* Interrupt generation */
#define PDL_DTC_IRQ_COMPLETE				0x00020000ul
#define PDL_DTC_IRQ_TRANSFER				0x00040000ul

/* Trigger selection */
#define PDL_DTC_TRIGGER_CHAIN		(uint32_t)(0x00u << 24)
#define PDL_DTC_TRIGGER_SW			(uint32_t)(VECT_ICU_SWINT << 24)
#define PDL_DTC_TRIGGER_CMT0		(uint32_t)(VECT_CMT0_CMI0 << 24)
#define PDL_DTC_TRIGGER_CMT1		(uint32_t)(VECT_CMT1_CMI1 << 24)
#define PDL_DTC_TRIGGER_CMT2		(uint32_t)(VECT_CMT2_CMI2 << 24)
#define PDL_DTC_TRIGGER_CMT3		(uint32_t)(VECT_CMT3_CMI3 << 24)
#define PDL_DTC_TRIGGER_SPI0_RX		(uint32_t)(VECT_RSPI0_SPRI0 << 24)
#define PDL_DTC_TRIGGER_SPI0_TX		(uint32_t)(VECT_RSPI0_SPTI0 << 24)
#define PDL_DTC_TRIGGER_IRQ0		(uint32_t)(VECT_ICU_IRQ0 << 24)
#define PDL_DTC_TRIGGER_IRQ1		(uint32_t)(VECT_ICU_IRQ1 << 24)
#define PDL_DTC_TRIGGER_IRQ2		(uint32_t)(VECT_ICU_IRQ2 << 24)
#define PDL_DTC_TRIGGER_IRQ3		(uint32_t)(VECT_ICU_IRQ3 << 24)
#define PDL_DTC_TRIGGER_IRQ4		(uint32_t)(VECT_ICU_IRQ4 << 24)
#define PDL_DTC_TRIGGER_IRQ5		(uint32_t)(VECT_ICU_IRQ5 << 24)
#define PDL_DTC_TRIGGER_IRQ6		(uint32_t)(VECT_ICU_IRQ6 << 24)
#define PDL_DTC_TRIGGER_IRQ7		(uint32_t)(VECT_ICU_IRQ7 << 24)
#define PDL_DTC_TRIGGER_ADI0		(uint32_t)(VECT_AD0_ADI0 << 24)
#define PDL_DTC_TRIGGER_S12ADI0		(uint32_t)(VECT_S12AD0_S12ADI0 << 24)
#define PDL_DTC_TRIGGER_S12ADI1		(uint32_t)(VECT_S12AD1_S12ADI1 << 24)
#define PDL_DTC_TRIGGER_CMPI		(uint32_t)(VECT_S12AD_CMPI << 24)
#define PDL_DTC_TRIGGER_TGIA0		(uint32_t)(VECT_MTU0_TGIA0 << 24)
#define PDL_DTC_TRIGGER_TGIA1		(uint32_t)(VECT_MTU1_TGIA1 << 24)
#define PDL_DTC_TRIGGER_TGIA2		(uint32_t)(VECT_MTU2_TGIA2 << 24)
#define PDL_DTC_TRIGGER_TGIA3		(uint32_t)(VECT_MTU3_TGIA3 << 24)
#define PDL_DTC_TRIGGER_TGIA4		(uint32_t)(VECT_MTU4_TGIA4 << 24)
#define PDL_DTC_TRIGGER_TGIA6		(uint32_t)(VECT_MTU6_TGIA6 << 24)
#define PDL_DTC_TRIGGER_TGIA7		(uint32_t)(VECT_MTU7_TGIA7 << 24)
#define PDL_DTC_TRIGGER_TGIB0		(uint32_t)(VECT_MTU0_TGIB0 << 24)
#define PDL_DTC_TRIGGER_TGIB1		(uint32_t)(VECT_MTU1_TGIB1 << 24)
#define PDL_DTC_TRIGGER_TGIB2		(uint32_t)(VECT_MTU2_TGIB2 << 24)
#define PDL_DTC_TRIGGER_TGIB3		(uint32_t)(VECT_MTU3_TGIB3 << 24)
#define PDL_DTC_TRIGGER_TGIB4		(uint32_t)(VECT_MTU4_TGIB4 << 24)
#define PDL_DTC_TRIGGER_TGIB6		(uint32_t)(VECT_MTU6_TGIB6 << 24)
#define PDL_DTC_TRIGGER_TGIB7		(uint32_t)(VECT_MTU7_TGIB7 << 24)
#define PDL_DTC_TRIGGER_TGIC0		(uint32_t)(VECT_MTU0_TGIC0 << 24)
#define PDL_DTC_TRIGGER_TGIC3		(uint32_t)(VECT_MTU3_TGIC3 << 24)
#define PDL_DTC_TRIGGER_TGIC4		(uint32_t)(VECT_MTU4_TGIC4 << 24)
#define PDL_DTC_TRIGGER_TGIC6		(uint32_t)(VECT_MTU6_TGIC6 << 24)
#define PDL_DTC_TRIGGER_TGIC7		(uint32_t)(VECT_MTU7_TGIC7 << 24)
#define PDL_DTC_TRIGGER_TGID0		(uint32_t)(VECT_MTU0_TGID0 << 24)
#define PDL_DTC_TRIGGER_TGID3		(uint32_t)(VECT_MTU3_TGID3 << 24)
#define PDL_DTC_TRIGGER_TGID4		(uint32_t)(VECT_MTU4_TGID4 << 24)
#define PDL_DTC_TRIGGER_TGID6		(uint32_t)(VECT_MTU6_TGID6 << 24)
#define PDL_DTC_TRIGGER_TGID7		(uint32_t)(VECT_MTU7_TGID7 << 24)
#define PDL_DTC_TRIGGER_TGIU5		(uint32_t)(VECT_MTU5_TGIU5 << 24)
#define PDL_DTC_TRIGGER_TGIV5		(uint32_t)(VECT_MTU5_TGIV5 << 24)
#define PDL_DTC_TRIGGER_TGIW5		(uint32_t)(VECT_MTU5_TGIW5 << 24)
#define PDL_DTC_TRIGGER_TCIV4		(uint32_t)(VECT_MTU4_TCIV4 << 24)
#define PDL_DTC_TRIGGER_TCIV7		(uint32_t)(VECT_MTU7_TCIV7 << 24)
#define PDL_DTC_TRIGGER_GTCIA0		(uint32_t)(VECT_GPT0_GTCIA0 << 24)
#define PDL_DTC_TRIGGER_GTCIA1		(uint32_t)(VECT_GPT1_GTCIA1 << 24)
#define PDL_DTC_TRIGGER_GTCIA2		(uint32_t)(VECT_GPT2_GTCIA2 << 24)
#define PDL_DTC_TRIGGER_GTCIA3		(uint32_t)(VECT_GPT3_GTCIA3 << 24)
#define PDL_DTC_TRIGGER_GTCIB0		(uint32_t)(VECT_GPT0_GTCIB0 << 24)
#define PDL_DTC_TRIGGER_GTCIB1		(uint32_t)(VECT_GPT1_GTCIB1 << 24)
#define PDL_DTC_TRIGGER_GTCIB2		(uint32_t)(VECT_GPT2_GTCIB2 << 24)
#define PDL_DTC_TRIGGER_GTCIB3		(uint32_t)(VECT_GPT3_GTCIB3 << 24)
#define PDL_DTC_TRIGGER_GTCIC0		(uint32_t)(VECT_GPT0_GTCIC0 << 24)
#define PDL_DTC_TRIGGER_GTCIC1		(uint32_t)(VECT_GPT1_GTCIC1 << 24)
#define PDL_DTC_TRIGGER_GTCIC2		(uint32_t)(VECT_GPT2_GTCIC2 << 24)
#define PDL_DTC_TRIGGER_GTCIC3		(uint32_t)(VECT_GPT3_GTCIC3 << 24)
#define PDL_DTC_TRIGGER_GTCIE0		(uint32_t)(VECT_GPT0_GTCIE0 << 24)
#define PDL_DTC_TRIGGER_GTCIE1		(uint32_t)(VECT_GPT1_GTCIE1 << 24)
#define PDL_DTC_TRIGGER_GTCIE2		(uint32_t)(VECT_GPT2_GTCIE2 << 24)
#define PDL_DTC_TRIGGER_GTCIE3		(uint32_t)(VECT_GPT3_GTCIE3 << 24)
#define PDL_DTC_TRIGGER_GTCIV0		(uint32_t)(VECT_GPT0_GTCIV0 << 24)
#define PDL_DTC_TRIGGER_GTCIV1		(uint32_t)(VECT_GPT1_GTCIV1 << 24)
#define PDL_DTC_TRIGGER_GTCIV2		(uint32_t)(VECT_GPT2_GTCIV2 << 24)
#define PDL_DTC_TRIGGER_GTCIV3		(uint32_t)(VECT_GPT3_GTCIV3 << 24)
#define PDL_DTC_TRIGGER_LOCO1		(uint32_t)(VECT_GPT0_LOCO1 << 24)
#define PDL_DTC_TRIGGER_RXI0		(uint32_t)(VECT_SCI0_RXI0 << 24)
#define PDL_DTC_TRIGGER_RXI1		(uint32_t)(VECT_SCI1_RXI1 << 24)
#define PDL_DTC_TRIGGER_RXI2		(uint32_t)(VECT_SCI2_RXI2 << 24)
#define PDL_DTC_TRIGGER_TXI0		(uint32_t)(VECT_SCI0_TXI0 << 24)
#define PDL_DTC_TRIGGER_TXI1		(uint32_t)(VECT_SCI1_TXI1 << 24)
#define PDL_DTC_TRIGGER_TXI2		(uint32_t)(VECT_SCI2_TXI2 << 24)
#define PDL_DTC_TRIGGER_ICRXI0		(uint32_t)(VECT_RIIC0_ICRXI0 << 24)
#define PDL_DTC_TRIGGER_ICTXI0		(uint32_t)(VECT_RIIC0_ICTXI0 << 24)

/* Stop / Start control */
#define PDL_DTC_STOP				0x01u
#define PDL_DTC_START				0x02u

/* Register modification control */
#define PDL_DTC_UPDATE_SOURCE		0x04ul
#define PDL_DTC_UPDATE_DESTINATION	0x08ul
#define PDL_DTC_UPDATE_COUNT		0x10ul
#define PDL_DTC_UPDATE_BLOCK_SIZE	0x20ul

#endif
/* End of file */
