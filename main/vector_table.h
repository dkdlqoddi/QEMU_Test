#ifndef	__VECTOR_TABLE__
#define __VECTOR_TABLE__

#include <common.h>
#include "../armv8m/ARMCM33.h"
#include "../libc/stdio.h"

//"and r5, r5, %0\n\t"				\
		"sub r4, #4\n\t"					\

/* Exception Return MACRO */
#define EXCEPTION_RETURN_PC_TWO				\
	__asm__ volatile (						\
		"mov r4, sp\n\t"					\
		"add r4, #0x20\n\t"					\
		"ldr r5, [r4]\n\t"					\
		"add r5, #0x02\n\t"					\
		"str r5, [r4]" :::					\
	)
#define EXCEPTION_RETURN_PC_ONE				\
	__asm__ volatile (						\
		"mov r4, sp\n\t"					\
		"add r4, #0x1C\n\t"					\
		"ldr r5, [r4]\n\t"					\
		"add r5, #0x02\n\t"					\
		"str r5, [r4]" :::					\
	)

/* About Vector Table */
#define VECTOR_TABLE_NS_SECTION	".vector_table_NS"
#define VECTOR_TABLE_S_SECTION	".vector_table_S"
typedef struct
{
	__RW uint32_t Stack_Pointer;
	__RW uint32_t Reset_Handler;
	__RW uint32_t NMI_Handler;
	__RW uint32_t HardFault_Handler;
	__RW uint32_t MemManage_Handler;
	__RW uint32_t BusFault_Handler;
	__RW uint32_t UsageFault_Handler;
		 uint32_t Reserved0[4];
	__RW uint32_t SVC_Handler;
	__RW uint32_t DebugMon_Handler;
		 uint32_t Reserved1;
	__RW uint32_t PendSV_Handler;
	__RW uint32_t SysTick_Handler;
} Vector_Table;

/* About Interrupt Table */
#define INTERRUPT_TABLE_NS_SECTION	".IRQ_NS"
#define INTERRUPT_TABLE_S_SECTION	".IRQ_S"
#define NUMBER_OF_IRQ			(78)

/* Main Process */
void set_IRQ (void (*irq) (void), uint32_t num);

/* Contents of Vector Table (Non-Secure) */
void NMI_Handler_NS(void);			/* NMI Handler				*/
void HardFault_Handler_NS(void);	/* Hard Fault Handler		*/
void MemManage_Handler_NS(void);	/* MPU Fault Handler		*/
void BusFault_Handler_NS(void);		/* Bus Fault Handler		*/
void UsageFault_Handler_NS(void);	/* Usage Fault Handler		*/
void SecureFault_Handler_NS(void);	/* Secure Fault Handler		*/
void Reserved_Handler_NS(void);		/* Reserved					*/
void SVC_Handler_NS(void);			/* SVCall Handler			*/
void DebugMon_Handler_NS(void);		/* Debug Monitor Handler	*/
void PendSV_Handler_NS(void);		/* PendSV Handler			*/
void SysTick_Handler_NS(void);		/* SysTick Handler			*/

/* Contents of Vector Table (Secure) */
void NMI_Handler_S(void);			/* NMI Handler				*/
void HardFault_Handler_S(void);		/* Hard Fault Handler		*/
void MemManage_Handler_S(void);		/* MPU Fault Handler		*/
void BusFault_Handler_S(void);		/* Bus Fault Handler		*/
void UsageFault_Handler_S(void);	/* Usage Fault Handler		*/
void SecureFault_Handler_S(void);	/* Secure Fault Handler		*/
void Reserved_Handler_S(void);		/* Reserved					*/
void SVC_Handler_S(void);			/* SVCall Handler			*/
void DebugMon_Handler_S(void);		/* Debug Monitor Handler	*/
void PendSV_Handler_S(void);		/* PendSV Handler			*/
void SysTick_Handler_S(void);		/* SysTick Handler			*/

/* Operation */
void enable_exceptions(void);
void set_exceptions(void);
void set_vector_table_offset(uint32_t addr);
void set_all_interrupts_priority(void);
void set_all_interrupts(void);

void check_all_exceptions(void);

void request_system_reset(void);	/* SYSRESETREQ				*/

#endif	// vector_table.h