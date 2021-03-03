/*
	https://codeforces.com/problemset/problem/834/A

Walking through the streets of Marshmallow City, Slastyona have spotted some merchants selling a kind of useless toy which is very popular nowadays – caramel spinner! Wanting to join the craze, she has immediately bought the strange contraption.

Spinners in Sweetland have the form of V-shaped pieces of caramel. Each spinner can, well, spin around an invisible magic axis. At a specific point in time, a spinner can take 4 positions shown below (each one rotated 90 degrees relative to the previous, with the fourth one followed by the first one):

	v	<	^	>

After the spinner was spun, it starts its rotation, which is described by a following algorithm: the spinner maintains its position for a second then majestically switches to the next position in clockwise or counter-clockwise order, depending on the direction the spinner was spun in.

Slastyona managed to have spinner rotating for exactly n seconds. Being fascinated by elegance of the process, she completely forgot the direction the spinner was spun in! Lucky for her, she managed to recall the starting position, and wants to deduct the direction given the information she knows. Help her do this.

Input
There are two characters in the first string – the starting and the ending position of a spinner. The position is encoded with one of the following characters: v (ASCII code 118, lowercase v), < (ASCII code 60), ^ (ASCII code 94) or > (ASCII code 62) (see the picture above for reference). Characters are separated by a single space.

In the second strings, a single number n is given (0≤n≤10^9) – the duration of the rotation.

It is guaranteed that the ending position of a spinner is a result of a n second spin in any of the directions, assuming the given starting position.

Output
Output cw, if the direction is clockwise, ccw – if counter-clockwise, and undefined otherwise.

SAMPLES:
^ >
1
	cw

< ^
3
	ccw
	
^ v
6
	undefined
	
Observations:
- if n % 2 == 0, then impossible to tell
- translate symbols to base-4
	- then ^ > becomes 3 4
	- if ((init_pos + n) % 4 == final_pos) then cw
	else ccw
 */
#include <iostream>

template<typename T>
void print(T t) { std::cout << t << std::endl; }

const char SYMBOL_TO_NUM[] = { '0' , 'v', '<', '^', '>' };
const int STM_ARR_LEN = sizeof(SYMBOL_TO_NUM)/sizeof(char);

int main()
{
	// Input
	char init_pos, final_pos;
	int n;
	std::cin >> init_pos >> final_pos >> n;
	
	// Early termination case
	if (n % 2 == 0)	{ print("undefined"); return 0; }
	
	// Else
	// Translate positions into base-4 nums
	for (int i = 1; i < STM_ARR_LEN; i++)
		if (init_pos == SYMBOL_TO_NUM[i])	init_pos = i;
	
	for (int i = 1; i < STM_ARR_LEN; i++)
		if (final_pos == SYMBOL_TO_NUM[i])	final_pos = i;
	
	// predict position given number of spins for clockwise motion
	int pred_pos = ((init_pos + n) % 4 == 0) ?  4 : (init_pos + n) % 4;
	
	if (pred_pos == final_pos)	print("cw");
	else						print("ccw");
	
	return 0;
}