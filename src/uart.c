/* 
    Author: Rhythm Winicour-Freeman
    File: uart.c
    Description: Function implementations for uart.h
*/
#include "../inc/rcc.h"
#include "../inc/uart.h"
#include "../inc/gpio.h"

/* Bit Fields */


/* Helper function prototypes */
uint32_t computeBaudRate(uint32_t periph_clk, uint32_t baud_rate);
void setBaudRate(uint32_t periph_clk, uint32_t baud_rate);

void uartInit(void)
{
    // set PA2 to alternate function
	GPIOA_MODER &= ~MODER_PIN2_ANALOG; // clear P2 mode bits
	GPIOA_MODER |= MODER_PIN2_ALT; // set P2 as alt function (10)

	// set alt function as AF07 (0111) for UART2_TX
	GPIOA_AFRL &= ~AFRL_PIN2_AF15; // clear bits
	GPIOA_AFRL |= AFRL_PIN2_AF7; // set P2 as AF7

	// enable uart clock????
	

	// set baud rate
	setBaudRate(SYS_CLK_FREQ, BAUD_RATE);

	// set UART2 as transmitter
	USART2_CR1 |= USART_TX_EN;

	// enable uart
	USART2_CR1 |= USART_EN;
}


void uartWriteByte(int byte)
{
	// wait until TXE is set, meaning UART is ready to transmit again
	while(!(USART2_SR & USART_TXE));

	// transmit the masked byte
	USART2_DR = byte & 0xFF; // TODO: add a better/more detailed comment about why
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



/* Helper function implementations */
uint32_t computeBaudRate(uint32_t periph_clk, uint32_t baud_rate)
{
	return periph_clk / baud_rate;
}

void setBaudRate(uint32_t periph_clk, uint32_t baud_rate)
{
	USART2_BRR = computeBaudRate(periph_clk, baud_rate);
}

