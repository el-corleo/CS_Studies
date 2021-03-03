// https://www.hackerrank.com/challenges/birthday-cake-candles/problem

import java.util.*;

public class Solution_8 {
    // Complete the birthdayCakeCandles function below.
    static int birthdayCakeCandles(int[] ar) {
        // sort
        Arrays.sort(ar);
        // edge case where all items are the same
        if (ar[0] == ar[ar.length-1])
            return ar.length;
        
        int tallest = ar[ar.length -1];
        int sentinel;
        int ind_mod = 0;
        int total = 0;

        while (true)
        {
            sentinel = ar[ar.length-(++ind_mod)];
            if (sentinel == tallest)
                total++;
            else
                break;
        }

        return total;
    }

    public static void main(String[] args)
	{
		int[] ar_1 = {3, 4, 5, 3, 2, 7, 6, 3, 6, 7};
		int[] ar_2 = {8, 4, 5, 8, 2, 7, 6, 3, 8, 7};
		int[] ar_3 = {7, 7, 7, 7, 7, 7, 7, 7, 7, 7};
		
        System.out.println(birthdayCakeCandles(ar_1));
        System.out.println(birthdayCakeCandles(ar_2));
        System.out.println(birthdayCakeCandles(ar_3));
    }
}