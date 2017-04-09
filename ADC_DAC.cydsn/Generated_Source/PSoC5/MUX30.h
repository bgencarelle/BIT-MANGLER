/*******************************************************************************
* File Name: MUX30.h  
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

#if !defined(CY_PINS_MUX30_H) /* Pins MUX30_H */
#define CY_PINS_MUX30_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MUX30_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MUX30__PORT == 15 && ((MUX30__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MUX30_Write(uint8 value);
void    MUX30_SetDriveMode(uint8 mode);
uint8   MUX30_ReadDataReg(void);
uint8   MUX30_Read(void);
void    MUX30_SetInterruptMode(uint16 position, uint16 mode);
uint8   MUX30_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MUX30_SetDriveMode() function.
     *  @{
     */
        #define MUX30_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MUX30_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MUX30_DM_RES_UP          PIN_DM_RES_UP
        #define MUX30_DM_RES_DWN         PIN_DM_RES_DWN
        #define MUX30_DM_OD_LO           PIN_DM_OD_LO
        #define MUX30_DM_OD_HI           PIN_DM_OD_HI
        #define MUX30_DM_STRONG          PIN_DM_STRONG
        #define MUX30_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MUX30_MASK               MUX30__MASK
#define MUX30_SHIFT              MUX30__SHIFT
#define MUX30_WIDTH              1u

/* Interrupt constants */
#if defined(MUX30__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MUX30_SetInterruptMode() function.
     *  @{
     */
        #define MUX30_INTR_NONE      (uint16)(0x0000u)
        #define MUX30_INTR_RISING    (uint16)(0x0001u)
        #define MUX30_INTR_FALLING   (uint16)(0x0002u)
        #define MUX30_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MUX30_INTR_MASK      (0x01u) 
#endif /* (MUX30__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MUX30_PS                     (* (reg8 *) MUX30__PS)
/* Data Register */
#define MUX30_DR                     (* (reg8 *) MUX30__DR)
/* Port Number */
#define MUX30_PRT_NUM                (* (reg8 *) MUX30__PRT) 
/* Connect to Analog Globals */                                                  
#define MUX30_AG                     (* (reg8 *) MUX30__AG)                       
/* Analog MUX bux enable */
#define MUX30_AMUX                   (* (reg8 *) MUX30__AMUX) 
/* Bidirectional Enable */                                                        
#define MUX30_BIE                    (* (reg8 *) MUX30__BIE)
/* Bit-mask for Aliased Register Access */
#define MUX30_BIT_MASK               (* (reg8 *) MUX30__BIT_MASK)
/* Bypass Enable */
#define MUX30_BYP                    (* (reg8 *) MUX30__BYP)
/* Port wide control signals */                                                   
#define MUX30_CTL                    (* (reg8 *) MUX30__CTL)
/* Drive Modes */
#define MUX30_DM0                    (* (reg8 *) MUX30__DM0) 
#define MUX30_DM1                    (* (reg8 *) MUX30__DM1)
#define MUX30_DM2                    (* (reg8 *) MUX30__DM2) 
/* Input Buffer Disable Override */
#define MUX30_INP_DIS                (* (reg8 *) MUX30__INP_DIS)
/* LCD Common or Segment Drive */
#define MUX30_LCD_COM_SEG            (* (reg8 *) MUX30__LCD_COM_SEG)
/* Enable Segment LCD */
#define MUX30_LCD_EN                 (* (reg8 *) MUX30__LCD_EN)
/* Slew Rate Control */
#define MUX30_SLW                    (* (reg8 *) MUX30__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MUX30_PRTDSI__CAPS_SEL       (* (reg8 *) MUX30__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MUX30_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MUX30__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MUX30_PRTDSI__OE_SEL0        (* (reg8 *) MUX30__PRTDSI__OE_SEL0) 
#define MUX30_PRTDSI__OE_SEL1        (* (reg8 *) MUX30__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MUX30_PRTDSI__OUT_SEL0       (* (reg8 *) MUX30__PRTDSI__OUT_SEL0) 
#define MUX30_PRTDSI__OUT_SEL1       (* (reg8 *) MUX30__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MUX30_PRTDSI__SYNC_OUT       (* (reg8 *) MUX30__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MUX30__SIO_CFG)
    #define MUX30_SIO_HYST_EN        (* (reg8 *) MUX30__SIO_HYST_EN)
    #define MUX30_SIO_REG_HIFREQ     (* (reg8 *) MUX30__SIO_REG_HIFREQ)
    #define MUX30_SIO_CFG            (* (reg8 *) MUX30__SIO_CFG)
    #define MUX30_SIO_DIFF           (* (reg8 *) MUX30__SIO_DIFF)
#endif /* (MUX30__SIO_CFG) */

/* Interrupt Registers */
#if defined(MUX30__INTSTAT)
    #define MUX30_INTSTAT            (* (reg8 *) MUX30__INTSTAT)
    #define MUX30_SNAP               (* (reg8 *) MUX30__SNAP)
    
	#define MUX30_0_INTTYPE_REG 		(* (reg8 *) MUX30__0__INTTYPE)
#endif /* (MUX30__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MUX30_H */


/* [] END OF FILE */
