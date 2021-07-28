
# https://projecteuler.net/problem=21

# Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
# If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

# For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

# Evaluate the sum of all the amicable numbers under 10000.

# OBSERVATIONS:
# 	- Can use memoization

# keep dict of all possible pairings
pairs_found = {}
for i in range(1,10000):
	pairs_found[i] = 0

# sum divisors
def find_div_sum(num):
	sqrt_num = num**0.5
	tot = 0
	for div_cand in range(1, int(sqrt_num)+1):
		if num%div_cand == 0:
			tot += div_cand
			if div_cand != sqrt_num and num/div_cand != num:
				tot += num/div_cand

	return tot

# if amicable return sum, else return 0
def find_amic_num(num): 
	# num not yet examined
	if pairs_found[num] == 0:
		# sum of orig num
		pair = find_div_sum(num)
		# pair must be below 10000 to be valid
		if pair < 10000 and num != pair and find_div_sum(pair) == num:
			pairs_found[num] = 1
			pairs_found[pair] = 1
			return num + pair
	return 0

i = 3
tot = 0
while i < 10000:
	tot += find_amic_num(i)
	i += 1

print(tot)
