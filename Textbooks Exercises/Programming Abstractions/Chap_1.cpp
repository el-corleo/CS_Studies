/*
 *	Programming Abstractions Chap. 1
 */
#include <iostream>
#include <vector>
#include <math.h>

template <typename Output>
void print(Output o) { std::cout << o << std::endl; }

int get_input() { int i; std::cin >> i; return i; }


// PROTOTYPES
int ex_one(int);
std::string ex_two(int);
int ex_three();
int ex_four();
int ex_five();
std::string ex_six();
float ex_seven();
int ex_eight();
std::string ex_nine();
void find_factors(std::vector<int>&, int, int);
void find_primes(std::vector<int>&, int);
void ex_ten();
void hailstone(int);
float ex_eleven();
float ex_tweleve();


int main()
{
	// Convert Celsius to Farenheit
	//print(ex_one(get_input())); 
	
	// Convert Meters to Feet & Inches
	//print(ex_two(get_input()));
	
	// Gauss Sum from 1-100
	//print(ex_three());
	
	// Sum of first N odd integers
	//print(ex_four());
	
	// Read input from client until Sentinel 0, then print highest value entered
	//print(ex_five());
	
	// Same as five but with highest and second highest
	//print(ex_six());
	
	// Average of exam scores
	//print(ex_seven());
	
	// Reverse digits
	//print(ex_eight());
	
	// Prime factorization of given num N
	//print(ex_nine());
	
	// Hailstone sequencevoidm_ten);
	//ex_ten();
	
	// Leibniz pi
	//print(ex_eleven());
	
	// Area of a quarter circle
	print(ex_tweleve());
	
	return 0;
}

//----------------------------
// SOLUTIONS
int ex_one(int i)
{
	return (9.0*i/5.0)+32;
}

std::string ex_two(int i)
{
	int inches = i/0.0254;
	return ""+std::to_string(inches/12)+" feet " + std::to_string(inches%12);
}

int ex_three()
{
	// (0+100)+(1+99)+...+(48+52)+(49+51)+50
	// 0 to 49 combinations forming 100 (i.e., 50*100) plus 50
	return 50*100+50;
}

int ex_four()
{
	int N = 0;
	while(N < 1) { std::cin >> N; } // ensure the answer is positive
	
	// 2n-1 = last odd in seq
	// 2n = end terms sum
	// sum = 2n*0.5n = n*n
	return N*N;
}

const int SENTINEL = 0;
int ex_five()
{
	int input = get_input();
	int highest = input;
	while (input != SENTINEL) { highest = (input > highest) ? input : highest; input = get_input(); }
	return highest;
}

std::string ex_six()
{
	int highest[2];
	highest[0] = get_input();
	int input = get_input();
	
	if (input > highest[0])	{ highest[1] = highest[0]; highest[0] = input; }
	else					{ highest[1] = input; }
	
	while (input != SENTINEL)
	{
		if (input > highest[0])
		{ highest[1] = highest[0]; highest[0] = input; }
		else if (input > highest[1])
		{ highest[1] = input; }
		input = get_input();
	}
	std::string result = "highest = " + std::to_string(highest[0]) + "\nsecond highest = "
						+ std::to_string(highest[1]);
	return result;
}
	
float ex_seven()
{
	int sum = 0, total = 0;
	int input = get_input();
	while(input != -1) { total++; sum += input; input = get_input(); }
	return float(sum)/total;
}

int ex_eight()
{
	int number = get_input();
	int reversed_num = 0;
	while (number > 0)
	{
		// isolate last digit
		reversed_num = reversed_num*10 + number%10;
		number /= 10;
	}
	return reversed_num;
}


std::string ex_nine()
{
	std::vector<int> prime_factors;
	int N = get_input();
	std::vector<int> primes;
	find_primes(primes, N);
	for (int i = 0; i < primes.size(); i++)
		find_factors(prime_factors, N, primes[i]);
	
	std::string result = "";
	for(int i = 0; i < prime_factors.size(); i++)
		if (i == prime_factors.size()-1)	result += std::to_string(prime_factors[i]);
		else								result += std::to_string(prime_factors[i]) + " x ";
		
	return result;
}

void find_factors(std::vector<int> &facts, int N, int next_prime)
{
	while (N%next_prime==0) { facts.push_back(next_prime); N/=next_prime; }
}

void find_primes(std::vector<int> & primes, int N)
{
	bool add;
	for (int i = 2; i <= N/2; i++)
	{
		add = true;
		for (int prime : primes)
			if (i%prime == 0)	{ add = false; break; }
		if (add)	primes.push_back(i);
	}
}
	
void ex_ten()
{
	hailstone(get_input());
}

void hailstone(int N)
{
	if (N == 1)			return;
	else if (N%2 == 0)
	{
		print(std::to_string(N) + " is even. Divide by 2 to get " + std::to_string(N/2));
		hailstone(N/2);
	} else
	{
		print(std::to_string(N) + " is odd. Multiply by 3 and add 1 to get " + std::to_string(N*3+1));
		hailstone(N*3+1);
	}
}

float ex_eleven()
{
	float pi_approx = 1;
	int divisor = 3;
	for (int i = 1; i <= 10000; i++, divisor+=2)
	{
		if(i%2==0)	pi_approx += 1.0/divisor;
		else		pi_approx -= 1.0/divisor;
	}
	
	return pi_approx*4;
}

float ex_tweleve()
{
	int radius = get_input();
	float dx = radius/10000.0;
	
	float area = 0;
	float x = 0;
	for (int i = 0; i < 10000; i++)
	{
		area += dx*(sqrt(radius*radius - x*x));
		x+=dx;
	}
	
	return area;
}
