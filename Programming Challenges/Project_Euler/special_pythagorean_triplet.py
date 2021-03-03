# https://projecteuler.net/problem=9
#
# A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,
#	a^2 + b^2 = c^2
# For example, 32 + 42 = 9 + 16 = 25 = 52.
# There exists exactly one Pythagorean triplet for which a + b + c = 1000.
# Find the product abc.
#
# Ans: 31875000


# premises and ideas
# a + b + c = 1000
# c = 1000 - a - b
# a**2 + b**2 = c**2
# a**2 + b**2 = (1000 - a - b)**2
# sqrt(a**2 + b**2) = 1000 - a - b

# since pythagorean triplets are a < b < c:
# c >= a + 2
# b >= a + 1
# a + a + 1 + a + 2 <= 1000
# 3a + 3 <= 1000
#
# 	a < 333 < b
#
# c >= b + 1
# a <= b - 1
# b - 1 + b + b + 1 <= 1000
# 3b <= 1000
#
#	b < 334 < c
#
# b <= c - 1
# a <= c - 2
# c - 1 + c - 2 + c <= 1000
# 3c - 3 <= 1000
#
#	c > 334

def is_valid(a, b, c):
	if a+b+c != 1000:
		return False
	if (a*a + b*b) != c*c:
		return False
	return True

found = False
for a in range(100, 333):
	for b in range(a+1, 999):
		for c in range(b+1, 1000):
			found = is_valid(a, b, c)
			if found:
				print(a, b, c)
				break
		if found:	break
	if found:	break

 
