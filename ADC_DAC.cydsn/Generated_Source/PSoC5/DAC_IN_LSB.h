/*******************************************************************************
* File Name: DAC_IN_LSB.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_DAC_IN_LSB_H) /* CY_STATUS_REG_DAC_IN_LSB_H */
#define CY_STATUS_REG_DAC_IN_LSB_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} DAC_IN_LSB_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 DAC_IN_LSB_Read(void) ;
void DAC_IN_LSB_InterruptEnable(void) ;
void DAC_IN_LSB_InterruptDisable(void) ;
void DAC_IN_LSB_WriteMask(uint8 mask) ;
uint8 DAC_IN_LSB_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define DAC_IN_LSB_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define DAC_IN_LSB_INPUTS              8


/***************************************
*             Registers
***************************************/

/* Status Register */
#define DAC_IN_LSB_Status             (* (reg8 *) DAC_IN_LSB_sts_sts_reg__STATUS_REG )
#define DAC_IN_LSB_Status_PTR         (  (reg8 *) DAC_IN_LSB_sts_sts_reg__STATUS_REG )
#define DAC_IN_LSB_Status_Mask        (* (reg8 *) DAC_IN_LSB_sts_sts_reg__MASK_REG )
#define DAC_IN_LSB_Status_Aux_Ctrl    (* (reg8 *) DAC_IN_LSB_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_DAC_IN_LSB_H */


/* [] END OF FILE */
