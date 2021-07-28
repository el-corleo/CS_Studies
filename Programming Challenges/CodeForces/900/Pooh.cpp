/*
 https://codeforces.com/problemset/problem/876/A
 
 Winnie-the-Pooh likes honey very much! That is why he decided to visit his friends. Winnie has got three best friends: Rabbit, Owl and Eeyore, each of them lives in his own house. There are winding paths between each pair of houses. The length of a path between Rabbit's and Owl's houses is a meters, between Rabbit's and Eeyore's house is b meters, between Owl's and Eeyore's house is c meters.

For enjoying his life and singing merry songs Winnie-the-Pooh should have a meal n times a day. Now he is in the Rabbit's house and has a meal for the first time. Each time when in the friend's house where Winnie is now the supply of honey is about to end, Winnie leaves that house. If Winnie has not had a meal the required amount of times, he comes out from the house and goes to someone else of his two friends. For this he chooses one of two adjacent paths, arrives to the house on the other end and visits his friend. You may assume that when Winnie is eating in one of his friend's house, the supply of honey in other friend's houses recover (most probably, they go to the supply store).

Winnie-the-Pooh does not like physical activity. He wants to have a meal n times, traveling minimum possible distance. Help him to find this distance.

Input
First line contains an integer n (1≤n≤100) — number of visits.

Second line contains an integer a (1≤a≤100) — distance between Rabbit's and Owl's houses.

Third line contains an integer b (1≤b≤100) — distance between Rabbit's and Eeyore's houses.

Fourth line contains an integer c (1≤c≤100) — distance between Owl's and Eeyore's houses.

Output
Output one number — minimum distance in meters Winnie must go through to have a meal n times.

SAMPLES:
3
2
3
1
	3

1
2
3
5
	0
 */
#include <iostream>

const int AT_RABBITS = 0, AT_OWLS = 1, AT_EEYORES = 2;

int main()
{
	// Input
	int n_meals, dist_ro, dist_re, dist_oe, tot_dist = 0, curr_loc = AT_RABBITS;
	std::cin >> n_meals >> dist_ro >> dist_re >> dist_oe;
	
	// Process
	n_meals--;	// subtract one meal from starting at Rabbit'sb_type
	while (n_meals > 0)
	{
		if (curr_loc == AT_RABBITS)
		{
			curr_loc = (dist_ro < dist_re) ? AT_OWLS : AT_EEYORES;
			tot_dist += (curr_loc == AT_OWLS) ? dist_ro : dist_re;
		} else if (curr_loc == AT_OWLS)
		{
			curr_loc = (dist_ro < dist_oe) ? AT_RABBITS : AT_EEYORES;
			tot_dist += (curr_loc == AT_RABBITS) ? dist_ro : dist_oe;
		} else
		{
			curr_loc = (dist_re < dist_oe) ? AT_RABBITS : AT_OWLS;
			tot_dist += (curr_loc == AT_RABBITS) ? dist_re : dist_oe;
		}
		
		n_meals--;
	}
	
	std::cout << tot_dist << std::endl;
	
	return 0;
}