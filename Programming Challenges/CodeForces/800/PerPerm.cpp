/*
 * https://codeforces.com/problemset/problem/233/A
 

A permutation is a sequence of integers p sub_1, p sub_2, ..., p sub_n, consisting of n distinct positive integers, each of them doesn't exceed n. Let's denote the i-th element of permutation p as p sub_i. We'll call number n the size of permutation p sub_1, p sub_2, ..., p sub_n.

Nickolas adores permutations. He likes some permutations more than the others. He calls such permutations perfect. A perfect permutation is such permutation p that for any i (1 ≤ i ≤ n) ( n is the permutation size) the following equations hold p sub_p sub_i = i and p sub_i ≠ i. Nickolas asks you to print any perfect permutation of size n for the given n.

Input

A single line contains a single integer n (1 ≤ n ≤ 100) — the permutation size.

Output

If a perfect permutation of size n doesn't exist, print a single integer -1. Otherwise print n distinct integers from 1 to n, p sub_1, p sub_2, ..., p sub_n — permutation p, that is perfect. Separate printed numbers by whitespaces.

SAMPLES:
1
	-1

2
	2 1
	
4
	2 1 4 3
 */

#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	
	if (n%2 != 0)	std::cout << -1 << std::endl;
	else			for (int i = 1; i <= n; i+=2)
						std::cout << i+1 << " " << i << " ";

	return 0;
}