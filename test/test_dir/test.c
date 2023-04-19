#include "common.h"
#include "../vector_table.h"
#include "../uart.h"
#include "../stdio.h"
#include "../musca-a.c"

void ctest(void)
{
	cstart();
	uint32_t temp;
	READ_MEMORY(0x10000000, temp);
	PRINT_HEX(temp);
	return;
}
