/*
	URL: https://codeforces.com/problemset/problem/1195/A

	DESCRIPTION:
	
	Old timers of Summer Informatics School can remember previous camps in which each student was given a drink of his choice on the vechorka (late-evening meal). Or may be the story was more complicated?

There are n students living in a building, and for each of them the favorite drink a_i is known. So you know n integers a_1,a_2,…,a_n, where a_i (1≤a_i≤k) is the type of the favorite drink of the i-th student. The drink types are numbered from 1 to k.

There are infinite number of drink sets. Each set consists of exactly two portions of the same drink. In other words, there are k types of drink sets, the j-th type contains two portions of the drink j. The available number of sets of each of the k types is infinite.

You know that students will receive the minimum possible number of sets to give all students exactly one drink. Obviously, the number of sets will be exactly ⌈n/2⌉, where ⌈x⌉ is x rounded up.

After students receive the sets, they will distribute their portions by their choice: each student will get exactly one portion. Note, that if n is odd then one portion will remain unused and the students' teacher will drink it.

What is the maximum number of students that can get their favorite drink if ⌈n/2⌉ sets will be chosen optimally and students will distribute portions between themselves optimally?

	INPUT:

	The first line of the input contains two integers n and k (1≤n,k≤1000) — the number of students in the building and the number of different drinks.

The next n lines contain student's favorite drinks. The i-th line contains a single integer from 1 to k — the type of the favorite drink of the i-th student.

	OUTPUT:

	Print exactly one integer — the maximum number of students that can get a favorite drink.

	SAMPLES:

	5 3
	1
	3
	1
	1
	2
		4

	10 3
	2
	1
	3
	2
	3
	3
	1
	3
	1
	2
		9

	OBSERVATIONS:
		NOTABLE CONSTRAINTS
			- Drinks come in pairs
				- Thus at most will use ⌈n_stud/2⌉ pairs
				- e.g., n_stud = 5, then pairs = 3 (3*2 = 6)

		EDGE CASES
			- For all stud pref is same pref(a_1)=pref(a_2)=...pref(a_n) -> all stud get fav
			- For all stud pref is diff pref(a_1)≠pref(a_2)≠...pref(a_n) -> ⌈n_stud/2⌉ get fav
		
		POSS ALGOS
			- Add all into an array of length n_drinks and record freq
			- Check for even/odd status of each drink
*/
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	// Input
	int n_stud, n_drinks;
	std::cin >> n_stud >> n_drinks;
	int drink_pref[n_drinks]{};
	for (int i = 0; i < n_stud; i++)
	{ int x; std::cin >> x; drink_pref[x-1]++; }	// increase specific drink pref

	// Process
	int n_stud_get_pref = 0;
	for (int i = 0; i < n_drinks; i++)
	{ n_stud_get_pref += drink_pref[i]/2; }		// find pairs
	n_stud_get_pref += (n_stud/2) + (n_stud%2);	// add min num possible
	
	// Output
	print(n_stud_get_pref);

	return 0;
}

