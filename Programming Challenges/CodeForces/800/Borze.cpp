/*
 * https://codeforces.com/problemset/problem/32/B
 */

#include <iostream>
#include <string>

int main()
{
	// get input
    std::string s;
    std::cin >> s;
    // parse answer starting from rear
    std::string ans;
    int ind = 0;
    while (ind < s.length())
    {
        if (char(s[ind]) == '.')		{ ans += "0"; ind++; }
		else if (char(s[ind+1]) == '.')	{ ans += "1"; ind+=2; }
		else							{ ans += "2"; ind+=2; }
    }
	// output answer
	std::cout << ans << std::endl;
	return 0;
}