import sys
import os
import subprocess
import signal
import time

class QEMU_Test():
	def __init__(self):
		self.pwd = os.getcwd()
		self.test_dir_name = 'test_dir'
		self.ans_dir_name = 'ans_dir'
		self.elf_dir_name = 'elf_dir'
		self.log_dir_name = 'log_dir'
		self.result = list()
		return

	def __directory_check(self):
		if (not os.path.exists(f"{self.pwd}/{self.elf_dir_name}")):
			os.mkdir(f"{self.pwd}/{self.elf_dir_name}")
		if (not os.path.exists(f"{self.pwd}/{self.log_dir_name}")):
			os.mkdir(f"{self.pwd}/{self.log_dir_name}")
		return

	def __build(self, test_name):
		os.system(f"/bin/bash test_build.sh {test_name}")
		return

	def __run_qemu(self, test_name):
		f = open(f"{self.pwd}/{self.log_dir_name}/{test_name}.txt", "w")
		proc = subprocess.Popen(["qemu-system-arm",
								 "-M", "musca-a",
								 "-cpu", "cortex-m33",
								 "-kernel", f"elf_dir/{test_name}.elf",
								 "-nographic",],
								 stdout=f)
		time.sleep(1)
		proc.kill()
		f.close()
		return

	def __compare(self, test_name, cnt, total_cnt):
		result = ""
		log_fp = open(f"{self.pwd}/{self.log_dir_name}/{test_name}.txt", 'r')
		ans_fp = open(f"{self.pwd}/{self.ans_dir_name}/{test_name}.txt", 'r')
		log_data = log_fp.readlines()
		ans_data = ans_fp.readlines()
		if (log_data == ans_data):
			result = "Passed"
		else:
			result = "Failed"
		log_fp.close()
		ans_fp.close()
		return result

	def run(self):
		print(f"QEMU Test project {self.pwd}")
		test_list = os.listdir(f"{self.pwd}/{self.test_dir_name}")
		total_cnt = len(test_list)
		pass_cnt = 0
		total_start_time = time.time()
		self.__directory_check()
		for cnt, test_name in enumerate(test_list):
			start_time = time.time()
			print(f"    Start{cnt + 1}: {test_name}")
			print(f"{cnt + 1}/{total_cnt} Test #{cnt + 1}: {test_name} .....", end="")
			test_name = test_name.split(".")[0]
			print(".....", end="")
			self.__build(test_name)
			print(".....", end="")
			self.__run_qemu(test_name)
			print(".....", end="")
			result = self.__compare(test_name, cnt, total_cnt)
			print(".....", end="\t")
			print(f"{result}", end="\t")
			print(f"{time.time() - start_time:.2f} sec\n")
			if (result == "Passed"):
				pass_cnt += 1
		print(f"\033[32m{int(pass_cnt / total_cnt * 100):d}% tests passed\033[0m, {total_cnt - pass_cnt} tests \033[31mfailed \033[0mout of {total_cnt}\n")
		print(f"Total Test time (real) = {time.time() - total_start_time:.2f} sec")
		return

if (__name__ == '__main__'):
	test = QEMU_Test()
	test.run()
	os.system("exit")