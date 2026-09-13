/* 
    Author: Rhythm Winicour-Freeman
    File: main.c
    Description: Main application file 
*/
#include "../inc/gpio.h"
#include "../inc/systick.h"
#include "../inc/uart.h"
#include "../inc/rcc.h"
#include "../inc/exti.h"

extern volatile int btnFlag;


int main(void)
{
    // initialize
    periphClockEnable();
    userLedInit();
    userBtnInit();
    uartInit();
    pc13ExtiInit();

    // main event loop
    while(1)
    {
        if(btnFlag == 1)
        {
            uartWriteString("Button Pressed!");
            btnFlag = 0; // clear flag
        }
    }

    return 0;
}