#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/* Register Definitions */
#define RCC_BASE (0x40023800)
#define RCC_AHB1_OFFSET (0x30)
#define RCC_AHB1 *(volatile uint32_t*)(RCC_BASE + RCC_AHB1_OFFSET)

#define GPIOA_BASE (0x40020000)
#define GPIOA_MODER_OFFSET (0x00)
#define GPIOA_OTYPER_OFFSET (0x04)
#define GPIOA_OSPEEDR_OFFSET (0x08)
#define GPIOA_PUPDR_OFFSET (0x0C)
#define GPIOA_ODR_OFFSET (0x14)
#define GPIOA_MODER *(volatile uint32_t*)(GPIOA_BASE + GPIOA_MODER_OFFSET)
#define GPIOA_OTYPER *(volatile uint32_t*)(GPIOA_BASE + GPIOA_OTYPER_OFFSET)
#define GPIOA_OSPEEDR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_OSPEEDR_OFFSET)
#define GPIOA_PUPDR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_PUPDR_OFFSET)
#define GPIOA_ODR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_ODR_OFFSET)

/* Function Prototypes */
void gpioInit(void);
void ledToggle(void);
void ledOn(void);
void ledOff(void);


#endif /* GPIO_H */