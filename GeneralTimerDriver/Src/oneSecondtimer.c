#include "oneSecondTimer.h"
#include "gpio.h"
#include <stdint.h>
#include <stdbool.h>

void blinkPA5LED(){
	PA5LedInit();

	OneSecondTimer2Init();

	while(true){

		PA5LedToggle();

		delay();

		resetTimer2StatusRegister();
	}
}

void delay(){
	const uint32_t setStatusUpdateInterruptFlag = (1U<<0);

	while(!(TIM2->SR & setStatusUpdateInterruptFlag)){

	};
}

void resetTimer2StatusRegister(){
	const uint32_t setStatusUpdateInterruptFlag = (1U<<0);

	TIM2->SR &= ~setStatusUpdateInterruptFlag;
}

void OneSecondTimer2Init(void){
	enableTimer2();

	uint16_t prescalerValue = 1600;

	setTimer2PrescalerValue(prescalerValue);

	uint32_t autoReloadValue = 10000;

	setTimer2AutoReloadValue(autoReloadValue);

	enableTimer2Counter();

	resetTimer2Counter();
}

void enableTimer2(){
	const uint32_t TIM2EN = (1U<<0);

	RCC->APB1ENR |= TIM2EN;
}

void setTimer2PrescalerValue(uint16_t prescalerValue){
	TIM2->PSC = prescalerValue - 1;
}

void setTimer2AutoReloadValue(uint32_t autoReloadValue){
	TIM2->ARR = 10000-1;
}

void enableTimer2Counter(){
	const uint32_t CR1_CEN = (1U<<0);

	TIM2->CR1 = CR1_CEN;
}

void resetTimer2Counter(){
	TIM2->CNT = 0;
}
