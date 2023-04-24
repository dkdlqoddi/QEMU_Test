#include <common.h>
#include "../vector_table.h"
#include "../../uart/uart.h"
#include "../../libc/stdio.h"

void ctest(void)
{
	init_uart();
	uint32_t temp = read_register(0x00000000U, 0xE000ED0CU);
	temp |= 0x00000004U;
	write_register(0x00000000U, 0xE000ED0CU, temp);
	temp = read_register(0x00000000U, 0xE000ED0CU);
	printf("%x\n", temp);
	return;
}
