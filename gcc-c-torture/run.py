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
	err_list = []
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

	with open("../error_compilation.txt", 'r') as f:
		lines = f.readlines()
		for line in lines:
			err_list.append(line.replace('\n',''))
	f.close()


	with open("../error_execution.txt", 'r') as f:
		lines = f.readlines()
		for line in lines:
			err_list.append(line.replace('\n','')+'.c')
	f.close()

	err_list.sort()
	mau_list.sort()
	gcc_list = list(set(gcc_list).difference(mau_list+err_list))
	gcc_list.sort()

	# Iterate through the list of C programs
	for program in gcc_list:
	# Compile the C program
		compile_command = ["gcc", program, "-o", program.split(".")[0]]
		try:
			subprocess.run(compile_command, check=True)
			exe_list.append(program.split(".")[0])

		except subprocess.CalledProcessError as e:
			print(f"Error compiling  {program}: {e}")	
			error_compilation.append(program)

	with open("../error_compilation.log", 'w') as out:
		out.write("Number of compiled files: " + str(len(gcc_list) - len(error_compilation)) + '\n')
		out.write("Number of error compilation files: " + str(len(error_compilation))  + "/" + str(len(gcc_list)) + '\n')
		out.write("Error list: " + '\n')
		for line in error_compilation:
			out.write(line+'\n')
	out.close()

	# Execute the program
	with open("../trace.txt", 'w') as tr:
		for program in exe_list:
			tr.write(program+'.c'+'\n')
		# Run the compiled C program
			run_command = [f"./{program}"] 
			try:
				#result = subprocess.run(run_command, check=True)
				result = subprocess.run(run_command, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
				stdout_data = result.stdout
				stderr_data = result.stderr
				tr.write(stdout_data+'\n')
				tr.write(stderr_data+'\n')
			except subprocess.CalledProcessError as e:
				print(f"Error running {program}: {e}")	
				error_execution.append(program)
				
		with open("../error_execution.log", 'w') as out:
			out.write("Number of executed files: " + str(len(exe_list) - len(error_execution)) + '\n')
			out.write("Number of error execution files: " + str(len(error_execution)) + "/" + str(len(exe_list)) + '\n')
			out.write("Error list: " + '\n')
			for line in error_execution:
				out.write(line+'\n')
		out.close()
	tr.close();