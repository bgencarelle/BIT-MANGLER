/*******************************************************************************
* File Name: PWM_11_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_11.h"

static PWM_11_backupStruct PWM_11_backup;


/*******************************************************************************
* Function Name: PWM_11_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_11_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_11_SaveConfig(void) 
{

    #if(!PWM_11_UsingFixedFunction)
        #if(!PWM_11_PWMModeIsCenterAligned)
            PWM_11_backup.PWMPeriod = PWM_11_ReadPeriod();
        #endif /* (!PWM_11_PWMModeIsCenterAligned) */
        PWM_11_backup.PWMUdb = PWM_11_ReadCounter();
        #if (PWM_11_UseStatus)
            PWM_11_backup.InterruptMaskValue = PWM_11_STATUS_MASK;
        #endif /* (PWM_11_UseStatus) */

        #if(PWM_11_DeadBandMode == PWM_11__B_PWM__DBM_256_CLOCKS || \
            PWM_11_DeadBandMode == PWM_11__B_PWM__DBM_2_4_CLOCKS)
            PWM_11_backup.PWMdeadBandValue = PWM_11_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_11_KillModeMinTime)
             PWM_11_backup.PWMKillCounterPeriod = PWM_11_ReadKillTime();
        #endif /* (PWM_11_KillModeMinTime) */

        #if(PWM_11_UseControl)
            PWM_11_backup.PWMControlRegister = PWM_11_ReadControlRegister();
        #endif /* (PWM_11_UseControl) */
    #endif  /* (!PWM_11_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_11_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_11_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_11_RestoreConfig(void) 
{
        #if(!PWM_11_UsingFixedFunction)
            #if(!PWM_11_PWMModeIsCenterAligned)
                PWM_11_WritePeriod(PWM_11_backup.PWMPeriod);
            #endif /* (!PWM_11_PWMModeIsCenterAligned) */

            PWM_11_WriteCounter(PWM_11_backup.PWMUdb);

            #if (PWM_11_UseStatus)
                PWM_11_STATUS_MASK = PWM_11_backup.InterruptMaskValue;
            #endif /* (PWM_11_UseStatus) */

            #if(PWM_11_DeadBandMode == PWM_11__B_PWM__DBM_256_CLOCKS || \
                PWM_11_DeadBandMode == PWM_11__B_PWM__DBM_2_4_CLOCKS)
                PWM_11_WriteDeadTime(PWM_11_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_11_KillModeMinTime)
                PWM_11_WriteKillTime(PWM_11_backup.PWMKillCounterPeriod);
            #endif /* (PWM_11_KillModeMinTime) */

            #if(PWM_11_UseControl)
                PWM_11_WriteControlRegister(PWM_11_backup.PWMControlRegister);
            #endif /* (PWM_11_UseControl) */
        #endif  /* (!PWM_11_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_11_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_11_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_11_Sleep(void) 
{
    #if(PWM_11_UseControl)
        if(PWM_11_CTRL_ENABLE == (PWM_11_CONTROL & PWM_11_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_11_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_11_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_11_UseControl) */

    /* Stop component */
    PWM_11_Stop();

    /* Save registers configuration */
    PWM_11_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_11_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_11_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_11_Wakeup(void) 
{
     /* Restore registers values */
    PWM_11_RestoreConfig();

    if(PWM_11_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_11_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
