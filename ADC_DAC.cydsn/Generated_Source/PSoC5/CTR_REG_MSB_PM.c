/*******************************************************************************
* File Name: CTR_REG_MSB_PM.c
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

#include "CTR_REG_MSB.h"

/* Check for removal by optimization */
#if !defined(CTR_REG_MSB_Sync_ctrl_reg__REMOVED)

static CTR_REG_MSB_BACKUP_STRUCT  CTR_REG_MSB_backup = {0u};

    
/*******************************************************************************
* Function Name: CTR_REG_MSB_SaveConfig
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
void CTR_REG_MSB_SaveConfig(void) 
{
    CTR_REG_MSB_backup.controlState = CTR_REG_MSB_Control;
}


/*******************************************************************************
* Function Name: CTR_REG_MSB_RestoreConfig
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
void CTR_REG_MSB_RestoreConfig(void) 
{
     CTR_REG_MSB_Control = CTR_REG_MSB_backup.controlState;
}


/*******************************************************************************
* Function Name: CTR_REG_MSB_Sleep
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
void CTR_REG_MSB_Sleep(void) 
{
    CTR_REG_MSB_SaveConfig();
}


/*******************************************************************************
* Function Name: CTR_REG_MSB_Wakeup
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
void CTR_REG_MSB_Wakeup(void)  
{
    CTR_REG_MSB_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
