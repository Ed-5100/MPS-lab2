/*
 * Task4.c
 *
 *  Created on: Sep 24, 2020
 *      Author: You Hu
 */

#include "init.h"
#include <stdint.h>
#include<stdlib.h>

void blinkScreen();
void Init_GPIO_EXTI8();
void Init_Timer();
void t4_init();
void Init_GPIO_interrup_HAL();
void EXTI0_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);//Task1
void t4_update();

volatile uint8_t timeUpdated = 0;
volatile uint8_t buttonPressed = 0;
volatile uint8_t buttonReleased = 0;
volatile uint32_t elapsed = 0;

int32_t randomNumber = 0;
uint32_t startTime = 0;
float averageScore = 0;
unsigned int iterations = 0;
int stage=0;
static int set=0;
static int time=0;

int main(){
	Sys_Init();
	Init_Timer();
	t4_init();
	Init_GPIO_EXTI8();//D5
	Init_GPIO_interrup_HAL();//D4
	printf("\033c\033[36m\033[2J");
	fflush(stdout);
	while(1){
		t4_update();
	}
}

void Init_GPIO_interrup_HAL(){
	GPIO_InitTypeDef GPIO_InitStruct;
	HAL_Init();

	//GPIO port J clock enable
	__HAL_RCC_GPIOJ_CLK_ENABLE();
	__HAL_RCC_SYSCFG_CLK_ENABLE();

	GPIO_InitStruct.Pin = GPIO_PIN_0;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(GPIOJ, &GPIO_InitStruct);

	HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(){
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_0);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	averageScore = 0;
	iterations = 0;
	time=0;
	stage=0;
	printf("\033c\033[36m\033[2J");
}



void t4_init(){
	//srand(time(NULL));
	printf("\033[2J\033[37;40m");
	fflush(stdout);
}

void t4_update(){
	if(stage==0){
		printf("\033[5;30H");
		fflush(stdout);
		printf("Running...");
		fflush(stdout);
		randomNumber=rand() % 100+20;
		stage=1;
		time=0;

		return;
	}
	if(stage==1){
		if(randomNumber<time){
			stage=2;
		}
		return;
	}
	if(stage==2){
		stage=3;
		time=0;
		blinkScreen();
		return;
	}
	if(stage==3){
		if(set){
			HAL_Delay(50);
			if(GPIOC->IDR & 0x100 == 0x100){
				int temp=time;
				averageScore=(averageScore*iterations+temp)/(iterations+1);
				iterations+=1;
				stage=0;
				printf("\033[1;30H");
				fflush(stdout);
				printf("            ");
				fflush(stdout);
				printf("\033[4;25H");
				fflush(stdout);
				printf("   LAST:%d.%ds   AVG: %d.%ds   ",temp/10,temp%10,(int)averageScore/10,(int)averageScore%10);
				fflush(stdout);
			}
			set=0;
			HAL_Delay(50);
			return;
		}
	}
}

void blinkScreen(){
	printf("\033[30;47m");
	// Clear and redraw display (flash it & sound the bell).
	printf("\a\033[s\033[2J\033[u");
	fflush(stdout);
	HAL_Delay(100);

	printf("\033[37;40m");
	// Clear and redraw display (flash it).
	printf("\033[s\033[2J\033[u");
	fflush(stdout);
}


//
//
// -- Init Functions ----------
//
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

	// Enable Update Interrupts.
	TIM6->DIER |= TIM_DIER_UIE;

	// Start the timer.
	TIM6->CR1 |= TIM_CR1_CEN;
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

//
//
// -- ISRs (IRQs) -------------
//
void TIM6_DAC_IRQHandler() {
	// Clear Interrupt Bit
	TIM6->SR &= 0xFFFFFFFE;

	time+=1;
	if(stage==3){
		printf("\033[1;30H");
		fflush(stdout);
		printf("  %d.%d  ",time/10,time%10);
		fflush(stdout);
	}
	asm ("nop");
}

// Non-HAL GPIO/EXTI Handler
void EXTI9_5_IRQHandler() {
	// Clear Interrupt Bit by setting it to 1.
	EXTI->PR &= EXTI_PR_PR8;
	// Other code here:
	set = 1;

	asm ("nop");
}

