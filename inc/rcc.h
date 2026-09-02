/* 
    Author: Rhythm Winicour-Freeman
    File: rcc.h
    Description: Register/bit field definitions and function prototypes for the RCC peripheral 
*/
#ifndef RCC_H
#define RCC_H


#include <stdint.h>


/* Register Definitions */
#define RCC_BASE (0x40023800)
#define RCC_AHB1ENR_OFFSET (0x30)
#define RCC_APB1ENR_OFFSET (0x40)
#define RCC_APB2ENR_OFFSET (0x44)
#define RCC_AHB1ENR *(volatile uint32_t*)(RCC_BASE + RCC_AHB1ENR_OFFSET)
#define RCC_APB1ENR *(volatile uint32_t*)(RCC_BASE + RCC_APB1ENR_OFFSET)
#define RCC_APB2ENR *(volatile uint32_t*)(RCC_BASE + RCC_APB2ENR_OFFSET)


/* Bit Fields */
#define GPIOA_CLK_EN (1U << 0)
#define GPIOC_CLK_EN (1U << 2)
#define USART2_CLK_EN (1U << 17)
#define SYSCFG_CLK_EN (1U << 14)


/* Function Prototypes */
void periphClockEnable(void);


#endif /* RCC_H */