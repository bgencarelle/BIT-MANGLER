/*******************************************************************************
* File Name: DVDAC.c  
* Version 1.90
*
* Description:
*  This file provides the source code to the API for the 8-bit Voltage DAC 
*  (VDAC8) User Module.
*
* Note:
*  Any unusual or non-standard behavior should be noted here. Other-
*  wise, this section should remain blank.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "DVDAC.h"

#if (CY_PSOC5A)
#include <CyLib.h>
#endif /* CY_PSOC5A */

uint8 DVDAC_initVar = 0u;

#if (CY_PSOC5A)
    static uint8 DVDAC_restoreVal = 0u;
#endif /* CY_PSOC5A */

#if (CY_PSOC5A)
    static DVDAC_backupStruct DVDAC_backup;
#endif /* CY_PSOC5A */


/*******************************************************************************
* Function Name: DVDAC_Init
********************************************************************************
* Summary:
*  Initialize to the schematic state.
* 
* Parameters:
*  void:
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_Init(void) 
{
    DVDAC_CR0 = (DVDAC_MODE_V );

    /* Set default data source */
    #if(DVDAC_DEFAULT_DATA_SRC != 0 )
        DVDAC_CR1 = (DVDAC_DEFAULT_CNTL | DVDAC_DACBUS_ENABLE) ;
    #else
        DVDAC_CR1 = (DVDAC_DEFAULT_CNTL | DVDAC_DACBUS_DISABLE) ;
    #endif /* (DVDAC_DEFAULT_DATA_SRC != 0 ) */

    /* Set default strobe mode */
    #if(DVDAC_DEFAULT_STRB != 0)
        DVDAC_Strobe |= DVDAC_STRB_EN ;
    #endif/* (DVDAC_DEFAULT_STRB != 0) */

    /* Set default range */
    DVDAC_SetRange(DVDAC_DEFAULT_RANGE); 

    /* Set default speed */
    DVDAC_SetSpeed(DVDAC_DEFAULT_SPEED);
}


/*******************************************************************************
* Function Name: DVDAC_Enable
********************************************************************************
* Summary:
*  Enable the VDAC8
* 
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_Enable(void) 
{
    DVDAC_PWRMGR |= DVDAC_ACT_PWR_EN;
    DVDAC_STBY_PWRMGR |= DVDAC_STBY_PWR_EN;

    /*This is to restore the value of register CR0 ,
    which is modified  in Stop API , this prevents misbehaviour of VDAC */
    #if (CY_PSOC5A)
        if(DVDAC_restoreVal == 1u) 
        {
             DVDAC_CR0 = DVDAC_backup.data_value;
             DVDAC_restoreVal = 0u;
        }
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: DVDAC_Start
********************************************************************************
*
* Summary:
*  The start function initializes the voltage DAC with the default values, 
*  and sets the power to the given level.  A power level of 0, is the same as
*  executing the stop function.
*
* Parameters:
*  Power: Sets power level between off (0) and (3) high power
*
* Return:
*  void 
*
* Global variables:
*  DVDAC_initVar: Is modified when this function is called for the 
*  first time. Is used to ensure that initialization happens only once.
*
*******************************************************************************/
void DVDAC_Start(void)  
{
    /* Hardware initiazation only needs to occure the first time */
    if(DVDAC_initVar == 0u)
    { 
        DVDAC_Init();
        DVDAC_initVar = 1u;
    }

    /* Enable power to DAC */
    DVDAC_Enable();

    /* Set default value */
    DVDAC_SetValue(DVDAC_DEFAULT_DATA); 
}


/*******************************************************************************
* Function Name: DVDAC_Stop
********************************************************************************
*
* Summary:
*  Powers down DAC to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_Stop(void) 
{
    /* Disble power to DAC */
    DVDAC_PWRMGR &= (uint8)(~DVDAC_ACT_PWR_EN);
    DVDAC_STBY_PWRMGR &= (uint8)(~DVDAC_STBY_PWR_EN);

    /* This is a work around for PSoC5A  ,
    this sets VDAC to current mode with output off */
    #if (CY_PSOC5A)
        DVDAC_backup.data_value = DVDAC_CR0;
        DVDAC_CR0 = DVDAC_CUR_MODE_OUT_OFF;
        DVDAC_restoreVal = 1u;
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: DVDAC_SetSpeed
********************************************************************************
*
* Summary:
*  Set DAC speed
*
* Parameters:
*  power: Sets speed value
*
* Return:
*  void
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_SetSpeed(uint8 speed) 
{
    /* Clear power mask then write in new value */
    DVDAC_CR0 &= (uint8)(~DVDAC_HS_MASK);
    DVDAC_CR0 |=  (speed & DVDAC_HS_MASK);
}


/*******************************************************************************
* Function Name: DVDAC_SetRange
********************************************************************************
*
* Summary:
*  Set one of three current ranges.
*
* Parameters:
*  Range: Sets one of Three valid ranges.
*
* Return:
*  void 
*
* Theory:
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_SetRange(uint8 range) 
{
    DVDAC_CR0 &= (uint8)(~DVDAC_RANGE_MASK);      /* Clear existing mode */
    DVDAC_CR0 |= (range & DVDAC_RANGE_MASK);      /*  Set Range  */
    DVDAC_DacTrim();
}


/*******************************************************************************
* Function Name: DVDAC_SetValue
********************************************************************************
*
* Summary:
*  Set 8-bit DAC value
*
* Parameters:  
*  value:  Sets DAC value between 0 and 255.
*
* Return: 
*  void 
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_SetValue(uint8 value) 
{
    #if (CY_PSOC5A)
        uint8 DVDAC_intrStatus = CyEnterCriticalSection();
    #endif /* CY_PSOC5A */

    DVDAC_Data = value;                /*  Set Value  */

    /* PSOC5A requires a double write */
    /* Exit Critical Section */
    #if (CY_PSOC5A)
        DVDAC_Data = value;
        CyExitCriticalSection(DVDAC_intrStatus);
    #endif /* CY_PSOC5A */
}


/*******************************************************************************
* Function Name: DVDAC_DacTrim
********************************************************************************
*
* Summary:
*  Set the trim value for the given range.
*
* Parameters:
*  range:  1V or 4V range.  See constants.
*
* Return:
*  void
*
* Theory: 
*
* Side Effects:
*
*******************************************************************************/
void DVDAC_DacTrim(void) 
{
    uint8 mode;

    mode = (uint8)((DVDAC_CR0 & DVDAC_RANGE_MASK) >> 2) + DVDAC_TRIM_M7_1V_RNG_OFFSET;
    DVDAC_TR = CY_GET_XTND_REG8((uint8 *)(DVDAC_DAC_TRIM_BASE + mode));
}


/* [] END OF FILE */
