/*
 * https://codeforces.com/problemset/problem/118/B
 
Vasya's birthday is approaching and Lena decided to sew a patterned handkerchief to him as a present. Lena chose digits from 0 to n as the pattern. The digits will form a rhombus. The largest digit n should be located in the centre. The digits should decrease as they approach the edges. For example, for n = 5 the handkerchief pattern should look like that:


          0
        0 1 0
      0 1 2 1 0
    0 1 2 3 2 1 0
  0 1 2 3 4 3 2 1 0
0 1 2 3 4 5 4 3 2 1 0
  0 1 2 3 4 3 2 1 0
    0 1 2 3 2 1 0
      0 1 2 1 0
        0 1 0
          0

Your task is to determine the way the handkerchief will look like by the given n.

Input

The first line contains the single integer n (2 ≤ n ≤ 9).

Output

Print a picture for the given n. You should strictly observe the number of spaces before the first digit on each line. Every two adjacent digits in the same line should be separated by exactly one space. There should be no spaces after the last digit at the end of each line.

SAMPLES:
2
    0
  0 1 0
0 1 2 1 0
  0 1 0
    0

3
      0
    0 1 0
  0 1 2 1 0
0 1 2 3 2 1 0
  0 1 2 1 0
    0 1 0
      0


 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

void buildLine(int n, int spaces, std::string &line)
{
	// add init spaces
	for (int sp = 0; sp < spaces; sp++)
		line += " ";
	// add nums
	for (int j = 0; j <= n*2; j++)
	{
		if ((j > n || n == 0) && j == 0)	line += std::to_string(j);
		else if (j <= n)					line += std::to_string(j) + " ";
		else if (j < n*2)					line += std::to_string(n-(j-n)) + " ";
		else								line += std::to_string(n-(j-n));
	}
}

int main()
{
	// input
	int n;
	std::cin >> n;
	
	// process & output
	std::string line;
	for (int i = 0; i < (2*n+1); i++)
	{	
		line = "";
		if (i < (n+1))	buildLine(i, (2*(n-i)), line);
		else
		{
			if (i%n!=0)	buildLine((n-(i%n)), (2*(n-(n-(i%n)))), line);
			else		buildLine(0, (2*n), line);
		}
		Log(line);
	}
	
	return 0;
}