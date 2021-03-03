/*
 * https://codeforces.com/problemset/problem/459/B
	
	Pashmak decided to give Parmida a pair of flowers from the garden. There are n flowers in the garden and the i-th of them has a beauty number b i. Parmida is a very strange girl so she doesn't want to have the two most beautiful flowers necessarily. She wants to have those pairs of flowers that their beauty difference is maximal possible!

	Your task is to write a program which calculates two things:

	The maximum beauty difference of flowers that Pashmak can give to Parmida.

	The number of ways that Pashmak can pick the flowers. Two ways are considered different if and only if there is at least one flower that is chosen in the first way and not chosen in the second way.

	Input
	The first line of the input contains n (2≤n≤2·10^5). In the next line there are n space-separated integers b 1, b 2, ..., b n (1≤b i≤10^9).

	Output
	The only line of output should contain two integers. The maximum beauty difference and the number of ways this may happen, respectively.
	
	SAMPLE:
	1.)	input:	2
				1 1
		ouput:	1 1
	2.) input:	3
				1 4 5
		ouput:	4 1
	3.)	input:	5
				3 1 2 3 1
		ouput:	2 4
		
	Troublesome inputs:
	5
	1 1 1 1 1
	_ 4
	  _ 3
	    _ 2
		  _ 1

	Careful with overflow:
		- Multiplying two ints together and assigning the value to long long still produces overflow
		(as in test 4, where there were 200,000 elements all either 1 or 1000000000)
 */
#include <iostream>
#include <algorithm>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

long long sum(long long n) { long long sum = 0; while(n>0) sum+=n--; return sum; }

int main()
{
	// input
	long long nFlowers;
	std::cin >> nFlowers;
	int flower_beauty[nFlowers];
	for (int i = 0; i < nFlowers; i++)
		std::cin >> flower_beauty[i];
	
	// process
	std::sort(flower_beauty, flower_beauty+nFlowers);
	long long ind_min=0, ind_max=nFlowers-1, nMax=0, nMin=0;
	long long max=flower_beauty[ind_max], min=flower_beauty[ind_min];
	bool quit=false;
	while (!quit)
	{
		if (ind_min < nFlowers && flower_beauty[ind_min++] == min)	nMin++;
		if (ind_max >= 0 && flower_beauty[ind_max--] == max) 		nMax++;
		if ((ind_min > nFlowers-1 && ind_max < 0) 
			|| (flower_beauty[ind_min] != min && flower_beauty[ind_max] != max))
			quit = true;
	}
		
	long long combo;
	if (min==max)	combo = sum(nFlowers-1);
	else			combo = nMax*nMin;
	
	// output
	Log(std::to_string(max-min) + " " + std::to_string(combo));
	return 0;
}