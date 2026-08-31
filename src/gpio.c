#include "../inc/gpio.h"
#include "../inc/rcc.h"

void userLedInit(void)
{
    // clear bits
    GPIOA_MODER &= ~(1U << 10);

    // set PA5 to output mode
    GPIOA_MODER |= (1U << 10);
}

void userLedToggle(void)
{
    GPIOA_ODR ^= (1U << 5);
}

void userLedOn(void)
{
    GPIOA_ODR |= (1U << 5);
}

void userLedOff(void)
{
    GPIOA_ODR &= ~(1U << 5);
}


void userBtnInit(void)
{
    // clear bits (also sets to input mode, PC13)
    GPIOC_MODER &= ~(1U << 26);

    // clear bits
    GPIOC_PUPDR &= ~(3U << 26);

    // enable pull down resistor
    GPIOC_PUPDR |= (2U << 26);
}
