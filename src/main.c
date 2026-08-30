#include "../inc/gpio.h"
#include "../inc/systick.h"

int main(void)
{
    gpioInit();
    systickInit();

    while(1)
    {
        ledToggle();
        systick_ms_delay(500);
    }

    return 0;
}