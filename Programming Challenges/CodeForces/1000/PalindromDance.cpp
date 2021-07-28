/*
 * https://codeforces.com/problemset/problem/1040/A
 
 A group of n dancers rehearses a performance for the closing ceremony. The dancers are arranged in a row, they've studied their dancing moves and can't change positions. For some of them, a white dancing suit is already bought, for some of them — a black one, and for the rest the suit will be bought in the future.

On the day when the suits were to be bought, the director was told that the participants of the olympiad will be happy if the colors of the suits on the scene will form a palindrome. A palindrome is a sequence that is the same when read from left to right and when read from right to left. The director liked the idea, and she wants to buy suits so that the color of the leftmost dancer's suit is the same as the color of the rightmost dancer's suit, the 2nd left is the same as 2nd right, and so on.

The director knows how many burls it costs to buy a white suit, and how many burls to buy a black suit. You need to find out whether it is possible to buy suits to form a palindrome, and if it's possible, what's the minimal cost of doing so. Remember that dancers can not change positions, and due to bureaucratic reasons it is not allowed to buy new suits for the dancers who already have suits, even if it reduces the overall spending.

Input
The first line contains three integers n, a, and b (1≤n≤20, 1≤a,b≤100) — the number of dancers, the cost of a white suit, and the cost of a black suit.

The next line contains n numbers c_i, i-th of which denotes the color of the suit of the i-th dancer. Number 0 denotes the white color, 1 — the black color, and 2 denotes that a suit for this dancer is still to be bought.

Output
If it is not possible to form a palindrome without swapping dancers and buying new suits for those who have one, then output -1. Otherwise, output the minimal price to get the desired visual effect.

SAMPLE:
5 100 1
0 1 2 1 2
	101
	
3 10 12
1 2 0
	-1
	
3 12 1
0 1 0
	0

Observations:
- match elements from endpoints toward center
	- note 0 = 0 and 0 = 2, 1 = 1 and 1 = 2
	- if one element = 2, add its pair's cost (either black or white) to total
	- if both elements = 2, add 2 * min(black_cost, white_cost)
		- [despite writing this before solving, I forget the '2*' and failed on the 11th test]
	- if elements don't match, immediately return -1, as swapping is not possible
 */
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

bool match(int a, int b, int &wh_cost, int &bl_cost, int &tot_cost)
{
	if (a == b)
	{
		// both have no set color
		if (a == 2)	tot_cost += (wh_cost < bl_cost) ? 2*wh_cost : 2*bl_cost;
		return true;
	} else if (a == 2 || b == 2)
	{
		// a has no set color
		if (a == 2)	tot_cost += (b == 0) ? wh_cost : bl_cost; // b is white, then white, else black
		else		tot_cost += (a == 0) ? wh_cost : bl_cost;
		return true;
	}
	
	return false;
}

int main()
{	
	// Setup
	int num_dancers, wh_cost, bl_cost, tot_cost = 0;;
	std::cin >> num_dancers >> wh_cost >> bl_cost;
	int dancer_order[num_dancers];
	for (int i = 0; i < num_dancers; i++)
		std::cin >> dancer_order[i];
	
	// Process
	for (int i = 0; i < num_dancers/2; i++)
		if (!match(dancer_order[i], dancer_order[num_dancers-i-1], wh_cost, bl_cost, tot_cost)) { print(-1); return 0; }
	
	// Check if odd length and if element @ num_dancers/2 == 2
	if (num_dancers%2 != 0 && dancer_order[num_dancers/2] == 2)
	{ tot_cost += (wh_cost < bl_cost) ? wh_cost : bl_cost; }
		
	print(tot_cost);
	
	return 0;
}