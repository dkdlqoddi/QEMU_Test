#ifndef __COMMON__
#define __COMMON__

/* Read/Write Definitions */
#define		__RO	volatile const	/* 'Read Only' Permissions	*/
#define		__WO	volatile		/* 'Write Only' Permissions	*/
#define		__RW	volatile		/* 'Read/Write' Permissions	*/

/* Type Casting */
/*	Unsigned Type */
typedef unsigned char		uint8_t;
typedef unsigned short		uint16_t;
typedef	unsigned int		uint32_t;
typedef unsigned long long	uint64_t;
/*	Signed Type */
typedef	char		int8_t;
typedef short		int16_t;
typedef int			int32_t;
typedef long long	int64_t;
/* Data Type */
#define DOUBLE_WORD_SIZE	(64U)
#define WORD_SIZE			(32U)
#define HALF_WORD_SIZE		(16U)
#define BYTE_SIZE			(8U)
#define BIT_SIZE			(1U)
#define BIT(loc)			(1U << (loc % 32U))
/* va_list */
typedef __builtin_va_list va_list;
#define va_start(ap, param)	__builtin_va_start(ap, param)
#define va_end(ap)			__builtin_va_end(ap)
#define va_arg(ap, type)	__builtin_va_arg(ap, type)
#define va_copy(dest, src)	__builtin_va_copy(dest, src)

/* Log */
#define LOG_SIZE	(16)
#define LOG_LOOP	(4)

/* Section */
#define SECTION(section)	__attribute__ ((__section__ (section)))

/* Debugging Macros */
#define DEBUG_USING_R0(data)	\
	__asm__(			\
		"mov r0, %0"	\
		:				\
		: "r"(data)		\
		:				\
	)
#define DEBUG_USING_R1(data)	\
	__asm__(			\
		"mov r1, %0"	\
		:				\
		: "r"(data)		\
		:				\
	)

/* Memory/Register Control Macros */
#define	READ_MEMORY(addr, data)	\
	__asm__(			\
		"ldr %0, [%1]"	\
		: "=r"(data)	\
		: "r"(addr)		\
		:				\
	);
#define	WRITE_MEMORY(addr, data)	\
	__asm__(					\
		"str %0, [%1]"			\
		:						\
		: "r"(data), "r"(addr)	\
		:						\
	);

/* Exception Change Return Address */
#define CHANGE_RETURN_ADDRESS	\
	__asm__(					\
		"mov r1, sp\n\t"		\
		"add r1, #32\n\t"		\
		"mov r1, sp\n\t"		\
		"pop {r2}\n\t"			\
		"add r2, #4\n\t"		\
		"push {r2}\n\t"			\
		"sub r1, #32\n\t"		\
		"mov r1, sp" :::		\
	)

/* Barriers */
#define __DMB	__asm__("dmb sy" ::: "memory")	/* Data Memory Barrier	*/
#define __DSB	__asm__("dsb sy" ::: "memory")	/* Data Synchronization Barrier	*/
#define __ISB	__asm__("isb" ::: "memory")		/* Instruction Synchronization Barrier	*/

/* Log */
#define PRINT_HEX(hex)	printf("0x%X\n", hex)
#define print_hex(hex)	printf("0x%x\n", hex)

/* Global Memory/Register Control Functions */
/*	Read Operations */
uint32_t read_memory(uint32_t addr);
uint32_t read_register(uint32_t offset, uint32_t addr);
int8_t *read_non_secure_log(void);
int8_t *read_secure_log(void);
/*	Write Operations */
void write_memory(uint32_t addr, uint32_t data);
void write_register(uint32_t offset, uint32_t addr, uint32_t data);
void write_non_secure_log(int8_t *log);
void write_secure_log(int8_t *log);

#endif	// common.h
