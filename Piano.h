// Piano.h
// This software configures the off-board piano keys
// Runs on LM4F120 or TM4C123
// Program written by: Alex Lopez, Jaehyun Han 
// Date Created: October 30 2019
// Last Modified: November 15 2019

// Header files contain the prototypes for public functions

// **************Piano_Init*********************
// Initialize piano key inputs, called once 
// Input: none 
// Output: none
void Piano_Init(void);

// **************Piano_In*********************
// Input from piano key inputs 
// Input: none 
// Output: 0 to 3 depending on keys
// 0x01 is Key0, 0x02 is Key1, 0x04 is Key2 and 0x08 is key3
unsigned long Piano_In(void);
