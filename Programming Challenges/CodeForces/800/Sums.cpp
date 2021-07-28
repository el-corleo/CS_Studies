/*
 * https://codeforces.com/problemset/problem/339/A

 Xenia the beginner mathematician is a third year student at elementary school. She is now learning the addition operation.

The teacher has written down the sum of multiple numbers. Pupils should calculate the sum. To make the calculation easier, the sum only contains numbers 1, 2 and 3. Still, that isn't enough for Xenia. She is only beginning to count, so she can calculate a sum only if the summands follow in non-decreasing order. For example, she can't calculate sum 1+3+2+1 but she can calculate sums 1+1+2 and 3+3.

You've got the sum that was written on the board. Rearrange the summans and print the sum in such a way that Xenia can calculate the sum.
Input

The first line contains a non-empty string s — the sum Xenia needs to count. String s contains no spaces. It only contains digits and characters "+". Besides, string s is a correct sum of numbers 1, 2 and 3. String s is at most 100 characters long.
Output

Print the new sum that Xenia can count.

SAMPLE:
3+2+1
	1+2+3

1+1+3+1+3
	1+1+1+3+3

2
	2
 */

#include <iostream>
#include <string>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	std::string sum;
	std::cin >> sum;
	int num[3] = {0, 0, 0};
	for (int i = 0; i < sum.length(); i++)
		switch (char(sum[i]))
		{
			case '1':	num[0]++; break;
			case '2':	num[1]++; break;
			case '3':	num[2]++; break;
		}
	
	std::string new_sum = "";
	for (int i = 0; i < num[0]; i++)
		new_sum += "1+";
	for (int i = 0; i < num[1]; i++)
		new_sum += "2+";
	for (int i = 0; i < num[2]; i++)
		new_sum += "3+";
	
	std::cout << new_sum.substr(0,new_sum.length()-1) << std::endl;
	
	return 0;
}