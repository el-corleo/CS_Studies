/*
 * https://codeforces.com/problemset/problem/230/A
 
Kirito is stuck on a level of the MMORPG he is playing now. To move on in the game, he's got to defeat all n dragons that live on this level. Kirito and the dragons have strength, which is represented by an integer. In the duel between two opponents the duel's outcome is determined by their strength. Initially, Kirito's strength equals s.

If Kirito starts duelling with the i-th (1 ≤ i ≤ n) dragon and Kirito's strength is not greater than the dragon's strength x i, then Kirito loses the duel and dies. But if Kirito's strength is greater than the dragon's strength, then he defeats the dragon and gets a bonus strength increase by y i.

Kirito can fight the dragons in any order. Determine whether he can move on to the next level of the game, that is, defeat all dragons without a single loss.

Input

The first line contains two space-separated integers s and n (1 ≤ s ≤ 104, 1 ≤ n ≤ 103). Then n lines follow: the i-th line contains space-separated integers x i and y i (1 ≤ x i ≤ 104, 0 ≤ y i ≤ 104) — the i-th dragon's strength and the bonus for defeating it.

Output

On a single line print "YES" (without the quotes), if Kirito can move on to the next level and print "NO" (without the quotes), if he can't.

SAMPLES:
2 2
1 99
100 0
YES

10 1
100 100
NO 
 */
#include <iostream>
#include <algorithm>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

struct Dragon {
	int d_s;
	int bonus;
};

bool sortDrag(Dragon const& lhs, Dragon const& rhs)
{ return lhs.d_s < rhs.d_s; }

int main()
{
	bool possible = true;
	// input
	int s, dup_s, n;
	std::cin >> s >> n;
	Dragon dragons[n];
	dup_s = s;
	for (int i = 0; i < n; i++)
	{
		std::cin >> dragons[i].d_s >> dragons[i].bonus;
		// try seeing if it works w/o sorting
		if (possible)
		{	
			if (dup_s <= dragons[i].d_s)	possible = false;
			else							dup_s+= dragons[i].bonus;
		}
	}
	
	// process (if needs to be sorted)
	if (!possible)
	{
		possible = true; // reset
		std::sort(dragons, dragons+n, &sortDrag);
		for (int i = 0; i < n; i++)
		{
			if (s <= dragons[i].d_s)	{ possible = false; break;}
			else						s+= dragons[i].bonus;
		}
	}
	
	// output
	Log((possible) ? "YES" : "NO");
	return 0;
}