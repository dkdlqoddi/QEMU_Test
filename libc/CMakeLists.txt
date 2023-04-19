add_library(libc OBJECT
	stdio.h
	stdio.c
	)

target_include_directories(libc PUBLIC ../include)

# Testing...