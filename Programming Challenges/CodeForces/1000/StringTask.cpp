/*
 * https://codeforces.com/problemset/problem/118/A
 
 Petya started to attend programming lessons. On the first lesson his task was to write a simple program. The program was supposed to do the following: in the given string, consisting if uppercase and lowercase Latin letters, it:

deletes all the vowels,
inserts a character "." before each consonant,
replaces all uppercase consonants with corresponding lowercase ones.
Vowels are letters "A", "O", "Y", "E", "U", "I", and the rest are consonants. The program's input is exactly one string, it should return the output as a single string, resulting after the program's processing the initial string.

Help Petya cope with this easy task.

Input
The first line represents input string of Petya's program. This string only consists of uppercase and lowercase Latin letters and its length is from 1 to 100, inclusive.

Output
Print the resulting string. It is guaranteed that this string is not empty.

SAMPLE:
tour
	.t.r

Codeforces
	.c.d.f.r.c.s

aBAcAba
	.b.c.b
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

void removeVowels(std::string &s)
{
	std::string tmp_str = "";
	char ch;
	for (int i = 0; i < s.length(); i++)
	{
		ch = char(s[i]);
		if(!(ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' || ch=='Y' 
			|| ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y'))
			tmp_str += ch;
	}
	s = tmp_str;
}

void toLower(std::string &s)
{
	std::string tmp_str = "";
	char ch;
	for(int i = 0; i < s.length(); i++)
	{
		ch = char(s[i]);
		tmp_str += ch | ' ';
	}
	s = tmp_str;
}

void insertDot(std::string &s)
{
	std::string tmp_str = "";
	for(int i = 0; i < s.length(); i++)
	{
		tmp_str += '.';
		tmp_str += char(s[i]);
	}
	s = tmp_str;
}

int main()
{
	// input
	std::string s;
	std::cin >> s;
	// process
	removeVowels(s);
	toLower(s);
	insertDot(s);
	// output
	Log(s);
	
	return 0;
}