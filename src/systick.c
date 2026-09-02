/* 
    Author: Rhythm Winicour-Freeman
    File: systick.c
    Description: Function implementations for systick.h
*/
#include "../inc/systick.h"


void systickInit(void)
{
    // load reload value
    SYSTICK_LOAD = SYSTICK_RELOAD;

    // clear current value
    SYSTICK_VAL = 0;

    // select processor clock
    SYSTICK_CTRL |= SYSTICK_CTRL_PROC_CLK;

    // enable systick
    SYSTICK_CTRL |= SYSTICK_EN;
}

void systickDisable(void)
{
    SYSTICK_CTRL &= ~SYSTICK_EN;
}

void systickDelay_ms(uint32_t delay)
{
    // for loop that runs for "delay" iterations (delay ms)
    for(volatile int i = 0; i < delay; ++i)
    {
        // blocking loop that will take precisely 1ms
        while((SYSTICK_CTRL & SYSTICK_COUNT_FLAG) == 0)
        {
            // do nothing, cpu is blocked
        }
    }
}