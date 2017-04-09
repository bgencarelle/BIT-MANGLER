/*******************************************************************************
* File Name: gjf.h  
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

#if !defined(CY_PINS_gjf_H) /* Pins gjf_H */
#define CY_PINS_gjf_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "gjf_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 gjf__PORT == 15 && ((gjf__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    gjf_Write(uint8 value);
void    gjf_SetDriveMode(uint8 mode);
uint8   gjf_ReadDataReg(void);
uint8   gjf_Read(void);
void    gjf_SetInterruptMode(uint16 position, uint16 mode);
uint8   gjf_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the gjf_SetDriveMode() function.
     *  @{
     */
        #define gjf_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define gjf_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define gjf_DM_RES_UP          PIN_DM_RES_UP
        #define gjf_DM_RES_DWN         PIN_DM_RES_DWN
        #define gjf_DM_OD_LO           PIN_DM_OD_LO
        #define gjf_DM_OD_HI           PIN_DM_OD_HI
        #define gjf_DM_STRONG          PIN_DM_STRONG
        #define gjf_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define gjf_MASK               gjf__MASK
#define gjf_SHIFT              gjf__SHIFT
#define gjf_WIDTH              1u

/* Interrupt constants */
#if defined(gjf__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in gjf_SetInterruptMode() function.
     *  @{
     */
        #define gjf_INTR_NONE      (uint16)(0x0000u)
        #define gjf_INTR_RISING    (uint16)(0x0001u)
        #define gjf_INTR_FALLING   (uint16)(0x0002u)
        #define gjf_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define gjf_INTR_MASK      (0x01u) 
#endif /* (gjf__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define gjf_PS                     (* (reg8 *) gjf__PS)
/* Data Register */
#define gjf_DR                     (* (reg8 *) gjf__DR)
/* Port Number */
#define gjf_PRT_NUM                (* (reg8 *) gjf__PRT) 
/* Connect to Analog Globals */                                                  
#define gjf_AG                     (* (reg8 *) gjf__AG)                       
/* Analog MUX bux enable */
#define gjf_AMUX                   (* (reg8 *) gjf__AMUX) 
/* Bidirectional Enable */                                                        
#define gjf_BIE                    (* (reg8 *) gjf__BIE)
/* Bit-mask for Aliased Register Access */
#define gjf_BIT_MASK               (* (reg8 *) gjf__BIT_MASK)
/* Bypass Enable */
#define gjf_BYP                    (* (reg8 *) gjf__BYP)
/* Port wide control signals */                                                   
#define gjf_CTL                    (* (reg8 *) gjf__CTL)
/* Drive Modes */
#define gjf_DM0                    (* (reg8 *) gjf__DM0) 
#define gjf_DM1                    (* (reg8 *) gjf__DM1)
#define gjf_DM2                    (* (reg8 *) gjf__DM2) 
/* Input Buffer Disable Override */
#define gjf_INP_DIS                (* (reg8 *) gjf__INP_DIS)
/* LCD Common or Segment Drive */
#define gjf_LCD_COM_SEG            (* (reg8 *) gjf__LCD_COM_SEG)
/* Enable Segment LCD */
#define gjf_LCD_EN                 (* (reg8 *) gjf__LCD_EN)
/* Slew Rate Control */
#define gjf_SLW                    (* (reg8 *) gjf__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define gjf_PRTDSI__CAPS_SEL       (* (reg8 *) gjf__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define gjf_PRTDSI__DBL_SYNC_IN    (* (reg8 *) gjf__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define gjf_PRTDSI__OE_SEL0        (* (reg8 *) gjf__PRTDSI__OE_SEL0) 
#define gjf_PRTDSI__OE_SEL1        (* (reg8 *) gjf__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define gjf_PRTDSI__OUT_SEL0       (* (reg8 *) gjf__PRTDSI__OUT_SEL0) 
#define gjf_PRTDSI__OUT_SEL1       (* (reg8 *) gjf__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define gjf_PRTDSI__SYNC_OUT       (* (reg8 *) gjf__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(gjf__SIO_CFG)
    #define gjf_SIO_HYST_EN        (* (reg8 *) gjf__SIO_HYST_EN)
    #define gjf_SIO_REG_HIFREQ     (* (reg8 *) gjf__SIO_REG_HIFREQ)
    #define gjf_SIO_CFG            (* (reg8 *) gjf__SIO_CFG)
    #define gjf_SIO_DIFF           (* (reg8 *) gjf__SIO_DIFF)
#endif /* (gjf__SIO_CFG) */

/* Interrupt Registers */
#if defined(gjf__INTSTAT)
    #define gjf_INTSTAT            (* (reg8 *) gjf__INTSTAT)
    #define gjf_SNAP               (* (reg8 *) gjf__SNAP)
    
	#define gjf_0_INTTYPE_REG 		(* (reg8 *) gjf__0__INTTYPE)
#endif /* (gjf__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_gjf_H */


/* [] END OF FILE */
