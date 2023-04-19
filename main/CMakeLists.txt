add_library(main OBJECT
	musca-a.S
	musca-a.c
	)

target_include_directories(main PUBLIC ../include)

# Testing...