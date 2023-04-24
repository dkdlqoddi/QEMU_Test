#ifndef __MPU__
#define __MPU__

#include <common.h>

void set_mpu_region(uint8_t idx,
					uint32_t base,
					uint8_t sh,
					uint8_t ro,
					uint8_t po,
					uint8_t xn,
					uint32_t limit);
void set_mpu_regions(void);

#endif	// mpu.h