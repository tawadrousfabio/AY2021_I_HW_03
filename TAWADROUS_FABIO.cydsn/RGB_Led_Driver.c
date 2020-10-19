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
    PWM_R_Start(); // Start PWM connected to red channel
    PWM_G_Start(); 
    PWM_B_Start(); 
}

/**
*   \brief Stop PWMs
*/
void RGBLed_Stop(void)
{
    PWM_R_Stop(); 
    PWM_G_Stop();
    PWM_B_Stop();
}

/**
*   \brief This function is specific for the 3 PWMs, and modifies the compare value for each color.
*/
void RGBLed_WriteCmp(Cmp p)
{
    PWM_R_WriteCompare(p.red_cmp);  //set the compare value of the red channel 
    PWM_G_WriteCompare(p.green_cmp); 
    PWM_B_WriteCompare(p.blue_cmp);  
}

/**
*   \brief On error: stop the timer, and reset the variables.
*/
void error(){
    UART_Timer_Stop();
    rec = 0; //this avoid data to be sent to c
    i = 0;  //if arrives new data, they will be stored from the beginning of the vector
}

/**
*   \brief if data are ok: stop the timer, reset the i variable and set the received = 1.
*/
void sendtoapply(){
    UART_Timer_Stop();
    rec = 1; //in this way, data are sent to main.c
    i = 0;
}

/* [] END OF FILE */
