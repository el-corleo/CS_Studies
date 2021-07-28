#include <iostream>

std::string abbrev(std::string s)
{
	return s[0] + std::to_string(s.length()-2) + s[s.length()-1];
}

int main()
{
	int n;
	std::cin >> n;
	std::string s = "";
	for (int i = 0; i < n; i++)
	{
		std::cin >> s;
		if (s.length() > 10)	s = abbrev(s);
			
		std::cout << s << std::endl;
	}
	
	return 0;
}