// Lab5.c
// Runs on TM4C123
// Program written by: Alex Lopez, Jaehyun Han 
// Date Created: October 30 2019
// Last Modified: November 15 2019

// Hardware connections

#include "tm4c123gh6pm.h"
#include "PLL.h"
#include "Sound.h"
#include "Piano.h"
#include "dac.h"

// basic functions defined at end of startup.s
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
void WaitForInterrupt(void);  // Wait for interrupts

int count = 0;

//digital approx of sign wave using 5 outputs (D0-D4), 40 stages
unsigned long sound[40] = {0x10,0x12,0x14,0x17,0x19,0x1a,0x1c,0x1d,0x1e,0x1f,
							0x1f,0x1f,0x1e,0x1d,0x1c,0x1a,0x19,0x17,0x14,0x12,
							 0x10,0xd,0xb,0x8,0x6,0x5,0x3,0x2,0x1,0x0,
							 0x0,0x0,0x1,0x2,0x3,0x5,0x6,0x8,0xb,0xd};

int main(void){

	PLL_Init();									// bus clock at 80 MHz
	DAC_Init();									// Initiate PortE as output
	Piano_Init();								// Initiate PortD as input with interrupt
	Sound_Init();					           // Initiate Systick with interrupt 
	EnableInterrupts();							// Enable Global interrupt

  while(1){                
  	WaitForInterrupt();	
  }              
}

void GPIOPortD_Handler(void)                  // PortD interrupt service routine
{
	int note = 0;
	GPIO_PORTD_ICR_R = 0x0F;                    // Clear the flag
	
	if (GPIO_PORTD_DATA_R == 0X01){             // Note D4 = 294 Hz
		note = 294;
	}
	else if (GPIO_PORTD_DATA_R == 0X02){        // Note C4 = 262 Hz
		note = 262;
	}
	else if (GPIO_PORTD_DATA_R == 0X04){        // Note B5 = 494 Hz
		note = 494;
	}
	else if (GPIO_PORTD_DATA_R == 0X08){        // Note A5 = 440 Hz
		note = 440;
	}
	
	Sound_Play(note);                           // Send 'note' value to Sound_Play fuction, see sound.c
}

void SysTick_Handler(void){                   // SysTick interrupt service routine

	DAC_Out(sound[count]);                      // Send output signal to PortE
	
	if(count < 39){                             // Check if 'count' is lower than 39 because 40 stages for sign wave
		count++;
	}
	else{
		count=0;
	}
}
