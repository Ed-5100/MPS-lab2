/*
 * Task3.c
 *
 *  Created on: Sep 24, 2020
 *      Author: You Hu
 */
#include "init.h"
#include <stdint.h>
#include<stdlib.h>
//


TIM_HandleTypeDef htim6;
unsigned int t_hal =0;
static int set=0;


void Init_timer_HAL();
void TIM6_DAC_IRQHandler();
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

int main() {
	Sys_Init();
	Init_timer_HAL();
	printf("\033c\033[36m\033[2J");//Clear the screen
	fflush(stdout);
	while (1){//Print time
		printf("\033[2;30H");
		fflush(stdout);
		printf(" %d.%d from start", t_hal/10, t_hal%10);
		fflush(stdout);
	}
}

void Init_timer_HAL(){
	HAL_Init();
	HAL_TIM_Base_MspInit(&htim6);

	//Set the TIM to be TIM6 and the corresponding prescaler and period
	htim6.Instance = TIM6;
	htim6.Init.Prescaler =2699;
	htim6.Init.Period = 3999;

	//Enable clock
	__HAL_RCC_TIM6_CLK_ENABLE();

	//Set priority and enable IRQ
	HAL_NVIC_SetPriority(TIM6_DAC_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn);

	//Initiate the timer
	HAL_TIM_Base_Init(&htim6);
	HAL_TIM_Base_Start_IT(&htim6);
}

void TIM6_DAC_IRQHandler(){
	HAL_TIM_IRQHandler(&htim6);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM6){//Increment the time
		t_hal++;
	}
}

