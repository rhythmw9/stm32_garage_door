#include "../inc/gpio.h"

int main(void)
{
    gpioInit();

    while(1)
    {
        ledOn();

        for(volatile int i = 0; i < 10000000; ++i);

        ledOff();

        for(volatile int i = 0; i < 10000000; ++i);
    }

    return 0;
}