add_library(test OBJECT
	test.S
	)

add_subdirectory(test_dir)

target_include_directories(test PUBLIC ../include)

# Testing...