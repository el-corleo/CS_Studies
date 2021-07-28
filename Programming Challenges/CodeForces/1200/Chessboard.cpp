/*
	https://codeforces.com/problemset/problem/445/A 
 
	A. DZY Loves Chessboard
	time limit per test: 1 second
	memory limit per test: 256 megabytes
	input: standard input
	output: standard output

	DZY loves chessboard, and he enjoys playing with it.

	He has a chessboard of n rows and m columns. Some cells of the chessboard are bad, others are good. For every good cell, DZY wants to put a chessman on it. Each chessman is either white or black. After putting all chessmen, DZY wants that no two chessmen with the same color are on two adjacent cells. Two cells are adjacent if and only if they share a common edge.

	You task is to find any suitable placement of chessmen on the given chessboard.

	Input
	The first line contains two space-separated integers n and m (1≤n,m≤100).

	Each of the next n lines contains a string of m characters: the j-th character of the i-th string is either "." or "-". A "." means that the corresponding cell (in the i-th row and the j-th column) is good, while a "-" means it is bad.

	Output
	Output must contain n lines, each line must contain a string of m characters. The j-th character of the i-th string should be either "W", "B" or "-". Character "W" means the chessman on the cell is white, "B" means it is black, "-" means the cell is a bad cell.

	If multiple answers exist, print any of them. It is guaranteed that at least one answer exists.

	SAMPLE I/O:
	1.)	in:		1 1
				.
		out:	B
	2.)	in:		2 2
				..
				..
		out:	BW
				WB
	3.) in:		3 3
				.-.
				---
				--.
		out:	B-B
				---
				--B
	
	Troublesome input:
	4 4
	----
	-..-
	-..-
	....
 */
#include <iostream>
#include <string>

template<typename T>
void Log(T t) { std::cout << t << std::endl; }

int main()
{
	// input & process
	int rows, cols, dash_cnt = 0;
	std::cin >> rows >> cols;
	std::string board = "";
	char pieces[2] = { 'W', 'B' };
	int piece_ind = 0;
	char ch, next_piece = pieces[piece_ind++];
	for (int i = 0; i < rows*cols; i++)
	{
		// set appropriate piece
		if (i%cols==0)	next_piece = (cols%2==0) ? pieces[piece_ind%2] : pieces[(++piece_ind)%2];
		else			next_piece = pieces[(++piece_ind)%2];
		// add piece to board
		std::cin >> ch;
		if (ch == '-')	{ board += '-'; dash_cnt++; }
		else 			{ board += next_piece; dash_cnt = 0; }
	}
	
	// output
	for (int i = 0; i < rows; i++)
		Log(board.substr(i*cols,cols));
	
	return 0;
}