/*
* https://www.hackerrank.com/challenges/queens-attack-2/problem
* 
*/
import java.util.*;
import java.io.*;

public class Solution20
{
	static final int UPPER_RIGHT = 0, UPPER_LEFT = 1, LOWER_RIGHT = 2, LOWER_LEFT = 3;
	
	public static void main(String[] args)
	{
		loadFile();
		
		//int[][] obstacles = {{5,5},{4,2},{2,3}};
		//System.out.println("Result: " + queensAttack(5, 3, 4, 3, obstacles));
	}
	
	static void loadFile()
	{
		Scanner scan = null;
		try { scan = new Scanner(new File("Sol20.txt")); }
		catch (Exception e) {}
		
		String vars = scan.nextLine();
		int n = Integer.parseInt(vars.substring(0,vars.indexOf(" "))); // board size
		int k = Integer.parseInt(vars.substring(vars.indexOf(" ")+1)); // # obstacles
		vars = scan.nextLine();
		int r_q = Integer.parseInt(vars.substring(0,vars.indexOf(" "))); // queen row coord
		int c_q = Integer.parseInt(vars.substring(vars.indexOf(" ")+1)); // queen col coord
		int[][] obstacles = new int[k][2];
		int ind = 0;
		while (scan.hasNext())
		{
			String line = scan.nextLine();
			obstacles[ind][0] = Integer.parseInt(line.substring(0, line.indexOf(" ")));
			line = line.substring(line.indexOf(" ")+1);
			obstacles[ind++][1] = Integer.parseInt(line);
		}
		
		System.out.println("Result: " + queensAttack(n, k, r_q, c_q, obstacles));
	}
	
    // for furthest distance from edge times, expand outwards
	// and check rings around queen
	static int queensAttack(int size, int k, int r_q, int c_q, int[][] obstacles) {
        Arrays.sort(obstacles, (a,b) -> Integer.compare(a[0], b[0]));
		
		int num_attacks = 0;
		
		// possible attacks
		// column
		num_attacks += size - 1; // not the queen's spot
		// row
		num_attacks += size - 1; // not the queen's spot
		// lower left diag 
		num_attacks += Math.min(r_q-1, c_q-1);
		// upper left diag
		num_attacks += Math.min(size-r_q, c_q-1);
		// lower right diag
		num_attacks += Math.min(r_q-1, size-c_q);
		// upper right diag
		num_attacks += Math.min(size-r_q, size-c_q);

		// subtract all obstacle-blocked paths
		num_attacks -= impossibleAttacks(size, r_q, c_q, obstacles);
		
		return num_attacks;
	}
	
	// checks to see if valid attack
	static int impossibleAttacks(int size, int r, int c, int[][] obstacles)
	{
		int impossible_attacks = 0;
		
		// same row as queen
		impossible_attacks += same_row(size, r, c, obstacles);

		// same column as queen
		impossible_attacks += same_col(size, r, c, obstacles);

		// same diagonal
		impossible_attacks += same_diag(size, r, c, obstacles);
		
		return impossible_attacks;
	}
	
	static int same_row(int size, int r, int c, int[][] obstacles)
	{
		int[] min_max_ind = bin_search(r, obstacles);
		
		if (min_max_ind[0] == -1)	return 0;
				
		int larger_col = Math.max(obstacles[min_max_ind[0]][1], obstacles[min_max_ind[1]][1]);
		int smaller_col = Math.min(obstacles[min_max_ind[0]][1], obstacles[min_max_ind[1]][1]);
				
		if (min_max_ind[1] != -1 && min_max_ind[0] == min_max_ind[1])
			return (smaller_col < c) ? smaller_col : size-larger_col+1;
		else if (min_max_ind[1] != -1)
			return smaller_col + size-larger_col+1;
		else
			return smaller_col;
	}
	
	static int same_col(int size, int r, int c, int[][] obstacles)
	{
		int min_row = 0;
		int max_row = size+1;
		for (int i = 0; i < obstacles.length; i++)
			if (obstacles[i][1] == c)
			{
				// higher than queen but lower than prev_max
				if (obstacles[i][0] > r && obstacles[i][0] < max_row)		max_row = obstacles[i][0];
				// lower than queen but higher than prev_min
				else if (obstacles[i][0] < r && obstacles[i][0] > min_row)	min_row = obstacles[i][0];
			}
		
		if (max_row <= size)	return min_row + size-max_row+1;
		else					return min_row;
	}
	
	static int same_diag(int size, int r, int c, int[][] obstacles)
	{
		// used to prevent double counting obstacles on the same path
		boolean upper_right_found = false;
		boolean upper_left_found = false;
		boolean lower_right_found = false;
		boolean lower_left_found = false;
		
		int num_obs = 0;
		int limit = Math.max(size-r, r-1);
		int[] row_ind;
		for (int i = 1; i <= limit; i++)
		{
			if (upper_right_found && upper_left_found && lower_right_found && lower_left_found)
				break;
			
			// UPPER
			if (!upper_right_found || !upper_left_found)
			{
				row_ind = bin_search(r+i, obstacles);
				if (row_ind[0] != -1 && r+i <= size)
				{
					int closest_right = 0, closest_left = 0;
					while (row_ind[0] < obstacles.length && obstacles[row_ind[0]][0] == r+i)
					{
						// find one on diag
						if (obstacles[row_ind[0]][1] == c+i)
							closest_right = obstacles[row_ind[0]][1];
						else if (obstacles[row_ind[0]][1] == c-i)
							closest_left = obstacles[row_ind[0]][1];
						
						row_ind[0]++;					
					}

					if (!upper_right_found && closest_right > 0)
					{
						num_obs += add_diag_obs(size, r+i, c+i, UPPER_RIGHT);
						upper_right_found = true;
					}
					
					if (!upper_left_found && closest_left > 0)
					{
						num_obs += add_diag_obs(size, r+i, c-i, UPPER_LEFT);
						upper_left_found = true;
					}
				}
			}
			// LOWER
			if (!lower_right_found || !lower_left_found)
			{
				row_ind = bin_search(r-i, obstacles);
				if (row_ind[0] != -1 && r-i > 0)
				{
					int closest_right = 0, closest_left = 0;
					while (row_ind[0] >= 0 && obstacles[row_ind[0]][0] == r-i)
					{
						// find one closest to queen and on diag
						if (obstacles[row_ind[0]][1] == c+i)
							closest_right = obstacles[row_ind[0]][1];
						else if (obstacles[row_ind[0]][1] == c-i)
							closest_left = obstacles[row_ind[0]][1];
						row_ind[0]++;
					}
				
					if (!lower_right_found && closest_right > 0)
					{
						num_obs += add_diag_obs(size, r-i, c+i, LOWER_RIGHT);
						lower_right_found = true;
					}
					if (!lower_left_found && closest_left > 0)
					{
						num_obs += add_diag_obs(size, r-i, c-i, LOWER_LEFT);
						lower_left_found = true;
					}
				}		
			}
		}
		
		return num_obs;
	}
	
	static int[] bin_search(int r, int[][] obstacles)
	{
		int max = obstacles.length-1;
		int min = 0;
		int mid;
		int min_ind = -1;
		int max_ind = -1;
		
		while (min <= max)
		{
			mid = min+(max-min)/2;
			if (obstacles[mid][0] == r)		{ min_ind = mid; break; }
			else if (obstacles[mid][0] < r)	min = mid + 1;
			else							max = mid - 1;
		}
		
		if (min_ind == -1) return new int[]{-1,-1};
		
		while (min_ind-1 >= 0 && obstacles[min_ind-1][0] == r) min_ind--;
		max_ind = min_ind;
		while (max_ind+1 < obstacles.length && obstacles[max_ind+1][0] == r) max_ind++;
		
		return new int[]{min_ind,max_ind};
	}
	
	static int add_diag_obs(int size, int r, int c, int where)
	{
		int obs = 0;
		switch(where)
		{
			case UPPER_RIGHT:
				while (r <= size && c <= size)
				{
					obs++;
					r++;
					c++;
				}
				return obs;
			case UPPER_LEFT:
				while (r <= size && c > 0)
				{
					obs++;
					r++;
					c--;
				}
				return obs;
			case LOWER_RIGHT:
				while (r > 0 && c <= size)
				{
					obs++;
					r--;
					c++;
				}
				return obs;
			case LOWER_LEFT:
				while (r > 0 && c > 0)
				{
					obs++;
					r--;
					c--;
				}
				return obs;
		}
		return obs;
	}
}