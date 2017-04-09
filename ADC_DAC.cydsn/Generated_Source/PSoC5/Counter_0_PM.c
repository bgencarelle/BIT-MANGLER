/*******************************************************************************
* File Name: Counter_0_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Counter_0.h"

static Counter_0_backupStruct Counter_0_backup;


/*******************************************************************************
* Function Name: Counter_0_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_0_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_0_SaveConfig(void) 
{
    #if (!Counter_0_UsingFixedFunction)

        Counter_0_backup.CounterUdb = Counter_0_ReadCounter();

        #if(!Counter_0_ControlRegRemoved)
            Counter_0_backup.CounterControlRegister = Counter_0_ReadControlRegister();
        #endif /* (!Counter_0_ControlRegRemoved) */

    #endif /* (!Counter_0_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_0_RestoreConfig
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
* Global variables:
*  Counter_0_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_0_RestoreConfig(void) 
{      
    #if (!Counter_0_UsingFixedFunction)

       Counter_0_WriteCounter(Counter_0_backup.CounterUdb);

        #if(!Counter_0_ControlRegRemoved)
            Counter_0_WriteControlRegister(Counter_0_backup.CounterControlRegister);
        #endif /* (!Counter_0_ControlRegRemoved) */

    #endif /* (!Counter_0_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_0_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Counter_0_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_0_Sleep(void) 
{
    #if(!Counter_0_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_0_CTRL_ENABLE == (Counter_0_CONTROL & Counter_0_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_0_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_0_backup.CounterEnableState = 0u;
        }
    #else
        Counter_0_backup.CounterEnableState = 1u;
        if(Counter_0_backup.CounterEnableState != 0u)
        {
            Counter_0_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_0_ControlRegRemoved) */
    
    Counter_0_Stop();
    Counter_0_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_0_Wakeup
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
*  Counter_0_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_0_Wakeup(void) 
{
    Counter_0_RestoreConfig();
    #if(!Counter_0_ControlRegRemoved)
        if(Counter_0_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_0_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_0_ControlRegRemoved) */
    
}


/* [] END OF FILE */
