#!/usr/bin/env python3
import re
import binascii
import os
import sys
import subprocess

if __name__ == '__main__':
	
	gcc_list = []
	mau_list = []
	error_compilation = []
	error_execution = []	
	exe_list = []
# Generate for loop list programs	
	for file in os.listdir():
		if file.endswith(".c"):
			gcc_list.append(file)		

	gcc_list.sort()
	with open("../list_mau.txt", 'r') as f:
		lines = f.readlines() 
		for line in lines:
			mau_list.append(line.replace('\n',''))
	f.close()
	
	mau_list.sort()
	gcc_list = list(set(gcc_list).difference(mau_list))
	gcc_list.sort()

	# Iterate through the list of C programs
	for program in gcc_list:
	# Compile the C program
		compile_command = ["/opt/kalray/accesscore/bin/kvx-cos-gcc", program, "-o", program.split(".")[0]]
		try:
			subprocess.run(compile_command, check=True)
			exe_list.append(program.split(".")[0])

		except subprocess.CalledProcessError as e:
			print(f"Error compiling  {program}: {e}")	
			error_compilation.append(program)

	with open("../error_compilation.txt", 'w') as out:
		for line in error_compilation:
			out.write(line+'\n')
	out.close()

	# Execute the program
	for program in exe_list:
	# Run the compiled C program
		run_command = [f"/opt/kalray/accesscore/bin/kvx-cluster -- {program}"]
		try:
			subprocess.run(run_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
		except subprocess.CalledProcessError as e:
			print(f"Error running {program}: {e}")	
			error_execution.append(program)
			
	with open("../error_execution.txt", 'w') as out:
		for line in error_execution:
			out.write(line+'\n')
	out.close()
