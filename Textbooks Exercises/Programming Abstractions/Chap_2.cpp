/*
 *	Programming Abstractions Chap. 2
 *	1 & 2 are reimplementations of their counterparts in Chap. 1 
 */
#include <iostream>
#include <random>
#include <vector>
#include <math.h>

// UTILITIES
template<typename I>
I get_input(I& i) { std::cin >> i; return i; }

template<typename T>
void print(T t) { std::cout << t << std::endl; }


// PROTOTYPES
int ex_three(float);
float ex_four();
bool ex_five(int);
int sum_divisors(int);
bool ex_six(int, std::vector<int>&);
double ex_seven(int);
int ex_nine();
double ex_twelve();
void ex_thirteen();
double ex_fourteen();
void ex_fifteen();

// MAIN
int main()
{
	// Rounding
	//print(ex_three(get_input()));
	
	// Windchill
	//try 						{ print(ex_four()); }
	//catch (const char* msg)	{ print(msg); }
	
	// Perfect Numbers
	//for (int i = 1; i < 10000; i++)	{ ex_five(i); }
	
	// IsPrime
	//std::vector<int> primes;
	//primes.push_back(2);
	//for (int i = 3; i < 101; i++)	{ print(i); print(ex_six(i, primes)); }
	
	// Successive approx for roots
	//print(ex_seven(get_input()));
	
	// Permutations
	//print(ex_nine());

	// Random Average
	//print(ex_twelve());
	
	// Radioactive decay
	//ex_thirteen();

	// Estimating pi
	//print(ex_fourteen());

	// Three consecutive heads
	ex_fifteen();

	return 0;
}


// IMPLEMENTATIONS
int ex_three(float f) { return int(f+0.5); }

float ex_four()
{ 
	float temp;
	get_input(temp);
	float wind_spd;
	get_input(wind_spd);
	
	if (wind_spd == 0)	return temp;
	else if (temp > 40)	throw "Undefined above 40C";
	else				return (35.74 + (0.6215*temp) - (35.75*powf(wind_spd,0.16)) +(0.4275*temp*powf(wind_spd,0.16))); }

bool ex_five(int n)
{
	if (sum_divisors(n) == n)	{ print(n); return true; }
	else						return false;
}

int sum_divisors(int n)
{
	int sum = 0;
	for (int i = 1; i <= n/2; i++)
	{
		if (n%i == 0)	sum += i;
	}
	return sum;
}

bool ex_six(int n, std::vector<int> &primes)
{
	for (int i : primes)
	{
		if (i > n/2)	{ primes.push_back(n); return true; }
		if (n%i==0)		return false;
	}
	
	return true;
}

const double EPSILON = 0.0001;
double ex_seven(int base)
{
	double g = base/2;
	//My solution:
	//while (g*g < base-EPSILON || g*g > base+EPSILON)	{ g = (g + base/g)/2; }
	//Book's request:
	while (true)
	{ 
		double og = g;
		g = (g + base/g)/2;
		if (g == og || g == base/og)	break;
	}
	return g;
}

int ex_nine()
{
	// get input
	int n;
	get_input(n);
	int k;
	get_input(k);
	
	// process
	int limit = n-k;
	int product = n--;
	while(n>limit) { product *= n--; }
	return product;
}

double ex_twelve()
{
	int n_trials;
	get_input(n_trials);
	double average;

	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	// Generate random numbers [0-1], average them and return their average
	for (int i = 0; i < n_trials; i++) average += dist(mt);

	return average/n_trials;
}


void ex_thirteen()
{
	int years = 0;
	int atoms;
	get_input(atoms);
	
	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	std::string output;

	while (atoms > 0)
	{ 
		for (int i = 0; i < atoms; i++) { if (dist(mt) < 0.5) atoms--; }
		output = "There are " + std::to_string(atoms) + " atoms at the end of year " + std::to_string(++years) + "."; 
		print(output);
	}
}

double ex_fourteen()
{
	int num_darts;
	double x, y;
	int darts_in_circ = 0;
	get_input(num_darts);

	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(-1.0, 1.0);

	for (int i = 0; i < num_darts; i++)
	{
		x = dist(mt);
		y = dist(mt);

		if ((x*x+y*y)<1) darts_in_circ++;
	}

	return double(darts_in_circ)/(num_darts-darts_in_circ);
}


void ex_fifteen()
{
	int threshold;
	get_input(threshold);

	int heads_run = 0;
	int tot_flips = 0;

	// random number generator
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, 1.0);

	while (heads_run < threshold) 
	{ 
		heads_run = (dist(mt) < 0.5) ? heads_run+1 : 0;
		tot_flips++;
	}

	std::string output = "It took " + std::to_string(tot_flips) + " to get " + std::to_string(threshold) + " heads in a row.";
	print(output);
}
