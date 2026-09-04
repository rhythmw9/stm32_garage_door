/* 
    Author: Rhythm Winicour-Freeman
    File: exti.c
    Description: Function implementations for exti.h
*/
#include "../inc/exti.h"
#include "../inc/gpio.h"

/* Helper Function Prototypes */
void disableGlobalInterrupts(void);
void enableGlobalInterrupts(void);
void enableIrqLine(uint8_t irqNum);

void pc13ExtiInit()
{
    disableGlobalInterrupts();

    // select Port C for EXTI 13
    SYSCFG_EXTICR4 |= EXTICR4_PC13_SEL;

    // unmask EXTI 13
    EXTI_IMR |= EXTI13_IRQ_UNMASK;

    // set to trigger on falling edge
    EXTI_FTSR |= EXTI13_FALLING_EN;

    /* Hardcoded to EXTI 13 for now (IRQ number 40)...
        TODO: generalize to all interrupt lines
    */
    uint8_t irqNum = 40;
    enableIrqLine(irqNum);

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
    volatile uint32_t* NVIC_ISER_BASE_ = NVIC_ISER_BASE;

    // compute which ISR register to access and which bit to set in that address
    uint8_t regIndex = irqNum / 32;
    uint8_t bitPos = irqNum % 32;

    // enable the specific IRQ line
    NVIC_ISER_BASE_[regIndex] |= (1U << bitPos);
}


/* Interupt Service Routine */
void EXTI15_10_IRQHandler(void)
{
    // wait for button to be pressed
    if((EXTI_PR & LINE13) != 0)
    {
        // clear flag
        EXTI_PR |= LINE13;

        // toggle user led
        GPIOA_ODR ^= ODR_PIN5;
    }
}