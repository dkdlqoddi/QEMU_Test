#ifndef __INTERRUPT_TABLE
#define __INTERRUPT_TABLE

#include "../libc/stdio.h"

/* Contents of Interrupt Table (Non-Secure) */
void Watchdog_Reset_Request_NS(void);
void Watchdog_Interrupt_NS(void);
void S32K_Timer_Interrupt_NS(void);
void Timer0_Interrupt_NS(void);
void Timer1_Interrupt_NS(void);
void Dual_Timer_Interrupt_NS(void);
void Message_Handling_Unit0_CPU0_Interrupt_NS(void);
void Message_Handling_Unit1_CPU0_Interrupt_NS(void);
void MPU_Combined_NS(void);
void PPC_Combined_NS(void);
void MSC_Combined_NS(void);
void Bridge_Error_Combined_Interrupt_NS(void);
void CPU0_Instruction_Cache_Invalidation_Interrupt_NS(void);
void SYS_PPU_NS(void);
void CPU0_PPU_NS(void);
void CPI1_PPU_NS(void);
void CPU0DBG_PPU_NS(void);
void CPU1DBG_PPU_NS(void);
void RAM0_PPU_NS(void);
void RAM1_PPU_NS(void);
void RAM2_PPU_NS(void);
void RAM3_PPU_NS(void);
void DBG_PPU_NS(void);
void CPU0CTIIRQ0_NS(void);
void CPU0CTIIRQ1_NS(void);
void GPTIMERINTR_NS(void);	/* General Purpose Timer Interrupt	*/
void I2C0INTR_NS(void);		/* I2C0 Interrupt					*/
void I2C1INTR_NS(void);		/* I2C1 Interrupt					*/
void I2SINTR_NS(void);		/* I2S Interrupt					*/
void SPIINTR_NS(void);		/* SPI Interrupt					*/
void QSPIINTR_NS(void);		/* QSPI Interrupt					*/
void UARTRXINTR0_NS(void);	/* UART0 Receive FIFO Interrupt		*/
void UARTTXINTR0_NS(void);	/* UART0 Transmit FIFO Interrupt	*/
void UARTRTINTR0_NS(void);	/* UART0 Receive Timeout Interrupt	*/
void UARTMSINTR0_NS(void);	/* UART0 Modem Status Interrupt		*/
void UARTEINTR0_NS(void);	/* UART0 Error Interrupt			*/
void UARTINTR0_NS(void);	/* UART0 Interrupt					*/
void UARTRXINTR1_NS(void);	/* UART1 Receive FIFO Interrupt		*/
void UARTTXINTR1_NS(void);	/* UART1 Transmit FIFO Interrupt	*/
void UARTRTINTR1_NS(void);	/* UART1 Receive Timeout Interrupt	*/
void UARTMSINTR1_NS(void);	/* UART1 Modem Status Interrupt		*/
void UARTEINTR1_NS(void);	/* UART1 Error Interrupt			*/
void UARTINTR1_NS(void);	/* UART1 Interrupt					*/
void GPIOINT0_NS(void);		/* GPIO Interrupt					*/
void GPIOINT1_NS(void);		/* GPIO Interrupt					*/
void GPIOINT2_NS(void);		/* GPIO Interrupt					*/
void GPIOINT3_NS(void);		/* GPIO Interrupt					*/
void GPIOINT4_NS(void);		/* GPIO Interrupt					*/
void GPIOINT5_NS(void);		/* GPIO Interrupt					*/
void GPIOINT6_NS(void);		/* GPIO Interrupt					*/
void GPIOINT7_NS(void);		/* GPIO Interrupt					*/
void GPIOINT8_NS(void);		/* GPIO Interrupt					*/
void GPIOINT9_NS(void);		/* GPIO Interrupt					*/
void GPIOINT10_NS(void);	/* GPIO Interrupt					*/
void GPIOINT11_NS(void);	/* GPIO Interrupt					*/
void GPIOINT12_NS(void);	/* GPIO Interrupt					*/
void GPIOINT13_NS(void);	/* GPIO Interrupt					*/
void GPIOINT14_NS(void);	/* GPIO Interrupt					*/
void GPIOINT15_NS(void);	/* GPIO Interrupt					*/
void COMBINT_NS(void);		/* Combined Interurpt				*/
void PWMINT0_NS(void);		/* PWM0 Interrupt					*/
void RTCINT_NS(void);		/* RTC Interrupt					*/
void GPTIMERINT1_NS(void);	/* General Purpose Timer Interrupt1	*/
void GPTIMERINT0_NS(void);	/* General Purpose Timer Interrupt0 */
void PWMINT1_NS(void);		/* PWM1 Interrupt					*/
void PWMINT2_NS(void);		/* PWM2 Interrupt					*/
void IOMUX_INTR_NS(void);	/* IOMUX Interrupt					*/
void Reserved_Interrupt_NS(void);

/* Contents of Interrupt Table (Secure) */
void Watchdog_Reset_Request_S(void);
void Watchdog_Interrupt_S(void);
void S32K_Timer_Interrupt_S(void);
void Timer0_Interrupt_S(void);
void Timer1_Interrupt_S(void);
void Dual_Timer_Interrupt_S(void);
void Message_Handling_Unit0_CPU0_Interrupt_S(void);
void Message_Handling_Unit1_CPU0_Interrupt_S(void);
void MPU_Combined_S(void);
void PPC_Combined_S(void);
void MSC_Combined_S(void);
void Bridge_Error_Combined_Interrupt_S(void);
void CPU0_Instruction_Cache_Invalidation_Interrupt_S(void);
void SYS_PPU_S(void);
void CPU0_PPU_S(void);
void CPI1_PPU_S(void);
void CPU0DBG_PPU_S(void);
void CPU1DBG_PPU_S(void);
void RAM0_PPU_S(void);
void RAM1_PPU_S(void);
void RAM2_PPU_S(void);
void RAM3_PPU_S(void);
void DBG_PPU_S(void);
void CPU0CTIIRQ0_S(void);
void CPU0CTIIRQ1_S(void);
void GPTIMERINTR_S(void);	/* General Purpose Timer Interrupt	*/
void I2C0INTR_S(void);		/* I2C0 Interrupt					*/
void I2C1INTR_S(void);		/* I2C1 Interrupt					*/
void I2SINTR_S(void);		/* I2S Interrupt					*/
void SPIINTR_S(void);		/* SPI Interrupt					*/
void QSPIINTR_S(void);		/* QSPI Interrupt					*/
void UARTRXINTR0_S(void);	/* UART0 Receive FIFO Interrupt		*/
void UARTTXINTR0_S(void);	/* UART0 Transmit FIFO Interrupt	*/
void UARTRTINTR0_S(void);	/* UART0 Receive Timeout Interrupt	*/
void UARTMSINTR0_S(void);	/* UART0 Modem Status Interrupt		*/
void UARTEINTR0_S(void);	/* UART0 Error Interrupt			*/
void UARTINTR0_S(void);		/* UART0 Interrupt					*/
void UARTRXINTR1_S(void);	/* UART1 Receive FIFO Interrupt		*/
void UARTTXINTR1_S(void);	/* UART1 Transmit FIFO Interrupt	*/
void UARTRTINTR1_S(void);	/* UART1 Receive Timeout Interrupt	*/
void UARTMSINTR1_S(void);	/* UART1 Modem Status Interrupt		*/
void UARTEINTR1_S(void);	/* UART1 Error Interrupt			*/
void UARTINTR1_S(void);		/* UART1 Interrupt					*/
void GPIOINT0_S(void);		/* GPIO Interrupt					*/
void GPIOINT1_S(void);		/* GPIO Interrupt					*/
void GPIOINT2_S(void);		/* GPIO Interrupt					*/
void GPIOINT3_S(void);		/* GPIO Interrupt					*/
void GPIOINT4_S(void);		/* GPIO Interrupt					*/
void GPIOINT5_S(void);		/* GPIO Interrupt					*/
void GPIOINT6_S(void);		/* GPIO Interrupt					*/
void GPIOINT7_S(void);		/* GPIO Interrupt					*/
void GPIOINT8_S(void);		/* GPIO Interrupt					*/
void GPIOINT9_S(void);		/* GPIO Interrupt					*/
void GPIOINT10_S(void);		/* GPIO Interrupt					*/
void GPIOINT11_S(void);		/* GPIO Interrupt					*/
void GPIOINT12_S(void);		/* GPIO Interrupt					*/
void GPIOINT13_S(void);		/* GPIO Interrupt					*/
void GPIOINT14_S(void);		/* GPIO Interrupt					*/
void GPIOINT15_S(void);		/* GPIO Interrupt					*/
void COMBINT_S(void);		/* Combined Interurpt				*/
void PWMINT0_S(void);		/* PWM0 Interrupt					*/
void RTCINT_S(void);		/* RTC Interrupt					*/
void GPTIMERINT1_S(void);	/* General Purpose Timer Interrupt1	*/
void GPTIMERINT0_S(void);	/* General Purpose Timer Interrupt0 */
void PWMINT1_S(void);		/* PWM1 Interrupt					*/
void PWMINT2_S(void);		/* PWM2 Interrupt					*/
void IOMUX_INTR_S(void);	/* IOMUX Interrupt					*/
void Reserved_Interrupt_S(void);

#endif  // interrupt_table.h