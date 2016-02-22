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
#include <project.h>
#define COUNTER_RESET 0

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Counter_Start(); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
   int last_test = 0; 
int pwm_counter; 
    for(;;)
    {
        //if interrupt turns off 
            //record counter number
            //clear counter
            //reset interrupt_test
        //else
            //grab current interrupt_test value
        int current_test = Start_Stop_Read(); 
        if((last_test > 0) && (current_test == 0)){
            pwm_counter = Counter_ReadCounter(); 
            Counter_WriteCounter(COUNTER_RESET); 
            last_test = current_test; 
        }else{
            last_test = current_test; 
        }
    }
}

/* [] END OF FILE */
