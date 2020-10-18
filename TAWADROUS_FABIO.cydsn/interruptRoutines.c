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
extern uint8_t v[5];
extern uint8_t i;

static char message[20] = {'\0'};

CY_ISR(myinterrupt)
{
    
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {
        v[i] = UART_ReadRxData();
        //sprintf(message, "Received: %d\r\n", v[i] );
        //UART_PutString(message);
        i++;
        //rec=1; 
    }
    
    if (i > 4){
         switch (v[0]){            
            case 0xA0:
                if(v[4] == 0xC0){
                    rec = 1;
                    i=0;
                } else{
                    UART_PutString("error:  be sure that the last byte is 'C0' \r\n");
                    rec = 0;
                    i=0;
                }
            break;
                
            default:
                UART_PutString("error:  be sure that the first byte is 'A0' \r\n");
                rec = 0;
                i = 0;
            break;
        }
    } else if (i==1 && v[0] == 'v'){
        UART_PutString("RGB LED Program $$$");
        rec = 0;
        i = 0;
    } 
    

}

/* [] END OF FILE */
