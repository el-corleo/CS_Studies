/*
 * https://codeforces.com/problemset/problem/215/A
 */
#include <iostream>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input & process
	int max_rat = 0, num_gears = 0, rat;
	int n;
	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	int m, b;
	std::cin >> m;
	for (int i = 0; i < m; i++)
	{
		std::cin >> b;
		for (int j = 0; j < n; j++)
		{
			rat = b/a[j];
			if (b%a[j] == 0 && rat > max_rat)		{ max_rat = rat; num_gears = 1; }
			else if (b%a[j] == 0 &&rat == max_rat)	{ num_gears++; }
		}
	}	
	// output
	Log(num_gears);
	return 0;
}