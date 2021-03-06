/*******************************************************************************
* File Name: ADC_1_OUT_MSB_1.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_ADC_1_OUT_MSB_1_H) /* CY_CONTROL_REG_ADC_1_OUT_MSB_1_H */
#define CY_CONTROL_REG_ADC_1_OUT_MSB_1_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} ADC_1_OUT_MSB_1_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    ADC_1_OUT_MSB_1_Write(uint8 control) ;
uint8   ADC_1_OUT_MSB_1_Read(void) ;

void ADC_1_OUT_MSB_1_SaveConfig(void) ;
void ADC_1_OUT_MSB_1_RestoreConfig(void) ;
void ADC_1_OUT_MSB_1_Sleep(void) ; 
void ADC_1_OUT_MSB_1_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define ADC_1_OUT_MSB_1_Control        (* (reg8 *) ADC_1_OUT_MSB_1_Sync_ctrl_reg__CONTROL_REG )
#define ADC_1_OUT_MSB_1_Control_PTR    (  (reg8 *) ADC_1_OUT_MSB_1_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_ADC_1_OUT_MSB_1_H */


/* [] END OF FILE */
