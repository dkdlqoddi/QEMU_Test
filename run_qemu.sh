qemu-system-arm			\
	-M musca-a			\
	-cpu cortex-m33		\
	-kernel mpu.elf		\
	-S					\
	-gdb tcp::1236		\
	-nographic
