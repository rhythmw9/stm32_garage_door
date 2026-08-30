#include "../inc/gpio.h"
#include "../inc/systick.h"
#include "../inc/uart.h"

int main(void)
{
    systickInit();
    gpioInit();
    uartInit();

    uartWriteString("Hello");
    uartWriteString("World");

    systickDelay_ms(10000);

    uartWriteString("Goodbye");
    uartWriteString("World");

    systickDisable();

    while(1)
    {
        // block
    }

    return 0;
}