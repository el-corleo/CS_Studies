#include <iostream>

int main()
{
	// get total dragons
	int nD[5];
	bool all_drag = false;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> nD[i];
		if (nD[i] == 1)	all_drag = true;
	}
	
	// one among the divisors; all dragons suffer
	if (all_drag)		{ std::cout << nD[4] << std::endl; return 0; }
	// if number of dragons is less that k, l, m, n
	for (int i : nD)
		if (i > nD[4])	{ std::cout << 0 << std::endl; return 0; }
	
	// find primes up to nD
	int p[nD[4]/2];
	p[0] = 2;
	p[1] = 3;
	p[2] = 5;
	p[3] = 7;
	int ind = 4;
	bool is_prime;
	for (int i = 11; i < nD[4]; i++)
	{
		is_prime = true;
		for (int j = 0; j < ind; j++)
		{if (p[j] > nD[4]/2)	break;
			else if (i%p[j]==0)	{ is_prime = false; break; }
		}
		if (is_prime)	{ p[ind++] = i; }
	}
	
	// eliminate primes that are factors
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (nD[j] == p[i]) ind--;
	
	// return count of all non-prime numbers up to (-1 is for 1st dragon)
	std::cout << (nD[4]-ind-1) << std::endl;
	
	return 0;
}