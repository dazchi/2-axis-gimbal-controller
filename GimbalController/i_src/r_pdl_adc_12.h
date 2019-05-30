/*""FILE COMMENT""*******************************************************
* System Name	: 12-bit ADC converter API for RX62Txx
* File Name		: r_pdl_adc_12.h
* Version		: 1.01
* Contents		: ADC_12 function prototypes
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

#ifndef R_PDL_ADC_12_H
#define R_PDL_ADC_12_H

#include "r_pdl_common_defs_RX62Txx.h"

/* Function prototypes */

bool R_ADC_12_Set(
	uint8_t
);

bool R_ADC_12_CreateChannel(
	uint32_t,
	uint32_t,
	uint32_t,
	uint32_t,
	uint32_t,
	uint32_t,
	uint32_t,
	void *,
	uint8_t
);

bool R_ADC_12_CreateUnit(
	uint8_t,
	uint32_t,
	uint32_t,
	uint32_t,
	uint32_t,
	float,
	void *,
	uint8_t
);

bool R_ADC_12_Control(
	uint8_t
);

bool R_ADC_12_Read(
	uint8_t,
	uint8_t *,
	uint16_t *,
	uint16_t *
);

bool R_ADC_12_Destroy(
	uint8_t
);

#define PDL_ADC_12_0_STATE						0x01u
#define PDL_ADC_12_1_STATE						0x02u
#define PDL_ADC_12_CMP_000_STATE 				0x04u
#define PDL_ADC_12_CMP_001_STATE 				0x08u
#define PDL_ADC_12_CMP_002_STATE 				0x10u
#define PDL_ADC_12_CMP_100_STATE				0x20u
#define PDL_ADC_12_CMP_101_STATE 				0x40u
#define PDL_ADC_12_CMP_102_STATE				0x80u

/* Options of configuration for R_ADC_12_SetAll() */

/* Pin selection (2 units) */
#define PDL_ADC_12_ADTRG0_A						0x01u
#define PDL_ADC_12_ADTRG0_B						0x02u
#define PDL_ADC_12_ADTRG1_A						0x04u
#define PDL_ADC_12_ADTRG1_B						0x08u



/* Options of configuration for R_ADC_12_CreateUnitAll() */

/* S12ADA0/1.ADCSR: Scan mode (2 units) */
#define PDL_ADC_12_MODE_SINGLE					0x00000001u
#define PDL_ADC_12_MODE_ONE_CYCLE_SCAN 			0x00000002u
#define PDL_ADC_12_MODE_CONTINUOUS_SCAN			0x00000004u
#define PDL_ADC_12_MODE_TWO_CHANNEL_SCAN		0x00000008u

/* S12ADA0/1.ADCSR: Trigger source enabling*/
#define PDL_ADC_12_TIMER_TRIGGER_ENABLE			0x00000010u
#define PDL_ADC_12_ADTRGN_TRIGGER_ENABLE		0x00000020u

/* S12ADA0/1.ADANS: Input channel selection (2 units) */
#define PDL_ADC_12_CHANNELS_OPTION_0			0x00000040u
#define PDL_ADC_12_CHANNELS_OPTION_1			0x00000080u
#define PDL_ADC_12_CHANNELS_OPTION_2			0x00000100u
#define PDL_ADC_12_CHANNELS_OPTION_3			0x00000200u

/*  S12ADA0/1.ADSSTR: Sampling time calcuation control (2 units) */
#define PDL_ADC_12_ADSSTR_CALCULATE				0x00000400u
#define PDL_ADC_12_ADSSTR_SPECIFY				0x00000800u

/* S12ADA0/1.ADCER: Dedicated sample-and-hold circuit select (2 units) */
#define PDL_ADC_12_SAMPLE_AND_HOLD_ENABLE		0x00001000u
#define PDL_ADC_12_SAMPLE_AND_HOLD_DISABLE		0x00002000u

/* S12ADA0/1.ADCER: Data precision selection (2 units) */
#define PDL_ADC_12_DATA_PRECISION_12 			0x00004000u
#define PDL_ADC_12_DATA_PRECISION_10 			0x00008000u
#define PDL_ADC_12_DATA_PRECISION_8 			0x00010000u

/* S12ADA0/1.ADCER: Resut register clearing (2 units) */
#define PDL_ADC_12_RETAIN_RESULT				0x00020000u
#define PDL_ADC_12_CLEAR_RESULT					0x00040000u

/* S12ADA0/1.ADCER: Data alignment (2 units) */
#define PDL_ADC_12_DATA_ALIGNMENT_RIGHT			0x00080000u
#define PDL_ADC_12_DATA_ALIGNMENT_LEFT			0x00100000u

/* S12ADA0/1.ADCSR: DTC trigger control (2 units) */
#define PDL_ADC_12_DTC_TRIGGER_DISABLE			0x00200000u
#define PDL_ADC_12_DTC_TRIGGER_ENABLE			0x00400000u

/* S12ADA0/1.ADCER: 2-channel scan interrupt select (2 units) */
#define PDL_ADC_12_EITHER_GROUP					0x00800000u
#define PDL_ADC_12_BOTH_GROUP					0x01000000u

/* S12ADA0/1.ADCER: Double trigger interrupt select (2 units) */
#define PDL_ADC_12_EITHER_TRIGGER				0x02000000u
#define PDL_ADC_12_BOTH_TRIGGER					0x04000000u

/* S12ADA0/1.ADCER: Self-Diagnostic (2 units) */
#define PDL_ADC_12_DIAG_DISABLE					0x08000000u
#define PDL_ADC_12_DIAG_VREFH0_ROTATED			0x10000000u
#define PDL_ADC_12_DIAG_VREFH0_ZERO				0x20000000u
#define PDL_ADC_12_DIAG_VREFH0_HALF				0x40000000u
#define PDL_ADC_12_DIAG_VREFH0_FULL				0x80000000u

#define PDL_ADC_12_SELF_DIAGNOSTIC_DISABLE			(PDL_ADC_12_DIAG_DISABLE)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_ROTATED	(PDL_ADC_12_DIAG_VREFH0_ROTATED)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_ZERO		(PDL_ADC_12_DIAG_VREFH0_ZERO)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_HALF		(PDL_ADC_12_DIAG_VREFH0_HALF)
#define PDL_ADC_12_SELF_DIAGNOSTIC_VREFH0_FULL		(PDL_ADC_12_DIAG_VREFH0_FULL)


/*Options of gpx_trigger_selection for R_ADC_12_CreateUnitAll()*/

/* S12ADA0/1.ADCSR, S12ADA0/1.ADSTRGR: Trigger selection (2 units * 2 groups) */
#define PDL_ADC_12_GP_TRIGGER_MTU_0_CMIC		0x00000001u
#define PDL_ADC_12_GP_TRIGGER_MTU_1_CMIC		0x00000002u
#define PDL_ADC_12_GP_TRIGGER_MTU_2_CMIC		0x00000004u
#define PDL_ADC_12_GP_TRIGGER_MTU_3_CMIC		0x00000008u
#define PDL_ADC_12_GP_TRIGGER_MTU_4_CMIC		0x00000010u
#define PDL_ADC_12_GP_TRIGGER_MTU_6_CMIC		0x00000020u
#define PDL_ADC_12_GP_TRIGGER_MTU_7_CMIC		0x00000040u
#define PDL_ADC_12_GP_TRIGGER_MTU_0_CM_E		0x00000080u
#define PDL_ADC_12_GP_TRIGGER_MTU_4_CM_A		0x00000100u
#define PDL_ADC_12_GP_TRIGGER_MTU_4_CM_B		0x00000200u
#define PDL_ADC_12_GP_TRIGGER_MTU_4_CM_A_B		0x00000400u
#define PDL_ADC_12_GP_TRIGGER_MTU_4_CM_AB_IS	0x00000800u
#define PDL_ADC_12_GP_TRIGGER_MTU_7_CM_A		0x00001000u
#define PDL_ADC_12_GP_TRIGGER_MTU_7_CM_B		0x00002000u
#define PDL_ADC_12_GP_TRIGGER_MTU_7_CM_A_B		0x00004000u
#define PDL_ADC_12_GP_TRIGGER_MTU_7_CM_AB_IS	0x00008000u
#define PDL_ADC_12_GP_TRIGGER_GPT_0_CM_A 		0x00010000u
#define PDL_ADC_12_GP_TRIGGER_GPT_0_CM_B 		0x00020000u
#define PDL_ADC_12_GP_TRIGGER_GPT_1_CM_A 		0x00040000u
#define PDL_ADC_12_GP_TRIGGER_GPT_1_CM_B 		0x00080000u
#define PDL_ADC_12_GP_TRIGGER_GPT_2_CM_A 		0x00100000u
#define PDL_ADC_12_GP_TRIGGER_GPT_2_CM_B 		0x00200000u
#define PDL_ADC_12_GP_TRIGGER_GPT_3_CM_A 		0x00400000u
#define PDL_ADC_12_GP_TRIGGER_GPT_3_CM_B 		0x00800000u
#define PDL_ADC_12_GP_TRIGGER_GPT_0_CM_A_B 		0x01000000u
#define PDL_ADC_12_GP_TRIGGER_GPT_1_CM_A_B 		0x02000000u
#define PDL_ADC_12_GP_TRIGGER_GPT_2_CM_A_B 		0x04000000u
#define PDL_ADC_12_GP_TRIGGER_GPT_3_CM_A_B 		0x08000000u



/*Options of configuration for R_ADC_12_CreateUnitChannelAll()*/

/* ADCMPMD1: Comparator reference voltage control (All) */
#define PDL_ADC_12_CMP_REFL_AVCC0_1_8			0x00000001u
#define PDL_ADC_12_CMP_REFL_AVCC0_2_8			0x00000002u
#define PDL_ADC_12_CMP_REFL_AVCC0_3_8			0x00000004u
#define PDL_ADC_12_CMP_REFL_AVCC0_4_8			0x00000008u
#define PDL_ADC_12_CMP_REFL_AVCC0_5_8			0x00000010u
#define PDL_ADC_12_CMP_REFL_AVCC0_6_8			0x00000020u
#define PDL_ADC_12_CMP_REFL_AVCC0_7_8			0x00000040u
#define PDL_ADC_12_CMP_REFH_AVCC0_1_8			0x00000080u
#define PDL_ADC_12_CMP_REFH_AVCC0_2_8			0x00000100u
#define PDL_ADC_12_CMP_REFH_AVCC0_3_8			0x00000200u
#define PDL_ADC_12_CMP_REFH_AVCC0_4_8			0x00000400u
#define PDL_ADC_12_CMP_REFH_AVCC0_5_8			0x00000800u
#define PDL_ADC_12_CMP_REFH_AVCC0_6_8			0x00001000u
#define PDL_ADC_12_CMP_REFH_AVCC0_7_8			0x00002000u

/* ADCMPMD1: Comparator operating mode control (2 units) */
#define PDL_ADC_12_CMP_AN00X_REFL_EXT			0x00004000u
#define PDL_ADC_12_CMP_AN00X_REFL_INT			0x00008000u

#define PDL_ADC_12_CMP_AN00X_REFH_EXT			0x00010000u
#define PDL_ADC_12_CMP_AN00X_REFH_INT			0x00020000u

#define PDL_ADC_12_CMP_AN10X_REFL_EXT			0x00040000u
#define PDL_ADC_12_CMP_AN10X_REFL_INT			0x00080000u

#define PDL_ADC_12_CMP_AN10X_REFH_EXT			0x00100000u
#define PDL_ADC_12_CMP_AN10X_REFH_INT			0x00200000u

#define PDL_ADC_12_CMP_AN00X_BEFORE_AMPLIFIER	0x00400000u
#define PDL_ADC_12_CMP_AN00X_AFTER_AMPLIFIER	0x00800000u

#define PDL_ADC_12_CMP_AN10X_BEFORE_AMPLIFIER	0x01000000u
#define PDL_ADC_12_CMP_AN10X_AFTER_AMPLIFIER	0x02000000u

/* ADCMPSEL: Comparator DTC trigger control (All) */
#define PDL_ADC_12_CMP_DTC_TRIGGER_DISABLE		0x04000000u
#define PDL_ADC_12_CMP_DTC_TRIGGER_ENABLE		0x08000000u

/* ADCMPSEL: POE request control (All) */
#define PDL_ADC_12_CMP_POE_REQUEST_DISABLE		0x10000000u
#define PDL_ADC_12_CMP_POE_REQUEST_ENABLE		0x20000000u



/* Options of chx0x_configuration for R_ADC_12_CreateChannelAll() */

/*  S12ADA0/1.ADANS, S12ADA0/1.ADPG: Programmable gain amplifier control (2 units * 3 channels) */
#define PDL_ADC_12_CH_GAIN_DISABLE				0x00000001u
#define PDL_ADC_12_CH_GAIN_2_000				0x00000002u
#define PDL_ADC_12_CH_GAIN_2_500				0x00000004u
#define PDL_ADC_12_CH_GAIN_3_077				0x00000008u
#define PDL_ADC_12_CH_GAIN_3_636				0x00000010u
#define PDL_ADC_12_CH_GAIN_4_000				0x00000020u
#define PDL_ADC_12_CH_GAIN_4_444  				0x00000040u
#define PDL_ADC_12_CH_GAIN_5_000				0x00000080u
#define PDL_ADC_12_CH_GAIN_5_714				0x00000100u
#define PDL_ADC_12_CH_GAIN_6_667				0x00000200u
#define PDL_ADC_12_CH_GAIN_10_000				0x00000400u
#define PDL_ADC_12_CH_GAIN_13_333				0x00000800u

/* ADCMPMD0: Comparator operating mode control (2 units * 3 channels) */
#define PDL_ADC_12_CH_CMP_DISABLE				0x00010000u
#define PDL_ADC_12_CH_CMP_LOW					0x00020000u
#define PDL_ADC_12_CH_CMP_HIGH					0x00040000u
#define PDL_ADC_12_CH_CMP_WINDOW				0x00080000u

/* ADCMPNR0/1: Comparator filter mode control (2 units * 3 channels) */
#define PDL_ADC_12_CH_CMP_SAMPLE_DISABLE		0x00100000u
#define PDL_ADC_12_CH_CMP_SAMPLE_PCLK_DIV_1		0x00200000u
#define PDL_ADC_12_CH_CMP_SAMPLE_PCLK_DIV_2		0x00400000u
#define PDL_ADC_12_CH_CMP_SAMPLE_PCLK_DIV_4		0x00800000u
#define PDL_ADC_12_CH_CMP_SAMPLE_PCLK_DIV_8		0x01000000u
#define PDL_ADC_12_CH_CMP_SAMPLE_PCLK_DIV_16	0x02000000u
#define PDL_ADC_12_CH_CMP_SAMPLE_PCLK_DIV_128	0x04000000u

/* ADCMPSEL: Comparator interrupt control (2 units * 3 channels) */
#define PDL_ADC_12_CH_CMP_INT_POE_DISABLE		0x08000000u
#define PDL_ADC_12_CH_CMP_INT_POE_ENABLE		0x10000000u




/* On / off control */
#define PDL_ADC_12_0_ON							0x01u
#define PDL_ADC_12_0_OFF						0x02u
#define PDL_ADC_12_1_ON							0x04u
#define PDL_ADC_12_1_OFF						0x08u

/* CPU control */
#define PDL_ADC_12_CPU_ON						0x10u
#define PDL_ADC_12_CPU_OFF						0x20u




/* Options for unit of of R_ADC_12_DestroyAll() */
#define PDL_ADC_12_0_DESTROY					0x01u
#define PDL_ADC_12_1_DESTROY					0x02u
#define PDL_ADC_12_CMP_000_DESTROY				0x04u
#define PDL_ADC_12_CMP_001_DESTROY				0x08u
#define PDL_ADC_12_CMP_002_DESTROY				0x10u
#define PDL_ADC_12_CMP_100_DESTROY				0x20u
#define PDL_ADC_12_CMP_101_DESTROY				0x40u
#define PDL_ADC_12_CMP_102_DESTROY				0x80u

#define PDL_ADC_12_CMP_ALL_DESTROY				(PDL_ADC_12_CMP_000_DESTROY | \
												PDL_ADC_12_CMP_001_DESTROY | \
												PDL_ADC_12_CMP_002_DESTROY | \
												PDL_ADC_12_CMP_100_DESTROY | \
												PDL_ADC_12_CMP_101_DESTROY | \
												PDL_ADC_12_CMP_102_DESTROY)


#endif
/* End of file */
