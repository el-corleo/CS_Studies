# https://projecteuler.net/problem=31

# In the United Kingdom the currency is made up of pound (£) and pence (p). There are eight coins in general circulation:

#    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).

# It is possible to make £2 in the following way:

#    1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

# How many different ways can £2 be made using any number of coins?

# Observations:
#	- Can build up from 1p coin,
#		- start with 200 x 1p, subtract n x 2p, then n x 5p, etc.
#		- start with 198 x 1p and 1 x 2p, then subtract n x 5p, etc.
#	- Can be greedy and take as many of x coins as possible and progressively cut each pile down to zero

# Ultimately, I couldn't solve this one. I had a very similar idea to the recursive implementation
# copied below, but I failed to translate idea to code


coins = [1, 2, 5, 10, 20, 50, 100, 200]

TARGET_VAL = 200

def diff_combos(target, available_coins):
	# base case, only one way to make 200 with 1 coin type
	if available_coins == 0:	return 1
	cnt = 0
	# until target is < 0 
	while target >= 0:
		# add all ways to make target val w/ soon to be added coin
		cnt += diff_combos(target, available_coins-1)
		# add coin, so subtract from the target
		target -= coins[available_coins]
	return cnt

print(diff_combos(TARGET_VAL, 7))
