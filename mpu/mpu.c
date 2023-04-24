#include "mpu.h"
#include <ARMCM33.h>

/**
 * TODO
 * Add MAIR Attirbutes
 */
void set_mpu_region(uint8_t idx,
					uint32_t base,
					uint8_t sh,
					uint8_t ro,
					uint8_t po,
					uint8_t xn,
					uint32_t limit)
{
	/**
	 * ARM_MPU_SetRegion(RNR, RBAR, RLAR)
	 *		RBAR
	 *			Base Address
	 *			Shareability
	 *			Read-Only
	 *			Non-Privileged
	 *			Execute Never
	 *		RLAR
	 *			Limit Address
	 *			Index
	 */
	ARM_MPU_SetRegion(idx,
					  ARM_MPU_RBAR(base,
								   sh,
								   ro,
								   po,
								   xn),
					  ARM_MPU_RLAR(limit,
								   idx));
	/**
	 * ARM_MPU_SetMemAttr(Index, Attribute)
	 * Attribute :
	 * 		Outer Memory Attributes
	 *			Non-Transient
	 *			Write-Back
	 *			Read Allocation
	 *			Write Allocation
	 * 		Device Memory Attributes or Inner Memory Attributes
	 */
	ARM_MPU_SetMemAttr(idx,
					   ARM_MPU_ATTR(ARM_MPU_ATTR_MEMORY_(1U,
					   									 1U,
														 1U,
														 1U),
									ARM_MPU_ATTR_MEMORY_(1U,
														 1U,
														 1U,
														 1U)));
	return;
}

void set_mpu_regions(void)
{
	/* Code Region				*/
	set_mpu_region(0U,
				   0x00000000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0x20000000U - 0x1U);
	/* SRAM Region				*/
	set_mpu_region(1U,
				   0x20000000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0x40000000U - 0x1U);
	/* Peripheral Region		*/
	set_mpu_region(2U,
				   0x40000000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0x60000000U - 0x1U);
	/* RAM						*/
	set_mpu_region(3U,
				   0x60000000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0xA0000000U - 0x1U);
	/* External Device			*/
	set_mpu_region(4U,
				   0xA0000000U,
				   ARM_MPU_SH_NON, 1U, 0U, 1U,
				   0xE0040000U - 0x1U);
	/* Device					*/
	set_mpu_region(5U,
				   0xE0040000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0xE0440000U - 0x1U);
	/* Private Peripheral Bus	*/
	set_mpu_region(6U,
				   0xE0044000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0xE0100000U - 0x1U);
	/* Vendor_SYS				*/
	set_mpu_region(7U,
				   0xE0100000U,
				   ARM_MPU_SH_NON, 0U, 0U, 0U,
				   0xFFFFFFFFU - 0x1U);
	/**
	 * [2] PRIVDEFENA	: Enables Privileged Access
	 * [1] HFMIENA		: Enables MPU during HardFault and NMI Handlers
	 * [0] ENABLE		: Enables MPU
	 */
	ARM_MPU_Enable(0b001U);
	return;
}