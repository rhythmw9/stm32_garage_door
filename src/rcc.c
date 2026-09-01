#include "../inc/rcc.h"

/* Bit Fields */
#define GPIOA_CLK_EN (1U << 0)
#define GPIOC_CLK_EN (1U << 2)

void periphClockEnable(void)
{
    // GPIOA
    RCC_AHB1ENR |= GPIOA_CLK_EN;

    // GPIOC
    RCC_AHB1ENR |= GPIOC_CLK_EN;
}