/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "interruptRoutines.h"

#include "UART.h"
#include "stdio.h"
#include "RGB_Led_Driver.h"

extern uint8_t rec;
extern uint8_t v[5];
extern uint8_t i;

CY_ISR(Interrupt_RGB_LED_Handler)
{
    
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        v[i] = UART_ReadRxData();
        i++;
        UART_Timer_Start();
    }
    
    if (i > 4){
           
        switch (v[0]){  
            
            case 0xA0:
                if(v[4] == 0xC0) sendtoapply();
                else{
                    UART_PutString("error:  be sure that the last byte is 'C0' \r\n");
                    error();
                }
                break;
                
            default:
                UART_PutString("error:  be sure that the first byte is 'A0' \r\n");
                error();
                break;
        }
    } 
    else if (i==1 && v[0] == 'v'){
        UART_PutString("RGB LED Program $$$");
        error();
    } 
    
}

CY_ISR(Interrupt_Timer_Handler){
    UART_PutString("Communication error, time delay > 5s \r\n");
    error();
}

/* [] END OF FILE */
