// dac.c
// This software configures DAC output
// Runs on TM4C123
// Program written by: Alex Lopez, Jaehyun Han 
// Date Created: October 30 2019
// Last Modified: November 15 2019

#include "tm4c123gh6pm.h"

// **************DAC_Init*********************
// Initialize 5-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void){ unsigned int delay;	
	SYSCTL_RCGC2_R |=0x10;
	delay = 0x10;
	GPIO_PORTE_DIR_R |=0x1F;
	GPIO_PORTE_AFSEL_R &=0xE0;
	GPIO_PORTE_AMSEL_R &=0xE0;
	GPIO_PORTE_DEN_R |=0x1F;
}

// **************DAC_Out*********************
// output to DAC, set output pins
// Input: 5-bit data, 0 to 31 
// Output: none
void DAC_Out(unsigned long data){
  GPIO_PORTE_DATA_R = data;
}
