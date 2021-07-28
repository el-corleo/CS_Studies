/*
 * https://codeforces.com/problemset/problem/34/A
 * 
 * n soldiers stand in a circle. For each soldier his height ai is known. 
 * A reconnaissance unit can be made of such two neighbouring soldiers, whose heights difference is minimal, i.e. |ai - aj| is minimal. 
 * So each of them will be less noticeable with the other. Output any pair of soldiers that can form a reconnaissance unit.
 * 
 * Input
 *
 * The first line contains integer n (2 ≤ n ≤ 100) — amount of soldiers. 
 * Then follow the heights of the soldiers in their order in the circle — n space-separated integers a1, a2, ..., an (1 ≤ ai ≤ 1000). 
 * The soldier heights are given in clockwise or counterclockwise direction.
 * 
 * Output
 *
 * Output two integers — indexes of neighbouring soldiers, who should form a reconnaissance unit. 
 * If there are many optimum solutions, output any of them. Remember, that the soldiers stand in a circle.
 *
 * SAMPLE
 * 5
 * 10 12 13 15 10
 *		5 1
 *
 * 4
 * 10 20 30 40
 * 		1 2
 */

#include <iostream>
#include <cmath>

int main()
{
	//input
	int n, first, h_1, h_2, min_ind_1, min_ind_2, min =1001;
	std::cin >> n >> first;
	for (int i = 0; i < n; i++, h_1 = h_2) // set h_1 for subsequent iterations
	{
		if (i < n-1)	std::cin >> h_2;
		if (i == 0)
		{
			if (std::abs(first-h_2) < min) { min = std::abs(first-h_2); min_ind_1 = i; min_ind_2 = i+1; }
		}
		else if (i == n-1)
		{
			if (std::abs(h_1-first) < min) { min_ind_1 = i; min_ind_2 = 0; }
		}
		else
		{
			if (std::abs(h_1-h_2) < min) { min = std::abs(h_1-h_2); min_ind_1 = i; min_ind_2 = i+1; }
		}
	}
	
	//output
	std::cout << ++min_ind_1 << " " << ++min_ind_2 << std::endl;
	return 0;
}