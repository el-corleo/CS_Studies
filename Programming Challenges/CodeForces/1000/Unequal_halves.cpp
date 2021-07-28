/*
 * https://codeforces.com/problemset/problem/1174/A
 * 
 * You're given an array a of length 2n. Is it possible to reorder it in such way so that the sum of the first n elements isn't equal to the sum of the last n elements?
 * 
 * Input
 *
 * The first line contains an integer n
 * (1≤n≤1000), where 2n is the number of elements in the array a.
 *
 * The second line contains 2n space-separated integers a1, a2, …, a2n (1≤ai≤106) — the elements of the array a.
 *
 * Output
 *
 * If there's no solution, print "-1" (without quotes). Otherwise, print a single line containing 2n space-separated integers. 
 * They must form a reordering of a. You are allowed to not change the order.
 *
 * 3
 * 1 2 2 1 3 1
 *		2 1 3 1 1 2
 *
 * 1
 * 1 1
 *		-1
 *
 * Observations:
 *		- O(N) algorithm is possible
 * 		- can look at midpoint and compare to elements in second half of list, if different from one of them, then swap and return
 *		- if not different from any of them, the midpoint == all the elements of the second half, check against all elements in first half and switch that with last element in second half
 * 		- if not different from any in the second half, then return -1
 *
 *		- Above only works if we assume the two halves already equal each other, which is not necessarily the case
 *			e.g., 1 1 2 0 0 0 wouldn't work
 * 		
 */
#include <iostream>
#include <bits/stdc++.h>

template<typename T>
void print(T t) 		{ std::cout << t << " "; }

// failed because of false assumption that halves would equal each other at first
void first_attempt(int first_half_ind, int last_half_ind, int n, int (&arr)[10])
{
	// compare last in first to first in last
	while (last_half_ind < n)
	{
		// swap first unlike elements
		if (arr[first_half_ind] != arr[last_half_ind])
		{
			int tmp = arr[first_half_ind];
			arr[first_half_ind] = arr[last_half_ind];
			arr[last_half_ind] = tmp;
			for (int i = 0; i < n; i++)	{ print(arr[i]); }
			//return 0;
		}
		last_half_ind++;
	}

	// compare last in first to all others in first
	while (first_half_ind >= 0)
	{
		// swap first unlike elements
		if (arr[n/2] != arr[first_half_ind])
		{
			int tmp = arr[first_half_ind];
			arr[first_half_ind] = arr[last_half_ind];
			arr[last_half_ind] = tmp;
			for (int i = 0; i < n; i++)	{ print(arr[i]); }
			//return 0;
		}
		first_half_ind--;
	}
}

int main()
{
	int n;
	std::cin >> n;
	n *= 2;
	int first_half_ind = n/2;
	int arr[n];
	int sum_first = 0;
	int sum_second = 0;

	for (int i = 0; i < n; i++) 
	{ 
		std::cin >> arr[i];
		if (i < first_half_ind) sum_first += arr[i];
		else 					sum_second += arr[i];
	}

	// if sum of first half != sum of second half, print out current order
	if (sum_first != sum_second)
	{
		for (int i = 0; i < n; i++)	{ print(arr[i]); }
		return 0;
	}
	// else order array
	std::sort(arr, arr+n);
	// if first and last element are not equal, swap first and last
	if (arr[0] != arr[n-1])
	{
		int tmp = arr[(n/2)-1];
		arr[(n/2)-1] = arr[n/2];
		arr[n/2] = tmp;
		for (int i = 0; i < n; i++)	{ print(arr[i]); }
		return 0;
	}
	// No solution
	print(-1);

	return 0;
}