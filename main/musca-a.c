#include <common.h>
#include "../vector_table/vector_table.h"

void cstart(void)
{
	uint32_t temp = 0xFFFFFFFFU;
	WRITE_MEMORY(0x10000000, temp);
	READ_MEMORY(0x10000000, temp);
	return;
}
