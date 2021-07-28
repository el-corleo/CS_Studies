/*
 * Exercises & Misc for Chap. 2 of Lospinoso - C++ Crash Course
 */

#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

enum class Reindeers { RUDOLPH, VIXEN, DANCER, PRANCER, COMET, BLITZEN, CUPID, DONNER, DASHER };

struct Acct
{
	int acct_num;
	std::string users[2];
	double balance;
	bool is_delinquent;
};

// like a struct but ensures all located in same block of memory (?)
// The union Variant can be interpreted as a char[10], an int, or a double.
// It takes up only as much memory as its largest member (probably string in this case).
// Use the dot operator to specify interpretation
// OFTEN BEST TO AVOID UNIONS!!!
union Variant
{
	char string[10];
	int integer;
	double floating_point;
};

// members are public by default
struct Pig
{
	Pig()
	{
		noise = "oink!";
		useless = new char[15];
	}

	Pig(std::string noise, int age)
	{
		this->noise = noise;
		this->age = age;
		useless = new char[15];
	}

	~Pig()
	{
		delete[] useless;
	}
	
	void speak()
	{
		print(noise);
	}

	int get_age()	{ return this->age; }
	private:
		std::string noise;
		int age;
		char *  useless;
};

struct Hog
{
	int age;
	std::string name;
	double tusk_len;
};

// members are private by default
class Dog
{
	std::string noise;
	public:
		Dog()
		{
			noise = "bark!";
		}

		Dog(std::string new_noise)
		{
			this->noise = new_noise;
		}

		void speak()
		{
			print(noise);
		}		
};

// Exercises
enum class Operation { ADD, SUBTRACT, MULTIPLY, DIVIDE };

struct Calculator
{
	Calculator(Operation op)
	{ this->op = op; }

	int calculate(int a, int b)
	{
		switch (op)
		{
			case Operation::ADD: { return a + b; }; break;
			case Operation::SUBTRACT: { return a - b; }; break;
			case Operation::MULTIPLY: { return a * b; }; break;
			case Operation::DIVIDE: { return a / b; }; break;	
		}
		return 0;
	}
	private:
		Operation op;
};

void exercises()
{
	// brace initialization is equivalent using obj{ arg }; and obj = { arg };
	Calculator c_a{ Operation::ADD };
	Calculator c_s = { Operation::SUBTRACT };
	Calculator c_m{ Operation::MULTIPLY };
	Calculator c_d = { Operation::DIVIDE };

	print(c_a.calculate(1,2));
	print(c_s.calculate(1,2));
	print(c_m.calculate(1,2));
	print(c_d.calculate(1,2));
}

int main()
{
	// exercises
	exercises();

	// pg 103 tells how to find the size of an array
	short array[] = { 104, 103, 102, 101, 100, 99 };
	size_t n_elem_in_array = sizeof(array) / sizeof(short);
	
	print("Old Fashioned way: " + std::to_string(n_elem_in_array));
	
	// pg 104 speaks of string literals just being char arrays
	char english[] = "A book holds a house of gold.";
	char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";
	
	printf("%s\n", english);
	//printf("%s\n", chinese);
	
	// pg 107 enum and enum class are detailed
	// 	we are warned to not use enum as it is mostly there for backward compatibility w/ C
	Reindeers best_reindeer = Reindeers::BLITZEN;
	
	// pg 108 talks about switch statements
	//	syntax is slightly different from Java switch statements
	switch (best_reindeer)
	{
		case (Reindeers::RUDOLPH):
		{ print("RUDOLPH"); } break;
		case (Reindeers::BLITZEN):
		{ print("BLITZEN"); } break;
		default:
		{ print("INVALID INPUT"); }
	}
	
	// pg 110 mentions structs
	Acct acct{};	// braces ensure zeroing for all fields; equivalent to Acct acct = {};
	acct.acct_num = 1000;
	acct.users[0] = "Bobo";
	acct.users[1] = "";
	acct.balance = 0.05;
	acct.is_delinquent = true;
	
	// pg 112 discusses Unions
	Variant v;
	v.integer = 42;
	printf("The ultimate ans: %d\n", v.integer);
	v.floating_point = 2.7182818284;		
	printf("e = %f\n", v.floating_point);	
	// may accidentally access integer when it was already changed to a floating point in the union
	printf("Now the union's integer component is %d\n", v.integer);	
	
	// pg 112-115 details the difference between struct and class keywords
	Pig p;
	Dog d;
	Dog pd{ "bark-oink!" }; // init for constructor w/ parameter
	p.speak();
	d.speak();
	pd.speak();

	// pg 118 talks about brace initialization
	// Basically, it's best to use curly brace initialization (not parethentical init)
	//Hog pig_0 = 0; is forbidden syntax; does not compile
	Hog hog_0{}; 	// all fields zeroed
	Hog hog_1 = {};	// same

	Hog hog_2{ 42, "Bobo" };	// Inits first two fields top-bottom
	Hog hog_3{ 42, "Bobo", 12.5 };	// Inits all fields
	//Hog hog_3{ 42, 12.5 };	// Cannot skip fields in between

	int arr_1[]{ 1, 2, 3};	// init arr of length 3	
	int arr_2[5]{};		// int arr of length 5 with 0s
	int arr_3[5]{ 1, 2, 3};	// int arr of length 5 with 1, 2, 3, 0, 0	
	int arr_4[5];		// int arr of length 5 with whatever is left in memory	

	return 0;
}
