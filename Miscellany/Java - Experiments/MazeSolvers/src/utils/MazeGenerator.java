/**
 * MazeGenerator.java
 *
 * Generates mazes for MazeSolver.java to solve.
 * Not all mazes are guaranteed to have a solution!
 * Takes three command line arguments:
 * 		r = # rows
 *		c = # colums
 * 		open_spaces = (approx.) # of open spaces in maze
 *
 * Use: java MazeGenerator 20 20 350 > maze_20x20.txt
 *
 * @EC
 * @09-2020
 * For AP CS A
 */
package utils;

public class MazeGenerator
{
	public static void main(String[] args)
	{
			String[] maze = generate(args);
			for (String s: maze)
				System.out.println(s);
	}
	
	public static String[] generate(String[] args)
	{
		// Setup
		int r = Integer.parseInt(args[0]);
		int c = Integer.parseInt(args[1]);
		double open_space_prob = Integer.parseInt(args[2])/(double) (r*c);	// prob empty space
		String[] maze = new String[r];
		
		// Create maze and print to standard output
		// # = obstacles
		// \s = open space
		// A = start
		// B = goal
		char type;
		int chance_start_goal = 1;
		int[] start_coords = { (int) (Math.random()*r), (int) (Math.random()*c) };
		int[] goal_coords = { (int) (Math.random()*r), (int) (Math.random()*c) }; // possible overlap
		
		for (int i = 0; i < r; i++)
		{
			String line = "";
			for (int j =0; j < c; j++)
			{
				// determine space type
				if (i == start_coords[0] && j == start_coords[1])		type = 'A';
				else if (i == goal_coords[0] && j == goal_coords[1])	type = 'B';
				else													type = (Math.random() <= open_space_prob) ? ' ' : '#';

				line += type;
			}
			maze[i] = line;
		}

		return maze;
	}
}