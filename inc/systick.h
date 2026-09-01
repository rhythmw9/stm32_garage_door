/* 
    Author: Rhythm Winicour-Freeman
    File: systick.h
    Description: Register definitions and functin prototpyes for the SYSTICK core peripheral
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

/* Function Prototypes */
void systickInit(void);
void systickDisable(void);
void systickDelay_ms(uint32_t delay);

#endif /* SYSTICK_H */