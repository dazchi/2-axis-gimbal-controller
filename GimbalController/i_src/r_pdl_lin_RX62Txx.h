/*""FILE COMMENT""*******************************************************
* System Name	: LIN module API for RX62Txx
* File Name		: r_pdl_lin_RX62Txx.h
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

#ifndef R_PDL_LIN_RX62Txx_H
#define R_PDL_LIN_RX62Txx_H

#define LIN_CHANNELS 1

/* Callback function prototype */
extern VoidCallBackFunc rpdl_LIN_callback_func;

bool R_LIN_CreateAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	VoidCallBackFunc const,
	const uint8_t
);
bool R_LIN_DestroyAll(
	void
);
bool R_LIN_TransferAll(
	const uint8_t,
	const uint8_t,
	volatile const uint8_t * const,
	const uint8_t
);
bool R_LIN_ReadAll(
	volatile uint8_t * const,
	const uint8_t
);
bool R_LIN_ControlAll(
	const uint8_t,
	const uint8_t
);
bool R_LIN_GetStatusAll(
	volatile uint16_t * const,
	volatile uint8_t * const
);
bool ReturnFalse(void);

/* Macro definitions */
#define R_LIN_Create(a, b, c, d, e, f, g) \
( \
( ( ((a) == 0) && ((g) <= IPL_MAX) ) ) ? \
R_LIN_CreateAll((b), (c), (d), (e), (f), (g) ): \
ReturnFalse() \
)

#define R_LIN_Destroy(a) \
( \
( ((a) == 0) ) ? \
R_LIN_DestroyAll( ): \
ReturnFalse() \
)

#define R_LIN_Transfer(a, b, c, d, e) \
( \
( ( ((a) == 0) && ((e) <= 8) ) ) ? \
R_LIN_TransferAll( (b), (c), (d), (e) ): \
ReturnFalse() \
)

#define R_LIN_Read(a, b, c) \
( \
( ( ((a) == 0) && ((c) > 0) && ((c) <= 8) ) ) ? \
R_LIN_ReadAll( (b), (c) ): \
ReturnFalse() \
)

#define R_LIN_Control(a, b, c) \
( \
( ((a) == 0) ) ? \
R_LIN_ControlAll( (b), (c) ): \
ReturnFalse() \
)

#define R_LIN_GetStatus(a, b, c) \
( \
( ((a) == 0) ) ? \
R_LIN_GetStatusAll( (b), (c) ): \
ReturnFalse() \
)

#endif
/* End of file */
