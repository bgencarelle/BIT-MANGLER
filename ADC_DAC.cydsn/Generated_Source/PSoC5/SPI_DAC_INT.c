/*******************************************************************************
* File Name: SPI_DAC_INT.c
* Version 2.50
*
* Description:
*  This file provides all Interrupt Service Routine (ISR) for the SPI Master
*  component.
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "SPI_DAC_PVT.h"
#include "cyapicallbacks.h"

/* User code required at start of ISR */
/* `#START SPI_DAC_ISR_START_DEF` */

/* `#END` */


/*******************************************************************************
* Function Name: SPI_DAC_TX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for TX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_DAC_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPI_DAC_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified when exist data to
*  sending and FIFO Not Full.
*  SPI_DAC_txBuffer[SPI_DAC_TX_BUFFER_SIZE] - used to store
*  data to sending.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPI_DAC_TX_ISR)
{
    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPI_DAC_TX_ISR_ENTRY_CALLBACK
        SPI_DAC_TX_ISR_EntryCallback();
    #endif /* SPI_DAC_TX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPI_DAC_TX_ISR_START` */

    /* `#END` */
    
    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
        /* Check if TX data buffer is not empty and there is space in TX FIFO */
        while(SPI_DAC_txBufferRead != SPI_DAC_txBufferWrite)
        {
            tmpStatus = SPI_DAC_GET_STATUS_TX(SPI_DAC_swStatusTx);
            SPI_DAC_swStatusTx = tmpStatus;

            if(0u != (SPI_DAC_swStatusTx & SPI_DAC_STS_TX_FIFO_NOT_FULL))
            {
                if(0u == SPI_DAC_txBufferFull)
                {
                   SPI_DAC_txBufferRead++;

                    if(SPI_DAC_txBufferRead >= SPI_DAC_TX_BUFFER_SIZE)
                    {
                        SPI_DAC_txBufferRead = 0u;
                    }
                }
                else
                {
                    SPI_DAC_txBufferFull = 0u;
                }

                /* Put data element into the TX FIFO */
                CY_SET_REG16(SPI_DAC_TXDATA_PTR, 
                                             SPI_DAC_txBuffer[SPI_DAC_txBufferRead]);
            }
            else
            {
                break;
            }
        }

        if(SPI_DAC_txBufferRead == SPI_DAC_txBufferWrite)
        {
            /* TX Buffer is EMPTY: disable interrupt on TX NOT FULL */
            SPI_DAC_TX_STATUS_MASK_REG &= ((uint8) ~SPI_DAC_STS_TX_FIFO_NOT_FULL);
        }

    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPI_DAC_TX_ISR_END` */

    /* `#END` */
    
    #ifdef SPI_DAC_TX_ISR_EXIT_CALLBACK
        SPI_DAC_TX_ISR_ExitCallback();
    #endif /* SPI_DAC_TX_ISR_EXIT_CALLBACK */
}


/*******************************************************************************
* Function Name: SPI_DAC_RX_ISR
********************************************************************************
*
* Summary:
*  Interrupt Service Routine for RX portion of the SPI Master.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_DAC_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer modified when FIFO contains
*  new data.
*  SPI_DAC_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified when overflow occurred.
*  SPI_DAC_rxBuffer[SPI_DAC_RX_BUFFER_SIZE] - used to store
*  received data, modified when FIFO contains new data.
*  All described above Global variables are used when Software Buffer is used.
*
*******************************************************************************/
CY_ISR(SPI_DAC_RX_ISR)
{
    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)
        uint8 tmpStatus;
        uint16 rxData;
    #endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

    #ifdef SPI_DAC_RX_ISR_ENTRY_CALLBACK
        SPI_DAC_RX_ISR_EntryCallback();
    #endif /* SPI_DAC_RX_ISR_ENTRY_CALLBACK */

    /* User code required at start of ISR */
    /* `#START SPI_DAC_RX_ISR_START` */

    /* `#END` */
    
    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)

        tmpStatus = SPI_DAC_GET_STATUS_RX(SPI_DAC_swStatusRx);
        SPI_DAC_swStatusRx = tmpStatus;

        /* Check if RX data FIFO has some data to be moved into the RX Buffer */
        while(0u != (SPI_DAC_swStatusRx & SPI_DAC_STS_RX_FIFO_NOT_EMPTY))
        {
            rxData = CY_GET_REG16(SPI_DAC_RXDATA_PTR);

            /* Set next pointer. */
            SPI_DAC_rxBufferWrite++;
            if(SPI_DAC_rxBufferWrite >= SPI_DAC_RX_BUFFER_SIZE)
            {
                SPI_DAC_rxBufferWrite = 0u;
            }

            if(SPI_DAC_rxBufferWrite == SPI_DAC_rxBufferRead)
            {
                SPI_DAC_rxBufferRead++;
                if(SPI_DAC_rxBufferRead >= SPI_DAC_RX_BUFFER_SIZE)
                {
                    SPI_DAC_rxBufferRead = 0u;
                }

                SPI_DAC_rxBufferFull = 1u;
            }

            /* Move data from the FIFO to the Buffer */
            SPI_DAC_rxBuffer[SPI_DAC_rxBufferWrite] = rxData;

            tmpStatus = SPI_DAC_GET_STATUS_RX(SPI_DAC_swStatusRx);
            SPI_DAC_swStatusRx = tmpStatus;
        }

    #endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

    /* User code required at end of ISR (Optional) */
    /* `#START SPI_DAC_RX_ISR_END` */

    /* `#END` */
    
    #ifdef SPI_DAC_RX_ISR_EXIT_CALLBACK
        SPI_DAC_RX_ISR_ExitCallback();
    #endif /* SPI_DAC_RX_ISR_EXIT_CALLBACK */
}

/* [] END OF FILE */
