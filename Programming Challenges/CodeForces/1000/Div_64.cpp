/*
	URL: https://codeforces.com/problemset/problem/887/A

	DESCRIPTION:

	Top-model Izabella participates in the competition. She wants to impress judges and show her mathematical skills.

Her problem is following: for given string, consisting of only 0 and 1, tell if it's possible to remove some digits in such a way, that remaining number is a representation of some positive integer, divisible by 64, in the binary numerical system.

	INPUT:

	In the only line given a non-empty binary string s with length up to 100.

	OUTPUT:

	Print «yes» (without quotes) if it's possible to remove digits required way and «no» otherwise.

	SAMPLES:

	100010001
		yes

	100
		no

	OBSERVATIONS:
		NOTABLE CONSTRAINTS
			- must be a multiple of 64
				- 0000 0100 0000 + 0100 0000
				- 0000 1000 0000 + 0100 0000
				- 0000 1100 0000 + 0100 0000
				- 0001 0000 0000 etc.

		EDGE CASES
			- if length of string of 0s and 1s < 7; auto fail
			- if > 7, but no 1s beyond pos 7; auto fail

		POSS ALGOS
			- count zeroes after first 1, if >5, yes; else, no
		
*/
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	// Input
	std::string seq;
	std::cin >> seq;

	// Process
	bool first_1_found = false;
	int n_zeroes = 0;
	for(int i = 0; seq[i] != NULL; i++)
	{
		if (seq[i] == '1')			first_1_found = true;
		if (first_1_found && seq[i] == '0')	n_zeroes++;	
	}

	// Output
	if (n_zeroes > 5)	print("yes");
	else			print("no");

	return 0;
}

