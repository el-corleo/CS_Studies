/*
 * https://codeforces.com/problemset/problem/165/A

 One day Vasya painted a Cartesian coordinate system on a piece of paper and marked some set of points (x_1, y_1), (x_2, y_2), ..., (x_n, y_n). Let's define neighbors for some fixed point from the given set (x, y):

    point (x', y') is (x, y)'s right neighbor, if x' > x and y' = y
    point (x', y') is (x, y)'s left neighbor, if x' < x and y' = y
    point (x', y') is (x, y)'s lower neighbor, if x' = x and y' < y
    point (x', y') is (x, y)'s upper neighbor, if x' = x and y' > y 

We'll consider point (x, y) from the given set supercentral, if it has at least one upper, at least one lower, at least one left and at least one right neighbor among this set's points.

Vasya marked quite many points on the paper. Analyzing the picture manually is rather a challenge, so Vasya asked you to help him. Your task is to find the number of supercentral points in the given set.
Input

The first input line contains the only integer n (1 ≤ n ≤ 200) — the number of points in the given set. Next n lines contain the coordinates of the points written as "x y" (without the quotes) (|x|, |y| ≤ 1000), all coordinates are integers. The numbers in the line are separated by exactly one space. It is guaranteed that all points are different.
Output

Print the only number — the number of supercentral points of the given set.

SAMPLE:
8
1 1
4 2
3 1
1 2
0 2
0 1
1 0
1 3
	2

5
0 0
0 1
1 0
0 -1
-1 0
	1
 */

#include <iostream>

struct Point {
	int x;
	int y;
	bool hasN = false;
	bool hasE = false;
	bool hasS = false;
	bool hasW = false;
};

int main()
{
	// load points
	int n;
	std::cin >> n;
	Point p_arr[n];
	for (int i = 0; i < n; i++)
	{
		int x, y;
		std::cin >> x >> y;
		Point p;
		p.x = x;
		p.y = y;
		p_arr[i] = p;
	}
	
	// go thru points and keep track of ones with neighbors
	// then track supercentral points
	int sc = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;
			if (p_arr[i].x == p_arr[j].x)
			{
				if (p_arr[i].y < p_arr[j].y) p_arr[i].hasN = true;
				if (p_arr[i].y > p_arr[j].y) p_arr[i].hasS = true;
			} else if (p_arr[i].y == p_arr[j].y)
			{
				if (p_arr[i].x < p_arr[j].x) p_arr[i].hasW = true;
				if (p_arr[i].x > p_arr[j].x) p_arr[i].hasE = true;
			}
		}
		// increment supercentral counter
		if (p_arr[i].hasN 
			&& p_arr[i].hasE 
			&& p_arr[i].hasS 
			&& p_arr[i].hasW)
			{ sc++; }
	}
	
	// output
	std::cout << sc << std::endl;
	
	return 0;
}