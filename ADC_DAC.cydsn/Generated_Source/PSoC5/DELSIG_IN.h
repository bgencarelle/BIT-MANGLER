/*******************************************************************************
* File Name: DELSIG_IN.h  
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

#if !defined(CY_PINS_DELSIG_IN_H) /* Pins DELSIG_IN_H */
#define CY_PINS_DELSIG_IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DELSIG_IN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DELSIG_IN__PORT == 15 && ((DELSIG_IN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DELSIG_IN_Write(uint8 value);
void    DELSIG_IN_SetDriveMode(uint8 mode);
uint8   DELSIG_IN_ReadDataReg(void);
uint8   DELSIG_IN_Read(void);
void    DELSIG_IN_SetInterruptMode(uint16 position, uint16 mode);
uint8   DELSIG_IN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DELSIG_IN_SetDriveMode() function.
     *  @{
     */
        #define DELSIG_IN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DELSIG_IN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DELSIG_IN_DM_RES_UP          PIN_DM_RES_UP
        #define DELSIG_IN_DM_RES_DWN         PIN_DM_RES_DWN
        #define DELSIG_IN_DM_OD_LO           PIN_DM_OD_LO
        #define DELSIG_IN_DM_OD_HI           PIN_DM_OD_HI
        #define DELSIG_IN_DM_STRONG          PIN_DM_STRONG
        #define DELSIG_IN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DELSIG_IN_MASK               DELSIG_IN__MASK
#define DELSIG_IN_SHIFT              DELSIG_IN__SHIFT
#define DELSIG_IN_WIDTH              1u

/* Interrupt constants */
#if defined(DELSIG_IN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DELSIG_IN_SetInterruptMode() function.
     *  @{
     */
        #define DELSIG_IN_INTR_NONE      (uint16)(0x0000u)
        #define DELSIG_IN_INTR_RISING    (uint16)(0x0001u)
        #define DELSIG_IN_INTR_FALLING   (uint16)(0x0002u)
        #define DELSIG_IN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DELSIG_IN_INTR_MASK      (0x01u) 
#endif /* (DELSIG_IN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DELSIG_IN_PS                     (* (reg8 *) DELSIG_IN__PS)
/* Data Register */
#define DELSIG_IN_DR                     (* (reg8 *) DELSIG_IN__DR)
/* Port Number */
#define DELSIG_IN_PRT_NUM                (* (reg8 *) DELSIG_IN__PRT) 
/* Connect to Analog Globals */                                                  
#define DELSIG_IN_AG                     (* (reg8 *) DELSIG_IN__AG)                       
/* Analog MUX bux enable */
#define DELSIG_IN_AMUX                   (* (reg8 *) DELSIG_IN__AMUX) 
/* Bidirectional Enable */                                                        
#define DELSIG_IN_BIE                    (* (reg8 *) DELSIG_IN__BIE)
/* Bit-mask for Aliased Register Access */
#define DELSIG_IN_BIT_MASK               (* (reg8 *) DELSIG_IN__BIT_MASK)
/* Bypass Enable */
#define DELSIG_IN_BYP                    (* (reg8 *) DELSIG_IN__BYP)
/* Port wide control signals */                                                   
#define DELSIG_IN_CTL                    (* (reg8 *) DELSIG_IN__CTL)
/* Drive Modes */
#define DELSIG_IN_DM0                    (* (reg8 *) DELSIG_IN__DM0) 
#define DELSIG_IN_DM1                    (* (reg8 *) DELSIG_IN__DM1)
#define DELSIG_IN_DM2                    (* (reg8 *) DELSIG_IN__DM2) 
/* Input Buffer Disable Override */
#define DELSIG_IN_INP_DIS                (* (reg8 *) DELSIG_IN__INP_DIS)
/* LCD Common or Segment Drive */
#define DELSIG_IN_LCD_COM_SEG            (* (reg8 *) DELSIG_IN__LCD_COM_SEG)
/* Enable Segment LCD */
#define DELSIG_IN_LCD_EN                 (* (reg8 *) DELSIG_IN__LCD_EN)
/* Slew Rate Control */
#define DELSIG_IN_SLW                    (* (reg8 *) DELSIG_IN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DELSIG_IN_PRTDSI__CAPS_SEL       (* (reg8 *) DELSIG_IN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DELSIG_IN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DELSIG_IN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DELSIG_IN_PRTDSI__OE_SEL0        (* (reg8 *) DELSIG_IN__PRTDSI__OE_SEL0) 
#define DELSIG_IN_PRTDSI__OE_SEL1        (* (reg8 *) DELSIG_IN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DELSIG_IN_PRTDSI__OUT_SEL0       (* (reg8 *) DELSIG_IN__PRTDSI__OUT_SEL0) 
#define DELSIG_IN_PRTDSI__OUT_SEL1       (* (reg8 *) DELSIG_IN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DELSIG_IN_PRTDSI__SYNC_OUT       (* (reg8 *) DELSIG_IN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DELSIG_IN__SIO_CFG)
    #define DELSIG_IN_SIO_HYST_EN        (* (reg8 *) DELSIG_IN__SIO_HYST_EN)
    #define DELSIG_IN_SIO_REG_HIFREQ     (* (reg8 *) DELSIG_IN__SIO_REG_HIFREQ)
    #define DELSIG_IN_SIO_CFG            (* (reg8 *) DELSIG_IN__SIO_CFG)
    #define DELSIG_IN_SIO_DIFF           (* (reg8 *) DELSIG_IN__SIO_DIFF)
#endif /* (DELSIG_IN__SIO_CFG) */

/* Interrupt Registers */
#if defined(DELSIG_IN__INTSTAT)
    #define DELSIG_IN_INTSTAT            (* (reg8 *) DELSIG_IN__INTSTAT)
    #define DELSIG_IN_SNAP               (* (reg8 *) DELSIG_IN__SNAP)
    
	#define DELSIG_IN_0_INTTYPE_REG 		(* (reg8 *) DELSIG_IN__0__INTTYPE)
#endif /* (DELSIG_IN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DELSIG_IN_H */


/* [] END OF FILE */
