#include "stm32f4xx.h"
#include <stdint.h>

#ifndef TIMER_H
#define TIMER_H

void delay();

void resetTimer2StatusRegister();

void OneSecondTimer2Init();

void enableTimer2();

void setTimer2PrescalerValue(uint16_t prescalerValue);

void setTimer2AutoReloadValue(uint32_t autoReloadValue);

void enableTimer2Counter();

void resetTimer2Counter();

#endif
