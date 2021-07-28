/*
	https://codeforces.com/problemset/problem/975/A

In Aramic language words can only represent objects.

Words in Aramic have special properties:

    A word is a root if it does not contain the same letter more than once.
    A root and all its permutations represent the same object.
    The root x of a word y is the word that contains all letters that appear in y in a way that each letter appears once. For example, the root of "aaaa", "aa", "aaa" is "a", the root of "aabb", "bab", "baabb", "ab" is "ab".
    Any word in Aramic represents the same object as its root. 

You have an ancient script in Aramic. What is the number of different objects mentioned in the script?

Input

The first line contains one integer n (1≤n≤10^3) — the number of words in the script.

The second line contains n words s_1,s_2,…,s_n — the script itself. The length of each string does not exceed 10^3.

It is guaranteed that all characters of the strings are small latin letters.

Output

Output one integer — the number of different objects mentioned in the given ancient Aramic script.

SAMPLES:
5
a aa aaa ab abb
	2

3
amer arem mrea
	1

Observations:
	- For each item that appears, must go through each character to determine root
	- Should keep a list of all roots that have already appeared and a counter variable
		- Increment counter if new word has different root than those in list
	- Could check first to see if new word's root matches the length of any of the roots, 
	sort by length (BST), to narrow down the search space when checking to see if set of characters
	in new word's root matches characters in (Brute Force)
		- With multiple roots having same size, would need to disambiguate 
	- Have an arr[26+1] that indexes size of roots, and has a linked list to search through for a match
	- Could use a trie for roots to speed up search
*/
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

struct Node
{
	int root[26]; // one for every letter of the alphabet
	Node * next;
};

typedef Node * LLNode;

bool contains_root(LLNode& link, int (&word)[26])
{
	if (link == nullptr) return false; // no roots

	LLNode n = link;

	while(n != nullptr)
	{
		int i = 0;
		while(i < 26)
			if (n->root[i] != word[i])	break; // didn't match
			else				i++;
		if (i == 26)	return true;	// found a match
		else		n = n->next;	// search next node
	}
	return false;	// no match found
}

void add_root(LLNode& link, int (&word)[26])
{
	Node * n = new Node;
	for (int i = 0; i < 26; i++)
		n->root[i] = word[i];
	n->next = link;
	link = n;
}

int main()
{
	int n, num_roots = 0;
	std::cin >> n;
	// array for roots, indexed by length; extra 1 is so that we can count from index 1
	LLNode roots[27] = { nullptr }; // set all to NULL
	// load words
	for (int i = 0; i < n; i++)
	{
		int word[26] = { 0 };	// 26 entries for a-z; all set to zero cnt  
		std::string new_word;	// next word to extract root from
		std::cin >> new_word;
		int word_root_len = 0;	// next word's root length, serves as index for found roots array
		for (char c : new_word)
		{
			if (word[c-'a'] == 0)	word_root_len++;
			word[c-'a'] = 1;	// set to true
		}
		// see if root already found, otherwise add it to list
		if (!contains_root(roots[word_root_len], word))	{ add_root(roots[word_root_len], word); num_roots++; }
	}

	print(num_roots);
	
	return 0;
}
