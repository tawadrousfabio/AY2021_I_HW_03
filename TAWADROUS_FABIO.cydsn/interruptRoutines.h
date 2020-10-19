/**
*   \brief Header of the interrupts routine file.
*   \author: Fabio Tawadrous
*/


#ifndef __INTERRUPT_ROUTINES_H
    #define __INTERRUPT_ROUTINES_H
    #include "cytypes.h"
    
    CY_ISR_PROTO(Interrupt_RGB_LED_Handler); //color change isr
    CY_ISR_PROTO(Interrupt_Timer_Handler);  //timer control isr
#endif

/* [] END OF FILE */
