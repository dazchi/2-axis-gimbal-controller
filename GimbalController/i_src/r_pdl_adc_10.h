/*""FILE COMMENT""*******************************************************
* System Name	: ADC converter API for RX62T
* File Name		: r_pdl_adc_10.h
* Version		: 1.01
* Contents		: ADC function prototypes
* Customer		:
* Model			:
* Order			:
* CPU			: RX
* Compiler		: RXC
* OS			:
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

#ifndef R_PDL_ADC_10_H
#define R_PDL_ADC_10_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */
bool R_ADC_10_Create(
	uint8_t,
	uint32_t,
	uint32_t,
	float,
	void *,
	uint8_t
);
bool R_ADC_10_Destroy(
	uint8_t
);
bool R_ADC_10_Control(
	uint16_t
);
bool R_ADC_10_Read(
	uint8_t,
	uint16_t *
);

/* Scan mode */
#define PDL_ADC_10_MODE_SINGLE					0x00000001u
#define PDL_ADC_10_MODE_CONTINUOUS_SCAN			0x00000002u
#define PDL_ADC_10_MODE_ONE_CYCLE_SCAN			0x00000004u

/* Channel selection */
#define PDL_ADC_10_CHANNELS_OPTION_0			0x00000008u
#define PDL_ADC_10_CHANNELS_OPTION_1			0x00000010u
#define PDL_ADC_10_CHANNELS_OPTION_2			0x00000020u
#define PDL_ADC_10_CHANNELS_OPTION_3			0x00000040u
#define PDL_ADC_10_CHANNELS_OPTION_4			0x00000080u
#define PDL_ADC_10_CHANNELS_OPTION_5			0x00000100u
#define PDL_ADC_10_CHANNELS_OPTION_6			0x00000200u
#define PDL_ADC_10_CHANNELS_OPTION_7			0x00000400u
#define PDL_ADC_10_CHANNELS_OPTION_8			0x00000800u
#define PDL_ADC_10_CHANNELS_OPTION_9			0x00001000u
#define PDL_ADC_10_CHANNELS_OPTION_10			0x00002000u
#define PDL_ADC_10_CHANNELS_OPTION_11			0x00004000u

/* Data alignment */
#define PDL_ADC_10_DATA_ALIGNMENT_LEFT			0x00008000u
#define PDL_ADC_10_DATA_ALIGNMENT_RIGHT			0x00010000u

/* DTC trigger control */
#define PDL_ADC_10_DTC_TRIGGER_DISABLE			0x00020000u
#define PDL_ADC_10_DTC_TRIGGER_ENABLE			0x00040000u

/* Sampling time calcuation control */
#define PDL_ADC_10_ADSSTR_CALCULATE				0x00080000u
#define PDL_ADC_10_ADSSTR_SPECIFY				0x00100000u

/* Data accuracy */
#define PDL_ADC_10_DATA_ACCURACY_10_BIT			0x00200000u
#define PDL_ADC_10_DATA_ACCURACY_8_BIT			0x00400000u

/* Self-Diagnostic */									
#define PDL_ADC_10_SINGLE_AN0					(PDL_ADC_10_MODE_SINGLE | \
												 PDL_ADC_10_CHANNELS_OPTION_0)
#define PDL_ADC_10_ADDIAGR_DISABLE				0x00800000u
#define PDL_ADC_10_ADDIAGR_VREF_ZERO			0x01000000u
#define PDL_ADC_10_ADDIAGR_VREF_HALF			0x02000000u
#define PDL_ADC_10_ADDIAGR_VREF_FULL			0x04000000u
#define PDL_ADC_10_SELF_DIAGNOSTIC_DISABLE		(PDL_ADC_10_ADDIAGR_DISABLE)
#define PDL_ADC_10_SELF_DIAGNOSTIC_VREF_ZERO	(PDL_ADC_10_SINGLE_AN0 | \
												 PDL_ADC_10_ADDIAGR_VREF_ZERO)
#define PDL_ADC_10_SELF_DIAGNOSTIC_VREF_HALF	(PDL_ADC_10_SINGLE_AN0 | \
												 PDL_ADC_10_ADDIAGR_VREF_HALF)
#define PDL_ADC_10_SELF_DIAGNOSTIC_VREF_FULL	(PDL_ADC_10_SINGLE_AN0 | \
												 PDL_ADC_10_ADDIAGR_VREF_FULL)

/* Trigger selection */
#define PDL_ADC_10_TRIGGER_SOFTWARE				0x00000001u
#define PDL_ADC_10_TRIGGER_ADTRG				0x00000002u
#define PDL_ADC_10_TRIGGER_MTU_0_CMIC			0x00000004u
#define PDL_ADC_10_TRIGGER_MTU_1_CMIC			0x00000008u
#define PDL_ADC_10_TRIGGER_MTU_2_CMIC			0x00000010u
#define PDL_ADC_10_TRIGGER_MTU_3_CMIC			0x00000020u
#define PDL_ADC_10_TRIGGER_MTU_4_CMIC			0x00000040u
#define PDL_ADC_10_TRIGGER_MTU_6_CMIC			0x00000080u
#define PDL_ADC_10_TRIGGER_MTU_7_CMIC			0x00000100u
#define PDL_ADC_10_TRIGGER_MTU_0_CM_E			0x00000200u
#define PDL_ADC_10_TRIGGER_MTU_4_CM_A			0x00000400u
#define PDL_ADC_10_TRIGGER_MTU_4_CM_B			0x00000800u
#define PDL_ADC_10_TRIGGER_MTU_4_CM_AB			0x00001000u
#define PDL_ADC_10_TRIGGER_MTU_4_CM_AB_IS		0x00002000u
#define PDL_ADC_10_TRIGGER_MTU_7_CM_A			0x00004000u
#define PDL_ADC_10_TRIGGER_MTU_7_CM_B			0x00008000u
#define PDL_ADC_10_TRIGGER_MTU_7_CM_AB			0x00010000u
#define PDL_ADC_10_TRIGGER_MTU_7_CM_AB_IS		0x00020000u
#define PDL_ADC_10_TRIGGER_GPT0_CM_A			0x00040000u
#define PDL_ADC_10_TRIGGER_GPT0_CM_B			0x00080000u
#define PDL_ADC_10_TRIGGER_GPT1_CM_A			0x00100000u
#define PDL_ADC_10_TRIGGER_GPT1_CM_B			0x00200000u
#define PDL_ADC_10_TRIGGER_GPT2_CM_A			0x00400000u
#define PDL_ADC_10_TRIGGER_GPT2_CM_B			0x00800000u
#define PDL_ADC_10_TRIGGER_GPT3_CM_A			0x01000000u
#define PDL_ADC_10_TRIGGER_GPT3_CM_B			0x02000000u
#define PDL_ADC_10_TRIGGER_GPT0_CM_AB			0x04000000u
#define PDL_ADC_10_TRIGGER_GPT1_CM_AB			0x08000000u
#define PDL_ADC_10_TRIGGER_GPT2_CM_AB			0x10000000u
#define PDL_ADC_10_TRIGGER_GPT3_CM_AB			0x20000000u

/* On / off control */
#define PDL_ADC_10_0_ON							0x01u
#define PDL_ADC_10_0_OFF						0x02u

/* CPU control */
#define PDL_ADC_10_CPU_ON						0x10u
#define PDL_ADC_10_CPU_OFF						0x20u

#endif
/* End of file */
