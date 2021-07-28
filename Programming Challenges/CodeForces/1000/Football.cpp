/*
 * https://codeforces.com/problemset/problem/43/A
 
One day Vasya decided to have a look at the results of Berland 1910 Football Championship’s finals. Unfortunately he didn't find the overall score of the match; however, he got hold of a profound description of the match's process. On the whole there are n lines in that description each of which described one goal. Every goal was marked with the name of the team that had scored it. Help Vasya, learn the name of the team that won the finals. It is guaranteed that the match did not end in a tie.

Input

The first line contains an integer n (1 ≤ n ≤ 100) — the number of lines in the description. Then follow n lines — for each goal the names of the teams that scored it. The names are non-empty lines consisting of uppercase Latin letters whose lengths do not exceed 10 symbols. It is guaranteed that the match did not end in a tie and the description contains no more than two different teams.

Output

Print the name of the winning team. We remind you that in football the team that scores more goals is considered the winner.
 
 SAMPLES:
 1
 ABC
	ABC

 5
 A
 ABA
 ABA
 A
 A
	A
 
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	int n, t_a = 0, t_b = 0;
	std::cin >> n;
	std::string team_a, team_b = "?", tmp;
	std::cin >> team_a;
	t_a++;
	for (int i = 0; i < n-1; i++)
	{
		std::cin >> tmp;
		if (tmp.compare(team_a)==0)	t_a++;
		else						{ team_b = tmp; t_b++; }
		
		if (t_a != t_b && (t_a > n/2 || t_b > n/2))	break;
	}
	
	if (t_a > t_b)	Log(team_a);
	else			Log(team_b);
	return 0;
}