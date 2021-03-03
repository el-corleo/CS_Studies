/*
 * https://codeforces.com/contest/148/problem/A

«One dragon. Two dragon. Three dragon», — the princess was counting. She had trouble falling asleep, and she got bored of counting lambs when she was nine.

However, just counting dragons was boring as well, so she entertained herself at best she could. Tonight she imagined that all dragons were here to steal her, and she was fighting them off. Every k-th dragon got punched in the face with a frying pan. Every l-th dragon got his tail shut into the balcony door. Every m-th dragon got his paws trampled with sharp heels. Finally, she threatened every n-th dragon to call her mom, and he withdrew in panic.

How many imaginary dragons suffered moral or physical damage tonight, if the princess counted a total of d dragons?

Input

Input data contains integer numbers k, l, m, n and d, each number in a separate line (1 ≤ k, l, m, n ≤ 10, 1 ≤ d ≤ 10^5).

Output

Output the number of damaged dragons.

SAMPLE:
1
2
3
4
12
12

2
3
4
5
24
17

 */

#include <iostream>
#include <vector>

bool inVec(std::vector<int> &v, int e)
{
	for(int i = 0; i < v.size(); i++)
		if (v.at(i)==e) return true;
	return false;
}

bool divisByOther(int e, std::vector<int> &v, int skip)
{
	for (int i = skip+1; i < v.size(); i++) 
		if (e%v.at(i)==0) return true;
	return false;
}

int main()
{
	// get total dragons
	int nD[5];
	bool all_drag = false;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> nD[i];
		if (i != 4 && nD[i] == 1)	all_drag = true;
	}
	
	// one among the divisors; all dragons suffer
	if (all_drag)		{ std::cout << nD[4] << std::endl; return 0; }
	// if number of dragons is less that k, l, m, n
	if (nD[0] > nD[4] && nD[1] > nD[4] && nD[2] > nD[4] && nD[3] > nD[4])
		{ std::cout << 0 << std::endl; return 0; }
	
	// eliminate redundancy
	std::vector<int> toCheck;
	for (int i = 0; i < 4; i++)
	{ 
		bool add = true;
		for (int j = 0; j < 4; j++)
		{
			if (j != i && (nD[i]%nD[j]==0))
				add = false;
			if (nD[i]==nD[j] && !inVec(toCheck,nD[i]))
				add = true;
		}	
		if (add)
			toCheck.push_back(nD[i]);
	}
		
	// all factors
	std::vector<int> facts;
	for (int i = 0; i < toCheck.size(); i ++)
		for (int j = toCheck.at(i); j <= nD[4]; j+=toCheck.at(i))
			if (!divisByOther(j, toCheck, i)) facts.push_back(j);
	
	// return count of all non-prime numbers up to (-1 is for 1st dragon)
	std::cout << facts.size() << std::endl;
	
	return 0;
}