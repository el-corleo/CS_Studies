/*
 * https://codeforces.com/problemset/problem/205/A
 *
 * The Little Elephant loves Ukraine very much. Most of all he loves town Rozdol (ukr. "Rozdil").
 *
 * However, Rozdil is dangerous to settle, so the Little Elephant wants to go to some other town. 
 * The Little Elephant doesn't like to spend much time on travelling, so for his journey he will choose a town that needs minimum time to travel to. 
 * If there are multiple such cities, then the Little Elephant won't go anywhere.
 *
 * For each town except for Rozdil you know the time needed to travel to this town. Find the town the Little Elephant will go to or print "Still Rozdil", if he stays in Rozdil.
 *
 * Input
 *
 * The first line contains a single integer n (1 ≤ n ≤ 105) — the number of cities. 
 * The next line contains n integers, separated by single spaces: the i-th integer represents the time needed to go from town Rozdil to the i-th town. 
 * The time values are positive integers, not exceeding 109.
 *
 * You can consider the cities numbered from 1 to n, inclusive. Rozdil is not among the numbered cities.
 *
 * Output
 *
 * Print the answer on a single line — the number of the town the Little Elephant will go to. 
 * If there are multiple cities with minimum travel time, print "Still Rozdil" (without the quotes).
 *
 * consider the case that there are multiple cities the same distance away,
 * BUT that there is also one that is closer than them
 * THUS, must traverse the whole list
 */

#include <iostream>

int main()
{
	//input
	int n, tmp, min_city_ind, min = 1000000001;
	std::cin >> n;
	bool still_R = false;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> tmp;
		if (tmp == min)	{ still_R = true; }
		if (tmp < min)	{ min = tmp; min_city_ind = i; still_R = false; }
	}
	
	//output
	if (still_R)	std::cout << "Still Rozdil" << std::endl;
	else			std::cout << min_city_ind << std::endl;
	return 0;
}