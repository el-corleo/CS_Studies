/*
 * http://codeforces.com/problemset/problem/222/A
 
 One day shooshuns found a sequence of n integers, written on a blackboard. The shooshuns can perform one operation with it, the operation consists of two steps:

   - Find the number that goes k-th in the current sequence and add the same number to the end of the sequence;
   - Delete the first number of the current sequence. 

The shooshuns wonder after how many operations all numbers on the board will be the same and whether all numbers will ever be the same.

	Input

The first line contains two space-separated integers n and k (1≤k≤n≤10^5).

The second line contains n space-separated integers: a_1,a_2,...,a_n (1≤a_i≤10^5) — the sequence that the shooshuns found.

	Output

Print the minimum number of operations, required for all numbers on the blackboard to become the same. If it is impossible to achieve, print -1.
 
 	SAMPLE:
	1.) input:	3 2
				3 1 1
		output:	1
	2.) input:	3 1
				3 1 1
		output: -1
		
	OBSERVATIONS:
	- if any term after the kth element != the kth element, then it will fail
		e.g.,	a b c c d	@ k = 3
				b c c d c
				c c d c c	Loop starts here
				c d c c d
				d c c d c
				c c d c c	Loop restarts
	- if original list is already composed of all the same elements, then output = 0
	- if all same from kth element onwards, then will take k-1 steps to make list homogenous
		e.g.,	a b c c c	@ k = 3
				k - 1 = 2
	
	Troublesome inputs:
	100000 80739
	9340
	<list too long to include and CF doesn't provide full tests anyway, but I guess that what happened was that the list is actually the same number starting from entry 9340>
	
	5 3
	2 1 1 1 5
	- after failing test 44, I realized I had failed to set the b_same_before_i_start flag to false when the elements don't match after i+1 > start
	
	Final algorithm complexity: O(n)
	Improvements:
		- instead of using a thousand flags, could just go through input and track where it first starts to be homogenous; once past kth element, can break and return impossible if two items don't match, but cannot before kth element
 */
#include <iostream>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// Input & Process
	int i_len, i_start, i_same_from_ind = 0;
	int i_arr_elems[2];
	bool b_all_same = true, b_same_before_i_start = true, b_same_after_i_start = true;
	std::cin >> i_len >> i_start >> i_arr_elems[0];
	for (int i = 1; i < i_len; i++)
	{
		// load number
		std::cin >> i_arr_elems[1];
		// check to see if same as prev num
		if (i_arr_elems[0] != i_arr_elems[1])
		{
			// at and after i_start, if not all same, set flags to false and break
			if (i+1 > i_start)
			{
				b_all_same = false;
				b_same_before_i_start = false;
				b_same_after_i_start = false;
				break;
			}
			// if flag set to false, then num_steps != 0
			else	{ b_all_same = false; b_same_before_i_start = false; }
		} else
		{
			// set index where it list begins to be homogenous
			if (i+1 <= i_start && !b_same_before_i_start)
			{ b_same_before_i_start = true; i_same_from_ind = i; }
		}
		i_arr_elems[0] = i_arr_elems[1];
	}
	
	// Output
	// if all elements in original list are the same, then output 0 and return
	if (b_all_same)				{ Log(i_same_from_ind); return 0; }
	// if all elements are same starting before i_start
	if (b_same_before_i_start)	{ Log(i_same_from_ind-1); return 0; }
	// if all elements >= i_start are the same, then output i_start-1
	if (b_same_after_i_start)	{ Log(i_start-1); return 0; }
	// impossible
	Log(-1);
	return 0;
}