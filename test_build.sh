# Compiler Settings
#CROSS_COMPILER="arm-none-eabi-"
CROSS_COMPILER="/home1/jaeyul.woo/.local/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-"
FILENAME="musca-a"
ARCH="armv8-m.main"
CPU="cortex-m33"

# Command Settings
GCC="${CROSS_COMPILER}gcc"
READELF="${CROSS_COMPILER}readelf"
OBJDUMP="${CROSS_COMPILER}objdump"
OBJCOPY="${CROSS_COMPILER}objcopy"
GCC_FLAGS="-nostdlib -nostdinc -mthumb -g3 -Wno-builtin-declaration-mismatch"

# Test Files
TEST_FILES="test.S
			test_dir/$1.c
			vector_table.S
			vector_table.h
			vector_table.c
			common.h
			common.c
			memory.h
			uart.h
			uart.c
			stdio.h
			stdio.c"
LDS="musca-a.lds"
TEST_ELF="elf_dir/$1.elf"

if [ "$1" == "clean" ]; then
	rm -v ${TEST_ELF}
else
	${GCC}				\
		-march=${ARCH}	\
		-mtune=${CPU}	\
		${TEST_FILES}	\
		${HEADER_FILES}	\
		-o ${TEST_ELF}	\
		-T ${LDS}		\
		${GCC_FLAGS}
fi
