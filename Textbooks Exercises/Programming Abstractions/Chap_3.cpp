/*
 *	Programming Abstractions Chap. 3
 */
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

template<typename X>
void get_input(X &x) { std::cin >> x; }
	
bool ex_one();
bool endsWith(std::string str, std::string suffix);

int main()
{
	// endsWith(str, suffix)
	/*
	int inputs;
	get_input(inputs);
	for (int i = 0; i < inputs; i++)
		print(ex_one());
	*/

	// 
	ex_two();  
	return 0;
}

// bools only accept ints as inputs where 0 is false and anything else is true
bool ex_one()
{
	std::string str;
	std::string suffix;
	get_input(str);
	get_input(suffix);

	return endsWith(str, suffix);
}

bool endsWith(std::string str, std::string suffix)
{
	int start_str = str.size()-suffix.size();
	if (start_str < 0)	return false;	// if suffix is longer than str, this is impossible

	int suf_ind = 0;
	for (int i = start_str; i < str.size(); i++)
		if (str[i] != suffix[suf_ind++])	return false;

	return true;
}
