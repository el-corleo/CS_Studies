#include <iostream>

int main()
{
	int nD;
	std::cin >> nD;
	int raw_total=0;
	int x;
	for (int i = 0; i < nD; i++)
	{
		std::cin >> x;
		raw_total+= x;
	}
	
	std::cout << raw_total/double(nD) << std::endl;
	
	return 0;
}