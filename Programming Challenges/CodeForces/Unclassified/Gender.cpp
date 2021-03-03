#include <iostream>
#include <set>

int main()
{
	std::string name;
	std::cin >> name;
	std::set<char> letters;
	for (int i = 0; i < name.length(); i++)
		if (letters.find(char(name[i])) == letters.end()) letters.insert(char(name[i]));
	
	if (letters.size()%2==0)	std::cout << "CHAT WITH HER!" << std::endl;
	else						std::cout << "IGNORE HIM!" << std::endl;
	
	return 0;
}