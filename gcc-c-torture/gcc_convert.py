#!/usr/bin/env python3
import re
import binascii
import os
import sys


def extract_called_functions(ipath, opath):
	# Open and read the C code file
	with open(ipath, 'rb') as file:
		code = file.read().decode('iso-8859-1')
		main_found = False
		called_functions = []
		in_main = []
		non_main = []
		conv_code = []
		func_found = False

		# Split the code into lines
		lines = code.split('\n')
		for line in lines:
			if main_found == False:
				non_main.append(line + '\n')
			# Look for the main function
			if 'main(' in line:
				main_found = True
				
			if 'main (' in line:
				main_found = True

			if 'int main (void)' in line:
				main_found = True

			if main_found:
			# Find function calls in the line using a regular expression
				calls = re.findall(r'\b(\w+)\s*\(', line)
				called_functions.extend(calls)
				elements_to_delete = ["main", "if", "abort", "exit", "void", "sizeof", "auto", "break", "case", "continue", "default",
    "do", "double", "else", "enum", "extern", "for", "goto",
    "if", "register", "return",
    "sizeof", "static", "struct", "switch", "typedef", "union",
     "void", "volatile", "while"]
				called_functions = [x for x in called_functions if x not in elements_to_delete]
				called_functions = list(set(called_functions))


				#Save in main:
				in_main.append(line)
				#Check if the main function ends
			
		non_main = non_main[:-1]
		keyword_list = ["define", "struct", "enum", "extend", "malloc", "extern", "abort", "exit", "auto", "break", "continue", "default",
    "do", "double", "else", "enum", "extern", "for", "goto",
    "register", "return",
    "sizeof", "static", "struct", "switch", "typedef", "union",
     "void", "volatile", "while"]
		
		#print(called_functions)
		for line in non_main:
			for func in called_functions:
				if re.search(func, line):
					key_found = False
					for key in keyword_list:
						if re.match(key, line):
							key_found = True
							
					if key_found == False:
						func_found = True
						pc = 0

				if func_found:
					if re.search("{",line):
						if pc == 0:
							line = line.replace("{"+"\n", "{"+"\n"+"  printf(" + '"' + func + ' "' + ");" + "\n")
							pc = 1
						
				if re.search("abort", line):
					if not re.search("void abort ()", line):
						if not re.search(r'\\', line):
							line = line.replace(" abort ();", "{ printf(" + '"' + "abort_func " + '"' + "); " + "		" + "abort (); }") + '\n'
							break

				if re.search("exit", line):
					line = line.replace(" exit (0);", "{ printf(" + '"' + "exit_func " + '"' + "); " + "		" + "exit (0); }") + '\n'
					break

			conv_code.append(line)
		
		for line in in_main:
			if re.search("abort", line):
				line = line.replace(" abort ();", "{ printf(" + '"' + "abort_main " + '"' + "); " + "		" + "abort (); }") 
				line = line.replace(" abort();", "{ printf(" + '"' + "abort_main " + '"' + "); " + "		" + "abort(); }")
			if re.search("exit", line):
				line = line.replace(" exit (0);", "{ printf(" + '"' + "exit_main " + '"' + "); " + "		" + "exit (0); }") 
			if re.search("return", line):
				line = line.replace(" return 0;", " printf(" + '"' + "return 0" + '"' + "); " + "		" + "return 0; ") 
			conv_code.append(line + '\n')

		
	with open(opath, 'w') as out:
		for line in conv_code:
			out.write(line)
	out.close()

		
if __name__ == '__main__':
	
	gcc_list = []
	gcc_path = "execute"
	out_path = "converted"
# Generate for loop list programs	
	for file in os.listdir(gcc_path):
		if file.endswith(".c"):
			gcc_list.append(file)		

	gcc_list.sort()
	#extract_called_functions(gcc_path+"/"+str("20000112-1.c"), out_path+"/"+str("20000112-1.c"))

	for i in range(len(gcc_list)):
		extract_called_functions(gcc_path+"/"+str(gcc_list[i]), out_path+"/"+str(gcc_list[i]))


