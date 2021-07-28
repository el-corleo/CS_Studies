/*
	URL: https://codeforces.com/problemset/problem/849/A

	DESCRIPTION:

	Where do odds begin, and where do they end? Where does hope emerge, and will they ever break?

Given an integer sequence a1, a2, ..., an of length n. Decide whether it is possible to divide it into an odd number of non-empty subsegments, the each of which has an odd length and begins and ends with odd numbers.

A subsegment is a contiguous slice of the whole sequence. For example, {3, 4, 5} and {1} are subsegments of sequence {1, 2, 3, 4, 5, 6}, while {1, 2, 4} and {7} are not.

	Input

The first line of input contains a non-negative integer n (1 ≤ n ≤ 100) — the length of the sequence.

The second line contains n space-separated non-negative integers a1, a2, ..., an (0 ≤ ai ≤ 100) — the elements of the sequence.

	Output

Output "Yes" if it's possible to fulfill the requirements, and "No" otherwise.

You can output each letter in any case (upper or lower).

	OBSERVATIONS:

	- If original sequence begins or ends with an even number, then it's impossible 
	- Sequence length must be odd since it must be split into two odd factors
	- Smallest subsets could be of 1, meaning n subsets all consisting of single odd numbers
	- Largest subsets could be of n/3, meaning 3 subsets ranging in size from 1 to n-2
*/

	// if size == 0, true
	// if begins with or ends with even, false
	// find next terminating odd number (i+2 to ensure oddness), then recurse

	// 1 5 3
	/* 
		func(arr, 3) 				-> 1
			func(arr, 2)			-> 5 
				func(arr, 1) 		-> 3
					func(arr, 0)	-> return true
	*/

	// 1 4 5 3 1
	/*
		func(arr, 5)				-> 1
			func(arr, 4)			-> 4 X
		func(arr, 5)				-> 1, 4, 5
			func(arr, 2)			-> 3
				func(arr, 1)		-> 1
					func(arr, 0)	-> return true
	*/

	// 1 5 4 3 1
	/*
		func(arr, 5)				-> 1
			func(arr, 4)			-> 5
				func(arr, 3)		-> 4 X
			func(arr, 4)			-> 5, 4, 3
				func(arr, 1)		-> 1
					func(arr, 0)	-> return true
	*/

	// 1 5 3 4 1
	/*
		func(arr, 5)				-> 1
			func(arr, 4)			-> 5
				func(arr, 3)		-> 3
					func(arr, 2)	-> 4 X
				func(arr, 3)		-> 3, 4, 1
					func(arr, 0)	-> return true
	*/

	// 
	
	/*
		1 2 1 | 1 | 1 | 1 | 1	-> +
		1 2 2 1 | 1 | 1 | 1		-> -
		1 2 2 2 1 | 1 | 1		-> +
		1 2 2 2 2 1 | 1			-> -

		1 2 1 2 1 2 1			-> -
		1 2 2 1 | 1 2 1 		-> -
		1 2 2 2 1 | 1 | 1		-> +

		- for each cluster of evens, need two odd bookends
		- for each cluster of evens, need an odd-odd sequence following and/or preceding
	*/

#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }
	
int main()
{
	int n;
	std::cin >> n;
	
	// if n is even, then impossible
	if ((n & 1) == 0)	 { print("No"); return 0; }

	// load into array
	int arr[n];
	int odds = 0, clusters = 0;

	const int NORMAL = 0, CLUSTER = 1, EXIT_CLUSTER = 2;
	int MODE = NORMAL;
	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
		switch (MODE) {
			case NORMAL:
				if ((arr[i] & 1) == 1)	{ odds++; }
				else					{ MODE = CLUSTER; }
				break;
			case CLUSTER:
				if (i == n - 1 && (arr[i] & 1) == 1)	{ odds++; clusters++; }
				else if ((arr[i] & 1) == 1)				{ odds++; MODE = EXIT_CLUSTER; }
				break;
			default:
				if ((arr[i] & 1) == 1)	{ clusters++; odds++; MODE = NORMAL; }
				else					{ odds--; MODE = CLUSTER; }
		}
	}

	// check if first or last are even
	if ((arr[0] & 1) == 0 || (arr[n-1] & 1) == 0)	{ print("No"); return 0; }
	else											{ print("Yes"); return 0; }


	// UNNECESSARY CHECKS, ugh...
	
	// two odds needed to bookend every cluster
	if (clusters * 2 > odds)	{ print("No"); return 0; }
	else						{ odds -= clusters * 2; }

	// if clusters are odd, then need even remainder of odds
	if ((clusters & 1) == 1 && (odds & 1) == 1) { print("No"); return 0; }
	if (((clusters & 1) == 0 && (odds & 1) == 0) \
		|| (clusters != 1 && odds == 0)) { print("No"); return 0; }

	print("Yes");

	return 0;
}
