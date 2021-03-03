import java.util.Scanner;

public class SumInt
{
	private static int its = 0;
	
	public static void main(String[] args)
	{
		Scanner scan = new Scanner(System.in);
		
		System.out.println("Type range (space separated):");
		int lo = scan.nextInt();
		int hi = scan.nextInt();
		scan.close();
		
		// brute force
		System.out.println("Range is from " + lo + " to " + hi);
		System.out.println("Sum is " + sum(lo, hi));
		System.out.println("Brute force iter num: " + its);
		// euler
		System.out.println("AltSum is " + altSum(lo, hi));
		System.out.println("Euler method iter num: " + its);
		// recursion must first set to a 1 to n range
		//hi = hi-lo+1;
		//lo = 1;
		//System.out.println("RecurSum is " + recursiveSum(lo, hi));
		//System.out.println("Recursive method iter num: " + its);
	}
	
	// dumber implementation, but still works
	private static int sum(int lo, int hi)
	{
		int sum = 0;
		int iterations = 0;
		
		for (int i = lo; i <= hi; i++)
		{
			sum += i;
			iterations++;	
		}
		
		its = iterations;
		
		return sum;
	}
	
	// smarter implementation with fewer iterations
	private static int altSum(int lo, int hi)
	{
		int sum = ((hi+lo+1) % 2 == 0) ? 0 : (hi+lo)/2;
		int iterations = 0;
				
		for (int i = 0; i < (hi-lo+1)/2; i++)
		{
			sum += lo + hi;
			iterations++;
		}
		
		its = iterations;
		
		return sum;
	}
	
	// recursive implementation only works for 1 to n Integers
	// @ n = 100000 there's a StackOverflow
	// this method is buggy also, e.g @ n = 999	
	private static int recursiveSum(int lo, int hi)
	{
		its++;
		if (lo > hi)
			return 0;
		else 
			return (lo + hi + recursiveSum(lo+1, hi-1));
	}
}