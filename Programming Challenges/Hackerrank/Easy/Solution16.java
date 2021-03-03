/*
* https://www.hackerrank.com/challenges/electronics-shop/problem
*/
import java.util.*;

public class Solution16
{
	static int getMoneySpent(int[] keyboards, int[] drives, int b) {
        // sort arrays
        Arrays.sort(keyboards);
        Arrays.sort(drives);

        // check that min + min of array not > b
        if (keyboards[0]+drives[0]>b) return -1;

        // look for highest combined price [start from the rear]
        if (keyboards[keyboards.length-1]>drives[drives.length-1])
            return findCombined(keyboards, drives, b);
        else
            return findCombined(drives, keyboards, b);
    }

    static int findCombined(int[] a, int[] b, int budget)
    {
        int pair, i, j, highest = -1;
        for (i = a.length-1; i >= 0; i--)
        {
            pair = budget - a[i];
            for (j = b.length-1; j >= 0; j--)
                if (b[j] == pair)   return budget;
				// no need to search rest of the list
				// will always generate lower totals
                else if (b[j] < pair)
                {
                    highest = (a[i]+b[j] > highest) ? a[i]+b[j] : highest;
                    break;
                }
        }
        return highest;
    }
		
	public static void main(String[] args)
	{
		int[] key = {4};//{3,1};
		int[] dri = {5};//{5,4,8};
		int budget = 5; //10;
		System.out.println(getMoneySpent(key, dri, budget));
	}
}