/*
 * https://codeforces.com/problemset/problem/352/B

	One day Jeff got hold of an integer sequence a 1, a 2, ..., a n of length n. The boy immediately decided to analyze the sequence. For that, he needs to find all values of x, for which these conditions hold:

	x occurs in sequence a.
	
	Consider all positions of numbers x in the sequence a (such i, that a i = x). These numbers, sorted in the increasing order, must form an arithmetic progression.
	
	Help Jeff, find all x that meet the problem conditions.

	Input
	The first line contains integer n (1≤n≤10^5). The next line contains integers a 1, a 2, ..., a n (1≤a i≤10^5). The numbers are separated by spaces.

	Output
	In the first line print integer t — the number of valid x. On each of the next t lines print two integers x and p x, where x is current suitable value, p x is the common difference between numbers in the progression (if x occurs exactly once in the sequence, p x must equal 0). Print the pairs in the order of increasing x.
	
	SAMPLE:
	1.) input: 	1
				2
		output:	1
				2 0
	2.) input:	8
				1 2 1 3 1 2 1 5
		output:	4
				1 2
				2 4
				3 0
				5 0
				
	Troublesome input:
	6
	1 2 2 1 1 2
	desired output is 0 because there is no 'arithmetic sequence'
	9
	2 3 3 3 2 1 2 3 2
	desired output is 1 0 because 1 meets the criteria
	
	[LESSON LEARNED: I didn't understand the specification and would have to ask for clarification if this were posed at an interview]
	
	Improvements:
	Can use just set instead of map, to save on space and time when printing sets
	*/
#include <iostream>
#include <map>
#include <set>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

struct element {
		int num;
		int dist;
		int dist_tmp;
		bool dist_set = false;
};

int main()
{
	// input
	int len, tmp_num;
	std::cin >> len;
	std::map<int, element> seq;					// for all possible sequences encountered
	std::map<int, element>::iterator seq_it;
	std::set<int> valid;						// only for valid sequences
	std::set<int>::iterator valid_it;
	// O(N)
	for(int i = 0; i < len; i++)
	{
		std::cin >> tmp_num;
		seq_it = seq.find(tmp_num);
		
		// number not yet encountered
		if (seq_it == seq.end())
		{
			element e;
			e.num = tmp_num;
			e.dist = 0;
			e.dist_tmp = i;
			seq[tmp_num] = e;
			valid.insert(tmp_num);
		}
		// second encounter of number
		else if (!seq[tmp_num].dist_set)
		{ 
			seq[tmp_num].dist = i - seq[tmp_num].dist_tmp;
			seq[tmp_num].dist_set = true;
			seq[tmp_num].dist_tmp = i;
		}
		else 
		{
			// distance from last entry not the same as initial; invalid seq
			if (i - seq[tmp_num].dist_tmp != seq[tmp_num].dist)	valid.erase(tmp_num);
			// reset dist_tmp to current index to check again on next encounter of said number
			else 												seq[tmp_num].dist_tmp = i;
		}
	}
	
	// output
	Log(valid.size());
	// O(N)
	for (seq_it = seq.begin(); seq_it != seq.end(); seq_it++)
	{
		valid_it = valid.find(seq_it->first);
		// print out only valid entries
		if (valid_it != valid.end())	Log(std::to_string(seq_it->first) + " " + std::to_string(seq_it->second.dist));
	}
	return 0;
}