#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>
#include "stm32f4xx.h"
#include <stdint.h>

void sysTickDelayMS(const uint32_t msDelay);

#endif
