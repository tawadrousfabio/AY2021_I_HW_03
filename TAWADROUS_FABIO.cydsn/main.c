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
#include "interruptRoutines.h"
#include "RGB_Led_Driver.h"
uint8_t rec = 0;
uint8_t v[4];
Cmp c;
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    RGBLed_Start();
    UART_Start();
    isr_UART_StartEx(myinterrupt);
    

    for(;;)
    {
        if(rec==1){
            UART_PutString("hello world \r\n");
            c.red_cmp = 255-v[1];
            c.green_cmp = 255-v[2];
            c.blue_cmp = 255-v[3];
            
            RGBLed_WriteCmp(c);
            rec = 0;
        }
        
    }
}

/* [] END OF FILE */
