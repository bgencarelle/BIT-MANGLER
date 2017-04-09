/*******************************************************************************
* File Name: MUX_BUS.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_MUX_BUS_ALIASES_H) /* Pins MUX_BUS_ALIASES_H */
#define CY_PINS_MUX_BUS_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define MUX_BUS_0			(MUX_BUS__0__PC)
#define MUX_BUS_0_INTR	((uint16)((uint16)0x0001u << MUX_BUS__0__SHIFT))

#define MUX_BUS_1			(MUX_BUS__1__PC)
#define MUX_BUS_1_INTR	((uint16)((uint16)0x0001u << MUX_BUS__1__SHIFT))

#define MUX_BUS_2			(MUX_BUS__2__PC)
#define MUX_BUS_2_INTR	((uint16)((uint16)0x0001u << MUX_BUS__2__SHIFT))

#define MUX_BUS_3			(MUX_BUS__3__PC)
#define MUX_BUS_3_INTR	((uint16)((uint16)0x0001u << MUX_BUS__3__SHIFT))

#define MUX_BUS_4			(MUX_BUS__4__PC)
#define MUX_BUS_4_INTR	((uint16)((uint16)0x0001u << MUX_BUS__4__SHIFT))

#define MUX_BUS_5			(MUX_BUS__5__PC)
#define MUX_BUS_5_INTR	((uint16)((uint16)0x0001u << MUX_BUS__5__SHIFT))

#define MUX_BUS_6			(MUX_BUS__6__PC)
#define MUX_BUS_6_INTR	((uint16)((uint16)0x0001u << MUX_BUS__6__SHIFT))

#define MUX_BUS_7			(MUX_BUS__7__PC)
#define MUX_BUS_7_INTR	((uint16)((uint16)0x0001u << MUX_BUS__7__SHIFT))

#define MUX_BUS_8			(MUX_BUS__8__PC)
#define MUX_BUS_8_INTR	((uint16)((uint16)0x0001u << MUX_BUS__8__SHIFT))

#define MUX_BUS_9			(MUX_BUS__9__PC)
#define MUX_BUS_9_INTR	((uint16)((uint16)0x0001u << MUX_BUS__9__SHIFT))

#define MUX_BUS_10			(MUX_BUS__10__PC)
#define MUX_BUS_10_INTR	((uint16)((uint16)0x0001u << MUX_BUS__10__SHIFT))

#define MUX_BUS_11			(MUX_BUS__11__PC)
#define MUX_BUS_11_INTR	((uint16)((uint16)0x0001u << MUX_BUS__11__SHIFT))

#define MUX_BUS_INTR_ALL	 ((uint16)(MUX_BUS_0_INTR| MUX_BUS_1_INTR| MUX_BUS_2_INTR| MUX_BUS_3_INTR| MUX_BUS_4_INTR| MUX_BUS_5_INTR| MUX_BUS_6_INTR| MUX_BUS_7_INTR| MUX_BUS_8_INTR| MUX_BUS_9_INTR| MUX_BUS_10_INTR| MUX_BUS_11_INTR))

#endif /* End Pins MUX_BUS_ALIASES_H */


/* [] END OF FILE */
