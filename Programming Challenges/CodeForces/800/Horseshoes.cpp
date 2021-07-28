/*
 * https://codeforces.com/problemset/problem/228/A
 
Valera the Horse is going to the party with friends. He has been following the fashion trends for a while, and he knows that it is very popular to wear all horseshoes of different color. Valera has got four horseshoes left from the last year, but maybe some of them have the same color. In this case he needs to go to the store and buy some few more horseshoes, not to lose face in front of his stylish comrades.

Fortunately, the store sells horseshoes of all colors under the sun and Valera has enough money to buy any four of them. However, in order to save the money, he would like to spend as little money as possible, so you need to help Valera and determine what is the minimum number of horseshoes he needs to buy to wear four horseshoes of different colors to a party.

Input

The first line contains four space-separated integers s 1, s 2, s 3, s 4 (1 ≤ s 1, s 2, s 3, s 4 ≤ 10^9) — the colors of horseshoes Valera has.

Consider all possible colors indexed with integers.

Output

Print a single integer — the minimum number of horseshoes Valera needs to buy.

SAMPLES:
1 7 3 3
1

7 7 7 7
3
 */

#include <iostream>
#include <set>

template<typename T>
void LOG(T t) { std::cout << t << std::endl; }

int main()
{
	int shoes[4];
	std::cin >> shoes[0];
	std::cin >> shoes[1];
	std::cin >> shoes[2];
	std::cin >> shoes[3];
	int shoes_2_buy = 0;
	std::set<int> used;
	
	for(int i = 0; i < 3; i++)
	{
		if (used.find(shoes[i])!=used.end()) continue;
		used.insert(shoes[i]);
		
		for(int j = i+1; j < 4; j++)
			if (shoes[i]==shoes[j]) shoes_2_buy++;
	}
	
	LOG(shoes_2_buy);
			
	return 0;
}