/*
	URL: https://codeforces.com/problemset/problem/789/A

	DESCRIPTION:

	Anastasia loves going for a walk in Central Uzhlyandian Park. But she became uninterested in simple walking, so she began to collect Uzhlyandian pebbles. At first, she decided to collect all the pebbles she could find in the park.

She has only two pockets. She can put at most k pebbles in each pocket at the same time. There are n different pebble types in the park, and there are w_i pebbles of the i-th type. Anastasia is very responsible, so she never mixes pebbles of different types in same pocket. However, she can put different kinds of pebbles in different pockets at the same time. Unfortunately, she can't spend all her time collecting pebbles, so she can collect pebbles from the park only once a day.

Help her to find the minimum number of days needed to collect all the pebbles of Uzhlyandian Central Park, taking into consideration that Anastasia can't place pebbles of different types in same pocket.

	INPUT:

	The first line contains two integers n and k (1 ≤ n ≤ 10^5, 1 ≤ k ≤ 10^9) — the number of different pebble types and number of pebbles Anastasia can place in one pocket.

The second line contains n integers w_1, w_2, ..., w_n (1 ≤ w_i ≤ 10^4) — number of pebbles of each type. 
	
	OUTPUT:

	The only line of output contains one integer — the minimum number of days Anastasia needs to collect all the pebbles.

	SAMPLES:

	3 2
	2 3 4
		3

	5 4
	3 1 8 9 7
		5

	OBSERVATIONS:
		- Like scheduling where you start the longest jobs first?
			- This way you can always make sure the pockets are as full as possible
		- Process two highest until < pocket_cap for at least 1, then move to next
		- Num of pebbles at least 1, so no need to think about 0 edge case 
		- First implementation exceeded time limit (too many sorts)
*/
#include <iostream>
#include <bits/stdc++.h>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

bool all_zero(const int pebbles[], int size)
{
	for (int i = 0; i < size; i++)	if (pebbles[i] > 0) return false;
	return true;
}

int main()
{
	// Input
	int n_types, pocket_cap, day_cnt = 0;
	std::cin >> n_types >> pocket_cap;
	int pebbles[n_types];
	for (int i = 0; i < n_types; i++)	{ std::cin >> pebbles[i]; }
		
	// Process
	// case n_types == 1
	if (n_types == 1)
		if (pebbles[0] % pocket_cap != 0)	{ print((pebbles[0]/pocket_cap)+1); return 0; }
		else					{ print((pebbles[0]/pocket_cap)); return 0; }
	// case n_types > 1	
	// collect until all types are 0
	int days_1, days_2, ind;
	while(!all_zero(pebbles, n_types))
	{
		// reset search ind
		ind = 1;
		// sort from greatest to least
		std::sort(pebbles, pebbles+n_types, std::greater<int>());
		// find max num day can collect pebbles[ind_1] before it < pocket_cap
		if (pebbles[0] < pocket_cap)	
		{ days_1 = 1; pebbles[0] = 0; }
		else				
		{ days_1 = pebbles[0] / pocket_cap; pebbles[0] -= days_1 * pocket_cap; }
		// same for ind_2
		if (pebbles[ind] < pocket_cap)
		{ days_2 = 1; pebbles[ind] = 0; }
		else
		{ days_2 = pebbles[ind] / pocket_cap; pebbles[ind] -= days_2 * pocket_cap; }

		while(pebbles[ind] != 0 && days_2 < days_1)
		{	
			// if at limit, make no comparison
			if (ind < n_types-1)	ind = (pebbles[ind] > pebbles[ind+1]) ? ind : ind+1;
			// increment days
			days_2++;
			// subtract min pocket_cap and pebbles[ind]
			pebbles[ind] -= (pebbles[ind] < pocket_cap) ? pebbles[ind] : pocket_cap;	
			// increment ind if < pocket_cap, but stay if can extract more
			if (pebbles[ind] < pocket_cap)	ind = (ind+1 == n_types) ? 1 : ind+1;
		}
		// add new days
		day_cnt += days_1;
	}
	// Output
	print(day_cnt);

	return 0;
}
// pc = 3 |	9 8 7 6 5 4 3 2 1
// 		3 2 2 2 1 1 1 0 0 12/2 = 6
//		0 2 1 0 2 1 0 2 1
//		0 1 1 0 1 1 0 1 1 6/2 = 3
//		0 0 0 0 0 0 0 0 0

// pc = 4 |	9 8 7 3 1
//		2 2 1 0 0 5/2 = 2.5
//		1 0 3 3 1
//		1 0 1 1 1 4/2 = 2
//		
