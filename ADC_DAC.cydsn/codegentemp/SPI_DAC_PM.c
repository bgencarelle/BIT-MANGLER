/*******************************************************************************
* File Name: SPI_DAC_PM.c
* Version 2.50
*
* Description:
*  This file contains the setup, control and status commands to support
*  component operations in low power mode.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_DAC_PVT.h"

static SPI_DAC_BACKUP_STRUCT SPI_DAC_backup =
{
    SPI_DAC_DISABLED,
    SPI_DAC_BITCTR_INIT,
};


/*******************************************************************************
* Function Name: SPI_DAC_SaveConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_DAC_SaveConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPI_DAC_RestoreConfig
********************************************************************************
*
* Summary:
*  Empty function. Included for consistency with other components.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_DAC_RestoreConfig(void) 
{

}


/*******************************************************************************
* Function Name: SPI_DAC_Sleep
********************************************************************************
*
* Summary:
*  Prepare SPIM Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_DAC_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_Sleep(void) 
{
    /* Save components enable state */
    SPI_DAC_backup.enableState = ((uint8) SPI_DAC_IS_ENABLED);

    SPI_DAC_Stop();
}


/*******************************************************************************
* Function Name: SPI_DAC_Wakeup
********************************************************************************
*
* Summary:
*  Prepare SPIM Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  SPI_DAC_backup - used when non-retention registers are restored.
*  SPI_DAC_txBufferWrite - modified every function call - resets to
*  zero.
*  SPI_DAC_txBufferRead - modified every function call - resets to
*  zero.
*  SPI_DAC_rxBufferWrite - modified every function call - resets to
*  zero.
*  SPI_DAC_rxBufferRead - modified every function call - resets to
*  zero.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_Wakeup(void) 
{
    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)
        SPI_DAC_rxBufferFull  = 0u;
        SPI_DAC_rxBufferRead  = 0u;
        SPI_DAC_rxBufferWrite = 0u;
    #endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
        SPI_DAC_txBufferFull  = 0u;
        SPI_DAC_txBufferRead  = 0u;
        SPI_DAC_txBufferWrite = 0u;
    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

    /* Clear any data from the RX and TX FIFO */
    SPI_DAC_ClearFIFO();

    /* Restore components block enable state */
    if(0u != SPI_DAC_backup.enableState)
    {
        SPI_DAC_Enable();
    }
}


/* [] END OF FILE */
