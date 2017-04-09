/*******************************************************************************
* File Name: MASK_OFF_CONTROL.h  
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

#if !defined(CY_PINS_MASK_OFF_CONTROL_H) /* Pins MASK_OFF_CONTROL_H */
#define CY_PINS_MASK_OFF_CONTROL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MASK_OFF_CONTROL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MASK_OFF_CONTROL__PORT == 15 && ((MASK_OFF_CONTROL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MASK_OFF_CONTROL_Write(uint8 value);
void    MASK_OFF_CONTROL_SetDriveMode(uint8 mode);
uint8   MASK_OFF_CONTROL_ReadDataReg(void);
uint8   MASK_OFF_CONTROL_Read(void);
void    MASK_OFF_CONTROL_SetInterruptMode(uint16 position, uint16 mode);
uint8   MASK_OFF_CONTROL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MASK_OFF_CONTROL_SetDriveMode() function.
     *  @{
     */
        #define MASK_OFF_CONTROL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MASK_OFF_CONTROL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MASK_OFF_CONTROL_DM_RES_UP          PIN_DM_RES_UP
        #define MASK_OFF_CONTROL_DM_RES_DWN         PIN_DM_RES_DWN
        #define MASK_OFF_CONTROL_DM_OD_LO           PIN_DM_OD_LO
        #define MASK_OFF_CONTROL_DM_OD_HI           PIN_DM_OD_HI
        #define MASK_OFF_CONTROL_DM_STRONG          PIN_DM_STRONG
        #define MASK_OFF_CONTROL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MASK_OFF_CONTROL_MASK               MASK_OFF_CONTROL__MASK
#define MASK_OFF_CONTROL_SHIFT              MASK_OFF_CONTROL__SHIFT
#define MASK_OFF_CONTROL_WIDTH              1u

/* Interrupt constants */
#if defined(MASK_OFF_CONTROL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MASK_OFF_CONTROL_SetInterruptMode() function.
     *  @{
     */
        #define MASK_OFF_CONTROL_INTR_NONE      (uint16)(0x0000u)
        #define MASK_OFF_CONTROL_INTR_RISING    (uint16)(0x0001u)
        #define MASK_OFF_CONTROL_INTR_FALLING   (uint16)(0x0002u)
        #define MASK_OFF_CONTROL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MASK_OFF_CONTROL_INTR_MASK      (0x01u) 
#endif /* (MASK_OFF_CONTROL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MASK_OFF_CONTROL_PS                     (* (reg8 *) MASK_OFF_CONTROL__PS)
/* Data Register */
#define MASK_OFF_CONTROL_DR                     (* (reg8 *) MASK_OFF_CONTROL__DR)
/* Port Number */
#define MASK_OFF_CONTROL_PRT_NUM                (* (reg8 *) MASK_OFF_CONTROL__PRT) 
/* Connect to Analog Globals */                                                  
#define MASK_OFF_CONTROL_AG                     (* (reg8 *) MASK_OFF_CONTROL__AG)                       
/* Analog MUX bux enable */
#define MASK_OFF_CONTROL_AMUX                   (* (reg8 *) MASK_OFF_CONTROL__AMUX) 
/* Bidirectional Enable */                                                        
#define MASK_OFF_CONTROL_BIE                    (* (reg8 *) MASK_OFF_CONTROL__BIE)
/* Bit-mask for Aliased Register Access */
#define MASK_OFF_CONTROL_BIT_MASK               (* (reg8 *) MASK_OFF_CONTROL__BIT_MASK)
/* Bypass Enable */
#define MASK_OFF_CONTROL_BYP                    (* (reg8 *) MASK_OFF_CONTROL__BYP)
/* Port wide control signals */                                                   
#define MASK_OFF_CONTROL_CTL                    (* (reg8 *) MASK_OFF_CONTROL__CTL)
/* Drive Modes */
#define MASK_OFF_CONTROL_DM0                    (* (reg8 *) MASK_OFF_CONTROL__DM0) 
#define MASK_OFF_CONTROL_DM1                    (* (reg8 *) MASK_OFF_CONTROL__DM1)
#define MASK_OFF_CONTROL_DM2                    (* (reg8 *) MASK_OFF_CONTROL__DM2) 
/* Input Buffer Disable Override */
#define MASK_OFF_CONTROL_INP_DIS                (* (reg8 *) MASK_OFF_CONTROL__INP_DIS)
/* LCD Common or Segment Drive */
#define MASK_OFF_CONTROL_LCD_COM_SEG            (* (reg8 *) MASK_OFF_CONTROL__LCD_COM_SEG)
/* Enable Segment LCD */
#define MASK_OFF_CONTROL_LCD_EN                 (* (reg8 *) MASK_OFF_CONTROL__LCD_EN)
/* Slew Rate Control */
#define MASK_OFF_CONTROL_SLW                    (* (reg8 *) MASK_OFF_CONTROL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MASK_OFF_CONTROL_PRTDSI__CAPS_SEL       (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MASK_OFF_CONTROL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MASK_OFF_CONTROL_PRTDSI__OE_SEL0        (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__OE_SEL0) 
#define MASK_OFF_CONTROL_PRTDSI__OE_SEL1        (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MASK_OFF_CONTROL_PRTDSI__OUT_SEL0       (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__OUT_SEL0) 
#define MASK_OFF_CONTROL_PRTDSI__OUT_SEL1       (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MASK_OFF_CONTROL_PRTDSI__SYNC_OUT       (* (reg8 *) MASK_OFF_CONTROL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MASK_OFF_CONTROL__SIO_CFG)
    #define MASK_OFF_CONTROL_SIO_HYST_EN        (* (reg8 *) MASK_OFF_CONTROL__SIO_HYST_EN)
    #define MASK_OFF_CONTROL_SIO_REG_HIFREQ     (* (reg8 *) MASK_OFF_CONTROL__SIO_REG_HIFREQ)
    #define MASK_OFF_CONTROL_SIO_CFG            (* (reg8 *) MASK_OFF_CONTROL__SIO_CFG)
    #define MASK_OFF_CONTROL_SIO_DIFF           (* (reg8 *) MASK_OFF_CONTROL__SIO_DIFF)
#endif /* (MASK_OFF_CONTROL__SIO_CFG) */

/* Interrupt Registers */
#if defined(MASK_OFF_CONTROL__INTSTAT)
    #define MASK_OFF_CONTROL_INTSTAT            (* (reg8 *) MASK_OFF_CONTROL__INTSTAT)
    #define MASK_OFF_CONTROL_SNAP               (* (reg8 *) MASK_OFF_CONTROL__SNAP)
    
	#define MASK_OFF_CONTROL_0_INTTYPE_REG 		(* (reg8 *) MASK_OFF_CONTROL__0__INTTYPE)
#endif /* (MASK_OFF_CONTROL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MASK_OFF_CONTROL_H */


/* [] END OF FILE */
