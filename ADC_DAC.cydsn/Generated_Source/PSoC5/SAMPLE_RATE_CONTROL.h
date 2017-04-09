/*******************************************************************************
* File Name: SAMPLE_RATE_CONTROL.h  
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

#if !defined(CY_PINS_SAMPLE_RATE_CONTROL_H) /* Pins SAMPLE_RATE_CONTROL_H */
#define CY_PINS_SAMPLE_RATE_CONTROL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SAMPLE_RATE_CONTROL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SAMPLE_RATE_CONTROL__PORT == 15 && ((SAMPLE_RATE_CONTROL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    SAMPLE_RATE_CONTROL_Write(uint8 value);
void    SAMPLE_RATE_CONTROL_SetDriveMode(uint8 mode);
uint8   SAMPLE_RATE_CONTROL_ReadDataReg(void);
uint8   SAMPLE_RATE_CONTROL_Read(void);
void    SAMPLE_RATE_CONTROL_SetInterruptMode(uint16 position, uint16 mode);
uint8   SAMPLE_RATE_CONTROL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the SAMPLE_RATE_CONTROL_SetDriveMode() function.
     *  @{
     */
        #define SAMPLE_RATE_CONTROL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define SAMPLE_RATE_CONTROL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define SAMPLE_RATE_CONTROL_DM_RES_UP          PIN_DM_RES_UP
        #define SAMPLE_RATE_CONTROL_DM_RES_DWN         PIN_DM_RES_DWN
        #define SAMPLE_RATE_CONTROL_DM_OD_LO           PIN_DM_OD_LO
        #define SAMPLE_RATE_CONTROL_DM_OD_HI           PIN_DM_OD_HI
        #define SAMPLE_RATE_CONTROL_DM_STRONG          PIN_DM_STRONG
        #define SAMPLE_RATE_CONTROL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define SAMPLE_RATE_CONTROL_MASK               SAMPLE_RATE_CONTROL__MASK
#define SAMPLE_RATE_CONTROL_SHIFT              SAMPLE_RATE_CONTROL__SHIFT
#define SAMPLE_RATE_CONTROL_WIDTH              1u

/* Interrupt constants */
#if defined(SAMPLE_RATE_CONTROL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in SAMPLE_RATE_CONTROL_SetInterruptMode() function.
     *  @{
     */
        #define SAMPLE_RATE_CONTROL_INTR_NONE      (uint16)(0x0000u)
        #define SAMPLE_RATE_CONTROL_INTR_RISING    (uint16)(0x0001u)
        #define SAMPLE_RATE_CONTROL_INTR_FALLING   (uint16)(0x0002u)
        #define SAMPLE_RATE_CONTROL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define SAMPLE_RATE_CONTROL_INTR_MASK      (0x01u) 
#endif /* (SAMPLE_RATE_CONTROL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SAMPLE_RATE_CONTROL_PS                     (* (reg8 *) SAMPLE_RATE_CONTROL__PS)
/* Data Register */
#define SAMPLE_RATE_CONTROL_DR                     (* (reg8 *) SAMPLE_RATE_CONTROL__DR)
/* Port Number */
#define SAMPLE_RATE_CONTROL_PRT_NUM                (* (reg8 *) SAMPLE_RATE_CONTROL__PRT) 
/* Connect to Analog Globals */                                                  
#define SAMPLE_RATE_CONTROL_AG                     (* (reg8 *) SAMPLE_RATE_CONTROL__AG)                       
/* Analog MUX bux enable */
#define SAMPLE_RATE_CONTROL_AMUX                   (* (reg8 *) SAMPLE_RATE_CONTROL__AMUX) 
/* Bidirectional Enable */                                                        
#define SAMPLE_RATE_CONTROL_BIE                    (* (reg8 *) SAMPLE_RATE_CONTROL__BIE)
/* Bit-mask for Aliased Register Access */
#define SAMPLE_RATE_CONTROL_BIT_MASK               (* (reg8 *) SAMPLE_RATE_CONTROL__BIT_MASK)
/* Bypass Enable */
#define SAMPLE_RATE_CONTROL_BYP                    (* (reg8 *) SAMPLE_RATE_CONTROL__BYP)
/* Port wide control signals */                                                   
#define SAMPLE_RATE_CONTROL_CTL                    (* (reg8 *) SAMPLE_RATE_CONTROL__CTL)
/* Drive Modes */
#define SAMPLE_RATE_CONTROL_DM0                    (* (reg8 *) SAMPLE_RATE_CONTROL__DM0) 
#define SAMPLE_RATE_CONTROL_DM1                    (* (reg8 *) SAMPLE_RATE_CONTROL__DM1)
#define SAMPLE_RATE_CONTROL_DM2                    (* (reg8 *) SAMPLE_RATE_CONTROL__DM2) 
/* Input Buffer Disable Override */
#define SAMPLE_RATE_CONTROL_INP_DIS                (* (reg8 *) SAMPLE_RATE_CONTROL__INP_DIS)
/* LCD Common or Segment Drive */
#define SAMPLE_RATE_CONTROL_LCD_COM_SEG            (* (reg8 *) SAMPLE_RATE_CONTROL__LCD_COM_SEG)
/* Enable Segment LCD */
#define SAMPLE_RATE_CONTROL_LCD_EN                 (* (reg8 *) SAMPLE_RATE_CONTROL__LCD_EN)
/* Slew Rate Control */
#define SAMPLE_RATE_CONTROL_SLW                    (* (reg8 *) SAMPLE_RATE_CONTROL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SAMPLE_RATE_CONTROL_PRTDSI__CAPS_SEL       (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SAMPLE_RATE_CONTROL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SAMPLE_RATE_CONTROL_PRTDSI__OE_SEL0        (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__OE_SEL0) 
#define SAMPLE_RATE_CONTROL_PRTDSI__OE_SEL1        (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SAMPLE_RATE_CONTROL_PRTDSI__OUT_SEL0       (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__OUT_SEL0) 
#define SAMPLE_RATE_CONTROL_PRTDSI__OUT_SEL1       (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SAMPLE_RATE_CONTROL_PRTDSI__SYNC_OUT       (* (reg8 *) SAMPLE_RATE_CONTROL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(SAMPLE_RATE_CONTROL__SIO_CFG)
    #define SAMPLE_RATE_CONTROL_SIO_HYST_EN        (* (reg8 *) SAMPLE_RATE_CONTROL__SIO_HYST_EN)
    #define SAMPLE_RATE_CONTROL_SIO_REG_HIFREQ     (* (reg8 *) SAMPLE_RATE_CONTROL__SIO_REG_HIFREQ)
    #define SAMPLE_RATE_CONTROL_SIO_CFG            (* (reg8 *) SAMPLE_RATE_CONTROL__SIO_CFG)
    #define SAMPLE_RATE_CONTROL_SIO_DIFF           (* (reg8 *) SAMPLE_RATE_CONTROL__SIO_DIFF)
#endif /* (SAMPLE_RATE_CONTROL__SIO_CFG) */

/* Interrupt Registers */
#if defined(SAMPLE_RATE_CONTROL__INTSTAT)
    #define SAMPLE_RATE_CONTROL_INTSTAT            (* (reg8 *) SAMPLE_RATE_CONTROL__INTSTAT)
    #define SAMPLE_RATE_CONTROL_SNAP               (* (reg8 *) SAMPLE_RATE_CONTROL__SNAP)
    
	#define SAMPLE_RATE_CONTROL_0_INTTYPE_REG 		(* (reg8 *) SAMPLE_RATE_CONTROL__0__INTTYPE)
#endif /* (SAMPLE_RATE_CONTROL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SAMPLE_RATE_CONTROL_H */


/* [] END OF FILE */
