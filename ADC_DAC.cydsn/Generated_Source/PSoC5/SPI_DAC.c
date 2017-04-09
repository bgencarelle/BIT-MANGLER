/*******************************************************************************
* File Name: SPI_DAC.c
* Version 2.50
*
* Description:
*  This file provides all API functionality of the SPI Master component.
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

#if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
    volatile uint16 SPI_DAC_txBuffer[SPI_DAC_TX_BUFFER_SIZE];
    volatile uint8 SPI_DAC_txBufferFull;
    volatile uint8 SPI_DAC_txBufferRead;
    volatile uint8 SPI_DAC_txBufferWrite;
#endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

#if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)
    volatile uint16 SPI_DAC_rxBuffer[SPI_DAC_RX_BUFFER_SIZE];
    volatile uint8 SPI_DAC_rxBufferFull;
    volatile uint8 SPI_DAC_rxBufferRead;
    volatile uint8 SPI_DAC_rxBufferWrite;
#endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

uint8 SPI_DAC_initVar = 0u;

volatile uint8 SPI_DAC_swStatusTx;
volatile uint8 SPI_DAC_swStatusRx;


/*******************************************************************************
* Function Name: SPI_DAC_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default SPIM configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  When this function is called it initializes all of the necessary parameters
*  for execution. i.e. setting the initial interrupt mask, configuring the
*  interrupt service routine, configuring the bit-counter parameters and
*  clearing the FIFO and Status Register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_Init(void) 
{
    /* Initialize the Bit counter */
    SPI_DAC_COUNTER_PERIOD_REG = SPI_DAC_BITCTR_INIT;

    /* Init TX ISR  */
    #if(0u != SPI_DAC_INTERNAL_TX_INT_ENABLED)
        CyIntDisable         (SPI_DAC_TX_ISR_NUMBER);
        CyIntSetPriority     (SPI_DAC_TX_ISR_NUMBER,  SPI_DAC_TX_ISR_PRIORITY);
        (void) CyIntSetVector(SPI_DAC_TX_ISR_NUMBER, &SPI_DAC_TX_ISR);
    #endif /* (0u != SPI_DAC_INTERNAL_TX_INT_ENABLED) */

    /* Init RX ISR  */
    #if(0u != SPI_DAC_INTERNAL_RX_INT_ENABLED)
        CyIntDisable         (SPI_DAC_RX_ISR_NUMBER);
        CyIntSetPriority     (SPI_DAC_RX_ISR_NUMBER,  SPI_DAC_RX_ISR_PRIORITY);
        (void) CyIntSetVector(SPI_DAC_RX_ISR_NUMBER, &SPI_DAC_RX_ISR);
    #endif /* (0u != SPI_DAC_INTERNAL_RX_INT_ENABLED) */

    /* Clear any stray data from the RX and TX FIFO */
    SPI_DAC_ClearFIFO();

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

    (void) SPI_DAC_ReadTxStatus(); /* Clear Tx status and swStatusTx */
    (void) SPI_DAC_ReadRxStatus(); /* Clear Rx status and swStatusRx */

    /* Configure TX and RX interrupt mask */
    SPI_DAC_TX_STATUS_MASK_REG = SPI_DAC_TX_INIT_INTERRUPTS_MASK;
    SPI_DAC_RX_STATUS_MASK_REG = SPI_DAC_RX_INIT_INTERRUPTS_MASK;
}


/*******************************************************************************
* Function Name: SPI_DAC_Enable
********************************************************************************
*
* Summary:
*  Enable SPIM component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SPI_DAC_Enable(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPI_DAC_COUNTER_CONTROL_REG |= SPI_DAC_CNTR_ENABLE;
    SPI_DAC_TX_STATUS_ACTL_REG  |= SPI_DAC_INT_ENABLE;
    SPI_DAC_RX_STATUS_ACTL_REG  |= SPI_DAC_INT_ENABLE;
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPI_DAC_INTERNAL_CLOCK)
        SPI_DAC_IntClock_Enable();
    #endif /* (0u != SPI_DAC_INTERNAL_CLOCK) */

    SPI_DAC_EnableTxInt();
    SPI_DAC_EnableRxInt();
}


/*******************************************************************************
* Function Name: SPI_DAC_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_DAC_initVar - used to check initial configuration, modified on
*  first function call.
*
* Theory:
*  Enable the clock input to enable operation.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_Start(void) 
{
    if(0u == SPI_DAC_initVar)
    {
        SPI_DAC_Init();
        SPI_DAC_initVar = 1u;
    }

    SPI_DAC_Enable();
}


/*******************************************************************************
* Function Name: SPI_DAC_Stop
********************************************************************************
*
* Summary:
*  Disable the SPI Master component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the clock input to enable operation.
*
*******************************************************************************/
void SPI_DAC_Stop(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    SPI_DAC_TX_STATUS_ACTL_REG &= ((uint8) ~SPI_DAC_INT_ENABLE);
    SPI_DAC_RX_STATUS_ACTL_REG &= ((uint8) ~SPI_DAC_INT_ENABLE);
    CyExitCriticalSection(enableInterrupts);

    #if(0u != SPI_DAC_INTERNAL_CLOCK)
        SPI_DAC_IntClock_Disable();
    #endif /* (0u != SPI_DAC_INTERNAL_CLOCK) */

    SPI_DAC_DisableTxInt();
    SPI_DAC_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPI_DAC_EnableTxInt
********************************************************************************
*
* Summary:
*  Enable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPI_DAC_EnableTxInt(void) 
{
    #if(0u != SPI_DAC_INTERNAL_TX_INT_ENABLED)
        CyIntEnable(SPI_DAC_TX_ISR_NUMBER);
    #endif /* (0u != SPI_DAC_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPI_DAC_EnableRxInt
********************************************************************************
*
* Summary:
*  Enable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPI_DAC_EnableRxInt(void) 
{
    #if(0u != SPI_DAC_INTERNAL_RX_INT_ENABLED)
        CyIntEnable(SPI_DAC_RX_ISR_NUMBER);
    #endif /* (0u != SPI_DAC_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPI_DAC_DisableTxInt
********************************************************************************
*
* Summary:
*  Disable internal Tx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Tx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPI_DAC_DisableTxInt(void) 
{
    #if(0u != SPI_DAC_INTERNAL_TX_INT_ENABLED)
        CyIntDisable(SPI_DAC_TX_ISR_NUMBER);
    #endif /* (0u != SPI_DAC_INTERNAL_TX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPI_DAC_DisableRxInt
********************************************************************************
*
* Summary:
*  Disable internal Rx interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal Rx interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPI_DAC_DisableRxInt(void) 
{
    #if(0u != SPI_DAC_INTERNAL_RX_INT_ENABLED)
        CyIntDisable(SPI_DAC_RX_ISR_NUMBER);
    #endif /* (0u != SPI_DAC_INTERNAL_RX_INT_ENABLED) */
}


/*******************************************************************************
* Function Name: SPI_DAC_SetTxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPI_DAC_SetTxInterruptMode(uint8 intSrc) 
{
    SPI_DAC_TX_STATUS_MASK_REG = intSrc;
}


/*******************************************************************************
* Function Name: SPI_DAC_SetRxInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPI_DAC_SetRxInterruptMode(uint8 intSrc) 
{
    SPI_DAC_RX_STATUS_MASK_REG  = intSrc;
}


/*******************************************************************************
* Function Name: SPI_DAC_ReadTxStatus
********************************************************************************
*
* Summary:
*  Read the Tx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Tx status register.
*
* Global variables:
*  SPI_DAC_swStatusTx - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Tx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPI_DAC_ReadTxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPI_DAC_DisableTxInt();

        tmpStatus = SPI_DAC_GET_STATUS_TX(SPI_DAC_swStatusTx);
        SPI_DAC_swStatusTx = 0u;

        SPI_DAC_EnableTxInt();

    #else

        tmpStatus = SPI_DAC_TX_STATUS_REG;

    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPI_DAC_ReadRxStatus
********************************************************************************
*
* Summary:
*  Read the Rx status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the Rx status register.
*
* Global variables:
*  SPI_DAC_swStatusRx - used to store in software Rx status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the Rx status register for error
*  detection and flow control.
*
* Side Effects:
*  Clear Rx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPI_DAC_ReadRxStatus(void) 
{
    uint8 tmpStatus;

    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPI_DAC_DisableRxInt();

        tmpStatus = SPI_DAC_GET_STATUS_RX(SPI_DAC_swStatusRx);
        SPI_DAC_swStatusRx = 0u;

        SPI_DAC_EnableRxInt();

    #else

        tmpStatus = SPI_DAC_RX_STATUS_REG;

    #endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/*******************************************************************************
* Function Name: SPI_DAC_WriteTxData
********************************************************************************
*
* Summary:
*  Write a byte of data to be sent across the SPI.
*
* Parameters:
*  txDataByte: The data value to send across the SPI.
*
* Return:
*  None.
*
* Global variables:
*  SPI_DAC_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call if TX Software Buffer is used.
*  SPI_DAC_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*  SPI_DAC_txBuffer[SPI_DAC_TX_BUFFER_SIZE] - used to store
*  data to sending, modified every function call if TX Software Buffer is used.
*
* Theory:
*  Allows the user to transmit any byte of data in a single transfer.
*
* Side Effects:
*  If this function is called again before the previous byte is finished then
*  the next byte will be appended to the transfer with no time between
*  the byte transfers. Clear Tx status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_WriteTxData(uint16 txData) 
{
    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)

        uint8 tempStatus;
        uint8 tmpTxBufferRead;

        /* Block if TX buffer is FULL: don't overwrite */
        do
        {
            tmpTxBufferRead = SPI_DAC_txBufferRead;
            if(0u == tmpTxBufferRead)
            {
                tmpTxBufferRead = (SPI_DAC_TX_BUFFER_SIZE - 1u);
            }
            else
            {
                tmpTxBufferRead--;
            }

        }while(tmpTxBufferRead == SPI_DAC_txBufferWrite);

        /* Disable TX interrupt to protect global veriables */
        SPI_DAC_DisableTxInt();

        tempStatus = SPI_DAC_GET_STATUS_TX(SPI_DAC_swStatusTx);
        SPI_DAC_swStatusTx = tempStatus;


        if((SPI_DAC_txBufferRead == SPI_DAC_txBufferWrite) &&
           (0u != (SPI_DAC_swStatusTx & SPI_DAC_STS_TX_FIFO_NOT_FULL)))
        {
            /* Put data element into the TX FIFO */
            CY_SET_REG16(SPI_DAC_TXDATA_PTR, txData);
        }
        else
        {
            /* Add to the TX software buffer */
            SPI_DAC_txBufferWrite++;
            if(SPI_DAC_txBufferWrite >= SPI_DAC_TX_BUFFER_SIZE)
            {
                SPI_DAC_txBufferWrite = 0u;
            }

            if(SPI_DAC_txBufferWrite == SPI_DAC_txBufferRead)
            {
                SPI_DAC_txBufferRead++;
                if(SPI_DAC_txBufferRead >= SPI_DAC_TX_BUFFER_SIZE)
                {
                    SPI_DAC_txBufferRead = 0u;
                }
                SPI_DAC_txBufferFull = 1u;
            }

            SPI_DAC_txBuffer[SPI_DAC_txBufferWrite] = txData;

            SPI_DAC_TX_STATUS_MASK_REG |= SPI_DAC_STS_TX_FIFO_NOT_FULL;
        }

        SPI_DAC_EnableTxInt();

    #else
        /* Wait until TX FIFO has a place */
        while(0u == (SPI_DAC_TX_STATUS_REG & SPI_DAC_STS_TX_FIFO_NOT_FULL))
        {
        }

        /* Put data element into the TX FIFO */
        CY_SET_REG16(SPI_DAC_TXDATA_PTR, txData);

    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPI_DAC_ReadRxData
********************************************************************************
*
* Summary:
*  Read the next byte of data received across the SPI.
*
* Parameters:
*  None.
*
* Return:
*  The next byte of data read from the FIFO.
*
* Global variables:
*  SPI_DAC_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPI_DAC_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function
*  call if RX Software Buffer is used.
*  SPI_DAC_rxBuffer[SPI_DAC_RX_BUFFER_SIZE] - used to store
*  received data.
*
* Theory:
*  Allows the user to read a byte of data received.
*
* Side Effects:
*  Will return invalid data if the FIFO is empty. The user should Call
*  GetRxBufferSize() and if it returns a non-zero value then it is safe to call
*  ReadByte() function.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint16 SPI_DAC_ReadRxData(void) 
{
    uint16 rxData;

    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPI_DAC_DisableRxInt();

        if(SPI_DAC_rxBufferRead != SPI_DAC_rxBufferWrite)
        {
            if(0u == SPI_DAC_rxBufferFull)
            {
                SPI_DAC_rxBufferRead++;
                if(SPI_DAC_rxBufferRead >= SPI_DAC_RX_BUFFER_SIZE)
                {
                    SPI_DAC_rxBufferRead = 0u;
                }
            }
            else
            {
                SPI_DAC_rxBufferFull = 0u;
            }
        }

        rxData = SPI_DAC_rxBuffer[SPI_DAC_rxBufferRead];

        SPI_DAC_EnableRxInt();

    #else

        rxData = CY_GET_REG16(SPI_DAC_RXDATA_PTR);

    #endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

    return(rxData);
}


/*******************************************************************************
* Function Name: SPI_DAC_GetRxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the RX buffer.
*  If RX Software Buffer not used then function return 0 if FIFO empty or 1 if
*  FIFO not empty. In another case function return size of RX Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the RX buffer.
*
* Global variables:
*  SPI_DAC_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer.
*  SPI_DAC_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8 SPI_DAC_GetRxBufferSize(void) 
{
    uint8 size;

    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)

        /* Disable RX interrupt to protect global veriables */
        SPI_DAC_DisableRxInt();

        if(SPI_DAC_rxBufferRead == SPI_DAC_rxBufferWrite)
        {
            size = 0u;
        }
        else if(SPI_DAC_rxBufferRead < SPI_DAC_rxBufferWrite)
        {
            size = (SPI_DAC_rxBufferWrite - SPI_DAC_rxBufferRead);
        }
        else
        {
            size = (SPI_DAC_RX_BUFFER_SIZE - SPI_DAC_rxBufferRead) + SPI_DAC_rxBufferWrite;
        }

        SPI_DAC_EnableRxInt();

    #else

        /* We can only know if there is data in the RX FIFO */
        size = (0u != (SPI_DAC_RX_STATUS_REG & SPI_DAC_STS_RX_FIFO_NOT_EMPTY)) ? 1u : 0u;

    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPI_DAC_GetTxBufferSize
********************************************************************************
*
* Summary:
*  Returns the number of bytes/words of data currently held in the TX buffer.
*  If TX Software Buffer not used then function return 0 - if FIFO empty, 1 - if
*  FIFO not full, 4 - if FIFO full. In another case function return size of TX
*  Software Buffer.
*
* Parameters:
*  None.
*
* Return:
*  Integer count of the number of bytes/words in the TX buffer.
*
* Global variables:
*  SPI_DAC_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer.
*  SPI_DAC_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
uint8  SPI_DAC_GetTxBufferSize(void) 
{
    uint8 size;

    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPI_DAC_DisableTxInt();

        if(SPI_DAC_txBufferRead == SPI_DAC_txBufferWrite)
        {
            size = 0u;
        }
        else if(SPI_DAC_txBufferRead < SPI_DAC_txBufferWrite)
        {
            size = (SPI_DAC_txBufferWrite - SPI_DAC_txBufferRead);
        }
        else
        {
            size = (SPI_DAC_TX_BUFFER_SIZE - SPI_DAC_txBufferRead) + SPI_DAC_txBufferWrite;
        }

        SPI_DAC_EnableTxInt();

    #else

        size = SPI_DAC_TX_STATUS_REG;

        if(0u != (size & SPI_DAC_STS_TX_FIFO_EMPTY))
        {
            size = 0u;
        }
        else if(0u != (size & SPI_DAC_STS_TX_FIFO_NOT_FULL))
        {
            size = 1u;
        }
        else
        {
            size = SPI_DAC_FIFO_SIZE;
        }

    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */

    return(size);
}


/*******************************************************************************
* Function Name: SPI_DAC_ClearRxBuffer
********************************************************************************
*
* Summary:
*  Clear the RX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_DAC_rxBufferWrite - used for the account of the bytes which
*  have been written down in the RX software buffer, modified every function
*  call - resets to zero.
*  SPI_DAC_rxBufferRead - used for the account of the bytes which
*  have been read from the RX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any received data not read from the RAM buffer will be lost when overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_ClearRxBuffer(void) 
{
    /* Clear Hardware RX FIFO */
    while(0u !=(SPI_DAC_RX_STATUS_REG & SPI_DAC_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(SPI_DAC_RXDATA_PTR);
    }

    #if(SPI_DAC_RX_SOFTWARE_BUF_ENABLED)
        /* Disable RX interrupt to protect global veriables */
        SPI_DAC_DisableRxInt();

        SPI_DAC_rxBufferFull  = 0u;
        SPI_DAC_rxBufferRead  = 0u;
        SPI_DAC_rxBufferWrite = 0u;

        SPI_DAC_EnableRxInt();
    #endif /* (SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */
}


/*******************************************************************************
* Function Name: SPI_DAC_ClearTxBuffer
********************************************************************************
*
* Summary:
*  Clear the TX RAM buffer by setting the read and write pointers both to zero.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  SPI_DAC_txBufferWrite - used for the account of the bytes which
*  have been written down in the TX software buffer, modified every function
*  call - resets to zero.
*  SPI_DAC_txBufferRead - used for the account of the bytes which
*  have been read from the TX software buffer, modified every function call -
*  resets to zero.
*
* Theory:
*  Setting the pointers to zero makes the system believe there is no data to
*  read and writing will resume at address 0 overwriting any data that may have
*  remained in the RAM.
*
* Side Effects:
*  Any data not yet transmitted from the RAM buffer will be lost when
*  overwritten.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_ClearTxBuffer(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPI_DAC_AUX_CONTROL_DP0_REG |= ((uint8)  SPI_DAC_TX_FIFO_CLR);
    SPI_DAC_AUX_CONTROL_DP0_REG &= ((uint8) ~SPI_DAC_TX_FIFO_CLR);

    #if(SPI_DAC_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPI_DAC_AUX_CONTROL_DP1_REG |= ((uint8)  SPI_DAC_TX_FIFO_CLR);
        SPI_DAC_AUX_CONTROL_DP1_REG &= ((uint8) ~SPI_DAC_TX_FIFO_CLR);
    #endif /* (SPI_DAC_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);

    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED)
        /* Disable TX interrupt to protect global veriables */
        SPI_DAC_DisableTxInt();

        SPI_DAC_txBufferFull  = 0u;
        SPI_DAC_txBufferRead  = 0u;
        SPI_DAC_txBufferWrite = 0u;

        /* Buffer is EMPTY: disable TX FIFO NOT FULL interrupt */
        SPI_DAC_TX_STATUS_MASK_REG &= ((uint8) ~SPI_DAC_STS_TX_FIFO_NOT_FULL);

        SPI_DAC_EnableTxInt();
    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED) */
}


#if(0u != SPI_DAC_BIDIRECTIONAL_MODE)
    /*******************************************************************************
    * Function Name: SPI_DAC_TxEnable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to transmit.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPI_DAC_TxEnable(void) 
    {
        SPI_DAC_CONTROL_REG |= SPI_DAC_CTRL_TX_SIGNAL_EN;
    }


    /*******************************************************************************
    * Function Name: SPI_DAC_TxDisable
    ********************************************************************************
    *
    * Summary:
    *  If the SPI master is configured to use a single bi-directional pin then this
    *  will set the bi-directional pin to receive.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void SPI_DAC_TxDisable(void) 
    {
        SPI_DAC_CONTROL_REG &= ((uint8) ~SPI_DAC_CTRL_TX_SIGNAL_EN);
    }

#endif /* (0u != SPI_DAC_BIDIRECTIONAL_MODE) */


/*******************************************************************************
* Function Name: SPI_DAC_PutArray
********************************************************************************
*
* Summary:
*  Write available data from ROM/RAM to the TX buffer while space is available
*  in the TX buffer. Keep trying until all data is passed to the TX buffer.
*
* Parameters:
*  *buffer: Pointer to the location in RAM containing the data to send
*  byteCount: The number of bytes to move to the transmit buffer.
*
* Return:
*  None.
*
* Side Effects:
*  Will stay in this routine until all data has been sent.  May get locked in
*  this loop if data is not being initiated by the master if there is not
*  enough room in the TX FIFO.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void SPI_DAC_PutArray(const uint16 buffer[], uint8 byteCount)
                                                                          
{
    uint8 bufIndex;

    bufIndex = 0u;

    while(byteCount > 0u)
    {
        SPI_DAC_WriteTxData(buffer[bufIndex]);
        bufIndex++;
        byteCount--;
    }
}


/*******************************************************************************
* Function Name: SPI_DAC_ClearFIFO
********************************************************************************
*
* Summary:
*  Clear the RX and TX FIFO's of all data for a fresh start.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Side Effects:
*  Clear status register of the component.
*
*******************************************************************************/
void SPI_DAC_ClearFIFO(void) 
{
    uint8 enableInterrupts;

    /* Clear Hardware RX FIFO */
    while(0u !=(SPI_DAC_RX_STATUS_REG & SPI_DAC_STS_RX_FIFO_NOT_EMPTY))
    {
        (void) CY_GET_REG16(SPI_DAC_RXDATA_PTR);
    }

    enableInterrupts = CyEnterCriticalSection();
    /* Clear TX FIFO */
    SPI_DAC_AUX_CONTROL_DP0_REG |= ((uint8)  SPI_DAC_TX_FIFO_CLR);
    SPI_DAC_AUX_CONTROL_DP0_REG &= ((uint8) ~SPI_DAC_TX_FIFO_CLR);

    #if(SPI_DAC_USE_SECOND_DATAPATH)
        /* Clear TX FIFO for 2nd Datapath */
        SPI_DAC_AUX_CONTROL_DP1_REG |= ((uint8)  SPI_DAC_TX_FIFO_CLR);
        SPI_DAC_AUX_CONTROL_DP1_REG &= ((uint8) ~SPI_DAC_TX_FIFO_CLR);
    #endif /* (SPI_DAC_USE_SECOND_DATAPATH) */
    CyExitCriticalSection(enableInterrupts);
}


/* Following functions are for version Compatibility, they are obsolete.
*  Please do not use it in new projects.
*/


/*******************************************************************************
* Function Name: SPI_DAC_EnableInt
********************************************************************************
*
* Summary:
*  Enable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Enable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPI_DAC_EnableInt(void) 
{
    SPI_DAC_EnableRxInt();
    SPI_DAC_EnableTxInt();
}


/*******************************************************************************
* Function Name: SPI_DAC_DisableInt
********************************************************************************
*
* Summary:
*  Disable internal interrupt generation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Theory:
*  Disable the internal interrupt output -or- the interrupt component itself.
*
*******************************************************************************/
void SPI_DAC_DisableInt(void) 
{
    SPI_DAC_DisableTxInt();
    SPI_DAC_DisableRxInt();
}


/*******************************************************************************
* Function Name: SPI_DAC_SetInterruptMode
********************************************************************************
*
* Summary:
*  Configure which status bits trigger an interrupt event.
*
* Parameters:
*  intSrc: An or'd combination of the desired status bit masks (defined in the
*  header file).
*
* Return:
*  None.
*
* Theory:
*  Enables the output of specific status bits to the interrupt controller.
*
*******************************************************************************/
void SPI_DAC_SetInterruptMode(uint8 intSrc) 
{
    SPI_DAC_TX_STATUS_MASK_REG  = (intSrc & ((uint8) ~SPI_DAC_STS_SPI_IDLE));
    SPI_DAC_RX_STATUS_MASK_REG  =  intSrc;
}


/*******************************************************************************
* Function Name: SPI_DAC_ReadStatus
********************************************************************************
*
* Summary:
*  Read the status register for the component.
*
* Parameters:
*  None.
*
* Return:
*  Contents of the status register.
*
* Global variables:
*  SPI_DAC_swStatus - used to store in software status register,
*  modified every function call - resets to zero.
*
* Theory:
*  Allows the user and the API to read the status register for error detection
*  and flow control.
*
* Side Effects:
*  Clear status register of the component.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 SPI_DAC_ReadStatus(void) 
{
    uint8 tmpStatus;

    #if(SPI_DAC_TX_SOFTWARE_BUF_ENABLED || SPI_DAC_RX_SOFTWARE_BUF_ENABLED)

        SPI_DAC_DisableInt();

        tmpStatus  = SPI_DAC_GET_STATUS_RX(SPI_DAC_swStatusRx);
        tmpStatus |= SPI_DAC_GET_STATUS_TX(SPI_DAC_swStatusTx);
        tmpStatus &= ((uint8) ~SPI_DAC_STS_SPI_IDLE);

        SPI_DAC_swStatusTx = 0u;
        SPI_DAC_swStatusRx = 0u;

        SPI_DAC_EnableInt();

    #else

        tmpStatus  = SPI_DAC_RX_STATUS_REG;
        tmpStatus |= SPI_DAC_TX_STATUS_REG;
        tmpStatus &= ((uint8) ~SPI_DAC_STS_SPI_IDLE);

    #endif /* (SPI_DAC_TX_SOFTWARE_BUF_ENABLED || SPI_DAC_RX_SOFTWARE_BUF_ENABLED) */

    return(tmpStatus);
}


/* [] END OF FILE */
