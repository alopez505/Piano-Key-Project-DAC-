// Piano.c
// This software configures the off-board piano keys
// Runs on TM4C123
// Program written by: Alex Lopez, Jaehyun Han 
// Date Created: October 30 2019
// Last Modified: November 15 2019

#include "tm4c123gh6pm.h"

// this file explains how the module works

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void){ unsigned long delay;
  SYSCTL_RCGC2_R |=0x08;
	delay = 0x06;
	GPIO_PORTD_DIR_R &=0xF0;
	GPIO_PORTD_AFSEL_R &=0xF0;
	GPIO_PORTD_AMSEL_R &=0xF0;
	GPIO_PORTD_DEN_R |=0x0F;
	
  GPIO_PORTD_IS_R &= 0xF0;              // Set Edge trigger
	GPIO_PORTD_IBE_R = 0x0F;              // Set trigger on Both Edges
	GPIO_PORTD_IM_R = 0x0F;               // Clear
	GPIO_PORTD_ICR_R = 0x0F;              // Clear Flag
	NVIC_PRI0_R &= 0x40000000;            // Set priority to 1 (bit 29 to 1)
	NVIC_EN0_R = 0x08;                    // Enable interrupt for PortD
	
}
// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 3 depending on keys
// 0x01 is Key0, 0x02 is Key1, 0x04 is Key2 and 0x08 is key3
unsigned long Piano_In(void){ 
   unsigned long input;
   input = GPIO_PORTD_DATA_R & 0x0F;
   return input;
}
