#include "common.h"
#include "../../vector_table.h"
#include "../../uart.h"
#include "../../stdio.h"
#include "../../musca-a.c"
#include "../../mpu/mpu.h"

void ctest(void)
{
	set_mpu_regions();
	uint32_t temp;
	READ_MEMORY(0xE000EDDC, temp);
	PRINT_HEX(temp);
    READ_MEMORY(0xE000EDE0, temp);
	PRINT_HEX(temp);
	return;
}
