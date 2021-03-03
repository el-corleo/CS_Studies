/*
 * https://codeforces.com/problemset/problem/96/A
 
Petya loves football very much. One day, as he was watching a football match, he was writing the players' current positions on a piece of paper. To simplify the situation he depicted it as a string consisting of zeroes and ones. A zero corresponds to players of one team; a one corresponds to players of another team. If there are at least 7 players of some team standing one after another, then the situation is considered dangerous. For example, the situation 00100110111111101 is dangerous and 11110111011101 is not. You are given the current situation. Determine whether it is dangerous or not.

Input

The first input line contains a non-empty string consisting of characters "0" and "1", which represents players. The length of the string does not exceed 100 characters. There's at least one player from each team present on the field.

Output

Print "YES" if the situation is dangerous. Otherwise, print "NO".

SAMPLES:
001001
NO

1000000001
YES
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string s, ans = "NO";
	std::cin >> s;
	char ch = char(s[0]);
	int cnt = 1;
	
	for(int i = 1; i < s.length(); i++)
	{
		if (ch == char(s[i]))	cnt++;
		else					cnt = 1;
		if (cnt == 7)			{ ans = "YES"; break; }
		ch = char(s[i]);
	}
	
	Log(ans);
	
	return 0;
}