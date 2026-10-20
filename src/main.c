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
#include "../inc/motor.h"

extern volatile int btnFlag;
int currentAngle = 0;


int main(void)
{
    // initialize
    periphClockEnable();
    userLedInit();
    systickInit();
    userBtnInit();
    uartInit();
    pc13ExtiInit();
    motorDriverBoardInit();

    // main event loop
    while(1)
    {
        motorRotate(360, 10, &currentAngle);
        motorRotate(0, 10, &currentAngle);
    }

    return 0;
}