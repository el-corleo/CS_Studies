/*
 * https://codeforces.com/problemset/problem/141/A

 So, the New Year holidays are over. Santa Claus and his colleagues can take a rest and have guests at last. When two "New Year and Christmas Men" meet, thear assistants cut out of cardboard the letters from the guest's name and the host's name in honor of this event. Then the hung the letters above the main entrance. One night, when everyone went to bed, someone took all the letters of our characters' names. Then he may have shuffled the letters and put them in one pile in front of the door.

The next morning it was impossible to find the culprit who had made the disorder. But everybody wondered whether it is possible to restore the names of the host and his guests from the letters lying at the door? That is, we need to verify that there are no extra letters, and that nobody will need to cut more letters.

Help the "New Year and Christmas Men" and their friends to cope with this problem. You are given both inscriptions that hung over the front door the previous night, and a pile of letters that were found at the front door next morning.
Input

The input file consists of three lines: the first line contains the guest's name, the second line contains the name of the residence host and the third line contains letters in a pile that were found at the door in the morning. All lines are not empty and contain only uppercase Latin letters. The length of each line does not exceed 100.
Output

Print "YES" without the quotes, if the letters in the pile could be permuted to make the names of the "New Year and Christmas Men". Otherwise, print "NO" without the quotes.

SAMPLE:
SANTACLAUS
DEDMOROZ
SANTAMOROZDEDCLAUS
	YES

PAPAINOEL
JOULUPUKKI
JOULNAPAOILELUPUKKI
	NO

BABBONATALE
FATHERCHRISTMAS
BABCHRISTMASBONATALLEFATHER
	NO
 */
 
#include <iostream>
#include <string>
#include <map>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	std::string n_1, n_2, lts;
	std::cin >> n_1 >> n_2 >> lts;
	std::map<char,int> name_lts;
	std::map<char,int> avail_lts;
	bool can_use = true;
	
	// split into maps
	// two names
	for (int i = 0; i < n_1.length(); i++)
		if (name_lts.find(char(n_1[i])) != name_lts.end())	name_lts[char(n_1[i])]++; 
		else												name_lts[char(n_1[i])] = 1;
	
	for (int i = 0; i < n_2.length(); i++)
		if (name_lts.find(char(n_2[i])) != name_lts.end())	name_lts[char(n_2[i])]++; 
		else												name_lts[char(n_2[i])] = 1;
	// available letters
	for (int i = 0; i < lts.length(); i++)
		if (avail_lts.find(char(lts[i])) != avail_lts.end())	avail_lts[char(lts[i])]++; 
		else													avail_lts[char(lts[i])] = 1;
	
	// equality checks
	// size
	if (name_lts.size() != avail_lts.size())	can_use = false;
	// contents
	else 
	{
		std::map<char, int>::iterator it;

		for ( it = avail_lts.begin(); it != avail_lts.end(); it++ )
		{
			char key = it->first;
			int val = it->second;
			if (avail_lts.find(key) == avail_lts.end())	{ can_use = false; break; }
			else if (avail_lts[key] != name_lts[key])	{ can_use = false; break; }
		}
	}
	
	// output
	if (can_use)	Log("YES");
	else			Log("NO");
	
	return 0;
}