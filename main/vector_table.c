#include "vector_table.h"

#define UART_ON
#define DEBUG

volatile void (*IRQ_NS[NUMBER_OF_IRQ]) (void)	SECTION(INTERRUPT_TABLE_NS_SECTION)	= { 0 };
volatile void (*IRQ_S[NUMBER_OF_IRQ]) (void)	SECTION(INTERRUPT_TABLE_S_SECTION)	= { 0 };

void
set_IRQ (void (*irq) (void), uint32_t num)
{
	return;
}

/* Contents of Vector Table (Non-Secure) */
void NMI_Handler_NS(void)
{
	/**
	 * NMI Handler
	 * Exception Number	: 2
	 * Priority		: -1
	 */
#ifdef UART_ON
	printf("NMI_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void HardFault_Handler_NS(void)
{
	/**
	 * Hard Fault Handler
	 * Exception Number	: 3
	 * Priority		: -1
	 */
#ifdef UART_ON
	printf("HardFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void MemManage_Handler_NS(void)
{
	/**
	 * MPU Fault Handler
	 * Exception Number	: 4
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("MemManage_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void BusFault_Handler_NS(void)
{
	/**
	 * Bus Fault Handler
	 * Exception Number	: 5
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("BusFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void UsageFault_Handler_NS(void)
{
	/**
	 * Usage Fault Handler
	 * Exception Number	: 6
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("UsageFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void SecureFault_Handler_NS(void)
{
	/**
	 * Secure Fault Handler
	 * Exception Number	: 7
	 * Priority			: (Programmable)
	 */
#ifdef UART_ON
	printf("SecureFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	 return;
}
void Reserved_Handler_NS(void)
{
	/**
	 * Reserved
	 * Exception Number	: 8-10, 13
	 * Priority		: NA
	 */
#ifdef UART_ON
	printf("Reserved_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void SVC_Handler_NS(void)
{
	/**
	 * SVCall Handler
	 * Exception Number	: 11
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("SVC_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void DebugMon_Handler_NS(void)
{
	/**
	 * Debug Monitor Handler
	 * Exception Number	: 12
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("DebugMon_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void PendSV_Handler_NS(void)
{
	/**
	 * PendSV Handler
	 * Exception Number	: 14
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("PendSV_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void SysTick_Handler_NS(void)
{
	/**
	 * SysTick Handler
	 * Exception Number	: 15
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("SysTick_Handler_NS!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
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
#ifdef UART_ON
	printf("NMI_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void HardFault_Handler_S(void)
{
	/**
	 * Hard Fault Handler
	 * Exception Number	: 3
	 * Priority			: -1
	 */
#ifdef UART_ON
	printf("HardFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void MemManage_Handler_S(void)
{
	/**
	 * MPU Fault Handler
	 * Exception Number	: 4
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("MemManage_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void BusFault_Handler_S(void)
{
	/**
	 * Bus Fault Handler
	 * Exception Number	: 5
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("BusFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void UsageFault_Handler_S(void)
{
	/**
	 * Usage Fault Handler
	 * Exception Number	: 6
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("UsageFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void SecureFault_Handler_S(void)
{
	/**
	 * @brief Secure Fault Handler
	 * Exception Number	: 7
	 * Priority			: (Programmable)
	 */
#ifdef UART_ON
	printf("SecureFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	 return;
}
void Reserved_Handler_S(void)
{
	/**
	 * Reserved
	 * Exception Number	: 8-10, 13
	 * Priority		: NA
	 */
#ifdef UART_ON
	printf("Reserved_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void SVC_Handler_S(void)
{
	/**
	 * SVCall Handler
	 * Exception Number	: 11
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("SVC_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void DebugMon_Handler_S(void)
{
	/**
	 * Debug Monitor Handler
	 * Exception Number	: 12
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("DebugMon_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void PendSV_Handler_S(void)
{
	/**
	 * PendSV Handler
	 * Exception Number	: 14
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("PendSV_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}
void SysTick_Handler_S(void)
{
	/**
	 * SysTick Handler
	 * Exception Number	: 15
	 * Priority		: (Programmable)
	 */
#ifdef UART_ON
	printf("SysTick_Handler_S!!\n");
	EXCEPTION_RETURN_PC_TWO;
#else
	EXCEPTION_RETURN_PC_ONE;
#endif
#ifndef DEBUG
	while (1);
#endif
	return;
}

/* Operation */
void enable_exceptions(void)
{
	set_exceptions();
	__NVIC_SetPriorityGrouping(4U);
	set_vector_table_offset(SCB->VTOR);
	set_all_interrupts_priority();
	set_all_interrupts();
}
void set_exceptions(void)
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
void set_all_interrupts_priority(void)
{
	__NVIC_SetPriority(Interrupt0_IRQn, 0U);
	__NVIC_SetPriority(Interrupt1_IRQn, 1U);
	__NVIC_SetPriority(Interrupt2_IRQn, 2U);
	__NVIC_SetPriority(Interrupt3_IRQn, 3U);
	__NVIC_SetPriority(Interrupt4_IRQn, 4U);
	__NVIC_SetPriority(Interrupt5_IRQn, 5U);
	__NVIC_SetPriority(Interrupt6_IRQn, 6U);
	__NVIC_SetPriority(Interrupt7_IRQn, 7U);
	__NVIC_SetPriority(Interrupt8_IRQn, 8U);
	__NVIC_SetPriority(Interrupt9_IRQn, 9U);
	return;
}
void set_all_interrupts(void)
{
	__NVIC_EnableIRQ(Interrupt0_IRQn);
	__NVIC_EnableIRQ(Interrupt1_IRQn);
	__NVIC_EnableIRQ(Interrupt2_IRQn);
	__NVIC_EnableIRQ(Interrupt3_IRQn);
	__NVIC_EnableIRQ(Interrupt4_IRQn);
	__NVIC_EnableIRQ(Interrupt5_IRQn);
	__NVIC_EnableIRQ(Interrupt6_IRQn);
	__NVIC_EnableIRQ(Interrupt7_IRQn);
	__NVIC_EnableIRQ(Interrupt8_IRQn);
	__NVIC_EnableIRQ(Interrupt9_IRQn);
	return;
}
void check_all_exceptions(void)
{
	/* Exception Test */
	uint32_t *temp;

	/* Call Reset_Handler*/
	//request_system_reset();
	//SCB->AIRCR |= 0x0000000CU;

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

	/* Call DebugMon_Handler TODO */
	DebugMon_Handler_S();

	/* Call PendSV_Handler TODO */
	PendSV_Handler_S();

	/* Call SysTick Handler TODO */
	// SysTick Control and Status Register
	//uint32_t *SYST_SCSR;
	//SYST_SCSR = (uint32_t *)0xE000E010UL;
	//*SYST_SCSR = 0x00000007U;
	SysTick_Handler_S();
	return;
}
void request_system_reset(void)
{
	uint32_t temp = read_register(0x00000000, 0xE000ED0C);
	temp |= 0x00000004U;
	write_register(0x00000000, 0xE000ED0C, temp);
	return;
}