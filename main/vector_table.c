#include "vector_table.h"

#define UART_ON
#define DEBUG

volatile void (*IRQ_NS[NUMBER_OF_IRQ]) (void)	SECTION(INTERRUPT_TABLE_NS_SECTION)	= { 0 };
volatile void (*IRQ_S[NUMBER_OF_IRQ]) (void)	SECTION(INTERRUPT_TABLE_S_SECTION)	= { 0 };

/* Contents of Vector Table (Non-Secure) */
void NMI_Handler_NS(void)
{
	/**
	 * NMI Handler
	 * Exception Number	: 2
	 * Priority		: -1
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("NMI_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void HardFault_Handler_NS(void)
{
	/**
	 * Hard Fault Handler
	 * Exception Number	: 3
	 * Priority		: -1
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("HardFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void MemManage_Handler_NS(void)
{
	/**
	 * MPU Fault Handler
	 * Exception Number	: 4
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("MemManage_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void BusFault_Handler_NS(void)
{
	/**
	 * Bus Fault Handler
	 * Exception Number	: 5
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("BusFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void UsageFault_Handler_NS(void)
{
	/**
	 * Usage Fault Handler
	 * Exception Number	: 6
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("UsageFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void SecureFault_Handler_NS(void)
{
	/**
	 * Secure Fault Handler
	 * Exception Number	: 7
	 * Priority			: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("SecureFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	 POP_REGISTERS;
	return;
}
void Reserved_Handler_NS(void)
{
	/**
	 * Reserved
	 * Exception Number	: 8-10, 13
	 * Priority		: NA
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("Reserved_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void SVC_Handler_NS(void)
{
	/**
	 * SVCall Handler
	 * Exception Number	: 11
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("SVC_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void DebugMon_Handler_NS(void)
{
	/**
	 * Debug Monitor Handler
	 * Exception Number	: 12
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("DebugMon_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void PendSV_Handler_NS(void)
{
	/**
	 * PendSV Handler
	 * Exception Number	: 14
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("PendSV_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void SysTick_Handler_NS(void)
{
	/**
	 * SysTick Handler
	 * Exception Number	: 15
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("SysTick_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}

/* Contents of Vector Table (Secure) */
void NMI_Handler_S(void)
{
	/**
	 * NMI Handler
	 * Exception Number	: 2
	 * Priority			: -1
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("NMI_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void HardFault_Handler_S(void)
{
	/**
	 * Hard Fault Handler
	 * Exception Number	: 3
	 * Priority			: -1
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("HardFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void MemManage_Handler_S(void)
{
	/**
	 * MPU Fault Handler
	 * Exception Number	: 4
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("MemManage_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void BusFault_Handler_S(void)
{
	/**
	 * Bus Fault Handler
	 * Exception Number	: 5
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("BusFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void UsageFault_Handler_S(void)
{
	/**
	 * Usage Fault Handler
	 * Exception Number	: 6
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("UsageFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void SecureFault_Handler_S(void)
{
	/**
	 * @brief Secure Fault Handler
	 * Exception Number	: 7
	 * Priority			: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("SecureFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	 POP_REGISTERS;
	return;
}
void Reserved_Handler_S(void)
{
	/**
	 * Reserved
	 * Exception Number	: 8-10, 13
	 * Priority		: NA
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("Reserved_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void SVC_Handler_S(void)
{
	/**
	 * SVCall Handler
	 * Exception Number	: 11
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("SVC_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void DebugMon_Handler_S(void)
{
	/**
	 * Debug Monitor Handler
	 * Exception Number	: 12
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("DebugMon_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void PendSV_Handler_S(void)
{
	/**
	 * PendSV Handler
	 * Exception Number	: 14
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("PendSV_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}
void SysTick_Handler_S(void)
{
	/**
	 * SysTick Handler
	 * Exception Number	: 15
	 * Priority		: (Programmable)
	 */
	PUSH_REGISTERS;
#ifdef UART_ON
	printf("SysTick_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	POP_REGISTERS;
	return;
}

/* Operation */
#define MAX_INTERRUPT_MUSCA	(78)
void enable_exceptions_and_interrupts(void)
{
	uint32_t *get_vtor;
	enable_exceptions();
	__NVIC_SetPriorityGrouping(4U);
	set_vector_table_offset(SCB->VTOR);
	set_priority_all_interrupts();
	allocate_all_interrupts();
	enable_all_interrupts();
	read_priority_all_interrupts();
	read_enabled_all_interrupts();
}
void enable_exceptions(void)
{
	SCB->SHCSR |= SCB_SHCSR_SECUREFAULTENA_Msk	\
				| SCB_SHCSR_USGFAULTENA_Msk		\
				| SCB_SHCSR_BUSFAULTENA_Msk		\
				| SCB_SHCSR_MEMFAULTENA_Msk;
	return;
}
void set_vector_table_offset(uint32_t addr)
{
	SCB->VTOR = (addr & SCB_VTOR_TBLOFF_Msk);
	return;
}
void set_priority_all_interrupts(void)
{
	for (uint32_t IRQn = 0; IRQn < MAX_INTERRUPT_MUSCA; IRQn++)
	{
		//NVIC->IPR[IRQn] = (uint8_t)((priority << (8U - __NVIC_PRIO_BITS)) & (uint32_t)0xFFUL);
		NVIC->IPR[IRQn] = (uint8_t)(IRQn & 0xFFU);
	}
	return;
}
void read_priority_all_interrupts(void)
{
	uint32_t temp;
	for (uint32_t IRQn = 0; IRQn < MAX_INTERRUPT_MUSCA; IRQn++)
	{
		temp = NVIC->IPR[IRQn];
		printf("Priority of IRQ[%d] = %d\n", temp, temp);
	}
	return;
}
void allocate_all_interrupts(void)
{
	/* Contents of Interrupt Table (Non-Secure) */
	IRQ_NS[0] = NMI_Handler_NS;
	IRQ_NS[1] = Watchdog_Reset_Request_NS;
	IRQ_NS[2] = Watchdog_Interrupt_NS;
	IRQ_NS[3] = S32K_Timer_Interrupt_NS;
	IRQ_NS[4] = Timer0_Interrupt_NS;
	IRQ_NS[5] = Timer1_Interrupt_NS;
	IRQ_NS[6] = Dual_Timer_Interrupt_NS;
	IRQ_NS[7] = Message_Handling_Unit0_CPU0_Interrupt_NS;
	IRQ_NS[8] = Message_Handling_Unit1_CPU0_Interrupt_NS;
	IRQ_NS[9] = Reserved_Interrupt_NS;
	IRQ_NS[10] = MPU_Combined_NS;
	IRQ_NS[11] = PPC_Combined_NS;
	IRQ_NS[12] = MSC_Combined_NS;
	IRQ_NS[13] = Bridge_Error_Combined_Interrupt_NS;
	IRQ_NS[14] = CPU0_Instruction_Cache_Invalidation_Interrupt_NS;
	IRQ_NS[15] = Reserved_Interrupt_NS;
	IRQ_NS[16] = SYS_PPU_NS;
	IRQ_NS[17] = CPU0_PPU_NS;
	IRQ_NS[18] = CPI1_PPU_NS;
	IRQ_NS[19] = CPU0DBG_PPU_NS;
	IRQ_NS[20] = CPU1DBG_PPU_NS;
	IRQ_NS[21] = Reserved_Interrupt_NS;
	IRQ_NS[22] = Reserved_Interrupt_NS;
	IRQ_NS[23] = RAM0_PPU_NS;
	IRQ_NS[24] = RAM1_PPU_NS;
	IRQ_NS[25] = RAM2_PPU_NS;
	IRQ_NS[26] = RAM3_PPU_NS;
	IRQ_NS[27] = DBG_PPU_NS;
	IRQ_NS[28] = Reserved_Interrupt_NS;
	IRQ_NS[29] = CPU0CTIIRQ0_NS;
	IRQ_NS[30] = CPU0CTIIRQ1_NS;
	IRQ_NS[31] = Reserved_Interrupt_NS;
	IRQ_NS[32] = Reserved_Interrupt_NS;
	IRQ_NS[33] = Reserved_Interrupt_NS;
	IRQ_NS[34] = GPTIMERINTR_NS;
	IRQ_NS[35] = I2C0INTR_NS;
	IRQ_NS[36] = I2C1INTR_NS;
	IRQ_NS[37] = I2SINTR_NS;
	IRQ_NS[38] = SPIINTR_NS;
	IRQ_NS[39] = QSPIINTR_NS;
	IRQ_NS[40] = UARTRXINTR0_NS;
	IRQ_NS[41] = UARTTXINTR0_NS;
	IRQ_NS[42] = UARTRTINTR0_NS;
	IRQ_NS[43] = UARTMSINTR0_NS;
	IRQ_NS[44] = UARTEINTR0_NS;
	IRQ_NS[45] = UARTINTR0_NS;
	IRQ_NS[46] = UARTRXINTR1_NS;
	IRQ_NS[47] = UARTTXINTR1_NS;
	IRQ_NS[48] = UARTRTINTR1_NS;
	IRQ_NS[49] = UARTMSINTR1_NS;
	IRQ_NS[50] = UARTEINTR1_NS;
	IRQ_NS[51] = UARTINTR1_NS;
	IRQ_NS[52] = GPIOINT0_NS;
	IRQ_NS[53] = GPIOINT1_NS;
	IRQ_NS[54] = GPIOINT2_NS;
	IRQ_NS[55] = GPIOINT3_NS;
	IRQ_NS[56] = GPIOINT4_NS;
	IRQ_NS[57] = GPIOINT5_NS;
	IRQ_NS[58] = GPIOINT6_NS;
	IRQ_NS[59] = GPIOINT7_NS;
	IRQ_NS[60] = GPIOINT8_NS;
	IRQ_NS[61] = GPIOINT9_NS;
	IRQ_NS[62] = GPIOINT10_NS;
	IRQ_NS[63] = GPIOINT11_NS;
	IRQ_NS[64] = GPIOINT12_NS;
	IRQ_NS[65] = GPIOINT13_NS;
	IRQ_NS[66] = GPIOINT14_NS;
	IRQ_NS[67] = GPIOINT15_NS;
	IRQ_NS[68] = COMBINT_NS;
	IRQ_NS[69] = Reserved_Interrupt_NS;
	IRQ_NS[70] = Reserved_Interrupt_NS;
	IRQ_NS[71] = PWMINT0_NS;
	IRQ_NS[72] = RTCINT_NS;
	IRQ_NS[73] = GPTIMERINT1_NS;
	IRQ_NS[74] = GPTIMERINT0_NS;
	IRQ_NS[75] = PWMINT1_NS;
	IRQ_NS[76] = PWMINT2_NS;
	IRQ_NS[77] = IOMUX_INTR_NS;

	/* Contents of Interrupt Table (Secure) */
	IRQ_S[0] = NMI_Handler_S;
	IRQ_S[1] = Watchdog_Reset_Request_S;
	IRQ_S[2] = Watchdog_Interrupt_S;
	IRQ_S[3] = S32K_Timer_Interrupt_S;
	IRQ_S[4] = Timer0_Interrupt_S;
	IRQ_S[5] = Timer1_Interrupt_S;
	IRQ_S[6] = Dual_Timer_Interrupt_S;
	IRQ_S[7] = Message_Handling_Unit0_CPU0_Interrupt_S;
	IRQ_S[8] = Message_Handling_Unit1_CPU0_Interrupt_S;
	IRQ_S[9] = Reserved_Interrupt_S;
	IRQ_S[10] = MPU_Combined_S;
	IRQ_S[11] = PPC_Combined_S;
	IRQ_S[12] = MSC_Combined_S;
	IRQ_S[13] = Bridge_Error_Combined_Interrupt_S;
	IRQ_S[14] = CPU0_Instruction_Cache_Invalidation_Interrupt_S;
	IRQ_S[15] = Reserved_Interrupt_S;
	IRQ_S[16] = SYS_PPU_S;
	IRQ_S[17] = CPU0_PPU_S;
	IRQ_S[18] = CPI1_PPU_S;
	IRQ_S[19] = CPU0DBG_PPU_S;
	IRQ_S[20] = CPU1DBG_PPU_S;
	IRQ_S[21] = Reserved_Interrupt_S;
	IRQ_S[22] = Reserved_Interrupt_S;
	IRQ_S[23] = RAM0_PPU_S;
	IRQ_S[24] = RAM1_PPU_S;
	IRQ_S[25] = RAM2_PPU_S;
	IRQ_S[26] = RAM3_PPU_S;
	IRQ_S[27] = DBG_PPU_S;
	IRQ_S[28] = Reserved_Interrupt_S;
	IRQ_S[29] = CPU0CTIIRQ0_S;
	IRQ_S[30] = CPU0CTIIRQ1_S;
	IRQ_S[31] = Reserved_Interrupt_S;
	IRQ_S[32] = Reserved_Interrupt_S;
	IRQ_S[33] = Reserved_Interrupt_S;
	IRQ_S[34] = GPTIMERINTR_S;
	IRQ_S[35] = I2C0INTR_S;
	IRQ_S[36] = I2C1INTR_S;
	IRQ_S[37] = I2SINTR_S;
	IRQ_S[38] = SPIINTR_S;
	IRQ_S[39] = QSPIINTR_S;
	IRQ_S[40] = UARTRXINTR0_S;
	IRQ_S[41] = UARTTXINTR0_S;
	IRQ_S[42] = UARTRTINTR0_S;
	IRQ_S[43] = UARTMSINTR0_S;
	IRQ_S[44] = UARTEINTR0_S;
	IRQ_S[45] = UARTINTR0_S;
	IRQ_S[46] = UARTRXINTR1_S;
	IRQ_S[47] = UARTTXINTR1_S;
	IRQ_S[48] = UARTRTINTR1_S;
	IRQ_S[49] = UARTMSINTR1_S;
	IRQ_S[50] = UARTEINTR1_S;
	IRQ_S[51] = UARTINTR1_S;
	IRQ_S[52] = GPIOINT0_S;
	IRQ_S[53] = GPIOINT1_S;
	IRQ_S[54] = GPIOINT2_S;
	IRQ_S[55] = GPIOINT3_S;
	IRQ_S[56] = GPIOINT4_S;
	IRQ_S[57] = GPIOINT5_S;
	IRQ_S[58] = GPIOINT6_S;
	IRQ_S[59] = GPIOINT7_S;
	IRQ_S[60] = GPIOINT8_S;
	IRQ_S[61] = GPIOINT9_S;
	IRQ_S[62] = GPIOINT10_S;
	IRQ_S[63] = GPIOINT11_S;
	IRQ_S[64] = GPIOINT12_S;
	IRQ_S[65] = GPIOINT13_S;
	IRQ_S[66] = GPIOINT14_S;
	IRQ_S[67] = GPIOINT15_S;
	IRQ_S[68] = COMBINT_S;
	IRQ_S[69] = Reserved_Interrupt_S;
	IRQ_S[70] = Reserved_Interrupt_S;
	IRQ_S[71] = PWMINT0_S;
	IRQ_S[72] = RTCINT_S;
	IRQ_S[73] = GPTIMERINT1_S;
	IRQ_S[74] = GPTIMERINT0_S;
	IRQ_S[75] = PWMINT1_S;
	IRQ_S[76] = PWMINT2_S;
	IRQ_S[77] = IOMUX_INTR_S;
	return;
}
void enable_all_interrupts(void)
{
	for (uint32_t IRQn = 0; IRQn < MAX_INTERRUPT_MUSCA; IRQn++)
	{
		NVIC->ISER[(IRQn >> 5U)] = 1U << (IRQn & 0x1FU);
	}
	return;
}
void read_enabled_all_interrupts(void)
{
	uint32_t temp;
	for (uint32_t IRQn = 0; IRQn < MAX_INTERRUPT_MUSCA; IRQn++)
	{
		temp = (NVIC->ISER[(IRQn >> 5U)] & (1U << (IRQn & 0x1FU))) >> (IRQn & 0x1FU);
		if (temp)
		{
			printf("IRQ[%d] is Enabled\n", IRQn);
		}
		else
		{
			printf("IRQ[%d] is Disabled\n", IRQn);
		}
	}
	return;
}
void check_all_exceptions(void)
{
	/* Exception Test */
	uint32_t *temp;

	/* Call Reset_Handler TODO */

	/* Call NMI_Handler TODO */
	NMI_Handler_S();

	/* Call HardFault_Handler TODO */
	HardFault_Handler_S();

	/* Call MemManage_Handler */
	temp = (uint32_t *)0xA0000000UL;
	*temp = 0xFFFFFFFFU;

	/* Call BusFault_Handler */
	temp = (uint32_t *)0xFFFFFFFFUL;
	*temp = 0xFFFFFFFFU;

	/* Call UsageFault Handler */
	__asm__("udf":::);

	/* Call SVC_Handler */
	__asm__("svc #0":::);
	__asm__("svc #1":::);

	/* Call DebugMon_Handler TODO */
	DebugMon_Handler_S();

	/* Call PendSV_Handler TODO */
	PendSV_Handler_S();

	/* Call SysTick Handler TODO */
	SysTick_Handler_S();
	return;
}