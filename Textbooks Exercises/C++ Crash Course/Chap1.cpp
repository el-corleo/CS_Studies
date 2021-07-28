/*
 * Exercises for Chap. 1 of Lospinoso - C++ Crash Course
 */

#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

// Ex 1-1, 1-2, & 1-3
int abs(int a) { return (a < 0) ? (a*-1) : a; }

// Ex 1-4
int sum(int a, int b) { return a+b; }

int main()
{
	int a,b,c;
	std::cin >> a >> b >> c;
	print(abs(a));
	print(sum(b,c));

	return 0;
}