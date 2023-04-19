cmake_minimum_required(VERSION 3.25)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_HOME_DIRECTORY}/toolchain.cmake )

project(Chapter_07_MPU C ASM)

option(DEBUG "about debug" ON)
option(QEMU_TEST "about qemu test" ON)

configure_file(config.h.in config.h)

add_subdirectory(main)
add_subdirectory(include)
add_subdirectory(uart)
add_subdirectory(libc)
add_subdirectory(armv8m)
add_subdirectory(vector_table)

add_executable(mpu.elf)

target_link_libraries(mpu.elf
	main
	include
	uart
	libc
	armv8m
	vector_table
)


add_custom_command(
	TARGET mpu.elf
	POST_BUILD
	COMMAND ${CMAKE_OBJCOPY}
	ARGS -O binary mpu.elf mpu.bin
)
add_custom_command(
	TARGET mpu.elf
	POST_BUILD
	COMMAND ${CMAKE_OBJDUMP}
	ARGS -D -s mpu.elf > mpu.lst
)
add_custom_command(
	TARGET mpu.elf
	POST_BUILD
	COMMAND ${CMAKE_READELF}
	ARGS -a mpu.elf > mpu_readelf.txt
)
