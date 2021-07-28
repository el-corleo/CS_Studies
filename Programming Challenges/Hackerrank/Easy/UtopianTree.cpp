/*
 * https://www.hackerrank.com/challenges/utopian-tree/problem
 
The Utopian Tree goes through 2 cycles of growth every year. Each spring, it doubles in height. Each summer, its height increases by 1 meter.

A Utopian Tree sapling with a height of 1 meter is planted at the onset of spring. How tall will the tree be after

growth cycles?

For example, if the number of growth cycles is n=5, the calculations are as follows:

Function Description

Complete the utopianTree function in the editor below.

utopianTree has the following parameter(s):

    int n: the number of growth cycles to simulate

Returns

    int: the height of the tree after the given number of cycles

Input Format

The first line contains an integer, t, the number of test cases.
t subsequent lines each contain an integer, n, the number of cycles for that test case.

SAMPLE:
3
0
1
4
    1
    2
    7
 */

#include <iostream>

/*---------------
 * prototypes
 *---------------
 */

int grow(int num, int nTimes);

/*---------------
 * Main program
 *---------------
 */

int utopianTree(int n) {
    switch (n)
    {
        case 0:
            return 1;
        case 1:
            return 2;
        default:
			if (n%2 == 0)	return 1+grow(1, n-1);
			else			return grow(1, n);
    }
}

int grow(int num, int nTimes)
{
	std::cout << num << std::endl;
    // base case
    if (nTimes == 0)    return num;
    // even cycle OR odd
    if (nTimes%2 == 0)  return grow(num+1, nTimes-1);
    else                return grow(2*num, nTimes-1);
}

int main()
{
	int n;
	std::cout << "How many cycles?" << std::endl;
	std::cin >> n;
	std::cout << utopianTree(n) << std::endl;
}
	