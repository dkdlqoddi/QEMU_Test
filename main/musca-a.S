	.syntax unified
	.arch	armv8-m.main

	.section	.text_NS
	.global		Reset_Handler_NS
Reset_Handler_NS:
	b		.

	.text
	.global		Reset_Handler_S
Reset_Handler_S:
	bl		cstart

_exit:
	b		.	/* Never Reached */

	.end
