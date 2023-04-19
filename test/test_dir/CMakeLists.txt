add_library(test_dir OBJECT
	test.c
	)

target_include_directories(test_dir PUBLIC ../../include)

# Testing...