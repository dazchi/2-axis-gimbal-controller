/*""FILE COMMENT""*******************************************************
* System Name	: General PWM Timer unit API for RX62T
* File Name		: r_pdl_gpt_RX62Txx.h
* Version		: 1.01
* Contents		: GPT API header
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

#ifndef R_PDL_GPT_RX62Txx_H
#define R_PDL_GPT_RX62Txx_H

#define GPT_CHANNELS 4

/* Callback function storage */
extern VoidCallBackFunc rpdl_GPT_GTCIA_callback_func[GPT_CHANNELS];
extern VoidCallBackFunc rpdl_GPT_GTCIB_callback_func[GPT_CHANNELS];
extern VoidCallBackFunc rpdl_GPT_GTCIC_callback_func[GPT_CHANNELS];
extern VoidCallBackFunc rpdl_GPT_GTCIE_callback_func[GPT_CHANNELS];
extern VoidCallBackFunc rpdl_GPT_GTCIV_callback_func[GPT_CHANNELS];
extern VoidCallBackFunc rpdl_GPT_LOCO_callback_func;

/* Structure prototypes */
typedef struct R_GPT_Create_parameters
{
	uint16_t data2;
	uint32_t data3;
	uint32_t data4;
	uint32_t data5;
	uint32_t data6;
	uint32_t data7;
	uint32_t data8;
	uint32_t data9;
	uint32_t data10;
	VoidCallBackFunc func1;
	VoidCallBackFunc func2;
	VoidCallBackFunc func3;
	uint8_t data11;
	VoidCallBackFunc func4;
	VoidCallBackFunc func5;
	VoidCallBackFunc func6;
	uint8_t data12;
} R_GPT_Create_structure;

typedef struct R_GPT_ControlChannel_parameters
{
	uint16_t data4;
	uint16_t data5;
	uint16_t data6;
	uint16_t data7;
	uint16_t data8;
	uint16_t data9;
	uint16_t data10;
	uint16_t data11;
	uint16_t data12;
	uint16_t data13;
	uint16_t data14;
	uint16_t data15;
	uint16_t data16;
	uint16_t data17;
	uint16_t data18;
	uint16_t data19;
	uint16_t data20;
	uint16_t data21;
	uint16_t data22;
	uint16_t data23;
} R_GPT_ControlChannel_structure;

/* Library prototypes */
bool R_GPT_SetAll(
	const uint32_t
);

bool R_GPT_CreateAll(
	const uint8_t,
	R_GPT_Create_structure * const
);

bool R_GPT_DestroyAll(
	void
);

bool R_GPT_ControlChannelAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	R_GPT_ControlChannel_structure * const
);

bool R_GPT_ControlUnitAll(
	const uint32_t,
	const uint16_t,
	const uint16_t
);

bool R_GPT_ReadChannelAll(
	const uint8_t,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);

bool R_GPT_ReadUnitAll(
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);

bool ReturnFalse(void);
void R_GPT_Create_load_defaults(R_GPT_Create_structure * const);

/* Macro definitions */

#define R_GPT_Set(a) \
( \
R_GPT_SetAll( (a) ) \
)

#define R_GPT_Create(a, b) \
( \
( ((a) < GPT_CHANNELS) ) ? \
R_GPT_CreateAll((a), (b)) : \
ReturnFalse() \
)

#define R_GPT_Destroy(a) \
( \
( (a) == 0 ) ? \
R_GPT_DestroyAll() : \
ReturnFalse() \
)

#define R_GPT_ControlChannel(a, b, c, d) \
( \
( ((a) < GPT_CHANNELS) ) ? \
R_GPT_ControlChannelAll((a), (b), (c), (d)) : \
ReturnFalse() \
)

#define R_GPT_ControlUnit(a, b, c, d) \
( \
( (a) == 0 ) ? \
R_GPT_ControlUnitAll((b), (c), (d)) : \
ReturnFalse() \
)

#define R_GPT_ReadChannel(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v) \
( \
( ((a) < GPT_CHANNELS) ) ? \
R_GPT_ReadChannelAll((a), (b), (c), (d), (e), (f), (g), (h), (i), (j), (k), (l), (m), (n), (o), (p), (q), (r), (s), (t), (u), (v)) : \
ReturnFalse() \
)

#define R_GPT_ReadUnit(a, b, c, d, e, f, g) \
( \
( (a) == 0 ) ? \
R_GPT_ReadUnitAll((b), (c), (d), (e), (f), (g)) : \
ReturnFalse() \
)

#endif
/* End of file */
