/* 
    Author: Rhythm Winicour-Freeman
    File: gpio.c 
    Description: Function implementations for gpio.h
*/
#include "../inc/gpio.h"
#include "../inc/rcc.h"

/* Bit Fields */
#define MODER_PIN5_OUTPUT (1U << 10)
#define MODER_PIN5_ANALOG (3U << 10) // use this for clearing bits (and input mode)
#define ODR_PIN5 (1U << 5)
#define MODER_PIN13_IO (1U << 26)
#define MODER_PIN13_ANALOG (3U << 26) // use this for clearing bits (and input mode)
#define PUPDR_PIN13_CLEAR (3U << 26) // use for no PUPDR as well
#define PUPDR_PIN13_PD (2U << 26)


void userLedInit(void)
{
    // clear bits
    GPIOA_MODER &= ~MODER_PIN5_ANALOG;

    // set PA5 to output mode
    GPIOA_MODER |= MODER_PIN5_OUTPUT;
}

void userLedToggle(void)
{
    GPIOA_ODR ^= ODR_PIN5;
}

void userLedOn(void)
{
    GPIOA_ODR |= ODR_PIN5;
}

void userLedOff(void)
{
    GPIOA_ODR &= ~ODR_PIN5;
}


void userBtnInit(void)
{
    // clear bits (also sets to input mode, PC13)
    GPIOC_MODER &= ~MODER_PIN13_ANALOG;

    // clear bits
    GPIOC_PUPDR &= ~PUPDR_PIN13_CLEAR;

    // enable pull down resistor
    GPIOC_PUPDR |= PUPDR_PIN13_PD;
}
