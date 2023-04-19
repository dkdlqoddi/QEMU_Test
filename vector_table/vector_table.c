#include "vector_table.h"

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
	//printf("NMI_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("HardFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("MemManage_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("BusFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("UsageFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("SecureFault_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("Reserved_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("SVC_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("DebugMon_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("PendSV_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("SysTick_Handler_NS!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("NMI_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("HardFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("MemManage_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("BusFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("UsageFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("SecureFault_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("Reserved_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("SVC_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("DebugMon_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("PendSV_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
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
	//printf("SysTick_Handler_S!!\n");
	EXCEPTION_RETURN_PC;
#ifndef DEBUG
	while (1);
#endif
	return;
}
