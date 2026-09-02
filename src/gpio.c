/* 
    Author: Rhythm Winicour-Freeman
    File: gpio.c 
    Description: Function implementations for gpio.h
*/
#include "../inc/gpio.h"
#include "../inc/rcc.h"


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
