#include <gpio.h>
#include <stdbool.h>
#include <stdint.h>
#include "stm32f4xx.h"

void enableGPIOforAHB1(const uint32_t enableGPIO){
	RCC->AHB1ENR |= enableGPIO;
}

void setGPIOAModeToOutput(const uint32_t setBit, const uint32_t setBit2){
	GPIOA->MODER |= setBit;

	GPIOA->MODER &= setBit2;
}

void PA5LedInit(){
	const uint32_t enableGPIOA = (1U<<0);

	const uint32_t setBit10To1 = (1U<<10);

	const uint32_t setBit11To0 = ~(1U<<11);

	enableGPIOforAHB1(enableGPIOA);

	setGPIOAModeToOutput(setBit10To1, setBit11To0);
}

void PA5LedToggle(){
	const uint32_t togglePinOnOff=(1U<<5);

	GPIOA->ODR ^= togglePinOnOff;
}
