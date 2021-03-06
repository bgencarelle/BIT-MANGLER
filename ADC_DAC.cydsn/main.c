 /*******************************************************************************
* File Name: main.c

* Note that this file contains the DMA_Config function as well.
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>


void PWM_Start(void);
void PWM_Set(uint8 PWMin);


uint16  BIT_MASK_CTRL = 0;
uint16  DIV_MASK_CTRL = 0;
uint16  OLD_BIT_MASK_DEPTH = 0;
uint16  OLD_DIV_MASK_DEPTH = 0;
uint16  FINAL_OUT = 0;        
uint16  MASK_CTRL = 0;
uint16  OLD_MASK_DEPTH = 0;
uint8   MASK_EFFECT = 0;
uint16  Effect(uint16 depth);
uint16  SAR_ADCResultArray[ADC_SAR_Seq_NUMBER_OF_CHANNELS];
uint8   seq_sar_dataReady; 
int32   audio_result;
uint8   audio_dataReady;   
uint8   audio_lsb;
uint8   audio_msb;
uint16  FRQ_CTRL = 0;


int main(void)
{
    int32   Filt_ADC;
    
    /* Start the components */
    Opamp_1_Start();
    Opamp_2_Start();
    PWM_Start();
    PWM_ADC_CK_Enable();
    PWM_ADC_CK_Start();
    LCD_Char_1_Start();
//   ADC_DelSig_1_Start();
    Filter_Start();
    ADC_SAR_1_Start();
    ADC_SAR_1_IRQ_Enable();
    ADC_SAR_Seq_Start();
    ADC_SAR_Seq_IRQ_Enable();
    ADC_SAR_Seq_StartConvert();
    
 //  CapSense_1_Start();
    SPI_DAC_Start();
    
    /* Start ISRs */
    /* Enable global interrupts */
    CyGlobalIntEnable;
    ADC_SAR_Seq_StartConvert();
    LCD_Char_1_Position(0u, 0u);
    LCD_Char_1_PrintString("ADC1 ");
    LCD_Char_1_Position(1u, 0u);
    LCD_Char_1_PrintString("ADC2 ");
    
    
    for(;;)
    {
    
    
    if (audio_dataReady !=0)
    {   
    ADC_1_OUT_LSB_Write(audio_lsb);
    ADC_1_OUT_MSB_Write((audio_msb));
    FINAL_OUT = (((DAC_IN_MSB_Read()<<8) | DAC_IN_LSB_Read()));
    SPI_DAC_WriteTxData((FINAL_OUT)| 0b1111000000000000);
        audio_dataReady = 0;
    }
      if (seq_sar_dataReady !=0)
        {   

    PWM_ADC_CK_WritePeriod((SAR_ADCResultArray[0]>>3)+1);//sample rate control
    PWM_ADC_CK_WriteCompare((SAR_ADCResultArray[0]>>4));//SAR_ADCResultArray[0]>>1);//compare for 50% duty
    DIV_MASK_LSB_Write(0);//SAR_ADCResultArray[1] & 0xFF);//frequency div depth LSB;
    DIV_MASK_MSB_Write(0);//SAR_ADCResultArray[1]>>8u);//frequency div depth MSB;
    PWM_Set(1);//SAR_ADCResultArray[2]>>7)+1);//div value
    BIT_MASK_CTRL = 0;//Effect(SAR_ADCResultArray[3]>>7);
    seq_sar_dataReady=0;
        }  

    
    if (1 == 0)
    {
        
    LCD_Char_1_Position(0u, strlen("ADC1 "));
    LCD_Char_1_PrintInt16(FRQ_CTRL); 
    LCD_Char_1_Position(1u, strlen("ADC2 "));
    LCD_Char_1_PrintInt16(MASK_CTRL); 
    
    }
    
    
    }
}


uint16 Effect(uint16 depth)
{
            uint16 mask;
            switch (depth) 
        {
        case 0:
            mask = 0xFFFFu;//b1111 1111 1111;
            break;
        case 1:
            mask = 0xFFFEu;//b1111 1111 1110;
            break;  
        case 2:
            mask = 0xFFFCu;//b1111 1111 1100;
            break; 
        case 3:
            mask = 0xFFF8u;//b1111 1111 1000;
            break;
        case 4:
            mask = 0xFFF0u;//b1111 1111 0000;
            break;  
        case 5:
            mask = 0xFFE0u;//b1111 1110 0000;
            break; 
         case 6:
            mask = 0b111111010000;
            break; 
        case 7:
            mask = 0b111111000000;
            break;  
        case 8:
            mask = 0b111110110000;
            break;  
        case 9:
            mask = 0b111110100000;
            break;  
        case 10:
            mask = 0b111110010000;
            break;  
        case 11:
            mask = 0b111110000000;
            break;  
        case 12:
            mask = 0b111101110000;
            break;  
        case 13:
            mask = 0b111101100000;
            break;  
        case 14:
            mask = 0b111101000000;
            break;  
        case 15:
            mask = 0b111100000000;
        case 16:
            mask = 0b111100000000;
        case 17:
            mask = 0b111000000000;
        case 27:
            mask = 0b110100000000;
        case 28:
            mask = 0b110000000000;
        case 29:
            mask = 0b101100000000;
        case 30:
            mask = 0b101000000000;
        case 31:
            mask = 0b100000000000;
            break;  
        default:
            mask= 0xFFFFu;
        }
    return mask | 0xF000u;
}
void PWM_Start(void)
{
    
//  PWM_1_Enable();
//  PWM_2_Enable();
//  PWM_3_Enable();
    PWM_4_Enable();
    PWM_5_Enable();
    PWM_6_Enable();
    PWM_7_Enable();
    PWM_8_Enable();
    PWM_9_Enable();
    PWM_10_Enable();
    PWM_11_Enable();
    
//  PWM_1_Start();
//  PWM_2_Start();
//  PWM_3_Start();
    PWM_4_Start();
    PWM_5_Start();
    PWM_6_Start();
    PWM_7_Start();
    PWM_8_Start();
    PWM_9_Start();
    PWM_10_Start();
    PWM_11_Start();
    return;
}
void PWM_Set(uint8 PWMin){
   uint8 PWMdiv = PWMin>>1;
//  division
    PWM_4_WritePeriod(PWMin);
    PWM_5_WritePeriod(PWMin);
    PWM_6_WritePeriod(PWMin);
    PWM_7_WritePeriod(PWMin);
    PWM_8_WritePeriod(PWMin);
    PWM_9_WritePeriod(PWMin);
    PWM_10_WritePeriod(PWMin);
    PWM_11_WritePeriod(PWMin);
//  compare    
    PWM_4_WriteCompare(PWMdiv);
    PWM_5_WriteCompare(PWMdiv);
    PWM_6_WriteCompare(PWMdiv);
    PWM_7_WriteCompare(PWMdiv);
    PWM_8_WriteCompare(PWMdiv);
    PWM_9_WriteCompare(PWMdiv);
    PWM_10_WriteCompare(PWMdiv);
    PWM_11_WriteCompare(PWMdiv);
    return;
}
/* [] END OF FILE */
