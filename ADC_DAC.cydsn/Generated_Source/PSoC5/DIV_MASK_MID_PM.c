/*******************************************************************************
* File Name: DIV_MASK_MID_PM.c
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

#include "DIV_MASK_MID.h"

/* Check for removal by optimization */
#if !defined(DIV_MASK_MID_Sync_ctrl_reg__REMOVED)

static DIV_MASK_MID_BACKUP_STRUCT  DIV_MASK_MID_backup = {0u};

    
/*******************************************************************************
* Function Name: DIV_MASK_MID_SaveConfig
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
void DIV_MASK_MID_SaveConfig(void) 
{
    DIV_MASK_MID_backup.controlState = DIV_MASK_MID_Control;
}


/*******************************************************************************
* Function Name: DIV_MASK_MID_RestoreConfig
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
void DIV_MASK_MID_RestoreConfig(void) 
{
     DIV_MASK_MID_Control = DIV_MASK_MID_backup.controlState;
}


/*******************************************************************************
* Function Name: DIV_MASK_MID_Sleep
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
void DIV_MASK_MID_Sleep(void) 
{
    DIV_MASK_MID_SaveConfig();
}


/*******************************************************************************
* Function Name: DIV_MASK_MID_Wakeup
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
void DIV_MASK_MID_Wakeup(void)  
{
    DIV_MASK_MID_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
