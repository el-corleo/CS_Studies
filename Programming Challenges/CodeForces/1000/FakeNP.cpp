/*
 https://github.com/karansinghgit/CodeForces-Ladders/blob/master/div2A.md

 Tavak and Seyyed are good friends. Seyyed is very funny and he told Tavak to solve the following problem instead of longest-path.

You are given l and r. For all integers from l to r, inclusive, we wrote down all of their integer divisors except 1. Find the integer that we wrote down the maximum number of times.

Solve the problem to show that it's not a NP problem.

Input

The first line contains two integers l and r (2 ≤ l ≤ r ≤ 10^9).

Output

Print single integer, the integer that appears maximum number of times in the divisors.

If there are multiple answers, print any of them.

SAMPLE
19 29
	2

3 6
	3

Observations:
Case l = r
	return l
	if l will always be a divisor of itself (even for primes), and all divisors except for 1 are listed

Case l - r = 1
	return 2
	if range is 1, then one will be divisible by two and the other by some other number

Case l - r = n, where n > 1
	n = 2 | 2 : 4, 3 : 5, 4 : 6, 5 : 7, return 2 [ either 2x2 & ax1 or 2x1 & ax1 & bx1 ]
	n = 3 | 2 : 5, 3 : 6, 4 : 7, 5 : 8, return 2 
	n = 4 | 2 : 6, 3 : 7, 4 : 8, 5 : 9, return 2
	n = 5 | 2 : 7, 3 : 8, 4 : 9, 5 : 10, return 2
 */
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	int l, r;
	std::cin >> l >> r;

	if (l == r)	print(l);
	else		print(2);

	return 0;
}