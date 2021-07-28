/*
 * https://codeforces.com/problemset/problem/282/A
 */

#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	int result = 0;
	int instr;
	std::string s;
	std::cin >> instr;
	for (int i = 0; i < instr; i++)
	{
		std::cin >> s;
		for (int j = 0; j < s.length(); j++)
			if (char(s[j]) == '+')		{ result++; break; }
			else if (char(s[j]) == '-')	{ result--; break; }
	}

	Log(result);
	return 0;
}