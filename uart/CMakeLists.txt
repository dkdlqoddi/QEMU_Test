add_library(uart OBJECT
	uart.c
	uart.h
	)

target_include_directories(uart PUBLIC ../include)

# Testing...