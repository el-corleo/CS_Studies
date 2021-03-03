/*
 * https://codeforces.com/problemset/problem/124/A
 
 Petr stands in line of n people, but he doesn't know exactly which position he occupies. He can say that there are no less than a people standing in front of him and no more than b people standing behind him. Find the number of different positions Petr can occupy.

Input
The only line contains three integers n, a and b (0≤a,b<n≤100).

Output
Print the single number — the number of the sought positions.

SAMPLES:
3 1 1
	2
	
5 2 3
	3
 */
 
#include <iostream>
 
int min(int a, int b) { return (a > b) ? b : a; }
 
int main()
{
    int n, a, b;
    std::cin >> n >> a >> b;
    std::cout << min(n-a, b+1) << std::endl;    
    return 0;
}