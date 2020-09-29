//----------------------------------
// Lab 2 - Timer Interrupts - Lab02.c
//----------------------------------
// Objective:
//   Build a small game that records user's reaction time.
//

//
//
// -- Imports ---------------
//
#include "init.h"
#include <stdint.h>
#include<stdlib.h>
//

// -- Code Body -------------


static int set=0;


void Init_GPIO_interrup_HAL();
void EXTI0_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);//Task1
void Init_GPIO_EXTI8();
void EXTI9_5_IRQHandler();

int main() {
	Sys_Init();
	Init_GPIO_EXTI8();
	Init_GPIO_interrup_HAL(); //Task1
	printf("\033c\033[36m\033[2J");
	fflush(stdout);
	while (1){
		//printf("not Pushed, with global variable:%c \r\n",set);
		if(set){
				set=0;
			}
	}
}


//PJ0=D4  PC8=D5
void Init_GPIO_interrup_HAL(){
	GPIO_InitTypeDef GPIO_InitStruct;
	HAL_Init();

	//GPIO port J clock enable
	__HAL_RCC_GPIOJ_CLK_ENABLE();
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	//Set pins to enable interrupt
	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

	//Set priority and enable the IRQ
	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	set= 1;
	if(HAL_GPIO_ReadPin(GPIOJ,GPIO_PIN_0)==1){//Ensure the interrupt condition is met
		printf("Pushed D4, global varaible set = %d\r\n", set);
	}
}

void Init_GPIO_EXTI8() {
	//pc8 for pin d5
	// Enable GPIO clocks?
	// Looks like GPIO reg updates are synced to a base clock.
	//  for any changes to appear the clocks need to be running.
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	// Enable clock to SYSCONFIG module to enable writing of EXTICRn registers
	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	// or __HAL_RCC_SYSCFG_CLK_ENABLE();
	// Delay after an RCC peripheral clock enabling
	asm ("nop");
	asm ("nop");

	// Set Pin 13/5 to output. (LED1 and LED2)
	//GPIOJ->MODER

	// GPIO Interrupt
	// By default pin PA0 will trigger the interrupt, change EXTICR3 to route proper pin
	SYSCFG->EXTICR[2] |= SYSCFG_EXTICR3_EXTI8_PC;// EXTICR1-4 are confusingly an array [0-3].

	// Set Pin 8 as input (button) with pull-down.
	GPIOC->PUPDR |= GPIO_PUPDR_PUPDR8_1;

	// Set interrupt enable for EXTI8.
	NVIC->ISER[23 / 32] = (uint32_t) 1 << (23 % 32);

	// Unmask interrupt.
	EXTI->IMR|=EXTI_IMR_MR8;

	// Register for rising edge.
	EXTI->RTSR|=EXTI_RTSR_TR8;

	// And register for the falling edge.
	//EXTI->FTSR|=EXTI_FTSR_TR8;
}

// Non-HAL GPIO/EXTI Handler
void EXTI9_5_IRQHandler() {
	// Clear Interrupt Bit by setting it to 1.
	EXTI->PR &= EXTI_PR_PR8;
	// Other code here:
	set = 1;
	if(GPIOC->IDR & 0x100 == 0x100){
		printf("Interrupted D5, global varaible set = %d\r\n", set);
	}
	asm ("nop");
}
