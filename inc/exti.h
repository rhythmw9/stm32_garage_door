/* 
    Author: Rhythm Winicour-Freeman
    File: exti.h
    Description: Register/bit field definitions and function prototypes
*/
#ifndef EXTI_H
#define EXTI_H

#include <stdint.h>

/* Register Definitions */
#define SYSCFG_BASE (0x40013800)
#define SYSCFG_EXTICR4_OFFSET (0x14)
#define SYSCFG_EXTICR4 *(volatile uint32_t*)(SYSCFG_BASE + SYSCFG_EXTICR4_OFFSET)

#define EXTI_BASE (0x40013C00)
#define EXTI_IMR_OFFSET (0x00)
#define EXTI_FTSR_OFFSET (0x0C)
#define EXTI_PR_OFFSET (0x14)
#define EXTI_IMR *(volatile uint32_t*)(EXTI_BASE + EXTI_IMR_OFFSET)
#define EXTI_FTSR *(volatile uint32_t*)(EXTI_BASE + EXTI_FTSR_OFFSET)
#define EXTI_PR *(volatile uint32_t*)(EXTI_BASE + EXTI_PR_OFFSET)

#define NVIC_ISER_BASE (volatile uint32_t*)(0xE000E100) // used as a base pointer for the whole ISERx block

/* Bit Field */
#define LINE13 (1U << 13)
#define EXTICR4_PC13_SEL (0b0010 << 4)
#define EXTI13_IRQ_UNMASK (1U << 13)
#define EXTI13_FALLING_EN (1U << 13)

/* Function Prototypes */
void pc13ExtiInit();

#endif /* EXTI_H */