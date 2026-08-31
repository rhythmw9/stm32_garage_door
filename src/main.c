#include "../inc/gpio.h"
#include "../inc/systick.h"
#include "../inc/uart.h"
#include "../inc/rcc.h"

int main(void)
{
    // initialize
    periphClockEnable();
    userLedInit();
    userBtnInit();

    int btnState = 0; // initially not pressed

    // main event loop
    while(1)
    {
        // // get button  state
        // btnState = GPIOC_IDR |= (1U << 13);

        // if(btnState)
        // {
        //     userLedOn();
        // } else
        // {
        //     userLedOff();
        // }

        while(!(GPIOC_IDR & (1U << 13)))
        {
            userLedOn();
        }

        userLedOff();
    }

    return 0;
}