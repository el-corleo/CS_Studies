/*
 * https://codeforces.com/problemset/problem/272/A
 
 

Dima and his friends have been playing hide and seek at Dima's place all night. As a result, Dima's place got messy. In the morning they decided that they need to clean the place.

To decide who exactly would clean the apartment, the friends want to play a counting-out game. First, all the guys stand in a circle, and then each of them shows some number of fingers on one hand (one to five), and then the boys count in a circle, starting from Dima, the number of people, respective to the total number of fingers shown. The person on who the countdown stops will clean the apartment.

For example, if Dima and one of his friends played hide and seek, and 7 fingers were shown during the counting-out, then Dima would clean the place. If there were 2 or say, 8 fingers shown, then his friend would clean the place.

Dima knows how many fingers each of his friends will show during the counting-out. Now he is interested in the number of ways to show some number of fingers on one hand (one to five), so that he did not have to clean the place. Help Dima.

Input

The first line contains integer n (1 ≤ n ≤ 100) — the number of Dima's friends. Dima himself isn't considered to be his own friend. The second line contains n positive integers, not exceeding 5, representing, how many fingers the Dima's friends will show.

The numbers in the lines are separated by a single space.

Output

In a single line print the answer to the problem.

SAMPLES:
1
1
	3

1
2
	2

2
3 5
	3
 */

#include <iostream>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int getInt(std::istream& st)
{
	int n;
	std::cin >> n;
	return n;
}

int main()
{
	int nFriends, nFings = 0;
	std::cin >> nFriends;
	for (int i = 0; i < nFriends; i++)
		nFings += getInt(std::cin);
	
	// under 4 friends means more chances on landing on dima
	if (nFriends == 1)		Log((nFings%2==0) ? 2 : 3);
	else if (nFriends == 2)	Log((nFings%3==0 || nFings%3==2) ? 3 : 4);
	else if (nFriends == 3)	Log((nFings%4==0) ? 3 : 4);
	else if (nFriends == 4)	Log(4);
	// 5+ friends means there's only one chance max, sometimes 0
	else					
	{
		// this is the interval where it's impossible for him to lose
		// i.e.,	where nFings%(nFriends+1) is between [1,(nFriends+1-5)]
		// because always starts on dima AND total people (nFriends+1) minus dima's fingers (5<=)
		// means only possible losses occur on mod = 0 and the 4 before it
		if ((nFings%(nFriends+1) > 0) && (nFings%(nFriends+1) <= (nFriends+1-5)))
			Log(5);
		else
			Log(4);
	}
	
	
	return 0;
}