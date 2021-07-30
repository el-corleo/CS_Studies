list_1 = ['foo', 'bar', True]
list_2 = ['bar', 'foo', 1, 2, 2.0]

def print_list(list_to_print):
	for x in list_to_print:
		print(f"List item: {x}")

def print_x_times(list_to_print, x=10):
	for i in range(1,x):
		for x in list_to_print:
			print(x)

print_list(list_1)
print_list(list_2)

list_1.append(False)

print_x_times(list_1)
