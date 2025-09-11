#include <systick.h>
#include <stdint.h>
#include <stdbool.h>

void setSysTickCycles(const uint32_t clockCycles){
	SysTick->LOAD = clockCycles - 1;
}

void resetSysTickCounter(){
	SysTick->VAL = 0;
}

void setSysTickClockSource(const uint32_t controlClockSource){
	SysTick->CTRL = controlClockSource;
}

void toggleSysTickCounter(const uint32_t toggleCommand){
	SysTick->CTRL ^= toggleCommand;
}

bool sysTickHasNotReachedZero(){
	const uint32_t clockCountFlagCheck = (1U<<16);

	return ((SysTick->CTRL & clockCountFlagCheck) == 0);
}

void resetSysTickCTRL(){
	SysTick->CTRL = 0;
}

void sysTickDelayMS(const uint32_t msDelay){
	const uint32_t clockCyclesFor1MS = 16000;

	setSysTickCycles(clockCyclesFor1MS);

	resetSysTickCounter();

	const uint32_t setControlClockSourceToInternal = (1U<<2);

	setSysTickClockSource(setControlClockSourceToInternal);

	const uint32_t enableSysTickCounter = (1U<<0);

	toggleSysTickCounter(enableSysTickCounter);

	for(int i = 0; i < msDelay; ++i){
		while(sysTickHasNotReachedZero()){

		}
	}

	 resetSysTickCTRL();
}
