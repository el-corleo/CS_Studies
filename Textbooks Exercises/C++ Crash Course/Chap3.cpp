/*
 * Exercises & Misc for Chap. 3 of Lospinoso - C++ Crash Course
 */
#include <iostream>

struct Animal
{
	std::string sound;
};

struct Rock
{
	char roll[5];	// must be +1 longer than intended size to fit NULL
};

void printAni(Animal* ani_ptr)
{
	printf("Pigs definitely go %s\n", ani_ptr->sound.c_str());
}

void printRock(Rock* rock_ptr, size_t n_rocks)
{
	for(size_t i = 0; i < n_rocks; i++)
		printf("Hi, I'm %s. I'm a lovely rock.\n", rock_ptr[i].roll);
} 

void changeRock(Rock& rock)
{
	rock.roll[0] = 'T';
	rock.roll[1] = 'u';
	rock.roll[2] = 'f';
	rock.roll[3] = 'f';
}

// const Correctness [begin]
void petruchio(const char* shrew)
{
	printf("Fear not, sweet wench, they shall not touch thee, %s.", shrew);
	//shrew[0] = 'K'; // compiler error becuase of const modifier in parameter declaration
}

struct ConstExample
{
	int data;
	int get_data() const { return this->data; }
};

bool greater_than(const ConstExample& a, const ConstExample& b)
{
	return a.get_data() > b.get_data();
}

// const Correctness [end]

// auto [begin]
struct Dwarf
{
	char* name;
	int age;
};

Dwarf dwarves[1]; // <-- when does this get populated?

struct Contract
{
	void add(const Dwarf&);	//<-- add to what? or did author leave unimplemented?
private:
	Dwarf employees[13];	//<-- shouldn't we add this to store the added dwarves?
	int ind = 0;
};
void Contract::add(const Dwarf& d) { this->employees[ind++]; }

void form_company(Contract& contract)
{
	for (const auto& dwarf : dwarves)
	{ contract.add(dwarf); }
}

// auto [end]

// EXERCISES [begin]
// 3_2
void read_from(const char* arr, int size)
{
	for (int i = 0; i < size; i++) 
	{ std::cout << arr[i]; }
	
	std::cout << std::endl;
}

void write_to(char* arr, int ind, char c)
{
	arr[ind] = c;
}

// EXERCISES [end]

int main()
{
	int sample_int = {};	// sets to zero
	printf("sample_int: %d\n", sample_int);

	int* sample_int_add = &sample_int;
	printf("&sample_int: %p\n", sample_int_add);
	
	*sample_int_add = 42;	// dereference pointer address to access memory directly
				// then change value there to 42	
	printf("sample_int new val: %d\n", *sample_int_add);
	printf("&sample_int: %p\n", sample_int_add);

	Animal pig;
	Animal* pig_ptr = &pig;
	pig_ptr->sound = "oink!";	// ptr->member is equivalent to (*ptr).member
	printf("Pigs go %s\n", (*pig_ptr).sound.c_str());
	printf("Pigs go %s\n", pig_ptr->sound.c_str());
	printf("I said, pigs go %s\n", pig.sound.c_str());
	
	Animal pigs[] = { "oink!", "Oink!", "OINK!" };
	printAni(pigs);	// highlights array decaying to a point to arrays first element
			//  when treated as pointer

	Rock rocks[] = { "Gold", "Mica", "Iron" };
	printRock(rocks, sizeof(rocks)/sizeof(Rock));
	Rock* third_rock_1 = &rocks[2];	// two different ways of obtaining a reference to the third element in an array
	Rock* third_rock_2 = rocks + 2;

	printf("third_rock_add: %p\n", third_rock_1);
	printf("third_rock_add: %p\n", third_rock_1);

	printf("third_rock: %s\n", third_rock_1->roll);
	changeRock(rocks[2]);	// pass by reference
	printf("third_rock: %s\n", third_rock_1->roll);

	// References are safer than pointers pg. 77
	//	- harder to set to null
	//	- cannot be reseated (reassigned)
	// References do not have to be dereferenced and can use dot notation directly
	//	- e.g., ref_var.member vs (*ptr_var).member or ptr_var->member
	
	// this code shows references do not change the address they refer to
	int original = 100;
	int& original_ref = original;
	printf("Original: %d\n", original);	// prints 100
	printf("Reference: %d\n", original_ref);// prints 100

	int new_value = 200;
	original_ref = new_value;
	printf("Original: %d\n",original);	// prints 200
	printf("New Value: %d\n",new_value);	// prints 200
	printf("Reference: %d\n",original_ref); // prints 200

	// const Correctness pg. 81
	// const is a lot like Java's final
	// const argument 
	//	- qualifying a function parameter with const guarantees that it won't be changed
	//	- this functions as limiting to read-only permission
	char shrew[]{'Y', 'O', 'U'};
	petruchio(shrew);

	// const method 
	//	- guarantee to not modify current objects state in given method
	//	- attempted modifications of members in a const method generates a compiler error
	ConstExample a, b;
	a.data = 1;
	b.data = 2;
	printf("\nA = %d & B = %d, therefore A > B is %d\n", a.get_data(), b.get_data(), greater_than(a, b)); 
	
	// auto type divination pg. 84
	//	- "Alone, all of this simple initialization help doesn’t buy you much; however, 
	//	when types become more complicated—for example, dealing with iterators from stdlib 
	//	containers—it really saves quite a bit of typing. It also makes your code more 
	//	resilient to refactoring."
	//	- can use with &, * and const
	auto year { 2019 };		// int
	auto& year_ref = year;		// int&
	const auto& year_cref = year;	// const int&
	auto* year_ptr = &year;		// int*
	const auto* year_cptr = &year;	// const int*

	// EXERCISES
	// 3_2
	char lower[] = "abc?e";
	char upper[] = "ABC?E";
	char* upper_ptr = upper;// Equivalent: &upper[0]
	lower[3] = 'd';		// lower now contains a b c d e \0
	upper_ptr[3] = 'D';	// upper now contains A B C D E \0

	char letter_d = lower[3];	// letter_d equals 'd'
	char letter_D = upper_ptr[3];	// letter_D equals 'D'

	//printf("lower: %s\nupper: %s", lower, upper); x
	//lower[7] = 'g';	// Super bad. You must never do this.
	int size = sizeof(lower)/sizeof(lower[0]);
	read_from(lower, size);
	read_from(upper, size);
	
	write_to(lower, 1, 'x');
	write_to(upper, 1, 'X');

	read_from(lower, size);
	read_from(upper, size);
	
	// 3_4
	auto orig = 100;
	auto& orig_ref = orig;
	printf("Original: %d\n", orig);
	printf("Reference: %d\n", orig_ref);
	
	auto new_val = 200;
	original_ref = new_val;
	printf("Original: %d\n", orig);
	printf("New Value: %d\n", new_val);
	printf("Reference: %d\n", orig_ref);

	return 0;
}

