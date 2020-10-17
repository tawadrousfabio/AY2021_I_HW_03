/**
*   \brief Source code for RGB Led Driver.
*   \author: Fabio Tawadrous
*   
*   In this file what were defined in the header file
*   is being implemented.
*/

#include "RGLedDriver.h"

//static void RGLed_WriteRedCmp(uint16_t redcmp, uint8_t redtype, uint16_t redperiod);       //Set the Red-channel PWM parameters
//static void RGLed_WriteGreenCmp(uint16_t greencmp, uint8_t greentype, uint16_t greenperiod);   //Set the Green-channel PWM parameters


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

void RGLed_WriteCmp(Cmp p)
{
    RGLed_WriteRedCmp(p.red_cmp, p.red_cmp_type, p.red_period); //set the red channel
    RGLed_WriteGreenCmp(p.green_cmp, p.green_cmp_type, p.green_period); //set the green channel
}
*/

/**
*   \brief This function is specific for the PWM red channel, and modifies the compare value & type, and the period.
*/
void RGBLed_WriteCmp(Cmp p)
{
    PWM_R_WriteCompare(p.red_cmp);  //set the compare value of the k-th pattern in the red channel PWM
    PWM_G_WriteCompare(p.green_cmp);  //set the compare value of the k-th pattern in the red channel PWM
    PWM_B_WriteCompare(p.blue_cmp);  //set the compare value of the k-th pattern in the red channel PWM
}


/* [] END OF FILE */
