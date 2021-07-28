/**
 * MazeSolver.java
 *
 * Uses either DFS or BFS to solve mazes
 * Takes one command line argument:
 *		ml = maze filepath to load
 * Or generates an r x c maze with ~x spaces cleared
 *
 * Use: java MazeSolver "\mazes\maze_20x20.txt"
 * @EC
 * @09-2020
 * For AP CS A
 */
import algos.*;
import utils.*;
import libs.*;
 
public class MazeSolver
{
	public static void main(String[] args)
	{
		// load or generate map
		String[] maze;
		if (args[0].contains(".txt"))	{ maze = MazeLoader.load(args[0]); }
		else							{ maze = MazeGenerator.generate(args); }
		
		// run algo for path
		int width = maze[0].length();
		int height = maze.length;
		double div_w = 1.0/width;
		double div_h = 1.0/height;
		for (int i = 0; i < height; i ++)
			for (int j = 0; j < width; j++)
			{
				if (maze[i].charAt(j) == '#') { StdDraw.setPenColor(); StdDraw.filledSquare(j*div_w,i*div_h,div_w); }
				else if (maze[i].charAt(j) == ' ') { StdDraw.setPenColor(StdDraw.WHITE); StdDraw.filledSquare(j*div_w,i*div_h,div_w); }
				else if (maze[i].charAt(j) == 'A') { StdDraw.setPenColor(StdDraw.RED); StdDraw.filledSquare(j*div_w,i*div_h,div_w); }
				else if (maze[i].charAt(j) == 'B') { StdDraw.setPenColor(StdDraw.BLUE); StdDraw.filledSquare(j*div_w,i*div_h,div_w); }
			}
		StdDraw.show();
		
		// display
		int[][] path = DFS.findPath(maze);
	}
}