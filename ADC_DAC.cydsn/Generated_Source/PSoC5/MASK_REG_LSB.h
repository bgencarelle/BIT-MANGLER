/*******************************************************************************
* File Name: MASK_REG_LSB.h  
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

#if !defined(CY_CONTROL_REG_MASK_REG_LSB_H) /* CY_CONTROL_REG_MASK_REG_LSB_H */
#define CY_CONTROL_REG_MASK_REG_LSB_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} MASK_REG_LSB_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    MASK_REG_LSB_Write(uint8 control) ;
uint8   MASK_REG_LSB_Read(void) ;

void MASK_REG_LSB_SaveConfig(void) ;
void MASK_REG_LSB_RestoreConfig(void) ;
void MASK_REG_LSB_Sleep(void) ; 
void MASK_REG_LSB_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define MASK_REG_LSB_Control        (* (reg8 *) MASK_REG_LSB_Sync_ctrl_reg__CONTROL_REG )
#define MASK_REG_LSB_Control_PTR    (  (reg8 *) MASK_REG_LSB_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_MASK_REG_LSB_H */


/* [] END OF FILE */
