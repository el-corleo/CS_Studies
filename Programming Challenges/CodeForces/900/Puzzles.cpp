/*
 * https://codeforces.com/problemset/problem/337/A
 
 The end of the school year is near and Ms. Manana, the teacher, will soon have to say goodbye to a yet another class. She decided to prepare a goodbye present for her n students and give each of them a jigsaw puzzle (which, as wikipedia states, is a tiling puzzle that requires the assembly of numerous small, often oddly shaped, interlocking and tessellating pieces).

The shop assistant told the teacher that there are m puzzles in the shop, but they might differ in difficulty and size. Specifically, the first jigsaw puzzle consists of f 1 pieces, the second one consists of f 2 pieces and so on.

Ms. Manana doesn't want to upset the children, so she decided that the difference between the numbers of pieces in her presents must be as small as possible. Let A be the number of pieces in the largest puzzle that the teacher buys and B be the number of pieces in the smallest such puzzle. She wants to choose such n puzzles that A-B is minimum possible. Help the teacher and find the least possible value of A-B.

Input
The first line contains space-separated integers n and m (2≤n≤m≤50). The second line contains m space-separated integers f_1,f_2,...,f_m (4≤f_i≤1000) — the quantities of pieces in the puzzles sold in the shop.

Output
Print a single integer — the least possible difference the teacher can obtain.

SAMPLES:
4 6
10 12 10 7 5 22
	5
 */
#include <iostream>
#include <algorithm>
#include <climits>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input 
	int nStud, nPuzz;
	std::cin >> nStud >> nPuzz;
	int puzzles[nPuzz];
	for (int i = 0; i < nPuzz; i++)
	{ std::cin >> puzzles[i]; }
	
	// process
	std::sort(puzzles, puzzles+nPuzz);
	int min = INT_MAX, upper;
	for (int lower = 0; lower <= nPuzz-nStud; lower++)
	{
		upper = lower+nStud-1;
		if (puzzles[upper] - puzzles[lower] < min)	min = puzzles[upper] - puzzles[lower]; 
	}
	
	// output
	Log(min);
	return 0;
}