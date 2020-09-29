/*
 * Task2.c
 *
 *  Created on: Sep 24, 2020
 *      Author: You Hu
 */
#include "init.h"
#include <stdint.h>
#include<stdlib.h>

//
//
static int time = 0;

void Init_Timer();
void TIM6_DAC_IRQHandler();

int main(){
	Sys_Init();
	Init_Timer();
	printf("\033c\033[36m\033[2J");
	fflush(stdout);

	while(1){
		printf("\033[2;30H");
		fflush(stdout);
		printf("  %d.%d  ",time/10,time%10);
		fflush(stdout);
		asm ("nop");
	}
}

void Init_Timer() {
		// Enable the TIM6 interrupt.
	// Looks like HAL hid this little gem, this register isn't mentioned in
	//   the STM32F7 ARM Reference Manual....
	NVIC->ISER[54 / 32] = (uint32_t) 1 << (54 % 32);

	// Enable TIM2 clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	asm ( "nop" );
	asm ( "nop" );

	// Set pre-scaler to slow down ticlks
	TIM6->PSC=10799;

	// Set the Auto-reload Value for 10Hz overflow
	TIM6->ARR=999;

	// Generate update events to auto reload.
	TIM6->EGR |= TIM_EGR_UG;
	TIM6->SR &= 0xFFFFFFFE;
	asm ( "nop" );
	asm ( "nop" );
	// Enable Update Interrupts.
	TIM6->DIER |= TIM_DIER_UIE;
	//TIM6->SR &= 0xFFFFFFFE;

	// Start the timer.
	TIM6->CR1 |= 0x05;
}

void TIM6_DAC_IRQHandler() {
	// Clear Interrupt Bit
	TIM6->SR &= 0xFFFFFFFE;

	// Other code here:
	time+=1;
}
