/**
*   \brief Source code for the implementation of what happens during the two interrupts
*   \author: Fabio Tawadrous
*/

#include "interruptRoutines.h"

#include "UART.h"
#include "stdio.h"
#include "RGB_Led_Driver.h"

extern uint8_t rec;
extern uint8_t v[5];
extern uint8_t i;
uint8_t esc = 0; 

CY_ISR(Interrupt_RGB_LED_Handler)
{
    
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY) 
    {
        v[i] = UART_ReadRxData();
        i++;
        UART_Timer_Start(); //when received the first byte, start the timer (5s).
    }
    
    //CONTROLS
    
        
        switch (v[0]){  
            
            
            case 0xA0: //the header is correct
                if(i>4){
                    if(v[4] == 0xC0) sendtoapply(); //check if also the tail is correct, then send data.
                    else{
                        UART_PutString("error:  be sure that the last byte is 'C0' \r\n");
                        error(); //if the tail is not the correct one, reset i and rec
                    }
                    break;
                } else break;
            
            case 'v':
                UART_PutString("RGB LED Program $$$"); //for GUI use
                error();
                break;
            default: //for any character different from 0xA0 and 'v' 
             
                //UART_PutString("error:  if you are going to run the GUI, please type v. /r/n if you want a new color, start with A0\r\n");        
                   
                error();
                break;
        }
        
        
}


//Interrupt for the timer (if the timer counts the 5s)
CY_ISR(Interrupt_Timer_Handler){
    UART_PutString("Communication error: time delay > 5s \r\n");
    error();
}

/* [] END OF FILE */
