/*
 * https://codeforces.com/problemset/problem/318/A

Being a nonconformist, Volodya is displeased with the current state of things, particularly with the order of natural numbers (natural number is positive integer number). He is determined to rearrange them. But there are too many natural numbers, so Volodya decided to start with the first n. He writes down the following sequence of numbers: firstly all odd integers from 1 to n (in ascending order), then all even integers from 1 to n (also in ascending order). Help our hero to find out which number will stand at the position number k.

Input

The only line of input contains integers n and k (1 ≤ k ≤ n ≤ 1012).

Please, do not use the %lld specifier to read or write 64-bit integers in C++. It is preferred to use the cin, cout streams or the %I64d specifier.

Output

Print the number that will stand at the position number k after Volodya's manipulations.

SAMPLES:
10 3
5

7 7
6

 Observations:
 if n%2==0 [e.g., 20] [1 3 5 7 9 11 13 15 17 19 2 4 6 8 10 12 14 16 18 20]
	if k > n/2 [e.g., 14]
		then n/2 = num_odds [10 in this case]
		shift = k - num_odds [4 in this case]
		then 2*(shift-1) = num_at_pos_k 
	if k < n/2 [e.g., 9]
		then 2*k - 1 = num_at_pos_k [17 in this case]
 if n%2!=0 [e.g., 21] [1 3 5 7 9 11 13 15 17 19 21 2 4 6 8 10 12 14 16 18 20]
	if k > (n+1)/2 [e.g., 12]
		then (n+1)/2 = num_odds [11 in this case]
		shift = k - num_odds [1 in this case]
		then 2*shift = num_at_pos_k [2 in this case]
	if k <= n/2 [e.g., 11]
		then 2*k - 1 [21 in this case]
 
	8 4
	1 3 5 7 2 4 6 8
 */

#include <iostream>

int main()
{
	//input
	long long n, k, ans;
	std::cin >> n >> k;
	// even n have an even number of odds [e.g., 20 has 10 odds]
	if (n%2==0)
	{
		if (k > n/2)	ans = 2*(k-(n/2));
		else			ans = 2*k - 1;
	}
	// odd n have an odd number of odds [e.g., 21 has 11 odds]
	else
	{
		if (k > (n+1)/2)	ans = 2*(k-((n+1)/2));
		else				ans = 2*k - 1;
	}
	
	//output
	std::cout << ans << std::endl;
	return 0;
}