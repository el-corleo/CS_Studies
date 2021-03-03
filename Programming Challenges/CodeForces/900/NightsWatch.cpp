/*
 * https://codeforces.com/problemset/problem/768/A
 
 

"Night gathers, and now my watch begins. It shall not end until my death. I shall take no wife, hold no lands, father no children. I shall wear no crowns and win no glory. I shall live and die at my post. I am the sword in the darkness. I am the watcher on the walls. I am the shield that guards the realms of men. I pledge my life and honor to the Night's Watch, for this night and all the nights to come." — The Night's Watch oath.

With that begins the watch of Jon Snow. He is assigned the task to support the stewards.

This time he has n stewards with him whom he has to provide support. Each steward has his own strength. Jon Snow likes to support a steward only if there exists at least one steward who has strength strictly less than him and at least one steward who has strength strictly greater than him.

Can you find how many stewards will Jon support?

Input

First line consists of a single integer n (1 ≤ n ≤ 10^5) — the number of stewards with Jon Snow.

Second line consists of n space separated integers a 1, a 2, ..., a n (0 ≤ a i ≤ 10^9) representing the values assigned to the stewards.

Output

Output a single integer representing the number of stewards which Jon will feed.

SAMPLES:
2
1 5
	0

3
1 2 5
	1
	
Observations:
If list is already sorted, pay attention to lowest and highest value and then output num of stewards that lie between the two.
Else, first sort, then do the aforementioned.

Problems:
-Used && test instead of || test in the while loop
-Failed to check bounds in while loop
 */

#include <iostream>
#include <algorithm>

void print(int i) { std::cout << i << std::endl; }

int main()
{
	// Input
	int num_stewards;
	std::cin >> num_stewards;
	if (num_stewards < 3)	{ print(0); return 0; }
	int strength[num_stewards];
	for(int i = 0; i < num_stewards; i++)	{ std::cin >> strength[i]; }
	
	// Process
	std::sort(strength,strength+num_stewards);
	int lo = strength[0];
	int hi = strength[num_stewards-1];
	int lo_ind = -1;
	int hi_ind = -1;
	int ind = 0;
	while (strength[ind] <= lo || strength[num_stewards-ind-1] >= hi)
	{
		if (++ind >= num_stewards)								break;
		if (lo_ind == -1 && strength[ind] > lo)					lo_ind = ind;
		if (hi_ind == -1 && strength[num_stewards-ind-1] < hi)	hi_ind = num_stewards-ind-1;
	}
	
	// Output
	if (lo_ind == -1 || hi_ind == -1)	print(0);
	else								print(hi_ind-lo_ind+1);
	
	return 0;
}






