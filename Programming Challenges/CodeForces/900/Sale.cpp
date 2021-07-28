/*
 * https://codeforces.com/problemset/problem/34/B
 
 Once Bob got to a sale of old TV sets. There were n TV sets at that sale. TV set with index i costs ai bellars. Some TV sets have a negative price — their owners are ready to pay Bob if he buys their useless apparatus. Bob can «buy» any TV sets he wants. Though he's very strong, Bob can carry at most m TV sets, and he has no desire to go to the sale for the second time. Please, help Bob find out the maximum sum of money that he can earn.

Input
The first line contains two space-separated integers n and m (1≤m≤n≤100) — amount of TV sets at the sale, and amount of TV sets that Bob can carry. The following line contains n space-separated integers a_i (-1000≤a_i≤1000) — prices of the TV sets.

Output
Output the only number — the maximum sum of money that Bob can earn, given that he can carry at most m TV sets.

SAMPLE:
5 3
-6 0 35 -2 4
	8
	
4 2
7 0 0 -7
	7
 */
#include <iostream>
#include <algorithm>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input & process
	int n, m, price, num_neg = 0, neg_tot = 0;
	std::cin >> n >> m;
	int prices[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> price;
		prices[i] = 0;
		if (price < 0)	{ prices[i] = price; num_neg++; neg_tot += price; }
	}

	// output
	if (num_neg <= m )	Log((-1*neg_tot));
	else
	{
		neg_tot = 0;
		std::sort(prices, prices+n);
		for (int i = 0; i < m; i++)
			neg_tot += prices[i];
		Log((-1*neg_tot));
	}
	return 0;
}