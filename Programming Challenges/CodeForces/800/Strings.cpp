/*
 * https://codeforces.com/problemset/problem/112/A
 
 Little Petya loves presents. His mum bought him two strings of the same size for his birthday. The strings consist of uppercase and lowercase Latin letters. Now Petya wants to compare those two strings lexicographically. The letters' case does not matter, that is an uppercase letter is considered equivalent to the corresponding lowercase letter. Help Petya perform the comparison.

Input
Each of the first two lines contains a bought string. The strings' lengths range from 1 to 100 inclusive. It is guaranteed that the strings are of the same length and also consist of uppercase and lowercase Latin letters.

Output
If the first string is less than the second one, print "-1". If the second string is less than the first one, print "1". If the strings are equal, print "0". Note that the letters' case is not taken into consideration when the strings are compared.

SAMPLE:
aaaa
aaaA
	0

abs
Abz
	-1
	
abcdefg
AbCdEfF
	1
 */

#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

/*
 * 		01000001 (char 'A')
 *	Or	00100000 (char ' ')
 *	= 	01100001 (char 'a')
 *	----------------------
 *		01100001 (char 'a')
 *	Or 	00100000 (char ' ')
 *	= 	01100001 (char 'a')
 */
char upper(char c)
{
	return c | ' ';
}

int main()
{
	std::string s_1, s_2;
	std::cin >> s_1 >> s_2;
	
	for (int i = 0; i < s_1.length(); i++)
		if (upper(char(s_1[i])) != upper(char(s_2[i])))
		{ Log((upper(char(s_1[i]))-upper(char(s_2[i])) > 0) ? 1 : -1); return 0; }
	
	Log("0");
	return 0;
}