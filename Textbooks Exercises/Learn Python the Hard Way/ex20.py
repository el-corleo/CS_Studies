from sys import argv

script, input_file = argv

def print_all(f):
	print(f.read())

def rewind(f):
	f.seek(0)

def print_ln(ln_cnt, f):
	print(ln_cnt, f.readline())

current_file = open(input_file)

print_all(current_file)
rewind(current_file)

current_line = 1

print_ln(current_line, current_file)
current_line += 1
print_ln(current_line, current_file)
current_line += 1
print_ln(current_line, current_file)

current_file
