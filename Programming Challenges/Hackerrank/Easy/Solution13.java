/*
* https://www.hackerrank.com/challenges/divisible-sum-pairs/problem
*
* sample input
* ar = {8,10} | k = 2 | n = 2
* ar = {1,3,2,6,1,2} | k = 3 | n = 6
* ar = {36 46 25 97 57 14 21 50 75 58 54 32 73 11 36 22 95 46 54 61} | k = 7 | n = 20
* ar = {43,95, 51, 55, 40, 86, 65, 81, 51, 20, 47, 50, 65, 53, 23, 78, 75, 75, 47, 73, 25, 27, 14, 8, 26, 58, 95, 28, 3 ,23, 48, 69, 26, 3, 73, 52, 34, 7 ,40, 33, 56, 98, 71, 29, 70, 71 ,28 ,12 ,18 ,49 ,19 ,25 ,2 ,18, 15 ,41, 51, 42, 46, 19, 98, 56, 54, 98, 72, 25, 16, 49, 34, 99, 48, 93, 64, 44, 50, 91, 44, 17, 63, 27, 3, 65, 75, 19, 68, 30, 43, 37, 72, 54, 82, 92, 37, 52, 72, 62, 3 ,88, 82, 71} | k = 22 | n = 100
* ar = {34 38 30 27 1 81 37 19 74 73 32 13 44 99 7 88 50 52 32 82 29 1 55 85 89 58 35 19 76 55 45 37 41 74 80 46 38 74 56 18 86 23 57 27 52 9 69 78 52 8 62 85 65 2 11 70 34 26 72 11 20 32 9 75 74 85 29 6 87 81 40 11 31 49 66 91 99 85 18 54 81 93 52 9 72 89 85 66 24 11 85 3 14 36 72 3 76 99 88 8} | k = 96 | n = 100
*
* can be accomplished in O(n) by separating elements in ar into buckets of mod k in a new array of length k and then calculating combinations of complementary mods (i.e., where sum of indexes equals k 
*/


import java.util.*;

public class Solution13
{
	public static void main(String[] args)
	{
		int[] ar = {8,10};
		int k = 2;
		int n = 2;
		divisibleSumPairs(n,k,ar);
	}
	
	public static int divisibleSumPairs(int n, int k, int[] ar) {
        // add first and last, see if divisible by k
        // decrement last and repeat until i+j < k
        int total = 0;
        for(int i = 0; i < n-1; i++)
            for(int j = n-1; j > i; j--)
                if ((ar[i]+ar[j]) % k == 0)
                    total++;
		
		System.out.println("total:"+total);
        return total;
    }
}