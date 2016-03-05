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


int main(){
    CyGlobalIntEnable; /* Enable global interrupts. */
    Timer_1_Start(); 
    PWM_1_Start(); 
    high_StartEx(timer1); 
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    /*int j = 20000; //period
    int k = 10000; //compare value
    volatile int l;*/
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
        PWM_1_WriteCompare(k); 
        l = Timer_1_ReadCounter(); */
    }
}

CY_ISR(timer1){
    Timer_1_ReadStatusRegister(); //clears interrupt
    volatile static int i = 0; 
    volatile static int j[10]; 
    if(i < 10){
      j[i] = Timer_1_ReadCounter(); 
      i++; 
    }else{
      i=0; 
      j[i] = Timer_1_ReadCapture(); 
    }
    //Timer_1_Init(); 
   .// Reset_Write(1); 
    //Reset_Write(0); 
}

/* [] END OF FILE */
