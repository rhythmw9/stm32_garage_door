#ifndef RCC_H
#define RCC_H

/* Register Definitions */
#define RCC_BASE (0x40023800)
#define RCC_AHB1_OFFSET (0x30)
#define RCC_AHB1 *(volatile uint32_t*)(RCC_BASE + RCC_AHB1_OFFSET)

#endif /* RCC_H */