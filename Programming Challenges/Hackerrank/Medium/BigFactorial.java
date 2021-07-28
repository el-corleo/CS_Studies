/*
* https://www.hackerrank.com/challenges/extra-long-factorials/problem
*/

import java.util.*;

public class BigFactorial
{
	public static void main(String[] args)
	{
		int n = 25;
		ArrayList<Integer> digits = new ArrayList<Integer>();
		pop_array_list(n, digits);
		
		// multiply digits in digits n-1 times
		for (int i = n-1; i > 1; i--)
			multiply_all(i, digits);
	}
	
	private static void multiply_all(int n, ArrayList<Integer> digits)
	{
		ArrayList<Integer> multipliers = new ArrayList<Integer>();
		ArrayList<Integer> results = new ArrayList<Integer>();
		pop_array_list(n, multipliers);
		
		int val_1 = 0, val_2 = 0, val_3 = 0;
		int r_1 = 0, r_2 = 0, r_3 = 0;
		
		// multiply first multiplier
		for (int i = 0; i < digits.size(); i++)
		{
			// calculate multi + carry
			val_1 = multipliers.get(0)*digits.get(i)+r_1;
			// calculate carry
			r_1 = val_1/10;
			// add tenths digit to result
			results.add(val_1%10);
		}
		// add last carry if result was greater than 9
		if (val_1 > 9) results.add(r_1);
		
		if (multipliers.size()>1)
			for (int i = 1; i < multipliers.size(); i++)
				multiply_single(multipliers.get(i), digits, results);
		
		// print out results
		for (int i = results.size()-1; i >= 0; i--)
			System.out.print(results.get(i));
		System.out.println();
		
		// put in original digits array
		for (int i = 0; i < results.size(); i++)
			try{ digits.set(i, results.get(i)); }
			catch (Exception e) { digits.add(results.get(i)); }
	}
	
	private static void multiply_single(int n, ArrayList<Integer> digits,
										ArrayList<Integer> results)
	{
		int val_1 = 0, val_2 = 0;
		int r_1 = 0, r_2 = 0;
		// multiply second multiplier
			for (int i = 0; i < digits.size(); i++)
			{
				// calculate multi + carry
				val_1 = n*digits.get(i)+r_1;
				// calculate carry
				r_1 = val_1/10;
				// add tenths digit to results
				if (i+1 != results.size())
				{
					val_2 = results.get(i+1) + (val_1%10) + r_2;
					r_2 = val_2/10;
					results.set(i+1, val_2%10);
				} else // if results is same length as digits
				{
					val_2 = r_2 + val_1;
					r_2 = val_2/10;
					results.add(val_2%10);
				}
			}
			// add last carry if result was greater than 9
			// && results and digits not same length
			if (val_1 > 9) results.add(r_1);
	}
	
	private static void pop_array_list(int n, ArrayList<Integer> list)
	{
		while (n > 0)
		{
			list.add(n%10);
			n /= 10;
		}
	}
}