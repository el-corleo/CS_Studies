/*
 * http://codeforces.com/problemset/problem/281/A
 
Capitalization is writing a word with its first letter as a capital letter. Your task is to capitalize the given word.

Note, that during capitalization all the letters except the first one remains unchanged.
Input

A single line contains a non-empty word. This word consists of lowercase and uppercase English letters. The length of the word will not exceed 10^3.
Output

Output the given word after capitalization.

SAMPLE:
ApPLe
	ApPLe

konjac
	Konjac
 */

#include <iostream>

int main()
{
	std::string w;
	std::cin >> w;
	
	if (char(w[0]) < 97)	{ std::cout << w << std::endl; }
	else					{ std::cout << char(w[0]-32) << w.substr(1) << std::endl; }
						
	return 0;
}