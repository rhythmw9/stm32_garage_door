/* 
    Author: Rhythm Winicour-Freeman
    File: systick.c
    Description: Function implementations for systick.h
*/
#include "../inc/systick.h"

#define PROCESSOR_FREQ 16000
#define SYSTICK_RELOAD (PROCESSOR_FREQ - 1)
#define SYSTICK_CTRL_PROC_CLK (1U << 2)
#define SYSTICK_EN (1U << 0) // clear to disable
#define SYSTICK_COUNT_FLAG (1U << 16)

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