/*******************************************************************************
* File Name: DVDAC_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DVDAC.h"

static DVDAC_backupStruct DVDAC_backup;


/*******************************************************************************
* Function Name: DVDAC_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void DVDAC_SaveConfig(void) 
{
    if (!((DVDAC_CR1 & DVDAC_SRC_MASK) == DVDAC_SRC_UDB))
    {
        DVDAC_backup.data_value = DVDAC_Data;
    }
}


/*******************************************************************************
* Function Name: DVDAC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void DVDAC_RestoreConfig(void) 
{
    if (!((DVDAC_CR1 & DVDAC_SRC_MASK) == DVDAC_SRC_UDB))
    {
        if((DVDAC_Strobe & DVDAC_STRB_MASK) == DVDAC_STRB_EN)
        {
            DVDAC_Strobe &= (uint8)(~DVDAC_STRB_MASK);
            DVDAC_Data = DVDAC_backup.data_value;
            DVDAC_Strobe |= DVDAC_STRB_EN;
        }
        else
        {
            DVDAC_Data = DVDAC_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: DVDAC_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  DVDAC_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void DVDAC_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(DVDAC_ACT_PWR_EN == (DVDAC_PWRMGR & DVDAC_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        DVDAC_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        DVDAC_backup.enableState = 0u;
    }
    
    DVDAC_Stop();
    DVDAC_SaveConfig();
}


/*******************************************************************************
* Function Name: DVDAC_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  DVDAC_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void DVDAC_Wakeup(void) 
{
    DVDAC_RestoreConfig();
    
    if(DVDAC_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        DVDAC_Enable();

        /* Restore the data register */
        DVDAC_SetValue(DVDAC_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
