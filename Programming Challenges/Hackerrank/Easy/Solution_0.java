import java.util.*;

// Number of negative subarrays
// https://www.hackerrank.com/challenges/java-negative-subarray/problem
public class Solution
{
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);

		int negSubArr = 0;
		int size = scan.nextInt();
		int[] arr = new int[size];

		// populate array
		for (int i = 0; i < size; i++)
			arr[i] = scan.nextInt();
		
		// check all subarrays for negative results
		for (int i = 0; i < size; i++)
			for (int j = size - 1; j >= i; j--)
				negSubArr += (sum(arr, i,j) < 0) ? 1 : 0;
		
		System.out.println(negSubArr);
    }
							  
	private static int sum(int[] arr, int lo, int hi)
	{
		int sum = 0;
		
		for (int i =lo; i <= hi; i++)
			sum += arr[i];
				
		return sum;
	}
	
}