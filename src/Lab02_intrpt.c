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
//
// -- Prototypes ------------
//
void blinkScreen();
void Init_GPIO_EXTI8();
void Init_Timer();

//
//
// -- Code Body -------------
//
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
static int task=4;
static int time=0;

int main() {
	Sys_Init();
	switch(task){
	case 11: Init_GPIO_EXTI8(); break;
	case 12: break;
	case 2: Init_Timer(); break;
	case 3:	break;
	case 4:
		Init_Timer();
		t4_init();
		break;
	}
	Init_Timer();
	Init_GPIO_EXTI8();
	printf("\033c\033[36m\033[2J");
	fflush(stdout);
	while (1) {
		// Main loop code goes here


		/*
		printf("Blink!\r\n");
		HAL_Delay(1000);
		blinkScreen(); // Alternatively: in some terminals, the BELL can be configured to produce
					   // 			a "visual bell" ... a blink.
		*/

		//HAL_Delay(1000);
		switch(task){
		case 11: task1_reg_update(); break;
		case 12: break;
		case 2: break;
		case 3:	break;
		case 4:
			t4_update();
			break;
		}
	}
}

//
//
// -- Utility Functions ------
//
void task1_reg_update(){
	if(set){
		HAL_Delay(10);
		if(GPIOC->IDR & 0x100 == 0x100)
			printf("Interrupted\r\n");
		set=0;
	}
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

	// Other code here:
	time+=1;
	if(task==2){
		printf("\033[2;30H");
		fflush(stdout);
		printf("  %d.%d  ",time/10,time%10);
		fflush(stdout);
	}
	if(task==4){
		if(stage==3){
			printf("\033[1;30H");
			fflush(stdout);
			printf("  %d.%d  ",time/10,time%10);
			fflush(stdout);
		}
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

//HAL - GPIO/EXTI Handler
void xxx_IRQHandler() {
	//HAL_GPIO_EXTI_IRQHandler(???);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	// ISR code here.
}


// For the HAL timer interrupts, all of the associated Callbacks need to exist,
// otherwise during assembly, they will generate compiler errors as missing symbols
// Below are the ones that are not used.

// void HAL_TIMEx_BreakCallback(TIM_HandleTypeDef *htim){};
// void HAL_TIMEx_CommutationCallback(TIM_HandleTypeDef *htim){};
