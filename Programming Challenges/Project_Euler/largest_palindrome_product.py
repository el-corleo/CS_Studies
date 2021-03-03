# https://projecteuler.net/problem=4
#
# A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
# Find the largest palindrome made from the product of two 3-digit numbers.
#
# Ans: 906609


# 998001 = 999*999
# 10000 = 100*100
# thus, must be less than this
# two approaches:
#	1.) look for 3-digit divisors for next largest palindrome: 997799, etc.
#	2.) reduce factors slowly to find next largest palindrome: 999*998, 998*998, etc.
import numpy as np

def is_palindrome(num):
	digits = []
	while num > 0:
		#print(num%10)
		digits.append(int(num%10))
		num = np.uint64(num/10)
	
	i = 0
	while i < len(digits)//2:
		#print(digits[i])
		#print(digits[-i-1])
		if digits[i] != digits[-i-1]:
			return False
		else:
			i += 1
	return True

a = 999
b = 999
found = False
while a > 100:
	while b > 100:
		found = is_palindrome(np.uint64(a*b))
		if found: 
			print(f'a is {a}')
			print(f'b is {b}')
			print('a*b is {:d}'.format(a*b))
			break
		else:
			b -= 1

	a -= 1
	b = 999


