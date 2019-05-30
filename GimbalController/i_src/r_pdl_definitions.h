/*""FILE COMMENT""*******************************************************
* System Name	: PDL driver API
* File Name		: r_pdl_definitions.h
* Version		: 1.01
* Contents		: API headers for RX62TxFM
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

#ifndef R_PDL_DEFS_H
#define R_PDL_DEFS_H

#define PDL_VERSION	0x0101u	/* v01.01 in BCD format */
#define DEVICE_PACKAGE_LQFP_64

/* Peripiherals that are common to all device packages */
#include "r_pdl_adc_12_RX62Txx.h"
#include "r_pdl_bsc_RX62Txx.h"
#include "r_pdl_cgc_RX62Txx.h"
#include "r_pdl_cmt_RX62Txx.h"
#include "r_pdl_crc_RX62Txx.h"
#include "r_pdl_dtc_RX62Txx.h"
#include "r_pdl_gpt_RX62Txx.h"
#include "r_pdl_iic_RX62Txx.h"
#include "r_pdl_intc_RX62Txx.h"
#include "r_pdl_iwdt_RX62Txx.h"
#include "r_pdl_lin_RX62Txx.h"
#include "r_pdl_lpc_RX62Txx.h"
#include "r_pdl_lvd_RX62Txx.h"
#include "r_pdl_mcu_RX62Txx.h"
#include "r_pdl_mtu3_RX62Txx.h"
#include "r_pdl_pfc_RX62Txx.h"
#include "r_pdl_poe_RX62Txx.h"
#include "r_pdl_sci_RX62Txx.h"
#include "r_pdl_spi_RX62Txx.h"
#include "r_pdl_wdt_RX62Txx.h"

/* Peripiherals that are device package-dependent */
#include "r_pdl_io_port_RX62TxFM.h"

#endif
/* End of file */
