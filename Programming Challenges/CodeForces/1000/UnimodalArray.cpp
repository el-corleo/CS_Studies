/*
	URL: https://codeforces.com/problemset/problem/831/A

	DESCRIPTION:

	An array of integers is unimodal, if:

    - it is strictly increasing in the beginning;
    - after that it is constant;
    - after that it is strictly decreasing. 

	The first block (increasing) and the last block (decreasing) may be absent. It is allowed that both of this blocks are absent.

	For example, the following three arrays are unimodal: [5, 7, 11, 11, 2, 1], [4, 4, 2], [7], but the following three are not unimodal: [5, 5, 6, 6, 1], [1, 2, 1, 2], [4, 5, 5, 6].

	Write a program that checks if an array is unimodal.

	INPUT:

	The first line contains integer n (1 ≤ n ≤ 100) — the number of elements in the array.

	The second line contains n integers a1, a2, ..., an (1 ≤ ai ≤ 1 000) — the elements of the array.

	OUTPUT:

	Print "YES" if the given array is unimodal. Otherwise, print "NO".

	You can output each letter in any case (upper or lower).
*/
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	int n, a, b;
	std::cin >> n;
	std::cin >> a;	// get first element
	bool is_unimodal = true;
	int phase = 0;
	while (is_unimodal)
	{
		// if n == 1, then automatically unimodal
		if (n == 1)	break;

		std::cin >> b;	// get next element
		switch (phase) {
			// ascending
			case 0:
				if (a == b)	phase++;
				if (a > b)	phase += 2;
				break;
			// constant
			case 1:
				if (a < b)	is_unimodal = false; 
				if (a > b)	phase++;
				break;
			// descending
			case 2:
				if (a <= b)	is_unimodal = false;
				break;
		}
		
		a = b; // move forward 
		n--;
	}

	if (is_unimodal)	print("YES");
	else				print("NO");

	return 0;
}
