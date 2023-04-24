#include <common.h>
#include "../vector_table.h"
#include "../../uart/uart.h"
#include "../../libc/stdio.h"
#include "../../mpu/mpu.h"

void ctest(void)
{
	set_mpu_regions();
	uint32_t temp;
	READ_MEMORY(0xE000EDDC, temp);
	printf("%s\n", temp);
    READ_MEMORY(0xE000EDE0, temp);
	printf("%s\n", temp);
	return;
}
