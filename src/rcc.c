/* 
    Author: Rhythm Winicour-Freeman
    File: rcc.c
    Description: Function implementations for rcc.h 
*/
#include "../inc/rcc.h"


void periphClockEnable(void)
{
    // GPIOA
    RCC_AHB1ENR |= GPIOA_CLK_EN;

    // GPIOC
    RCC_AHB1ENR |= GPIOC_CLK_EN;

    // USART2
    RCC_APB1ENR |= USART2_CLK_EN;

    // SYSCFG
    RCC_APB2ENR |= SYSCFG_CLK_EN;
}