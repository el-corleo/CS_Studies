/*
* https://www.hackerrank.com/challenges/magic-square-forming/problem
*/
import java.util.*;

public class Solution15
{
	private static int[][] edge_rows = {{8,1,6},{4,9,2},{8,3,4},{6,7,2},
										{4,3,8},{2,7,6},{6,1,8},{2,9,4}};
	private static int[][] mid_rows = {{3,5,7},{1,5,9},{9,5,1},{7,5,3}};
	/*
	8 1 6	4 9 2	8 3 4	4 3 8	6 1 8	2 9 4	6 7 2	2 7 6
	3 5 7	3 5 7	1 5 9	9 5 1	7 5 3	7 5 3	1 5 9	9 5 1
	4 9 2	8 1 6	6 7 2	2 7 6	2 9 4	6 1 8	8 3 4	4 3 8
	*/
	private static int formingMagicSquare(int[][] s)
	{	
		while (true)
		{		
			// compare copy to 8 possible square, return one with lowest cost
			int best_fit = compare_row(s[0]);
			if (best_fit < 0)
			{
				int lowest_cost = 100;
				for (int ind = 0; ind < edge_rows.length; ind++)
				{
					int cost = cost(s,edge_rows[ind],mid_rows[ind/2],
						edge_rows[(ind%2==0)?ind+1:ind-1]);
					lowest_cost = (cost < lowest_cost) ? cost : lowest_cost;
				}
				return lowest_cost;
			} 
			else	return cost(s,edge_rows[best_fit],mid_rows[best_fit/2],
						edge_rows[(best_fit%2==0)?best_fit+1:best_fit-1]);
		}
    }
	
	private static int cost(int[][] s, int[] top, int[] mid, int[] bottom)
	{
		int cost = 0;
		// calculate orig total
		for (int r = 0; r < s.length; r++)
			for (int c = 0; c < s.length; c++)
				if (r==0) 			cost += Math.abs(s[r][c]-top[c]);
				else if (r == 1)	cost += Math.abs(s[r][c]-mid[c]);
				else				cost += Math.abs(s[r][c]-bottom[c]);
		
		return cost;
	}
	
	// returns index of row with lowest change cost
	private static int compare_row(int[] row)
	{
		int lowest_cost = 100;
		int lowest_ind = 0;
		boolean multiple_poss = false;
		for (int ind = 0; ind < edge_rows.length; ind++)
		{
			int cost = 0;
			// find row cost
			for (int c = 0; c < row.length; c++)
				cost += Math.abs(edge_rows[ind][c] - row[c]);
			// reset lowest if cost is lower
			if (cost == lowest_cost) multiple_poss = true;
			else if (cost < lowest_cost)
			{
				lowest_cost = cost;
				lowest_ind = ind;
				multiple_poss = true;
			}
		}
		
		return (multiple_poss) ? -1 : lowest_ind;
	}
		
	public static void main(String[] args)
	{
		int[][] s = {{2,9,8},{4,2,7},{5,6,7}};
		System.out.println(formingMagicSquare(s));
	}
}