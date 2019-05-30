/*""FILE COMMENT""*******************************************************
* System Name	: Interrupt program for RX62Txx
* File Name		: Interrupt_SCI.c
* Version		: 1.01
* Contents		: Interrupt handlers for all SCI channels
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

#include "r_pdl_sci.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn receive data error interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCI0_ERIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: SSR for that SCI channel
*-------------------------------------------------------------------
* Use function	: rpdl_SCI_RX_Error_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_ERI0
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0, fint)
#else
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0)
#endif
void Interrupt_SCI0_ERI0(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_RX_Error_callback_func[0] != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_RX_Error_callback_func[0]();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI0.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI0.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_ERI1
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1, fint)
#else
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1)
#endif
void Interrupt_SCI1_ERI1(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_RX_Error_callback_func[1] != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_RX_Error_callback_func[1]();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI1.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI1.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_ERI2
#pragma interrupt Interrupt_SCI2_ERI2(vect=VECT_SCI2_ERI2, fint)
#else
#pragma interrupt Interrupt_SCI2_ERI2(vect=VECT_SCI2_ERI2)
#endif
void Interrupt_SCI2_ERI2(void)
{
	/* Will the user handle the errors? */
	if (rpdl_SCI_RX_Error_callback_func[2] != PDL_NO_FUNC)
	{
		/* Call the error handler */
		rpdl_SCI_RX_Error_callback_func[2]();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI2.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI2.SSR.BYTE & (uint8_t)BIT_0));
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn receive data interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_RXIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: 
*-------------------------------------------------------------------
* Use function	: rpdl_SCI_RX_End_callback_func
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_RXI0
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0)
#endif
void Interrupt_SCI0_RXI0(void)
{
	/* Ok to process the data? */
	if (rpdl_SCI_rx_using_irq[0] == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_MP_mode[0] == 2)
		{
			/* check if ID cycle ? */
			if (SCI0.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI0.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_MP_rx_stationID[0])
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI0.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);

					/* Notify the user */
					if (rpdl_SCI_RX_End_callback_func[0] != PDL_NO_FUNC)
					{
						rpdl_SCI_RX_End_callback_func[0]();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*rpdl_SCI_rx_string_pointer[0] = SCI0.RDR;

		/* Increment the character counter */
		rpdl_SCI_rx_counter[0]++;

		/* More characters expected? */
		if (rpdl_SCI_rx_counter[0] < rpdl_SCI_rx_threshold[0])
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_rx_string_pointer[0]++;
		}
		else
		{
			/* Disable interrupt request generation, and try to disable reception */
			SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);

			/* Async MP mode ? */
			if (((SCI0.SMR.BIT.MP) != 0) && ((rpdl_SCI_MP_mode[0]) != 0))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI0.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_RX_End_callback_func[0] != PDL_NO_FUNC)
			{
				rpdl_SCI_RX_End_callback_func[0]();
			}
		}
	}
	/* The DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_RX_End_callback_func[0] != PDL_NO_FUNC)
		{
			rpdl_SCI_RX_End_callback_func[0]();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_RXI1
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1, fint)
#else
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1)
#endif
void Interrupt_SCI1_RXI1(void)
{
	/* Ok to process the data? */
	if (rpdl_SCI_rx_using_irq[1] == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_MP_mode[1] == 2)
		{
			/* check if ID cycle ? */
			if (SCI1.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI1.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_MP_rx_stationID[1])
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI1.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);

					/* Notify the user */
					if (rpdl_SCI_RX_End_callback_func[1] != PDL_NO_FUNC)
					{
						rpdl_SCI_RX_End_callback_func[1]();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*rpdl_SCI_rx_string_pointer[1] = SCI1.RDR;

		/* Increment the character counter */
		rpdl_SCI_rx_counter[1]++;

		/* More characters expected? */
		if (rpdl_SCI_rx_counter[1] < rpdl_SCI_rx_threshold[1])
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_rx_string_pointer[1]++;
		}
		else
		{
			/* Disable interrupt request generation, and try to disable reception */
			SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);

			/* Async MP mode ? */
			if (((SCI1.SMR.BIT.MP) != 0) && ((rpdl_SCI_MP_mode[1]) != 0))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI1.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_RX_End_callback_func[1] != PDL_NO_FUNC)
			{
				rpdl_SCI_RX_End_callback_func[1]();
			}
		}
	}
	/* The DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_RX_End_callback_func[1] != PDL_NO_FUNC)
		{
			rpdl_SCI_RX_End_callback_func[1]();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_RXI2
#pragma interrupt Interrupt_SCI2_RXI2(vect=VECT_SCI2_RXI2, fint)
#else
#pragma interrupt Interrupt_SCI2_RXI2(vect=VECT_SCI2_RXI2)
#endif
void Interrupt_SCI2_RXI2(void)
{
	/* Ok to process the data? */
	if (rpdl_SCI_rx_using_irq[2] == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (rpdl_SCI_MP_mode[2] == 2)
		{
			/* check if ID cycle ? */
			if (SCI2.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI2.RDR;

				/* ID matching ? */
				if (id != rpdl_SCI_MP_rx_stationID[2])
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI2.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);

					/* Notify the user */
					if (rpdl_SCI_RX_End_callback_func[2] != PDL_NO_FUNC)
					{
						rpdl_SCI_RX_End_callback_func[2]();
					}					
				}	

				/* Exit ISR */
				return;	
			}
		}

		
		/* Read and store the character */
		*rpdl_SCI_rx_string_pointer[2] = SCI2.RDR;

		/* Increment the character counter */
		rpdl_SCI_rx_counter[2]++;

		/* More characters expected? */
		if (rpdl_SCI_rx_counter[2] < rpdl_SCI_rx_threshold[2])
		{
			/* Move to the next location in the buffer */
			rpdl_SCI_rx_string_pointer[2]++;
		}
		else
		{
			/* Disable interrupt request generation, and try to disable reception */
			SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);

			/* Async MP mode ? */
			if (((SCI2.SMR.BIT.MP) != 0) && ((rpdl_SCI_MP_mode[2]) != 0))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI2.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (rpdl_SCI_RX_End_callback_func[2] != PDL_NO_FUNC)
			{
				rpdl_SCI_RX_End_callback_func[2]();
			}
		}
	}
	/* The DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_RX_End_callback_func[2] != PDL_NO_FUNC)
		{
			rpdl_SCI_RX_End_callback_func[2]();
		}
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn transmit data interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_TXIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: TDR for that SCI channel
*-------------------------------------------------------------------
* Use function	: 
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_TXI0
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0)
#endif

void Interrupt_SCI0_TXI0(void)
{
	/* Ok to process the string? */
	if (rpdl_SCI_tx_using_irq[0] == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_tx_threshold[0] == 0) && (*rpdl_SCI_tx_string_pointer[0] != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_tx_counter[0] < rpdl_SCI_tx_threshold[0])
		)
		{
			/* Send the character */
			SCI0.TDR = *rpdl_SCI_tx_string_pointer[0];

			/* Increment the pointer */
			rpdl_SCI_tx_string_pointer[0]++;

			/* Increment the counter */
			rpdl_SCI_tx_counter[0]++;
		}
		else
		{
			/* Disable interrupt request generation */
			SCI0.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI0.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_TX_End_callback_func[0] != PDL_NO_FUNC)
				{
					rpdl_SCI_TX_End_callback_func[0]();
				}
			}
		}
	}
	/* The DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_TX_End_callback_func[0] != PDL_NO_FUNC)
		{
			rpdl_SCI_TX_End_callback_func[0]();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_TXI1
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1, fint)
#else
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1)
#endif
void Interrupt_SCI1_TXI1(void)
{
	/* Ok to process the string? */
	if (rpdl_SCI_tx_using_irq[1] == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_tx_threshold[1] == 0) && (*rpdl_SCI_tx_string_pointer[1] != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_tx_counter[1] < rpdl_SCI_tx_threshold[1])
		)
		{
			/* Send the character */
			SCI1.TDR = *rpdl_SCI_tx_string_pointer[1];

			/* Increment the pointer */
			rpdl_SCI_tx_string_pointer[1]++;

			/* Increment the counter */
			rpdl_SCI_tx_counter[1]++;
		}
		else
		{
			/* Disable interrupt request generation */
			SCI1.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI1.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_TX_End_callback_func[1] != PDL_NO_FUNC)
				{
					rpdl_SCI_TX_End_callback_func[1]();
				}
			}
		}
	}
	/* The DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_TX_End_callback_func[1] != PDL_NO_FUNC)
		{
			rpdl_SCI_TX_End_callback_func[1]();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_TXI2
#pragma interrupt Interrupt_SCI2_TXI2(vect=VECT_SCI2_TXI2, fint)
#else
#pragma interrupt Interrupt_SCI2_TXI2(vect=VECT_SCI2_TXI2)
#endif
void Interrupt_SCI2_TXI2(void)
{
	/* Ok to process the string? */
	if (rpdl_SCI_tx_using_irq[2] == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((rpdl_SCI_tx_threshold[2] == 0) && (*rpdl_SCI_tx_string_pointer[2] != NULL))
		||
		/* Not reached the byte total? */
		(rpdl_SCI_tx_counter[2] < rpdl_SCI_tx_threshold[2])
		)
		{
			/* Send the character */
			SCI2.TDR = *rpdl_SCI_tx_string_pointer[2];

			/* Increment the pointer */
			rpdl_SCI_tx_string_pointer[2]++;

			/* Increment the counter */
			rpdl_SCI_tx_counter[2]++;
		}
		else
		{
			/* Disable interrupt request generation */
			SCI2.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI2.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (rpdl_SCI_TX_End_callback_func[2] != PDL_NO_FUNC)
				{
					rpdl_SCI_TX_End_callback_func[2]();
				}
			}
		}
	}
	/* The DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (rpdl_SCI_TX_End_callback_func[2] != PDL_NO_FUNC)
		{
			rpdl_SCI_TX_End_callback_func[2]();
		}
	}
}

/*""FUNC COMMENT""***************************************************
* Module outline: SCIn transmit end interrupt processing
*-------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_TEIn(void)
*-------------------------------------------------------------------
* Function		: 
*-------------------------------------------------------------------
* Argument		: Nothing
*-------------------------------------------------------------------
* Return value	: Nothing
*-------------------------------------------------------------------
* Output		: SCR for that channel
*-------------------------------------------------------------------
* Use function	: rpdl_SCI_TX_End_callback_func()
*-------------------------------------------------------------------
* Notes			: 
*-------------------------------------------------------------------
* History		: 2011.05.04
*				: Ver 1.01
*				: Release CS3.
*""FUNC COMMENT END""**********************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_TEI0
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0)
#endif
void Interrupt_SCI0_TEI0(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);

	/* Call the callback function */
	if (rpdl_SCI_TX_End_callback_func[0] != PDL_NO_FUNC)
	{
		rpdl_SCI_TX_End_callback_func[0]();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_TEI1
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1, fint)
#else
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1)
#endif
void Interrupt_SCI1_TEI1(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);

	/* Call the callback function */
	if (rpdl_SCI_TX_End_callback_func[1] != PDL_NO_FUNC)
	{
		rpdl_SCI_TX_End_callback_func[1]();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_TEI2
#pragma interrupt Interrupt_SCI2_TEI2(vect=VECT_SCI2_TEI2, fint)
#else
#pragma interrupt Interrupt_SCI2_TEI2(vect=VECT_SCI2_TEI2)
#endif
void Interrupt_SCI2_TEI2(void)
{
	/* Disable interrupt request generation, and try to disable transmission */
	SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);

	/* Call the callback function */
	if (rpdl_SCI_TX_End_callback_func[2] != PDL_NO_FUNC)
	{
		rpdl_SCI_TX_End_callback_func[2]();
	}
}

/* End of file */
