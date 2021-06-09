// dac.h
// This software configures DAC output
// Runs on LM4F120 or TM4C123
// Program written by: Alex Lopez, Jaehyun Han 
// Date Created: October 30 2019
// Last Modified: November 15 2019

// Header files contain the prototypes for public functions

// **************DAC_Init*********************
// Initialize 4-bit DAC, called once 
// Input: none
// Output: none
void DAC_Init(void);


// **************DAC_Out*********************
// output to DAC, set output pins
// Input: 5-bit data, 0 to 31 
// Output: none
void DAC_Out(unsigned long data);
