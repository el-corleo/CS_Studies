#https://projecteuler.net/problem=1
#
# If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
# Find the sum of all the multiples of 3 or 5 below 1000.
#
# Ans: 233168


#brute force
total = 0
for i in range(350):
	if i*3 < 1000:
		total += i*3

	if i*5 < 1000 and (i*5)%3 != 0:
		total += i*5

print(total)
