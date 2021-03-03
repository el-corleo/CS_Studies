/*
 * https://codeforces.com/problemset/problem/352/A
 
 must end in 0 - sequences with no 0s are impossible
 must be divisible by 9
 
 ended up brute forcing to find patterns; turns out 
 only sequences with num_fives%9==0 and at least one zero can work
 */

#include<iostream>
#include<string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{	
	// input
	int n, tmp, fives = 0, zeroes = 0;
	bool has_zero = false;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp;
		if (!has_zero && tmp==0) has_zero = true;
		if (tmp==0)	zeroes++;
		else		fives++;
	}
	
	if (!has_zero)	{ Log(-1); }
	else if (fives>=9)
	{
		int iterations = fives/9;
		std::string num;  // must be a string; it's too big even for long long
		for (int i = 0; i < iterations*9; i++)
		{ num+="5"; }
		for (int i = 0; i < zeroes; i++)
		{ num+="0"; }
	
		Log(num);
	} else { Log(0); }
	
	return 0;
}