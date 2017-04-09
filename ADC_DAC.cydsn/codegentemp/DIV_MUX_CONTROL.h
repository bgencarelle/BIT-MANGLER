/*******************************************************************************
* File Name: DIV_MUX_CONTROL.h  
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

#if !defined(CY_PINS_DIV_MUX_CONTROL_H) /* Pins DIV_MUX_CONTROL_H */
#define CY_PINS_DIV_MUX_CONTROL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DIV_MUX_CONTROL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DIV_MUX_CONTROL__PORT == 15 && ((DIV_MUX_CONTROL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DIV_MUX_CONTROL_Write(uint8 value);
void    DIV_MUX_CONTROL_SetDriveMode(uint8 mode);
uint8   DIV_MUX_CONTROL_ReadDataReg(void);
uint8   DIV_MUX_CONTROL_Read(void);
void    DIV_MUX_CONTROL_SetInterruptMode(uint16 position, uint16 mode);
uint8   DIV_MUX_CONTROL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DIV_MUX_CONTROL_SetDriveMode() function.
     *  @{
     */
        #define DIV_MUX_CONTROL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DIV_MUX_CONTROL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DIV_MUX_CONTROL_DM_RES_UP          PIN_DM_RES_UP
        #define DIV_MUX_CONTROL_DM_RES_DWN         PIN_DM_RES_DWN
        #define DIV_MUX_CONTROL_DM_OD_LO           PIN_DM_OD_LO
        #define DIV_MUX_CONTROL_DM_OD_HI           PIN_DM_OD_HI
        #define DIV_MUX_CONTROL_DM_STRONG          PIN_DM_STRONG
        #define DIV_MUX_CONTROL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DIV_MUX_CONTROL_MASK               DIV_MUX_CONTROL__MASK
#define DIV_MUX_CONTROL_SHIFT              DIV_MUX_CONTROL__SHIFT
#define DIV_MUX_CONTROL_WIDTH              1u

/* Interrupt constants */
#if defined(DIV_MUX_CONTROL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DIV_MUX_CONTROL_SetInterruptMode() function.
     *  @{
     */
        #define DIV_MUX_CONTROL_INTR_NONE      (uint16)(0x0000u)
        #define DIV_MUX_CONTROL_INTR_RISING    (uint16)(0x0001u)
        #define DIV_MUX_CONTROL_INTR_FALLING   (uint16)(0x0002u)
        #define DIV_MUX_CONTROL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DIV_MUX_CONTROL_INTR_MASK      (0x01u) 
#endif /* (DIV_MUX_CONTROL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DIV_MUX_CONTROL_PS                     (* (reg8 *) DIV_MUX_CONTROL__PS)
/* Data Register */
#define DIV_MUX_CONTROL_DR                     (* (reg8 *) DIV_MUX_CONTROL__DR)
/* Port Number */
#define DIV_MUX_CONTROL_PRT_NUM                (* (reg8 *) DIV_MUX_CONTROL__PRT) 
/* Connect to Analog Globals */                                                  
#define DIV_MUX_CONTROL_AG                     (* (reg8 *) DIV_MUX_CONTROL__AG)                       
/* Analog MUX bux enable */
#define DIV_MUX_CONTROL_AMUX                   (* (reg8 *) DIV_MUX_CONTROL__AMUX) 
/* Bidirectional Enable */                                                        
#define DIV_MUX_CONTROL_BIE                    (* (reg8 *) DIV_MUX_CONTROL__BIE)
/* Bit-mask for Aliased Register Access */
#define DIV_MUX_CONTROL_BIT_MASK               (* (reg8 *) DIV_MUX_CONTROL__BIT_MASK)
/* Bypass Enable */
#define DIV_MUX_CONTROL_BYP                    (* (reg8 *) DIV_MUX_CONTROL__BYP)
/* Port wide control signals */                                                   
#define DIV_MUX_CONTROL_CTL                    (* (reg8 *) DIV_MUX_CONTROL__CTL)
/* Drive Modes */
#define DIV_MUX_CONTROL_DM0                    (* (reg8 *) DIV_MUX_CONTROL__DM0) 
#define DIV_MUX_CONTROL_DM1                    (* (reg8 *) DIV_MUX_CONTROL__DM1)
#define DIV_MUX_CONTROL_DM2                    (* (reg8 *) DIV_MUX_CONTROL__DM2) 
/* Input Buffer Disable Override */
#define DIV_MUX_CONTROL_INP_DIS                (* (reg8 *) DIV_MUX_CONTROL__INP_DIS)
/* LCD Common or Segment Drive */
#define DIV_MUX_CONTROL_LCD_COM_SEG            (* (reg8 *) DIV_MUX_CONTROL__LCD_COM_SEG)
/* Enable Segment LCD */
#define DIV_MUX_CONTROL_LCD_EN                 (* (reg8 *) DIV_MUX_CONTROL__LCD_EN)
/* Slew Rate Control */
#define DIV_MUX_CONTROL_SLW                    (* (reg8 *) DIV_MUX_CONTROL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DIV_MUX_CONTROL_PRTDSI__CAPS_SEL       (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DIV_MUX_CONTROL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DIV_MUX_CONTROL_PRTDSI__OE_SEL0        (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__OE_SEL0) 
#define DIV_MUX_CONTROL_PRTDSI__OE_SEL1        (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DIV_MUX_CONTROL_PRTDSI__OUT_SEL0       (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__OUT_SEL0) 
#define DIV_MUX_CONTROL_PRTDSI__OUT_SEL1       (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DIV_MUX_CONTROL_PRTDSI__SYNC_OUT       (* (reg8 *) DIV_MUX_CONTROL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DIV_MUX_CONTROL__SIO_CFG)
    #define DIV_MUX_CONTROL_SIO_HYST_EN        (* (reg8 *) DIV_MUX_CONTROL__SIO_HYST_EN)
    #define DIV_MUX_CONTROL_SIO_REG_HIFREQ     (* (reg8 *) DIV_MUX_CONTROL__SIO_REG_HIFREQ)
    #define DIV_MUX_CONTROL_SIO_CFG            (* (reg8 *) DIV_MUX_CONTROL__SIO_CFG)
    #define DIV_MUX_CONTROL_SIO_DIFF           (* (reg8 *) DIV_MUX_CONTROL__SIO_DIFF)
#endif /* (DIV_MUX_CONTROL__SIO_CFG) */

/* Interrupt Registers */
#if defined(DIV_MUX_CONTROL__INTSTAT)
    #define DIV_MUX_CONTROL_INTSTAT            (* (reg8 *) DIV_MUX_CONTROL__INTSTAT)
    #define DIV_MUX_CONTROL_SNAP               (* (reg8 *) DIV_MUX_CONTROL__SNAP)
    
	#define DIV_MUX_CONTROL_0_INTTYPE_REG 		(* (reg8 *) DIV_MUX_CONTROL__0__INTTYPE)
#endif /* (DIV_MUX_CONTROL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DIV_MUX_CONTROL_H */


/* [] END OF FILE */
