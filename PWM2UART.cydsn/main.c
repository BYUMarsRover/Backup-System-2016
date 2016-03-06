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
CY_ISR_PROTO(timer1); 
CY_ISR_PROTO(isr1); 
volatile int rise = 0; 
volatile int fall = 0; 


int main(){
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_1_Start(); 
    PWM_1_Start(); 
    high_StartEx(timer1); 
    isr_1_StartEx(isr1); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    /*int j = 20000; //period
    int k = 10000; //compare value*/
    volatile int l;
    for(;;)
    { 
       /*if( j > 10000){
            j -= 2000; 
            k -= 1000;         
        }else{
            j = 20000; 
            k = 10000; 
        }
        PWM_1_WritePeriod(j); 
        PWM_1_WriteCompare(k); */
       /* l = Timer_1_ReadCounter(); 
        if(l < 10){
         l = 0;    
        }*/
    }
}
//works inconsisently
CY_ISR(timer1){
    Timer_1_ReadStatusRegister(); //clears interrupt
    if(rise == 0){
        rise = Timer_1_ReadCapture(); 
        Timer_1_ClearFIFO(); 
    }else{
        fall = Timer_1_ReadCapture();
        volatile int out = rise - fall; 
        rise = 0; 
    }
}
//this doesn't run which is correct
CY_ISR(isr1){
    __NOP; 
}
/* [] END OF FILE */
