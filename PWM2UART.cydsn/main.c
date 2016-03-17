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
    
    }
}

//value varies between 1200-2100
CY_ISR(timer1){
    
    Timer_1_ReadStatusRegister(); //clears interrupt
    volatile uint16 x = Timer_1_ReadCapture(); 
    static int j[5]; 
    static int i = 0;
    
    if(i < 6){
     j[i] = x;  
     i++; 
    }else{
     i = 0; 
     j[i] = x; 
     i++; 
    }
}
//this doesn't run which is correct
CY_ISR(isr1){
    __NOP; 
}
/* [] END OF FILE */
