add_library(vector_table OBJECT
	vector_table.h
	vector_table.c
	vector_table.S
	)

target_include_directories(vector_table PUBLIC ../include)

# Testing...