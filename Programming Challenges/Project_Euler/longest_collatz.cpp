/*
https://projecteuler.net/problem=14



The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:
13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.

SUGGESTED OPTIMIZATIONS:
	- Dynamic Programming approach to store values already terminated in a hash table, then search at the end and return cnt + hashed value's cnt
*/
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int collatz(unsigned long seed)
{

	int cnt = 0;
	while(seed != 1)
	{
		//print(seed);
		if (seed%2==0)	seed /= 2;
		else		seed = 3*seed + 1;
		cnt++; 
	}
	return cnt;
}

int main()
{
	int limit = 1000000;
	int longest = 0;
	int seed = 0;
	for (int i = 1; i < limit; i++)
	{
		/*
		if (i%2==0)
		{
			print("Orig i:");
			print(i);
			int x = i;
			while ((x>>1)%2==0) { x = x>>1; print(x); }
		}
		*/
		int steps = collatz(i);
		if (steps > longest)	{ longest = steps; seed = i; }
		//if (i%100000==0)	{ print("SEED:"); print(seed); }
	}

	print(seed);
	
	return 0;
}
