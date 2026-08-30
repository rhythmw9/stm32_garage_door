#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

/* Register Definitions */
#define GPIOA_BASE (0x40020000)
#define GPIOA_MODER_OFFSET (0x00)
#define GPIOA_OTYPER_OFFSET (0x04)
#define GPIOA_OSPEEDR_OFFSET (0x08)
#define GPIOA_PUPDR_OFFSET (0x0C)
#define GPIOA_IDR_OFFSET (0x10)
#define GPIOA_ODR_OFFSET (0x14)
#define GPIOA_BSRR_OFFSET (0x18)
#define GPIOA_LCKR_OFFSET (0x1C)
#define GPIOA_AFRL_OFFSET (0x20)
#define GPIOA_AFRH_OFFSET (0x24)
#define GPIOA_MODER *(volatile uint32_t*)(GPIOA_BASE + GPIOA_MODER_OFFSET)
#define GPIOA_OTYPER *(volatile uint32_t*)(GPIOA_BASE + GPIOA_OTYPER_OFFSET)
#define GPIOA_OSPEEDR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_OSPEEDR_OFFSET)
#define GPIOA_PUPDR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_PUPDR_OFFSET)
#define GPIOA_IDR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_IDR_OFFSET)
#define GPIOA_ODR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_ODR_OFFSET)
#define GPIOA_BSRR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_BSRR_OFFSET)
#define GPIOA_LCKR *(volatile uint32_t*)(GPIOA_BASE + GPIOA_LCKR_OFFSET)
#define GPIOA_AFRL *(volatile uint32_t*)(GPIOA_BASE + GPIOA_AFRL_OFFSET)
#define GPIOA_AFRH *(volatile uint32_t*)(GPIOA_BASE + GPIOA_AFRH_OFFSET)

/* Function Prototypes */
void gpioInit(void);
void ledToggle(void);
void ledOn(void);
void ledOff(void);

#endif /* GPIO_H */