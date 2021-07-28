#include <iostream>

int main()
{
	int n[9];
	for (int i = 0; i < 9; i++)
		std::cin >> n[i];
	
	if((n[0]+n[1]+n[3])%2)		std::cout <<"0";
	else						std::cout <<"1";
	if((n[0]+n[1]+n[2]+n[4])%2)	std::cout <<"0";
	else						std::cout <<"1";
	if((n[2]+n[1]+n[5])%2)		std::cout <<"0";
	else						std::cout <<"1";
	std::cout <<"\n";

	if((n[0]+n[3]+n[4]+n[6])%2)			std::cout <<"0";
	else								std::cout <<"1";
	if((n[1]+n[3]+n[4]+n[5]+n[7])%2)	std::cout <<"0";
	else								std::cout <<"1";
	if((n[2]+n[4]+n[5]+n[8])%2)			std::cout <<"0";
	else								std::cout <<"1";
	std::cout <<"\n";

	if((n[6]+n[7]+n[3])%2)		std::cout <<"0";
	else						std::cout <<"1";
	if((n[6]+n[7]+n[8]+n[4])%2)	std::cout <<"0";
	else						std::cout <<"1";
	if((n[7]+n[8]+n[5])%2)		std::cout <<"0";
	else						std::cout <<"1";
	std::cout <<"\n";

	
	return 0;
}