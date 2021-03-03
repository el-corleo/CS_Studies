#*args represents an unspecified number of args
def print_three(*args):
	arg1, arg2, arg3 = args
	print(f"arg1: {arg1}, arg2: {arg2}, arg3: {arg3}")

def print_two(arg1, arg2):
	print(f"arg1: {arg1}, arg2: {arg2}")

def print_none():
	print("Nothing to see here")

print_three("Bobo", "Bobo", "Bobo")
print_two("Bobo", "Bobo")
print_none()
