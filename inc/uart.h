#ifndef UART_H
#define UART_H

#define SYS_CLK_FREQ 16000000
#define BAUD_RATE 115200 //115200

#include <stdint.h>

/* Register Definitions */
#define USART2_BASE (0x40004400)
#define USART2_SR_OFFSET (0x00)
#define USART2_DR_OFFSET (0x04)
#define USART2_BRR_OFFSET (0x08)
#define USART2_CR1_OFFSET (0x0C)
#define USART2_CR2_OFFSET (0x10)
#define USART2_CR3_OFFSET (0x14)
#define USART2_GTPR_OFFSET (0x18)
#define USART2_SR *(volatile uint32_t*)(USART2_BASE + USART2_SR_OFFSET)
#define USART2_DR *(volatile uint32_t*)(USART2_BASE + USART2_DR_OFFSET)
#define USART2_BRR *(volatile uint32_t*)(USART2_BASE + USART2_BRR_OFFSET)
#define USART2_CR1 *(volatile uint32_t*)(USART2_BASE + USART2_CR1_OFFSET)
#define USART2_CR2 *(volatile uint32_t*)(USART2_BASE + USART2_CR2_OFFSET)
#define USART2_CR3 *(volatile uint32_t*)(USART2_BASE + USART2_CR3_OFFSET)
#define USART2_GTPR *(volatile uint32_t*)(USART2_BASE + USART2_GTPR_OFFSET)

/* Function Prototypes */
void uartInit(void);
void uartWriteByte(int byte);
void uartWriteString(const char* msg);

#endif /* UART_H */