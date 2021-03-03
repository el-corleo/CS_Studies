/*
 * https://codeforces.com/problemset/problem/450/A

	troublesom inputs:
	10 5
	2 7 3 6 2 5 1 3 4 5
	=4
	
 	7 3
	6 1 5 4 2 3 1
	=4
	
	100 3
	4 14 20 11 19 11 14 20 5 7 6 12 11 17 5 11 7 6 2 10 13 5 12 8 5 17 20 18 7 19 11 7 7 20 20 8 10 17
	17 19 20 5 15 16 19 7 11 16 4 17 2 10 1 20 20 16 19 9 9 11 5 7 12 9 9 6 20 18 13 19 8 4 8 1 2 4 10
	11 15 14 1 7 17 12 13 19 12 2 3 14 15 15 5 17 14 12 17 14 16 9
 	=86
	
	solution:
	reduce problem
	e.g., above 100-item, 3-candy one can reduce to 
		21 19 17 16
		18 16 14 13
		15 13 11 10
		12 10 8  7
		9  7  5  4
		6  4  2  1
		3  1  -  -
	'4' will be the last one to leave because it comes later in the original order compared to '5'
	AND
	'2' and '1' are less than the 3-candy per time condition and will disappear before the '4'
 */

#include <iostream>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }
	
int main()
{
	int n, m;
	std::cin >> n >> m;
	int tmp, max = 0, max_ind = n;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> tmp;
		// REDUCTION STEP
		// divide by candy-per-time 'm'
		//		if not evenly divisible by 'm', add 1 more rotation
		//		before going home
		tmp = (tmp%m!=0) ? (tmp /= m)+1 : (tmp /= m);
		if (tmp >= max)
		{
			max = tmp;
			max_ind = i;
		}
	}
	
	Log(max_ind);
	
	return 0;
}