/*
 * https://codeforces.com/problemset/problem/227/B

Once at a team training Vasya, Petya and Sasha got a problem on implementing linear search in an array.

According to the boys, linear search works as follows. The array elements in a pre-selected order are in turn compared with the number that you need to find. Once you find the array element that is equal to the required one, the search ends. The efficiency of the algorithm is the number of performed comparisons. The fewer comparisons the linear search has made, the more effective it is.

Vasya believes that a linear search would work better if it sequentially iterates through the elements, starting with the 1-st one (in this problem we consider the elements of the array indexed from 1 to n) and ending with the n-th one. And Petya says that Vasya is wrong: the search will need less comparisons if it sequentially iterates the elements starting from the n-th and ending with the 1-st one. Sasha argues that the two approaches are equivalent.

To finally begin the task, the teammates decided to settle the debate and compare the two approaches on an example. For this, they took an array that is a permutation of integers from 1 to n, and generated m queries of the form: find element with value b i in the array. They want to calculate for both approaches how many comparisons in total the linear search will need to respond to all queries. If the first search needs fewer comparisons, then the winner of the dispute is Vasya. If the second one does, then the winner is Petya. If both approaches make the same number of comparisons, then Sasha's got the upper hand.

But the problem is, linear search is too slow. That's why the boys aren't going to find out who is right before the end of the training, unless you come in here. Help them to determine who will win the dispute.

Input

The first line contains integer n (1 ≤ n ≤ 10^5) — the number of elements in the array. The second line contains n distinct space-separated integers a 1, a 2, ..., a n (1 ≤ a i ≤ n) — the elements of array.

The third line contains integer m (1 ≤ m ≤ 10^5) — the number of queries. The last line contains m space-separated integers b 1, b 2, ..., b m (1 ≤ b i ≤ n) — the search queries. Note that the queries can repeat.

Output

Print two integers, showing how many comparisons Vasya's approach needs and how many comparisons Petya's approach needs. Separate the numbers by spaces.

Please, do not use the %lld specifier to read or write 64-bit integers in С++. It is preferred to use cin, cout streams or the %I64d specifier.

SAMPLES:
2
1 2
1
1
	1 2

2
2 1
1
1
	2 1

3
3 1 2
3
1 2 3
	6 6
 */

#include <iostream>
#include <map>

template<typename T>
void Log(T t_1, T t_2) { std::cout << t_1 << " " << t_2 << std::endl; }

int main()
{
	// input
	long long size, queries, tmp;
	std::cin >> size;
	std::map<long long,long long> elements;
	for(int i = 0; i < size; i++)
	{
		std::cin >> tmp;
		elements[tmp] = i; // tmp = element, i = index
	}
	std::cin >> queries;
	
	// helper
	unsigned long long v_comp = 0, p_comp = 0;
	unsigned long long result;

	// find element
	for(int i = 0; i < queries; i++)
	{
		std::cin >> tmp; // query
		if (elements.find(tmp) != elements.end())
		{ 
			result = elements[tmp]+1; 
			v_comp += result;
			p_comp += size-(result-1);
		}
		else
		{
			v_comp += size;
			p_comp += size;
		}
		
	}
		
	Log(v_comp, p_comp);
	return 0;
}