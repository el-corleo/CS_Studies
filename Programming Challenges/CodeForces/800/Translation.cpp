/*
 * https://codeforces.com/problemset/problem/41/A
 
The translation from the Berland language into the Birland language is not an easy task. Those languages are very similar: a berlandish word differs from a birlandish word with the same meaning a little: it is spelled (and pronounced) reversely. For example, a Berlandish word code corresponds to a Birlandish word edoc. However, it's easy to make a mistake during the «translation». Vasya translated word s from Berlandish into Birlandish as t. Help him: find out if he translated the word correctly.
Input

The first line contains word s, the second line contains word t. The words consist of lowercase Latin letters. The input data do not consist unnecessary spaces. The words are not empty and their lengths do not exceed 100 symbols.
Output

If the word t is a word s, written reversely, print YES, otherwise print NO.

SAMPLE:
code
edoc
	YES

abb
aba
	NO

code
code
	NO
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string s, t, ans = "NO";
	std::cin >> s >> t;
	
	if (s.size() == t.size())
	{
		ans = "YES";
		for (int i = 0; i < s.size(); i++)
			if (char(s[i]) != char(t[t.size()-1-i])) { ans = "NO"; break; }
	}
	
	Log(ans);
	return 0;
}