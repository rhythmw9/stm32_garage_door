#include "../inc/rcc.h"

void periphClockEnable(void)
{
    // GPIOA
    RCC_AHB1ENR |= (1U << 0);

    // GPIOC
    RCC_AHB1ENR |= (1U << 2);
}