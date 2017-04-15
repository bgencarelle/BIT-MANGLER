/*******************************************************************************
* File Name: DAC_IN_MSB.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DAC_IN_MSB.h"

#if !defined(DAC_IN_MSB_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: DAC_IN_MSB_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 DAC_IN_MSB_Read(void) 
{ 
    return DAC_IN_MSB_Status;
}


/*******************************************************************************
* Function Name: DAC_IN_MSB_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DAC_IN_MSB_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    DAC_IN_MSB_Status_Aux_Ctrl |= DAC_IN_MSB_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: DAC_IN_MSB_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void DAC_IN_MSB_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    DAC_IN_MSB_Status_Aux_Ctrl &= (uint8)(~DAC_IN_MSB_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: DAC_IN_MSB_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void DAC_IN_MSB_WriteMask(uint8 mask) 
{
    #if(DAC_IN_MSB_INPUTS < 8u)
    	mask &= ((uint8)(1u << DAC_IN_MSB_INPUTS) - 1u);
	#endif /* End DAC_IN_MSB_INPUTS < 8u */
    DAC_IN_MSB_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: DAC_IN_MSB_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 DAC_IN_MSB_ReadMask(void) 
{
    return DAC_IN_MSB_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
