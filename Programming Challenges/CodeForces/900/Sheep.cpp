/*

Bob is a farmer. He has a large pasture with many sheep. Recently, he has lost some of them due to wolf attacks. He thus decided to place some shepherd dogs in such a way that all his sheep are protected.

The pasture is a rectangle consisting of R×C cells. Each cell is either empty, contains a sheep, a wolf or a dog. Sheep and dogs always stay in place, but wolves can roam freely around the pasture, by repeatedly moving to the left, right, up or down to a neighboring cell. When a wolf enters a cell with a sheep, it consumes it. However, no wolf can enter a cell with a dog.

Initially there are no dogs. Place dogs onto the pasture in such a way that no wolf can reach any sheep, or determine that it is impossible. Note that since you have many dogs, you do not need to minimize their number.

Input
First line contains two integers R (1≤R≤500) and C (1≤C≤500), denoting the number of rows and the numbers of columns respectively.

Each of the following R lines is a string consisting of exactly C characters, representing one row of the pasture. Here, 'S' means a sheep, 'W' a wolf and '.' an empty cell.

Output
If it is impossible to protect all sheep, output a single line with the word "No".

Otherwise, output a line with the word "Yes". Then print R lines, representing the pasture after placing dogs. Again, 'S' means a sheep, 'W' a wolf, 'D' is a dog and '.' an empty space. You are not allowed to move, remove or add a sheep or a wolf.

If there are multiple solutions, you may print any of them. You don't have to minimize the number of dogs.

SAMPLES:
6 6
..S...
..S.W.
.S....
..W...
...W..
......
	Yes
	..SD..
	..SDW.
	.SD...
	.DW...
	DD.W..
	......

1 2
SW
	No

5 5
.S...
...S.
S....
...S.
.S...
	Yes
	.S...
	...S.
	S.D..
	...S.
	.S...

*/
#include <iostream>
#include <string>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

int main()
{
	// Setup
	int r, c;
	std::cin >> r >> c;
	
	std::string pasture[r];
	std::string line; // for each row in the pasture
	char ch;
	int* current_line = new int[c];	// to keep track of wolves and sheep in current line
	int* form = current_line;
	for (int i = 0; i < c; i++)
		current_line[i] = 0;
	int prev_s_or_w = 0;
	
	// Process
	for (int i = 0; i < r; i++)
	{
		line = "";
		for (int j = 0; j < c; j++)
		{
			std::cin >> ch;		
			// set values of current line and checks against former
			if (ch == 'W')
			{
				// check if one before or above was sheep
				if (j-1 >= 0 && current_line[j-1] == 'S')	{ print("No"); return 0; }
				if (i > 0 && *(form + j) == 'S')			{ print("No"); return 0; }
				current_line[j] = 'W';
			}
			else if (ch == 'S')
			{
				// check if one before or above was wolf
				if (j-1 >= 0 && current_line[j-1] == 'W')	{ print("No"); return 0; }
				if (i > 0 && *(form + j) == 'W')			{ print("No"); return 0; }
				current_line[j] = 'S';
			}
			else { ch = 'D'; } // sets all '.' to 'D'
			
			line += ch;
		}
		pasture[i] = line;
		// set current to former and create new array for current
		form = current_line;
		current_line = new int[c];
		for (int i = 0; i < c; i++)
			current_line[i] = 0;
	}
	
	// Output
	print("Yes");
	for (int i = 0; i < r; i++)
		print(pasture[i]);
	
	return 0;
}