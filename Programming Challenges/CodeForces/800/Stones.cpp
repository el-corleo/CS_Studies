/*
 * http://codeforces.com/problemset/problem/266/A
 
	There are n stones on the table in a row, each of them can be red, green or blue. Count the minimum number of stones to take from the table so that any two neighboring stones had different colors. Stones in a row are considered neighboring if there are no other stones between them.

Input
The first line contains integer n (1 ≤ n ≤ 50) — the number of stones on the table.

The next line contains string s, which represents the colors of the stones. We'll consider the stones in the row numbered from 1 to n from left to right. Then the i-th character s equals "R", if the i-th stone is red, "G", if it's green and "B", if it's blue.

Output
Print a single integer — the answer to the problem.

SAMPLE:
3
RRG
	1
	
5
RRRRR
	4
	
4
BRBG
	0
 */

#include <iostream>
#include <string>

int main()
{
	int len;
	std::string s;
	std::cin >> len >> s;
	char ch = char(s[0]);
	int removals = 0;
	
	for (int i = 1; i < len; i++)
	{
		if (char(s[i] == ch))	{ removals++; }
		else					{ ch = char(s[i]); }
	}
	
	std::cout << removals << std::endl;
	
	return 0;
}