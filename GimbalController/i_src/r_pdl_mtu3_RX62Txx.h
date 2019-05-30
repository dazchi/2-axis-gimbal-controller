/*""FILE COMMENT""*******************************************************
* System Name	: Multi-function Timer Pulse Unit API for RX62T
* File Name		: r_pdl_mtu3_RX62Txx.h
* Version		: 1.01
* Contents		: MTU3 API header
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

#ifndef R_PDL_MTU3_RX62Txx_H
#define R_PDL_MTU3_RX62Txx_H

#define MTU3_UNITS 				1
#define MTU3_CHANNELS_PER_UNIT	8
#define MTU3_CHANNELS (uint8_t)(MTU3_UNITS * MTU3_CHANNELS_PER_UNIT)

/* Callback function storage */
extern VoidCallBackFunc rpdl_MTU3_func1_callback_func[MTU3_CHANNELS];
extern VoidCallBackFunc rpdl_MTU3_func2_callback_func[MTU3_CHANNELS];
extern VoidCallBackFunc rpdl_MTU3_func3_callback_func[MTU3_CHANNELS];
extern VoidCallBackFunc rpdl_MTU3_func4_callback_func[MTU3_CHANNELS];
extern VoidCallBackFunc rpdl_MTU3_TGRE_callback_func;
extern VoidCallBackFunc rpdl_MTU3_TGRF_callback_func;
extern VoidCallBackFunc rpdl_MTU3_Overflow_callback_func[MTU3_CHANNELS];
extern VoidCallBackFunc rpdl_MTU3_Underflow_callback_func[3];

typedef struct R_MTU3_Create_parameters
{
	uint32_t data2;
	uint32_t data3;
	uint32_t data4;
	uint32_t data5;
	uint32_t data6;
	uint32_t data7;
	uint32_t data8;
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
	VoidCallBackFunc func1;
	VoidCallBackFunc func2;
	VoidCallBackFunc func3;
	VoidCallBackFunc func4;
	uint8_t data20;
	VoidCallBackFunc func5;
	VoidCallBackFunc func6;
	VoidCallBackFunc func7;
	VoidCallBackFunc func8;
	uint8_t data21;
} R_MTU3_Create_structure;

typedef struct R_MTU3_ControlChannel_parameters
{
	uint8_t data2;
	uint16_t data3;
	uint16_t data4;
	uint16_t data5;
	uint16_t data6;
	uint16_t data7;
	uint16_t data8;
	uint16_t data9;
	uint16_t data10;
	uint16_t data11;
	uint16_t data12;
} R_MTU3_ControlChannel_structure;

typedef struct R_MTU3_ControlUnit_parameters
{
	uint16_t data2;
	uint16_t data3;
	uint32_t data4;
	uint32_t data5;
	uint32_t data6;
	uint32_t data7;
	uint16_t data8;
	uint16_t data9;
	uint16_t data10;
} R_MTU3_ControlUnit_structure;

/* Library prototypes */
bool R_MTU3_SetAll(
	const uint8_t
);
bool R_MTU3_CreateAll(
	const uint8_t,
	R_MTU3_Create_structure * const
);
bool R_MTU3_DestroyAll(
	void
);
bool R_MTU3_ControlChannelAll(
	const uint8_t,
	R_MTU3_ControlChannel_structure * const
);
bool R_MTU3_ControlUnitAll(
	const uint8_t,
	R_MTU3_ControlUnit_structure * const
);
bool R_MTU3_ReadChannelAll(
	const uint8_t,
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);
bool R_MTU3_ReadUnitAll(
	const uint8_t,
	volatile uint16_t * const,
	volatile uint8_t * const
);
bool ReturnFalse(void);
void R_MTU3_Create_load_defaults(R_MTU3_Create_structure * const);
void R_MTU3_ControlUnit_load_defaults(R_MTU3_ControlUnit_structure * const);

/* Macro definitions */

#define R_MTU3_Set(a) \
( \
R_MTU3_SetAll( (a) ) \
)

#define R_MTU3_Create(a, b) \
( \
( (a) < MTU3_CHANNELS ) ? \
R_MTU3_CreateAll( (a), (b) ) : \
ReturnFalse() \
)

#define R_MTU3_ControlChannel(a, b) \
( \
( (a) < MTU3_CHANNELS ) ? \
R_MTU3_ControlChannelAll( (a), (b) ) : \
ReturnFalse() \
)

#define R_MTU3_ControlUnit(a, b) \
( \
( (a) < MTU3_UNITS ) ? \
R_MTU3_ControlUnitAll( (a), (b) ) : \
ReturnFalse() \
)

#define R_MTU3_ReadChannel(a, b, c, d, e, f, g, h, i) \
( \
( (a) < MTU3_CHANNELS ) ? \
R_MTU3_ReadChannelAll( (a), (b), (c), (d), (e), (f), (g), (h), (i) ) : \
ReturnFalse() \
)

#define R_MTU3_ReadUnit(a, b, c, d) \
( \
( (a) < MTU3_UNITS ) ? \
R_MTU3_ReadUnitAll( (b), (c), (d) ) : \
ReturnFalse() \
)

#define R_MTU3_Destroy() \
( \
R_MTU3_DestroyAll( ) \
)

#endif
/* End of file */
