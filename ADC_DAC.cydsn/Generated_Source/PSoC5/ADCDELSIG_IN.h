/*******************************************************************************
* File Name: ADCDELSIG_IN.h  
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

#if !defined(CY_PINS_ADCDELSIG_IN_H) /* Pins ADCDELSIG_IN_H */
#define CY_PINS_ADCDELSIG_IN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ADCDELSIG_IN_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ADCDELSIG_IN__PORT == 15 && ((ADCDELSIG_IN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    ADCDELSIG_IN_Write(uint8 value);
void    ADCDELSIG_IN_SetDriveMode(uint8 mode);
uint8   ADCDELSIG_IN_ReadDataReg(void);
uint8   ADCDELSIG_IN_Read(void);
void    ADCDELSIG_IN_SetInterruptMode(uint16 position, uint16 mode);
uint8   ADCDELSIG_IN_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the ADCDELSIG_IN_SetDriveMode() function.
     *  @{
     */
        #define ADCDELSIG_IN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define ADCDELSIG_IN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define ADCDELSIG_IN_DM_RES_UP          PIN_DM_RES_UP
        #define ADCDELSIG_IN_DM_RES_DWN         PIN_DM_RES_DWN
        #define ADCDELSIG_IN_DM_OD_LO           PIN_DM_OD_LO
        #define ADCDELSIG_IN_DM_OD_HI           PIN_DM_OD_HI
        #define ADCDELSIG_IN_DM_STRONG          PIN_DM_STRONG
        #define ADCDELSIG_IN_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define ADCDELSIG_IN_MASK               ADCDELSIG_IN__MASK
#define ADCDELSIG_IN_SHIFT              ADCDELSIG_IN__SHIFT
#define ADCDELSIG_IN_WIDTH              1u

/* Interrupt constants */
#if defined(ADCDELSIG_IN__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in ADCDELSIG_IN_SetInterruptMode() function.
     *  @{
     */
        #define ADCDELSIG_IN_INTR_NONE      (uint16)(0x0000u)
        #define ADCDELSIG_IN_INTR_RISING    (uint16)(0x0001u)
        #define ADCDELSIG_IN_INTR_FALLING   (uint16)(0x0002u)
        #define ADCDELSIG_IN_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define ADCDELSIG_IN_INTR_MASK      (0x01u) 
#endif /* (ADCDELSIG_IN__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ADCDELSIG_IN_PS                     (* (reg8 *) ADCDELSIG_IN__PS)
/* Data Register */
#define ADCDELSIG_IN_DR                     (* (reg8 *) ADCDELSIG_IN__DR)
/* Port Number */
#define ADCDELSIG_IN_PRT_NUM                (* (reg8 *) ADCDELSIG_IN__PRT) 
/* Connect to Analog Globals */                                                  
#define ADCDELSIG_IN_AG                     (* (reg8 *) ADCDELSIG_IN__AG)                       
/* Analog MUX bux enable */
#define ADCDELSIG_IN_AMUX                   (* (reg8 *) ADCDELSIG_IN__AMUX) 
/* Bidirectional Enable */                                                        
#define ADCDELSIG_IN_BIE                    (* (reg8 *) ADCDELSIG_IN__BIE)
/* Bit-mask for Aliased Register Access */
#define ADCDELSIG_IN_BIT_MASK               (* (reg8 *) ADCDELSIG_IN__BIT_MASK)
/* Bypass Enable */
#define ADCDELSIG_IN_BYP                    (* (reg8 *) ADCDELSIG_IN__BYP)
/* Port wide control signals */                                                   
#define ADCDELSIG_IN_CTL                    (* (reg8 *) ADCDELSIG_IN__CTL)
/* Drive Modes */
#define ADCDELSIG_IN_DM0                    (* (reg8 *) ADCDELSIG_IN__DM0) 
#define ADCDELSIG_IN_DM1                    (* (reg8 *) ADCDELSIG_IN__DM1)
#define ADCDELSIG_IN_DM2                    (* (reg8 *) ADCDELSIG_IN__DM2) 
/* Input Buffer Disable Override */
#define ADCDELSIG_IN_INP_DIS                (* (reg8 *) ADCDELSIG_IN__INP_DIS)
/* LCD Common or Segment Drive */
#define ADCDELSIG_IN_LCD_COM_SEG            (* (reg8 *) ADCDELSIG_IN__LCD_COM_SEG)
/* Enable Segment LCD */
#define ADCDELSIG_IN_LCD_EN                 (* (reg8 *) ADCDELSIG_IN__LCD_EN)
/* Slew Rate Control */
#define ADCDELSIG_IN_SLW                    (* (reg8 *) ADCDELSIG_IN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ADCDELSIG_IN_PRTDSI__CAPS_SEL       (* (reg8 *) ADCDELSIG_IN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ADCDELSIG_IN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ADCDELSIG_IN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ADCDELSIG_IN_PRTDSI__OE_SEL0        (* (reg8 *) ADCDELSIG_IN__PRTDSI__OE_SEL0) 
#define ADCDELSIG_IN_PRTDSI__OE_SEL1        (* (reg8 *) ADCDELSIG_IN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ADCDELSIG_IN_PRTDSI__OUT_SEL0       (* (reg8 *) ADCDELSIG_IN__PRTDSI__OUT_SEL0) 
#define ADCDELSIG_IN_PRTDSI__OUT_SEL1       (* (reg8 *) ADCDELSIG_IN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ADCDELSIG_IN_PRTDSI__SYNC_OUT       (* (reg8 *) ADCDELSIG_IN__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(ADCDELSIG_IN__SIO_CFG)
    #define ADCDELSIG_IN_SIO_HYST_EN        (* (reg8 *) ADCDELSIG_IN__SIO_HYST_EN)
    #define ADCDELSIG_IN_SIO_REG_HIFREQ     (* (reg8 *) ADCDELSIG_IN__SIO_REG_HIFREQ)
    #define ADCDELSIG_IN_SIO_CFG            (* (reg8 *) ADCDELSIG_IN__SIO_CFG)
    #define ADCDELSIG_IN_SIO_DIFF           (* (reg8 *) ADCDELSIG_IN__SIO_DIFF)
#endif /* (ADCDELSIG_IN__SIO_CFG) */

/* Interrupt Registers */
#if defined(ADCDELSIG_IN__INTSTAT)
    #define ADCDELSIG_IN_INTSTAT            (* (reg8 *) ADCDELSIG_IN__INTSTAT)
    #define ADCDELSIG_IN_SNAP               (* (reg8 *) ADCDELSIG_IN__SNAP)
    
	#define ADCDELSIG_IN_0_INTTYPE_REG 		(* (reg8 *) ADCDELSIG_IN__0__INTTYPE)
#endif /* (ADCDELSIG_IN__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ADCDELSIG_IN_H */


/* [] END OF FILE */
