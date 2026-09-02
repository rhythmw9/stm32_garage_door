/* 
    Author: Rhythm Winicour-Freeman
    File: systick.h
    Description: Register/bit field definitions and functin prototpyes for the SYSTICK core peripheral
*/
#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

/* Register Definitions */
#define SYSTICK_BASE (0xE000E010)
#define SYSTICK_CTRL_OFFSET (0x00)
#define SYSTICK_LOAD_OFFSET (0x04)
#define SYSTICK_VAL_OFFSET (0x08)
#define SYSTICK_CALIB_OFFSET (0x0C)
#define SYSTICK_CTRL *(volatile uint32_t*)(SYSTICK_BASE + SYSTICK_CTRL_OFFSET)
#define SYSTICK_LOAD *(volatile uint32_t*)(SYSTICK_BASE + SYSTICK_LOAD_OFFSET)
#define SYSTICK_VAL *(volatile uint32_t*)(SYSTICK_BASE + SYSTICK_VAL_OFFSET)


/* Bit Fields */
#define SYSTICK_RELOAD (1600 - 1) // for a 1ms tick
#define SYSTICK_CTRL_PROC_CLK (1U << 2)
#define SYSTICK_EN (1U << 0) // clear to disable
#define SYSTICK_COUNT_FLAG (1U << 16)

/* Function Prototypes */
void systickInit(void);
void systickDisable(void);
void systickDelay_ms(uint32_t delay);

#endif /* SYSTICK_H */