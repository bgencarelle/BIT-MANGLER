/*******************************************************************************
* File Name: VREF_NEG_SAR1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_VREF_NEG_SAR1_H) /* Pins VREF_NEG_SAR1_H */
#define CY_PINS_VREF_NEG_SAR1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VREF_NEG_SAR1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VREF_NEG_SAR1__PORT == 15 && ((VREF_NEG_SAR1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VREF_NEG_SAR1_Write(uint8 value);
void    VREF_NEG_SAR1_SetDriveMode(uint8 mode);
uint8   VREF_NEG_SAR1_ReadDataReg(void);
uint8   VREF_NEG_SAR1_Read(void);
void    VREF_NEG_SAR1_SetInterruptMode(uint16 position, uint16 mode);
uint8   VREF_NEG_SAR1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VREF_NEG_SAR1_SetDriveMode() function.
     *  @{
     */
        #define VREF_NEG_SAR1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VREF_NEG_SAR1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VREF_NEG_SAR1_DM_RES_UP          PIN_DM_RES_UP
        #define VREF_NEG_SAR1_DM_RES_DWN         PIN_DM_RES_DWN
        #define VREF_NEG_SAR1_DM_OD_LO           PIN_DM_OD_LO
        #define VREF_NEG_SAR1_DM_OD_HI           PIN_DM_OD_HI
        #define VREF_NEG_SAR1_DM_STRONG          PIN_DM_STRONG
        #define VREF_NEG_SAR1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VREF_NEG_SAR1_MASK               VREF_NEG_SAR1__MASK
#define VREF_NEG_SAR1_SHIFT              VREF_NEG_SAR1__SHIFT
#define VREF_NEG_SAR1_WIDTH              1u

/* Interrupt constants */
#if defined(VREF_NEG_SAR1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VREF_NEG_SAR1_SetInterruptMode() function.
     *  @{
     */
        #define VREF_NEG_SAR1_INTR_NONE      (uint16)(0x0000u)
        #define VREF_NEG_SAR1_INTR_RISING    (uint16)(0x0001u)
        #define VREF_NEG_SAR1_INTR_FALLING   (uint16)(0x0002u)
        #define VREF_NEG_SAR1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VREF_NEG_SAR1_INTR_MASK      (0x01u) 
#endif /* (VREF_NEG_SAR1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VREF_NEG_SAR1_PS                     (* (reg8 *) VREF_NEG_SAR1__PS)
/* Data Register */
#define VREF_NEG_SAR1_DR                     (* (reg8 *) VREF_NEG_SAR1__DR)
/* Port Number */
#define VREF_NEG_SAR1_PRT_NUM                (* (reg8 *) VREF_NEG_SAR1__PRT) 
/* Connect to Analog Globals */                                                  
#define VREF_NEG_SAR1_AG                     (* (reg8 *) VREF_NEG_SAR1__AG)                       
/* Analog MUX bux enable */
#define VREF_NEG_SAR1_AMUX                   (* (reg8 *) VREF_NEG_SAR1__AMUX) 
/* Bidirectional Enable */                                                        
#define VREF_NEG_SAR1_BIE                    (* (reg8 *) VREF_NEG_SAR1__BIE)
/* Bit-mask for Aliased Register Access */
#define VREF_NEG_SAR1_BIT_MASK               (* (reg8 *) VREF_NEG_SAR1__BIT_MASK)
/* Bypass Enable */
#define VREF_NEG_SAR1_BYP                    (* (reg8 *) VREF_NEG_SAR1__BYP)
/* Port wide control signals */                                                   
#define VREF_NEG_SAR1_CTL                    (* (reg8 *) VREF_NEG_SAR1__CTL)
/* Drive Modes */
#define VREF_NEG_SAR1_DM0                    (* (reg8 *) VREF_NEG_SAR1__DM0) 
#define VREF_NEG_SAR1_DM1                    (* (reg8 *) VREF_NEG_SAR1__DM1)
#define VREF_NEG_SAR1_DM2                    (* (reg8 *) VREF_NEG_SAR1__DM2) 
/* Input Buffer Disable Override */
#define VREF_NEG_SAR1_INP_DIS                (* (reg8 *) VREF_NEG_SAR1__INP_DIS)
/* LCD Common or Segment Drive */
#define VREF_NEG_SAR1_LCD_COM_SEG            (* (reg8 *) VREF_NEG_SAR1__LCD_COM_SEG)
/* Enable Segment LCD */
#define VREF_NEG_SAR1_LCD_EN                 (* (reg8 *) VREF_NEG_SAR1__LCD_EN)
/* Slew Rate Control */
#define VREF_NEG_SAR1_SLW                    (* (reg8 *) VREF_NEG_SAR1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VREF_NEG_SAR1_PRTDSI__CAPS_SEL       (* (reg8 *) VREF_NEG_SAR1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VREF_NEG_SAR1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VREF_NEG_SAR1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VREF_NEG_SAR1_PRTDSI__OE_SEL0        (* (reg8 *) VREF_NEG_SAR1__PRTDSI__OE_SEL0) 
#define VREF_NEG_SAR1_PRTDSI__OE_SEL1        (* (reg8 *) VREF_NEG_SAR1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VREF_NEG_SAR1_PRTDSI__OUT_SEL0       (* (reg8 *) VREF_NEG_SAR1__PRTDSI__OUT_SEL0) 
#define VREF_NEG_SAR1_PRTDSI__OUT_SEL1       (* (reg8 *) VREF_NEG_SAR1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VREF_NEG_SAR1_PRTDSI__SYNC_OUT       (* (reg8 *) VREF_NEG_SAR1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VREF_NEG_SAR1__SIO_CFG)
    #define VREF_NEG_SAR1_SIO_HYST_EN        (* (reg8 *) VREF_NEG_SAR1__SIO_HYST_EN)
    #define VREF_NEG_SAR1_SIO_REG_HIFREQ     (* (reg8 *) VREF_NEG_SAR1__SIO_REG_HIFREQ)
    #define VREF_NEG_SAR1_SIO_CFG            (* (reg8 *) VREF_NEG_SAR1__SIO_CFG)
    #define VREF_NEG_SAR1_SIO_DIFF           (* (reg8 *) VREF_NEG_SAR1__SIO_DIFF)
#endif /* (VREF_NEG_SAR1__SIO_CFG) */

/* Interrupt Registers */
#if defined(VREF_NEG_SAR1__INTSTAT)
    #define VREF_NEG_SAR1_INTSTAT            (* (reg8 *) VREF_NEG_SAR1__INTSTAT)
    #define VREF_NEG_SAR1_SNAP               (* (reg8 *) VREF_NEG_SAR1__SNAP)
    
	#define VREF_NEG_SAR1_0_INTTYPE_REG 		(* (reg8 *) VREF_NEG_SAR1__0__INTTYPE)
#endif /* (VREF_NEG_SAR1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VREF_NEG_SAR1_H */


/* [] END OF FILE */
