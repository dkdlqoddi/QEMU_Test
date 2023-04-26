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
	for (uint32_t IRQn = 0; IRQn < MAX_INTERRUPT_MUSCA; IRQn++)
	{
		continue;
	}
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
	__asm__ volatile (
		"movs r2, #2\n\t"
		"blx %0" ::"r"(0x1):
	);

	/* Call BusFault_Handler */
	temp = (uint32_t *)0xFFFFFFFFUL;
	*temp = 0xFFFFFFFFU;

	/* Call UsageFault Handler */
	__asm__("udf":::);

	/* Call SVC_Handler */
	__asm__("svc #0":::);

	/* Call DebugMon_Handler TODO */
	DebugMon_Handler_S();

	/* Call PendSV_Handler TODO */
	PendSV_Handler_S();

	/* Call SysTick Handler TODO */
	SysTick_Handler_S();
	return;
}