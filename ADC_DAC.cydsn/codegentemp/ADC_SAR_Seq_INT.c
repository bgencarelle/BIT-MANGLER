/*******************************************************************************
* File Name: ADC_SAR_Seq_INT.c
* Version 2.0
*
*  Description:
*    This file contains the code that operates during the interrupt
*    service routine.
*
*   Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "ADC_SAR_Seq.h"
#include "cyapicallbacks.h"


/******************************************************************************
* Custom Declarations and Variables
* - add user inlcude files, prototypes and variables between the following
*   #START and #END tags
******************************************************************************/
/* `#START SEQ_ADC_SYS_VAR`  */
extern uint16 SAR_ADCResultArray[ADC_SAR_Seq_NUMBER_OF_CHANNELS];
extern uint8 seq_sar_dataReady;  
uint8 chan = 0;
/* `#END`  */

#if(ADC_SAR_Seq_IRQ_REMOVE == 0u)


    /******************************************************************************
    * Function Name: ADC_SAR_Seq_ISR
    *******************************************************************************
    *
    * Summary:
    *  Handle Interrupt Service Routine.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Reentrant:
    *  No.
    *
    ******************************************************************************/
    CY_ISR( ADC_SAR_Seq_ISR )
    {
        #ifdef ADC_SAR_Seq_ISR_INTERRUPT_CALLBACK
            ADC_SAR_Seq_ISR_InterruptCallback();
        #endif /* ADC_SAR_Seq_ISR_INTERRUPT_CALLBACK */
        
        
        /************************************************************************
        *  Custom Code
        *  - add user ISR code between the following #START and #END tags
        *************************************************************************/
          /* `#START MAIN_SEQ_ADC_ISR`  */
			for(chan = 0; chan < ADC_SAR_Seq_NUMBER_OF_CHANNELS; chan++)
            {
				SAR_ADCResultArray[ADC_SAR_Seq_NUMBER_OF_CHANNELS - chan -1] = ADC_SAR_Seq_GetResult16(chan);
            }
            seq_sar_dataReady = 1;
        
          /* `#END`  */
    }

#endif   /* End ADC_SAR_Seq_IRQ_REMOVE */

/* [] END OF FILE */
