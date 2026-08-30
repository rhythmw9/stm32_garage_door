#include "../inc/rcc.h"
#include "../inc/uart.h"
#include "../inc/gpio.h"

// helper functions
uint32_t computeBaudRate(uint32_t periph_clk, uint32_t baud_rate);
void setBaudRate(uint32_t periph_clk, uint32_t baud_rate);

void uartInit(void)
{
    // set PA2 to alternate function
	GPIOA_MODER &= ~(3U << 4); // clear P2 mode bits
	GPIOA_MODER |= (2U << 4); // set P2 as alt function (10)

	// set alt function as AF07 (0111) for UART2_TX
	GPIOA_AFRL &= ~(0b1111 << 8); // clear bits
	GPIOA_AFRL |= (0b0111 << 8); // set P2 as AF7

	// enable uart clock
	RCC_APB1ENR |= (1U << 17);

	// set baud rate
	setBaudRate(SYS_CLK_FREQ, BAUD_RATE);

	// set UART2 as transmitter
	USART2_CR1 |= (1U << 3);

	// enable uart
	USART2_CR1 |= (1U << 13);
}


void uartWriteByte(int byte)
{
	// wait until TXE is set, meaning UART is ready to transmit again
	while(!(USART2_SR & (1U << 7)));

	// transmit the masked byte
	USART2_DR = byte & 0xFF;
}


void uartWriteString(const char* msg)
{
	const char* tmp = msg;

	while(*tmp != '\0')
	{
		uartWriteByte(*tmp);
		++tmp;
	}

	uartWriteByte('\n');
	uartWriteByte('\r');
}



uint32_t computeBaudRate(uint32_t periph_clk, uint32_t baud_rate)
{
	return periph_clk / baud_rate;
}

void setBaudRate(uint32_t periph_clk, uint32_t baud_rate)
{
	USART2_BRR = computeBaudRate(periph_clk, baud_rate);
}

