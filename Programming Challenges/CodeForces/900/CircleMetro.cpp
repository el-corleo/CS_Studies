/*
 * https://codeforces.com/problemset/problem/1169/A

 The circle line of the Roflanpolis subway has n stations.

There are two parallel routes in the subway. The first one visits stations in order 1→2→…→n→1→2→… (so the next stop after station x is equal to (x+1) if x<n and 1 otherwise). 
The second route visits stations in order n→(n−1)→…→1→n→(n−1)→… (so the next stop after station x is equal to (x−1) if x>1 and n otherwise). 
All trains depart their stations simultaneously, and it takes exactly 1 minute to arrive at the next station.

Two toads live in this city, their names are Daniel and Vlad.

Daniel is currently in a train of the first route at station a and will exit the subway when his train reaches station x.

Coincidentally, Vlad is currently in a train of the second route at station b and he will exit the subway when his train reaches station y.

Surprisingly, all numbers a,x,b,y are distinct.

Toad Ilya asks you to check if Daniel and Vlad will ever be at the same station at the same time during their journey. In other words, check if there is a moment when their trains stop at the same station. 
Note that this includes the moments when Daniel or Vlad enter or leave the subway.

Input

The first line contains five space-separated integers n, a, x, b, y (4≤n≤100, 1≤a,x,b,y≤n, all numbers among a, x, b, y are distinct) — the number of stations in Roflanpolis, 
Daniel's start station, Daniel's finish station, Vlad's start station and Vlad's finish station, respectively.

Output

Output "YES" if there is a time moment when Vlad and Daniel are at the same station, and "NO" otherwise. You can print each letter in any case (upper or lower).

SAMPLE:
5 1 4 3 2
	YES

10 2 1 9 10
	NO

Observations:
	- Example 1
		- 5 stations | a = 1, x = 4 ; b = 3, y = 2
		- 1 2 3 4
		- 3 2
		- Intersect at 2
	- Example 2
		- 10 stations | a = 2, x = 1 ; b = 9, y = 10
		- 2 3 4 5 6 7 8 9 10 1
		- 9 8 7 6 5 4 3 2 1 10
		- No intersection
	- Brute force: (acceptable because of low guarantee for n <= 100)
		- Increment/Decrement (done first because a != x != b != y)
		- Test for equality
		- Repeat

 */
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	// Input
	int n, a, x, b, y;
	std::cin >> n >> a >> x >> b >> y;

	// Process
	while(a != x && b != y)
	{
		a = (a==n) ? 1 : a+1;
		b = (b==1) ? n : b-1;
		if (a == b) { print("YES"); return 0; } // found intersection
	}

	// no intersection
	print("NO");
	return 0;
}