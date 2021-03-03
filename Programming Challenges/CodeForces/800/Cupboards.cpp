/*
 * https://codeforces.com/problemset/problem/248/A
 
 

One foggy Stockholm morning, Karlsson decided to snack on some jam in his friend Lillebror Svantenson's house. Fortunately for Karlsson, there wasn't anybody in his friend's house. Karlsson was not going to be hungry any longer, so he decided to get some food in the house.

Karlsson's gaze immediately fell on n wooden cupboards, standing in the kitchen. He immediately realized that these cupboards have hidden jam stocks. Karlsson began to fly greedily around the kitchen, opening and closing the cupboards' doors, grab and empty all the jars of jam that he could find.

And now all jars of jam are empty, Karlsson has had enough and does not want to leave traces of his stay, so as not to let down his friend. Each of the cupboards has two doors: the left one and the right one. Karlsson remembers that when he rushed to the kitchen, all the cupboards' left doors were in the same position (open or closed), similarly, all the cupboards' right doors were in the same position (open or closed). Karlsson wants the doors to meet this condition as well by the time the family returns. Karlsson does not remember the position of all the left doors, also, he cannot remember the position of all the right doors. Therefore, it does not matter to him in what position will be all left or right doors. It is important to leave all the left doors in the same position, and all the right doors in the same position. For example, all the left doors may be closed, and all the right ones may be open.

Karlsson needs one second to open or close a door of a cupboard. He understands that he has very little time before the family returns, so he wants to know the minimum number of seconds t, in which he is able to bring all the cupboard doors in the required position.

Your task is to write a program that will determine the required number of seconds t.

Input

The first input line contains a single integer n — the number of cupboards in the kitchen (2 ≤ n ≤ 104). Then follow n lines, each containing two integers l i and r i (0 ≤ l i, r i ≤ 1). Number l i equals one, if the left door of the i-th cupboard is opened, otherwise number l i equals zero. Similarly, number r i equals one, if the right door of the i-th cupboard is opened, otherwise number r i equals zero.

The numbers in the lines are separated by single spaces.

Output

In the only output line print a single integer t — the minimum number of seconds Karlsson needs to change the doors of all cupboards to the position he needs.

SAMPLES:
5
0 1
1 0
0 1
1 1
0 1
3
 */

#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
	int left_z = 0;
	int right_z = 0;
	int n, tmp_l, tmp_r;
	std::cin >> n;
	
	// how many cupboards are closed on each side
	for (int i = 0; i < n; i++)
	{
		std::cin >> tmp_l;
		std::cin >> tmp_r;
		
		if (tmp_l == 0) left_z++;
		if (tmp_r == 0) right_z++;
	}
	
	int result;
	// more closed on left
	if (left_z > n/2)	{ result = n-left_z; }
	else				{ result = left_z; }
	if (right_z > n/2)	{ result += n-right_z; }
	else				{ result += right_z; }
	
	LOG(result);
	
	return 0;
}