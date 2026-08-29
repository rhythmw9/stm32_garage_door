#include "../inc/systick.h"

void systickInit(void)
{
    // load reload value
    SYSTICK_LOAD = 16000 - 1;

    // clear current value
    SYSTICK_VAL = 0;

    // select processor clock
    SYSTICK_CTRL |= (1U << 2);

    // enable systick
    SYSTICK_CTRL |= (1U << 0);
}

void systickDisable(void)
{
    SYSTICK_CTRL &= ~(1U << 0);
}

void systick_ms_delay(uint32_t delay)
{
    // for loop that runs for "delay" iterations (delay ms)
    for(volatile int i = 0; i < delay; ++i)
    {
        // blocking loop that will take precisely 1ms
        while((SYSTICK_CTRL & (1U << 16)) == 0)
        {
            // do nothing, cpu is blocked
        }
    }
}