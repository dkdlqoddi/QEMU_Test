	.section	.vector_table_NS, "a"
	.align		2
	.global		_vector_table_NS
_vector_table_NS :
	.long	_MSP_NS					/* Top of Stack			*/
	.long	Reset_Handler_NS + 1	/* Reset Handler		*/
	.long	NMI_Handler_NS			/* NMI Handler			*/
	.long	HardFault_Handler_NS	/* Hard Fault Handler	*/
	.long	MemManage_Handler_NS	/* MPU Fault Handler	*/
	.long	BusFault_Handler_NS		/* Bus Fault Handler	*/
	.long	UsageFault_Handler_NS	/* Usage Fault Handler	*/
	.long	0						/* Reserved				*/
	.long	0						/* Reserved				*/
	.long	0						/* Reserved				*/
	.long	0						/* Reserved				*/
	.long	SVC_Handler_NS			/* SVCall Handler		*/
	.long	DebugMon_Handler_NS		/* Debug Monitor Handler*/
	.long	0						/* Reserved				*/
	.long	PendSV_Handler_NS		/* PendSV Handler		*/
	.long	SysTick_Handler_NS		/* SysTick Handler		*/

	.section	.vector_table_S, "a"
	.align		2
	.global		_vector_table_S
_vector_table_S :
	.long	_MSP_S					/* Top of Stack			*/
	.long	Reset_Handler_S + 1		/* Reset Handler		*/
	.long	NMI_Handler_S			/* NMI Handler			*/
	.long	HardFault_Handler_S		/* Hard Fault Handler	*/
	.long	MemManage_Handler_S		/* MPU Fault Handler	*/
	.long	BusFault_Handler_S		/* Bus Fault Handler	*/
	.long	UsageFault_Handler_S	/* Usage Fault Handler	*/
	.long	0						/* Reserved				*/
	.long	0						/* Reserved				*/
	.long	0						/* Reserved				*/
	.long	0						/* Reserved				*/
	.long	SVC_Handler_S			/* SVCall Handler		*/
	.long	DebugMon_Handler_S		/* Debug Monitor Handler*/
	.long	0						/* Reserved				*/
	.long	PendSV_Handler_S		/* PendSV Handler		*/
	.long	SysTick_Handler_S		/* SysTick Handler		*/

	.end
