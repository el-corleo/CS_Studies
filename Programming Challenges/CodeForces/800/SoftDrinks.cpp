/*
 * https://codeforces.com/problemset/problem/151/A
 */

#include <iostream>
#include <algorithm>

int main()
{
	int n, k, l, c, d, p, nl, np;
	std::cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	
	// n friends
	// k*l milliliters of drink
	// c*d slices of lime
	// p grams of salt
	
	// nl milliliters per toast + 1 slice of lime + np grams of salt
	// max toasts given quantity
	
	// min of drink, lime, salt
	int drink = (k*l)/nl/n;
	int lime = (c*d)/n;
	int salt = p/np/n;
	
	std::cout << std::min(std::min(drink, lime), salt) << std::endl;
	
	return 0;
}