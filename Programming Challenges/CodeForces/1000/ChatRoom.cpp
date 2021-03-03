/*
 * https://codeforces.com/problemset/problem/58/A
 
 

Vasya has recently learned to type and log on to the Internet. He immediately entered a chat room and decided to say hello to everybody. Vasya typed the word s. It is considered that Vasya managed to say hello if several letters can be deleted from the typed word so that it resulted in the word "hello". For example, if Vasya types the word "ahhellllloou", it will be considered that he said hello, and if he types "hlelo", it will be considered that Vasya got misunderstood and he didn't manage to say hello. Determine whether Vasya managed to say hello by the given word s.

Input

The first and only line contains the word s, which Vasya typed. This word consisits of small Latin letters, its length is no less that 1 and no more than 100 letters.

Output

If Vasya managed to say hello, print "YES", otherwise print "NO".

SAMPLE
ahhellllloou
YES

hlelo
NO
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input
	std::string typed;
	std::cin >> typed;
	
	// process
	bool letters[5];
	letters[0] = false;	letters[1] = false;	letters[2] = false;	letters[3] = false;	letters[4] = false;
	for (int i = 0; i < typed.length(); i++)
	{
		// check if letters appear in correct sequence
		if (!letters[0]) 		letters[0] = char(typed[i]) == 'h';
		else if (!letters[1])	letters[1] = char(typed[i]) == 'e';
		else if (!letters[2])	letters[2] = char(typed[i]) == 'l';
		else if (!letters[3])	letters[3] = char(typed[i]) == 'l';
		else if (!letters[4])	letters[4] = char(typed[i]) == 'o';
		// break if all are already found
		if (letters[4])	break;
	}
	
	// output
	// YES if all found in correct sequence
	if (letters[4])	Log("YES");
	else			Log("NO");
	
	return 0;
}