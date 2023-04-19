#ifndef __UART__
#define __UART__

#include <common.h>
#include <peripheral.h>

#define UART0_OFFSET	(0x00000000U)
#define UART1_OFFSET	(0x00001000U)

#define UART_BASE_MEMORY_ADDRESS	(0x40101000U)
#define UART_DR						(0x40101000U)	/* Data Register [RW]	*/
#define UART_RSR_ECR				(0x40101004U)	/* Receive Status Register/Error Clear Register [RW]	*/
#define UART_FR						(0x40101018U)	/* Flag Register [RO]	*/
#define UART_ILPR					(0x40101020U)	/* IrDA Low-Power Counter Register [RW]	*/
#define UART_IBRD					(0x40101024U)	/* Integer Baud Rate Register [RW]	*/
#define UART_FBRD					(0x40101028U)	/* Fractional Baud Rate Register [RW]	*/
#define UART_LCR					(0x4010102CU)	/* Line Control Register [RW]	*/
#define UART_CR						(0x40101030U)	/* Control Register [RW]	*/
#define UART_IFLS					(0x40101034U)	/* Interrupt FIFO Level Select Register [RW]	*/
#define UART_IMSC					(0x40101038U)	/* Interrupt Mask Set/Clear Register [RW]	*/
#define UART_RIS					(0x4010103CU)	/* Raw Interrupt Status Register [RO]	*/
#define UART_MIS					(0x40101040U)	/* Masked Interrupt Status Register [RO]	*/
#define UART_ICR					(0x40101044U)	/* Interrupt Clear Register [RO]	*/
#define UART_DMACR					(0x40101048U)	/* DMA Control Register [RW]	*/
#define UART_PERIPH_ID0				(0x40101FE0U)	/* UART Peripheral ID Register 0 [RO]	*/
#define UART_PERIPH_ID1				(0x40101FE4U)	/* UART Peripheral ID Register 1 [RO]	*/
#define UART_PERIPH_ID2				(0x40101FE4U)	/* UART Peripheral ID Register 2 [RO]	*/
#define UART_PERIPH_ID3				(0x40101FE4U)	/* UART Peripheral ID Register 3 [RO]	*/
#define UART_PCELL_ID0				(0x40101FF0U)	/* UART Component ID Register 0 [RO]	*/
#define UART_PCELL_ID1				(0x40101FF0U)	/* UART Component ID Register 1 [RO]	*/
#define UART_PCELL_ID2				(0x40101FF0U)	/* UART Component ID Register 2 [RO]	*/
#define UART_PCELL_ID3				(0x40101FF0U)	/* UART Component ID Register 3 [RO]	*/

/* Data Register [RW] */
/* Receive Status Register/Error Clear Register [RW] */

/* Flag Register [RO] */
#define UART_FR_RI		(0x00000100U)	/* Ring Indicator	*/
#define UART_FR_TXFE	(0x00000080U)	/* Transmit FIFO Empty	*/
#define UART_FR_RXFF	(0x00000040U)	/* Receive FIFO Full	*/
#define UART_FR_TXFF	(0x00000020U)	/* Transmit FIFO Full	*/
#define UART_FR_RXFE	(0x00000010U)	/* Receive FIFO Empty	*/
#define UART_FR_BUSY	(0x00000008U)	/* UART Busy	*/
#define UART_FR_DCD		(0x00000004U)	/* Data Carrier Detect	*/
#define UART_FR_DSR		(0x00000002U)	/* Data Set Ready	*/
#define UART_FR_CTS		(0x00000001U)	/* Clear To Send	*/

/* IrDA Low-Power Counter Register [RW] */
/* Integer Baud Rate Register [RW] */
#define UART_FBRD_SHIFT			(6U)
#define UART_IBRD_MASK(data)	(((data >> UART_FBRD_SHIFT) & 0x0000FFFFU) << 0U)
/* Fractional Baud Rate Register [RW] */
#define UART_FBRD_MASK(data)	((data & 0x0000003FU) << 0U)

/* Line Control Register [RW] */
#define UART_LCR_SPS	(0x00000080U)	/* Stick Parity Select	*/
#define UART_LCR_WLEN	(0x00000060U)	/* Word Length	*/
#define UART_LCR_WLEN_MASK(data)	((data & 0x3U) << 5U)
#define UART_LCR_FEN	(0x00000010U)	/* Enable FIFOs	*/
#define UART_LCR_STP2	(0x00000008U)	/* Two Stop Bits Select	*/
#define UART_LCR_EPS	(0x00000004U)	/* Even Parity Select	*/
#define UART_LCR_PEN	(0x00000002U)	/* Parity Enable	*/
#define UART_LCR_BRK	(0x00000001U)	/* Send Break	*/

/* Control Register [RW] */
#define UART_CR_CTSEN	(0x00008000U)	/* CTS Hardware Flow Control Enable	*/
#define UART_CR_RTSEN	(0x00004000U)	/* RTS Hardware Flow Control Enable	*/
#define UART_CR_OUT2	(0x00002000U)	/* Complement of the UART Out2 Modem Status Output	*/
#define UART_CR_OUT1	(0x00001000U)	/* Complement of the UART Out1 Modem Status Output	*/
#define UART_CR_RTS		(0x00000800U)	/* Request to Send	*/
#define UART_CR_DTR		(0x00000400U)	/* Data Transmit Ready	*/
#define UART_CR_RXE		(0x00000200U)	/* Receive Enable	*/
#define UART_CR_TXE		(0x00000100U)	/* Transmit Enable	*/
#define UART_CR_LBE		(0x00000080U)	/* Loopback Enable	*/
#define UART_CR_SIRLP	(0x00000004U)	/* SIR Low-Power IrDA Mode	*/
#define UART_CR_SIREN	(0x00000002U)	/* SIR Enable	*/
#define UART_CR_UARTEN	(0x00000001U)	/* UART Enable	*/

/* Interrupt FIFO Level Select Register [RW] */

/* Interrupt Mask Set/Clear Register [RW] */
#define UART_IMSR_OEIM		(0x00000400U)	/* Overrun Error Interrupt Mask	*/
#define UART_IMSR_BEIM		(0x00000200U)	/* Break Error Interrupt Mask	*/
#define UART_IMSR_PEIM		(0x00000100U)	/* Parity Error Interrupt Mask	*/
#define UART_IMSR_FEIM		(0x00000080U)	/* Framing Error Interrupt Mask	*/
#define UART_IMSR_RTIM		(0x00000040U)	/* Receive Timeout Interrupt Mask	*/
#define UART_IMSR_TXIM		(0x00000020U)	/* Transmit Interrupt Mask	*/
#define UART_IMSR_RXIM		(0x00000010U)	/* Receive Interrupt Mask	*/
#define UART_IMSR_DSRMIM	(0x00000008U)	/* nUARTDSR Modem Interrupt Mask	*/
#define UART_IMSR_DCDMIM	(0x00000004U)	/* nUARTDCD Modem Interrupt Mask	*/
#define UART_IMSR_CTSMIM	(0x00000002U)	/* nUARTCTS Modem Interrupt Mask	*/
#define UART_IMSR_RIMIM		(0x00000001U)	/* nUARTRI Modem Interrupt Mask	*/

/* Raw Interrupt Status Register [RO] */
/* Masked Interrupt Status Register [RO] */

/* Interrupt Clear Register [RO] */
#define UART_ICR_OEIC	(0x00000400U)	/* Overrun Error Interrupt Clear	*/
#define UART_ICR_BEIC	(0x00000200U)	/* Break Error Interrupt Clear	*/
#define UART_ICR_PEIC	(0x00000100U)	/* Parity Error Interrupt Clear	*/
#define UART_ICR_FEIC	(0x00000080U)	/* Framing Error Interrupt Clear	*/
#define UART_ICR_RTIC	(0x00000040U)	/* Receive Timeout Interrupt Clear	*/
#define UART_ICR_TXIC	(0x00000020U)	/* Transmit Interrupt Clear	*/
#define UART_ICR_RXIC	(0x00000010U)	/* Receive Interrupt Clear	*/
#define UART_ICR_DSRMIC	(0x00000008U)	/* nUARTDSR Modem Interrupt Clear	*/
#define UART_ICR_DCDMIC	(0x00000004U)	/* nUARTDCD Modem Interrupt Clear	*/
#define UART_ICR_CTSMIC	(0x00000002U)	/* nUARTCTS Modem Interrupt Clear	*/
#define UART_ICR_RIMIC	(0x00000001U)	/* nUARTRI Modem Interrupt Clear	*/

/* DMA Control Register [RW] */
#define UART_DMACR_DMAONERR	(0x00000004U)	/* DMA On Error	*/
#define UART_DMACR_TXDMAE	(0x00000002U)	/* Transmit DMA Enable	*/
#define UART_DMACR_RXDMAE	(0x00000001U)	/* Receive DMA Enable	*/

/* UART Peripheral ID Register 0 [RO] */
/* UART Peripheral ID Register 1 [RO] */
/* UART Peripheral ID Register 2 [RO] */
/* UART Peripheral ID Register 3 [RO] */
/* UART Component ID Register 0 [RO] */
/* UART Component ID Register 1 [RO] */
/* UART Component ID Register 2 [RO] */
/* UART Component ID Register 3 [RO] */

/* Enable UART0 */
void enable_uart(void);
void disable_uart(void);
void enable_uart_fifo(void);
void disable_uart_fifo(void);
void set_uart_baudrate(uint32_t clk, uint32_t baudrate);
void set_uart_default_character_format(void);
void init_uart_irq(void);
void clear_uart_dma(void);
void clear_uart_cr(void);
void set_uart_clock_frequency(void);
void init_uart(void);

/* Operations */
uint8_t uart_is_readable(void);
void uart_poll_in(int8_t *c);
void uart_poll_out(int8_t c);

#endif	// uart.h