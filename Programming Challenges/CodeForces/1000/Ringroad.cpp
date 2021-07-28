/*
 * https://codeforces.com/problemset/problem/339/B
 * 
 * Xenia lives in a city that has n houses built along the main ringroad. The ringroad houses are numbered 1 through n in the clockwise order. 
 * The ringroad traffic is one way and also is clockwise.
 *
 * Xenia has recently moved into the ringroad house number 1. 
 * As a result, she's got m things to do. In order to complete the i-th task, she needs to be in the house number ai and complete all tasks with numbers less than i. 
 * Initially, Xenia is in the house number 1, find the minimum time she needs to complete all her tasks if moving from a house to a neighboring one along the ringroad takes one unit of time.
 * 
 * Input
 *
 * The first line contains two integers n and m (2 ≤ n ≤ 105, 1 ≤ m ≤ 105). The second line contains m integers a1, a2, ..., am (1 ≤ ai ≤ n). 
 * Note that Xenia can have multiple consecutive tasks in one house.
 * 
 * Output
 *
 * Print a single integer — the time Xenia needs to complete all tasks.
 *
 * Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.
 *
 * Very poorly phrased question...
 * n = num houses
 * m = num tasks
 * a[m] = {house_num_task_1, ... , house_num_task_m}
 *
 * e.g.,	4 3 
 *			3 2 3 
 *			= 6
 *			4 3 
 *			2 3 3 
 *			= 2
 *
 * Goal: find out min time required to go to each house w/o back-tracking
 */
 #include <iostream>
 #include <cmath>
 
 int main()
 {
	// input
	int n, m, hs_1, hs_2;
	std::cin >> n >> m >> hs_1;
	// process
	long long ans = hs_1-1;
	for (int i = 0; i < m-1; i++)
	{
		std::cin >> hs_2;
		if (hs_1-hs_2 <= 0)	ans+= std::abs(hs_1-hs_2);
		else 				ans += (n-hs_1) + hs_2;
		hs_1 = hs_2;
	}
	// output
	std::cout << ans << std::endl;
	return 0;
 }