add_library(include OBJECT
	common.c
	common.h
	memory.h
	peripheral.h
	)

target_include_directories(include PUBLIC ../include)

# Testing...