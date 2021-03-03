/*
 * https://codeforces.com/problemset/problem/144/A
 
A Ministry for Defense sent a general to inspect the Super Secret Military Squad under the command of the Colonel SuperDuper. Having learned the news, the colonel ordered to all n squad soldiers to line up on the parade ground.

By the military charter the soldiers should stand in the order of non-increasing of their height. But as there's virtually no time to do that, the soldiers lined up in the arbitrary order. However, the general is rather short-sighted and he thinks that the soldiers lined up correctly if the first soldier in the line has the maximum height and the last soldier has the minimum height. Please note that the way other solders are positioned does not matter, including the case when there are several soldiers whose height is maximum or minimum. Only the heights of the first and the last soldier are important.

For example, the general considers the sequence of heights (4, 3, 4, 2, 1, 1) correct and the sequence (4, 3, 1, 2, 2) wrong.

Within one second the colonel can swap any two neighboring soldiers. Help him count the minimum time needed to form a line-up which the general will consider correct.

Input

The first input line contains the only integer n (2 ≤ n ≤ 100) which represents the number of soldiers in the line. The second line contains integers a 1, a 2, ..., a n (1 ≤ a i ≤ 100) the values of the soldiers' heights in the order of soldiers' heights' increasing in the order from the beginning of the line to its end. The numbers are space-separated. Numbers a 1, a 2, ..., a n are not necessarily different.

Output

Print the only integer — the minimum number of seconds the colonel will need to form a line-up the general will like.

SAMPLES:
4
33 44 11 22
	2

7
10 10 58 31 63 40 76
	10
 */

#include <iostream>
#include <bits/stdc++.h>

int main()
{
	int n;
	int tmp;
	int min=INT_MAX, min_ind=0, max=INT_MIN, max_ind=0;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		if (tmp <= min)	{ min = tmp; min_ind = i; } // closest to end is the one
		if (tmp > max)	{ max = tmp; max_ind = i; } // closest to start is the one
	}
	
	if (max_ind > min_ind)	min_ind++; // if the two must cross, it gains an extra spot
	
	std::cout << (n-1-min_ind+max_ind) << std::endl;

	return 0;
}