/*******************************************************************************
* File Name: ADC_REG_CLCOK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_ADC_REG_CLCOK_H)
#define CY_CLOCK_ADC_REG_CLCOK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void ADC_REG_CLCOK_Start(void) ;
void ADC_REG_CLCOK_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ADC_REG_CLCOK_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ADC_REG_CLCOK_StandbyPower(uint8 state) ;
void ADC_REG_CLCOK_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ADC_REG_CLCOK_GetDividerRegister(void) ;
void ADC_REG_CLCOK_SetModeRegister(uint8 modeBitMask) ;
void ADC_REG_CLCOK_ClearModeRegister(uint8 modeBitMask) ;
uint8 ADC_REG_CLCOK_GetModeRegister(void) ;
void ADC_REG_CLCOK_SetSourceRegister(uint8 clkSource) ;
uint8 ADC_REG_CLCOK_GetSourceRegister(void) ;
#if defined(ADC_REG_CLCOK__CFG3)
void ADC_REG_CLCOK_SetPhaseRegister(uint8 clkPhase) ;
uint8 ADC_REG_CLCOK_GetPhaseRegister(void) ;
#endif /* defined(ADC_REG_CLCOK__CFG3) */

#define ADC_REG_CLCOK_Enable()                       ADC_REG_CLCOK_Start()
#define ADC_REG_CLCOK_Disable()                      ADC_REG_CLCOK_Stop()
#define ADC_REG_CLCOK_SetDivider(clkDivider)         ADC_REG_CLCOK_SetDividerRegister(clkDivider, 1u)
#define ADC_REG_CLCOK_SetDividerValue(clkDivider)    ADC_REG_CLCOK_SetDividerRegister((clkDivider) - 1u, 1u)
#define ADC_REG_CLCOK_SetMode(clkMode)               ADC_REG_CLCOK_SetModeRegister(clkMode)
#define ADC_REG_CLCOK_SetSource(clkSource)           ADC_REG_CLCOK_SetSourceRegister(clkSource)
#if defined(ADC_REG_CLCOK__CFG3)
#define ADC_REG_CLCOK_SetPhase(clkPhase)             ADC_REG_CLCOK_SetPhaseRegister(clkPhase)
#define ADC_REG_CLCOK_SetPhaseValue(clkPhase)        ADC_REG_CLCOK_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ADC_REG_CLCOK__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ADC_REG_CLCOK_CLKEN              (* (reg8 *) ADC_REG_CLCOK__PM_ACT_CFG)
#define ADC_REG_CLCOK_CLKEN_PTR          ((reg8 *) ADC_REG_CLCOK__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ADC_REG_CLCOK_CLKSTBY            (* (reg8 *) ADC_REG_CLCOK__PM_STBY_CFG)
#define ADC_REG_CLCOK_CLKSTBY_PTR        ((reg8 *) ADC_REG_CLCOK__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ADC_REG_CLCOK_DIV_LSB            (* (reg8 *) ADC_REG_CLCOK__CFG0)
#define ADC_REG_CLCOK_DIV_LSB_PTR        ((reg8 *) ADC_REG_CLCOK__CFG0)
#define ADC_REG_CLCOK_DIV_PTR            ((reg16 *) ADC_REG_CLCOK__CFG0)

/* Clock MSB divider configuration register. */
#define ADC_REG_CLCOK_DIV_MSB            (* (reg8 *) ADC_REG_CLCOK__CFG1)
#define ADC_REG_CLCOK_DIV_MSB_PTR        ((reg8 *) ADC_REG_CLCOK__CFG1)

/* Mode and source configuration register */
#define ADC_REG_CLCOK_MOD_SRC            (* (reg8 *) ADC_REG_CLCOK__CFG2)
#define ADC_REG_CLCOK_MOD_SRC_PTR        ((reg8 *) ADC_REG_CLCOK__CFG2)

#if defined(ADC_REG_CLCOK__CFG3)
/* Analog clock phase configuration register */
#define ADC_REG_CLCOK_PHASE              (* (reg8 *) ADC_REG_CLCOK__CFG3)
#define ADC_REG_CLCOK_PHASE_PTR          ((reg8 *) ADC_REG_CLCOK__CFG3)
#endif /* defined(ADC_REG_CLCOK__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ADC_REG_CLCOK_CLKEN_MASK         ADC_REG_CLCOK__PM_ACT_MSK
#define ADC_REG_CLCOK_CLKSTBY_MASK       ADC_REG_CLCOK__PM_STBY_MSK

/* CFG2 field masks */
#define ADC_REG_CLCOK_SRC_SEL_MSK        ADC_REG_CLCOK__CFG2_SRC_SEL_MASK
#define ADC_REG_CLCOK_MODE_MASK          (~(ADC_REG_CLCOK_SRC_SEL_MSK))

#if defined(ADC_REG_CLCOK__CFG3)
/* CFG3 phase mask */
#define ADC_REG_CLCOK_PHASE_MASK         ADC_REG_CLCOK__CFG3_PHASE_DLY_MASK
#endif /* defined(ADC_REG_CLCOK__CFG3) */

#endif /* CY_CLOCK_ADC_REG_CLCOK_H */


/* [] END OF FILE */
