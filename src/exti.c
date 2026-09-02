/* 
    Author: Rhythm Winicour-Freeman
    File: exti.c
    Description: Function implementations for exti.h
*/
#include "../inc/exti.h"
//#include "../inc/rcc.h"

/* Helper Function Prototypes */
void disableGlobalInterrupts(void);
void enableGlobalInterrupts(void);
void enableIrqLine(uint8_t irqNum);

void pc13ExtiInit(void)
{
    disableGlobalInterrupts();

    // select Port C for EXTI 13
    SYSCFG_EXTICR4 |= EXTICR4_PC13_SEL;

    // unmask EXTI 13
    EXTI_IMR |= EXTI13_IRQ_UNMASK;

    // set to trigger on falling edge
    EXTI_FTSR |= EXTI13_FALLING_EN;

    // enable EXTI 13 in the NVIC
    //NVIC_EnableIRQ(EXTI15_10_IRQn);

    enableGlobalInterrupts();
}



/* Helper Function Implementations */
void disableGlobalInterrupts(void)
{
    __asm__ volatile("cpsid i");
}


void enableGlobalInterrupts(void)
{
    __asm__ volatile("cpsie i");
}


void enableIrqLine(uint8_t irqNum)
{
    uint8_t const32_8bit = 32;

    uint8_t regIndex = irqNum / const32_8bit;
    uint8_t bitPos = irqNum % const32_8bit;

    // TODO: complete function, will have to define EXTI and NVIC registers and offsets to continue
}