/*
 * https://www.hackerrank.com/challenges/drawing-book/problem
 */

#include <iostream>

/*-----------
 * prototypes
 *-----------
 */
 
 int pageCount(int p, int n);
 
/*-------------
 * main program
 *-------------
 */
 
int main()
{
	int p, n;
	std::cout << "p & n?" << std::endl;
	std::cin >> p >> n;
	std::cout << pageCount(p, n) << std::endl;
}

/*-------------------------------------------
 * takes as input number of pages in book (n)
 * and number of page to turn to (p)
 * returns minimum number of page turns to
 * get to target page
 *		-	1 <= p <= n <= 10e5
 * 		-	can start from front or back
 *		-	printed double-sided except for
 *			first (and possibly last, too)
 *-------------------------------------------
 */

int pageCount(int p, int n)
{
	// if p > n, then impossible
	if (p > n)			return -1;
	// determine whether closer to beginning or end
    if (p - n/2 <= 0)   return p/2; 			// return half total pages if closer to beginning
    else                return abs((p/2)-(n/2));// return half - middle if closer to end
}