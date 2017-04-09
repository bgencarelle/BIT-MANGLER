/*******************************************************************************
* File Name: MASK_REG_LSB_PM.c
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

#include "MASK_REG_LSB.h"

/* Check for removal by optimization */
#if !defined(MASK_REG_LSB_Sync_ctrl_reg__REMOVED)

static MASK_REG_LSB_BACKUP_STRUCT  MASK_REG_LSB_backup = {0u};

    
/*******************************************************************************
* Function Name: MASK_REG_LSB_SaveConfig
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
void MASK_REG_LSB_SaveConfig(void) 
{
    MASK_REG_LSB_backup.controlState = MASK_REG_LSB_Control;
}


/*******************************************************************************
* Function Name: MASK_REG_LSB_RestoreConfig
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
void MASK_REG_LSB_RestoreConfig(void) 
{
     MASK_REG_LSB_Control = MASK_REG_LSB_backup.controlState;
}


/*******************************************************************************
* Function Name: MASK_REG_LSB_Sleep
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
void MASK_REG_LSB_Sleep(void) 
{
    MASK_REG_LSB_SaveConfig();
}


/*******************************************************************************
* Function Name: MASK_REG_LSB_Wakeup
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
void MASK_REG_LSB_Wakeup(void)  
{
    MASK_REG_LSB_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */