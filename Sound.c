// Sound.c, 
// This module contains the SysTick ISR that plays sound
// Runs on LM4F120 or TM4C123
// Program written by: Alex Lopez, Jaehyun Han 
// Date Created: October 30 2019
// Last Modified: November 15 2019

#include "tm4c123gh6pm.h"
#include "dac.h"

// this file explains how the module works

// **************Sound_Init*********************
// Initialize Systick periodic interrupts
// Input: Initial interrupt period
// Output: none
void Sound_Init(void){                          // Initiate SysTick with interrupts
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x00000007;
	NVIC_SYS_PRI3_R = 0x60000000;									// Set priority to 6
}

// **************Sound_Play*********************
// Converts deaired note to reload value
// 1/80 MHz = 12.5 ns
// 40 stages to digital sign wave, see lab5.c
// Reload = 1 / ( Note * 12.5 ns * 40 stages)
// Input: period
// Output: none
void Sound_Play(unsigned long period){          // Set Reload value depends on 'period' value.
	
	if(period == 440){
		NVIC_ST_RELOAD_R = 4544;
	}
	
	else if(period == 494){
		NVIC_ST_RELOAD_R = 4048;
	}

	else if(period == 262){
		NVIC_ST_RELOAD_R = 7633;
	}

	else if(period == 294){
		NVIC_ST_RELOAD_R = 6802;
	}
	
	else{   																			// If switches are not pressed, 
		NVIC_ST_RELOAD_R = 0;
  }
	NVIC_ST_CURRENT_R = 0;
}