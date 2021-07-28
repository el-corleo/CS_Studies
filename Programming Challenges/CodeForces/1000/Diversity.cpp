/*
https://codeforces.com/problemset/problem/844/A

Calculate the minimum number of characters you need to change in the string s, so that it contains at least k different letters, or print that it is impossible.

String s consists only of lowercase Latin letters, and it is allowed to change characters only to lowercase Latin letters too.
Input

First line of input contains string s, consisting only of lowercase Latin letters (1 ≤ |s| ≤ 1000, |s| denotes the length of s).

Second line of input contains integer k (1 ≤ k ≤ 26).
Output

Print single line with a minimum number of necessary changes, or the word «impossible» (without quotes) if it is impossible.

SAMPLES:
yandex
6
	0

yahoo
5
	1

google
7
	impossible

Observations:
	- If num_diff_let > word.length, then impossible
	- arr[26] that contains count for all letter types
	- If possible, then search for first 0 entry and first entry >1
		- decrement >1 entry, increment 0 entry, find next 0
		- if >1 entry is still >1, then repeat; else find next >1 entry
*/
#include <iostream>

int main()
{
	std::string word;
	std::cin >> word;
	int num_diff_let;
	std::cin >> num_diff_let;
	
	int word_len = 0, unique_lets = 0;
	int letters[26]{};
	
	// populate letters array
	for (char c : word)
	{
		// increment if val at index is 0, i.e., is a unique letter
		if (letters[c-'a'] == 0)	unique_lets++;
		// update letter count for that letter
		letters[c-'a']++;
		// update word length
		word_len++; 
	}

	// impossible
	if (num_diff_let > word_len)		{ std::cout << "impossible" << std::endl; return 0; }
	// already achieved, e.g., anonymous 6
	if (unique_lets >= num_diff_let)	{ std::cout << 0 << std::endl; return 0; }

	// possible
	int z_ind = 0;
	int non_z_ind = 0;
	int num_changes = 0;
	while(true)
	{
		// find first zero and non-zero ind
		while(letters[z_ind] != 0 && !(z_ind > 25))		z_ind++;
		while(letters[non_z_ind] < 2 && !(non_z_ind > 25))	non_z_ind++;	
		if(z_ind > 25 || non_z_ind > 25)			break;
		// decrement non-zero ind and increase zero
		letters[non_z_ind]--;
		letters[z_ind]++;
		// update result
		num_changes++;
		unique_lets++;
		// found min changes to satisfy 'at least' req.
		if(unique_lets == num_diff_let)		break;
	}
	// output result
	std::cout << num_changes << std::endl;
	return 0;
}
