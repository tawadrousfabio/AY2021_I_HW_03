/**
*
*/

#include "UART_InterruptRoutine.h"

#include "UART.h"
#include "stdio.h" // --> sprintf function

extern uint8_t rec;

CY_ISR(Custom_UART_RX_ISR)
{
    // Check UART Status
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        static char message[20] = {'\0'};
        sprintf(message, "Received: %c\r\n", UART_ReadRxData());
        UART_PutString(message);
    }
}

/* [] END OF FILE */
