# https://projecteuler.net/problem=8

# Find the thirteen adjacent digits in the 1000-digit number that have the greatest product. What is the value of this product?

# use sliding window, push window over if 0 in window

num = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450"

	


def get_thirteen_prod(substr):
	prod = 1
	for i in range(0, len(substr)):
		# return location of first zero in substr
		if int(substr[i]) == 0:
			return i
		prod *= int(substr[i])
	# no zeros in substr
	return prod


def get_max_prod():
	i_start = 0
	i_end = 13
	max_prod = get_thirteen_prod(num[i_start:i_end])
	next_prod = 0
	while i_end < len(num):
		# check for zeros
		while next_prod < 13:
			i_start += next_prod + 1
			i_end = i_start + 13
			# index out of bounds
			if i_end >= len(num):	break
			next_prod = get_thirteen_prod(num[i_start:i_end])
		# terminate if out of bounds
		if i_end >= len(num):	break
		# update max_prod if greater found
		if next_prod > max_prod:	max_prod = next_prod
		# divide out earliest factor
		next_prod /= int(num[i_start])
		# multiply by next factor if not zero
		if int(num[i_end]) != 0:
			next_prod *= int(num[i_end])
			# increment start and end points
			i_start += 1
			i_end += 1
		# else rest next_prod to force finding zero
		else:
			next_prod = 0
	
	return max_prod


print(get_max_prod())
