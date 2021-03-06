// Sound.h
// This module contains the SysTick ISR that plays sound
// This module also contains the Edge Triggered ISR 
// Runs on LM4F120 or TM4C123
// Date Created: October 30 2019
// Last Modified: November 15 2019

// Header files contain the prototypes for public functions

// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Called once, with sound initially off
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
// Output: none
void Sound_Init(void);


// **************Sound_Play*********************
// Start sound output, and set Systick interrupt period 
// Input: interrupt period
//           Units to be determined by YOU
//           Maximum to be determined by YOU
//           Minimum to be determined by YOU
//         input of zero disable sound output
// Output: none
void Sound_Play(unsigned long period);
