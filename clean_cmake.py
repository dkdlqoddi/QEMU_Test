from enum import Enum
import os
import shutil

class File_Types(Enum):
	FILE			= 1
	DIRECTORY		= 2
	REGEX_FILE		= 3
	REGEX_DIRECTORY	= 4

class CMake_Cleaner():
	def __init__(self):
		# Basic Settings
		self.pwd					= os.getcwd()
		self.project_name			= "mpu"

		# Clean List
		self.clean_file_list		= ["Makefile",
									   "config.h",
									   "CMakeCache.txt",
									   "cmake_install.cmake",
									   f"{self.project_name}.bin",
									   f"{self.project_name}.elf",
									   f"{self.project_name}.lst",
									   f"{self.project_name}.map",
									   f"{self.project_name}_readelf.txt",]
		self.clean_directory_list	= ["CMakeFiles",]
		return

	# Process
	def run(self):
		self.__search_and_delete_subdirectory()
		return

	# Tools
	def __search_and_delete_subdirectory(self):
		search_queue = ["."]
		while (len(search_queue) != 0):
			current_dir = search_queue[0]
			search_queue.pop(0)
			file_list = os.listdir(current_dir)
			for f in file_list:
				if (os.path.isfile(f"{current_dir}/{f}")):
					if (f in self.clean_file_list):
						os.remove(f"{current_dir}/{f}")
				elif (f in self.clean_directory_list):
					shutil.rmtree(f"{current_dir}/{f}")
				else:
					search_queue.append(f"{current_dir}/{f}")
		return

if (__name__ == "__main__"):
	cc = CMake_Cleaner()
	cc.run()