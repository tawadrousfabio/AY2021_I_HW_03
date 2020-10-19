/**
*   \file main.c
*   \brief Project aim: to control a RGB led through a serial port and cool term or a GUI
*   \author: Fabio Tawadrous
*/


#include "project.h"
#include "interruptRoutines.h"
#include "RGB_Led_Driver.h"

uint8_t rec = 0;  //flag
uint8_t v[5]; //vector of received data
Cmp c = {255, 255, 255}; //"black" led
uint8_t i = 0; //array index 

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    RGBLed_Start(); //start PWMs
    UART_Start();  // start UART
    
    //Start the two isr
    isr_UART_StartEx(Interrupt_RGB_LED_Handler);
    isr_Timer_StartEx(Interrupt_Timer_Handler);
    
    RGBLed_WriteCmp(c); //write the RGB values of the "black led"

    for(;;)
    {
        if(rec==1){
            UART_PutString("Color changed \r\n");
            
            //set the new RGB values (0 = min, 255 = max)
            c.red_cmp = 255-v[1];
            c.green_cmp = 255-v[2];
            c.blue_cmp = 255-v[3];
            
            RGBLed_WriteCmp(c); //write the new values on led
            
            //reset the index and flag
            i=0;
            rec = 0;
        } 
    }
}

/* [] END OF FILE */
