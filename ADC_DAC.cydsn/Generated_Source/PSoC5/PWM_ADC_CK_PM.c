/*******************************************************************************
* File Name: PWM_ADC_CK_PM.c
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

#include "PWM_ADC_CK.h"

static PWM_ADC_CK_backupStruct PWM_ADC_CK_backup;


/*******************************************************************************
* Function Name: PWM_ADC_CK_SaveConfig
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
*  PWM_ADC_CK_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_ADC_CK_SaveConfig(void) 
{

    #if(!PWM_ADC_CK_UsingFixedFunction)
        #if(!PWM_ADC_CK_PWMModeIsCenterAligned)
            PWM_ADC_CK_backup.PWMPeriod = PWM_ADC_CK_ReadPeriod();
        #endif /* (!PWM_ADC_CK_PWMModeIsCenterAligned) */
        PWM_ADC_CK_backup.PWMUdb = PWM_ADC_CK_ReadCounter();
        #if (PWM_ADC_CK_UseStatus)
            PWM_ADC_CK_backup.InterruptMaskValue = PWM_ADC_CK_STATUS_MASK;
        #endif /* (PWM_ADC_CK_UseStatus) */

        #if(PWM_ADC_CK_DeadBandMode == PWM_ADC_CK__B_PWM__DBM_256_CLOCKS || \
            PWM_ADC_CK_DeadBandMode == PWM_ADC_CK__B_PWM__DBM_2_4_CLOCKS)
            PWM_ADC_CK_backup.PWMdeadBandValue = PWM_ADC_CK_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_ADC_CK_KillModeMinTime)
             PWM_ADC_CK_backup.PWMKillCounterPeriod = PWM_ADC_CK_ReadKillTime();
        #endif /* (PWM_ADC_CK_KillModeMinTime) */

        #if(PWM_ADC_CK_UseControl)
            PWM_ADC_CK_backup.PWMControlRegister = PWM_ADC_CK_ReadControlRegister();
        #endif /* (PWM_ADC_CK_UseControl) */
    #endif  /* (!PWM_ADC_CK_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_ADC_CK_RestoreConfig
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
*  PWM_ADC_CK_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_ADC_CK_RestoreConfig(void) 
{
        #if(!PWM_ADC_CK_UsingFixedFunction)
            #if(!PWM_ADC_CK_PWMModeIsCenterAligned)
                PWM_ADC_CK_WritePeriod(PWM_ADC_CK_backup.PWMPeriod);
            #endif /* (!PWM_ADC_CK_PWMModeIsCenterAligned) */

            PWM_ADC_CK_WriteCounter(PWM_ADC_CK_backup.PWMUdb);

            #if (PWM_ADC_CK_UseStatus)
                PWM_ADC_CK_STATUS_MASK = PWM_ADC_CK_backup.InterruptMaskValue;
            #endif /* (PWM_ADC_CK_UseStatus) */

            #if(PWM_ADC_CK_DeadBandMode == PWM_ADC_CK__B_PWM__DBM_256_CLOCKS || \
                PWM_ADC_CK_DeadBandMode == PWM_ADC_CK__B_PWM__DBM_2_4_CLOCKS)
                PWM_ADC_CK_WriteDeadTime(PWM_ADC_CK_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_ADC_CK_KillModeMinTime)
                PWM_ADC_CK_WriteKillTime(PWM_ADC_CK_backup.PWMKillCounterPeriod);
            #endif /* (PWM_ADC_CK_KillModeMinTime) */

            #if(PWM_ADC_CK_UseControl)
                PWM_ADC_CK_WriteControlRegister(PWM_ADC_CK_backup.PWMControlRegister);
            #endif /* (PWM_ADC_CK_UseControl) */
        #endif  /* (!PWM_ADC_CK_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_ADC_CK_Sleep
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
*  PWM_ADC_CK_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_ADC_CK_Sleep(void) 
{
    #if(PWM_ADC_CK_UseControl)
        if(PWM_ADC_CK_CTRL_ENABLE == (PWM_ADC_CK_CONTROL & PWM_ADC_CK_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_ADC_CK_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_ADC_CK_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_ADC_CK_UseControl) */

    /* Stop component */
    PWM_ADC_CK_Stop();

    /* Save registers configuration */
    PWM_ADC_CK_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_ADC_CK_Wakeup
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
*  PWM_ADC_CK_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_ADC_CK_Wakeup(void) 
{
     /* Restore registers values */
    PWM_ADC_CK_RestoreConfig();

    if(PWM_ADC_CK_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_ADC_CK_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
