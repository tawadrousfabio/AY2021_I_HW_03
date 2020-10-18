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

void RGBLed_Start(void)
{
    // Start PWM Components
    PWM_R_Start(); // Start PWM connected to red channel
    PWM_G_Start(); // Start PWM connected to green channel
    PWM_B_Start(); // Start PWM connected to blue channel
}

void RGBLed_Stop(void)
{
    // Stop PWM Components
    PWM_R_Stop(); 
    PWM_G_Stop();
    PWM_B_Stop();
}

/**
*   \brief This function is specific for the PWM red channel, and modifies the compare value & type, and the period.
*/
void RGBLed_WriteCmp(Cmp p)
{
    PWM_R_WriteCompare(p.red_cmp);  //set the compare value of the k-th pattern in the red channel PWM
    PWM_G_WriteCompare(p.green_cmp);  //set the compare value of the k-th pattern in the red channel PWM
    PWM_B_WriteCompare(p.blue_cmp);  //set the compare value of the k-th pattern in the red channel PWM
}

/**
*   \brief On error: stop the timer, and reset the variable.
*/
void error(){
    UART_Timer_Stop();
    rec = 0;
    i = 0;
}

/**
*   \brief if data are ok: stop the timer, reset the i variable and set the received = 1.
*/
void sendtoapply(){
    UART_Timer_Stop();
    rec = 1;
    i = 0;
}

/* [] END OF FILE */
