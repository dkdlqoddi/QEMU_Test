#ifndef __MEMORY__
#define __MEMORY__

/* Code Region */
/* Non-Secure Region */
#define	SRAM0_NS		        (0x00000000U)
#define	SRAM1_NS		        (0x00080000U)
#define SRAM2_NS		        (0x00100000U)
#define SRAM3_NS		        (0x00180000U)
#define QSPI_MEMORY_NS		    (0x00200000U)
#define CODE_RESERVED0_NS	    (0x00A00000U)
#define	OTP_SECURE_REGISTERS_NS	(0x0E000000U)
#define CODE_RESERVED1_NS	    (0x0E000100U)
/* Secure Region */
#define SRAM0_S			        (0x10000000U)
#define SRAM1_S			        (0x10080000U)
#define	SRAM2_S			        (0x10100000U)
#define	SRAM3_S			        (0x10180000U)
#define QSPI_MEMORY_S		    (0x10200000U)
#define CODE_RESERVED0_S	    (0x10A00000U)
#define OTP_SECURE_REGISTERS_S	(0x1E000000U)
#define CODE_RESERVED1_S	    (0x1E000100U)

/* SRAM Region */
/* None-Secure Region */
#define INTERNAL_SRAM0_NS	(0x20000000U)
#define INTERNAL_SRAM1_NS	(0x20008000U)
#define INTERNAL_SRAM2_NS	(0x20010000U)
#define INTERNAL_SRAM3_NS	(0x20018000U)
#define SRAM_RESERVED_NS	(0x20020000U)
/* Secure Region */
#define INTERNAL_SRAM0_S	(0x30000000U)
#define INTERNAL_SRAM1_S	(0x30008000U)
#define INTERNAL_SRAM2_S	(0x30010000U)
#define INTERNAL_SRAM3_S	(0x30018000U)
#define SRAM_RESERVED_S		(0x30020000U)

/* Peripheral */
#define PERIPHERAL		(0x40000000U)

/* AHB5 Expansion 0 */
#define AHB5_EXPANSION0		(0x60000000U)

/* AHB5 Expansion 1 */
#define AHB5_EXPANSION1		(0x80000000U)

/* Syestem */
#define SYSTEM			(0xE0000000U)

/* Secure/Non-Secure */
#define SECURE_REGION		(0x00000000U)
#define NON_SECURE_REGION	(0x00020000U)

#endif	// memory.h