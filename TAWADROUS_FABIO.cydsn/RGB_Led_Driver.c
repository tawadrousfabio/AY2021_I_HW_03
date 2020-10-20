/**
*   \brief Source code for RGB Led Driver.
*   \author: Fabio Tawadrous
*   
*   In this file what were defined in the header file
*   is being implemented.
*/

#include "RGB_Led_Driver.h"
extern uint8_t i;
extern uint8_t rec;

/**
*   \brief Start PWMs
*/
void RGBLed_Start(void)
{
    PWM_RG_Start(); // Start PWM connected to red channel
    PWM_B_Start(); 
}

/**
*   \brief Stop PWMs
*/
void RGBLed_Stop(void)
{
    PWM_RG_Stop(); 
    PWM_B_Stop();
}

/**
*   \brief  Modifies the compare value for each color.
*/
void RGBLed_WriteCmp(Cmp p)
{
    PWM_RG_WriteCompare1(p.red_cmp);  //set the compare value of the red channel 
    PWM_RG_WriteCompare2(p.green_cmp); 
    PWM_B_WriteCompare(p.blue_cmp);  
}

/**
*   \brief On error: stop the timer, and reset the variables.
*/
void error(){
    UART_Timer_Stop();
    rec = 0; //put the flag = 0
    i = 0;  //if arrives a new byte, it will be stored from the beginning of the array
}

/**
*   \brief if header and tail are correct: stop the timer, reset the i variable and set the flag = 1.
*/
void sendtoapply(){
    UART_Timer_Stop();
    rec = 1; //flag = 1. In this way, data are sent to main.c
    i = 0;
}

/* [] END OF FILE */
