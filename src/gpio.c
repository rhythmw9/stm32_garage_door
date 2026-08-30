#include "../inc/gpio.h"
#include "../inc/rcc.h"

void gpioInit(void)
{
    // enable clock
    RCC_AHB1ENR |= (1U << 0);

    // set pin A5 to output mode
    GPIOA_MODER |= (1U << 10);
}

void ledToggle(void)
{
    GPIOA_ODR ^= (1U << 5);
}

void ledOn(void)
{
    GPIOA_ODR |= (1U << 5);
}

void ledOff(void)
{
    GPIOA_ODR &= ~(1U << 5);
}