#include "uart.h"

void enable_uart(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_LCR);
	write_register(offset, UART_CR, data | UART_CR_UARTEN);
	return;
}
void disable_uart(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_LCR);
	write_register(offset, UART_CR, data & ~UART_CR_UARTEN);
	return;
}
void enable_uart_fifo(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_LCR);
	write_register(offset, UART_LCR, data | UART_LCR_FEN);
	return;
}
void disable_uart_fifo(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_LCR);
	write_register(offset, UART_LCR, data & ~UART_LCR_FEN);
	return;
}
void set_uart_baudrate(uint32_t clk, uint32_t baudrate)
{
	baudrate *= WORD_SIZE;
	uint32_t bauddiv_h = ((clk >> (32U - UART_FBRD_SHIFT)) <<
							(32U - UART_FBRD_SHIFT)) / baudrate;
	uint64_t bauddiv = ((clk << UART_FBRD_SHIFT) / baudrate) + bauddiv_h;
	uint32_t offset = PERI_SECURE | UART0_OFFSET;

	/* Out of Bound */
	if ((bauddiv < (1U << UART_FBRD_SHIFT) || ((65535U << UART_FBRD_SHIFT) < bauddiv)))
	{
		/* TODO: Add Log Message*/
		return;
	}

	write_register(offset, UART_IBRD, UART_IBRD_MASK(bauddiv));
	write_register(offset, UART_FBRD, UART_FBRD_MASK(bauddiv));
	__DMB();

	/**
	 * In order to internally update the contents of ibrd or fbrd,
	 * a lcr_h write mush always be performed at the end.
	 * [ARM DDI 0183F, Page 3-13]
	 */
	uint32_t data = read_register(offset, UART_LCR);
	write_register(offset, UART_LCR, data);
	return;
}
void init_uart_irq(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	write_register(offset, UART_IMSC, 0U);
	write_register(offset, UART_ICR, 0U);
	return;
}
void clear_uart_dma(void)
{
	write_register(PERI_SECURE | UART0_OFFSET, UART_DMACR, 0U);
	__ISB();
	return;
}
void clear_uart_cr(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_CR);
	data &= ~(UART_CR_CTSEN |
			  UART_CR_RTSEN |
			  UART_CR_SIREN);
	data |= (UART_CR_RXE | UART_CR_TXE);
	write_register(offset, UART_CR, data);
	__ISB();
	return;
}
void set_uart_default_character_format(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_LCR);
	data &= ~(UART_LCR_SPS |
			  UART_LCR_WLEN_MASK(0x3U) |
			  UART_LCR_EPS |
			  UART_LCR_PEN |
			  UART_LCR_BRK);
	data |= UART_LCR_WLEN_MASK(0x3U);
	write_register(offset, UART_LCR, data);
	return;
}

void set_uart_clock_frequency(void)
{
	return;
}

void init_uart(void)
{
	disable_uart();
	disable_uart_fifo();
	/* TODO: Set Clock & Baudrate */
	set_uart_baudrate(8000000, 115200);
	/* TODO: Set the default character format */
	set_uart_default_character_format();
	enable_uart_fifo();
	init_uart_irq();
	clear_uart_dma();
	clear_uart_cr();
	enable_uart();

	set_uart_clock_frequency();
	return;
}

/* Operations */
uint8_t uart_is_readable(void)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_CR);
	if (!(data & UART_CR_UARTEN) || (data & UART_CR_RXE))
	{
		return -1;
	}
	data = read_register(offset, UART_FR);
	return ((data & UART_FR_RXFE) == 0U);
}
void uart_poll_in(int8_t *c)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	if (!uart_is_readable())
	{
		return;
	}
	*c = (int8_t)read_register(offset, UART_RSR_ECR);
	return;
}
void uart_poll_out(int8_t c)
{
	uint32_t offset = PERI_SECURE | UART0_OFFSET;
	uint32_t data = read_register(offset, UART_FR);
	while (data & UART_FR_TXFF)
	{
		data = read_register(offset, UART_FR);
	}
	write_register(offset, UART_DR, (uint32_t)c);
	return;
}
