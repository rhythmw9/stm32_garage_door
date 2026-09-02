/* 
    Author: Rhythm Winicour-Freeman
    File: main.c
    Description: Main application file 
*/
#include "../inc/gpio.h"
#include "../inc/systick.h"
#include "../inc/uart.h"
#include "../inc/rcc.h"

#define PRESS_DETECTED (GPIOC_MODER & (1U << 13))

int main(void)
{
    // initialize
    periphClockEnable();
    userLedInit();
    userBtnInit();
    uartInit();

    int pressCount = 0;
    const char* p = (char*)&pressCount;


    // main event loop
    while(1)
    {
        if(PRESS_DETECTED)
        {
            ++pressCount;
            uartWriteString("Press Detected!");
            uartWriteString(p);
        }

        userLedOn();

        systickDelay_ms(5000);

        userLedOff();
    }

    return 0;
}