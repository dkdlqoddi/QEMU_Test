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

# Output Files
ASM_FILES="${FILENAME}.S
		   vector_table.S"
HEADER_FILES="common.h
			  vector_table.h"
C_FILES="${FILENAME}.c
		 vector_table.c"
LDS="${FILENAME}.lds"
MAP="${FILENAME}.map"
ELF="${FILENAME}.elf"
READELF_TXT="readelf.txt"
OBJDUMP_TXT="objdump.txt"
BINARY_FILE="${FILENAME}.bin"

# QTest Files
QTEST_ELF_DIR="elf_dir"
QTEST_LOG_DIR="log_dir"

if [ "$1" == "clean" ]; then
	rm -v ${MAP}
	rm -v ${ELF}
	rm -v ${READELF_TXT}
	rm -v ${OBJDUMP_TXT}
	rm -v ${BINARY_FILE}
	rm -vr ${QTEST_ELF_DIR}
	rm -vr ${QTEST_LOG_DIR}
else
	${GCC}				\
		-march=${ARCH}	\
		-mtune=${CPU}	\
		${ASM_FILES}	\
		${HEADER_FILES}	\
		${C_FILES}		\
		-o ${ELF}		\
		-T ${LDS}		\
		-Wl,-Map=${MAP}	\
		${GCC_FLAGS}

	${READELF}				\
		-a ${ELF}			\
		> ${READELF_TXT}

	${OBJDUMP}				\
		-D -s ${ELF}		\
		> ${OBJDUMP_TXT}

	${OBJCOPY}				\
		-O binary ${ELF}	\
		${BINARY_FILE}
fi
