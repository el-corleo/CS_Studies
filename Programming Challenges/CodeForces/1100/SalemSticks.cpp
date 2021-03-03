/*
	UNSOLVED
	
	URL: https://codeforces.com/problemset/problem/1105/A

	DESCRIPTION:

	Salem gave you n sticks with integer positive lengths a_1,a_2,…,a_n.

For every stick, you can change its length to any other positive integer length (that is, either shrink or stretch it). The cost of changing the stick's length from a to b is |a−b|, where |x| means the absolute value of x.

A stick length a_i is called almost good for some integer t if |a_i−t|≤1.

Salem asks you to change the lengths of some sticks (possibly all or none), such that all sticks' lengths are almost good for some positive integer t and the total cost of changing is minimum possible. The value of t is not fixed in advance and you can choose it as any positive integer.

As an answer, print the value of t and the minimum cost. If there are multiple optimal choices for t, print any of them.

	INPUT:

	The first line contains a single integer n (1≤n≤1000) — the number of sticks.

	The second line contains n integers a_i (1≤a_i≤100) — the lengths of the sticks.

	OUTPUT:

	Print the value of t and the minimum possible cost. If there are multiple optimal choices for t, print any of them.

	SAMPLES:

	3
	10 1 4
		3 7

	5
	1 1 2 2 3
		2 0

	4
	1 2 3 4
		3 1 | 2 1

	6
	1 1 2 3 3 4
		2 1

	6
	1 1 1 1 6 9
		3 11

	OBSERVATIONS:
		NOTABLE CONSTRAINTS
			- all must center around median's value [not true!]
				- e.g., 10 comes down to 4 for a cost of 6 and 1 goes to 2 for cost of 1
				- e.g., 2 is median and everything minus 2 is already ≤ 1

		EDGE CASES
			- where all are already almost good and cost = 0	

		POSS ALGOS
			[X] - keep running total, hi, lo; find floor(avg); find range(hi-lo)
				- if range ≤ 2, then cost is 0 and median is t
				- else, traverse array, 
					- if elem < avg, then cost += avg-1-elem
					- if elem > avg, then cost += elem-avg+1
	
	MISTAKES:
		- failed to think of edge case where all values are equal
	
113

86 67 31 33 72 100 88 63 16 12 79 80 76 45 31 96 44 10 24 33 53 11 56 100 23 57 9 48 28 73 18 48 12 89 73 9 51 11 82 94 90 92 34 99 54 58 33 67 35 87 58 90 94 64 57 80 87 99 84 99 20 1 63 12 16 40 50 95 33 58 7 23 71 89 53 15 95 29 71 16 65 21 66 89 82 30 6 45 6 66 58 32 27 78 28 42 8 61 10 26 7 55 76 65 100 38 79 1 23 81 55 58 38

*/
#include <iostream>
#include <stdlib.h>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int compare(const void* a, const void* b)
{ return (*(int*)a - *(int*)b); }

int abs_diff(int a, int b)
{
	if ((a-b) < 0)	return -(a-b);
	else		return (a-b);
}

int main()
{
	// Input
	int n_sticks, total = 0, hi = -1, lo = 101;
	std::cin >> n_sticks;
	int stick_lens[n_sticks];
	for (int i = 0; i < n_sticks; i++)
	{
		std::cin >> stick_lens[i];
		if (stick_lens[i] > hi)		hi = stick_lens[i];
		if (stick_lens[i] < lo)		lo = stick_lens[i];
		total += stick_lens[i];
	}

	// Process
	int avg = total / n_sticks;
	// edge cases
	if (hi==lo)	{ print(std::to_string(hi) + " 0"); return 0; }
	if (hi-lo < 3)	{ print(std::to_string(hi-1) + " 0"); return 0; }
	// other cases
	std::qsort(stick_lens, n_sticks, sizeof(int), compare);
	int med_len = abs_diff(stick_lens[(n_sticks/2)], avg);
	int meds[med_len];
	int costs[med_len]{ 0 };
	if (avg < stick_lens[n_sticks/2])
		for(int i = 0, val = avg; i < med_len; i++, val++)	meds[i] = val; 
	else
		for(int i = 0, val = stick_lens[n_sticks/2]; i < med_len; i++, val++)	meds[i] = val; 
		
	/*
	print("Med_len");
	print(med_len);	
	print("Avg");
	print(avg);
	*/
	
	for(int stick : stick_lens)
	{
		for (int i = 0; i < med_len; i++)
		{
			if (meds[i] > stick)		costs[i] += meds[i]-1-stick;
			else if (meds[i] < stick)	costs[i] += stick-1-meds[i];
		}
	}

	// Output
	int lowest = costs[0];
	int winner = 0;
	for (int i = 1; i < med_len; i++)
		if (costs[i] < lowest)	{ lowest = costs[i]; winner = i; }

	print(std::to_string(meds[winner]) + " " + std::to_string(costs[winner]));
	return 0;
}

