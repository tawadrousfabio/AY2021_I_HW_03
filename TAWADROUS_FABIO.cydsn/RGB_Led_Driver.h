/**
*   \brief Header code for RGB Led Driver.
*   \author: Fabio Tawadrous   
*/

#ifndef _RGB_LED_DRIVER_H_
    #define _RGB_LED_DRIVER_H_
    #include "project.h"
    

    
    /**
    *   \brief Struct holding the color data
    */
    typedef struct {
        uint8_t red_cmp;    //Red PWM compare value (0-255) 
        uint8_t green_cmp;  //green PWM compare value (0-255) 
        uint8_t blue_cmp; //Red PWM compare type (0-255)
    } Cmp;
    
    
    /**
    *   \brief Start RGB Led Driver (PWMs).
    */
    void RGBLed_Start(void);
    
    /**
    *   \brief Stop RGB Led Driver (PWMs).
    */
    void RGBLed_Stop(void);
    
    
    /**
    *   \brief Modiy the compare value of the RGB channels.
    */
    void RGBLed_WriteCmp(Cmp c);
    
    /**
    *   \brief Function called when there is an error
    */
    void error();
    
    /**
    *   \brief Called when data pass all the controls.
    */
    void sendtoapply();
#endif

/* [] END OF FILE */
