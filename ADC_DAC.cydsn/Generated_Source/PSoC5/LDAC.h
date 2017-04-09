/*******************************************************************************
* File Name: LDAC.h  
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

#if !defined(CY_PINS_LDAC_H) /* Pins LDAC_H */
#define CY_PINS_LDAC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LDAC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LDAC__PORT == 15 && ((LDAC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    LDAC_Write(uint8 value);
void    LDAC_SetDriveMode(uint8 mode);
uint8   LDAC_ReadDataReg(void);
uint8   LDAC_Read(void);
void    LDAC_SetInterruptMode(uint16 position, uint16 mode);
uint8   LDAC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the LDAC_SetDriveMode() function.
     *  @{
     */
        #define LDAC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define LDAC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define LDAC_DM_RES_UP          PIN_DM_RES_UP
        #define LDAC_DM_RES_DWN         PIN_DM_RES_DWN
        #define LDAC_DM_OD_LO           PIN_DM_OD_LO
        #define LDAC_DM_OD_HI           PIN_DM_OD_HI
        #define LDAC_DM_STRONG          PIN_DM_STRONG
        #define LDAC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define LDAC_MASK               LDAC__MASK
#define LDAC_SHIFT              LDAC__SHIFT
#define LDAC_WIDTH              1u

/* Interrupt constants */
#if defined(LDAC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in LDAC_SetInterruptMode() function.
     *  @{
     */
        #define LDAC_INTR_NONE      (uint16)(0x0000u)
        #define LDAC_INTR_RISING    (uint16)(0x0001u)
        #define LDAC_INTR_FALLING   (uint16)(0x0002u)
        #define LDAC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define LDAC_INTR_MASK      (0x01u) 
#endif /* (LDAC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LDAC_PS                     (* (reg8 *) LDAC__PS)
/* Data Register */
#define LDAC_DR                     (* (reg8 *) LDAC__DR)
/* Port Number */
#define LDAC_PRT_NUM                (* (reg8 *) LDAC__PRT) 
/* Connect to Analog Globals */                                                  
#define LDAC_AG                     (* (reg8 *) LDAC__AG)                       
/* Analog MUX bux enable */
#define LDAC_AMUX                   (* (reg8 *) LDAC__AMUX) 
/* Bidirectional Enable */                                                        
#define LDAC_BIE                    (* (reg8 *) LDAC__BIE)
/* Bit-mask for Aliased Register Access */
#define LDAC_BIT_MASK               (* (reg8 *) LDAC__BIT_MASK)
/* Bypass Enable */
#define LDAC_BYP                    (* (reg8 *) LDAC__BYP)
/* Port wide control signals */                                                   
#define LDAC_CTL                    (* (reg8 *) LDAC__CTL)
/* Drive Modes */
#define LDAC_DM0                    (* (reg8 *) LDAC__DM0) 
#define LDAC_DM1                    (* (reg8 *) LDAC__DM1)
#define LDAC_DM2                    (* (reg8 *) LDAC__DM2) 
/* Input Buffer Disable Override */
#define LDAC_INP_DIS                (* (reg8 *) LDAC__INP_DIS)
/* LCD Common or Segment Drive */
#define LDAC_LCD_COM_SEG            (* (reg8 *) LDAC__LCD_COM_SEG)
/* Enable Segment LCD */
#define LDAC_LCD_EN                 (* (reg8 *) LDAC__LCD_EN)
/* Slew Rate Control */
#define LDAC_SLW                    (* (reg8 *) LDAC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LDAC_PRTDSI__CAPS_SEL       (* (reg8 *) LDAC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LDAC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LDAC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LDAC_PRTDSI__OE_SEL0        (* (reg8 *) LDAC__PRTDSI__OE_SEL0) 
#define LDAC_PRTDSI__OE_SEL1        (* (reg8 *) LDAC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LDAC_PRTDSI__OUT_SEL0       (* (reg8 *) LDAC__PRTDSI__OUT_SEL0) 
#define LDAC_PRTDSI__OUT_SEL1       (* (reg8 *) LDAC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LDAC_PRTDSI__SYNC_OUT       (* (reg8 *) LDAC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(LDAC__SIO_CFG)
    #define LDAC_SIO_HYST_EN        (* (reg8 *) LDAC__SIO_HYST_EN)
    #define LDAC_SIO_REG_HIFREQ     (* (reg8 *) LDAC__SIO_REG_HIFREQ)
    #define LDAC_SIO_CFG            (* (reg8 *) LDAC__SIO_CFG)
    #define LDAC_SIO_DIFF           (* (reg8 *) LDAC__SIO_DIFF)
#endif /* (LDAC__SIO_CFG) */

/* Interrupt Registers */
#if defined(LDAC__INTSTAT)
    #define LDAC_INTSTAT            (* (reg8 *) LDAC__INTSTAT)
    #define LDAC_SNAP               (* (reg8 *) LDAC__SNAP)
    
	#define LDAC_0_INTTYPE_REG 		(* (reg8 *) LDAC__0__INTTYPE)
#endif /* (LDAC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LDAC_H */


/* [] END OF FILE */
