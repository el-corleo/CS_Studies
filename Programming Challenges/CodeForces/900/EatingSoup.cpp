/*
 * https://codeforces.com/problemset/problem/1163/A

 The three friends, Kuro, Shiro, and Katie, met up again! It's time for a party...

What the cats do when they unite? Right, they have a party. Since they wanted to have as much fun as possible, they invited all their friends. 
Now n cats are at the party, sitting in a circle and eating soup. The rules are simple: anyone having finished their soup leaves the circle.

Katie suddenly notices that whenever a cat leaves, the place where she was sitting becomes an empty space, which means the circle is divided 
into smaller continuous groups of cats sitting next to each other. At the moment Katie observes, there are m cats who left the circle. 
This raises a question for Katie: what is the maximum possible number of groups the circle is divided into at the moment?

Could you help her with this curiosity?

Input

The only line contains two integers n and m (2≤n≤1000, 0≤m≤n) — the initial number of cats at the party and the number of cats who left the circle 
at the moment Katie observes, respectively.

Output

Print a single integer — the maximum number of groups of cats at the moment Katie observes.

SAMPLE:
7 4
	3

6 2
	2

3 0
	1

2 2
	0
	
Troublesome Inputs:
729 501
	228

Observations:
	- A group is defined as a vertex of degree x and all its connected nodes, even if x = 0
	- How can you remove m vertices to leave the maximum number of groups?
	- Case n == m
		- Return 0, as no cats are left
	- Case m == 0, m == 1, or n-m == 1
		- Return 1, as all components still connected
	- Case n = 2k+1
		- Ex n = 7
			- m = 0 or m = 1, answer is 1
			- m = 2, answer is 2
			- m = 3, answer is 3
			- m = 4, answer is 3
			- m = 5, answer is 2
			- m = 6, answer is 1
		- Subcases m = 2b+1 or m=2b+2 are equal

	- Case n = 2k
		- Ex n = 6
			- m = 0 or m = 1, answer is 1
			- m = 2, answer is 2
			- m = 3, answer is 3
			- m = 4, answer is 2
			- m = 5, answer is 1
	- for n/2 >= m >= 2
		- return (n/2)-((n/2)-m)
	- for n-1 >= m > n/2
		- return (n/2)-(m-(n/2))	
 */
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	int n, m;
	std::cin >> n >> m;

	// Case 0, 1, n-1
	if (m == 0)						{ print(1); return 0; }
	// Case m == n
	if (m == n)						{ print(0); return 0; } 
	// 2 | n
	if 		(n%2==0 && m < (n/2))	{ print(m); return 0; }
	else if (n%2==0 && m >= (n/2))	{ print(n-m); return 0; }
	// ~ 2 | n
	if 		(m <= (n/2))			{ print(m); return 0; }
	else							{ print(n-m); return 0; }

	return 0;
}