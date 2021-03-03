/*
 * https://codeforces.com/problemset/problem/199/A
 

Recently, a chaotic virus Hexadecimal advanced a new theorem which will shake the Universe. She thinks that each Fibonacci number can be represented as sum of three not necessary different Fibonacci numbers.

Let's remember how Fibonacci numbers can be calculated. F 0 = 0, F 1 = 1, and all the next numbers are F i = F i - 2 + F i - 1.

So, Fibonacci numbers make a sequence of numbers: 0, 1, 1, 2, 3, 5, 8, 13, ...

If you haven't run away from the PC in fear, you have to help the virus. Your task is to divide given Fibonacci number n by three not necessary different Fibonacci numbers or say that it is impossible.

Input

The input contains of a single integer n (0 ≤ n < 10^9) — the number that should be represented by the rules described above. It is guaranteed that n is a Fibonacci number.

Output

Output three required numbers: a, b and c. If there is no answer for the test you have to print "I'm too stupid to solve this problem" without the quotes.

If there are multiple answers, print any of them.
 
 SAMPLES:
 3
 1 1 1
 
 13
 2 3 8
 
 Observations:
 if you can use any three fib numbers, then just use 0 + the original two that generate the next fib num
 */

#include<iostream>
#include<string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

const int fib[] = {	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733 };

int main()
{
	// input
	int n;
	std::cin >> n;
	
	// determine factors
	int facts[3];
	facts[0] = 0;
	int i = 1;
	while (fib[i] < n)
	{
		facts[1] = fib[i-1];
		facts[2] = fib[i];
		i++;
	}
	
	// in case n is zero, make all entries 0
	if (n==0) { facts[1] = 0; facts[2] = 0; }
	if (n==1) { facts[1] = 0; facts[2] = 1; }

	// print
	Log(std::to_string(facts[0]) + " " + std::to_string(facts[1]) + " " + std::to_string(facts[2]));
	return 0;
}