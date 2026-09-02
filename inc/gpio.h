/* 
    Author: Rhythm Winicour-Freeman
    File: gpio.h
    Description: Register/bit field definitions and function definitions for all GPIO peripherals 
*/
#ifndef GPIO_H
#define GPIO_H


#include <stdint.h>


/* Register Definitions */
#define GPIOA_BASE (0x40020000) // This register is the base address for GPIOA but also its the first address in the whole GPIOx memory block
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

#define GPIOC_BASE (GPIOA_BASE + 0x800)
#define GPIOC_MODER_OFFSET (0x00)
#define GPIOC_OTYPER_OFFSET (0x04)
#define GPIOC_OSPEEDR_OFFSET (0x08)
#define GPIOC_PUPDR_OFFSET (0x0C)
#define GPIOC_IDR_OFFSET (0x10)
#define GPIOC_ODR_OFFSET (0x14)
#define GPIOC_BSRR_OFFSET (0x18)
#define GPIOC_LCKR_OFFSET (0x1C)
#define GPIOC_AFRL_OFFSET (0x20)
#define GPIOC_AFRH_OFFSET (0x24)
#define GPIOC_MODER *(volatile uint32_t*)(GPIOC_BASE + GPIOC_MODER_OFFSET)
#define GPIOC_OTYPER *(volatile uint32_t*)(GPIOC_BASE + GPIOC_OTYPER_OFFSET)
#define GPIOC_OSPEEDR *(volatile uint32_t*)(GPIOC_BASE + GPIOC_OSPEEDR_OFFSET)
#define GPIOC_PUPDR *(volatile uint32_t*)(GPIOC_BASE + GPIOC_PUPDR_OFFSET)
#define GPIOC_IDR *(volatile uint32_t*)(GPIOC_BASE + GPIOC_IDR_OFFSET)
#define GPIOC_ODR *(volatile uint32_t*)(GPIOC_BASE + GPIOC_ODR_OFFSET)
#define GPIOC_BSRR *(volatile uint32_t*)(GPIOC_BASE + GPIOC_BSRR_OFFSET)
#define GPIOC_LCKR *(volatile uint32_t*)(GPIOC_BASE + GPIOC_LCKR_OFFSET)
#define GPIOC_AFRL *(volatile uint32_t*)(GPIOC_BASE + GPIOC_AFRL_OFFSET)
#define GPIOC_AFRH *(volatile uint32_t*)(GPIOC_BASE + GPIOC_AFRH_OFFSET)


/* Bit Fields */
#define MODER_PIN5_OUTPUT (1U << 10)
#define MODER_PIN5_ANALOG (3U << 10) // use this for clearing bits (and input mode)
#define ODR_PIN5 (1U << 5)
#define MODER_PIN13_IO (1U << 26)
#define MODER_PIN13_ANALOG (3U << 26) // use this for clearing bits (and input mode)
#define PUPDR_PIN13_CLEAR (3U << 26) // use for no PUPDR as well
#define PUPDR_PIN13_PD (2U << 26)
#define MODER_PIN2_ANALOG (3U << 4) // use this for clearing bits (and input mode)
#define MODER_PIN2_ALT (2U << 4)
#define AFRL_PIN2_AF15 (0b1111 << 8) // set to alt func 15, also use this for clearing
#define AFRL_PIN2_AF7 (0b0111 << 8)


/* Function Prototypes */
void userLedInit(void);
void userLedToggle(void);
void userLedOn(void);
void userLedOff(void);

void userBtnInit(void);


#endif /* GPIO_H */