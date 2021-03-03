/*
 * https://codeforces.com/problemset/problem/1011/A
 
 Natasha is going to fly to Mars. She needs to build a rocket, which consists of several stages in some order. Each of the stages is defined by a lowercase Latin letter. This way, the rocket can be described by the string — concatenation of letters, which correspond to the stages.

There are n stages available. The rocket must contain exactly k of them. Stages in the rocket should be ordered by their weight. So, after the stage with some letter can go only stage with a letter, which is at least two positions after in the alphabet (skipping one letter in between, or even more). For example, after letter 'c' can't go letters 'a', 'b', 'c' and 'd', but can go letters 'e', 'f', ..., 'z'.

For the rocket to fly as far as possible, its weight should be minimal. The weight of the rocket is equal to the sum of the weights of its stages. The weight of the stage is the number of its letter in the alphabet. For example, the stage 'a 'weighs one ton,' b 'weighs two tons, and' z' — 26 tons.

Build the rocket with the minimal weight or determine, that it is impossible to build a rocket at all. Each stage can be used at most once.

Input
The first line of input contains two integers — n and k (1≤k≤n≤50) – the number of available stages and the number of stages to use in the rocket.

The second line contains string s, which consists of exactly n lowercase Latin letters. Each letter defines a new stage, which can be used to build the rocket. Each stage can be used at most once.

Output
Print a single integer — the minimal total weight of the rocket or -1, if it is impossible to build the rocket at all.

SAMPLE:
5 3
xyabd
	29

7 4
problem
	34

2 2
ab
	-1
12 1
abaabbaaabbb
	1
	
Observations:
	- all lowercase, so can use char val to sort/compare [a = 97]
	- if k == n and there is a sequence of letters less than 2 spaces apart, return -1
	- 
	- letters are not in order (use priority queue to sort by smallest)
 */
 #include <iostream>
 #include <string>
 #include <bits/stdc++.h>
 
 template<typename T>
 void print(T t) { std::cout << t << std:: endl; }
 
 int main()
 {
	// Input
	int n, k, tot_weight = 0;
	std::string s;
	std::cin >> n >> k >> s;
	int stages[n];
	for (int i = 0; i < n; i++) { stages[i] = int(s[i]); }
	
	// Process
	std::sort(stages,stages+n);
	int curr_ind = 0, last_ind_used = 0;	// two indexes track last stage used and current considered
	tot_weight += stages[curr_ind++] - 96;	// set init stage weight; 96 offsets char ascii value
	k--; 									// reduce number of stages left
	
	// case where k == 1
	if (k == 0) { print(tot_weight); return 0; }
	// case where k > 1
	while (curr_ind < n)
	{
		// check for proper spacing, if not move to next possible stage
		if (stages[curr_ind]-stages[last_ind_used] > 1)
		{ last_ind_used = curr_ind; tot_weight += stages[curr_ind++] - 96; k--; }
		else
		{ curr_ind++; }
		
		// found lightest combo
		if (k == 0)		{ print(tot_weight); return 0; }
	}
	// no combo possible
	print(-1);
	return 0;
 }