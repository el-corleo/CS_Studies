/*
 *	When Serezha was three years old, he was given a set of cards with letters for his birthday. They were arranged into words in the way which formed the boy's mother favorite number in binary notation. Serezha started playing with them immediately and shuffled them because he wasn't yet able to read. His father decided to rearrange them. Help him restore the original number, on condition that it was the maximum possible one.

Input

The first line contains a single integer n
(1⩽n⩽10^5) — the length of the string. The second line contains a string consisting of English lowercase letters: 'z', 'e', 'r', 'o' and 'n'.

It is guaranteed that it is possible to rearrange the letters in such a way that they form a sequence of words, each being either "zero" which corresponds to the digit 0
or "one" which corresponds to the digit 1.

Output

Print the maximum possible number in binary notation. Print binary digits separated by a space. The leading zeroes are allowed.

*
*

	Observations:
	- Could keep an array of length five, scan through and place each letter in the input string into a bucket, then pull...
	- Calculate (num 'z') and calculate (num 'o' - num 'z') to find total num of ones and zeros;
		then print all the remaining 'o's as 1, followed by all the 'z's as 0
*/
#include<iostream>
#include<string>

int main()
{
	// Setup
	int len_str;
	std::cin >> len_str;
	std::string letters;
	std::cin >> letters;
	// Parse z's and o's
	int z_and_o[2] = {0,0};
	for (int i = 0; i < len_str; i++)
		if (char(letters[i]) == 'z')		z_and_o[0]++;
		else if (char(letters[i]) == 'o')	z_and_o[1]++;
	z_and_o[1] = z_and_o[1]-z_and_o[0]; // all non-'zero' related o's are for 'one'
	// Print results
	while (z_and_o[1] > 0)	{ std::cout << "1 "; z_and_o[1]--; }
	while (z_and_o[0] > 0)	{ std::cout << "0 "; z_and_o[0]--; }
	
	return 0;
}







