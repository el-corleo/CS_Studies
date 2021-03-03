/*
 * https://codeforces.com/problemset/problem/219/A
 
A string is called a k-string if it can be represented as k concatenated copies of some string. For example, the string "aabaabaabaab" is at the same time a 1-string, a 2-string and a 4-string, but it is not a 3-string, a 5-string, or a 6-string and so on. Obviously any string is a 1-string.

You are given a string s, consisting of lowercase English letters and a positive integer k. Your task is to reorder the letters in the string s in such a way that the resulting string is a k-string.

Input

The first input line contains integer k (1 ≤ k ≤ 1000). The second line contains s, all characters in s are lowercase English letters. The string length s satisfies the inequality 1 ≤ |s| ≤ 1000, where |s| is the length of string s.

Output

Rearrange the letters in string s in such a way that the result is a k-string. Print the result on a single output line. If there are multiple solutions, print any of them.

If the solution doesn't exist, print "-1" (without quotes).

SAMPLES:
2
aazz
	azaz

3
abcabcabz
	-1
 */
#include <iostream>
#include <string>

const int ascii_a = 97, ascii_z = 122;
int main()
{
	// INPUT
	std::string s, tmp="", ans="";
	int n;
	std::cin >> n;
	std::cin >> s;
	// count num of individual chars
	int char_map[ascii_z-ascii_a+1]; //range of ascii chars
	for (int i = 0; i < (ascii_z-ascii_a+1); i++)
		char_map[i]=0;
	for (int i = 0; i < s.length(); i++)
	{
		char_map[char(s[i])-ascii_a]++;
	}
	
	// PROCESS
	// if one of the chars is not divisible by n, then it cannot be repeated n times
	for (int i = 0; i < (ascii_z-ascii_a+1); i++)
		if (char_map[i]%n != 0)		ans = "-1";
	// make repeatable string
	if (ans != "-1")
		for (int i = 0; i < (ascii_z-ascii_a+1); i++)
			if (char_map[i] > 0)
				for (int j = 0; j < char_map[i]/n; j++)
					tmp+=char(i+ascii_a);
	// copy repeatable string n times
	for (int i = 0; i < n; i++)
		ans+=tmp;
	
	// OUTPUT
	std::cout << ans << std::endl;
	return 0;
}