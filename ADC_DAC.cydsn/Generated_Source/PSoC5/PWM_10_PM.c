/*******************************************************************************
* File Name: PWM_10_PM.c
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

#include "PWM_10.h"

static PWM_10_backupStruct PWM_10_backup;


/*******************************************************************************
* Function Name: PWM_10_SaveConfig
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
*  PWM_10_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_10_SaveConfig(void) 
{

    #if(!PWM_10_UsingFixedFunction)
        #if(!PWM_10_PWMModeIsCenterAligned)
            PWM_10_backup.PWMPeriod = PWM_10_ReadPeriod();
        #endif /* (!PWM_10_PWMModeIsCenterAligned) */
        PWM_10_backup.PWMUdb = PWM_10_ReadCounter();
        #if (PWM_10_UseStatus)
            PWM_10_backup.InterruptMaskValue = PWM_10_STATUS_MASK;
        #endif /* (PWM_10_UseStatus) */

        #if(PWM_10_DeadBandMode == PWM_10__B_PWM__DBM_256_CLOCKS || \
            PWM_10_DeadBandMode == PWM_10__B_PWM__DBM_2_4_CLOCKS)
            PWM_10_backup.PWMdeadBandValue = PWM_10_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_10_KillModeMinTime)
             PWM_10_backup.PWMKillCounterPeriod = PWM_10_ReadKillTime();
        #endif /* (PWM_10_KillModeMinTime) */

        #if(PWM_10_UseControl)
            PWM_10_backup.PWMControlRegister = PWM_10_ReadControlRegister();
        #endif /* (PWM_10_UseControl) */
    #endif  /* (!PWM_10_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_10_RestoreConfig
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
*  PWM_10_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_10_RestoreConfig(void) 
{
        #if(!PWM_10_UsingFixedFunction)
            #if(!PWM_10_PWMModeIsCenterAligned)
                PWM_10_WritePeriod(PWM_10_backup.PWMPeriod);
            #endif /* (!PWM_10_PWMModeIsCenterAligned) */

            PWM_10_WriteCounter(PWM_10_backup.PWMUdb);

            #if (PWM_10_UseStatus)
                PWM_10_STATUS_MASK = PWM_10_backup.InterruptMaskValue;
            #endif /* (PWM_10_UseStatus) */

            #if(PWM_10_DeadBandMode == PWM_10__B_PWM__DBM_256_CLOCKS || \
                PWM_10_DeadBandMode == PWM_10__B_PWM__DBM_2_4_CLOCKS)
                PWM_10_WriteDeadTime(PWM_10_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_10_KillModeMinTime)
                PWM_10_WriteKillTime(PWM_10_backup.PWMKillCounterPeriod);
            #endif /* (PWM_10_KillModeMinTime) */

            #if(PWM_10_UseControl)
                PWM_10_WriteControlRegister(PWM_10_backup.PWMControlRegister);
            #endif /* (PWM_10_UseControl) */
        #endif  /* (!PWM_10_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_10_Sleep
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
*  PWM_10_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_10_Sleep(void) 
{
    #if(PWM_10_UseControl)
        if(PWM_10_CTRL_ENABLE == (PWM_10_CONTROL & PWM_10_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_10_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_10_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_10_UseControl) */

    /* Stop component */
    PWM_10_Stop();

    /* Save registers configuration */
    PWM_10_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_10_Wakeup
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
*  PWM_10_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_10_Wakeup(void) 
{
     /* Restore registers values */
    PWM_10_RestoreConfig();

    if(PWM_10_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_10_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
