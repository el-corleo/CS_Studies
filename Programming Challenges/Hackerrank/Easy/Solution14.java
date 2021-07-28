/*
* https://www.hackerrank.com/challenges/migratory-birds/problem
*/

import java.util.*;

public class Solution14
{
	private static int migratoryBirds(List<Integer> arr) {
		int[] num_of_birds = new int[6];
        int ind = 0;
		// find total number of sightings per bird type
        while(ind < arr.size())
            num_of_birds[arr.get(ind++)]++;

		// determine max
        int max = 5;
        for (int i = 4; i > 0; i--)
            max = (num_of_birds[i] >= num_of_birds[max]) ? i : max;

        return max;
    }
	
	public static void main(String[] args)
	{
		List<Integer> arr = new ArrayList<Integer>();
		arr.add(1);
		arr.add(4);
		arr.add(4);
		arr.add(4);
		arr.add(5);
		arr.add(3);
		migratoryBirds(arr);
	}
}