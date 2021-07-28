# https://projecteuler.net/problem=5
#
# 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
# What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
#
# Ans: 232792560



# for digits 1-20
# ---------------
# 3724680960 = 20*19*18*17*16*14*13*11
# I eliminated 15 because factors 3 and 5 exist in 20 and 18
# 	similarly 12 because 6 and 2 exist
# Then divide by 2^(2^2)
#
# for digits 1-10
# ---------------
# 5040 = 10*9*8*7
# eliminated other factors because their combinations exist with the existing ones
# Then divide by 2^(2^0)
#
# Hypothesis:
#	for 1-40, it'd be non-repeating factors' product divided by 2^(2^4)?
#
# Insights from Project Euler
# ---------------------------
# Build up for [1-10]
# 2
# 2*3
# 2*3*2 	| not 4, because 4 = 2*2
# 2*3*2*5
# 2*3*2*5	| 5 and 6 are same because 6 = 3*2, which are already included
# 2*3*2*5*7
# 2*3*2*5*7*2
# 2*3*2*5*7*2*3 | 9 and 10 will be same because 10 = 5*2, which are already factors
#
# From what I understand of the suggested algorithm
# 	- Look for floor of how many times the primes fit into highest term by taking log base-prime of highest term
#		- e.g.,	log(20)/log(2)	=	2^4	= 16	< 20
#						3^2	= 9	< 20
#						5^1	= 5	< 20
#						7^1	= 7	< 20
#						11^1	= 11	< 20
#						13^1	= 13	< 20
#						17^1	= 17	< 20
#						19^1	= 19	< 20
#	Et voila! Those are your factors!

n = 3724680960/16


for i in range(1,21):
	if (n%i) != 0:
		print(i)
		break

print(n)
