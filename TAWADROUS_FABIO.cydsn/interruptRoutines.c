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

extern uint8_t rec;
extern uint8_t v[4];
uint8_t i = 0;

static char message[20] = {'\0'};

CY_ISR(myinterrupt)
{
    
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        v[i] = UART_ReadRxData();
        sprintf(message, "Received: %d\r\n", v[i] );
        UART_PutString(message);
        i++;
        //rec=1;
        
    }
    
    if(i>4){
        rec = 1;
        i=0;
    }
}

/* [] END OF FILE */
