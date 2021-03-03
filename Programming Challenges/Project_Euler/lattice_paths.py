# Starting in the top left corner of a 2×2 grid, 
# and only being able to move to the right and down, 
# there are exactly 6 routes to the bottom right corner.
# 
# How many such routes are there through a 20×20 grid?

# OBSERVATIONS:
# 	- Solutions are diagonally reflected, calculate top triangle and multiply by two
#		- last solution in top triangle has alternating right down w/ no repetition
#	- Regardless of path, should always take same n_steps to get from s to t
#	- Combinatorics to the rescue!
#		- C((a+b), a) where a and b are the dimensions of the grid
#		- i.e., (a+b)!/a!(a+b-a)! => (a+b)!/a!b!
#		- and since this is a square grid, a = b
#		- i.e., (2a)!/a!a!

def fact(size, part='den'):
	tot = 1
	orig_size = size
	if part == 'num':
		while size > (orig_size/2):	
			tot *= size
			size -= 1
	else:
		while size > 1:
			tot *= size
			size -= 1
	return tot

def solve_path(size):
	paths = fact(2*size,'num')/fact(size)
	print(paths)

size = int(input('size:'))
while(size>0):
	solve_path(size)
	size = int(input('size:'))
	
