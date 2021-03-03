/*
 * https://codeforces.com/problemset/problem/320/A
 
A magic number is a number formed by concatenation of numbers 1, 14 and 144. We can use each of these numbers any number of times. Therefore 14144, 141414 and 1411 are magic numbers but 1444, 514 and 414 are not.

You're given a number. Determine if it is a magic number or not.

Input

The first line of input contains an integer n, (1 ≤ n ≤ 10^9). This number doesn't contain leading zeros.

Output

Print "YES" if n is a magic number or print "NO" if it's not.

SAMPLES:
114114
	YES

1111
	YES

441231
	NO
 */
 #include <iostream>
 #include <string>
 
 bool poss(std::string &str, char ch, int &i, int cnt)
 {
	if (cnt == 0)		return false;
	if (ch == '1')		return true;
	if (ch == '4')		return poss(str, char(str[--i]), i, --cnt);
	else				return false;
 }
 
 int main()
 {
	// input
	std::string n;
	std::cin >> n;
	// process
	char ch;
	bool yes = true;
	for (int i = n.size()-1; i >= 0 ; i--)
	{
		ch = char(n[i]);
		if (poss(n, ch, i, 3))	continue;
		else 					{ yes = false; break; }
	}
	// output
	std::cout << ((yes) ? "YES" : "NO") << std::endl;
	return 0;
 }