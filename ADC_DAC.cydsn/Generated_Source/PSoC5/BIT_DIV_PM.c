/*******************************************************************************
* File Name: BIT_DIV_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "BIT_DIV.h"

/* Check for removal by optimization */
#if !defined(BIT_DIV_Sync_ctrl_reg__REMOVED)

static BIT_DIV_BACKUP_STRUCT  BIT_DIV_backup = {0u};

    
/*******************************************************************************
* Function Name: BIT_DIV_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BIT_DIV_SaveConfig(void) 
{
    BIT_DIV_backup.controlState = BIT_DIV_Control;
}


/*******************************************************************************
* Function Name: BIT_DIV_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void BIT_DIV_RestoreConfig(void) 
{
     BIT_DIV_Control = BIT_DIV_backup.controlState;
}


/*******************************************************************************
* Function Name: BIT_DIV_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BIT_DIV_Sleep(void) 
{
    BIT_DIV_SaveConfig();
}


/*******************************************************************************
* Function Name: BIT_DIV_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void BIT_DIV_Wakeup(void)  
{
    BIT_DIV_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
