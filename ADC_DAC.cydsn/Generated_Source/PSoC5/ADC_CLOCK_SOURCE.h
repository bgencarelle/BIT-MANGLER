/*******************************************************************************
* File Name: ADC_CLOCK_SOURCE.h
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

#if !defined(CY_CLOCK_ADC_CLOCK_SOURCE_H)
#define CY_CLOCK_ADC_CLOCK_SOURCE_H

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

void ADC_CLOCK_SOURCE_Start(void) ;
void ADC_CLOCK_SOURCE_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void ADC_CLOCK_SOURCE_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void ADC_CLOCK_SOURCE_StandbyPower(uint8 state) ;
void ADC_CLOCK_SOURCE_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 ADC_CLOCK_SOURCE_GetDividerRegister(void) ;
void ADC_CLOCK_SOURCE_SetModeRegister(uint8 modeBitMask) ;
void ADC_CLOCK_SOURCE_ClearModeRegister(uint8 modeBitMask) ;
uint8 ADC_CLOCK_SOURCE_GetModeRegister(void) ;
void ADC_CLOCK_SOURCE_SetSourceRegister(uint8 clkSource) ;
uint8 ADC_CLOCK_SOURCE_GetSourceRegister(void) ;
#if defined(ADC_CLOCK_SOURCE__CFG3)
void ADC_CLOCK_SOURCE_SetPhaseRegister(uint8 clkPhase) ;
uint8 ADC_CLOCK_SOURCE_GetPhaseRegister(void) ;
#endif /* defined(ADC_CLOCK_SOURCE__CFG3) */

#define ADC_CLOCK_SOURCE_Enable()                       ADC_CLOCK_SOURCE_Start()
#define ADC_CLOCK_SOURCE_Disable()                      ADC_CLOCK_SOURCE_Stop()
#define ADC_CLOCK_SOURCE_SetDivider(clkDivider)         ADC_CLOCK_SOURCE_SetDividerRegister(clkDivider, 1u)
#define ADC_CLOCK_SOURCE_SetDividerValue(clkDivider)    ADC_CLOCK_SOURCE_SetDividerRegister((clkDivider) - 1u, 1u)
#define ADC_CLOCK_SOURCE_SetMode(clkMode)               ADC_CLOCK_SOURCE_SetModeRegister(clkMode)
#define ADC_CLOCK_SOURCE_SetSource(clkSource)           ADC_CLOCK_SOURCE_SetSourceRegister(clkSource)
#if defined(ADC_CLOCK_SOURCE__CFG3)
#define ADC_CLOCK_SOURCE_SetPhase(clkPhase)             ADC_CLOCK_SOURCE_SetPhaseRegister(clkPhase)
#define ADC_CLOCK_SOURCE_SetPhaseValue(clkPhase)        ADC_CLOCK_SOURCE_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(ADC_CLOCK_SOURCE__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define ADC_CLOCK_SOURCE_CLKEN              (* (reg8 *) ADC_CLOCK_SOURCE__PM_ACT_CFG)
#define ADC_CLOCK_SOURCE_CLKEN_PTR          ((reg8 *) ADC_CLOCK_SOURCE__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define ADC_CLOCK_SOURCE_CLKSTBY            (* (reg8 *) ADC_CLOCK_SOURCE__PM_STBY_CFG)
#define ADC_CLOCK_SOURCE_CLKSTBY_PTR        ((reg8 *) ADC_CLOCK_SOURCE__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define ADC_CLOCK_SOURCE_DIV_LSB            (* (reg8 *) ADC_CLOCK_SOURCE__CFG0)
#define ADC_CLOCK_SOURCE_DIV_LSB_PTR        ((reg8 *) ADC_CLOCK_SOURCE__CFG0)
#define ADC_CLOCK_SOURCE_DIV_PTR            ((reg16 *) ADC_CLOCK_SOURCE__CFG0)

/* Clock MSB divider configuration register. */
#define ADC_CLOCK_SOURCE_DIV_MSB            (* (reg8 *) ADC_CLOCK_SOURCE__CFG1)
#define ADC_CLOCK_SOURCE_DIV_MSB_PTR        ((reg8 *) ADC_CLOCK_SOURCE__CFG1)

/* Mode and source configuration register */
#define ADC_CLOCK_SOURCE_MOD_SRC            (* (reg8 *) ADC_CLOCK_SOURCE__CFG2)
#define ADC_CLOCK_SOURCE_MOD_SRC_PTR        ((reg8 *) ADC_CLOCK_SOURCE__CFG2)

#if defined(ADC_CLOCK_SOURCE__CFG3)
/* Analog clock phase configuration register */
#define ADC_CLOCK_SOURCE_PHASE              (* (reg8 *) ADC_CLOCK_SOURCE__CFG3)
#define ADC_CLOCK_SOURCE_PHASE_PTR          ((reg8 *) ADC_CLOCK_SOURCE__CFG3)
#endif /* defined(ADC_CLOCK_SOURCE__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define ADC_CLOCK_SOURCE_CLKEN_MASK         ADC_CLOCK_SOURCE__PM_ACT_MSK
#define ADC_CLOCK_SOURCE_CLKSTBY_MASK       ADC_CLOCK_SOURCE__PM_STBY_MSK

/* CFG2 field masks */
#define ADC_CLOCK_SOURCE_SRC_SEL_MSK        ADC_CLOCK_SOURCE__CFG2_SRC_SEL_MASK
#define ADC_CLOCK_SOURCE_MODE_MASK          (~(ADC_CLOCK_SOURCE_SRC_SEL_MSK))

#if defined(ADC_CLOCK_SOURCE__CFG3)
/* CFG3 phase mask */
#define ADC_CLOCK_SOURCE_PHASE_MASK         ADC_CLOCK_SOURCE__CFG3_PHASE_DLY_MASK
#endif /* defined(ADC_CLOCK_SOURCE__CFG3) */

#endif /* CY_CLOCK_ADC_CLOCK_SOURCE_H */


/* [] END OF FILE */
