/*
	URL: https://codeforces.com/problemset/problem/1121/A

	DESCRIPTION:

Everybody knows that the m-coder Tournament will happen soon. m schools participate in the tournament, and only one student from each school participates.

There are a total of n students in those schools. Before the tournament, all students put their names and the names of their schools into the Technogoblet of Fire. After that, Technogoblet selects the strongest student from each school to participate.

Arkady is a hacker who wants to have k Chosen Ones selected by the Technogoblet. Unfortunately, not all of them are the strongest in their schools, but Arkady can make up some new school names and replace some names from Technogoblet with those. You can't use each made-up name more than once. In that case, Technogoblet would select the strongest student in those made-up schools too.

You know the power of each student and schools they study in. Calculate the minimal number of schools Arkady has to make up so that k Chosen Ones would be selected by the Technogoblet.

Input

The first line contains three integers n, m and k (1≤n≤100, 1≤m,k≤n) — the total number of students, the number of schools and the number of the Chosen Ones.

The second line contains n different integers p1,p2,…,pn (1≤pi≤n), where pi denotes the power of i-th student. The bigger the power, the stronger the student.

The third line contains n integers s1,s2,…,sn (1≤si≤m), where si denotes the school the i-th student goes to. At least one student studies in each of the schools.

The fourth line contains k different integers c1,c2,…,ck (1≤ci≤n)  — the id's of the Chosen Ones.

Output

Output a single integer  — the minimal number of schools to be made up by Arkady so that k Chosen Ones would be selected by the Technogoblet.

	EXAMPLES:

	7 3 1
	1 5 3 4 6 7 2
	1 3 1 2 1 2 3
	3
		1

	8 4 4
	1 2 3 4 5 6 7 8
	4 3 2 1 4 3 2 1
	3 4 5 6
		2
	
	PLAN:
	
	- Have a length n array ordered by power
	- Find top rep from each school
		- search backwards through the array for each different school
	- Look for overlap in chosen ones
		- i.e., how many are already repping their school
	- Subtract overlap from k
		- this is the answer

	POST-MORTEM:

	- Had a logic error in the code searching for the school representatives
	- A number of improvements could be made to speed the code up
		- Instead of having a separate array for chosen_ones, could just consume the input when searching for overlap
*/
#include<iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	// Input
	int n, m, k;
	std::cin >> n >> m >> k;
	int studs[n+1]; int schools[n+1];
	
	for (int i = 1; i < n+1; i++)	std::cin >> studs[i];
	
	for (int i = 1; i < n+1; i++)	std::cin >> schools[i];

	int chosen_ones[k];
	for (int i = 0; i < k; i++)	std::cin >> chosen_ones[i];

	
	// Processing
	// search for reps from each school
	int reps[m+1] = {0};
	for (int i = 1; i < n+1; i++)
		if (reps[schools[i]] == 0)						reps[schools[i]] = i;
		else if (studs[i] > studs[reps[schools[i]]])	reps[schools[i]] = i;

	// search for overlap w/ chosen ones
	int made_up_names_needed = k;
	for (int i = 0; i < k; i++)
		for (int j = 1; j < m+1; j++)
			if (chosen_ones[i] == reps[j])	{ made_up_names_needed--; break; }

	// Output
	print(made_up_names_needed);

	return 0;
}
