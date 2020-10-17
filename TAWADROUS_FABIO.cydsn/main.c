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
#include "project.h"
#include "UART_InterruptRoutine.h"
#include "RGLedDriver.h"

uint8_t rec = 0;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    // Start UART component
    UART_Start();
    // Send a string of chars
    UART_PutString("Please, send a character!\r\n");
    // Enable the isr
    //isr_UART_StartEx(Custom_UART_RX_ISR);
    
    RGBLed_Start();
    
    Cmp p0 = {255, 255, 255};
    Cmp p1 = {0, 0, 0};
    RGBLed_WriteCmp(p1);
    
    for(;;)
    {

    }
}

/* [] END OF FILE */
