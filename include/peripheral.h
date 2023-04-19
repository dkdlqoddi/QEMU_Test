#ifndef __PERIPHERAL__
#define __PERIPHERAL__

#define PERI_NON_SECURE	(0x00000000U)
#define PERI_SECURE		(0x10000000U)

#define PERI_RESET_CTRL			(0x4010C000U)	/* RESET_CTRL Register [RW]		*/
#define PERI_CLK_CTRL			(0x4010C004U)	/* CLK_CTRL Register [RW]		*/
#define PERI_PLL_CTRL			(0x4010C00CU)	/* PLL_CTRL Register [RW]		*/
#define PERI_DBG_CTRL			(0x4010C010U)	/* DBG_CTRL Register [RW]		*/
#define PERI_INTR_CTRL			(0x4010C018U)	/* INTR_CTRL Register [RW]		*/
#define PERI_CPU0_VTOR_SRAM		(0x4010C020U)	/* CPU0_VTOR_SRAM Regsiter [RW]	*/
#define PERI_CPU1_VTOR_SRAM		(0x4010C020U)	/* CPU1_VTOR_SRAM Regsiter [RW]	*/
#define PERI_IOMUX_MAIN_INSEL	(0x4010)

/* RESET_CTRL	*/
/* Controls reset signals to test chip peripherals	*/
#define PERI_RESET_CTRL_OTPPSEL_EABLE	(0x00020000U)
#define PERI_RESET_CTRL_OTP_RESET		(0x00010000U)
#define PERI_RESET_CTRL_RTC_RESET		(0x00004000U)
#define PERI_RESET_CTRL_PWM2_RESET		(0x00002000U)
#define PERI_RESET_CTRL_PWM1_RESET		(0x00001000U)
#define PERI_RESET_CTRL_PWM0_RESET		(0x00000800U)
#define PERI_RESET_CTRL_GPIO_RESET		(0x00000200U)
#define PERI_RESET_CTRL_UART1_RESET		(0x00000100U)
#define PERI_RESET_CTRL_UART0_RESET		(0x00000080U)
#define PERI_RESET_CTRL_QSPI_RESET		(0x00000040U)
#define PERI_RESET_CTRL_SPI_RESET		(0x00000020U)
#define PERI_RESET_CTRL_I2S_RESET		(0x00000010U)
#define PERI_RESET_CTRL_I2C1_RESET		(0x00000008U)
#define PERI_RESET_CTRL_I2C0_RESET		(0x00000004U)
#define PERI_RESET_CTRL_GPTIMER_RESET	(0x00000002U)
#define PERI_RESET_CTRL_SCC_RESET		(0x00000001U)

/* CLK_CTRL	*/
/* Controls the test chip clocks and clock PLLS	*/
/* PLL_CTRL	*/
/* Controls the power and control signals to the PLLs in the test chip	*/
/* DBG_CTRL	*/
/* Controls the debug signals in the test chip	*/
/* INTR_CTRL	*/
/* Controls interrupt signals in the test chip	*/
/* CPU0_VTOR_SRAM	*/
/* Controls Core 0 reset vector signals in the test chip	*/

#endif  // peripheral.h