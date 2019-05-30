/*""FILE COMMENT""*******************************************************
* System Name	: A/D converter API for RX62Tx(not FM)
* File Name		: r_pdl_adc_10_RX62TxnFM.h
* Version		: 1.01
* Contents		: ADC header
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

#ifndef R_PDL_ADC_10_RX62Txx_H
#define R_PDL_ADC_10_RX62Txx_H

#define ADC_10_UNITS 1

extern VoidCallBackFunc rpdl_ADC_10_callback_func[];

/* Library prototypes */
bool R_ADC_10_CreateAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const float,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_ADC_10_DestroyAll(
	const uint8_t
);
bool R_ADC_10_ControlAll(
	const uint8_t
);
bool R_ADC_10_ReadAll(
	const uint8_t,
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_ADC_10_Create(a, b, c, d, e, f, g) \
( \
( ( ((a) < ADC_10_UNITS) && ((g) <= IPL_MAX) ) ) ? \
R_ADC_10_CreateAll( (a), (b), (c), (d), (e), (f), (g)): \
ReturnFalse() \
)

#define R_ADC_10_Destroy(a) \
( \
( (a) < ADC_10_UNITS ) ? \
R_ADC_10_DestroyAll( (a) ): \
ReturnFalse() \
)

#define R_ADC_10_Control(a) \
( \
R_ADC_10_ControlAll( (a) ) \
)

#define R_ADC_10_Read(a, b) \
( \
( (a) < ADC_10_UNITS ) ? \
R_ADC_10_ReadAll( (a), (b) ): \
ReturnFalse() \
)

#endif
/* End of file */
