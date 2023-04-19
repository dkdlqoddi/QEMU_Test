import subprocess
import os

class CMake_Variables():
	home_dir	= "${CMAKE_HOME_DIRECTORY}"
	objcopy		= "${CMAKE_OBJCOPY}"
	objdump		= "${CMAKE_OBJDUMP}"
	readelf		= "${CMAKE_READELF}"

class CMake_Builder():
	def __init__(self):
		# Basic Settings
		self.pwd			= os.getcwd()

		# cmake_minimum_required(VERSION {self.cmake_version})
		self.cmake_version	= "3.25"
		self.toolchain_name	= "toolchain.cmake"

		# set({self.set})
		self.set			= [
			# set({attribute} {name})
			["CMAKE_TOOLCHAIN_FILE", f"{CMake_Variables.home_dir}/{self.toolchain_name}"]
		]
		self.toolchain_name	= f"{CMake_Variables.home_dir}/toolchain.cmake"

		# project({self.project_name} {self.project_lang})
		self.project_name	= "Chapter_07_MPU"
		self.project_langs	= ["C", "ASM"]

		# option({self.option})
		self.option			= [
			# option({Variable_Name} "{Help_Text}" {Boolean_Value(ON/OFF)})\n
			["DEBUG",		"about debug",		"ON"],
			["QEMU_TEST",	"about qemu test",	"ON"],
		]

		# configure_file({self.config_in} {self.config_out})
		self.configure		= [
			["config.h.in", "config.h"],
		]

		# add_subdirectory({self.subdirectory})
		self.subdirectory_ignore_dirs	= ["test",
										   "CMakeFiles",]
		self.subdirectory_ignore_files	= ["config.h",]
		self.subdirectory_include_types	= [".S",
										   ".c",
										   ".h",]
		self.subdirectory				= self.__search_subdirectory()

		# target_link_libraries({self.target_name}.elf
		# 						{subdirectory})
		self.target_name	= "mpu"

		# target_include_directories({self.target_name}.elf {self.include_list})
		self.include_list	= []

		# add_custom_command(TARGET {self.target_name}.elf {self.command_list})
		self.generate_file	= []
		self.build_event	= [
			[f"{self.target_name}.elf", "POST_BUILD", CMake_Variables.objcopy, f"-O binary {self.target_name}.elf {self.target_name}.bin"],
			[f"{self.target_name}.elf", "POST_BUILD", CMake_Variables.objdump, f"-D -s {self.target_name}.elf > {self.target_name}.lst"],
			[f"{self.target_name}.elf", "POST_BUILD", CMake_Variables.readelf, f"-a {self.target_name}.elf > {self.target_name}_readelf.txt"],
		]

		# cmakedefine
		self.cmakedefine_list	= []

		# toolchain
		self.toolchain_list	= [
			["COMPILER_ROOT",			"/home1/jaeyul.woo/.local/gcc-arm-none-eabi-10.3-2021.10/bin/arm-none-eabi-"],
  			["CMAKE_ASM_COMPILER",		"${COMPILER_ROOT}gcc"],
			["CMAKE_C_COMPILER",		"${COMPILER_ROOT}gcc"],
			["CMAKE_LINKER",			"${COMPILER_ROOT}ld"],
			["CMAKE_NM",				"${COMPILER_ROOT}nm"],
			["CMAKE_OBJCOPY",			"${COMPILER_ROOT}objcopy"],
			["CMAKE_OBJDUMP",			"${COMPILER_ROOT}objdump"],
			["COMMON_FLAGS",			"\"-march=armv8-m.main -mtune=cortex-m33 -nostdlib -nostdinc -mthumb -g3 -Wno-builtin-declaration-mismatch\""],
			["CMAKE_ASM_FLAGS",			"\"-march=armv8-m.main -mtune=cortex-m33 -nostdlib -nostdinc -mthumb -g3 -Wno-builtin-declaration-mismatch\""],
			["CMAKE_C_FLAGS",			"\"-march=armv8-m.main -mtune=cortex-m33 -nostdlib -nostdinc -mthumb -g3 -Wno-builtin-declaration-mismatch\""],
			["LINKER_SCRIPT",			"${CMAKE_HOME_DIRECTORY}/musca-a.lds"],
			["CMAKE_EXE_LINKER_FLAGS",	"\"-T ${LINKER_SCRIPT} -N -Xlinker -Map=" + f"{self.target_name}.map\""],
		]
		return

	# Process
	def run(self):
		# Make File "CMakeLists.txt"
		self.fw = open("CMakeLists.txt", "w")
		self.__make_cmake_version()
		self.__make_set()
		self.__make_project()
		self.__make_option()
		self.__make_configure()
		self.__make_subdirectory()
		self.__make_executable()
		self.__make_target_link()
		self.__make_target_include()
		self.__make_custom_command()
		self.fw.close()
		# Make File "config.h.in"
		self.fw = open("config.h.in", "w")
		self.__make_cmakedefine()
		self.fw.close()
		# Make File "toolchain.cmake"
		self.fw = open("toolchain.cmake", "w")
		self.__make_toolchain()
		self.fw.close()
		return

	# Setter/Getter
	def set_project_name(self, name):
		self.project_name	= name
		return
	def set_target_name(self, name):
		self.target_name	= name
		return

	# Tools
	def __search_subdirectory(self):
		search_queue = ["."]
		result_list = []
		while (len(search_queue) != 0):
			current_dir = search_queue[0]
			included_list = []
			search_queue.pop(0)
			file_list = os.listdir(current_dir)
			for f in file_list:
				if (os.path.isfile(f"{current_dir}/{f}")):
					if (self.__is_included(f)):
						included_list.append(f)
				elif (f not in self.subdirectory_ignore_dirs):
					search_queue.append(f"{current_dir}/{f}")
			if (len(included_list) != 0):
				result_list.append([current_dir, included_list])
		return result_list
	def __is_included(self, filename):
		for i in self.subdirectory_include_types:
			if ((filename[-len(i):] == i) and (filename not in self.subdirectory_ignore_files)):
				return True
		return False
	
	# Build CMakeLists.txt
	def __make_cmake_version(self):
		self.fw.write(f"cmake_minimum_required(VERSION {self.cmake_version})\n")
		return
	def __make_set(self):
		self.fw.write("\n")
		for s in self.set:
			self.fw.write(f"set(")
			for c in s:
				self.fw.write(f"{c} ")
			self.fw.write(")\n")
		return
	def __make_project(self):
		self.fw.write("\n")
		self.fw.write(f"project({self.project_name}")
		for lang in self.project_langs:
			self.fw.write(f" {lang}")
		self.fw.write(")\n")
		return
	def __make_option(self):
		self.fw.write("\n")
		for name, help_text, value in self.option:
			self.fw.write(f"option({name} \"{help_text}\" {value})\n")
		return
	def __make_configure(self):
		self.fw.write("\n")
		for configure_in, configure_out in self.configure:
			self.fw.write(f"configure_file({configure_in} {configure_out})\n")
		return
	def __make_subdirectory(self):
		self.fw.write("\n")
		for subdirectory in self.subdirectory:
			self.fw.write(f"add_subdirectory({subdirectory[0][2:]})\n")
		return
	def __make_executable(self):
		self.fw.write("\n")
		self.fw.write(f"add_executable({self.target_name}.elf)\n")
		return
	def __make_target_link(self):
		self.fw.write("\n")
		self.fw.write(f"target_link_libraries({self.target_name}.elf\n")
		for subdirectory in self.subdirectory:
			self.fw.write(f"\t{subdirectory[0][2:]}\n")
		self.fw.write(")\n")
		return
	def __make_target_include(self):
		self.fw.write("\n")
		for attribute, include_list in self.include_list:
			self.fw.write(f"target_include_directories({self.target_name}.elf {attribute}\n")
			for i in include_list:
				self.fw.write(f"\t{i}\n")
			self.fw.write(")\n")
		return
	def __make_custom_command(self):
		self.fw.write("\n")
		# TODO: self.generate_file
		for target, attribute, command, args in self.build_event:
			self.fw.write("add_custom_command(\n")
			self.fw.write(f"\tTARGET {target}\n")
			self.fw.write(f"\t{attribute}\n")
			self.fw.write(f"\tCOMMAND {command}\n")
			self.fw.write(f"\tARGS {args}\n")
			self.fw.write(")\n")
		return

	# Build config.h.in
	def __make_cmakedefine(self):
		for cmakedefine in self.cmakedefine_list:
			self.fw.write(f"#cmakedefine {cmakedefine}\n")
		return

	# Build toolchain.make
	def __make_toolchain(self):
		for toolchain in self.toolchain_list:
			self.fw.write("set(")
			for t in toolchain:
				self.fw.write(f" {t}")
			self.fw.write(")\n")
		return

if (__name__ == "__main__"):
	cb = CMake_Builder()
	cb.run()