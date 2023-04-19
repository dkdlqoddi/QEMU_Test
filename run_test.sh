#!/bin/sh
qemu-system-arm			\
	-M musca-a			\
	-cpu cortex-m33		\
	-kernel test.elf	\
	-gdb tcp::1236		\
	-nographic
