/******************************************************************************
 * @file	musca-a.c
 * @brief	Musca-A0 Board Startup File for Cortex-M33 Device
 * @version  V1.0
 * @date     20. April 2023
 ******************************************************************************/

#include <common.h>
#include "vector_table.h"
//#include "../mpu/mpu.h"
#include "../uart/uart.h"
#include "../libc/stdio.h"
#include "../armv8m/ARMCM33.h"

void cstart(void)
{
	/* 1. Enable exception */
	enable_exceptions_and_interrupts();
	/* 2. Initialize the memory protection unit */
	set_mpu_regions();
	ARM_MPU_Enable(0b001U);
	/* 3. Initialize any critical I/O devices (UART) */
	init_uart();
	/* 4. Enable interrupts */

	/* Test */
	check_all_exceptions();

	return;
}
