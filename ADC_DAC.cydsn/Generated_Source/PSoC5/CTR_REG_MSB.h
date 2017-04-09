/*******************************************************************************
* File Name: CTR_REG_MSB.h  
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

#if !defined(CY_CONTROL_REG_CTR_REG_MSB_H) /* CY_CONTROL_REG_CTR_REG_MSB_H */
#define CY_CONTROL_REG_CTR_REG_MSB_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} CTR_REG_MSB_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    CTR_REG_MSB_Write(uint8 control) ;
uint8   CTR_REG_MSB_Read(void) ;

void CTR_REG_MSB_SaveConfig(void) ;
void CTR_REG_MSB_RestoreConfig(void) ;
void CTR_REG_MSB_Sleep(void) ; 
void CTR_REG_MSB_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define CTR_REG_MSB_Control        (* (reg8 *) CTR_REG_MSB_Sync_ctrl_reg__CONTROL_REG )
#define CTR_REG_MSB_Control_PTR    (  (reg8 *) CTR_REG_MSB_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_CTR_REG_MSB_H */


/* [] END OF FILE */
