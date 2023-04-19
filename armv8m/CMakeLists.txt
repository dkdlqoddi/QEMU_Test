add_library(armv8m OBJECT
	core_cm33.h
	cmsis_version.h
	)

target_include_directories(armv8m PUBLIC ../include)

# Testing...