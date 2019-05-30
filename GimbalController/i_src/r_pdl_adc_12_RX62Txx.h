/*""FILE COMMENT""*******************************************************
* System Name	: 12-bit A/D converter API for RX62Txx
* File Name		: r_pdl_adc_12_RX62Txx.h
* Version		: 1.01
* Contents		: ADC_12 header
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

#ifndef R_PDL_ADC_12_RX62Txx_H
#define R_PDL_ADC_12_RX62Txx_H

extern VoidCallBackFunc rpdl_ADC_12_callback_func[];
extern VoidCallBackFunc rpdl_ADC_12_cmp_callback_func;

#define ADC_12_UNITS 2

/* Library prototypes */
bool R_ADC_12_SetAll(
	const uint8_t
);
bool R_ADC_12_CreateChannelAll(
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_ADC_12_CreateChannelCommon(
	const uint8_t,
	const uint8_t,
	const uint32_t
);
bool R_ADC_12_CreateUnitAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const float,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_ADC_12_CreateGroup(
	const uint8_t,
	const uint32_t
);
bool R_ADC_12_ControlAll(
	const uint8_t
);
bool R_ADC_12_ReadAll(
	const uint8_t,
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);
bool R_ADC_12_DestroyAll(
	const uint8_t
);
bool ReturnFalse(void);

/* Macro definitions */

#define R_ADC_12_Set(a) \
( \
	R_ADC_12_SetAll((a)) \
)

#define R_ADC_12_CreateChannel(a, b, c, d, e, f, g, h, i) \
( \
( ((i) <= IPL_MAX) ) ? \
R_ADC_12_CreateChannelAll( (a), (b), (c), (d), (e), (f), (g), (h), (i) ): \
ReturnFalse() \
)

#define R_ADC_12_CreateUnit(a, b, c, d, e, f, g, h ) \
( \
( ( ((a) < ADC_12_UNITS) && ((h) <= IPL_MAX) ) ) ? \
R_ADC_12_CreateUnitAll( (a), (b), (c), (d), (e), (f), (g), (h) ): \
ReturnFalse() \
)

#define R_ADC_12_Control(a) \
( \
( ((a) & 0x0Fu) != 0x00u ) ? \
R_ADC_12_ControlAll( (a) ): \
ReturnFalse() \
)

#define R_ADC_12_Read(a, b, c, d) \
( \
( (a) < ADC_12_UNITS ) ? \
R_ADC_12_ReadAll( (a), (b), (c), (d) ): \
ReturnFalse() \
)

#define R_ADC_12_Destroy(a) \
( \
R_ADC_12_DestroyAll((a)) \
)

#endif
/* End of file */
