ENTRY(Reset_Handler_S)
OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)

MEMORY
{
	SRAM_NS		(RWX) : ORIGIN = 0x00000000, LENGTH = 80K
	FLASH_NS	(RX)  : ORIGIN = 0x00200000, LENGTH = 256K
	SRAM_S		(RWX) : ORIGIN = 0x10000000, LENGTH = 80K
	FLASH_S 	(RX)  : ORIGIN = 0x10200000, LENGTH = 256K
}

_zero_table_size = 0x1000;

SECTIONS
{
	/* Non-Secure Regions */
	.vector_table_NS :
	{
		*(.vector_table_NS)
	} > FLASH_NS

    .IRQ_NS :
    {
        *(.IRQ_NS)
    } > FLASH_NS

	.text_NS :
	{
		*(.text_NS)
	} > FLASH_NS

	.data_NS :
	{
		*(.data_NS)
	} > FLASH_NS

	.bss_NS :
	{
		*(.bss_NS)
	} > FLASH_NS

	.zero.table_NS :
	{
		. += _zero_table_size;
		_MSP_NS = .;
	} > SRAM_NS

	.global_variable_NS :
	{
		*(.global_variable_NS)
	} > SRAM_NS

/***********************************************/
	/* Secure Regions */
	.vector_table :
	{
		*(.vector_table_S)
	} > FLASH_S

    .IRQ :
    {
        *(.IRQ_S)
    } > FLASH_S


	.text :
	{
		*(.text)
		*(.text_S)
	} > FLASH_S

	.data :
	{
		*(.data)
		*(.data_S)
	} > FLASH_S

	.bss :
	{
		*(.bss)
		*(.bss_S)
	} > FLASH_S

	.zero.table :
	{
		. += _zero_table_size;
		_MSP_S = .;
	} > SRAM_S

	.global_variable :
	{
		*(.global_variable)
		*(.global_variable_S)
	} > SRAM_S
}
