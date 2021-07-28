/*
 *	https://codeforces.com/problemset/problem/989/A
 
The landscape can be expressed as a row of consecutive cells, each of which either contains a flower of colour amber or buff or canary yellow, or is empty.

When a flower withers, it disappears from the cell that it originally belonged to, and it spreads petals of its colour in its two neighbouring cells (or outside the field if the cell is on the side of the landscape). In case petals fall outside the given cells, they simply become invisible.

You are to help Kanno determine whether it's possible that after some (possibly none or all) flowers shed their petals, at least one of the cells contains all three colours, considering both petals and flowers. Note that flowers can wither in arbitrary order.

Input

The first and only line of input contains a non-empty string s
consisting of uppercase English letters 'A', 'B', 'C' and characters '.' (dots) only (|s|≤100

) — denoting cells containing an amber flower, a buff one, a canary yellow one, and no flowers, respectively.

Output

Output "Yes" if it's possible that all three colours appear in some cell, and "No" otherwise.

You can print each letter in any case (upper or lower).

SAMPLES:
.BAC.
	Yes

AA..CB
	No

Observations:
-Just need to find a sequence of ABC, ACB, BAC, BCA, CAB, CBA in the string
*/
#include <iostream>

int main()
{
	// Input
	std::string landscape;
	std::cin >> landscape;
	
	// Process & Output
	if (landscape.find("ABC")!=std::string::npos ||
		landscape.find("ACB")!=std::string::npos ||
		landscape.find("BAC")!=std::string::npos ||
		landscape.find("BCA")!=std::string::npos ||
		landscape.find("CAB")!=std::string::npos ||
		landscape.find("CBA")!=std::string::npos)	std::cout << "Yes" << std::endl;
	else											std::cout << "No" << std::endl;
	
	return 0;
}







