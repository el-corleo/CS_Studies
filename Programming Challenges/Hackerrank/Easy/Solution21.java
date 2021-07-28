/*
* https://www.hackerrank.com/challenges/circular-array-rotation
*/

public class Solution21
{
	public static void main(String[] args)
	{
		int[] a = {1,2,3};
		int k = 2;
		int[] queries = {0,1,2};
		int[] answers = circularArrayRotation(a,k,queries);	
		
		for (int i : answers)
			System.out.println(i);
	}
	
	static int[] circularArrayRotation(int[] a, int k, int[] queries) {
        int old_zero = k % a.length;
        int[] shifted_val = new int[queries.length];

        for (int i = 0; i < shifted_val.length; i++)
            if (queries[i] < old_zero) shifted_val[i] = a[a.length-(old_zero-queries[i])];
            else shifted_val[i] = a[(queries[i]-old_zero)];
        
        return shifted_val;
    }
}