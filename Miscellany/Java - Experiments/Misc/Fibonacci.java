import java.util.*;

public class Fibonacci
{	
	/*
	 * Only works for n_terms > 1
	 */
	public static ArrayList<Integer> fibonacci(int n_terms)
	{
		ArrayList<Integer> fib_seq_to_n = new ArrayList<Integer>();
		fibonacci(fib_seq_to_n, n_terms);
		
		return fib_seq_to_n;
	}
	
	/*
	 * Breakdown, then build up
	 */
	private static void fibonacci(ArrayList<Integer> arr, int max_terms)
	{
		// base case
		if (max_terms == 2)
		{
			arr.add(1);
			arr.add(1);
			return;
		}
		
		// recursive step
		fibonacci(arr, max_terms-1);
		arr.add(arr.get(max_terms-2) + arr.get(max_terms-3));
	}
		
}

